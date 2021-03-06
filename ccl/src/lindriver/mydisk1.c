/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: mydisk.c
 *
 * Author: $author$
 *   Date: 8/8/2005
 *
 *    $Id$
 *
 * Linux driver "mydisk".
 *
 **********************************************************************
 */

#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/locks.h>
#include <linux/interrupt.h>
#include <linux/pci.h>
#include <linux/ioctl.h>
#include <linux/proc_fs.h>
#include <linux/devfs_fs_kernel.h>
#include <linux/string.h>

#include <asm/page.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/system.h>
#include <asm/types.h>
#include <asm/irq.h>
#include <asm/io.h>

#include "mydisk.h"

/*
 **********************************************************************
 * defines
 **********************************************************************
 */

#define MYDISK_MODULE_NAME "mydisk"
#define MYDISK_REQUEST_IDS 4096

#if defined(_DBPRINTK)
#define dbprintk(args...) printk(args)
#else
#define dbprintk(args...)
#endif

#if !defined(MYDISK_IOCTL_MAGIC)
#define MYDISK_IOCTL_MAGIC 'X'
#endif /* !defined(MYDISK_IOCTL_MAGIC) */

#if !defined(MYDISK_IOCTL_RESETMOD)
#define MYDISK_IOCTL_RESETMOD _IO(MYDISK_IOCTL_MAGIC, 255)
#endif /* !defined(MYDISK_IOCTL_RESETMOD) */

/*
 **********************************************************************
 * types
 **********************************************************************
 */

/**
 ************************************************************
 * Struct: mydisk_request_item
 *
 * Author: $author$
 *   Date: 8/8/2005
 ************************************************************
 */
typedef struct mydisk_request_item
{
    list_t list;
    wait_queue_head_t waitqueue;
    mydisk_request_t request;
} mydisk_request_item_t;

/*
 **********************************************************************
 * vaiables
 **********************************************************************
 */
static const char *module_name = MYDISK_MODULE_NAME;

static int mydisk_device_major = 0;
static devfs_handle_t mydisk_devfs_handle = 0;

static list_t mydisk_request_list;
static list_t mydisk_request_freelist;

static spinlock_t mydisk_request_list_lock;
static spinlock_t mydisk_request_freelist_lock;

static wait_queue_head_t mydisk_request_waitqueue;

static unsigned mydisk_request_ids = 0;
static unsigned mydisk_request_free_id = -1;
static unsigned mydisk_request_id[MYDISK_REQUEST_IDS];
static mydisk_request_item_t *mydisk_request_item[MYDISK_REQUEST_IDS];

#if defined(MODULE)
/*
 **********************************************************************
 * module information
 **********************************************************************
 */
MODULE_AUTHOR("$author$");
MODULE_DESCRIPTION("mydisk");
MODULE_LICENSE("Copyright (c) 1988-2005 $organization$");

/*
 **********************************************************************
 * module parameters
 *
 * The following are module parameters. They are exported using
 * the MODULE_PARM(variable, type) and MODULE_PARM_DESC(variable, desc)
 * macros with the parameters as follows:
 *
 * variable - The identifier of the variable to be exported
 *
 * type - A string indicating the type of the variable
 *        "b" - byte
 *        "h" - short
 *        "i" - integer
 *        "l" - long
 *        "s" - char*
 *
 * desc - A string describing the module parameter.
 **********************************************************************
 */
MODULE_PARM(mydisk_device_major, "i");
#endif /* defined(MODULE) */

/**
 ************************************************************
 * Function: spin_unlock_interruptible_sleep_on
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Unlock a spin lock while preventing a race condition.
 ************************************************************
 */
static void spin_unlock_interruptible_sleep_on
(spinlock_t *lock, wait_queue_head_t *waitqueue)
{
    wait_queue_t wait;

    /* Add the current task to the wait queue.
     */
    init_waitqueue_entry(&wait, current);
    add_wait_queue(waitqueue, &wait);

    /* Set the state of kernel to INTERRUPTIBLE to
     * prevent task switching.
     */
    set_current_state(TASK_INTERRUPTIBLE);

    /* Unlock the spin lock.
     */
    spin_unlock(lock);

    /* Schedule and switch the next task by setting
     * the state of the kernel back to RUNNING.
     */
    schedule();
    set_current_state(TASK_RUNNING);

    /* Remove the curent task from the wait queue.
     */
    remove_wait_queue(waitqueue, &wait);
}

/**
 ************************************************************
 * Function: mydisk_get_request_item
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Get a request item from the free list, or by kmallocing
 * a new one.
 ************************************************************
 */
static mydisk_request_item_t *mydisk_get_request_item()
{
    unsigned id;
    mydisk_request_item_t *item;

    spin_lock(&mydisk_request_freelist_lock);

    /* I an item is available in the free list,
     * remove it from the free list.
     */
    if (&mydisk_request_freelist != (list_t*)
        (item = (mydisk_request_item_t*)
         (mydisk_request_freelist.next)))
    {
        dbprintk
        ("%s: %s() - Got a free item=0x%p...\n",
         module_name, __FUNCTION__, item);

        list_del_init(&item->list);

        spin_unlock(&mydisk_request_freelist_lock);
    }
    /* Otherwise create a new one.
     */
    else
    {
        /* Get the next available item id. The ids are used to
         * associate user space requests with kernel space
         * request items.
         */
        if ((id = mydisk_request_free_id) < mydisk_REQUEST_IDS)
            mydisk_request_free_id = mydisk_request_id[id];

        else if ((id = mydisk_request_ids) < mydisk_REQUEST_IDS)
                mydisk_request_id[mydisk_request_ids++] = -1;

        spin_unlock(&mydisk_request_freelist_lock);

        item = NULL;

        /* If the id is valid, create a new request.
         */
        if (id < mydisk_REQUEST_IDS)
        {
            /* If the kmalloc succedes, initialize the item.
             */
            if (NULL != (item = (mydisk_request_item_t*)kmalloc
                (sizeof(mydisk_request_item_t), GFP_KERNEL)))
            {
                dbprintk
                ("%s: %s() - kmalloced item=0x%p...\n",
                 module_name, __FUNCTION__, item);

                item->request.id = id;
                INIT_LIST_HEAD(&item->list);
                init_waitqueue_head(&item->waitqueue);
                mydisk_request_item[id] = item;
            }
            /* Otherwise free the id already allocated.
             */
            else
            {
                spin_lock(&mydisk_request_freelist_lock);

                mydisk_request_id[id] = mydisk_request_free_id;
                mydisk_request_free_id = id;

                spin_unlock(&mydisk_request_freelist_lock);
            }
        }
    }

    return item;
}

/**
 ************************************************************
 * Function: mydisk_free_request_item
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Add a request item to the free list.
 ************************************************************
 */
static void mydisk_free_request_item(mydisk_request_item_t *item)
{
    dbprintk
    ("%s: %s(mydisk_request_item_t *item=0x%p)\n",
     module_name, __FUNCTION__, item);

    spin_lock(&mydisk_request_freelist_lock);

    list_add(&item->list, &mydisk_request_freelist);

    spin_unlock(&mydisk_request_freelist_lock);
}

/**
 ************************************************************
 * Function: mydisk_free_request_freelist
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Free all of the items in the free list.
 ************************************************************
 */
static void mydisk_free_request_freelist()
{
    mydisk_request_item_t *item;

    dbprintk
    ("%s: %s()\n",
     module_name, __FUNCTION__);

    spin_lock(&mydisk_request_freelist_lock);

    /* Kfree all of the items in the free list.
     */
    while (&mydisk_request_freelist != (list_t*)
           (item = (mydisk_request_item_t*)
            (mydisk_request_freelist.next)))
    {
        dbprintk
        ("%s: %s() - kfreeing item=0x%p...\n",
         module_name, __FUNCTION__, item);

        list_del(&item->list);
        kfree(item);
    }

    /* Reset the id free list.
     */
    mydisk_request_ids = 0;
    mydisk_request_free_id = -1;

    spin_unlock(&mydisk_request_freelist_lock);
}

/**
 ************************************************************
 * Function: mydisk_wait_receive_request_item
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Wait to receive a request posted from another task.
 ************************************************************
 */
static mydisk_request_item_t *mydisk_wait_receive_request_item()
{
    int pending_signal;
    mydisk_request_item_t *item = NULL;

    dbprintk
    ("%s: %s(mydisk_request_item_t *item=0x%p)\n",
     module_name, __FUNCTION__, item);

    do
    {
        spin_lock(&mydisk_request_list_lock);

        /* If a request is available in the request
         * list, remove it from the list.
         */
        if (&mydisk_request_list != (list_t*)
            (item = (mydisk_request_item_t*)
             (mydisk_request_list.next)))
        {
            dbprintk
            ("%s: %s() - Got a request item=0x%p...\n",
             module_name, __FUNCTION__, item);

            list_del_init(&item->list);

            spin_unlock(&mydisk_request_list_lock);
            break;
        }
        /* Otherwise wait until a request is added to
         * the list.
         */
        else
        {
            item = NULL;

            dbprintk
            ("%s: %s() - sleeping...\n",
             module_name, __FUNCTION__);

            spin_unlock_interruptible_sleep_on
            (&mydisk_request_list_lock, 
             &mydisk_request_waitqueue);

            dbprintk
            ("%s: %s() - ...wokeup\n",
             module_name, __FUNCTION__);

            /* If a signal is received, stop checking, and 
             * return NULL.
             */
            if ((pending_signal = signal_pending(current)))
            {
                dbprintk
                ("%s: %s() - received signal\n",
                 module_name, __FUNCTION__);
                break;
            }
        }
    }
    while (NULL == item);

    return item;
}

/**
 ************************************************************
 * Function: mydisk_wait_service_request_item
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Add a request to the list, and wait for it to be 
 * serviced by another task.
 ************************************************************
 */
static int mydisk_wait_service_request_item(mydisk_request_item_t *item)
{
    int pending_signal = 1;

    dbprintk
    ("%s: %s(mydisk_request_item_t *item=0x%p)\n",
     module_name, __FUNCTION__, item);

    spin_lock(&mydisk_request_list_lock);

    list_add_tail(&item->list, &mydisk_request_list);

    /* Wakeup anyboby waiting for requests.
     */
    if (waitqueue_active(&mydisk_request_waitqueue))
    {
        dbprintk
        ("%s: %s() - Wakeup...\n",
         module_name, __FUNCTION__);

        wake_up(&mydisk_request_waitqueue);
    }

    dbprintk
    ("%s: %s() - Sleeping...\n",
     module_name, __FUNCTION__);

    spin_unlock_interruptible_sleep_on
    (&mydisk_request_list_lock, &item->waitqueue);

    /* If a signal is received, remove the request
     * from the list.
     */
    if ((pending_signal = signal_pending(current)))
    {
        dbprintk
        ("%s: %s() - received signal\n",
         module_name, __FUNCTION__);

        spin_lock(&mydisk_request_list_lock);

        list_del_init(&item->list);

        spin_unlock(&mydisk_request_list_lock);
    }

    return pending_signal;
}

/**
 **********************************************************************
 * Function: mydisk_open
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
static int mydisk_open
(struct inode *inode, struct file *file)
{
    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p)\n",
     module_name, __FUNCTION__, inode, file);

    MOD_INC_USE_COUNT;
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_release
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
static int mydisk_release
( struct inode *inode, struct file *file )
{
    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p)\n",
     module_name, __FUNCTION__, inode, file);

    MOD_DEC_USE_COUNT;
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_ioctl_resetmod
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
static int mydisk_ioctl_resetmod(unsigned long arg)
{
    dbprintk
    ("%s: %s(unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, arg );

    while (MOD_IN_USE)
        MOD_DEC_USE_COUNT;

    MOD_INC_USE_COUNT;
    return 0;
}

/**
 ************************************************************
 * Function: mydisk_ioctl_send_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Send a request from user space to kernel space to be
 * serviced by another task.
 ************************************************************
 */
static int mydisk_ioctl_send_request
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    int pending_signal;
    mydisk_request_item_t *item;
    mydisk_request_t *user_request;
    unsigned request_id;

    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_WRITE, (void*)
         (user_request=(mydisk_request_t*)arg), 
         sizeof(mydisk_request_t)))
    {
        dbprintk
        ("%s: %s() - verify_area failed\n", 
         module_name, __FUNCTION__);
        return -EFAULT;
    }

    /* If we are able to get a request item, copy the
     * request from user space, and place the item in
     * the request list. Then wait for the request to
     * be serviced by another task.
     */
    if (NULL != (item = mydisk_get_request_item()))
    {
        request_id = item->request.id;

        copy_from_user
        (&item->request, user_request, 
         sizeof(mydisk_request_t));

        item->request.id = request_id;

        dbprintk
        ("%s: %s() - Waiting on request id=0x%x type=0x%x\n",
         module_name, __FUNCTION__, 
         item->request.id, item->request.type);

        /* If a signal was received, free the item.
         */
        if ((pending_signal = mydisk_wait_service_request_item(item)))
        {
            dbprintk
            ("%s: %s() - received signal\n",
             module_name, __FUNCTION__);

            mydisk_free_request_item(item);
            mydisk_free_request_freelist();

            return -ERESTARTSYS;
        }

        dbprintk
        ("%s: %s() - Serviced request id=0x%x type=0x%x\n",
         module_name, __FUNCTION__, 
         item->request.id, item->request.type);

        /* Copy the results back to user space, and
         * free the item.
         */
        copy_to_user
        (user_request, &item->request, 
         sizeof(mydisk_request_t));

        mydisk_free_request_item(item);
        mydisk_free_request_freelist();

        return 0;
    }

    return -EINVAL;
}

/**
 ************************************************************
 * Function: mydisk_ioctl_receive_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Receive a request from another task, and copy it to
 * user space to be serviced.
 ************************************************************
 */
static int mydisk_ioctl_receive_request
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    mydisk_request_item_t *item;
    mydisk_request_t *user_request;

    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_WRITE, (void*)
         (user_request=(mydisk_request_t*)arg), 
         sizeof(mydisk_request_t)))
    {
        dbprintk
        ("%s: %s() - verify_area failed\n", 
         module_name, __FUNCTION__);
        return -EFAULT;
    }

    /* If we received a request from another task, copy
     * it to user space to be serviced.
     */
    if (NULL != (item = mydisk_wait_receive_request_item()))
    {
        dbprintk
        ("%s: %s() - Received request id=0x%x type=0x%x\n",
         module_name, __FUNCTION__, 
         item->request.id, item->request.type);

        copy_to_user
        (user_request, &item->request, 
         sizeof(mydisk_request_t));

        return 0;
    }

    /* Otherwise a signal must have been received. So we will
     * return -ERESTARTSYS for handling of the signal.
     */
    return -ERESTARTSYS;
}

/**
 ************************************************************
 * Function: mydisk_ioctl_service_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Copy a request serviced in user space to kernel space, and
 * wake up the task waiting for its completion.
 ************************************************************
 */
static int mydisk_ioctl_service_request
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    mydisk_request_item_t *item;
    mydisk_request_t *user_request;
    unsigned request_id;

    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_READ, (void*)
         (user_request=(mydisk_request_t*)arg), 
         sizeof(mydisk_request_t)))
    {
        dbprintk
        ("%s: %s() - verify_area failed\n", 
         module_name, __FUNCTION__);
        return -EFAULT;
    }

    copy_from_user
    (&request_id, &user_request->id, sizeof(request_id));

    /* If the request is a valid one, copy it from
     * user space, and wake up the waiting task.
     */
    if (request_id < mydisk_request_ids)
    if (NULL != (item = mydisk_request_item[request_id]))
    if (waitqueue_active(&item->waitqueue))
    {
        copy_from_user
        (&item->request, user_request, 
         sizeof(mydisk_request_t));

        /* Wakeup anyboby waiting for service.
         */
        wake_up(&item->waitqueue);

        return 0;
    }

    return -EINVAL;
}

/**
 **********************************************************************
 * Function: mydisk_ioctl
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
static int mydisk_ioctl
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, inode, file, cmd, arg );

    switch(cmd) 
    {
    case MYDISK_IOCTL_SEND_REQUEST:
        return mydisk_ioctl_send_request(inode, file, cmd, arg);

    case MYDISK_IOCTL_RECEIVE_REQUEST:
        return mydisk_ioctl_receive_request(inode, file, cmd, arg);

    case MYDISK_IOCTL_SERVICE_REQUEST:
        return mydisk_ioctl_service_request(inode, file, cmd, arg);

    case MYDISK_IOCTL_RESETMOD:
        return mydisk_ioctl_resetmod(arg);

    default:
        dbprintk
        ("%s: %s() - Invalid ioctl command 0x%x\n",
         module_name, __FUNCTION__, cmd);
        return -EINVAL;
    }
    
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_proc_info
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
static int mydisk_proc_info
(char *buffer, char **start, off_t offset, int length)
{
    char *p;
    
    p=buffer+sprintf(buffer, "%s Version $Id$\n", module_name);
    
    return p-buffer;
}

/*
 * Device file operations table
 */
static struct file_operations mydisk_file_operations = 
{
       open: mydisk_open,
    release: mydisk_release,
      ioctl: mydisk_ioctl
};

/**
 **********************************************************************
 * Function: mydisk_init
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
int __init mydisk_init(void)
{
    int dynamic_major;
    int devfs_major;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    INIT_LIST_HEAD(&mydisk_request_list);
    INIT_LIST_HEAD(&mydisk_request_freelist);
    spin_lock_init(&mydisk_request_list_lock);
    spin_lock_init(&mydisk_request_freelist_lock);
    init_waitqueue_head(&mydisk_request_waitqueue);


    /* Register the device file operations.
     */
    if ((devfs_major = devfs_register_chrdev
        (mydisk_device_major, 
         module_name, &mydisk_file_operations)) < 0)
    {
        printk
        ("%s: Unable to use device major %d\n", 
         module_name, mydisk_device_major);

        return devfs_major;
    }
    
    /* If the device major was obtained dynamically
     * via devfs, set the device major to the value
     * obtained from devfs.
     */
    if ((dynamic_major = !mydisk_device_major))
        mydisk_device_major = devfs_major;

    printk
    ("%s: Using device major %d\n", 
     module_name, mydisk_device_major);
     
    /* Create a /dev entry 
     */
    mydisk_devfs_handle = devfs_register
    (NULL, module_name, 
     dynamic_major? DEVFS_FL_AUTO_DEVNUM: DEVFS_FL_NONE,
     mydisk_device_major, 0, S_IFCHR | S_IRUSR | S_IWUSR, 
     &mydisk_file_operations, NULL);

    /* Create a /proc entry
     */
    create_proc_info_entry
    (module_name, 0, NULL, mydisk_proc_info);

    return 0;
}

#if defined(MODULE)
/**
 **********************************************************************
 * Function: mydisk_exit
 *
 *   Author: $author$
 *     Date: 8/8/2005
 **********************************************************************
 */
void mydisk_exit(void)
{
    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);
    
    /* Remove the /proc entry
     */
    remove_proc_entry(module_name, NULL);

    /* Remove the /dev entry
     */
    devfs_unregister(mydisk_devfs_handle);

    /* Unregister device file operations.
     */
    devfs_unregister_chrdev
    (mydisk_device_major, module_name);

}

/*
 * export module init and exit
 */
module_init(mydisk_init);
module_exit(mydisk_exit);
#endif /* defined(MODULE) */


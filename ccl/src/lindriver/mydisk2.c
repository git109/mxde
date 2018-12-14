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
 *   Date: 8/6/2005
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
#include <linux/fs.h>
#include <linux/hdreg.h>
#include <linux/blkdev.h>
#include <linux/proc_fs.h>
#include <linux/devfs_fs_kernel.h>
#include <linux/string.h>
#include <linux/completion.h>

#include <asm/page.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/system.h>
#include <asm/types.h>
#include <asm/irq.h>
#include <asm/io.h>

#if !defined(CLONE_SIGNAL)
#define CLONE_SIGNAL (CLONE_SIGHAND | CLONE_THREAD)
#endif

#define MYDISK_MODULE_NAME "mydisk"
#define MYDISK_MODULE_NAMEB MYDISK_MODULE_NAME "b"
static char *module_name = MYDISK_MODULE_NAME;
static char *module_nameb = MYDISK_MODULE_NAMEB;

#define MAJOR_NR mydisk_device_majorb
static int mydisk_device_majorb = 0;
static int mydisk_device_major = 0;

#define DEVICE_NR(device) MINOR(device) 
#define DEVICE_NAME MYDISK_MODULE_NAME
#define DEVICE_NO_RANDOM 
#define DEVICE_REQUEST mydisk_request
#define DEVICE_OFF(device) 

#include <linux/blk.h>

#include "mydisk.h"

/*
 **********************************************************************
 * defines
 **********************************************************************
 */
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

#define MYDISK_RAHEAD    1
#define MYDISK_BLOCKS    2880
#define MYDISK_BYTES     (MYDISK_BLOCKS * MYDISK_BLOCKSIZE)
#define MYDISK_KBYTES    (MYDISK_BYTES / 1024)

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
    spinlock_t lock;
    wait_queue_head_t waitqueue;
    void *data;
    mydisk_request_t request;
} mydisk_request_item_t;

/*
 **********************************************************************
 * vaiables
 **********************************************************************
 */
static int mydisk_device_minors = 1;
static devfs_handle_t mydisk_devfs_handle = 0;
static devfs_handle_t mydisk_devfs_handleb = 0;

static list_t mydisk_request_list;
static list_t mydisk_request_freelist;
static list_t mydisk_end_request_list;

static spinlock_t mydisk_request_list_lock;
static spinlock_t mydisk_request_freelist_lock;
static spinlock_t mydisk_end_request_list_lock;

static wait_queue_head_t mydisk_request_waitqueue;
static wait_queue_head_t mydisk_end_request_waitqueue;

static DECLARE_COMPLETION(mydisk_end_request_exited);
static int mydisk_wait_end_request_canceled = 0;
static pid_t mydisk_end_request_pid = -1;

static unsigned mydisk_request_ids = 0;
static unsigned mydisk_request_free_id = -1;
static unsigned mydisk_request_id[MYDISK_REQUEST_IDS];
static mydisk_request_item_t *mydisk_request_item[MYDISK_REQUEST_IDS];

static int mydisk_rahead = MYDISK_RAHEAD;
static int mydisk_size = MYDISK_KBYTES;
static int mydisk_blksize = MYDISK_BLOCKSIZE;
static int mydisk_hardsect = MYDISK_BLOCKSIZE;
static int mydisk_blocks = MYDISK_BLOCKS;

static int *mydisk_sizes = NULL;
static int *mydisk_blksizes = NULL;
static int *mydisk_hardsects = NULL;

static int mydisk_request_busy = 0;

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
MODULE_PARM(mydisk_device_majorb, "i");
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

    /* Schedule and switch the next task.
     */
    schedule();

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
        ("0x%p %s: %s() - Got a free item=0x%p...\n",
         current, module_name, __FUNCTION__, item);

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
        if ((id = mydisk_request_free_id) < MYDISK_REQUEST_IDS)
            mydisk_request_free_id = mydisk_request_id[id];

        else if ((id = mydisk_request_ids) < MYDISK_REQUEST_IDS)
                mydisk_request_id[mydisk_request_ids++] = -1;

        if (id < MYDISK_REQUEST_IDS)
            mydisk_request_item[id] = NULL;

        spin_unlock(&mydisk_request_freelist_lock);

        item = NULL;

        /* If the id is valid, create a new request.
         */
        if (id < MYDISK_REQUEST_IDS)
        {
            /* If the kmalloc succedes, initialize the item.
             */
            if (NULL != (item = (mydisk_request_item_t*)kmalloc
                (sizeof(mydisk_request_item_t), GFP_KERNEL)))
            {
                dbprintk
                ("0x%p %s: %s() - kmalloced item=0x%p...\n",
                 current, module_name, __FUNCTION__, item);

                item->request.id = id;
                INIT_LIST_HEAD(&item->list);
                spin_lock_init(&item->lock);
                init_waitqueue_head(&item->waitqueue);

                spin_lock(&mydisk_request_freelist_lock);
                mydisk_request_item[id] = item;
                spin_unlock(&mydisk_request_freelist_lock);
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
 * Function: mydisk_kfree_request_item
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Add a request item to the free list.
 ************************************************************
 */
static void mydisk_kfree_request_item(mydisk_request_item_t *item)
{
    dbprintk
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    dbprintk
    ("0x%p %s: %s() - freeing id=0x%x...\n",
     current, module_name, __FUNCTION__, item->request.id);

    /* Add the id to the id free list.
     */
    mydisk_request_id[item->request.id] = mydisk_request_free_id;
    mydisk_request_free_id = item->request.id;
    mydisk_request_item[item->request.id] = NULL;

    list_del(&item->list);

    dbprintk
    ("0x%p %s: %s() - kfreeing item=0x%p...\n",
     current, module_name, __FUNCTION__, item);

    kfree(item);
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
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    spin_lock(&mydisk_request_freelist_lock);

    mydisk_kfree_request_item(item);
    //list_add(&item->list, &mydisk_request_freelist);

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
    ("0x%p %s: %s()\n",
     current, module_name, __FUNCTION__);

    spin_lock(&mydisk_request_freelist_lock);

    /* Kfree all of the items in the free list.
     */
    while (&mydisk_request_freelist != (list_t*)
           (item = (mydisk_request_item_t*)
            (mydisk_request_freelist.next)))
        mydisk_kfree_request_item(item);

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
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

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
            ("0x%p %s: %s() - Got a request item=0x%p...\n",
             current, module_name, __FUNCTION__, item);

            list_del_init(&item->list);

            spin_unlock(&mydisk_request_list_lock);
        }
        /* Otherwise wait until a request is added to
         * the list.
         */
        else
        {
            item = NULL;

            dbprintk
            ("0x%p %s: %s() - Requests Sleeping...\n",
             current, module_name, __FUNCTION__);

            spin_unlock_interruptible_sleep_on
            (&mydisk_request_list_lock, 
             &mydisk_request_waitqueue);

            dbprintk
            ("0x%p %s: %s() - Requests ...Wokeup\n",
             current, module_name, __FUNCTION__);

            /* If a signal is received, stop checking, and 
             * return NULL.
             */
            if ((pending_signal = signal_pending(current)))
            {
                dbprintk
                ("0x%p %s: %s() - received signal\n",
                 current, module_name, __FUNCTION__);
                break;
            }
        }
    }
    while (NULL == item);

    return item;
}

/**
 ************************************************************
 * Function: mydisk_wait_end_request_item
 *
 *   Author: $author$
 *     Date: 8/10/2005
 *
 * Wait to receive a request posted from another task.
 ************************************************************
 */
static mydisk_request_item_t *mydisk_wait_end_request_item()
{
    int pending_signal;
    mydisk_request_item_t *item = NULL;

    dbprintk
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    do
    {
        spin_lock(&mydisk_end_request_list_lock);

        /* If a request is available in the request
         * list, remove it from the list.
         */
        if (&mydisk_end_request_list != (list_t*)
            (item = (mydisk_request_item_t*)
             (mydisk_end_request_list.next)))
        {
            dbprintk
            ("0x%p %s: %s() - Got an end request item=0x%p...\n",
             current, module_name, __FUNCTION__, item);

            list_del_init(&item->list);

            spin_unlock(&mydisk_end_request_list_lock);
        }
        /* Otherwise wait until a request is added to
         * the list.
         */
        else
        {
            item = NULL;

            dbprintk
            ("0x%p %s: %s() - End Requests Sleeping...\n",
             current, module_name, __FUNCTION__);

            spin_unlock_interruptible_sleep_on
            (&mydisk_end_request_list_lock, 
             &mydisk_end_request_waitqueue);

            dbprintk
            ("0x%p %s: %s() - End Requests ...Wokeup\n",
             current, module_name, __FUNCTION__);

            /* If a signal is received, stop checking, and 
             * return NULL.
             */
            if ((pending_signal = signal_pending(current)))
            {
                dbprintk
                ("0x%p %s: %s() - received signal\n",
                 current, module_name, __FUNCTION__);
                break;
            }
            else if (mydisk_wait_end_request_canceled)
            {
                dbprintk
                ("0x%p %s: %s() - canceled\n",
                 current, module_name, __FUNCTION__);
                break;
            }
        }
    }
    while (NULL == item);

    return item;
}

/**
 ************************************************************
 * Function: mydisk_cancel_wait_end_request
 *
 *   Author: $author$
 *     Date: 8/10/2005
 ************************************************************
 */
static void mydisk_cancel_wait_end_request()
{
    dbprintk
    ("0x%p %s: %s()\n",
     current, module_name, __FUNCTION__);

    spin_lock(&mydisk_end_request_list_lock);

    mydisk_wait_end_request_canceled = 1;

    /* Wakeup anyboby waiting for requests.
     */
    if (waitqueue_active(&mydisk_end_request_waitqueue))
    {
        dbprintk
        ("0x%p %s: %s() - End Requests Wakeup...\n",
         current, module_name, __FUNCTION__);

        wake_up(&mydisk_end_request_waitqueue);
    }

    spin_unlock(&mydisk_end_request_list_lock);
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
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    spin_lock(&mydisk_request_list_lock);

    list_add_tail(&item->list, &mydisk_request_list);

    /* Wakeup anyboby waiting for requests.
     */
    if (waitqueue_active(&mydisk_request_waitqueue))
    {
        dbprintk
        ("0x%p %s: %s() - Requests Wakeup...\n",
         current, module_name, __FUNCTION__);

        wake_up(&mydisk_request_waitqueue);
    }

    dbprintk
    ("0x%p %s: %s() - Item Sleeping...\n",
     current, module_name, __FUNCTION__);

    spin_lock(&item->lock);
    spin_unlock(&mydisk_request_list_lock);

    spin_unlock_interruptible_sleep_on
    (&item->lock, &item->waitqueue);

    dbprintk
    ("0x%p %s: %s() - Item ...Wokeup\n",
     current, module_name, __FUNCTION__);

    /* If a signal is received, remove the request
     * from the list.
     */
    if ((pending_signal = signal_pending(current)))
    {
        dbprintk
        ("0x%p %s: %s() - received signal\n",
         current, module_name, __FUNCTION__);

        spin_lock(&mydisk_request_list_lock);

        if (&item->list != item->list.next)
            list_del_init(&item->list);

        spin_unlock(&mydisk_request_list_lock);
    }

    return pending_signal;
}

/**
 ************************************************************
 * Function: mydisk_add_request_item
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Add a request to the list.
 ************************************************************
 */
static void mydisk_add_request_item(mydisk_request_item_t *item)
{
    dbprintk
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    spin_lock(&mydisk_request_list_lock);

    list_add_tail(&item->list, &mydisk_request_list);

    /* Wakeup anyboby waiting for requests.
     */
    if (waitqueue_active(&mydisk_request_waitqueue))
    {
        dbprintk
        ("0x%p %s: %s() - Requests Wakeup...\n",
         current, module_name, __FUNCTION__);

        wake_up(&mydisk_request_waitqueue);
    }

    spin_unlock(&mydisk_request_list_lock);
}

/**
 ************************************************************
 * Function: mydisk_add_end_request_item
 *
 *   Author: $author$
 *     Date: 8/10/2005
 *
 * Add a request to the list.
 ************************************************************
 */
static void mydisk_add_end_request_item(mydisk_request_item_t *item)
{
    dbprintk
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    spin_lock(&mydisk_end_request_list_lock);

    list_add_tail(&item->list, &mydisk_end_request_list);

    /* Wakeup anyboby waiting for end requests.
     */
    if (waitqueue_active(&mydisk_end_request_waitqueue))
    {
        dbprintk
        ("0x%p %s: %s() - End Requests Wakeup...\n",
         current, module_name, __FUNCTION__);

        wake_up(&mydisk_end_request_waitqueue);
    }

    spin_unlock(&mydisk_end_request_list_lock);
}

/**
 **********************************************************************
 * Function: mydisk_open
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_open
(struct inode *inode, struct file *file)
{
    dbprintk
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p)\n",
     current, module_name, __FUNCTION__, inode, file);

    MOD_INC_USE_COUNT;
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_release
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_release
( struct inode *inode, struct file *file )
{
    dbprintk
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p)\n",
     current, module_name, __FUNCTION__, inode, file);

    MOD_DEC_USE_COUNT;
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_ioctl_resetmod
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_ioctl_resetmod(unsigned long arg)
{
    dbprintk
    ("0x%p %s: %s(unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, arg );

    while (MOD_IN_USE)
        MOD_DEC_USE_COUNT;

    MOD_INC_USE_COUNT;
    return 0;
}

/**
 ************************************************************
 * Function: mydisk_send_geometry_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Send a geometry request to be serviced by another task.
 ************************************************************
 */
static int mydisk_send_geometry_request
(struct hd_geometry *geometry)
{
    int result = 0;
    int pending_signal;
    mydisk_request_item_t *item;

    dbprintk
    ("0x%p %s: %s(struct hd_geometry *geometry=0x%p)\n",
     current, module_name, __FUNCTION__, geometry);

    if (NULL == (item = mydisk_get_request_item()))
        return result = -ENOMEM;

    item->request.type = e_MYDISK_GEOMETRY_REQUEST;
    item->request.geometry.status = -EINVAL;
    item->request.geometry.heads = 0;
    item->request.geometry.cylinders = 0;
    item->request.geometry.sectors = mydisk_hardsect;
    item->request.geometry.start = mydisk_size;

    /* If a signal was received, free the item.
     */
    if ((pending_signal = mydisk_wait_service_request_item(item)))
    {
    	dbprintk
    	("0x%p %s: %s() - received signal\n",
     	current, module_name, __FUNCTION__);

    	result = -ERESTARTSYS;
    }
    else if (item->request.geometry.status)
    {
    	dbprintk
    	("0x%p %s: %s() - received status=%d\n",
     	current, module_name, __FUNCTION__,
        item->request.geometry.status);

        result = -EFAULT;
    }
    else
    {
        geometry->heads = item->request.geometry.heads;
        geometry->cylinders = item->request.geometry.cylinders;
        geometry->sectors = item->request.geometry.sectors;
        geometry->start = item->request.geometry.start;
    }

    mydisk_free_request_item(item);
    return result;
}

/**
 ************************************************************
 * Function: mydisk_create_block_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Create a block request to be serviced by another task.
 ************************************************************
 */
static mydisk_request_item_t *mydisk_create_block_request
(unsigned int type, unsigned long lun,
 unsigned long lba, unsigned long length,
 mydisk_block_t *block)
{
    mydisk_request_item_t *item;

    dbprintk
    ("0x%p %s: %s(mydisk_block_t *block=0x%p)\n",
     current, module_name, __FUNCTION__, block);

    if (NULL == (item = mydisk_get_request_item()))
        return item;

    item->data = block;
    item->request.type = e_MYDISK_BLOCK_REQUEST;
    item->request.block.status = -EINVAL;
    item->request.block.type = type;
    item->request.block.lun = lun;
    item->request.block.lba = lba;
    item->request.block.length = length;

    if (e_MYDISK_WRITE_BLOCK_REQUEST == type)
        memcpy
        (&item->request.block.block, 
         block, sizeof(mydisk_block_t));

    return item;
}

/**
 ************************************************************
 * Function: mydisk_send_block_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Send a block request to be serviced by another task.
 ************************************************************
 */
static int mydisk_send_block_request
(unsigned int type, unsigned long lun,
 unsigned long lba, unsigned long length,
 mydisk_block_t *block)
{
    int result = 0;
    int pending_signal;
    mydisk_request_item_t *item;

    dbprintk
    ("0x%p %s: %s(mydisk_block_t *block=0x%p)\n",
     current, module_name, __FUNCTION__, block);

    if (NULL == (item = mydisk_create_block_request
        (type, lun, lba, length, block)))
        return result = -ENOMEM;

    /* If a signal was received, free the item.
     */
    if ((pending_signal = mydisk_wait_service_request_item(item)))
    {
    	dbprintk
    	("0x%p %s: %s() - received signal\n",
     	current, module_name, __FUNCTION__);

    	result = -ERESTARTSYS;
    }
    else if (item->request.block.status)
    {
    	dbprintk
    	("0x%p %s: %s() - received status=%d\n",
     	current, module_name, __FUNCTION__, item->request.block.status);

        result = -EFAULT;
    }

    else if (e_MYDISK_READ_BLOCK_REQUEST == type)
            memcpy
            (block, &item->request.block.block, 
             sizeof(mydisk_block_t));

    mydisk_free_request_item(item);
    return result;
}

/**
 ************************************************************
 * Function: mydisk_post_block_request
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Send a block request to be serviced by another task.
 ************************************************************
 */
static int mydisk_post_block_request
(unsigned int type, unsigned long lun,
 unsigned long lba, unsigned long length,
 mydisk_block_t *block)
{
    int result = 0;
    mydisk_request_item_t *item;

    dbprintk
    ("0x%p %s: %s(mydisk_block_t *block=0x%p)\n",
     current, module_name, __FUNCTION__, block);

    if (NULL == (item = mydisk_create_block_request
        (type, lun, lba, length, block)))
        return result = -ENOMEM;

    mydisk_add_request_item(item);
    return result;
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
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_WRITE, (void*)
         (user_request=(mydisk_request_t*)arg), 
         sizeof(mydisk_request_t)))
    {
        dbprintk
        ("0x%p %s: %s() - verify_area failed\n", 
         current, module_name, __FUNCTION__);
        return -EFAULT;
    }

    /* If we are able to get a request item, copy the
     * request from user space, and place the item in
     * the request list. Then wait for the request to
     * be serviced by another task.
     */
    if (NULL != (item = mydisk_get_request_item()))
    {
        spin_lock(&item->lock);

        request_id = item->request.id;

        copy_from_user
        (&item->request, user_request, 
         sizeof(mydisk_request_t));

        item->request.id = request_id;

        spin_unlock(&item->lock);

        dbprintk
        ("0x%p %s: %s() - Waiting on request id=0x%x type=0x%x\n",
         current, module_name, __FUNCTION__, 
         item->request.id, item->request.type);

        /* If a signal was received, free the item.
         */
        if ((pending_signal = mydisk_wait_service_request_item(item)))
        {
            dbprintk
            ("0x%p %s: %s() - received signal\n",
             current, module_name, __FUNCTION__);

            mydisk_free_request_item(item);

            return -ERESTARTSYS;
        }

        dbprintk
        ("0x%p %s: %s() - Serviced request id=0x%x type=0x%x\n",
         current, module_name, __FUNCTION__, 
         item->request.id, item->request.type);

        spin_lock(&item->lock);

        /* Copy the results back to user space, and
         * free the item.
         */
        copy_to_user
        (user_request, &item->request, 
         sizeof(mydisk_request_t));

        spin_unlock(&item->lock);

        mydisk_free_request_item(item);

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
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_WRITE, (void*)
         (user_request=(mydisk_request_t*)arg), 
         sizeof(mydisk_request_t)))
    {
        dbprintk
        ("0x%p %s: %s() - verify_area failed\n", 
         current, module_name, __FUNCTION__);
        return -EFAULT;
    }

    /* If we received a request from another task, copy
     * it to user space to be serviced.
     */
    if (NULL != (item = mydisk_wait_receive_request_item()))
    {
        dbprintk
        ("0x%p %s: %s() - Received request id=0x%x type=0x%x\n",
         current, module_name, __FUNCTION__, 
         item->request.id, item->request.type);

        spin_lock(&item->lock);

        copy_to_user
        (user_request, &item->request, 
         sizeof(mydisk_request_t));

        spin_unlock(&item->lock);
        return 0;
    }

    /* Otherwise a signal must have been received. So we will
     * return -ERESTARTSYS for handling of the signal.
     */
    return -ERESTARTSYS;
}

/**
 **********************************************************************
 * Function: mydisk_end_request
 *
 *   Author: $author$
 *     Date: 8/9/2005
 **********************************************************************
 */
static void mydisk_end_request(int success)
{
    dbprintk
    ("0x%p %s: %s(int success=%d)\n",
     current, module_name, __FUNCTION__, success);

    spin_lock_irq(&io_request_lock);

    end_request(success);
    mydisk_request_busy = 0;

    mydisk_request(BLK_DEFAULT_QUEUE(mydisk_device_majorb));

    spin_unlock_irq(&io_request_lock);
}

/**
 **********************************************************************
 * Function: mydisk_service_end_request
 *
 *   Author: $author$
 *     Date: 8/10/2005
 **********************************************************************
 */
static void mydisk_service_end_request(mydisk_request_item_t *item)
{
    int success;

    dbprintk
    ("0x%p %s: %s(mydisk_request_item_t *item=0x%p)\n",
     current, module_name, __FUNCTION__, item);

    switch(item->request.type)
    {
    case e_MYDISK_BLOCK_REQUEST:
        success = !item->request.block.status;
        switch(item->request.block.type)
        {
        case e_MYDISK_READ_BLOCK_REQUEST:
            memcpy
            (item->data, 
             &item->request.block.block, 
             sizeof(mydisk_block_t));
            break;
        }
        mydisk_end_request(success);
        break;
    }
}

/**
 **********************************************************************
 * Function: mydisk_end_request_thread
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_end_request_thread(void *data)
{
    mydisk_request_item_t *item;

	daemonize();

    dbprintk
    ("0x%p %s: %s(void *data=0x%p)...\n",
     current, module_name, __FUNCTION__, data);

    while ((item = mydisk_wait_end_request_item()))
    {
        mydisk_service_end_request(item);
        mydisk_free_request_item(item);
    }

    dbprintk
    ("0x%p %s: ...%s(void *data=0x%p)\n",
     current, module_name, __FUNCTION__, data);

	complete_and_exit(&mydisk_end_request_exited, 0);
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
    int result = -EINVAL;
    mydisk_request_item_t *item = NULL;
    mydisk_request_t *user_request;
    unsigned request_id;

    dbprintk
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_READ, (void*)
         (user_request=(mydisk_request_t*)arg), 
         sizeof(mydisk_request_t)))
    {
        dbprintk
        ("0x%p %s: %s() - verify_area failed\n", 
         current, module_name, __FUNCTION__);
        return -EFAULT;
    }

    copy_from_user
    (&request_id, user_request, sizeof(request_id));

    spin_lock(&mydisk_request_freelist_lock);

    /* If the request is a valid one, copy it from
     * user space, and wake up the waiting task.
     */
    if (request_id < mydisk_request_ids)
        item = mydisk_request_item[request_id];

    spin_unlock(&mydisk_request_freelist_lock);

    if (NULL != item)
    {
        spin_lock(&item->lock);

        copy_from_user
        (&item->request, user_request, 
         sizeof(mydisk_request_t));

        if (waitqueue_active(&item->waitqueue))
        {
            dbprintk
            ("0x%p %s: %s() - Item Wakeup...\n",
             current, module_name, __FUNCTION__);

            /* Wakeup anyboby waiting for service.
             */
            wake_up(&item->waitqueue);
            spin_unlock(&item->lock);
            result = 0;
        }
        else
        {
            mydisk_add_end_request_item(item);
            spin_unlock(&item->lock);
        }
    }

    return result;
}

/**
 ************************************************************
 * Function: mydisk_ioctl_blk_getsize
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Send a request from user space to kernel space to be
 * serviced by another task.
 ************************************************************
 */
static int mydisk_ioctl_blk_getsize
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    int result = -EINVAL;

    dbprintk
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, inode, file, cmd, arg );

    return result;
}

/**
 ************************************************************
 * Function: mydisk_ioctl_hdio_getgeo
 *
 *   Author: $author$
 *     Date: 8/8/2005
 *
 * Send a request from user space to kernel space to be
 * serviced by another task.
 ************************************************************
 */
static int mydisk_ioctl_hdio_getgeo
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    int result = 0;
    struct hd_geometry *user_geometry;
    struct hd_geometry geometry;

    dbprintk
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, inode, file, cmd, arg );

    if (verify_area
        (VERIFY_WRITE, (void*)
         (user_geometry = (struct hd_geometry*)arg), 
         sizeof(struct hd_geometry)))
    {
        dbprintk
        ("0x%p %s: %s() - verify_area failed\n", 
         current, module_name, __FUNCTION__);

        return result = -EFAULT;
    }

    geometry.heads = 2;
    geometry.cylinders = 45;
    geometry.sectors = 8;
    geometry.start = 0;

    if ((result = mydisk_send_geometry_request(&geometry)))
        return result;

    copy_to_user
    (user_geometry, &geometry, 
     sizeof(struct hd_geometry));

    return result;
}

/**
 **********************************************************************
 * Function: mydisk_ioctl
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_ioctl
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    dbprintk
    ("0x%p %s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     current, module_name, __FUNCTION__, inode, file, cmd, arg);

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

    case BLKGETSIZE:
        return mydisk_ioctl_blk_getsize(inode, file, cmd, arg);

    case HDIO_GETGEO:
        return mydisk_ioctl_hdio_getgeo(inode, file, cmd, arg);

    default:
        dbprintk
        ("0x%p %s: %s() - Invalid ioctl command 0x%x\n",
         current, module_name, __FUNCTION__, cmd);
        return -EINVAL;
    }
    
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_check_media_change
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_check_media_change(kdev_t dev)
{
    dbprintk
    ("0x%p %s: %s(kdev_t dev=0x%x)\n",
     current, module_name, __FUNCTION__, dev);

    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_revalidate
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_revalidate(kdev_t dev)
{
    dbprintk
    ("0x%p %s: %s(kdev_t dev=0x%x)\n",
     current, module_name, __FUNCTION__, dev);

    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_request
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static void mydisk_request(request_queue_t *q)
{

    static int r_once = 0;
    static int w_once = 0;

    int err = 0;
    int success = 0;
    unsigned int type;
    unsigned long lun;
    unsigned long lba;
    unsigned long length;
    mydisk_block_t *block;
/*
    struct request *request;
*/
    dbprintk
    ("0x%p %s: %s(request_queue_t *q=0x%p)\n",
     current, module_name, __FUNCTION__, q);

    if (mydisk_request_busy)
        return;

    do 
    {
        INIT_REQUEST;

        dbprintk
        ("0x%p %s: %s - %s block=%lu length=%lu\n",
         current, module_name, __FUNCTION__, 
         (WRITE != CURRENT->cmd)?"Read":"Write", 
         CURRENT->sector, CURRENT->current_nr_sectors);

        type = (WRITE != CURRENT->cmd)
        ?e_MYDISK_READ_BLOCK_REQUEST
        :e_MYDISK_WRITE_BLOCK_REQUEST;
        lun = DEVICE_NR(CURRENT->rq_dev);
        lba = CURRENT->sector;
        length = CURRENT->current_nr_sectors;
        block = (mydisk_block_t*)(CURRENT->buffer);
/*
        if ((r_once && (e_MYDISK_READ_BLOCK_REQUEST == type)) 
            || (w_once && (e_MYDISK_WRITE_BLOCK_REQUEST == type)))
            success = (e_MYDISK_READ_BLOCK_REQUEST == type);
        else
*/
        if ((success = !(err = mydisk_post_block_request
            (type, lun, lba, length, block))))
        {

            if (e_MYDISK_READ_BLOCK_REQUEST == type)
                r_once = 1;
            else w_once = 1;

            mydisk_request_busy = 1;
            break;
        }

        end_request(success);

        if (e_MYDISK_READ_BLOCK_REQUEST == type)
            r_once = 1;
        else w_once = 1;

    }
    while(1);
/*
    do 
    {
        INIT_REQUEST;

        dbprintk
        ("%s: %s - %s block=%lu length=%lu\n",
         module_name, __FUNCTION__, 
         (WRITE != CURRENT->cmd)?"Read":"Write", 
         CURRENT->sector, CURRENT->current_nr_sectors);

        if (-ERESTARTSYS != err)
        {
            type = (WRITE != CURRENT->cmd)
            ?e_MYDISK_READ_BLOCK_REQUEST
            :e_MYDISK_WRITE_BLOCK_REQUEST;
            lun = DEVICE_NR(CURRENT->rq_dev);
            lba = CURRENT->sector;
            length = CURRENT->current_nr_sectors;
            block = (mydisk_block_t*)(CURRENT->buffer);

            success = !(err = mydisk_send_block_request
            (type, lun, lba, length, block));
        }

        end_request(success);
    }
    while(1);

    mydisk_request_busy = 1;

    while (!list_empty(&q->queue_head))
    {
        request = blkdev_entry_next_request(&q->queue_head);
        blkdev_dequeue_request(request);
        spin_unlock_irq(&io_request_lock);
        do
        {
            dbprintk
            ("%s: %s - %s block=%lu length=%lu\n",
             module_name, __FUNCTION__, 
             (WRITE != request->cmd)?"Read":"Write", 
             request->sector, request->current_nr_sectors);

            type = (WRITE != request->cmd)
            ?e_MYDISK_READ_BLOCK_REQUEST
            :e_MYDISK_WRITE_BLOCK_REQUEST;
            lun = DEVICE_NR(request->rq_dev);
            lba = request->sector;
            length = request->current_nr_sectors;
            block = (mydisk_block_t*)(request->buffer);

            success = !(err = mydisk_send_block_request
            (type, lun, lba, length, block));
        }
        while (end_that_request_first(request, success, DEVICE_NAME));
        spin_lock_irq(&io_request_lock);
        end_that_request_last(request);
    }

    mydisk_request_busy = 0;
*/
}

/**
 **********************************************************************
 * Function: mydisk_proc_info
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
static int mydisk_proc_info
(char *buffer, char **start, off_t offset, int length)
{
    char *p;
    
    p=buffer+sprintf(buffer, "%s Version $Id$\n", module_name);
    p+=sprintf(p, "%s MOD_IN_USE = %d\n", module_name, MOD_IN_USE);
    
    return p-buffer;
}

/*
 * Block device operations table
 */
static struct block_device_operations mydisk_block_device_operations = 
{
                  open: mydisk_open,
               release: mydisk_release,
                 ioctl: mydisk_ioctl,
    check_media_change: mydisk_check_media_change,
            revalidate: mydisk_revalidate
};

/*
 * Device file operations table
 */
static struct file_operations mydisk_device_operations = 
{
                  open: mydisk_open,
               release: mydisk_release,
                 ioctl: mydisk_ioctl,
};

/**
 **********************************************************************
 * Function: mydisk_init_chrdev
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
int mydisk_init_chrdev(void)
{
    int dynamic_major;
    int devfs_major;

    dbprintk
    ("0x%p %s: %s()\n", 
     current, module_name, __FUNCTION__);

    /* Register the device operations.
     */
    if ((devfs_major = devfs_register_chrdev
        (mydisk_device_major,  module_name, 
         &mydisk_device_operations)) < 0)
    {
        printk
        ("%s: Unable to register device major %d\n", 
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
    ("%s: Using %s device major %d\n", 
     module_name, dynamic_major
     ?"dynamic":"static", mydisk_device_major);
     
    /* Create a /dev entry 
     */
    mydisk_devfs_handle = devfs_register
    (NULL, module_name, 
     dynamic_major? DEVFS_FL_AUTO_DEVNUM: DEVFS_FL_NONE,
     mydisk_device_major, 0, S_IFCHR | S_IRUSR | S_IWUSR, 
     &mydisk_device_operations, NULL);

    /* Create a /proc entry
     */
    create_proc_info_entry
    (module_name, 0, NULL, mydisk_proc_info);
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_exit_chrdev
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
void mydisk_exit_chrdev(void)
{
    dbprintk
    ("0x%p %s: %s()\n", 
     current, module_name, __FUNCTION__);
    
    /* Remove the /proc entry
     */
    remove_proc_entry(module_name, NULL);

    /* Remove the /dev entry
     */
    devfs_unregister(mydisk_devfs_handle);

    /* Unregister device operations.
     */
    devfs_unregister_chrdev
    (mydisk_device_major, module_name);
}

/**
 **********************************************************************
 * Function: mydisk_init_blkdev
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
int mydisk_init_blkdev(void)
{
    int dynamic_major;
    int devfs_major;
    int device_minor;

    dbprintk
    ("0x%p %s: %s()\n", 
     current, module_name, __FUNCTION__);

    if (!(mydisk_sizes = kmalloc
          (mydisk_device_minors * sizeof(int), GFP_KERNEL)))
        return -ENOMEM;

    else if (!(mydisk_blksizes = kmalloc
               (mydisk_device_minors * sizeof(int), GFP_KERNEL)))
    {
        kfree(mydisk_sizes);
        return -ENOMEM;
    }
    else if (!(mydisk_hardsects = kmalloc
              (mydisk_device_minors * sizeof(int), GFP_KERNEL)))
    {
        kfree(mydisk_blksizes);
        kfree(mydisk_sizes);
        return -ENOMEM;
    }

    for (device_minor=0; 
         device_minor<mydisk_device_minors; device_minor++)
    {
        mydisk_sizes[device_minor] = mydisk_size;
        mydisk_blksizes[device_minor] = mydisk_blksize;
        mydisk_hardsects[device_minor] = mydisk_hardsect;
    }

    /* Register the block device operations.
     */
    if ((devfs_major = devfs_register_blkdev
        (mydisk_device_majorb, module_nameb, 
         &mydisk_block_device_operations)) < 0)
    {
        printk
        ("%s: Unable to register block device major %d\n", 
         module_name, mydisk_device_majorb);

        kfree(mydisk_hardsects);
        kfree(mydisk_blksizes);
        kfree(mydisk_sizes);
        return devfs_major;
    }
    
    /* If the device major was obtained dynamically
     * via devfs, set the device major to the value
     * obtained from devfs.
     */
    if ((dynamic_major = !mydisk_device_majorb))
        mydisk_device_majorb = devfs_major;

    printk
    ("%s: Using %s block device major %d\n", 
     module_name, dynamic_major
     ?"dynamic":"static", mydisk_device_majorb);
     
    /* Create a /dev entry 
     */
    mydisk_devfs_handleb = devfs_register
    (NULL, module_nameb, 
     dynamic_major? DEVFS_FL_AUTO_DEVNUM: DEVFS_FL_NONE,
     mydisk_device_majorb, 0, S_IFBLK | S_IRUSR | S_IWUSR, 
     &mydisk_block_device_operations, NULL);

    blk_size[mydisk_device_majorb] = mydisk_sizes;
    blksize_size[mydisk_device_majorb] = mydisk_blksizes;
    hardsect_size[mydisk_device_majorb] = mydisk_hardsects;
    read_ahead[mydisk_device_majorb] = mydisk_rahead;

    blk_init_queue
    (BLK_DEFAULT_QUEUE(mydisk_device_majorb), mydisk_request);

    for (device_minor=0; 
         device_minor<mydisk_device_minors; device_minor++)
        register_disk
        (NULL, MKDEV(mydisk_device_majorb, device_minor), 
         1, &mydisk_block_device_operations, mydisk_blocks);

	mydisk_end_request_pid = kernel_thread
    (mydisk_end_request_thread, NULL, 
     CLONE_FS | CLONE_FILES | CLONE_SIGNAL);
    return 0;
}

/**
 **********************************************************************
 * Function: mydisk_init
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
int __init mydisk_init(void)
{
    int result;

    dbprintk
    ("0x%p %s: %s()\n", 
     current, module_name, __FUNCTION__);

    INIT_LIST_HEAD(&mydisk_request_list);
    INIT_LIST_HEAD(&mydisk_request_freelist);
    INIT_LIST_HEAD(&mydisk_end_request_list);
    spin_lock_init(&mydisk_request_list_lock);
    spin_lock_init(&mydisk_request_freelist_lock);
    spin_lock_init(&mydisk_end_request_list_lock);
    init_waitqueue_head(&mydisk_request_waitqueue);
    init_waitqueue_head(&mydisk_end_request_waitqueue);

    if (!(result = mydisk_init_chrdev()))
    if ((result = mydisk_init_blkdev()))
        mydisk_exit_chrdev();
    return result;
}

#if defined(MODULE)
/**
 **********************************************************************
 * Function: mydisk_exit_blkdev
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
void mydisk_exit_blkdev(void)
{
    int device_minor;

    dbprintk
    ("0x%p %s: %s()\n", 
     current, module_name, __FUNCTION__);
    
    if (0 < mydisk_end_request_pid)
    {
        mydisk_cancel_wait_end_request();
	    wait_for_completion(&mydisk_end_request_exited);
    }

    /* Remove the /dev entry
     */
    devfs_unregister(mydisk_devfs_handleb);

    for (device_minor=0; 
         device_minor<mydisk_device_minors; device_minor++)
        fsync_dev
        (MKDEV(mydisk_device_majorb, device_minor));

    /* Unregister block device operations.
     */
    devfs_unregister_blkdev
    (mydisk_device_majorb, module_nameb);

    blk_cleanup_queue
    (BLK_DEFAULT_QUEUE(mydisk_device_majorb));

    hardsect_size[mydisk_device_majorb] = NULL;
    blksize_size[mydisk_device_majorb] = NULL;
    blk_size[mydisk_device_majorb] = NULL;
    read_ahead[mydisk_device_majorb] = 0;

    kfree(mydisk_hardsects);
    kfree(mydisk_blksizes);
    kfree(mydisk_sizes);
}

/**
 **********************************************************************
 * Function: mydisk_exit
 *
 *   Author: $author$
 *     Date: 8/6/2005
 **********************************************************************
 */
void mydisk_exit(void)
{
    dbprintk
    ("0x%p %s: %s()\n", 
     current, module_name, __FUNCTION__);

    mydisk_exit_blkdev();
    mydisk_exit_chrdev();
    mydisk_free_request_freelist();
}

/*
 * export module init and exit
 */
module_init(mydisk_init);
module_exit(mydisk_exit);
#endif /* defined(MODULE) */


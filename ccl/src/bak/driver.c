/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: driver.c
 *
 * Author: $author$
 *   Date: 7/27/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/locks.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
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

#include "driver.h"

/*
 **********************************************************************
 * defines
 **********************************************************************
 */

#define DRIVER_MODULE_NAME "driver"
#define DRIVER_PCI_VENDOR_ID 0x12de
#define DRIVER_PCI_DEVICE_ID 0x0002
#define DRIVER_MAX_PCI_DEVICES 16

#if defined(_DBPRINTK)
#define dbprintk(args...) printk(args)
#else
#define dbprintk(args...)
#endif

#define cs_read_control(reg) inl_p((int)reg)
#define cs_write_control(reg, val) outl_p(val, (int)reg)

/*
 **********************************************************************
 * types
 **********************************************************************
 */

/**
 **********************************************************************
 * Struct: driver_pci_device
 *
 * Author: $author$
 *   Date: 7/27/2003
 **********************************************************************
 */
typedef struct driver_pci_device
{
    unsigned flags;
    int vendor_id;
    int device_id;
    struct pci_dev *pci_dev;
    volatile cs_regs_t *io_regs;
    volatile cs_regs_t *regs;
    unsigned char irq;
    void (*irq_handler)
    (struct driver_pci_device *device, 
     int irq, struct pt_regs *regs);
} driver_pci_device_t;

/*
 **********************************************************************
 * vaiables
 **********************************************************************
 */
static const char *module_name = DRIVER_MODULE_NAME;

static int driver_device_major = 0;
static devfs_handle_t driver_devfs_handle = 0;

static int driver_pci_vendor_id = DRIVER_PCI_VENDOR_ID;
static int driver_pci_device_id = DRIVER_PCI_DEVICE_ID;
static int driver_pci_device_count = 0;
static driver_pci_device_t driver_pci_device[DRIVER_MAX_PCI_DEVICES];

#if defined(MODULE)
/*
 **********************************************************************
 * module information
 **********************************************************************
 */
MODULE_AUTHOR("");
MODULE_DESCRIPTION("");
MODULE_LICENSE("");

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
MODULE_PARM(driver_device_major, "i");
#endif /* defined(MODULE) */

/**
 **********************************************************************
 * Function: driver_irq_handler
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static void driver_irq_handler
(int irq, void *dev_id, struct pt_regs *regs)
{
    void (*irq_handler)
    (driver_pci_device_t *device, 
     int irq, struct pt_regs *regs);
    driver_pci_device_t *device;
    volatile cs_regs_t *cs_regs;
    u32 isr;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    if (NULL != (device = (driver_pci_device_t*)dev_id))
    if (NULL != (cs_regs = device->io_regs))
    {
        isr = cs_read_control(&cs_regs->interrupt_control);

        if (isr & CS_INTERRUPT_CONTROL_INTERRUPTED)
        {
            cs_write_control
            (&cs_regs->interrupt_control, 
             CS_INTERRUPT_CONTROL_INTCLEAR);

            if (NULL != (irq_handler = device->irq_handler))
                (*irq_handler)(device, irq, regs);
        }
    }
}

/**
 **********************************************************************
 * Function: driver_request_pci_irq
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static unsigned char driver_request_pci_irq(void)
{
    int err;
    int pci_device_index;
    volatile cs_regs_t *regs;
    unsigned char pci_irq = 0;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    if (driver_pci_device_count < 1)
    {
        dbprintk
        ("%s: %s() - PCI device 0x%x:0x%x not found\n",
         module_name, __FUNCTION__, 
         driver_pci_vendor_id, 
         driver_pci_device_id);

        return 0;
    }

    for (pci_device_index = 0; 
         pci_device_index < driver_pci_device_count; 
         pci_device_index++)
    {
        if (NULL == driver_pci_device[pci_device_index].pci_dev)
        {
            dbprintk
            ("%s: %s() - PCI device[%d] 0x%x:0x%x not found\n",
             module_name, __FUNCTION__, pci_device_index,
             driver_pci_device[pci_device_index].vendor_id, 
             driver_pci_device[pci_device_index].device_id);

            continue;
        }

        if (driver_pci_device[pci_device_index].irq)
        {
            dbprintk
            ("%s: %s() - PCI device[%d] aleady using IRQ 0x%x\n",
             module_name, __FUNCTION__, pci_device_index,
             driver_pci_device[pci_device_index].irq);

            continue;
        }
    
        pci_read_config_byte
        (driver_pci_device[pci_device_index].pci_dev, 
         PCI_INTERRUPT_LINE, &pci_irq);

        if (!pci_irq)
        {
            dbprintk
            ("%s: %s() - PCI device[%d] 0x%x:0x%x doesn't use an IRQ\n",
             module_name, __FUNCTION__, pci_device_index,
             driver_pci_device[pci_device_index].vendor_id, 
             driver_pci_device[pci_device_index].device_id);

            continue;
        }

        dbprintk
        ("%s: %s() - PCI device[%d] 0x%x:0x%x uses IRQ 0x%x\n", 
         module_name, __FUNCTION__, pci_device_index,
         driver_pci_device[pci_device_index].vendor_id, 
         driver_pci_device[pci_device_index].device_id, 
         pci_irq);
     
        if (NULL != (regs = driver_pci_device[pci_device_index].io_regs))
            cs_write_control
            (&regs->interrupt_control,
             CS_INTERRUPT_CONTROL_INTCLEAR);

        if ((err = request_irq
            (pci_irq, driver_irq_handler, SA_SHIRQ, 
             module_name, &driver_pci_device[pci_device_index])))
        {
            printk
            ("%s: %s() - Unable to get IRQ 0x%x\n",
             module_name, __FUNCTION__, pci_irq);
         
            if (-EBUSY == err)
                printk
                ("%s: %s() - IRQ 0x%x already in use\n",
                 module_name, __FUNCTION__, pci_irq);

            return pci_device_index;                 
        }

        dbprintk
        ("%s: %s() - Using IRQ 0x%x\n", 
         module_name, __FUNCTION__, pci_irq);

        driver_pci_device[pci_device_index].irq = pci_irq;
    }

    return pci_device_index;
}

/**
 **********************************************************************
 * Function: driver_free_pci_irq
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static void driver_free_pci_irq(void)
{
    int pci_device_index;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    for (pci_device_index = driver_pci_device_count-1; 
         pci_device_index >= 0; --pci_device_index)
    {
        if (!driver_pci_device[pci_device_index].irq)
            continue;

        dbprintk
        ("%s: %s() - Freeing IRQ 0x%x\n",
         module_name, __FUNCTION__, 
         driver_pci_device[pci_device_index].irq);
     
        free_irq
        (driver_pci_device[pci_device_index].irq, 
         &driver_pci_device[pci_device_index]);

        driver_pci_device[pci_device_index].irq = 0;
    }
}

/**
 **********************************************************************
 * Function: driver_map_pci_regs
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static void driver_map_pci_regs(void)
{
    int pci_device_index;
	int resource_flags;
	int resource_start;
    int resource_size;
    volatile void *addr;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    for (pci_device_index = 0; 
         pci_device_index < driver_pci_device_count;
		 pci_device_index++)
    {
		if ((NULL != driver_pci_device[pci_device_index].io_regs) 
		    || (NULL != driver_pci_device[pci_device_index].regs))
			continue;

		resource_flags = driver_pci_device
		[pci_device_index].pci_dev->resource[0].flags;

		resource_start = driver_pci_device
		[pci_device_index].pci_dev->resource[0].start;
        
        resource_size = sizeof(cs_regs_t);

        dbprintk
        ("%s: %s() - Resource[%d] flags=0x%x start=0x%x\n", 
         module_name, __FUNCTION__, 
         0, resource_flags, resource_start);

		if (resource_flags & IORESOURCE_IO)
		{
            driver_pci_device[pci_device_index].io_regs
		    = (volatile cs_regs_t*)resource_start;

            dbprintk
            ("%s: %s() - Mapped PCI device[%d] 0x%x:0x%x at IO 0x%p\n", 
             module_name, __FUNCTION__, pci_device_index,
             driver_pci_device[pci_device_index].vendor_id, 
             driver_pci_device[pci_device_index].device_id, 
             driver_pci_device[pci_device_index].io_regs);
		}
        else if (resource_flags & IORESOURCE_MEM)
        {
            if (NULL != (addr = (volatile void*)
                ioremap(resource_start, resource_size)))
            {
                driver_pci_device[pci_device_index].regs 
                = (volatile cs_regs_t*)addr;

                dbprintk
                ("%s: %s() - Mapped PCI device[%d] 0x%x:0x%x to 0x%p\n", 
                 module_name, __FUNCTION__, pci_device_index,
                 driver_pci_device[pci_device_index].vendor_id, 
                 driver_pci_device[pci_device_index].device_id, 
                 driver_pci_device[pci_device_index].regs);
            }
            else dbprintk
            ("%s: %s()- Unable to map PCI device[%d] 0x%x:0x%x at 0x%p\n",
             module_name, __FUNCTION__, pci_device_index, 
             driver_pci_device[pci_device_index].vendor_id, 
             driver_pci_device[pci_device_index].device_id, 
		     (caddr_t)resource_start);
        }
    }
}

/**
 **********************************************************************
 * Function: driver_unmap_pci_regs
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static void driver_unmap_pci_regs(void)
{
    int pci_device_index;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    for (pci_device_index = driver_pci_device_count-1; 
         pci_device_index >= 0; --pci_device_index)
    {
        if (NULL != driver_pci_device[pci_device_index].regs)
        {
            iounmap((caddr_t)driver_pci_device[pci_device_index].regs);
            driver_pci_device[pci_device_index].regs = NULL;
        }
    }
}

/**
 **********************************************************************
 * Function: driver_find_pci_device
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static void driver_find_pci_device(void)
{
	int resource_start;
    struct pci_dev *pci_dev=0;

    if (driver_pci_device_count > 0)
        return;

    dbprintk
    ("%s: %s()- Searching for PCI device 0x%x:0x%x...\n",
     module_name, __FUNCTION__, 
     driver_pci_vendor_id, 
     driver_pci_device_id);

    while ((pci_dev = pci_find_device
           (driver_pci_vendor_id, 
            driver_pci_device_id, pci_dev)))
    {
        driver_pci_device
        [driver_pci_device_count].flags = 0; 

        driver_pci_device
        [driver_pci_device_count].vendor_id = driver_pci_vendor_id; 
        driver_pci_device
        [driver_pci_device_count].device_id = driver_pci_device_id; 

        driver_pci_device
        [driver_pci_device_count].pci_dev = pci_dev;
         
        driver_pci_device
        [driver_pci_device_count].io_regs = NULL;
         
        driver_pci_device
        [driver_pci_device_count].regs = NULL;
         
        driver_pci_device
        [driver_pci_device_count].irq = 0;
         
        driver_pci_device
        [driver_pci_device_count].irq_handler = NULL;

		resource_start = pci_dev->resource[0].start;

        dbprintk
        ("%s: %s() - PCI device[%d] 0x%x:0x%x found at 0x%p\n", 
         module_name, __FUNCTION__, 
         driver_pci_device_count,
         driver_pci_vendor_id, 
         driver_pci_device_id, 
		 (caddr_t)resource_start);

        driver_pci_device_count++;
    }
    
    dbprintk
    ("%s: %s()- %d PCI devices found\n",
     module_name, __FUNCTION__, 
     driver_pci_device_count);
}

/**
 **********************************************************************
 * Function: driver_open
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static int driver_open
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
 * Function: driver_release
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static int driver_release
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
 * Function: driver_ioctl_reset
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static int driver_ioctl_reset(unsigned long arg)
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
 **********************************************************************
 * Function: driver_ioctl_test
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static int driver_ioctl_test(unsigned long arg)
{
    u32 status;
    u32 signature;
    int was_reset;
    unsigned flags;
    int pci_device_index;
    volatile cs_regs_t *regs;
    unsigned long timeout = 500;

    dbprintk
    ("%s: %s(unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, arg );

    driver_map_pci_regs();

    driver_request_pci_irq();

    for (pci_device_index = 0; pci_device_index < driver_pci_device_count; pci_device_index++)
    if (NULL != (regs = driver_pci_device[pci_device_index].io_regs))
    {
        signature = cs_read_control(&regs->signature);

        dbprintk
        ("%s: %s() - Resetting device[%d] signature = 0x%x...\n",
         module_name, __FUNCTION__, 
         pci_device_index, signature);

        cs_write_control(&regs->control, CS_CONTROL_RESET);
        cs_write_control(&regs->control, CS_CONTROL_CLEAR);

        was_reset = 0;
        timeout += jiffies;

        mdelay(750);

        while (jiffies < timeout)
        {
            status = cs_read_control(&regs->mailbox_status);
            flags = driver_pci_device[pci_device_index].flags;

            if ((CS_STATUS_MAIL_EMPTY == (CS_STATUS_MAIL_EMPTY & status))
                || (CS_FLAG_WAIT_FOR_RESET != (flags & CS_FLAG_WAIT_FOR_RESET)))
            {
                dbprintk
                ("%s: %s() - ...Reset device[%d] signature = 0x%x\n",
                 module_name, __FUNCTION__, 
                 pci_device_index, signature);
                was_reset = 1;
                break;
            }
            mdelay(1);
        }

        if (was_reset)
            continue;

        dbprintk
        ("%s: %s() - ...Failed to reset device[%d] signature = 0x%x\n",
         module_name, __FUNCTION__, 
         pci_device_index, signature);
    }

    return 0;
}

/**
 **********************************************************************
 * Function: driver_ioctl
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static int driver_ioctl
(struct inode *inode, struct file *file,
 unsigned int cmd, unsigned long arg)
{
    dbprintk
    ("%s: %s(struct inode *inode=0x%p, struct file *file=0x%p,"
     " unsigned int cmd=0x%x, unsigned long arg=0x%lx)\n",
     module_name, __FUNCTION__, inode, file, cmd, arg );

    switch(cmd) 
    {
    case DRIVER_IOC_RESET:
        return driver_ioctl_reset(arg);

    case DRIVER_IOC_TEST:
        return driver_ioctl_test(arg);

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
 * Function: driver_proc_info
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
static int driver_proc_info
(char *buffer, char **start, off_t offset, int length)
{
    char *p;
    
    p=buffer+sprintf(buffer, "%s Version $Id$\n", module_name);
    
    return p-buffer;
}

/*
 * Device file operations table
 */
static struct file_operations driver_file_operations = 
{
    open:    driver_open,
    release: driver_release,
    ioctl:   driver_ioctl
};

/**
 **********************************************************************
 * Function: driver_init
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
int __init driver_init(void)
{
    int dynamic_major;
    int devfs_major;

    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);

    driver_find_pci_device();

    /* Register the device file operations.
     */
    if ((devfs_major = devfs_register_chrdev
        (driver_device_major, 
         module_name, &driver_file_operations)) < 0)
    {
        printk
        ("%s: Unable to use device major %d\n", 
         module_name, driver_device_major);

        return devfs_major;
    }
    
    /* If the device major was obtained dynamically
     * via devfs, set the device major to the value
     * obtained from devfs.
     */
    if ((dynamic_major = !driver_device_major))
        driver_device_major = devfs_major;

    printk
    ("%s: Using device major %d\n", 
     module_name, driver_device_major);
     
    /* Create a /dev entry 
     */
    driver_devfs_handle = devfs_register
    (NULL, module_name, 
     dynamic_major? DEVFS_FL_AUTO_DEVNUM: DEVFS_FL_NONE,
     driver_device_major, 0, S_IFCHR | S_IRUSR | S_IWUSR, 
     &driver_file_operations, NULL);

    /* Create a /proc entry
     */
    create_proc_info_entry
    (module_name, 0, NULL, driver_proc_info);

    return 0;
}

#if defined(MODULE)
/**
 **********************************************************************
 * Function: driver_exit
 *
 *   Author: $author$
 *     Date: 7/27/2003
 **********************************************************************
 */
void driver_exit(void)
{
    dbprintk
    ("%s: %s()\n", module_name, __FUNCTION__);
    
    /* Remove the /proc entry
     */
    remove_proc_entry(module_name, NULL);

    /* Remove the /dev entry
     */
    devfs_unregister(driver_devfs_handle);

    /* Unregister device file operations.
     */
    devfs_unregister_chrdev
    (driver_device_major, module_name);

    driver_free_pci_irq();

    driver_unmap_pci_regs();
}

/*
 * export module init and exit
 */
module_init(driver_init);
module_exit(driver_exit);
#endif /* defined(MODULE) */

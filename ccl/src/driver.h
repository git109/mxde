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
 *   File: driver.h
 *
 * Author: $author$
 *   Date: 7/23/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _DRIVER_H
#define _DRIVER_H

#if defined(__KERNEL__)
#include <linux/types.h>
#include <linux/ioctl.h>
#else
#if defined(WIN32)
#else
#include <sys/ioctl.h>
#endif /* defined(WIN32) */
#endif

/*
 * IOCTL definitions
 */
#if defined(WIN32)
#define DRIVER_IOC_RESET 0
#define DRIVER_IOC_TEST  0
#else
#define DRIVER_IOC_MAGIC 'X'
#define DRIVER_IOC_RESET _IO(DRIVER_IOC_MAGIC, 1)
#define DRIVER_IOC_TEST  _IO(DRIVER_IOC_MAGIC, 2)
#endif

#if defined(__KERNEL__)
#define CS_INTERRUPT_CONTROL_INTERRUPTED 0x00800000
#define CS_INTERRUPT_CONTROL_INTCLEAR    0x023F1000

#define CS_CONTROL_RESET 0x0F000000
#define CS_CONTROL_CLEAR 0x00000000

#define CS_STATUS_MAIL_EMPTY  0x000F0000
#define CS_STATUS_INTERRUPTED 0x00800000

#define CS_FLAG_BUS_MASTER        0x00000001
#define CS_FLAG_OUT_OF_ORDER      0x00000002
#define CS_FLAG_INTERRUPT         0x00000004
#define CS_FLAG_CARDBUSY          0x00000008
#define CS_FLAG_USE_OPREG         0x00000010
#define CS_FLAG_NEED_DPC          0x00000020
#define CS_FLAG_USE_FASTMAP_IOREG 0x00000040
#define CS_FLAG_WAIT_FOR_RESET    0x00000100

/**
 **********************************************************************
 * Struct: cs_regs
 *
 * Author: $author$
 *   Date: 7/27/2003
 **********************************************************************
 */
typedef struct cs_regs
{
    u32 command;
    u32 fastmap_from;
    u32 fastmap_to;
    u32 sizes;
    u32 compcmd;
    u32 mailbox_in;
    u32 mailbox_out;
    u32 signature;
    u32 to_addr;
    u32 to_size;
    u32 from_addr;
    u32 from_size;
    u32 mailbox_status;
    u32 interrupt_control;
    u32 control;
} cs_regs_t;
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif

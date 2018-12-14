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
 *   File: mydisk.h
 *
 * Author: $author$
 *   Date: 8/8/2005
 *
 *    $Id$
 *
 * Header for Linux driver "mydisk".
 *
 **********************************************************************
 */
#ifndef MYDISK_H
#define MYDISK_H

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
#define MYDISK_IOCTL_RESETMOD 255
#else
#define MYDISK_IOCTL_MAGIC 'X'
#define MYDISK_IOCTL_SEND_REQUEST _IO(MYDISK_IOCTL_MAGIC, 1)
#define MYDISK_IOCTL_RECEIVE_REQUEST _IO(MYDISK_IOCTL_MAGIC, 2)
#define MYDISK_IOCTL_SERVICE_REQUEST _IO(MYDISK_IOCTL_MAGIC, 3)
#define MYDISK_IOCTL_RESETMOD _IO(MYDISK_IOCTL_MAGIC, 255)
#endif /* defined(WIN32) */

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 8/8/2005
 **********************************************************************
 */
enum
{
    e_MYDISK_REQUEST_FIRST,

    e_MYDISK_BLOCK_REQUEST = e_MYDISK_REQUEST_FIRST,

    e_MYDISK_REQUEST_NEXT,
    e_MYDISK_REQUEST_LAST = e_MYDISK_REQUEST_NEXT-1
};

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 8/8/2005
 **********************************************************************
 */
enum
{
    e_MYDISK_BLOCK_REQUEST_FIRST,

    e_MYDISK_READ_BLOCK_REQUEST = e_MYDISK_BLOCK_REQUEST_FIRST,
    e_MYDISK_WRITE_BLOCK_REQUEST,

    e_MYDISK_BLOCK_REQUEST_NEXT,
    e_MYDISK_BLOCK_REQUEST_LAST = e_MYDISK_BLOCK_REQUEST_NEXT-1
};

/**
 **********************************************************************
 * Struct: mydisk_block_request
 *
 * Author: $author$
 *   Date: 8/8/2005
 **********************************************************************
 */
typedef struct mydisk_block_request
{
    unsigned int type;
    unsigned long lun;
    unsigned long lba;
    unsigned long length;
} mydisk_block_request_t;

/**
 **********************************************************************
 * Struct: mydisk_request
 *
 * Author: $author$
 *   Date: 8/8/2005
 **********************************************************************
 */
typedef struct mydisk_request
{
    unsigned int id;
    unsigned int type;
    union
    {
        mydisk_block_request_t block;
    };
} mydisk_request_t;

#if defined(__KERNEL__)
#endif /* defined(__KERNEL__) */


#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* MYDISK_H */

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
 *   File: mydriver.h
 *
 * Author: $author$
 *   Date: 8/1/2005
 *
 *    $Id$
 *
 * Header for Linux driver "mydriver".
 *
 **********************************************************************
 */
#ifndef MYDRIVER_H
#define MYDRIVER_H

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
#define MYDRIVER_IOCTL_RESETMOD 255
#else
#define MYDRIVER_IOCTL_MAGIC 'X'
#define MYDRIVER_IOCTL_SEND_REQUEST    _IOW(MYDRIVER_IOCTL_MAGIC, 1, mydriver_request_t *)
#define MYDRIVER_IOCTL_RECEIVE_REQUEST _IOW(MYDRIVER_IOCTL_MAGIC, 2, mydriver_request_t *)
#define MYDRIVER_IOCTL_SERVICE_REQUEST _IOR(MYDRIVER_IOCTL_MAGIC, 3, mydriver_request_t *)
#define MYDRIVER_IOCTL_RESETMOD        _IO(MYDRIVER_IOCTL_MAGIC, 255)
#endif /* defined(WIN32) */

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 8/1/2005
 **********************************************************************
 */
enum
{
    e_MYDRIVER_REQUEST_TYPE_FIRST,

    e_MYDRIVER_RDBLOCK_REQUEST_TYPE = e_MYDRIVER_REQUEST_TYPE_FIRST,
    e_MYDRIVER_WRBLOCK_REQUEST_TYPE,

    e_MYDRIVER_REQUEST_TYPE_NEXT,
    e_MYDRIVER_REQUEST_TYPE_LAST = e_MYDRIVER_REQUEST_TYPE_NEXT-1
};

/**
 **********************************************************************
 * Struct: mydriver_block_request
 *
 * Author: $author$
 *   Date: 8/1/2005
 **********************************************************************
 */
typedef struct mydriver_block_request
{
    unsigned long lun;
    unsigned long lba;
    unsigned long length;
} mydriver_block_request_t;

/**
 **********************************************************************
 * Struct: mydriver_request
 *
 * Author: $author$
 *   Date: 8/1/2005
 **********************************************************************
 */
typedef struct mydriver_request
{
    unsigned id;
    int type;
    union
    {
        mydriver_block_request_t block;
    };
} mydriver_request_t;

#if defined(__KERNEL__)
#endif /* defined(__KERNEL__) */


#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* MYDRIVER_H */


/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cplatform_ioctl.h
 *
 * Author: $author$
 *   Date: 2/20/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_IOCTL_H
#define _CPLATFORM_IOCTL_H

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 */
#include <winioctl.h>
#define PLATFORM_IOCTL(magic, code) code
#else /* defined(WINDOWS) */
/* Linux
 */
#if defined(__KERNEL__) 
/* Linux kernel space
 */
#include <linux/types.h>
#include <linux/ioctl.h>
#else /* defined(__KERNEL__) */
/* Linux user space
 */
#include <sys/ioctl.h>
#endif /* defined(__KERNEL__) */

#define PLATFORM_IOCTL(magic, code) _IO(magic, code)
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_IOCTL_H */

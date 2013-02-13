/**
 **********************************************************************
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
 *   File: cplatform_X11_Xarch.h
 *
 * Author: $author$           
 *   Date: 5/4/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_XARCH_H
#define _CPLATFORM_X11_XARCH_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/Xarch.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

/*
 * Copyright 1997 Metro Link Incorporated
 *
 *                           All Rights Reserved
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of the above listed copyright holder(s)
 * not be used in advertising or publicity pertaining to distribution of
 * the software without specific, written prior permission.  The above listed
 * copyright holder(s) make(s) no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express or
 * implied warranty.
 *
 * THE ABOVE LISTED COPYRIGHT HOLDER(S) DISCLAIM(S) ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS, IN NO EVENT SHALL THE ABOVE LISTED COPYRIGHT HOLDER(S) BE
 * LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/* $XFree86: xc/include/Xarch.h,v 1.10tsi Exp $ */


/*
 * Determine the machine's byte order.
 */

/* See if it is set in the imake config first */
#ifdef X_BYTE_ORDER

#define X_BIG_ENDIAN 4321
#define X_LITTLE_ENDIAN 1234

#else

#ifdef SVR4
#if defined(NCR) || defined(Mips) || defined(__sgi)
#include <sys/endian.h>
#else
#if !defined(sun)
#include <sys/byteorder.h>
#endif
#endif
#elif defined(CSRG_BASED)
#if defined(__NetBSD__) || defined(__OpenBSD__)
#include <sys/types.h>
#endif
#include <machine/endian.h>
#elif defined(linux)
#if defined __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <endian.h>
#define __STRICT_ANSI__
#else
#include <endian.h>
#endif
/* 'endian.h' might have been included before 'Xarch.h' */
#if !defined(LITTLE_ENDIAN) && defined(__LITTLE_ENDIAN)
#define LITTLE_ENDIAN __LITTLE_ENDIAN
#endif
#if !defined(BIG_ENDIAN) && defined(__BIG_ENDIAN)
#define BIG_ENDIAN __BIG_ENDIAN
#endif
#if !defined(PDP_ENDIAN) && defined(__PDP_ENDIAN)
#define PDP_ENDIAN __PDP_ENDIAN
#endif
#if !defined(BYTE_ORDER) && defined(__BYTE_ORDER)
#define BYTE_ORDER __BYTE_ORDER
#endif
#elif defined(Lynx)
#if 0
/* LynxOS 2.4.0 has wrong defines in bsd/ip.h */
#include <bsd/in.h>
#include <bsd/in_systm.h>
#include <bsd/ip.h>
#endif
#endif

#ifndef BYTE_ORDER
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN    4321

#if defined(__QNX__) && !defined(__QNXNTO__)
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#if defined(__QNXNTO__)
#if defined(i386) || defined(__i386__) || defined(__x86__)
#define BYTE_ORDER LITTLE_ENDIAN
#else
#define BYTE_ORDER BIG_ENDIAN
#endif
#endif

#ifdef Lynx
#if defined(i386) || defined(__i386__) || defined(__x86__)
#define BYTE_ORDER LITTLE_ENDIAN
#else
#define BYTE_ORDER BIG_ENDIAN
#endif
#endif
#if (defined(sun) && defined(SVR4)) && !defined(Lynx)
#include <sys/isa_defs.h>
#ifdef _LITTLE_ENDIAN
#define BYTE_ORDER LITTLE_ENDIAN
#endif
#ifdef _BIG_ENDIAN
#define BYTE_ORDER BIG_ENDIAN
#endif
#endif /* sun */
#endif /* BYTE_ORDER */

#define X_BYTE_ORDER BYTE_ORDER
#define X_BIG_ENDIAN BIG_ENDIAN
#define X_LITTLE_ENDIAN LITTLE_ENDIAN

#endif /* not in imake config */

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_XARCH_H */

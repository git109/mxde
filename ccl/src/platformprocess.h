/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: platformprocess.h
 *
 * Author: $author$
 *   Date: 10/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _PLATFORMPROCESS_H
#define _PLATFORMPROCESS_H

#if defined(WIN32)
/* 
 * Windows processes
 */
#include <windows.h>
#define PROCESS HANDLE
#define INVALID_PROCESS NULL
#define WAIT_INFINITE INFINITE
#else /* defined(WIN32) */
/* 
 * Unix processes
 */
#define PROCESS int
#define INVALID_PROCESS -1
#define WAIT_INFINITE -1
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif

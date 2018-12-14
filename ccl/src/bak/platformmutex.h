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
 *   File: platformmutex.h
 *
 * Author: $author$
 *   Date: 11/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _PLATFORMMUTEX_H
#define _PLATFORMMUTEX_H

#if defined(WIN32) 
/*
 * Windows Mutexes
 */
#include <windows.h>
#define MUTEX HANDLE
#define INVALID_MUTEX NULL
#else /* defined(WIN32) */
/*
 * Posix Mutexes
 */
#define MUTEX int
#define INVALID_MUTEX -1
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif

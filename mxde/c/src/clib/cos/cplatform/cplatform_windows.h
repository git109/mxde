/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cplatform_windows.h
 *
 * Author: $author$
 *   Date: 5/5/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_WINDOWS_H
#define _CPLATFORM_WINDOWS_H

#include "cplatform.h"

#if !defined(_CPLATFORM_WINUSER_H) 
#include "cplatform_winuser.h"
#endif /* !defined(_CPLATFORM_WINUSER_H) */

#if defined(WINDOWS_WCE)
/* Windows CE
 */
typedef LPWSTR LPCMDLINE;
typedef WNDCLASS TWNDCLASS;
#else /* defined(WINDOWS_WCE) */
/* Otherwise
 */
typedef LPSTR LPCMDLINE;
typedef WNDCLASSEX TWNDCLASS;
#endif /* defined(WINDOWS_WCE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_WINDOWS_H */

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
 *   File: cplatform_winuser.h
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_WINUSER_H
#define _CPLATFORM_WINUSER_H

#if !defined(_CPLATFORM_WINDOWS_H) 
#include "cplatform_windows.h"
#endif /* !defined(_CPLATFORM_WINDOWS_H) */

#if !defined(WS_EX_LAYERED) 
/* NO layered window support
 */
#define WS_EX_LAYERED 0
#define LWA_COLORKEY 0
#define LWA_ALPHA 0

#define UpdateLayeredWindow \
    (hWnd,hdcDst,pptDst,psize,hdcSrc,pptSrc,crKey,pblend,dwFlags) (FALSE)
    
#define SetLayeredWindowAttributes \
    (hwnd,crKey,bAlpha,dwFlags) (FALSE)

#else /* !defined(WS_EX_LAYERED) */
/* Otherwise
 */
#endif /* !defined(WS_EX_LAYERED) */

#if !defined(CS_DROPSHADOW) 
/* NO drop shadow support
 */
#define CS_DROPSHADOW 0
#else /* !defined(CS_DROPSHADOW) */
/* Otherwise
 */
#endif /* !defined(CS_DROPSHADOW) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if !defined(WS_EX_LAYERED) 
/* NO layered window support
 */
#else /* !defined(WS_EX_LAYERED) */
/* Otherwise
 */
#endif /* !defined(WS_EX_LAYERED) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_WINUSER_H */

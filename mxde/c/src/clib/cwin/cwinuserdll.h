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
 *   File: cwinuserdll.h
 *
 * Author: $author$
 *   Date: 12/12/2009
 **********************************************************************
 */
#ifndef _CWINUSERDLL_H
#define _CWINUSERDLL_H

#include "cplatform.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if !defined(_WIN32_WINNT) 
#if (WINVER >= 0x0500)

#if !defined(WS_EX_LAYERED)
#define WS_EX_LAYERED 0x00080000
#endif /* !defined(WS_EX_LAYERED) */

#define LWA_COLORKEY            0x00000001
#define LWA_ALPHA               0x00000002

//WINUSERAPI
BOOL
WINAPI
SetLayeredWindowAttributes(
    __in HWND hwnd,
    __in COLORREF crKey,
    __in BYTE bAlpha,
    __in DWORD dwFlags);
#endif /* (WINVER >= 0x0500) */
#define CS_DROPSHADOW 0x00020000
#if (WINVER >= 0x0501)
#endif /* */
#endif /* !defined(_WIN32_WINNT) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CWINUSERDLL_H */

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
 *   File: cwinuserdll.c
 *
 * Author: $author$
 *   Date: 12/12/2009
 **********************************************************************
 */
#include "cwinuserdll.h"

#if !defined(_WIN32_WINNT) 
#if (WINVER >= 0x0500)
//WINUSERAPI
BOOL
WINAPI
SetLayeredWindowAttributes(
    __in HWND hwnd,
    __in COLORREF crKey,
    __in BYTE bAlpha,
    __in DWORD dwFlags)
{
    typedef DWORD (WINAPI *PSLWA)(HWND, DWORD, BYTE, DWORD);

    BOOL result = FALSE;
    PSLWA pSetLayeredWindowAttributes;
    HMODULE hModule;
    if ((hModule = LoadLibrary(_T("user32"))))
    {
        if ((pSetLayeredWindowAttributes = 
             (PSLWA)GetProcAddress(hModule, "SetLayeredWindowAttributes")))
             result = pSetLayeredWindowAttributes(hwnd, crKey, bAlpha, dwFlags);
        FreeLibrary(hModule);
    }
    return result;
}
#endif /* (WINVER >= 0x0500) */
#endif /* !defined(_WIN32_WINNT) */

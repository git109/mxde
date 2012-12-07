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
 *   File: cwinbitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPWINDOW_HXX) || defined(CWINBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINBITMAPWINDOW_HXX) && !defined(CWINBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINBITMAPWINDOW_HXX
#endif /* !defined(_CWINBITMAPWINDOW_HXX) && !defined(CWINBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINBITMAPWINDOW_MEMBERS_ONLY)
#include "cwinshapedwindow.hxx"

#define CWINBITMAPWINDOW_WINDOW_CLASSNAME \
    "cWinBitmapWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapWindowExtends
 *
 *  Author: $author$
 *    Date: 12/2/2009
 **********************************************************************
 */
typedef cWinShapedWindow
cWinBitmapWindowExtends;
/**
 **********************************************************************
 *  Class: cWinBitmapWindow
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapWindow
: public cWinBitmapWindowExtends
{
public:
    typedef cWinBitmapWindowExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinBitmapWindow
     *
     *       Author: $author$
     *         Date: 12/2/2009
     **********************************************************************
     */
    cWinBitmapWindow
    (COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinBitmapWindow
     *
     *      Author: $author$
     *        Date: 12/2/2009
     **********************************************************************
     */
    virtual ~cWinBitmapWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/3/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
#if defined(CWINBITMAPWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        LRESULT lResult = 0;
#if !defined(CWINBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        PAINTSTRUCT ps;
        HBITMAP hBitmap;
        HDC hDC, hDCBitmap;
        RECT rect;
        
        if ((hBitmap = GetWindowBitmap()))
        if ((GetClientRect(hWnd, &rect)))
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((hDCBitmap = CreateCompatibleDC(hDC)))
            {
                HGDIOBJ hGDIOBJ = SelectObject(hDCBitmap, hBitmap);

                BitBlt
                (hDC, rect.left,rect.top, 
                 rect.right-rect.left, rect.bottom-rect.top, 
                 hDCBitmap, 0,0, SRCCOPY);

                SelectObject(hDCBitmap, hGDIOBJ);
                DeleteDC(hDCBitmap);
            }
            EndPaint(hWnd, &ps);
            return lResult;
        }
#else /* !defined(CWINBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
#endif /* defined(CWINBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetWindowBitmap
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual HBITMAP GetWindowBitmap() const
#if defined(CWINBITMAPWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HBITMAP hBitmap = NULL;
#if !defined(CWINBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hBitmap;
    }
#endif /* defined(CWINBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPWINDOW_HXX) || defined(CWINBITMAPWINDOW_MEMBERS_ONLY) */

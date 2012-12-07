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
 *   File: cwindibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
#if !defined(_CWINDIBITMAPWINDOW_HXX) || defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINDIBITMAPWINDOW_HXX) && !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINDIBITMAPWINDOW_HXX
#endif /* !defined(_CWINDIBITMAPWINDOW_HXX) && !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwinncpaintedwindow.hxx"
#include "cwindibitmap.hxx"

#define CWINDIBITMAPWINDOW_BG_COLOR_R 0xFF
#define CWINDIBITMAPWINDOW_BG_COLOR_G 0xFF
#define CWINDIBITMAPWINDOW_BG_COLOR_B 0xDD

#define CWINDIBITMAPWINDOW_BG_COLOR \
    RGB(CWINDIBITMAPWINDOW_BG_COLOR_R, \
        CWINDIBITMAPWINDOW_BG_COLOR_G, \
        CWINDIBITMAPWINDOW_BG_COLOR_B)

#define CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR_R 192
#define CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR_G 255
#define CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR_B 192

#define CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR \
    RGB(CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR_R, \
        CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR_G, \
        CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR_B)

#define CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_A 0x80
#define CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_R 0x00
#define CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_G 0xFF
#define CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_B 0x00

#define CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR \
    RGB(CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_R, \
        CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_G, \
        CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_B)

#define CWINDIBITMAPWINDOW_WINDOW_CLASSNAME \
    "cWinDIBitmapWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 12/18/2009
 **********************************************************************
 */
typedef cWinNCPaintedWindow
cWinDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinDIBitmapWindow
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDIBitmapWindow
: public cWinDIBitmapWindowExtend
{
public:
    typedef cWinDIBitmapWindowExtend cExtends;
    
    cWinDIBitmap m_diBitmap;
    
    /**
     **********************************************************************
     *  Constructor: cWinDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 12/18/2009
     **********************************************************************
     */
    cWinDIBitmapWindow
    (COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
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
     *  Destructor: ~cWinDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 12/18/2009
     **********************************************************************
     */
    virtual ~cWinDIBitmapWindow()
    {
    }
#else /* !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY)
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
    {
        LRESULT lResult = 0;
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
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     *  Function: GetWindowBitmap
     *
     *    Author: $author$
     *      Date: 12/18/2009
     **********************************************************************
     */
    virtual HBITMAP GetWindowBitmap() const
    {
        HBITMAP hBitmap = m_diBitmap.Attached();
        return hBitmap;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINDIBITMAPWINDOW_HXX) || defined(CWINDIBITMAPWINDOW_MEMBERS_ONLY) */

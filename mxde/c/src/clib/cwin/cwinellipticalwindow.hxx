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
 *   File: cwinellipticalwindow.hxx
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
#if !defined(_CWINELLIPTICALWINDOW_HXX) || defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY)
#if !defined(_CWINELLIPTICALWINDOW_HXX) && !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY)
#define _CWINELLIPTICALWINDOW_HXX
#endif /* !defined(_CWINELLIPTICALWINDOW_HXX) && !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY) */

#if !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY)
#include "cwinncwindow.hxx"
#include "cwinwindowclass.hxx"
#include "cwincolorref.hxx"
#include "cwinbrush.hxx"

#define CWINELLIPTICALWINDOW_BG_COLOR_R 0xFF
#define CWINELLIPTICALWINDOW_BG_COLOR_G 0xFF
#define CWINELLIPTICALWINDOW_BG_COLOR_B 0xDD

#define CWINELLIPTICALWINDOW_BG_COLOR \
    RGB(CWINELLIPTICALWINDOW_BG_COLOR_R, \
        CWINELLIPTICALWINDOW_BG_COLOR_G, \
        CWINELLIPTICALWINDOW_BG_COLOR_B)

#define CWINELLIPTICALWINDOW_RADIUS_WIDTH 64
#define CWINELLIPTICALWINDOW_RADIUS_HEIGHT \
    CWINELLIPTICALWINDOW_RADIUS_WIDTH

#define CWINELLIPTICALWINDOW_WINDOW_CLASSNAME \
    "cWinEllipticalWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinEllipticalWindowExtends
 *
 *  Author: $author$
 *    Date: 7/20/2009
 **********************************************************************
 */
typedef cWinNCWindow
cWinEllipticalWindowExtends;
/**
 **********************************************************************
 *  Class: cWinEllipticalWindow
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinEllipticalWindow
: public cWinEllipticalWindowExtends
{
public:
    typedef cWinEllipticalWindowExtends cExtends;

    const TCHAR* m_windowClassNameChars;

    TSIZE m_radiusWidth;
    TSIZE m_radiusHeight;

    cWinCOLORREF m_bgColor;
    cWinBrush m_bgBrush;

    /**
     **********************************************************************
     *  Constructor: cWinEllipticalWindow
     *
     *       Author: $author$
     *         Date: 7/20/2009
     **********************************************************************
     */
    cWinEllipticalWindow
    (TSIZE radiusWidth=CWINELLIPTICALWINDOW_RADIUS_WIDTH,
     TSIZE radiusHeight=CWINELLIPTICALWINDOW_RADIUS_HEIGHT,
     COLORREF bgColor=CWINELLIPTICALWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINELLIPTICALWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated),
      m_windowClassNameChars(windowClassNameChars),
      m_radiusWidth(radiusWidth),
      m_radiusHeight(radiusHeight),
      m_bgColor(bgColor),
      m_bgBrush(hBgBrush)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEllipticalWindow
     *
     *      Author: $author$
     *        Date: 7/20/2009
     **********************************************************************
     */
    virtual ~cWinEllipticalWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CreateWindowEllipticalRegion
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowEllipticalRegion
    (RECT& rect) 
#if defined(CWINELLIPTICALWINDOW_MEMBER_FUNCS_INTERFACE)
    ;
#else /* CWINELLIPTICALWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        HRGN hRgn = NULL;
#if !defined(CWINELLIPTICALWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        hRgn = CreateEllipticRgn
        (rect.left,rect.top, rect.right,rect.bottom);
#else /* !defined(CWINELLIPTICALWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINELLIPTICALWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINELLIPTICALWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual eError InitializeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        HBRUSH hBrush;

        if (m_windowClassNameChars)
        if (0 > (length = windowClass.SetWindowClassName(m_windowClassNameChars)))
            return error = -length;

        if (!(hBrush = m_bgBrush.Attached()))
        if ((error = m_bgBrush.CreateSolid(m_bgColor.Attached())))
            return error;

        windowClass.SetBackground(m_bgBrush.Attached());
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeWindowClass
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual eError FinalizeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        error = m_bgBrush.Destroy(true);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnSize
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual BOOL OnSize
    (LRESULT& lResult,
     HRGN& hRgn,
     RECT& rect,
     HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL handled = FALSE;

        if (!hRgn)
        if ((hRgn = CreateWindowEllipticalRegion(rect)))
        {
            lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
            handled = TRUE;
        }
        return handled;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINELLIPTICALWINDOW_HXX) || defined(CWINELLIPTICALWINDOW_MEMBERS_ONLY) */

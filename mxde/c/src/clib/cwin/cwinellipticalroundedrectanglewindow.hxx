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
 *   File: cwinellipticalroundedrectanglewindow.hxx
 *
 * Author: $author$
 *   Date: 7/14/2009
 **********************************************************************
 */
#if !defined(_CWINELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#define _CWINELLIPTICALROUNDEDRECTANGLEWINDOW_HXX
#endif /* !defined(_CWINELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#include "cwinncwindow.hxx"
#include "cwinwindowclass.hxx"
#include "cwincolorref.hxx"
#include "cwinbrush.hxx"

#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR_R 0xFF
#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR_G 0xFF
#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR_B 0xDD

#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR \
    RGB(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR_R, \
        CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR_G, \
        CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR_B)

#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_WIDTH 25
#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_HEIGHT \
    CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_WIDTH

#define CWINELLIPTICALROUNDEDRECTANGLEWINDOW__WINDOW_CLASSNAME \
    "cWinEllipticalRoundedRectangleWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinEllipticalRoundedRectangleWindowExtends
 *
 *  Author: $author$
 *    Date: 7/14/2009
 **********************************************************************
 */
typedef cWinNCWindow
cWinEllipticalRoundedRectangleWindowExtends;

/**
 **********************************************************************
 *  Class: cWinEllipticalRoundedRectangleWindow
 *
 * Author: $author$
 *   Date: 7/14/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinEllipticalRoundedRectangleWindow
: public cWinEllipticalRoundedRectangleWindowExtends
{
public:
    typedef cWinEllipticalRoundedRectangleWindowExtends cExtends;

    const TCHAR* m_windowClassNameChars;

    TSIZE m_cornerRadiusWidth;
    TSIZE m_cornerRadiusHeight;

    cWinCOLORREF m_bgColor;
    cWinBrush m_bgBrush;

    /**
     **********************************************************************
     *  Constructor: cWinEllipticalRoundedRectangleWindow
     *
     *       Author: $author$
     *         Date: 7/14/2009
     **********************************************************************
     */
    cWinEllipticalRoundedRectangleWindow
    (TSIZE cornerRadiusWidth=CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_WIDTH,
     TSIZE cornerRadiusHeight=CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_HEIGHT,
     COLORREF bgColor=CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINELLIPTICALROUNDEDRECTANGLEWINDOW__WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated),
      m_windowClassNameChars(windowClassNameChars),
      m_cornerRadiusWidth(cornerRadiusWidth),
      m_cornerRadiusHeight(cornerRadiusHeight),
      m_bgColor(bgColor),
      m_bgBrush(hBgBrush)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEllipticalRoundedRectangleWindow
     *
     *      Author: $author$
     *        Date: 7/14/2009
     **********************************************************************
     */
    virtual ~cWinEllipticalRoundedRectangleWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnSize
     *
     *   Author: $author$
     *     Date: 7/14/2009
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

        if ((0 < m_cornerRadiusWidth) 
            && (0 < m_cornerRadiusHeight))
        if (!hRgn)
        if ((hRgn = CreateWindowEllipticalRoundedRegion
            (rect, m_cornerRadiusWidth, m_cornerRadiusHeight)))
        {
            lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
            handled = TRUE;
        }
        return handled;
    }
    /**
     **********************************************************************
     * Function: CreateWindowEllipticalRoundedRegion
     *
     *   Author: $author$
     *     Date: 7/14/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowEllipticalRoundedRegion
    (RECT& r,
     LONG radiusWidth,
     LONG radiusHeight) 
    {
        HRGN hRgn = NULL;;
        hRgn = CreateRoundRectRgn
        (r.left,r.top, r.right+1,r.bottom+1, 
         radiusWidth*2-1, radiusHeight*2-1);
        return hRgn;
    }

    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 7/15/2009
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
     *     Date: 7/15/2009
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
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cwinroundedrectanglemainwindow.hxx
 *
 * Author: $author$
 *   Date: 11/8/2010
 **********************************************************************
 */
#if !defined(_CWINROUNDEDRECTANGLEMAINWINDOW_HXX) || defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDRECTANGLEMAINWINDOW_HXX) && !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDRECTANGLEMAINWINDOW_HXX
#endif /* !defined(_CWINROUNDEDRECTANGLEMAINWINDOW_HXX) && !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY)
#include "cwinroundedrectanglewindow.hxx"
#include "cwinmainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CWINROUNDEDFRAMEMAINWINDOW_WINDOW_CLASSNAME "cWinRoundedRectangleMainWindow"

class c_INSTANCE_CLASS cWinRoundedRectangleMainWindow;
/**
 **********************************************************************
 * Typedef: cWinRoundedRectangleMainWindowExtend
 *
 *  Author: $author$
 *    Date: 11/8/2010
 **********************************************************************
 */
typedef cWinMainWindowT
<cWinRoundedRectangleMainWindow, 
 cWinRoundedRectangleWindow>
cWinRoundedRectangleMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedRectangleMainWindow
 *
 * Author: $author$
 *   Date: 11/8/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRoundedRectangleMainWindow
: //virtual public cWinRoundedRectangleMainWindowImplement,
  public cWinRoundedRectangleMainWindowExtend
{
public:
    //typedef cWinRoundedRectangleMainWindowImplement cImplements;
    typedef cWinRoundedRectangleMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRoundedRectangleMainWindow
     *
     *       Author: $author$
     *         Date: 11/8/2010
     **********************************************************************
     */
    cWinRoundedRectangleMainWindow
    (TSIZE cornerRadius=CWINROUNDEDRECTANGLEWINDOW_CORNER_RADIUS,
     COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINROUNDEDFRAMEMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
        m_cornerRadius = cornerRadius;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedRectangleMainWindow
     *
     *      Author: $author$
     *        Date: 11/8/2010
     **********************************************************************
     */
    virtual ~cWinRoundedRectangleMainWindow()
    {
    }
#else /* !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: WindowStyle
     *
     *   Author: $author$
     *     Date: 11/8/2010
     **********************************************************************
     */
    virtual DWORD WindowStyle() const 
    {
        DWORD style = WS_POPUP;
        return style;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowPosition
     *
     *   Author: $author$
     *     Date: 11/8/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowPosition
    (int& x, int& y) const
    {
        eError error = e_ERROR_NONE;
        x = 0;
        y = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowSize
     *
     *   Author: $author$
     *     Date: 11/8/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        width = 100;
        height = 100;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDRECTANGLEMAINWINDOW_HXX) || defined(CWINROUNDEDRECTANGLEMAINWINDOW_MEMBERS_ONLY) */

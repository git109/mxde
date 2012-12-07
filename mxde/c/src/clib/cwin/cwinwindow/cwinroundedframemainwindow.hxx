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
 *   File: cwinroundedframemainwindow.hxx
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEMAINWINDOW_HXX) || defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEMAINWINDOW_HXX) && !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEMAINWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEMAINWINDOW_HXX) && !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY)
#include "cwinmainwindow.hxx"
#include "cwinroundedframewindow.hxx"

#define CWINROUNDEDFRAMEMAINWINDOW_WINDOW_CLASSNAME "cWinRoundedFrameMainWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinRoundedFrameMainWindow;
/**
 **********************************************************************
 * Typedef: cWinRoundedFrameMainWindowExtend
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cWinMainWindowT
<cWinRoundedFrameMainWindow, 
 cWinRoundedFrameWindow>
cWinRoundedFrameMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameMainWindow
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRoundedFrameMainWindow
: //virtual public cWinRoundedFrameMainWindowImplement,
  public cWinRoundedFrameMainWindowExtend
{
public:
    //typedef cWinRoundedFrameMainWindowImplement cImplements;

    typedef cWinRoundedFrameMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameMainWindow
     *
     *       Author: $author$
     *         Date: 7/29/2010
     **********************************************************************
     */
    cWinRoundedFrameMainWindow
    (COLORREF bgColor=CWINFRAMEWINDOW_BG_COLOR,
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
        TSIZE cornerRadius=CWINROUNDEDFRAMEWINDOW_CORNER_RADIUS;
        m_cornerRadius = cornerRadius;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedFrameMainWindow
     *
     *      Author: $author$
     *        Date: 7/29/2010
     **********************************************************************
     */
    virtual ~cWinRoundedFrameMainWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: WindowStyle
     *
     *   Author: $author$
     *     Date: 7/29/2010
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
     *     Date: 7/29/2010
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
     *     Date: 7/29/2010
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

#else /* !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEMAINWINDOW_HXX) || defined(CWINROUNDEDFRAMEMAINWINDOW_MEMBERS_ONLY) */

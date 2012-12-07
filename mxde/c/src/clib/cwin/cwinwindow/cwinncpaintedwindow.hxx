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
 *   File: cwinncpaintedwindow.hxx
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
#if !defined(_CWINNCPAINTEDWINDOW_HXX) || defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY)
#if !defined(_CWINNCPAINTEDWINDOW_HXX) && !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY)
#define _CWINNCPAINTEDWINDOW_HXX
#endif /* !defined(_CWINNCPAINTEDWINDOW_HXX) && !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY)
#include "cwinncwindow.hxx"
#include "cwinwindowclass.hxx"
#include "cwincolorref.hxx"
#include "cwinbrush.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinNCPaintedWindowExtend
 *
 *  Author: $author$
 *    Date: 12/18/2009
 **********************************************************************
 */
typedef cWinNCWindow
cWinNCPaintedWindowExtend;
/**
 **********************************************************************
 *  Class: cWinNCPaintedWindow
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinNCPaintedWindow
: public cWinNCPaintedWindowExtend
{
public:
    typedef cWinNCPaintedWindowExtend cExtends;
    
    const TCHAR* m_windowClassNameChars;
    
    cWinCOLORREF m_bgColor;
    cWinBrush m_bgBrush;
    
    /**
     **********************************************************************
     *  Constructor: cWinNCPaintedWindow
     *
     *       Author: $author$
     *         Date: 12/18/2009
     **********************************************************************
     */
    cWinNCPaintedWindow
    (COLORREF bgColor=CWINNCWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINNCWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated),
      m_windowClassNameChars(windowClassNameChars),
      m_bgColor(bgColor),
      m_bgBrush(hBgBrush)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinNCPaintedWindow
     *
     *      Author: $author$
     *        Date: 12/18/2009
     **********************************************************************
     */
    virtual ~cWinNCPaintedWindow()
    {
    }
#else /* !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 12/19/2009
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
     *     Date: 12/19/2009
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
     * Function: SetWindowClassName
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual TLENGTH SetWindowClassName
    (const TCHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH) 
    {
        TLENGTH count = e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: WindowClassName
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual const TCHAR* WindowClassName() const 
    {
        const TCHAR* windowClassNameChars = (m_windowClassNameChars);
        return windowClassNameChars;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINNCPAINTEDWINDOW_HXX) || defined(CWINNCPAINTEDWINDOW_MEMBERS_ONLY) */

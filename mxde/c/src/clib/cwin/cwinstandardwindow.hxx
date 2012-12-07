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
 *   File: cwinstandardwindow.hxx
 *
 * Author: $author$
 *   Date: 7/28/2009
 **********************************************************************
 */
#if !defined(_CWINSTANDARDWINDOW_HXX) || defined(CWINSTANDARDWINDOW_MEMBERS_ONLY)
#if !defined(_CWINSTANDARDWINDOW_HXX) && !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY)
#define _CWINSTANDARDWINDOW_HXX
#endif /* !defined(_CWINSTANDARDWINDOW_HXX) && !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY)
#include "cwinwindow.hxx"
#include "cwinwindowclass.hxx"
#include "cwincolorref.hxx"
#include "cwinbrush.hxx"

#define CWINSTANDARDWINDOW_WINDOW_CLASSNAME \
    "cWinStandardWindow"

#define CWINSTANDARDWINDOW_BG_COLOR_R 0xFF
#define CWINSTANDARDWINDOW_BG_COLOR_G 0xFF
#define CWINSTANDARDWINDOW_BG_COLOR_B 0xDD

#define CWINSTANDARDWINDOW_BG_COLOR \
    RGB(CWINSTANDARDWINDOW_BG_COLOR_R, \
        CWINSTANDARDWINDOW_BG_COLOR_G, \
        CWINSTANDARDWINDOW_BG_COLOR_B)

#define CWINSTANDARDWINDOW_X CW_USEDEFAULT
#define CWINSTANDARDWINDOW_Y CW_USEDEFAULT
#define CWINSTANDARDWINDOW_WIDTH CW_USEDEFAULT
#define CWINSTANDARDWINDOW_HEIGHT CW_USEDEFAULT

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinStandardWindowExtends
 *
 *  Author: $author$
 *    Date: 7/28/2009
 **********************************************************************
 */
typedef cWinWindow
cWinStandardWindowExtends;
/**
 **********************************************************************
 *  Class: cWinStandardWindow
 *
 * Author: $author$
 *   Date: 7/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinStandardWindow
: public cWinStandardWindowExtends
{
public:
    typedef cWinStandardWindowExtends cExtends;

    const TCHAR* m_windowClassNameChars;

    cWinCOLORREF m_bgColor;
    cWinBrush m_bgBrush;

    /**
     **********************************************************************
     *  Constructor: cWinStandardWindow
     *
     *       Author: $author$
     *         Date: 7/28/2009
     **********************************************************************
     */
    cWinStandardWindow
    (COLORREF bgColor=CWINSTANDARDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINSTANDARDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends(hInstance,attached,isCreated),
      m_bgColor(bgColor),
      m_bgBrush(hBgBrush),
      m_windowClassNameChars(windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinStandardWindow
     *
     *      Author: $author$
     *        Date: 7/28/2009
     **********************************************************************
     */
    virtual ~cWinStandardWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual eError DestroyMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: RegisterWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError RegisterWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        error = windowClass.Register(hInstance);
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: UnregisterWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError UnregisterWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        error = windowClass.Unregister();
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 7/28/2009
     **********************************************************************
     */
    virtual eError InitializeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        HBRUSH hBrush;

        if (m_windowClassNameChars)
        if (0 > (length = windowClass.SetWindowClassName(m_windowClassNameChars)))
            return error = -length;

        if (!(hBrush = m_bgBrush.Attached()))
        if ((error = m_bgBrush.CreateSolid(m_bgColor.Attached())))
            return error;

        windowClass.SetBackground(m_bgBrush.Attached());
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FinalizeWindowClass
     *
     *   Author: $author$
     *     Date: 7/28/2009
     **********************************************************************
     */
    virtual eError FinalizeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        error = m_bgBrush.Destroy(true);
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetMainWindowRectangle
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual eError SetMainWindowRectangle
    (const RECT& rect) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: MainWindowRectangle
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual eError MainWindowRectangle
    (RECT& rect,
     HWND hWndParent) const 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetMainWindowParent
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual eError SetMainWindowParent
    (HWND hWndParent) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: MainWindowParent
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual HWND MainWindowParent
    (eError& error) const 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        HWND hWndParent = GetDesktopWindow();
        error = e_ERROR_NONE;
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        HWND hWndParent = NULL;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hWndParent;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowClassName
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual TLENGTH SetWindowClassName
    (const TCHAR* windowClassNameChars,
     TLENGTH length=UNDEFINED_LENGTH) 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowClassName
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual const TCHAR* WindowClassName
    (TLENGTH& length) const 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        const TCHAR* windowClassNameChars = m_windowClassNameChars;
        length = UNDEFINED_LENGTH;
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        const TCHAR* windowClassNameChars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;;
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return windowClassNameChars;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowClassName
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    virtual const TCHAR* WindowClassName() const 
#if defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        const TCHAR* windowClassNameChars = m_windowClassNameChars;
#else /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        const TCHAR* windowClassNameChars = 0;
#endif /* !defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return windowClassNameChars;
    }
#endif /* defined(CWINSTANDARDWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/28/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        SetIsCreated(false);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSTANDARDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINSTANDARDWINDOW_HXX) || defined(CWINSTANDARDWINDOW_MEMBERS_ONLY) */

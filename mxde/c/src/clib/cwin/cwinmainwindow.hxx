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
 *   File: cwinmainwindow.hxx
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
#if !defined(_CWINMAINWINDOW_HXX) || defined(CWINMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMAINWINDOW_HXX) && !defined(CWINMAINWINDOW_MEMBERS_ONLY)
#define _CWINMAINWINDOW_HXX
#endif /* !defined(_CWINMAINWINDOW_HXX) && !defined(CWINMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMAINWINDOW_MEMBERS_ONLY)
#include "cwinstandardwindow.hxx"
#include "cwinwindowclass.hxx"
#include "cwinwindow.hxx"
#include "cwincmdline.hxx"
#include "cstring.hxx"
#include "ctypes.hxx"

#define CWINMAINWINDOW_BG_COLOR_R 0xFF
#define CWINMAINWINDOW_BG_COLOR_G 0xFF
#define CWINMAINWINDOW_BG_COLOR_B 0xFF

#define CWINMAINWINDOW_BG_COLOR \
    RGB(CWINMAINWINDOW_BG_COLOR_R, \
        CWINMAINWINDOW_BG_COLOR_G, \
        CWINMAINWINDOW_BG_COLOR_B)

#define CWINMAINWINDOW_WINDOW_CLASSNAME \
    "cWinMainWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinMainWindow;

#undef CDB_CLASS
#define CDB_CLASS "cWinMainWindowT"
/**
 **********************************************************************
 *  Class: cWinMainWindowT
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
template
<class TDerives=cWinMainWindow,
 class TWinWindowExtend=cWinStandardWindow,
 class TExtends=TWinWindowExtend>

class c_EXPORT_CLASS cWinMainWindowT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    
    bool m_hasDropShadow;
    bool m_isLayeredWindow;
    
    cWinCmdLine m_cmdLine;

    /**
     **********************************************************************
     *  Constructor: cWinMainWindowT
     *
     *       Author: $author$
     *         Date: 12/31/2009
     **********************************************************************
     */
    cWinMainWindowT
    (COLORREF bgColor,
     bool hasDropShadow,
     bool isLayeredWindow,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_hasDropShadow(hasDropShadow),
      m_isLayeredWindow(isLayeredWindow)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cWinMainWindowT
     *
     *       Author: $author$
     *         Date: 12/31/2009
     **********************************************************************
     */
    cWinMainWindowT
    (COLORREF bgColor=CWINMAINWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_hasDropShadow(false),
      m_isLayeredWindow(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMainWindowT
     *
     *      Author: $author$
     *        Date: 12/31/2009
     **********************************************************************
     */
    virtual ~cWinMainWindowT()
    {
    }
#else /* !defined(CWINMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnMainWindowCreated
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual eError OnMainWindowCreated
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMainWindowDestroy
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual eError OnMainWindowDestroy
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        DWORD style = (m_isLayeredWindow)?(LayeredWindowStyle()):(WindowStyle());
        DWORD styleEx = (m_isLayeredWindow)?(LayeredWindowStyleEx()):(WindowStyleEx());
        int x = CW_USEDEFAULT;
        int y = CW_USEDEFAULT;
        int width = CW_USEDEFAULT;
        int height = CW_USEDEFAULT;
        const TCHAR* windowClassNameChars;
        HWND hWndDesktop;
        HWND hWnd;
        TLENGTH length;
        
        if (cmdLine)
        if (0 > (length = m_cmdLine.AssignCHARS(cmdLine)))
            return error = -length;

        if (!(error = ChangeDefaultWindowPosition(x,y)))
        if (!(error = ChangeDefaultWindowSize(width,height)))
        if ((windowClassNameChars = windowClass.WindowClassName()))
        if ((hWndDesktop = GetDesktopWindow()))
        if ((hWnd = CreateAttached
            (error, hInstance, windowClassNameChars, 
             NULL, hWndDesktop, NULL, style, styleEx, 
             x,y, width,height)))
        if (!(error = OnMainWindowCreated
            (windowClass, hInstance, hPrevinst, cmdLine, cmdShow)))
             Show();
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError DestroyMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        error = OnMainWindowDestroy
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnInitializedMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/28/2010
     **********************************************************************
     */
    virtual eError OnInitializedMainWindowClass
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/28/2010
     **********************************************************************
     */
    virtual eError OnFinalizeMainWindowClass
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: InitializeMainWindowClass
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError InitializeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = InitializeWindowClass
            (windowClass, hInstance)))
        {
            if ((m_hasDropShadow))
                windowClass.SetStyle(CS_DROPSHADOW);
            
            error = OnInitializedMainWindowClass
            (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError FinalizeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        eError error2;

        error = OnFinalizeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);

        if ((error2 = FinalizeWindowClass
            (windowClass, hInstance)))
        if (!(error))
            error = error2;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult;
        SetIsCreated(false);
        PostQuitMessage(0);
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: SetHasDropShadow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual bool SetHasDropShadow
    (bool isTrue=true) 
    {
        bool has = (m_hasDropShadow = isTrue);
        return has;
    }
    /**
     **********************************************************************
     * Function: HasDropShadow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual bool HasDropShadow() const 
    {
        bool has = m_hasDropShadow;
        return has;
    }
    
    /**
     **********************************************************************
     * Function: SetIsLayeredWindow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual bool SetIsLayeredWindow
    (bool isTrue=true) 
    {
        bool is = (m_isLayeredWindow = isTrue);
        return is;
    }
    /**
     **********************************************************************
     * Function: IsLayeredWindow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual bool IsLayeredWindow() const 
    {
        bool is = m_isLayeredWindow;
        return is;
    }
    
    /**
     **********************************************************************
     * Function: LayeredWindowStyle
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual DWORD LayeredWindowStyle() const 
    {
        DWORD style = WS_POPUP;
        return style;
    }
    /**
     **********************************************************************
     * Function: LayeredWindowStyleEx
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual DWORD LayeredWindowStyleEx() const 
    {
        DWORD style = WS_EX_LAYERED;
        return style;
    }
    
    /**
     **********************************************************************
     * Function: WindowStyle
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual DWORD WindowStyle() const 
    {
        DWORD style = WS_OVERLAPPEDWINDOW;
        return style;
    }
    /**
     **********************************************************************
     * Function: WindowStyleEx
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual DWORD WindowStyleEx() const 
    {
        DWORD style = 0;
        return style;
    }
    
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowPosition
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowPosition
    (int& x, int& y) const
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowSize
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: FirstCmdLineArg
     *
     *   Author: $author$
     *     Date: 8/1/2010
     **********************************************************************
     */
    virtual const TCHAR* FirstCmdLineArg
    (TLENGTH& length) const 
    {
        const TCHAR* chars = 0;
        chars = m_cmdLine.FirstArg(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: NextCmdLineArg
     *
     *   Author: $author$
     *     Date: 8/1/2010
     **********************************************************************
     */
    virtual const TCHAR* NextCmdLineArg
    (TLENGTH& length, const TCHAR* prevChars) const 
    {
        const TCHAR* chars = 0;
        chars = m_cmdLine.NextArg(length, prevChars);
        return chars;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinMainWindowExtend
 *
 *  Author: $author$
 *    Date: 1/1/2010
 **********************************************************************
 */
typedef cWinMainWindowT
<cWinMainWindow, cWinStandardWindow>
cWinMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMainWindow
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMainWindow
: public cWinMainWindowExtend
{
public:
    typedef cWinMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMainWindow
     *
     *       Author: $author$
     *         Date: 1/1/2010
     **********************************************************************
     */
    cWinMainWindow
    (COLORREF bgColor=CWINMAINWINDOW_BG_COLOR,
     bool hasDropShadow=false,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMainWindow
     *
     *      Author: $author$
     *        Date: 1/1/2010
     **********************************************************************
     */
    virtual ~cWinMainWindow()
    {
    }
#else /* !defined(CWINMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_CLOSE_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_CLOSE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        PostQuitMessage(0);
        Destroy();
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMAINWINDOW_HXX) || defined(CWINMAINWINDOW_MEMBERS_ONLY) */

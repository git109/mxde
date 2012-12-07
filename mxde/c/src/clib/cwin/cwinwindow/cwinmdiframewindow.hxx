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
 *   File: cwinmdiframewindow.hxx
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
#if !defined(_CWINMDIFRAMEWINDOW_HXX) || defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMDIFRAMEWINDOW_HXX) && !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY)
#define _CWINMDIFRAMEWINDOW_HXX
#endif /* !defined(_CWINMDIFRAMEWINDOW_HXX) && !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY)
#include "cwinmdiclientwindow.hxx"
#include "cwinstandardwindow.hxx"
#include "cwinmdiclientwindowsuperclass.hxx"
#include "cwinmdichildwindowclass.hxx"

#define CWINMDIFRAMEWINDOW_BG_COLOR \
    CWINSTANDARDWINDOW_BG_COLOR
    
#define CWINMDIFRAMEWINDOW_WINDOW_CLASSNAME "cWinMDIFrameWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinMDIFrameWindow;

#undef CDB_CLASS
#define CDB_CLASS "cWinMDIFrameWindowT"
/**
 **********************************************************************
 *  Class: cWinMDIFrameWindowT
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
template
<class TDerives=cWinMDIFrameWindow,
 class TWinMDIFrameWindowExtend=cWinStandardWindow,
 class TWinMDIChildWindowClass=cWinMDIChildWindowClass,
 class TWinMDIClientWindow=cWinMDIClientWindow,
 class TWinMDIClientWindowClass=cWinMDIClientWindowSuperClass,
 class TExtends=TWinMDIFrameWindowExtend>

class c_EXPORT_CLASS cWinMDIFrameWindowT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TWinMDIChildWindowClass tWinMDIChildWindowClass;
    typedef TWinMDIClientWindowClass tWinMDIClientWindowClass;
    typedef TWinMDIClientWindow tWinMDIClientWindow;
    
    const TCHAR* m_mdiChildWindowClassNameChars;
    const TCHAR* m_mdiClientWindowClassNameChars;
    tWinMDIClientWindow m_mdiClientWindow;
    HWND m_hWndMDIClient;
    
    /**
     **********************************************************************
     *  Constructor: cWinMDIFrameWindowT
     *
     *       Author: $author$
     *         Date: 1/2/2010
     **********************************************************************
     */
    cWinMDIFrameWindowT
    (COLORREF bgColor=CWINMDIFRAMEWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDIFRAMEWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hBgBrush,
       windowClassNameChars,
       hInstance, attached, isCreated),
       
      m_mdiChildWindowClassNameChars
      (_T(CWINMDICHILDWINDOWCLASS_WINDOW_CLASSNAME)),
      
      m_mdiClientWindowClassNameChars
      (_T(CWINMDICLIENTWINDOW_WINDOW_CLASSNAME)),
      m_hWndMDIClient(NULL)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIFrameWindowT
     *
     *      Author: $author$
     *        Date: 1/2/2010
     **********************************************************************
     */
    virtual ~cWinMDIFrameWindowT()
    {
    }
#else /* !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: RegisterMDIClientWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError RegisterMDIClientWindowClass
    (tWinMDIClientWindowClass& windowClass,
     HINSTANCE hInstance, const TCHAR* windowClassNameChars=0) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = InitializeMDIClientWindowClass
            (windowClass, hInstance, windowClassNameChars)))
            error = windowClass.Register(hInstance);
        return error;
    }
    /**
     **********************************************************************
     * Function: UnregisterMDIClientWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError UnregisterMDIClientWindowClass
    (tWinMDIClientWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        error = windowClass.Unregister();
        if ((error2 = FinalizeMDIClientWindowClass
            (windowClass, hInstance)))
        if (!error)
            error = error2;
        return error;
    }    
    /**
     **********************************************************************
     * Function: InitializeMDIClientWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError InitializeMDIClientWindowClass
    (tWinMDIClientWindowClass& windowClass,
     HINSTANCE hInstance, const TCHAR* windowClassNameChars=0) 
    {
        eError error = e_ERROR_NONE;
        if ((windowClassNameChars))
            windowClass.SetWindowClassName(windowClassNameChars);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMDIClientWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError FinalizeMDIClientWindowClass
    (tWinMDIClientWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: RegisterMDIChildWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError RegisterMDIChildWindowClass
    (tWinMDIChildWindowClass& windowClass,
     HINSTANCE hInstance, const TCHAR* windowClassNameChars=0) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = InitializeMDIChildWindowClass
            (windowClass, hInstance, windowClassNameChars)))
            error = windowClass.Register(hInstance);
        return error;
    }
    /**
     **********************************************************************
     * Function: UnregisterMDIChildWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError UnregisterMDIChildWindowClass
    (tWinMDIChildWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        error = windowClass.Unregister();
        if ((error2 = FinalizeMDIChildWindowClass
            (windowClass, hInstance)))
        if (!error)
            error = error2;
        return error;
    }    
    /**
     **********************************************************************
     * Function: InitializeMDIChildWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError InitializeMDIChildWindowClass
    (tWinMDIChildWindowClass& windowClass,
     HINSTANCE hInstance, const TCHAR* windowClassNameChars=0) 
    {
        eError error = e_ERROR_NONE;
        if ((windowClassNameChars))
            windowClass.SetWindowClassName(windowClassNameChars);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMDIChildWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError FinalizeMDIChildWindowClass
    (tWinMDIChildWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: On_WM_CREATE_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        DWORD style = CWINMDICLIENTWINDOW_WINDOW_STYLE;
        DWORD styleEx = CWINMDICLIENTWINDOW_WINDOW_EXSTYLE;
        int x = CW_USEDEFAULT;
        int y = CW_USEDEFAULT;
        int width = CW_USEDEFAULT;
        int height = CW_USEDEFAULT;
        const TCHAR* windowClassNameChars;
        sWinCLIENTCREATESTRUCT ccs;
        eError error;
       
        if ((windowClassNameChars = m_mdiClientWindowClassNameChars))
        {
            ccs.ccs.hWindowMenu = NULL;
            ccs.ccs.idFirstChild = 0;
            ccs.target = (cWinWindowMessageTargetInterface*)(&m_mdiClientWindow);
            
            if ((m_mdiClientWindow.HasAllChildStyles()))
                style |= MDIS_ALLCHILDSTYLES;
                
            if ((m_hWndMDIClient = m_mdiClientWindow.CreateAttached
                (error, m_hInstance, windowClassNameChars, 
                 NULL, hWnd, NULL, style, styleEx, 
                 x,y, width,height, &ccs)))
                m_mdiClientWindow.Show();
        }
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        HWND hWndMDIClient = m_hWndMDIClient;
        LRESULT lResult = DefFrameProc
        (hWnd,hWndMDIClient,msg,wParam,lParam);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: SetHasAllChildStyles
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual bool SetHasAllChildStyles
    (bool isTrue=true) 
    {
        bool has = m_mdiClientWindow.SetHasAllChildStyles(isTrue);
        return has;
    }
    /**
     **********************************************************************
     * Function: HasAllChildStyles
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual bool HasAllChildStyles() const 
    {
        bool has = m_mdiClientWindow.HasAllChildStyles();
        return has;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinMDIFrameWindowExtend
 *
 *  Author: $author$
 *    Date: 1/2/2010
 **********************************************************************
 */
typedef cWinMDIFrameWindowT
<cWinMDIFrameWindow, cWinStandardWindow>
cWinMDIFrameWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMDIFrameWindow
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIFrameWindow
: public cWinMDIFrameWindowExtend
{
public:
    typedef cWinMDIFrameWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMDIFrameWindow
     *
     *       Author: $author$
     *         Date: 1/2/2010
     **********************************************************************
     */
    cWinMDIFrameWindow
    (COLORREF bgColor=CWINSTANDARDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDIFRAMEWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hBgBrush,
       windowClassNameChars,
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIFrameWindow
     *
     *      Author: $author$
     *        Date: 1/2/2010
     **********************************************************************
     */
    virtual ~cWinMDIFrameWindow()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDIFRAMEWINDOW_HXX) || defined(CWINMDIFRAMEWINDOW_MEMBERS_ONLY) */

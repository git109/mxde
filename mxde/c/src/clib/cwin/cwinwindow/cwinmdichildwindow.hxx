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
 *   File: cwinmdichildwindow.hxx
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
#if !defined(_CWINMDICHILDWINDOW_HXX) || defined(CWINMDICHILDWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMDICHILDWINDOW_HXX) && !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY)
#define _CWINMDICHILDWINDOW_HXX
#endif /* !defined(_CWINMDICHILDWINDOW_HXX) && !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY)
#include "cwinmdiclientwindow.hxx"
#include "cwinmdichildwindowclass.hxx"
#include "cwinstandardwindow.hxx"

#define CWINMDICHILDWINDOW_WINDOW_STYLE \
    MDIS_ALLCHILDSTYLES
    
#define CWINMDICHILDWINDOW_WINDOW_EXSTYLE \
    WS_EX_MDICHILD

#define CWINMDICHILDWINDOW_WINDOW_CLASSNAME \
    CWINMDICHILDWINDOWCLASS_WINDOW_CLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cWinMDIChildWindowT"
/**
 **********************************************************************
 *  Class: cWinMDIChildWindowT
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
template
<class TDerives=cWinMDIChildWindow,
 class TWinMDIChildWindowExtend=cWinStandardWindow,
 class TExtends=TWinMDIChildWindowExtend>

class c_EXPORT_CLASS cWinMDIChildWindowT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    
    /**
     **********************************************************************
     *  Constructor: cWinMDIChildWindowT
     *
     *       Author: $author$
     *         Date: 1/2/2010
     **********************************************************************
     */
    cWinMDIChildWindowT
    (COLORREF bgColor=CWINSTANDARDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDICHILDWINDOW_WINDOW_CLASSNAME),
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
     *  Destructor: ~cWinMDIChildWindowT
     *
     *      Author: $author$
     *        Date: 1/2/2010
     **********************************************************************
     */
    virtual ~cWinMDIChildWindowT()
    {
    }
#else /* !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    static cDerives* CreateInstance
    (eError& error, HINSTANCE hInstance, 
     HWND hParentWnd, LPCTSTR windowName=NULL, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     LPCTSTR className=NULL, HMENU hMenu=NULL_HANDLE, 
     DWORD style=CWINMDICHILDWINDOW_WINDOW_STYLE,
     DWORD exStyle=CWINMDICHILDWINDOW_WINDOW_EXSTYLE) 
    {
        cDerives* instance = 0;
        error = e_ERROR_NEW;
        if ((instance = new cDerives()))
        {
            if (!(error = instance->CreateTheWindow
                (hInstance, hParentWnd, windowName, 
                 x,y, width,height, hMenu, className, 
                 style, exStyle)))
                return instance;
                
            delete instance;
            instance = 0;
        }
        return instance;
    }
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    static eError DestroyInstance
    (cDerives& instance) 
    {
        eError error = instance.Destroy();
        delete &instance;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: CreateTheWindow
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual eError CreateTheWindow
    (HINSTANCE hInstance, 
     HWND hParentWnd, LPCTSTR windowName=NULL, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     HMENU hMenu=NULL_HANDLE, LPCTSTR className=NULL, 
     DWORD style=CWINMDICHILDWINDOW_WINDOW_STYLE,
     DWORD exStyle=CWINMDICHILDWINDOW_WINDOW_EXSTYLE, 
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        CreateTheWindowAttached
        (error, hInstance, hParentWnd, windowName, 
         x,y, width,height, hMenu, className, 
         style, exStyle, onlyDestroyed);
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateTheWindowAttached
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual HWND CreateTheWindowAttached
    (eError& error, HINSTANCE hInstance, 
     HWND hParentWnd, LPCTSTR windowName=NULL, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     HMENU hMenu=NULL_HANDLE, LPCTSTR className=NULL, 
     DWORD style=CWINMDICHILDWINDOW_WINDOW_STYLE,
     DWORD exStyle=CWINMDICHILDWINDOW_WINDOW_EXSTYLE, 
     bool onlyDestroyed=false) 
    {
        HWND hWnd;
        
        if (!(className))
            className = WindowClassName();
            
        hWnd = CreateAttached
        (error, hInstance, className, windowName, 
         hParentWnd, hMenu, style, exStyle, 
         x,y, width,height, NULL, onlyDestroyed);
        return hWnd;
    }
    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual HWND CreateDetached
    (eError& error,
     DWORD exStyle, LPCTSTR className, 
     LPCTSTR windowName, DWORD style, 
     int x, int y, int width, int height, 
     HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) const
    {
        HWND detached = NULL;
        
        error = e_ERROR_FAILED;
        
        if ((detached = CreateMDIWindow
            (className, windowName, style, 
             x,y, width,height, hParentWnd, 
             hInstance, ((LPARAM)lParam))))
             error = e_ERROR_NONE;
             
        return detached;
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
        LRESULT lResult = DefMDIChildProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
};
#undef CDB_CLASS

class c_EXPORT_CLASS cWinMDIChildWindow;
/**
 **********************************************************************
 * Typedef: cWinMDIChildWindowExtend
 *
 *  Author: $author$
 *    Date: 1/2/2010
 **********************************************************************
 */
typedef cWinMDIChildWindowT
<cWinMDIChildWindow, cWinStandardWindow>
cWinMDIChildWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMDIChildWindow
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIChildWindow
: public cWinMDIChildWindowExtend
{
public:
    typedef cWinMDIChildWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMDIChildWindow
     *
     *       Author: $author$
     *         Date: 1/2/2010
     **********************************************************************
     */
    cWinMDIChildWindow
    (COLORREF bgColor=CWINSTANDARDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDICHILDWINDOW_WINDOW_CLASSNAME),
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
     *  Destructor: ~cWinMDIChildWindow
     *
     *      Author: $author$
     *        Date: 1/2/2010
     **********************************************************************
     */
    virtual ~cWinMDIChildWindow()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICHILDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDICHILDWINDOW_HXX) || defined(CWINMDICHILDWINDOW_MEMBERS_ONLY) */

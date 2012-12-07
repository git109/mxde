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
 *   File: cwinwindow.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINWINDOW_HXX) || defined(CWINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINWINDOW_HXX) && !defined(CWINWINDOW_MEMBERS_ONLY)
#define _CWINWINDOW_HXX
#endif /* !defined(_CWINWINDOW_HXX) && !defined(CWINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINWINDOW_MEMBERS_ONLY)
#include "cwinwindowinterface.hxx"
#include "cwinhwnd.hxx"
#include "cstring.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinWindowExtend
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinHWND
cWinWindowExtend;
/**
 **********************************************************************
 *  Class: cWinWindow
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinWindow
: virtual public cWinWindowImplement,
  public cWinWindowExtend
{
public:
    typedef cWinWindowImplement cImplements;
    typedef cWinWindowExtend cExtends;

    HINSTANCE m_hInstance;
    
    /**
     **********************************************************************
     *  Constructor: cWinWindow
     *
     *       Author: $author$
     *         Date: 11/20/2011
     **********************************************************************
     */
    cWinWindow
    (HWND attached,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_hInstance(NULL)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cWinWindow
     *
     *       Author: $author$
     *         Date: 7/21/2010
     **********************************************************************
     */
    cWinWindow
    (HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_hInstance(hInstance)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinWindow
     *
     *      Author: $author$
     *        Date: 7/21/2010
     **********************************************************************
     */
    virtual ~cWinWindow()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOW_MEMBERS_ONLY) */

    /*
     **********************************************************************
     * Create/Destroy
     **********************************************************************
     */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$
     *      Date: 7/21/2010
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance, LPCTSTR className, 
     LPCTSTR windowName=NULL, HWND hParentWnd=NULL_HANDLE, 
     HMENU hMenu=NULL_HANDLE, DWORD style=CWIN_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWIN_DEFAULT_WINDOW_EXSTYLE, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     LPVOID lParam=NULL, bool onlyDestroyed=false)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        CreateAttached
        (error, hInstance, className, windowName, 
         hParentWnd, hMenu, style, exStyle, 
         x, y, width, height, lParam, 
         onlyDestroyed);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HWND CreateAttached
    (eError& error, HINSTANCE hInstance, LPCTSTR className, 
     LPCTSTR windowName=NULL, HWND hParentWnd=NULL_HANDLE, 
     HMENU hMenu=NULL_HANDLE, DWORD style=CWIN_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWIN_DEFAULT_WINDOW_EXSTYLE, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     LPVOID lParam=NULL, bool onlyDestroyed=false) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HWND hWndAttached = CreateAttached
        (error, exStyle, className, windowName, style, 
         x, y, width, height, hParentWnd, hMenu, hInstance, 
         (lParam)?(lParam):((LPVOID)((cWinWindowMessageTargetInterface*)(this))), 
         onlyDestroyed);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hWndAttached;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$
     *      Date: 7/21/2010
     **********************************************************************
     */
    virtual eError Create
    (DWORD exStyle, LPCTSTR className, 
     LPCTSTR windowName, DWORD style, 
     int x, int y, int width, int height, 
     HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam,
     bool onlyDestroyed=false)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        CreateAttached
        (error, exStyle, className, windowName, style, 
         x, y, width, height, hParentWnd, hMenu, 
         hInstance, lParam, onlyDestroyed);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HWND CreateAttached
    (eError& error,
     DWORD exStyle, LPCTSTR className, 
     LPCTSTR windowName, DWORD style, 
     int x, int y, int width, int height, 
     HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam,
     bool onlyDestroyed=false) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HWND hWndAttached = NULL;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        HWND detached;

        if (!(error = Destroyed(onlyDestroyed)))
        if ((detached = CreateDetached
            (error, exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, lParam)))
        if (detached == (hWndAttached = AttachCreated(detached)))
            m_hInstance = hInstance;
        else
        DestroyDetached(detached);
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hWndAttached;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$
     *      Date: 7/21/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND detached;
        
        if ((detached = Detach()))
            error = DestroyDetached(detached);
        else
        if (!(onlyCreated))
            error = e_ERROR_NONE;
            
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        HWND detached = NULL;
        error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        if ((detached = CreateWindowEx
            (exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, lParam)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on CreateWindowEx()\n"));
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (HWND detached) const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        if (DestroyWindow(detached))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on DestroyWindow()\n"));
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Move
     *
     *    Author: $author$
     *      Date: 7/28/2010
     **********************************************************************
     */
    virtual eError Move
    (int x,int y, 
     int width,int height, 
     BOOL repaint = FALSE)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((MoveWindow(hWnd, x,y, width,height, repaint)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: MoveTo
     *
     *    Author: $author$
     *      Date: 8/2/2010
     **********************************************************************
     */
    virtual eError MoveTo
    (int x,int y, 
     BOOL repaint = FALSE)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND hWnd;
        RECT r;
        if ((hWnd = Attached()))
        if ((GetWindowRect(hWnd, &r)))
        if ((MoveWindow
            (hWnd, x,y, (r.right-r.left),
             (r.bottom-r.top), repaint)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SizeTo
     *
     *    Author: $author$
     *      Date: 8/2/2010
     **********************************************************************
     */
    virtual eError SizeTo
    (int width,int height, 
     BOOL repaint = FALSE)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND hWnd;
        HWND hWndParent;
        RECT r;
        POINT p;
        if ((hWnd = Attached()))
        if ((GetWindowRect(hWnd, &r)))
        {
            p.x = r.left;
            p.y = r.top;
            
            if ((hWndParent = GetParent(hWnd)))
            if (!(ScreenToClient(hWndParent, &p)))
                return e_ERROR_FAILED;
                
            if ((MoveWindow
                (hWnd, p.x,p.y, 
                 width,height, repaint)))
                error = e_ERROR_NONE;
        }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /*
     **********************************************************************
     * Show
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: Show
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual eError Show
    (INT cmdShow=SW_SHOWNORMAL) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        HWND hWnd;
        if ((hWnd = Attached()))
        {
            ShowWindow(hWnd, cmdShow);
            error = e_ERROR_NONE;
        }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Hide
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual eError Hide
    (INT cmdShow=SW_HIDE) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = Show(cmdShow);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /*
     **********************************************************************
     * Text
     **********************************************************************
     */

    /**
     **********************************************************************
     *  Function: SetText
     *
     *    Author: $author$
     *      Date: 12/5/2009
     **********************************************************************
     */
    virtual eError SetText
    (const CHAR* chars)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((SetWindowTextA(hWnd, chars)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetText
     *
     *    Author: $author$
     *      Date: 12/5/2009
     **********************************************************************
     */
    virtual eError SetText
    (const WCHAR* chars)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((SetWindowTextW(hWnd, chars)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /*
     **********************************************************************
     * Rgn
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: SetRgn
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HRGN SetRgn
    (HRGN hToRgn,
     BOOL bRedraw=FALSE) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        HRGN hRgn = SetRgn(error, hToRgn, bRedraw);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetRgn
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HRGN GetRgn
    (HRGN hCopyToRgn) const 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        HRGN hRgn = GetRgn(error, hCopyToRgn);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetRgn
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HRGN SetRgn
    (eError& error,
     HRGN hToRgn,
     BOOL bRedraw=FALSE) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
        if (!(hToRgn))
            error = e_ERROR_NULL_PARAMETER;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        else
        {
            HWND hWnd;
            if (!(hWnd = Attached()))
                error = e_ERROR_NOT_ATTACHED;
            else
            if ((SetWindowRgn(hWnd, hToRgn, bRedraw)))
            {
                hRgn = hToRgn;
                error = e_ERROR_NONE;
            }
            else
            error = e_ERROR_FAILED;
        }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        else
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetRgn
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HRGN GetRgn
    (eError& error,
     HRGN hCopyToRgn) const 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
        if (!(hCopyToRgn))
            error = e_ERROR_NULL_PARAMETER;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        else
        {
            HWND hWnd;
            if (!(hWnd = Attached()))
                error = e_ERROR_NOT_ATTACHED;
            else
            if ((GetWindowRgn(hWnd, hCopyToRgn)))
            {
                hRgn = hCopyToRgn;
                error = e_ERROR_NONE;
            }
            else
            error = e_ERROR_FAILED;
        }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        else
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /*
     **********************************************************************
     * Rect
     **********************************************************************
     */

    /**
     **********************************************************************
     *  Function: GetRect
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual eError GetRect(RECT& rect) const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND attached;
        if ((attached = Attached()))
        if ((::GetWindowRect(attached, &rect)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetClientRect
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual eError GetClientRect(RECT& rect) const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND attached;
        if ((attached = Attached()))
        if ((::GetClientRect(attached, &rect)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetWindowRect
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual eError GetWindowRect(RECT& rect) const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND attached;
        if ((attached = Attached()))
        if ((::GetWindowRect(attached, &rect)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetClientWindowRect
     *
     *    Author: $author$
     *      Date: 7/28/2010
     **********************************************************************
     */
    virtual eError GetClientWindowRect(RECT& rect) const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND attached;
        RECT rectWnd;
        POINT point;
        if ((attached = Attached()))
        if ((::GetClientRect(attached, &rect)))
        if ((::GetWindowRect(attached, &rectWnd)))
        {
            point.x = rect.left;
            point.y = rect.top;
            if ((::ClientToScreen(attached, &point)))
            {
                rect.left = (point.x - rectWnd.left);
                rect.top = (point.y - rectWnd.top);
                rect.right += rect.left;
                rect.bottom += rect.top;
                error = e_ERROR_NONE;
            }
        }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetClientBorderRect
     *
     *    Author: $author$
     *      Date: 7/28/2010
     **********************************************************************
     */
    virtual eError GetClientBorderRect(RECT& rect) const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HWND attached;
        RECT rectWnd;
        POINT point;
        if ((attached = Attached()))
        if ((::GetClientRect(attached, &rect)))
        if ((::GetWindowRect(attached, &rectWnd)))
        {
            point.x = rect.left;
            point.y = rect.top;
            if ((::ClientToScreen(attached, &point)))
            {
                rect.left = (point.x - rectWnd.left);
                rect.top = (point.y - rectWnd.top);
                
                point.x = rect.right;
                point.y = rect.bottom;
                
                if ((::ClientToScreen(attached, &point)))
                {
                    rect.right = (rectWnd.right - point.x);
                    rect.bottom = (rectWnd.bottom - point.y);
                    error = e_ERROR_NONE;
                }
            }
        }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: GetClientRect
     *
     *    Author: $author$
     *      Date: 7/21/2010
     **********************************************************************
     */
    static inline BOOL GetClientRect
    (HWND hWnd, LPRECT lpRect)
    {
        BOOL success = ::GetClientRect(hWnd, lpRect);
        return success;
    }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: GetWindowRect
     *
     *    Author: $author$
     *      Date: 7/21/2010
     **********************************************************************
     */
    static inline BOOL GetWindowRect
    (HWND hWnd, LPRECT lpRect)
    {
        BOOL success = ::GetWindowRect(hWnd, lpRect);
        return success;
    }
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CWINWINDOW_MEMBERS_ONLY)
/* include cWinAttachedHINSTANCE member functions
 */
#define CWINATTACHEDHINSTANCE_MEMBERS_ONLY
#include "cwinattachedhinstance.hxx"
#undef CWINATTACHEDHINSTANCE_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINWINDOW_HXX) || defined(CWINWINDOW_MEMBERS_ONLY) */

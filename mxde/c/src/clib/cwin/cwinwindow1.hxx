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
 *   File: cwinwindow.hxx
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
#ifndef _CWINWINDOW_HXX
#define _CWINWINDOW_HXX

#include "cwinwindowmessagetargetinterface.hxx"
#include "cwinattachedhinstanceinterface.hxx"
#include "cwinhwnd.hxx"
#include "cstring.hxx"
#include "cdebug.hxx"

#define CWIN_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define CWIN_DEFAULT_WINDOW_EXSTYLE 0

/**
 **********************************************************************
 *  Class: cWinWindow
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindow
: virtual public cWinWindowMessageTargetImplement,
  virtual public cWinAttachedHINSTANCEImplement,
  public cWinHWND
{
public:
    typedef cWinWindowMessageTargetImplement cImplements;
    typedef cWinHWND cExtends;
    typedef cWinWindow cDerives;

    HINSTANCE m_hInstance;

    /**
     **********************************************************************
     * Constructor: cWinWindow
     *
     *      Author: $author$
     *        Date: 5/7/2009
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
     * Destructor: ~cWinWindow
     *
     *     Author: $author$
     *       Date: 5/7/2009
     **********************************************************************
     */
    virtual ~cWinWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/19/2009
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
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        error = Create
        (className, windowName, style, exStyle, 
         x, y, width, height, hParentWnd, hMenu, hInstance, 
         (lParam)?(lParam):((LPVOID)((cWinWindowMessageTargetInterface*)(this))), 
         onlyDestroyed);
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual eError Create
    (LPCTSTR className, LPCTSTR windowName, 
     DWORD style, DWORD exStyle, 
     int x, int y, int width, int height, 
     HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam,
     bool onlyDestroyed=false) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
        CreateAttached
        (error, className, windowName, style, exStyle, 
         x, y, width, height, hParentWnd, hMenu, hInstance, lParam);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        HWND detached;
        bool isCreated;

        if ((isCreated = IsCreated()))
            SetIsCreated(false);
        else
        if (onlyCreated)
            return e_ERROR_NOT_CREATED;

        m_hInstance = NULL;
        detached = Detach();
        error = DestroyDetached(detached);
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

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
        if ((GetWindowRect(attached, &rect)))
            error = e_ERROR_NONE;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */

#if defined(TCHAR_NOT_CHAR) 
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
        TLENGTH length;
        const TCHAR* tchars;
        cTCHARString tstring;
        if (0 < (length = tstring.AssignCHARS(chars)))
        if ((tchars = tstring.HasChars(length)))
            error = SetText(tchars);
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
#endif /* defined(TCHAR_NOT_CHAR) */
    /**
     **********************************************************************
     *  Function: SetText
     *
     *    Author: $author$
     *      Date: 12/5/2009
     **********************************************************************
     */
    virtual eError SetText
    (const TCHAR* chars)
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((SetWindowText(hWnd, chars)))
            error = e_ERROR_NONE;
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
        (error, className, windowName, style, exStyle, 
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
     * Function: CreateAttached
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HWND CreateAttached
    (eError& error,
     LPCTSTR className, LPCTSTR windowName, 
     DWORD style, DWORD exStyle, 
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
        bool isCreated;
        HWND detached;

        if (!(error = Destroyed(onlyDestroyed)))
        if ((isCreated = (NULL != (detached = CreateDetached
            (error, exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, lParam)))))
        if ((hWndAttached = Attach(detached)))
        {
            m_hInstance = hInstance;
            SetIsCreated(isCreated);
        }
        else
        DestroyDetached(detached);
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hWndAttached;
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
     * Function: AttachInstance
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HINSTANCE AttachInstance
    (HINSTANCE hToInstance,
     bool onlyDetached=false) 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HINSTANCE hInstance = NULL;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        HINSTANCE attached;
        if (!(attached = AttachedInstance())
            ||!onlyDetached)
            hInstance = (m_hInstance = hToInstance);
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hInstance;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DetachInstance
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HINSTANCE DetachInstance() 
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HINSTANCE hInstance = NULL;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        hInstance = (m_hInstance);
        m_hInstance = NULL;
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hInstance;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AttachedInstance
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HINSTANCE AttachedInstance() const
#if defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HINSTANCE hInstance = NULL;
#if !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        hInstance = (m_hInstance);
#else /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hInstance;
    }
#endif /* defined(CWINWINDOW_MEMBER_FUNCS_INTERFACE) */
};
#endif /* _CWINWINDOW_HXX */

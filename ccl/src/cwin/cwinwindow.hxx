/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cwinwindow.hxx
 *
 * Author: $author$
 *   Date: 4/15/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINWINDOW_HXX
#define _CWINWINDOW_HXX

#include "cwinhandle.hxx"
#include "cwinrect.hxx"

#define CWIN_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define CWIN_DEFAULT_WINDOW_EXSTYLE 0

/**
 **********************************************************************
 *  Class: cWinWindow
 *
 * Author: $author$
 *   Date: 1/24/2004
 **********************************************************************
 */
class cWinWindow
: public cCreatedHandleT<HWND, NULL>
{
public:
    typedef cCreatedHandleT<HWND, NULL> cIs;
    typedef cWinWindow cAs;

    HINSTANCE m_instance;
    HINSTANCE m_old_instance;

    /**
     **********************************************************************
     * Constructor: cWinWindow
     *
     *      Author: $author$
     *        Date: 1/24/2004
     **********************************************************************
     */
    cWinWindow
    (HINSTANCE instance=NULL, HWND handle=NULL, 
     bool created=false, HINSTANCE old_instance=NULL) 
    : cIs(handle, created),
      m_instance(instance),
      m_old_instance(old_instance)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindow
     *
     *     Author: $author$
     *       Date: 1/24/2004
     **********************************************************************
     */
    virtual ~cWinWindow()
    {
        eError error;

        if (m_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    static cWinWindow* CreateInstance(eError& error, HWND handle) 
    {
        cWinWindow* window = 0;

        if ((window = new cWinWindow()))
        {
            if ((error = window->Attach(handle)))
            {
                delete window;
                window = 0;
            }
            else error = e_ERROR_NONE;
        }
        else error = e_ERROR_FAILED;
        return window;
    }
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual eError DestroyInstance() 
    {
        eError error = Detach();

        delete this;
        return error;
    }


    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual eError Create
    (LPCTSTR classname, HINSTANCE instance, 
     LPCTSTR windowname=NULL, HWND parent=NULL, 
     HMENU menu=NULL, DWORD style=CWIN_DEFAULT_WINDOW_STYLE,
     DWORD exstyle=CWIN_DEFAULT_WINDOW_EXSTYLE, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT)
    {
        return CreateTheWindow
        (classname, windowname, style, exstyle, 
         x, y, width, height, parent, menu, instance, this);
    }
    /**
     **********************************************************************
     * Function: CreateTheWindow
     *
     *   Author: $author$
     *     Date: 5/4/2004
     **********************************************************************
     */
    virtual eError CreateTheWindow
    (LPCTSTR classname, LPCTSTR windowname, 
     DWORD style, DWORD exstyle, 
     int x, int y, int width, int height, 
     HWND parent, HMENU menu, 
     HINSTANCE instance, LPVOID param)
    {
        HINSTANCE old_instance=m_instance;

        m_instance = instance;

        if (NULL != (m_handle = CreateWindowEx
            (exstyle, classname, windowname, style, 
             x, y, width, height, parent, menu, instance, param)))
        {
            m_created = true;
            return e_ERROR_NONE;
        }

        m_instance = old_instance;
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        m_created = false;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DestroyWindow(m_handle))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(_WIN32_WCE) 
        if (ShowWindow(m_handle, SW_HIDE))
#else /* defined(_WIN32_WCE) */
        if (CloseWindow(m_handle))
#endif /* defined(_WIN32_WCE) */
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: SendMessage
     *
     *   Author: $author$
     *     Date: 5/3/2004
     **********************************************************************
     */
    virtual LRESULT SendMessage
    (UINT message, WPARAM wparam, LPARAM lparam) const
    {
        if (m_handle)
            return ::SendMessage
            (m_handle, message, wparam, lparam);
        return 0;
    }
    /**
     **********************************************************************
     * Function: PostMessage
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT PostMessage
    (UINT message, WPARAM wparam, LPARAM lparam) const
    {
        if (m_handle)
            return ::PostMessage
            (m_handle, message, wparam, lparam);
        return 0;
    }

    /**
     **********************************************************************
     * Function: Invalidate
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    virtual eError Invalidate(bool erase=false)
    {
        RECT rect;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (GetWindowRect(m_handle, &rect))
        {
            rect.right -= rect.left;
            rect.bottom -= rect.top;
            rect.left = 0;
            rect.top = 0;

            if (InvalidateRect(m_handle, &rect, erase?TRUE:FALSE))
                return e_ERROR_NONE;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Show
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual eError Show(int show=SW_SHOW)
    {
        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (ShowWindow(m_handle, show))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: SetPosTop
     *
     *   Author: $author$
     *     Date: 6/6/2006
     **********************************************************************
     */
    virtual eError SetPosTop(bool foreground=true)
    {
        eError error = e_ERROR_FAILED;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        SetWindowPos
        (m_handle, HWND_TOP, 0,0,0,0, 
         SWP_NOMOVE | SWP_NOSIZE);

        if (foreground)
            SetForegroundWindow(m_handle);
        return error;
    }

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual int SetText(LPCTSTR text, int length=-1)
    {
        if (!m_handle)
            return -e_ERROR_NOT_ATTACHED;

        length = SetWindowText(m_handle, text);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual int GetText(LPTSTR text, int size)
    {
        if (!m_handle)
            return -e_ERROR_NOT_ATTACHED;

        size = GetWindowText(m_handle, text, size);
        return size;
    }

    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    inline HINSTANCE GetInstance() const
    {
        return m_instance;
    }

    /**
     **********************************************************************
     * Operator: HWND
     *
     *   Author: $author$
     *     Date: 5/6/2004
     **********************************************************************
     */
    operator HWND() const
    {
        return GetHandle();
    }

    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    static LRESULT CALLBACK WindowProc
    (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        cWinWindow *window;
        CREATESTRUCT *cs;
        LPVOID data;

        window = (cWinWindow*)GetWindowLong(handle, GWL_USERDATA);

        switch(message)
        {
#if defined(_WIN32_WCE)
        case WM_CREATE:
#else /* defined(_WIN32_WCE) */
        case WM_NCCREATE:
#endif /* defined(_WIN32_WCE) */
            if ((cs = (CREATESTRUCT*)lparam))
            {
                data = cs->lpCreateParams;
                SetWindowLong(handle, GWL_USERDATA, (LONG)data);

                if (NULL != (window = (cWinWindow*)data))
                if (NULL == window->m_handle)
                    window->m_handle = handle;
            }
            break;
        }

        if (window)
            return window->OnWindowProc(message, wparam, lparam);

        return DefWindowProc(handle, message, wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: CreateInstanceWindowProc
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    static LRESULT CALLBACK CreateInstanceWindowProc
    (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        cWinWindow *window = 0;
        LRESULT result;
        eError error;

        switch(message)
        {
#if defined(_WIN32_WCE) 
        case WM_CREATE:
#else /* defined(_WIN32_WCE) */
        case WM_NCCREATE:
#endif /* defined(_WIN32_WCE) */
            if ((window = CreateInstance(error, handle)))
                SetWindowLong(handle, GWL_USERDATA, (LONG)window);
            break;

#if defined(_WIN32_WCE) 
        case WM_DESTROY:
#else /* defined(_WIN32_WCE) */
        case WM_NCDESTROY:
#endif /* defined(_WIN32_WCE) */
            if ((window = (cWinWindow*)GetWindowLong(handle, GWL_USERDATA)))
            {
                result = window->OnWindowProc(message, wparam, lparam);
                error = window->DestroyInstance();
                return result;
            }
            result = DefWindowProc(handle, message, wparam, lparam);
            return result;

        default:
            window = (cWinWindow*)GetWindowLong(handle, GWL_USERDATA);
        }

        if (window)
            return window->OnWindowProc(message, wparam, lparam);

        return DefWindowProc(handle, message, wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnWindowProc
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWindowProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        switch(message)
        {
#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        case WM_NCCREATE:
            return OnWMNCCreate(wparam, lparam);
#endif /* defined(_WIN32_WCE) */

        case WM_CREATE:
            return OnWMCreate(wparam, lparam);

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        case WM_NCDESTROY:
            return OnWMNCDestroy(wparam, lparam);
#endif /* defined(_WIN32_WCE) */

        case WM_DESTROY:
            return OnWMDestroy(wparam, lparam);

        case WM_ERASEBKGND:
            return OnWMEraseBackground(wparam, lparam);

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        case WM_NCPAINT:
            return OnWMNCPaint(wparam, lparam);
#endif /* defined(_WIN32_WCE) */

        case WM_PAINT:
            return OnWMPaint(wparam, lparam);

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        case WM_NCCALCSIZE:
            return OnWMNCCalcSize(wparam, lparam);
#endif /* defined(_WIN32_WCE) */

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        case WM_DROPFILES:
            return OnWMDropFiles(wparam, lparam);
#endif /* defined(_WIN32_WCE) */

        case WM_NOTIFY:
            return OnWMNotify(wparam, lparam);

        case WM_COMMAND:
            return OnWMCommand(wparam, lparam);

        case WM_CLOSE:
            return OnWMClose(wparam, lparam);

        case WM_SIZE:
            return OnWMSize(wparam, lparam);

        case WM_LBUTTONDOWN:
            return OnWMLButtonDown(wparam, lparam);

        case WM_LBUTTONUP:
            return OnWMLButtonUp(wparam, lparam);

        case WM_RBUTTONDOWN:
            return OnWMRButtonDown(wparam, lparam);

        case WM_RBUTTONUP:
            return OnWMRButtonUp(wparam, lparam);

        case WM_MBUTTONDOWN:
            return OnWMMButtonDown(wparam, lparam);

        case WM_MBUTTONUP:
            return OnWMMButtonUp(wparam, lparam);

        case WM_MOUSEMOVE:
            return OnWMMouseMove(wparam, lparam);

        case WM_DRAWITEM:
            return OnWMDrawItem(wparam, lparam);
        }

        return OnDefWindowProc(message, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnDefWindowProc
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnDefWindowProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        return DefWindowProc
        (m_handle, message, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMNCCreate
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual LRESULT OnWMNCCreate(WPARAM wparam, LPARAM lparam)
    {
#if defined(_WIN32_WCE)
        return 0;
#else /* defined(_WIN32_WCE) */
        return OnDefWindowProc
        (WM_NCCREATE, wparam, lparam);
#endif /* defined(_WIN32_WCE) */
    }
    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_CREATE, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMNCDestroy
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual LRESULT OnWMNCDestroy(WPARAM wparam, LPARAM lparam)
    {
#if defined(_WIN32_WCE) 
        return 0;
#else /* defined(_WIN32_WCE) */
        return OnDefWindowProc
        (WM_NCDESTROY, wparam, lparam);
#endif /* defined(_WIN32_WCE) */
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_DESTROY, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMEraseBackground
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual LRESULT OnWMEraseBackground(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_ERASEBKGND, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: DoOnWMEraseBackground
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual LRESULT DoOnWMEraseBackground
    (WPARAM wparam, LPARAM lparam)
    {
        BOOL painted = FALSE;
        HDC hdc;
        eError error;
        cWinRect rect;

        if (!(error = rect.GetClient(m_handle)))
        if ((hdc = (HDC)wparam))
            painted = OnEraseBackground(hdc, rect);

        if (painted)
            return 1;

        return OnDefWindowProc
        (WM_ERASEBKGND, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnEraseBackground
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnEraseBackground(HDC hdc, RECT& rect)
    {
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: OnWMNCPaint
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual LRESULT OnWMNCPaint(WPARAM wparam, LPARAM lparam)
    {
#if defined(_WIN32_WCE) 
        return 0;
#else /* defined(_WIN32_WCE) */
        return OnDefWindowProc
        (WM_NCPAINT, wparam, lparam);
#endif /* defined(_WIN32_WCE) */
    }
    /**
     **********************************************************************
     * Function: DoOnWMNCPaint
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual LRESULT DoOnWMNCPaint
    (WPARAM wparam, LPARAM lparam, BOOL erase=FALSE)
    {
#if defined(_WIN32_WCE) 
        return 0;
#else /* defined(_WIN32_WCE) */
        BOOL painted = FALSE;
        HDC hdc;
        eError error;
        cWinRect rect;

        if (!(error = rect.GetUpdate(m_handle, erase)))
        if ((hdc = GetWindowDC(m_handle)))
        {
            painted = OnNCPaint(hdc, rect);
            ReleaseDC(m_handle, hdc);
        }

        if (painted)
            return 0;

        return OnDefWindowProc
        (WM_NCPAINT, wparam, lparam);
#endif /* defined(_WIN32_WCE) */
    }
    /**
     **********************************************************************
     * Function: OnNCPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnNCPaint(HDC hdc, RECT& rect)
    {
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: OnWMPaint
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual LRESULT OnWMPaint(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_PAINT, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: DoOnWMPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual LRESULT DoOnWMPaint
    (WPARAM wparam, LPARAM lparam, BOOL erase=FALSE)
    {
        BOOL painted = FALSE;
        HDC hdc;
        PAINTSTRUCT ps;
        eError error;
        cWinRect rect;

        if (!(error = rect.GetUpdate(m_handle, erase)))
        if ((hdc = BeginPaint(m_handle, &ps)))
        {
            painted = OnPaint(hdc, rect);
            EndPaint(m_handle, &ps);
        }

        if (painted)
            return 0;

        return OnDefWindowProc
        (WM_PAINT, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnPaint(HDC hdc, RECT& rect)
    {
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: OnWMNCCalcSize
     *
     *   Author: $author$
     *     Date: 5/5/2004
     **********************************************************************
     */
    virtual LRESULT OnWMNCCalcSize(WPARAM wparam, LPARAM lparam)
    {
#if defined(_WIN32_WCE) 
        return 0;
#else /* defined(_WIN32_WCE) */
        return OnDefWindowProc
        (WM_NCCALCSIZE, wparam, lparam);
#endif /* defined(_WIN32_WCE) */
    }
    /**
     **********************************************************************
     * Function: OnWMDropFiles
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDropFiles(WPARAM wparam, LPARAM lparam)
    {
#if defined(_WIN32_WCE) 
        return 0;
#else /* defined(_WIN32_WCE) */
        return OnDefWindowProc
        (WM_DROPFILES, wparam, lparam);
#endif /* defined(_WIN32_WCE) */
    }
    /**
     **********************************************************************
     * Function: OnWMNotify
     *
     *   Author: $author$
     *     Date: 5/25/2004
     **********************************************************************
     */
    virtual LRESULT OnWMNotify(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_NOTIFY, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMCommand
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCommand(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_COMMAND, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMSize
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual LRESULT OnWMSize(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_SIZE, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMClose
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMClose(WPARAM wparam, LPARAM lparam)
    {
        PostQuitMessage(0);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnWMRButtonDown
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMRButtonDown(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_RBUTTONDOWN, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMRButtonUp
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMRButtonUp(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_RBUTTONUP, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMLButtonDown
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMLButtonDown(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_LBUTTONDOWN, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMLButtonUp
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMLButtonUp(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_LBUTTONUP, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMMButtonDown
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMMButtonDown(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_MBUTTONDOWN, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMMButtonUp
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMMButtonUp(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_MBUTTONUP, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMMouseMove
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual LRESULT OnWMMouseMove(WPARAM wparam, LPARAM lparam)
    {
        return OnDefWindowProc
        (WM_MOUSEMOVE, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDrawItem
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual LRESULT OnWMDrawItem(WPARAM wparam, LPARAM lparam)
    {
        BOOL drawn = FALSE;
        LPDRAWITEMSTRUCT lpdis;

        if ((lpdis = (LPDRAWITEMSTRUCT)lparam))
            drawn = OnDrawItem(*lpdis, wparam);

        if (drawn)
            return drawn;

        return OnDefWindowProc
        (WM_DRAWITEM, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnDrawItem
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnDrawItem
    (DRAWITEMSTRUCT& dis, WPARAM wparam)
    {
        return FALSE;
    }
};

#endif /* ndef _CWINWINDOW_HXX */

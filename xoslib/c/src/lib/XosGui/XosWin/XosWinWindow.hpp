///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosWinWindow.hpp
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINWINDOW_HPP) || defined(XOSWINWINDOW_MEMBERS_ONLY)
#if !defined(_XOSWINWINDOW_HPP) && !defined(XOSWINWINDOW_MEMBERS_ONLY)
#define _XOSWINWINDOW_HPP
#endif // !defined(_XOSWINWINDOW_HPP) && !defined(XOSWINWINDOW_MEMBERS_ONLY) 

#if !defined(XOSWINWINDOW_MEMBERS_ONLY)
#include "XosWinHWNDAttached.hpp"

#define XOSWIN_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define XOSWIN_DEFAULT_WINDOW_EXSTYLE 0

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWindowImplement
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinHWNDCreatedAttachedImplement
XosWinWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWindowExtend
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinHWNDCreatedAttached
XosWinWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinWindow
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosWinWindow
: virtual public XosWinWindowImplement,
  public XosWinWindowExtend
{
public:
    typedef XosWinWindowImplement Implements;
    typedef XosWinWindowExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Class: OnWindowMessageDefaultObserver
    ///
    /// Author: $author$
    ///   Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    class c_EXPORT_CLASS OnWindowMessageDefaultObserver
    {
    public:
        ///////////////////////////////////////////////////////////////////////
        /// Function: OnWindowMessageDefaultObserve
        ///
        ///   Author: $author$
        ///     Date: 1/30/2011
        ///////////////////////////////////////////////////////////////////////
        virtual LRESULT OnWindowMessageDefaultObserve
        (HWND hWnd,
         UINT msg,
         WPARAM wParam,
         LPARAM lParam)
        {
            LRESULT lResult = 0;
            return lResult;
        }
    };

    HINSTANCE m_hInstance;
    OnWindowMessageDefaultObserver* m_onWindowMessageDefaultObserver;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinWindow
    ///
    ///       Author: $author$
    ///         Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinWindow
    (OnWindowMessageDefaultObserver* onWindowMessageDefaultObserver,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(attached, isCreated),
      m_hInstance(hInstance),
      m_onWindowMessageDefaultObserver(onWindowMessageDefaultObserver)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinWindow
    ///
    ///       Author: $author$
    ///         Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinWindow
    (HINSTANCE hInstance,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(attached, isCreated),
      m_hInstance(hInstance),
      m_onWindowMessageDefaultObserver(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinWindow
    ///
    ///       Author: $author$
    ///         Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinWindow
    (HWND attached=NULL,
     bool isCreated=false)
	: Extends(attached, isCreated),
      m_hInstance(NULL),
      m_onWindowMessageDefaultObserver(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinWindow
    ///
    ///      Author: $author$
    ///        Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (HINSTANCE hInstance, LPCTSTR className, 
     LPCTSTR windowName=NULL, HWND hParentWnd=NULL_HANDLE, 
     HMENU hMenu=NULL_HANDLE, DWORD style=XOSWIN_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=XOSWIN_DEFAULT_WINDOW_EXSTYLE, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT,
     LPVOID lParam=NULL, 
     bool isCreated=true, bool onlyDestroyed=false)
    {
        XosError error = Create
        (exStyle, className, windowName, style, 
         x,y, width,height, hParentWnd, hMenu, hInstance, lParam, 
         isCreated, onlyDestroyed);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///
    /// Windows API style create
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (DWORD exStyle, LPCTSTR className, 
     LPCTSTR windowName, DWORD style, 
     int x, int y, int width, int height, 
     HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam,
     bool isCreated=true, bool onlyDestroyed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        HWND detached;

        if (!(error = Destroyed(onlyDestroyed)))
        if ((detached = CreateDetached
            (error, exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, 
             (lParam)?(lParam):((XosWinWindow*)(this)))))
        {
            Attach(detached, isCreated);
            m_hInstance = hInstance;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy
    (bool onlyCreated=false)
    {
        XosError error = XOS_ERROR_FAILED;
        HWND detached;
        
        if ((detached = Detach()))
            error = DestroyDetached(detached);
        else
        if (!(onlyCreated))
            error = XOS_ERROR_NONE;
            
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: CreateDetached
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HWND CreateDetached
    (XosError& error,
     DWORD exStyle, LPCTSTR className, 
     LPCTSTR windowName, DWORD style, 
     int x, int y, int width, int height, 
     HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) const
    {
        HWND detached = NULL;
        error = XOS_ERROR_FAILED;

        if ((detached = CreateWindowEx
            (exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, lParam)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed on CreateWindowEx()\n")); }

        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DestroyDetached
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError DestroyDetached
    (HWND detached) const
    {
        XosError error = XOS_ERROR_FAILED;

        if (DestroyWindow(detached))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed on DestroyWindow()\n")); }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Move
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Move
    (int x,int y, 
     int width,int height, 
     BOOL repaint = FALSE) 
    {
        XosError error = XOS_ERROR_FAILED;
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((MoveWindow(hWnd, x,y, width,height, repaint)))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: MoveTo
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError MoveTo
    (int x,int y, 
     BOOL repaint = FALSE) 
    {
        XosError error = XOS_ERROR_FAILED;
        HWND hWnd;
        RECT r;
        if ((hWnd = Attached()))
        if ((GetWindowRect(hWnd, &r)))
        if ((MoveWindow
            (hWnd, x,y, (r.right-r.left),
             (r.bottom-r.top), repaint)))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SizeTo
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SizeTo
    (int width,int height, 
     BOOL repaint = FALSE) 
    {
        XosError error = XOS_ERROR_FAILED;
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
                return XOS_ERROR_FAILED;
                
            if ((MoveWindow
                (hWnd, p.x,p.y, 
                 width,height, repaint)))
                error = XOS_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Show
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Show
    (INT cmdShow=SW_SHOWNORMAL)
    {
        XosError error = XOS_ERROR_FAILED;
        HWND hWnd;
        if ((hWnd = Attached()))
        {
            ShowWindow(hWnd, cmdShow);
            error = XOS_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Hide
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Hide
    (INT cmdShow=SW_HIDE)
    {
        XosError error = Show();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetText
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetText(const CHAR* chars)
    {
        XosError error = XOS_ERROR_FAILED;
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((SetWindowTextA(hWnd, chars)))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetText
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetText(const WCHAR* chars)
    {
        XosError error = XOS_ERROR_FAILED;
        HWND hWnd;
        if ((hWnd = Attached()))
        if ((SetWindowTextW(hWnd, chars)))
            error = XOS_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetRgn
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HRGN SetRgn
    (HRGN hToRgn,
     BOOL bRedraw=FALSE)
    {
        XosError error = XOS_ERROR_FAILED;
        HRGN hRgn = SetRgn(error, hToRgn, bRedraw);
        return hRgn;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetRgn
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HRGN GetRgn
    (HRGN hCopyToRgn) const
    {
        XosError error = XOS_ERROR_FAILED;
        HRGN hRgn = GetRgn(error, hCopyToRgn);
        return hRgn;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetRgn
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HRGN SetRgn
    (XosError& error,
     HRGN hToRgn,
     BOOL bRedraw=FALSE)
    {
        HRGN hRgn = NULL;
        if ((hToRgn))
        {
            HWND hWnd;
            if ((hWnd = Attached()))
            if ((SetWindowRgn(hWnd, hToRgn, bRedraw)))
            {
                hRgn = hToRgn;
                error = XOS_ERROR_NONE;
            }
        }
        return hRgn;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetRgn
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HRGN GetRgn
    (XosError& error,
     HRGN hCopyToRgn) const
    {
        HRGN hRgn = NULL;
        if ((hCopyToRgn))
        {
            HWND hWnd;
            if ((hWnd = Attached()))
            if ((GetWindowRgn(hWnd, hCopyToRgn)))
            {
                hRgn = hCopyToRgn;
                error = XOS_ERROR_NONE;
            }
        }
        return hRgn;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetRect
    (RECT& rect) const
    {
        XosError error = GetWindowRect(rect);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetClientRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetClientRect
    (RECT& rect) const
    {
        XosError error = XOS_ERROR_FAILED;
        HWND attached;
        if ((attached = Attached()))
        if ((::GetClientRect(attached, &rect)))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetWindowRect
    (RECT& rect) const
    {
        XosError error = XOS_ERROR_FAILED;
        HWND attached;
        if ((attached = Attached()))
        if ((::GetWindowRect(attached, &rect)))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetClientWindowRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetClientWindowRect
    (RECT& rect) const
    {
        XosError error = XOS_ERROR_FAILED;
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
                error = XOS_ERROR_NONE;
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetClientBorderRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetClientBorderRect
    (RECT& rect) const
    {
        XosError error = XOS_ERROR_FAILED;
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
                    error = XOS_ERROR_NONE;
                }
            }
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetClientRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static inline BOOL GetClientRect
    (HWND hWnd, LPRECT rect)
    { return ::GetClientRect(hWnd, rect); }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowRect
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static inline BOOL GetWindowRect
    (HWND hWnd, LPRECT rect)
    { return ::GetWindowRect(hWnd, rect); }

    ///////////////////////////////////////////////////////////////////////
    /// Function: RegisterOnWindowMessageDefaultObserver
    ///
    ///   Author: $author$
    ///     Date: 2/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void RegisterOnWindowMessageDefaultObserver
    (OnWindowMessageDefaultObserver* onWindowMessageDefaultObserver)
    { m_onWindowMessageDefaultObserver = onWindowMessageDefaultObserver; }
    ///////////////////////////////////////////////////////////////////////
    /// Function: UnregisterOnWindowMessageDefaultObserver
    ///
    ///   Author: $author$
    ///     Date: 2/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void UnregisterOnWindowMessageDefaultObserver()
    { m_onWindowMessageDefaultObserver = 0; }
#else // !defined(XOSWINWINDOW_MEMBERS_ONLY) 
#endif // !defined(XOSWINWINDOW_MEMBERS_ONLY) 

#if !defined(XOSWINWINDOW_MEMBERS_ONLY)
#include "XosOnWindowMessageMembers.hpp"
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnWindowMessage
    ///
    ///   Author: $author$
    ///     Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        switch(msg)
        {
#include "XosOnWindowMessageCases.hpp"
		default:
            lResult = OnWindowMessageDefault(hWnd, msg, wParam, lParam);
            break;
        }
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: WindowProc
    ///
    ///    Author: $author$
    ///      Date: 12/9/2011
    ///////////////////////////////////////////////////////////////////////
    static LRESULT CALLBACK WindowProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
		XosWinWindow* window;

		if (!(window = (XosWinWindow*)(GetWindowLongPtr(hWnd, GWL_USERDATA))))
		if ((WM_NCCREATE == (msg)))
		{
			CREATESTRUCT* cs;
			if ((cs = (CREATESTRUCT*)(lParam)))
			if ((window = (XosWinWindow*)(cs->lpCreateParams)))
            {
                if (!(window->Attached())) window->Attach(hWnd);
				SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)(window));
            }
		}

		if ((window))
			lResult = window->OnWindowMessage(hWnd, msg, wParam, lParam);
		else
		lResult = DefWindowProc(hWnd, msg, wParam, lParam);
        return lResult;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINWINDOW_MEMBERS_ONLY) 
#endif // !defined(XOSWINWINDOW_MEMBERS_ONLY) 

#endif // !defined(_XOSWINWINDOW_HPP) || defined(XOSWINWINDOW_MEMBERS_ONLY) 

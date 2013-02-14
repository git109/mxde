///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
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
///   File: XosWinChildWindow.hpp
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINCHILDWINDOW_HPP
#define _XOSWINCHILDWINDOW_HPP

#include "XosWinWindow.hpp"
#include "XosWinWindowClass.hpp"
#include "XosString.hpp"

#define XOSWINCHILDWINDOW_DEFAULT_WINDOW_CLASSNAME "XosWinChildWindow"

#define XOSWINCHILDWINDOW_DEFAULT_WINDOW_EXSTYLE 0

#define XOSWINCHILDWINDOW_DEFAULT_WINDOW_STYLE \
    WS_CHILD | WS_VISIBLE

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosWinChildWindowClass
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinChildWindowClass
: public XosWinWindowClass
{
public:
    typedef XosWinWindowClass Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinChildWindowClass
    ///
    ///       Author: $author$
    ///         Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinChildWindowClass
    (LPCTSTR windowClassNameChars=_T(XOSWINCHILDWINDOW_DEFAULT_WINDOW_CLASSNAME),
     WNDPROC wndProc=XosWinWindow::WindowProc,
     int windowExtra=(int)(sizeof(XosWinInterfaceBase*)),
     int windowExtraOffset=0,
     int classExtra=0,
     int classExtraOffset=0,
     UINT style=0,
     ATOM attached=NULL,
     bool isRegistered=false)
    : Extends
       (windowClassNameChars, wndProc, 
        windowExtra, windowExtraOffset, 
        classExtra, classExtraOffset,
        style, attached, isRegistered)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinChildWindowClass
    ///
    ///      Author: $author$
    ///        Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinChildWindowClass()
    {
        XosError error;
        if ((m_isRegistered))
        if ((error = Unregister()))
            throw(error);
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinChildWindowImplement
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowImplement
XosWinChildWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinChildWindowExtend
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindow
XosWinChildWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinChildWindow
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinChildWindow
: virtual public XosWinChildWindowImplement,
  public XosWinChildWindowExtend
{
public:
    typedef XosWinChildWindowImplement Implements;
    typedef XosWinChildWindowExtend Extends;

    static XosWinChildWindowClass m_windowClass;
    XosTString m_windowClassName;
    DWORD m_style;
    DWORD m_exStyle;
    
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinChildWindow
    ///
    ///       Author: $author$
    ///         Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinChildWindow
    (HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(hInstance, attached, isCreated),
      m_windowClassName(XOSWINCHILDWINDOW_DEFAULT_WINDOW_CLASSNAME),
      m_style(XOSWINCHILDWINDOW_DEFAULT_WINDOW_STYLE),
      m_exStyle(XOSWINCHILDWINDOW_DEFAULT_WINDOW_EXSTYLE)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinChildWindow
    ///
    ///      Author: $author$
    ///        Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinChildWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName = 0, 
     LPVOID lParam = 0, bool isCreated = false, bool onlyDestroyed = false)
    {
        XosError error = XOS_ERROR_FAILED;
        DWORD style = m_style;
        DWORD exStyle = m_exStyle;
        LPCTSTR className;

        if ((className = m_windowClassName.c_str()))
            error = Create
            (hInstance, hParentWnd, id, x,y, width,height,
             windowName, style, exStyle, className, lParam,
             isCreated, onlyDestroyed);
             
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName, 
     DWORD style, DWORD exStyle, LPCTSTR className, 
     LPVOID lParam = 0, bool isCreated = false, bool onlyDestroyed = false)
    {
        XosError error = XOS_ERROR_FAILED;
        HMENU hMenu = (HMENU)(id);

        error = Extends::Create
        (hInstance, className, windowName, 
         hParentWnd, hMenu, style, exStyle, 
         x, y, width, height, lParam, 
         isCreated, onlyDestroyed);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: RegisterWindowClass
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static XosError RegisterWindowClass
    (HINSTANCE hInstance)
    {
        XosError error = m_windowClass.Register(hInstance);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: UnregisterWindowClass
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static XosError UnregisterWindowClass()
    {
        XosError error = m_windowClass.Unregister();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD SetStyle
    (DWORD toStyle)
    {
        m_style = toStyle;
        return m_style;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AddStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD AddStyle
    (DWORD toStyle)
    {
        m_style |= toStyle;
        return m_style;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: RemoveStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD RemoveStyle
    (DWORD toStyle)
    {
        m_style &= ~toStyle;
        return m_style;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD GetStyle() const
    {
        return m_style;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetExStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD SetExStyle
    (DWORD toExStyle)
    {
        m_exStyle = toExStyle;
        return m_exStyle;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AddExStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD AddExStyle
    (DWORD toExStyle)
    {
        m_exStyle |= toExStyle;
        return m_exStyle;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: RemoveExStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD RemoveExStyle
    (DWORD toExStyle)
    {
        m_exStyle &= ~toExStyle;
        return m_exStyle;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetExStyle
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD GetExStyle() const
    {
        return m_exStyle;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINCHILDWINDOW_HPP 

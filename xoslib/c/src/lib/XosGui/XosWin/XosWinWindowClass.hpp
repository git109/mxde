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
///   File: XosWinWindowClass.hpp
///
/// Author: $author$
///   Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINWINDOWCLASS_HPP
#define _XOSWINWINDOWCLASS_HPP

#include "XosWinATOMAttached.hpp"
#include "XosWinWindow.hpp"
#include "XosString.hpp"
#include "XosDebug.hpp"

#define XOSWINWINDOWCLASS_CLASSNAME_CHARS "XosWinWindowClass"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWindowClassImplement
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinATOMAttachedImplement
XosWinWindowClassImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWindowClassExtend
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinATOMAttached
XosWinWindowClassExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinWindowClass
///
/// Author: $author$
///   Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinWindowClass
: virtual public XosWinWindowClassImplement,
  public XosWinWindowClassExtend
{
public:
    typedef XosWinWindowClassImplement Implements;
    typedef XosWinWindowClassExtend Extends;

    LPCTSTR m_windowClassNameChars;
    WNDPROC m_wndProc;
    HBRUSH m_hBackgroundBrush;
    int m_windowExtra;
    int m_windowExtraOffset;
    int m_classExtra;
    int m_classExtraOffset;
    UINT m_style;

    bool m_isRegistered;
    XosTString m_windowClassName;
    WNDCLASSEX m_wndClass;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinWindowClass
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinWindowClass
    (LPCTSTR windowClassNameChars=_T(XOSWINWINDOWCLASS_CLASSNAME_CHARS),
     WNDPROC wndProc=XosWinWindow::WindowProc,
     int windowExtra=(int)(sizeof(XosWinInterfaceBase*)),
     int windowExtraOffset=0,
     int classExtra=0,
     int classExtraOffset=0,
     UINT style=0,
     ATOM attached=NULL,
     bool isRegistered=false)
    : Extends(attached),
      m_windowClassNameChars(windowClassNameChars),
      m_wndProc(wndProc),
      m_hBackgroundBrush(NULL),
      m_windowExtra(windowExtra),
      m_windowExtraOffset(windowExtraOffset),
      m_classExtra(classExtra),
      m_classExtraOffset(classExtraOffset),
      m_style(style),
      m_isRegistered(isRegistered)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinWindowClass
    ///
    ///      Author: $author$
    ///        Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinWindowClass()
    {
        XosError error;
        if ((m_isRegistered))
        if ((error = Unregister()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Register
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Register
    (HINSTANCE instance, LPCTSTR classname=NULL, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=-1, int clsextra=-1)
    {
        XosError error = XOS_ERROR_FAILED;
        ATOM detached;

        if ((IsRegistered()))
        if ((error = Unregister()))
            return error;

        if (classname)
            SetWindowClassName(classname);
        else
        if (!(classname = GetWindowClassName()))
            return error;

        if (!wndproc)
        if (!(wndproc = GetWindowProc()))
            return error;

        if (!background)
            background = GetBackground();

        if (0 > wndextra)
            wndextra = GetWindowExtra();

        if (0 > clsextra)
            clsextra = GetClassExtra();

        if (!style)
            style = GetStyle();

        if ((detached = RegisterDetached
            (error, m_wndClass, instance, classname, wndproc, menuname, icon, 
             iconsm, cursor, background, style, wndextra, clsextra)))
        {
            Attach(detached);
            SetIsRegistered();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Unregister
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Unregister()
    {
        XosError error = XOS_ERROR_NONE;
        ATOM detached;

        SetIsRegistered(false);

        if ((detached = Detach()))
            error = UnregisterDetached(detached, m_wndClass);

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: RegisterDetached
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ATOM RegisterDetached
    (XosError& error, WNDCLASSEX& wndClass, 
     HINSTANCE instance, LPCTSTR classname, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0, bool isInitial=false)
    {
        ATOM detached = NULL;

        memset(&wndClass, 0, sizeof(WNDCLASSEX));
        wndClass.cbSize = sizeof(WNDCLASSEX);
        wndClass.hInstance = instance;
        wndClass.lpszClassName = classname;
        wndClass.style = style;
        wndClass.cbClsExtra = clsextra;
        wndClass.cbWndExtra = wndextra;

        if ((NULL != menuname) || isInitial)
            wndClass.lpszMenuName = menuname;

        if ((NULL != icon) || isInitial)
            wndClass.hIcon = icon;

        if ((NULL != iconsm) || isInitial)
            wndClass.hIconSm = iconsm;

        if ((NULL != cursor) || isInitial)
            wndClass.hCursor = cursor;

        else if (NULL == wndClass.hCursor)
                wndClass.hCursor = GetDefaultCursor();

        if ((NULL != background) || isInitial)
            wndClass.hbrBackground = background;

        else if (NULL == wndClass.hbrBackground)
                wndClass.hbrBackground = GetDefaultBackground();

        if ((NULL != wndproc) || isInitial)
            wndClass.lpfnWndProc = wndproc;

        else if (NULL == wndClass.lpfnWndProc)
                wndClass.lpfnWndProc = GetDefaultWindowProc();

        if ((NULL != (detached = RegisterClassEx(&wndClass))))
            error = XOS_ERROR_NONE;
        else
        XOS_DBE(("() failed on RegisterClassEx()\n"));

        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: UnregisterDetached
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError UnregisterDetached
    (ATOM detached, const WNDCLASSEX& wndClass)
    {
        XosError error = XOS_ERROR_FAILED;
 
        if ((detached))
        if ((UnregisterClass
            (wndClass.lpszClassName, wndClass.hInstance)))
            error = XOS_ERROR_NONE;
        else
        XOS_DBE(("() failed on UnregisterClass()\n"));

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetInfo
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetInfo
    (HINSTANCE instance, LPCTSTR classname)
    {
        XosError error = XOS_ERROR_FAILED;

        m_wndClass.cbSize = sizeof(WNDCLASSEX);

        if (classname)
        if ((GetClassInfoEx(instance, classname, &m_wndClass)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed on GetClassInfoEx()\n")); }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetIsRegistered
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRegistered
    (bool is=true) 
    {
        int isRegistered = false;
        isRegistered = (m_isRegistered = is);
        return isRegistered;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsRegistered
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsRegistered() const 
    {
        bool isRegistered = false;
        isRegistered = m_isRegistered;
        return isRegistered;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowClassName
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetWindowClassName
    (LPCTSTR chars, TLENGTH length=-1) 
    {
        ssize_t count = 0;
        m_windowClassName.assign(chars, length);
        if (0 < (count = m_windowClassName.length()))
        if ((chars = m_windowClassName.c_str()))
            m_windowClassNameChars = chars;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowClassName
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LPCTSTR GetWindowClassName() const 
    {
        LPCTSTR chars = m_windowClassNameChars;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowProc
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual WNDPROC SetWindowProc
    (WNDPROC wndProc) 
    {
        m_wndProc = wndProc;
        return wndProc;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowProc
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual WNDPROC GetWindowProc() const 
    {
        WNDPROC wndProc = m_wndProc;
        return wndProc;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowExtra
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetWindowExtra
    (int bytes) 
    {
        int count = (m_windowExtra = bytes);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowExtra
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetWindowExtra() const 
    {
        int count = m_windowExtra;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowExtraOffset
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetWindowExtraOffset
    (int bytes) 
    {
        int count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowExtraOffset
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetWindowExtraOffset() const 
    {
        int count = m_windowExtraOffset;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetClassExtra
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetClassExtra
    (int bytes) 
    {
        int count = (m_classExtra = bytes);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetClassExtra
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetClassExtra() const 
    {
        int count = m_classExtra;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetClassExtraOffset
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetClassExtraOffset
    (int bytes) 
    {
        int count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetClassExtraOffset
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetClassExtraOffset() const 
    {
        int count = m_classExtraOffset;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetBackground
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HBRUSH SetBackground(HBRUSH hBrush) 
    {
        m_hBackgroundBrush = hBrush;
        return hBrush;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetBackground
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual HBRUSH GetBackground() const 
    {
        HBRUSH hBrush = NULL;
        hBrush = m_hBackgroundBrush;
        return hBrush;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetStyle
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual UINT SetStyle
    (UINT toStyle) 
    {
        UINT style = 0;
        style = (m_style = toStyle);
        return style;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetStyle
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual UINT GetStyle() const 
    {
        UINT style = 0;
        style = (m_style);
        return style;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDefaultCursor
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    HCURSOR GetDefaultCursor() const 
    {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDefaultBackground
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    HBRUSH GetDefaultBackground() const 
    {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDefaultWindowProc
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    WNDPROC GetDefaultWindowProc() const 
    {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINWINDOWCLASS_HPP 
        


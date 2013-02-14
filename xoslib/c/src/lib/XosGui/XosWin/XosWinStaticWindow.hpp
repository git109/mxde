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
///   File: XosWinStaticWindow.hpp
///
/// Author: $author$
///   Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINSTATICWINDOW_HPP
#define _XOSWINSTATICWINDOW_HPP

#include "XosWinTextChildWindow.hpp"
#include "XosWinStaticWindowSuperClass.hpp"

#define XOSWINSTATICWINDOW_DEFAULT_WINDOW_CLASSNAME \
    XOSWINSTATICWINDOWSUPERCLASS_CLASSNAME

#define XOSWINSTATICWINDOW_DEFAULT_WINDOW_STYLE \
    XOSWINCHILDWINDOW_DEFAULT_WINDOW_STYLE | SS_RIGHT

#define XOSWINSTATICWINDOW_DEFAULT_WINDOW_EXSTYLE \
    XOSWINCHILDWINDOW_DEFAULT_WINDOW_EXSTYLE

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinStaticWindowImplement
///
///  Author: $author$
///    Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinTextChildWindowImplement
XosWinStaticWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinStaticWindowExtend
///
///  Author: $author$
///    Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinTextChildWindow
XosWinStaticWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinStaticWindow
///
/// Author: $author$
///   Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinStaticWindow
: virtual public XosWinStaticWindowImplement,
  public XosWinStaticWindowExtend
{
public:
    typedef XosWinStaticWindowImplement Implements;
    typedef XosWinStaticWindowExtend Extends;

    static XosWinStaticWindowSuperClass m_windowClass;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinStaticWindow
    ///
    ///       Author: $author$
    ///         Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinStaticWindow
    (const WCHAR* chars,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(chars, hInstance, attached, isCreated)
    {
        m_windowClassName = (XOSWINSTATICWINDOW_DEFAULT_WINDOW_CLASSNAME);
        m_style = (XOSWINSTATICWINDOW_DEFAULT_WINDOW_STYLE);
        m_exStyle =(XOSWINSTATICWINDOW_DEFAULT_WINDOW_EXSTYLE);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinStaticWindow
    ///
    ///       Author: $author$
    ///         Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinStaticWindow
    (const char* chars=0,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(chars, hInstance, attached, isCreated)
    {
        m_windowClassName = (XOSWINSTATICWINDOW_DEFAULT_WINDOW_CLASSNAME);
        m_style = (XOSWINSTATICWINDOW_DEFAULT_WINDOW_STYLE);
        m_exStyle =(XOSWINSTATICWINDOW_DEFAULT_WINDOW_EXSTYLE);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinStaticWindow
    ///
    ///      Author: $author$
    ///        Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinStaticWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnDefWindowProc
    ///
    ///    Author: $author$
    ///      Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT OnDefWindowProc
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        LRESULT lResult = 0;
        WNDPROC windowSubclassProc = 0;
        DWORD wndClassExtra = 0;
        DWORD wndClassIndex = 0;

        if (sizeof(windowSubclassProc) <= (wndClassExtra = GetClassLong(hWnd, GCL_CBCLSEXTRA)))
        if (0 <= (wndClassIndex = wndClassExtra-sizeof(windowSubclassProc)))
            windowSubclassProc = (WNDPROC)(GetClassLongPtr(hWnd, wndClassIndex));
        
        if (windowSubclassProc)
            lResult = CallWindowProc
            (windowSubclassProc, hWnd, msg, wParam, lParam);
        else
        lResult = DefWindowProc(hWnd, msg, wParam, lParam);
        return lResult;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: RegisterWindowClass
    ///
    ///    Author: $author$
    ///      Date: 4/8/2012
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
    ///      Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    static XosError UnregisterWindowClass()
    {
        XosError error = m_windowClass.Unregister();
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
#endif // _XOSWINSTATICWINDOW_HPP 
        


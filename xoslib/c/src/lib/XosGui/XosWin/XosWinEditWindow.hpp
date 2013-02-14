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
///   File: XosWinEditWindow.hpp
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINEDITWINDOW_HPP
#define _XOSWINEDITWINDOW_HPP

#include "XosWinChildWindow.hpp"
#include "XosWinEditWindowSuperClass.hpp"

#define XOSWINEDITWINDOW_DEFAULT_WINDOW_CLASSNAME \
    XOSWINEDITWINDOWSUPERCLASS_CLASSNAME

#define XOSWINEDITWINDOW_DEFAULT_WINDOW_STYLE \
    XOSWINCHILDWINDOW_DEFAULT_WINDOW_STYLE | ES_AUTOHSCROLL

#define XOSWINEDITWINDOW_DEFAULT_WINDOW_EXSTYLE \
    XOSWINCHILDWINDOW_DEFAULT_WINDOW_EXSTYLE | WS_EX_CLIENTEDGE

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinEditWindowImplement
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinChildWindowImplement
XosWinEditWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinEditWindowExtend
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinChildWindow
XosWinEditWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinEditWindow
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinEditWindow
: virtual public XosWinEditWindowImplement,
  public XosWinEditWindowExtend
{
public:
    typedef XosWinEditWindowImplement Implements;
    typedef XosWinEditWindowExtend Extends;

    static XosWinEditWindowSuperClass m_windowClass;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinEditWindow
    ///
    ///       Author: $author$
    ///         Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinEditWindow
    (HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(hInstance, attached, isCreated)
    {
        m_windowClassName = (XOSWINEDITWINDOW_DEFAULT_WINDOW_CLASSNAME);
        m_style = (XOSWINEDITWINDOW_DEFAULT_WINDOW_STYLE);
        m_exStyle =(XOSWINEDITWINDOW_DEFAULT_WINDOW_EXSTYLE);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinEditWindow
    ///
    ///      Author: $author$
    ///        Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinEditWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnDefWindowProc
    ///
    ///    Author: $author$
    ///      Date: 4/4/2012
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
    ///      Date: 4/7/2012
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
    ///      Date: 4/7/2012
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

#endif // _XOSWINEDITWINDOW_HPP 
        


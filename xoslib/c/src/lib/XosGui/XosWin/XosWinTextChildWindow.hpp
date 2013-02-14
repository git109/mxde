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
///   File: XosWinTextChildWindow.hpp
///
/// Author: $author$
///   Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINTEXTCHILDWINDOW_HPP
#define _XOSWINTEXTCHILDWINDOW_HPP

#include "XosWinChildWindow.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinTextChildWindowImplement
///
///  Author: $author$
///    Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinChildWindowImplement
XosWinTextChildWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinTextChildWindowExtend
///
///  Author: $author$
///    Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinChildWindow
XosWinTextChildWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinTextChildWindow
///
/// Author: $author$
///   Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinTextChildWindow
: virtual public XosWinTextChildWindowImplement,
  public XosWinTextChildWindowExtend
{
public:
    typedef XosWinTextChildWindowImplement Implements;
    typedef XosWinTextChildWindowExtend Extends;

    XosTString m_text;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinTextChildWindow
    ///
    ///       Author: $author$
    ///         Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinTextChildWindow
    (const WCHAR* chars,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(hInstance, attached, isCreated)
    {
        if ((chars))
            m_text.assign(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinTextChildWindow
    ///
    ///       Author: $author$
    ///         Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinTextChildWindow
    (const char* chars=0,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
	: Extends(hInstance, attached, isCreated)
    {
        if ((chars))
            m_text.assign(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinTextChildWindow
    ///
    ///      Author: $author$
    ///        Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinTextChildWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_CREATE_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_CREATE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        LPCTSTR chars;
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        if ((m_text.length()) && (chars = m_text.c_str()))
            SetText(chars);
        return lResult;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINTEXTCHILDWINDOW_HPP 
        


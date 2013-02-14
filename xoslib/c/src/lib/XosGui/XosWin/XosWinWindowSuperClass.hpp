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
///   File: XosWinWindowSuperClass.hpp
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINWINDOWSUPERCLASS_HPP
#define _XOSWINWINDOWSUPERCLASS_HPP

#include "XosWinWindowClass.hpp"
#include "commctrl.h"

#define XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIXA "Xos"

#define XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIX \
    _T(XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIXA)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWindowSuperClassImplement
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowClassImplement
XosWinWindowSuperClassImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinWindowSuperClassExtend
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowClass
XosWinWindowSuperClassExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinWindowSuperClass
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinWindowSuperClass
: virtual public XosWinWindowSuperClassImplement,
  public XosWinWindowSuperClassExtend
{
public:
    typedef XosWinWindowSuperClassImplement Implements;
    typedef XosWinWindowSuperClassExtend Extends;

    WNDPROC m_windowSubclassProc;
    XosTString m_windowSubclassName;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinWindowSuperClass
    ///
    ///       Author: $author$
    ///         Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinWindowSuperClass
    (LPCTSTR windowSubclassNameChars=0,
     LPCTSTR windowClassNameChars=0,
     WNDPROC windowClassProc=WindowClassProc,
     WNDPROC windowSubclassProc=0) 
    : Extends(windowClassNameChars, windowClassProc),
      m_windowSubclassProc(windowSubclassProc),
      m_windowSubclassName(windowSubclassNameChars)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinWindowSuperClass
    ///
    ///      Author: $author$
    ///        Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinWindowSuperClass()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Register
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Register
    (HINSTANCE instance, HINSTANCE sublassInstance=NULL, 
     LPCTSTR sublassClassname=NULL, LPCTSTR classname=NULL, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=-1, int clsextra=-1,
     bool onlyUnregistered=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        int extra;
        ATOM detached;
        
        if (!sublassClassname)
        if (!(sublassClassname = GetWindowSubclassName()))
            return error;

        if ((error2 = GetInfo(sublassInstance, sublassClassname)))
             return error2;
             
        m_windowSubclassProc = m_wndClass.lpfnWndProc;
        
        if (!classname)
        if (!(classname = GetWindowClassName()))
            return error;

        if (!wndproc)
        if (!(wndproc = GetWindowProc()))
            return error;

        if (0 > wndextra)
            wndextra = GetWindowExtra();

        if (0 < (extra = m_wndClass.cbWndExtra))
            wndextra += extra;
            
        if (0 > clsextra)
            clsextra = GetClassExtra();

        if (0 < (extra = m_wndClass.cbClsExtra))
            clsextra += extra;
            
        clsextra += sizeof(m_windowSubclassProc);
        
        if ((m_wndClass.lpfnWndProc = (wndproc)))
        if ((m_wndClass.hInstance = (instance)))
        if ((m_wndClass.lpszClassName = (classname)))
        if (0 <= (extra = m_wndClass.cbWndExtra = (wndextra)))
        if (0 <= (extra = m_wndClass.cbClsExtra = (clsextra)))
        if ((detached = RegisterClassEx(&m_wndClass)))
        if ((SetWindowClassInstance(this)))
        {
            Attach(detached);
            SetIsRegistered();
            error = XOS_ERROR_NONE;
        }
        else
        UnregisterClass(classname, instance);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowClassInstance
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosWinWindowSuperClass* SetWindowClassInstance
    (XosWinWindowSuperClass* toWindowClass)
    {
        XosWinWindowSuperClass* windowClass = 0;
        return windowClass;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowClassInstance
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosWinWindowSuperClass* GetWindowClassInstance() const
    {
        XosWinWindowSuperClass* windowClass = 0;
        return windowClass;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowSubclassName
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LPCTSTR SetWindowSubclassName
    (LPCTSTR chars, ssize_t length=-1)
    {
        m_windowSubclassName.assign(chars, length);
        return m_windowSubclassName.c_str();
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowSubclassName
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LPCTSTR GetWindowSubclassName() const
    {
        return m_windowSubclassName.c_str();
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowSubclassProc
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual WNDPROC SetWindowSubclassProc
    (WNDPROC windowProc)
    {
        m_windowSubclassProc = windowProc;
        return m_windowSubclassProc;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowSubclassProc
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual WNDPROC GetWindowSubclassProc() const
    {
        return m_windowSubclassProc;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: WindowClassProc
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static LRESULT CALLBACK WindowClassProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        XosWinWindow* target = 0;
        WNDPROC windowSubclassProc = 0;
        DWORD wndExtra;
        DWORD wndIndex;
        DWORD wndClassExtra;
        DWORD wndClassIndex;
        
        if (sizeof(XosWinWindow*) <= (wndExtra = GetClassLong(hWnd, GCL_CBWNDEXTRA)))
        if (0 <= (wndIndex = wndExtra-sizeof(XosWinWindow*)))
        if ((target = (XosWinWindow*)(GetWindowLongPtr(hWnd, wndIndex))))
        {
            lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
            return lResult;
        }
        else
        if ((WM_NCCREATE == msg))
        {
            CREATESTRUCT* cs;
            if ((cs = (CREATESTRUCT*)(lParam)))
            if ((target = (XosWinWindow*)(cs->lpCreateParams)))
            if (sizeof(windowSubclassProc) <= (wndClassExtra = GetClassLong(hWnd, GCL_CBCLSEXTRA)))
            if (0 <= (wndClassIndex = wndClassExtra-sizeof(windowSubclassProc)))
            if ((windowSubclassProc = (WNDPROC)(GetClassLongPtr(hWnd, wndClassIndex))))
            {
                SetWindowLongPtr(hWnd, wndIndex, (LONG_PTR)(target));
                if (!(target->Attached())) target->Attach(hWnd);
                lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
                return lResult;
            }
        }
        
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
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINWINDOWSUPERCLASS_HPP 
        


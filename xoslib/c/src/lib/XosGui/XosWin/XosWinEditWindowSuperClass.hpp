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
///   File: XosWinEditWindowSuperClass.hpp
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINEDITWINDOWSUPERCLASS_HPP
#define _XOSWINEDITWINDOWSUPERCLASS_HPP

#include "XosWinWindowSuperClass.hpp"

#define XOSWINEDITWINDOWSUPERCLASS_SUBCLASSNAMEA WC_EDITA

#define XOSWINEDITWINDOWSUPERCLASS_CLASSNAMEA \
    XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIXA \
    XOSWINEDITWINDOWSUPERCLASS_SUBCLASSNAMEA

#define XOSWINEDITWINDOWSUPERCLASS_SUBCLASSNAME \
    _T(XOSWINEDITWINDOWSUPERCLASS_SUBCLASSNAMEA)

#define XOSWINEDITWINDOWSUPERCLASS_CLASSNAME \
    _T(XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIXA) \
    _T(XOSWINEDITWINDOWSUPERCLASS_SUBCLASSNAMEA)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinEditWindowSuperClassImplement
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowSuperClassImplement
XosWinEditWindowSuperClassImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinEditWindowSuperClassExtend
///
///  Author: $author$
///    Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowSuperClass
XosWinEditWindowSuperClassExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinEditWindowSuperClass
///
/// Author: $author$
///   Date: 4/6/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinEditWindowSuperClass
: virtual public XosWinEditWindowSuperClassImplement,
  public XosWinEditWindowSuperClassExtend
{
public:
    typedef XosWinEditWindowSuperClassImplement Implements;
    typedef XosWinEditWindowSuperClassExtend Extends;

    XosWinWindowSuperClass* m_oldWindowClassInstance;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinEditWindowSuperClass
    ///
    ///       Author: $author$
    ///         Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinEditWindowSuperClass
    (LPCTSTR windowSubclassNameChars=XOSWINEDITWINDOWSUPERCLASS_SUBCLASSNAME,
     LPCTSTR windowClassNameChars=XOSWINEDITWINDOWSUPERCLASS_CLASSNAME,
     WNDPROC windowClassProc=DerivedWindowClassProc) 
    : Extends(windowSubclassNameChars, windowClassNameChars, windowClassProc),
      m_oldWindowClassInstance(GetWindowClassInstance())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinEditWindowSuperClass
    ///
    ///      Author: $author$
    ///        Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinEditWindowSuperClass()
    {
        if (this == GetWindowClassInstance())
            SetWindowClassInstance(m_oldWindowClassInstance);
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
        XosWinWindowSuperClass* windowClass 
        = DerivedWindowClassInstance(true, toWindowClass);
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
        XosWinWindowSuperClass* windowClass 
        = DerivedWindowClassInstance();
        return windowClass;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: DerivedWindowClassInstance
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static XosWinWindowSuperClass* DerivedWindowClassInstance
    (bool isSetTo=false, XosWinWindowSuperClass* windowClass=0)
    {
        static XosWinWindowSuperClass* windowClassInstance = 0;
        if (isSetTo)
            windowClassInstance = windowClass;
        return windowClassInstance;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DerivedWindowClassProc
    ///
    ///    Author: $author$
    ///      Date: 4/6/2012
    ///////////////////////////////////////////////////////////////////////
    static LRESULT CALLBACK DerivedWindowClassProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        DWORD wndClassExtra;
        DWORD wndClassIndex;
        WNDPROC windowSubclassProc;
        XosWinWindowSuperClass* windowClassInstance;
        
        if ((windowClassInstance = DerivedWindowClassInstance()))
        if ((windowSubclassProc = windowClassInstance->GetWindowSubclassProc()))
        if (sizeof(windowSubclassProc) <= (wndClassExtra = GetClassLong(hWnd, GCL_CBCLSEXTRA)))
        if (0 <= (wndClassIndex = wndClassExtra-sizeof(windowSubclassProc)))
        if (0 <= (SetClassLongPtr(hWnd, wndClassIndex, (LONG_PTR)(windowSubclassProc))))
        if ((LONG_PTR)(windowSubclassProc) == (GetClassLongPtr(hWnd, wndClassIndex)))
        if (0 <= (SetClassLongPtr(hWnd, GCLP_WNDPROC, (LONG_PTR)(WindowClassProc))))
        if ((LONG_PTR)(WindowClassProc) == (GetClassLongPtr(hWnd, GCLP_WNDPROC)))
        {
            SetWindowLongPtr(hWnd, GWL_WNDPROC, (LONG_PTR)(WindowClassProc));
            lResult = WindowClassProc(hWnd, msg, wParam, lParam);
            return lResult;
        }
        lResult = DefWindowProc(hWnd, msg, wParam, lParam);
        return lResult;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINEDITWINDOWSUPERCLASS_HPP 

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
///   File: XosWinStaticWindowSuperClass.hpp
///
/// Author: $author$
///   Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINSTATICWINDOWSUPERCLASS_HPP
#define _XOSWINSTATICWINDOWSUPERCLASS_HPP

#include "XosWinWindowSuperClass.hpp"

#define XOSWINSTATICWINDOWSUPERCLASS_SUBCLASSNAMEA WC_STATICA

#define XOSWINSTATICWINDOWSUPERCLASS_CLASSNAMEA \
    XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIXA \
    XOSWINSTATICWINDOWSUPERCLASS_SUBCLASSNAMEA

#define XOSWINSTATICWINDOWSUPERCLASS_SUBCLASSNAME \
    _T(XOSWINSTATICWINDOWSUPERCLASS_SUBCLASSNAMEA)

#define XOSWINSTATICWINDOWSUPERCLASS_CLASSNAME \
    _T(XOSWINWINDOWSUPERCLASS_CLASSNAME_PREFIXA) \
    _T(XOSWINSTATICWINDOWSUPERCLASS_SUBCLASSNAMEA)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinStaticWindowSuperClassImplement
///
///  Author: $author$
///    Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowSuperClassImplement
XosWinStaticWindowSuperClassImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinStaticWindowSuperClassExtend
///
///  Author: $author$
///    Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowSuperClass
XosWinStaticWindowSuperClassExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinStaticWindowSuperClass
///
/// Author: $author$
///   Date: 4/8/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinStaticWindowSuperClass
: virtual public XosWinStaticWindowSuperClassImplement,
  public XosWinStaticWindowSuperClassExtend
{
public:
    typedef XosWinStaticWindowSuperClassImplement Implements;
    typedef XosWinStaticWindowSuperClassExtend Extends;

    XosWinWindowSuperClass* m_oldWindowClassInstance;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinStaticWindowSuperClass
    ///
    ///       Author: $author$
    ///         Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinStaticWindowSuperClass
    (LPCTSTR windowSubclassNameChars=XOSWINSTATICWINDOWSUPERCLASS_SUBCLASSNAME,
     LPCTSTR windowClassNameChars=XOSWINSTATICWINDOWSUPERCLASS_CLASSNAME,
     WNDPROC windowClassProc=DerivedWindowClassProc) 
    : Extends(windowSubclassNameChars, windowClassNameChars, windowClassProc),
      m_oldWindowClassInstance(GetWindowClassInstance())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinStaticWindowSuperClass
    ///
    ///      Author: $author$
    ///        Date: 4/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinStaticWindowSuperClass()
    {
        if (this == GetWindowClassInstance())
            SetWindowClassInstance(m_oldWindowClassInstance);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetWindowClassInstance
    ///
    ///    Author: $author$
    ///      Date: 4/8/2012
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
    ///      Date: 4/8/2012
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
    ///      Date: 4/8/2012
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
    ///      Date: 4/8/2012
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
#endif // _XOSWINSTATICWINDOWSUPERCLASS_HPP 
        


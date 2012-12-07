/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cwinwindowsuperclassextend.hxx
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
#if !defined(_CWINWINDOWSUPERCLASSEXTEND_HXX) || defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY)
#if !defined(_CWINWINDOWSUPERCLASSEXTEND_HXX) && !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY)
#define _CWINWINDOWSUPERCLASSEXTEND_HXX
#endif /* !defined(_CWINWINDOWSUPERCLASSEXTEND_HXX) && !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY) */

#if !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY)
#include "cwinwindowsuperclass.hxx"

#define CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX _T("c")

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cWinWindowSuperClassExtendT"
/**
 **********************************************************************
 *  Class: cWinWindowSuperClassExtendT
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
template
<class TDerives,
 class TWinWindowSuperClass=cWinWindowSuperClass,
 class TExtends=TWinWindowSuperClass>

class c_EXPORT_CLASS cWinWindowSuperClassExtendT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TWinWindowSuperClass tWinWindowSuperClass;
    
    tWinWindowSuperClass* m_oldWindowClassInstance;
    
    /**
     **********************************************************************
     *  Constructor: cWinWindowSuperClassExtendT
     *
     *       Author: $author$
     *         Date: 1/1/2010
     **********************************************************************
     */
    cWinWindowSuperClassExtendT
    (LPCTSTR windowSubclassNameChars=0,
     LPCTSTR windowClassNameChars=0,
     WNDPROC windowClassProc=DerivedWindowClassProc,
     WNDPROC windowSubclassProc=0) 
    : cExtends
      (windowSubclassNameChars, windowClassNameChars, 
       windowClassProc, windowSubclassProc),
      m_oldWindowClassInstance(WindowClassInstance())
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinWindowSuperClassExtendT
     *
     *      Author: $author$
     *        Date: 1/1/2010
     **********************************************************************
     */
    virtual ~cWinWindowSuperClassExtendT()
    {
    }
#else /* !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY) */

#if !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: SetWindowClassInstance
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    virtual tWinWindowSuperClass* SetWindowClassInstance
    (tWinWindowSuperClass* toWindowClass) const
    {
        tWinWindowSuperClass* windowClass
        = DerivedWindowClassInstance(true, toWindowClass);
        return windowClass;
    }
    /**
     **********************************************************************
     * Function: WindowClassInstance
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    virtual tWinWindowSuperClass* WindowClassInstance() const 
    {
        tWinWindowSuperClass* windowClass 
        = DerivedWindowClassInstance();
        return windowClass;
    }
    /**
     **********************************************************************
     * Function: DerivedWindowClassInstance
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    static tWinWindowSuperClass* DerivedWindowClassInstance
    (bool isSet=false, tWinWindowSuperClass* toWindowClass=0) 
    {
        static tWinWindowSuperClass* windowClassInstance = 0;
        if (isSet)
            windowClassInstance = toWindowClass;
        return windowClassInstance;
    }
    /**
     **********************************************************************
     * Function: SetWindowClassProc
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    static LRESULT SetWindowClassProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam,
     cWinWindowMessageTargetInterface* target=0) 
    {
        LRESULT lResult = 0;
        DWORD wndExtra;
        DWORD wndIndex;
        DWORD wndClassExtra;
        DWORD wndClassIndex;
        WNDPROC windowSubclassProc;
        tWinWindowSuperClass* windowClassInstance;
        
        if ((target))
        if (sizeof(cWinWindowMessageTargetInterface*) 
            <= (wndExtra = GetClassLong(hWnd, GCL_CBWNDEXTRA)))
        if (0 <= (wndIndex = wndExtra-sizeof(cWinWindowMessageTargetInterface*)))
            SetWindowLongPtr(hWnd, wndIndex, ((LONG_PTR)(target)));
        
        if ((windowClassInstance = DerivedWindowClassInstance()))
        if ((windowSubclassProc = windowClassInstance->WindowSubclassProc()))
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
    /**
     **********************************************************************
     * Function: DerivedWindowClassProc
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    static LRESULT CALLBACK DerivedWindowClassProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = SetWindowClassProc
        (hWnd, msg, wParam, lParam);
        return lResult;
    }
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY) */

#endif /* !defined(_CWINWINDOWSUPERCLASSEXTEND_HXX) || defined(CWINWINDOWSUPERCLASSEXTEND_MEMBERS_ONLY) */

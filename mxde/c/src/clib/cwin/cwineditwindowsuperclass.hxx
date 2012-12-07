/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwineditwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
#ifndef _CWINEDITWINDOWSUPERCLASS_HXX
#define _CWINEDITWINDOWSUPERCLASS_HXX

#include "cwinwindowsuperclass.hxx"

#define CWINEDITWINDOWSUPERCLASS_SUBCLASSNAME_CHARS "Edit"
#define CWINEDITWINDOWSUPERCLASS_CLASSNAME_CHARS "cEdit"

/**
 **********************************************************************
 *  Class: cWinEditWindowSuperClass
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinEditWindowSuperClass
: public cWinWindowSuperClass
{
public:
    typedef cWinWindowSuperClass cExtends;
    typedef cWinEditWindowSuperClass cDerives;
    
    cWinWindowSuperClass* m_oldWindowClassInstance;
    
    /**
     **********************************************************************
     * Constructor: cWinEditWindowSuperClass
     *
     *      Author: $author$
     *        Date: 10/26/2009
     **********************************************************************
     */
    cWinEditWindowSuperClass
    (LPCTSTR windowSubclassNameChars=_T(CWINEDITWINDOWSUPERCLASS_SUBCLASSNAME_CHARS),
     LPCTSTR windowClassNameChars=_T(CWINEDITWINDOWSUPERCLASS_CLASSNAME_CHARS),
     WNDPROC windowClassProc=DerivedWindowClassProc) 
    : cExtends(windowSubclassNameChars, windowClassNameChars, windowClassProc),
      m_oldWindowClassInstance(WindowClassInstance())
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinEditWindowSuperClass
     *
     *     Author: $author$
     *       Date: 10/26/2009
     **********************************************************************
     */
    virtual ~cWinEditWindowSuperClass()
    {
        if (this == WindowClassInstance())
            SetWindowClassInstance(m_oldWindowClassInstance);
    }
    
#if !defined(CWINEDITWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
#if !defined(CWINEDITWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: SetWindowClassInstance
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual cWinWindowSuperClass* SetWindowClassInstance
    (cWinWindowSuperClass* windowClass) const 
    {
        cWinWindowSuperClass* windowClassInstance 
        = DerivedWindowClassInstance(true, windowClass);
        return windowClassInstance;
    }
    /**
     **********************************************************************
     * Function: WindowClassInstance
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual cWinWindowSuperClass* WindowClassInstance() const 
    {
        cWinWindowSuperClass* windowClassInstance 
        = DerivedWindowClassInstance();
        return windowClassInstance;
    }
    /**
     **********************************************************************
     * Function: DerivedWindowClassInstance
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    static cWinWindowSuperClass* DerivedWindowClassInstance
    (bool isSetTo=false, cWinWindowSuperClass* windowClass=0)
    {
        static cWinWindowSuperClass* windowClassInstance = 0;
        if (isSetTo)
            windowClassInstance = windowClass;
        return windowClassInstance;
    }
    /**
     **********************************************************************
     * Function: DerivedWindowClassProc
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
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
        cWinWindowSuperClass* windowClassInstance;
        
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
#endif /* !defined(CWINEDITWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CWINEDITWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */

};
#endif /* _CWINEDITWINDOWSUPERCLASS_HXX */

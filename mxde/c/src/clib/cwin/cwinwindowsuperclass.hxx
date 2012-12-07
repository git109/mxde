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
 *   File: cwinwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 10/25/2009
 **********************************************************************
 */
#ifndef _CWINWINDOWSUPERCLASS_HXX
#define _CWINWINDOWSUPERCLASS_HXX

#include "cwinwindowclass.hxx"
#include "cwinwindowmessagetargetinterface.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowSuperClassInterface
 *
 * Author: $author$
 *   Date: 10/25/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinWindowSuperClassInterface
: virtual public cWinWindowClassInterface
{
public:
    typedef cWinWindowClassInterface cImplements;
    typedef cWinWindowSuperClassInterface cDerives;
};

/**
 **********************************************************************
 *  Class: cWinWindowSuperClassImplement
 *
 * Author: $author$
 *   Date: 10/25/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinWindowSuperClassImplement
: virtual public cWinWindowSuperClassInterface
{
public:
    typedef cWinWindowSuperClassInterface cImplements;
    typedef cWinWindowSuperClassImplement cDerives;
};

/**
 **********************************************************************
 *  Class: cWinWindowSuperClass
 *
 * Author: $author$
 *   Date: 10/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindowSuperClass
: virtual public cWinWindowSuperClassImplement,
  public cWinWindowClass
{
public:
    typedef cWinWindowSuperClassImplement cImplements;
    typedef cWinWindowClass cExtends;
    typedef cWinWindowSuperClass cDerives;
    
    WNDPROC m_windowSubclassProc;
    LPCTSTR m_windowSubclassNameChars;
    cTString m_windowSubclassName;

    /**
     **********************************************************************
     * Constructor: cWinWindowSuperClass
     *
     *      Author: $author$
     *        Date: 10/25/2009
     **********************************************************************
     */
    cWinWindowSuperClass
    (LPCTSTR windowSubclassNameChars=0,
     LPCTSTR windowClassNameChars=0,
     WNDPROC windowClassProc=WindowClassProc,
     WNDPROC windowSubclassProc=0) 
    : cExtends(windowClassNameChars, windowClassProc),
      m_windowSubclassProc(windowSubclassProc),
      m_windowSubclassNameChars(windowSubclassNameChars)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowSuperClass
     *
     *     Author: $author$
     *       Date: 10/25/2009
     **********************************************************************
     */
    virtual ~cWinWindowSuperClass()
    {
    }
    
    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 10/25/2009
     **********************************************************************
     */
    virtual eError Register
    (HINSTANCE instance, HINSTANCE sublassInstance=NULL, 
     LPCTSTR sublassClassname=NULL, LPCTSTR classname=NULL, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=-1, int clsextra=-1,
     bool onlyUnregistered=false) 
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        eError error2;
        int extra;
        ATOM detached, attached;
        
        if (!sublassClassname)
        if (!(sublassClassname = WindowSubclassName()))
            return error;

        if ((error2 = m_wndClass.GetInfo
             (sublassInstance, sublassClassname)))
             return error2;
             
        m_windowSubclassProc = m_wndClass.WindowProc();
        
        if (!classname)
        if (!(classname = WindowClassName()))
            return error;

        if (!wndproc)
        if (!(wndproc = WindowProc()))
            return error;

        if (0 > wndextra)
            wndextra = WindowExtra();

        if (0 < (extra = m_wndClass.WindowExtra()))
            wndextra += extra;
            
        if (0 > clsextra)
            clsextra = ClassExtra();

        if (0 < (extra = m_wndClass.ClassExtra()))
            clsextra += extra;
            
        clsextra += sizeof(m_windowSubclassProc);
        
        if ((m_wndClass.SetWindowProc(wndproc)))
        if ((m_wndClass.SetInstance(instance)))
        if ((m_wndClass.SetClassName(classname)))
        if (0 <= (extra = m_wndClass.SetWindowExtra(wndextra)))
        if (0 <= (extra = m_wndClass.SetClassExtra(clsextra)))
        if ((detached = m_wndClass.Register()))
        {
            if (detached == (attached = Attach(detached)))
            if (SetIsRegistered())
            if ((SetWindowClassInstance(this)))
                return error = e_ERROR_NONE;
            else
            SetIsRegistered(false);

            m_wndClass.Unregister();
        }
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowSubclassName
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual TLENGTH SetWindowSubclassName
    (LPCTSTR chars, TLENGTH length=-1) 
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = 0;
        if (0 <= (count = m_windowSubclassName.Assign(chars, length)))
        if ((chars = m_windowSubclassName.HasChars(length)))
            m_windowSubclassNameChars = chars;
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowSubclassName
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual LPCTSTR WindowSubclassName() const 
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
        LPCTSTR chars = m_windowSubclassNameChars;
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        LPCTSTR chars = 0;
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowSubclassProc
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual WNDPROC SetWindowSubclassProc
    (WNDPROC windowProc) 
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
        WNDPROC windowSubclassProc = (m_windowSubclassProc = windowProc);
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        WNDPROC windowSubclassProc = 0;
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return windowSubclassProc;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowSubclassProc
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual WNDPROC WindowSubclassProc() const 
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
        WNDPROC windowSubclassProc = (m_windowSubclassProc);
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        WNDPROC windowSubclassProc = 0;
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return windowSubclassProc;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
        cWinWindowSuperClass* windowClassInstance = 0;
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return windowClassInstance;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowClassInstance
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual cWinWindowSuperClass* WindowClassInstance() const 
#if defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
    {
        cWinWindowSuperClass* windowClassInstance = 0;
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return windowClassInstance;
    }
#endif /* defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE)
#if !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: WindowClassProc
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    static LRESULT CALLBACK WindowClassProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        cWinWindowMessageTargetInterface* target = 0;
        WNDPROC windowSubclassProc = 0;
        DWORD wndExtra;
        DWORD wndIndex;
        DWORD wndClassExtra;
        DWORD wndClassIndex;
        
        if (sizeof(cWinWindowMessageTargetInterface*) 
            <= (wndExtra = GetClassLong(hWnd, GCL_CBWNDEXTRA)))
        if (0 <= (wndIndex = wndExtra-sizeof(cWinWindowMessageTargetInterface*)))
        if ((target = (cWinWindowMessageTargetInterface*)
            (GetWindowLongPtr(hWnd, wndIndex))))
        {
            lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
            return lResult;
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
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWSUPERCLASS_MEMBER_FUNCS_INTERFACE) */
};
#endif /* _CWINWINDOWSUPERCLASS_HXX */

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
 *   File: cwinwndclass.hxx
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
#ifndef _CWINWNDCLASS_HXX
#define _CWINWNDCLASS_HXX

#include "cwinbase.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 * Typedef: cWinWNDCLASSExtends
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef TWNDCLASS
cWinWNDCLASSExtends;

/**
 **********************************************************************
 *  Class: cWinWNDCLASS
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWNDCLASS
: public cWinWNDCLASSExtends
{
public:
    typedef cWinWNDCLASSExtends cExtends;
    typedef cWinWNDCLASS cDerives;

    TWNDCLASS& m_wndClass;

    /**
     **********************************************************************
     * Constructor: cWinWNDCLASS
     *
     *      Author: $author$
     *        Date: 5/8/2009
     **********************************************************************
     */
    cWinWNDCLASS() 
    : m_wndClass((TWNDCLASS&)(*this))
    {
        memset(&m_wndClass, 0, sizeof(TWNDCLASS));
    }
    
    /**
     **********************************************************************
     * Function: GetInfo
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual eError GetInfo
    (HINSTANCE instance, LPCTSTR classname) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        
#if defined(WINDOWS_WCE) 
#else /* defined(WINDOWS_WCE) */
        m_wndClass.cbSize = sizeof(TWNDCLASS);
#endif /* defined(WINDOWS_WCE) */

        if (classname)
        if ((GetClassInfoEx(instance, classname, &m_wndClass)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on GetClassInfoEx()\n"));
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    void Set
    (HINSTANCE instance, LPCTSTR classname, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0, bool isInitial=false) 
    {
#if defined(WINDOWS_WCE) 
#else /* defined(WINDOWS_WCE) */
        m_wndClass.cbSize = sizeof(TWNDCLASS);
#endif /* defined(WINDOWS_WCE) */

        m_wndClass.hInstance = instance;
        m_wndClass.lpszClassName = classname;
        m_wndClass.style = style;
        m_wndClass.cbClsExtra = clsextra;
        m_wndClass.cbWndExtra = wndextra;

        if ((NULL != menuname) || isInitial)
            m_wndClass.lpszMenuName = menuname;

        if ((NULL != icon) || isInitial)
            m_wndClass.hIcon = icon;

#if defined(WINDOWS_WCE) 
#else /* defined(WINDOWS_WCE) */
        if ((NULL != iconsm) || isInitial)
            m_wndClass.hIconSm = iconsm;
#endif /* defined(WINDOWS_WCE) */

        if ((NULL != cursor) || isInitial)
            m_wndClass.hCursor = cursor;

        else if (NULL == m_wndClass.hCursor)
                m_wndClass.hCursor = GetDefaultCursor();

        if ((NULL != background) || isInitial)
            m_wndClass.hbrBackground = background;

        else if (NULL == m_wndClass.hbrBackground)
                m_wndClass.hbrBackground = GetDefaultBackground();

        if ((NULL != wndproc) || isInitial)
            m_wndClass.lpfnWndProc = wndproc;

        else if (NULL == m_wndClass.lpfnWndProc)
                m_wndClass.lpfnWndProc = GetDefaultWindowProc();
    }

    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    ATOM Register() const
    {
        ATOM atom = NULL;
#if defined(WINDOWS_WCE) 
        if (!(NULL != (atom = RegisterClass(&m_wndClass))))
#else /* defined(WINDOWS_WCE) */
        if (!(NULL != (atom = RegisterClassEx(&m_wndClass))))
#endif /* defined(WINDOWS_WCE) */
            DBE(("() failed on RegisterClass()\n"));
        return atom;
    }
    /**
     **********************************************************************
     * Function: Unregister
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    eError Unregister() const
    {
        eError error = e_ERROR_FAILED;
        if (UnregisterClass
            (m_wndClass.lpszClassName, m_wndClass.hInstance))
            return e_ERROR_NONE;
        else
        DBE(("() failed on UnregisterClass()\n"));
        return error;
    }

    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual INT SetSize
    (INT size=-1) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        INT count = -e_ERROR_INVALID_PARAMETER;
        
        if (0 > size)
#if defined(WINDOWS_WCE) 
            count = sizeof(TWNDCLASS);
#else /* defined(WINDOWS_WCE) */
            count = (m_wndClass.cbSize = sizeof(TWNDCLASS));
            else
            count = (m_wndClass.cbSize = size);
#endif /* defined(WINDOWS_WCE) */
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        INT count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Size
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual UINT Size() const 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
#if defined(WINDOWS_WCE) 
        UINT count = sizeof(TWNDCLASS);
#else /* defined(WINDOWS_WCE) */
        UINT count = (m_wndClass.cbSize);
#endif /* defined(WINDOWS_WCE) */
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        UINT count = 0;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetInstance
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual HINSTANCE SetInstance
    (HINSTANCE instance) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        m_wndClass.hInstance = instance;
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        instance = NULL;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return instance;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Instance
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual HINSTANCE Instance() const 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        HINSTANCE instance = (m_wndClass.hInstance);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        HINSTANCE instance = NULL;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return instance;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowProc
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual WNDPROC SetWindowProc
    (WNDPROC windowProc) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        WNDPROC wndProc = (m_wndClass.lpfnWndProc = windowProc);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        WNDPROC wndProc = DefWindowProc;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return wndProc;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual WNDPROC WindowProc() const 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        WNDPROC wndProc = (m_wndClass.lpfnWndProc);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        WNDPROC wndProc = DefWindowProc;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return wndProc;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetClassName
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual LPCTSTR SetClassName
    (LPCTSTR className) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        m_wndClass.lpszClassName = className;
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        LPCTSTR className = 0;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return className;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ClassName
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual LPCTSTR ClassName() const 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        LPCTSTR className = m_wndClass.lpszClassName;
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        LPCTSTR className = 0;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return className;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetClassExtra
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual int SetClassExtra
    (int size) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = (m_wndClass.cbClsExtra = size);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ClassExtra
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual int ClassExtra() const 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = (m_wndClass.cbClsExtra);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowExtra
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual int SetWindowExtra
    (int size) 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = (m_wndClass.cbWndExtra = size);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowExtra
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual int WindowExtra() const 
#if defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = (m_wndClass.cbWndExtra);
#else /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWNDCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWNDCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetDefaultCursor
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    HCURSOR GetDefaultCursor() const 
    {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultBackground
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    HBRUSH GetDefaultBackground() const 
    {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultWindowProc
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    WNDPROC GetDefaultWindowProc() const 
    {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }
};
#endif /* _CWINWNDCLASS_HXX */

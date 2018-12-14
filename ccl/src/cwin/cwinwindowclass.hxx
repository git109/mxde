/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cwinwindowclass.hxx
 *
 * Author: $author$
 *   Date: 1/21/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINWINDOWCLASS_HXX
#define _CWINWINDOWCLASS_HXX

#include "cwinatom.hxx"
#include "ctcharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowClass
 *
 * Author: $author$
 *   Date: 1/23/2004
 **********************************************************************
 */
class cWinWindowClass
: public cWinAtom
{
public:
    typedef cWinAtom cIs;

#if defined(_WIN32_WCE) 
    WNDCLASS m_wndclass;
#else /* defined(_WIN32_WCE) */
    WNDCLASSEX m_wndclass;
#endif /* defined(_WIN32_WCE) */
    cTCHARBuffer m_classname;

    /**
     **********************************************************************
     * Constructor: cWinWindowClass
     *
     *      Author: $author$
     *        Date: 1/23/2004
     **********************************************************************
     */
    cWinWindowClass(ATOM atom=0) 
    : cIs(atom) 
    {
        memset(&m_wndclass, 0, sizeof(m_wndclass));
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowClass
     *
     *     Author: $author$
     *       Date: 1/23/2004
     **********************************************************************
     */
    virtual ~cWinWindowClass()
    {
    }
    /**
     **********************************************************************
     * Function: RegisterExtra
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual eError RegisterExtra
    (LPCTSTR classname, int wndextra, int clsextra, 
     HINSTANCE instance, WNDPROC wndproc=NULL, 
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0)
    {
        return Register
       (classname, instance, wndproc, menuname, 
        icon, iconsm, cursor, background, 
        style, wndextra, clsextra);
    }
    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual eError Register
    (LPCTSTR classname, HINSTANCE instance, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0)
    {
        int count;

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        m_wndclass.cbSize=sizeof(m_wndclass);
#endif /* defined(_WIN32_WCE) */
        m_wndclass.lpszClassName=classname;
        m_wndclass.cbClsExtra=clsextra;
        m_wndclass.cbWndExtra=wndextra;

        if (NULL != menuname)
            m_wndclass.lpszMenuName=menuname;

        if (NULL != icon)
            m_wndclass.hIcon = icon;

#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
        if (NULL != iconsm)
            m_wndclass.hIconSm = iconsm;
#endif /* defined(_WIN32_WCE) */

        if (NULL != cursor)
            m_wndclass.hCursor = cursor;

        else if (NULL == m_wndclass.hCursor)
                m_wndclass.hCursor = GetDefaultCursor();

        if (NULL != background)
            m_wndclass.hbrBackground = background;

        else if (NULL == m_wndclass.hbrBackground)
                m_wndclass.hbrBackground = GetDefaultBackground();

        if (NULL != wndproc)
            m_wndclass.lpfnWndProc = wndproc;

        else if (NULL == m_wndclass.lpfnWndProc)
                m_wndclass.lpfnWndProc = GetDefaultWindowProc();

        m_wndclass.style=style;
        m_wndclass.hInstance=instance;

        if (0 < (count = SetClassName(classname)))
        if ((m_wndclass.lpszClassName = GetClassName()))
#if defined(_WIN32_WCE) 
        if (NULL != (m_handle = RegisterClass(&m_wndclass)))
#else /* defined(_WIN32_WCE) */
        if (NULL != (m_handle = RegisterClassEx(&m_wndclass)))
#endif /* defined(_WIN32_WCE) */
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Unregister
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual eError Unregister()
    {
        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (UnregisterClass
            (m_wndclass.lpszClassName, m_wndclass.hInstance))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: SetMenu
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual LPCTSTR SetMenu(LPCTSTR menu_name)
    {
        m_wndclass.lpszMenuName = menu_name;
        return m_wndclass.lpszMenuName;
    }
    /**
     **********************************************************************
     * Function: GetMenu
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual LPCTSTR GetMenu() const
    {
        return m_wndclass.lpszMenuName;
    }
    /**
     **********************************************************************
     * Function: SetIcon
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HICON SetIcon(HICON icon)
    {
        return m_wndclass.hIcon = icon;
    }
    /**
     **********************************************************************
     * Function: GetIcon
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HICON GetIcon() const
    {
        return m_wndclass.hIcon;
    }
    /**
     **********************************************************************
     * Function: SetBackground
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HBRUSH SetBackground(HBRUSH background)
    {
        return m_wndclass.hbrBackground = background;
    }
    /**
     **********************************************************************
     * Function: GetBackground
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HBRUSH GetBackground() const
    {
        return m_wndclass.hbrBackground;
    }
    /**
     **********************************************************************
     * Function: SetClassName
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual int SetClassName(LPCTSTR classname)
    {
        int length;
        LPCTSTR old_classname=m_classname.GetBuffer(length);

        if (classname != old_classname)
            length = m_classname.Copy(classname);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetClassName
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual LPCTSTR GetClassName() const
    {
        return m_classname.GetBuffer();
    }

    /**
     **********************************************************************
     * Function: GetDefaultCursor
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual HCURSOR GetDefaultCursor() const 
    {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultBackground
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual HBRUSH GetDefaultBackground() const 
    {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }
    /**
     **********************************************************************
     * Function: GetDefaultWindowProc
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual WNDPROC GetDefaultWindowProc() const 
    {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }
};

#endif /* _CWINWINDOWCLASS_HXX */



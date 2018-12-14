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
 *   File: cwinwindowsubclass.hxx
 *
 * Author: $author$
 *   Date: 1/21/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINWINDOWSUBCLASS_HXX
#define _CWINWINDOWSUBCLASS_HXX

#include "cwinwindowclass.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowSubclass
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinWindowSubclass
: public cWinWindowClass
{
public:
    typedef cWinWindowClass cIs;

    /**
     **********************************************************************
     * Constructor: cWinWindowSubclass
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinWindowSubclass() 
    : cWinWindowClass() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowSubclass
     *
     *     Author: $author$
     *       Date: 1/25/2004
     **********************************************************************
     */
    virtual ~cWinWindowSubclass()
    {
    }
    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Register
    (LPCTSTR super_classname, HINSTANCE super_instance,
     LPCTSTR classname, HINSTANCE instance, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0)
    {
        int count;

        if (GetClassInfoEx
            (super_instance, super_classname, &m_wndclass))

        if (0 < (count = m_classname.Copy(classname)))

        if ((m_wndclass.lpszClassName = m_classname.GetBuffer()))
        {
            m_wndclass.hInstance=instance;

            if (menuname)
                m_wndclass.lpszMenuName=menuname;

            if (clsextra > 0)
                m_wndclass.cbClsExtra += clsextra;

            if (wndextra > 0)
                m_wndclass.cbWndExtra += wndextra;

            if (icon)
                m_wndclass.hIcon=icon;

            if (iconsm)
                m_wndclass.hIconSm=iconsm;

            if (cursor)
                m_wndclass.hCursor=cursor;

            if (background)
                m_wndclass.hbrBackground=background;

            if (wndproc)
                m_wndclass.lpfnWndProc=wndproc;

            if (style)
                m_wndclass.style=style;

            if (NULL != (m_handle = RegisterClassEx(&m_wndclass)))
                return e_ERROR_NONE;
        }

        return e_ERROR_FAILED;
    }
};

#endif /* _CWINWINDOWSUBCLASS_HXX */



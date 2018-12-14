/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cwinmdichildwindow.hxx
 *
 * Author: $author$
 *   Date: 6/6/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINMDICHILDWINDOW_HXX
#define _CWINMDICHILDWINDOW_HXX

#include "cwinwindow.hxx"

#define CWIN_DEFAULT_MDI_CHILD_WINDOW_STYLE \
    MDIS_ALLCHILDSTYLES

/**
 **********************************************************************
 *  Class: cWinMDIChildWindow
 *
 * Author: $author$
 *   Date: 6/6/2007
 **********************************************************************
 */
class cWinMDIChildWindow
: public cWinWindow
{
public:
    typedef cWinWindow cExtends;
    typedef cWinMDIChildWindow cDerives;

    /**
     **********************************************************************
     * Constructor: cWinMDIChildWindow
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    cWinMDIChildWindow
    (HINSTANCE instance=NULL, HWND handle=NULL, 
     bool created=false, HINSTANCE old_instance=NULL) 
    : cExtends(instance, handle, created, old_instance) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIChildWindow
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    virtual ~cWinMDIChildWindow()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE instance, LPCTSTR classname,
     HWND parent, LPCTSTR windowname=NULL, 
     DWORD style=CWIN_DEFAULT_MDI_CHILD_WINDOW_STYLE,
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT)
    {
        HINSTANCE old_instance = m_instance;
        MDICREATESTRUCT mcs;

        mcs.szTitle = windowname;
        mcs.szClass = classname;
        mcs.hOwner  = instance;
        mcs.x = x;
        mcs.y = y;
        mcs.cx = width;
        mcs.cy = height;
        mcs.style = style;
        mcs.lParam = (LPARAM)(this);

        m_instance = instance;

        if ((m_handle = (HWND)(::SendMessage
            (parent, WM_MDICREATE, 0, (LPARAM)&mcs))))
            return e_ERROR_NONE;

        m_instance = old_instance;
        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: OnWMClose
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual LRESULT OnWMClose(WPARAM wparam, LPARAM lparam)
    {
        return OnDefMDIChildProc
        (WM_CLOSE, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMMDIActivate
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual LRESULT OnWMMDIActivate(WPARAM wparam, LPARAM lparam)
    {
        return OnDefMDIChildProc
        (WM_MDIACTIVATE, wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    static LRESULT CALLBACK WindowProc
    (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        cWinWindow *window;
        CREATESTRUCT *cs;
        MDICREATESTRUCT *mcs;
        LPVOID data;

        window = (cWinWindow*)GetWindowLong(handle, GWL_USERDATA);

        switch(message)
        {
#if defined(_WIN32_WCE)
        case WM_CREATE:
#else /* defined(_WIN32_WCE) */
        case WM_NCCREATE:
#endif /* defined(_WIN32_WCE) */
            if ((cs = (CREATESTRUCT*)lparam))
            if ((mcs = (MDICREATESTRUCT*)cs->lpCreateParams))
            {
                data = (LPVOID)mcs->lParam;
                SetWindowLong(handle, GWL_USERDATA, (LONG)data);

                if (NULL != (window = (cWinWindow*)data))
                if (NULL == window->m_handle)
                    window->m_handle = handle;
            }
            break;
        }

        if (window)
            return window->OnWindowProc(message, wparam, lparam);

        return DefMDIChildProc(handle, message, wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnDefWindowProc
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnDefWindowProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        switch(message)
        {
        case WM_MDIACTIVATE:
            return OnWMMDIActivate(wparam, lparam);
        }
        return OnDefMDIChildProc
        (message, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnDefMDIChildProc
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual LRESULT OnDefMDIChildProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        return DefMDIChildProc
        (m_handle, message, wparam, lparam);
    }
};

#endif /* _CWINMDICHILDWINDOW_HXX */

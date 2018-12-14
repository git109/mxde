/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cwinlistviewwindow.hxx
 *
 * Author: $author$
 *   Date: 5/23/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINLISTVIEWWINDOW_HXX
#define _CWINLISTVIEWWINDOW_HXX

#include "cwincommoncontrolwindow.hxx"
#include "cwincontrolwindow.hxx"
#include "cwinlistview.hxx"
#include "cwincommoncontrol.hxx"

#define CWINLISTVIEWWINDOW_WINDOW_CLASS_NAME _T("cWinListViewWindow")

/**
 **********************************************************************
 *  Class: cWinListViewWindow
 *
 * Author: $author$
 *   Date: 5/23/2004
 **********************************************************************
 */
class cWinListViewWindow
: public cWinCommonControlWindow
{
public:
    typedef cWinCommonControlWindow cIs;

	cWinListView m_list_control;

    /**
     **********************************************************************
     * Constructor: cWinListViewWindow
     *
     *      Author: $author$
     *        Date: 5/23/2004
     **********************************************************************
     */
    cWinListViewWindow(HINSTANCE instance=NULL, HWND handle=NULL, bool created=false) 
    : cIs(instance, handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinListViewWindow
     *
     *     Author: $author$
     *       Date: 5/23/2004
     **********************************************************************
     */
    virtual ~cWinListViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        cWinClientRect client_rect(m_handle);
        eError error;

		if (!(error = m_list_control.Create
			(m_instance, m_handle, 1, 0,0,
             client_rect.right-client_rect.left+1, 
             client_rect.bottom-client_rect.top+1)))
		{
            SetControl(m_list_control);
            OnCreateControl();
        }
        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        if (m_list_control.GetIsCreated())
        {
            m_list_control.SetImageList(NULL);
            OnDestroyControl();
            SetControl(NULL);
		    m_list_control.Destroy();
        }
        return cIs::OnWMDestroy(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: GetListControl
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    inline cWinListView &GetListControl()
    {
        return m_list_control;
    }

    /**
     **********************************************************************
     * Function: RegisterWindowClass
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    static eError RegisterWindowClass(HINSTANCE instance)
    {
        LPCTSTR window_class_name=GetWindowClassName();
        cWinWindowClass &window_class=GetWindowClass();

        return window_class.Register
        (window_class_name, instance, WindowProc);
    }
    /**
     **********************************************************************
     * Function: UnregisterWindowClass
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    static eError UnregisterWindowClass()
    {
        cWinWindowClass &window_class=GetWindowClass();

        return window_class.Unregister();
    }

    /**
     **********************************************************************
     * Function: GetWindowClass
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    static cWinWindowClass &GetWindowClass()
    {
        static cWinWindowClass window_class;
        return window_class;
    }
    /**
     **********************************************************************
     * Function: GetWindowClassName
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    static inline LPCTSTR GetWindowClassName()
    {
        return CWINLISTVIEWWINDOW_WINDOW_CLASS_NAME;
    }
};

#endif /* ndef _CWINLISTVIEWWINDOW_HXX */

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
 *   File: cwintreeviewwindow.hxx
 *
 * Author: $author$
 *   Date: 5/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINTREEVIEWWINDOW_HXX
#define _CWINTREEVIEWWINDOW_HXX

#include "cwincommoncontrolwindow.hxx"
#include "cwincontrolwindow.hxx"
#include "cwincommoncontrol.hxx"

#define CWINTREEVIEWWINDOW_WINDOW_CLASS_NAME _T("cWinTreeViewWindow")

/**
 **********************************************************************
 *  Class: cWinTreeViewWindow
 *
 * Author: $author$
 *   Date: 5/12/2004
 **********************************************************************
 */
class cWinTreeViewWindow
: public cWinCommonControlWindow
{
public:
    typedef cWinCommonControlWindow cIs;

	cWinTreeView m_tree_control;

    /**
     **********************************************************************
     * Constructor: cWinTreeViewWindow
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinTreeViewWindow(HINSTANCE instance=NULL, HWND handle=NULL, bool created=false) 
    : cIs(instance, handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinTreeViewWindow
     *
     *     Author: $author$
     *       Date: 5/12/2004
     **********************************************************************
     */
    virtual ~cWinTreeViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnWMNotify
     *
     *   Author: $author$
     *     Date: 5/25/2004
     **********************************************************************
     */
    virtual LRESULT OnWMNotify(WPARAM wparam, LPARAM lparam)
    {
        NMTREEVIEW &notify=*((LPNMTREEVIEW)lparam);

        switch(notify.hdr.code)
        {
        case TVN_SELCHANGED:
            return OnSelChanged(notify, wparam, lparam);
        }
        return cIs::OnWMNotify(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnSelChanged
     *
     *   Author: $author$
     *     Date: 5/25/2004
     **********************************************************************
     */
    virtual LRESULT OnSelChanged(NMTREEVIEW &notify, WPARAM wparam, LPARAM lparam)
    {
        return cIs::OnWMNotify(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        eError error;

		if (!(error = m_tree_control.Create
			(m_instance, m_handle, 1, 0,0, 100,100)))
		{
            SetControl(m_tree_control);
            OnCreateControl();
        }
        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        if (m_tree_control.GetIsCreated())
        {
            m_tree_control.SetImageList(NULL);
            OnDestroyControl();
            SetControl(NULL);
		    m_tree_control.Destroy();
        }
        return cIs::OnWMDestroy(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: GetTreeControl
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    inline cWinTreeView &GetTreeControl()
    {
        return m_tree_control;
    }

    /**
     **********************************************************************
     * Function: RegisterWindowClass
     *
     *   Author: $author$
     *     Date: 5/13/2004
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
     *     Date: 5/13/2004
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
     *     Date: 5/13/2004
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
     *     Date: 5/13/2004
     **********************************************************************
     */
    static inline LPCTSTR GetWindowClassName()
    {
        return CWINTREEVIEWWINDOW_WINDOW_CLASS_NAME;
    }
};

#endif /* ndef _CWINTREEVIEWWINDOW_HXX */

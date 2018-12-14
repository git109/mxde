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
 *   File: winft.cxx
 *
 * Author: $author$
 *   Date: 4/30/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "resource.h"
#include "cwintreeviewwindow.hxx"
#include "cwincontrolwindow.hxx"
#include "cwincommoncontrol.hxx"
#include "cwinwindow.hxx"
#include "cwinobject.hxx"
#include "cwinmaint.hxx"

/**
 **********************************************************************
 *  Class: cWinFTTreeViewWindow
 *
 * Author: $author$
 *   Date: 5/13/2004
 **********************************************************************
 */
class cWinFTTreeViewWindow
: public cWinTreeViewWindow
{
public:
    typedef cWinTreeViewWindow cIs;

    /**
     **********************************************************************
     * Constructor: cWinFTTreeViewWindow
     *
     *      Author: $author$
     *        Date: 5/13/2004
     **********************************************************************
     */
    cWinFTTreeViewWindow() 
    {
    }

    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;

        if (!(error = m_image_list.LoadBitmap
            (m_instance, IDB_IMAGELIST, 24)))
            m_tree_control.SetImageList(m_image_list);

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinFTMainWindow
 *
 * Author: $author$
 *   Date: 4/30/2004
 **********************************************************************
 */
class cWinFTMainWindow
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    LPCTSTR m_window_class_name;
    cWinFTTreeViewWindow m_tree_view;

    /**
     **********************************************************************
     * Constructor: cWinFTMainWindow
     *
     *      Author: $author$
     *        Date: 4/30/2004
     **********************************************************************
     */
    cWinFTMainWindow(LPCTSTR window_class_name=_T("cWinFTMainWindow")) 
    : m_window_class_name(window_class_name) 
    {
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        eError error;

		if (!(error = m_tree_view.Create
			(m_tree_view.GetWindowClassName(),
             m_instance, NULL, m_handle, NULL, 
             WS_CHILD | WS_VISIBLE, 0, 0,0, 100,100)))
		{
        }
        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        if (m_tree_view.GetIsCreated())
        {
		    m_tree_view.Destroy();
        }
        return cIs::OnWMDestroy(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: GetWindowClassName
     *
     *   Author: $author$
     *     Date: 4/30/2004
     **********************************************************************
     */
    LPCTSTR GetWindowClassName() const
    {
        return m_window_class_name;
    }
};

/**
 **********************************************************************
 *  Class: cWinFTMain
 *
 * Author: $author$
 *   Date: 4/30/2004
 **********************************************************************
 */
class cWinFTMain
: public cWinMain
{
public:
    typedef cWinMain cIs;

    /**
     **********************************************************************
     * Constructor: cWinFTMain
     *
     *      Author: $author$
     *        Date: 4/30/2004
     **********************************************************************
     */
    cWinFTMain() 
    : cWinMain() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinFTMain
     *
     *     Author: $author$
     *       Date: 4/30/2004
     **********************************************************************
     */
    virtual ~cWinFTMain()
    {
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 4/30/2004
     **********************************************************************
     */
    virtual int OnWinMain
    (HINSTANCE instance, HINSTANCE previnst,
     LPSTR cmdline, int cmdshow)
    {
        int result=0;
        eError error;
        cWinIcon icon;
        cWinBrush brush;
        cWinImageList image_list;
        cWinWindowClass window_class;
        cWinFTMainWindow window;
		cWinTreeView tree_control;

        //if (!(error = brush.GetStock(GRAY_BRUSH)))
        //if (!(error = image_list.LoadBitmap(instance, IDB_IMAGELIST, 24)))
        //if (!(error = icon.Create(instance, IDR_MAIN_WINDOW)))
        if (!(error = cWinTreeViewWindow::RegisterWindowClass(instance)))
        {
            //window_class.SetIcon(icon.GetHandle());
            //window_class.SetBackground(brush.GetHandle());

            if (!(error = window_class.Register
                (window.GetWindowClassName(), 
                 instance, window.WindowProc)))
            {
                if (!(error = window.Create
                    (window.GetWindowClassName(), instance)))
                {
                    window.Show();
/*
					if (!(error = tree_control.Create
						(instance, window.GetHandle(), 
                         1, 0,0, 100,100)))
					{

						cWinTreeView::cItem item;
						cWinTreeView::cInsert insert;

                        item.SetText("Hello John");
                        item.SetImage(1);
                        insert.SetItem(item);

                        window.m_tree_control.SetImageList(image_list);

                        window.m_tree_control.InsertItem(insert);

                        window.SetControl(tree_control);
*/
                    OnMessageLoop();
/*
                        window.SetControl(NULL);
						tree_control.Destroy();
					}
*/
                    window.Destroy();
                }
                window_class.Unregister();
            }
			//image_list.Destroy();
            cWinTreeViewWindow::UnregisterWindowClass();
        }
        return result;
    }
} g_winft_main;

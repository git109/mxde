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
 *   File: winevcs.cxx
 *
 * Author: $author$
 *   Date: 6/5/2007
 *
 *    $Id$
 **********************************************************************
 */

#include "afxres.h"
#include "resource.h"
#include "cwinevcsexplorerviewwindow.hxx"
#include "cwinevcsviewwindow.hxx"
#include "cwinevcsmainwindow.hxx"
#include "cwinevcsdialog.hxx"
#include "cwinevcsmain.hxx"
#include "cwinobject.hxx"
#include "cwinmaint.hxx"

/**
 **********************************************************************
 *  Class: cWinEvcsMain
 *
 * Author: $author$
 *   Date: 6/5/2007
 **********************************************************************
 */
class cWinEvcsMain
: virtual public cWinEvcsMainInterface,
  public cWinMain
{
public:
    typedef cWinMain cExtends;
    typedef cWinEvcsMain cDerives;

    const char *m_window_name;
    const char *m_window_classname;
    const char *m_child_window_classname;
    cWinWindowClass m_child_window_class;
    cWinWindowClass m_window_class;
    cWinEvcsMainWindow m_window;

    /**
     **********************************************************************
     * Constructor: cWinEvcsMain
     *
     *      Author: $author$
     *        Date: 6/5/2007
     **********************************************************************
     */
    cWinEvcsMain
    (const char *window_name="WinEvcs",
     const char *window_classname="cWinEvcs",
     const char *child_window_classname="cWinEvcsChild")
    : m_window_name(window_name),
      m_window_classname(window_classname),
      m_child_window_classname(child_window_classname),
      m_window(*this, m_window_class, m_child_window_class) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsMain
     *
     *      Author: $author$
     *        Date: 6/5/2007
     **********************************************************************
     */
    virtual ~cWinEvcsMain()
    {
    }

    /**
     **********************************************************************
     * Function: OnWinMain
     *
     *   Author: $author$
     *     Date: 1/23/2004
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

        if (!(error = brush.GetStock(WHITE_BRUSH)))
        if (!(error = icon.Create(instance, IDR_MAIN_WINDOW)))
        {
            m_window_class.SetBackground(brush.GetHandle());
            m_window_class.SetIcon(icon.GetHandle());
            m_window_class.SetMenu(MAKEINTRESOURCE(IDR_MAIN_WINDOW));

            if (!(error = m_window_class.Register
                (m_window_classname, instance, 
                 cWinEvcsMainWindow::WindowProc)))
            {
                m_child_window_class.SetBackground(brush.GetHandle());
                m_child_window_class.SetIcon(icon.GetHandle());

                if (!(error = m_child_window_class.Register
                    (m_child_window_classname, instance, 
                     cWinEvcsViewWindow::WindowProc)))
                {
                    if (!(error = cWinTreeViewWindow::
                         RegisterWindowClass(instance)))
                    {
                        if (!(error = cWinListViewWindow::
                            RegisterWindowClass(instance)))
                        {
                            if (!(error = m_window.Create
                                 (m_window_classname, instance, m_window_name)))
                            {
                                m_window.Show();
                                OnMessageLoop();
                                m_window.Destroy();
                            }
                            cWinListViewWindow::UnregisterWindowClass();
                        }
                        cWinTreeViewWindow::UnregisterWindowClass();
                    }
                    m_child_window_class.Unregister();
                }
                m_window_class.Unregister();
            }
        }
        return result;
    }
};

cWinEvcsMain g_winevcs_main;

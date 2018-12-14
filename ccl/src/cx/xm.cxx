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
 *   File: xm.cxx
 *
 * Author: $author$
 *   Date: 4/24/2004
 *
 *    $Id$
 **********************************************************************
 */
#include "cxmmenu.hxx"
#include "cxmwidget.hxx"
#include "cxmmain.hxx"
#include "cxtwidget.hxx"
#include "cxobject.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *   Enum: 
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
enum
{
    e_MENU_FILE_OPEN,
    e_MENU_FILE_CLOSE,
    e_MENU_FILE_SAVE,
    e_MENU_FILE_SAVE_AS,
    e_MENU_FILE_EXIT
};

/**
 **********************************************************************
 *  Class: cTheMainWindow
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cTheMainWindow
: public cXmMainWindow
{
public:
    typedef cXmMainWindow cIs;

    c_XM_MENU_DECLARE(m_menudef)

    /**
     **********************************************************************
     * Constructor: cTheMainWindow
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cTheMainWindow
    (String xt_name="cTheMainWindow",
     String xt_class_name="cTheMainWindow")
    : cIs(xt_name, xt_class_name) 
    {
    }
};

/**
 **********************************************************************
 *   Menu: cTheMainWindow::m_menudef
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
c_XM_MENU_BAR (cTheMainWindow::m_menudef,1)
  c_XM_MENU_PULLDOWN ("&File")
     c_XM_MENU_ITEM ("&Open...",   "Ctrl+O",e_MENU_FILE_OPEN)
     c_XM_MENU_ITEM ("&Close",     0,       e_MENU_FILE_CLOSE)
     c_XM_MENU_ITEM ("&Save",      "Ctrl+S",e_MENU_FILE_SAVE)
     c_XM_MENU_ITEM ("Save &As...",0,       e_MENU_FILE_SAVE_AS)
     c_XM_MENU_SEPARATOR
     c_XM_MENU_ITEM ("E&xit",      "Ctrl+Q",e_MENU_FILE_EXIT)
  c_XM_MENU_PULLDOWN_END
c_XM_MENU_END

class cTheMain;

/**
 **********************************************************************
 *  Class: cTheApplicationShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cTheApplicationShell
: public cXmApplicationShell
{
public:
    typedef cXmApplicationShell cIs;

    cTheMain &m_main;

    cXAtom_WM_PROTOCOLS m_atom_wm_protocols;
    cXAtom_WM_DELETE_WINDOW m_atom_wm_delete_window;

    cTheMainWindow m_client_window;

    /**
     **********************************************************************
     * Constructor: cTheApplicationShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cTheApplicationShell
    (cTheMain &main, 
     String xt_name="cTheApplicationShell",
     String xt_class_name="cTheApplicationShell")
    : cIs(xt_name, xt_class_name),
      m_main(main)
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError Create
    (Display *x_display, const cXtArgs &args=cXtArgs::m_null)
    {
        eError error;

        if (!(error = m_atom_wm_protocols.Create(x_display)))

        if (!(error = m_atom_wm_delete_window.Create(x_display)))

        if (!(error = cIs::Create(x_display, args)))
        {
            if (!(error = AddProtocolCallback
                (m_atom_wm_protocols, 
                 m_atom_wm_delete_window,
                 DeleteCallback, this)))

            if (!(error=m_client_window.CreateManaged(*this)))
                return error;

            Destroy();
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: OnDeleteCallback
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual void OnDeleteCallback(XtPointer xt_call=0);
};

/**
 **********************************************************************
 *  Class: cTheMain
 *
 * Author: $author$
 *   Date: 4/24/2004
 **********************************************************************
 */
class cTheMain
: public cXmMain
{
public:
    typedef cXmMain cIs;

    cTheApplicationShell m_shell;

    /**
     **********************************************************************
     * Constructor: cTheMain
     *
     *      Author: $author$
     *        Date: 4/24/2004
     **********************************************************************
     */
    cTheMain(char *display_name="0:0")
    : cIs(display_name),
      m_shell(*this)
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError Open(int argc, char **argv)
    {
        eError error=e_ERROR_NONE;

        if (!(error = m_shell.Create(m_display.GetHandle())))
        {
            if (!(error = m_shell.Realize()))
                return error;

            m_shell.Destroy();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error=e_ERROR_NONE;

        m_shell.Destroy();
        return error;
    }
} g_xm;

/**
 **********************************************************************
 * Function: cTheApplicationShell::OnDeleteCallback
 *
 *   Author: $author$
 *     Date: 4/29/2004
 **********************************************************************
 */
void cTheApplicationShell::OnDeleteCallback(XtPointer xt_call)
{
    //printf("OnDeleteCallback(XtPointer xt_call=%x)\n", xt_call);
}


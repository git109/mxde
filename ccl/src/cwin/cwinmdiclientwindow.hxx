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
 *   File: cwinmdiclientwindow.hxx
 *
 * Author: $author$
 *   Date: 6/6/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINMDICLIENTWINDOW_HXX
#define _CWINMDICLIENTWINDOW_HXX

#include "cwinwindow.hxx"

#define CWIN_DEFAULT_MDI_CLIENT_WINDOW_STYLE \
    WS_VISIBLE| WS_CHILD | WS_CLIPCHILDREN | \
    WS_VSCROLL | WS_HSCROLL

#define CWIN_DEFAULT_MDI_CLIENT_WINDOW_EXSTYLE \
    WS_EX_CLIENTEDGE

#define CWIN_DEFAULT_MDI_CLIENT_WINDOW_CLASSNAME _T("mdiclient")

/**
 **********************************************************************
 *  Class: cWinMDIClientWindow
 *
 * Author: $author$
 *   Date: 6/6/2007
 **********************************************************************
 */
class cWinMDIClientWindow
: public cWinWindow
{
public:
    typedef cWinWindow cExtends;
    typedef cWinMDIClientWindow cDerives;

    /**
     **********************************************************************
     * Constructor: cWinMDIClientWindow
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    cWinMDIClientWindow
    (HINSTANCE instance=NULL, HWND handle=NULL, 
     bool created=false, HINSTANCE old_instance=NULL) 
    : cExtends(instance, handle, created, old_instance) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIClientWindow
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    virtual ~cWinMDIClientWindow()
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
    (HINSTANCE instance, HWND parent, 
     HMENU mdi_child_menu=NULL, UINT mdi_child_id=0,
     LPCTSTR classname=CWIN_DEFAULT_MDI_CLIENT_WINDOW_CLASSNAME,
     DWORD style=CWIN_DEFAULT_MDI_CLIENT_WINDOW_STYLE,
     DWORD exstyle=CWIN_DEFAULT_MDI_CLIENT_WINDOW_EXSTYLE, 
     int x=CW_USEDEFAULT, int y=CW_USEDEFAULT, 
     int width=CW_USEDEFAULT, int height=CW_USEDEFAULT)
    {
        CLIENTCREATESTRUCT ccs;

        ccs.hWindowMenu = mdi_child_menu;
        ccs.idFirstChild = mdi_child_id;

        return CreateTheWindow
        (classname, NULL, style, exstyle, 
         x, y, width, height, parent, NULL, instance, &ccs);
    }
};

#endif /* _CWINMDICLIENTWINDOW_HXX */

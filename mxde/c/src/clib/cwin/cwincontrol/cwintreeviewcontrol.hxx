/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cwintreeviewcontrol.hxx
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
#if !defined(_CWINTREEVIEWCONTROL_HXX) || defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY)
#if !defined(_CWINTREEVIEWCONTROL_HXX) && !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY)
#define _CWINTREEVIEWCONTROL_HXX
#endif /* !defined(_CWINTREEVIEWCONTROL_HXX) && !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY) */

#if !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY)
#include "cwincontrol.hxx"

#define CWINTREEVIEWCONTROL_DEFAULT_WINDOW_CLASSNAME WC_TREEVIEW

#define CWINTREEVIEWCONTROL_DEFAULT_WINDOW_STYLE \
    WS_CHILD | WS_VISIBLE | \
    TVS_HASLINES | TVS_LINESATROOT | \
    TVS_HASBUTTONS | TVS_SHOWSELALWAYS | \
    TVS_EDITLABELS

#define CWINTREEVIEWCONTROL_DEFAULT_WINDOW_EXSTYLE \
    WS_EX_CLIENTEDGE

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinTreeViewControl
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinTreeViewControl
: public cWinControl
{
public:
    typedef cWinControl cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinTreeViewControl
     *
     *       Author: $author$
     *         Date: 3/24/2010
     **********************************************************************
     */
    cWinTreeViewControl
    (HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinTreeViewControl
     *
     *      Author: $author$
     *        Date: 3/24/2010
     **********************************************************************
     */
    virtual ~cWinTreeViewControl()
    {
    }
#else /* !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$
     *      Date: 3/24/2010
     **********************************************************************
     */
    virtual HWND CreateDetached
    (eError& error, 
     HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName = 0, 
     DWORD style = CWINTREEVIEWCONTROL_DEFAULT_WINDOW_STYLE, 
     DWORD exStyle = CWINTREEVIEWCONTROL_DEFAULT_WINDOW_EXSTYLE, 
     LPCTSTR className = CWINTREEVIEWCONTROL_DEFAULT_WINDOW_CLASSNAME, 
     LPVOID lParam = 0)
#if defined(CWINTREEVIEWCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINTREEVIEWCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINTREEVIEWCONTROL_MEMBER_FUNCS_IMPLEMENT)
        HMENU hMenu=(HMENU)(id);
        HWND hWnd = cWinWindow::CreateDetached
        (error, exStyle, className, windowName, 
         style, x,y, width,height, hParentWnd, hMenu, hInstance, lParam);
#else /* !defined(CWINTREEVIEWCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        HWND hWnd = NULL;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINTREEVIEWCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return hWnd;
    }
#endif /* defined(CWINTREEVIEWCONTROL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINTREEVIEWCONTROL_HXX) || defined(CWINTREEVIEWCONTROL_MEMBERS_ONLY) */

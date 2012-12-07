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
 *   File: cwinmdiclientwindow.hxx
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
#if !defined(_CWINMDICLIENTWINDOW_HXX) || defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMDICLIENTWINDOW_HXX) && !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY)
#define _CWINMDICLIENTWINDOW_HXX
#endif /* !defined(_CWINMDICLIENTWINDOW_HXX) && !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY)
#include "cwinsuperclassedwindow.hxx"
#include "cwinmdiclientwindowsuperclass.hxx"

#define CWINMDICLIENTWINDOW_WINDOW_STYLE \
    WS_VISIBLE| WS_CHILD | WS_CLIPCHILDREN | \
    WS_VSCROLL | WS_HSCROLL //| MDIS_ALLCHILDSTYLES

#define CWINMDICLIENTWINDOW_WINDOW_EXSTYLE \
    WS_EX_CLIENTEDGE

#define CWINMDICLIENTWINDOW_WINDOW_CLASSNAME \
    CWINMDICLIENTWINDOWSUPERCLASS_WINDOW_CLASSNAME
    
#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinMDIClientWindowExtend
 *
 *  Author: $author$
 *    Date: 1/1/2010
 **********************************************************************
 */
typedef cWinSuperClassedWindow
cWinMDIClientWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMDIClientWindow
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIClientWindow
: public cWinMDIClientWindowExtend
{
public:
    typedef cWinMDIClientWindowExtend cExtends;

    bool m_hasAllChildStyles;
        
    /**
     **********************************************************************
     *  Constructor: cWinMDIClientWindow
     *
     *       Author: $author$
     *         Date: 1/1/2010
     **********************************************************************
     */
    cWinMDIClientWindow
    (bool hasAllChildStyles=false,
     WNDPROC windowSubclassProc=NULL,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (windowSubclassProc, 
       hInstance, attached, isCreated),
       
      m_hasAllChildStyles(hasAllChildStyles)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIClientWindow
     *
     *      Author: $author$
     *        Date: 1/1/2010
     **********************************************************************
     */
    virtual ~cWinMDIClientWindow()
    {
    }
#else /* !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_MDICREATE_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_MDICREATE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        SetIsCreated(false);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnWindowMessage
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        switch(msg)
        {
        case WM_MDICREATE:
            lResult = On_WM_MDICREATE_WindowMessage(hWnd,msg,wParam,lParam);
            break;
        default:
            lResult = cExtends::OnWindowMessage(hWnd,msg,wParam,lParam);
        }
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: SetHasAllChildStyles
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual bool SetHasAllChildStyles
    (bool isTrue=true) 
    {
        bool has = (m_hasAllChildStyles = isTrue);
        return has;
    }
    /**
     **********************************************************************
     * Function: HasAllChildStyles
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual bool HasAllChildStyles() const 
    {
        bool has = (m_hasAllChildStyles);
        return has;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDICLIENTWINDOW_HXX) || defined(CWINMDICLIENTWINDOW_MEMBERS_ONLY) */

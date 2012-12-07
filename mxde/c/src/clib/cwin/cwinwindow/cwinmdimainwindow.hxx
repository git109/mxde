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
 *   File: cwinmdimainwindow.hxx
 *
 * Author: $author$
 *   Date: 1/3/2010
 **********************************************************************
 */
#if !defined(_CWINMDIMAINWINDOW_HXX) || defined(CWINMDIMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMDIMAINWINDOW_HXX) && !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY)
#define _CWINMDIMAINWINDOW_HXX
#endif /* !defined(_CWINMDIMAINWINDOW_HXX) && !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY)
#include "cwinmdiframewindow.hxx"
#include "cwinmainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinMDIMainWindow;

#undef CDB_CLASS
#define CDB_CLASS "cWinMDIMainWindowT"
/**
 **********************************************************************
 *  Class: cWinMDIMainWindowT
 *
 * Author: $author$
 *   Date: 1/3/2010
 **********************************************************************
 */
template
<class TDerives=cWinMDIMainWindow,
 class TWinMDIFrameWindow=cWinMDIFrameWindow,
 class TWinMDIMainWindowExtend=cWinMainWindowT
 <TDerives, TWinMDIFrameWindow>,
 class TExtends=TWinMDIMainWindowExtend>

class c_EXPORT_CLASS cWinMDIMainWindowT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    
    cWinMDIClientWindowSuperClass m_mdiClientWindowClass;
    
    /**
     **********************************************************************
     *  Constructor: cWinMDIMainWindowT
     *
     *       Author: $author$
     *         Date: 1/3/2010
     **********************************************************************
     */
    cWinMDIMainWindowT
    (COLORREF bgColor=CWINMDIFRAMEWINDOW_BG_COLOR,
     bool hasDropShadow=false,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDIFRAMEWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars,
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIMainWindowT
     *
     *      Author: $author$
     *        Date: 1/3/2010
     **********************************************************************
     */
    virtual ~cWinMDIMainWindowT()
    {
    }
#else /* !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError InitializeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = cExtends::InitializeWindowClass
            (windowClass, hInstance)))
            error = RegisterMDIClientWindowClass
            (m_mdiClientWindowClass, hInstance);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeWindowClass
     *
     *   Author: $author$
     *     Date: 1/3/2010
     **********************************************************************
     */
    virtual eError FinalizeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        
        error = UnregisterMDIClientWindowClass
        (m_mdiClientWindowClass, hInstance);
        
        if ((error2 = cExtends::FinalizeWindowClass
            (windowClass, hInstance)) && !error)
            error = error2;
        return error;
    }
    
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinMDIMainWindowExtend
 *
 *  Author: $author$
 *    Date: 1/3/2010
 **********************************************************************
 */
typedef cWinMDIMainWindowT<>
cWinMDIMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMDIMainWindow
 *
 * Author: $author$
 *   Date: 1/3/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIMainWindow
: public cWinMDIMainWindowExtend
{
public:
    typedef cWinMDIMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMDIMainWindow
     *
     *       Author: $author$
     *         Date: 1/3/2010
     **********************************************************************
     */
    cWinMDIMainWindow
    (COLORREF bgColor=CWINMDIFRAMEWINDOW_BG_COLOR,
     bool hasDropShadow=false,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDIFRAMEWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars,
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIMainWindow
     *
     *      Author: $author$
     *        Date: 1/3/2010
     **********************************************************************
     */
    virtual ~cWinMDIMainWindow()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDIMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDIMAINWINDOW_HXX) || defined(CWINMDIMAINWINDOW_MEMBERS_ONLY) */

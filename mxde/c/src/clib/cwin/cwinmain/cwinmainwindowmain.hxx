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
 *   File: cwinmainwindowmain.hxx
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
#if !defined(_CWINMAINWINDOWMAIN_HXX) || defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY)
#if !defined(_CWINMAINWINDOWMAIN_HXX) && !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY)
#define _CWINMAINWINDOWMAIN_HXX
#endif /* !defined(_CWINMAINWINDOWMAIN_HXX) && !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY) */

#if !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY)
#include "cwinmainwindow.hxx"
#include "cwinwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinMainWindowMainT
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
template
<class TWinMainWindow=cWinMainWindow,
 class TExtend=cWinWindowMain,
 class TExtends=TExtend>

class cWinMainWindowMainT
: public TExtends
{
public:
    typedef TExtends cExtends;
    
    TWinMainWindow m_mainWindow;
    
    /**
     **********************************************************************
     *  Constructor: cWinMainWindowMainT
     *
     *       Author: $author$
     *         Date: 11/11/2010
     **********************************************************************
     */
    cWinMainWindowMainT()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMainWindowMainT
     *
     *      Author: $author$
     *        Date: 11/11/2010
     **********************************************************************
     */
    virtual ~cWinMainWindowMainT()
    {
    }
#else /* !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY) */
#endif /* !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY) */

#if !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        error = m_mainWindow.CreateMainWindow
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual eError DestroyMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        error = m_mainWindow.DestroyMainWindow
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: InitializeMainWindowClass
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual eError InitializeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        error = m_mainWindow.InitializeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual eError FinalizeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        error = m_mainWindow.FinalizeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY) */
#endif /* !defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY) */

#endif /* !defined(_CWINMAINWINDOWMAIN_HXX) || defined(CWINMAINWINDOWMAINT_MEMBERS_ONLY) */

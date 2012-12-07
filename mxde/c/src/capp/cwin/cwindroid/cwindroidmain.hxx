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
 *   File: cwindroidmain.hxx
 *
 * Author: $author$
 *   Date: 1/22/2010
 **********************************************************************
 */
#if !defined(_CWINDROIDMAIN_HXX) || defined(CWINDROIDMAIN_MEMBERS_ONLY)
#if !defined(_CWINDROIDMAIN_HXX) && !defined(CWINDROIDMAIN_MEMBERS_ONLY)
#define _CWINDROIDMAIN_HXX
#endif /* !defined(_CWINDROIDMAIN_HXX) && !defined(CWINDROIDMAIN_MEMBERS_ONLY) */

#if !defined(CWINDROIDMAIN_MEMBERS_ONLY)
#include "cwindroidmainwindow.hxx"
#include "cwinwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDroidMainExtend
 *
 *  Author: $author$
 *    Date: 1/22/2010
 **********************************************************************
 */
typedef cWinWindowMain
cWinDroidMainExtend;
/**
 **********************************************************************
 *  Class: cWinDroidMain
 *
 * Author: $author$
 *   Date: 1/22/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDroidMain
: public cWinDroidMainExtend
{
public:
    typedef cWinDroidMainExtend cExtends;

    cWinDroidMainWindow m_mainWindow;

    /**
     **********************************************************************
     *  Constructor: cWinDroidMain
     *
     *       Author: $author$
     *         Date: 1/22/2010
     **********************************************************************
     */
    cWinDroidMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDroidMain
     *
     *      Author: $author$
     *        Date: 1/22/2010
     **********************************************************************
     */
    virtual ~cWinDroidMain()
    {
    }
#else /* !defined(CWINDROIDMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINDROIDMAIN_MEMBERS_ONLY) */

#if !defined(CWINDROIDMAIN_MEMBERS_ONLY)
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

#else /* !defined(CWINDROIDMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINDROIDMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINDROIDMAIN_HXX) || defined(CWINDROIDMAIN_MEMBERS_ONLY) */

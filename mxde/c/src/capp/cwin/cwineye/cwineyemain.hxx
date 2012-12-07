/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwineyemain.hxx
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
#if !defined(_CWINEYEMAIN_HXX) || defined(CWINEYEMAIN_MEMBERS_ONLY)
#if !defined(_CWINEYEMAIN_HXX) && !defined(CWINEYEMAIN_MEMBERS_ONLY)
#define _CWINEYEMAIN_HXX
#endif /* !defined(_CWINEYEMAIN_HXX) && !defined(CWINEYEMAIN_MEMBERS_ONLY) */

#if !defined(CWINEYEMAIN_MEMBERS_ONLY)
#include "cwineyemainwindow.hxx"
#include "cwinwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinEyeMainExtends
 *
 *  Author: $author$
 *    Date: 7/21/2009
 **********************************************************************
 */
typedef cWinWindowMain
cWinEyeMainExtends;
/**
 **********************************************************************
 *  Class: cWinEyeMain
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
class cWinEyeMain
: public cWinEyeMainExtends
{
public:
    typedef cWinEyeMainExtends cExtends;

    cWinEyeMainWindow m_mainWindow;

    /**
     **********************************************************************
     *  Constructor: cWinEyeMain
     *
     *       Author: $author$
     *         Date: 7/21/2009
     **********************************************************************
     */
    cWinEyeMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEyeMain
     *
     *      Author: $author$
     *        Date: 7/21/2009
     **********************************************************************
     */
    virtual ~cWinEyeMain()
    {
    }
#else /* !defined(CWINEYEMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINEYEMAIN_MEMBERS_ONLY) */

#if !defined(CWINEYEMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = m_mainWindow.CreateMainWindow
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: InitializeMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual eError InitializeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = m_mainWindow.InitializeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual eError FinalizeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = m_mainWindow.FinalizeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINEYEMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINEYEMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINEYEMAIN_HXX) || defined(CWINEYEMAIN_MEMBERS_ONLY) */

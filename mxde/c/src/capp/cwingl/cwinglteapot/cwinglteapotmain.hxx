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
 *   File: cwinglteapotmain.hxx
 *
 * Author: $author$
 *   Date: 12/5/2009
 **********************************************************************
 */
#if !defined(_CWINGLTEAPOTMAIN_HXX) || defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY)
#if !defined(_CWINGLTEAPOTMAIN_HXX) && !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY)
#define _CWINGLTEAPOTMAIN_HXX
#endif /* !defined(_CWINGLTEAPOTMAIN_HXX) && !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY) */

#if !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY)
#include "cwinglteapotmainwindow.hxx"
#include "cwinwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinGLTeapotMainExtends
 *
 *  Author: $author$
 *    Date: 12/5/2009
 **********************************************************************
 */
typedef cWinWindowMain
cWinGLTeapotMainExtends;
/**
 **********************************************************************
 *  Class: cWinGLTeapotMain
 *
 * Author: $author$
 *   Date: 12/5/2009
 **********************************************************************
 */
class cWinGLTeapotMain
: public cWinGLTeapotMainExtends
{
public:
    typedef cWinGLTeapotMainExtends cExtends;
    
    cWinGLTeapotMainWindow m_mainWindow;
    
    /**
     **********************************************************************
     *  Constructor: cWinGLTeapotMain
     *
     *       Author: $author$
     *         Date: 12/5/2009
     **********************************************************************
     */
    cWinGLTeapotMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinGLTeapotMain
     *
     *      Author: $author$
     *        Date: 12/5/2009
     **********************************************************************
     */
    virtual ~cWinGLTeapotMain()
    {
    }
    /**
     **********************************************************************
     *  Function: CreateMainWindow
     *
     *    Author: $author$
     *      Date: 12/2/2009
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
     *  Function: InitializeMainWindowClass
     *
     *    Author: $author$
     *      Date: 12/2/2009
     **********************************************************************
     */
    virtual eError InitializeMainWindowClass()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     *  Function: FinalizeMainWindowClass
     *
     *    Author: $author$
     *      Date: 12/2/2009
     **********************************************************************
     */
    virtual eError FinalizeMainWindowClass()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#else /* !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY) */

#if !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINGLTEAPOTMAIN_HXX) || defined(CWINGLTEAPOTMAIN_MEMBERS_ONLY) */

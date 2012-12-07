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
 *   File: cwinphonemain.hxx
 *
 * Author: $author$
 *   Date: 5/30/2009
 **********************************************************************
 */
#ifndef _CWINPHONEMAIN_HXX
#define _CWINPHONEMAIN_HXX

#include "cwinwindowmain.hxx"
#include "cwinphonemainwindow.hxx"

/**
 **********************************************************************
 *  Class: cWinPhoneMain
 *
 * Author: $author$
 *   Date: 5/30/2009
 **********************************************************************
 */
class cWinPhoneMain
: public cWinWindowMain
{
public:
    typedef cWinWindowMain cExtends;
    typedef cWinPhoneMain cDerives;

    cWinPhoneMainWindow m_mainWindow;

    /**
     **********************************************************************
     * Constructor: cWinPhoneMain
     *
     *      Author: $author$
     *        Date: 5/30/2009
     **********************************************************************
     */
    cWinPhoneMain() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinPhoneMain
     *
     *     Author: $author$
     *       Date: 5/30/2009
     **********************************************************************
     */
    virtual ~cWinPhoneMain()
    {
    }

    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 5/19/2009
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
     *     Date: 5/22/2009
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
     *     Date: 5/22/2009
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
#endif /* _CWINPHONEMAIN_HXX */


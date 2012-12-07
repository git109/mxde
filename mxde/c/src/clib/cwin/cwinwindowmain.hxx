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
 *   File: cwinwindowmain.hxx
 *
 * Author: $author$
 *   Date: 5/18/2009
 **********************************************************************
 */
#ifndef _CWINWINDOWMAIN_HXX
#define _CWINWINDOWMAIN_HXX

#include "cwinmain.hxx"
#include "cwinwindow.hxx"
#include "cwinwindowclass.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowMain
 *
 * Author: $author$
 *   Date: 5/18/2009
 **********************************************************************
 */
class cWinWindowMain
: public cWinMain
{
public:
    typedef cWinMain cExtends;
    typedef cWinWindowMain cDerives;

    cWinWindowClass m_windowClass;

    /**
     **********************************************************************
     * Function: BeforeProcessMessages
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual INT BeforeProcessMessages
    (HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        INT result = -e_ERROR_FAILED;
        eError error;

        if (hInstance)
        if (!(error = InitializeMainWindowClass
            (m_windowClass, hInstance, hPrevinst, cmdLine, cmdShow)))
        if (!(error = m_windowClass.Register(hInstance)))
        if (!(error = CreateMainWindow
            (m_windowClass, hInstance, hPrevinst, cmdLine, cmdShow)))
            result = 0;

        return result;
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
        eError error = e_ERROR_NONE;
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
        eError error = e_ERROR_NONE;
        return error;
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
        eError error = e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    virtual eError DestroyMainWindow() 
    {
        eError error = e_ERROR_FAILED;
        return error;
    }
};
#endif /* _CWINWINDOWMAIN_HXX */

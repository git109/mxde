/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cwinroundedframewindowmain.hxx
 *
 * Author: $author$
 *   Date: 11/26/2011
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEWINDOWMAIN_HXX) || defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEWINDOWMAIN_HXX) && !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEWINDOWMAIN_HXX
#endif /* !defined(_CWINROUNDEDFRAMEWINDOWMAIN_HXX) && !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY)
#include "cwinroundedframewindowmainwindow.hxx"
#include "cwinwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRoundedFrameWindowMainExtend
 *
 *  Author: $author$
 *    Date: 11/26/2011
 **********************************************************************
 */
typedef cWinWindowMain
cWinRoundedFrameWindowMainExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameWindowMain
 *
 * Author: $author$
 *   Date: 11/26/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRoundedFrameWindowMain
: //virtual public cWinRoundedFrameWindowMainImplement,
  public cWinRoundedFrameWindowMainExtend
{
public:
    //typedef cWinRoundedFrameWindowMainImplement cImplements;
    typedef cWinRoundedFrameWindowMainExtend cExtends;

    cWinRoundedFrameWindowMainWindow m_mainWindow;

    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameWindowMain
     *
     *       Author: $author$
     *         Date: 11/26/2011
     **********************************************************************
     */
    cWinRoundedFrameWindowMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedFrameWindowMain
     *
     *      Author: $author$
     *        Date: 11/26/2011
     **********************************************************************
     */
    virtual ~cWinRoundedFrameWindowMain()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
        error = GetMainWindow().CreateMainWindow
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
        error = GetMainWindow().DestroyMainWindow
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: InitializeMainWindowClass
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
        error = GetMainWindow().InitializeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
        error = GetMainWindow().FinalizeMainWindowClass
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return error;
    }
    /**
     **********************************************************************
     *  Function: GetMainWindow
     *
     *    Author: $author$
     *      Date: 11/26/2011
     **********************************************************************
     */
    virtual cWinRoundedFrameWindowMainWindow& GetMainWindow() const
    {
        return (cWinRoundedFrameWindowMainWindow&)(m_mainWindow);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEWINDOWMAIN_HXX) || defined(CWINROUNDEDFRAMEWINDOWMAIN_MEMBERS_ONLY) */

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
 *   File: cwincryptohashmain.hxx
 *
 * Author: $author$
 *   Date: 2/16/2010
 **********************************************************************
 */
#if !defined(_CWINCRYPTOHASHMAIN_HXX) || defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY)
#if !defined(_CWINCRYPTOHASHMAIN_HXX) && !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY)
#define _CWINCRYPTOHASHMAIN_HXX
#endif /* !defined(_CWINCRYPTOHASHMAIN_HXX) && !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY)
#include "cwincryptohashdialogwindow.hxx"
#include "cwindialogmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCryptoHashMainExtend
 *
 *  Author: $author$
 *    Date: 2/16/2010
 **********************************************************************
 */
typedef cWinDialogMain
cWinCryptoHashMainExtend;
/**
 **********************************************************************
 *  Class: cWinCryptoHashMain
 *
 * Author: $author$
 *   Date: 2/16/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinCryptoHashMain
: public cWinCryptoHashMainExtend
{
public:
    typedef cWinCryptoHashMainExtend cExtends;

    cWinWindowClass m_iconWindowClass;

#else /* !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: BeforeMainDialog
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual INT BeforeMainDialog
    (HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        cWinCryptoHashDialogWindow& mainDialog = GetCryptoHashDialogWindow();
        INT result = 0;
        eError error;

        if (hInstance)
        if (!(error = mainDialog.m_iconWindow.InitializeMainWindowClass
            (m_iconWindowClass, hInstance, hPrevinst, cmdLine, cmdShow)))
        if (!(error = m_iconWindowClass.Register(hInstance)))
        if (!(error = mainDialog.m_iconWindow.CreateMainWindow
            (m_iconWindowClass, hInstance, hPrevinst, cmdLine, cmdShow)))
        {
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: AfterMainDialog
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual INT AfterMainDialog
    (HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        cWinCryptoHashDialogWindow& mainDialog = GetCryptoHashDialogWindow();
        INT result = 0;
        
        mainDialog.m_iconWindow.DestroyMainWindow
        (m_iconWindowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        m_iconWindowClass.Unregister();
        mainDialog.m_iconWindow.FinalizeMainWindowClass
        (m_iconWindowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetCryptoHashDialogWindow
     *
     *   Author: $author$
     *     Date: 2/16/2010
     **********************************************************************
     */
    virtual cWinCryptoHashDialogWindow& 
    GetCryptoHashDialogWindow() const = 0;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINCRYPTOHASHMAIN_HXX) || defined(CWINCRYPTOHASHMAIN_MEMBERS_ONLY) */

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
 *   File: cwindialogmain.hxx
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
#ifndef _CWINDIALOGMAIN_HXX
#define _CWINDIALOGMAIN_HXX

#include "cwinmain.hxx"
#include "cwinmaindialog.hxx"

/**
 **********************************************************************
 *  Class: cWinDialogMain
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDialogMain
: public cWinMain
{
public:
    typedef cWinMain cExtends;
    typedef cWinDialogMain cDerives;

    cWinDialogWindowClass m_dialogWindowClass;

    /**
     **********************************************************************
     * Function: BeforeProcessMessages
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual INT BeforeProcessMessages
    (HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        INT result = -e_ERROR_FAILED;
        INT mainDialogID = 0;
        cWinMainDialog& mainDialog = GetMainDialog(mainDialogID);
        HWND hWndDesktop;
        BOOL wasVisible;
        eError error;
        INT err;

        if (!(err = BeforeMainDialog
            (hInstance, hPrevinst, cmdLine, cmdShow)))
        {
            if ((hInstance == GetHINSTANCE()))
            if ((hWndDesktop = GetDesktopWindow()))
            if (!(error = m_dialogWindowClass.Register(hInstance)))
            if (!(error = mainDialog.Create
                (hInstance, hPrevinst, cmdLine, 
                 cmdShow, mainDialogID, hWndDesktop)))
            {
                if ((wasVisible = ShowWindow
                    (mainDialog.m_hWndCreated, SW_SHOWNORMAL))
                    || !wasVisible)
                    return 0;
                    
                mainDialog.Destroy();
            }
                
            AfterMainDialog
            (hInstance, hPrevinst, cmdLine, cmdShow);
        }

        return result;
    }
    /**
     **********************************************************************
     * Function: AfterProcessMessages
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual INT AfterProcessMessages
    (HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        INT result = AfterMainDialog
        (hInstance, hPrevinst, cmdLine, cmdShow);
        return result;
    }

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
        INT result = 0;
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
        INT result = 0;
        return result;
    }
    
    /**
     **********************************************************************
     * Function: GetMainDialog
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual cWinMainDialog& GetMainDialog
    (INT& dialogID) const = 0;
};
#endif /* _CWINDIALOGMAIN_HXX */

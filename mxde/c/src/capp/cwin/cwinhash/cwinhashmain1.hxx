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
 *   File: cwinhashmain.hxx
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
#ifndef _CWINHASHMAIN_HXX
#define _CWINHASHMAIN_HXX

#include "cwincryptohashmain.hxx"
#include "cwincryptohashdialogwindow.hxx"
#include "cwineditwindowsuperclass.hxx"
#include "cwindialogmain.hxx"
#include "cmd5.hxx"

#define CWINHASHMAIN_DIALOG_CAPTION "cWinHash"

/**
 **********************************************************************
 *  Class: cWinHashMainDialog
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
class cWinHashMainDialog
: public cWinCryptoHashDialogWindow
{
public:
    typedef cWinCryptoHashDialogWindow cExtends;
    typedef cWinHashMainDialog cDerives;

    cMD5 m_hash;
    BYTE m_hashed[cMD5::HASHSIZE];
    WCHAR m_hashedText[cMD5::HASHSIZE*2+1];

    /**
     **********************************************************************
     * Function: On_WM_INITDIALOG_WindowMessage
     *
     *   Author: $author$
     *     Date: 10/27/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_INITDIALOG_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = FALSE;
        lResult = cExtends::On_WM_INITDIALOG_WindowMessage(hWnd, msg, wParam, lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: GetCryptoHash
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual cCryptoHashInterface& GetCryptoHash
    (WCHAR*& hashedText,
     BYTE*& hashed,
     TSIZE& hashedSize) const 
    {
        cCryptoHashInterface& cryptoHash = (cCryptoHashInterface&)(m_hash);
        hashedText = (WCHAR*)(m_hashedText);
        hashed = (BYTE*)(m_hashed);
        hashedSize = sizeof(m_hashed);
        return cryptoHash;
    }

    /**
     **********************************************************************
     * Function: GetDialogCaption
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual const TCHAR* GetDialogCaption() const 
    {
        const TCHAR* chars = _T(CWINHASHMAIN_DIALOG_CAPTION);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cWinHashMain
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
class cWinHashMain
: public cWinCryptoHashMain
{
public:
    typedef cWinCryptoHashMain cExtends;
    typedef cWinHashMain cDerives;

    cWinHashMainDialog m_mainDialog;
    cWinEditWindowSuperClass m_editWindowSuperClass;

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
        cExtends::BeforeMainDialog
        (hInstance, hPrevinst, cmdLine, cmdShow);
        OleInitialize(0);
        m_editWindowSuperClass.Register(hInstance);
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
        OleUninitialize();
        cExtends::AfterMainDialog
        (hInstance, hPrevinst, cmdLine, cmdShow);
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
    GetCryptoHashDialogWindow() const 
    {
        cWinCryptoHashDialogWindow& dialogWindow = ((cWinCryptoHashDialogWindow&)(m_mainDialog));
        return dialogWindow;
    }
    /**
     **********************************************************************
     * Function: GetMainDialog
     *
     *   Author: $author$
     *     Date: 10/26/2009
     **********************************************************************
     */
    virtual cWinMainDialog& GetMainDialog
    (INT& resID) const 
    {
        cWinMainDialog& mainDialog = (cWinMainDialog&)(m_mainDialog);
        resID = IDD_MAIN_DIALOG;
        return mainDialog;
    }
};
#endif /* _CWINHASHMAIN_HXX */

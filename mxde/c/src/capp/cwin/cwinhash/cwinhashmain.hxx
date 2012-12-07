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
 *  Class: cWinHashMainDialogT
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
template 
<class THash=cMD5>
class cWinHashMainDialogT
: public cWinCryptoHashDialogWindow
{
public:
    typedef cWinCryptoHashDialogWindow cExtends;
    
    const TCHAR* m_dialogCaptionChars;
    
    THash m_hash;
    BYTE m_hashed[THash::HASHSIZE];
    WCHAR m_hashedText[THash::HASHSIZE*2+1];

    /**
     **********************************************************************
     *  Constructor: cWinHashMainDialogT
     *
     *       Author: $author$
     *         Date: 2/16/2010
     **********************************************************************
     */
    cWinHashMainDialogT
    (const TCHAR* dialogCaptionChars=_T(CWINHASHMAIN_DIALOG_CAPTION))
    : m_dialogCaptionChars(dialogCaptionChars)
    {
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
        const TCHAR* chars=m_dialogCaptionChars;
        return chars;
    }
};

typedef cWinHashMainDialogT<> 
cWinHashMainDialog;

/**
 **********************************************************************
 *  Class: cWinHashMainT
 *
 * Author: $author$
 *   Date: 10/26/2009
 **********************************************************************
 */
template 
<class THashMainDialog=cWinHashMainDialog>
class cWinHashMainT
: public cWinCryptoHashMain
{
public:
    typedef cWinCryptoHashMain cExtends;

    THashMainDialog m_mainDialog;

    /**
     **********************************************************************
     *  Constructor: cWinHashMainT
     *
     *       Author: $author$
     *         Date: 2/16/2010
     **********************************************************************
     */
    cWinHashMainT
    (const TCHAR* dialogCaptionChars=_T(CWINHASHMAIN_DIALOG_CAPTION))
    : m_mainDialog(dialogCaptionChars)
    {
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

typedef cWinHashMainT<> 
cWinHashMain;

#endif /* _CWINHASHMAIN_HXX */

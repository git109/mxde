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
 *   File: cwinmd5main.hxx
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
#ifndef _CWINMD5MAIN_HXX
#define _CWINMD5MAIN_HXX

#include "cwincryptohashmaindialog.hxx"
#include "cwindialogmain.hxx"
#include "cmd5.hxx"

#define CWINMD5MAIN_DIALOG_CAPTION "WinMD5"

/**
 **********************************************************************
 *  Class: cWinMD5MainDialog
 *
 * Author: $author$
 *   Date: 5/9/2009
 **********************************************************************
 */
class cWinMD5MainDialog
: public cWinCryptoHashMainDialog
{
public:
    typedef cWinCryptoHashMainDialog cExtends;
    typedef cWinMD5MainDialog cDerives;

    cMD5 m_hash;
    BYTE m_hashed[cMD5::HASHSIZE];
    WCHAR m_hashedText[cMD5::HASHSIZE*2+1];

    /**
     **********************************************************************
     * Function: GetCryptoHash
     *
     *   Author: $author$
     *     Date: 5/13/2009
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
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual const TCHAR* GetDialogCaption() const 
    {
        const TCHAR* chars = _T(CWINMD5MAIN_DIALOG_CAPTION);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cWinMD5Main
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class cWinMD5Main
: public cWinDialogMain
{
public:
    typedef cWinDialogMain cExtends;
    typedef cWinMD5Main cDerives;

    cWinMD5MainDialog m_mainDialog;

    /**
     **********************************************************************
     * Function: GetMainDialog
     *
     *   Author: $author$
     *     Date: 5/13/2009
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
#endif /* _CWINMD5MAIN_HXX */

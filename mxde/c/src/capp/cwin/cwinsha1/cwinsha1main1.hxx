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
 *   File: cwinsha1main.hxx
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
#ifndef _CWINSHA1MAIN_HXX
#define _CWINSHA1MAIN_HXX

#include "cwincryptohashmaindialog.hxx"
#include "cwindialogmain.hxx"
#include "csha1.hxx"

#define CWINSHA1MAIN_DIALOG_CAPTION "WinSHA1"

/**
 **********************************************************************
 *  Class: cWinSHA1MainDialog
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
class cWinSHA1MainDialog
: public cWinCryptoHashMainDialog
{
public:
    typedef cWinCryptoHashMainDialog cExtends;
    typedef cWinSHA1MainDialog cDerives;

    cSHA1 m_hash;
    BYTE m_hashed[cSHA1::HASHSIZE];
    WCHAR m_hashedText[cSHA1::HASHSIZE*2+1];

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
        const TCHAR* chars = _T(CWINSHA1MAIN_DIALOG_CAPTION);
        return chars;
    }
}; 

/**
 **********************************************************************
 *  Class: cWinSHA1Main
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
class cWinSHA1Main
: public cWinDialogMain
{
public:
    typedef cWinDialogMain cExtends;
    typedef cWinSHA1Main cDerives;

    cWinSHA1MainDialog m_mainDialog;

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
#endif /* _CWINSHA1MAIN_HXX */

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

#include "afxres.h"
#include "resource.h"
#include "cwinmain.hxx"
#include "cwindialog.hxx"
#include "cmd5.hxx"
#include "cwindropfiles.hxx"
#include "cstring.hxx"
#include "cfile.hxx"

#define CCRYPTOHASHMAIN_BUFFER_SIZE 4096

/**
 **********************************************************************
 *  Class: cWinMD5MainDialog
 *
 * Author: $author$
 *   Date: 5/9/2009
 **********************************************************************
 */
class cWinMD5MainDialog
: public cWinDialog
{
public:
    typedef cWinDialog cExtends;
    typedef cWinMD5MainDialog cDerives;

    cString m_fileName;
    cWinDropFiles m_dropFiles;
    cFile m_file;

    cMD5 m_hash;
    BYTE m_hashed[cMD5::HASHSIZE];
    WCHAR m_hashedText[cMD5::HASHSIZE*2+1];

    BYTE m_buffer[CCRYPTOHASHMAIN_BUFFER_SIZE];

    /**
     **********************************************************************
     * Function: On_WM_DROPFILES_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DROPFILES_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        HDROP hDrop;
        TLENGTH count, length;
        const WCHAR* fileNameWChars;
        const CHAR* fileNameChars;
        eError error;

        if ((hDrop = (HDROP)(wParam)))
        if (0 < (count = m_dropFiles.Open(hDrop)))
        {
            if ((fileNameWChars = m_dropFiles.GetFirstFileName(length)))
            if (0 < (length = m_fileName.AssignWChars(fileNameWChars, length)))
            if ((fileNameChars = m_fileName.HasChars(length)))
            if (!(error = m_file.Open(fileNameChars, "rb")))
            {
                if (0 <= (count = m_hash.Initialize()))
                {
                    do
                    {
                        if (0 < (length = m_file.Read
                            ((CHAR*)(m_buffer), (TLENGTH)(sizeof(m_buffer)))))
                        if (0 > (count = m_hash.Hash(m_buffer, length)))
                            break;

                        SendMessage(hWnd, WM_USER, 0, 0);
                    }
                    while (0 < length);
                    m_hash.Finalize(m_hashed, sizeof(m_hashed));
                }
                m_file.Close();
            }
            m_dropFiles.Close();
        }

        cWCHARS::ToX(m_hashedText, m_hashed, sizeof(m_hashed));
        SetDlgItemText(hWnd, IDC_STATIC, m_hashedText);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        PostQuitMessage(0);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_INITDIALOG_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_INITDIALOG_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        HWND hCtl;

        if ((hCtl = GetDlgItem(hWnd, IDOK)))
            ShowWindow(hCtl, SW_HIDE);

        if ((hCtl = GetDlgItem(hWnd, IDCANCEL)))
            ShowWindow(hCtl, SW_HIDE);

        DragAcceptFiles(hWnd, TRUE);
        return lResult;
    }

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
: public cWinMain
{
public:
    typedef cWinMain cExtends;
    typedef cWinMD5Main cDerives;

    cWinDialogWindowClass m_dialogWindowClass;
    cWinMD5MainDialog m_mainDialog;

    /**
     **********************************************************************
     * Constructor: cWinMD5Main
     *
     *      Author: $author$
     *        Date: 5/7/2009
     **********************************************************************
     */
    cWinMD5Main() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMD5Main
     *
     *     Author: $author$
     *       Date: 5/7/2009
     **********************************************************************
     */
    virtual ~cWinMD5Main()
    {
    }

    /**
     **********************************************************************
     * Function: BeforeProcessMessages
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    virtual INT BeforeProcessMessages
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
    {
        INT result = 0;
        eError error;
        HINSTANCE hInstance;
        HWND hWndDesktop;

        if ((hInstance = GetHINSTANCE()))
        if ((hWndDesktop = GetDesktopWindow()))
        if (!(error = m_dialogWindowClass.Register(hInstance)))
        if (!(error = m_mainDialog.Create
            (hInstance, hWndDesktop, IDD_MAIN_DIALOG)))
            ShowWindow(m_mainDialog.m_hWndCreated, SW_SHOWNORMAL);

        return result;
    }
};
#endif /* _CWINMD5MAIN_HXX */

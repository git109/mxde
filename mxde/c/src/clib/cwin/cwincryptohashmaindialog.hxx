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
 *   File: cwincryptohashmaindialog.hxx
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
#ifndef _CWINCRYPTOHASHMAINDIALOG_HXX
#define _CWINCRYPTOHASHMAINDIALOG_HXX

#include "afxres.h"
#include "resource.h"

#include "cwinmaindialog.hxx"
#include "cwindropfiles.hxx"

#include "ccryptohash.hxx"

#include "cfile.hxx"
#include "cstring.hxx"
#include "cbuffer.hxx"
#include "ctchartocharreader.hxx"

#define CWINCRYPTOHASHMAINDIALOG_BUFFER_SIZE (4096<<4)

/**
 **********************************************************************
 *  Class: cWinCryptoHashMainDialog
 *
 * Author: $author$
 *   Date: 5/13/2009
 **********************************************************************
 */
class cWinCryptoHashMainDialog
: public cWinMainDialog
{
public:
    typedef cWinMainDialog cExtends;
    typedef cWinCryptoHashMainDialog cDerives;

    bool m_quit;
    cBYTEFile m_file;
    cString m_fileName;
    cTString m_tFileName;
    cTCHARBuffer m_tBuffer;
    cTCHARToBYTEReader m_t2bReader;
    cTCHARToCHARToBYTEReader m_t2c2bReader;
    cWinDropFiles m_dropFiles;

    TLENGTH m_bufferSize;
    BYTE m_buffer[CWINCRYPTOHASHMAINDIALOG_BUFFER_SIZE];

    /**
     **********************************************************************
     * Constructor: cWinCryptoHashMainDialog
     *
     *      Author: $author$
     *        Date: 5/13/2009
     **********************************************************************
     */
    cWinCryptoHashMainDialog() 
    : m_quit(false),
      m_t2bReader(m_tBuffer),
      m_t2c2bReader(m_tBuffer),
      m_bufferSize(CWINCRYPTOHASHMAINDIALOG_BUFFER_SIZE)
    {
    }

    /**
     **********************************************************************
     * Function: On_WM_INITDIALOG_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_INITDIALOG_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        WCHAR* hashedText = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        cCryptoHashInterface& hash = GetCryptoHash
        (hashedText, hashed, hashedSize);
        int adjustedSize = 0;
        const TCHAR* tChars;
        const CHAR* chars;
        TLENGTH length;
        TSIZE size;
        HWND hCtl;
        RECT d,w;
        HDC hDC;
        TEXTMETRIC tm;

        if ((tChars = GetDialogCaption()))
            SetWindowText(hWnd, tChars);
        
        if ((hCtl = GetDlgItem(hWnd, IDC_EDIT)))
        if (GetClientRect(hCtl, &w))
        if ((hDC = GetDC(hCtl)))
        {
            if ((GetTextMetrics(hDC, &tm)))
            if ((hashedSize = tm.tmAveCharWidth*(hashedSize*2+1)) 
                > (size = w.right - w.left))
                adjustedSize = (int)hashedSize-(int)size;
                
            ReleaseDC(hCtl, hDC);
        }
        
        if ((hCtl = GetDesktopWindow()))
        if (GetClientRect(hCtl, &d))
        if (GetWindowRect(hWnd, &w))
        if ((MoveWindow
            (hWnd, ((d.right-d.left)/2)-w.right+w.left, 
            ((d.bottom-d.top)/2)-w.bottom+w.top,
             w.right-w.left+adjustedSize, w.bottom-w.top, TRUE)))
        if (adjustedSize)
        if (MoveDlgItem(hWnd, IDOK, adjustedSize,0, 0,0, TRUE))
        if (MoveDlgItem(hWnd, IDCANCEL, adjustedSize,0, 0,0, TRUE))
        if (MoveDlgItem(hWnd, IDC_UNICODE, adjustedSize,0, 0,0, TRUE))
        if (MoveDlgItem(hWnd, IDC_STATIC, 0,0, adjustedSize,0, TRUE))
        if (MoveDlgItem(hWnd, IDC_EDIT, 0,0, adjustedSize,0, TRUE))
        if (MoveDlgItem(hWnd, IDC_TEXT, 0,0, adjustedSize,0, TRUE))
        {
        }

        DragAcceptFiles(hWnd, TRUE);

        if ((chars = FirstCmdLineArg(length)) && (0 < length))
        if (0 < (m_tFileName.AssignCHARS(chars, length)))
        if ((tChars = m_tFileName.HasChars(length)))
        if ((SetDlgItemText(hWnd, IDC_EDIT, tChars)))
            PostMessage(hWnd, WM_COMMAND, IDOK, 0);

        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault
        (hWnd,msg,wParam,lParam);
        PostQuitMessage(0);
        m_quit = true;
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_DROPFILES_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DROPFILES_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        TCHAR nullChar = 0;
        HDROP hDrop;
        TLENGTH count, length;
        const TCHAR* fileNameTChars;
        const CHAR* fileNameChars;
        eError error;

        SetForegroundWindow(hWnd);
        SetDlgItemText(hWnd, IDC_STATIC, &nullChar);
        SetDlgItemText(hWnd, IDC_EDIT, &nullChar);
        SetDlgItemText(hWnd, IDC_TEXT, &nullChar);
        
        if ((hDrop = (HDROP)(wParam)))
        if (0 < (count = m_dropFiles.Open(hDrop)))
        {
            if ((fileNameTChars = m_dropFiles.GetFirstFileName(length)))
            if (0 < (length = m_tFileName.AssignTChars(fileNameTChars, length)))
            if (0 < (length = m_fileName.AssignTChars(fileNameTChars, length)))
            if ((fileNameChars = m_fileName.HasChars(length)))
            if (!(error = HashFile(hWnd, fileNameChars)))
            if ((fileNameTChars = m_tFileName.HasChars(length)))
                SetDlgItemText(hWnd, IDC_EDIT, fileNameTChars);

            m_dropFiles.Close();
        }
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_COMMAND_IDC_TRUE_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_IDC_TRUE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        TCHAR nullChar = 0;
        TLENGTH count, length;
        HWND hDlgItem;
        eError error;

        SetDlgItemText(hWnd, IDC_STATIC, &nullChar);

        if ((hDlgItem = GetDlgItem(hWnd, IDC_TEXT)))
        if (0 < (length = GetWindowTextLength(hDlgItem)))
        {
            SetDlgItemText(hWnd, IDC_EDIT, &nullChar);
            
            if (length < (count = m_tBuffer.AdjustToSize(length+1)))
            if (length <= (count = m_tBuffer.SetLength(length)))
            if (0 <= (count = m_tBuffer.Reset()))
                error = HashTextDlgItem(hWnd, hDlgItem);
                
            return lResult;
        }
            
        if ((hDlgItem = GetDlgItem(hWnd, IDC_EDIT)))
        if (0 < (length = GetWindowTextLength(hDlgItem)))
        {
            SetDlgItemText(hWnd, IDC_TEXT, &nullChar);
            
            if (length < (count = m_tBuffer.AdjustToSize(length+1)))
            if (length <= (count = m_tBuffer.SetLength(length)))
            if (0 <= (count = m_tBuffer.Reset()))
                error = HashFileDlgItem(hWnd, hDlgItem);
        }
            
        return lResult;
    }

    /**
     **********************************************************************
     * Function: HashTextDlgItem
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual eError HashTextDlgItem
    (HWND hWnd, HWND hDlgItem) 
    {
        eError error = e_ERROR_FAILED;
        TLENGTH count, length;
        TCHAR* tBufferChars;
        
        if ((tBufferChars = m_tBuffer.WriteBuffer(length)))
        if (0 < (count = GetWindowText(hDlgItem, tBufferChars, length)))
        if ((IsDlgButtonChecked(hWnd, IDC_UNICODE)))
            error = Hash(hWnd, m_t2bReader);
        else
            error = Hash(hWnd, m_t2c2bReader);
            
        return error;
    }
    /**
     **********************************************************************
     * Function: HashFileDlgItem
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual eError HashFileDlgItem
    (HWND hWnd, HWND hDlgItem) 
    {
        eError error = e_ERROR_FAILED;
        TLENGTH count, length;
        TCHAR* tBufferChars;
        const CHAR* fileNameChars;
        
        if ((tBufferChars = m_tBuffer.WriteBuffer(length)))
        if (0 < (count = GetWindowText(hDlgItem, tBufferChars, length)))
        if (0 < (length = m_fileName.AssignTChars(tBufferChars, length)))
        if ((fileNameChars = m_fileName.HasChars(length)))
            error = HashFile(hWnd, fileNameChars);
            
        return error;
    }
    
    /**
     **********************************************************************
     * Function: HashFile
     *
     *   Author: $author$
     *     Date: 5/13/2009
     **********************************************************************
     */
    virtual eError HashFile
    (HWND hWnd, const CHAR* fileNameChars) 
    {
        eError error;

        if (!(error = m_file.Open(fileNameChars, "rb")))
        {
            error = Hash(hWnd, m_file);
            m_file.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual eError Hash
    (HWND hWnd, cBYTEReaderInterface& reader) 
    {
        WCHAR* hashedText = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        cCryptoHashInterface& hash = GetCryptoHash
        (hashedText, hashed, hashedSize);
        eError error = e_ERROR_NONE;
        TLENGTH count, length;
        MSG msg;

        if (0 <= (count = hash.Initialize()))
        {
            do
            {
                if (0 < (length = reader.Read(m_buffer, m_bufferSize)))
                if (0 > (count = hash.Hash(m_buffer, length)))
                    break;

                //SendMessage(hWnd, WM_USER, 0, 0);
                if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                    DispatchMessage(&msg);
                    
                if (m_quit)
                    return error;
            }
            while (0 < length);

            if (0 < (count = hash.Finalize(hashed, hashedSize)))
            {
                cWCHARS::ToX(hashedText, hashed, count);
                SetDlgItemText(hWnd, IDC_STATIC, hashedText);
            }
        }
        return error;
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
     TSIZE& hashedSize) const = 0;

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
        const TCHAR* chars = 0;
        return chars;
    }
};
#endif /* _CWINCRYPTOHASHMAINDIALOG_HXX */

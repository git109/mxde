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
 *   File: cwindialog.hxx
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
#ifndef _CWINDIALOG_HXX
#define _CWINDIALOG_HXX

#include "cwinwindow.hxx"
#include "cwindialogwindowclass.hxx"

/**
 **********************************************************************
 *  Class: cWinDialog
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDialog
: public cWinWindow
{
public:
    typedef cWinWindow cExtends;
    typedef cWinDialog cDerives;

    HINSTANCE m_hInstance;
    HWND m_hWndCreated;
    bool m_isModal;

    /**
     **********************************************************************
     * Constructor: cWinDialog
     *
     *      Author: $author$
     *        Date: 5/7/2009
     **********************************************************************
     */
    cWinDialog
    (bool isModal=false,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(attached, isCreated), 
      m_hInstance(hInstance),
      m_hWndCreated(NULL),
      m_isModal(isModal)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDialog
     *
     *     Author: $author$
     *       Date: 5/7/2009
     **********************************************************************
     */
    virtual ~cWinDialog()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance,
     HWND hWndParent,
     INT id) 
    {
        eError error = e_ERROR_FAILED;

        if ((m_hWndCreated = CreateDialogParam
            (hInstance, MAKEINTRESOURCE(id), 
             hWndParent, DialogProc, (LPARAM)(this))))
             error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: DialogProc
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    static BOOL CALLBACK DialogProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL result = FALSE;
        cWinDialog* winDialog;

        if ((winDialog = WinDialog(hWnd, msg, wParam, lParam)))
        {
            winDialog->OnWindowMessage(hWnd, msg, wParam, lParam);
            return result;
        }

        switch(msg)
        {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
            case IDOK:
            case IDYES:
            case IDRETRY:
            case IDIGNORE:
            case IDNO:
            case IDABORT:
            case IDCANCEL:
                DestroyWindow(hWnd);
                break;
            }
            break;
        }
        return result;
    }

    /**
     **********************************************************************
     * Function: ModalDialogProc
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    static BOOL CALLBACK ModalDialogProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL result = FALSE;

        switch(msg)
        {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
            case IDOK:
            case IDYES:
            case IDRETRY:
            case IDIGNORE:
                EndDialog(hWnd, TRUE);
                break;

            case IDNO:
            case IDABORT:
            case IDCANCEL:
                EndDialog(hWnd, FALSE);
                break;
            }
            break;
        }
        return result;
    }

    /**
     **********************************************************************
     * Function: WinDialog
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    static cWinDialog* WinDialog
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
#if !defined(WINDOWS_WCE) 
        int wndExtra = GetClassLong(hWnd, GCL_CBWNDEXTRA);

        if (wndExtra < cWinDialogWindowClass::WindowExtra())
            return 0;
#endif /* !defined(WINDOWS_WCE) */

        int wndExtraOffset = cWinDialogWindowClass::WindowExtraOffset();

        cWinDialog* winDialog = (cWinDialog*)
        (GetWindowLongPtr(hWnd, wndExtraOffset));

        switch(msg)
        {
        case WM_INITDIALOG:
            SetWindowLongPtr(hWnd, wndExtraOffset, lParam);

            if ((winDialog = (cWinDialog*)(lParam)))
                winDialog->Attach(hWnd);
            break;

#if defined(WINDOWS_WCE) 
/* Windows CE
 */
        case WM_DESTROY:
#else /* defined(WINDOWS_WCE) */
/* Otherwise
 */
        case WM_NCDESTROY:
#endif /* defined(WINDOWS_WCE) */
            SetWindowLongPtr(hWnd, wndExtraOffset, 0);
            break;
        }
        return winDialog;
    }

    /**
     **********************************************************************
     * Function: On_WM_COMMAND_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        switch(LOWORD(wParam))
        {
        case IDOK:
        case IDYES:
        case IDRETRY:
        case IDIGNORE:
        case IDHELP:
            lResult = On_WM_COMMAND_IDC_TRUE_WindowMessage
            (hWnd, msg, wParam, lParam);
            break;

        case IDNO:
        case IDABORT:
        case IDCANCEL:
        case IDCLOSE:
            lResult = On_WM_COMMAND_IDC_FALSE_WindowMessage
            (hWnd, msg, wParam, lParam);
            break;
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
        CloseDialog(hWnd, TRUE);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_COMMAND_IDC_FALSE_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_IDC_FALSE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        CloseDialog(hWnd, FALSE);
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
        return lResult;
    }

    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        switch(msg)
        {
        case WM_INITDIALOG:
            lResult = On_WM_INITDIALOG_WindowMessage
            (hWnd, msg, wParam, lParam);
            break;
        }
        return lResult;
    }

    /**
     **********************************************************************
     * Function: CloseDialog
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual void CloseDialog
    (HWND hWnd,
     int result) 
    {
        if (m_isModal)
            EndDialog(hWnd, result);
        else
        DestroyWindow(hWnd);
    }
};
#endif /* _CWINDIALOG_HXX */

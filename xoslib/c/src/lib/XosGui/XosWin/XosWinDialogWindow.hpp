///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosWinDialogWindow.hpp
///
/// Author: $author$
///   Date: 1/29/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINDIALOGWINDOW_HPP
#define _XOSWINDIALOGWINDOW_HPP

#include "XosWinDialogWindowClass.hpp"
#include "XosWinWindow.hpp"
#include "XosArray.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinDialogWindowExtend
///
///  Author: $author$
///    Date: 1/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindow
XosWinDialogWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinDialogWindow
///
/// Author: $author$
///   Date: 1/29/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinDialogWindow
: public XosWinDialogWindowExtend
{
public:
    typedef XosWinDialogWindowExtend Extends;

    HINSTANCE m_hInstance;
    HWND m_hWndCreated;
    bool m_isModal;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinDialogWindow
    ///
    ///       Author: $author$
    ///         Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinDialogWindow
    (bool isModal=false,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : Extends(hInstance, attached, isCreated), 
      m_hInstance(hInstance),
      m_hWndCreated(NULL),
      m_isModal(isModal)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinDialogWindow
    ///
    ///      Author: $author$
    ///        Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinDialogWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (HINSTANCE hInstance,
     HWND hWndParent,
     INT id)
    {
        XosError error = XOS_ERROR_FAILED;

        if ((m_hWndCreated = CreateDialogParam
            (hInstance, MAKEINTRESOURCE(id), 
             hWndParent, DialogProc, (LPARAM)(this))))
             error = XOS_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy(bool onlyCreated=false)
    {
        XosError error = XOS_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: On_WM_INITDIALOG_WindowMessage
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_INITDIALOG_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = FALSE;
        return lResult;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: On_WM_COMMAND_IDC_TRUE_WindowMessage
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
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
    ///////////////////////////////////////////////////////////////////////
    ///  Function: On_WM_COMMAND_IDC_FALSE_WindowMessage
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////
    ///  Function: On_WM_COMMAND_WindowMessage
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnWindowMessageDefault
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////
    ///  Function: CloseDialog
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void CloseDialog
    (HWND hWnd,
     int result) 
    {
        if (m_isModal)
            EndDialog(hWnd, result);
        else
        DestroyWindow(hWnd);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetIsButtonChecked
    ///
    ///    Author: $author$
    ///      Date: 5/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL SetIsButtonChecked
    (int nIDItem, bool isTrue=true)
    {
        if ((m_attached))
            return CheckDlgButton
            (m_attached, nIDItem, (isTrue)?(BST_CHECKED):(BST_UNCHECKED));
        return FALSE;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetIsButtonChecked
    ///
    ///    Author: $author$
    ///      Date: 5/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsButtonChecked(int nIDItem) const
    {
        if ((m_attached))
            return (BST_CHECKED == (IsDlgButtonChecked(m_attached, nIDItem)));
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetItemInt
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual INT GetItemInt
    (int nIDItem) const
    {
        INT value = 0;
        UINT uvalue = 0;
        BOOL success = FALSE;

        if ((m_attached))
        {
            uvalue = GetDlgItemInt(m_attached, nIDItem, &success, TRUE);
            if ((success))
                value = (INT)(uvalue);
        }
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetItemUInt
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual UINT GetItemUInt
    (int nIDItem) const
    {
        UINT value = 0;
        UINT uvalue = 0;
        BOOL success = FALSE;

        if ((m_attached))
        {
            uvalue = GetDlgItemInt(m_attached, nIDItem, &success, FALSE);
            if ((success))
                value = (uvalue);
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetItemText
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL SetItemText
    (int nIDItem, int toValue)
    {
        XosString toText(toValue);
        BOOL isSuccess = SetItemText(nIDItem, toText.c_str());
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetItemText
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL SetItemText
    (int nIDItem, const std::string& toText)
    {
        BOOL isSuccess = SetItemText(nIDItem, toText.c_str());
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetItemText
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosTString GetItemText
    (int nIDItem) const
    {
        XosTString text;
        XosTCHARArray tarray;
        TCHAR* tchars;
        ssize_t tcharsSize;
        ssize_t tcharsLength;
        UINT length;

        if ((m_attached))
        if ((tchars = tarray.Elements(tcharsSize, tcharsLength)))
        if (0 < (length = GetDlgItemText(m_attached, nIDItem, tchars,tcharsSize)))
            text.append(tchars, length);
        return text;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetItemTextW
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosWString GetItemTextW
    (int nIDItem) const
    {
        XosWString text;
        text.append(GetItemText(nIDItem).c_str());
        return text;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetItemTextA
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosString GetItemTextA
    (int nIDItem) const
    {
        XosString text;
        text.append(GetItemText(nIDItem).c_str());
        return text;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetItemText
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL SetItemText
    (int nIDItem, const WCHAR* toChars, ssize_t toLength=-1)
    {
        BOOL isSuccess = FALSE;
        const TCHAR* chars;
        XosTString text;
        if ((m_attached) && (toChars))
        {
            text.assign(toChars, toLength);
            if ((chars = text.c_str()))
                isSuccess = SetDlgItemText(m_attached, nIDItem, chars);
        }
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetItemText
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL SetItemText
    (int nIDItem, const CHAR* toChars, ssize_t toLength=-1)
    {
        BOOL isSuccess = FALSE;
        const TCHAR* chars;
        XosTString text;
        if ((m_attached) && (toChars))
        {
            text.assign(toChars, toLength);
            if ((chars = text.c_str()))
                isSuccess = SetDlgItemText(m_attached, nIDItem, chars);
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: MoveDlgItem
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    static BOOL MoveDlgItem
    (HWND hDlg, int nIDDlgItem,
     int xOffset, int yOffset,
     int widthOffset, int heightOffset, 
     BOOL bRepaint=FALSE) 
    {
        BOOL result = FALSE;
        HWND hCtl;
        RECT d,w;
        POINT left, right;
        
        if (GetClientRect(hDlg, &d))
        {
            left.x = d.left;
            left.y = d.top;
            right.x = d.right;
            right.y = d.bottom;
            
            if ((ClientToScreen(hDlg, &left)))
            if ((ClientToScreen(hDlg, &right)))
            if ((hCtl = GetDlgItem(hDlg, nIDDlgItem)))
            if (GetWindowRect(hCtl, &w))
                result = MoveWindow
                (hCtl, w.left-left.x+xOffset, w.top-left.y+yOffset, 
                 w.right-w.left+widthOffset, w.bottom-w.top+heightOffset, bRepaint);
        }
        return result;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ModalDialogProc
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
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
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DialogProc
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    static BOOL CALLBACK DialogProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL result = FALSE;
        XosWinDialogWindow* dialogWindow;

        if ((dialogWindow = DialogWindow(hWnd, msg, wParam, lParam)))
        {
            dialogWindow->OnWindowMessage(hWnd, msg, wParam, lParam);
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
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DialogWindow
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    static XosWinDialogWindow* DialogWindow
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        int wndExtra = GetClassLong(hWnd, GCL_CBWNDEXTRA);

        if (wndExtra < XosWinDialogWindowClass::WindowExtra())
            return 0;

        int wndExtraOffset = XosWinDialogWindowClass::WindowExtraOffset();

        XosWinDialogWindow* dialogWindow = (XosWinDialogWindow*)
        (GetWindowLongPtr(hWnd, wndExtraOffset));

        switch(msg)
        {
        case WM_INITDIALOG:
            SetWindowLongPtr(hWnd, wndExtraOffset, lParam);

            if ((dialogWindow = (XosWinDialogWindow*)(lParam)))
                dialogWindow->Attach(hWnd);
            break;

        case WM_DESTROY:
            SetWindowLongPtr(hWnd, wndExtraOffset, 0);
            break;
        }
        return dialogWindow;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINDIALOGWINDOW_HPP 
        


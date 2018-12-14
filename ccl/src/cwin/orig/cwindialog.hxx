/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cwindialog.hxx
 *
 * Author: $author$
 *   Date: 4/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINDIALOG_HXX
#define _CWINDIALOG_HXX

#include "cwinwindow.hxx"
#include "cwinobject.hxx"

/**
 **********************************************************************
 *  Class: cWinDialog
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cWinDialog
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    /**
     **********************************************************************
     *  Class: cWindowClass
     *
     * Author: $author$
     *   Date: 4/9/2004
     **********************************************************************
     */
    class cWindowClass
    : public cWinWindowClass
    {
    public:
        typedef cWinWindowClass cIs;

        /**
         **********************************************************************
         * Constructor: cWindowClass
         *
         *      Author: $author$
         *        Date: 4/9/2004
         **********************************************************************
         */
        cWindowClass(LPCTSTR classname=_T("cWinDialog"))
        {
            eError error;
            int length;

            if (0 > (length = SetClassName(classname)))
                throw(error = -length);
        }
        /**
         **********************************************************************
         * Function: Register
         *
         *   Author: $author$
         *     Date: 4/9/2004
         **********************************************************************
         */
        virtual eError Register
        (HINSTANCE instance, LPCTSTR menuname=NULL, 
         HICON icon=NULL, HICON iconsm=NULL,
         HCURSOR cursor=NULL, HBRUSH background=NULL, 
         UINT style=0, int clsextra=0)
        {
            LPCSTR classname;
            
            if ((classname=GetClassName()))
                return cIs::Register
                (classname, instance, DefDlgProc,
                 menuname, icon, iconsm, cursor, background,
                 style, WndExtraSize(), clsextra);

            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: WndExtraOffset
         *
         *   Author: $author$
         *     Date: 4/9/2004
         **********************************************************************
         */
        static int WndExtraOffset()
        {
            return DLGWINDOWEXTRA;
        }
        /**
         **********************************************************************
         * Function: WndExtraSize
         *
         *   Author: $author$
         *     Date: 4/9/2004
         **********************************************************************
         */
        static int WndExtraSize()
        {
            return WndExtraOffset()+sizeof(long);
        }
    };

    bool m_is_modal;

    /**
     **********************************************************************
     * Constructor: cWinDialog
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cWinDialog
    (bool is_modal=false, HINSTANCE instance=NULL, HWND handle=NULL) 
    : cIs(instance, handle),
      m_is_modal(is_modal)
    {
    }

    /**
     **********************************************************************
     * Function: ModalDialogProc
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    static BOOL CALLBACK ModalDialogProc
    (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        cWinDialog *dialog;

        if ((dialog = GetWinDialog
            (handle, message, wparam, lparam)))
            return dialog->OnDialogProc
            (message, wparam, lparam);
        else
        {
            switch(message)
            {
            case WM_COMMAND:
                switch(LOWORD(wparam))
                {
                case IDOK:
                case IDYES:
                case IDRETRY:
                case IDIGNORE:
                    EndDialog(handle,1);
                    break;

                case IDNO:
                case IDABORT:
                case IDCANCEL:
                    EndDialog(handle,0);
                    break;
                }
                break;
            }
        }
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: GetWinDialog
     *
     *   Author: $author$
     *     Date: 4/10/2004
     **********************************************************************
     */
    static cWinDialog *GetWinDialog
    (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        LONG wndextra=GetClassLong(handle,GCL_CBWNDEXTRA);

        if (wndextra >= cWindowClass::WndExtraSize())
        {
            cWinDialog *dialog=(cWinDialog*)GetWindowLong
            (handle, cWindowClass::WndExtraOffset());

            switch(message)
            {
            case WM_INITDIALOG:
                SetWindowLong
                (handle, cWindowClass::WndExtraOffset(), lparam);

                if ((dialog = (cWinDialog*)lparam))
                    dialog->Attach(handle);
                break;

            case WM_NCDESTROY:
                SetWindowLong
                (handle, cWindowClass::WndExtraOffset(), 0);
                break;
            }
            return dialog;
        }
        return 0;
    }

    /**
     **********************************************************************
     * Function: OnDialogProc
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    virtual BOOL OnDialogProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        switch(message)
        {
        case WM_INITDIALOG:
            return OnWMInitDialog(wparam, lparam);

        case WM_COMMAND:
            switch(LOWORD(wparam))
            {
            case IDOK:
            case IDYES:
            case IDRETRY:
            case IDIGNORE:
                return OnDialogOK(wparam, lparam);

            case IDNO:
            case IDABORT:
            case IDCANCEL:
                return OnDialogCancel(wparam, lparam);
            }
            break;
        }
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: OnWMInitDialog
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    virtual BOOL OnWMInitDialog(WPARAM wparam, LPARAM lparam)
    {
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnDialogOk
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual BOOL OnDialogOK(WPARAM wparam, LPARAM lparam)
    {
        if (m_is_modal)
            End(1);
        else Destroy();
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnDialogCancel
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual BOOL OnDialogCancel(WPARAM wparam, LPARAM lparam)
    {
        if (m_is_modal)
            End(0);
        else Destroy();
        return TRUE;
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 4/10/2004
     **********************************************************************
     */
    virtual int Modal
    (HINSTANCE instance, HWND window, int id)
    {
        int result;
        HINSTANCE old_instance=m_instance;

        m_instance = instance;
        m_is_modal = true;

        if (0 > (result = DialogBoxParam
            (instance, MAKEINTRESOURCE(id), 
             window, ModalDialogProc, (LPARAM)this)))
             result = -e_ERROR_FAILED;

        m_is_modal = false;
        m_instance = old_instance;

        return result;
    }
    /**
     **********************************************************************
     * Function: End
     *
     *   Author: $author$
     *     Date: 4/10/2004
     **********************************************************************
     */
    virtual eError End(int result)
    {
        eError error=e_ERROR_NOT_ATTACHED;

        if (NULL != m_handle)
            if (EndDialog(m_handle, result))
                error = e_ERROR_NONE;
            else error = e_ERROR_FAILED;

        return error;
    }
};

#endif /* ndef _CWINDIALOG_HXX */

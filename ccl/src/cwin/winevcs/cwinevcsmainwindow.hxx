/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cwinevcsmainwindow.hxx
 *
 * Author: $author$
 *   Date: 6/7/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINEVCSMAINWINDOW_HXX
#define _CWINEVCSMAINWINDOW_HXX

#include "cwinevcsexplorerviewwindow.hxx"
#include "cwinevcsviewwindow.hxx"
#include "cwinevcsclientwindow.hxx"
#include "cwinevcsdialog.hxx"
#include "cwinevcsmain.hxx"
#include "cwinmdiframewindow.hxx"
#include "cwinobject.hxx"

#include "cfilesystementryinterface.hxx"

/**
 **********************************************************************
 *  Class: cWinEvcsMainWindow
 *
 * Author: $author$
 *   Date: 6/5/2007
 **********************************************************************
 */
class cWinEvcsMainWindow
: public cWinMDIFrameWindow
{
public:
    typedef cWinMDIFrameWindow cExtends;
    typedef cWinEvcsMainWindow cDerives;

    cWinEvcsMainInterface &m_winevcs;
    cWinWindowClass &m_window_class;
    cWinWindowClass &m_child_window_class;

    cWinEvcsClientWindow m_client_window;

    cFileSystemEntryInterface* m_file_system_entry;

    /**
     **********************************************************************
     * Constructor: cWinEvcsMainWindow
     *
     *      Author: $author$
     *        Date: 6/5/2007
     **********************************************************************
     */
    cWinEvcsMainWindow
    (cWinEvcsMainInterface &winevcs, 
     cWinWindowClass &window_class,
     cWinWindowClass &child_window_class)
    : m_winevcs(winevcs),
      m_window_class(window_class),
      m_child_window_class(child_window_class),
      m_file_system_entry(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsMainWindow
     *
     *      Author: $author$
     *        Date: 6/5/2007
     **********************************************************************
     */
    virtual ~cWinEvcsMainWindow()
    {
    }

    /**
     **********************************************************************
     * Function: GetClientWindow
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cWinMDIClientWindow& GetClientWindow() const 
    {
        return (cWinMDIClientWindow&)(m_client_window);
    }

    /**
     **********************************************************************
     * Function: OnFileExit
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual void OnFileExit()
    {
        PostMessage(WM_CLOSE, 0, 0);
    }
    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual void OnFileOpen
    (LPCTSTR filename=NULL, int length=-1)
    {
        eError error;
        cGetOpenFileNameDialog ofn_dialog;
        cFileSystemEntryInterface::eType type;

        if (!m_file_system_entry)
            m_file_system_entry 
            = cFileSystemEntryInterface::NewInstance(error);

        if (m_file_system_entry)
        if (cFileSystemEntryInterface::e_TYPE_DIRECTORY
            == (type = m_file_system_entry->Exists(filename, length)))
        {
            OnFileOpenDirectory(filename, length);
            return;
        }

        if (!(error = ofn_dialog.Modal
            (GetInstance(),GetHandle(), filename, length)))
        if ((filename = ofn_dialog.GetFileName(length)))
        if (0 < length)
           OnFileOpenFile(filename, length);
    }
    /**
     **********************************************************************
     * Function: OnFileOpenDirectory
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual void OnFileOpenDirectory
    (LPCTSTR filename=NULL, int length=-1)
    {
        eError error;
        cWinEvcsExplorerViewWindow* window;

        if ((window = NewExplorerViewWindow()))
        {
            if ((error = window->Create
                (GetInstance(), 
                 m_child_window_class.GetClassName(), 
                 m_client_window.GetHandle(), filename)))
                 DeleteExplorerViewWindow(*window);
            else window->OnOpenDirectory(filename);
        }
    }
    /**
     **********************************************************************
     * Function: OnFileOpenFile
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual void OnFileOpenFile
    (LPCTSTR filename=NULL, int length=-1)
    {
        eError error;
        cWinEvcsViewWindow* window;

        if ((window = NewViewWindow()))
        {
            if ((error = window->Create
                (GetInstance(), 
                 m_child_window_class.GetClassName(), 
                 m_client_window.GetHandle(), filename)))
                 DeleteViewWindow(*window);
        }
    }

    /**
     **********************************************************************
     * Function: OnHelpAbout
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual void OnHelpAbout()
    {
        cWinEvcsHelpDialog help_dialog;

        help_dialog.Modal
        (GetInstance(), GetHandle(), IDR_MAIN_WINDOW);
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        DragAcceptFiles(m_handle, TRUE);
        return cExtends::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMCommand
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnWMCommand(WPARAM wparam, LPARAM lparam)
    {
        WORD id;

        switch(id = LOWORD(wparam))
        {
        case ID_APP_EXIT:
            OnFileExit();
            break;

        case ID_APP_ABOUT:
            OnHelpAbout();
            break;
        }
        return cExtends::OnWMCommand(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDropFiles
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnWMDropFiles(WPARAM wparam, LPARAM lparam)
    {
        eError error;
        int length;
        LPCTSTR filename;
        cWinDropFiles::cItem *item;
        cWinDropFiles drop_files;

        if (!(error = drop_files.Open((HDROP)wparam)))
        {
            SetPosTop();

            if ((item = drop_files.GetFirstItem()))
            do
            {
                if ((filename = item->GetName(length)))
                    OnFileOpen(filename, length);
            }
            while ((item = drop_files.GetNextItem(*item)));

            drop_files.Close();
            return 0;
        }

        return 1;
    }

    /**
     **********************************************************************
     * Function: OnDefWindowProc
     *
     *   Author: $author$
     *     Date: 6/5/2007
     **********************************************************************
     */
    virtual LRESULT xOnDefWindowProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        HWND handle = 0;

        if ((handle = m_client_window.m_handle))
            return DefFrameProc
            (m_handle, handle, message, wparam, lparam);

        return DefWindowProc
        (m_handle, message, wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: NewExplorerViewWindow
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cWinEvcsExplorerViewWindow* NewExplorerViewWindow() 
    {
        cWinEvcsExplorerViewWindow* 
            window = new cWinEvcsExplorerViewWindow(m_winevcs);
        return window;
    }
    /**
     **********************************************************************
     * Function: DeleteExplorerViewWindow
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteExplorerViewWindow
    (cWinEvcsExplorerViewWindow& window) 
    {
        eError error = e_ERROR_NONE;
        delete &window;
        return error;
    }

    /**
     **********************************************************************
     * Function: NewViewWindow
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cWinEvcsViewWindow* NewViewWindow() 
    {
        cWinEvcsViewWindow* window = new cWinEvcsViewWindow();
        return window;
    }
    /**
     **********************************************************************
     * Function: DeleteViewWindow
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteViewWindow
    (cWinEvcsViewWindow& window) 
    {
        eError error = e_ERROR_NONE;
        delete &window;
        return error;
    }
};

#endif /* _CWINEVCSMAINWINDOW_HXX */

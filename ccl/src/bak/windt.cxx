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
 *   File: windt.cxx
 *
 * Author: $author$
 *   Date: 5/18/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "resource.h"
#include "cxmldocument.hxx"
#include "cdocumentinterface.hxx"
#include "cwinlistviewwindow.hxx"
#include "cwinlistview.hxx"
#include "cwintreeviewwindow.hxx"
#include "cwincontrolwindow.hxx"
#include "cwincommoncontrol.hxx"
#include "cwinwindow.hxx"
#include "cwinobject.hxx"
#include "cwinmaint.hxx"

/**
 **********************************************************************
 *  Class: cWinDTInterface
 *
 * Author: $author$
 *   Date: 5/19/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinDTInterface
{
public:
    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual eError OnFileOpen
    (LPCTSTR filename=NULL, int length=-1) = 0;

    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual cDocumentInterface *GetDocument() const = 0;
};

/**
 **********************************************************************
 *  Class: cWinDTTreeViewWindow
 *
 * Author: $author$
 *   Date: 5/18/2004
 **********************************************************************
 */
class cWinDTTreeViewWindow
: public cWinTreeViewWindow
{
public:
    typedef cWinTreeViewWindow cIs;

    cWinDTInterface &m_windt;
    cWinListViewWindow &m_list_view;

    /**
     **********************************************************************
     * Constructor: cWinDTTreeViewWindow
     *
     *      Author: $author$
     *        Date: 5/18/2004
     **********************************************************************
     */
    cWinDTTreeViewWindow
    (cWinDTInterface &windt, cWinListViewWindow &list_view)
    : m_windt(windt), m_list_view(list_view)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDTTreeViewWindow
     *
     *     Author: $author$
     *       Date: 5/18/2004
     **********************************************************************
     */
    virtual ~cWinDTTreeViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 5/18/2004
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;

        if (!(error = m_image_list.LoadBitmap
            (m_instance, IDR_MAIN_WINDOW, 20)))
            m_tree_control.SetImageList(m_image_list);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnSelChanged
     *
     *   Author: $author$
     *     Date: 5/25/2004
     **********************************************************************
     */
    virtual LRESULT OnSelChanged(NMTREEVIEW &notify, WPARAM wparam, LPARAM lparam)
    {
        TVITEM &tvitem=notify.itemNew;
        cWinTreeViewItem item(tvitem);
        cWinListView &list_control=m_list_view.GetListControl();
        cElementInterface *element;
        cAttributeInterface *attribute;

        list_control.DeleteAllItems();

        if ((element = (cElementInterface*)item.GetParam()))
        if ((attribute = element->GetFirstAttribute()))
        do
        {
            int namelen, textlen;
            const char *name=attribute->GetName(namelen);
            const char *text=attribute->GetText(textlen);
            LPTSTR name_text;
            cTCHARBuffer name_buffer;
            cWinListViewItem item;

            if (name && (0 < namelen))
            if (0 < (namelen = name_buffer.Write(name, namelen)))
            if ((name_text = name_buffer.GetWriteBuffer(namelen)))
                item.SetText(name_text, namelen);

            if (0 < namelen)
                list_control.InsertItem(item);

            item.SetSubItem(1);

            if (text && (0 < textlen))
            if (0 < (textlen = name_buffer.Copy(text, textlen)))
            if ((name_text = name_buffer.GetWriteBuffer(textlen)))
                item.SetText(name_text, textlen);

            if (0 < textlen)
                list_control.SetItem(item);
        }
        while ((attribute = attribute->GetNextAttribute()));
        return cIs::OnSelChanged(notify, wparam, lparam);
    }
};

/**
 **********************************************************************
 *  Class: cWinDTListViewWindow
 *
 * Author: $author$
 *   Date: 5/23/2004
 **********************************************************************
 */
class cWinDTListViewWindow
: public cWinListViewWindow
{
public:
    typedef cWinListViewWindow cIs;

    cWinDTInterface &m_windt;
    cWinTreeViewWindow &m_tree_view;

    /**
     **********************************************************************
     * Constructor: cWinDTListViewWindow
     *
     *      Author: $author$
     *        Date: 5/23/2004
     **********************************************************************
     */
    cWinDTListViewWindow
    (cWinDTInterface &windt, cWinTreeViewWindow &tree_view)
    : m_windt(windt), m_tree_view(tree_view)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDTListViewWindow
     *
     *     Author: $author$
     *       Date: 5/23/2004
     **********************************************************************
     */
    virtual ~cWinDTListViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;
        cWinClientRect client_rect(m_control);
        cWinListViewColumn column;

        column.SetWidth((client_rect.right-client_rect.left+1)/2);
        column.SetText("Name");
        m_list_control.InsertColumn(0,column);

        column.SetText("Text");
        m_list_control.InsertColumn(1,column);

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinDTMainWindow
 *
 * Author: $author$
 *   Date: 5/18/2004
 **********************************************************************
 */
class cWinDTMainWindow
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    cWinDTInterface &m_windt;
    cWinDTTreeViewWindow m_tree_view;
    cWinDTListViewWindow m_list_view;
    int m_tree_view_width, m_tree_view_height;
    int m_list_view_width, m_list_view_height;

    /**
     **********************************************************************
     * Constructor: cWinDTMainWindow
     *
     *      Author: $author$
     *        Date: 5/18/2004
     **********************************************************************
     */
    cWinDTMainWindow(cWinDTInterface &windt) 
    : m_windt(windt),
      m_tree_view(windt, m_list_view),
      m_list_view(windt, m_tree_view),
      m_tree_view_width(100),
      m_tree_view_height(100),
      m_list_view_width(100),
      m_list_view_height(100)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDTMainWindow
     *
     *     Author: $author$
     *       Date: 5/18/2004
     **********************************************************************
     */
    virtual ~cWinDTMainWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual void OnFileOpen
    (LPCTSTR filename=NULL, int length=-1)
    {
        eError error;
        cGetOpenFileNameDialog ofn_dialog;

        if (!(error = ofn_dialog.Modal
            (GetInstance(),GetHandle(), filename, length)))
        if ((filename = ofn_dialog.GetFileName(length)))
        if (0 < length)
        {
            m_windt.OnFileOpen(filename, length);
            OnFileOpened();
        }
    }
    /**
     **********************************************************************
     * Function: AddTreeItems
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual void AddTreeItems
    (cWinTreeView &tree_control, 
     cElementSetInterface &element_set, 
     HTREEITEM parent_item=NULL)
    {
        cElementInterface *element;

        if ((element = element_set.GetFirstElement()))
        {
            do
            {
                cWinTreeViewItem tree_item;
                cTCHARBuffer text_buffer;
                int textlen;
                TCHAR *text;
                int element_type;
                int element_textlen;
                const char *element_text;

                switch(element_type = element->GetType())
                {
                case cElementInterface::e_TYPE_PARENT_ELEMENT:
                    tree_item.SetImage(1);
                    tree_item.SetSelectedImage(1);
                    break;
                }

                tree_item.SetParam((LPARAM)element);

                if ((element_text = element->GetText(element_textlen)))
                if (0 < element_textlen)
                    text_buffer.Write(element_text, element_textlen);

                if ((text = text_buffer.GetWriteBuffer(textlen)))
                if (0 < textlen)
                    tree_item.SetText(text, textlen);

                {
                    cWinTreeViewInsert tree_insert(tree_item, parent_item);
                    HTREEITEM new_item;

                    if (NULL != (new_item = tree_control.InsertItem(tree_insert)))
                        AddTreeItems(tree_control, *element, new_item);
                }
            }
            while ((element = element->GetNextElement()));
        }
    }
    /**
     **********************************************************************
     * Function: OnFileOpened
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual void OnFileOpened()
    {
        if (m_tree_view.GetIsCreated())
        {
            cWinTreeView &tree_control=m_tree_view.GetTreeControl();
            cDocumentInterface *document;

            tree_control.DeleteAllItems();

            if ((document = m_windt.GetDocument()))
                AddTreeItems(tree_control, *document);
        }
    }

    /**
     **********************************************************************
     * Function: OnWMDropFiles
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDropFiles(WPARAM wparam, LPARAM lparam)
    {
        eError error;
        int length;
        LPCTSTR filename;
        cWinDropFiles::cItem *item;
        cWinDropFiles drop_files;

        if (!(error = drop_files.Open((HDROP)wparam, 1)))
        {
            if ((item = drop_files.GetFirstItem()))
            if ((filename = item->GetName(length)))
                OnFileOpen(filename, length);

            drop_files.Close();
            return 0;
        }

        return cIs::OnWMDropFiles(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/18/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        cWinClientRect client_rect(m_handle);
        int client_width = client_rect.right-client_rect.left+1;
        int client_height = client_rect.bottom-client_rect.top+1;

        m_tree_view_width = client_width/3;
        m_tree_view_height = client_height;

        m_tree_view.Create
	    (m_tree_view.GetWindowClassName(),
         m_instance, NULL, m_handle, NULL, 
         WS_CHILD | WS_VISIBLE, 0, 0,0, 
         m_tree_view_width, m_tree_view_height);

        m_list_view_width = client_width-m_tree_view_width;
        m_list_view_height = client_height;

        m_list_view.Create
	    (m_list_view.GetWindowClassName(),
         m_instance, NULL, m_handle, NULL, 
         WS_CHILD | WS_VISIBLE, 0, m_tree_view_width,0, 
         m_list_view_width, m_list_view_height);

        DragAcceptFiles(m_handle, TRUE);

        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/18/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        if (m_list_view.GetIsCreated())
            m_list_view.Destroy();

        if (m_tree_view.GetIsCreated())
            m_tree_view.Destroy();

        return cIs::OnWMDestroy(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnWMSize
     *
     *   Author: $author$
     *     Date: 5/18/2004
     **********************************************************************
     */
    virtual LRESULT OnWMSize(WPARAM wparam, LPARAM lparam)
    {
        if (SIZE_MINIMIZED != wparam)
        {
            if (m_tree_view.GetIsCreated())
            {
                int width=LOWORD(lparam), height=HIWORD(lparam);
                int left=0, top=0;

                if (width > m_tree_view_width)
                    width = m_tree_view_width;

                MoveWindow
                (m_tree_view, left,top, width,height, TRUE);
            }

            if (m_list_view.GetIsCreated())
            {
                int width=LOWORD(lparam), height=HIWORD(lparam);
                int left=m_tree_view_width, top=0;

                if (width > m_tree_view_width)
                {
                    width -= m_tree_view_width;

                    MoveWindow
                    (m_list_view, left,top, width,height, TRUE);
                }
            }
        }
        return cIs::OnWMSize(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: GetWindowClassName
     *
     *   Author: $author$
     *     Date: 5/18/2004
     **********************************************************************
     */
    static LPCTSTR GetWindowClassName()
    {
        return _T("cWinDTMainWindow");
    }
};

/**
 **********************************************************************
 *  Class: cWinDT
 *
 * Author: $author$
 *   Date: 5/18/2004
 **********************************************************************
 */
class cWinDT
: virtual public cWinDTInterface,
  public cWinMain
{
public:
    typedef cWinMain cIs;

    cDocumentInterface *m_document;

    /**
     **********************************************************************
     * Constructor: cWinDT
     *
     *      Author: $author$
     *        Date: 5/18/2004
     **********************************************************************
     */
    cWinDT() 
    : m_document(0) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDT
     *
     *     Author: $author$
     *       Date: 5/18/2004
     **********************************************************************
     */
    virtual ~cWinDT()
    {
    }

    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual eError OnFileOpen
    (LPCTSTR filename, int length=-1)
    {
        eError error=e_ERROR_FAILED;
        cDocumentInterface *document;

        if ((document = CreateDocumentByFileName(filename, length)))
        {
            if (!(error = document->ParseFromFile(filename)))
            {
                cDocumentInterface *old_document=GetDocument();

                SetDocument(document);

                if (old_document)
                    DestroyDocument(old_document);

                return error;
            }

            DestroyDocument(document);
        }

        return error;
    }

    /**
     **********************************************************************
     * Function: OnWinMain
     *
     *   Author: $author$
     *     Date: 5/18/2004
     **********************************************************************
     */
    virtual int OnWinMain
    (HINSTANCE instance, HINSTANCE previnst,
     LPSTR cmdline, int cmdshow)
    {
        int result=0;
        eError error;
        cWinIcon icon;
        cWinWindowClass window_class;
        cWinDTMainWindow window(*this);

        if (!(error = cWinTreeViewWindow::RegisterWindowClass(instance)))
        {
            if (!(error = cWinListViewWindow::RegisterWindowClass(instance)))
            {
                if (!(error = icon.Create(instance, IDR_MAIN_WINDOW)))
                {
                    window_class.SetIcon(icon.GetHandle());

                    if (!(error = window_class.Register
                        (window.GetWindowClassName(), 
                         instance, window.WindowProc)))
                    {
                        if (!(error = window.Create
                            (window.GetWindowClassName(), instance)))
                        {
                            OnMessageLoop();
                            window.Destroy();
                        }
                        window_class.Unregister();
                    }
                    icon.Destroy();
                }
                cWinListViewWindow::UnregisterWindowClass();
            }
            cWinTreeViewWindow::UnregisterWindowClass();
        }
        return result;
    }

    /**
     **********************************************************************
     * Function: CreateDocumentByFileName
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByFileName
    (LPCTSTR filename, int length=-1)
    {
        cDocumentInterface *document=0;

        document = new cXMLDocument;
        return document;
    }
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual eError DestroyDocument
    (cDocumentInterface *document)
    {
        eError error=e_ERROR_NULL_PARAMETER;

        if (document)
            error = document->FreeInstance();

        return error;
    }

    /**
     **********************************************************************
     * Function: SetDocument
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual cDocumentInterface *SetDocument
    (cDocumentInterface *document)
    {
        return m_document = document;
    }
    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual cDocumentInterface *GetDocument() const
    {
        return m_document;
    }
} g_windt;


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
 *   File: winft.cxx
 *
 * Author: $author$
 *   Date: 4/30/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "resource.h"
#include "cwintreeviewwindow.hxx"
#include "cwincontrolwindow.hxx"
#include "cwincommoncontrol.hxx"
#include "cwinwindow.hxx"
#include "cwinobject.hxx"
#include "cwinmaint.hxx"
#include "cccharbuffer.hxx"
#include "ccchartotcharbuffer.hxx"
#include "ccchartocharbuffer.hxx"
#include "cfiledirectory.hxx"

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 4/23/2005
 **********************************************************************
 */
enum
{
    e_FIRST_TREE, 
    e_SOURCE_TREE = e_FIRST_TREE,
    e_TARGET_TREE,
    e_TREES,
    e_LAST_TREE = e_TREES-1
};

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 5/5/2005
 **********************************************************************
 */
enum
{
    e_FIRST_TREE_IMAGE, 
    e_TREE_IMAGE_FILE = e_FIRST_TREE_IMAGE,
    e_TREE_IMAGE_FOLDER,
    e_TREE_IMAGE_DRIVE,
    e_TREE_IMAGE_SERVER,
    e_TREE_IMAGES,
    e_LAST_TREE_IMAGE = e_TREE_IMAGES-1
};

/**
 **********************************************************************
 *  Class: cWinFTTreeViewWindow
 *
 * Author: $author$
 *   Date: 5/13/2004
 **********************************************************************
 */
class cWinFTTreeViewWindow
: public cWinTreeViewWindow
{
public:
    typedef cWinTreeViewWindow cIs;

    cWinFTTreeViewWindow *m_neighbor;
    cFileDirectory m_dir;
    cCCharBuffer m_filename_buffer;
    const cChar *m_filename;
    TCHAR m_dotname[2];

    /**
     **********************************************************************
     * Constructor: cWinFTTreeViewWindow
     *
     *      Author: $author$
     *        Date: 5/13/2004
     **********************************************************************
     */
    cWinFTTreeViewWindow() 
    : m_neighbor(0),
      m_filename(0)
    {
        m_dotname[0] = DIRECTORY_DOT_CHAR;
        m_dotname[1] = 0;
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        DragAcceptFiles(m_handle, TRUE);
        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        return cIs::OnWMDestroy(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;

        if (!(error = m_image_list.LoadBitmap
            (m_instance, IDB_IMAGELIST, 24)))
            m_tree_control.SetImageList(m_image_list);

        return error;
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
     * Function: OnItemExpanding
     *
     *   Author: $author$
     *     Date: 5/11/2005
     **********************************************************************
     */
    virtual LRESULT OnItemExpanding
    (NMTREEVIEW &notify, WPARAM wparam, LPARAM lparam)
    {
        TVITEM &tvitem=notify.itemNew;
        cWinTreeViewItem item(tvitem);
        HTREEITEM hitem;
        cFileDirectoryEntryInterface *entry;

        if ((hitem = item.GetItem()))
        if ((entry = (cFileDirectoryEntryInterface*)item.GetParam()))
        if (TVE_EXPAND == notify.action)
        {
            if (!OnDirectoryEntryExpanding(*entry, hitem))
                return TRUE;
        }
        else if (TVE_COLLAPSE == notify.action)
        {
            if (!OnDirectoryEntryCollapsing(*entry, hitem))
                return TRUE;
        }

        return cIs::OnItemExpanding(notify, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnDirectoryEntryExpanding
     *
     *   Author: $author$
     *     Date: 5/15/2005
     **********************************************************************
     */
    virtual BOOL OnDirectoryEntryExpanding
    (cFileDirectoryEntryInterface &entry, HTREEITEM hitem)
    {
        BOOL expanded = FALSE;
        int entry_type, entry_namelen, entry_pathlen;
        const cChar *entry_name, *entry_path;
        cFileDirectoryInterface *directory;
        cCCharBuffer *path, *path1, *path2, 
                      path_buffer1, path_buffer2;

        if (!entry.GetIsExpanded())
        {
            if (cFileDirectoryEntryInterface::e_TYPE_DIRECTORY
                & (entry_type = entry.GetEntryType()))
            if ((entry_name = entry.GetEntryName(entry_namelen)))
            if (0 < entry_namelen)
            if (0 < (entry_pathlen = path_buffer1.
                Write(entry_name, entry_namelen)))
            {
                path = &path_buffer1;

                if ((directory = entry.GetParentDirectory()))
                {
                    path2 = &path_buffer2;

                    if ((entry_name = directory->GetPath(entry_namelen)))
                    if (0 < entry_namelen)
                    if (0 < (entry_pathlen = path2->
                        Copy(entry_name, entry_namelen)))
                    if ((entry_name = path->GetBuffer(entry_namelen)))
                    if (0 < entry_namelen)
                    if (0 < path2->Put(DIRECTORY_SEPARATOR_CHAR))
                    if (0 < (entry_pathlen = path2->
                        Write(entry_name, entry_namelen)))
                    {
                        path1 = path;
                        path = path2;
                        path2 = path1;
                    }
                }

                if ((entry_path = path->GetBuffer(entry_pathlen)))
                if ((directory = cDynamicFileDirectory::
                    CreateInstance(directory)))
                {
                    if (OnOpenDirectory(*directory, entry_path, hitem))
                        expanded = TRUE;
                    else directory->FreeInstance();
                }
            }
            entry.SetIsExpanded(TRUE);
        }
        return expanded;
    }
    /**
     **********************************************************************
     * Function: OnDirectoryEntryCollapsing
     *
     *   Author: $author$
     *     Date: 5/15/2005
     **********************************************************************
     */
    virtual BOOL OnDirectoryEntryCollapsing
    (cFileDirectoryEntryInterface &entry, HTREEITEM hitem)
    {
        BOOL collapsed = FALSE;

        if (entry.GetIsExpanded())
        {
            cWinTreeView &tree_control=GetTreeControl();
            HTREEITEM hchild_item;
            int entry_type;
            eError error;

            do
            {
                cWinTreeViewItem child_item(hitem);

                if (!(error = tree_control.GetChildItem(child_item)))
                if ((hchild_item = child_item.GetItem()))
                if (!(error = tree_control.DeleteItem(hchild_item)))
                    continue;
                break;
            }
            while(!error);

            if (cFileDirectoryEntryInterface::e_TYPE_DIRECTORY
                & (entry_type = entry.GetEntryType()))
            {
                OnEntryTreeItem
                (entry_type, m_dotname, 1, hitem);
            }

            collapsed = TRUE;
            entry.SetIsExpanded(FALSE);
        }
        return collapsed;
    }
    /**
     **********************************************************************
     * Function: OnDeleteItem
     *
     *   Author: $author$
     *     Date: 5/11/2005
     **********************************************************************
     */
    virtual LRESULT OnDeleteItem
    (NMTREEVIEW &notify, WPARAM wparam, LPARAM lparam)
    {
        cWinTreeView &tree_control=GetTreeControl();
        TVITEM &tvitem=notify.itemOld;
        cWinTreeViewItem item(tvitem);
        HTREEITEM hitem;
        cFileDirectoryEntryInterface *entry;

        if ((hitem = item.GetItem()))
        if ((entry = (cFileDirectoryEntryInterface*)item.GetParam()))
        {
            entry->FreeInstance();
        }
        return cIs::OnDeleteItem(notify, wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual BOOL OnFileOpen
    (LPCTSTR filename=NULL, int length=-1)
    {
        cWinTreeView &tree_control=GetTreeControl();
        BOOL opened = FALSE;
        int count;

        if (0 < (count = m_filename_buffer.Copyc(filename, length)))
        if ((m_filename = m_filename_buffer.GetBuffer(count)))
        if (0 < count)
        {
            tree_control.DeleteAllItems();
            opened = OnOpenDirectory(m_filename);
        }
        return opened;
    }

    /**
     **********************************************************************
     * Function: OnOpenDirectory
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual BOOL OnOpenDirectory
    (const cChar *filename,
     HTREEITEM parent_item=NULL) 
    {
        BOOL opened = OnOpenDirectory
        (m_dir, filename, parent_item);
        return opened;
    }
    /**
     **********************************************************************
     * Function: OnOpenDirectory
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual BOOL OnOpenDirectory
    (cFileDirectoryInterface &dir,
     const cChar *filename,
     HTREEITEM parent_item=NULL) 
    {
        BOOL opened;
        eError error;
        cFileDirectoryEntryInterface* entry;

        if ((opened = !(error = dir.OpenPath(filename))))
        {
            OnOpenChildDirectory(parent_item);

            if ((entry = dir.GetFirstEntry()))
            do
            {
                OnFileDirectoryEntry(*entry, parent_item);
            }
            while(!(error = entry->GetNextEntry()));

            dir.Close();
        }
        return opened;
    }
    /**
     **********************************************************************
     * Function: OnOpenChildDirectory
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual BOOL OnOpenChildDirectory(HTREEITEM parent_item) 
    {
        cWinTreeView &tree_control=GetTreeControl();
        BOOL opened;
        eError error;

        if ((opened = (NULL != parent_item)))
        do
        {
            cWinTreeViewItem tree_item(parent_item);
            HTREEITEM child_item;

            if (!(error = tree_control.GetChildItem(tree_item)))
            if ((child_item = tree_item.GetItem()))
            if (child_item != parent_item)
            {
                error = tree_control.DeleteItem(child_item);
                continue;
            }
            break;
        }
        while(!error);

        return opened;
    }
    /**
     **********************************************************************
     * Function: OnFileDirectoryEntry
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual void OnFileDirectoryEntry
    (cFileDirectoryEntryInterface &entry,
     HTREEITEM parent_item=NULL) 
    {
        int entry_namelen = 0;
        int entry_type = entry.GetEntryType();
        const cChar *entry_name = entry.GetEntryName(entry_namelen);
        cFileDirectoryInterface *directory = entry.GetParentDirectory();
        HTREEITEM item;
        int textlen;
        TCHAR *text;
        cDynamicFileDirectoryEntry *dentry;
        cCCharToTCHARBuffer text_buffer;

        if (!(dentry = cDynamicFileDirectoryEntry::CreateInstance
            (directory, entry_type, entry_name, entry_namelen)))
            return;

        if (0 < entry_namelen)
            text_buffer.WriteCChar(entry_name, entry_namelen);

        text = text_buffer.GetWriteBuffer(textlen);

        if (NULL != (item = OnEntryTreeItem
            (entry_type, text, textlen, parent_item, 
             (LPARAM)((cFileDirectoryEntryInterface*)dentry))))
        {
            if (cFileDirectoryEntryInterface::
                e_TYPE_DIRECTORY & entry_type)
            {
                OnEntryTreeItem
                (entry_type, m_dotname, 1, item);
            }
        }
        else dentry->FreeInstance();
    }
    /**
     **********************************************************************
     * Function: OnEntryTreeItem
     *
     *   Author: $author$
     *     Date: 5/7/2005
     **********************************************************************
     */
    virtual HTREEITEM OnEntryTreeItem
    (int type, TCHAR *text, int textlen,
     HTREEITEM parent_item=NULL, LPARAM param=NULL) 
    {
        cWinTreeViewItem tree_item;
        int tree_image;
        HTREEITEM item;

        if (cFileDirectoryEntryInterface::
            e_TYPE_DIRECTORY & type)
            tree_image = e_TREE_IMAGE_FOLDER;
        else 
            tree_image = e_TREE_IMAGE_FILE;

        tree_item.SetImage(tree_image);
        tree_item.SetSelectedImage(tree_image);

        if (0 < textlen)
            tree_item.SetText(text, textlen);

        tree_item.SetParam(param);

        item = OnTreeItem(tree_item, parent_item);
        return item;
    }
    /**
     **********************************************************************
     * Function: OnTreeItem
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual HTREEITEM OnTreeItem
    (cWinTreeViewItem &tree_item,
     HTREEITEM parent_item=NULL) 
    {
        cWinTreeView &tree_control=GetTreeControl();
        cWinTreeViewInsert tree_insert(tree_item, parent_item);
        HTREEITEM item= tree_control.InsertItem(tree_insert);
        return item;
    }

    /**
     **********************************************************************
     * Function: SetNeighbor
     *
     *   Author: $author$
     *     Date: 6/16/2005
     **********************************************************************
     */
    virtual cWinFTTreeViewWindow* SetNeighbor
    (cWinFTTreeViewWindow* neighbor) 
    {
        return m_neighbor = neighbor;
    }
    /**
     **********************************************************************
     * Function: GetNeighbor
     *
     *   Author: $author$
     *     Date: 6/16/2005
     **********************************************************************
     */
    virtual cWinFTTreeViewWindow* GetNeighbor() 
    {
        return m_neighbor;
    }
};

/**
 **********************************************************************
 *  Class: cWinFTMainWindow
 *
 * Author: $author$
 *   Date: 4/30/2004
 **********************************************************************
 */
class cWinFTMainWindow
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    LPCTSTR m_window_class_name;
    cWinFTTreeViewWindow m_tree_view[e_TREES];

    /**
     **********************************************************************
     * Constructor: cWinFTMainWindow
     *
     *      Author: $author$
     *        Date: 4/30/2004
     **********************************************************************
     */
    cWinFTMainWindow
    (LPCTSTR window_class_name=_T("cWinFTMainWindow")) 
    : m_window_class_name(window_class_name)
    {
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        cWinClientRect client_rect(m_handle);
        int client_width = client_rect.right-client_rect.left+1;
        int client_height = client_rect.bottom-client_rect.top+1;
        int tree_view_width, tree_view_height;
        int tree_view_left, tree_view_top;
        int tree_view, tree_view_neighbor;
        eError error;

        tree_view_left = 0;
        tree_view_top = 0;
        tree_view_width = client_width/e_TREES;
        tree_view_height = client_height;

        for (tree_view=e_FIRST_TREE; 
             tree_view<=e_LAST_TREE; 
             tree_view++, tree_view_left+=tree_view_width)
		{
		    if ((error = m_tree_view[tree_view].Create
			    (m_tree_view[tree_view].GetWindowClassName(),
                 m_instance, NULL, m_handle, NULL, 
                 WS_CHILD | WS_VISIBLE, 0, 
                 tree_view_left,tree_view_top, 
                 tree_view_width, tree_view_height)))
                 break;
        }
        for (tree_view=e_FIRST_TREE; 
             tree_view<=e_LAST_TREE; 
             tree_view++)
		{
            for (tree_view_neighbor=e_FIRST_TREE; 
                 tree_view_neighbor<=e_LAST_TREE; 
                 tree_view_neighbor++)
		    {
                if (tree_view != tree_view_neighbor)
                    m_tree_view[tree_view].SetNeighbor
                    (m_tree_view+tree_view_neighbor);
            }
        }
        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        int tree_view;

        for (tree_view=e_FIRST_TREE; 
             tree_view<=e_LAST_TREE; 
             tree_view++)
        if (m_tree_view[tree_view].GetIsCreated())
        {
		    m_tree_view[tree_view].Destroy();
        }
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
        int client_width=LOWORD(lparam);
        int client_height=HIWORD(lparam);
        int tree_view_width, tree_view_height;
        int tree_view_left, tree_view_top;
        int tree_view;

        tree_view_left = 0;
        tree_view_top = 0;
        tree_view_width = client_width/e_TREES;
        tree_view_height = client_height;

        if (SIZE_MINIMIZED != wparam)
        for (tree_view=e_FIRST_TREE; 
             tree_view<=e_LAST_TREE; 
             tree_view++, tree_view_left+=tree_view_width)
        {
            if (m_tree_view[tree_view].GetIsCreated())
            {
                MoveWindow
                (m_tree_view[tree_view], 
                 tree_view_left,tree_view_top,
                 tree_view_width,tree_view_height, TRUE);
            }
        }
        return cIs::OnWMSize(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: GetWindowClassName
     *
     *   Author: $author$
     *     Date: 4/30/2004
     **********************************************************************
     */
    LPCTSTR GetWindowClassName() const
    {
        return m_window_class_name;
    }
};

/**
 **********************************************************************
 *  Class: cWinFTMain
 *
 * Author: $author$
 *   Date: 4/30/2004
 **********************************************************************
 */
class cWinFTMain
: public cWinMain
{
public:
    typedef cWinMain cIs;

    /**
     **********************************************************************
     * Constructor: cWinFTMain
     *
     *      Author: $author$
     *        Date: 4/30/2004
     **********************************************************************
     */
    cWinFTMain() 
    : cWinMain() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinFTMain
     *
     *     Author: $author$
     *       Date: 4/30/2004
     **********************************************************************
     */
    virtual ~cWinFTMain()
    {
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 4/30/2004
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
        cWinFTMainWindow window;

        if (!(error = cWinTreeViewWindow::RegisterWindowClass(instance)))
        {
            if (!(error = icon.Create(instance, IDI_ICON)))
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
            cWinTreeViewWindow::UnregisterWindowClass();
        }
        return result;
    }
} g_winft_main;

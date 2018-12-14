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
 *   File: cwinevcsexplorerviewwindow.hxx
 *
 * Author: $author$
 *   Date: 6/7/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINEVCSEXPLORERVIEWWINDOW_HXX
#define _CWINEVCSEXPLORERVIEWWINDOW_HXX

#include "cwintreeviewwindow.hxx"
#include "cwinlistviewwindow.hxx"
#include "cwinevcsviewwindow.hxx"
#include "cwinevcsmain.hxx"

#include "cfiledirectoryinterface.hxx"
#include "cfiledirectoryentryinterface.hxx"

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
enum
{
    e_FIRST_TREE_IMAGE, 

    e_TREE_IMAGE_FILE = e_FIRST_TREE_IMAGE,
    e_TREE_IMAGE_FOLDER,
    /*e_TREE_IMAGE_DRIVE,
    e_TREE_IMAGE_SERVER,*/

    e_TREE_IMAGES,
    e_LAST_TREE_IMAGE = e_TREE_IMAGES-1
};

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerTreeViewWindow
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
class cWinEvcsExplorerTreeViewWindow
: public cWinTreeViewWindow
{
public:
    typedef cWinTreeViewWindow cExtends;
    typedef cWinEvcsExplorerTreeViewWindow cDerives;

    cWinEvcsMainInterface &m_winevcs;
    cWinListViewWindow &m_list_view;

    cFileDirectoryInterface* m_dir;

    /**
     **********************************************************************
     * Constructor: cWinEvcsExplorerTreeViewWindow
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    cWinEvcsExplorerTreeViewWindow
    (cWinEvcsMainInterface &winevcs, cWinListViewWindow &list_view)
    : m_winevcs(winevcs), m_list_view(list_view),
      m_dir(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsExplorerTreeViewWindow
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    virtual ~cWinEvcsExplorerTreeViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnOpenDirectory
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual BOOL OnOpenDirectory
    (const TCHAR* filename,
     HTREEITEM parent_item=NULL,
     BOOL expand_directory=TRUE) 
    {
        BOOL opened = FALSE;
        eError error;

        if (!m_dir)
        if (!(m_dir = cFileDirectoryInterface::NewInstance(error)))
            return opened;
        
        opened = OnOpenDirectory
        (*m_dir, filename, parent_item, expand_directory);
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
     const TCHAR* filename,
     HTREEITEM parent_item=NULL,
     BOOL expand_directory=TRUE) 
    {
        BOOL opened;
        eError error;
        cFileDirectoryEntryInterface* entry;

        if ((opened = !(error = dir.Open(filename))))
        {
            //OnOpenChildDirectory(parent_item);

            if ((entry = dir.GetFirstEntry(error)))
            do
            {
                OnInsertFileDirectoryEntry
                (*entry, parent_item, expand_directory);
            }
            while((entry = dir.GetNextEntry(*entry, error)));

            dir.Close();
        }
        return opened;
    }

    /**
     **********************************************************************
     * Function: OnInsertFileDirectoryEntry
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual void OnInsertFileDirectoryEntry
    (cFileDirectoryEntryInterface &entry,
     HTREEITEM parent_item=NULL,
     BOOL expand_directory=TRUE) 
    {
        eError error = 0;
        int entry_namelen = 0;
        int entry_type = entry.GetType(error);
        const TCHAR* entry_name = entry.GetName(entry_namelen);
        cFileDirectoryEntryInterface *dentry = 0;
        HTREEITEM item;
        int textlen;
        TCHAR *text;
        cTCHARBuffer text_buffer;

        if ((entry_name && (0 < entry_namelen)))
            text_buffer.Write(entry_name, entry_namelen);

        if ((text = text_buffer.GetWriteBuffer(textlen)))
        if (NULL != (item = OnInsertFileDirectoryEntryTreeItem
            (entry_type, text, textlen, parent_item, 
             (LPARAM)((cFileDirectoryEntryInterface*)dentry))))
        {
        }
    }

    /**
     **********************************************************************
     * Function: OnInsertFileDirectoryEntryTreeItem
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual HTREEITEM OnInsertFileDirectoryEntryTreeItem
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

        item = OnInsertTreeItem(tree_item, parent_item);
        return item;
    }
    /**
     **********************************************************************
     * Function: OnInsertTreeItem
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual HTREEITEM OnInsertTreeItem
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
            (m_instance, IDR_EXPLORER_WINDOW, 
             EXPLORER_WINDOW_BITMAP_HEIGHT)))
            m_tree_control.SetImageList(m_image_list);

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerListViewWindow
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
class cWinEvcsExplorerListViewWindow
: public cWinListViewWindow
{
public:
    typedef cWinListViewWindow cExtends;
    typedef cWinEvcsExplorerListViewWindow cDerives;

    cWinEvcsMainInterface &m_winevcs;
    cWinTreeViewWindow &m_tree_view;

    /**
     **********************************************************************
     * Constructor: cWinEvcsExplorerListViewWindow
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    cWinEvcsExplorerListViewWindow
    (cWinEvcsMainInterface &winevcs, cWinTreeViewWindow &tree_view)
    : m_winevcs(winevcs), m_tree_view(tree_view) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsExplorerListViewWindow
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    virtual ~cWinEvcsExplorerListViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;
        cWinClientRect client_rect(m_control);
        cWinListViewColumn column;
        const TCHAR** pchars;
        int n, length;

        if ((pchars = GetColumnNames(length)))
        if (0 < length)
        {
            column.SetWidth((client_rect.right-client_rect.left+1)/length);

            for (n = 0; n < length; n++)
            {
                column.SetText(pchars[n]);
                m_list_control.InsertColumn(n, column);
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetColumnNames
     *
     *   Author: $author$
     *     Date: 6/11/2007
     **********************************************************************
     */
    virtual const TCHAR** 
    GetColumnNames(int &length) 
    {
        const TCHAR** pchars = 0;
        return pchars;
    }
};

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
enum
{
    e_FIRST_DIRECTORY_LIST_COLUMN = 0,

    e_DIRECTORY_LIST_COLUMN_NAME = e_FIRST_DIRECTORY_LIST_COLUMN,
    e_DIRECTORY_LIST_COLUMN_SIZE,
    e_DIRECTORY_LIST_COLUMN_TYPE,
    e_DIRECTORY_LIST_COLUMN_MODIFIED,

    e_NEXT_DIRECTORY_LIST_COLUMN,
    e_LAST_DIRECTORY_LIST_COLUMN = e_NEXT_DIRECTORY_LIST_COLUMN-1,

    e_DIRECTORY_LIST_COLUMNS = e_NEXT_DIRECTORY_LIST_COLUMN-e_FIRST_DIRECTORY_LIST_COLUMN
};

#define DIRECTORY_LIST_COLUMN_NAME_NAME "Name"
#define DIRECTORY_LIST_COLUMN_NAME_SIZE "Size"
#define DIRECTORY_LIST_COLUMN_NAME_TYPE "Type"
#define DIRECTORY_LIST_COLUMN_NAME_MODIFIED "Modified"

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerDirectoryListViewWindow
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
class cWinEvcsExplorerDirectoryListViewWindow
: public cWinEvcsExplorerListViewWindow
{
public:
    typedef cWinEvcsExplorerListViewWindow cExtends;
    typedef cWinEvcsExplorerDirectoryListViewWindow cDerives;

    static const TCHAR* m_column_name[e_DIRECTORY_LIST_COLUMNS];

    /**
     **********************************************************************
     * Constructor: cWinEvcsExplorerDirectoryListViewWindow
     *
     *      Author: $author$
     *        Date: 6/11/2007
     **********************************************************************
     */
    cWinEvcsExplorerDirectoryListViewWindow
    (cWinEvcsMainInterface &winevcs, cWinTreeViewWindow &tree_view)
    : cExtends(winevcs, tree_view) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsExplorerDirectoryListViewWindow
     *
     *      Author: $author$
     *        Date: 6/11/2007
     **********************************************************************
     */
    virtual ~cWinEvcsExplorerDirectoryListViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: GetColumnNames
     *
     *   Author: $author$
     *     Date: 6/11/2007
     **********************************************************************
     */
    virtual const TCHAR** 
    GetColumnNames(int &length) 
    {
        const TCHAR** pchars = m_column_name;
        length = e_DIRECTORY_LIST_COLUMNS;
        return pchars;
    }
};

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
enum
{
    e_FIRST_FILE_LIST_COLUMN = 0,

    e_FILE_LIST_COLUMN_PROPERTY = e_FIRST_FILE_LIST_COLUMN,
    e_FILE_LIST_COLUMN_VALUE,

    e_NEXT_FILE_LIST_COLUMN,
    e_LAST_FILE_LIST_COLUMN = e_NEXT_FILE_LIST_COLUMN-1,

    e_FILE_LIST_COLUMNS = e_NEXT_FILE_LIST_COLUMN-e_FIRST_FILE_LIST_COLUMN
};

#define FILE_LIST_COLUMN_NAME_PROPERTY "Property"
#define FILE_LIST_COLUMN_NAME_VALUE "Value"

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerFileListViewWindow
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
class cWinEvcsExplorerFileListViewWindow
: public cWinEvcsExplorerListViewWindow
{
public:
    typedef cWinEvcsExplorerListViewWindow cExtends;
    typedef cWinEvcsExplorerFileListViewWindow cDerives;

    static const TCHAR* m_column_name[e_FILE_LIST_COLUMNS];

    /**
     **********************************************************************
     * Constructor: cWinEvcsExplorerFileListViewWindow
     *
     *      Author: $author$
     *        Date: 6/11/2007
     **********************************************************************
     */
    cWinEvcsExplorerFileListViewWindow
    (cWinEvcsMainInterface &winevcs, cWinTreeViewWindow &tree_view)
    : cExtends(winevcs, tree_view) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsExplorerFileListViewWindow
     *
     *      Author: $author$
     *        Date: 6/11/2007
     **********************************************************************
     */
    virtual ~cWinEvcsExplorerFileListViewWindow()
    {
    }
    /**
     **********************************************************************
     * Function: GetColumnNames
     *
     *   Author: $author$
     *     Date: 6/11/2007
     **********************************************************************
     */
    virtual const TCHAR** GetColumnNames
    (int &length) 
    {
        const TCHAR** pchars = m_column_name;
        length = e_FILE_LIST_COLUMNS;
        return pchars;
    }
};

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerViewWindow
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
class cWinEvcsExplorerViewWindow
: public cWinEvcsViewWindow
{
public:
    typedef cWinEvcsViewWindow cExtends;
    typedef cWinEvcsExplorerViewWindow cDerives;

    cWinEvcsMainInterface &m_winevcs;
    cWinEvcsExplorerTreeViewWindow m_tree_view;
    cWinEvcsExplorerDirectoryListViewWindow m_directory_list_view;
    cWinEvcsExplorerFileListViewWindow m_file_list_view;
    int m_tree_view_width, m_tree_view_height;
    int m_list_view_width, m_list_view_height;

    /**
     **********************************************************************
     * Constructor: cWinEvcsExplorerViewWindow
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    cWinEvcsExplorerViewWindow
    (cWinEvcsMainInterface &winevcs,
     HINSTANCE instance=NULL, HWND handle=NULL, 
     bool created=false, HINSTANCE old_instance=NULL) 
    : cExtends(instance, handle, created, old_instance),
      m_winevcs(winevcs),
      m_tree_view(winevcs, m_directory_list_view),
      m_directory_list_view(winevcs, m_tree_view),
      m_file_list_view(winevcs, m_tree_view),
      m_tree_view_width(100),
      m_tree_view_height(100),
      m_list_view_width(100),
      m_list_view_height(100) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsExplorerViewWindow
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    virtual ~cWinEvcsExplorerViewWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnOpenDirectory
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual BOOL OnOpenDirectory
    (const TCHAR* filename) 
    {
        BOOL opened = m_tree_view.OnOpenDirectory(filename);
        return opened;
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 6/7/2007
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

        m_directory_list_view.Create
	    (m_directory_list_view.GetWindowClassName(),
         m_instance, NULL, m_handle, NULL, 
         WS_CHILD | WS_VISIBLE, 0, m_tree_view_width,0, 
         m_list_view_width, m_list_view_height);

        m_file_list_view.Create
	    (m_directory_list_view.GetWindowClassName(),
         m_instance, NULL, m_handle, NULL, 
         WS_CHILD | WS_VISIBLE, 0, m_tree_view_width,0, 
         m_list_view_width, m_list_view_height);

        m_directory_list_view.Show(SW_HIDE);
        return cExtends::OnWMCreate(wparam, lparam);
    }
};

#endif /* _CWINEVCSEXPLORERVIEWWINDOW_HXX */

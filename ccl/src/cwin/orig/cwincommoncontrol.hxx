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
 *   File: cwincommoncontrol.hxx
 *
 * Author: $author$
 *   Date: 4/30/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINCOMMONCONTROL_HXX
#define _CWINCOMMONCONTROL_HXX

#include <windows.h>
#include <commctrl.h>
#include "cwinwindow.hxx"
#include "cwinobject.hxx"

/**
 **********************************************************************
 *  Class: cWinImageList
 *
 * Author: $author$
 *   Date: 4/30/2004
 **********************************************************************
 */
class cWinImageList
: public cCreatedHandleT<HIMAGELIST, NULL>
{
public:
    typedef cCreatedHandleT<HIMAGELIST, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinImageList
     *
     *      Author: $author$
     *        Date: 4/30/2004
     **********************************************************************
     */
    cWinImageList(HIMAGELIST handle=NULL, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImageList
     *
     *     Author: $author$
     *       Date: 4/30/2004
     **********************************************************************
     */
    virtual ~cWinImageList()
    {
    }

    /**
     **********************************************************************
     * Function: LoadBitmap
     *
     *   Author: $author$
     *     Date: 4/30/2004
     **********************************************************************
     */
    virtual eError LoadBitmap
    (HINSTANCE instance, int id, 
     int cx, int grow=0, COLORREF mask=CLR_NONE)
    {
        return LoadBitmap
        (instance, MAKEINTRESOURCE(id), cx, grow, mask);
    }
    /**
     **********************************************************************
     * Function: LoadBitmap
     *
     *   Author: $author$
     *     Date: 4/30/2004
     **********************************************************************
     */
    virtual eError LoadBitmap
    (HINSTANCE instance, LPCTSTR name, 
     int cx, int grow=0, COLORREF mask=CLR_NONE)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = ImageList_LoadBitmap
            (instance, name, cx, grow, mask)))
        {
            m_created = true;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/29/2005
     **********************************************************************
     */
    virtual eError Create
    (int cx, int cy, int initial=0, 
     int grow=0, int flags=ILC_COLOR)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = ImageList_Create
            (cx, cy, flags, initial, grow)))
        {
            m_created = true;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/30/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (ImageList_Destroy(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        return error;
    }

    /**
     **********************************************************************
     * Operator: HIMAGELIST
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    inline operator HIMAGELIST () const
    {
        return m_handle;
    }
};

#define CWINTREEVIEW_DEFAULT_WINDOW_STYLE \
    WS_CHILD | WS_VISIBLE | \
    TVS_HASLINES | TVS_LINESATROOT | \
    TVS_HASBUTTONS | TVS_SHOWSELALWAYS | \
    TVS_EDITLABELS

#define CWINTREEVIEW_DEFAULT_WINDOW_EXSTYLE \
    WS_EX_CLIENTEDGE

/**
 **********************************************************************
 *  Class: cWinTreeViewItem
 *
 * Author: $author$
 *   Date: 5/6/2004
 **********************************************************************
 */
class cWinTreeViewItem
: public TVITEMEX
{
public:
    typedef TVITEMEX cIs;

    /**
     **********************************************************************
     * Constructor: cWinTreeViewItem
     *
     *      Author: $author$
     *        Date: 5/6/2004
     **********************************************************************
     */
    cWinTreeViewItem
    (HTREEITEM p_hItem=NULL, UINT p_mask=0, UINT p_state=0,
     UINT p_stateMask=0, LPTSTR p_pszText=NULL, int p_cchTextMax=0,
     int p_iImage=0, int p_iSelectedImage=0, int p_cChildren=0,
     LPARAM p_lParam=NULL, int p_iIntegral=0)
    {
        hItem = p_hItem;
        mask = p_mask;
        state = p_state;
        stateMask = p_stateMask;
        pszText = p_pszText;
        cchTextMax = p_cchTextMax;
        iImage = p_iImage;
        iSelectedImage = p_iSelectedImage;
        cChildren = p_cChildren;
        lParam = p_lParam;
        iIntegral = p_iIntegral;
    }
    /**
     **********************************************************************
     * Constructor: cWinTreeViewItem
     *
     *      Author: $author$
     *        Date: 5/25/2004
     **********************************************************************
     */
    cWinTreeViewItem(TVITEM &item)
    {
        mask = item.mask;
        hItem = item.hItem;
        state = item.state;
        stateMask = item.stateMask;
        pszText = item.pszText;
        cchTextMax = item.cchTextMax;
        iImage = item.iImage;
        iSelectedImage = item.iSelectedImage;
        cChildren = item.cChildren;
        lParam = item.lParam;
        iIntegral = 0;
    }

    /**
     **********************************************************************
     * Function: SetItem
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    HTREEITEM SetItem(HTREEITEM p_hItem)
    {
        mask |= TVIF_HANDLE;
        return hItem = p_hItem;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    HTREEITEM GetItem() const
    {
        if (mask & TVIF_HANDLE)
            return hItem;

        return NULL;
    }

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 5/6/2004
     **********************************************************************
     */
    LPTSTR SetText(LPTSTR p_pszText, int p_cchTextMax=-1)
    {
        if (0 > p_cchTextMax)
            p_cchTextMax = _tcsclen(p_pszText);

        mask |= TVIF_TEXT;
        pszText = p_pszText;
        cchTextMax = p_cchTextMax;
        return p_pszText;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    LPTSTR GetText() const
    {
        if (mask & TVIF_TEXT)
            return pszText;

        return NULL;
    }

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    int SetImage(int p_iImage)
    {
        mask |= TVIF_IMAGE;
        return iImage = p_iImage;
    }
    /**
     **********************************************************************
     * Function: GetImage
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    int GetImage() const
    {
        if (mask & TVIF_IMAGE)
            return iImage;

        return -1;
    }

    /**
     **********************************************************************
     * Function: SetSelectedImage
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    int SetSelectedImage(int p_iSelectedImage)
    {
        mask |= TVIF_SELECTEDIMAGE;
        return iSelectedImage = p_iSelectedImage;
    }
    /**
     **********************************************************************
     * Function: GetSelectedImage
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    int GetSelectedImage() const
    {
        if (mask & TVIF_SELECTEDIMAGE)
            return iSelectedImage;

        return -1;
    }

    /**
     **********************************************************************
     * Function: SetParamMask
     *
     *   Author: $author$
     *     Date: 6/24/2005
     **********************************************************************
     */
    DWORD SetParamMask(BOOL on=TRUE)
    {
        if (on)
            return mask |= TVIF_PARAM;

        return mask &= ~TVIF_PARAM;
    }
    /**
     **********************************************************************
     * Function: SetParam
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    LPARAM SetParam(LPARAM p_lParam)
    {
        mask |= TVIF_PARAM;
        return lParam = p_lParam;
    }
    /**
     **********************************************************************
     * Function: GetParam
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    LPARAM GetParam() const
    {
        if (mask & TVIF_PARAM)
            return lParam;

        return NULL;
    }

    /**
     **********************************************************************
     * Function: SetState
     *
     *   Author: $author$
     *     Date: 5/7/2005
     **********************************************************************
     */
    UINT SetState(UINT p_stateMask, UINT p_state) 
    {
        mask |= TVIF_STATE;
        state = p_state;
        stateMask = p_stateMask;
        return stateMask & state;
    }
    /**
     **********************************************************************
     * Function: GetState
     *
     *   Author: $author$
     *     Date: 5/7/2005
     **********************************************************************
     */
    UINT GetState() const 
    {
        return stateMask & state;
    }
};

/**
 **********************************************************************
 *  Class: cWinTreeViewInsert
 *
 * Author: $author$
 *   Date: 5/6/2004
 **********************************************************************
 */
class cWinTreeViewInsert
: public TV_INSERTSTRUCT
{
public:
    typedef TV_INSERTSTRUCT cIs;

    /**
     **********************************************************************
     * Constructor: cWinTreeViewInsert
     *
     *      Author: $author$
     *        Date: 5/6/2004
     **********************************************************************
     */
    cWinTreeViewInsert
    (HTREEITEM p_hParent=NULL, 
     HTREEITEM p_hInsertAfter=NULL) 
    {
        cWinTreeViewItem item;

        hParent = p_hParent;
        hInsertAfter = p_hInsertAfter;
        SetItem(item);
    }
    /**
     **********************************************************************
     * Constructor: cWinTreeViewInsert
     *
     *      Author: $author$
     *        Date: 5/6/2004
     **********************************************************************
     */
    cWinTreeViewInsert
    (cWinTreeViewItem &p_item,
     HTREEITEM p_hParent=NULL, 
     HTREEITEM p_hInsertAfter=NULL) 
    {
        hParent = p_hParent;
        hInsertAfter = p_hInsertAfter;
        SetItem(p_item);
    }

    /**
     **********************************************************************
     * Function: SetItem
     *
     *   Author: $author$
     *     Date: 5/6/2004
     **********************************************************************
     */
    TVITEMEX &SetItem(cWinTreeViewItem &p_item)
    {
        itemex.mask = p_item.mask;
        itemex.hItem = p_item.hItem;
        itemex.state = p_item.state;
        itemex.stateMask = p_item.stateMask;
        itemex.pszText = p_item.pszText;
        itemex.cchTextMax = p_item.cchTextMax;
        itemex.iImage = p_item.iImage;
        itemex.iSelectedImage = p_item.iSelectedImage;
        itemex.cChildren = p_item.cChildren;
        itemex.lParam = p_item.lParam;
        itemex.iIntegral = p_item.iIntegral;
        return itemex;
    }

    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 5/6/2004
     **********************************************************************
     */
    LRESULT Send(HWND hwnd) const
    {
        return ::SendMessage
        (hwnd, TVM_INSERTITEM, 0, (LPARAM)this);
    }
};

/**
 **********************************************************************
 *  Class: cWinTreeView
 *
 * Author: $author$
 *   Date: 5/4/2004
 **********************************************************************
 */
class cWinTreeView
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    /**
     **********************************************************************
     * Constructor: cWinTreeView
     *
     *      Author: $author$
     *        Date: 5/4/2004
     **********************************************************************
     */
    cWinTreeView(HINSTANCE instance=NULL, HWND handle=NULL, bool created=false) 
    : cIs(instance, handle, created) 
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/4/2004
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE instance, HWND parent, int id, 
     int x, int y, int width, int height, 
     DWORD style=CWINTREEVIEW_DEFAULT_WINDOW_STYLE, 
     DWORD exstyle=CWINTREEVIEW_DEFAULT_WINDOW_EXSTYLE, 
     LPVOID param=NULL)
    {
        LPCTSTR classname=GetWindowClassName();
        LPCTSTR windowname=NULL;
        HMENU menu=(HMENU)id;

        return CreateTheWindow
        (classname, windowname, style, exstyle, 
         x, y, width, height, parent, menu, instance, param);
    }

    /**
     **********************************************************************
     * Function: SetImageList
     *
     *   Author: $author$
     *     Date: 5/6/2004
     **********************************************************************
     */
    virtual HIMAGELIST SetImageList
    (HIMAGELIST image_list, 
     INT image_list_type=TVSIL_NORMAL) const
    {
        if (m_handle)
            return TreeView_SetImageList
            (m_handle, image_list, image_list_type);

        return NULL;
    }
    /**
     **********************************************************************
     * Function: GetImageList
     *
     *   Author: $author$
     *     Date: 5/6/2004
     **********************************************************************
     */
    virtual HIMAGELIST GetImageList
    (INT image_list_type=TVSIL_NORMAL) const
    {
        if (m_handle)
            return TreeView_GetImageList
            (m_handle, image_list_type);

        return NULL;
    }

    /**
     **********************************************************************
     * Function: InsertItem
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    virtual HTREEITEM InsertItem(TVINSERTSTRUCT &insert)
    {
        HTREEITEM item=NULL;

        if (m_handle)
            item = TreeView_InsertItem(m_handle, &insert);

        return item;
    }
    /**
     **********************************************************************
     * Function: DeleteItem
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    virtual eError DeleteItem(HTREEITEM item)
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (TreeView_DeleteItem(m_handle, item))
                error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteAllItems
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    virtual eError DeleteAllItems()
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (TreeView_DeleteAllItems(m_handle))
                error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: SetItem
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    virtual eError SetItem(TVITEMEX &item)
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (TreeView_SetItem(m_handle, &item))
                error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 5/11/2004
     **********************************************************************
     */
    virtual eError GetItem(TVITEMEX &item) const
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (TreeView_GetItem(m_handle, &item))
                error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: GetParentItem
     *
     *   Author: $author$
     *     Date: 5/11/2005
     **********************************************************************
     */
    virtual eError GetParentItem(TVITEMEX &item) const
    {
        eError error=e_ERROR_FAILED;
        HTREEITEM hitem;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (!(hitem = TreeView_GetParent
                 (m_handle, item.hItem)))
                error = e_ERROR_ENDOF;

        else 
        {
            item.hItem = hitem;
            item.mask |= TVIF_HANDLE;

            if (TreeView_GetItem(m_handle, &item))
                error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetChildItem
     *
     *   Author: $author$
     *     Date: 6/10/2005
     **********************************************************************
     */
    virtual eError GetChildItem(TVITEMEX &item) const
    {
        eError error=e_ERROR_FAILED;
        HTREEITEM hitem;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (!(hitem = TreeView_GetChild
                 (m_handle, item.hItem)))
                error = e_ERROR_ENDOF;

        else 
        {
            item.hItem = hitem;
            item.mask |= TVIF_HANDLE;

            if (TreeView_GetItem(m_handle, &item))
                error = e_ERROR_NONE;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetNextSiblingItem
     *
     *   Author: $author$
     *     Date: 6/22/2005
     **********************************************************************
     */
    virtual eError GetNextSiblingItem(TVITEMEX &item) const
    {
        eError error=e_ERROR_FAILED;
        HTREEITEM hitem;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (!(hitem = TreeView_GetNextSibling
                 (m_handle, item.hItem)))
                error = e_ERROR_ENDOF;

        else 
        {
            item.hItem = hitem;
            item.mask |= TVIF_HANDLE;

            if (TreeView_GetItem(m_handle, &item))
                error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetPrevSiblingItem
     *
     *   Author: $author$
     *     Date: 6/22/2005
     **********************************************************************
     */
    virtual eError GetPrevSiblingItem(TVITEMEX &item) const
    {
        eError error=e_ERROR_FAILED;
        HTREEITEM hitem;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (!(hitem = TreeView_GetPrevSibling
                 (m_handle, item.hItem)))
                error = e_ERROR_ENDOF;

        else 
        {
            item.hItem = hitem;
            item.mask |= TVIF_HANDLE;

            if (TreeView_GetItem(m_handle, &item))
                error = e_ERROR_NONE;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetSelectedItem
     *
     *   Author: $author$
     *     Date: 6/27/2005
     **********************************************************************
     */
    virtual eError GetSelectedItem(TVITEMEX &item) const
    {
        eError error=e_ERROR_FAILED;
        HTREEITEM hitem;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (!(hitem = TreeView_GetSelection(m_handle)))
                error = e_ERROR_ENDOF;

        else 
        {
            item.hItem = hitem;
            item.mask |= TVIF_HANDLE;

            if (TreeView_GetItem(m_handle, &item))
                error = e_ERROR_NONE;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetWindowClassName
     *
     *   Author: $author$
     *     Date: 5/4/2004
     **********************************************************************
     */
    static inline LPCTSTR GetWindowClassName()
    {
        return WC_TREEVIEW;
    }

    /**
     **********************************************************************
     * Function: GetDefaultWindowStyle
     *
     *   Author: $author$
     *     Date: 5/5/2004
     **********************************************************************
     */
    static inline DWORD GetDefaultWindowStyle()
    {
        return CWINTREEVIEW_DEFAULT_WINDOW_STYLE;
    }
    /**
     **********************************************************************
     * Function: GetDefaultWindowExStyle
     *
     *   Author: $author$
     *     Date: 5/5/2004
     **********************************************************************
     */
    static inline DWORD GetDefaultWindowExStyle()
    {
        return CWINTREEVIEW_DEFAULT_WINDOW_EXSTYLE;
    }
};

#endif /* ndef _CWINCOMMONCONTROL_HXX */

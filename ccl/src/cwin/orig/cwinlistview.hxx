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
 *   File: cwinlistview.hxx
 *
 * Author: $author$
 *   Date: 5/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINLISTVIEW_HXX
#define _CWINLISTVIEW_HXX

#include "cwincommoncontrol.hxx"

#define CWINLISTVIEW_DEFAULT_WINDOW_STYLE \
    WS_CHILD | WS_VISIBLE | \
    LVS_REPORT | LVS_SHOWSELALWAYS | \
    LVS_NOSORTHEADER | LVS_EDITLABELS

#define CWINLISTVIEW_DEFAULT_WINDOW_EXSTYLE \
    WS_EX_CLIENTEDGE

/**
 **********************************************************************
 *  Class: cWinListViewColumn
 *
 * Author: $author$
 *   Date: 5/28/2004
 **********************************************************************
 */
class cWinListViewColumn
: public LVCOLUMN
{
public:
    typedef LVCOLUMN cIs;

    /**
     **********************************************************************
     * Constructor: cWinListViewColumn
     *
     *      Author: $author$
     *        Date: 5/28/2004
     **********************************************************************
     */
    cWinListViewColumn
    (UINT p_mask=0, int p_fmt=0, int p_cx=0, 
     LPTSTR p_pszText=NULL, int p_cchTextMax=0,
     int p_iSubItem=0, int p_iImage=0, int p_iOrder=0) 
    {
        mask = p_mask;
        fmt = p_fmt;
        cx = p_cx;
        pszText = p_pszText;
        cchTextMax = p_cchTextMax;
        iSubItem = p_iSubItem;
        iImage = p_iImage;
        iOrder = p_iOrder;
    }

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    LPTSTR SetText(LPTSTR p_pszText, int p_cchTextMax=-1)
    {
        if (0 > p_cchTextMax)
            p_cchTextMax = _tcsclen(p_pszText);

        mask |= LVCF_TEXT;
        pszText = p_pszText;
        cchTextMax = p_cchTextMax;
        return p_pszText;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    LPTSTR GetText() const
    {
        if (mask & LVCF_TEXT)
            return pszText;
        return NULL;
    }

    /**
     **********************************************************************
     * Function: SetWidth
     *
     *   Author: $author$
     *     Date: 5/29/2004
     **********************************************************************
     */
    virtual int SetWidth(int width)
    {
        mask |= LVCF_WIDTH;
        return cx = width;
    }
    /**
     **********************************************************************
     * Function: GetWidth
     *
     *   Author: $author$
     *     Date: 5/29/2004
     **********************************************************************
     */
    virtual int GetWidth() const
    {
        if (mask & LVCF_WIDTH)
            return cx;
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cWinListViewItem
 *
 * Author: $author$
 *   Date: 5/22/2004
 **********************************************************************
 */
class cWinListViewItem
: public LVITEM
{
public:
    typedef LVITEM cIs;

    /**
     **********************************************************************
     * Constructor: cWinListViewItem
     *
     *      Author: $author$
     *        Date: 5/22/2004
     **********************************************************************
     */
    cWinListViewItem
    (UINT p_mask=0, int p_iItem=0, int p_iSubItem=0,
     UINT p_state=0, UINT p_stateMask=0,
     LPTSTR p_pszText=NULL, int p_cchTextMax=0,
     int p_iImage=0, LPARAM p_lParam=NULL, int p_iIndent=0) 
    {
        mask = p_mask;
        iItem = p_iItem;
        iSubItem = p_iSubItem;
        state = p_state;
        stateMask = p_stateMask;
        pszText = p_pszText;
        cchTextMax = p_cchTextMax;
        iImage = p_iImage;
        lParam = p_lParam;
        iIndent = p_iIndent;
    }

    /**
     **********************************************************************
     * Function: SetItem
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    int SetItem(int p_iItem)
    {
        return iItem = p_iItem;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    int GetItem() const
    {
        return iItem;
    }

    /**
     **********************************************************************
     * Function: SetSubItem
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    virtual int SetSubItem(int p_iSubItem)
    {
        return iSubItem = p_iSubItem;
    }
    /**
     **********************************************************************
     * Function: GetSubItem
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    int GetSubItem() const
    {
        return iSubItem;
    }

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    LPTSTR SetText(LPTSTR p_pszText, int p_cchTextMax=-1)
    {
        if (0 > p_cchTextMax)
            p_cchTextMax = _tcsclen(p_pszText);

        mask |= LVIF_TEXT;
        pszText = p_pszText;
        cchTextMax = p_cchTextMax;
        return p_pszText;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    LPTSTR GetText() const
    {
        return pszText;
    }

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    int SetImage(int p_iImage)
    {
        mask |= LVIF_IMAGE;
        return iImage = p_iImage;
    }
    /**
     **********************************************************************
     * Function: GetImage
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    int GetImage() const
    {
        return iImage;
    }

    /**
     **********************************************************************
     * Function: SetParam
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    LPARAM SetParam(LPARAM p_lParam)
    {
        mask |= LVIF_PARAM;
        return lParam = p_lParam;
    }
    /**
     **********************************************************************
     * Function: GetParam
     *
     *   Author: $author$
     *     Date: 5/22/2004
     **********************************************************************
     */
    LPARAM GetParam() const
    {
        return lParam;
    }
};

/**
 **********************************************************************
 *  Class: cWinListView
 *
 * Author: $author$
 *   Date: 5/21/2004
 **********************************************************************
 */
class cWinListView
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    /**
     **********************************************************************
     * Constructor: cWinListView
     *
     *      Author: $author$
     *        Date: 5/21/2004
     **********************************************************************
     */
    cWinListView(HINSTANCE instance=NULL, HWND handle=NULL, bool created=false) 
    : cIs(instance, handle, created) 
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE instance, HWND parent, int id, 
     int x, int y, int width, int height, 
     DWORD style=CWINLISTVIEW_DEFAULT_WINDOW_STYLE, 
     DWORD exstyle=CWINLISTVIEW_DEFAULT_WINDOW_EXSTYLE, 
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
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual HIMAGELIST SetImageList
    (HIMAGELIST image_list, 
     INT image_list_type=TVSIL_NORMAL) const
    {
        if (m_handle)
            return ListView_SetImageList
            (m_handle, image_list, image_list_type);

        return NULL;
    }
    /**
     **********************************************************************
     * Function: GetImageList
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual HIMAGELIST GetImageList
    (INT image_list_type=TVSIL_NORMAL) const
    {
        if (m_handle)
            return ListView_GetImageList
            (m_handle, image_list_type);

        return NULL;
    }

    /**
     **********************************************************************
     * Function: InsertColumn
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    virtual int InsertColumn(int index, LVCOLUMN &column)
    {
        int icolumn=-1;

        if (m_handle)
            icolumn = ListView_InsertColumn
            (m_handle, index, &column);

        return icolumn;
    }
    /**
     **********************************************************************
     * Function: DeleteColumn
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    virtual eError DeleteColumn(int index)
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (ListView_DeleteColumn(m_handle, index))
                error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: InsertItem
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual int InsertItem(LVITEM &item)
    {
        int iitem=-1;

        if (m_handle)
            iitem = ListView_InsertItem(m_handle, &item);

        return iitem;
    }
    /**
     **********************************************************************
     * Function: DeleteItem
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual eError DeleteItem(int item)
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (ListView_DeleteItem(m_handle, item))
                error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteAllItems
     *
     *   Author: $author$
     *     Date: 5/23/2004
     **********************************************************************
     */
    virtual eError DeleteAllItems()
    {
        eError error=e_ERROR_FAILED;

        if (!m_handle)
            error = e_ERROR_NOT_ATTACHED;

        else if (ListView_DeleteAllItems(m_handle))
                error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: SetItem
     *
     *   Author: $author$
     *     Date: 5/28/2004
     **********************************************************************
     */
    virtual eError SetItem(LVITEM &item)
    {
        eError error=e_ERROR_FAILED;

        if (m_handle)
        if (ListView_SetItem(m_handle, &item))
            error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: GetDefaultWindowStyle
     *
     *   Author: $author$
     *     Date: 5/21/2004
     **********************************************************************
     */
    static inline DWORD GetDefaultWindowStyle()
    {
        return CWINLISTVIEW_DEFAULT_WINDOW_STYLE;
    }
    /**
     **********************************************************************
     * Function: GetDefaultWindowExStyle
     *
     *   Author: $author$
     *     Date: 5/21/2004
     **********************************************************************
     */
    static inline DWORD GetDefaultWindowExStyle()
    {
        return CWINLISTVIEW_DEFAULT_WINDOW_EXSTYLE;
    }
    /**
     **********************************************************************
     * Function: GetWindowClassName
     *
     *   Author: $author$
     *     Date: 5/21/2004
     **********************************************************************
     */
    static inline LPCTSTR GetWindowClassName()
    {
        return WC_LISTVIEW;
    }
};

#endif /* ndef _CWINLISTVIEW_HXX */

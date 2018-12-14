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
 *   File: winim.cxx
 *
 * Author: $author$
 *   Date: 3/28/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "afxres.h"
#include "resource.h"
#include "cimage.hxx"
#include "cproperty.hxx"
#include "cwintreeviewwindow.hxx"
#include "cwincontrolwindow.hxx"
#include "cwincommoncontrol.hxx"
#include "cwinimage.hxx"
#include "cmajickimage.hxx"
#include "cwindialog.hxx"
#include "cwinwindow.hxx"
#include "cwinobject.hxx"
#include "cwinmaint.hxx"
#include "cxmldocument.hxx"

/**
 **********************************************************************
 *  Class: cWinPropertyControl
 *
 * Author: $author$
 *   Date: 4/14/2004
 **********************************************************************
 */
class cWinPropertyControl
: public cDynamicListItemT<cWinPropertyControl, cWinWindow>
{
public:
    typedef cDynamicListItemT<cWinPropertyControl, cWinWindow> cIs;

    cProperty &m_property;

    /**
     **********************************************************************
     * Constructor: cWinPropertyControl
     *
     *      Author: $author$
     *        Date: 4/14/2004
     **********************************************************************
     */
    cWinPropertyControl(cProperty &property, HWND handle=NULL)
    : m_property(property)
    {
        m_handle = handle;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual eError Get()
    {
        int length;
        const TCHAR *value;
        eError error=e_ERROR_FAILED;

        if ((value = m_property.GetValue(length)))
        if (0 <= (length = SetText(value)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual eError Set()
    {
        int length,size;
        TCHAR *value;
        eError error=e_ERROR_FAILED;
        cTCHARBuffer buffer;

        if ((value = buffer.GetWriteBuffer(size, length)))
        if (0 <= (length = GetText(value, size)))
        if (0 <= (length = m_property.SetValue(value, length)))
            error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/15/2004
     **********************************************************************
     */
    virtual eError Create
    (cProperty &property, HWND parent,
     int controlid, int x, int y, int width, int height)
    {
        int type;
        eError error;

        switch(type = property.GetType())
        {
        default:
            if (!(error = CreateTheWindow
                (_T("EDIT"), _T(""),
                 WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_AUTOHSCROLL,
                 WS_EX_CLIENTEDGE, x, y, width, height, parent, NULL,
                 m_instance, (LPVOID)controlid)))
            {
                m_created = false;
            }
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinPropertyControlList
 *
 * Author: $author$
 *   Date: 4/14/2004
 **********************************************************************
 */
class cWinPropertyControlList
: public cDynamicListT<cWinPropertyControl, cWinPropertyControlList>
{
public:
    typedef cDynamicListT<cWinPropertyControl, cWinPropertyControlList> cIs;
};

/**
 **********************************************************************
 *  Class: cWinImageObjectPropertyDialog
 *
 * Author: $author$
 *   Date: 4/11/2004
 **********************************************************************
 */
class cWinImageObjectPropertyDialog
: public cWinDialog
{
public:
    typedef cWinDialog cIs;

    cImageObject &m_object;
    cWinPropertyControlList m_property_control_list;

    /**
     **********************************************************************
     * Constructor: cWinImageObjectPropertyDialog
     *
     *      Author: $author$
     *        Date: 4/11/2004
     **********************************************************************
     */
    cWinImageObjectPropertyDialog(cImageObject &object) 
    : m_object(object) 
    {
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
        eError error;
        HWND namewnd, valuewnd;
        cWinRect windowrect, clientrect;
        cWinRect namerect, valuerect;

        if (!(error = windowrect.GetWindow(m_handle)))
        if (!(error = clientrect.GetClient(m_handle)))
        if (NULL != (namewnd = GetDlgItem(m_handle, IDC_PROPERTY_NAME)))
        if (!(error = namerect.GetWindow(namewnd)))
        if (!(error = namerect.ToClient(m_handle)))
        if (NULL != (valuewnd = GetDlgItem(m_handle, IDC_PROPERTY_VALUE)))
        if (!(error = valuerect.GetWindow(valuewnd)))
        if (!(error = valuerect.ToClient(m_handle)))
        {
            cWinRect proprect(namerect, valuerect);
            int propheight = proprect.bottom-proprect.top+1;
            int clientheight = clientrect.bottom-clientrect.top-proprect.top+1;
            int propspacing = 4;
            int propsheight = 0;
            int controlid = 1;

            int namelen;
            const TCHAR *name;
            cProperty *property;
            cWinPropertyControl *property_control;

            ShowWindow(namewnd, SW_HIDE);
            ShowWindow(valuewnd, SW_HIDE);

            if ((property = m_object.GetFirstProperty()))
            do
            {
                if ((name = property->GetName(namelen)))
                if ((namewnd = CreateWindow
                    ("STATIC",name,
                     WS_CHILD|WS_VISIBLE|SS_RIGHT,
                     namerect.left, namerect.top,
                     namerect.right-namerect.left+1,
                     namerect.bottom-namerect.top+1,
                     m_handle,NULL,m_instance,0)))
                {
                    if ((property_control = 
                        new cWinPropertyControl(*property, valuewnd)))
                    {
                        if (!(error = property_control->Create
                            (*property, m_handle, controlid,
                             valuerect.left, valuerect.top,
                             valuerect.right-valuerect.left+1,
                             valuerect.bottom-valuerect.top+1)))
                        if (!(error = property_control->Get()))
                        {
                            m_property_control_list.Add(property_control);

                            propsheight += propheight;

                            if ((property = property->GetNext()))
                            {
                                namerect.top += (propheight+propspacing);
                                namerect.bottom += (propheight+propspacing);
                                valuerect.top += (propheight+propspacing);
                                valuerect.bottom += (propheight+propspacing);
                                propsheight += propspacing;
                                controlid++;
                            }
                            continue;
                        }
                        delete property_control;
                    }
                    DestroyWindow(namewnd);
                }
                break;
            }
            while (property);

            if (propsheight > clientheight)
            {
                windowrect.bottom += (propsheight - clientheight);
                MoveWindow
                (m_handle, windowrect.left, windowrect.top, 
                 windowrect.right-windowrect.left+1,
                 windowrect.bottom-windowrect.top+1,FALSE);
            }
        }
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
        cWinPropertyControl *property_control;

        if ((property_control = m_property_control_list.GetFirst()))
        do
        {
            property_control->Set();
        }
        while ((property_control = property_control->GetNext()));
        return cIs::OnDialogOK(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 4/11/2004
     **********************************************************************
     */
    virtual int Modal(HINSTANCE instance, HWND window, int id)
    {
        int result;
        cWinRect old_rect
        (m_object.m_x, m_object.m_y,
         m_object.m_x+m_object.m_width,
         m_object.m_y+m_object.m_height);

        result = cIs::Modal(instance, window, id);

        if (IDOK == result)
        {
            cWinRect new_rect
            (m_object.m_x, m_object.m_y,
             m_object.m_x+m_object.m_width,
             m_object.m_y+m_object.m_height);
            cWinRect rect(old_rect, new_rect);

            InvalidateRect(window, &rect, TRUE);
        }
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cWinIMInterface
 *
 * Author: $author$
 *   Date: 5/13/2004
 **********************************************************************
 */
class cWinIMInterface
{
public:
    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    virtual void OnFileOpen
    (LPCTSTR filename=NULL, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetFirstObject
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual cImageObject *GetFirstObject() const = 0;
    /**
     **********************************************************************
     * Function: GetLastObjectAt
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual cImageObject *GetLastObjectAt(int x, int y) const = 0;
};

/**
 **********************************************************************
 *  Class: cWinIMTreeViewWindow
 *
 * Author: $author$
 *   Date: 5/14/2004
 **********************************************************************
 */
class cWinIMTreeViewWindow
: public cWinTreeViewWindow
{
public:
    typedef cWinTreeViewWindow cIs;

    /**
     **********************************************************************
     * Constructor: cWinIMTreeViewWindow
     *
     *      Author: $author$
     *        Date: 5/14/2004
     **********************************************************************
     */
    cWinIMTreeViewWindow() 
    {
    }
    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;

        if (!(error = m_image_list.LoadBitmap
            (m_instance, IDR_IMAGE_LIST, 20)))
            m_tree_control.SetImageList(m_image_list);

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinIMMainWindow
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cWinIMMainWindow
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    cWinIMInterface &m_winim;
    cWinWindowClass &m_window_class;
    cWinIMTreeViewWindow m_tree_view;
    int m_tree_view_width, m_tree_view_height;
    cWinMenu m_popup_menu;
    cWinPoint m_point;
    cImageObject *m_object;
    cImageObject *m_move_object;

    /**
     **********************************************************************
     * Constructor: cWinIMMainWindow
     *
     *      Author: $author$
     *        Date: 3/28/2004
     **********************************************************************
     */
    cWinIMMainWindow(cWinIMInterface &winim,cWinWindowClass &window_class)
    : m_winim(winim),
      m_window_class(window_class),
      m_object(0),
      m_move_object(0),
      m_tree_view_width(100),
      m_tree_view_height(100)
    {
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        cWinClientRect client_rect(m_handle);

        m_tree_view_width = client_rect.right-client_rect.left+1;
        m_tree_view_height = (client_rect.bottom-client_rect.top+1)/3;

        m_tree_view.Create
	    (m_tree_view.GetWindowClassName(),
         m_instance, NULL, m_handle, NULL, 
         WS_CHILD | WS_VISIBLE, 0, 0,
         client_rect.bottom-m_tree_view_height+1, 
         m_tree_view_width, m_tree_view_height);

        m_popup_menu.Create(m_instance,IDR_MAIN_POPUP);
        DragAcceptFiles(m_handle, TRUE);

        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        if (m_popup_menu.GetIsCreated())
            m_popup_menu.Destroy();

        if (m_tree_view.GetIsCreated())
            m_tree_view.Destroy();

        return cIs::OnWMDestroy(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnWMSize
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual LRESULT OnWMSize(WPARAM wparam, LPARAM lparam)
    {
        if (SIZE_RESTORED == wparam)
        if (m_tree_view.GetIsCreated())
        {
            int width=LOWORD(lparam), height=HIWORD(lparam);
            int left=0, top=0;

            if (height > m_tree_view_height)
                top = height-m_tree_view_height;

            MoveWindow
            (m_tree_view, 0,top, width, 
             m_tree_view_height, TRUE);
        }
        return cIs::OnWMSize(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnWMCommand
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCommand(WPARAM wparam, LPARAM lparam)
    {
        WORD id;

        switch(id = LOWORD(wparam))
        {
        case ID_FILE_SAVE:
            OnFileSave();
            break;

        case ID_VIEW_PROPERTIES:
            OnViewProperties();
            break;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnWMDropFiles
     *
     *   Author: $author$
     *     Date: 3/30/2004
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

        return 1;
    }
    /**
     **********************************************************************
     * Function: OnWMLButtonDown
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual LRESULT OnWMLButtonDown(WPARAM wparam, LPARAM lparam)
    {
        int x=LOWORD(lparam),y=HIWORD(lparam);
        cWinPoint point(x,y);

        if ((m_move_object = m_winim.GetLastObjectAt(x,y)))
            m_point = point;

        return cIs::OnWMLButtonDown(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMLButtonUp
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual LRESULT OnWMLButtonUp(WPARAM wparam, LPARAM lparam)
    {
        if (m_move_object)
            m_move_object = 0;

        return cIs::OnWMLButtonUp(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMMouseMove
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual LRESULT OnWMMouseMove(WPARAM wparam, LPARAM lparam)
    {
        if (m_move_object)
        {
            int x=LOWORD(lparam),y=HIWORD(lparam);
            int dx=x-m_point.x,dy=y-m_point.y;
            cWinPoint point(x,y);

            OnMoveObject(*m_move_object, dx, dy);
            m_point = point;
        }

        return cIs::OnWMMouseMove(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMRButtonDown
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
    virtual LRESULT OnWMRButtonDown(WPARAM wparam, LPARAM lparam)
    {
        eError error;
        int x=LOWORD(lparam),y=HIWORD(lparam);
        cWinPoint point(x,y);
        cWinMenu popup;
        cImageObject *object;

        if (m_popup_menu.GetIsCreated())
        {
            HMENU hmenu=m_popup_menu.GetHandle();

            if (!(error = popup.GetSubMenu(hmenu, 0)))
            if (!(error = point.ToScreen(m_handle)))
            if ((object = m_winim.GetLastObjectAt(x,y)))
            {
                LRESULT result=1;

                if (!(error = popup.TrackPopup
                    (m_handle, point.x, point.y)))
                {
                    m_object = object;
                    result = 0;
                }
                return result;
            }
        }

        return cIs::OnWMRButtonDown(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: OnFileOpened
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual void OnFileOpened()
    {
        if (m_tree_view.GetIsCreated())
        {
            cWinTreeView &tree_control=m_tree_view.GetTreeControl();
            cImageObjectInterface *object;
            cImageObjectTypeInterface *object_type;
            const char *object_type_name;

            tree_control.DeleteAllItems();

            if ((object = m_winim.GetFirstObject()))
            do
            {
                cWinTreeViewItem tree_item;

                tree_item.SetImage(1);
                tree_item.SetSelectedImage(1);

                if ((object_type = object->GetObjectType()))
                if ((object_type_name = object_type->GetName()))
                {
                    int textlen;
                    TCHAR *text;
                    cTCHARBuffer text_buffer;

                    if (0 < (textlen = text_buffer.Write(object_type_name)))
                    if ((text = text_buffer.GetWriteBuffer(textlen)))
                    {
                        tree_item.SetText(text);
                        {
                            cWinTreeViewInsert tree_insert(tree_item);

                            tree_control.InsertItem(tree_insert);
                        }
                    }
                }
            }
            while ((object = object->GetNextObject()));
        }
    }
    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 3/28/2004
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
            m_winim.OnFileOpen(filename, length);
            OnFileOpened();
        }
    }
    /**
     **********************************************************************
     * Function: OnFileSave
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual void OnFileSave()
    {
        eError error;
        int length;
        cImageObject *object;
        cGetSaveFileNameDialog ofn_dialog;

        if (m_object)
        {
            if (!(error = ofn_dialog.Modal
                (GetInstance(),GetHandle(),m_object->GetFile(length))))
                OnSaveObject(ofn_dialog.GetFileName(length),m_object);

            m_object = 0;
        }
        else
        {
            if ((object = m_winim.GetFirstObject()))
            if (!(error = ofn_dialog.Modal
                (GetInstance(),GetHandle())))
                OnSaveObject
                (ofn_dialog.GetFileName(length),object,true);
        }
    }
    /**
     **********************************************************************
     * Function: OnViewProperties
     *
     *   Author: $author$
     *     Date: 4/10/2004
     **********************************************************************
     */
    virtual void OnViewProperties()
    {
        if (m_object)
        {
            cWinImageObjectPropertyDialog prop_dialog(*m_object);

            prop_dialog.Modal
            (GetInstance(),GetHandle(),IDR_PROPERTY_DIALOG);

            m_object = 0;
        }
    }
    /**
     **********************************************************************
     * Function: OnWMPaint
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual LRESULT OnWMPaint(WPARAM wparam, LPARAM lparam)
    {
        HDC hdc;
        PAINTSTRUCT ps;
        eError error;
        cWinRect rect;

        if (!(error = rect.GetUpdate(m_handle, true)))
        if ((hdc = BeginPaint(m_handle, &ps)))
        {
            cWinDC dc(hdc);
            cWinImage im(dc);

            OnPaint(im);
            EndPaint(m_handle, &ps);
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnPaint
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    void OnPaint(cWinImage &im)
    {
        cImageObject *object;

        for (object=m_winim.GetFirstObject(); 
             object; object=object->GetNext())
            object->Paint(im);
    }

    /**
     **********************************************************************
     * Function: OnMoveObject
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual void OnMoveObject
    (cImageObject &object, int dx, int dy)
    {
        int x,y,width,height;
        eError error;
        HGDIOBJ hobj;
        HBRUSH hbrush;
        cWinRect rect;
        cWinBitmap bm;
        cWinDC fg_dc,bg_dc;
        cWinImage im(bg_dc);

        x = object.m_x;
        y = object.m_y;
        width = object.m_width;
        height = object.m_height;

        object.m_x += dx;
        object.m_y += dy;

        if (x < object.m_x)
            width += (object.m_x - x);
        else if (x > object.m_x)
        {
            width += (x - object.m_x);
            x = object.m_x;
        }

        if (y < object.m_y)
            height += (object.m_y - y);
        else if (y > object.m_y)
        {
            height += (y - object.m_y);
            y = object.m_y;
        }

        if (!(error = rect.GetClient(m_handle)))
        if (!(error = bg_dc.Create(m_handle)))
        {
            if (!(error = fg_dc.Get(m_handle)))
            {
                if (!(error = bm.Create
                    (fg_dc.GetHandle(), 
                     rect.right-rect.left,
                     rect.bottom-rect.top)))
                {
                    if (NULL != (hobj = bg_dc.SelectObject(bm.GetHandle())))
                    {
                        if (NULL != (hbrush = m_window_class.GetBackground()))
                            bg_dc.FillRect
                            (rect.left, rect.top, 
                             rect.right, rect.bottom, hbrush);

                        OnPaint(im);

                        fg_dc.BitBlt
                        (x,y,width,height,
                         bg_dc.GetHandle(),x,y);

                        bg_dc.SelectObject(hobj);
                    }
                    bm.Destroy();
                }
                fg_dc.Release();
            }
            bg_dc.Destroy();
        }
    }

    /**
     **********************************************************************
     * Function: OnSaveObject
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual void OnSaveObject
    (const char *filename, 
     cImageObject *object, 
     bool include_siblings=false)
    {
        int n,xmin,xmax,ymin,ymax;
        ImageInfo *image_info;
        Image *image;
        cImageObject *o;

        xmin = object->m_x;
        xmax = object->m_x+object->m_width-1;
        ymin = object->m_y;
        ymax = object->m_y+object->m_height-1;

        if (include_siblings)
        for (o = object->GetNext(); o; o = o->GetNext())
        {
            if (xmin > o->m_x)
                xmin = o->m_x;

            if (xmax < (n = o->m_x+o->m_width-1))
                xmax = n;

            if (ymin > o->m_y)
                ymin = o->m_y;

            if (ymax < (n = o->m_y+o->m_height-1))
                ymax = n;
        }

        SetRegisterStaticModules(RegisterStaticModules);

        InitializeMagick("");

        if ((image_info=CloneImageInfo(NULL)))
        {
            strcpy(image_info->filename,filename);

            if ((image=AllocateImage(image_info)))
            {
                cMajickImage majick(image);

                image->rows=ymax-ymin+1;
                image->columns=xmax-xmin+1;

                do
                {
                    object->Paint
                    (majick, 
                     object->m_x-xmin, 
                     object->m_y-ymin);

                    if (include_siblings)
                        continue;

                    break;
                }
                while ((object = object->GetNext()));

                WriteImage(image_info,image);
                DestroyImage(image);
            }

            DestroyImageInfo(image_info);
        }

        DestroyMagick();
    }
    /**
     **********************************************************************
     * Function: RegisterStaticModules
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
    static void RegisterStaticModules(void)
    {
        RegisterGIFImage();
    }
};

/**
 **********************************************************************
 *  Class: cWinIM
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cWinIM
: virtual public cWinIMInterface,
  public cWinMain
{
public:
    typedef cWinMain cIs;

    const char *m_window_classname;
    cWinWindowClass m_window_class;
    cWinDialog::cWindowClass m_dialog_window_class;
    cWinIMMainWindow m_window;
    cImageObjectTypes m_object_types;
    cImageObjectSet m_object_set;

    /**
     **********************************************************************
     * Constructor: cWinIM
     *
     *      Author: $author$
     *        Date: 3/28/2004
     **********************************************************************
     */
    cWinIM(const char *window_classname="cWinIM")
    : m_window_classname(window_classname),
      m_window(*this,m_window_class)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinIM
     *
     *     Author: $author$
     *       Date: 3/28/2004
     **********************************************************************
     */
    virtual ~cWinIM()
    {
    }

    /**
     **********************************************************************
     * Function: OnFileOpen
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    virtual void OnFileOpen
    (LPCTSTR filename=NULL, int length=-1)
    {
        eError error;
        cXMLDocument document;
        cElementInterface *element;
        cImageObjectType *object_type;
        cImageObject *object;

        if (!(error = document.ParseFromFile(filename)))
        if ((element = document.GetFirstElement()))
        if (!(error = m_object_set.Clear()))
        {
            do
            {
                const char *text=element->GetText();

                if ((object_type = m_object_types.Find(text)))
                if ((object = object_type->CreateObject
                    (error, m_object_set, m_object_types, *element)))
                    m_object_set.Add(object);
            }
            while ((element = element->GetNextElement()));

            m_window.Invalidate(true);
        }
    }

    /**
     **********************************************************************
     * Function: OnWinMain
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual int OnWinMain
    (HINSTANCE instance, HINSTANCE previnst,
     LPSTR cmdline, int cmdshow)
    {
        int result=0;
        eError error;
        cWinIcon icon;
        cWinBrush brush;

        if (!(error = brush.GetStock(WHITE_BRUSH)))
        if (!(error = icon.Create(instance, IDR_MAIN_WINDOW)))
        if (!(error = cWinTreeViewWindow::RegisterWindowClass(instance)))
        {
            m_window_class.SetMenu(MAKEINTRESOURCE(IDR_MAIN_WINDOW));
            m_window_class.SetIcon(icon.GetHandle());
            m_window_class.SetBackground(brush.GetHandle());

            if (!(error = m_window_class.Register
                (m_window_classname, instance, cWinWindow::WindowProc)))
            {
                if (!(error = m_dialog_window_class.Register(instance)))
                {
                    if (!(error = m_window.Create(m_window_classname, instance)))
                    {
                        OnCreate();
                        m_window.Show();
                        OnMessageLoop();
                        OnDestroy();
                        m_window.Destroy();
                    }
                    m_dialog_window_class.Unregister();
                }
                m_window_class.Unregister();
            }
            cWinTreeViewWindow::UnregisterWindowClass();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnCreate
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual void OnCreate()
    {
        cStaticImageObjectType *static_type;

        for (static_type=cStaticImageObjectType::GetFirst(); 
             static_type; static_type=static_type->GetNext())
        {
            cImageObjectType &object_type=static_type->GetObjectType();
            const char *name=object_type.GetName();

            m_object_types.Insert(&object_type);
        }
    }
    /**
     **********************************************************************
     * Function: OnDestroy
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual void OnDestroy()
    {
        m_object_set.Clear();
    }

    /**
     **********************************************************************
     * Function: GetLastObjectAt
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    virtual cImageObject *GetLastObjectAt(int x, int y) const
    {
        return GetLastObjectAt(m_object_set,x,y);
    }
    /**
     **********************************************************************
     * Function: GetLastObjectAt
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    virtual cImageObject *GetLastObjectAt
    (const cImageObjectSet &object_set, int x, int y) const
    {
        cImageObject *object,*child_object;

        if ((object = object_set.GetLast()))
        do
        {
            if ((child_object = GetLastObjectAt(*object, x,y)))
                return child_object;

            if ((x >= object->m_x) && (x < object->m_x+object->m_width))
            if ((y >= object->m_y) && (y < object->m_y+object->m_height))
                return object;
        }
        while ((object = object->GetPrevious()));

        return 0;
    }

    /**
     **********************************************************************
     * Function: GetFirstObject
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual cImageObject *GetFirstObject() const
    {
        return m_object_set.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastObject
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual cImageObject *GetLastObject() const
    {
        return m_object_set.GetLast();
    }
} g_winim;

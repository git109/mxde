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
 *   File: cwinobject.hxx
 *
 * Author: $author$
 *   Date: 1/23/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINOBJECT_HXX
#define _CWINOBJECT_HXX

#include <windows.h>
#include <tchar.h>

#include "clistt.hxx"
#include "ctcharbuffer.hxx"
#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cWinHandle
 *
 * Author: $author$
 *   Date: 1/23/2004
 **********************************************************************
 */
class cWinHandle
: public cHandleT<HANDLE, NULL>
{
public:
    typedef cHandleT<HANDLE, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinHandle
     *
     *      Author: $author$
     *        Date: 1/23/2004
     **********************************************************************
     */
    cWinHandle(HANDLE handle=NULL) 
    : cIs(handle) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinHandle
     *
     *     Author: $author$
     *       Date: 1/23/2004
     **********************************************************************
     */
    virtual ~cWinHandle()
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
};

/**
 **********************************************************************
 *  Class: cWinAtom
 *
 * Author: $author$
 *   Date: 1/24/2004
 **********************************************************************
 */
class cWinAtom
: public cHandleT<ATOM, 0>
{
public:
    typedef cHandleT<ATOM, 0> cIs;

    /**
     **********************************************************************
     * Constructor: cWinAtom
     *
     *      Author: $author$
     *        Date: 1/24/2004
     **********************************************************************
     */
    cWinAtom(ATOM atom=0) 
    : cIs(atom) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinAtom
     *
     *     Author: $author$
     *       Date: 1/24/2004
     **********************************************************************
     */
    virtual ~cWinAtom()
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 1/24/2004
     **********************************************************************
     */
};

/**
 **********************************************************************
 *  Class: cWinIcon
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinIcon
: public cCreatedHandleT<HICON, NULL>
{
public:
    typedef cCreatedHandleT<HICON, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinIcon
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinIcon(HICON icon=NULL, bool created=false) 
    : cIs(icon, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinIcon
     *
     *     Author: $author$
     *       Date: 1/25/2004
     **********************************************************************
     */
    virtual ~cWinIcon()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Create(HINSTANCE instance, WORD id)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = LoadIcon(instance, MAKEINTRESOURCE(id))))
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
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DestroyIcon(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_created = false;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinMenu
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cWinMenu
: public cCreatedHandleT<HMENU, NULL>
{
public:
    typedef cCreatedHandleT<HMENU, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinMenu
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cWinMenu(HMENU menu=NULL, bool created=false) 
    : cIs(menu, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMenu
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cWinMenu()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Create(HINSTANCE instance, WORD id)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = LoadMenu
            (instance, MAKEINTRESOURCE(id))))
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
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DestroyMenu(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_created = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetSubMenu
     *
     *   Author: $author$
     *     Date: 4/4/2004
     **********************************************************************
     */
    virtual eError GetSubMenu(HMENU menu, int pos)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = ::GetSubMenu(menu, pos)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: TrackPopup
     *
     *   Author: $author$
     *     Date: 4/4/2004
     **********************************************************************
     */
    virtual eError TrackPopup
    (HWND hwnd, int x=0, int y=0, 
     UINT flags=TPM_RIGHTBUTTON | TPM_BOTTOMALIGN | TPM_LEFTALIGN)
    {
        eError error=e_ERROR_FAILED;
        int reserved=0;
        RECT rect;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (TrackPopupMenu
            (m_handle, flags, x, y, reserved, hwnd, &rect))
            error = e_ERROR_NONE;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinPoint
 *
 * Author: $author$
 *   Date: 4/5/2004
 **********************************************************************
 */
class cWinPoint
: public POINT
{
public:
    typedef POINT cIs;

    /**
     **********************************************************************
     * Constructor: cWinPoint
     *
     *      Author: $author$
     *        Date: 4/5/2004
     **********************************************************************
     */
    cWinPoint(LONG p_x=0, LONG p_y=0) 
    {
        x = p_x;
        y = p_y;
    }
    /**
     **********************************************************************
     * Function: ToScreen
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError ToScreen(HWND hwnd)
    {
        if (ClientToScreen(hwnd, this))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Operator: =
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    cWinPoint &operator = (cWinPoint &point)
    {
        x = point.x;
        y = point.y;
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cWinRect
 *
 * Author: $author$
 *   Date: 2/28/2004
 **********************************************************************
 */
class cWinRect
: public RECT
{
public:
    typedef RECT cIs;

    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 2/28/2004
     **********************************************************************
     */
    cWinRect
    (int p_left=0, int p_top=0, int p_right=0, int p_bottom=0) 
    {
        left = p_left;
        top = p_top;
        right = p_right;
        bottom = p_bottom;
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinRect(HWND window) 
    {
        eError error;

        if (window)
        if ((error = GetWindow(window)))
            throw(error);
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 4/13/2004
     **********************************************************************
     */
    cWinRect(cWinRect &r1, cWinRect &r2)
    {
        left = r1.left;
        top = r1.top;
        right = r1.right;
        bottom = r1.bottom;

        if (left > r2.left)
            left = r2.left;

        if (top > r2.top)
            top = r2.top;

        if (right < r2.right)
            right = r2.right;

        if (bottom < r2.bottom)
            bottom = r2.bottom;
    }

    /**
     **********************************************************************
     * Function: ToClient
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    eError ToClient(HWND hwnd)
    {
        cWinPoint p1(left, top),p2(right,bottom);

        if (ScreenToClient(hwnd, &p1))
        if (ScreenToClient(hwnd, &p2))
        {
            left = p1.x;
            top =p1.y;
            right = p2.x;
            bottom = p2.y;
            return e_ERROR_NONE;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetClient
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    eError GetClient(HWND hwnd)
    {
        if (GetClientRect(hwnd, this))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetWindow
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError GetWindow(HWND hwnd)
    {
        if (GetWindowRect(hwnd, this))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetUpdate
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    eError GetUpdate(HWND hwnd, bool erase=false)
    {
        if (GetUpdateRect(hwnd, this, erase))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cWinClientRect
 *
 * Author: $author$
 *   Date: 5/12/2004
 **********************************************************************
 */
class cWinClientRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinClientRect
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinClientRect(HWND window=NULL) 
    {
        eError error;

        if (window)
        if ((error = GetClient(window)))
            throw(error);
    }
};

/**
 **********************************************************************
 *  Class: cWinDC
 *
 * Author: $author$
 *   Date: 2/28/2004
 **********************************************************************
 */
class cWinDC
: public cCreatedHandleT<HDC, NULL>
{
public:
    typedef cCreatedHandleT<HDC, NULL> cIs;

    HWND m_hwnd;

    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 2/28/2004
     **********************************************************************
     */
    cWinDC(HDC handle=NULL, bool created=false) 
    : cIs(handle, created),
      m_hwnd(NULL)
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 2/28/2004
     **********************************************************************
     */
    cWinDC(HWND hwnd, HDC handle=NULL) 
    : cIs(handle),
      m_hwnd(hwnd)
    {
        eError error;

        if (hwnd && !handle)
        if ((error = Get(hwnd)))
            throw(error);
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDC
     *
     *     Author: $author$
     *       Date: 2/28/2004
     **********************************************************************
     */
    virtual ~cWinDC()
    {
        eError error;

        if (m_created)
        if ((error = Destroy()))
            throw(error);

        if (m_hwnd)
        if ((error = Release()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError Get(HWND hwnd)
    {
        eError error=e_ERROR_FAILED;

        if (m_hwnd)
            return e_ERROR_ALREADY_CREATED;

        if ((m_handle = GetDC(hwnd)))
        {
            error = e_ERROR_NONE;
            m_hwnd = hwnd;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError Release()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (NULL == m_hwnd)
            return e_ERROR_NOT_CREATED;

        if (ReleaseDC(m_hwnd, m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_hwnd = NULL;
        return error;
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual eError Create(HWND hwnd)
    {
        eError error=e_ERROR_FAILED;
        HDC handle;

        if (m_hwnd)
            return e_ERROR_ALREADY_CREATED;

        if ((handle = GetDC(hwnd)))
        {
            if ((m_handle = CreateCompatibleDC(handle)))
            {
                error = e_ERROR_NONE;
                m_hwnd = hwnd;
                m_created = true;
            }

            ReleaseDC(hwnd, handle);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DeleteDC(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_hwnd = NULL;
        m_created = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: SelectObject
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual HGDIOBJ SelectObject(HGDIOBJ hobj)
    {
        if (m_handle)
            hobj = ::SelectObject(m_handle, hobj);
        else hobj = NULL;
        return hobj;
    }
    /**
     **********************************************************************
     * Function: FillRect
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError FillRect
    (int left, int top, int right, int bottom, HBRUSH hbrush)
    {
        eError error=e_ERROR_NOT_ATTACHED;

        if (m_handle)
        {
            cWinRect rect(left, top, right, bottom);

            if (::FillRect(m_handle, &rect, hbrush))
                return e_ERROR_NONE;

            error = e_ERROR_FAILED;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: BitBlt
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError BitBlt
    (int x, int y, int width, int height, 
     HDC hdc, int dc_x, int dc_y, DWORD rop=SRCCOPY)
    {
        eError error=e_ERROR_NOT_ATTACHED;

        if (m_handle)
        {
            if (::BitBlt
                (m_handle, x, y, width, height, 
                 hdc, dc_x, dc_y, rop))
                return e_ERROR_NONE;

            error = e_ERROR_FAILED;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinGDIObject
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinGDIObject
: public cCreatedHandleT<HGDIOBJ, NULL>
{
public:
    typedef cCreatedHandleT<HGDIOBJ, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinGDIObject
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinGDIObject(HGDIOBJ handle=NULL, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinGDIObject
     *
     *     Author: $author$
     *       Date: 1/25/2004
     **********************************************************************
     */
    virtual ~cWinGDIObject()
    {
        eError error;

        if (m_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: GetStock
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError GetStock(int id)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = GetStockObject(id)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DeleteObject(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_created = false;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinBitmap
 *
 * Author: $author$
 *   Date: 4/8/2004
 **********************************************************************
 */
class cWinBitmap
: public cHandleIsHandleT<HBITMAP, NULL, cWinGDIObject>
{
public:
    typedef cHandleIsHandleT<HBITMAP, NULL, cWinGDIObject> cIs;

    /**
     **********************************************************************
     * Constructor: cWinBitmap
     *
     *      Author: $author$
     *        Date: 4/8/2004
     **********************************************************************
     */
    cWinBitmap(HBITMAP handle=NULL, bool created=false) 
    : cIs(handle, created) 
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual eError Create(HDC hdc, int width, int height)
    {
        eError error=e_ERROR_FAILED;
        HBITMAP handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (handle = CreateCompatibleBitmap
            (hdc, width, height)))
        {
            if ((error = Attach(handle)))
                DeleteObject(handle);
            else
            {
                m_created = true;
                error = e_ERROR_NONE;
            }
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Load
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual eError Load
    (HINSTANCE instance, LPCTSTR name)
    {
        eError error=e_ERROR_FAILED;
        HBITMAP handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (handle = LoadBitmap(instance, name)))
        {
            if ((error = Attach(handle)))
                DeleteObject(handle);
            else
            {
                m_created = true;
                error = e_ERROR_NONE;
            }
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Load
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    inline eError Load(HINSTANCE instance, int id)
    {
        return Load(instance, MAKEINTRESOURCE(id));
    }
};

/**
 **********************************************************************
 *  Class: cWinBrush
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinBrush
: public cHandleIsHandleT<HBRUSH, NULL, cWinGDIObject>
{
public:
    typedef cHandleIsHandleT<HBRUSH, NULL, cWinGDIObject> cIs;

    /**
     **********************************************************************
     * Constructor: cWinBrush
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinBrush(HBRUSH handle=NULL, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinBrush
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinBrush(int id) 
    {
        eError error;

        if ((error = GetStock(id)))
            throw(error);
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinBrush
     *
     *      Author: $author$
     *        Date: 3/29/2007
     **********************************************************************
     */
    virtual ~cWinBrush()
    {
    }

    /**
     **********************************************************************
     * Function: GetStock
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError GetStock(int id)
    {
        eError error;

        if (!(error = cIs::GetStock(id)))
            m_handle = (HBRUSH)cHandleIs::GetHandle();

        return error;
    }
    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError CreateSolid(BYTE red, BYTE green, BYTE blue)
    {
        return CreateSolid(RGB(red, green, blue));
    }
    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError CreateSolid(COLORREF color)
    {
        eError error=e_ERROR_FAILED;
        HBRUSH handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (handle = CreateSolidBrush(color)))
        {
            if ((error = Attach(handle)))
                DeleteObject(handle);
            else
            {
                m_created = true;
                error = e_ERROR_NONE;
            }
        }

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinWindowClass
 *
 * Author: $author$
 *   Date: 1/23/2004
 **********************************************************************
 */
class cWinWindowClass
: public cWinAtom
{
public:
    typedef cWinAtom cIs;

    WNDCLASSEX m_wndclass;
    cTCHARBuffer m_classname;

    /**
     **********************************************************************
     * Constructor: cWinWindowClass
     *
     *      Author: $author$
     *        Date: 1/23/2004
     **********************************************************************
     */
    cWinWindowClass(ATOM atom=0) 
    : cIs(atom) 
    {
        memset(&m_wndclass, 0, sizeof(m_wndclass));
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowClass
     *
     *     Author: $author$
     *       Date: 1/23/2004
     **********************************************************************
     */
    virtual ~cWinWindowClass()
    {
    }
    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual eError Register
    (LPCTSTR classname, HINSTANCE instance, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0)
    {
        int count;

        m_wndclass.cbSize=sizeof(m_wndclass);
        m_wndclass.lpszClassName=classname;
        m_wndclass.cbClsExtra=clsextra;
        m_wndclass.cbWndExtra=wndextra;

        if (NULL != menuname)
            m_wndclass.lpszMenuName=menuname;

        if (NULL != icon)
            m_wndclass.hIcon = icon;

        if (NULL != iconsm)
            m_wndclass.hIconSm = iconsm;

        if (NULL != cursor)
            m_wndclass.hCursor = cursor;

        else if (NULL == m_wndclass.hCursor)
                m_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

        if (NULL != background)
            m_wndclass.hbrBackground = background;

        else if (NULL == m_wndclass.hbrBackground)
                m_wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

        if (NULL != wndproc)
            m_wndclass.lpfnWndProc = wndproc;

        else if (NULL == m_wndclass.lpfnWndProc)
                m_wndclass.lpfnWndProc = DefWindowProc;

        m_wndclass.style=style;
        m_wndclass.hInstance=instance;

        if (0 < (count = SetClassName(classname)))
        if ((m_wndclass.lpszClassName = GetClassName()))
        if (NULL != (m_handle = RegisterClassEx(&m_wndclass)))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Unregister
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual eError Unregister()
    {
        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (UnregisterClass
            (m_wndclass.lpszClassName, m_wndclass.hInstance))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: SetMenu
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual LPCTSTR SetMenu(LPCTSTR menu_name)
    {
        m_wndclass.lpszMenuName = menu_name;
        return m_wndclass.lpszMenuName;
    }
    /**
     **********************************************************************
     * Function: GetMenu
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual LPCTSTR GetMenu() const
    {
        return m_wndclass.lpszMenuName;
    }
    /**
     **********************************************************************
     * Function: SetIcon
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HICON SetIcon(HICON icon)
    {
        return m_wndclass.hIcon = icon;
    }
    /**
     **********************************************************************
     * Function: GetIcon
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HICON GetIcon() const
    {
        return m_wndclass.hIcon;
    }
    /**
     **********************************************************************
     * Function: SetBackground
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HBRUSH SetBackground(HBRUSH background)
    {
        return m_wndclass.hbrBackground = background;
    }
    /**
     **********************************************************************
     * Function: GetBackground
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual HBRUSH GetBackground() const
    {
        return m_wndclass.hbrBackground;
    }
    /**
     **********************************************************************
     * Function: SetClassName
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual int SetClassName(LPCTSTR classname)
    {
        int length;
        LPCTSTR old_classname=m_classname.GetBuffer(length);

        if (classname != old_classname)
            length = m_classname.Copy(classname);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetClassName
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual LPCTSTR GetClassName() const
    {
        return m_classname.GetBuffer();
    }
};

/**
 **********************************************************************
 *  Class: cWinWindowSubclass
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinWindowSubclass
: public cWinWindowClass
{
public:
    typedef cWinWindowClass cIs;

    /**
     **********************************************************************
     * Constructor: cWinWindowSubclass
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinWindowSubclass() 
    : cWinWindowClass() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowSubclass
     *
     *     Author: $author$
     *       Date: 1/25/2004
     **********************************************************************
     */
    virtual ~cWinWindowSubclass()
    {
    }
    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Register
    (LPCTSTR super_classname, HINSTANCE super_instance,
     LPCTSTR classname, HINSTANCE instance, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=0, int clsextra=0)
    {
        int count;

        if (GetClassInfoEx
            (super_instance, super_classname, &m_wndclass))

        if (0 < (count = m_classname.Copy(classname)))

        if ((m_wndclass.lpszClassName = m_classname.GetBuffer()))
        {
            m_wndclass.hInstance=instance;

            if (menuname)
                m_wndclass.lpszMenuName=menuname;

            if (clsextra > 0)
                m_wndclass.cbClsExtra += clsextra;

            if (wndextra > 0)
                m_wndclass.cbWndExtra += wndextra;

            if (icon)
                m_wndclass.hIcon=icon;

            if (iconsm)
                m_wndclass.hIconSm=iconsm;

            if (cursor)
                m_wndclass.hCursor=cursor;

            if (background)
                m_wndclass.hbrBackground=background;

            if (wndproc)
                m_wndclass.lpfnWndProc=wndproc;

            if (style)
                m_wndclass.style=style;

            if (NULL != (m_handle = RegisterClassEx(&m_wndclass)))
                return e_ERROR_NONE;
        }

        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cGetOpenFileNameDialog
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cGetOpenFileNameDialog
{
public:
    OPENFILENAME m_ofn;
    cTCHARBuffer m_filename;

    /**
     **********************************************************************
     * Constructor: cGetOpenFileNameDialog
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cGetOpenFileNameDialog() 
    {
        memset(&m_ofn, 0, sizeof(m_ofn));
        m_ofn.lStructSize = sizeof(m_ofn);
    }
    /**
     **********************************************************************
     * Destructor: ~cGetOpenFileNameDialog
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cGetOpenFileNameDialog()
    {
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Modal
    (HINSTANCE instance, HWND window, 
     LPCTSTR filename=NULL, int filenamelen=-1)
    {
        eError error=e_ERROR_FAILED;

        if (!(error = Ready
            (instance, window, filename, filenamelen)))
        if (GetOpenFileName(&m_ofn))
        {
            m_filename.SetLength(-1);
            error = e_ERROR_NONE;
        }
        else error=e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Ready
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Ready
    (HINSTANCE instance, HWND window, 
     LPCTSTR filename=NULL, int filenamelen=-1)
    {
        eError error=e_ERROR_NONE;

        if (NULL != filename)
        {
            if (0 > (filenamelen = m_filename.Copy
                (filename, filenamelen)))
                return error = -filenamelen;
        }

        m_ofn.hwndOwner = window;
        m_ofn.hInstance = instance;
        m_ofn.lpstrFile = m_filename.GetWriteBuffer();
        m_ofn.nMaxFile = m_filename.GetSize()-1;
        m_ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
        m_ofn.Flags = OFN_NOCHANGEDIR|OFN_SHOWHELP;
        return error;
    }

    /**
     **********************************************************************
     * Function: Ready
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    LPCTSTR GetFileName(int &length) const
    {
        return m_filename.GetBuffer(length);
    }
};

/**
 **********************************************************************
 *  Class: cGetSaveFileNameDialog
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cGetSaveFileNameDialog
: public cGetOpenFileNameDialog
{
public:
    typedef cGetOpenFileNameDialog cIs;

    /**
     **********************************************************************
     * Constructor: cGetSaveFileNameDialog
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cGetSaveFileNameDialog() 
    : cGetOpenFileNameDialog() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cGetSaveFileNameDialog
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cGetSaveFileNameDialog()
    {
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Modal
    (HINSTANCE instance, HWND window, 
     LPCTSTR filename=NULL, int filenamelen=-1)
    {
        eError error=e_ERROR_FAILED;

        if (!(error = Ready
            (instance, window, filename, filenamelen)))
        if (GetSaveFileName(&m_ofn))
        {
            m_filename.SetLength(-1);
            error = e_ERROR_NONE;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cWinDropFiles
 *
 * Author: $author$
 *   Date: 3/30/2004
 **********************************************************************
 */
class cWinDropFiles
: public cOpenedHandleT<HDROP,  NULL>
{
public:
    typedef cOpenedHandleT<HDROP,  NULL> cIs;

    /**
     **********************************************************************
     *  Class: cItem
     *
     * Author: $author$
     *   Date: 3/31/2004
     **********************************************************************
     */
    class cItem
    : public cDynamicListItemT<cItem>
    {
    public:
        typedef cDynamicListItemT<cItem> cIs;

        cTCHARBuffer m_name_buffer;

        /**
         **********************************************************************
         * Constructor: cItem
         *
         *      Author: $author$
         *        Date: 3/31/2004
         **********************************************************************
         */
        cItem() 
        {
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 3/31/2004
         **********************************************************************
         */
        eError Get(HDROP hdrop, UINT index)
        {
            eError error=e_ERROR_FAILED;
            LPTSTR name;
            UINT length;
            int count;

            length = DragQueryFile(hdrop, index, NULL, 0);

            if ((0 < length) && (((UINT)-1) > length))
            {
                if ((length >= (UINT)m_name_buffer.GetSize()))
                if (0 > (count = m_name_buffer.SetSize(length+2)))
                    return error=-count;

                if (NULL != (name = m_name_buffer.GetWriteBuffer()))
                {
                    length = DragQueryFile(hdrop, index, name, length+1);

                    if ((0 < length) && (((UINT)-1) > length))
                    {
                        if (0 > (count = m_name_buffer.SetLength(length)))
                            return error=-count;

                        error = e_ERROR_NONE;
                    }
                }
            }
            return error;
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 3/31/2004
         **********************************************************************
         */
        inline LPCTSTR GetName(int &length) const
        {
            return m_name_buffer.GetBuffer(length);
        }
    };

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 3/31/2004
     **********************************************************************
     */
    class cList
    : public cDynamicListT<cItem, cList>
    {
    public:
        typedef cDynamicListT<cItem, cList> cIs;

    };

    UINT m_count;
    cList m_list;

    /**
     **********************************************************************
     * Constructor: cWinDropFiles
     *
     *      Author: $author$
     *        Date: 3/30/2004
     **********************************************************************
     */
    cWinDropFiles(HDROP handle=NULL, bool opened=false) 
    : cIs(handle, opened),
      m_count(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDropFiles
     *
     *     Author: $author$
     *       Date: 3/30/2004
     **********************************************************************
     */
    virtual ~cWinDropFiles()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);

        if (NULL != m_handle)
        if ((error = Detach()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual eError Open(HDROP hdrop, UINT max_count=0)
    {
        eError error;
        cItem *item;

        if (!(error = Attach(hdrop, true)))
        {
            m_count = DragQueryFile(m_handle, -1, NULL, 0);

            if ((0 < m_count) && (((UINT)-1) > m_count))
            {
                if ((0 < max_count) && (max_count < m_count))
                    m_count = max_count;

                for (UINT i=0; i<m_count; i++)
                {
                    if ((item = new cItem()))
                    {
                        if ((error = item->Get(m_handle, i)))
                        {
                            delete item;
                            return error;
                        }

                        m_list.Add(item);
                    }
                }
            }
        }
        
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error=e_ERROR_NONE;

        if (!m_opened)
            return e_ERROR_NOT_OPEN;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((error = m_list.Clear()))
            return error;

        DragFinish(m_handle);
        m_opened = false;
        m_handle = NULL;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetFirstItem
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    inline cItem *GetFirstItem() const
    {
        return m_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetCount
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    inline UINT GetCount() const
    {
        return m_count;
    }
};

#endif /* ndef _CWINOBJECT_HXX */

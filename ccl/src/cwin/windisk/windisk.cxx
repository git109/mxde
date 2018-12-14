/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: windisk.cxx
 *
 * Author: $author$
 *   Date: 1/21/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "ieee80215_network_device.h"
#include "ieee80215_network.h"
#include "ieee80215_device.h"

#include "cthreadinstance.hxx"
#include "cthread.hxx"
#include "cevent.hxx"
#include "ccomm.hxx"

#include "cwinimage.hxx"
#include "cimageinterface.hxx"
#include "resource.h"
#include "cwindialog.hxx"
#include "cwinmain.hxx"
#include "cwinwindowt.hxx"
#include "printf.h"

HWND g_hwnd = 0;

/**
 **********************************************************************
 * Function: Printf
 *
 *   Author: $author$
 *     Date: 1/18/2006
 **********************************************************************
 */
int Printf(const char* format, ...)
{
    int count = 0;
    return count;
}

/**
 **********************************************************************
 * Function: s_ieee80215_network_on_connected
 *
 *   Author: $author$
 *     Date: 8/12/2005
 **********************************************************************
 */
void s_ieee80215_network_on_connected(void ) 
{
    PostMessage
    (g_hwnd, WM_COMMAND, 
     MAKEWPARAM(IDC_CONNECTED, ID_CONNECTED), 0);
}
/**
 **********************************************************************
 * Function: s_ieee80215_network_on_disconnect
 *
 *   Author: $author$
 *     Date: 8/12/2005
 **********************************************************************
 */
void s_ieee80215_network_on_disconnect(void ) 
{
    PostMessage
    (g_hwnd, WM_COMMAND, 
     MAKEWPARAM(IDC_CONNECTED, ID_DISCONNECTED), 0);
}

/**
 **********************************************************************
 * Function: ieee80215_network_on_initialize
 *
 *   Author: $author$
 *     Date: 1/31/2006
 **********************************************************************
 */
void ieee80215_network_on_initialize(void)
{

    ieee80215_network_BeaconRXTimeout = 250;

    ieee80215_network_set_on_connected
    (s_ieee80215_network_on_connected);

    ieee80215_network_set_on_disconnect
    (s_ieee80215_network_on_disconnect);

}

/**
 **********************************************************************
 * Function: ieee80215_device_on_sleep
 *
 *   Author: $author$
 *     Date: 1/20/2006
 **********************************************************************
 */
void ieee80215_device_on_sleep(void) 
{
    PostMessage
    (g_hwnd, WM_COMMAND, 
     MAKEWPARAM(IDC_AWAKE, ID_ASLEEP), 0);
}
/**
 **********************************************************************
 * Function: ieee80215_device_on_wakeup
 *
 *   Author: $author$
 *     Date: 1/20/2006
 **********************************************************************
 */
void ieee80215_device_on_wakeup(void) 
{
    PostMessage
    (g_hwnd, WM_COMMAND, 
     MAKEWPARAM(IDC_AWAKE, ID_AWAKE), 0);
}

/**
 **********************************************************************
 *  Class: cTestThread
 *
 * Author: $author$
 *   Date: 1/19/2006
 **********************************************************************
 */
class cTestThread
: public cThreadInstance
{
public:
    typedef cThreadInstance cIs;

    cEvent m_event_done;

    /**
     **********************************************************************
     * Constructor: cTestThread
     *
     *      Author: $author$
     *        Date: 1/19/2006
     **********************************************************************
     */
    cTestThread() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cTestThread
     *
     *      Author: $author$
     *        Date: 1/19/2006
     **********************************************************************
     */
    virtual ~cTestThread()
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    virtual void OnRun() 
    {
        PostMessage
        (g_hwnd, WM_COMMAND, 
         MAKEWPARAM(IDOK, ID_ALIVE), 0);

        platform_forever = 1;
        platform_void_main();
        m_event_done.Wait();

        PostMessage
        (g_hwnd, WM_COMMAND, 
         MAKEWPARAM(IDOK, ID_DEAD), 0);
    }

    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    virtual eError Start(HWND hwnd) 
    {
        eError error;

        if (!(error = m_event_done.Create()))
        {
            g_hwnd = hwnd;

            if ((error = cIs::Start()))
            {
                m_event_done.Close();
                g_hwnd = 0;
            }
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Stop
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    virtual eError Stop() 
    {
        eError error = m_event_done.Set();
        platform_forever = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    virtual eError Finish() 
    {
        eError error, error2;

        error = cIs::Finish();

        if ((error2 = m_event_done.Close()))
        if (!error)
            error = error2;

        g_hwnd = 0;
        return error;
    }
} g_thread;

/**
 **********************************************************************
 *  Class: cWinDiskDialog
 *
 * Author: $author$
 *   Date: 1/21/2006
 **********************************************************************
 */
class cWinDiskDialog
: public cWinDialog
{
public:
    typedef cWinDialog cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/29/2006
     **********************************************************************
     */
    enum
    {
        e_FIRST_BUTTON = 0,

        e_BUTTON_OK = e_FIRST_BUTTON,
        e_BUTTON_CANCEL,
        e_BUTTON_AWAKE,
        e_BUTTON_CONNECTED,
        e_BUTTON_EJECT,
        e_BUTTON_ACCESS,

        e_NEXT_BUTTON,
        e_LAST_BUTTON = e_NEXT_BUTTON-1
    };

    cWinBitmap m_bitmap[e_NEXT_BUTTON];

    /**
     **********************************************************************
     * Function: DoStartTest
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    bool DoStartTest()
    {
        bool started = true;
        eError error;

        if ((error = g_thread.Start(m_handle)))
            started = false;

        return started;
    }
    /**
     **********************************************************************
     * Function: DoStopTest
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    bool DoStopTest()
    {
        bool stopping = true;

        eError error;

        if ((error = g_thread.Stop()))
            stopping = false;

        return stopping;
    }
    /**
     **********************************************************************
     * Function: DoFinishTest
     *
     *   Author: $author$
     *     Date: 1/19/2006
     **********************************************************************
     */
    bool DoFinishTest()
    {
        bool finished = true;
        eError error;

        if ((error = g_thread.Finish()))
            finished = false;

        return finished;
    }

    /**
     **********************************************************************
     * Function: OnFinishDialog
     *
     *   Author: $author$
     *     Date: 1/31/2006
     **********************************************************************
     */
    virtual BOOL OnFinishDialog
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        DestroyBitmaps();
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: OnDialog
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual BOOL OnDialog(WPARAM wparam, LPARAM lparam)
    {
        UINT ctl;

        switch((ctl = LOWORD(wparam)))
        {
        case IDC_AWAKE:
            switch(HIWORD(wparam))
            {
            case ID_AWAKE:
                SetDlgItemInt(m_handle, ctl, 1, FALSE);
                break;

            case ID_ASLEEP:
                SetDlgItemInt(m_handle, ctl, 0, FALSE);
                break;
            }
            break;

        case IDC_CONNECTED:
            switch(HIWORD(wparam))
            {
            case ID_CONNECTED:
                SetDlgItemInt(m_handle, ctl, 1, FALSE);
                break;

            case ID_DISCONNECTED:
                SetDlgItemInt(m_handle, ctl, 0, FALSE);
                break;
            }
            break;
        }
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnDialogOK
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual BOOL OnDialogOK(WPARAM wparam, LPARAM lparam)
    {
        BOOL ok;
        UINT code;
        UINT on = GetDlgItemInt(m_handle, IDOK, &ok, FALSE);

        if (1 < on)
        {
            switch((code = HIWORD(wparam)))
            {
            case ID_ALIVE:
                SetDlgItemInt(m_handle, IDOK, 1, FALSE);
                break;

            case ID_DEAD:
                if (DoFinishTest())
                {
                    SetDlgItemInt(m_handle, IDOK, 0, FALSE);
                    SetDlgItemInt(m_handle, IDCANCEL, 0, FALSE);
                }
                break;
            }
        }
        else if (on)
        {
            if (DoStopTest())
                SetDlgItemInt(m_handle, IDOK, 2, FALSE);
        }
        else if (DoStartTest())
        {
            SetDlgItemInt(m_handle, IDCANCEL, 1, FALSE);
            SetDlgItemInt(m_handle, IDOK, 2, FALSE);
        }
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnDialogCancel
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual BOOL OnDialogCancel(WPARAM wparam, LPARAM lparam)
    {
        BOOL ok;
        UINT on = GetDlgItemInt(m_handle, IDOK, &ok, FALSE);

        if (on)
            return TRUE;

        return cIs::OnDialogCancel(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnDialogDestroy
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual BOOL OnDialogDestroy(WPARAM wparam, LPARAM lparam)
    {
        PostQuitMessage(0);
        cIs::OnDialogDestroy(wparam, lparam);
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnDrawItem
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnDrawItem
    (DRAWITEMSTRUCT& dis, WPARAM wparam)
    {
        cWinBitmap& bm = GetBitmap(dis);
        cWinDC dc(dis.hDC);
        cWinDC sdc;
        eError error;
        HGDIOBJ hob;
        BOOL ok;
        int x = 0;

        if (!bm.GetIsCreated())
        {
            if ((error = CreateBitmap(bm, dis)))
                return FALSE;
            SetDlgItemInt(m_handle, dis.CtlID, 0, FALSE);
        }
        else if (GetDlgItemInt(m_handle, dis.CtlID, &ok, FALSE))
                x = bm.m_width/2;

        if (!(error = sdc.Create(dis.hDC)))
        {
            hob = sdc.SelectObject(bm.GetHandle());
            dc.BitBlt
            (0,0, bm.m_width/2,bm.m_height, 
             sdc.m_handle, x,0, SRCCOPY);
            sdc.SelectObject(hob);
            sdc.Destroy();
        }
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: DestroyBitmaps
     *
     *   Author: $author$
     *     Date: 1/31/2006
     **********************************************************************
     */
    virtual eError DestroyBitmaps() 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        int bm;

        for (bm=e_FIRST_BUTTON; bm<e_NEXT_BUTTON; bm++)
        {
            cWinBitmap& bitmap = m_bitmap[bm];

            if (bitmap.GetIsCreated())
            if ((error2 = bitmap.Destroy()))
            if (!error)
                error = error2;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateBitmap
     *
     *   Author: $author$
     *     Date: 1/29/2006
     **********************************************************************
     */
    virtual eError CreateBitmap
    (cWinBitmap& bm, DRAWITEMSTRUCT& dis) 
    {
        eError error;
        cWinDC sdc;
        cWinDC tdc;
        cWinImage tim(tdc);
        cWinClientRect rect(dis.hwndItem);
        cWinWindowToClientRect wrect(dis.hwndItem);
        int width = rect.right-rect.left;
        int height = rect.bottom-rect.top;
        int x = height/2;
        int y = height/2;
        int wx = wrect.left;
        int wy = wrect.top;
        int r = 128;
        int g = 128;
        int b = 128;
        int r1 = 128;
        int g1 = 128;
        int b1 = 128;
        HGDIOBJ hob;
        cImageInterface *color;
        cImageInterface *shape;
        cImageInterface *old;

        GetBitmapColor(r, g, b, r1, g1, b1, dis);

        if (!(error = tdc.Create(dis.hDC)))
        {
            if (!(error = bm.Create
                (dis.hDC, width*2, height)))
            {
                hob = tdc.SelectObject(bm.GetHandle());

                if (!(error = sdc.Get(m_handle)))
                {
                    tdc.BitBlt(0,0, width,height, sdc.m_handle, wx,wy);
                    tdc.BitBlt(width,0, width,height, sdc.m_handle, wx,wy);
                    sdc.Release();
                }

                if ((color = tim.CreateColorImage(1, 1, 0, 0, 0)))
                {
                    if ((shape = tim.CreateFilledCircleImage(*color, y)))
                    {
                        old = tim.SetImage(shape);
                        tim.Fill(x, y, width-height, 1);
                        tim.Fill(x+width, y, width-height, 1);
                        tim.SetImage(old);
                        tim.DestroyImage(*shape);
                    }
                    tim.DestroyImage(*color);
                }

                if ((color = tim.CreateColorImage(1, 1, r, g, b)))
                {
                    if ((shape = tim.CreateFilledCircleImage(*color, y-2)))
                    {
                        old = tim.SetImage(shape);
                        tim.Fill(x, y, width-height, 1);
                        tim.SetImage(old);
                        tim.DestroyImage(*shape);
                    }
                    tim.DestroyImage(*color);
                }

                if ((color = tim.CreateColorImage(1, 1, r1, g1, b1)))
                {
                    if ((shape = tim.CreateFilledCircleImage(*color, y-2)))
                    {
                        old = tim.SetImage(shape);
                        tim.Fill(x+width, y, width-height, 1);
                        tim.SetImage(old);
                        tim.DestroyImage(*shape);
                    }
                    tim.DestroyImage(*color);
                }

                tdc.SelectObject(hob);
            }
            tdc.Destroy();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetBitmapColor
     *
     *   Author: $author$
     *     Date: 1/29/2006
     **********************************************************************
     */
    virtual void GetBitmapColor
    (int &r, int &g, int &b, 
     int &r1, int &g1, int &b1, 
     DRAWITEMSTRUCT& dis) 
    {
        r = 128;
        g = 128;
        b = 128;

        r1 = 96;
        g1 = 255;
        b1 = 96;

        switch(dis.CtlID)
        {
        case IDOK:
            r = 64;
            g = 255;
            b = 64;
            r1 = 255;
            g1 = 255;
            b1 = 64;
            break;

        case IDCANCEL:
            r = 255;
            g = 64;
            b = 64;
            r1 = 128;
            g1 = 128;
            b1 = 128;
            break;

        case IDC_AWAKE:
            break;

        case IDC_CONNECTED:
            break;

        case IDC_EJECT:
            break;

        case IDC_ACCESS:
            break;
        }
    }
    /**
     **********************************************************************
     * Function: GetBitmap
     *
     *   Author: $author$
     *     Date: 1/29/2006
     **********************************************************************
     */
    virtual cWinBitmap& GetBitmap(DRAWITEMSTRUCT& dis) 
    {
        switch(dis.CtlID)
        {
        case IDOK:
            return m_bitmap[e_BUTTON_OK];

        case IDCANCEL:
            return m_bitmap[e_BUTTON_CANCEL];

        case IDC_AWAKE:
            return m_bitmap[e_BUTTON_AWAKE];

        case IDC_CONNECTED:
            return m_bitmap[e_BUTTON_CONNECTED];

        case IDC_EJECT:
            return m_bitmap[e_BUTTON_EJECT];

        case IDC_ACCESS:
            return m_bitmap[e_BUTTON_ACCESS];
        }
        return m_bitmap[e_FIRST_BUTTON];
    }
};

/**
 **********************************************************************
 *  Class: cControlWindow
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cControlWindow
: public cWinWindowT<cControlWindow>
{
public:
    typedef cWinWindowT<cControlWindow> cIs;

    /**
     **********************************************************************
     * Constructor: cControlWindow
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cControlWindow() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cControlWindow
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    virtual ~cControlWindow()
    {
    }
    /**
     **********************************************************************
     * Function: OnWMEraseBackground
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual LRESULT OnWMEraseBackground(WPARAM wparam, LPARAM lparam)
    {
        return DoOnWMEraseBackground(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMNCPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual LRESULT OnWMNCPaint(WPARAM wparam, LPARAM lparam)
    {
        return DoOnWMNCPaint(wparam, lparam, FALSE);
    }
    /**
     **********************************************************************
     * Function: OnWMPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual LRESULT OnWMPaint(WPARAM wparam, LPARAM lparam)
    {
        return DoOnWMPaint(wparam, lparam, FALSE);
    }
    /**
     **********************************************************************
     * Function: OnEraseBackground
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnEraseBackground(HDC hdc, RECT& rect)
    {
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnNCPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnNCPaint(HDC hdc, RECT& rect)
    {
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnPaint
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual BOOL OnPaint(HDC hdc, RECT& rect)
    {
        cWinDC dc(hdc);
        cWinImage im(dc);
        cImageInterface *color;
        cImageInterface *old;
        int c = 96;

        if ((color = im.CreateColorImage(1, 1, c, c, c)))
        {
            old = im.SetImage(color);
            im.Fill
            (rect.left,rect.top, 
             rect.right-rect.left, rect.bottom-rect.top);
            im.SetImage(old);
            im.DestroyImage(*color);
        }
        return TRUE;
    }
};

/**
 **********************************************************************
 *  Class: cWinDisk
 *
 * Author: $author$
 *   Date: 1/21/2006
 **********************************************************************
 */
class cWinDisk
: public cWinMain
{
public:
    typedef cWinMain cIs;

    const TCHAR* m_control_classname;
    cWinWindowClass m_control_class;
    cControlWindow m_control;
    cWinDialogWindowClass m_dialog_window_class;
    cWinDiskDialog m_dialog;

    /**
     **********************************************************************
     * Constructor: cWinDisk
     *
     *      Author: $author$
     *        Date: 1/21/2006
     **********************************************************************
     */
    cWinDisk(const TCHAR* control_classname=_T("cWinControl")) 
    : m_control_classname(control_classname)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDisk
     *
     *      Author: $author$
     *        Date: 1/21/2006
     **********************************************************************
     */
    virtual ~cWinDisk()
    {
    }
    /**
     **********************************************************************
     * Function: OnWinMain
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    virtual int OnWinMain
    (HINSTANCE instance, HINSTANCE previnst,
     LPCMDLINE cmdline, int cmdshow) 
    {
        int result = 0;
        eError error;

        if (!(error = m_control_class.Register
            (m_control_classname, instance, 
             cControlWindow::CreateInstanceWindowProc)))
        {
            if (!(error = m_dialog_window_class.Register(instance)))
            {
                if (!(error = m_dialog.Create
                    (instance, GetDesktopWindow(), IDR_WINDISK)))
                {
                    m_dialog.Show();
                    OnMessageLoop();
                    m_dialog.Destroy();
                }
                m_dialog_window_class.Unregister();
            }
            m_control_class.Unregister();
        }
        return result;
    }
};

cWinDisk g_windisk;

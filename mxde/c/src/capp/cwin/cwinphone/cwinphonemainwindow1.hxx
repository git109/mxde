/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwinphonemainwindow.hxx
 *
 * Author: $author$
 *   Date: 5/30/2009
 **********************************************************************
 */
#ifndef _CWINPHONEMAINWINDOW_HXX
#define _CWINPHONEMAINWINDOW_HXX

#include "cwinwindowclass.hxx"
#include "cwinwindow.hxx"
#include "cwincolorref.hxx"
#include "cwinimageobject.hxx"
#include "cwinimage.hxx"

#define CWINPHONEMAINWINDOW_CORNER_RADIUS 25

#define CWINPHONEMAINWINDOW_CLIENT_LEFT 10
#define CWINPHONEMAINWINDOW_CLIENT_TOP 32
#define CWINPHONEMAINWINDOW_CLIENT_BOTTOM 96
#define CWINPHONEMAINWINDOW_CLIENT_WIDTH 320
#define CWINPHONEMAINWINDOW_CLIENT_HEIGHT 480

#define CWINPHONEMAINWINDOW_WIDTH \
    CWINPHONEMAINWINDOW_CLIENT_WIDTH \
    + (CWINPHONEMAINWINDOW_CLIENT_LEFT * 2)

#define CWINPHONEMAINWINDOW_HEIGHT \
    CWINPHONEMAINWINDOW_CLIENT_HEIGHT \
    + CWINPHONEMAINWINDOW_CLIENT_TOP \
    + CWINPHONEMAINWINDOW_CLIENT_BOTTOM

#define CWINPHONEMAINWINDOW_CLIENT_COLOR_R 0x66
#define CWINPHONEMAINWINDOW_CLIENT_COLOR_G 0x66
#define CWINPHONEMAINWINDOW_CLIENT_COLOR_B 0x66

#define CWINPHONEMAINWINDOW_CLIENT_COLOR \
    RGB(CWINPHONEMAINWINDOW_CLIENT_COLOR_R, \
        CWINPHONEMAINWINDOW_CLIENT_COLOR_G, \
        CWINPHONEMAINWINDOW_CLIENT_COLOR_B)

#define CWINPHONEMAINWINDOW_COLOR_R 0x66
#define CWINPHONEMAINWINDOW_COLOR_G 0x66
#define CWINPHONEMAINWINDOW_COLOR_B 0x99

#define CWINPHONEMAINWINDOW_COLOR \
    RGB(CWINPHONEMAINWINDOW_COLOR_R, \
        CWINPHONEMAINWINDOW_COLOR_G, \
        CWINPHONEMAINWINDOW_COLOR_B)

/**
 **********************************************************************
 * Typedef: cWinPhoneMainWindowExtends
 *
 *  Author: $author$
 *    Date: 5/30/2009
 **********************************************************************
 */
typedef cWinWindow
cWinPhoneMainWindowExtends;

/**
 **********************************************************************
 *  Class: cWinPhoneMainWindow
 *
 * Author: $author$
 *   Date: 5/30/2009
 **********************************************************************
 */
class cWinPhoneMainWindow
: public cWinPhoneMainWindowExtends
{
public:
    typedef cWinPhoneMainWindowExtends cExtends;
    typedef cWinPhoneMainWindow cDerives;

    int m_width, m_height, m_cornerRadius;
    int m_clientLeft, m_clientTop, m_clientBottom;
    int m_clientWidth, m_clientHeight;

    cWinCOLORREF m_clientBackgroundCOLORREF;
    cWinCOLORREF m_backgroundCOLORREF;
    HBRUSH m_hClientBackground;
    HBRUSH m_hBackground;

    cWinDC m_dc;
    cWinImage m_image;
    cWinImageColor m_color;
    cWinImageColor m_topColor1;
    cWinImageColor m_topColor2;
    cWinImageColor m_topColor3;
    cWinImageColor m_bottomColor1;
    cWinImageColor m_bottomColor2;
    cWinImageColor m_bottomColor3;

    /**
     **********************************************************************
     * Constructor: cWinPhoneMainWindow
     *
     *      Author: $author$
     *        Date: 5/30/2009
     **********************************************************************
     */
    cWinPhoneMainWindow
    (int width=CWINPHONEMAINWINDOW_WIDTH,
     int height=CWINPHONEMAINWINDOW_HEIGHT,
     int cornerRadius=CWINPHONEMAINWINDOW_CORNER_RADIUS,
     int clientLeft=CWINPHONEMAINWINDOW_CLIENT_LEFT,
     int clientTop=CWINPHONEMAINWINDOW_CLIENT_TOP,
     int clientBottom=CWINPHONEMAINWINDOW_CLIENT_BOTTOM,
     int clientWidth=CWINPHONEMAINWINDOW_CLIENT_WIDTH,
     int clientHeight=CWINPHONEMAINWINDOW_CLIENT_HEIGHT,
     COLORREF clientBackgroundCOLORREF=CWINPHONEMAINWINDOW_CLIENT_COLOR,
     COLORREF backgroundCOLORREF=CWINPHONEMAINWINDOW_COLOR,
     HBRUSH hClientBackground=NULL,
     HBRUSH hBackground=NULL)
    : m_width(width), m_height(height), m_cornerRadius(cornerRadius),
      m_clientLeft(clientLeft), m_clientTop(clientTop), m_clientBottom(clientBottom),
      m_clientWidth(clientWidth), m_clientHeight(clientHeight),
      m_clientBackgroundCOLORREF(clientBackgroundCOLORREF),
      m_backgroundCOLORREF(backgroundCOLORREF),
      m_hClientBackground(hClientBackground),
      m_hBackground(hBackground),
      m_image(m_dc),
      m_color
      (m_image, 
       CWINPHONEMAINWINDOW_COLOR_R, 
       CWINPHONEMAINWINDOW_COLOR_G, 
       CWINPHONEMAINWINDOW_COLOR_B,
       0, 2,2),
      m_topColor1
      (m_image, m_color, -0x05),
      m_topColor2
      (m_image, m_color, 0x25),
      m_topColor3
      (m_image, m_color, 0x10),
      m_bottomColor1
      (m_image, m_color, -0x10),
      m_bottomColor2
      (m_image, m_color, -0x20),
      m_bottomColor3
      (m_image, m_color, -0x40)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinPhoneMainWindow
     *
     *     Author: $author$
     *       Date: 5/30/2009
     **********************************************************************
     */
    virtual ~cWinPhoneMainWindow()
    {
    }

    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        DestroyWindow(hWnd);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        PostQuitMessage(0);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_SIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_SIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        HRGN hRgn;
        RECT r;

        if ((GetWindowRect(hWnd, &r)))
        if ((hRgn = CreateRoundRectRgn
            (0,0, r.right - r.left,r.bottom - r.top, 
             m_cornerRadius*2, m_cornerRadius*2)))
            SetWindowRgn(hWnd, hRgn, TRUE);

        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCALCSIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        LPRECT pRect = (LPRECT)(lParam);
        LPNCCALCSIZE_PARAMS pNCCParams;

        if (wParam)
        if ((pNCCParams = (LPNCCALCSIZE_PARAMS)(lParam)))
        {
            pRect = &pNCCParams->rgrc[0];
            lParam = WVR_VALIDRECTS;
        }

        if (pRect)
        {
            pRect->left += m_clientLeft;
            pRect->top += m_clientTop;
            pRect->right -= m_clientLeft;
            pRect->bottom -= m_clientBottom;
        }
        //lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        PAINTSTRUCT p;
        RECT r;
        HDC hDC;
        if ((GetClientRect(hWnd, &r)))
        if ((hDC = BeginPaint(hWnd, &p)))
        {
            FillRect(hDC, &r, m_hClientBackground);
            EndPaint(hWnd, &p);
        }
        //lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCPAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        HBRUSH hBrush;
        HDC hDC, attached;
        RECT r;

        if ((hBrush = m_hBackground))
        if ((hDC = GetWindowDC(hWnd)))
        //if ((hDC = GetDCEx(hWnd, (HRGN)(wParam), DCX_WINDOW)))
        {
            r.left = 0;
            r.top = m_clientTop;
            r.right = m_clientLeft;
            r.bottom = m_clientTop+m_clientHeight;
            FillRect(hDC, &r, hBrush);

            r.left = 0;
            r.top = 0;
            r.right = m_width;
            r.bottom = m_clientTop;
            FillRect(hDC, &r, hBrush);

            r.left = m_clientLeft+m_clientWidth;
            r.top = m_clientTop;
            r.right = m_width;
            r.bottom = m_clientTop+m_clientHeight;
            FillRect(hDC, &r, hBrush);

            r.left = 0;
            r.top = m_clientTop+m_clientHeight;
            r.right = m_width;
            r.bottom = m_height;
            FillRect(hDC, &r, hBrush);

            if ((attached = m_dc.Attach(hDC)))
            {
                cImageRoundedRectangle rr1
                (m_image, m_topColor3, m_topColor3, 
                 m_bottomColor2, m_bottomColor3, 
                 m_bottomColor3, m_bottomColor3, 
                 m_bottomColor2, m_topColor3, m_cornerRadius, 
                 m_width-m_cornerRadius-m_cornerRadius+2, 
                 m_height-m_cornerRadius-m_cornerRadius+2,
                 m_color.m_width);

                cImageRoundedRectangle rr2
                (m_image, m_topColor2, m_topColor2, 
                 m_bottomColor2, m_bottomColor2, 
                 m_bottomColor2, m_bottomColor2, 
                 m_bottomColor2, m_topColor2, m_cornerRadius-2, 
                 m_width-m_cornerRadius-m_cornerRadius+2, 
                 m_height-m_cornerRadius-m_cornerRadius+2,
                 m_color.m_width);

                cImageRoundedRectangle rr3
                (m_image, m_topColor2, m_topColor2, 
                 m_bottomColor2, m_bottomColor2, 
                 m_bottomColor2, m_bottomColor2, 
                 m_bottomColor2, m_topColor2, m_cornerRadius-3, 
                 m_width-m_cornerRadius-m_cornerRadius+2, 
                 m_height-m_cornerRadius-m_cornerRadius+2,
                 m_color.m_width);

                cImageRoundedRectangle rr4
                (m_image, m_topColor1, m_topColor1, 
                 m_bottomColor1, m_bottomColor1, 
                 m_bottomColor1, m_bottomColor1, 
                 m_bottomColor1, m_topColor1, m_cornerRadius-5, 
                 m_width-m_cornerRadius-m_cornerRadius+2, 
                 m_height-m_cornerRadius-m_cornerRadius+2,
                 m_color.m_width);

                cImageRectangle r1
                (m_image, m_bottomColor3, 
                 m_topColor2, m_topColor2, 
                 m_bottomColor3, 
                 m_clientWidth+4, 
                 m_clientHeight+4,
                 m_color.m_width);

                r1.Plot(m_clientLeft-2, m_clientTop-2);
                rr1.Plot(m_cornerRadius-1, m_cornerRadius-1);
                rr2.Plot(m_cornerRadius-1, m_cornerRadius-1);
                rr3.Plot(m_cornerRadius-1, m_cornerRadius-1);
                rr4.Plot(m_cornerRadius-1, m_cornerRadius-1);
                m_dc.Detach();
            }
            ReleaseDC(hWnd, hDC);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        int xPos = GET_X_LPARAM(lParam);
        int yPos = GET_Y_LPARAM(lParam);
        RECT r;
        if ((GetWindowRect(hWnd, &r)))
        if (yPos < (r.top+m_clientTop))
            lResult = HTCAPTION;
        return lResult;
    }

    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_FAILED;
        const TCHAR* chars;
        HWND hWndDesktop;
        RECT r;

        if ((chars = windowClass.WindowClassName()))
        if ((hWndDesktop = GetDesktopWindow()))
        if (GetClientRect(hWndDesktop, &r))
        if (!(error = Create
            (hInstance, chars, NULL, hWndDesktop, 
             NULL, WS_POPUP | WS_VISIBLE, 0, 
             (r.right-r.left)/8,(r.bottom-r.top)/8, 
             m_width,m_height)))
            Show();
        return error;
    }

    /**
     **********************************************************************
     * Function: InitializeMainWindowClass
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual eError InitializeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        if ((m_hBackground = CreateSolidBrush(m_backgroundCOLORREF)))
        if ((m_hClientBackground = CreateSolidBrush(m_clientBackgroundCOLORREF)))
        {
            windowClass.SetBackground(m_hClientBackground);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 5/30/2009
     **********************************************************************
     */
    virtual eError FinalizeMainWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};
#endif /* _CWINPHONEMAINWINDOW_HXX */

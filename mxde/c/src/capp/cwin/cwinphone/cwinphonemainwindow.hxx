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
 *   Date: 7/15/2009
 **********************************************************************
 */
#if !defined(_CWINPHONEMAINWINDOW_HXX) || defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINPHONEMAINWINDOW_HXX) && !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY)
#define _CWINPHONEMAINWINDOW_HXX
#endif /* !defined(_CWINPHONEMAINWINDOW_HXX) && !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY)
#include "cwinimageellipticalroundedrectanglewindow.hxx"
#include "cwinellipticalroundedrectanglewindow.hxx"
#include "cellipticalroundedrectangleimageobject.hxx"
#include "c3droundedrectangleimageobject.hxx"
#include "cwinimageobject.hxx"
#include "cwinimage.hxx"
#include "cwindibitmapfile.hxx"
#include "cfilledmidpointcircleimageobject.hxx"
#include "cmidpointcircleimage.hxx"
#include "cbresenhamlineimage.hxx"

#define CWINPHONEMAINWINDOW_BUTTON_BITMAP_FILE "cWinPhoneButton.bmp"

#define CWINPHONEMAINWINDOW_COLOR_WHITE_R -1
#define CWINPHONEMAINWINDOW_COLOR_WHITE_G -1
#define CWINPHONEMAINWINDOW_COLOR_WHITE_B -1

#define CWINPHONEMAINWINDOW_COLOR_BLACK_R 0x00
#define CWINPHONEMAINWINDOW_COLOR_BLACK_G 0x00
#define CWINPHONEMAINWINDOW_COLOR_BLACK_B 0x00

#define CWINPHONEMAINWINDOW_COLOR_DARK_GREY_R 0xAA
#define CWINPHONEMAINWINDOW_COLOR_DARK_GREY_G 0xAA
#define CWINPHONEMAINWINDOW_COLOR_DARK_GREY_B 0xAA

#define CWINPHONEMAINWINDOW_COLOR_LIGHT_GREY_R 0xDD
#define CWINPHONEMAINWINDOW_COLOR_LIGHT_GREY_G 0xDD
#define CWINPHONEMAINWINDOW_COLOR_LIGHT_GREY_B 0xDD

#define CWINPHONEMAINWINDOW_CLIENT_LEFT 20
#define CWINPHONEMAINWINDOW_CLIENT_TOP 63
#define CWINPHONEMAINWINDOW_CLIENT_BOTTOM 96
#define CWINPHONEMAINWINDOW_CLIENT_WIDTH 320
#define CWINPHONEMAINWINDOW_CLIENT_HEIGHT 480

#define CWINPHONEMAINWINDOW_CLIENT_COLOR_R 0x33
#define CWINPHONEMAINWINDOW_CLIENT_COLOR_G 0x33
#define CWINPHONEMAINWINDOW_CLIENT_COLOR_B 0x33

#define CWINPHONEMAINWINDOW_CLIENT_COLOR \
    RGB(CWINPHONEMAINWINDOW_CLIENT_COLOR_R, \
        CWINPHONEMAINWINDOW_CLIENT_COLOR_G, \
        CWINPHONEMAINWINDOW_CLIENT_COLOR_B)

#define CWINPHONEMAINWINDOW_CORNER_RADIUS 55

#define CWINPHONEMAINWINDOW_WIDTH \
    CWINPHONEMAINWINDOW_CLIENT_WIDTH \
    + (CWINPHONEMAINWINDOW_CLIENT_LEFT * 2)

#define CWINPHONEMAINWINDOW_HEIGHT \
    CWINPHONEMAINWINDOW_CLIENT_HEIGHT \
    + CWINPHONEMAINWINDOW_CLIENT_TOP \
    + CWINPHONEMAINWINDOW_CLIENT_BOTTOM

#define CWINPHONEMAINWINDOW_COLOR_R 0x55
#define CWINPHONEMAINWINDOW_COLOR_G 0x55
#define CWINPHONEMAINWINDOW_COLOR_B 0x55

#define CWINPHONEMAINWINDOW_COLOR \
    RGB(CWINPHONEMAINWINDOW_COLOR_R, \
        CWINPHONEMAINWINDOW_COLOR_G, \
        CWINPHONEMAINWINDOW_COLOR_B)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinPhoneMainWindowExtends
 *
 *  Author: $author$
 *    Date: 7/15/2009
 **********************************************************************
 */
typedef cWinImageEllipticalRoundedRectangleWindow
cWinPhoneMainWindowExtends;
/**
 **********************************************************************
 *  Class: cWinPhoneMainWindow
 *
 * Author: $author$
 *   Date: 7/15/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinPhoneMainWindow
: public cWinPhoneMainWindowExtends
{
public:
    typedef cWinPhoneMainWindowExtends cExtends;

    int m_width, m_height;
    int m_clientWidth, m_clientHeight;
    int m_clientLeft, m_clientTop, m_clientBottom;

    cWinCOLORREF m_nClientBgColor;
    cWinBrush m_nClientBgBrush;

    cWinDC m_imageDC;
    cWinImage m_image;
    cWinImageColor m_imageBlack;
    cWinImageColor m_imageWhite;
    cWinImageColor m_imageBgColor;
    cWinImageColor m_imageBgTopColor1;
    cWinImageColor m_imageBgTopColor2;
    cWinImageColor m_imageBgTopColor3;
    cWinImageColor m_imageBgTopColor4;
    cWinImageColor m_imageBgBottomColor1;
    cWinImageColor m_imageBgBottomColor2;
    cWinImageColor m_imageBgBottomColor3;
    cWinImageColor m_imageBgBottomColor4;
    
    cImageObject* m_imageBgTopColor[4];
    cImageObject* m_imageBgBottomColor[4];
    
    cBresenhamLineImage m_line;
    cMidpointCircleImage m_circle;
    cFilledMidpointCircleImageObject m_imageFilledCircle;
    
    const char* m_buttonBitmapFileNameChars;
    cWinDIBitmap m_buttonBitmap;
    cWinBitmap m_buttonMaskBitmap;
    cWinBitmapInfo m_buttonBitmapInfo;
    cWinDIBitmapFile m_buttonBitmapFile;

    /**
     **********************************************************************
     *  Constructor: cWinPhoneMainWindow
     *
     *       Author: $author$
     *         Date: 7/15/2009
     **********************************************************************
     */
    cWinPhoneMainWindow
    (const char* buttonBitmapFileNameChars=CWINPHONEMAINWINDOW_BUTTON_BITMAP_FILE,
     int width=CWINPHONEMAINWINDOW_WIDTH,
     int height=CWINPHONEMAINWINDOW_HEIGHT,
     int cornerRadius=CWINPHONEMAINWINDOW_CORNER_RADIUS,
     int clientWidth=CWINPHONEMAINWINDOW_CLIENT_WIDTH,
     int clientHeight=CWINPHONEMAINWINDOW_CLIENT_HEIGHT,
     int clientLeft=CWINPHONEMAINWINDOW_CLIENT_LEFT,
     int clientTop=CWINPHONEMAINWINDOW_CLIENT_TOP,
     int clientBottom=CWINPHONEMAINWINDOW_CLIENT_BOTTOM,
     COLORREF clientBgColor=CWINPHONEMAINWINDOW_CLIENT_COLOR,
     COLORREF bgColor=CWINPHONEMAINWINDOW_COLOR,
     HBRUSH hClientBgBrush=NULL,
     HBRUSH hBgBrush=NULL)
    : cExtends(cornerRadius, cornerRadius, clientBgColor, hClientBgBrush),
      m_width(width), m_height(height), 
      m_clientWidth(clientWidth), m_clientHeight(clientHeight),
      m_clientLeft(clientLeft), m_clientTop(clientTop), m_clientBottom(clientBottom),
      m_nClientBgColor(bgColor),
      m_nClientBgBrush(hBgBrush),

      m_image(m_imageDC),
      m_imageBlack(m_image, 0,0,0),
      m_imageWhite(m_image, -1,-1,-1),
      m_imageBgColor
      (m_image, 
       CWINPHONEMAINWINDOW_COLOR_R, 
       CWINPHONEMAINWINDOW_COLOR_G, 
       CWINPHONEMAINWINDOW_COLOR_B,
       0, 2,2),
       
      m_imageBgTopColor1
      (m_image, m_imageBgColor, 0x10),
      m_imageBgTopColor2
      (m_image, m_imageBgColor, 0x30),
      m_imageBgTopColor3
      (m_image, m_imageBgColor, -0x07),
      m_imageBgTopColor4
      (m_image, m_imageBgColor, -0x03),
      
      m_imageBgBottomColor1
      (m_image, m_imageBgColor, -0x40),
      m_imageBgBottomColor2
      (m_image, m_imageBgColor, -0x25),
      m_imageBgBottomColor3
      (m_image, m_imageBgColor, -0x09),
      m_imageBgBottomColor4
      (m_image, m_imageBgColor, -0x03),
      
      m_line(m_image),
      m_circle(m_image),
      m_imageFilledCircle(m_image, 20),
      
      m_buttonBitmapFileNameChars(buttonBitmapFileNameChars)
    {
        m_imageBgTopColor[0] = &m_imageBgTopColor1;
        m_imageBgTopColor[1] = &m_imageBgTopColor2;
        m_imageBgTopColor[2] = &m_imageBgTopColor3;
        m_imageBgTopColor[3] = &m_imageBgTopColor4;
        
        m_imageBgBottomColor[0] = &m_imageBgBottomColor1;
        m_imageBgBottomColor[1] = &m_imageBgBottomColor2;
        m_imageBgBottomColor[2] = &m_imageBgBottomColor3;
        m_imageBgBottomColor[3] = &m_imageBgBottomColor4;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinPhoneMainWindow
     *
     *      Author: $author$
     *        Date: 7/15/2009
     **********************************************************************
     */
    virtual ~cWinPhoneMainWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 7/15/2009
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
        HWND hWnd;
        HDC hDC;
        RECT r;

        if ((chars = windowClass.WindowClassName()))
        if ((hWndDesktop = GetDesktopWindow()))
        if (GetClientRect(hWndDesktop, &r))
        if (!(error = Create
            (hInstance, chars, NULL, hWndDesktop, 
             NULL, WS_POPUP | WS_VISIBLE, 0, 
             (r.right-r.left)/8,(r.bottom-r.top)/8, 
             m_width,m_height)))
        {
            Show();
        }
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
        eError error;
        if (!(error = InitializeWindowClass(windowClass, hInstance)))
            error = m_nClientBgBrush.CreateSolid(m_nClientBgColor);
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
        eError error = m_nClientBgBrush.Destroy(true);
        eError error2;
        if ((error2 = FinalizeWindowClass
            (windowClass, hInstance)) && !error)
            error = error2;
        return error;
    }
#else /* !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        cImageInterface* image;
        PAINTSTRUCT ps;
        HDC hDC, hIDC;
        RECT r;
        
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((GetClientRect(hWnd, &r)))
            {
                int cx = r.right/2;
                int cy = r.bottom/2;
                int radius = r.right/4;
                c3dRoundedRectangleImageObject rr
                (m_image, m_imageBgTopColor, m_imageBgBottomColor, 
                 radius/4, radius*3, radius*3, 2, 4);
                
                hIDC = m_imageDC.SelectAttached(hDC);
                image = m_image.SelectImage(&m_imageWhite);
                
                //m_image.Fill(0,0, 10,10);
                
                m_line.DrawLine
                (m_imageFilledCircle, cx,cy, cx,cy-radius-radius/8);
                
                m_circle.PlotCircle
                (m_imageFilledCircle, cx,cy, radius,
                 e_CIRCLE_OCTANT_ALL & ~(e_CIRCLE_OCTANT_1 | e_CIRCLE_OCTANT_8));
                 
                m_image.SelectAsImage(image);
                
                rr.Plot(cx-radius-(radius/2), cy-radius-(radius/2));
                
                m_imageDC.SelectAttached(hIDC);
            }
            EndPaint(hWnd, &ps);
        }
        else
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        DestroyWindow(hWnd);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_CREATE_WindowMessage
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        int width, height;
        TSIZE rWidth, rHeight;
        HDC hDC, hCDC, hIDC;
        HGDIOBJ hGDIOBJ;
        HBITMAP hBitmap;
        eError error;
        cImageInterface* image;
        
        if ((m_buttonBitmapFileNameChars))
        if ((hDC = GetWindowDC(hWnd)))
        {
            if (0 < (m_buttonBitmapFile.ReadDIBitmap
                (m_buttonBitmap, m_buttonBitmapInfo, 
                 hDC, m_buttonBitmapFileNameChars)))
            if (0 < (width = m_buttonBitmap.Width()))
            if (0 < (height = m_buttonBitmap.Height()))
            if (!(error = m_buttonMaskBitmap.Create(hDC, width, height)))
            if ((hBitmap = m_buttonMaskBitmap.Attached()))
            if ((hCDC = CreateCompatibleDC(hDC)))
            {
                hGDIOBJ = SelectObject(hCDC, hBitmap);
                hIDC = m_imageDC.Attached();
                m_imageDC.Attach(hCDC);
                rWidth = width/2;
                rHeight = height/2;
                
                image = m_image.SelectImage(&m_imageWhite);                
                m_image.Fill(0,0, width,height);
                
                m_image.SelectImage(&m_imageBlack);
                m_image.FillEllipse
                (rWidth-1,rHeight-1, rWidth,rHeight);
                
                if (image)
                    image->SelectAsImage();
                m_imageDC.Attach(hIDC);
                SelectObject(hCDC, hGDIOBJ);
                DeleteDC(hCDC);
            }
            ReleaseDC(hWnd, hDC);
        }
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        SetIsCreated(false);
        PostQuitMessage(0);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_NCLBUTTONDOWN_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCLBUTTONDOWN_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCLBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCLBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCRBUTTONDOWN_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCRBUTTONDOWN_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCRBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCRBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_TOP_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_TOP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = HTCAPTION;
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_BOTTOM_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_BOTTOM_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = HTCAPTION;
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_LEFT_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_LEFT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = HTCAPTION;
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_RIGHT_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_RIGHT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = HTCAPTION;
        return lResult;
    }

    /**
     **********************************************************************
     * Function: NCPaintBackground
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual LRESULT NCPaintBackground
    (HWND hWnd, HDC hDC, RECT& rect)
    {
        LRESULT lResult = 0;
        HBRUSH hBrush;
        RECT r;

        if ((hBrush = m_nClientBgBrush.Attached()))
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
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: NCPaintButtons
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual LRESULT NCPaintButtons
    (HWND hWnd, HDC hDC, RECT& rect)
    {
        LRESULT lResult = 0;
        RECT r;
        HDC hCDC;
        HBITMAP hBitmap;
        int width, height;

        r.left = 0;
        r.top = m_clientTop+m_clientHeight;
        r.right = m_width;
        r.bottom = m_height;

        if ((hBitmap = m_buttonBitmap.Attached()))
        if ((hBitmap = m_buttonMaskBitmap.Attached()))
        if (m_width > (width = m_buttonBitmap.Width()))
        if ((m_height) > (height = m_buttonBitmap.Height()))
        if ((hCDC = CreateCompatibleDC(hDC)))
        {
            r.left += (m_width-width)/2;
            r.top += (m_height-r.top-height)/2;

            m_buttonBitmap.MaskedBlockTransferBits
            (hDC, r.left,r.top, width,height, hCDC, 
             hBitmap, 0,0, 0,0, SRCAND, SRCPAINT);
            DeleteDC(hCDC);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: NCPaintFrame
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual LRESULT NCPaintFrame
    (HWND hWnd, HDC hDC, RECT& rect)
    {
        LRESULT lResult = 0;

        NCPaintBackground(hWnd, hDC, rect);

        if ((m_imageDC.Attach(hDC)))
        {
            cEllipticalRoundedRectangleImageObject errio
            (m_image, m_imageBgBottomColor1, m_imageBgTopColor1, m_imageBgTopColor1,
             m_imageBgTopColor1, m_imageBgBottomColor1, m_imageBgBottomColor1,
             m_imageBgBottomColor1, m_imageBgBottomColor1, 
             m_cornerRadiusWidth, m_cornerRadiusHeight,
             m_width-m_cornerRadiusWidth*2+2,
             m_height-m_cornerRadiusHeight*2+2,
             m_imageBgColor.m_width);

            cEllipticalRoundedRectangleImageObject errio2
            (m_image, m_imageBgBottomColor3, m_imageBgTopColor2, m_imageBgTopColor2,
             m_imageBgTopColor2, m_imageBgBottomColor3, m_imageBgBottomColor2,
             m_imageBgBottomColor2, m_imageBgBottomColor2, 
             m_cornerRadiusWidth-2, m_cornerRadiusHeight-2,
             m_width-m_cornerRadiusWidth*2+2,
             m_height-m_cornerRadiusHeight*2+2,
             m_imageBgColor.m_width);

            cEllipticalRoundedRectangleImageObject errio3
            (m_image, m_imageBgBottomColor4, m_imageBgTopColor3, m_imageBgTopColor3,
             m_imageBgTopColor3, m_imageBgBottomColor4, m_imageBgBottomColor3,
             m_imageBgBottomColor3, m_imageBgBottomColor3, 
             m_cornerRadiusWidth-4, m_cornerRadiusHeight-4,
             m_width-m_cornerRadiusWidth*2+2,
             m_height-m_cornerRadiusHeight*2+2,
             m_imageBgColor.m_width);

            cEllipticalRoundedRectangleImageObject errio4
            (m_image, m_imageBgBottomColor4, m_imageBgTopColor4, m_imageBgTopColor4,
             m_imageBgTopColor4, m_imageBgBottomColor4, m_imageBgBottomColor4,
             m_imageBgBottomColor4, m_imageBgBottomColor4, 
             m_cornerRadiusWidth-6, m_cornerRadiusHeight-6,
             m_width-m_cornerRadiusWidth*2+2,
             m_height-m_cornerRadiusHeight*2+2,
             m_imageBgColor.m_width);

            c3dRoundedRectangleImageObject rr
            (m_image, m_imageBgTopColor, m_imageBgBottomColor, 
             m_cornerRadiusWidth, m_width-m_cornerRadiusWidth*2+2, 
             m_height-m_cornerRadiusHeight*2+2, 2, 4);
            
            rr.Plot(m_cornerRadiusWidth-1, m_cornerRadiusHeight-1);
            /*
            errio.Plot(m_cornerRadiusWidth-1, m_cornerRadiusHeight-1);
            errio2.Plot(m_cornerRadiusWidth-1, m_cornerRadiusHeight-1);
            errio3.Plot(m_cornerRadiusWidth-1, m_cornerRadiusHeight-1);
            errio4.Plot(m_cornerRadiusWidth-1, m_cornerRadiusHeight-1);
            */
            
            m_imageDC.Detach();
        }

        NCPaintButtons(hWnd, hDC, rect);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCPAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        HDC hDC;
        RECT rect;

        if ((GetWindowRect(hWnd, &rect)))
        if ((hDC = GetWindowDC(hWnd)))
        {
            NCPaintFrame(hWnd, hDC, rect);
            ReleaseDC(hWnd, hDC);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCALCSIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        LPRECT pRect;

        if ((pRect = (LPRECT)(lParam)))
        {
            if (wParam)
            {
                NCCALCSIZE_PARAMS& nccParams = *(LPNCCALCSIZE_PARAMS)(lParam);
                pRect = &nccParams.rgrc[0];
                lResult = WVR_VALIDRECTS;
            }
            pRect->left += m_clientLeft;
            pRect->top += m_clientTop;
            pRect->right -= m_clientLeft;
            pRect->bottom -= m_clientBottom;
        }
        else
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        int xPos = GET_X_LPARAM(lParam);
        int yPos = GET_Y_LPARAM(lParam);
        LRESULT lResult = 0;
        RECT r;

        if ((GetWindowRect(hWnd, &r)))
        if (yPos < (r.top+m_clientTop))
            return On_WM_NCHITTEST_TOP_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (yPos >= (r.bottom-m_clientBottom))
            return On_WM_NCHITTEST_BOTTOM_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos < (r.left+m_clientLeft))
            return On_WM_NCHITTEST_LEFT_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos >= (r.right-m_clientLeft))
            return On_WM_NCHITTEST_RIGHT_WindowMessage
            (hWnd, msg, wParam, lParam);

        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINPHONEMAINWINDOW_HXX) || defined(CWINPHONEMAINWINDOW_MEMBERS_ONLY) */

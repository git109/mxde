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
 *   File: cwineyemainwindow.hxx
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
#if !defined(_CWINEYEMAINWINDOW_HXX) || defined(CWINEYEMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINEYEMAINWINDOW_HXX) && !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY)
#define _CWINEYEMAINWINDOW_HXX
#endif /* !defined(_CWINEYEMAINWINDOW_HXX) && !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY)
#include "cwinimageellipticalwindow.hxx"
#include "cwindibitmapfile.hxx"
#include "cwinrgbquad.hxx"
#include "cwinregionimage.hxx"
#include "cwinregionimageextend.hxx"
#include "cwinregionimagebrush.hxx"
#include "cwinregionimagebase.hxx"
#include "cwinregion.hxx"
#include "cmidpointellipse.hxx"
#include "cimagebaseposition.hxx"

#define CWINEYEMAINWINDOW_CLIENT_BG_COLOR_R 0x00
#define CWINEYEMAINWINDOW_CLIENT_BG_COLOR_G 0x00
#define CWINEYEMAINWINDOW_CLIENT_BG_COLOR_B 0x00

#define CWINEYEMAINWINDOW_CLIENT_BG_COLOR \
    RGB(CWINEYEMAINWINDOW_CLIENT_BG_COLOR_R, \
        CWINEYEMAINWINDOW_CLIENT_BG_COLOR_G, \
        CWINEYEMAINWINDOW_CLIENT_BG_COLOR_B)

#define CWINEYEMAINWINDOW_CLIENT_RADIUS_WIDTH 38
#define CWINEYEMAINWINDOW_CLIENT_RADIUS_HEIGHT \
        CWINEYEMAINWINDOW_CLIENT_RADIUS_WIDTH

#define CWINEYEMAINWINDOW_BG_COLOR_R 0x00
#define CWINEYEMAINWINDOW_BG_COLOR_G 0x00
#define CWINEYEMAINWINDOW_BG_COLOR_B 0x00

#define CWINEYEMAINWINDOW_BG_COLOR \
    RGB(CWINEYEMAINWINDOW_BG_COLOR_R, \
        CWINEYEMAINWINDOW_BG_COLOR_G, \
        CWINEYEMAINWINDOW_BG_COLOR_B)

#define CWINEYEMAINWINDOW_RADIUS_WIDTH 64
#define CWINEYEMAINWINDOW_RADIUS_HEIGHT \
        CWINEYEMAINWINDOW_RADIUS_WIDTH

#define CWINEYEMAINWINDOW_BITMAP_FILENAME1 \
    "doc/images/cwineye/skins/default/device.bmp"

#define CWINEYEMAINWINDOW_BITMAP_FILENAME \
    "cwineye.bmp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinEyeMainWindowExtends
 *
 *  Author: $author$
 *    Date: 7/21/2009
 **********************************************************************
 */
typedef cWinImageEllipticalWindow
cWinEyeMainWindowExtends;
/**
 **********************************************************************
 *  Class: cWinEyeMainWindow
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinEyeMainWindow
: public cWinEyeMainWindowExtends
{
public:
    typedef cWinEyeMainWindowExtends cExtends;

    const char* m_bitmapFileNameChars;

    TSIZE m_clientRadiusWidth;
    TSIZE m_clientRadiusHeight;
    TSIZE m_nClientRadiusWidth;
    TSIZE m_nClientRadiusHeight;
    TSIZE m_clientRadiusWidthRatio;
    TSIZE m_clientRadiusWidthRatio2;
    TSIZE m_clientRadiusHeightRatio;
    TSIZE m_clientRadiusHeightRatio2;

    cWinCOLORREF m_nClientBgColor;
    cWinBrush m_nClientBgBrush;

    cWinDIBitmap m_bitmap;
    cWinBitmapInfo m_bitmapInfo;
    cWinDIBitmapFile m_bitmapFile;

    cWinRegionImageExtend m_regionImage;
    cWinRegionImageBrush m_regionBrush;
    
    cImageBasePosition m_imagePosition;
    cFilledMidpointEllipseSpace m_clientEllipseSpace;

    /**
     **********************************************************************
     *  Constructor: cWinEyeMainWindow
     *
     *       Author: $author$
     *         Date: 7/21/2009
     **********************************************************************
     */
    cWinEyeMainWindow
    (const char* bitmapFileNameChars=CWINEYEMAINWINDOW_BITMAP_FILENAME,
     TSIZE radiusWidth=CWINEYEMAINWINDOW_RADIUS_WIDTH,
     TSIZE radiusHeight=CWINEYEMAINWINDOW_RADIUS_HEIGHT,
     TSIZE clientRadiusWidth=CWINEYEMAINWINDOW_CLIENT_RADIUS_WIDTH,
     TSIZE clientRadiusHeight=CWINEYEMAINWINDOW_CLIENT_RADIUS_HEIGHT,
     COLORREF clientBgColor=CWINEYEMAINWINDOW_CLIENT_BG_COLOR,
     COLORREF bgColor=CWINEYEMAINWINDOW_BG_COLOR,
     HBRUSH hClientBgBrush=NULL,
     HBRUSH hBgBrush=NULL)
    : cExtends(radiusWidth, radiusHeight, clientBgColor, hClientBgBrush),
      m_bitmapFileNameChars(bitmapFileNameChars),
      m_clientRadiusWidth(clientRadiusWidth), 
      m_clientRadiusHeight(clientRadiusHeight),
      m_nClientRadiusWidth(radiusWidth-clientRadiusWidth), 
      m_nClientRadiusHeight(radiusHeight-clientRadiusHeight),
      m_clientRadiusWidthRatio(clientRadiusWidth),
      m_clientRadiusWidthRatio2(radiusWidth),
      m_clientRadiusHeightRatio(clientRadiusHeight),
      m_clientRadiusHeightRatio2(radiusHeight),
      m_nClientBgColor(bgColor),
      m_nClientBgBrush(hBgBrush),
      m_regionBrush((cWinRegionImageBase&)(m_regionImage))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEyeMainWindow
     *
     *      Author: $author$
     *        Date: 7/21/2009
     **********************************************************************
     */
    virtual ~cWinEyeMainWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 7/21/2009
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
        TLENGTH length;
        HWND hWndDesktop;
        HWND hWnd;
        HDC hDC;
        RECT r;

        if ((chars = windowClass.WindowClassName()))
        if ((hWndDesktop = GetDesktopWindow()))
        if (GetClientRect(hWndDesktop, &r))
        if (!(error = Create
            (hInstance, chars, NULL, hWndDesktop, 
             NULL, WS_POPUP, 0, 
             (r.right-r.left)/8,(r.bottom-r.top)/8, 
             m_radiusWidth*2-1, m_radiusHeight*2-1)))
        {
            if ((hWnd = Attached()))
            if ((hDC = GetDC(hWnd)))
            {
                if (m_bitmapFileNameChars)
                if (0 < (length = m_bitmapFile.ReadDIBitmap
                    (m_bitmap, m_bitmapInfo, hDC, m_bitmapFileNameChars)))
                {
                }
                ReleaseDC(hWnd, hDC);
            }
            Show();
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: InitializeMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/21/2009
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
        TLENGTH length;

        if (m_bitmapFileNameChars)
        if (0 < (length = m_bitmapFile.Read
            (m_bitmapFileNameChars)))
        {
            m_radiusWidth = m_bitmapFile.Width()/2+3;
            m_radiusHeight = m_bitmapFile.Height()/2+3;
            m_clientRadiusWidth = (m_radiusWidth*m_clientRadiusWidthRatio)/m_clientRadiusWidthRatio2;
            m_clientRadiusHeight = (m_radiusHeight*m_clientRadiusHeightRatio)/m_clientRadiusHeightRatio2;
            m_nClientRadiusWidth = m_radiusWidth-m_clientRadiusWidth;
            m_nClientRadiusHeight = m_radiusHeight-m_clientRadiusHeight;
        }

        if (!(error = InitializeWindowClass(windowClass, hInstance)))
            error = m_nClientBgBrush.CreateSolid(m_nClientBgColor);
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/21/2009
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

    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/21/2009
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
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/21/2009
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
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/25/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        PAINTSTRUCT ps;
        HBITMAP hBitmap;
        HDC hDC, hDCBitmap;
        
        if ((hBitmap = m_bitmap.Attached()))
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((hDCBitmap = CreateCompatibleDC(hDC)))
            {
                HGDIOBJ hGDIOBJ = SelectObject(hDCBitmap, hBitmap);

                BitBlt
                (hDC, 2,2, m_bitmap.m_width, m_bitmap.m_height, 
                 hDCBitmap, 0,0, SRCCOPY);

                SelectObject(hDCBitmap, hGDIOBJ);
                DeleteDC(hDCBitmap);
            }
            EndPaint(hWnd, &ps);
        }
        //lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual LRESULT xOn_WM_NCCALCSIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        LPRECT pRect;

        if ((pRect = (LPRECT)(lParam)))
        {
            LONG width = ((pRect->right-pRect->left)-(m_clientRadiusWidth*2-1))/2;
            LONG height = ((pRect->bottom-pRect->top)-(m_clientRadiusHeight*2-1))/2;

            if (wParam)
            {
                NCCALCSIZE_PARAMS& nccParams = *(LPNCCALCSIZE_PARAMS)(lParam);
                pRect = &nccParams.rgrc[0];
                lResult = WVR_VALIDRECTS;
            }
            pRect->left += width;
            pRect->top += height;
            pRect->right -= width;
            pRect->bottom -= height;
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
     *     Date: 7/21/2009
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
        {
            r.left += m_nClientRadiusWidth;
            r.right -= m_nClientRadiusWidth;
            r.top += m_nClientRadiusHeight;
            r.bottom -= m_nClientRadiusHeight;

            if ((xPos < r.left) || (xPos >= r.right)
                || (yPos < r.top) || (yPos >= r.bottom))
                return HTCAPTION;
            else
            {
                m_imagePosition.m_x = xPos;
                m_imagePosition.m_y = yPos;

                if (!(m_clientEllipseSpace.IsInEllipse
                    (m_imagePosition, 
                     r.left+m_clientRadiusWidth, 
                     r.top+m_clientRadiusHeight, 
                     m_clientRadiusWidth, m_clientRadiusHeight)))
                    return HTCAPTION;
            }
        }

        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINEYEMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINEYEMAINWINDOW_HXX) || defined(CWINEYEMAINWINDOW_MEMBERS_ONLY) */

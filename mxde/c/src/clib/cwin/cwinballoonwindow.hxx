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
 *   File: cwinballoonwindow.hxx
 *
 * Author: $author$
 *   Date: 6/2/2009
 **********************************************************************
 */
#ifndef _CWINBALLOONWINDOW_HXX
#define _CWINBALLOONWINDOW_HXX

#include "cwinimageobject.hxx"
#include "cwinimage.hxx"
#include "cwinncwindow.hxx"
#include "cwinwindowclass.hxx"
#include "cwinbrush.hxx"
#include "cwinhbrush.hxx"
#include "cwincolorref.hxx"
#include "cwinrect.hxx"
#include "cwinpen.hxx"

#define CWINBALLOONWINDOW_BG_COLOR_R 0xFF
#define CWINBALLOONWINDOW_BG_COLOR_G 0xFF
#define CWINBALLOONWINDOW_BG_COLOR_B 0xDD

#define CWINBALLOONWINDOW_BG_COLOR \
    RGB(CWINBALLOONWINDOW_BG_COLOR_R, \
        CWINBALLOONWINDOW_BG_COLOR_G, \
        CWINBALLOONWINDOW_BG_COLOR_B)

#define CWINBALLOONWINDOW_FG_COLOR_R 0x00
#define CWINBALLOONWINDOW_FG_COLOR_G 0x00
#define CWINBALLOONWINDOW_FG_COLOR_B 0x00

#define CWINBALLOONWINDOW_FG_COLOR \
    RGB(CWINBALLOONWINDOW_FG_COLOR_R, \
        CWINBALLOONWINDOW_FG_COLOR_G, \
        CWINBALLOONWINDOW_FG_COLOR_B)

#define CWINBALLOONWINDOW_BORDER_COLOR_R CWINBALLOONWINDOW_FG_COLOR_R
#define CWINBALLOONWINDOW_BORDER_COLOR_G CWINBALLOONWINDOW_FG_COLOR_G
#define CWINBALLOONWINDOW_BORDER_COLOR_B CWINBALLOONWINDOW_FG_COLOR_B

#define CWINBALLOONWINDOW_BORDER_COLOR \
    RGB(CWINBALLOONWINDOW_BORDER_COLOR_R, \
        CWINBALLOONWINDOW_BORDER_COLOR_G, \
        CWINBALLOONWINDOW_BORDER_COLOR_B)

#define CWINBALLOONWINDOW_WINDOW_CLASSNAME "cWinBalloonWindow"

/**
 **********************************************************************
 * Typedef: cWinBalloonWindowExtends
 *
 *  Author: $author$
 *    Date: 6/2/2009
 **********************************************************************
 */
typedef cWinNCWindow
cWinBalloonWindowExtends;
/**
 **********************************************************************
 *  Class: cWinBalloonWindow
 *
 * Author: $author$
 *   Date: 6/2/2009
 **********************************************************************
 */
class cWinBalloonWindow
: public cWinBalloonWindowExtends
{
public:
    typedef cWinBalloonWindowExtends cExtends;
    typedef cWinBalloonWindow cDerives;

    const TCHAR* m_windowClassNameChars;

    TSIZE m_radius, m_radiusRatio, m_radiusRatioTo;
    cWinCOLORREF m_bgColor, m_fgColor, m_borderColor;
    cWinBrush m_bgBrush, m_fgBrush, m_borderBrush;
    cWinPen m_borderPen;

    cWinDC m_dc;
    cWinImage m_image;
    cWinImageColor m_imageColor;
    cWinImageColor m_imageBGColor;
    cImageRoundedRectangle m_irr;

    /**
     **********************************************************************
     * Constructor: cWinBalloonWindow
     *
     *      Author: $author$
     *        Date: 6/2/2009
     **********************************************************************
     */
    cWinBalloonWindow
    (COLORREF bgColor=CWINBALLOONWINDOW_BG_COLOR,
     COLORREF fgColor=CWINBALLOONWINDOW_FG_COLOR,
     COLORREF borderColor=CWINBALLOONWINDOW_BORDER_COLOR,
     const TCHAR* windowClassNameChars=_T(CWINBALLOONWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated),
      m_windowClassNameChars(windowClassNameChars),
      m_radius(0),
      m_radiusRatio(1),
      m_radiusRatioTo(3),
      m_bgColor(bgColor), 
      m_fgColor(fgColor), 
      m_borderColor(borderColor),
      m_image(m_dc),
      m_imageColor
      (m_image, 
       CWINBALLOONWINDOW_BORDER_COLOR_R, 
       CWINBALLOONWINDOW_BORDER_COLOR_G, 
       CWINBALLOONWINDOW_BORDER_COLOR_B, 0, 2,2),
      m_imageBGColor
      (m_image, 
       CWINBALLOONWINDOW_BG_COLOR_R, 
       CWINBALLOONWINDOW_BG_COLOR_G, 
       CWINBALLOONWINDOW_BG_COLOR_B),
      m_irr(m_image, m_imageColor, 1,1,1,2)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinBalloonWindow
     *
     *     Author: $author$
     *       Date: 6/2/2009
     **********************************************************************
     */
    virtual ~cWinBalloonWindow()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 6/4/2009
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance,
     HWND hWndParent,
     int x, int y,
     int width, int height,
     DWORD style=WS_POPUP,
     DWORD exStyle=0,
     LPCTSTR className=NULL,
     LPCTSTR windowName=NULL,
     HMENU hMenu=NULL,
     bool onlyDestroyed=false) 
    {
        cExtends& thisExtends = *this;
        eError error = e_ERROR_FAILED;

        if (!className)
            className = m_windowClassNameChars;

        if (!(error = thisExtends.Create
            (hInstance, className, windowName, 
             hWndParent, hMenu, style, exStyle, 
             x,y, width,height, onlyDestroyed)))
            Show(SW_SHOWNORMAL);
        return error;
    }

    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 6/4/2009
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
        RECT r;
        HDC hDC;
        HPEN hPen;
        HGDIOBJ hObj;
        int bkMode;

        //lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);

        if ((GetClientRect(hWnd, &r)))
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((hPen = m_borderPen.Attached()))
            {
                hObj = SelectObject(hDC, hPen);
                bkMode = SetBkMode(hDC, TRANSPARENT);
                //Ellipse(hDC, 0,0, m_radius*2-1,m_radius*2-1);
                SetBkMode(hDC, bkMode);
                SelectObject(hDC, hObj);
            }
            if ((m_dc.Attach(hDC)))
            {
                cImageInterface* image;
                image = m_imageColor.SelectAsImage();
                m_imageColor.m_width = 1;
                m_imageColor.m_height = 1;
                m_image.DrawEllipse(m_radius-1,m_radius-1, m_radius,m_radius);
                //m_image.DrawCircle(m_radius-1,m_radius-1, m_radius);
                //m_imageBGColor.SetAsImage();
                //m_image.FillCircle(m_radius-1,m_radius-1, m_radius-3,m_radius-3);
                //m_image.FillEllipse(m_radius-1,m_radius-1, m_radius-1,m_radius-1);
                //m_irr.Plot(m_radius-1, m_radius-1);
                SelectAsImage(image);
                m_dc.Detach();
            }
            EndPaint(hWnd, &ps);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnSize
     *
     *   Author: $author$
     *     Date: 6/2/2009
     **********************************************************************
     */
    virtual BOOL OnSize
    (LRESULT& lResult,
     HRGN& hRgn,
     RECT& r,
     HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL handled = FALSE;
        LONG radius;

        if (!(radius = m_radius))
        {
            if (r.right < (radius = r.bottom-1))
                radius = r.right-1;

            if (m_radiusRatioTo)
                radius = (radius*m_radiusRatio)/m_radiusRatioTo;
        }
        if (0 < radius)
        if (!hRgn)
        if ((hRgn = CreateWindowRoundedRegion(r, radius)))
        {
            lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
            m_irr.m_radius = radius;
            m_irr.m_width = r.right-radius-radius+2;
            m_irr.m_height = r.bottom-radius-radius+2;
            m_radius = radius;
            handled = TRUE;
        }
        return handled;
    }
    /**
     **********************************************************************
     * Function: CreateWindowRoundedRegion
     *
     *   Author: $author$
     *     Date: 6/2/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowRoundedRegion
    (RECT& r,
     LONG radius) 
    {
        HRGN hRgn = NULL;;
        hRgn = CreateRoundRectRgn
        (r.left,r.top, r.right+1,r.bottom+1, radius*2-1,radius*2-1);
        return hRgn;
    }

    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 6/3/2009
     **********************************************************************
     */
    virtual eError InitializeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;

        if (m_windowClassNameChars)
        if (0 > (length = windowClass.SetWindowClassName(m_windowClassNameChars)))
            return error = -length;

        if (!(error = m_bgBrush.CreateSolid(m_bgColor.Attached())))
        {
            m_imageBGColor.Attach(m_bgBrush.Attached());
            windowClass.SetBackground(m_bgBrush.Attached());
            if (!(error = m_fgBrush.CreateSolid(m_fgColor.Attached())))
            {
                if (!(error = m_borderBrush.CreateSolid(m_borderColor.Attached())))
                {
                    m_borderPen.Create(m_borderColor.Attached());
                    m_imageColor.Attach(m_borderBrush.Attached());
                    return error;
                }
                m_fgBrush.Destroy();
            }
            m_bgBrush.Destroy();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeWindowClass
     *
     *   Author: $author$
     *     Date: 6/3/2009
     **********************************************************************
     */
    virtual eError FinalizeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        error = m_borderBrush.Destroy(true);
        if ((error2 = m_fgBrush.Destroy(true)) && !error)
            error = error2;
        if ((error2 = m_bgBrush.Destroy(true)) && !error)
            error = error2;
        return error;
    }
};
#endif /* _CWINBALLOONWINDOW_HXX */

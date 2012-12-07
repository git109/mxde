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
 *   File: cwinroundedframewindow.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEWINDOW_HXX) || defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEWINDOW_HXX) && !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEWINDOW_HXX) && !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
#include "cwinimageroundedrectanglewindow.hxx"
#include "c3droundedrectangleimageobject.hxx"
#include "c3drectangleimageobject.hxx"
#include "cwinimageobject.hxx"
#include "cwinimage.hxx"

#define CWINFRAMEWINDOW_COLOR_R 0x00
#define CWINFRAMEWINDOW_COLOR_G 0x00
#define CWINFRAMEWINDOW_COLOR_B 0x00

#define CWINFRAMEWINDOW_COLOR_WHITE_R 0xFF
#define CWINFRAMEWINDOW_COLOR_WHITE_G 0xFF
#define CWINFRAMEWINDOW_COLOR_WHITE_B 0xFF

#define CWINFRAMEWINDOW_COLOR_BLACK_R 0x00
#define CWINFRAMEWINDOW_COLOR_BLACK_G 0x00
#define CWINFRAMEWINDOW_COLOR_BLACK_B 0x00

#define CWINFRAMEWINDOW_COLOR_GREY_R 0xBB
#define CWINFRAMEWINDOW_COLOR_GREY_G 0xBB
#define CWINFRAMEWINDOW_COLOR_GREY_B 0xBB

#define CWINFRAMEWINDOW_COLOR_DARK_GREY_R 0x99
#define CWINFRAMEWINDOW_COLOR_DARK_GREY_G 0x99
#define CWINFRAMEWINDOW_COLOR_DARK_GREY_B 0x99

#define CWINFRAMEWINDOW_COLOR_LIGHT_GREY_R 0xDD
#define CWINFRAMEWINDOW_COLOR_LIGHT_GREY_G 0xDD
#define CWINFRAMEWINDOW_COLOR_LIGHT_GREY_B 0xDD

#define CWINFRAMEWINDOW_COLOR_WHITE \
    RGB(CWINFRAMEWINDOW_COLOR_WHITE_R,\
        CWINFRAMEWINDOW_COLOR_WHITE_G,\
        CWINFRAMEWINDOW_COLOR_WHITE_B)

#define CWINFRAMEWINDOW_COLOR_LIGHT_GREY \
    RGB(CWINFRAMEWINDOW_COLOR_LIGHT_GREY_R,\
        CWINFRAMEWINDOW_COLOR_LIGHT_GREY_G,\
        CWINFRAMEWINDOW_COLOR_LIGHT_GREY_B)

#define CWINFRAMEWINDOW_BG_COLOR \
    CWINFRAMEWINDOW_COLOR_WHITE
    
#define CWINFRAMEWINDOW_FG_COLOR \
    CWINFRAMEWINDOW_COLOR_LIGHT_GREY
    
#define CWINROUNDEDFRAMEWINDOW_CORNER_RADIUS 32

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRoundedFrameWindowExtend
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cWinImageRoundedRectangleWindow
cWinRoundedFrameWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameWindow
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRoundedFrameWindow
: public cWinRoundedFrameWindowExtend
{
public:
    typedef cWinRoundedFrameWindowExtend cExtends;
    
    enum { e_ROUNDED_FRAME_DEPTH = 5 };
    enum { e_RECT_FRAME_DEPTH = 2 };
    
    cWinCOLORREF m_fgColor;
    cWinBrush m_fgBrush;
    
    cWinDC m_imageDC;
    cWinImage m_image;
    
    cWinImageColor m_imageTopColor0;
    cWinImageColor m_imageTopColor1;
    cWinImageColor m_imageTopColor2;
    cWinImageColor m_imageTopColor3;
    cWinImageColor m_imageTopColor4;
    
    cWinImageColor m_imageBottomColor0;
    cWinImageColor m_imageBottomColor1;
    cWinImageColor m_imageBottomColor2;
    cWinImageColor m_imageBottomColor3;
    cWinImageColor m_imageBottomColor4;
    
    cWinImageColor m_imageRectTopColor1;
    cWinImageColor m_imageRectTopColor2;
    cWinImageColor m_imageRectBottomColor1;
    cWinImageColor m_imageRectBottomColor2;
    
    cImageObject* m_imageTopColor[e_ROUNDED_FRAME_DEPTH];
    cImageObject* m_imageBottomColor[e_ROUNDED_FRAME_DEPTH];
    
    cImageObject* m_imageRectTopColor[e_RECT_FRAME_DEPTH];
    cImageObject* m_imageRectBottomColor[e_RECT_FRAME_DEPTH];
    
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameWindow
     *
     *       Author: $author$
     *         Date: 12/30/2009
     **********************************************************************
     */
    cWinRoundedFrameWindow
    (COLORREF bgColor=CWINFRAMEWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINSHAPEDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (CWINROUNDEDFRAMEWINDOW_CORNER_RADIUS, 
       bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),

      m_fgColor(CWINFRAMEWINDOW_FG_COLOR),
      
      m_image(m_imageDC),
      
      m_imageTopColor0
      (m_image,
       CWINFRAMEWINDOW_COLOR_BLACK_R,
       CWINFRAMEWINDOW_COLOR_BLACK_G,
       CWINFRAMEWINDOW_COLOR_BLACK_B, 0,2,2),
      m_imageTopColor1
      (m_image,
       CWINFRAMEWINDOW_COLOR_DARK_GREY_R,
       CWINFRAMEWINDOW_COLOR_DARK_GREY_G,
       CWINFRAMEWINDOW_COLOR_DARK_GREY_B, 0,2,2),
      m_imageTopColor2
      (m_image,
       CWINFRAMEWINDOW_COLOR_GREY_R,
       CWINFRAMEWINDOW_COLOR_GREY_G,
       CWINFRAMEWINDOW_COLOR_GREY_B, 0,2,2),
      m_imageTopColor3
      (m_image,
       CWINFRAMEWINDOW_COLOR_WHITE_R,
       CWINFRAMEWINDOW_COLOR_WHITE_G,
       CWINFRAMEWINDOW_COLOR_WHITE_B, 0,2,2),
      m_imageTopColor4
      (m_image,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_R,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_G,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_B, 0,2,2),
      
      m_imageBottomColor0
      (m_image,
       CWINFRAMEWINDOW_COLOR_BLACK_R,
       CWINFRAMEWINDOW_COLOR_BLACK_G,
       CWINFRAMEWINDOW_COLOR_BLACK_B, 0,2,2),
      m_imageBottomColor1
      (m_image,
       CWINFRAMEWINDOW_COLOR_BLACK_R,
       CWINFRAMEWINDOW_COLOR_BLACK_G,
       CWINFRAMEWINDOW_COLOR_BLACK_B, 0,2,2),
      m_imageBottomColor2
      (m_image,
       CWINFRAMEWINDOW_COLOR_DARK_GREY_R,
       CWINFRAMEWINDOW_COLOR_DARK_GREY_G,
       CWINFRAMEWINDOW_COLOR_DARK_GREY_B, 0,2,2),
      m_imageBottomColor3
      (m_image,
       CWINFRAMEWINDOW_COLOR_GREY_R,
       CWINFRAMEWINDOW_COLOR_GREY_G,
       CWINFRAMEWINDOW_COLOR_GREY_B, 0,2,2),
      m_imageBottomColor4
      (m_image,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_R,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_G,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_B, 0,2,2),
       
      m_imageRectTopColor1
      (m_image,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_R,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_G,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_B, 0,1,1),
      m_imageRectTopColor2
      (m_image,
       CWINFRAMEWINDOW_COLOR_GREY_R,
       CWINFRAMEWINDOW_COLOR_GREY_G,
       CWINFRAMEWINDOW_COLOR_GREY_B, 0,1,1),
      m_imageRectBottomColor1
      (m_image,
       CWINFRAMEWINDOW_COLOR_WHITE_R,
       CWINFRAMEWINDOW_COLOR_WHITE_G,
       CWINFRAMEWINDOW_COLOR_WHITE_B, 0,1,1),
      m_imageRectBottomColor2
      (m_image,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_R,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_G,
       CWINFRAMEWINDOW_COLOR_LIGHT_GREY_B, 0,1,1)
    {
        m_imageTopColor[0] = &m_imageTopColor0;
        m_imageTopColor[1] = &m_imageTopColor1;
        m_imageTopColor[2] = &m_imageTopColor2;
        m_imageTopColor[3] = &m_imageTopColor3;
        m_imageTopColor[4] = &m_imageTopColor4;
        
        m_imageBottomColor[0] = &m_imageBottomColor0;
        m_imageBottomColor[1] = &m_imageBottomColor1;
        m_imageBottomColor[2] = &m_imageBottomColor2;
        m_imageBottomColor[3] = &m_imageBottomColor3;
        m_imageBottomColor[4] = &m_imageBottomColor4;
        
        m_imageRectTopColor[0] = &m_imageRectTopColor1;
        m_imageRectTopColor[1] = &m_imageRectTopColor2;
        m_imageRectBottomColor[0] = &m_imageRectBottomColor1;
        m_imageRectBottomColor[1] = &m_imageRectBottomColor2;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedFrameWindow
     *
     *      Author: $author$
     *        Date: 12/30/2009
     **********************************************************************
     */
    virtual ~cWinRoundedFrameWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: PaintFrame
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual LRESULT PaintFrame
    (HWND hWnd, HDC hDC, RECT& r, RECT& paintRect)
    {
        LRESULT lResult = 0;
        TSIZE width = r.right-r.left-m_cornerRadius*2+2;
        TSIZE height = r.bottom-r.top-m_cornerRadius*2+2;
        c3dRoundedRectangleImageObject rrObject
        (m_image, m_imageTopColor, m_imageBottomColor, 
         m_cornerRadius, width-1,height-1, 1,e_ROUNDED_FRAME_DEPTH);
        c3dRectangleImageObject rObject
        (m_image, m_imageRectTopColor, m_imageRectBottomColor, 
         width+e_RECT_FRAME_DEPTH,height+e_RECT_FRAME_DEPTH, 
         1,e_RECT_FRAME_DEPTH);
        cImageInterface* image;
        HBRUSH hFgBrush;
        RECT frameRect;
                 
        if (!(hFgBrush = m_fgBrush.Attached()))
            m_fgBrush.CreateSolid(m_fgColor.Attached());
        
        if ((hFgBrush = m_fgBrush.Attached()))
        {
            frameRect.left = r.left;
            frameRect.top = r.top;
            frameRect.right = r.left+m_cornerRadius;
            frameRect.bottom = r.bottom;
            FillRect(hDC, &frameRect, hFgBrush);
            frameRect.left = r.right-m_cornerRadius;
            frameRect.right = r.right;
            FillRect(hDC, &frameRect, hFgBrush);
            frameRect.left = r.left+m_cornerRadius;
            frameRect.right = r.right-m_cornerRadius;
            frameRect.bottom = r.top+m_cornerRadius;
            FillRect(hDC, &frameRect, hFgBrush);
            frameRect.top = r.bottom-m_cornerRadius;
            frameRect.bottom = r.bottom;
            FillRect(hDC, &frameRect, hFgBrush);
        }
        m_imageDC.Attach(hDC);
        rrObject.Plot(r.left+m_cornerRadius-1, r.top+m_cornerRadius-1);
        rObject.Plot
        (r.left+m_cornerRadius-e_RECT_FRAME_DEPTH, 
         r.top+m_cornerRadius-e_RECT_FRAME_DEPTH);
        m_imageDC.Detach();
        GdiFlush();
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual LRESULT xOn_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        PAINTSTRUCT ps;
        HDC hDC;
        RECT r;
        
        return lResult;
        
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((GetClientRect(hWnd, &r)))
            {
                PaintFrame(hWnd, hDC, r, ps.rcPaint);
            }
            EndPaint(hWnd, &ps);
        }
        else
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
            rect.right -= rect.left;
            rect.bottom -= rect.top;
            rect.left = rect.top = 0;
            PaintFrame(hWnd, hDC, rect, rect);
            ReleaseDC(hWnd, hDC);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_TOP_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
     *     Date: 12/30/2009
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
     *     Date: 12/30/2009
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
     *     Date: 12/30/2009
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
     * Function: On_WM_NCHITTEST_RIGHT_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/30/2009
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
        if (yPos < (r.top+m_cornerRadius))
            return On_WM_NCHITTEST_TOP_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (yPos >= (r.bottom-m_cornerRadius))
            return On_WM_NCHITTEST_BOTTOM_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos < (r.left+m_cornerRadius))
            return On_WM_NCHITTEST_LEFT_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos >= (r.right-m_cornerRadius))
            return On_WM_NCHITTEST_RIGHT_WindowMessage
            (hWnd, msg, wParam, lParam);

        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/31/2009
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
            pRect->left += m_cornerRadius;
            pRect->top += m_cornerRadius;
            pRect->right -= m_cornerRadius;
            pRect->bottom -= m_cornerRadius;
        }
        else
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEWINDOW_HXX) || defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */

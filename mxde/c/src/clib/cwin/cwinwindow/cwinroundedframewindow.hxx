/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   Date: 7/19/2010
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEWINDOW_HXX) || defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEWINDOW_HXX) && !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEWINDOW_HXX) && !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
#include "cwinimageroundedrectanglewindow.hxx"
#include "croundedrectangleimageobject.hxx"
#include "cwinimageobject.hxx"
#include "cwinimage.hxx"
#include "cwinstring.hxx"

#define CWINFRAMEWINDOW_FG_COLOR_R 0x99
#define CWINFRAMEWINDOW_FG_COLOR_G 0x99
#define CWINFRAMEWINDOW_FG_COLOR_B 0x77

#define CWINFRAMEWINDOW_BG_COLOR_R 0xFF
#define CWINFRAMEWINDOW_BG_COLOR_G 0xFF
#define CWINFRAMEWINDOW_BG_COLOR_B 0xDD

#define CWINFRAMEWINDOW_FG_COLOR \
    RGB(CWINFRAMEWINDOW_FG_COLOR_R,\
        CWINFRAMEWINDOW_FG_COLOR_G,\
        CWINFRAMEWINDOW_FG_COLOR_B)
    
#define CWINFRAMEWINDOW_BG_COLOR \
    RGB(CWINFRAMEWINDOW_BG_COLOR_R,\
        CWINFRAMEWINDOW_BG_COLOR_G,\
        CWINFRAMEWINDOW_BG_COLOR_B)
    
#define CWINROUNDEDFRAMEWINDOW_CORNER_RADIUS 32
#define CWINROUNDEDFRAMEWINDOW_BORDER_THICKNESS 4

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRoundedFrameWindowExtend
 *
 *  Author: $author$
 *    Date: 7/19/2010
 **********************************************************************
 */
typedef cWinImageRoundedRectangleWindow
cWinRoundedFrameWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameWindow
 *
 * Author: $author$
 *   Date: 7/19/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRoundedFrameWindow
: public cWinRoundedFrameWindowExtend
{
public:
    typedef cWinRoundedFrameWindowExtend cExtends;
    
    TSIZE m_borderThickness;
    
    cWinCOLORREF m_fgColor;
    cWinBrush m_fgBrush;
    
    cWinDC m_imageDC;
    cWinImage m_image;
    cWinImageColor m_imageColor;
    
    cWinString m_caption;
    
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameWindow
     *
     *       Author: $author$
     *         Date: 7/19/2010
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
       
      m_borderThickness
      (CWINROUNDEDFRAMEWINDOW_BORDER_THICKNESS),
       
      m_fgColor(CWINFRAMEWINDOW_FG_COLOR),
      
      m_image(m_imageDC),
      
      m_imageColor
      (m_image,
       CWINFRAMEWINDOW_FG_COLOR_R,
       CWINFRAMEWINDOW_FG_COLOR_G,
       CWINFRAMEWINDOW_FG_COLOR_B, 0,
       m_borderThickness,m_borderThickness)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedFrameWindow
     *
     *      Author: $author$
     *        Date: 7/19/2010
     **********************************************************************
     */
    virtual ~cWinRoundedFrameWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetCaption
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH SetCaption
    (const TCHAR* chars, TLENGTH length=UNDEFINED_LENGTH) 
#if defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count;
        eError error;
        
        if (0 <= (count = m_caption.assign(chars, length)))
        if (!(chars = m_caption.c_str()))
            count = -e_ERROR_FAILED;
        else
        if ((error = SetText(chars)))
            count = -error;

#else /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetCaption
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual const TCHAR* GetCaption
    (TLENGTH& length)
#if defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        const TCHAR* chars = 0;
#if !defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        TCHAR* buffer;
        TLENGTH count;
        HWND hWnd;
        
        length = -e_ERROR_FAILED;
        
        if ((hWnd = Attached())) 
        if (0 <= (count = GetWindowTextLength(hWnd)))
        if (0 < (count = m_caption.adjust_size(count+1)))
        if ((buffer = m_caption.str()))
        if (0 < (count = GetWindowText(hWnd, buffer, count)))
        if ((chars = m_caption.c_str()))
            length = count;
            
#else /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINROUNDEDFRAMEWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINROUNDEDFRAMEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: InitializeWindowClass
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual eError InitializeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error;
        HBRUSH hBrush;

        if (!(error = cExtends::InitializeWindowClass
            (windowClass, hInstance)))
            
        if (!(hBrush = m_fgBrush.Attached()))
            error = m_fgBrush.CreateSolid(m_fgColor.Attached());
            
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalizeWindowClass
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual eError FinalizeWindowClass
    (cWinWindowClass& windowClass,
     HINSTANCE hInstance) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        HBRUSH hBrush;
        
        if ((hBrush = m_fgBrush.Attached()))
            error = m_fgBrush.Destroy(true);
        
        if ((error2 = cExtends::FinalizeWindowClass
            (windowClass, hInstance)))
        if (!error)
            error = error2;
            
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnBeforePaintFrame
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual LRESULT OnBeforePaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;        
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnAfterPaintFrame
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual LRESULT OnAfterPaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;        
        return lResult;
    }
    /**
     **********************************************************************
     * Function: PaintFrame
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual LRESULT PaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;        
        TSIZE width = rect.right-rect.left-m_leftMargin-m_rightMargin-m_cornerRadius*2+2;
        TSIZE height = rect.bottom-rect.top-m_topMargin-m_bottomMargin-m_cornerRadius*2+2;
        cRoundedRectangleImageObject rrObject
        (m_image, m_imageColor, m_cornerRadius, 
         width,height, m_borderThickness);
        RECT frameRect;
        HBRUSH hBrush;
        
        if ((hBrush = m_bgBrush.Attached()))
        {
            frameRect.left = rect.left+m_leftMargin;
            frameRect.top = rect.top+m_topMargin;
            frameRect.right = rect.left+m_leftMargin+m_cornerRadius;
            frameRect.bottom = rect.bottom-m_bottomMargin;
            FillRect(hDC, &frameRect, hBrush);
            
            frameRect.left = rect.right-m_rightMargin-m_cornerRadius;
            frameRect.right = rect.right-m_rightMargin;
            FillRect(hDC, &frameRect, hBrush);
            
            frameRect.left = rect.left+m_leftMargin+m_cornerRadius;
            frameRect.right = rect.right-m_rightMargin-m_cornerRadius;
            frameRect.bottom = rect.top+m_topMargin+m_cornerRadius;
            FillRect(hDC, &frameRect, hBrush);
            
            frameRect.top = rect.bottom-m_bottomMargin-m_cornerRadius;
            frameRect.bottom = rect.bottom-m_bottomMargin;
            FillRect(hDC, &frameRect, hBrush);
        }
            
        m_imageDC.Attach(hDC);
        rrObject.Plot
        (rect.left+m_leftMargin+m_cornerRadius-1, 
         rect.top+m_topMargin+m_cornerRadius-1);
        m_imageDC.Detach();
        GdiFlush();
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
                        
            OnBeforePaintFrame(hWnd, hDC, rect, rect);
            PaintFrame(hWnd, hDC, rect, rect);
            OnAfterPaintFrame(hWnd, hDC, rect, rect);
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
        LONG xPos = GET_X_LPARAM(lParam);
        LONG yPos = GET_Y_LPARAM(lParam);
        LRESULT lResult = 0;
        RECT r;

        if ((GetWindowRect(hWnd, &r)))
        if (yPos < (LONG)(r.top+m_topMargin+m_cornerRadius))
            return On_WM_NCHITTEST_TOP_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (yPos >= (LONG)(r.bottom-m_bottomMargin-m_cornerRadius))
            return On_WM_NCHITTEST_BOTTOM_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos < (LONG)(r.left+m_leftMargin+m_cornerRadius))
            return On_WM_NCHITTEST_LEFT_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos >= (LONG)(r.right-m_rightMargin-m_cornerRadius))
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
                lResult = WVR_VALIDRECTS | WVR_REDRAW;
            }
            pRect->left += (m_leftMargin+m_cornerRadius);
            pRect->top += (m_topMargin+m_cornerRadius);
            pRect->right -= (m_rightMargin+m_cornerRadius);
            pRect->bottom -= (m_bottomMargin+m_cornerRadius);
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

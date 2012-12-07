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
 *   File: cwinhashiconwindow.hxx
 *
 * Author: $author$
 *   Date: 2/16/2010
 **********************************************************************
 */
#if !defined(_CWINHASHICONWINDOW_HXX) || defined(CWINHASHICONWINDOW_MEMBERS_ONLY)
#if !defined(_CWINHASHICONWINDOW_HXX) && !defined(CWINHASHICONWINDOW_MEMBERS_ONLY)
#define _CWINHASHICONWINDOW_HXX
#endif /* !defined(_CWINHASHICONWINDOW_HXX) && !defined(CWINHASHICONWINDOW_MEMBERS_ONLY) */

#if !defined(CWINHASHICONWINDOW_MEMBERS_ONLY)
#include "cwinmainwindow.hxx"
#include "cwinshapedwindow.hxx"
#include "cwinregionimageobject.hxx"
#include "cwinregionimage.hxx"
#include "cwinimageobject.hxx"
#include "cwinimage.hxx"
#include "ckeyiconimageobject.hxx"
#include "cfilledimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinHashIconWindow;
/**
 **********************************************************************
 * Typedef: cWinHashIconWindowExtend
 *
 *  Author: $author$
 *    Date: 2/16/2010
 **********************************************************************
 */
typedef cWinMainWindowT
<cWinHashIconWindow,
 cWinShapedWindow>
cWinHashIconWindowExtend;
/**
 **********************************************************************
 *  Class: cWinHashIconWindow
 *
 * Author: $author$
 *   Date: 2/16/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHashIconWindow
: public cWinHashIconWindowExtend
{
public:
    typedef cWinHashIconWindowExtend cExtends;
    
    cWinDC m_imageDC;
    cWinImage m_image;
    cWinImageColor m_imageRed;
    cWinImageColor m_imageGreen;
    cWinImageColor m_imageBlue;
    cWinImageColor m_imageBlack;
    cWinImageColor m_imageWhite;
    cWinImageColor m_imageGray;
    
    cWinRegion m_brushRegion;
    cWinRegionImage m_regionImage;
    cWinRegionImageObject m_regionBrush;
    
    HWND m_hWndWindow;
    
    /**
     **********************************************************************
     *  Constructor: cWinHashIconWindow
     *
     *       Author: $author$
     *         Date: 2/16/2010
     **********************************************************************
     */
    cWinHashIconWindow
    (COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINSHAPEDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_image(m_imageDC),
      m_imageRed(m_image, 255,0,0),
      m_imageGreen(m_image, 0,255,0),
      m_imageBlue(m_image, 0,0,255),
      m_imageBlack(m_image, 0,0,0),
      m_imageWhite(m_image, 255,255,255),
      m_imageGray(m_image, 128,128,128),
      
      m_regionImage(m_region),
      m_regionBrush(m_regionImage, m_brushRegion),
      
      m_hWndWindow(NULL)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinHashIconWindow
     *
     *      Author: $author$
     *        Date: 2/16/2010
     **********************************************************************
     */
    virtual ~cWinHashIconWindow()
    {
    }
#else /* !defined(CWINHASHICONWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINHASHICONWINDOW_MEMBERS_ONLY) */

#if !defined(CWINHASHICONWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateMainWindow
     *
     *   Author: $author$
     *     Date: 2/13/2010
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        DWORD style = WS_POPUP;
        DWORD styleEx = (m_isLayeredWindow)?WS_EX_LAYERED:0;
        const TCHAR* windowClassNameChars;
        HWND hWndDesktop;
        HWND hWnd;
        RECT r;
        
        if ((windowClassNameChars = windowClass.WindowClassName()))
        if ((hWndDesktop = GetDesktopWindow()))
        if (GetClientRect(hWndDesktop, &r))
        {
            int x = (r.right-r.left)/4;
            int y = (r.bottom-r.top)/4;
            int w = (r.right-r.left)/4;
            int h = (r.right-r.left)/8;
            
            if ((hWnd = CreateAttached
                (error, hInstance, windowClassNameChars, NULL, hWndDesktop, 
                 NULL, style, styleEx, x,y, w, h)))
            {
                //Show();
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$
     *     Date: 2/13/2010
     **********************************************************************
     */
    virtual eError DestroyMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        Destroy();
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateWindowRegion
     *
     *   Author: $author$
     *     Date: 2/13/2010
     **********************************************************************
     */
    virtual HRGN CreateWindowRegion
    (RECT& rect) 
    {
        HRGN hRgn = NULL;
        eError error;
        if (!(error = m_brushRegion.CreateRect(0,0, 1,1)))
        {
            int w = rect.right-rect.left;
            int h = rect.bottom-rect.top;
            
            cKeyIconImageObject kio
            (m_regionImage, m_regionBrush, 
             m_regionBrush, m_regionBrush, w, h);
            
            kio.Plot(0,0);
                
            if (!(error = m_brushRegion.Destroy(true)))
                hRgn = m_region.Attached();
        }
        return hRgn;
    }

    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 2/13/2010
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
        RECT rect;
        
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((GetClientRect(hWnd, &rect)))
            {
                int w = rect.right-rect.left;
                int h = rect.bottom-rect.top;
                
                cKeyIconImageObject kio
                (m_image, m_imageBlack, m_imageGray, m_imageBlack, w, h);
                
                hIDC = m_imageDC.SelectAttached(hDC);
                
                kio.Plot(0,0);
                
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
     * Function: On_WM_NCLBUTTONDBLCLK_WindowMessage
     *
     *   Author: $author$
     *     Date: 2/16/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_NCLBUTTONDBLCLK_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        eError error;
        if (m_hWndWindow)
        if (!(error = Hide()))
            ShowWindow(m_hWndWindow, SW_SHOWNORMAL);
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCRBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 2/13/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_NCRBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        Destroy();
        PostQuitMessage(0);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_WindowMessage
     *
     *   Author: $author$
     *     Date: 2/13/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = HTCAPTION;
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHASHICONWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINHASHICONWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINHASHICONWINDOW_HXX) || defined(CWINHASHICONWINDOW_MEMBERS_ONLY) */

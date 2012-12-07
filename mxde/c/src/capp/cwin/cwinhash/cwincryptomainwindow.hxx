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
 *   File: cwincryptomainwindow.hxx
 *
 * Author: $author$
 *   Date: 12/21/2010
 **********************************************************************
 */
#if !defined(_CWINCRYPTOMAINWINDOW_HXX) || defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINCRYPTOMAINWINDOW_HXX) && !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY)
#define _CWINCRYPTOMAINWINDOW_HXX
#endif /* !defined(_CWINCRYPTOMAINWINDOW_HXX) && !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY)
#include "cwinroundedframemainwindow.hxx"
#include "cwinregionimageobject.hxx"
#include "ckeyiconimageobject.hxx"

#define CWINCRYPTOMAINWINDOW_BG_COLOR_R 0xFF
#define CWINCRYPTOMAINWINDOW_BG_COLOR_G 0xFF
#define CWINCRYPTOMAINWINDOW_BG_COLOR_B 0xDD

#define CWINCRYPTOMAINWINDOW_BG_COLOR \
    RGB(CWINCRYPTOMAINWINDOW_BG_COLOR_R, \
        CWINCRYPTOMAINWINDOW_BG_COLOR_G, \
        CWINCRYPTOMAINWINDOW_BG_COLOR_B)

#define CWINCRYPTOMAINWINDOW_WINDOW_CLASSNAME "cWinCryptoMainWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCryptoMainWindowExtend
 *
 *  Author: $author$
 *    Date: 12/21/2010
 **********************************************************************
 */
typedef cWinRoundedFrameMainWindow
cWinCryptoMainWindowExtend;

/**
 **********************************************************************
 *  Class: cWinCryptoMainWindow
 *
 * Author: $author$
 *   Date: 12/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCryptoMainWindow
: //virtual public cWinCryptoMainWindowImplement,
  public cWinCryptoMainWindowExtend
{
public:
    //typedef cWinCryptoMainWindowImplement cImplements;
    typedef cWinCryptoMainWindowExtend cExtends;

    TSIZE m_iconBorder;
    TSIZE m_iconHeight;
    TSIZE m_iconWidth;
    TOFFSET m_iconX;
    TOFFSET m_iconY;
    
    cWinRegion m_objectBrushRegion;
    cWinRegionImage m_objectRegionImage;
    cWinRegionImageObject m_objectRegionBrush;
    
    cWinImageColor m_imageRed;
    cWinImageColor m_imageGreen;
    cWinImageColor m_imageBlue;
    cWinImageColor m_imageBlack;
    cWinImageColor m_imageWhite;
    cWinImageColor m_imageGray;
    
    /**
     **********************************************************************
     *  Constructor: cWinCryptoMainWindow
     *
     *       Author: $author$
     *         Date: 12/21/2010
     **********************************************************************
     */
    cWinCryptoMainWindow
    (COLORREF bgColor=CWINCRYPTOMAINWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINCRYPTOMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
            
      m_iconBorder(1),
      m_iconHeight((m_cornerRadius*2)-1),
      m_iconWidth(m_iconHeight*2),
      m_iconX(m_cornerRadius),
      m_iconY(0),
      
      m_objectRegionImage(m_region),
      m_objectRegionBrush
      (m_objectRegionImage, m_objectBrushRegion, 
       m_iconBorder*2+1, m_iconBorder*2+1),
      
      m_imageRed(m_image, 255,0,0),
      m_imageGreen(m_image, 0,255,0),
      m_imageBlue(m_image, 0,0,255),
      m_imageBlack(m_image, 0,0,0),
      m_imageWhite(m_image, 255,255,255),
      m_imageGray(m_image, 128,128,128)
    {
        m_topMargin = m_cornerRadius;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCryptoMainWindow
     *
     *      Author: $author$
     *        Date: 12/21/2010
     **********************************************************************
     */
    virtual ~cWinCryptoMainWindow()
    {
    }
#else /* !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/21/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        DestroyWindow(hWnd);
        //LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }

    /**
     **********************************************************************
     * Function: OnBeforePaintFrame
     *
     *   Author: $author$
     *     Date: 12/27/2010
     **********************************************************************
     */
    virtual LRESULT OnBeforePaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;
        HBRUSH hBrush;
        RECT rectIcon;
        
        if ((hBrush = m_fgBrush.Attached()))
        {
            rectIcon.left = m_iconX;
            rectIcon.top = m_iconY;
            rectIcon.right = m_iconX+m_iconWidth+m_iconBorder*2;
            rectIcon.bottom = m_iconY+m_iconHeight+m_iconBorder*2;
            FillRect(hDC, &rectIcon, hBrush);
        }     
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnAfterPaintFrame
     *
     *   Author: $author$
     *     Date: 12/27/2010
     **********************************************************************
     */
    virtual LRESULT OnAfterPaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;        
        HDC hIDC = m_imageDC.SelectAttached(hDC);
        cKeyIconImageObject kiio
        (m_image, m_imageBlack, m_imageGray, 
         m_imageBlack, m_iconWidth, m_iconHeight);
        
        kiio.Plot
        (m_iconX+m_iconBorder, 
         m_iconY+m_iconBorder);
        
        m_imageDC.SelectAttached(hIDC);
        return lResult;
    }

    /**
     **********************************************************************
     *  Function: OnAfterCreateWindowRegion
     *
     *    Author: $author$
     *      Date: 12/27/2010
     **********************************************************************
     */
    virtual HRGN OnAfterCreateWindowRegion
    (HRGN hRgn, RECT& rect)
    {
        eError error;
        
        if (!(error = m_objectBrushRegion.CreateRect(0,0, 1,1)))
        {
            cKeyIconImageObject kiio
            (m_objectRegionImage, m_objectRegionBrush, 
             m_objectRegionBrush, m_objectRegionBrush, 
             m_iconWidth, m_iconHeight);
            
            kiio.Plot(m_iconX,m_iconY);
            m_objectBrushRegion.Destroy(true);
        }
        return hRgn;
    }

    /**
     **********************************************************************
     * Function: ChangeDefaultWindowSize
     *
     *   Author: $author$
     *     Date: 12/21/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        width = m_cornerRadius*2+200;
        height = m_cornerRadius*2+100;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINCRYPTOMAINWINDOW_HXX) || defined(CWINCRYPTOMAINWINDOW_MEMBERS_ONLY) */

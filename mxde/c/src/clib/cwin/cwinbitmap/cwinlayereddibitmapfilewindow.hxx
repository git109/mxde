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
 *   File: cwinlayereddibitmapfilewindow.hxx
 *
 * Author: $author$
 *   Date: 12/20/2009
 **********************************************************************
 */
#if !defined(_CWINLAYEREDDIBITMAPFILEWINDOW_HXX) || defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINLAYEREDDIBITMAPFILEWINDOW_HXX) && !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#define _CWINLAYEREDDIBITMAPFILEWINDOW_HXX
#endif /* !defined(_CWINLAYEREDDIBITMAPFILEWINDOW_HXX) && !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#include "cwindibitmapfilewindow.hxx"
#include "cwinrgbpixel.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinLayeredDIBitmapFileWindowExtend
 *
 *  Author: $author$
 *    Date: 12/20/2009
 **********************************************************************
 */
typedef cWinDIBitmapFileWindow
cWinLayeredDIBitmapFileWindowExtend;
/**
 **********************************************************************
 *  Class: cWinLayeredDIBitmapFileWindow
 *
 * Author: $author$
 *   Date: 12/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinLayeredDIBitmapFileWindow
: public cWinLayeredDIBitmapFileWindowExtend
{
public:
    typedef cWinLayeredDIBitmapFileWindowExtend cExtends;
    
    cWinRGBPixel m_invisibleBgColorMin;
    cWinRGBPixel m_invisibleBgColorMax;
    cWinRGBPixel m_transparentBgColorMin;
    cWinRGBPixel m_transparentBgColorMax;
    UINT m_transparentBgColorAlpha;
    
    /**
     **********************************************************************
     *  Constructor: cWinLayeredDIBitmapFileWindow
     *
     *       Author: $author$
     *         Date: 12/20/2009
     **********************************************************************
     */
    cWinLayeredDIBitmapFileWindow
    (const TCHAR* bitmapFileNameChars=0,
     COLORREF invisibleBgColorMin=CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR,
     COLORREF invisibleBgColorMax=CWINDIBITMAPWINDOW_INVISIBLE_BG_COLOR,
     COLORREF transparentBgColorMin=CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR,
     COLORREF transparentBgColorMax=CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR,
     UINT transparentBgColorAlpha=CWINDIBITMAPWINDOW_TRANSPARENT_BG_COLOR_A,
     COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bitmapFileNameChars,
       bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_invisibleBgColorMin(invisibleBgColorMin),
      m_invisibleBgColorMax(invisibleBgColorMax),
      
      m_transparentBgColorMin(transparentBgColorMin),
      m_transparentBgColorMax(transparentBgColorMax),
      m_transparentBgColorAlpha(transparentBgColorAlpha)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinLayeredDIBitmapFileWindow
     *
     *      Author: $author$
     *        Date: 12/20/2009
     **********************************************************************
     */
    virtual ~cWinLayeredDIBitmapFileWindow()
    {
    }
#else /* !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnInvisibleBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnInvisibleBitmapPixel
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTransparentBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnTransparentBitmapPixel
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOpaqueBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnOpaqueBitmapPixel
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnBitmapPixel
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        int unequal;
        
        if (255 > (pixel.Green()))
            unequal = 0;
            
        if ((0 <= (unequal = pixel.Compare(m_invisibleBgColorMin))) 
            && (0 >= (unequal = pixel.Compare(m_invisibleBgColorMax))))
            error = OnInvisibleBitmapPixel
            (pixel, byte, bytes, col, row);
        else
        if ((0 <= (unequal = pixel.Compare(m_transparentBgColorMin))) 
            && (0 >= (unequal = pixel.Compare(m_transparentBgColorMax))))
            error = OnTransparentBitmapPixel
            (pixel, byte, bytes, col, row);
        else
        error = OnOpaqueBitmapPixel
        (pixel, byte, bytes, col, row);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginBitmapRow
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBitmapRow
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnEndBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginBitmap
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBitmap
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual eError OnEndBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINLAYEREDDIBITMAPFILEWINDOW_HXX) || defined(CWINLAYEREDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

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
 *   File: cwinshapeddibitmapfilewindow.hxx
 *
 * Author: $author$
 *   Date: 12/21/2009
 **********************************************************************
 */
#if !defined(_CWINSHAPEDDIBITMAPFILEWINDOW_HXX) || defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINSHAPEDDIBITMAPFILEWINDOW_HXX) && !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#define _CWINSHAPEDDIBITMAPFILEWINDOW_HXX
#endif /* !defined(_CWINSHAPEDDIBITMAPFILEWINDOW_HXX) && !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#include "cwindibitmapfilewindow.hxx"
#include "cwinrgbpixel.hxx"
#include "cwinregion.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinShapedDIBitmapFileWindowExtend
 *
 *  Author: $author$
 *    Date: 12/21/2009
 **********************************************************************
 */
typedef cWinDIBitmapFileWindow
cWinShapedDIBitmapFileWindowExtend;
/**
 **********************************************************************
 *  Class: cWinShapedDIBitmapFileWindow
 *
 * Author: $author$
 *   Date: 12/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinShapedDIBitmapFileWindow
: public cWinShapedDIBitmapFileWindowExtend
{
public:
    typedef cWinShapedDIBitmapFileWindowExtend cExtends;
    typedef cWinShapedDIBitmapFileWindow cDerives;
    
    typedef eError (cDerives::*MOnBitmapPixel)
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row);
     
    typedef eError (cDerives::*MOnEndBitmapRow)
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row);
     
    cWinRGBPixel m_invisibleBgColorMin;
    cWinRGBPixel m_invisibleBgColorMax;
    cWinRGBPixel m_transparentBgColorMin;
    cWinRGBPixel m_transparentBgColorMax;
    UINT m_transparentBgColorAlpha;
    
    MOnBitmapPixel m_onBitmapPixel;
    MOnEndBitmapRow m_onEndBitmapRow;
    
    INT m_regionXOffset;
    INT m_regionYOffset;
    
    UINT m_bitmapRows;
    UINT m_bitmapCols;
    
    cWinRegion m_region;
    cWinRegion m_regionPixel;
    RECT m_pixelRect;
    
    /**
     **********************************************************************
     *  Constructor: cWinShapedDIBitmapFileWindow
     *
     *       Author: $author$
     *         Date: 12/21/2009
     **********************************************************************
     */
    cWinShapedDIBitmapFileWindow
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
      m_transparentBgColorAlpha(transparentBgColorAlpha),
      
      m_onBitmapPixel(0),
      m_onEndBitmapRow(0),
      
      m_regionXOffset(0),
      m_regionYOffset(0),
      
      m_bitmapRows(0),
      m_bitmapCols(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinShapedDIBitmapFileWindow
     *
     *      Author: $author$
     *        Date: 12/21/2009
     **********************************************************************
     */
    virtual ~cWinShapedDIBitmapFileWindow()
    {
    }
#else /* !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnBeginBitmap
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        m_bitmapRows = rows;
        m_bitmapCols = cols;
        m_regionPixel.CreateRect(0,0, 1,1);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBitmap
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnEndBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        m_regionPixel.Destroy(true);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitmapPixelIn
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnBitmapPixelIn
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        int unequal;
        
        if ((0 > (unequal = pixel.Compare(m_invisibleBgColorMin))) 
            || (0 < (unequal = pixel.Compare(m_invisibleBgColorMax))))
        {
            m_pixelRect.right = col;
        }
        else
        {
            CombinePixelAndRegion();
            m_onBitmapPixel = &cDerives::OnBitmapPixelOut;
            m_onEndBitmapRow = &cDerives::OnEndBitmapRowOut;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitmapPixelOut
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnBitmapPixelOut
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        int unequal;
        
        if ((0 > (unequal = pixel.Compare(m_invisibleBgColorMin))) 
            || (0 < (unequal = pixel.Compare(m_invisibleBgColorMax))))
        {
            m_pixelRect.left = col;
            m_pixelRect.right = m_pixelRect.left+1;
            m_pixelRect.bottom = m_bitmapRows-row;
            m_pixelRect.top = m_pixelRect.bottom-1;
            m_onBitmapPixel = &cDerives::OnBitmapPixelIn;
            m_onEndBitmapRow = &cDerives::OnEndBitmapRowIn;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/21/2009
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
        if (m_onBitmapPixel)
            error = (this->*m_onBitmapPixel)
            (pixel, byte, bytes, col, row);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBitmapRowIn
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnEndBitmapRowIn
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        CombinePixelAndRegion();
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBitmapRowOut
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnEndBitmapRowOut
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
     * Function: OnBeginBitmapRow
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        m_onBitmapPixel = &cDerives::OnBitmapPixelOut;
        m_onEndBitmapRow = &cDerives::OnEndBitmapRowOut;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBitmapRow
     *
     *   Author: $author$
     *     Date: 12/21/2009
     **********************************************************************
     */
    virtual eError OnEndBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
        if (m_onEndBitmapRow)
            error = (this->*m_onEndBitmapRow)
            (rowByte, rowBytes, rowCols, row);
        return error;
    }
    /**
     **********************************************************************
     *  Function: CombinePixelAndRegion
     *
     *    Author: $author$
     *      Date: 12/21/2009
     **********************************************************************
     */
    eError CombinePixelAndRegion()
    {
        eError error = e_ERROR_NONE;
        eError error2;
        HRGN hRgn;
        
        if (!(error2 = m_regionPixel.SetRect
            (m_pixelRect.left+m_regionXOffset,
             m_pixelRect.top+m_regionXOffset, 
             m_pixelRect.right+m_regionXOffset,
             m_pixelRect.bottom+m_regionXOffset)))
        {
            if (!(hRgn = m_region.Attached()))
            if ((error2 = m_region.CreateRect
                (m_pixelRect.left+m_regionXOffset,
                 m_pixelRect.top+m_regionYOffset, 
                 m_pixelRect.right+m_regionXOffset,
                 m_pixelRect.bottom+m_regionYOffset)))
                return error;
                
            m_region.Combine(m_regionPixel);
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINSHAPEDDIBITMAPFILEWINDOW_HXX) || defined(CWINSHAPEDDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

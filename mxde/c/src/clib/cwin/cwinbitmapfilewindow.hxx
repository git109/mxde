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
 *   File: cwinbitmapfilewindow.hxx
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEWINDOW_HXX) || defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEWINDOW_HXX) && !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY)
#define _CWINBITMAPFILEWINDOW_HXX
#endif /* !defined(_CWINBITMAPFILEWINDOW_HXX) && !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY)
#include "cwinbitmapwindow.hxx"
#include "cwindibitmapfile.hxx"
#include "cwinrgbquad.hxx"
#include "cwinregion.hxx"

#define CWINBITMAPFILEWINDOW_WINDOW_CLASSNAME \
    "cWinBitmapFileWindow"

#define CWINBITMAPFILEWINDOW_SHADOW_XOFFSET 10
#define CWINBITMAPFILEWINDOW_SHADOW_YOFFSET 10

#define CWINBITMAPFILEWINDOW_SHADOW_BG_COLOR \
    RGB(0,0,0)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapFileWindowExtends
 *
 *  Author: $author$
 *    Date: 12/2/2009
 **********************************************************************
 */
typedef cWinBitmapWindow
cWinBitmapFileWindowExtends;
/**
 **********************************************************************
 *  Class: cWinBitmapFileWindow
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapFileWindow
: virtual public cWinBitmapFileImplement,
  public cWinBitmapFileWindowExtends
{
public:
    typedef cWinBitmapFileWindowExtends cExtends;
    typedef cWinBitmapFileWindow cDerives;
    
    typedef eError (cDerives::*MOnPixel)
    (RGBQUAD& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row);
    
    typedef eError (cDerives::*MOnEndRow)
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row);
     
    const TCHAR* m_bitmapFileNameChars;

    cWinDIBitmap m_bitmap;
    cWinBitmapInfo m_bitmapInfo;
    cWinDIBitmapFile m_diBitmapFile;
    cWinBitmapFile m_bitmapFile;
    cWinRegion m_regionPixel;
    cWinRegion m_regionImage;
    cWinRGBQUAD m_transparentColorMin;
    cWinRGBQUAD m_transparentColorMax;
    MOnPixel m_onPixel;
    MOnEndRow m_onEndRow;
    RECT m_pixelRect;
    TSIZE m_imageRows;
    TSIZE m_imageCols;
    int m_regionXOffset;
    int m_regionYOffset;
    
    /**
     **********************************************************************
     *  Constructor: cWinBitmapFileWindow
     *
     *       Author: $author$
     *         Date: 12/2/2009
     **********************************************************************
     */
    cWinBitmapFileWindow
    (const TCHAR* bitmapFileNameChars=0,
     COLORREF transparentColorMin=RGB(0,0,0),
     COLORREF transparentColorMax=RGB(0,0,0),
     COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINBITMAPFILEWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
      m_bitmapFileNameChars(bitmapFileNameChars),
      m_bitmapFile(this),
      m_transparentColorMin(transparentColorMin),
      m_transparentColorMax(transparentColorMax),
      m_onPixel(0),
      m_onEndRow(0),
      m_imageRows(1),
      m_imageCols(1),
      m_regionXOffset(0),
      m_regionYOffset(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinBitmapFileWindow
     *
     *      Author: $author$
     *        Date: 12/2/2009
     **********************************************************************
     */
    virtual ~cWinBitmapFileWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
    
    /**
     **********************************************************************
     *  Function: OnPixelOut
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    eError OnPixelOut
    (RGBQUAD& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row)
    {
        eError error = e_ERROR_NONE;
        
        if (!(m_transparentColorMin <= rgb) 
            || !(m_transparentColorMax >= rgb))
        {
            m_pixelRect.left = col;
            m_pixelRect.right = col+1;
            m_pixelRect.top = m_imageRows-row-1;
            m_pixelRect.bottom = m_imageRows-row;
            m_onPixel = &cDerives::OnPixelIn;
            m_onEndRow = &cDerives::OnEndRowIn;
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnPixelIn
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    eError OnPixelIn
    (RGBQUAD& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row)
    {
        eError error = e_ERROR_NONE;
        
        if (!(m_transparentColorMin <= rgb) 
            || !(m_transparentColorMax >= rgb))
            m_pixelRect.right = col;
        else
        {
            error = CombinePixelAndImage();
            m_onPixel = &cDerives::OnPixelOut;
            m_onEndRow = &cDerives::OnEndRowOut;
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnEndRowOut
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    eError OnEndRowOut
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnEndRowIn
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    eError OnEndRowIn
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row)
    {
        eError error = CombinePixelAndImage();
        return error;
    }
    /**
     **********************************************************************
     *  Function: CombinePixelAndImage
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    eError CombinePixelAndImage()
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
#else /* !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: OnImage
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual eError OnImage
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes)
#if defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        m_imageRows = rows;
        m_imageCols = cols;
#else /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: OnPixel
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual eError OnPixel
    (RGBQUAD& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row)
#if defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        if (m_onPixel)
            error = (this->*m_onPixel)
            (rgb, byte, bytes, col, row);
#else /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: OnBeginRow
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual eError OnBeginRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row)
#if defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        m_onPixel = &cDerives::OnPixelOut;
        m_onEndRow = &cDerives::OnEndRowIn;
#else /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnEndRow
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual eError OnEndRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row)
#if defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        if (m_onEndRow)
            error = (this->*m_onEndRow)
            (rowByte, rowBytes, rowCols,row);
#else /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreateWindowRegion
     *
     *    Author: $author$
     *      Date: 12/2/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowRegion
    (RECT& rect)
#if defined(CWINBMPMAINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBMPMAINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
#if !defined(CWINBMPMAINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count;
        eError error;
        if (m_bitmapFileNameChars)
        if (!(error = m_regionPixel.CreateRect(0,0, 1,1)))
        {
            if (0 <= (count = m_bitmapFile.Read
                (m_bitmapFileNameChars)))
                hRgn = m_region.Attached();
            else
            m_region.Destroy();
            
            m_regionPixel.Destroy(true);
        }
#else /* !defined(CWINBMPMAINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBMPMAINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINBMPMAINWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetWindowBitmap
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual HBITMAP GetWindowBitmap() const
#if defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HBITMAP hBitmap = NULL;
#if !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        hBitmap = m_bitmap.Attached();
#else /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hBitmap;
    }
#endif /* defined(CWINBITMAPFILEWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEWINDOW_HXX) || defined(CWINBITMAPFILEWINDOW_MEMBERS_ONLY) */

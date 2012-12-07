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
 *   File: cwindroidmainwindow.hxx
 *
 * Author: $author$
 *   Date: 1/22/2010
 **********************************************************************
 */
#if !defined(_CWINDROIDMAINWINDOW_HXX) || defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINDROIDMAINWINDOW_HXX) && !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY)
#define _CWINDROIDMAINWINDOW_HXX
#endif /* !defined(_CWINDROIDMAINWINDOW_HXX) && !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY)
#include "cwinmainwindow.hxx"
#include "cwinimagetoshapeddibitmapwindow.hxx"
#include "cwincmdline.hxx"
#include "cpngimagereader.hxx"
#include "cwinimageobject.hxx"
#include "cwinimage.hxx"

#define CWINPNGMAINWINDOW_FILENAME "../../../../../doc/images/cwindroid/skins/default/device.png"
#define CWINPNGMAINWINDOW_CLIENT_X 31
#define CWINPNGMAINWINDOW_CLIENT_Y 72
#define CWINPNGMAINWINDOW_CLIENT_WIDTH 320
#define CWINPNGMAINWINDOW_CLIENT_HEIGHT 480

#define CWINPNGMAINWINDOW_IVISIBLE_PIXEL_COLOR_R 0
#define CWINPNGMAINWINDOW_IVISIBLE_PIXEL_COLOR_G 0
#define CWINPNGMAINWINDOW_IVISIBLE_PIXEL_COLOR_B 0

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinDroidMainWindow;
/**
 **********************************************************************
 * Typedef: cWinDroidMainWindowExtend
 *
 *  Author: $author$
 *    Date: 1/22/2010
 **********************************************************************
 */
typedef cWinMainWindowT
<cWinDroidMainWindow,
 cWinImageToShapedDIBitmapWindow>
cWinDroidMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinDroidMainWindow
 *
 * Author: $author$
 *   Date: 1/22/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDroidMainWindow
: public cWinDroidMainWindowExtend
{
public:
    typedef cWinDroidMainWindowExtend cExtends;
    typedef cWinDroidMainWindow cDerives;

    typedef LRESULT (cDerives::*MOnWindowMessage)
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
     
    cPNGImageReader m_pngReader;
    
    cImagePixel m_invisiblePixel;
    
    LONG m_clientX, m_clientY;
    LONG m_clientWidth, m_clientHeight;
    
    TSIZE m_visibleXmin, m_visibleXmax;
    TSIZE m_visibleYmin, m_visibleYmax;
    TSIZE m_visibleBorder;
    
    cImagePixel* m_rowPixel;
    cWinRegion m_rowRegion;
    
    cWinDC m_imageDC;
    cWinImage m_image;
    cWinImageColor m_imageRed;
    cWinImageColor m_imageGreen;
    cWinImageColor m_imageBlue;
    cWinImageColor m_imageBlack;
    cWinImageColor m_imageWhite;
    cWinImageColor* m_imageColor;
    
    INT m_x1,m_y1, m_x2,m_y2, m_x3,m_y3;
    
    MOnWindowMessage m_on_WM_LBUTTONUP_WindowMessage;
    
    /**
     **********************************************************************
     *  Constructor: cWinDroidMainWindow
     *
     *       Author: $author$
     *         Date: 1/22/2010
     **********************************************************************
     */
    cWinDroidMainWindow
    (const TCHAR* fileNameChars=_T(CWINPNGMAINWINDOW_FILENAME),
     COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_pngReader(this),
      
      m_invisiblePixel
      (CWINPNGMAINWINDOW_IVISIBLE_PIXEL_COLOR_R,
       CWINPNGMAINWINDOW_IVISIBLE_PIXEL_COLOR_G,
       CWINPNGMAINWINDOW_IVISIBLE_PIXEL_COLOR_B),
      
      m_clientX(CWINPNGMAINWINDOW_CLIENT_X),
      m_clientY(CWINPNGMAINWINDOW_CLIENT_Y),
      m_clientWidth(CWINPNGMAINWINDOW_CLIENT_WIDTH),
      m_clientHeight(CWINPNGMAINWINDOW_CLIENT_HEIGHT),
      
      m_visibleXmin(0),
      m_visibleXmax(0),
      m_visibleYmin(0),
      m_visibleYmax(0),
      m_visibleBorder(1),
      
      m_rowPixel(0),

      m_image(m_imageDC),
      m_imageRed(m_image, 255,0,0),
      m_imageGreen(m_image, 0,255,0),
      m_imageBlue(m_image, 0,0,255),
      m_imageBlack(m_image, 0,0,0),
      m_imageWhite(m_image, 255,255,255),
      m_imageColor(0),
      
      m_x1(-1),m_y1(-1),
      m_x2(-1),m_y2(-1),
      m_x3(-1),m_y3(-1),
      
      m_on_WM_LBUTTONUP_WindowMessage(0)
    {
        m_fileNameChars = fileNameChars;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDroidMainWindow
     *
     *      Author: $author$
     *        Date: 1/22/2010
     **********************************************************************
     */
    virtual ~cWinDroidMainWindow()
    {
    }
#else /* !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnMainWindowCreated
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual eError OnMainWindowCreated
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        const TCHAR* fileNameChars = m_fileNameChars;
        cWinCmdLine cmd(cmdLine);
        cTCHARString fileName;
        const TCHAR* cmdArg;
        TLENGTH cmdArgLength;
        HWND hWnd;
        
        if ((cmdArg = cmd.FirstArg(cmdArgLength)))
        if (0 < (fileName.Assign(cmdArg, cmdArgLength)))
        if ((cmdArg = fileName.HasChars(cmdArgLength)))
            fileNameChars = cmdArg;
            
        if ((hWnd = Attached()))
            DragAcceptFiles(hWnd, TRUE);
            
        if ((fileNameChars))
            Read(fileNameChars);
        return error;
    }
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
    {
        HRGN hRgn = m_region.Attached();
        return hRgn;
    }
    
    /**
     **********************************************************************
     * Function: IsVisiblePixel
     *
     *   Author: $author$
     *     Date: 1/22/2010
     **********************************************************************
     */
    virtual bool IsVisiblePixel
    (cImagePixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) const
    {
        bool is = ((pixel.Red()>pixel.Green()) 
                    && (pixel.Red()>pixel.Blue())
                    && (((pixel.Green()<80)
                    &&  (pixel.Blue()<80))
                    || (imageCol <= 12) 
                    || (imageRow <= 32)));
        return is;
    }
    /**
     **********************************************************************
     * Function: OnImagePixel
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnImagePixel
    (cImagePixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        bool isVisiblePixel = IsVisiblePixel
        (pixel, pixelByte, pixelBytes, 
         imageCol, imageRow, imagePlane, 
         imagePlanes, imageHeight, imageWidth, 
         valuesPerPixel, bitsPerValue, pixelValueInterpretation);
          
        eError error = e_ERROR_NONE;
        
        if (isVisiblePixel)
        {
            if (imageCol < m_visibleXmin)
                m_visibleXmin = imageCol;
                
            if (imageCol > m_visibleXmax)
                m_visibleXmax = imageCol;
        }
        
        if (m_rowPixel)
        {
            cImagePixel& imagePixel = m_rowPixel[imageCol];
            imagePixel.SetRed(pixel.Red());   
            imagePixel.SetGreen(pixel.Green());   
            imagePixel.SetBlue(pixel.Blue());
            imagePixel.SetAlpha(isVisiblePixel?1:0);   
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginImageRow
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnBeginImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        m_visibleXmin = imageWidth;
        m_visibleXmax = 0;
        error = cExtends::OnBeginImageRow
        (rowByte, rowBytes, imageRow, 
         imagePlane, imagePlanes, imageHeight, imageWidth,
         valuesPerPixel, bitsPerValue, pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndImageRow
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnEndImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        HRGN hRgn, hRowRgn;
        TSIZE imageCol;
        
        if (m_rowPixel)
        for (imageCol = 0; imageCol < imageWidth; imageCol++)
        {
            cImagePixel& imagePixel = m_rowPixel[imageCol];
            bool isVisiblePixel = (0 < imagePixel.Alpha());
            
            if ((imageCol >= m_visibleXmin) 
                && (imageCol <= m_visibleXmax))
                isVisiblePixel = true;
                
            if ((error = cExtends::OnImagePixel
                (isVisiblePixel?m_rowPixel[imageCol]:m_invisiblePixel, 
                 rowByte, rowBytes, 
                 imageCol, imageRow, imagePlane, 
                 imagePlanes, imageHeight, imageWidth, 
                 valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
                return error;
        }
        
        if ((m_visibleXmax >= m_visibleXmin))
        {
            TSIZE visibleLeft = m_visibleXmin;
            TSIZE visibleRight = m_visibleXmax+1;
            TSIZE visibleTop = imageRow;
            TSIZE visibleBottom = imageRow+1;
            
            if (visibleLeft > m_visibleBorder)
                visibleLeft -= m_visibleBorder;
            else visibleLeft =0;
            
            if ((visibleRight += m_visibleBorder) > imageWidth)
                visibleRight = imageWidth;
                
            if (visibleTop > m_visibleBorder)
                visibleTop -= m_visibleBorder;
            else visibleTop =0;
            
            if ((visibleBottom += m_visibleBorder) > imageHeight)
                visibleBottom = imageHeight;
                
            if ((hRgn = m_region.Attached()))
            {
                if ((hRowRgn = m_rowRegion.Attached()))
                    m_rowRegion.SetRect
                    (visibleLeft, visibleTop,
                     visibleRight, visibleBottom);                 
                else
                if (!(error = m_rowRegion.CreateRect
                    (visibleLeft, visibleTop,
                     visibleRight, visibleBottom)))
                     hRowRgn = m_rowRegion.Attached();
                else
                return error;
                                     
                if ((hRowRgn))
                    m_region.Combine(m_rowRegion);
            }
            else
            if ((error = m_region.CreateRect
                (visibleLeft, visibleTop,
                 visibleRight, visibleBottom)))
                return error;
        }
        
        error = cExtends::OnEndImageRow
        (rowByte, rowBytes, imageRow, 
         imagePlane, imagePlanes, imageHeight, imageWidth,
         valuesPerPixel, bitsPerValue, pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginImage
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnBeginImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        
        if (!(m_rowPixel = new cImagePixel[imageWidth]))
            return e_ERROR_NEW;
            
        if (error)
        {
            delete[] m_rowPixel;
            m_rowPixel = 0;
            return error;
        }
        
        m_visibleYmin = imageHeight;
        m_visibleYmax = 0;
        error = cExtends::OnBeginImage
        (imagePlanes, imageHeight, imageWidth,
         valuesPerPixel, bitsPerValue, pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndImage
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnEndImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        
        error = cExtends::OnEndImage
        (imagePlanes, imageHeight, imageWidth,
         valuesPerPixel, bitsPerValue, pixelValueInterpretation);
        
        m_region.Destroy();
        m_rowRegion.Destroy();
         
        if (m_rowPixel)
        {
            delete[] m_rowPixel;
            m_rowPixel = 0;
        }
        return error;
    }
    
    /**
     **********************************************************************
     * Function: On_WM_LBUTTONUP_WindowMessage_2
     *
     *   Author: $author$
     *     Date: 2/2/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_LBUTTONUP_WindowMessage_2
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult;
        RECT rect;
         
        m_x2 = GET_X_LPARAM(lParam);
        m_y2 = GET_Y_LPARAM(lParam);
        
        //if ((GetClientRect(hWnd, &rect)))
        //    InvalidateRect(hWnd, &rect, TRUE);
            
        m_on_WM_LBUTTONUP_WindowMessage 
        = &cDerives::On_WM_LBUTTONUP_WindowMessage_3;
        
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_LBUTTONUP_WindowMessage_3
     *
     *   Author: $author$
     *     Date: 2/2/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_LBUTTONUP_WindowMessage_3
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult;
        RECT rect;
         
        m_x3 = GET_X_LPARAM(lParam);
        m_y3 = GET_Y_LPARAM(lParam);
        
        if ((GetClientRect(hWnd, &rect)))
            InvalidateRect(hWnd, &rect, TRUE);
            
        m_on_WM_LBUTTONUP_WindowMessage = 0;
        
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_LBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 2/2/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_LBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult;
        RECT rect;
         
        if (m_on_WM_LBUTTONUP_WindowMessage)
            return (this->*m_on_WM_LBUTTONUP_WindowMessage)
            (hWnd,msg,wParam,lParam);
            
        m_x1 = GET_X_LPARAM(lParam);
        m_y1 = GET_Y_LPARAM(lParam);
        
        //if ((GetClientRect(hWnd, &rect)))
        //    InvalidateRect(hWnd, &rect, TRUE);
            
        m_on_WM_LBUTTONUP_WindowMessage 
        = &cDerives::On_WM_LBUTTONUP_WindowMessage_2;
        
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/22/2010
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
                hIDC = m_imageDC.SelectAttached(hDC);
                image = m_image.SelectImage
                ((m_imageColor)?(m_imageColor):(&m_imageRed));
                
                INT x1 = (m_x1>=0)?(m_x1):(r.right/2);
                INT x2 = (m_x2>=0)?(m_x2):(r.right*3/4);
                INT x3 = (m_x3>=0)?(m_x3):(r.right/4);
                INT y1 = (m_y1>=0)?(m_y1):(r.bottom/4);
                INT y2 = (m_y2>=0)?(m_y2):(r.bottom*3/4);
                INT y3 = (m_y3>=0)?(m_y3):(r.bottom*3/4);
                
                m_image.FillTriangle
                (x1,y1, 
                 x2,y2, 
                 x3,y3);
                 
               m_image.SelectImage(&m_imageBlue);
               m_image.Draw(x1,y1, x2,y2);
               m_image.Draw(x2,y2, x3,y3);
               m_image.Draw(x3,y3, x1,y1);
               
/*                
                m_image.SelectImage(&m_imageGreen);
                
                m_image.FillTriangle
                (r.left+10,r.bottom-11, 
                 r.right-11,r.top+10, 
                 r.left+11,r.top+10);
                
                m_image.SelectImage(&m_imageBlue);
                
                m_image.FillTriangle
                (r.left+10,r.bottom/4, 
                 r.right-11,r.top+10, 
                 r.right/4,r.bottom-11);
                
                m_image.SelectImage(&m_imageBlack);
                
                m_image.FillTriangle
                (r.right-11,r.bottom/4, 
                 r.left+10,r.top+10, 
                 (r.right*3)/4,r.bottom-11);
*/                
                m_image.SelectAsImage(image);
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
     * Function: NCPaintBitmap
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual LRESULT NCPaintBitmap
    (HWND hWnd, HDC hDC, RECT& rect)
    {
        LRESULT lResult = 0;
        HBITMAP hBitmap;
        HDC hDCBitmap;

        rect.right -= rect.left;
        rect.bottom -= rect.top;
        rect.left = (rect.top = 0);        
        
        if ((hBitmap = GetWindowBitmap()))
        if ((hDCBitmap = CreateCompatibleDC(hDC)))
        {
            HGDIOBJ hGDIOBJ = SelectObject(hDCBitmap, hBitmap);

            BitBlt
            (hDC, rect.left,rect.top, 
             m_clientX, rect.bottom-rect.top, 
             hDCBitmap, 0,0, SRCCOPY);

            BitBlt
            (hDC, rect.left+m_clientX,rect.top, 
             (rect.right-rect.left)-m_clientX, m_clientY, 
             hDCBitmap, 0+m_clientX,0, SRCCOPY);

            BitBlt
            (hDC, rect.left+m_clientX+m_clientWidth,rect.top+m_clientY, 
             (rect.right-rect.left)-(m_clientX+m_clientWidth), (rect.bottom-rect.top)-m_clientY, 
             hDCBitmap, 0+m_clientX+m_clientWidth,0+m_clientY, SRCCOPY);

            BitBlt
            (hDC, rect.left+m_clientX,rect.top+m_clientY+m_clientHeight, 
             m_clientWidth, (rect.bottom-rect.top)-(m_clientY+m_clientHeight), 
             hDCBitmap, 0+m_clientX,0+m_clientY+m_clientHeight, SRCCOPY);

            SelectObject(hDCBitmap, hGDIOBJ);
            DeleteDC(hDCBitmap);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/22/2010
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
            NCPaintBitmap(hWnd, hDC, rect);
            ReleaseDC(hWnd, hDC);
        }
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
    virtual LRESULT On_WM_NCCALCSIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        LPRECT pRect;
        LONG width;
        LONG height;

        if ((pRect = (LPRECT)(lParam)))
        {
            if (wParam)
            {
                NCCALCSIZE_PARAMS& nccParams = *(LPNCCALCSIZE_PARAMS)(lParam);
                pRect = &nccParams.rgrc[0];
                lResult = WVR_VALIDRECTS;
            }
            width = (pRect->right - pRect->left);
            height = (pRect->bottom - pRect->top);
            
            if ((m_clientWidth+m_clientX < (width)) 
                && (m_clientHeight+m_clientY < (height)))
            {
                pRect->left += m_clientX;
                pRect->top += m_clientY;
                pRect->right = (pRect->left + m_clientWidth);
                pRect->bottom = (pRect->top + m_clientHeight);
            }
            else
            lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
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
     *     Date: 12/26/2009
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
        if (yPos < (r.top+m_clientY))
            return On_WM_NCHITTEST_TOP_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (yPos >= (r.top+m_clientY+m_clientHeight))
            return On_WM_NCHITTEST_BOTTOM_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos < (r.left+m_clientX))
            return On_WM_NCHITTEST_LEFT_WindowMessage
            (hWnd, msg, wParam, lParam);
        else
        if (xPos >= (r.left+m_clientX+m_clientWidth))
            return On_WM_NCHITTEST_RIGHT_WindowMessage
            (hWnd, msg, wParam, lParam);

        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCRBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/26/2009
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
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        Destroy();
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        PostQuitMessage(0);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: WindowStyle
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual DWORD WindowStyle() const 
    {
        DWORD style = WS_POPUP;
        return style;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowSize
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        HWND hWnd;
        RECT rect;
        
        width = 100;
        height = 100;
        
        if ((hWnd = GetDesktopWindow()))
        if ((GetClientRect(hWnd, &rect)))
        {
            width = (rect.right-rect.left)/4;
            height = (rect.bottom-rect.top)/4;
        }
        return error;
    }
    
    /**
     **********************************************************************
     * Function: GetImageReader
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual tImageReaderInterface* GetImageReader
    (eError& error,
     const CHAR* fileName,
     tImageReaderEventsInterface* delegated=0) 
    {
        tImageReaderInterface* reader = &m_pngReader;
        error = e_ERROR_NONE;
        return reader;
    }
    /**
     **********************************************************************
     * Function: FreeImageReader
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError FreeImageReader
    (tImageReaderInterface& reader) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }     
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINDROIDMAINWINDOW_HXX) || defined(CWINDROIDMAINWINDOW_MEMBERS_ONLY) */

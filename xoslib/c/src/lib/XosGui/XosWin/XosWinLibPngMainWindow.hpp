///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosWinLibPngMainWindow.hpp
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINLIBPNGMAINWINDOW_HPP) || defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY)
#if !defined(_XOSWINLIBPNGMAINWINDOW_HPP) && !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY)
#define _XOSWINLIBPNGMAINWINDOW_HPP
#endif // !defined(_XOSWINLIBPNGMAINWINDOW_HPP) && !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY) 

#if !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY)
#include "WinMainWindow.hpp"
#include "XosLibPngReader.hpp"
#include "XosLibPngImage.hpp"
#include "XosWinGLContext.hpp"
#include "XosOpenGLTexture2DImageRenderer.hpp"

#define XOSLIBPNG_IMAGE_FILENAME "XosLibPngImage.png"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinLibPngMainWindowExtend
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef WinMainWindow
XosWinLibPngMainWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinLibPngMainWindow
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinLibPngMainWindow
: virtual public XosLibPngReaderEventsImplement,
  public XosWinLibPngMainWindowExtend
{
public:
    typedef XosWinLibPngMainWindowExtend Extends;
    typedef XosWinLibPngMainWindow Derives;

    enum Draw {
        Image,
        ResizedImage,
        ResizedInImage
    };

    XosLibPngReader m_pngReader;
    std::string m_imageFileName;
    UINT m_minInImageWidth, m_minInImageHeight;
    UINT m_inImageOffsetX, m_inImageOffsetY;
    UINT m_inImageRatio, m_inImageRatioTo;
    UINT m_imageWidth, m_imageHeight;
    TSIZE m_imageSize;
    BYTE* m_imageRow;
    BYTE* m_imageCol;
    BYTE* m_image;
    Draw m_draw;

    GLuint m_glTexture;
    XosWinGLContext m_glContext;
    XosOpenGLTexture2DImageRenderer m_glRenderer;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinLibPngMainWindow
    ///
    ///       Author: $author$
    ///         Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinLibPngMainWindow()
    : m_pngReader(this),
      m_imageFileName(XOSLIBPNG_IMAGE_FILENAME),
      m_minInImageWidth(100),
      m_minInImageHeight(100),
      m_inImageOffsetX(10),
      m_inImageOffsetY(10),
      m_inImageRatio(8),
      m_inImageRatioTo(3),
      m_imageWidth(480),
      m_imageHeight(240),
      m_imageSize(0),
      m_imageRow(0),
      m_imageCol(0),
      m_image(0),
      m_draw(Image)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinLibPngMainWindow
    ///
    ///      Author: $author$
    ///        Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinLibPngMainWindow()
    {
        if ((m_image))
            free(m_image);
    }
#else // !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY) 
#endif // !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY) 

#if !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGPixel
    ///
    ///    Author: $author$
    ///      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGPixel
    (XosPixel& pixel,
     BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
    {
        XosError error = XOS_ERROR_NONE;
        if ((m_imageCol))
        {
        m_imageCol[0] = pixel.m_channel[XosPixel::XOS_COLOR_CHANNEL_BLUE];
        m_imageCol[1] = pixel.m_channel[XosPixel::XOS_COLOR_CHANNEL_GREEN];
        m_imageCol[2] = pixel.m_channel[XosPixel::XOS_COLOR_CHANNEL_RED];
        m_imageCol[3] = pixel.m_channel[XosPixel::XOS_COLOR_CHANNEL_ALPHA];
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnEndPNGCol
    ///
    ///    Author: $author$
    ///      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnEndPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
    {
        XosError error = XOS_ERROR_NONE;
        if ((m_imageCol))
            m_imageCol += 4;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnEndPNGRow
    ///
    ///    Author: $author$
    ///      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnEndPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
    {
        XosError error = XOS_ERROR_NONE;
        if ((m_imageRow) && (m_imageCol))
            m_imageCol = (m_imageRow += m_imageWidth*4);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnBeginPNGImage
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnBeginPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
    {
        XosError error = XOS_ERROR_NONE;

        if ((m_image))
            free(m_image);

        m_imageWidth = width;
        m_imageHeight = height;
        m_imageSize = height*width*4;
        m_imageCol = (m_imageRow = m_image = (BYTE*)(malloc(m_imageSize)));
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_SIZE_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 2/2/2013
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_SIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        if ((m_image))
        {
		    RECT rc;
            GetClientRect(hWnd, &rc);
            InvalidateRect(hWnd, NULL, TRUE);
            glViewport(0, 0, rc.right-rc.left, rc.bottom-rc.top);
        }
        lResult = Extends::On_WM_SIZE_WindowMessage(hWnd,msg,wParam,lParam);
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_ERASEBKGND_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 2/2/2013
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_ERASEBKGND_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        if ((m_image))
        {
            return lResult;
        }
        lResult = Extends::On_WM_SIZE_WindowMessage(hWnd,msg,wParam,lParam);
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_PAINT_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 11/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        if ((m_image))
        {
		    RECT rc;
            GetClientRect(hWnd, &rc);
		    ValidateRect(hWnd, NULL);

            switch(m_draw) 
            {
            default:
            case Image:
                m_glRenderer.RenderImage
                (m_glTexture, m_image, m_imageWidth, m_imageHeight);
                SwapBuffers(m_glContext.m_hDC);
                break;

            case ResizedImage:
                m_glRenderer.RenderResizedImage
                (m_glTexture, m_image, m_imageWidth, m_imageHeight,
                 rc.right-rc.left, rc.bottom-rc.top);
                SwapBuffers(m_glContext.m_hDC);
                break;

            case ResizedInImage:
                m_glRenderer.RenderResizedImage
                (m_glTexture, m_image, m_imageWidth, m_imageHeight,
                 m_image, m_imageWidth, m_imageHeight, 
                 rc.right-rc.left, rc.bottom-rc.top,
                 m_inImageOffsetX,m_inImageOffsetY, 
                 m_minInImageWidth,m_minInImageHeight, 
                 m_inImageRatio, m_inImageRatioTo);
                SwapBuffers(m_glContext.m_hDC);
                break;
            }
        }
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_NCHITTEST_BOTTOM_RIGHT_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 11/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_NCHITTEST_BOTTOM_RIGHT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = HTBOTTOMRIGHT;//HTCAPTION;
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_LBUTTONUP_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 11/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_LBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        if ((m_image))
        {
            switch(m_draw) 
            {
            default:
            case Image:
                m_draw = ResizedImage;
                break;

            case ResizedImage:
                m_draw = ResizedInImage;
                break;

            case ResizedInImage:
                m_draw = Image;
                break;
            }
            InvalidateRect(hWnd, NULL, TRUE);
        }
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_DESTROY_WindowMessage
    ///
    ///   Author: $author$
    ///     Date: 11/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        m_glContext.Destroy();
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnFileDropped
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void OnFileDropped(const char* fileName)
    {
        if ((fileName))
        {
            HWND hWnd = Attached();
            RECT rect;
            m_pngReader.Read(fileName);
            if ((GetClientRect(hWnd, &rect)))
                InvalidateRect(hWnd, &rect, TRUE);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMainWindowCreated
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void OnMainWindowCreated() 
    {
        if (!(m_glContext.Create(Attached())))
        {
            glGenTextures(1, &m_glTexture);
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_CULL_FACE);

            const uint8_t* imageData;
            size_t imageSize;
            const char* fileName;

            if ((imageData = XosLibPngImage::m_imageData)
                && (imageSize = XosLibPngImage::m_imageSize))
                m_pngReader.Read(imageData, imageSize);
            else
            if ((fileName = m_imageFileName.c_str()))
                m_pngReader.Read(fileName);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMainWindowDestroy
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void OnMainWindowDestroy() 
    {
        m_glContext.Destroy();
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY) 
#endif // !defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY) 

#endif // !defined(_XOSWINLIBPNGMAINWINDOW_HPP) || defined(XOSWINLIBPNGMAINWINDOW_MEMBERS_ONLY) 

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
///   File: XosToBGRALibPngReaderPeer.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSTOBGRALIBPNGREADERPEER_HPP
#define _XOSTOBGRALIBPNGREADERPEER_HPP

#include "XosLibPngReader.hpp"
#include "XosLibPngImage.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosToBGRALibPngReaderPeerImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngReaderEventsImplement
XosToBGRALibPngReaderPeerImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosToBGRALibPngReaderPeerExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngBase
XosToBGRALibPngReaderPeerExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosToBGRALibPngReaderPeer
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosToBGRALibPngReaderPeer
: virtual public XosToBGRALibPngReaderPeerImplement,
  public XosToBGRALibPngReaderPeerExtend
{
public:
    typedef XosToBGRALibPngReaderPeerImplement Implements;
    typedef XosToBGRALibPngReaderPeerExtend Extends;

    XosLibPngReader m_pngReader;
    UINT m_imageWidth;
    UINT m_imageHeight;
    TSIZE m_imageSize;
    BYTE* m_imageRow;
    BYTE* m_imageCol;
    BYTE* m_image;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosToBGRALibPngReaderPeer
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosToBGRALibPngReaderPeer()
    : m_pngReader(this),
      m_imageWidth(0),
      m_imageHeight(0),
      m_imageSize(0),
      m_imageRow(0),
      m_imageCol(0),
      m_image(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosToBGRALibPngReaderPeer
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosToBGRALibPngReaderPeer()
    {
        if ((m_image))
            free(m_image);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t* Read
    (size_t& width, size_t& height,
     const uint8_t* dataBuffer, size_t dataBufferSize)
    {
        uint8_t* image = 0;

        if ((m_image))
            free(m_image);

        m_imageWidth = 0;
        m_imageHeight = 0;
        m_imageSize = 0;
        m_imageRow = 0;
        m_imageCol = 0;
        m_image = 0;

        if (0 <= (m_pngReader.Read(dataBuffer, dataBufferSize)))
        {
            width = m_imageWidth;
            height = m_imageHeight;
            image = m_image;
        }
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t* Read
    (size_t& width, size_t& height,
     const char* fileName)
    {
        uint8_t* image = 0;

        if ((m_image))
            free(m_image);

        m_imageWidth = 0;
        m_imageHeight = 0;
        m_imageSize = 0;
        m_imageRow = 0;
        m_imageCol = 0;
        m_image = 0;

        if (0 <= (m_pngReader.Read(fileName)))
        {
            width = m_imageWidth;
            height = m_imageHeight;
            image = m_image;
        }
        return image;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGPixel
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
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
    ///      Date: 5/1/2012
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
    ///      Date: 5/1/2012
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
    ///      Date: 5/1/2012
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
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSTOBGRALIBPNGREADERPEER_HPP 
        


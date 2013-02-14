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
///   File: XosLibPngReader.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGREADER_HPP) || defined(XOSLIBPNGREADER_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGREADER_HPP) && !defined(XOSLIBPNGREADER_MEMBERS_ONLY)
#define _XOSLIBPNGREADER_HPP
#endif // !defined(_XOSLIBPNGREADER_HPP) && !defined(XOSLIBPNGREADER_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGREADER_MEMBERS_ONLY)
#include "XosLibPngReaderEvents.hpp"
#include "XosLibPngReaderEventsInterface.hpp"
#include "XosLibPngInfoReaderInterfaceCreated.hpp"
#include "XosLibPngInfoReaderInterface.hpp"
#include "XosLibPngBase.hpp"
#include "XosPixel.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngReaderImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngReaderEventsImplement
XosLibPngReaderImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngReaderExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngReaderEvents
XosLibPngReaderExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngReader
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngReader
: virtual public XosLibPngReaderImplement,
  public XosLibPngReaderExtend
{
public:
    typedef XosLibPngReaderImplement Implements;
    typedef XosLibPngReaderExtend Extends;
    typedef XosLibPngReader Derives;

    XosLibPngInfoReaderInterfaceCreated m_pngInfoReader;

    typedef XosError (Derives::*MOnPNGCol)
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType);
     
    TSIZE m_colBytes;
    MOnPNGCol m_onPNGCol;
    png_int_32 m_bytesRead;
    
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngReader
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngReader
    (XosLibPngReaderEventsInterface* delegated=0)
    : Extends(delegated),
      m_colBytes(0),
      m_onPNGCol(0),
      m_bytesRead(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngReader
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngReader()
    {
    }
#else // !defined(XOSLIBPNGREADER_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADER_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (const uint8_t* imageData, 
     size_t imageSize)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosError error;
        XosLibPngInfoReaderInterface* pngInfoReader;

        if (!(error = m_pngInfoReader.Create()))
        {
            if ((pngInfoReader = m_pngInfoReader.Attached()))        
            if ((pngInfoReader->AttachBuffer(imageData, imageSize, imageSize)))
            {
                count = Read(pngInfoReader);
                pngInfoReader->DetachBuffer();
            }
            m_pngInfoReader.Destroy();
        }
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (const char* fileName)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosError error;
        XosLibPngInfoReaderInterface* pngInfoReader;

        if (!(error = m_pngInfoReader.Create()))
        {
            if ((pngInfoReader = m_pngInfoReader.Attached()))        
            if (!(error = pngInfoReader->Open(fileName)))
            {
                count = Read(pngInfoReader);
                pngInfoReader->Close();
            }
            m_pngInfoReader.Destroy();
        }
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (XosLibPngInfoReaderInterface* pngInfoReader)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosError error;
        png_int_32 value;
        size_t height, width, bitDepth, colorChannels;
        unsigned colorType, filterType, interlaceType, compressionType;

        if (0 < (value = (m_bytesRead = pngInfoReader->ReadBegin(1))))
        if (0 <= (value = pngInfoReader->GetImageHeight()))
        if (0 <= (height = value))
        if (0 <= (value = pngInfoReader->GetImageWidth()))
        if (0 <= (width = value))
        if (0 <= (value = pngInfoReader->GetBitDepth()))
        if (0 <= (bitDepth = value))
        if (0 <= (value = pngInfoReader->GetColorChannels()))
        if (0 <= (colorChannels = value))
        if (0 <= (value = pngInfoReader->GetColorType()))
        if (0 <= (colorType = value))
        if (0 <= (value = pngInfoReader->GetFilterType()))
        if (0 <= (filterType = value))
        if (0 <= (value = pngInfoReader->GetInterlaceType()))
        if (0 <= (interlaceType = value))
        if (0 <= (value = pngInfoReader->GetCompressionType()))
        if (0 <= (compressionType = value))
        if (!(error = OnBeginPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
        if (!(error = OnPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
        if (0 <= (value = pngInfoReader->ReadEnd()))
        if (!(error = OnEndPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
        {
        }
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: On8BitPalette8BitPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On8BitPalette8BitPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: On8BitPalette16BitPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On8BitPalette16BitPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: On8BitRGBAPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On8BitRGBAPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosPixel pixel(colByte[0], colByte[1], colByte[2], colByte[3]);
        error = OnPNGPixel
        (pixel, colByte, colBytes, col, row, 
         height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: On8BitRGBPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On8BitRGBPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosPixel pixel(colByte[0], colByte[1], colByte[2]);
        error = OnPNGPixel
        (pixel, colByte, colBytes, col, row, 
         height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: On16BitRGBAPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On16BitRGBAPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosPixel pixel(colByte[0], colByte[1], colByte[2], colByte[3]);
        error = OnPNGPixel
        (pixel, colByte, colBytes, col, row, 
         height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: On16BitRGBPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On16BitRGBPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosPixel pixel(colByte[0], colByte[1], colByte[2]);
        error = OnPNGPixel
        (pixel, colByte, colBytes, col, row, 
         height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        if ((m_onPNGCol))
            error = (this->*m_onPNGCol)
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType);
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        BYTE* colByte;
        TSIZE col;
        
        for (colByte = rowByte, col = 0; 
             col < width; col++, colByte += m_colBytes)
        {
            if (!(error = OnBeginPNGCol
                (colByte, m_colBytes, col, row, 
                 height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
            if (!(error = OnPNGCol
                (colByte, m_colBytes, col, row, 
                 height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
            if (!(error = OnEndPNGCol
                (colByte, m_colBytes, col, row, 
                 height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
                continue;
            break;
        }
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGColorType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGColorType
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        switch(colorType)
        {
        case PNG_COLOR_TYPE_RGB:
            switch(bitDepth)
            {
            case 8:
                m_onPNGCol = &Derives::On8BitRGBPNGCol;
                break;
            case 16:
                m_onPNGCol = &Derives::On16BitRGBPNGCol;
                break;
            }
            break;
            
        case PNG_COLOR_TYPE_RGB_ALPHA:
            switch(bitDepth)
            {
            case 8:
                m_onPNGCol = &Derives::On8BitRGBAPNGCol;
                break;
            case 16:
                m_onPNGCol = &Derives::On16BitRGBAPNGCol;
                break;
            }
            break;
            
        case PNG_COLOR_TYPE_PALETTE:
            switch(bitDepth)
            {
            case 8:
                m_onPNGCol = &Derives::On8BitPalette8BitPNGCol;
                break;
            case 16:
                m_onPNGCol = &Derives::On8BitPalette16BitPNGCol;
                break;
            }
            break;
        }
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGImage
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngInfoReaderInterface* pngInfoReader;
        png_bytep* imageRow;
        png_int_32 imageRows;
        png_int_32 rowBytes;
        png_bytep rowByte;
        png_int_32 rowIndex;
        png_int_32 row;
        png_int_32 count;
        
        OnPNGColorType
        (height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);

        m_colBytes = ((bitDepth+7)/8)*colorChannels;
                
        if ((pngInfoReader = m_pngInfoReader.Attached()))
        if ((imageRow = pngInfoReader->ImageRow(imageRows, rowBytes)))
        if ((0 < (imageRows)) && (0 < (rowBytes)))
        for (row = 0; row < (png_int_32)(height); row += imageRows)
        {
            if (0 > (count = pngInfoReader->ReadRows()))
                break;
                
            m_bytesRead += count;

            for (rowByte = imageRow[rowIndex = 0]; 
                 rowIndex < imageRows; rowByte = imageRow[++rowIndex])
            {
                if (!(error = OnBeginPNGRow
                    (rowByte, rowBytes, row+rowIndex,
                     height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType)))
                if (!(error = OnPNGRow
                    (rowByte, rowBytes, row+rowIndex,
                     height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType)))
                if (!(error = OnEndPNGRow
                    (rowByte, rowBytes, row+rowIndex,
                     height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType)))
                    continue;
                    
                return error;
            }
        }
#else // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADER_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGREADER_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGREADER_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADER_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGREADER_HPP) || defined(XOSLIBPNGREADER_MEMBERS_ONLY) 
        


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
///   File: XosLibPngInfo.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGINFO_HPP) || defined(XOSLIBPNGINFO_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGINFO_HPP) && !defined(XOSLIBPNGINFO_MEMBERS_ONLY)
#define _XOSLIBPNGINFO_HPP
#endif // !defined(_XOSLIBPNGINFO_HPP) && !defined(XOSLIBPNGINFO_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFO_MEMBERS_ONLY)
#include "XosLibPngInfoInterface.hpp"
#include "XosLibPngStructInterface.hpp"
#include "XosLibPngInterfaceBase.hpp"
#include "XosLibPngColorPalette.hpp"
#include "XosLibPngBase.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoExtendExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<png_infop, int, 0, 
 XosLibPngInfoAttachedInterfaceImplement>
XosLibPngInfoExtendExtend;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<png_infop, int, 0, 
 XosLibPngInfoAttachedInterface,
 XosLibPngInfoExtendExtend>
XosLibPngInfoExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfo
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngInfo
: virtual public XosLibPngInfoInterface,
  public XosLibPngInfoExtend
{
public:
    typedef XosLibPngInfoInterface Implements;
    typedef XosLibPngInfoExtend Extends;

    XosLibPngStructInterface& m_pngStruct;
    XosLibPngColorPalette m_colorPalette;

    png_bytep* m_imageRow;
    png_uint_32 m_imageRows;
    png_uint_32 m_imageRowsPerRead;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngInfo
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngInfo
    (XosLibPngStructInterface& pngStruct,
     png_infop attached=0,
     bool isCreated=false) 
    : Extends(attached, isCreated),
      m_pngStruct(pngStruct),
      m_colorPalette(pngStruct, *this),
      m_imageRow(0),
      m_imageRows(0),
      m_imageRowsPerRead(1)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngInfo
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngInfo()
    {
        XosError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else // !defined(XOSLIBPNGINFO_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFO_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo detached;
        bool isCreated;

        if ((error = Destroyed()))
            return error;

        if ((structAttached = m_pngStruct.Attached()))
        if ((isCreated = (NULL != (detached = png_create_info_struct
            (structAttached)))))
        {
            m_attached = detached;
            m_isCreated = isCreated;
            error = XOS_ERROR_NONE;
        }
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy()
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo detached;

        if ((error = FreedImageRows()))
            return error;

        SetIsCreated(false);

        if ((detached = Detach()))
        {
            if ((structAttached = m_pngStruct.Attached()))
                png_destroy_info_struct
                (structAttached, &detached);
            else
            error = XOS_ERROR_FAILED;
        }
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ReadBegin
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 ReadBegin
    (png_int_32 rowsPerRead=0)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 count = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 rows, rowBytes, bytesRead;
        int bitDepth, colorType, colorChannels;
        int paletteColors;
        XosError error;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -XOS_ERROR_NOT_ATTACHED;

        bytesRead = m_pngStruct.SetBytesRead(count);

        // The call to png_read_info() gives all of the information from the
        // PNG file before the first IDAT (image data chunk).
        //
        png_read_info(structAttached, attached);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

        if ((0 > (rows = GetImageHeight())))
            return rows;

        if ((0 > (rowBytes = GetImageRowBytes())))
            return rowBytes;

        if (0 > (bitDepth = GetBitDepth()))
            return bitDepth;

        if (0 > (colorType = GetColorType()))
            return colorType;

        if (0 > (colorChannels = GetColorChannels()))
            return colorChannels;

        if (PNG_COLOR_MASK_PALETTE != (PNG_COLOR_MASK_PALETTE & colorType))
            paletteColors = 0;
        else
        if (0 > (paletteColors = m_colorPalette.Get()))
            return paletteColors;

        if (0 > (rowsPerRead))
            rowsPerRead = rows;
        else
        if (1 > (rowsPerRead))
        if (0 >= (rowsPerRead = GetImageRowsPerRead()))
            return -XOS_ERROR_FAILED;
            
        // Allocate the memory to hold the image rows. 
        //
        if (!(m_imageRow = AllocateImageRows
            (error, rowBytes, rowsPerRead)))
            return -error;
        else
        m_imageRows = rowsPerRead;
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ReadEnd
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 ReadEnd()
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 count = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 bytesRead;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -XOS_ERROR_NOT_ATTACHED;

        bytesRead = m_pngStruct.SetBytesRead(count);

        // read rest of file, and get additional chunks in info_ptr
        //
        png_read_end(structAttached, attached);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ReadRows
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 ReadRows()
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 count = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 bytesRead;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -XOS_ERROR_NOT_ATTACHED;

        if ((!m_imageRows) || (!m_imageRow))
            return -XOS_ERROR_FAILED;
            
        bytesRead = m_pngStruct.SetBytesRead(count);

        // Read m_imageRows rows at a time 
        //        
        png_read_rows
        (structAttached, m_imageRow, 
         png_bytepp_NULL, m_imageRows);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 Read()
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 count = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 rows, rowBytes, bytesRead;
        int bitDepth, colorType, colorChannels;
        int paletteColors;
        XosError error;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -XOS_ERROR_NOT_ATTACHED;

        bytesRead = m_pngStruct.SetBytesRead(count);

        // The call to png_read_info() gives all of the information from the
        // PNG file before the first IDAT (image data chunk).
        //
        png_read_info(structAttached, attached);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

        if ((0 > (rows = GetImageHeight())))
            return rows;

        if ((0 > (rowBytes = GetImageRowBytes())))
            return rowBytes;

        if (0 > (bitDepth = GetBitDepth()))
            return bitDepth;

        if (0 > (colorType = GetColorType()))
            return colorType;

        if (0 > (colorChannels = GetColorChannels()))
            return colorChannels;

        if (PNG_COLOR_MASK_PALETTE != (PNG_COLOR_MASK_PALETTE & colorType))
            paletteColors = 0;
        else
        if (0 > (paletteColors = m_colorPalette.Get()))
            return paletteColors;

        // Allocate the memory to hold the image rows. 
        //
        if (!(m_imageRow = AllocateImageRows
            (error, rowBytes, rows)))
            return -error;
        else
        m_imageRows = rows;

        bytesRead = m_pngStruct.SetBytesRead(count);

        // Read the image all at once 
        //
        png_read_image(structAttached, m_imageRow);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

        bytesRead = m_pngStruct.SetBytesRead(count);

        // read rest of file, and get additional chunks in info_ptr
        //
        png_read_end(structAttached, attached);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AllocateImageRows
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_bytep* AllocateImageRows
    (XosError& error, png_uint_32 rowBytes, png_uint_32 rows)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_bytep* imageRow = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_uint_32 row;

        error = XOS_ERROR_NONE;

        if (0 < rows)
        if (!(imageRow = new png_bytep[rows]))
            error = XOS_ERROR_NEW;
        else
        {
            for (row = 0; row < rows; row++)
            {
                if ((imageRow[row] = AllocateImageRow(error, rowBytes)))
                    continue;

                for (row++; row > 0; )
                    FreeImageRow(imageRow[--row]);

                FreeImageRows(*imageRow);
                imageRow = 0;
                break;
            }
        }
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return imageRow;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: FreeImageRows
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError FreeImageRows
    (png_bytep& imageRow)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_bytep* pImageRow = &imageRow;
        png_uint_32 row;

        for (row = m_imageRows; row; --row, pImageRow++)
            FreeImageRow(*pImageRow);

        delete[] &imageRow;
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: FreedImageRows
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError FreedImageRows()
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        if ((m_imageRow))
            error = FreeImageRows(*m_imageRow);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AllocateImageRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_bytep AllocateImageRow
    (XosError& error, png_uint_32 rowBytes)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_bytep imageRow = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        error = XOS_ERROR_NONE;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            error = XOS_ERROR_NOT_ATTACHED;
        else
        if (!(imageRow = (png_bytep)
            (png_malloc(structAttached, rowBytes))))
            error = XOS_ERROR_FAILED;
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return imageRow;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: FreeImageRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError FreeImageRow
    (png_bytep imageRow)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if (!(imageRow))
            error = XOS_ERROR_NULL_PARAMETER;
        else
        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            error = XOS_ERROR_NOT_ATTACHED;
        else
        png_free(structAttached, imageRow);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ImageRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_bytep* ImageRow
    (png_int_32& imageRows, png_int_32& rowBytes) const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_bytep* imageRow = 0;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        imageRow = (m_imageRow);
        imageRows = (m_imageRows);
        rowBytes = (GetImageRowBytes());
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return imageRow;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetImageWidth
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 SetImageWidth
    (png_uint_32 toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetImageWidth
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 GetImageWidth() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) && 
            (structAttached = m_pngStruct.Attached()))
            value = png_get_image_width(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetImageHeight
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 SetImageHeight
    (png_uint_32 toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetImageHeight
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 GetImageHeight() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_image_height(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetBitDepth
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetBitDepth
    (png_byte toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetBitDepth
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetBitDepth() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_bit_depth(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetColorType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetColorType
    (png_byte toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetColorType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetColorType() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_color_type(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetColorChannels
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetColorChannels
    (png_byte toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetColorChannels
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetColorChannels() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_channels(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetFilterType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetFilterType
    (png_byte toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetFilterType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetFilterType() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_filter_type(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetInterlaceType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetInterlaceType
    (png_byte toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetInterlaceType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetInterlaceType() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_interlace_type(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetCompressionType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int SetCompressionType
    (png_byte toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetCompressionType
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetCompressionType() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        int value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_compression_type(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetImageRowBytes
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 SetImageRowBytes
    (png_uint_32 toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetImageRowBytes
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 GetImageRowBytes() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) && 
            (structAttached = m_pngStruct.Attached()))
            value = png_get_rowbytes(structAttached, attached);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetImageRowsPerRead
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 SetImageRowsPerRead
    (png_uint_32 toValue)
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetImageRowsPerRead
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 GetImageRowsPerRead() const
#if defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 value = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT)
        value = (m_imageRowsPerRead);
#else // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        return value;
    }
#endif // defined(XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGINFO_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGINFO_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFO_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGINFO_HPP) || defined(XOSLIBPNGINFO_MEMBERS_ONLY) 
        


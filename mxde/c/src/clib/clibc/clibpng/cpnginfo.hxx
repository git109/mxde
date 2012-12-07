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
 *   File: cpnginfo.hxx
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
#if !defined(_CPNGINFO_HXX) || defined(CPNGINFO_MEMBERS_ONLY)
#if !defined(_CPNGINFO_HXX) && !defined(CPNGINFO_MEMBERS_ONLY)
#define _CPNGINFO_HXX
#endif /* !defined(_CPNGINFO_HXX) && !defined(CPNGINFO_MEMBERS_ONLY) */

#if !defined(CPNGINFO_MEMBERS_ONLY)
#include "cpnginfointerface.hxx"
#include "cpngstructinterface.hxx"
#include "cpngcolorpalette.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cPngInfo;
/**
 **********************************************************************
 * Typedef: cPngInfoExtends
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cCreatedT
<cPngInfo, 
 cPngInfoImplement, 
 cPngInfoAttached>
cPngInfoExtends;
/**
 **********************************************************************
 *  Class: cPngInfo
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfo
: public cPngInfoExtends
{
public:
    typedef cPngInfoExtends cExtends;
    typedef cPngInfo cDerives;

    cPngStructInterface& m_pngStruct;

    png_bytep* m_imageRow;
    png_uint_32 m_imageRows;
    png_uint_32 m_imageRowsPerRead;

    cPngColorPalette m_colorPalette;

    /**
     **********************************************************************
     * Constructor: cPngInfo
     *
     *      Author: $author$
     *        Date: 6/10/2009
     **********************************************************************
     */
    cPngInfo
    (cPngStructInterface& pngStruct,
     png_infop attached=0,
     bool isCreated=false) 
    : cExtends(isCreated),
      m_pngStruct(pngStruct),
      m_imageRow(0),
      m_imageRows(0),
      m_imageRowsPerRead(1),
      m_colorPalette(pngStruct, *this)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cPngInfo
     *
     *     Author: $author$
     *       Date: 6/10/2009
     **********************************************************************
     */
    virtual ~cPngInfo()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CPNGINFO_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFO_MEMBERS_ONLY) */

#if !defined(CPNGINFO_MEMBERS_ONLY) 
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        png_structp structAttached;
        tAttachedTo detached;
        bool isCreated;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((structAttached = m_pngStruct.Attached()))
        if ((isCreated = (NULL != (detached = png_create_info_struct
            (structAttached)))))
        {
            m_attached = detached;
            m_isCreated = isCreated;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_FAILED;
        png_structp structAttached;
        tAttachedTo detached;

        if ((error = FreedImageRows()))
            return error;

        if ((error = Created(onlyCreated, true)))
            return error;

        SetIsCreated(false);

        if ((detached = Detach()))
        {
            if ((structAttached = m_pngStruct.Attached()))
                png_destroy_info_struct
                (structAttached, &detached);
            else
            error = e_ERROR_FAILED;
        }
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;

        return error;
    }
#else /* !defined(CPNGINFO_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFO_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: ReadBegin
     *
     *   Author: $author$
     *     Date: 1/14/2010
     **********************************************************************
     */
    virtual png_int_32 ReadBegin
    (png_int_32 rowsPerRead=0) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 count = 0;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 rows, rowBytes, bytesRead;
        int bitDepth, colorType, colorChannels;
        int paletteColors;
        eError error;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -e_ERROR_NOT_ATTACHED;

        bytesRead = m_pngStruct.SetBytesRead(count);

        /* The call to png_read_info() gives all of the information from the
         * PNG file before the first IDAT (image data chunk).
         */
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
            return -e_ERROR_FAILED;
            
        /* Allocate the memory to hold the image rows. 
         */
        if (!(m_imageRow = AllocateImageRows
            (error, rowBytes, rowsPerRead)))
            return -error;
        else
        m_imageRows = rowsPerRead;

#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadEnd
     *
     *   Author: $author$
     *     Date: 1/14/2010
     **********************************************************************
     */
    virtual png_int_32 ReadEnd() 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 count = 0;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 bytesRead;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -e_ERROR_NOT_ATTACHED;

        bytesRead = m_pngStruct.SetBytesRead(count);

        /* read rest of file, and get additional chunks in info_ptr
         */
        png_read_end(structAttached, attached);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadRows
     *
     *   Author: $author$
     *     Date: 1/14/2010
     **********************************************************************
     */
    virtual png_int_32 ReadRows() 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 count = 0;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 bytesRead;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -e_ERROR_NOT_ATTACHED;

        if ((!m_imageRows) || (!m_imageRow))
            return -e_ERROR_FAILED;
            
        bytesRead = m_pngStruct.SetBytesRead(count);

        /* Read m_imageRows rows at a time 
         */        
        png_read_rows
        (structAttached, m_imageRow, 
         png_bytepp_NULL, m_imageRows);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 Read() 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 count = 0;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 rows, rowBytes, bytesRead;
        int bitDepth, colorType, colorChannels;
        int paletteColors;
        eError error;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            return -e_ERROR_NOT_ATTACHED;

        bytesRead = m_pngStruct.SetBytesRead(count);

        /* The call to png_read_info() gives all of the information from the
         * PNG file before the first IDAT (image data chunk).
         */
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

        /* Allocate the memory to hold the image rows. 
         */
        if (!(m_imageRow = AllocateImageRows
            (error, rowBytes, rows)))
            return -error;
        else
        m_imageRows = rows;

        bytesRead = m_pngStruct.SetBytesRead(count);

        /* Read the image all at once 
         */
        png_read_image(structAttached, m_imageRow);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;

        bytesRead = m_pngStruct.SetBytesRead(count);

        /* read rest of file, and get additional chunks in info_ptr
         */
        png_read_end(structAttached, attached);

        if (0 > (count = m_pngStruct.SetBytesRead(bytesRead)))
            return count;
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 Write() 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 count = 0;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNGINFO_MEMBERS_ONLY) 
    /**
     **********************************************************************
     * Function: FreedImageRows
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual eError FreedImageRows
    (bool onlyFreed=false,
     bool dontFree=false) 
    {
        eError error = e_ERROR_NONE;
        if ((m_imageRow))
        if (onlyFreed)
            return e_ERROR_FAILED;
        else
        if (!(dontFree))
            error = FreeImageRows(*m_imageRow);
        return error;
    }
    /**
     **********************************************************************
     * Function: AllocateImageRows
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_bytep* AllocateImageRows
    (eError& error, png_uint_32 rowBytes, png_uint_32 rows) 
    {
        png_bytep* imageRow = 0;
        png_uint_32 row;

        error = e_ERROR_NONE;

        if (0 < rows)
        if (!(imageRow = new png_bytep[rows]))
            error = e_ERROR_NEW;
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
        return imageRow;
    }
    /**
     **********************************************************************
     * Function: FreeImageRows
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual eError FreeImageRows
    (png_bytep& imageRow) 
    {
        eError error = e_ERROR_NONE;
        png_bytep* pImageRow = &imageRow;
        png_uint_32 row;

        for (row = m_imageRows; row; --row, pImageRow++)
            FreeImageRow(*pImageRow);

        delete[] &imageRow;
        return error;
    }

    /**
     **********************************************************************
     * Function: AllocateImageRow
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual png_bytep AllocateImageRow
    (eError& error,
     png_uint_32 rowBytes) 
    {
        png_bytep imageRow = NULL;
        png_structp structAttached;
        tAttachedTo attached;

        error = e_ERROR_NONE;

        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            error = e_ERROR_NOT_ATTACHED;
        else
        if (!(imageRow = (png_bytep)
            (png_malloc(structAttached, rowBytes))))
            error = e_ERROR_FAILED;

        return imageRow;
    }
    /**
     **********************************************************************
     * Function: FreeImageRow
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual eError FreeImageRow
    (png_bytep imageRow) 
    {
        eError error = e_ERROR_NONE;
        png_structp structAttached;
        tAttachedTo attached;

        if (!(imageRow))
            error = e_ERROR_NULL_PARAMETER;
        else
        if (!(attached = Attached()) || 
            !(structAttached = m_pngStruct.Attached()))
            error = e_ERROR_NOT_ATTACHED;
        else
        png_free(structAttached, imageRow);

        return error;
    }
#else /* !defined(CPNGINFO_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFO_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetImageWidth
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 SetImageWidth
    (png_uint_32 toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetImageWidth
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 GetImageWidth() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) && 
            (structAttached = m_pngStruct.Attached()))
            value = png_get_image_width(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetImageHeight
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 SetImageHeight
    (png_uint_32 toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetImageHeight
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 GetImageHeight() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_image_height(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBitDepth
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int SetBitDepth
    (png_byte toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = 0;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetBitDepth
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetBitDepth() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_bit_depth(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetColorType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int SetColorType
    (png_byte toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetColorType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetColorType() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_color_type(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetColorChannels
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int SetColorChannels
    (png_byte toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetColorChannels
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetColorChannels() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_channels(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetFilterType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int SetFilterType
    (png_byte toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFilterType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetFilterType() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_filter_type(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetInterlaceType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int SetInterlaceType
    (png_byte toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetInterlaceType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetInterlaceType() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_interlace_type(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetCompressionType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int SetCompressionType
    (png_byte toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetCompressionType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetCompressionType() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        int value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_compression_type(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetImageRowBytes
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 SetImageRowBytes
    (png_uint_32 toValue) 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetImageRowBytes
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 GetImageRowBytes() const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) && 
            (structAttached = m_pngStruct.Attached()))
            value = png_get_rowbytes(structAttached, attached);
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    
    /**
     **********************************************************************
     * Function: ImageRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual png_bytep* ImageRow
    (png_int_32& imageRows, png_int_32& rowBytes) const 
#if defined(CPNGINFO_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) 
        png_bytep* imageRow = (m_imageRow);
        imageRows = (m_imageRows);
        rowBytes = (GetImageRowBytes());
#else /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        png_bytep* imageRow = 0;
        imageRows = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CPNGINFO_MEMBER_FUNCS_IMPLEMENT) */
        return imageRow;
    }
#endif /* defined(CPNGINFO_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNGINFO_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: SetImageRowsPerRead
     *
     *   Author: $author$
     *     Date: 1/14/2010
     **********************************************************************
     */
    virtual png_int_32 SetImageRowsPerRead
    (png_int_32 toValue) 
    {
        png_int_32 value = (m_imageRowsPerRead = toValue);
        return value;
    }
    /**
     **********************************************************************
     * Function: GetImageRowsPerRead
     *
     *   Author: $author$
     *     Date: 1/14/2010
     **********************************************************************
     */
    virtual png_int_32 GetImageRowsPerRead() const 
    {
        png_int_32 value = (m_imageRowsPerRead);
        return value;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINFO_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFO_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFO_HXX) || defined(CPNGINFO_MEMBERS_ONLY) */

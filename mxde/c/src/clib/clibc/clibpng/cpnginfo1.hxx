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
#include "cpnginfoattached.hxx"
#include "cpngstructinterface.hxx"
#include "ccreated.hxx"

class c_INTERFACE_CLASS cPngInfoInterface;
/**
 **********************************************************************
 * Typedef: cPngInfoInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cPngInfoInterface, cPngInfoAttachedInterface>
cPngInfoInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInfoInterface
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInfoInterface
: virtual public cPngInfoInterfaceImplements
{
public:
    typedef cPngInfoInterfaceImplements cImplements;
    typedef cPngInfoInterface cDerives;
};
class c_EXPORT_CLASS cPngInfoImplement;
/**
 **********************************************************************
 * Typedef: cPngInfoImplementImplements
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cPngInfoImplement, cPngInfoInterface>
cPngInfoImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInfoImplement
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfoImplement
: virtual public cPngInfoImplementImplements
{
public:
    typedef cPngInfoImplementImplements cImplements;
    typedef cPngInfoImplement cDerives;
};
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
      m_imageRows(0)
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

        if ((error = FreedImageRows(onlyCreated)))
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

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 Read() 
    {
        png_int_32 count = 0;
        png_structp structAttached;
        tAttachedTo attached;
        png_int_32 rows, rowBytes, bytesRead;
        int bitDepth, colorType, colorChannels;
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

        /* Allocate the memory to hold the image rows. 
         */
        if (!(m_imageRow = AllocateImageRows(error, rowBytes, rows)))
            return -error;
        else
        m_imageRows = rows;

        bytesRead = m_pngStruct.SetBytesRead(count);

        /* Read the entire image in one go 
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

        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 Write() 
    {
        png_int_32 count = 0;
        return count;
    }

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
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetImageWidth
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 GetImageWidth() const 
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) || 
            (structAttached = m_pngStruct.Attached()))
            value = png_get_image_width(structAttached, attached);
        return value;
    }

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
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetImageHeight
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 GetImageHeight() const 
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_image_height(structAttached, attached);
        return value;
    }

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
    {
        int value = 0;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetBitDepth
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetBitDepth() const 
    {
        int value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_bit_depth(structAttached, attached);
        return value;
    }

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
    {
        int value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetColorType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetColorType() const 
    {
        int value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_color_type(structAttached, attached);
        return value;
    }

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
    {
        int value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetColorChannels
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetColorChannels() const 
    {
        int value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_channels(structAttached, attached);
        return value;
    }

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
    {
        int value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetFilterType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetFilterType() const 
    {
        int value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_filter_type(structAttached, attached);
        return value;
    }

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
    {
        int value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetInterlaceType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetInterlaceType() const 
    {
        int value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_interlace_type(structAttached, attached);
        return value;
    }

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
    {
        int value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetCompressionType
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual int GetCompressionType() const 
    {
        int value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) &&
            (structAttached = m_pngStruct.Attached()))
            value = png_get_compression_type(structAttached, attached);
        return value;
    }

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
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetImageRowBytes
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual png_int_32 GetImageRowBytes() const 
    {
        png_int_32 value = -e_ERROR_NOT_ATTACHED;
        png_structp structAttached;
        tAttachedTo attached;

        if ((attached = Attached()) && 
            (structAttached = m_pngStruct.Attached()))
            value = png_get_rowbytes(structAttached, attached);
        return value;
    }
};
#else /* !defined(CPNGINFO_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFO_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFO_HXX) || defined(CPNGINFO_MEMBERS_ONLY) */

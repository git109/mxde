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
 *   File: ctiff.hxx
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
#if !defined(_CTIFF_HXX) || defined(CTIFF_MEMBERS_ONLY)
#if !defined(_CTIFF_HXX) && !defined(CTIFF_MEMBERS_ONLY)
#define _CTIFF_HXX
#endif /* !defined(_CTIFF_HXX) && !defined(CTIFF_MEMBERS_ONLY) */

#if !defined(CTIFF_MEMBERS_ONLY)
#include "ctiffinterface.hxx"
#include "ctiffopened.hxx"
#include "ctiffattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cTIFFExtend
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cTIFFOpened
cTIFFExtend;
/**
 **********************************************************************
 *  Class: cTIFF
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTIFF
: virtual public cTIFFImplement,
  public cTIFFExtend
{
public:
    typedef cTIFFImplement cImplements;
    typedef cTIFFExtend cExtends;
    
    TIFFErrorHandler m_oldTIFFWarning;
    TIFFErrorHandler m_oldTIFFError;
    TIFFErrorHandlerExt m_oldTIFFWarningExt;
    TIFFErrorHandlerExt m_oldTIFFErrorExt;
    
    /**
     **********************************************************************
     *  Constructor: cTIFF
     *
     *       Author: $author$
     *         Date: 12/24/2009
     **********************************************************************
     */
    cTIFF
    (TIFF* attached=0,
     bool isOpen=false)
    : cExtends(attached,isOpen)
    {
        m_oldTIFFWarning = TIFFSetWarningHandler(TIFFWarning);
        m_oldTIFFError = TIFFSetErrorHandler(TIFFError);
        m_oldTIFFWarningExt = TIFFSetWarningHandlerExt(TIFFWarningExt);
        m_oldTIFFErrorExt = TIFFSetErrorHandlerExt(TIFFErrorExt);
    }
    /**
     **********************************************************************
     *  Destructor: ~cTIFF
     *
     *      Author: $author$
     *        Date: 12/24/2009
     **********************************************************************
     */
    virtual ~cTIFF()
    {
        TIFFSetWarningHandler(m_oldTIFFWarning);
        TIFFSetErrorHandler(m_oldTIFFError);
        TIFFSetWarningHandlerExt(m_oldTIFFWarningExt);
        TIFFSetErrorHandlerExt(m_oldTIFFErrorExt);
    }
#else /* !defined(CTIFF_MEMBERS_ONLY) */
#endif /* !defined(CTIFF_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual eError Open
    (const CHAR* fileName,
     const CHAR* fileMode=CPLATFORM_FILE_MODE_READ_BINARY,
     bool onlyClosed=false) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        TIFF* detached;
        
        if (!(error = Closed(onlyClosed))) 
        if ((detached = OpenDetached(error, fileName, fileMode)))
        {
            Attach(detached);
            SetIsOpen();
        }
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpen=false) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        TIFF* detached;
        
        if ((detached = Detach()))
            error = CloseDetached(detached);
        else
        if (!onlyOpen)
            error = e_ERROR_NONE;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: ReadEncodedStrip
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    virtual TLENGTH ReadEncodedStrip
    (UINT strip, BYTE* byte, TSIZE bytes) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = -e_ERROR_NOT_ATTACHED;
        TIFF* tiff;
        if ((tiff = Attached()))
            count = TIFFReadEncodedStrip(tiff, strip, byte, bytes);
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ComputeStrip
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    virtual TLENGTH ComputeStrip
    (UINT row, UINT sample) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = -e_ERROR_NOT_ATTACHED;
        TIFF* tiff;
        if ((tiff = Attached()))
            count = TIFFComputeStrip(tiff, row, sample);
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: StripSize
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    virtual TLENGTH StripSize() 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = -e_ERROR_NOT_ATTACHED;
        TIFF* tiff;
        if ((tiff = Attached()))
            count = TIFFStripSize(tiff);
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetColorMapSpanned
     *
     *   Author: $author$
     *     Date: 1/7/2010
     **********************************************************************
     */
    virtual TLENGTH GetColorMapSpanned
    (TSIZE& bitsPerColor,
     UINT16*& red,
     UINT16*& green,
     UINT16*& blue,
     TSIZE bitsPerSample) const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH color;
        UINT16 r,g,b;
        BYTE rh,rl;
        BYTE gh,gl;
        BYTE bh,bl;
        if (0 < (count = GetColorMap
            (red, green, blue, bitsPerSample)))
        {
            bitsPerColor = 8;
            for (color=0; color<count; color++)
            {
                r = red[color];
                g = green[color];
                b = blue[color];
                
                rh = r>>8;
                rl = r&255;
                
                gh = g>>8;
                gl = g&255;
                
                bh = b>>8;
                bl = b&255;
                    
                if ((((r)>255) && (rh != rl)) 
                    || (((g)>255) && (gh != gl))
                    || (((b)>255)) && (bh != bl))
                {
                    bitsPerColor = 16;
                    break;
                }
            }
        }
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetColorMap
     *
     *   Author: $author$
     *     Date: 1/7/2010
     **********************************************************************
     */
    virtual TLENGTH GetColorMap
    (UINT16*& red,
     UINT16*& green,
     UINT16*& blue,
     TSIZE bitsPerSample) const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField
             (tiff, TIFFTAG_COLORMAP, &red, &green, &blue)))
            count = (1 << bitsPerSample);
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OpenDetached
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TIFF* OpenDetached
    (eError& error,
     const CHAR* fileName,
     const CHAR* fileMode=CPLATFORM_FILE_MODE_READ_BINARY) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TIFF* tiff = 0;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_FAILED;
        if ((tiff = TIFFOpen(fileName, fileMode)))
            error = e_ERROR_NONE;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return tiff;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CloseDetached
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual eError CloseDetached
    (TIFF* tiff) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        if ((tiff))
        {
            TIFFClose(tiff);
            error = e_ERROR_NONE;
        }
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetImageWidth
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetImageWidth
    (TSIZE toWidth) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH imageWidth = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return imageWidth;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ImageWidth
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH ImageWidth() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH imageWidth = -e_ERROR_NOT_ATTACHED;
        UINT32 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &tiffValue)))
            imageWidth = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH imageWidth = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return imageWidth;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetImageLength
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetImageLength
    (TSIZE toLength) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH imageLength = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return imageLength;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ImageLength
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH ImageLength() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH imageLength = -e_ERROR_NOT_ATTACHED;
        UINT32 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &tiffValue)))
            imageLength = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH imageLength = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return imageLength;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetScanlineSize
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetScanlineSize
    (TSIZE toSize) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH scanlineSize = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return scanlineSize;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ScanlineSize
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH ScanlineSize() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH scanlineSize = -e_ERROR_NOT_ATTACHED;
        TIFF* tiff;
        if ((tiff = Attached()))
            scanlineSize = (TLENGTH)TIFFScanlineSize(tiff);
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH scanlineSize = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return scanlineSize;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetSamplesPerPixel
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetSamplesPerPixel
    (TSIZE toValue) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SamplesPerPixel
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SamplesPerPixel() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = -e_ERROR_NOT_ATTACHED;
        UINT16 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_SAMPLESPERPIXEL, &tiffValue)))
            value = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetBitsPerSample
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetBitsPerSample
    (TSIZE toBitsPerSample) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH bitsPerSample = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return bitsPerSample;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BitsPerSample
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH BitsPerSample() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH bitsPerSample = -e_ERROR_NOT_ATTACHED;
        UINT16 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_BITSPERSAMPLE, &tiffValue)))
            bitsPerSample = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH bitsPerSample = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return bitsPerSample;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetRowsPerStrip
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetRowsPerStrip
    (TSIZE toRowsPerStrip) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH rowsPerStrip = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return rowsPerStrip;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RowsPerStrip
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH RowsPerStrip() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH rowsPerStrip = -e_ERROR_NOT_ATTACHED;
        UINT32 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_ROWSPERSTRIP, &tiffValue)))
            rowsPerStrip = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH rowsPerStrip = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return rowsPerStrip;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetPhotometricInterpretation
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetPhotometricInterpretation
    (TSIZE toValue) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: PhotometricInterpretation
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH PhotometricInterpretation() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = -e_ERROR_NOT_ATTACHED;
        UINT16 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_PHOTOMETRIC, &tiffValue)))
            value = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetCompression
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH SetCompression
    (TSIZE toValue) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Compression
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TLENGTH Compression() const 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = -e_ERROR_NOT_ATTACHED;
        UINT16 tiffValue;
        TIFF* tiff;
        if ((tiff = Attached()))
        if ((TIFFGetField(tiff, TIFFTAG_COMPRESSION, &tiffValue)))
            value = tiffValue;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual eError DeleteInstance() 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        delete this;
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    static cTIFFInterface* CreateInstance
    (eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    static eError DestroyInstance
    (cTIFFInterface& tiff);
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnTIFFWarning
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual void OnTIFFWarning
    (const char*, const char*, va_list) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFWarningExt
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual void OnTIFFWarningExt
    (thandle_t, const char*, const char*, va_list) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFError
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual void OnTIFFError
    (const char*, const char*, va_list) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFErrorExt
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual void OnTIFFErrorExt
    (thandle_t, const char*, const char*, va_list) 
#if defined(CTIFF_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CTIFF_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTIFF_MEMBERS_ONLY)

#if !defined(CTIFF_MEMBER_FUNCS_INTERFACE)
#if !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: TIFFWarning
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    static void TIFFWarning
    (const char*, const char*, va_list)
    {
    }
    /**
     **********************************************************************
     * Function: TIFFWarningExt
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    static void TIFFWarningExt
    (thandle_t, const char*, const char*, va_list)
    {
    }
    /**
     **********************************************************************
     * Function: TIFFError
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    static void TIFFError
    (const char*, const char*, va_list)
    {
    }
    /**
     **********************************************************************
     * Function: TIFFErrorExt
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    static void TIFFErrorExt
    (thandle_t, const char*, const char*, va_list)
    {
    }
#endif /* !defined(CTIFF_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFF_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFF_MEMBERS_ONLY) */
#endif /* !defined(CTIFF_MEMBERS_ONLY) */

#endif /* !defined(_CTIFF_HXX) || defined(CTIFF_MEMBERS_ONLY) */

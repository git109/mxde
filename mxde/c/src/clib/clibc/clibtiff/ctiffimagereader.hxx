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
 *   File: ctiffimagereader.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CTIFFIMAGEREADER_HXX) || defined(CTIFFIMAGEREADER_MEMBERS_ONLY)
#if !defined(_CTIFFIMAGEREADER_HXX) && !defined(CTIFFIMAGEREADER_MEMBERS_ONLY)
#define _CTIFFIMAGEREADER_HXX
#endif /* !defined(_CTIFFIMAGEREADER_HXX) && !defined(CTIFFIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CTIFFIMAGEREADER_MEMBERS_ONLY)
#include "cimagereader.hxx"
#include "ctiffreader.hxx"
#include "cchars.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cTIFFImageReaderExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cImageReader
cTIFFImageReaderExtend;
/**
 **********************************************************************
 *  Class: cTIFFImageReader
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cTIFFImageReader
: virtual public cTIFFReaderEventsImplement,
  public cTIFFImageReaderExtend
{
public:
    typedef cTIFFImageReaderExtend cExtends;
    
    cTIFFReader m_tiffReader;
    eImagePixelValueInterpretation m_pixelValueInterpretation;
    TSIZE m_imagePlanes;
    TSIZE m_imagePlane;
    /**
     **********************************************************************
     *  Constructor: cTIFFImageReader
     *
     *       Author: $author$
     *         Date: 1/13/2010
     **********************************************************************
     */
    cTIFFImageReader
    (cImageReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_tiffReader((cTIFFReaderEventsInterface*)(this))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cTIFFImageReader
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cTIFFImageReader()
    {
    }
#else /* !defined(CTIFFIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CTIFFIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CTIFFIMAGEREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
    {
        TLENGTH count = m_tiffReader.Read(fileName);
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
    {
        TLENGTH count = m_tiffReader.Read(fileName);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnTIFFPixel
    (cImagePixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
     {
        eError error = OnImagePixel
        (pixel, pixelByte, pixelBytes, 
         imageCol, imageRow, m_imagePlane,
         m_imagePlanes, imageLength, imageWidth,
         samplesPerPixel, bitsPerSample, m_pixelValueInterpretation);
        return error;
     }
    /**
     **********************************************************************
     * Function: OnBeginTIFFRow
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnBeginTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = OnBeginImageRow
        (rowByte, rowBytes, imageRow, m_imagePlane,
         m_imagePlanes, imageLength, imageWidth,
         samplesPerPixel, bitsPerSample, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndTIFFRow
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnEndTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = OnEndImageRow
        (rowByte, rowBytes, imageRow, m_imagePlane,
         m_imagePlanes, imageLength, imageWidth,
         samplesPerPixel, bitsPerSample, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginTIFFImage
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnBeginTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = OnBeginImage
        (m_imagePlanes, imageLength, imageWidth,
         samplesPerPixel, bitsPerSample, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndTIFFImage
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnEndTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = OnEndImage
        (m_imagePlanes, imageLength, imageWidth,
         samplesPerPixel, bitsPerSample, m_pixelValueInterpretation);
        return error;
    }
    
    /**
     **********************************************************************
     *  Function: AcceptExtension
     *
     *    Author: $author$
     *      Date: 11/9/2010
     **********************************************************************
     */
    virtual eError AcceptExtension
    (const WCHAR* fileExtension)
    {
        static const WCHAR* accepted = L"tif";
        eError error = e_ERROR_NOT_IMPLEMENTED;
        if (fileExtension)
        if (!(cWChars::CompareCaseless(fileExtension, accepted)))
            error = e_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CTIFFIMAGEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFIMAGEREADER_HXX) || defined(CTIFFIMAGEREADER_MEMBERS_ONLY) */

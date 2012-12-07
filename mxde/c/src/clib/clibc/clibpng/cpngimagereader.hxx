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
 *   File: cpngimagereader.hxx
 *
 * Author: $author$
 *   Date: 1/16/2010
 **********************************************************************
 */
#if !defined(_CPNGIMAGEREADER_HXX) || defined(CPNGIMAGEREADER_MEMBERS_ONLY)
#if !defined(_CPNGIMAGEREADER_HXX) && !defined(CPNGIMAGEREADER_MEMBERS_ONLY)
#define _CPNGIMAGEREADER_HXX
#endif /* !defined(_CPNGIMAGEREADER_HXX) && !defined(CPNGIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CPNGIMAGEREADER_MEMBERS_ONLY)
#include "cimagereader.hxx"
#include "cpngreader.hxx"
#include "cchars.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPNGImageReaderExtend
 *
 *  Author: $author$
 *    Date: 1/16/2010
 **********************************************************************
 */
typedef cImageReader
cPNGImageReaderExtend;
/**
 **********************************************************************
 *  Class: cPNGImageReader
 *
 * Author: $author$
 *   Date: 1/16/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cPNGImageReader
: virtual public cPNGReaderEventsImplement,
  public cPNGImageReaderExtend
{
public:
    typedef cPNGReaderEventsImplement cImplements;
    typedef cPNGImageReaderExtend cExtends;
    
    cPNGReader m_pngReader;
    eImagePixelValueInterpretation m_pixelValueInterpretation;
    
    /**
     **********************************************************************
     *  Constructor: cPNGImageReader
     *
     *       Author: $author$
     *         Date: 1/16/2010
     **********************************************************************
     */
    cPNGImageReader
    (cImageReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_pngReader((cPNGReaderEventsInterface*)(this)),
      m_pixelValueInterpretation(e_IMAGEPIXEL_VALUE_INTERPRETATION_RGB)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cPNGImageReader
     *
     *      Author: $author$
     *        Date: 1/16/2010
     **********************************************************************
     */
    virtual ~cPNGImageReader()
    {
    }
#else /* !defined(CPNGIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CPNGIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CPNGIMAGEREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
    {
        TLENGTH count = m_pngReader.Read(fileName);
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
    {
        TLENGTH count = m_pngReader.Read(fileName);
        return count;
    }
    
    /**
     **********************************************************************
     * Function: OnPNGPixel
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGPixel
    (cImagePixelInterface& pixel,
     BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        error = OnImagePixel
        (pixel, colByte, colBytes, col, row, 
         0, 1, height, width, colorChannels, 
         bitDepth, m_pixelValueInterpretation);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnBeginPNGRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnBeginPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        error = OnBeginImageRow
        (rowByte, rowBytes, row, 
         0, 1, height, width, colorChannels, 
         bitDepth, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndPNGRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnEndPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        error = OnEndImageRow
        (rowByte, rowBytes, row, 
         0, 1, height, width, colorChannels, 
         bitDepth, m_pixelValueInterpretation);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnBeginPNGImage
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError OnBeginPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error;
        
        switch(colorType)
        {
        case PNG_COLOR_TYPE_RGB:
            m_pixelValueInterpretation = e_IMAGEPIXEL_VALUE_INTERPRETATION_RGB;
            break;
            
        case PNG_COLOR_TYPE_RGB_ALPHA:
            m_pixelValueInterpretation = e_IMAGEPIXEL_VALUE_INTERPRETATION_RGBA;
            break;
            
        case PNG_COLOR_TYPE_PALETTE:
            m_pixelValueInterpretation = e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE;
            break;
        }
        
        error = OnBeginImage
        (1, height, width, colorChannels, 
         bitDepth, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndPNGImage
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError OnEndPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error;
        error = OnEndImage
        (1, height, width, colorChannels, 
         bitDepth, m_pixelValueInterpretation);
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
        static const WCHAR* accepted = L"png";
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

#else /* !defined(CPNGIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CPNGIMAGEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CPNGIMAGEREADER_HXX) || defined(CPNGIMAGEREADER_MEMBERS_ONLY) */

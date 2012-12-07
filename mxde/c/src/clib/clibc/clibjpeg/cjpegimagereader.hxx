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
 *   File: cjpegimagereader.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#if !defined(_CJPEGIMAGEREADER_HXX) || defined(CJPEGIMAGEREADER_MEMBERS_ONLY)
#if !defined(_CJPEGIMAGEREADER_HXX) && !defined(CJPEGIMAGEREADER_MEMBERS_ONLY)
#define _CJPEGIMAGEREADER_HXX
#endif /* !defined(_CJPEGIMAGEREADER_HXX) && !defined(CJPEGIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CJPEGIMAGEREADER_MEMBERS_ONLY)
#include "cjpegreaderevents.hxx"
#include "cjpegreader.hxx"
#include "cimagereader.hxx"
#include "cimagepixel.hxx"
#include "cchars.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cJPEGImageReaderImplement
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cJPEGReaderEventsImplement
cJPEGImageReaderImplement;
/**
 **********************************************************************
 * Typedef: cJPEGImageReaderExtend
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cImageReader
cJPEGImageReaderExtend;
/**
 **********************************************************************
 *  Class: cJPEGImageReader
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cJPEGImageReader
: virtual public cJPEGImageReaderImplement,
  public cJPEGImageReaderExtend
{
public:
    typedef cJPEGImageReaderImplement cImplements;
    typedef cJPEGImageReaderExtend cExtends;
    typedef cJPEGImageReader cDerives;
    
    typedef eError (cDerives::*MOnJPEGSampleCol)
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap);
     
    cJPEGReader m_jpegReader;
    eImagePixelValueInterpretation m_imagePixelValueInterpretation;
    MOnJPEGSampleCol m_onJPEGSampleCol;
    
    /**
     **********************************************************************
     *  Constructor: cJPEGImageReader
     *
     *       Author: $author$
     *         Date: 11/13/2010
     **********************************************************************
     */
    cJPEGImageReader
    (cImageReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_jpegReader((cJPEGReaderEventsInterface*)(this)),
      m_imagePixelValueInterpretation(e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE),
      m_onJPEGSampleCol(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cJPEGImageReader
     *
     *      Author: $author$
     *        Date: 11/13/2010
     **********************************************************************
     */
    virtual ~cJPEGImageReader()
    {
    }
#else /* !defined(CJPEGIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CJPEGIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CJPEGIMAGEREADER_MEMBERS_ONLY)
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
        TLENGTH count = m_jpegReader.Read(fileName);
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
        TLENGTH count = m_jpegReader.Read(fileName);
        return count;
    }

    /**
     **********************************************************************
     * Function: OnColorMapJPEGSampleCol
     *
     *   Author: $author$
     *     Date: 11/16/2010
     **********************************************************************
     */
    eError OnColorMapJPEGSampleCol
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRGBJPEGSampleCol
     *
     *   Author: $author$
     *     Date: 11/16/2010
     **********************************************************************
     */
    eError OnRGBJPEGSampleCol
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        if (3 == samplesSize)
        {
            BYTE* byte = (BYTE*)(samples);
            cImagePixel pixel(byte[0], byte[1], byte[2]);
            error = OnImagePixel
            (pixel, byte, samplesSize, samplesCol, samplesRow, 
             0, 1, outputHeight, outputWidth, 3, 8, 
             m_imagePixelValueInterpretation);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnJPEGSampleCol
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnJPEGSampleCol
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        if ((m_onJPEGSampleCol))
            error = (this->*m_onJPEGSampleCol)
            (samples, samplesSize, samplesRow, samplesCol, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginJPEGSampleRow
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnBeginJPEGSampleRow
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnBeginImageRow
        ((BYTE*)(samples), samplesSize, samplesRow, 0, 1, 
         outputHeight, outputWidth, outputComponents, 0, 
         m_imagePixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndJPEGSampleRow
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnEndJPEGSampleRow
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnEndImageRow
        ((BYTE*)(samples), samplesSize, samplesRow, 0, 1, 
         outputHeight, outputWidth, outputComponents, 0, 
         m_imagePixelValueInterpretation);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginJPEGImage
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnBeginJPEGImage
    (JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        switch (outColorSpace)
        {
        case JCS_RGB:
            if (3 != outColorComponents)
                error = e_ERROR_FAILED;
            else
            if (colorMap)
            {
                m_imagePixelValueInterpretation 
                = e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE;
                m_onJPEGSampleCol = &cDerives::OnColorMapJPEGSampleCol;
            }
            else
            if (3 != outputComponents)
                error = e_ERROR_FAILED;
            else
            {
                m_imagePixelValueInterpretation 
                = e_IMAGEPIXEL_VALUE_INTERPRETATION_RGB;
                m_onJPEGSampleCol = &cDerives::OnRGBJPEGSampleCol;
            }
            break;
            
        default:
            error = e_ERROR_NOT_IMPLEMENTED;
        }
        if (!(error))
            error = OnBeginImage
            (1, outputHeight, outputWidth, 
             outputComponents, 0, m_imagePixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndJPEGImage
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnEndJPEGImage
    (JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnEndImage
        (1, outputHeight, outputWidth, 
         outputComponents, 0, m_imagePixelValueInterpretation);
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
        static const WCHAR* accepted = L"jpg";
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

#else /* !defined(CJPEGIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CJPEGIMAGEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGIMAGEREADER_HXX) || defined(CJPEGIMAGEREADER_MEMBERS_ONLY) */

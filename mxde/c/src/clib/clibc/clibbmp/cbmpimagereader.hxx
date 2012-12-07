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
 *   File: cbmpimagereader.hxx
 *
 * Author: $author$
 *   Date: 1/20/2010
 **********************************************************************
 */
#if !defined(_CBMPIMAGEREADER_HXX) || defined(CBMPIMAGEREADER_MEMBERS_ONLY)
#if !defined(_CBMPIMAGEREADER_HXX) && !defined(CBMPIMAGEREADER_MEMBERS_ONLY)
#define _CBMPIMAGEREADER_HXX
#endif /* !defined(_CBMPIMAGEREADER_HXX) && !defined(CBMPIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CBMPIMAGEREADER_MEMBERS_ONLY)
#include "cimagereader.hxx"
#include "cbmpreader.hxx"
#include "crgbquadimagepixel.hxx"
#include "crgbtripleimagepixel.hxx"
#include "cchars.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cBMPImageReaderExtend
 *
 *  Author: $author$
 *    Date: 1/20/2010
 **********************************************************************
 */
typedef cImageReader
cBMPImageReaderExtend;
/**
 **********************************************************************
 *  Class: cBMPImageReader
 *
 * Author: $author$
 *   Date: 1/20/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cBMPImageReader
: virtual public cBMPReaderEventsImplement,
  public cBMPImageReaderExtend
{
public:
    typedef cBMPReaderEventsImplement cImplements;
    typedef cBMPImageReaderExtend cExtends;
    
    cBMPReader m_bmpReader;
    TSIZE m_samplesPerPixel;
    eImagePixelValueInterpretation m_pixelValueInterpretation;
    
    /**
     **********************************************************************
     *  Constructor: cBMPImageReader
     *
     *       Author: $author$
     *         Date: 1/20/2010
     **********************************************************************
     */
    cBMPImageReader
    (cImageReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_bmpReader((cBMPReaderEventsInterface*)(this)),
      m_samplesPerPixel(0),
      m_pixelValueInterpretation(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cBMPImageReader
     *
     *      Author: $author$
     *        Date: 1/20/2010
     **********************************************************************
     */
    virtual ~cBMPImageReader()
    {
    }
#else /* !defined(CBMPIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CBMPIMAGEREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
#if defined(CBMPIMAGEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CBMPIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) 
        count = m_bmpReader.Read(fileName);
#else /* !defined(CBMPIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBMPIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CBMPIMAGEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CBMPIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) 
        count = m_bmpReader.Read(fileName);
#else /* !defined(CBMPIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBMPIMAGEREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBMPIMAGEREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnBMPPixel
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPPixel
    (RGBQUAD& rgb,
     BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        cRGBQUADImagePixel pixel(rgb);
        eError error = OnImagePixel
        (pixel, &colByte, colBytes, col, rows-row-1, 
         plane, planes, rows, cols, m_samplesPerPixel, 
         bits, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBMPPixel
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPPixel
    (RGBTRIPLE& rgb, 
     BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        cRGBTRIPLEImagePixel pixel(rgb);
        eError error = OnImagePixel
        (pixel, &colByte, colBytes, col, rows-row-1, 
         plane, planes, rows, cols, m_samplesPerPixel, 
         bits, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginBMPRow
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBeginBMPRow
    (BYTE& rowByte, TSIZE rowBytes, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = OnBeginImageRow
        (&rowByte, rowBytes, rows-row-1, 
         plane, planes, rows, cols, m_samplesPerPixel, 
         bits, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBMPRow
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnEndBMPRow
    (BYTE& rowByte, TSIZE rowBytes, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = OnEndImageRow
        (&rowByte, rowBytes, rows-row-1, plane,
         planes, rows, cols, m_samplesPerPixel, 
         bits, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginBMPImage
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBeginBMPImage
    (TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = OnBeginImage
        (planes, rows, cols, m_samplesPerPixel, 
         bits, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBMPImage
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnEndBMPImage
    (TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = OnEndImage
        (planes, rows, cols, m_samplesPerPixel, 
         bits, m_pixelValueInterpretation);
        return error;
    }
    /**
     **********************************************************************
     *  Function: AcceptExtension
     *
     *    Author: $author$
     *      Date: 11/18/2010
     **********************************************************************
     */
    virtual eError AcceptExtension
    (const WCHAR* fileExtension)
    {
        static const WCHAR* accepted = L"bmp";
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

#else /* !defined(CBMPIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CBMPIMAGEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CBMPIMAGEREADER_HXX) || defined(CBMPIMAGEREADER_MEMBERS_ONLY) */

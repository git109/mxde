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
 *   File: cgiffileimagereader.hxx
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
#if !defined(_CGIFFILEIMAGEREADER_HXX) || defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY)
#if !defined(_CGIFFILEIMAGEREADER_HXX) && !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY)
#define _CGIFFILEIMAGEREADER_HXX
#endif /* !defined(_CGIFFILEIMAGEREADER_HXX) && !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY)
#include "cgiffilereader.hxx"
#include "cimagereader.hxx"
#include "cimagepixel.hxx"
#include "cchars.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cGifFileImageReaderImplement
 *
 *  Author: $author$
 *    Date: 11/11/2010
 **********************************************************************
 */
typedef cGifFileReaderEventsImplement
cGifFileImageReaderImplement;
/**
 **********************************************************************
 * Typedef: cGifFileImageReaderExtend
 *
 *  Author: $author$
 *    Date: 11/11/2010
 **********************************************************************
 */
typedef cImageReader
cGifFileImageReaderExtend;
/**
 **********************************************************************
 *  Class: cGifFileImageReader
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifFileImageReader
: virtual public cGifFileImageReaderImplement,
  public cGifFileImageReaderExtend
{
public:
    typedef cGifFileImageReaderImplement cImplements;
    typedef cGifFileImageReaderExtend cExtends;
    
    cGifFileReader m_gifReader;
    
    /**
     **********************************************************************
     *  Constructor: cGifFileImageReader
     *
     *       Author: $author$
     *         Date: 11/11/2010
     **********************************************************************
     */
    cGifFileImageReader
    (cImageReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_gifReader((cGifFileReaderEventsInterface*)(this))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cGifFileImageReader
     *
     *      Author: $author$
     *        Date: 11/11/2010
     **********************************************************************
     */
    virtual ~cGifFileImageReader()
    {
    }
#else /* !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/11/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
#if defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_IMPLEMENT)
        count = -m_gifReader.Read(fileName);
#else /* !defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/11/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_IMPLEMENT)
        count = -m_gifReader.Read(fileName);
#else /* !defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CGIFFILEIMAGEREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnGifPixel
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifPixel
    (cImagePixelInterface& imagePixel,
     GifColorType& color,GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnImagePixel
        (imagePixel, (BYTE*)(&pixel), sizeof(pixel), 
         pixelColumn, pixelLine, 
         0, 1, height, width, 3, 8, 
         e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnGifPixelColor
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifPixelColor
    (GifColorType& color,GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        eError error = e_ERROR_NONE;
        cImagePixel imagePixel(color.Red, color.Green, color.Blue);
        error = OnGifPixel
        (imagePixel, color, pixel, pixelColumn, pixelLine,
         height, width, colors, interlaceType,
         backgroundPixel, colorMap);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginGifLine
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnBeginImageRow
        ((BYTE*)(pixels), pixelsLength*sizeof(GifPixelType), 
         pixelsLine, 0, 1, height, width, 1, 8, 
         e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndGifLine
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnEndImageRow
        ((BYTE*)(pixels), pixelsLength*sizeof(GifPixelType), 
         pixelsLine, 0, 1, height, width, 1, 8, 
         e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginGifImage
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnBeginImage
        (1, height, width, 3, 8, 
         e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndGifImage
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        eError error = e_ERROR_NONE;
        error = OnEndImage
        (1, height, width, 3, 8, 
         e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE);
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
        static const WCHAR* accepted = L"gif";
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

#else /* !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILEIMAGEREADER_HXX) || defined(CGIFFILEIMAGEREADER_MEMBERS_ONLY) */

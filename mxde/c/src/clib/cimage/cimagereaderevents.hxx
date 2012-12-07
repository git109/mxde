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
 *   File: cimagereaderevents.hxx
 *
 * Author: $author$
 *   Date: 1/12/2010
 **********************************************************************
 */
#if !defined(_CIMAGEREADEREVENTS_HXX) || defined(CIMAGEREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CIMAGEREADEREVENTS_HXX) && !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY)
#define _CIMAGEREADEREVENTS_HXX
#endif /* !defined(_CIMAGEREADEREVENTS_HXX) && !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY)
#include "cimagereadereventsinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cImageReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 1/12/2010
 **********************************************************************
 */
typedef cInstanceBase
cImageReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cImageReaderEvents
 *
 * Author: $author$
 *   Date: 1/12/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cImageReaderEvents
: virtual public cImageReaderEventsImplement,
  public cImageReaderEventsExtend
{
public:
    typedef cImageReaderEventsImplement cImplements;
    typedef cImageReaderEventsExtend cExtends;
    
    cImageReaderEventsInterface* m_delegated;
    
    /**
     **********************************************************************
     *  Constructor: cImageReaderEvents
     *
     *       Author: $author$
     *         Date: 1/12/2010
     **********************************************************************
     */
    cImageReaderEvents
    (cImageReaderEventsInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cImageReaderEvents
     *
     *      Author: $author$
     *        Date: 1/12/2010
     **********************************************************************
     */
    virtual ~cImageReaderEvents()
    {
    }
#else /* !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnImagePixel
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnImagePixel
    (cImagePixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnImagePixel
            (pixel, pixelByte, pixelBytes, imageCol, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginImageCol
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnBeginImageCol
    (BYTE* colByte, TSIZE colBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginImageCol
            (colByte, colBytes, imageCol, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndImageCol
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnEndImageCol
    (BYTE* colByte, TSIZE colBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndImageCol
            (colByte, colBytes, imageCol, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnImageCol
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnImageCol
    (BYTE* colByte, TSIZE colBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnImageCol
            (colByte, colBytes, imageCol, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginImageRow
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnBeginImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginImageRow
            (rowByte, rowBytes, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndImageRow
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnEndImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndImageRow
            (rowByte, rowBytes, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnImageRow
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnImageRow
            (rowByte, rowBytes, imageRow, 
             imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginImagePlane
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnBeginImagePlane
    (TSIZE imagePlane, TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginImagePlane
            (imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndImagePlane
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnEndImagePlane
    (TSIZE imagePlane, TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndImagePlane
            (imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnImagePlane
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnImagePlane
    (TSIZE imagePlane, TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnImagePlane
            (imagePlane, imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginImage
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnBeginImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginImage
            (imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndImage
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnEndImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndImage
            (imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnImage
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual eError OnImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cImageReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnImage
            (imagePlanes, imageHeight, imageWidth,
             valuesPerPixel, bitsPerValue, pixelValueInterpretation)))
            return error2;
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Delegate
     *
     *   Author: $author$
     *     Date: 11/12/2010
     **********************************************************************
     */
    virtual cImageReaderEventsInterface* Delegate
    (cImageReaderEventsInterface* delegated)
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        m_delegated = delegated;
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        delegated = 0;
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 1/12/2010
     **********************************************************************
     */
    virtual cImageReaderEventsInterface* Delegated
    (cImageReaderEventsInterface* delegated) const 
#if defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        delegated = m_delegated;
#else /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        delegated = 0;
#endif /* !defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEREADEREVENTS_HXX) || defined(CIMAGEREADEREVENTS_MEMBERS_ONLY) */

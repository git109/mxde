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
 *   File: ctiffreaderevents.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CTIFFREADEREVENTS_HXX) || defined(CTIFFREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CTIFFREADEREVENTS_HXX) && !defined(CTIFFREADEREVENTS_MEMBERS_ONLY)
#define _CTIFFREADEREVENTS_HXX
#endif /* !defined(_CTIFFREADEREVENTS_HXX) && !defined(CTIFFREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CTIFFREADEREVENTS_MEMBERS_ONLY)
#include "ctiffreadereventsinterface.hxx"
#include "cimagepixelinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cTIFFReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cInstanceBase
cTIFFReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cTIFFReaderEvents
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTIFFReaderEvents
: virtual public cTIFFReaderEventsImplement,
  public cTIFFReaderEventsExtend
{
public:
    typedef cTIFFReaderEventsImplement cImplements;
    typedef cTIFFReaderEventsExtend cExtends;
    
    cTIFFReaderEventsInterface* m_delegated;
    
    /**
     **********************************************************************
     *  Constructor: cTIFFReaderEvents
     *
     *       Author: $author$
     *         Date: 12/30/2009
     **********************************************************************
     */
    cTIFFReaderEvents
    (cTIFFReaderEventsInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cTIFFReaderEvents
     *
     *      Author: $author$
     *        Date: 12/30/2009
     **********************************************************************
     */
    virtual ~cTIFFReaderEvents()
    {
    }
#else /* !defined(CTIFFREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual eError OnTIFFPixel
    (cImagePixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnTIFFPixel
            (pixel, pixelByte, pixelBytes, 
             imageRow, imageCol,
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginTIFFPixel
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnBeginTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnBeginTIFFPixel
            (pixelByte, pixelBytes, 
             imageRow, imageCol,
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndTIFFPixel
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnEndTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnEndTIFFPixel
            (pixelByte, pixelBytes, 
             imageRow, imageCol,
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFPixel
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnTIFFPixel
            (pixelByte, pixelBytes, 
             imageRow, imageCol,
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginTIFFRow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnBeginTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnBeginTIFFRow
            (rowByte, rowBytes, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndTIFFRow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnEndTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnEndTIFFRow
            (rowByte, rowBytes, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFRow
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnTIFFRow
            (rowByte, rowBytes, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginTIFFStrip
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnBeginTIFFStrip
    (BYTE* stripByte, TSIZE stripBytes,
     TSIZE stripRows, TSIZE strip,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnBeginTIFFStrip
            (stripByte, stripBytes,
             stripRows, strip, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndTIFFStrip
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnEndTIFFStrip
    (BYTE* stripByte, TSIZE stripBytes,
     TSIZE stripRows, TSIZE strip,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnEndTIFFStrip
            (stripByte, stripBytes,
             stripRows, strip, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFStrip
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnTIFFStrip
    (BYTE* stripByte, TSIZE stripBytes,
     TSIZE stripRows, TSIZE strip,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnTIFFStrip
            (stripByte, stripBytes,
             stripRows, strip, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginTIFFImage
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnBeginTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnBeginTIFFImage
            (imageLength, imageWidth, rowsPerStrip, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndTIFFImage
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnEndTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnEndTIFFImage
            (imageLength, imageWidth, rowsPerStrip, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnTIFFImage
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual eError OnTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error2; 
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnTIFFImage
            (imageLength, imageWidth, rowsPerStrip, 
             samplesPerPixel, bitsPerSample,
             photometricInterpretation)))
            return error2;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual cTIFFReaderEventsInterface* Delegated
    (cTIFFReaderEventsInterface* delegated) const 
#if defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        delegated = m_delegated;
#else /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        delegated = 0;
#endif /* !defined(CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTIFFREADEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFREADEREVENTS_HXX) || defined(CTIFFREADEREVENTS_MEMBERS_ONLY) */

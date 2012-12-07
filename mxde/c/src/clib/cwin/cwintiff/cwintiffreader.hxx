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
 *   File: cwintiffreader.hxx
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
#if !defined(_CWINTIFFREADER_HXX) || defined(CWINTIFFREADER_MEMBERS_ONLY)
#if !defined(_CWINTIFFREADER_HXX) && !defined(CWINTIFFREADER_MEMBERS_ONLY)
#define _CWINTIFFREADER_HXX
#endif /* !defined(_CWINTIFFREADER_HXX) && !defined(CWINTIFFREADER_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADER_MEMBERS_ONLY)
#include "cwintiffreaderinterface.hxx"
#include "cwintiffreadereventsinterface.hxx"
#include "cwinrgbtriplepixel.hxx"
#include "ctiffreader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinTIFFReaderExtend
 *
 *  Author: $author$
 *    Date: 12/26/2009
 **********************************************************************
 */
typedef cTIFFReader
cWinTIFFReaderExtend;

/**
 **********************************************************************
 *  Class: cWinTIFFReader
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinTIFFReader
: virtual public cWinTIFFReaderEventsImplement,
  public cWinTIFFReaderExtend
{
public:
    typedef cWinTIFFReaderEventsImplement cImplements;
    typedef cWinTIFFReaderExtend cExtends;
    typedef cWinTIFFReader cDerives;
    
    cWinTIFFReaderEventsInterface* m_delegated;
    
    /**
     **********************************************************************
     *  Constructor: cWinTIFFReader
     *
     *       Author: $author$
     *         Date: 12/26/2009
     **********************************************************************
     */
    cWinTIFFReader
    (cWinTIFFReaderEventsInterface* delegated=0,
     cTIFFInterface* attached=0)
    : cExtends(delegated, attached),
      m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinTIFFReader
     *
     *      Author: $author$
     *        Date: 12/28/2009
     **********************************************************************
     */
    virtual ~cWinTIFFReader()
    {
    }
#else /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADER_MEMBERS_ONLY)
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
    {
        RGBTRIPLE rgb = { pixel.Blue(), pixel.Green(), pixel.Red() };
        cWinRGBTRIPLEPixel rgbPixel(rgb);
        eError error = ((cImplements*)(this))->OnTIFFPixel
        (rgbPixel, pixelByte, pixelBytes, 
         imageRow, imageCol, 
         imageLength, imageWidth, 
         samplesPerPixel, bitsPerSample, 
         photometricInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual cWinTIFFReaderEventsInterface* Delegated
    (cWinTIFFReaderEventsInterface* delegated) const 
    {
        return m_delegated;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */

#endif /* !defined(_CWINTIFFREADER_HXX) || defined(CWINTIFFREADER_MEMBERS_ONLY) */

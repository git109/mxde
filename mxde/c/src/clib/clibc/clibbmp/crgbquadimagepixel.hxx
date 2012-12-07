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
 *   File: crgbquadimagepixel.hxx
 *
 * Author: $author$
 *   Date: 1/20/2010
 **********************************************************************
 */
#if !defined(_CRGBQUADIMAGEPIXEL_HXX) || defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY)
#if !defined(_CRGBQUADIMAGEPIXEL_HXX) && !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY)
#define _CRGBQUADIMAGEPIXEL_HXX
#endif /* !defined(_CRGBQUADIMAGEPIXEL_HXX) && !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY) */

#if !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY)
#include "cimagepixel.hxx"
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cRGBQUADImagePixelExtend
 *
 *  Author: $author$
 *    Date: 1/20/2010
 **********************************************************************
 */
typedef cExportBase
cRGBQUADImagePixelExtend;
/**
 **********************************************************************
 *  Class: cRGBQUADImagePixel
 *
 * Author: $author$
 *   Date: 1/20/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cRGBQUADImagePixel
: virtual public cImagePixelImplement,
  public cRGBQUADImagePixelExtend
{
public:
    typedef cImagePixelImplement cImplements;
    typedef cRGBQUADImagePixelExtend cExtends;
    
    RGBQUAD& m_rgb;
    
    /**
     **********************************************************************
     *  Constructor: cRGBQUADImagePixel
     *
     *       Author: $author$
     *         Date: 1/20/2010
     **********************************************************************
     */
    cRGBQUADImagePixel
    (RGBQUAD& rgb)
    : m_rgb(rgb)
    {
    }
#else /* !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY) */

#if !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Red
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual tColorSample Red() const 
    {
        tColorSample colorSample = m_rgb.rgbRed;
        return colorSample;
    }
    /**
     **********************************************************************
     * Function: Green
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual tColorSample Green() const 
    {
        tColorSample colorSample = m_rgb.rgbGreen;
        return colorSample;
    }
    /**
     **********************************************************************
     * Function: Blue
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual tColorSample Blue() const 
    {
        tColorSample colorSample = m_rgb.rgbBlue;
        return colorSample;
    }
    /**
     **********************************************************************
     * Function: Alpha
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual tColorSample Alpha() const 
    {
        tColorSample colorSample = m_rgb.rgbReserved;
        return colorSample;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CRGBQUADIMAGEPIXEL_HXX) || defined(CRGBQUADIMAGEPIXEL_MEMBERS_ONLY) */

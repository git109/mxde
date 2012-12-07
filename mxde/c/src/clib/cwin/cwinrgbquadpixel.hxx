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
 *   File: cwinrgbquadpixel.hxx
 *
 * Author: $author$
 *   Date: 12/16/2009
 **********************************************************************
 */
#if !defined(_CWINRGBQUADPIXEL_HXX) || defined(CWINRGBQUADPIXEL_MEMBERS_ONLY)
#if !defined(_CWINRGBQUADPIXEL_HXX) && !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY)
#define _CWINRGBQUADPIXEL_HXX
#endif /* !defined(_CWINRGBQUADPIXEL_HXX) && !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY) */

#if !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY)
#include "cwin32bitpixel.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRGBQUADPixel
 *
 * Author: $author$
 *   Date: 12/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRGBQUADPixel
: public cWin32BitPixel
{
public:
    typedef cWin32BitPixel cExtends;
    
    RGBQUAD& m_rgb;
    
    /**
     **********************************************************************
     *  Constructor: cWinRGBQUADPixel
     *
     *       Author: $author$
     *         Date: 12/16/2009
     **********************************************************************
     */
    cWinRGBQUADPixel
    (RGBQUAD& rgb)
    : cExtends(((BYTE*)(&rgb))), 
      m_rgb(rgb)
    {
    }
#else /* !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY) */

#if !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: SetAlpha
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT SetAlpha
    (UINT toValue) 
    {
        UINT value = m_rgb.rgbReserved;
        m_rgb.rgbReserved = toValue;
        return value;
    }
    /**
     **********************************************************************
     * Function: Alpha
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT Alpha() const 
    {
        UINT value = m_rgb.rgbReserved;
        return value;
    }
    /**
     **********************************************************************
     * Function: SetRed
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT SetRed
    (UINT toValue) 
    {
        UINT value = m_rgb.rgbRed;
        m_rgb.rgbRed = toValue;
        return value;
    }
    /**
     **********************************************************************
     * Function: Red
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT Red() const 
    {
        UINT value = m_rgb.rgbRed;
        return value;
    }
    /**
     **********************************************************************
     * Function: SetGreen
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT SetGreen
    (UINT toValue) 
    {
        UINT value = m_rgb.rgbGreen;
        m_rgb.rgbGreen = toValue;
        return value;
    }
    /**
     **********************************************************************
     * Function: Green
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT Green() const 
    {
        UINT value = m_rgb.rgbGreen;
        return value;
    }
    /**
     **********************************************************************
     * Function: SetBlue
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT SetBlue
    (UINT toValue) 
    {
        UINT value = m_rgb.rgbBlue;
        m_rgb.rgbBlue = toValue;
        return value;
    }
    /**
     **********************************************************************
     * Function: Blue
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual UINT Blue() const 
    {
        UINT value = m_rgb.rgbBlue;
        return value;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBQUADPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CWINRGBQUADPIXEL_HXX) || defined(CWINRGBQUADPIXEL_MEMBERS_ONLY) */

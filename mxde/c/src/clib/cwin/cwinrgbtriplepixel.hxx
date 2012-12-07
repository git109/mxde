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
 *   File: cwinrgbtriplepixel.hxx
 *
 * Author: $author$
 *   Date: 12/16/2009
 **********************************************************************
 */
#if !defined(_CWINRGBTRIPLEPIXEL_HXX) || defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY)
#if !defined(_CWINRGBTRIPLEPIXEL_HXX) && !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY)
#define _CWINRGBTRIPLEPIXEL_HXX
#endif /* !defined(_CWINRGBTRIPLEPIXEL_HXX) && !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY) */

#if !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY)
#include "cwin24bitpixel.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRGBTRIPLEPixel
 *
 * Author: $author$
 *   Date: 12/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRGBTRIPLEPixel
: public cWin24BitPixel
{
public:
    typedef cWin24BitPixel cExtends;
    
    RGBTRIPLE& m_rgb;
    
    /**
     **********************************************************************
     *  Constructor: cWinRGBTRIPLEPixel
     *
     *       Author: $author$
     *         Date: 12/16/2009
     **********************************************************************
     */
    cWinRGBTRIPLEPixel
    (RGBTRIPLE& rgb)
    : cExtends((BYTE*)(&rgb)),
      m_rgb(rgb)
    {
    }
#else /* !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY) */

#if !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY)
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
        UINT value = m_rgb.rgbtRed;
        m_rgb.rgbtRed = toValue;
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
        UINT value = m_rgb.rgbtRed;
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
        UINT value = m_rgb.rgbtGreen;
        m_rgb.rgbtGreen = toValue;
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
        UINT value = m_rgb.rgbtGreen;
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
        UINT value = m_rgb.rgbtBlue;
        m_rgb.rgbtBlue = toValue;
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
        UINT value = m_rgb.rgbtBlue;
        return value;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CWINRGBTRIPLEPIXEL_HXX) || defined(CWINRGBTRIPLEPIXEL_MEMBERS_ONLY) */

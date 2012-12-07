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
 *   File: cwinrgbpixel.hxx
 *
 * Author: $author$
 *   Date: 12/20/2009
 **********************************************************************
 */
#if !defined(_CWINRGBPIXEL_HXX) || defined(CWINRGBPIXEL_MEMBERS_ONLY)
#if !defined(_CWINRGBPIXEL_HXX) && !defined(CWINRGBPIXEL_MEMBERS_ONLY)
#define _CWINRGBPIXEL_HXX
#endif /* !defined(_CWINRGBPIXEL_HXX) && !defined(CWINRGBPIXEL_MEMBERS_ONLY) */

#if !defined(CWINRGBPIXEL_MEMBERS_ONLY)
#include "cwinpixel.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRGBPixelExtend
 *
 *  Author: $author$
 *    Date: 12/20/2009
 **********************************************************************
 */
typedef cWinPBYTEAttached
cWinRGBPixelExtend;
/**
 **********************************************************************
 *  Class: cWinRGBPixel
 *
 * Author: $author$
 *   Date: 12/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRGBPixel
: virtual public cWinPixelImplement,
  public cWinRGBPixelExtend
{
public:
    typedef cWinPixelImplement cImplements;
    typedef cWinRGBPixelExtend cExtends;
    
    UINT m_red, m_green, m_blue;
    
    /**
     **********************************************************************
     *  Constructor: cWinRGBPixel
     *
     *       Author: $author$
     *         Date: 12/20/2009
     **********************************************************************
     */
    cWinRGBPixel
    (const COLORREF& rgb)
    : m_red(GetRValue(rgb)),
      m_green(GetGValue(rgb)),
      m_blue(GetBValue(rgb))
    {
    }
#else /* !defined(CWINRGBPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBPIXEL_MEMBERS_ONLY) */

#if !defined(CWINRGBPIXEL_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: SetRed
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual UINT SetRed
    (UINT toValue) 
    {
        UINT value = (m_red = toValue);
        return value;
    }
    /**
     **********************************************************************
     * Function: SetGreen
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual UINT SetGreen
    (UINT toValue) 
    {
        UINT value = (m_green = toValue);
        return value;
    }
    /**
     **********************************************************************
     * Function: SetBlue
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual UINT SetBlue
    (UINT toValue) 
    {
        UINT value = (m_blue = toValue);
        return value;
    }

    /**
     **********************************************************************
     * Function: Red
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual UINT Red() const 
    {
        UINT value = m_red;
        return value;
    }
    /**
     **********************************************************************
     * Function: Green
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual UINT Green() const 
    {
        UINT value = m_green;
        return value;
    }
    /**
     **********************************************************************
     * Function: Blue
     *
     *   Author: $author$
     *     Date: 12/20/2009
     **********************************************************************
     */
    virtual UINT Blue() const 
    {
        UINT value = m_blue;
        return value;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRGBPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CWINRGBPIXEL_HXX) || defined(CWINRGBPIXEL_MEMBERS_ONLY) */

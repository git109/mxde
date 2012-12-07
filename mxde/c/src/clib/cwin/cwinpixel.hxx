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
 *   File: cwinpixel.hxx
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
#if !defined(_CWINPIXEL_HXX) || defined(CWINPIXEL_MEMBERS_ONLY)
#if !defined(_CWINPIXEL_HXX) && !defined(CWINPIXEL_MEMBERS_ONLY)
#define _CWINPIXEL_HXX
#endif /* !defined(_CWINPIXEL_HXX) && !defined(CWINPIXEL_MEMBERS_ONLY) */

#if !defined(CWINPIXEL_MEMBERS_ONLY)
#include "cwinpixelinterface.hxx"
#include "cwinpbyteattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinPixelExtend
 *
 *  Author: $author$
 *    Date: 12/14/2009
 **********************************************************************
 */
typedef cWinPBYTEAttached
cWinPixelExtend;
/**
 **********************************************************************
 *  Class: cWinPixel
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinPixel
: virtual public cWinPixelImplement,
  public cWinPixelExtend
{
public:
    typedef cWinPixelImplement cImplements;
    typedef cWinPixelExtend cExtends;
    
    TSIZE m_bytes, m_bits;
    BYTE m_bit, m_bitMask;
    
    /**
     **********************************************************************
     *  Constructor: cWinPixel
     *
     *       Author: $author$
     *         Date: 12/14/2009
     **********************************************************************
     */
    cWinPixel
    (PBYTE pixel=0,
     TSIZE bytes=0,
     TSIZE bits=0,
     BYTE bit=0,
     BYTE bitMask=0)
    : cExtends(pixel), 
      m_bytes(bytes),
      m_bits(bits),
      m_bit(bit),
      m_bitMask(bitMask)
    {
    }
#else /* !defined(CWINPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINPIXEL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/15/2009
     **********************************************************************
     */
    virtual int Compare
    (const cWinPixelInterface& toPixel,
     bool includeAlpha=false) const 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        int unequal = 0;
        UINT c1, c2;
        if ((c1 = Blue()) == (c2 = toPixel.Blue()))
        {
            if ((c1 = Green()) == (c2 = toPixel.Green()))
            {
                if ((c1 = Red()) > (c2 = toPixel.Red()))
                    unequal = 1;
                else
                if ((c1 = Red()) < (c2 = toPixel.Red()))
                    unequal = -1;
            }
            else
            if ((c1 = Green()) > (c2 = toPixel.Green()))
                unequal = 1;
            else
            if ((c1 = Green()) < (c2 = toPixel.Green()))
                unequal = -1;
        }
        else
        if ((c1 = Blue()) > (c2 = toPixel.Blue()))
            unequal = 1;
        else
        if ((c1 = Blue()) < (c2 = toPixel.Blue()))
            unequal = -1;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetRed
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT SetRed
    (UINT toValue) 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Red
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Red() const 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetGreen
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT SetGreen
    (UINT toValue) 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Green
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Green() const 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetBlue
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT SetBlue
    (UINT toValue) 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Blue
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Blue() const 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetAlpha
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT SetAlpha
    (UINT toValue) 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Alpha
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Alpha() const 
#if defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINPIXEL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINPIXEL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWINPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CWINPIXEL_HXX) || defined(CWINPIXEL_MEMBERS_ONLY) */

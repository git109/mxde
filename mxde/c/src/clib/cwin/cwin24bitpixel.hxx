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
 *   File: cwin24bitpixel.hxx
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
#if !defined(_CWIN24BITPIXEL_HXX) || defined(CWIN24BITPIXEL_MEMBERS_ONLY)
#if !defined(_CWIN24BITPIXEL_HXX) && !defined(CWIN24BITPIXEL_MEMBERS_ONLY)
#define _CWIN24BITPIXEL_HXX
#endif /* !defined(_CWIN24BITPIXEL_HXX) && !defined(CWIN24BITPIXEL_MEMBERS_ONLY) */

#if !defined(CWIN24BITPIXEL_MEMBERS_ONLY)
#include "cwinpixel.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWin24BitPixel
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWin24BitPixel
: public cWinPixel
{
public:
    typedef cWinPixel cExtends;
    enum
    {
        eBlueBit      = (0),
        eGreenBit     = (8),
        eRedBit       = (16),
        
        eChannelBitMask = (255),
        eBlueBitMask    = (eChannelBitMask<<eBlueBit),        
        eGreenBitMask   = (eChannelBitMask<<eGreenBit),       
        eRedBitMask     = (eChannelBitMask<<eRedBit),        
    };
    /**
     **********************************************************************
     *  Constructor: cWin24BitPixel
     *
     *       Author: $author$
     *         Date: 12/14/2009
     **********************************************************************
     */
    cWin24BitPixel
    (PBYTE pixel=0,
     TSIZE bytes=3)
    : cExtends(pixel, bytes)
    {
    }
#else /* !defined(CWIN24BITPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWIN24BITPIXEL_MEMBERS_ONLY) */

#if !defined(CWIN24BITPIXEL_MEMBERS_ONLY)
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
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        UINT32* pixel;
        if ((pixel = (UINT32*)(Attached())))
        {
            value = ((*pixel)>>eRedBit)&eChannelBitMask;
            *pixel &= (eRedBitMask);
            *pixel |= ((toValue&eChannelBitMask)<<eRedBit);
        }
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Red
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Red() const 
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        UINT32* pixel;
        if ((pixel = (UINT32*)(Attached())))
            value = ((*pixel)>>eRedBit)&eChannelBitMask;
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        UINT32* pixel;
        if ((pixel = (UINT32*)(Attached())))
        {
            value = ((*pixel)>>eGreenBit)&eChannelBitMask;
            *pixel &= (eGreenBitMask);
            *pixel |= ((toValue&eChannelBitMask)<<eGreenBit);
        }
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Green
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Green() const 
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        UINT32* pixel;
        if ((pixel = (UINT32*)(Attached())))
            value = ((*pixel)>>eGreenBit)&eChannelBitMask;
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        UINT32* pixel;
        if ((pixel = (UINT32*)(Attached())))
        {
            value = ((*pixel)>>eBlueBit)&eChannelBitMask;
            *pixel &= (eBlueBitMask);
            *pixel |= ((toValue&eChannelBitMask)<<eBlueBit);
        }
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Blue
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Blue() const 
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        UINT32* pixel;
        if ((pixel = (UINT32*)(Attached())))
            value = ((*pixel)>>eBlueBit)&eChannelBitMask;
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Alpha
     *
     *   Author: $author$
     *     Date: 12/14/2009
     **********************************************************************
     */
    virtual UINT Alpha() const 
#if defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        UINT value = 0;
#if !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWIN24BITPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWIN24BITPIXEL_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWIN24BITPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CWIN24BITPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CWIN24BITPIXEL_HXX) || defined(CWIN24BITPIXEL_MEMBERS_ONLY) */

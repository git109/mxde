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
 *   File: cwinrgbquad.hxx
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
#if !defined(_CWINRGBQUAD_HXX) || defined(CWINRGBQUAD_MEMBERS_ONLY)
#if !defined(_CWINRGBQUAD_HXX) && !defined(CWINRGBQUAD_MEMBERS_ONLY)
#define _CWINRGBQUAD_HXX
#endif /* !defined(_CWINRGBQUAD_HXX) && !defined(CWINRGBQUAD_MEMBERS_ONLY) */

#if !defined(CWINRGBQUAD_MEMBERS_ONLY)
#include "cwinbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRGBQUAD
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRGBQUAD
: public RGBQUAD
{
public:
    typedef RGBQUAD cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRGBQUAD
     *
     *       Author: $author$
     *         Date: 7/22/2009
     **********************************************************************
     */
    cWinRGBQUAD
    (BYTE red=0,
     BYTE green=0,
     BYTE blue=0,
     BYTE reserved=0)
    {
        rgbBlue = blue;
        rgbGreen = green;
        rgbRed = red;
        rgbReserved = reserved;
    }
    /**
     **********************************************************************
     *  Constructor: cWinRGBQUAD
     *
     *       Author: $author$
     *         Date: 12/3/2009
     **********************************************************************
     */
    cWinRGBQUAD
    (COLORREF color)
    {
        rgbBlue = GetBValue(color);
        rgbGreen = GetGValue(color);
        rgbRed = GetRValue(color);
        rgbReserved = 0;
    }
    /**
     **********************************************************************
     *  Constructor: cWinRGBQUAD
     *
     *       Author: $author$
     *         Date: 12/3/2009
     **********************************************************************
     */
    cWinRGBQUAD
    (const RGBQUAD& rgb)
    {
        rgbBlue = rgb.rgbBlue;
        rgbGreen = rgb.rgbGreen;
        rgbRed = rgb.rgbRed;
        rgbReserved = rgb.rgbReserved;
    }
#else /* !defined(CWINRGBQUAD_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBQUAD_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Compare
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    int Compare(const RGBQUAD& rgb)
#if defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE) */
    {
        int unequal = 0;
#if !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT)
        if (rgbRed > rgb.rgbRed)
            unequal = 1;
        else 
        if (rgbRed < rgb.rgbRed)
            unequal = -1;
        else
        if (rgbGreen > rgb.rgbGreen)
            unequal = 1;
        else 
        if (rgbGreen < rgb.rgbGreen)
            unequal = -1;
        else
        if (rgbGreen > rgb.rgbGreen)
            unequal = 1;
        else 
        if (rgbGreen < rgb.rgbGreen)
            unequal = -1;
#else /* !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: operator <=
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    bool operator <= (const RGBQUAD& rgb)
#if defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE) */
    {
        bool unequal = (Compare(rgb) <= 0);
#if !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: operator >=
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    bool operator >= (const RGBQUAD& rgb)
#if defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE) */
    {
        bool unequal = (Compare(rgb) >= 0);
#if !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUAD_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CWINRGBQUAD_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINRGBQUAD_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRGBQUAD_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBQUAD_MEMBERS_ONLY) */

#endif /* !defined(_CWINRGBQUAD_HXX) || defined(CWINRGBQUAD_MEMBERS_ONLY) */

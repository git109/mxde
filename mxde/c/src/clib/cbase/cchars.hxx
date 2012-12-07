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
 *   File: cchars.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CCHARS_HXX) || defined(CCHARS_MEMBERS_ONLY)
#if !defined(_CCHARS_HXX) && !defined(CCHARS_MEMBERS_ONLY)
#define _CCHARS_HXX
#endif /* !defined(_CCHARS_HXX) && !defined(CCHARS_MEMBERS_ONLY) */

#if !defined(CCHARS_MEMBERS_ONLY)
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CCHARS_MEMBERS_STATIC
#define CCHARS_MEMBERS_STATIC static

#undef CCHARS_MEMBERS_INLINE
#define CCHARS_MEMBERS_INLINE inline

#undef CCHARS_MEMBERS_CONST
#define CCHARS_MEMBERS_CONST

#undef CDB_CLASS
#define CDB_CLASS "cCharsT"
/**
 **********************************************************************
 *  Class: cCharsT
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TInt=INT,
 class TUInt=UINT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH>

class cCharsT
: public cTypesT
  <TWhat, TEndWhat, VEndWhat, 
   TInt, TUInt, TSize, TLength, VUndefinedLength>
{
public:
    typedef cTypesT
    <TWhat, TEndWhat, VEndWhat, 
     TInt, TUInt, TSize, TLength, VUndefinedLength> cExtends;

    typedef TWhat tWhat;
    typedef TEndWhat tEndWhat;
    typedef TInt tInt;
    typedef TUInt tUInt;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vEndWhat = VEndWhat };
    enum { vUndefinedLength = VUndefinedLength };

#else /* !defined(CCHARS_MEMBERS_ONLY) */
#endif /* !defined(CCHARS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CompareCaseless
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CCHARS_MEMBERS_STATIC int CompareCaseless
    (const tWhat* what,
     const tWhat* toWhat,
     tLength length=vUndefinedLength, 
     tEndWhat endWhat=vEndWhat) CCHARS_MEMBERS_CONST
#if defined(CCHARS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */
    {
        int unequal = CompareCaseless
        (what, length, toWhat, length, endWhat);
        return unequal;
    }
#endif /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CompareCaseless
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CCHARS_MEMBERS_STATIC int CompareCaseless
    (const tWhat* what,
     tLength length,
     const tWhat* toWhat,
     tLength toLength=vUndefinedLength, 
     tEndWhat endWhat=vEndWhat) CCHARS_MEMBERS_CONST
#if defined(CCHARS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */
    {
        int unequal = -e_ERROR_FAILED-1;
        
        if (what == toWhat)
            unequal = 0;
        else
        if (what)
        {
            if (toWhat)
            {
                if (0 > length)
                    length = Count(what, endWhat);

                if (0 > toLength)
                    toLength = Count(toWhat, endWhat);

                if (length > toLength)
                {
                    unequal = 1;
                    length = toLength;
                }
                else
                if (toLength > length)
                    unequal = -1;
                else
                unequal = 0;

                for (; 0 < length; --length, what++, toWhat++)
                {
                    tWhat lWhat = ToLower(*what);
                    tWhat lToWhat = ToLower(*toWhat);
                    
                    if (lWhat > lToWhat)
                        return 1;
                    else
                    if (lWhat < lToWhat)
                        return -1;
                }
            }
            else
            unequal = 1;
        }
        else
        unequal = -1;
        
        return unequal;
    }
#endif /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ToLower
     *
     *    Author: $author$
     *      Date: 11/12/2010
     **********************************************************************
     */
    CCHARS_MEMBERS_STATIC CCHARS_MEMBERS_INLINE tWhat ToLower
    (tWhat what) CCHARS_MEMBERS_CONST
#if defined(CCHARS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat a = (tWhat)('a');
        const tWhat A = (tWhat)('A');
        const tWhat Z = (tWhat)('Z');
        if ((A <= what) && (Z >= what))
            what = (what - A) + a;
        return what;
    }
#endif /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ToUpper
     *
     *    Author: $author$
     *      Date: 11/12/2010
     **********************************************************************
     */
    CCHARS_MEMBERS_STATIC CCHARS_MEMBERS_INLINE tWhat ToUpper
    (tWhat what) CCHARS_MEMBERS_CONST
#if defined(CCHARS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat A = (tWhat)('A');
        const tWhat a = (tWhat)('a');
        if ((a <= what) && (a >= what))
            what = (what - a) + A;
        return what;
    }
#endif /* defined(CCHARS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCHARS_MEMBERS_ONLY)
};
#undef CDB_CLASS
#undef CCHARS_MEMBERS_CONST
#undef CCHARS_MEMBERS_INLINE
#undef CCHARS_MEMBERS_STATIC

/**
 **********************************************************************
 * Typedef: cChars
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cCharsT<CHAR> cChars;
/**
 **********************************************************************
 * Typedef: cWChars
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cCharsT<WCHAR> cWChars;
/**
 **********************************************************************
 * Typedef: cTChars
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cCharsT<TCHAR> cTChars;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCHARS_MEMBERS_ONLY) */
#endif /* !defined(CCHARS_MEMBERS_ONLY) */

#endif /* !defined(_CCHARS_HXX) || defined(CCHARS_MEMBERS_ONLY) */

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
 *   File: ctypes.hxx
 *
 * Author: $author$
 *   Date: 5/2/2009
 **********************************************************************
 */
#if !defined(_CTYPES_HXX) || defined(CTYPES_MEMBERS_ONLY)
#if !defined(_CTYPES_HXX) && !defined(CTYPES_MEMBERS_ONLY)
#define _CTYPES_HXX
#endif /* !defined(_CTYPES_HXX) && !defined(CTYPES_MEMBERS_ONLY) */

#if !defined(CTYPES_MEMBERS_ONLY)
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CTYPES_MEMBERS_STATIC
#define CTYPES_MEMBERS_STATIC static

#undef CTYPES_MEMBERS_INLINE
#define CTYPES_MEMBERS_INLINE inline

#undef CTYPES_MEMBERS_CONST
#define CTYPES_MEMBERS_CONST

#undef CDB_CLASS
#define CDB_CLASS "cTypesT"
/**
 **********************************************************************
 *  Class: cTypesT
 *
 * Author: $author$
 *   Date: 5/2/2009
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
 
class cTypesT
{
public:
    typedef TWhat tWhat;
    typedef TEndWhat tEndWhat;
    typedef TInt tInt;
    typedef TUInt tUInt;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vEndWhat = VEndWhat };
    enum { vUndefinedLength = VUndefinedLength };
#else /* !defined(CTYPES_MEMBERS_ONLY) */
#endif /* !defined(CTYPES_MEMBERS_ONLY) */

#if !defined(CTYPES_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tLength Set
    (tWhat* toWhat, tWhat what, 
     tLength length=vUndefinedLength, 
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tLength count = 0;
        tWhat c;

        if (toWhat)
        if (0 > length)
        {
            /* strset
             */
            while ((c = (*toWhat)) != endWhat)
            {
                (*toWhat++) = what;
                count++;
            }
        }
        else
        {
            /* memset
             */
            while (count < length)
            {
                (*toWhat++) = what;
                count++;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tLength Copy
    (tWhat* toWhat, const tWhat* what, 
     tLength length=vUndefinedLength, 
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tLength count = 0;
        tWhat c;

        if (toWhat && what)
        if (0 > length)
        {
            /* strcpy
             */
            while ((c = (*what++)) != endWhat)
            {
                (*toWhat++) = c;
                count++;
            }
            (*toWhat) = c;
        }
        else
        {
            /* memcpy
             */
            while (count < length)
            {
                (*toWhat++) = (c = (*what++));
                count++;
            }
        }
        return count;
    }
#else /* !defined(CTYPES_MEMBERS_ONLY) */
#endif /* !defined(CTYPES_MEMBERS_ONLY) */
    
    /**
     **********************************************************************
     * Function: Count
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tLength Count
    (const tWhat* what, 
     tEndWhat endWhat=vEndWhat, 
     tLength length=vUndefinedLength) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
        
        if (what && ((0 > length) || (count < length)))
        while ((*what++) != (tWhat)(endWhat))
        {
            if ((0 <= length) && (count >= length))
                break;
            count++;
        }
        return count;
    }
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: FindFirst
     *
     *   Author: $author$
     *     Date: 9/15/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC const tWhat* FindFirst
    (const tWhat* what,
     tWhat findWhat, 
     tEndWhat endWhat=vEndWhat, 
     tLength length=vUndefinedLength) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* found = 0;
        tWhat atWhat;
        tLength count;
        
        if (what)
        for (count = 0; (0 > length) || (count < length); count++, what++)
        {
            if (findWhat == (atWhat = (*what)))
            {
                found = what;
                break;
            }
            if ((0 > length) && (atWhat == (tWhat)(endWhat)))
                break;
        }
        return found;
    }
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FindLast
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC const tWhat* FindLast
    (const tWhat* what,
     tWhat findWhat, 
     tEndWhat endWhat=vEndWhat, 
     tLength length=vUndefinedLength) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* found = 0;
        const tWhat* whatEnd;
        tWhat atWhat;
        
        if ((whatEnd = what))
        {
            if (0 <= length)
                whatEnd += length;
            else
            while (endWhat != *whatEnd)
                whatEnd++;
                
            while (whatEnd != what)
            {
                if (findWhat == (atWhat = (*--whatEnd)))
                {
                    found = whatEnd;
                    break;
                }
            }
        }
        return found;
    }
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: FindFirst
     *
     *   Author: $author$
     *     Date: 9/24/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC const tWhat* FindFirst
    (const tWhat* what,
     const tWhat* whatFind, 
     tEndWhat endWhat=vEndWhat,
     tLength findLength=vUndefinedLength, 
     tLength length=vUndefinedLength) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* found = 0;
        tWhat findWhat, atWhat;
        int unequal;
        
        if (what && whatFind)
        {
            if (0 > length)
            if (1 > (length = Count(what, endWhat)))
                return 0;
                
            if (0 > findLength)
            if (1 > (findLength = Count(whatFind, endWhat)))
                return 0;
                
            if (findLength < length)
            {
                for (findWhat = *whatFind, length -= (findLength-1); 
                     (0 < length); --length, what++)
                {
                    if (findWhat == (atWhat = (*what)))
                    if (!(unequal = Compare
                        (what, whatFind, findLength, endWhat)))
                    {
                        found = what;
                        break;
                    }
                    if ((0 > length) && (atWhat == (tWhat)(endWhat)))
                        break;
                }
            }
            else
            if (findLength == length)
            {
                if (!(unequal = Compare
                    (what, whatFind, findLength, endWhat)))
                    found = what;
            }
        }
        return found;
    }
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FindLast
     *
     *   Author: $author$
     *     Date: 9/24/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC const tWhat* FindLast
    (const tWhat* what,
     const tWhat* whatFind, 
     tEndWhat endWhat=vEndWhat,
     tLength findLength=vUndefinedLength, 
     tLength length=vUndefinedLength) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* found = 0;
        tWhat findWhat, atWhat;
        int unequal;
        
        if (what && whatFind)
        {
            if (0 > length)
                length = Count(what, endWhat);
                
            if (0 > findLength)
                findLength = Count(whatFind, endWhat);
                
            if (findLength <= length)
            {
                for (findWhat = *whatFind, 
                     what += (length -= findLength); 
                     (0 < length); --length, --what)
                {
                    if (findWhat == (atWhat = (*what)))
                    if (!(unequal = Compare
                        (what, whatFind, findLength, endWhat)))
                    {
                        found = what;
                        break;
                    }
                }
                if (!(unequal = Compare
                    (what, whatFind, findLength, endWhat)))
                    found = what;
            }
        }
        return found;
    }
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC int Compare
    (const tWhat* what,
     const tWhat* toWhat,
     tLength length=vUndefinedLength, 
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    {
        int unequal = Compare
        (what, length, toWhat, length, endWhat);
        return unequal;
    }
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC int Compare
    (const tWhat* what,
     tLength length,
     const tWhat* toWhat,
     tLength toLength=vUndefinedLength, 
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
#if defined(CTYPES_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */
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
                    if (*what > *toWhat)
                        return 1;
                    else
                    if (*what < *toWhat)
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
#endif /* defined(CTYPES_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTYPES_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: ToSigned
     *
     *   Author: $author$
     *     Date: 9/27/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tLength ToSigned
    (const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tWhat minus = (tWhat)('-');
        tWhat space = (tWhat)(' ');
        tLength value = 0;
        tWhat c;
        
        if (what)
        if (0 > length)
        {
            for (;(c = (*what)) != endWhat; what++)
            {
                if (c != space)
                {
                    if (c != minus)
                        value = (tLength)(ToUnsigned(what, length, endWhat));
                    else
                    value = -(tLength)(ToUnsigned(what+1, length, endWhat));
                    break;
                }
            }
        }
        else
        {
            for (; 0 < length; --length, what++)
            {
                if ((c = *what) != space)
                {
                    if (c != minus)
                        value = (tLength)(ToUnsigned(what, length, endWhat));
                    else
                    value = -(tLength)(ToUnsigned(what+1, length-1, endWhat));
                    break;
                }
            }
        }
        return value;
    }
    /**
     **********************************************************************
     * Function: ToUnsigned
     *
     *   Author: $author$
     *     Date: 9/27/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tSize ToUnsigned
    (const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tSize value = 0;
        tSize d;
        tWhat c;

        if (what)
        if (0 > length)
        {
            while ((c = (*what++)) != endWhat)
            {
                if (0 > (d = DToUnsigned(c)))
                    break;
                value *= 10;
                value += d;
            }
        }
        else
        {
            for (; 0 < length; --length)
            {
                if (0 > (d = DToUnsigned(c = (*what++))))
                    break;
                value *= 10;
                value += d;
            }
        }
        return value;
    }
    
    /**
     **********************************************************************
     * Function: ToInt
     *
     *   Author: $author$
     *     Date: 6/22/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tInt ToInt
    (const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tWhat minus = (tWhat)('-');
        tWhat space = (tWhat)(' ');
        tInt value = 0;
        tWhat c;
        
        if (what)
        if (0 > length)
        {
            for (;(c = (*what)) != endWhat; what++)
            {
                if (c != space)
                {
                    if (c != minus)
                        value = (tInt)(ToUInt(what, length, endWhat));
                    else
                    value = -(tInt)(ToUInt(what+1, length, endWhat));
                    break;
                }
            }
        }
        else
        {
            for (; 0 < length; --length, what++)
            {
                if ((c = *what) != space)
                {
                    if (c != minus)
                        value = (tInt)(ToUInt(what, length, endWhat));
                    else
                    value = -(tInt)(ToUInt(what+1, length-1, endWhat));
                    break;
                }
            }
        }
        return value;
    }
    /**
     **********************************************************************
     * Function: ToUInt
     *
     *   Author: $author$
     *     Date: 6/22/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tUInt ToUInt
    (const tWhat* what,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tUInt value = 0;
        tInt d;
        tWhat c;

        if (what)
        if (0 > length)
        {
            while ((c = (*what++)) != endWhat)
            {
                if (0 > (d = DToInt(c)))
                    break;
                value *= 10;
                value += d;
            }
        }
        else
        {
            for (; 0 < length; --length)
            {
                if (0 > (d = DToInt(c = (*what++))))
                    break;
                value *= 10;
                value += d;
            }
        }
        return value;
    }
    /**
     **********************************************************************
     * Function: ToX
     *
     *   Author: $author$
     *     Date: 8/21/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tLength ToX
    (tWhat* what,
     const BYTE* bytes,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat,
     CHAR A='A') CTYPES_MEMBERS_CONST
    {
        tLength count = ToX
        (what, vUndefinedLength, 
         bytes, length, endWhat, A);
        return count;
    }
    /**
     **********************************************************************
     * Function: ToX
     *
     *   Author: $author$
     *     Date: 5/10/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC tLength ToX
    (tWhat* what,
     tLength size,
     const BYTE* bytes,
     tLength length=vUndefinedLength,
     tEndWhat endWhat=vEndWhat,
     CHAR A='A') CTYPES_MEMBERS_CONST
    {
        tLength count = 0;
        tLength i,j;
        BYTE d;
        tWhat x;

        for (j=0, i=0; ((j+2 < size) || (0 > size)) 
             && ((i < length) || (0 > length)); i++, j += 2)
        {
            if (!(d = bytes[i]) && (0 > length))
                break;
                
            what[count++] = (x = DToX((d >> 4), A, endWhat));
            what[count++] = (x = DToX((d & 15), A, endWhat));
        }
        if ((j+2 < size) || (0 > size))
            what[count] = endWhat;
        return count;
    }
    
    /**
     **********************************************************************
     * Function: DToUnsigned
     *
     *   Author: $author$
     *     Date: 9/27/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC CTYPES_MEMBERS_INLINE tSize DToUnsigned
    (tWhat d, 
     tWhat d0=(tWhat)('0'), 
     tWhat d9=(tWhat)('9')) CTYPES_MEMBERS_CONST
    {
        tSize value = -1;
        if ((d >= d0) && (d <= d9))
            value = d - d0;
        return value;
    }
    /**
     **********************************************************************
     * Function: DToInt
     *
     *   Author: $author$
     *     Date: 6/22/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC CTYPES_MEMBERS_INLINE tInt DToInt
    (tWhat d, 
     tWhat d0=(tWhat)('0'), 
     tWhat d9=(tWhat)('9')) CTYPES_MEMBERS_CONST
    {
        tInt value = -1;
        if ((d >= d0) && (d <= d9))
            value = d - d0;
        return value;
    }
    
    /**
     **********************************************************************
     * Function: DToX
     *
     *   Author: $author$
     *     Date: 5/10/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC CTYPES_MEMBERS_INLINE tWhat DToX
    (BYTE d, CHAR A='A', 
     tEndWhat endWhat=vEndWhat) CTYPES_MEMBERS_CONST
    {
        tWhat x;
        
        if ((0 <= d) && (9 >= d))
            x = (tWhat)('0') +  d;
        else
        if ((10 <= d) && (15 >= d))
            x = (tWhat)(A) + (d - 10);
        else
        x = endWhat;

        return x;
    }
    /**
     **********************************************************************
     * Function: XToD
     *
     *   Author: $author$
     *     Date: 5/10/2009
     **********************************************************************
     */
    CTYPES_MEMBERS_STATIC CTYPES_MEMBERS_INLINE BYTE XToD
    (tWhat x) CTYPES_MEMBERS_CONST
    {
        BYTE d;

        if (((tWhat)('0') <= x) && ((tWhat)('9') >= x))
            d = (BYTE)(x - (tWhat)('0'));
        else
        if (((tWhat)('A') <= x) && ((tWhat)('F') >= x))
            d = (BYTE)(x - (tWhat)('A') + 10);
        else
        if (((tWhat)('a') <= x) && ((tWhat)('f') >= x))
            d = (BYTE)(x - (tWhat)('a') + 10);
        else
        d = 0;

        return d;
    }
};
#undef CDB_CLASS
#undef CTYPES_MEMBERS_CONST
#undef CTYPES_MEMBERS_INLINE
#undef CTYPES_MEMBERS_STATIC

/**
 **********************************************************************
 * Typedef: cBYTES
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<BYTE> cBYTES;
/**
 **********************************************************************
 * Typedef: cWORDS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<WORD> cWORDS;
/**
 **********************************************************************
 * Typedef: cLONGS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<LONG> cLONGS;

/**
 **********************************************************************
 * Typedef: cCHARS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<CHAR> cCHARS;
/**
 **********************************************************************
 * Typedef: cTCHARS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<TCHAR> cTCHARS;
/**
 **********************************************************************
 * Typedef: cWCHARS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<WCHAR> cWCHARS;

/**
 **********************************************************************
 * Typedef: cPCHARS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<PCHAR, INT> cPCHARS;
/**
 **********************************************************************
 * Typedef: cPTCHARS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<PTCHAR, INT> cPTCHARS;
/**
 **********************************************************************
 * Typedef: cPWCHARS
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<PWCHAR, INT> cPWCHARS;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTYPES_MEMBERS_ONLY) */
#endif /* !defined(CTYPES_MEMBERS_ONLY) */

#endif /* !defined(_CTYPES_HXX) || defined(CTYPES_MEMBERS_ONLY) */

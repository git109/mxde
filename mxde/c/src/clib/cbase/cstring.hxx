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
 *   File: cstring.hxx
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
#if !defined(_CSTRING_HXX) || defined(CSTRING_MEMBERS_ONLY)
#if !defined(_CSTRING_HXX) && !defined(CSTRING_MEMBERS_ONLY)
#define _CSTRING_HXX
#endif /* !defined(_CSTRING_HXX) && !defined(CSTRING_MEMBERS_ONLY) */

#if !defined(CSTRING_MEMBERS_ONLY)
#include "cstdstring.hxx"
#include "cstringinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cString;

#undef CDB_CLASS
#define CDB_CLASS "cStringT"
/**
 **********************************************************************
 *  Class: cStringT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cString,
 class TStringImplement=cStringImplement,
 class TStringInterface=cStringInterface,
 class TStringBase=cStdStringBase,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TStringImplement,
 class TExtends=TStringBase>
 
class c_INSTANCE_CLASS cStringT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TStringInterface tStringInterface;

/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

    tLength m_tell;

    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 2/28/2009
     **********************************************************************
     */
    cStringT
    (const tChar* chars=0,
     tLength length=vUndefinedLength) 
    : m_tell(0)
    {
        eError error;
        if (chars)
        if (0 > (length = Append(chars, length)))
            throw(error = -length);
    }
#else /* !defined(CSTRING_MEMBERS_ONLY) */
#endif /* !defined(CSTRING_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SignedToChars
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual const tChar* SignedToChars
    (tLength value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
        tLength count;
        if (0 <= (count = AssignSigned(value)))
            chars = Chars();
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: UnsignedToChars
     *
     *   Author: $author$
     *     Date: 8/17/2009
     **********************************************************************
     */
    virtual const tChar* UnsignedToChars
    (tSize value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
        tLength count;
        if (0 <= (count = AssignUnsigned(value)))
            chars = Chars();
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Signed64ToChars
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual const tChar* Signed64ToChars
    (INT64 value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
        tLength count;
        if (0 <= (count = AssignSigned64(value)))
            chars = Chars();
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Unsigned64ToChars
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual const tChar* Unsigned64ToChars
    (UINT64 value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
        tLength count;
        if (0 <= (count = AssignUnsigned64(value)))
            chars = Chars();
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignSigned
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AssignSigned
    (tLength value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count;
        if (0 <= (count = Clear()))
            count = AppendSigned(value);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendSigned
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AppendSigned
    (tLength value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tChar minus = ((tChar)('-'));
        tLength count = 0;
        tLength count2;

        if (0 > value)
        if (0 > (count = Append(&minus, 1)))
            return count;
        else
        value = -value;

        if (0 > (count2 = AppendUnsigned((tSize)value)))
            return count2;
        else
        count += count2;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignUnsigned
     *
     *   Author: $author$
     *     Date: 8/17/2009
     **********************************************************************
     */
    virtual tLength AssignUnsigned
    (tSize value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count;
        if (0 <= (count = Clear()))
            count = AppendUnsigned(value);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendUnsigned
     *
     *   Author: $author$
     *     Date: 8/17/2009
     **********************************************************************
     */
    virtual tLength AppendUnsigned
    (tSize value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tChar zero = ((tChar)('0'));
        tLength count = 0;
        tSize digits;
        tSize msdValue;

        if (0 == value)
            count = Append(&zero, 1);
        else
        {
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
                
            for (; msdValue; msdValue /= 10, --digits)
            {
                tChar d = (tChar)('0' + (char)(msdValue%10));
                count += Append(&d, 1);
            }
            
            for (; digits; --digits)
                count += Append(&zero, 1);
        }
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignSigned64
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AssignSigned64
    (INT64 value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count;
        if (0 <= (count = Clear()))
            count = AppendSigned64(value);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendSigned64
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AppendSigned64
    (INT64 value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tChar minus = ((tChar)('-'));
        tLength count = 0;
        tLength count2;

        if (0 > value)
        if (0 > (count = Append(&minus, 1)))
            return count;
        else
        value = -value;

        if (0 > (count2 = AppendUnsigned64((UINT64)value)))
            return count2;
        else
        count += count2;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AssignUnsigned64
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AssignUnsigned64
    (UINT64 value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count;
        if (0 <= (count = Clear()))
            count = AppendUnsigned64(value);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendUnsigned64
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AppendUnsigned64
    (UINT64 value) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tChar zero = ((tChar)('0'));
        tLength count = 0;
        tSize digits;
        UINT64 msdValue;

        if (0 == value)
            count = Append(&zero, 1);
        else
        {
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
                
            for (; msdValue; msdValue /= 10, --digits)
            {
                tChar d = (tChar)('0' + (char)(msdValue%10));
                count += Append(&d, 1);
            }
            
            for (; digits; --digits)
                count += Append(&zero, 1);
        }
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: XToChars
     *
     *    Author: $author$
     *      Date: 4/5/2010
     **********************************************************************
     */
    virtual const tChar* XToChars
    (const BYTE* bytes,
     tLength length = vUndefinedLength)
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
        tLength count;
        if (0 <= (count = AssignX(bytes, length)))
            chars = Chars();
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AssignX
     *
     *    Author: $author$
     *      Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AssignX
    (const BYTE* bytes,
     tLength length = vUndefinedLength)
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
        if (0 > (count = ClearChars()))
            return count;
        count = AppendX(bytes, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppendX
     *
     *    Author: $author$
     *      Date: 4/5/2010
     **********************************************************************
     */
    virtual tLength AppendX
    (const BYTE* bytes,
     tLength length = vUndefinedLength)
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
        tLength appended;
        tWhat x[2];
        BYTE b;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                b = (*bytes++);
                x[0] = DToX(b >> 4);
                x[1] = DToX(b & 15);
                if (0 > (appended = AppendChars(x, 2)))
                    return appended;
            }
        }
        else
        for (; (b = (*bytes++)); count += appended)
        {
            x[0] = DToX(b >> 4);
            x[1] = DToX(b & 15);
            if (0 > (appended = AppendChars(x, 2)))
                return appended;
        }
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignW
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual tLength AssignW
    (const WCHAR* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = AssignWChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendW
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual tLength AppendW
    (const WCHAR* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = AppendWChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignT
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual tLength AssignT
    (const TCHAR* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = AssignTChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendT
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual tLength AppendT
    (const TCHAR* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = AppendTChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength Assign
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = AssignChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength Append
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = AppendChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength Clear() 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = ClearChars();
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignWChars
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength AssignWChars
    (const WCHAR* wChars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        if (0 > (count = ClearChars()))
            return count;
        count = AppendWChars(wChars, length);
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendWChars
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength AppendWChars
    (const WCHAR* wChars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        tLength appended;
        tChar c;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                c = (tChar)(*wChars++);
                if (0 > (appended = AppendChars(&c, 1)))
                    return appended;
            }
        }
        else
        for (; ((c = (tChar)(*wChars++)) != vEndChar); count += appended)
        {
            if (0 > (appended = AppendChars(&c, 1)))
                return appended;
        }
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignTChars
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual tLength AssignTChars
    (const TCHAR* tChars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        if (0 > (count = ClearChars()))
            return count;
        count = AppendTChars(tChars, length);
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendTChars
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual tLength AppendTChars
    (const TCHAR* tChars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        tLength appended;
        tChar c;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                c = (tChar)(*tChars++);
                if (0 > (appended = AppendChars(&c, 1)))
                    return appended;
            }
        }
        else
        for (; ((c = (tChar)(*tChars++)) != vEndChar); count += appended)
        {
            if (0 > (appended = AppendChars(&c, 1)))
                return appended;
        }
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignCHARS
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual tLength AssignCHARS
    (const CHAR* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        if (0 > (count = ClearChars()))
            return count;
        count = AppendCHARS(chars, length);
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendCHARS
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual tLength AppendCHARS
    (const CHAR* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        tLength appended;
        tChar c;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                c = (tChar)(*chars++);
                if (0 > (appended = AppendChars(&c, 1)))
                    return appended;
            }
        }
        else
        for (; ((c = (tChar)(*chars++)) != vEndChar); count += appended)
        {
            if (0 > (appended = AppendChars(&c, 1)))
                return appended;
        }
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Assign_chars
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual tLength Assign_chars
    (const char* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        if (0 > (count = ClearChars()))
            return count;
        count = Append_chars(chars, length);
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Append_chars
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual tLength Append_chars
    (const char* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTRING_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
        tLength appended;
        tChar c;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                c = (tChar)(*chars++);
                if (0 > (appended = AppendChars(&c, 1)))
                    return appended;
            }
        }
        else
        for (; ((c = (tChar)(*chars++)) != vEndChar); count += appended)
        {
            if (0 > (appended = AppendChars(&c, 1)))
                return appended;
        }
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength AssignChars
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
        if (0 > (count = ClearChars()))
            return count;
        count = AppendChars(chars, length);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength AppendChars
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = Length();
        if (0 > length)
            CTHIS append(chars);
        else CTHIS append(chars, length);
        count = Length()-count;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength ClearChars() 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = Length();
        CTHIS clear();
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual int Compare
    (const tChar* toChars,
     tLength toLength=vUndefinedLength) const
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
   {
        int unequal = 1;
        unequal = CompareChars(toChars, toLength);
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CompareChars
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual int CompareChars
    (const tChar* toChars,
     tLength toLength=vUndefinedLength) const
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        int unequal = 1;
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        if (0 > toLength)
            unequal = CTHIS compare(toChars);
        else
        {
            tLength length;
            cDerives to;
            if (0 <= (length = to.AppendChars(toChars, toLength)))
            if ((toChars = to.Chars(toLength)))
                unequal = CTHIS compare(toChars);
        }
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual const tChar* HasChars
    (tLength& charsLength) const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = CTHIS c_str();
        if (1 > (charsLength = (tLength)(CTHIS length())))
            chars = 0;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        if ((chars = Chars(charsLength)))
        if (1 > charsLength)
            chars = 0;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 9/18/2009
     **********************************************************************
     */
    virtual const tChar* HasChars() const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = CTHIS c_str();
        if (1 > (CTHIS length()))
            chars = 0;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength charsLength = 0;
        const tChar* chars = HasChars(charsLength);
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual const tChar* Chars
    (tLength& charsLength, bool onlyHasChars=false) const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = CTHIS c_str();
        if (1 > (charsLength = (tLength)(CTHIS length())))
        if (onlyHasChars)
            chars = 0;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        charsLength = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual const tChar* Chars
    (bool onlyHasChars=false) const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = CTHIS c_str();
        if (onlyHasChars)
        if (1 > (CTHIS length()))
            chars = 0;
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength charsLength = 0;
        const tChar* chars = Chars(charsLength, onlyHasChars);
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tLength Length() const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = (tLength)(CTHIS length());
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: DToX
     *
     *    Author: $author$
     *      Date: 4/5/2010
     **********************************************************************
     */
    virtual tChar DToX
    (BYTE d, CHAR A='A', 
     tEndChar endChar = vEndChar) const
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tChar x = (tChar)(endChar);

        if ((0 <= d) && (9 >= d))
            x = (tChar)(('0') +  d);
        else
        if ((10 <= d) && (15 >= d))
            x = (tChar)((A) + (d - 10));

#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return x;
    }
#endif /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSTRING_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INSTANCE_CLASS cString;
/**
 **********************************************************************
 * Typedef: cStringExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringT
<cString, cStringImplement, cStringInterface,
 cStdStringBase, CHAR>
cStringExtends;
/**
 **********************************************************************
 *  Class: cString
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cString
: public cStringExtends
{
public:
    typedef cStringExtends cExtends;
    typedef cString cDerives;
    /**
     **********************************************************************
     * Constructor: cString
     *
     *      Author: $author$
     *        Date: 3/3/2009
     **********************************************************************
     */
    cString
    (const tChar* chars=0,
     tLength length=vUndefinedLength) 
    : cExtends(chars,length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cString
     *
     *      Author: $author$
     *        Date: 3/14/2010
     **********************************************************************
     */
    cString
    (const WCHAR* chars,
     tLength length=vUndefinedLength) 
    {
        eError error;
        if (chars)
        if (0 > (length = AppendW(chars, length)))
            throw(error = -length);
    }
};

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARString;
/**
 **********************************************************************
 * Typedef: cTCHARStringExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringT
<cTCHARString, cTCHARStringImplement, cTCHARStringInterface,
 cTCHARStdStringBase, TCHAR>
cTCHARStringExtends;
/**
 **********************************************************************
 *  Class: cTCHARString
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
typedef
class c_INSTANCE_CLASS cTCHARString
: public cTCHARStringExtends
{
public:
    typedef cTCHARStringExtends cExtends;
    typedef cTCHARString cDerives;
    /**
     **********************************************************************
     * Constructor: cTCHARString
     *
     *      Author: $author$
     *        Date: 3/3/2009
     **********************************************************************
     */
    cTCHARString
    (const tChar* chars=0,
     tLength length=vUndefinedLength) 
    : cExtends(chars,length) 
    {
    }
#if defined(TCHAR_NOT_CHAR) 
    /**
     **********************************************************************
     * Constructor: cTCHARString
     *
     *      Author: $author$
     *        Date: 3/14/2010
     **********************************************************************
     */
    cTCHARString
    (const CHAR* chars,
     tLength length=vUndefinedLength) 
    {
        eError error;
        if (chars)
        if (0 > (length = AppendCHARS(chars, length)))
            throw(error = -length);
    }
#else /* defined(TCHAR_NOT_CHAR) */
    /**
     **********************************************************************
     * Constructor: cTCHARString
     *
     *      Author: $author$
     *        Date: 4/12/2010
     **********************************************************************
     */
    cTCHARString
    (const WCHAR* chars,
     tLength length=vUndefinedLength) 
    {
        eError error;
        if (chars)
        if (0 > (length = AppendW(chars, length)))
            throw(error = -length);
    }
#endif /* defined(TCHAR_NOT_CHAR) */
} cTString;

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARString;
/**
 **********************************************************************
 * Typedef: cWCHARStringExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringT
<cWCHARString, cWCHARStringImplement, cWCHARStringInterface,
 cWCHARStdStringBase, WCHAR>
cWCHARStringExtends;
/**
 **********************************************************************
 *  Class: cWCHARString
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
typedef
class c_INSTANCE_CLASS cWCHARString
: public cWCHARStringExtends
{
public:
    typedef cWCHARStringExtends cExtends;
    typedef cWCHARString cDerives;
    /**
     **********************************************************************
     * Constructor: cWCHARString
     *
     *      Author: $author$
     *        Date: 3/3/2009
     **********************************************************************
     */
    cWCHARString
    (const tChar* chars=0,
     tLength length=vUndefinedLength) 
    : cExtends(chars,length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cWCHARString
     *
     *      Author: $author$
     *        Date: 3/14/2010
     **********************************************************************
     */
    cWCHARString
    (const CHAR* chars,
     tLength length=vUndefinedLength) 
    {
        eError error;
        if (chars)
        if (0 > (length = AppendCHARS(chars, length)))
            throw(error = -length);
    }
} cWString;

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEString;
/**
 **********************************************************************
 * Typedef: cBYTEStringExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringT
<cBYTEString, cBYTEStringImplement, cBYTEStringInterface,
 cBYTEStdStringBase, BYTE>
cBYTEStringExtends;
/**
 **********************************************************************
 *  Class: cBYTEString
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
typedef
class c_INSTANCE_CLASS cBYTEString
: public cBYTEStringExtends
{
public:
    typedef cBYTEStringExtends cExtends;
    typedef cBYTEString cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEString
     *
     *      Author: $author$
     *        Date: 3/3/2009
     **********************************************************************
     */
    cBYTEString
    (const tChar* chars=0,
     tLength length=vUndefinedLength) 
    : cExtends(chars,length) 
    {
    }
} cBString;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTRING_MEMBERS_ONLY) */
#endif /* !defined(CSTRING_MEMBERS_ONLY) */

#endif /* !defined(_CSTRING_HXX) || defined(CSTRING_MEMBERS_ONLY) */

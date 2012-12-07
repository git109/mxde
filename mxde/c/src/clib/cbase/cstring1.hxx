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
#if defined(CSTRING_MEMBER_FUNCS_ONLY) 
#if defined(_CSTRING_HXX) 
#define _CSTRING_HXX_OLD 
#undef _CSTRING_HXX
#endif /* defined(_CSTRING_HXX) */
#endif /* defined(CSTRING_MEMBER_FUNCS_ONLY) */

#ifndef _CSTRING_HXX
#define _CSTRING_HXX

#if !defined(CSTRING_MEMBER_FUNCS_ONLY) 
#include <string>
#include "cstringinterface.hxx"

/**
 **********************************************************************
 * Typedef: cStdStringBase
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef std::basic_string<CHAR>
cStdStringBase;

class cString;

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
 class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TStringInterface=cStringInterface,
 class TStringImplement=cStringImplement,
 class TStringBase=cStdStringBase,
 class TImplements=TStringImplement,
 class TExtends=TStringBase>
 
class cStringT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstringinterfacebase.hxx"
#undef CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY

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
#else /* !defined(CSTRING_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_ONLY) */

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
        tLength count = 0;
        if (0 > length)
            CTHIS append(chars);
        else CTHIS append(chars, length);
        count = Length();
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
    (tLength& length) const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
        if ((chars = Chars(length)))
        if (0 >= length)
            chars = 0;
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
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
    (tLength& length) const 
#if defined(CSTRING_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = CTHIS c_str();
        length = Length();
#else /* !defined(CSTRING_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
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

#if !defined(CSTRING_MEMBER_FUNCS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStringExtends
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cStringT<cString,CHAR>
cStringExtends;
/**
 **********************************************************************
 *  Class: cString
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class cString
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
     *        Date: 3/1/2009
     **********************************************************************
     */
    cString
    (const tChar* chars=0,
     tLength length=vUndefinedLength) 
    : cExtends(chars,length)
    {
    }
};

/*
 * TCHAR
 */
class cTCHARString;
/**
 **********************************************************************
 * Typedef: cTCHARStdStringBase
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef std::basic_string<TCHAR>
cTCHARStdStringBase;
/**
 **********************************************************************
 * Typedef: cTCHARStringExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringT
<cTCHARString,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARStringInterface, 
 cTCHARStringImplement, cTCHARStdStringBase>
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
class cTCHARString
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
} cTString;

/*
 * WCHAR
 */
class cWCHARString;
/**
 **********************************************************************
 * Typedef: cWCHARStdStringBase
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef std::basic_string<WCHAR>
cWCHARStdStringBase;
/**
 **********************************************************************
 * Typedef: cWCHARStringExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringT
<cWCHARString,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARStringInterface, 
 cWCHARStringImplement, cWCHARStdStringBase>
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
class cWCHARString
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
} cWString;
#else /* !defined(CSTRING_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CSTRING_MEMBER_FUNCS_ONLY) */

#endif /* _CSTRING_HXX */

#if defined(CSTRING_MEMBER_FUNCS_ONLY) 
#if defined(_CSTRING_HXX_OLD) 
#define _CSTRING_HXX
#undef _CSTRING_HXX_OLD
#endif /* defined(_CSTRING_HXX_OLD) */
#endif /* defined(CSTRING_MEMBER_FUNCS_ONLY) */

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
 *   File: cdigitizer.hxx
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
#if defined(CDIGITIZER_MEMBER_FUNCS_ONLY) 
#if defined(_CDIGITIZER_HXX) 
#undef _CDIGITIZER_HXX
#define _CDIGITIZER_HXX_OLD
#endif /* defined(_CDIGITIZER_HXX) */
#endif /* defined(CDIGITIZER_MEMBER_FUNCS_ONLY) */

#ifndef _CDIGITIZER_HXX
#define _CDIGITIZER_HXX

#if !defined(CDIGITIZER_MEMBER_FUNCS_ONLY)
#include "cbase.hxx"

class cDigitizer;

#undef CDB_CLASS
#define CDB_CLASS "cDigitizerT"
/**
 **********************************************************************
 *  Class: cDigitizerT
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
template
<class TDerives=cDigitizer,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSigned=TSIGNED,
 class TUnsigned=TUNSIGNED,
 class TBase=cBase,
 class TExtends=TBase>
 
class cDigitizerT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
#else /* !defined(CDIGITIZER_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CDIGITIZER_MEMBER_FUNCS_ONLY) */

#define CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstreaminterfacebase.hxx"
#undef CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
    
    typedef TSigned tSigned;
    typedef TUnsigned tUnsigned;

    /**
     **********************************************************************
     * Function: Signed
     *
     *   Author: $author$
     *     Date: 3/3/2009
     **********************************************************************
     */
    virtual tSigned Signed
    (tLength& digits,
     const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CDIGITIZER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CDIGITIZER_MEMBER_FUNCS_INTERFACE) */
    {
        tSigned value = 0;
#if !defined(CDIGITIZER_MEMBER_FUNCS_IMPLEMENT) 
        bool negative = false;
        tLength count;
        tWhat c;

        digits = 0;
        if ((0 < length) && (vUndefinedLength != length))
        for (count = 0; count < length; count++)
        {
            if (!Digitize(digits, value, (c = what[count])))
            if (('-' == c) && (1 > digits))
               negative = true;
        }
        else
        for (count = 0; (c = what[count]) != vEndWhat; count++)
        {
            if (!Digitize(digits, value, c))
            if (('-' == c) && (1 > digits))
               negative = true;
        }
        if (negative)
            value = -value;
#else /* !defined(CDIGITIZER_MEMBER_FUNCS_IMPLEMENT) */
        digits = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDIGITIZER_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CDIGITIZER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Unsigned
     *
     *   Author: $author$
     *     Date: 3/3/2009
     **********************************************************************
     */
    virtual tUnsigned Unsigned
    (tLength& digits,
     const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CDIGITIZER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CDIGITIZER_MEMBER_FUNCS_INTERFACE) */
    {
        tUnsigned value = 0;
#if !defined(CDIGITIZER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count;
        tWhat c;

        digits = 0;
        if ((0 < length) && (vUndefinedLength != length))
        for (count = 0; count < length; count++)
            Digitize(digits, value, (c = what[count]));
        else
        for (count = 0; (c = what[count]) != vEndWhat; count++)
            Digitize(digits, value, c);
#else /* !defined(CDIGITIZER_MEMBER_FUNCS_IMPLEMENT) */
        digits = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDIGITIZER_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CDIGITIZER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CDIGITIZER_MEMBER_FUNCS_ONLY) 
    /**
     **********************************************************************
     * Function: Digitize
     *
     *   Author: $author$
     *     Date: 3/3/2009
     **********************************************************************
     */
    inline bool Digitize
    (tLength& digits, tSigned& value, tWhat c)
    {
        bool isDigit;
        tWhat d;
        if ((isDigit = (c >= '0') && (c <= '9')))
        {
            value = (value*10) + (d = (c - '0'));
            if (d || digits)
                digits++;
        }
        return isDigit;
    }
    /**
     **********************************************************************
     * Function: Digitize
     *
     *   Author: $author$
     *     Date: 3/3/2009
     **********************************************************************
     */
    inline bool Digitize
    (tLength& digits, tUnsigned& value, tWhat c)
    {
        bool isDigit;
        tWhat d;
        if ((isDigit = (c >= '0') && (c <= '9')))
        {
            value = (value*10) + (d = (c - '0'));
            if (d || digits)
                digits++;
        }
        return isDigit;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDigitizerExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cDigitizerT<cDigitizer>
cDigitizerExtends;
/**
 **********************************************************************
 *  Class: cDigitizer
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cDigitizer
: public cDigitizerExtends
{
public:
    typedef cDigitizerExtends cExtends;
    typedef cDigitizer cDerives;
};

class cTCHARDigitizer;
/**
 **********************************************************************
 * Typedef: cTCHARDigitizerExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cDigitizerT<cTCHARDigitizer,TCHAR>
cTCHARDigitizerExtends;
/**
 **********************************************************************
 *  Class: cTCHARDigitizer
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARDigitizer
: public cTCHARDigitizerExtends
{
public:
    typedef cTCHARDigitizerExtends cExtends;
    typedef cTCHARDigitizer cDerives;
};

class cWCHARDigitizer;
/**
 **********************************************************************
 * Typedef: cWCHARDigitizerExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cDigitizerT<cWCHARDigitizer,WCHAR>
cWCHARDigitizerExtends;
/**
 **********************************************************************
 *  Class: cWCHARDigitizer
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARDigitizer
: public cWCHARDigitizerExtends
{
public:
    typedef cWCHARDigitizerExtends cExtends;
    typedef cWCHARDigitizer cDerives;
};
#else /* !defined(CDIGITIZER_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CDIGITIZER_MEMBER_FUNCS_ONLY) */
#endif /* _CDIGITIZER_HXX */

#if defined(CDIGITIZER_MEMBER_FUNCS_ONLY) 
#if defined(_CDIGITIZER_HXX_OLD) 
#undef _CDIGITIZER_HXX_OLD
#define _CDIGITIZER_HXX
#endif /* defined(_CDIGITIZER_HXX_OLD) */
#endif /* defined(CDIGITIZER_MEMBER_FUNCS_ONLY) */

/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cnamedcodedenumt.hxx
 *
 * Author: $author$
 *   Date: 1/13/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CNAMEDCODEDENUMT_HXX
#define _CNAMEDCODEDENUMT_HXX

#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cNamedCodedEnumT
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
template
<class TName,
 class TCode,
 class TEnum,
 class TCompareName,
 class TCompareCode,
 class TAs,
 class Tis=cBase>
class cNamedCodedEnumT
{
public:
    /**
     **********************************************************************
     * Function: GetNameByEnum
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    static const TName& GetNameByEnum(TEnum value)
    {
        const TName& name = GetNameNone();
        const TName *names;
        const TEnum *enums_to_names;
        bool is_sorted;

        if ((names = TAs::GetNames(is_sorted)))
        if ((enums_to_names = TAs::GetEnumsToNames()))
        if ((TAs::e_FIRST <= value) && (TAs::e_LAST >= value))
            return names[enums_to_names[value]];

        return name;
    }
    /**
     **********************************************************************
     * Function: GetCodeByEnum
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    static const TCode& GetCodeByEnum(TEnum value) 
    {
        const TCode& code = GetCodeNone();
        const TCode *codes;
        const TEnum *enums_to_codes;
        bool is_sorted;

        if ((codes = TAs::GetCodes(is_sorted)))
        if ((enums_to_codes = TAs::GetEnumsToCodes()))
        if ((TAs::e_FIRST <= value) && (TAs::e_LAST >= value))
            return codes[enums_to_codes[value]];

        return code;
    }
    /**
     **********************************************************************
     * Function: GetEnumByCode
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    static TEnum GetEnumByCode(const TCode& code) 
    {
        TEnum value;
        const TCode *codes;
        bool is_sorted;

        if ((codes = TAs::GetCodes(is_sorted)))
        {
            for (value=TAs::e_FIRST; value<TAs::e_NEXT; value++)
                if (!TCompareCode::Compare(codes[value], code))
                    return value;
        }
        return value = TAs::e_NONE;
    }
    /**
     **********************************************************************
     * Function: GetEnumByName
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    static TEnum GetEnumByName(const TName& name) 
    {
        TEnum value;
        const TName *names;
        bool is_sorted;

        if ((names = TAs::GetNames(is_sorted)))
        {
            for (value=TAs::e_FIRST; value<TAs::e_NEXT; value++)
                if (!TCompareName::Compare(names[value], name))
                    return value;
        }
        return value = TAs::e_NONE;
    }
};

#endif /* _CNAMEDCODEDENUMT_HXX */
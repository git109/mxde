/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cnamedenumt.hxx
 *
 * Author: $author$
 *   Date: 3/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CNAMEDENUMT_HXX
#define _CNAMEDENUMT_HXX

#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cNamedEnumT
 *
 * Author: $author$
 *   Date: 3/13/2004
 **********************************************************************
 */
template
<class TName, class TType,
 class TCompare, class TAs, class TIs=cBase>
class cNamedEnumT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/13/2004
     **********************************************************************
     */
    static TName *GetName(TType type)
    {
        TName **names;

        if ((names = TAs::GetNames()))
        {
            if ((TAs::e_FIRST <= type) && (TAs::e_LAST >= type))
                return names[type];

            return names[TAs::e_NONE];
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 3/13/2004
     **********************************************************************
     */
    static TType GetType(TName *name)
    {
        TName **names;
        TType type;

        if ((names = TAs::GetNames()))
        for (type = TAs::e_FIRST; type < TAs::e_NEXT; type++)
            if (!TCompare::Compare(names[type], name))
                return type;

        return TAs::e_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cCharNamedEnumT
 *
 * Author: $author$
 *   Date: 3/13/2004
 **********************************************************************
 */
template <class TType, class TAs, class TIs=cBase>
class cCharNamedEnumT
: public cNamedEnumT
  <const char, TType, TAs, TAs, TIs>
{
public:
    typedef cNamedEnumT
    <const char, TType, TAs, TAs, TIs> cIs;

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/13/2004
     **********************************************************************
     */
    static int Compare(const char *name1, const char *name2)
    {
        return strcmp(name1, name2);
    }
};

/**
 **********************************************************************
 *  Class: cCharNamedEnumValueT
 *
 * Author: $author$
 *   Date: 3/14/2004
 **********************************************************************
 */
template <class TType, class TAs, class TIs=cBase>
class cCharNamedEnumValueT
: public cCharNamedEnumT<TType, TAs, TIs>
{
public:
    typedef cCharNamedEnumT<TType, TAs, TIs> cIs;

    TType m_value;

    /**
     **********************************************************************
     * Constructor: cCharNamedEnumValueT
     *
     *      Author: $author$
     *        Date: 3/14/2004
     **********************************************************************
     */
    cCharNamedEnumValueT(TType value) 
    : m_value(value) 
    {
    }

    /**
     **********************************************************************
     * Function: SetValueByNamed
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    TType SetValueByNamed(const char *named)
    {
        TType value;

        value = this->GetType(named);
        return m_value = value;
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    TType SetValue(const char *name)
    {
        TType value;

        value = this->GetType(name);
        return m_value = value;
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    TType SetValue(TType value)
    {
        return m_value = value;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    TType GetValue() const
    {
        return m_value;
    }
    /**
     **********************************************************************
     * Function: GetNamedByValue
     *
     *   Author: $author$
     *     Date: 3/1/2006
     **********************************************************************
     */
    const char* GetNamedByValue(TType value) const
    {
        const char* named = GetName(value);
        return named;
    }
};

#endif /* ndef _CNAMEDENUMT_HXX */

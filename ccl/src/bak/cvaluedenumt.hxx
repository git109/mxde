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
 *   File: cvaluedenumt.hxx
 *
 * Author: $author$
 *   Date: 6/18/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CVALUEDENUMT_HXX
#define _CVALUEDENUMT_HXX

/**
 **********************************************************************
 *  Class: cValuedEnumT
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
template 
<class TValue, class TType,
 class TCompare, class TAs, class TIs=cBase>
class cValuedEnumT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    static TValue GetValue(TType type)
    {
        const TValue *values;

        if ((values = TAs::GetValues()))
        {
            if ((TAs::e_FIRST <= type) && (TAs::e_LAST >= type))
                return values[type];

            return values[TAs::e_NONE];
        }
        return TAs::GetValueNone();
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    static TType GetType(TValue value)
    {
        TValue *values;
        TType type;

        if ((values = TAs::GetValues()))
        for (type = TAs::e_FIRST; type < TAs::e_NEXT; type++)
            if (!TCompare::Compare(values[type], value))
                return type;

        return TAs::e_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cIntValuedEnumT
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
template <class TType, class TAs, class TIs=cBase>
class cIntValuedEnumT
: public cValuedEnumT
  <int, TType, cIntValuedEnumT, TAs, TIs>
{
public:
    typedef cValuedEnumT
    <int, TType, cIntValuedEnumT, TAs, TIs> cIs;

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    static int Compare(int value1, int value2)
    {
        return value1-value2;
    }
};

/**
 **********************************************************************
 *  Class: cIntValuedEnumValueT
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
template <class TType, class TAs, class TIs=cBase>
class cIntValuedEnumValueT
: public cIntValuedEnumT<TType, TAs, TIs>
{
public:
    typedef cIntValuedEnumT<TType, TAs, TIs> cIs;

    TType m_value;

    /**
     **********************************************************************
     * Constructor: cIntValuedEnumValueT
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cIntValuedEnumValueT(TType value) 
    : m_value(value) 
    {
    }
    /**
     **********************************************************************
     * Function: GetValued
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    int GetValued() const
    {
        return cIs::GetValue(m_value);
    }
    /**
     **********************************************************************
     * Function: SetValueByValued
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    TType SetValueByValued(int valued)
    {
        TType value;

        value = GetType(valued);
        return m_value = value;
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 10/27/2004
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
     *     Date: 10/27/2004
     **********************************************************************
     */
    TType GetValue() const
    {
        return m_value;
    }
};

#endif /* ndef _CVALUEDENUMT_HXX */

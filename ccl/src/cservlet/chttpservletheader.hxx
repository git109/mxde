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
 *   File: chttpservletheader.hxx
 *
 * Author: $author$
 *   Date: 10/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETHEADER_HXX
#define _CHTTPSERVLETHEADER_HXX

#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletHeaderT
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
template <class TAs, class TIs=cDynamicListItemT<TAs> >
class cHttpServletHeaderT
: public TIs
{
public:
    typedef TIs cIs;

    cCharString m_name, m_value;
    cHttpHeaderFieldType m_type;

    /**
     **********************************************************************
     * Constructor: cHttpServletHeaderT
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttpServletHeaderT
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error;

        if ((error = Set(name, namelen, value, valuelen)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError Set
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        if (name)
        {
            if (0 > (namelen = m_name.SetChars(name, namelen)))
                return error = -namelen;

            if ((name = m_name.GetChars(namelen)))
                m_type.SetValue(name);

            else m_type.SetValue
                 (cHttpHeaderFieldType::e_NONE);
        }

        if (value)
        if (0 > (valuelen = m_value.SetChars(value, valuelen)))
            error = -valuelen;

        return error;
    }

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetName(int &length) const
    {
        const char* chars = m_name.GetChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetValue(int &length) const
    {
        const char* chars = m_value.GetChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        int type = m_type.GetValue();
        return type;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletHeader
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cHttpServletHeader
: public cHttpServletHeaderT
  <cHttpServletHeader>
{
public:
    typedef cHttpServletHeaderT
    <cHttpServletHeader> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpServletHeader
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttpServletHeader
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    : cIs(name, namelen, value, valuelen)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletHeaderList
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cHttpServletHeaderList
: public cDynamicListT
  <cHttpServletHeader, cHttpServletHeaderList>
{
public:
    typedef cDynamicListT
    <cHttpServletHeader, cHttpServletHeaderList> cIs;
};

#endif /* ndef _CHTTPSERVLETHEADER_HXX */

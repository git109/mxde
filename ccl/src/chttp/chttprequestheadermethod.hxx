/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: chttprequestheadermethod.hxx
 *
 * Author: $author$
 *   Date: 2/5/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTHEADERMETHOD_HXX
#define _CHTTPREQUESTHEADERMETHOD_HXX

#include "chttpheaderversion.hxx"
#include "cnamedenumt.hxx"
#include "cvaluedenumt.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderMethod
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderMethod
: public cCharNamedEnumValueT
  <int, cHttpRequestHeaderMethod>
{
public:
    typedef cCharNamedEnumValueT
    <int, cHttpRequestHeaderMethod> cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/22/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_METHOD_NONE = e_NONE,
        e_METHOD_GET,
        e_METHOD_PUT,
        e_METHOD_POST,
        e_METHOD_DELETE,
        e_METHOD_TRACE,
        e_METHOD_OPTIONS,
        e_METHOD_HEAD,

        e_NEXT,
        e_LAST = e_NEXT-1,
        e_DEFAULT = e_METHOD_GET
    };

    cCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethod
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderMethod(int value=e_DEFAULT) 
    : cIs(value) 
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/1/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        int value;

        if (0 > (value = SetValue(e_DEFAULT)))
            error = -value;

        return error;
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/1/2006
     **********************************************************************
     */
    virtual int SetValue(int value)
    {
        const char* chars;
        int length;

        if ((chars = GetNamedByValue(value)))
        if (0 > (length = m_name.Copy(chars)))
            return length;

        return m_value = value;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int SetName
    (const char* chars, int length=-1) 
    {
        SetValue(e_METHOD_NONE);

        if (0 < (length = m_name.Copy(chars, length)))
        if ((chars = m_name.GetBuffer(length)))
            SetValueByNamed(chars);

        return length;
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
        const char* chars = m_name.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 10/22/2004
     **********************************************************************
     */
    static const char **GetNames()
    {
        static const char *names[e_NEXT]=
        {
            "",
            "GET",
            "PUT",
            "POST",
            "DELETE",
            "TRACE",
            "OPTIONS",
            "HEAD",
        };
        return names;
    }
};

#endif /* _CHTTPREQUESTHEADERMETHOD_HXX */

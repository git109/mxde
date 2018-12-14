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
 *   File: chttprequestheadermethodserializer.hxx
 *
 * Author: $author$
 *   Date: 2/5/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTHEADERMETHODSERIALIZER_HXX
#define _CHTTPREQUESTHEADERMETHODSERIALIZER_HXX

#include "chttpnameserializer.hxx"
#include "chttprequestheadermethod.hxx"
#include "chttpheaderversion.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderMethodSerializer
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderMethodSerializer
: public cHttpNameSerializer
{
public:
    typedef cHttpNameSerializer cIs;

    const cHttpRequestHeaderMethod& m_method;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethodSerializer
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderMethodSerializer
    (const cHttpRequestHeaderMethod& method) 
    : m_method(method) 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if ((m_chars = m_method.GetName(m_charslen)))
        {
            m_charspos = 0;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderMethodDeserializer
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderMethodDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;

    cHttpRequestHeaderMethod& m_method;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethodDeserializer
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderMethodDeserializer
    (cHttpRequestHeaderMethod& method) 
    : m_method(method)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        if (0 > (count = m_method.m_name.Clear()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 2/12/2006
     **********************************************************************
     */
    virtual int Putb(BYTE b) 
    {
        int result = b;
        const char *name;
        int length;

        switch(b)
        {
        case ' ':
            if (!(name = m_method.GetName(length)))
                return -e_ERROR_FAILED;

            m_method.SetValueByNamed(name);
            m_done = true;
            break;

        default:
            result = m_method.m_name.Putc(b);
        }
        return result;
    }
};

#endif /* _CHTTPREQUESTHEADERMETHODSERIALIZER_HXX */



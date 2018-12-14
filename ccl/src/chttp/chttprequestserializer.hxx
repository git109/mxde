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
 *   File: chttprequestserializer.hxx
 *
 * Author: $author$
 *   Date: 2/25/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTSERIALIZER_HXX
#define _CHTTPREQUESTSERIALIZER_HXX

#include "chttprequestheaderserializer.hxx"
#include "chttprequest.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestDeserializer
 *
 * Author: $author$
 *   Date: 2/25/2006
 **********************************************************************
 */
class cHttpRequestDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;

    cHttpRequest& m_request;

    cHttpRequestHeaderDeserializer m_header_deserializer;

    /**
     **********************************************************************
     * Constructor: cHttpRequestDeserializer
     *
     *      Author: $author$
     *        Date: 2/25/2006
     **********************************************************************
     */
    cHttpRequestDeserializer
    (cHttpRequest& request) 
    : m_request(request),
      m_header_deserializer(request.m_header)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if (!(error = cIs::Initialize()))
        if (!(error = m_header_deserializer.Initialize()))
        if (!(error = m_request.Initialize()))
        {
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int Deserialize
    (cInputStreamInterface& input, int length=-1, int endchar=-1) 
    {
        int result = 0;
        int count;
        eError error;

        if ((error = Initialize()))
            return result = -error;

        if (0 > (count = m_header_deserializer.Deserialize(input)))
            return count;

        result += count;

        return result;
    }
};

#endif /* _CHTTPREQUESTSERIALIZER_HXX */



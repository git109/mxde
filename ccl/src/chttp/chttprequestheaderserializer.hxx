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
 *   File: chttprequestheaderserializer.hxx
 *
 * Author: $author$
 *   Date: 2/5/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTHEADERSERIALIZER_HXX
#define _CHTTPREQUESTHEADERSERIALIZER_HXX

#include "chttpheaderfieldlistserializer.hxx"
#include "chttprequestheaderpathserializer.hxx"
#include "chttprequestheadermethodserializer.hxx"
#include "chttpheaderversionserializer.hxx"
#include "chttprequestheader.hxx"
#include "chttpserializer.hxx"
#include "chttpheaderversion.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderSerializer
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderSerializer
: public cHttpSerializer
{
public:
    typedef cHttpSerializer cIs;

    const cHttpRequestHeader& m_header;

    cHttpRequestHeaderMethodSerializer m_method_serializer;
    cHttpRequestHeaderPathSerializer m_path_serializer;
    cHttpHeaderVersionSerializer m_version_serializer;
    cHttpHeaderFieldListSerializer m_field_list_serializer;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderSerializer
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderSerializer
    (const cHttpRequestHeader& header)
    : m_header(header),
      m_method_serializer(header.m_method),
      m_path_serializer(header.m_path),
      m_version_serializer(header.m_version),
      m_field_list_serializer(header.m_field_list)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if (!(error = cIs::Initialize()))
        if (!(error = m_method_serializer.Initialize()))
        if (!(error = m_path_serializer.Initialize()))
        if (!(error = m_version_serializer.Initialize()))
        if (!(error = m_field_list_serializer.Initialize()))
        {
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output, 
     const BYTE* endchars=0, int endchars_length=-1) 
    {
        static const BYTE version_endchars[2] = {'\r','\n'};
        int result = 0;
        int count;
        eError error;

        if ((error = Initialize()))
            return result = -error;

        if (0 > (count = m_method_serializer.Serialize(output)))
            return count;

        result += count;

        if (0 > (count = m_path_serializer.Serialize(output)))
            return count;

        result += count;

        if (0 > (count = m_version_serializer.Serialize
            (output, version_endchars, sizeof(version_endchars))))
            return count;

        result += count;

        if (0 > (count = m_field_list_serializer.Serialize(output)))
            return count;

        result += count;

        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderDeserializer
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;

    cHttpRequestHeader& m_header;

    cHttpRequestHeaderMethodDeserializer m_method_deserializer;
    cHttpRequestHeaderPathDeserializer m_path_deserializer;
    cHttpHeaderVersionDeserializer m_version_deserializer;
    cHttpHeaderFieldListDeserializer m_field_list_deserializer;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderDeserializer
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderDeserializer
    (cHttpRequestHeader& header)
    : m_header(header),
      m_method_deserializer(header.m_method),
      m_path_deserializer(header.m_path),
      m_version_deserializer(header.m_version),
      m_field_list_deserializer(header.m_field_list)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if (!(error = cIs::Initialize()))
        if (!(error = m_method_deserializer.Initialize()))
        if (!(error = m_path_deserializer.Initialize()))
        if (!(error = m_version_deserializer.Initialize()))
        if (!(error = m_field_list_deserializer.Initialize()))
        {
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
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

        if (0 > (count = m_method_deserializer.Deserialize(input)))
            return count;

        result += count;

        if (0 > (count = m_path_deserializer.Deserialize(input)))
            return count;

        result += count;

        if (0 > (count = m_version_deserializer.Deserialize(input)))
            return count;

        result += count;

        if (0 > (count = m_field_list_deserializer.Deserialize(input)))
            return count;

        result += count;

        return result;
    }
};

#endif /* _CHTTPREQUESTHEADERSERIALIZER_HXX */



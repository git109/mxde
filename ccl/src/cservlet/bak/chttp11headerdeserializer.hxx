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
 *   File: chttp11headerdeserializer.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP11HEADERDESERIALIZER_HXX
#define _CHTTP11HEADERDESERIALIZER_HXX

#include "chttprequestinterface.hxx"
#include "cinputstreaminterface.hxx"
#include "chttp11header.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderVersionDeserializerT
 *
 * Author: $author$
 *   Date: 10/23/2004
 **********************************************************************
 */
template <class TIs=cImplement>
class cHttpHeaderVersionDeserializerT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersionDeserializerT
     *
     *      Author: $author$
     *        Date: 10/23/2004
     **********************************************************************
     */
    cHttpHeaderVersionDeserializerT() 
    {
    }
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface& input,
     cHttpHeaderVersion& version,
     int endchar='\n') 
    {
        enum
        {
            e_STATE_PREFIX,
            e_STATE_MAJOR,
            e_STATE_MINOR
        } state = e_STATE_PREFIX;
        eError error = e_ERROR_FAILED;
        int major_value=-1, minor_value=-1;
        int prefix_index,prefix_len,len;
        const char *prefix;
        char c;

        if (!(prefix = GetPrefix(prefix_len)))
            return error;

        prefix_index = 0;

        while (0 < (len = input.Read((BYTE*)&c, sizeof(c))))
        {
            if (0 < endchar)
            if (endchar == c)
                break;

            switch(state)
            {
            case e_STATE_PREFIX:
                if (c != prefix[prefix_index])
                {
                    if (0 < prefix_index)
                        return error;
                }
                else if (prefix_len <= ++prefix_index)
                        state = e_STATE_MAJOR;
                break;

            case e_STATE_MAJOR:
                if ((c >= '0') && (c <= '9'))
                {
                    if (major_value < 0)
                        major_value = 0;

                    major_value = major_value*10+(c-'0');
                }
                else if ('.' == c)
                        state = e_STATE_MINOR;
                break;

            case e_STATE_MINOR:
                if ((c >= '0') && (c <= '9'))
                {
                    if (minor_value < 0)
                        minor_value = 0;

                    minor_value = minor_value*10+(c-'0');
                }
                break;
            }
        }

        if ((major_value >= 0) && (minor_value >= 0))
        {
            version.Set(major_value, minor_value);
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual const char* GetPrefix(int &len) 
    {
        static const char* prefix = "HTTP/";
        len = 5;
        return prefix;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderVersionDeserializer
 *
 * Author: $author$
 *   Date: 10/23/2004
 **********************************************************************
 */
class cHttpHeaderVersionDeserializer
: public cHttpHeaderVersionDeserializerT<>
{
public:
    typedef cHttpHeaderVersionDeserializerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersionDeserializer
     *
     *      Author: $author$
     *        Date: 10/23/2004
     **********************************************************************
     */
    cHttpHeaderVersionDeserializer() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderMethodDeserializerT
 *
 * Author: $author$
 *   Date: 10/22/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cHttpRequestHeaderMethodDeserializerT
: public TIs
{
public:
    typedef TIs cIs;

    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethodDeserializerT
     *
     *      Author: $author$
     *        Date: 10/22/2004
     **********************************************************************
     */
    cHttpRequestHeaderMethodDeserializerT() 
    {
    }
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/22/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface& input,
     cHttpRequestHeaderMethod& method,
     int endchar=' ') 
    {
        eError error = e_ERROR_FAILED;
        int method_value;
        int len;
        const char *value;
        char buf[1];

        if (0 > (len = m_buffer.Clear()))
            return error;

        while (0 < (len = input.Read((BYTE*)buf, sizeof(buf))))
        {
            if (0 < endchar)
            if (endchar == buf[0])
                break;

            if (0 >= (len = m_buffer.Write(buf, sizeof(buf))))
                break;
        }

        if ((value = m_buffer.GetBuffer(len)))
        if (0 < len)
        {
            method_value = method.SetValue(value);
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
 *   Date: 10/22/2004
 **********************************************************************
 */
class cHttpRequestHeaderMethodDeserializer
: public cHttpRequestHeaderMethodDeserializerT<>
{
public:
    typedef cHttpRequestHeaderMethodDeserializerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethodDeserializer
     *
     *      Author: $author$
     *        Date: 10/22/2004
     **********************************************************************
     */
    cHttpRequestHeaderMethodDeserializer() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttp11RequestHeaderDeserializerT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cImplement>
class cHttp11RequestHeaderDeserializerT
: public TIs
{
public:
    typedef TIs cIs;

    cHttpHeaderVersion m_version;
    cHttpHeaderVersionDeserializer m_version_deserializer;

    cHttpRequestHeaderMethod m_request_method;
    cHttpRequestHeaderMethodDeserializer m_request_method_deserializer;

    /**
     **********************************************************************
     * Constructor: cHttp11RequestHeaderDeserializerT
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cHttp11RequestHeaderDeserializerT()
    : m_version(0,0)
    {
    }
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface& input, 
     cHttpRequestInterface& request) 
    {
        eError error = e_ERROR_FAILED;

        if (!(error = m_request_method_deserializer
            .Deserialize(input, m_request_method)))

        if (!(error = m_version_deserializer
            .Deserialize(input, m_version)))
        {
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttp11RequestHeaderDeserializer
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class cHttp11RequestHeaderDeserializer
: public cHttp11RequestHeaderDeserializerT<>
{
public:
    typedef cHttp11RequestHeaderDeserializerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttp11RequestHeaderDeserializer
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cHttp11RequestHeaderDeserializer() 
    {
    }
};

#endif /* ndef _CHTTP11HEADERDESERIALIZER_HXX */

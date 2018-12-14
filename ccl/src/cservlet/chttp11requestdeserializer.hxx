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
 *   File: chttp11requestdeserializer.hxx
 *
 * Author: $author$
 *   Date: 10/24/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP11REQUESTDESERIALIZER_HXX
#define _CHTTP11REQUESTDESERIALIZER_HXX

#include "cinputstreamdeserializerinterface.hxx"
#include "cconnectioninterface.hxx"
#include "chttprequestinterface.hxx"
#include "cinputstreaminterface.hxx"
#include "chttp11header.hxx"

/**
 **********************************************************************
 *  Class: cHttp11RequestDeserializerT
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cInputStreamDeserializerInterface, 
 class TIs=cHttpRequestHeader>

class cHttp11RequestDeserializerT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cConnectionInterface &m_connection;
    cHttpRequestInterface& m_request;

    /**
     **********************************************************************
     * Constructor: cHttp11RequestDeserializerT
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttp11RequestDeserializerT
    (cConnectionInterface &connection,
     cHttpRequestInterface& request)
    : m_connection(connection),
      m_request(request)
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
    (cInputStreamInterface& input, int endchar=-1) 
    {
        eError error = e_ERROR_FAILED;

        m_connection.SetKeepAlive(false);

        if (!(error = m_request.ClearHeaders()))
        if (!(error = cIs::Deserialize(input, endchar)))
        {
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMethod
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnMethod
    (cHttpRequestHeaderMethod &method) 
    {
        eError error = e_ERROR_NONE;
        int method_value = method.GetValue();

        method_value = m_request.SetMethod(method_value);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPath
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnPath
    (cHttpRequestHeaderPath &path) 
    {
        eError error = e_ERROR_FAILED;
        const char *buf;
        int len;

        if ((buf = path.GetChars(len)))
        if (0 < (len = m_request.SetPathInfo(buf, len)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnCloseConnectionField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnCloseConnectionField() 
    {
        eError error = e_ERROR_NONE;
        m_connection.SetKeepAlive(false);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnKeepAliveConnectionField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnKeepAliveConnectionField() 
    {
        eError error = e_ERROR_NONE;
        m_connection.SetKeepAlive(true);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnContentTypeField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnContentTypeField
    (const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        m_request.SetContentType(value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnContentLengthField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnContentLengthField
    (const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        m_request.SetContentLength(atoi(value));
        return error;
    }
    /**
     **********************************************************************
     * Function: OnChunkedTransferEncodingField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnChunkedTransferEncodingField()
    {
        eError error = e_ERROR_NONE;
        m_request.SetIsChunkedContent(true);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnField
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnField
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        if (!(error = cIs::OnField
            (name, namelen, value, valuelen)))
            error = m_request.AddHeader
            (name, namelen, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError OnEnd(const char *chars, int length) 
    {
        eError error = e_ERROR_NONE;
        m_request.SetHeaderChars(chars, length);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttp11RequestDeserializer
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cHttp11RequestDeserializer
: public cHttp11RequestDeserializerT<>
{
public:
    typedef cHttp11RequestDeserializerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttp11RequestDeserializer
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttp11RequestDeserializer
    (cConnectionInterface &connection,
     cHttpRequestInterface& request)
    : cIs(connection, request)
    {
    }
};

#endif /* ndef _CHTTP11REQUESTDESERIALIZER_HXX */

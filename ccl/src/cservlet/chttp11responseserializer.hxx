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
 *   File: chttp11responseserializer.hxx
 *
 * Author: $author$
 *   Date: 11/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP11RESPONSESERIALIZER_HXX
#define _CHTTP11RESPONSESERIALIZER_HXX

#include "coutputstreamserializerinterface.hxx"
#include "cconnectioninterface.hxx"
#include "chttpresponseinterface.hxx"
#include "coutputstreaminterface.hxx"
#include "chttp11header.hxx"

/**
 **********************************************************************
 *  Class: cHttp11ResponseSerializerT
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cOutputStreamSerializerInterface, 
 class TIs=cHttpResponseHeader>

class cHttp11ResponseSerializerT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cConnectionInterface &m_connection;
    cHttpResponseInterface &m_response;

    /**
     **********************************************************************
     * Constructor: cHttp11ResponseSerializerT
     *
     *      Author: $author$
     *        Date: 11/5/2004
     **********************************************************************
     */
    cHttp11ResponseSerializerT
    (cConnectionInterface &connection,
     cHttpResponseInterface& response)
    : m_connection(connection),
      m_response(response) 
    {
    }
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output, 
     const BYTE* endchars=0, int endchars_length=-1) 
    {
        int result = -e_ERROR_FAILED;
        eHttpResponseHeaderStatus status;
        eError error;
        const char *chars;
        int length;

        if (m_response.IsCommitted())
            return 0;

        if ((error = this->ClearFields()))
            return result;

        status = m_response.GetStatus();
        this->SetStatus(status);
/*
        if (cHttpResponseHeaderStatus::e_STATUS_OK != status)
            m_connection.SetKeepAlive(false);
*/
        this->AddConnectionCloseField();

        if (m_response.IsChunkedContent())
            this->AddTransferEncodingChunkedField();

        else if (0 < (length = m_response.GetContentLength()))
                this->AddContentLengthField(length);
        
        if ((chars = m_response.GetContentType(length)))
        if (0 < length)
            this->AddContentTypeField(chars, length);
/*
        if (m_connection.KeepAlive())
            AddConnectionKeepAliveField();
*/
        if (0 < (result = cIs::Serialize
            (output, endchars, endchars_length)))
            m_response.SetIsCommitted();

        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttp11ResponseSerializer
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
class cHttp11ResponseSerializer
: public cHttp11ResponseSerializerT<>
{
public:
    typedef cHttp11ResponseSerializerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttp11ResponseSerializer
     *
     *      Author: $author$
     *        Date: 11/5/2004
     **********************************************************************
     */
    cHttp11ResponseSerializer
    (cConnectionInterface &connection,
     cHttpResponseInterface& response)
    : cIs(connection, response) 
    {
    }
};

#endif /* ndef _CHTTP11RESPONSESERIALIZER_HXX */

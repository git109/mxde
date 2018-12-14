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
 *   File: chttpresponseoutputstream.hxx
 *
 * Author: $author$
 *   Date: 11/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPRESPONSEOUTPUTSTREAM_HXX
#define _CHTTPRESPONSEOUTPUTSTREAM_HXX

#include "coutputstreamserializerinterface.hxx"
#include "chttpresponseinterface.hxx"
#include "coutputstream.hxx"

/**
 **********************************************************************
 *  Class: cHttpResponseOutputStreamT
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
template 
<class THttpResponseInterface=cHttpResponseInterface,
 class TOutputStreamInterface=cOutputStreamInterface, 
 class TOutputStreamSerializerInterface=cOutputStreamSerializerInterface, 
 class TIs=cOutputStream>

class cHttpResponseOutputStreamT
: public TIs
{
public:
    typedef TIs cIs;

    THttpResponseInterface &m_response;
    TOutputStreamSerializerInterface &m_response_serializer;
    TOutputStreamInterface &m_output;
    TOutputStreamInterface *m_response_output;

    /**
     **********************************************************************
     * Constructor: cHttpResponseOutputStreamT
     *
     *      Author: $author$
     *        Date: 11/7/2004
     **********************************************************************
     */
    cHttpResponseOutputStreamT
    (THttpResponseInterface &response,
     TOutputStreamSerializerInterface &response_serializer,
     TOutputStreamInterface &output)
    : m_response(response),
      m_response_serializer(response_serializer),
      m_output(output) 
    {
        m_response_output = &m_response.GetOutputStream();
        m_response.SetOutputStream(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cHttpResponseOutputStreamT
     *
     *     Author: $author$
     *       Date: 11/7/2004
     **********************************************************************
     */
    ~cHttpResponseOutputStreamT()
    {
        m_response.SetOutputStream(m_response_output);
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/7/2004
     **********************************************************************
     */
    virtual int Write(const BYTE *buf, int len=-1) 
    {
        int result;

        if (!m_response.IsCommitted())
        if (0 > (result = m_response_serializer
            .Serialize(m_output)))
            return result;

        result = m_output.Write(buf, len);
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpResponseOutputStream
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHttpResponseOutputStream
: public cHttpResponseOutputStreamT<>
{
public:
    typedef cHttpResponseOutputStreamT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpResponseOutputStream
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cHttpResponseOutputStream
    (cHttpResponseInterface &response,
     cOutputStreamSerializerInterface &response_serializer,
     cOutputStreamInterface &output)
    : cIs(response, response_serializer, output) 
    {
    }
};

#endif /* ndef _CHTTPRESPONSEOUTPUTSTREAM_HXX */

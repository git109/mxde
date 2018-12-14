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
 *   File: chttprequestinputstream.hxx
 *
 * Author: $author$
 *   Date: 11/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTINPUTSTREAM_HXX
#define _CHTTPREQUESTINPUTSTREAM_HXX

#include "cinputstreamdeserializerinterface.hxx"
#include "chttprequestinterface.hxx"
#include "cinputstream.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestInputStreamT
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
template 
<class THttpRequestInterface=cHttpRequestInterface,
 class TInputStreamInterface=cInputStreamInterface, 
 class TInputStreamDeserializerInterface=cInputStreamDeserializerInterface, 
 class TIs=cInputStream>

class cHttpRequestInputStreamT
: public TIs
{
public:
    typedef TIs cIs;

    THttpRequestInterface &m_request;
    TInputStreamDeserializerInterface &m_request_deserializer;
    TInputStreamInterface &m_input;
    TInputStreamInterface *m_request_input;

    /**
     **********************************************************************
     * Constructor: cHttpRequestInputStreamT
     *
     *      Author: $author$
     *        Date: 11/7/2004
     **********************************************************************
     */
    cHttpRequestInputStreamT
    (THttpRequestInterface &request,
     TInputStreamDeserializerInterface &request_deserializer,
     TInputStreamInterface &input)
    : m_request(request),
      m_request_deserializer(request_deserializer),
      m_input(input) 
    {
        m_request_input = &m_request.GetInputStream();
        m_request.SetInputStream(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cHttpRequestInputStreamT
     *
     *     Author: $author$
     *       Date: 11/7/2004
     **********************************************************************
     */
    virtual ~cHttpRequestInputStreamT()
    {
        m_request.SetInputStream(m_request_input);
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/7/2004
     **********************************************************************
     */
    virtual int Read(BYTE *buf, int len=-1) 
    {
        int result = -e_ERROR_FAILED;
        result = m_input.Read(buf, len);
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestInputStream
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
class cHttpRequestInputStream
: public cHttpRequestInputStreamT<>
{
public:
    typedef cHttpRequestInputStreamT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpRequestInputStream
     *
     *      Author: $author$
     *        Date: 11/7/2004
     **********************************************************************
     */
    cHttpRequestInputStream
    (cHttpRequestInterface &request,
     cInputStreamDeserializerInterface &request_deserializer,
     cInputStreamInterface &input) 
    : cIs(request, request_deserializer, input) 
    {
    }
};

#endif /* ndef _CHTTPREQUESTINPUTSTREAM_HXX */

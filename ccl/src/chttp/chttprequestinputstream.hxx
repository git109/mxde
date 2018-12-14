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
 *   File: chttprequestinputstream.hxx
 *
 * Author: $author$
 *   Date: 3/2/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTINPUTSTREAM_HXX
#define _CHTTPREQUESTINPUTSTREAM_HXX

#include "chttprequestinterface.hxx"
#include "cinputstream.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestInputStreamT
 *
 * Author: $author$
 *   Date: 3/2/2006
 **********************************************************************
 */
template
<class THttpRequestInterface=cHttpRequestInterface,
 class TInputStreamInterface=cInputStreamInterface, 
 class TIs=cInputStream>

class cHttpRequestInputStreamT
: public TIs
{
public:
    typedef TIs cIs;

    THttpRequestInterface &m_request;
    TInputStreamInterface &m_input;
    TInputStreamInterface *m_request_input;

    /**
     **********************************************************************
     * Constructor: cHttpRequestInputStreamT
     *
     *      Author: $author$
     *        Date: 3/2/2006
     **********************************************************************
     */
    cHttpRequestInputStreamT
    (THttpRequestInterface &request,
     TInputStreamInterface &input)
    : m_request(request),
      m_input(input),
      m_request_input(&request.GetContentInputStream()) 
    {
        m_request.SetContentInputStream(this);
    }
    /**
     **********************************************************************
     *  Destructor: ~cHttpRequestInputStreamT
     *
     *      Author: $author$
     *        Date: 3/2/2006
     **********************************************************************
     */
    virtual ~cHttpRequestInputStreamT()
    {
        m_request.SetContentInputStream(m_request_input);
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/2/2006
     **********************************************************************
     */
    virtual int Read(BYTE *buf, int len=-1) 
    {
        if (0 >= (len = m_input.Read(buf, len)))
            m_request.SetContentIsConsumed(true);
        return len;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestInputStream
 *
 * Author: $author$
 *   Date: 3/2/2006
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
     *        Date: 3/2/2006
     **********************************************************************
     */
    cHttpRequestInputStream
    (cHttpRequestInterface &request,
     cInputStreamInterface &input) 
    : cIs(request, input) 
    {
    }
};

#endif /* _CHTTPREQUESTINPUTSTREAM_HXX */

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
 *   File: chttprequestlengthinputstream.hxx
 *
 * Author: $author$
 *   Date: 3/3/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTLENGTHINPUTSTREAM_HXX
#define _CHTTPREQUESTLENGTHINPUTSTREAM_HXX

#include "chttprequestinputstream.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestLengthInputStream
 *
 * Author: $author$
 *   Date: 3/3/2006
 **********************************************************************
 */
class cHttpRequestLengthInputStream
: public cHttpRequestInputStream
{
public:
    typedef cHttpRequestInputStream cIs;

    int m_length;

    /**
     **********************************************************************
     * Constructor: cHttpRequestLengthInputStream
     *
     *      Author: $author$
     *        Date: 3/3/2006
     **********************************************************************
     */
    cHttpRequestLengthInputStream
    (cHttpRequestInterface &request,
     cInputStreamInterface &input,
     int length) 
    : cIs(request, input),
      m_length(length) 
    {
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
        if (0 >= len)
            return len;

        if (len > m_length)
        if (1 > (len = m_length))
            return len;

        if (0 < (len = m_input.Read(buf, len)))
        if (1 > (m_length -= len))
            m_request.SetContentIsConsumed(true);

        return len;
    }
};

#endif /* _CHTTPREQUESTLENGTHINPUTSTREAM_HXX */



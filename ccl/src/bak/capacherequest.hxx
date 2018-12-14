/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: capacherequest.hxx
 *
 * Author: $author$
 *   Date: 1/2/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CAPACHEREQUEST_HXX
#define _CAPACHEREQUEST_HXX

#include "capache.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cApacheRequestHeaderField
 *
 * Author: $author$
 *   Date: 1/1/2005
 **********************************************************************
 */
class cApacheRequestHeaderField
{
public:
    request_rec &m_request;
    cCharBuffer m_name_buffer;
    const char *m_name;
    int m_namelen;

    /**
     **********************************************************************
     * Constructor: cApacheRequestHeaderField
     *
     *      Author: $author$
     *        Date: 1/1/2005
     **********************************************************************
     */
    cApacheRequestHeaderField
    (request_rec &request, const char *name, int namelen=-1) 
    : m_request(request),
      m_name(""),
      m_namelen(0)
    {
        eError error;

        if (0 > (namelen = SetName(name, namelen)))
            throw (error = -namelen);
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 1/1/2005
     **********************************************************************
     */
    virtual int SetName
    (const char* chars, int length=-1) 
    {
        if (0 >= (length = m_name_buffer.Copy(chars, length)))
            length = -e_ERROR_FAILED;
        else m_name = m_name_buffer.GetBuffer(m_namelen);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 1/1/2005
     **********************************************************************
     */
    virtual const char* GetValue(int &length) const
    {
        const char* chars = 0;
        length = 0;

        if ((chars = ap_table_get
            (m_request.headers_in, m_name)))
            length = strlen(chars);

        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cApacheRequestContentType
 *
 * Author: $author$
 *   Date: 1/2/2005
 **********************************************************************
 */
class cApacheRequestContentType
: public cApacheRequestHeaderField
{
public:
    typedef cApacheRequestHeaderField cIs;

    /**
     **********************************************************************
     * Constructor: cApacheRequestContentType
     *
     *      Author: $author$
     *        Date: 1/2/2005
     **********************************************************************
     */
    cApacheRequestContentType(request_rec &request)
    : cIs(request, "Content-Type")
    {
    }
};

/**
 **********************************************************************
 *  Class: cApacheRequestContent
 *
 * Author: $author$
 *   Date: 1/2/2005
 **********************************************************************
 */
class cApacheRequestContent
: public cCharStream
{
public:
    typedef cCharStream cIs;

    request_rec &m_request;

    /**
     **********************************************************************
     * Constructor: cApacheRequestContent
     *
     *      Author: $author$
     *        Date: 1/2/2005
     **********************************************************************
     */
    cApacheRequestContent(request_rec &request) 
    : m_request(request)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/2/2005
     **********************************************************************
     */
    virtual int Read(char *buffer, int size) 
    {
        int length;
        
        if (0 > (length = ap_get_client_block
            (&m_request, buffer, size)))
            length = -e_ERROR_ENDOF;

        ap_reset_timeout(&m_request);
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/2/2005
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1) 
    {
        int length;
        
        if (0 > size)
            size = strlen(buffer);

        if (size != (length = ap_rwrite
            (buffer, size, &m_request)))
            length = -e_ERROR_FAILED;

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cApacheRequest
 *
 * Author: $author$
 *   Date: 1/2/2005
 **********************************************************************
 */
class cApacheRequest
{
public:
    request_rec &m_request;

    /**
     **********************************************************************
     * Constructor: cApacheRequest
     *
     *      Author: $author$
     *        Date: 1/2/2005
     **********************************************************************
     */
    cApacheRequest(request_rec &request) 
    : m_request(request) 
    {
    }
};

#endif /* _CAPACHEREQUEST_HXX */
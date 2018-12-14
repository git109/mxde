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
 *   File: cbytestreamproxy.hxx
 *
 * Author: $author$
 *   Date: 1/28/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMPROXY_HXX
#define _CBYTESTREAMPROXY_HXX

#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamProxy
 *
 * Author: $author$
 *   Date: 1/28/2005
 **********************************************************************
 */
class cBYTEStreamProxy
: public cBYTEStream
{
public:
    typedef cBYTEStream cIs;

    cBYTEStreamInterface &m_stream;
    int m_length, m_tell;

    /**
     **********************************************************************
     * Constructor: cBYTEStreamProxy
     *
     *      Author: $author$
     *        Date: 1/28/2005
     **********************************************************************
     */
    cBYTEStreamProxy
    (cBYTEStreamInterface &stream, 
     int length=-1, int tell=0) 
    : m_stream(stream),
      m_length(length),
      m_tell(tell)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/28/2004
     **********************************************************************
     */
    virtual int Read
    (BYTE *buffer,  int size=-1) 
    {
        int result;

        if (!m_length)
            return -e_ERROR_ENDOF;

        if (0 > size)
            size = strlen((const char*)buffer);

        if (0 < m_length)
        if (m_length < m_tell+size)
        if (m_length > m_tell)
            size = m_length-m_tell;
        else return -e_ERROR_ENDOF;

        if (0 < (result = m_stream.Read(buffer, size)))
        if (0 < m_length)
            m_tell += result;

        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/28/2004
     **********************************************************************
     */
    virtual int Write
    (const BYTE *buffer,  int size=-1) 
    {
        int result;

        if (!m_length)
            return -e_ERROR_ENDOF;

        if (0 > size)
            size = strlen((const char*)buffer);

        if (0 < m_length)
        if (m_length < m_tell+size)
        if (m_length > m_tell)
            size = m_length-m_tell;
        else return -e_ERROR_ENDOF;

        if (0 < (result = m_stream.Write(buffer, size)))
        if (0 < m_length)
            m_tell += result;

        return result;
    }
};

#endif /* _CBYTESTREAMPROXY_HXX */
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
 *   File: chttprequestchunkedinputstream.hxx
 *
 * Author: $author$
 *   Date: 3/2/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTCHUNKEDINPUTSTREAM_HXX
#define _CHTTPREQUESTCHUNKEDINPUTSTREAM_HXX

#include "chttprequestinputstream.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestChunkedInputStream
 *
 * Author: $author$
 *   Date: 3/2/2006
 **********************************************************************
 */
class cHttpRequestChunkedInputStream
: public cHttpRequestInputStream
{
public:
    typedef cHttpRequestInputStream cIs;

    int m_chunk_size, m_chunk_remain;

    /**
     **********************************************************************
     * Constructor: cHttpRequestChunkedInputStream
     *
     *      Author: $author$
     *        Date: 3/2/2006
     **********************************************************************
     */
    cHttpRequestChunkedInputStream
    (cHttpRequestInterface &request,
     cInputStreamInterface &input) 
    : cIs(request, input),
      m_chunk_size(-1),
      m_chunk_remain(-1)
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
        int count, length;

        if (0 > m_chunk_remain)
        {
            if (0 > (count = ReadChunkBegin()))
                return count;
        }
        else if (1 > m_chunk_remain)
        {
            if (0 > (count = ReadChunkBetween()))
                return count;
        }

        length = ReadChunkRemain(buf, len);
        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkRemain
     *
     *   Author: $author$
     *     Date: 3/3/2006
     **********************************************************************
     */
    virtual int ReadChunkRemain(BYTE *buf, int len)
    {
        int count, remain, length=0;

        do
        {
            if ((remain = (len > m_chunk_remain)))
            {
                remain = len-m_chunk_remain;
                len = m_chunk_remain;
            }

            if (len > (count = m_input.Read(buf, len)))
                m_request.SetContentIsConsumed(true);

            if (0 > count)
                return count;

            m_chunk_remain -= count;
            length += count;
            buf += count;

            if (remain)
            {
                if (0 > (count = ReadChunkBetween()))
                    return length;

                len = remain;
            }
        }
        while (remain);

        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkBetween
     *
     *   Author: $author$
     *     Date: 3/3/2006
     **********************************************************************
     */
    virtual int ReadChunkBetween()
    {
        int count;

        if (0 > (count = ReadChunkEnd()))
            return count;

        if (0 > (count = ReadChunkBegin()))
            return count;

        if (1 > m_chunk_remain)
            return -e_ERROR_ENDOF;

        return count;
    }
    /**
     **********************************************************************
     * Function: ReadChunkBegin
     *
     *   Author: $author$
     *     Date: 3/3/2006
     **********************************************************************
     */
    virtual int ReadChunkBegin()
    {
        int count, length=0;
        BYTE c;

        m_chunk_size = 0;
        m_chunk_remain = -1;

        do
        {
            if (((int)sizeof(c)) > (count = m_input.Read(&c, sizeof(c))))
            {
                m_request.SetContentIsConsumed(true);

                if (0 > count)
                    return count;

                return -e_ERROR_ENDOF;
            }

            if (('0' <= c) && ('9' >= c))
                m_chunk_size = (m_chunk_size<<4)+(c-'0');

            else if (('A' <= c) && ('F' >= c))
                    m_chunk_size = (m_chunk_size<<4)+(c-'A')+10;

            else if (('a' <= c) && ('f' >= c))
                    m_chunk_size = (m_chunk_size<<4)+(c-'a')+10;

            else if ('\n' == c)
            {
                m_chunk_remain = m_chunk_size;
                break;
            }

            else continue;

            length++;
        }
        while (0 <= c);

        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkEnd
     *
     *   Author: $author$
     *     Date: 3/3/2006
     **********************************************************************
     */
    virtual int ReadChunkEnd()
    {
        int count, length=0;
        BYTE c;

        do
        {
            if (((int)sizeof(c)) > (count = m_input.Read(&c, sizeof(c))))
            {
                m_request.SetContentIsConsumed(true);

                if (0 > count)
                    return count;

                return -e_ERROR_ENDOF;
            }

            if ('\n' == c)
                break;
        }
        while (0 <= c);

        return length;
    }
};

#endif /* _CHTTPREQUESTCHUNKEDINPUTSTREAM_HXX */



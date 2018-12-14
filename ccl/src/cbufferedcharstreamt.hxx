/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cbufferedcharstreamt.hxx
 *
 * Author: $author$
 *   Date: 8/16/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBUFFEREDCHARSTREAMT_HXX
#define _CBUFFEREDCHARSTREAMT_HXX

#define CBUFFEREDCHARSTREAMT_BUFFER_SIZE 1024

#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cBufferedCharStreamT
 *
 * Author: $author$
 *   Date: 8/16/2003
 **********************************************************************
 */
template <int VBufferSize = CBUFFEREDCHARSTREAMT_BUFFER_SIZE>
class cBufferedCharStreamT
: public cCharStream
{
public:
    typedef cCharStream cIs;

    cCharStream &m_stream;
    int m_length;
    int m_read_length;
    int m_read_buffer_tell;
    int m_read_buffer_length;
    int m_read_buffer_size;
    char m_read_buffer[VBufferSize];

    /**
     **********************************************************************
     * Constructor: cBufferedCharStreamT
     *
     *      Author: $author$
     *        Date: 8/16/2003
     **********************************************************************
     */
    cBufferedCharStreamT(cCharStream &stream, int length=-1)
    : m_stream(stream),
      m_length(length),
      m_read_length(0),
      m_read_buffer_tell(0),
      m_read_buffer_length(0),
      m_read_buffer_size(VBufferSize)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 8/16/2003
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        int count, result = 0;

        while ((count = ReadFromBuffer(buffer, size)) > 0)
        {
            result += count;
            buffer += count;

            if ((size -= count) < 1)
                break;
        }

        if (result < 1)
            return -e_ERROR_ENDOF;

        return result;
    }
    /**
     **********************************************************************
     * Function: ReadFromBuffer
     *
     *   Author: $author$
     *     Date: 8/16/2003
     **********************************************************************
     */
    virtual int ReadFromBuffer(char *buffer, int size)
    {
        int count;

        if (size < 0)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        if (m_read_buffer_length < 1)
        {
            count = m_read_buffer_size;

            if (m_length > 0)
            if (m_read_length >= m_length)
                return -e_ERROR_ENDOF;

            else if ((m_read_length + count) > m_length)
                    count = m_length - m_read_length;

            if ((count = m_stream.Read(m_read_buffer, count)) < 0)
                return count;

            m_read_buffer_tell = 0;
            m_read_length += (m_read_buffer_length = count);
        }

        if (size > m_read_buffer_length)
            size = m_read_buffer_length;

        memcpy(buffer, m_read_buffer + m_read_buffer_tell, size);

        m_read_buffer_tell += size;
        m_read_buffer_length -= size;
        return size;
    }
};


#endif

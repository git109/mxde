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
 *   File: chttpresponsewriter.hxx
 *
 * Author: $author$
 *   Date: 10/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPRESPONSEWRITER_HXX
#define _CHTTPRESPONSEWRITER_HXX

#include "coutputstreamserializerinterface.hxx"
#include "coutputstreaminterface.hxx"
#include "ccharwriterinterface.hxx"
#include "chttpresponseinterface.hxx"
#include "ccharwriter.hxx"

#define CHTTPRESPONSEWRITER_DEFAULT_BUFFER_SIZE 4096

/**
 **********************************************************************
 *  Class: cHttpResponseWriterT
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
template 
<class THttpResponseInterface=cHttpResponseInterface,
 class TOutputStreamInterface=cOutputStreamInterface, 
 class TOutputStreamSerializerInterface=cOutputStreamSerializerInterface, 
 class TIs=cCharWriter>

class cHttpResponseWriterT
: public TIs
{
public:
    typedef TIs cIs;

    THttpResponseInterface &m_response;
    TOutputStreamSerializerInterface &m_response_serializer;
    TOutputStreamInterface &m_output;

    cCharWriterInterface* m_response_writer;
    int m_buffer_size, m_buffer_length;
    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cHttpResponseWriterT
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpResponseWriterT
    (THttpResponseInterface &response,
     TOutputStreamSerializerInterface &response_serializer,
     TOutputStreamInterface &output,
     int buffer_size=CHTTPRESPONSEWRITER_DEFAULT_BUFFER_SIZE)
    : m_response(response),
      m_response_serializer(response_serializer),
      m_output(output),
      m_buffer_size(buffer_size),
      m_buffer_length(0)
    {
        m_response_writer = &m_response.GetWriter();
        m_response.SetWriter(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cHttpResponseWriterT
     *
     *     Author: $author$
     *       Date: 10/27/2004
     **********************************************************************
     */
    virtual ~cHttpResponseWriterT()
    {
        m_response.SetWriter(m_response_writer);
    }

    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 11/14/2004
     **********************************************************************
     */
    virtual int Flush() 
    {
        int count, length, result = 0;
        const char *chars;

        if ((chars = m_buffer.GetBuffer(length)))
        if (0 < length)
        {
            if (m_response.IsCommitted())
            {
                result = -e_ERROR_FAILED;

                if (m_response.IsChunkedContent())
                if (0 < (count = WriteChunk(chars, length)))
                    result = count;
            }
            else if (m_response.IsChunkedContent())
            {
                if (0 < (result = m_response_serializer
                    .Serialize(m_output)))
                    result = WriteChunk(chars, length);
            }
            else
            {
                m_response.SetContentLength(length);

                if (0 < (result = m_response_serializer
                    .Serialize(m_output)))
                    result = m_output.Write
                    ((const BYTE*)chars, length);
            }

            m_buffer_length = 0;
            m_buffer.Clear();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Write(const char *buf,  int len=-1) 
    {
        int count, length, result = 0;

        if (0 > len)
            len = strlen(buf);

        do
        {
            length = m_buffer_length + (count = len);

            if (m_buffer_size < length)
                count = m_buffer_size - m_buffer_length;

            if (0 > (count = m_buffer.Write
                (buf+result, count)))
                return count;

            len -= count;
            result += count;
            m_buffer_length += count;

            if (m_buffer_size <= length)
            {
                m_response.SetIsChunkedContent(true);

                if (0 > (count = Flush()))
                    return count;
            }
        }
        while (0 < len);

        return result;
    }
    /**
     **********************************************************************
     * Function: WriteChunk
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual int WriteChunk(const char *buf,  int len=-1) 
    {
        int chunk, count, length, result = -e_ERROR_FAILED;
        char x;

        if (0 > (length = len))
            length = (len = strlen(buf));

        for (chunk=0; 0<length; length>>=8)
            chunk = (chunk << 8) | (length & 255);

        if (1 < chunk)
        {
            result = 0;

            do
            {
                x = (chunk & 15);
                x = ((x<=9)?(x+'0'):(x-10+'a'));
                chunk >>= 4;

                if (0 > (count = m_output.Write
                    ((const BYTE*)&x, sizeof(x))))
                    return count;

                result += count;
            }
            while (0 < chunk);

            if (0 > (count = m_output.Write
                ((const BYTE*)"\r\n")))
                return count;

            result += count;

            if (0 > (count = m_output.Write
                ((const BYTE*)buf, len)))
                return count;

            result += count;

            if (0 > (count = m_output.Write
                ((const BYTE*)"\r\n")))
                return count;

            result += count;
        }
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpResponseWriter
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
class cHttpResponseWriter
: public cHttpResponseWriterT<>
{
public:
    typedef cHttpResponseWriterT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpResponseWriter
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpResponseWriter
    (cHttpResponseInterface &response,
     cOutputStreamSerializerInterface &response_serializer,
     cOutputStreamInterface &output,
     int buffer_size=CHTTPRESPONSEWRITER_DEFAULT_BUFFER_SIZE)
    : cIs(response, response_serializer, output, buffer_size) 
    {
    }
};

#endif /* ndef _CHTTPRESPONSEWRITER_HXX */

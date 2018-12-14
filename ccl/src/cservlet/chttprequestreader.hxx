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
 *   File: chttprequestreader.hxx
 *
 * Author: $author$
 *   Date: 11/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTREADER_HXX
#define _CHTTPREQUESTREADER_HXX

#include "cinputstreamdeserializerinterface.hxx"
#include "chttprequestinterface.hxx"
#include "ccharreader.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestReaderT
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
template 
<class THttpRequestInterface=cHttpRequestInterface,
 class TInputStreamInterface=cInputStreamInterface, 
 class TInputStreamDeserializerInterface=cInputStreamDeserializerInterface, 
 class TIs=cCharReader>

class cHttpRequestReaderT
: public TIs
{
public:
    typedef TIs cIs;

    THttpRequestInterface &m_request;
    TInputStreamDeserializerInterface &m_request_deserializer;
    TInputStreamInterface &m_input;

    cCharReaderInterface* m_request_reader;

    /**
     **********************************************************************
     * Constructor: cHttpRequestReaderT
     *
     *      Author: $author$
     *        Date: 11/7/2004
     **********************************************************************
     */
    cHttpRequestReaderT
    (THttpRequestInterface &request,
     TInputStreamDeserializerInterface &request_deserializer,
     TInputStreamInterface &input)
    : m_request(request),
      m_request_deserializer(request_deserializer),
      m_input(input) 
    {
        m_request_reader = &m_request.GetReader();
        m_request.SetReader(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cHttpRequestReaderT
     *
     *     Author: $author$
     *       Date: 11/7/2004
     **********************************************************************
     */
    virtual ~cHttpRequestReaderT()
    {
        m_request.SetReader(m_request_reader);
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/7/2004
     **********************************************************************
     */
    virtual int Read(char *buf, int len=-1) 
    {
        int result;
        result = m_input.Read((BYTE*)buf, len);
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestReader
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
class cHttpRequestReader
: public cHttpRequestReaderT<>
{
public:
    typedef cHttpRequestReaderT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpRequestReader
     *
     *      Author: $author$
     *        Date: 11/7/2004
     **********************************************************************
     */
    cHttpRequestReader
    (cHttpRequestInterface &request,
     cInputStreamDeserializerInterface &request_deserializer,
     cInputStreamInterface &input) 
    : cIs(request, request_deserializer, input) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestLengthReader
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttpRequestLengthReader
: public cHttpRequestReader
{
public:
    typedef cHttpRequestReader cIs;

    int m_length;

    /**
     **********************************************************************
     * Constructor: cHttpRequestLengthReader
     *
     *      Author: $author$
     *        Date: 11/11/2004
     **********************************************************************
     */
    cHttpRequestLengthReader
    (cHttpRequestInterface &request,
     cInputStreamDeserializerInterface &request_deserializer,
     cInputStreamInterface &input,
     int length) 
    : cIs(request, request_deserializer, input),
      m_length(length)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual int Read(char *buf, int len=-1) 
    {
        if (0 >= len)
            return len;

        if (len > m_length)
        if (1 > (len = m_length))
            return len;

        if (0 < (len = m_input.Read((BYTE*)buf, len)))
        if (1 > (m_length -= len))
            m_request.SetIsConsumed(true);

        return len;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestChunkedReader
 *
 * Author: $author$
 *   Date: 11/10/2004
 **********************************************************************
 */
class cHttpRequestChunkedReader
: public cHttpRequestReader
{
public:
    typedef cHttpRequestReader cIs;

    int m_chunk_size,m_chunk_remain;

    /**
     **********************************************************************
     * Constructor: cHttpRequestChunkedReader
     *
     *      Author: $author$
     *        Date: 11/10/2004
     **********************************************************************
     */
    cHttpRequestChunkedReader
    (cHttpRequestInterface &request,
     cInputStreamDeserializerInterface &request_deserializer,
     cInputStreamInterface &input) 
    : cIs(request, request_deserializer, input),
      m_chunk_size(-1),
      m_chunk_remain(-1)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual int Read(char *buf, int len=-1) 
    {
        int count,length=0;

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

        length = ReadChunkRemain((BYTE*)buf, len);
        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkRemain
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int ReadChunkRemain(BYTE *buf, int len)
    {
        int count,remain,length=0;

        do
        {
            if ((remain = (len > m_chunk_remain)))
            {
                remain = len-m_chunk_remain;
                len = m_chunk_remain;
            }

            if (len > (count = m_input.Read(buf, len)))
                m_request.SetIsConsumed(true);

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
     *     Date: 11/11/2004
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
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual int ReadChunkBegin()
    {
        int count,length=0;
        BYTE c;

        m_chunk_size=0;
        m_chunk_remain=-1;

        do
        {
            if (((int)sizeof(c)) > (count = m_input.Read(&c, sizeof(c))))
            {
                m_request.SetIsConsumed(true);

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
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual int ReadChunkEnd()
    {
        int count,length=0;
        BYTE c;

        do
        {
            if (((int)sizeof(c)) > (count = m_input.Read(&c, sizeof(c))))
            {
                m_request.SetIsConsumed(true);

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

#endif /* ndef _CHTTPREQUESTREADER_HXX */

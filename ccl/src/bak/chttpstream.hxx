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
 *   File: chttpstream.hxx
 *
 * Author: $author$
 *   Date: 11/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSTREAM_HXX
#define _CHTTPSTREAM_HXX

#include <stdlib.h>
#include "chttpheaderparser.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cHTTPContentStream
 *
 * Author: $author$
 *   Date: 11/9/2004
 **********************************************************************
 */
class cHTTPContentStream
: public cCharStream
{
public:
    typedef cCharStream cIs;

    cCharStream &m_stream;
    int m_length;

    /**
     **********************************************************************
     * Constructor: cHTTPContentStream
     *
     *      Author: $author$
     *        Date: 11/9/2004
     **********************************************************************
     */
    cHTTPContentStream(cCharStream &stream, int length=-1) 
    : m_stream(stream),
      m_length(length)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Read
    (char *buffer,  int length=-1) 
    {
        int count = 0;

        if (0 != m_length)
        {
            if (0 > length)
                length = strlen(buffer);

            if (0 <= m_length)
            {
                if (m_length < length)
                    length = m_length;

                m_length -= length;
            }

            if (0 < length)
                count = m_stream.Read(buffer, length);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Write
    (const char *buffer,  int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPChunkedContentStream
 *
 * Author: $author$
 *   Date: 11/9/2004
 **********************************************************************
 */
class cHTTPChunkedContentStream
: public cCharStream
{
public:
    typedef cCharStream cIs;

    enum
    {
        e_STATE_SIZE,
        e_STATE_CHUNK,
        e_STATE_CHUNK_END,
        e_STATE_END,
    };

    cCharStream &m_stream;
    int m_chunk_size,m_chunk_remain,m_state;

    /**
     **********************************************************************
     * Constructor: cHTTPChunkedContentStream
     *
     *      Author: $author$
     *        Date: 11/9/2004
     **********************************************************************
     */
    cHTTPChunkedContentStream(cCharStream &stream)
    : m_stream(stream),
      m_chunk_size(0),
      m_chunk_remain(0),
      m_state(e_STATE_SIZE)
    {
    }
    /**
     **********************************************************************
     * Function: Getc
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Getc() 
    {
        int c;
        
        switch (m_state)
        {
        case e_STATE_SIZE:
            if (0 <= (c = m_stream.Getc()))
            switch(c)
            {
            case '\n':
                if (1 > m_chunk_size)
                    m_state = e_STATE_END;
                else 
                {
                    m_state = e_STATE_CHUNK;
                    m_chunk_remain = m_chunk_size;
                }
                break;

            default:
                if (('0' <= c) && ('9' >= c))
                    m_chunk_size = (m_chunk_size<<4)+(c-'0');

                else if (('A' <= c) && ('F' >= c))
                        m_chunk_size = (m_chunk_size<<4)+(c-'A')+10;

                else if (('a' <= c) && ('f' >= c))
                        m_chunk_size = (m_chunk_size<<4)+(c-'a')+10;
            }
            break;

        case e_STATE_CHUNK:
            if (0 <= (c = m_stream.Getc()))
            if (1 > --m_chunk_remain)
                m_state = e_STATE_CHUNK_END;
            break;

        case e_STATE_CHUNK_END:
            if (0 <= (c = m_stream.Getc()))
            if ('\n' == c)
            {
                m_chunk_size = 0;
                m_state = e_STATE_SIZE;
            }
            break;

        default:
            return -e_ERROR_ENDOF;
        }
        return c;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Read
    (char *buffer,  int length=-1) 
    {
        int c,result = -e_ERROR_FAILED;

        if (0 > length)
            length = strlen(buffer);

        for (result=0; result<length; result++)
        {
            if (0 > (c = Getc()))
                break;

            buffer[result] = c;
        }

        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Write
    (const char *buffer,  int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPHeaderParserStream
 *
 * Author: $author$
 *   Date: 11/9/2004
 **********************************************************************
 */
class cHTTPHeaderParserStream
: public cCharStream
{
public:
    typedef cCharStream cIs;

    /**
     **********************************************************************
     * Function: OnHeaderField
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual eError OnHeaderField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHeaderEnd
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual eError OnHeaderEnd
    (const char* chars,  int length=-1) 
    {
        eError error = -e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPHeaderStreamParser
 *
 * Author: $author$
 *   Date: 11/9/2004
 **********************************************************************
 */
class cHTTPHeaderStreamParser
: public cHTTPHeaderParser
{
public:
    typedef cHTTPHeaderParser cIs;

    cHTTPHeaderParserStream &m_stream;

    /**
     **********************************************************************
     * Constructor: cHTTPHeaderStreamParser
     *
     *      Author: $author$
     *        Date: 11/9/2004
     **********************************************************************
     */
    cHTTPHeaderStreamParser(cHTTPHeaderParserStream &stream) 
    : m_stream(stream) 
    {
    }
    /**
     **********************************************************************
     * Function: OnHeaderField
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual eError OnField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = m_stream.OnHeaderField
        (name, namelen, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual eError OnEnd
    (const char* chars,  int length=-1) 
    {
        eError error = m_stream.OnHeaderEnd(chars, length);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPHeaderStream
 *
 * Author: $author$
 *   Date: 11/9/2004
 **********************************************************************
 */
class cHTTPHeaderStream
: public cCharStream
{
public:
    typedef cCharStream cIs;

    cCharStream &m_stream;
    cHTTPHeaderStreamParser m_parser;

    /**
     **********************************************************************
     * Constructor: cHTTPHeaderStream
     *
     *      Author: $author$
     *        Date: 11/9/2004
     **********************************************************************
     */
    cHTTPHeaderStream
    (cCharStream &stream, 
     cHTTPHeaderParserStream &parser_stream) 
    : m_stream(stream),
      m_parser(parser_stream)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Read
    (char *buffer,  int length=-1) 
    {
        int c,count,result = -e_ERROR_FAILED;

        if (0 > length)
            length = strlen(buffer);

        for (result=0; result<length; result+=count)
        {
            if (0 >= (count = m_stream.Read(buffer+result, 1)))
                break;

            if (0 > (c = m_parser.Putc(buffer[result])))
            {
                result+=count;
                break;
            }
        }

        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Write
    (const char *buffer,  int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPStream
 *
 * Author: $author$
 *   Date: 11/9/2004
 **********************************************************************
 */
class cHTTPStream
: public cHTTPHeaderParserStream
{
public:
    typedef cHTTPHeaderParserStream cIs;

    cHTTPHeaderStream m_header_stream;
    cHTTPContentStream m_length_content_stream;
    cHTTPChunkedContentStream m_chunked_content_stream;
    cCharStream *m_stream,*m_content_stream;

    /**
     **********************************************************************
     * Constructor: cHTTPStream
     *
     *      Author: $author$
     *        Date: 11/9/2004
     **********************************************************************
     */
    cHTTPStream(cCharStream &stream) 
    : m_header_stream(stream, *this),
      m_length_content_stream(stream),
      m_chunked_content_stream(stream),
      m_stream(&m_header_stream),
      m_content_stream(&stream)
    {
    }
    /**
     **********************************************************************
     * Function: OnHeaderField
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual eError OnHeaderField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        if (!strcmp("Content-Length", name))
        {
            if (0 < (m_length_content_stream.m_length = atoi(value)))
                m_content_stream = &m_length_content_stream;
        }
        else if (!strcmp("Transfer-Encoding", name))
        {
            if (!strcmp("chunked", value))
                m_content_stream = &m_chunked_content_stream;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHeaderEnd
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual eError OnHeaderEnd
    (const char* chars,  int length=-1) 
    {
        eError error = e_ERROR_ENDOF;

        m_stream = m_content_stream;
        return error;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Read
    (char *buffer,  int length=-1) 
    {
        int count,remain,result = -e_ERROR_FAILED;

        if (m_stream)
        {
            if (0 > length)
                length = strlen(buffer);

            for (remain=length, result=0; 
                 result<length; result+=count, remain-=count)
                if (0 >= (count = m_stream->Read
                    (buffer+result, remain)))
                    break;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/9/2004
     **********************************************************************
     */
    virtual int Write
    (const char *buffer,  int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};

#endif /* ndef _CHTTPSTREAM_HXX */

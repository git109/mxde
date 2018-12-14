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
 *   File: cmakefilecommentstocharwriter.hxx
 *
 * Author: $author$
 *   Date: 10/17/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMAKEFILECOMMENTSTOCHARWRITER_HXX
#define _CMAKEFILECOMMENTSTOCHARWRITER_HXX

#include "ccharstreamtocharwriter.hxx"
#include "ccharbuffer.hxx"
#include "ccharwriter.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cMakefileCommentsToCharWriter
 *
 * Author: $author$
 *   Date: 10/17/2005
 **********************************************************************
 */
class cMakefileCommentsToCharWriter
: public cCharStreamToCharWriter
{
public:
    typedef cCharStreamToCharWriter cIs;

    typedef int (cMakefileCommentsToCharWriter::*mPut)(int c);
    cCharStreamToCharWriter m_stream_writer;
    cCharBuffer m_buffer;
    mPut m_put;
    const char *m_text;
    int m_length;

    /**
     **********************************************************************
     * Constructor: cMakefileCommentsToCharWriter
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cMakefileCommentsToCharWriter(cCharWriterInterface &writer) 
    : cIs(writer),
      m_stream_writer(writer),
      m_put(TextPut)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        m_put = TextPut;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Putc(int c) 
    {
        int count = 1;

        count = (this->*m_put)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: TextPut
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    int TextPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '#':
            m_put = CommentPut;
            break;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentPut
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    int CommentPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\n':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnComment(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int OnComment
    (const char* chars, int length) 
    {
        if (0 < length)
        if ('%' == chars[0])
        {
            cCharBuffer buffer(chars+1, length-1, length-1);
            length = m_stream_writer.WriteStream(buffer, length-1);
        }
        return length;
    }
};

#endif /* _CMAKEFILECOMMENTSTOCHARWRITER_HXX */
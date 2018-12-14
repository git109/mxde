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
 *   File: ccharstream.hxx
 *
 * Author: $author$
 *   Date: 7/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARSTREAM_HXX
#define _CCHARSTREAM_HXX

#include "ccharstreamt.hxx"
#include "ccharstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cCharStream
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class cCharStream
: virtual public cCharStreamInterface,
  public cCharStreamT<cStream>
{
public:
    typedef cCharStreamT<cStream> cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/15/2003
     **********************************************************************
     */
    enum
    {
        e_EOL_CHAR_LF = 0x1,
        e_EOL_CHAR_CR = 0x2
    };

    int m_eol_chars;

    /**
     **********************************************************************
     * Constructor: cCharStream
     *
     *      Author: $author$
     *        Date: 7/5/2003
     **********************************************************************
     */
    cCharStream()
    : m_eol_chars(e_EOL_CHAR_LF)
    {
    }

    /**
     **********************************************************************
     * Function: WriteStream
     *
     * Author: $author$
     * Date:   2/16/2004
     **********************************************************************
     */
    virtual int WriteStream(cCharStream &stream, int size=-1)
    {
        int c,count;

        for (count=0; 0 <= (c = stream.Getc()); count++)
            if (0 > (c = Putc(c)))
                return c;

        return count;
    }

    /**
     **********************************************************************
     * Function: SetEOLChars()
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    inline int SetEOLChars(int eol_chars)
    {
        int old_eol_chars = m_eol_chars;

        m_eol_chars = eol_chars;
        return old_eol_chars;
    }
    /**
     **********************************************************************
     * Function: GetEOLChars()
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    inline int GetEOLChars() const
    {
        return m_eol_chars;
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamStreamT
 *
 * Author: $author$
 *   Date: 3/14/2004
 **********************************************************************
 */
template <class TIs=cCharStream>
class cCharStreamStreamT
: public TIs
{
public:
    typedef TIs cIs;

    cCharStream &m_stream;

    /**
     **********************************************************************
     * Constructor: cCharStreamStreamT
     *
     *      Author: $author$
     *        Date: 3/14/2004
     **********************************************************************
     */
    cCharStreamStreamT(cCharStream &stream) 
    : m_stream(stream) 
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        return m_stream.Read(buffer, size);
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        return m_stream.Write(buffer, size);
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamStream
 *
 * Author: $author$
 *   Date: 3/14/2004
 **********************************************************************
 */
class cCharStreamStream
: public cCharStreamStreamT<cCharStream>
{
public:
    typedef cCharStreamStreamT<cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamStream
     *
     *      Author: $author$
     *        Date: 3/14/2004
     **********************************************************************
     */
    cCharStreamStream(cCharStream &stream) 
    : cIs(stream) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamInterfaceStreamT
 *
 * Author: $author$
 *   Date: 2/5/2004
 **********************************************************************
 */
template <class TIs=cCharStream>
class cCharStreamInterfaceStreamT
: public TIs
{
public:
    typedef TIs cIs;

    cCharStreamInterface &m_stream;

    /**
     **********************************************************************
     * Constructor: cCharStreamInterfaceStreamT
     *
     *      Author: $author$
     *        Date: 2/5/2004
     **********************************************************************
     */
    cCharStreamInterfaceStreamT(cCharStreamInterface &stream) 
    : m_stream(stream) 
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        return m_stream.Read(buffer, size);
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        return m_stream.Write(buffer, size);
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamInterfaceStream
 *
 * Author: $author$
 *   Date: 2/6/2004
 **********************************************************************
 */
class cCharStreamInterfaceStream
: public cCharStreamInterfaceStreamT<cCharStream>
{
public:
    typedef cCharStreamInterfaceStreamT<cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamInterfaceStream
     *
     *      Author: $author$
     *        Date: 2/6/2004
     **********************************************************************
     */
    cCharStreamInterfaceStream(cCharStreamInterface &stream) 
    : cIs(stream) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamForkStreamT
 *
 * Author: $author$
 *   Date: 3/14/2004
 **********************************************************************
 */
template <class TIs=cCharStream>
class cCharStreamForkStreamT
: public TIs
{
public:
    typedef TIs cIs;

    cCharStream &m_stream_left;
    cCharStream &m_stream_right;

    /**
     **********************************************************************
     * Constructor: cCharStreamForkStreamT
     *
     *      Author: $author$
     *        Date: 3/14/2004
     **********************************************************************
     */
    cCharStreamForkStreamT
    (cCharStream &stream_left,
     cCharStream &stream_right) 
    : m_stream_left(stream_left),
      m_stream_right(stream_right) 
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        return -e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        int length, count;

        if (0 <= (length = m_stream_left.Write(buffer, size)))
        if (0 <= (count = m_stream_right.Write(buffer, size)))
            length += count;

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamForkStream
 *
 * Author: $author$
 *   Date: 3/14/2004
 **********************************************************************
 */
class cCharStreamForkStream
: public cCharStreamForkStreamT<cCharStream>
{
public:
    typedef cCharStreamForkStreamT<cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamForkStream
     *
     *      Author: $author$
     *        Date: 3/14/2004
     **********************************************************************
     */
    cCharStreamForkStream
    (cCharStream &stream_left,
     cCharStream &stream_right) 
    : cIs(stream_left, stream_right) 
    {
    }
};

#endif

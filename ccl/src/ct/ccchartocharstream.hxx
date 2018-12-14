/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: ccchartocharstream.hxx
 *
 * Author: $author$
 *   Date: 11/9/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCCHARTOCHARSTREAM_HXX
#define _CCCHARTOCHARSTREAM_HXX

#include "cccharstream.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cCCharToCharStream
 *
 * Author: $author$
 *   Date: 11/9/2005
 **********************************************************************
 */
class cCCharToCharStream
{
public:

    cCharStream &m_stream;

    /**
     **********************************************************************
     * Constructor: cCCharToCharStream
     *
     *      Author: $author$
     *        Date: 11/9/2005
     **********************************************************************
     */
    cCCharToCharStream(cCharStream &stream) 
    : m_stream(stream)
    {
    }
    /**
     **********************************************************************
     * Function: WriteCChar
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual int WriteCChar
    (const cChar* buffer, int length=-1) 
    {
        int i,count;
        char c;

        if (0 > length)
        {
            for (length=0; (c=buffer[length].ToChar()); length++)
                if (0 > (count = m_stream.Putc(c)))
                    return count;
        }
        else for (i=0; i<length; i++)
        {
            c = buffer[i].ToChar();

            if (0 > (count = m_stream.Putc(c)))
                return count;
        }

        return length;
    }
};

#endif /* _CCCHARTOCHARSTREAM_HXX */

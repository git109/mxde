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
 *   File: ccharstreamtocharwriter.hxx
 *
 * Author: $author$
 *   Date: 10/16/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARSTREAMTOCHARWRITER_HXX
#define _CCHARSTREAMTOCHARWRITER_HXX

#include "ccharwriter.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cCharStreamToCharWriter
 *
 * Author: $author$
 *   Date: 10/16/2005
 **********************************************************************
 */
class cCharStreamToCharWriter
{
public:
    cCharWriterInterface &m_writer;

    /**
     **********************************************************************
     * Constructor: cCharStreamToCharWriter
     *
     *      Author: $author$
     *        Date: 10/16/2005
     **********************************************************************
     */
    cCharStreamToCharWriter(cCharWriterInterface &writer)
    : m_writer(writer)
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
     * Function: WriteStream
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual int WriteStream
    (cCharStreamInterface& stream, int length=-1) 
    {
        eError error;
        int c,count;

        if (0 > length)
        {
            for (length=0; 0 <= (c = stream.Getc()); length++)
            {
                if ((0 > (c = Putc(c))))
                {
                    error = -c;
                    break;
                }
            }
        }
        else
        {
            for (count=length, length=0; length<count; length++)
            {
                if (0 > (c = stream.Getc()))
                    break;

                if ((0 > (c = Putc(c))))
                {
                    error = -c;
                    break;
                }
            }
        }

        if (error)
            return -error;

        return length;
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
        return m_writer.Putc(c);
    }
};

#endif /* _CCHARSTREAMTOCHARWRITER_HXX */
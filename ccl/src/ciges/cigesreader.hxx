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
 *   File: cigesreader.hxx
 *
 * Author: $author$
 *   Date: 7/23/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIGESREADER_HXX
#define _CIGESREADER_HXX

#include "cigeswriter.hxx"
#include "ccharreaderinterface.hxx"

/**
 **********************************************************************
 *  Class: cIGESReader
 *
 * Author: $author$
 *   Date: 7/23/2005
 **********************************************************************
 */
class cIGESReader
{
public:
    cIGESWriter m_writer;

    /**
     **********************************************************************
     * Constructor: cIGESReader
     *
     *      Author: $author$
     *        Date: 7/23/2005
     **********************************************************************
     */
    cIGESReader(cIGESEventInterface &event)
    : m_writer(event)
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual int Read
    (cCharReaderInterface& reader) 
    {
        int c,count = 0;
        eError error;

        if ((error = m_writer.Initialize()))
            return count = -error;

        while (0 <= (c = reader.Getc()))
        {
            if (0 > (c = m_writer.Putc(c)))
                return count = c;

            count++;
        }

        if ((error = m_writer.Finalize()))
            return count = -error;

        return count;
    }
};

#endif /* _CIGESREADER_HXX */
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
 *   File: cfilepathparser.hxx
 *
 * Author: $author$
 *   Date: 1/16/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEPATHPARSER_HXX
#define _CFILEPATHPARSER_HXX

#include "cfilepathwriter.hxx"

/**
 **********************************************************************
 *  Class: cFilePathParser
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
class cFilePathParser
{
public:
    cFilePathParserEventInterface& m_event;
    cFilePathWriter m_writer;

    /**
     **********************************************************************
     * Constructor: cFilePathParser
     *
     *      Author: $author$
     *        Date: 1/16/2006
     **********************************************************************
     */
    cFilePathParser
    (cFilePathParserEventInterface& event) 
    : m_event(event),
      m_writer(event)
    {
    }
    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Parse
    (const cChar* chars, int length=-1) 
    {
        eError error = e_ERROR_NONE;

        if (!chars)
            return e_ERROR_FAILED;

        if (0 > length)
            length = cChar::LengthOf(chars);

        if (0 < length)
        {
            cCCharBuffer buffer(chars, length, length);

            error = ParseStream(buffer);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Parsec
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Parsec
    (const char* chars, int length=-1) 
    {
        eError error = e_ERROR_NONE;

        if (!chars)
            return e_ERROR_FAILED;

        if (0 > length)
            length = strlen(chars);

        if (0 < length)
        {
            cCharBuffer buffer(chars, length, length);

            error = ParseStreamc(buffer);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseStream
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError ParseStream
    (cCCharStreamInterface& stream, int length=-1) 
    {
        eError error = e_ERROR_NONE;
        int count;
        cChar c;

        if ((error = m_writer.Initialize()))
            return error;

        if (0 > length)
        {
            while (0 < (count = stream.Get(c)))
            {
                if (0 > (count = m_writer.Put(c)))
                    return error = -count;
            }
        }
        else
        {
            for (; 0<length; --length)
            {
                if (0 > (count = stream.Get(c)))
                    break;

                if (0 > (count = m_writer.Put(c)))
                    return error = -count;
            }
        }
        error = m_writer.Finalize();
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseStreamc
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError ParseStreamc
    (cCharStreamInterface& stream, int length=-1) 
    {
        eError error = e_ERROR_NONE;
        int c;

        if ((error = m_writer.Initialize()))
            return error;

        if (0 > length)
        {
            while (0 <= (c = stream.Getc()))
            {
                if (0 > (c = m_writer.Putc(c)))
                    return error = -c;
            }
        }
        else
        {
            for (; 0<length; --length)
            {
                if (0 > (c = stream.Getc()))
                    break;

                if (0 > (c = m_writer.Putc(c)))
                    return error = -c;
            }
        }
        error = m_writer.Finalize();
        return error;
    }
};

#endif /* _CFILEPATHPARSER_HXX */


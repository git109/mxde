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
 *   File: ccchartocharbuffer.hxx
 *
 * Author: $author$
 *   Date: 5/3/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCCHARTOCHARBUFFER_HXX
#define _CCCHARTOCHARBUFFER_HXX

#include <string.h>
#include "ccharbuffer.hxx"
#include "cccharbuffer.hxx"
#include "cchar.hxx"

/**
 **********************************************************************
 *  Class: cCCharToCharBuffer
 *
 * Author: $author$
 *   Date: 5/3/2005
 **********************************************************************
 */
class cCCharToCharBuffer
: public cCharBuffer
{
public:
    typedef cCharBuffer cIs;

    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const char* buffer, int size, int length) 
    : cIs(buffer, size, length)
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const char* buffer=0, int length=-1) 
    {
        eError error;

        if (buffer)
        if (0 > (length = Write(buffer, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const cChar* buffer, int length=-1) 
    {
        eError error;

        if (buffer)
        if (0 > (length = WriteCChar(buffer, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const cCharBuffer* buffer) 
    {
        eError error;
        const char* chars;
        int length;

        if (buffer)
        if ((chars = buffer->GetBuffer(length)))
        if (0 > (length = Write(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const cCCharBuffer* buffer) 
    {
        eError error;
        const cChar* chars;
        int length;

        if (buffer)
        if ((chars = buffer->GetBuffer(length)))
        if (0 > (length = WriteCChar(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const cCCharToCharBuffer& buffer) 
    {
        eError error;
        const char* chars;
        int length;

        if ((chars = buffer.GetBuffer(length)))
        if (0 > (length = Write(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cCCharToCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharToCharBuffer
    (const cCCharBuffer& buffer) 
    {
        eError error;
        const cChar* chars;
        int length;

        if ((chars = buffer.GetBuffer(length)))
        if (0 > (length = WriteCChar(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: CopyCChar
     *
     *   Author: $author$
     *     Date: 5/3/2005
     **********************************************************************
     */
    virtual int CopyCChar
    (const cChar* buffer, int length=-1) 
    {
        int count;

        if (0 > (count = Clear()))
            return count;

        length = WriteCChar(buffer, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteCChar
     *
     *   Author: $author$
     *     Date: 5/3/2005
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
                if (0 > (count = Putc(c)))
                    return count;
        }
        else for (i=0; i<length; i++)
        {
            c = buffer[i].ToChar();

            if (0 > (count = Putc(c)))
                return count;
        }

        return length;
    }
};

#endif /* _CCCHARTOCHARBUFFER_HXX */
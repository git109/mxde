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
 *   File: ccchartotcharbuffer.hxx
 *
 * Author: $author$
 *   Date: 5/5/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCCHARTOTCHARBUFFER_HXX
#define _CCCHARTOTCHARBUFFER_HXX

#include "ccharbuffer.hxx"
#include "cchar.hxx"

/**
 **********************************************************************
 *  Class: cCCharToTCHARBuffer
 *
 * Author: $author$
 *   Date: 5/5/2005
 **********************************************************************
 */
class cCCharToTCHARBuffer
: public cTCHARBuffer
{
public:
    typedef cTCHARBuffer cIs;

    /**
     **********************************************************************
     * Constructor: cCCharToTCHARBuffer
     *
     *      Author: $author$
     *        Date: 5/5/2005
     **********************************************************************
     */
    cCCharToTCHARBuffer
    (const TCHAR* buffer=0, int size=1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharToTCHARBuffer
     *
     *      Author: $author$
     *        Date: 5/5/2005
     **********************************************************************
     */
    cCCharToTCHARBuffer
    (const cChar* buffer,
     int length=-1) 
    {
        eError error;

        if (0 > (length = WriteCChar(buffer, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: CopyCChar
     *
     *   Author: $author$
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual int CopyCChar
    (const cChar* buffer,
     int length=-1) 
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
     *     Date: 5/5/2005
     **********************************************************************
     */
    virtual int WriteCChar
    (const cChar* buffer,
     int length=-1) 
    {
        int i,count;
        char c;

        if (0 > length)
        {
            for (length=0; (c=buffer[length].ToChar()); length++)
                if (0 > (count = Put(c)))
                    return count;
        }
        else for (i=0; i<length; i++)
        {
            c = buffer[i].ToChar();

            if (0 > (count = Put(c)))
                return count;
        }

        return length;
    }
};

#endif /* _CCCHARTOTCHARBUFFER_HXX */
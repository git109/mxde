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
 *   File: cstringcharbuffer.hxx
 *
 * Author: $author$
 *   Date: 1/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTRINGCHARBUFFER_HXX
#define _CSTRINGCHARBUFFER_HXX

#include "ccharbuffer.hxx"
#include "cstring.hxx"

/**
 **********************************************************************
 *  Class: cStringCharBuffer
 *
 * Author: $author$
 *   Date: 1/4/2005
 **********************************************************************
 */
class cStringCharBuffer
: public cCharBuffer
{
public:
    typedef cCharBuffer cIs;

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual int Set(const cStringInterface &string) 
    {
        const cChar *chars;
        int c,i,length;

        if (0 > (length = Clear()))
            return length;

        if ((chars = string.GetChars(length)))
        if (0 < (length))
        {
            for (i=0; i<length; i++)
            {
                c = chars[i].ToChar();

                if (0 > (c = Putc(c)))
                    return c;
            }
        }
        return length;
    }
};

#endif /* _CSTRINGCHARBUFFER_HXX */
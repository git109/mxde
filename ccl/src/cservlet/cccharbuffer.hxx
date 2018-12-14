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
 *   File: cccharbuffer.hxx
 *
 * Author: $author$
 *   Date: 11/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCCHARBUFFER_HXX
#define _CCCHARBUFFER_HXX

#include "cbufferast.hxx"
#include "cccharstream.hxx"

#define CCCHARBUFFER_DEFAULT_SIZE 256

/**
 **********************************************************************
 *  Class: cCCharBufferT
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
template 
<class TAs, int VDefaultSize, class TIs=cCCharStream>

class cCCharBufferT
: public cBufferAsT<TAs, VDefaultSize, cChar, 0, TIs>
{
public:
    typedef cBufferAsT<TAs, VDefaultSize, cChar, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cCCharBufferT
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cCCharBufferT() 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharBufferT
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cCCharBufferT
    (const cChar *buffer, int size, int length) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharBufferT
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharBufferT
    (const cChar *buffer, int length=-1) 
    {
        eError error;
        int count;

        if (buffer)
        if (0 > (count = Write(buffer, length)))
            throw(error = -count);
    }
    /**
     **********************************************************************
     * Constructor: cCCharBufferT
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharBufferT
    (const char *buffer, int length=-1) 
    {
        eError error;
        int count;

        if (buffer)
        if (0 > (count = Writec(buffer, length)))
            throw(error = -count);
    }

    /**
     **********************************************************************
     * Function: Copyc
     *
     *   Author: $author$
     *     Date: 5/3/2005
     **********************************************************************
     */
    virtual int Copyc
    (const char* buffer, int length=-1) 
    {
        int count;

        if (0 > (count = Clear()))
            return count;

        length = Writec(buffer, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: Writec
     *
     *   Author: $author$
     *     Date: 5/3/2005
     **********************************************************************
     */
    virtual int Writec
    (const char* buffer, int length=-1) 
    {
        int i,count;
        cChar c;

        if (length < 0)
            length = strlen(buffer);

        for (i=0; i<length; i++)
        {
            c=buffer[i];

            if (0 > (count = Put(c)))
                return count;
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Comparec
     *
     *   Author: $author$
     *     Date: 12/11/2004
     **********************************************************************
     */
    virtual int Comparec
    (const char *buffer, int length=-1) const
    {
        const cChar *mbuffer;
        cChar of1,of2;
        int lendiff;

        if (!(mbuffer = m_read_buffer))
            return buffer?1:-1;

        if (length < 0)
            length = strlen(buffer);

        if (0 < (lendiff = (length - m_length)))
            length = m_length;
 
        if (length > 0)
        do
        {
            if ((of1 = *(buffer++)) > (of2 = *(mbuffer++)))
                return 1;

            if (of1 < of2)
                return -1;
        }
        while (--length > 0);

        return lendiff;
    }
};

/**
 **********************************************************************
 *  Class: cCCharBuffer
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
class cCCharBuffer
: public cCCharBufferT
  <cCCharBuffer, CCCHARBUFFER_DEFAULT_SIZE>
{
public:
    typedef cCCharBufferT
    <cCCharBuffer, CCCHARBUFFER_DEFAULT_SIZE> cIs;

    /**
     **********************************************************************
     * Constructor: cCCharBuffer
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cCCharBuffer() 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharBuffer
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cCCharBuffer
    (const cChar *buffer, int size, int length) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharBuffer
    (const cChar *buffer, int length=-1) 
    : cIs(buffer, length)
    {
    }
    /**
     **********************************************************************
     * Constructor: cCCharBuffer
     *
     *      Author: $author$
     *        Date: 5/3/2005
     **********************************************************************
     */
    cCCharBuffer
    (const char *buffer, int length=-1) 
    : cIs(buffer, length)
    {
    }
};

#endif /* ndef _CCCHARBUFFER_HXX */

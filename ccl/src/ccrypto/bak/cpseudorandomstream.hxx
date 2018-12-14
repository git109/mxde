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
 *   File: cpseudorandomstream.hxx
 *
 * Author: $author$
 *   Date: 1/18/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPSEUDORANDOMSTREAM_HXX
#define _CPSEUDORANDOMSTREAM_HXX

#include <time.h>
#include <stdlib.h>
#include "ccharstream.hxx"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cPseudoRandomSeed
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
class cPseudoRandomSeed
{
public:
    /**
     **********************************************************************
     * Constructor: cPseudoRandomSeed
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cPseudoRandomSeed(time_t t) 
    {
        srand(t);
    }
};

/**
 **********************************************************************
 *  Class: cPseudoRandomStreamT
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
template
<class TAs,
 class TChar=BYTE,
 class TIs=cBYTEStream>
class cPseudoRandomStreamT
: public TIs
{
public:
    typedef TIs cIs;

    cPseudoRandomSeed &m_seed;
    unsigned m_rand;
    int m_avail;

    /**
     **********************************************************************
     * Constructor: cPseudoRandomStreamT
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cPseudoRandomStreamT(cPseudoRandomSeed &seed)
    : m_seed(seed),
      m_rand(0),
      m_avail(0)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    virtual int Read(TChar *buffer, int size=-1) 
    {
        int i, j, count, length;

        if (0 > size)
            size = strlen((const char*)buffer);

        length = 0;

        while (length < size)
        {
            if (1 > m_avail)
            {
                m_rand = (unsigned)rand();
                m_avail = sizeof(m_rand);
            }

            if ((count = size-length) > m_avail)
                count = m_avail;

            for (j=0,i=0; i<count; i++)
            {
                if ((buffer[length+j] = (m_rand & 255)))
                    j++;

                m_rand >>= 8;
            }

            length += j;
            m_avail -= count;
        }
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cPseudoRandomStream
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
class cPseudoRandomStream
: public cPseudoRandomStreamT<cPseudoRandomStream>
{
public:
    typedef cPseudoRandomStreamT<cPseudoRandomStream> cIs;

    /**
     **********************************************************************
     * Constructor: cPseudoRandomStream
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cPseudoRandomStream(cPseudoRandomSeed &seed)
    : cIs(seed)
    {
    }
};

#endif /* _CPSEUDORANDOMSTREAM_HXX */
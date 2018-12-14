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
 *   File: csslrandom.hxx
 *
 * Author: $author$
 *   Date: 1/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLRANDOM_HXX
#define _CSSLRANDOM_HXX

#include "platform.h"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLRandom
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */
class cSSLRandom
{
public:
    enum {e_RANDOM_SIZE = 28};

    uint32 m_gmt_unix_time;
    uint8 m_random[e_RANDOM_SIZE];

    /**
     **********************************************************************
     * Constructor: cSSLRandom
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cSSLRandom(uint32 gmt_unix_time=0) 
    : m_gmt_unix_time(gmt_unix_time)
    {
        for (int i=0; i<sizeof(m_random); i++)
            m_random[i] = (i+1)^(i+i);
    }
    /**
     **********************************************************************
     * Constructor: cSSLRandom
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cSSLRandom
    (uint32 gmt_unix_time, cBYTEStream &stream) 
    : m_gmt_unix_time(gmt_unix_time)
    {
        eError error;
        int size;

        if (0 > (size = Set(gmt_unix_time, stream)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_gmt_unix_time)+sizeof(m_random);
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    int Copy(const cSSLRandom &random)
    {
        int size;

        if (&random == this)
            return size = Sizeof();

        m_gmt_unix_time = random.m_gmt_unix_time;
        memcpy(m_random, random.m_random, sizeof(m_random));
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    int Set(uint32 gmt_unix_time, cBYTEStream &stream)
    {
        int size;

        if ((size = stream.Read
            (m_random, sizeof(m_random))) < sizeof(m_random))
        if (size > 0)
            return size = -e_ERROR_FAILED;
        else return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = stream.ReadUInt32MSB(m_gmt_unix_time)))
            return size;

        if (0 > (size = stream.Read(m_random, sizeof(m_random))))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;

        if (0 > (size = stream.WriteUInt32MSB(m_gmt_unix_time)))
            return size;

        if (0 > (size = stream.Write(m_random, sizeof(m_random))))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    int operator != (cSSLRandom &random)
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLRANDOM_HXX */
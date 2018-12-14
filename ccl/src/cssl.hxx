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
 *   File: cssl.hxx
 *
 * Author: $author$
 *   Date: 6/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSL_HXX
#define _CSSL_HXX

#include "platform.h"
#include "cerror.h"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cSSLVersion
 *
 * Author: $author$
 *   Date: 6/13/2004
 **********************************************************************
 */
class cSSLVersion
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 6/13/2004
     **********************************************************************
     */
    enum
    {
        e_2 = 2,
        e_3 = 3
    };

    uint8 m_major,m_minor;

    /**
     **********************************************************************
     * Constructor: cSSLVersion
     *
     *      Author: $author$
     *        Date: 6/13/2004
     **********************************************************************
     */
    cSSLVersion(uint8 major=3,uint8 minor=0) 
    {
        eError error;

        if ((error = Set(major,minor)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    unsigned Sizeof()
    {
        return sizeof(m_major)+sizeof(m_minor);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    eError Copy(cSSLVersion &version)
    {
        return Set(version.m_major,version.m_minor);
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    eError Set(uint8 major=3,uint8 minor=0)
    {
        m_major=major;
        m_minor=minor;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    int Get(cCharStream &stream)
    {
        char major,minor;

        if (0 <= (major = stream.Getc()))
        if (0 <= (minor = stream.Getc()))
        {
            m_major = major;
            m_minor = minor;
            return sizeof(major)+sizeof(minor);
        }
        return -e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    int Put(cCharStream &stream)
    {
        char major,minor;

        if (0 <= (major = stream.Putc(m_major)))
        if (0 <= (minor = stream.Putc(m_minor)))
            return sizeof(major)+sizeof(minor);

        return -e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Operator: ==
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    bool operator == (cSSLVersion &version)
    {
        return 
        ((m_major == version.m_major) 
         && (m_minor == version.m_minor));
    }
    /**
     **********************************************************************
     * Operator: ==
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    bool operator == (int version)
    {
        return m_major == version;
    }
};

/**
 **********************************************************************
 *  Class: cSSLRandom
 *
 * Author: $author$
 *   Date: 6/13/2004
 **********************************************************************
 */
class cSSLRandom
{
public:
        enum {e_BYTES = 28};

        uint32 m_gmt_unix_time;
        uint8 m_random_byte[e_BYTES];

    /**
     **********************************************************************
     * Constructor: cSSLRandom
     *
     *      Author: $author$
     *        Date: 6/13/2004
     **********************************************************************
     */
    cSSLRandom() 
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    unsigned Sizeof()
    {
        return sizeof(m_gmt_unix_time)+e_BYTES;
    }
    eError Copy(cSSLRandom &random)
    {
        m_gmt_unix_time=random.m_gmt_unix_time;
        memcpy(m_random_byte,random.m_random_byte,e_BYTES);
        return e_ERROR_NONE;
    }
    eError Get(cStream &stream)
    {
        cError error;

        if (!(error=stream.Getuint32MSB(m_gmt_unix_time)))
        if (!(error=stream.Get(m_random_byte,c_BYTES)))
            return error;
        return c_ERROR_FAIL;
    }
    cError Put(cStream &stream)
    {
        cError error;

        if (!(error=stream.Putuint32MSB(m_gmt_unix_time)))
        if (!(error=stream.Put(m_random_byte,c_BYTES)))
            return error;
        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Operator: 
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
};

#endif /* ndef _CSSL_HXX */

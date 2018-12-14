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
 *   File: csslpremastersecret.hxx
 *
 * Author: $author$
 *   Date: 2/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLPREMASTERSECRET_HXX
#define _CSSLPREMASTERSECRET_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "csslversion.hxx"

/**
 **********************************************************************
 *  Class: cSSLPreMasterSecret
 *
 * Author: $author$
 *   Date: 2/7/2005
 **********************************************************************
 */
class cSSLPreMasterSecret
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/7/2005
     **********************************************************************
     */
    enum
    {
        e_SIZE = 46
    };

    cSSLVersion m_version;
    BYTE m_random[e_SIZE];

    /**
     **********************************************************************
     * Constructor: cSSLPreMasterSecret
     *
     *      Author: $author$
     *        Date: 2/7/2005
     **********************************************************************
     */
    cSSLPreMasterSecret
    (cSSLVersion &version, cBYTEStream &random) 
    {
        eError error;
        int size;

        if (0 > (size = Set(version, random)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Constructor: cSSLPreMasterSecret
     *
     *      Author: $author$
     *        Date: 2/7/2005
     **********************************************************************
     */
    cSSLPreMasterSecret() 
    {
        eError error;
        int size;

        if (0 > (size = Set()))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Copy(const cSSLPreMasterSecret &secret)
    {
        int size;

        if (&secret == this)
            return size = Sizeof();

        if (0 > (size = m_version.Copy(secret.m_version)))
            return size;

        memcpy(m_random, secret.m_random, e_SIZE);
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Set(cSSLVersion &version, cBYTEStream &random)
    {
        int size;

        if (0 > (size = m_version.Copy(version)))
            return size;

        if (e_SIZE != (size = random.Read(m_random, e_SIZE)))
        if (size > 0)
            size = -e_ERROR_ENDOF;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Set()
    {
        int size = Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = m_version.Read(stream)))
            return size;

        if (e_SIZE != (size = stream.Read(m_random, e_SIZE)))
        {
            if (size >= 0)
                size = -e_ERROR_ENDOF;
            return size;
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;

        if (0 > (size = m_version.Write(stream)))
            return size;

        if (e_SIZE != (size = stream.Write(m_random, e_SIZE)))
        {
            if (size >= 0)
                size = -e_ERROR_ENDOF;
            return size;
        }

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = m_version.Sizeof()+e_SIZE;
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int operator != (const cSSLPreMasterSecret &secret) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLPREMASTERSECRET_HXX */

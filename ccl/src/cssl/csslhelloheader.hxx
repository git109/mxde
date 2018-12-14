/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: csslhelloheader.hxx
 *
 * Author: $author$
 *   Date: 10/14/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSSLHELLOHEADER_HXX
#define _CSSLHELLOHEADER_HXX

#include "platform.h"
#include "csslversion.hxx"
#include "csslrandom.hxx"
#include "csslsessionid.hxx"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLHelloHeader
 *
 * Author: $author$
 *   Date: 1/14/2005
 **********************************************************************
 */
class cSSLHelloHeader
{
public:
    cSSLVersion m_version;
    cSSLRandom m_random;
    cSSLSessionID m_session;

    /**
     **********************************************************************
     * Constructor: cSSLHelloHeader
     *
     *      Author: $author$
     *        Date: 1/14/2005
     **********************************************************************
     */
    cSSLHelloHeader() 
    {
    }
    /**
     **********************************************************************
     * Constructor: cSSLHelloHeader
     *
     *      Author: $author$
     *        Date: 1/14/2005
     **********************************************************************
     */
    cSSLHelloHeader
    (const cSSLVersion &version,
     const cSSLRandom &random,
     const cSSLSessionID &session) 
    {
         eError error;
         int size;

         if (0 > (size = Set(version, random, session)))
             throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = m_version.Sizeof()+m_random.Sizeof()+m_session.Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Copy(const cSSLHelloHeader &header)
    {
        int size;

        if (&header == this)
            return size = Sizeof();

        size = Set(header.m_version, header.m_random, header.m_session);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Set
    (const cSSLVersion &version,
     const cSSLRandom &random,
     const cSSLSessionID &session)
    {
        int size;

        if (0 > (size = m_version.Copy(version)))
            return size;

        if (0 > (size = m_random.Copy(random)))
            return size;

        if (0 > (size = m_session.Copy(session)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = m_version.Read(stream)))
            return size;

        if (0 > (size = m_random.Read(stream)))
            return size;

        if (0 > (size = m_session.Read(stream)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;

        if (0 > (size = m_version.Write(stream)))
            return size;

        if (0 > (size = m_random.Write(stream)))
            return size;

        if (0 > (size = m_session.Write(stream)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: GetVersion
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    inline cSSLVersion& GetVersion() 
    {
        return m_version;
    }
    /**
     **********************************************************************
     * Function: GetRandom
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    inline cSSLRandom& GetRandom() 
    {
        return m_random;
    }
    /**
     **********************************************************************
     * Function: GetSession
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    inline cSSLSessionID& GetSession() 
    {
        return m_session;
    }
};

#endif /* _CSSLHELLOHEADER_HXX */

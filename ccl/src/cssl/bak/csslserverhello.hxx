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
 *   File: csslserverhello.hxx
 *
 * Author: $author$
 *   Date: 1/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLSERVERHELLO_HXX
#define _CSSLSERVERHELLO_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "csslclienthello.hxx"

/**
 **********************************************************************
 *  Class: cSSLServerHello
 *
 * Author: $author$
 *   Date: 1/15/2005
 **********************************************************************
 */
class cSSLServerHello
{
public:
    cSSLHelloHeader m_header;
    cSSLCipherSuite m_suite;
    cSSLCompressionMethod m_method;

    /**
     **********************************************************************
     * Constructor: cSSLServerHello
     *
     *      Author: $author$
     *        Date: 1/15/2005
     **********************************************************************
     */
    cSSLServerHello() 
    {
    }
    /**
     **********************************************************************
     * Constructor: cSSLServerHello
     *
     *      Author: $author$
     *        Date: 1/15/2005
     **********************************************************************
     */
    cSSLServerHello
    (const cSSLHelloHeader &header,
     const cSSLCipherSuite &suite,
     const cSSLCompressionMethod &method) 
    {
        eError error;
        int size;

        if (0 > (size = Set(header, suite, method)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = m_header.Sizeof()+m_suite.Sizeof()+m_method.Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Copy(const cSSLServerHello &hello)
    {
        int size;
        
        if (&hello == this)
            return size = Sizeof();

        size = Set(hello.m_header, hello.m_suite, hello.m_method);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Set
    (const cSSLHelloHeader &header,
     const cSSLCipherSuite &suite,
     const cSSLCompressionMethod &method)
    {
        int size;

        if (0 > (size = m_header.Copy(header)))
            return size;

        if (0 > (size = m_suite.Copy(suite)))
            return size;

        if (0 > (size = m_method.Copy(method)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = m_header.Read(stream)))
            return size;

        if (0 > (size = m_suite.Read(stream)))
            return size;

        if (0 > (size = m_method.Read(stream)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;

        if (0 > (size = m_header.Write(stream)))
            return size;

        if (0 > (size = m_suite.Write(stream)))
            return size;

        if (0 > (size = m_method.Write(stream)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: GetHeader
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    inline cSSLHelloHeader& GetHeader() 
    {
        return m_header;
    }
    /**
     **********************************************************************
     * Function: GetSuite
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    inline cSSLCipherSuite& GetSuite() 
    {
        return m_suite;
    }
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    inline cSSLCompressionMethod& GetMethod() 
    {
        return m_method;
    }
};

#endif /* _CSSLSERVERHELLO_HXX */

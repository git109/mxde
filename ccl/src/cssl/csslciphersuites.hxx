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
 *   File: csslciphersuites.hxx
 *
 * Author: $author$
 *   Date: 10/15/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSSLCIPHERSUITES_HXX
#define _CSSLCIPHERSUITES_HXX

#include "csslciphersuite.hxx"

/**
 **********************************************************************
 *  Class: cSSLCipherSuites
 *
 * Author: $author$
 *   Date: 1/14/2005
 **********************************************************************
 */
class cSSLCipherSuites
{
protected:
    uint16 m_sizeof;
    uint16 m_suites;
    uint16 m_suite_sizeof;
    cSSLCipherSuite m_suite[cSSLCipherSuite::e_ALL];

public:
    /**
     **********************************************************************
     * Constructor: cSSLCipherSuites
     *
     *      Author: $author$
     *        Date: 1/14/2005
     **********************************************************************
     */
    cSSLCipherSuites
    (const cSSLCipherSuite *suite=0, int suites=-1) 
    : m_suites(0),
      m_sizeof(0) 
    {
        eError error;
        int size;

        m_suite_sizeof = m_suite[0].Sizeof();

        if (suite)
        if (0 > (size = Set(suite, suites)))
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
        int size = sizeof(m_sizeof)+(m_suites*m_suite_sizeof);
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
    int Copy(const cSSLCipherSuites &suites)
    {
        int size;
        
        if (&suites == this)
            return size = Sizeof();

        size = Set(suites.GetSuite(), suites.GetSuites());
        return size;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    const cSSLCipherSuite *Get
    (const cSSLCipherSuite &suite) const
    {
        int i;

        for (i=0; i<m_suites; i++)
            if (m_suite[i].GetSuite() == suite.GetSuite())
                return m_suite+i;

        return 0;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Set(const cSSLCipherSuite *suite=0, int suites=-1)
    {
        int i,size;

        for (i=0; i<suites; i++)
            if (0 > (size = m_suite[i].Copy(suite[i])))
                return size;

        m_sizeof = suites*m_suite_sizeof;
        m_suites = suites;
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
        int i,size;
        uint16 size_of,suites;

        if (0 <= (size = stream.ReadUInt16MSB(size_of)))
        {
            if (size_of % m_suite_sizeof)
                return -e_ERROR_INVALID_RETURN_SIZE;

            if (cSSLCipherSuite::e_ALL
                < (suites = size_of/m_suite_sizeof))
                return -e_ERROR_RETURN_SIZE_OVER;

            for (i=0; i<suites; i++)
                if (0 > (size = m_suite[i].Read(stream)))
                    return size;

            m_suites = suites;
            m_sizeof = size_of;
            size = Sizeof();
        }
        return size;
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
        int i,size;

        if (0 <= (size = stream.WriteUInt16MSB(m_sizeof)))
        {
            for (i=0; i<m_suites; i++)
                if (0 > (size = m_suite[i].Write(stream)))
                    return size;

            size = Sizeof();
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: GetSuites
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline uint16 GetSuites() const
    {
        return m_suites;
    }
    /**
     **********************************************************************
     * Function: GetSuite
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline const cSSLCipherSuite* GetSuite() const
    {
        return m_suite;
    }
};

#endif /* _CSSLCIPHERSUITES_HXX */

/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: csha1main.hxx
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
#ifndef _CSHA1MAIN_HXX
#define _CSHA1MAIN_HXX

#include "ccryptohashmain.hxx"
#include "csha1.hxx"

/**
 **********************************************************************
 * Typedef: cSHA1MainExtends
 *
 *  Author: $author$
 *    Date: 5/4/2009
 **********************************************************************
 */
typedef cCryptoHashMain
cSHA1MainExtends;

/**
 **********************************************************************
 *  Class: cSHA1Main
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class cSHA1Main
: public cSHA1MainExtends
{
public:
    typedef cSHA1MainExtends cExtends;
    typedef cSHA1Main cDerives;

    cSHA1 m_hash;
    BYTE m_hashed[cSHA1::HASHSIZE];

    /**
     **********************************************************************
     * Function: CryptoHash
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual cCryptoHashInterface& CryptoHash
    (BYTE*& hashed, TSIZE& hashedSize) const 
    {
        cCryptoHashInterface& hash = (cCryptoHashInterface&)(m_hash);
        hashed=(BYTE*)(m_hashed);
        hashedSize = (TSIZE)(sizeof(m_hashed));
        return hash;
    }
    /**
     **********************************************************************
     * Function: TestVector
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual const CHAR** TestVector
    (const CHAR**& hashed) const
    {
        static CHAR *testVector[]={
            "",
	        "abc",
	        "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
	        NULL,
	        };

        static CHAR *testHashed[]={
            "da39a3ee5e6b4b0d3255bfef95601890afd80709",
	        "a9993e364706816aba3e25717850c26c9cd0d89d",
	        "84983e441c3bd26ebaae4aa1f95129e5e54670f1",
            NULL,
	        };

        hashed = (const CHAR**)(testHashed);
        return (const CHAR**)(testVector);
    }
};
#endif /* _CSHA1MAIN_HXX */

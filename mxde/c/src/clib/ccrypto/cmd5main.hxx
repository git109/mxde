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
 *   File: cmd5main.hxx
 *
 * Author: $author$
 *   Date: 5/2/2009
 **********************************************************************
 */
#ifndef _CMD5MAIN_HXX
#define _CMD5MAIN_HXX

#include "ccryptohashmain.hxx"
#include "cmd5.hxx"

/**
 **********************************************************************
 * Typedef: cMD5MainExtends
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cCryptoHashMain
cMD5MainExtends;

/**
 **********************************************************************
 *  Class: cMD5Main
 *
 * Author: $author$
 *   Date: 5/2/2009
 **********************************************************************
 */
class cMD5Main
: public cMD5MainExtends
{
public:
    typedef cMD5MainExtends cExtends;
    typedef cMD5Main cDerives;

    cMD5 m_hash;
    BYTE m_hashed[cMD5::HASHSIZE];

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
	        "a",
	        "abc",
	        "message digest",
	        "abcdefghijklmnopqrstuvwxyz",
	        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
	        "12345678901234567890123456789012345678901234567890123456789012345678901234567890",
	        NULL,
	        };

        static CHAR *testHashed[]={
	        "d41d8cd98f00b204e9800998ecf8427e",
	        "0cc175b9c0f1b6a831c399e269772661",
	        "900150983cd24fb0d6963f7d28e17f72",
	        "f96b697d7cb7938d525a2f31aaf161d0",
	        "c3fcd3d76192e4007dfb496cca67e13b",
	        "d174ab98d277d9f5a5611c2c9f419d9f",
	        "57edf4a22be3c955ac49da2e2107b67a",
            NULL,
	        };

        hashed = (const CHAR**)(testHashed);
        return (const CHAR**)(testVector);
    }
};
#endif /* _CMD5MAIN_HXX */

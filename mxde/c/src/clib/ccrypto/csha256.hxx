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
 *   File: csha256.hxx
 *
 * Author: $author$
 *   Date: 7/29/2009
 **********************************************************************
 */
#ifndef _CSHA256_HXX
#define _CSHA256_HXX

#include "ccryptohash.hxx"

/**
 **********************************************************************
 *  Class: cSHA256
 *
 * Author: $author$
 *   Date: 7/29/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cSHA256
: public cCryptoHash
{
public:
    typedef cCryptoHash cExtends;
    typedef cSHA256 cDerives;

    enum
    {
        WORDSIZE    = 4,
        LENGTHSIZE  = 8,
    };
    
    enum
    {
        HASHSIZE  = 32,
        KONSTSIZE = 64,
        BLOCKSIZE = 64,
        KEYMIN    = 1,
        KEYMAX    = BLOCKSIZE,
        KEYSIZE   = BLOCKSIZE,
    };

    static UINT32 m_K[KONSTSIZE];

    UINT32 m_A,m_B,m_C,m_D,m_E,m_F,m_G,m_H,m_l,m_h;
    BYTE m_hash[HASHSIZE];
    BYTE m_mac[HASHSIZE];
    BYTE m_in[BLOCKSIZE];
    BYTE m_key[BLOCKSIZE];

    /**
     **********************************************************************
     * Constructor: cSHA256
     *
     *      Author: $author$
     *        Date: 7/29/2009
     **********************************************************************
     */
    cSHA256() 
    : cExtends
      (HASHSIZE,
       BLOCKSIZE,
       KEYMIN,
       KEYMAX,
       m_key,
       m_mac,
       m_hash)
    {
    }
    /**
     **********************************************************************
     * Function: HashSize
     *
     *   Author: $author$
     *     Date: 7/30/2009
     **********************************************************************
     */
    virtual TLENGTH HashSize() const
    {
        return HASHSIZE;
    }

    /**
     **********************************************************************
     * Function: Initial
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual void Initial();
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual void Final();
    /**
     **********************************************************************
     * Function: Update
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual void Update
    (const BYTE* in, unsigned inlen);
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 7/29/2009
     **********************************************************************
     */
    virtual void Transform();
};
#endif /* _CSHA256_HXX */

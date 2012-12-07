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
 *   File: csha512.hxx
 *
 * Author: $author$
 *   Date: 11/21/2009
 **********************************************************************
 */
#if !defined(_CSHA512_HXX) || defined(CSHA512_MEMBERS_ONLY)
#if !defined(_CSHA512_HXX) && !defined(CSHA512_MEMBERS_ONLY)
#define _CSHA512_HXX
#endif /* !defined(_CSHA512_HXX) && !defined(CSHA512_MEMBERS_ONLY) */

#if !defined(CSHA512_MEMBERS_ONLY)
#include "ccryptohash.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cSHA512
 *
 * Author: $author$
 *   Date: 11/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cSHA512
: public cCryptoHash
{
public:
    typedef cCryptoHash cExtends;
    
    enum
    {
        WORDSIZE    = 8,
        LENGTHSIZE  = 16,
    };
    
    enum
    {
        HASHSIZE  = 64,
        KONSTSIZE = 80,
        BLOCKSIZE = 128,
        KEYMIN    = 1,
        KEYMAX    = BLOCKSIZE,
        KEYSIZE   = BLOCKSIZE,
    };

    static UINT64 m_K[KONSTSIZE];

    UINT64 m_A,m_B,m_C,m_D,m_E,m_F,m_G,m_H,m_l,m_h;
    BYTE m_hash[HASHSIZE];
    BYTE m_mac[HASHSIZE];
    BYTE m_in[BLOCKSIZE];
    BYTE m_key[BLOCKSIZE];

    /**
     **********************************************************************
     *  Constructor: cSHA512
     *
     *       Author: $author$
     *         Date: 11/21/2009
     **********************************************************************
     */
    cSHA512
    (cSHA512* delegateTo=0)
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
#else /* !defined(CSHA512_MEMBERS_ONLY) */
#endif /* !defined(CSHA512_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Initial
     *
     *    Author: $author$
     *      Date: 11/21/2009
     **********************************************************************
     */
    virtual void Initial()
#if defined(CSHA512_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */
#if !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT)
    ;
#else /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
    {
    }
#endif /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Final
     *
     *    Author: $author$
     *      Date: 11/21/2009
     **********************************************************************
     */
    virtual void Final()
#if defined(CSHA512_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */
#if !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT)
    ;
#else /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
    {
    }
#endif /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Update
     *
     *    Author: $author$
     *      Date: 11/21/2009
     **********************************************************************
     */
    virtual void Update
    (const BYTE* in, unsigned inlen)
#if defined(CSHA512_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */
#if !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT)
    ;
#else /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
    {
    }
#endif /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Transform
     *
     *    Author: $author$
     *      Date: 11/21/2009
     **********************************************************************
     */
    virtual void Transform()
#if defined(CSHA512_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */
#if !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT)
    ;
#else /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
    {
    }
#endif /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: HashSize
     *
     *   Author: $author$
     *     Date: 11/22/2009
     **********************************************************************
     */
    virtual TLENGTH HashSize() const
#if defined(CSHA512_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */
    {
        return HASHSIZE;
#if !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSHA512_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CSHA512_MEMBER_FUNCS_INTERFACE) */
    
#if !defined(CSHA512_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSHA512_MEMBERS_ONLY) */
#endif /* !defined(CSHA512_MEMBERS_ONLY) */

#endif /* !defined(_CSHA512_HXX) || defined(CSHA512_MEMBERS_ONLY) */

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
 *   File: cmd5.hxx
 *
 * Author: $author$
 *   Date: 1/8/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMD5_HXX
#define _CMD5_HXX

#include "chash.hxx"

/**
 **********************************************************************
 *  Class: cMD5
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cMD5
: public cHash
{
public:
    typedef cHash cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/8/2005
     **********************************************************************
     */
    enum
    {
        e_HASHSIZE  = 16,
        e_BLOCKSIZE = 64,
        e_KEYMIN    = 1,
        e_KEYMAX    = e_BLOCKSIZE,
        e_KEYSIZE   = e_BLOCKSIZE,
    };

    /**
     **********************************************************************
     * Constructor: cMD5
     *
     *      Author: $author$
     *        Date: 1/8/2005
     **********************************************************************
     */
    cMD5() 
    : cIs
      (e_HASHSIZE,
       e_BLOCKSIZE,
       e_KEYMIN,
       e_KEYMAX,
       m_key,
       m_mac,
       m_hash)
    {
    }
    /**
     **********************************************************************
     * Function: GetHashSize
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int GetHashSize() const 
    {
        int size = e_HASHSIZE;
        return size;
    }

protected:

    uint32 m_A,m_B,m_C,m_D,m_L,m_H;
    BYTE m_hash[e_HASHSIZE];
    BYTE m_in[e_BLOCKSIZE];
    BYTE m_key[e_BLOCKSIZE];
    BYTE m_mac[e_HASHSIZE];

    /**
     **********************************************************************
     * Function: Initial
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual void Initial();
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual void Final();
    /**
     **********************************************************************
     * Function: Update
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual void Update(const BYTE *in, unsigned inlen);
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    void Transform();
};

#endif /* _CMD5_HXX */
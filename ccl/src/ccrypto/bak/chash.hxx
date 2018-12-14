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
 *   File: chash.hxx
 *
 * Author: $author$
 *   Date: 1/8/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHASH_HXX
#define _CHASH_HXX

#include <string.h>
#include "chashinterface.hxx"
#include "ccrypto.hxx"

/**
 **********************************************************************
 *  Class: cHash
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cHash
: virtual public cHashImplement,
  public cCrypto
{
public:
    typedef cCrypto cIs;

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
        e_IPAD=0x36, 
        e_OPAD=0x5c
    };

    /**
     **********************************************************************
     * Constructor: cHash
     *
     *      Author: $author$
     *        Date: 1/8/2005
     **********************************************************************
     */
    cHash
    (int hashsize,
     int blocksize,
     int keymin,
     int keymax,
     BYTE *keybuff,
     BYTE *macbuff,
     BYTE *hashbuff)
    : m_hashsize(hashsize),
      m_blocksize(blocksize),
      m_keymin(keymin),
      m_keymax(keymax),
      m_keylen(0),
      m_keysize(0),
      m_keybuff(keybuff),
      m_macbuff(macbuff),
      m_hashbuff(hashbuff) 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key=0, int keylen=-1)
    {
        int i;

        if (key)
        {
            if (0 > keylen)
                keylen = strlen((const char*)key);

            if (keylen < m_keymin)
                return -e_ERROR_PARAMETER_SIZE_UNDER;

            if (keylen > m_keymax)
                return -e_ERROR_PARAMETER_SIZE_OVER;

            m_keylen = keylen;
            m_keysize = m_keymax;
            memcpy(m_keybuff, key, keylen);
            memset(m_keybuff+keylen, 0, m_keymax-keylen);

            /*
             * HMAC
             */
            for (i=0; i<m_keymax; i++)
                m_keybuff[i] ^= e_OPAD;
        }
        else keylen = 0;

        Initial();

        if (m_keysize)
        {
            /*
             * HMAC
             */
            for (i=0; i<m_keysize; i++)
                m_keybuff[i] = (m_keybuff[i]^e_OPAD)^e_IPAD;

            Update(m_keybuff, m_keysize);

            /*
             * HMAC
             */
            for (i=0; i<m_keysize; i++)
                m_keybuff[i] = (m_keybuff[i]^e_IPAD)^e_OPAD;
        }
        return keylen;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int Finalize
    (BYTE *out, int outsize)
    {
        if (outsize < m_hashsize)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        Final();

        if (m_keysize)
        {
            /*
             * HMAC
             */
            memcpy(m_macbuff, m_hashbuff, m_hashsize);
            Initial();
            Update(m_keybuff, m_keysize);
            Update(m_macbuff, m_hashsize);
            Final();
        }

        memcpy(out, m_hashbuff, m_hashsize);
        return m_hashsize;
    }
    /**
     **********************************************************************
     * Function: HashFill
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    virtual int HashFill
    (BYTE in, int inrepeat=1)
    {
        int count;

        for (count=0; count<inrepeat; count++)
            Update(&in, 1);
        return count;
    }
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Hash
    (const BYTE *in, int inlen=-1)
    {
        if (0 > inlen)
            inlen = strlen((const char*)in);

        Update(in, inlen);
        return inlen;
    }

protected:

    int m_hashsize;
    int m_blocksize;
    int m_keymin;
    int m_keymax;
    int m_keylen;
    int m_keysize;
    BYTE *m_keybuff;
    BYTE *m_macbuff;
    BYTE *m_hashbuff;

    /**
     **********************************************************************
     * Function: Initial
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual void Initial() = 0;
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual void Final() = 0;
    /**
     **********************************************************************
     * Function: Update
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual void Update(const BYTE *in, unsigned inlen) = 0;
};

#endif /* _CHASH_HXX */
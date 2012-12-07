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
 *   File: ccryptohash.hxx
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#ifndef _CCRYPTOHASH_HXX
#define _CCRYPTOHASH_HXX

#include "ccryptohashinterface.hxx"
#include "ccryptohmac.hxx"
#include "ccryptobase.hxx"
#include "ctypes.hxx"

/**
 **********************************************************************
 * Typedef: cCryptoHashExtends
 *
 *  Author: $author$
 *    Date: 5/1/2009
 **********************************************************************
 */
typedef cCryptoBase
cCryptoHashExtends;

/**
 **********************************************************************
 *  Class: cCryptoHash
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cCryptoHash
: virtual public cCryptoHashImplement,
  public cCryptoHashExtends
{
public:
    typedef cCryptoHashImplement cImplements;
    typedef cCryptoHashExtends cExtends;
    typedef cCryptoHash cDerives;

    TLENGTH m_hashsize;
    TLENGTH m_blocksize;
    TLENGTH m_keymin;
    TLENGTH m_keymax;
    TLENGTH m_keysize;
    TLENGTH m_keylen;

    BYTE *m_keybuff;
    BYTE *m_macbuff;
    BYTE *m_hashbuff;

    /**
     **********************************************************************
     * Constructor: cCryptoHash
     *
     *      Author: $author$
     *        Date: 5/1/2009
     **********************************************************************
     */
    cCryptoHash
    (TLENGTH hashsize,
     TLENGTH blocksize,
     TLENGTH keymin,
     TLENGTH keymax,
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
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual TLENGTH Initialize
    (const BYTE* key=0,
     TLENGTH keylen=-1) 
    {
        TLENGTH i;

        if (key)
        {
            if (0 > keylen)
                keylen = cBYTES::Count(key);

            if (keylen < m_keymin)
                return -e_ERROR_PARAMETER_SIZE_UNDER;

            if (keylen > m_keymax)
                return -e_ERROR_PARAMETER_SIZE_OVER;

            m_keylen = keylen;
            m_keysize = m_keymax;
            cBYTES::Copy(m_keybuff, key, keylen);
            cBYTES::Set(m_keybuff+keylen, 0, m_keymax-keylen);

            /*
             * HMAC
             */
            for (i=0; i<m_keymax; i++)
                m_keybuff[i] ^= e_CRYPTO_HMAC_OPAD;
        }
        else m_keysize = m_keylen = keylen = 0;

        Initial();

        if (m_keysize)
        {
            /*
             * HMAC
             */
            for (i=0; i<m_keysize; i++)
                m_keybuff[i] = (m_keybuff[i]^e_CRYPTO_HMAC_OPAD)^e_CRYPTO_HMAC_IPAD;

            Update(m_keybuff, m_keysize);

            /*
             * HMAC
             */
            for (i=0; i<m_keysize; i++)
                m_keybuff[i] = (m_keybuff[i]^e_CRYPTO_HMAC_IPAD)^e_CRYPTO_HMAC_OPAD;
        }
        return keylen;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual TLENGTH Finalize
    (BYTE* out,
     TSIZE outsize) 
    {
        TLENGTH outlen = (TLENGTH)(outsize);

        if (outlen > m_hashsize)
            outlen = m_hashsize;

        Final();

        if (m_keysize)
        {
            /*
             * HMAC
             */
            cBYTES::Copy(m_macbuff, m_hashbuff, m_hashsize);
            Initial();
            Update(m_keybuff, m_keysize);
            Update(m_macbuff, m_hashsize);
            Final();
        }

        cBYTES::Copy(out, m_hashbuff, outlen);
        return outlen;
    }
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual TLENGTH Hash
    (const BYTE *in,
     TLENGTH inlen=-1) 
    {
        if (0 > inlen)
            inlen = cBYTES::Count(in);

        Update(in, inlen);
        return inlen;
    }

    /**
     **********************************************************************
     * Function: Initial
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual void Initial() = 0;
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual void Final() = 0;
    /**
     **********************************************************************
     * Function: Update
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual void Update
    (const BYTE* in, unsigned inlen) = 0;
};
#endif /* _CCRYPTOHASH_HXX */

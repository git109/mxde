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
 *   File: cdes.hxx
 *
 * Author: $author$
 *   Date: 1/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDES_HXX
#define _CDES_HXX

#include "ccipher.hxx"

/**
 **********************************************************************
 *  Class: cDES
 *
 * Author: $author$
 *   Date: 1/9/2005
 **********************************************************************
 */
class cDES
: public cCipher
{
public:
    typedef cCipher cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/9/2005
     **********************************************************************
     */
    enum
    {
        e_BLOCKSIZE = 8,
        e_KEYMIN    = 8,
        e_KEYMAX    = 8,
        e_KEYSIZE   = 8,
        e_IVMIN     = 8,
        e_IVMAX     = 8,
        e_IVSIZE    = 8
    };

    /**
     **********************************************************************
     * Constructor: cDES
     *
     *      Author: $author$
     *        Date: 1/9/2005
     **********************************************************************
     */
    cDES() 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     BYTE padding=0)
    {
        int length = e_KEYMAX+e_IVMAX;

        if (0 > keylen)
            keylen = (int)strlen((const char*)key);

        if (e_KEYMIN > keylen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        if (e_KEYMAX < keylen)
            return -e_ERROR_PARAMETER_SIZE_OVER;

        CopyRepeat(m_key, e_KEYMAX, key, keylen);

        if (iv)
        {
            if (0 > ivlen)
                ivlen = (int)strlen((const char*)iv);

            if (e_IVMIN > ivlen)
                return -e_ERROR_PARAMETER_SIZE_UNDER;

            if (e_IVMAX < ivlen)
                return -e_ERROR_PARAMETER_SIZE_OVER;

            CopyRepeat(m_iv, e_IVMAX, iv, ivlen);
        }
        else
        {
            if (e_IVMAX < keylen)
                keylen = e_IVMAX;

            CopyRepeat(m_iv, e_IVMAX, key, keylen);
        }

        m_padding = padding;
        InitSchedule(m_schedule[0], m_key);
        return length;
    }
    /**
     **********************************************************************
     * Function: Encrypt
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int Encrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+e_BLOCKSIZE-1)/e_BLOCKSIZE)*e_BLOCKSIZE;

        if (outsize < outlen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        for (outlen=0; inlen>0; inlen-=size, outlen+=e_BLOCKSIZE)
        {
            if ((size=inlen) >= e_BLOCKSIZE)
            {
                size=e_BLOCKSIZE;
                EncryptBlock(out+outlen, in+outlen);
            }
            else
            {
                memcpy(block, in+outlen, size);
                memset(block+size, m_padding, e_BLOCKSIZE-size);
                EncryptBlock(out+outlen, block);
            }
        }
        return outlen;
    }
    /**
     **********************************************************************
     * Function: Decrypt
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int Decrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+e_BLOCKSIZE-1)/e_BLOCKSIZE)*e_BLOCKSIZE;

        if (outsize < outlen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        for (outlen=0; inlen>0; inlen-=size, outlen+=e_BLOCKSIZE)
        {
            if ((size=inlen) >= e_BLOCKSIZE)
            {
                size=e_BLOCKSIZE;
                DecryptBlock(out+outlen, in+outlen);
            }
            else
            {
                memcpy(block, in+outlen, size);
                memset(block+size, m_padding, e_BLOCKSIZE-size);
                DecryptBlock(out+outlen, block);
            }
        }
        return outlen;
    }

protected:

    typedef BYTE tBlock[e_BLOCKSIZE];
    typedef BYTE tKey[e_BLOCKSIZE*3];
    typedef uint32 tSchedule[32];

    static const uint32 m_setkey[8][64];
    static const uint32 m_encrypt[8][64];

    tKey m_key;
    tBlock m_iv;
    tSchedule m_schedule[3];

    /**
     **********************************************************************
     * Function: InitSchedule
     *
     *   Author: $author$
     *     Date: 1/9/2005
     **********************************************************************
     */
    void InitSchedule
    (tSchedule schedule, const tBlock key);
    /**
     **********************************************************************
     * Function: Encode
     *
     *   Author: $author$
     *     Date: 1/9/2005
     **********************************************************************
     */
    void Encode
    (uint32 data[2], tSchedule schedule);
    /**
     **********************************************************************
     * Function: Decode
     *
     *   Author: $author$
     *     Date: 1/9/2005
     **********************************************************************
     */
    void Decode
    (uint32 data[2], tSchedule schedule);
    /**
     **********************************************************************
     * Function: EncryptBlock
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual void EncryptBlock
    (tBlock out, const tBlock in);
    /**
     **********************************************************************
     * Function: DecryptBlock
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual void DecryptBlock
    (tBlock out, const tBlock in);
};

/**
 **********************************************************************
 *  Class: cDES3
 *
 * Author: $author$
 *   Date: 1/10/2005
 **********************************************************************
 */
class cDES3
: public cDES
{
public:
    typedef cDES cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/10/2005
     **********************************************************************
     */
    enum
    {
        e_KEYMIN    = cIs::e_KEYMIN*3,
        e_KEYMAX    = cIs::e_KEYMAX*3,
        e_KEYSIZE   = cIs::e_KEYSIZE*3,
    };

    /**
     **********************************************************************
     * Constructor: cDES3
     *
     *      Author: $author$
     *        Date: 1/10/2005
     **********************************************************************
     */
    cDES3() 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     BYTE padding=0)
    {
        int length = e_KEYMAX+e_IVMAX;

        if (0 > keylen)
            keylen = (int)strlen((const char*)key);

        if (e_KEYMIN > keylen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        if (e_KEYMAX < keylen)
            return -e_ERROR_PARAMETER_SIZE_OVER;

        CopyRepeat(m_key, e_KEYMAX, key, keylen);

        if (iv)
        {
            if (0 > ivlen)
                ivlen = (int)strlen((const char*)iv);

            if (e_IVMIN > ivlen)
                return -e_ERROR_PARAMETER_SIZE_UNDER;

            if (e_IVMAX < ivlen)
                return -e_ERROR_PARAMETER_SIZE_OVER;

            CopyRepeat(m_iv, e_IVMAX, iv, ivlen);
        }
        else
        {
            if (e_IVMAX < keylen)
                keylen = e_IVMAX;

            CopyRepeat(m_iv, e_IVMAX, key, keylen);
        }

        m_padding = padding;
        InitSchedule(m_schedule[0], m_key);
        InitSchedule(m_schedule[1], m_key+8);
        InitSchedule(m_schedule[2], m_key+16);
        return length;
    }
    /**
     **********************************************************************
     * Function: EncryptBlock
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual void EncryptBlock
    (tBlock out, const tBlock in);
    /**
     **********************************************************************
     * Function: DecryptBlock
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual void DecryptBlock
    (tBlock out, const tBlock in);
};

#endif /* _CDES_HXX */
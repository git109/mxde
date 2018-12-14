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
 *   File: caes.hxx
 *
 * Author: $author$
 *   Date: 11/3/2007
 *
 **********************************************************************
 */
#ifndef _CAES_HXX
#define _CAES_HXX

#include "ccipher.hxx"

/**
 **********************************************************************
 *  Class: cAES
 *
 * Author: $author$
 *   Date: 11/3/2007
 **********************************************************************
 */
class cAES
: public cCipher
{
public:
    typedef cCipher cExtends;
    typedef cAES cDerives;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 11/3/2007
     **********************************************************************
     */
    enum
    {
        e_BLOCKSIZE = 16,

        e_KEYMIN    = 16,
        e_KEYMAX    = 32,
        e_KEYINC    = 8,
        e_KEYSIZE   = 16,

        e_IVMIN     = 16,
        e_IVMAX     = 16,
        e_IVINC     = 16,
        e_IVSIZE    = 16
    };

//protected:

    typedef BYTE tBlock[e_BLOCKSIZE];
    typedef BYTE tKey[e_KEYMAX];

    unsigned m_keysize;
    tKey m_key;
    tBlock m_iv;

    unsigned nr;
    uint32* rk;
    uint32 buf[68];

public:

    /**
     **********************************************************************
     * Constructor: cAES
     *
     *      Author: $author$
     *        Date: 11/3/2007
     **********************************************************************
     */
    cAES() 
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     BYTE padding=0)
    {
        int length = e_IVMAX;

        if (0 > keylen)
            keylen = (int)strlen((const char*)key);

        if (e_KEYMIN > keylen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        if (e_KEYMAX < keylen)
            return -e_ERROR_PARAMETER_SIZE_OVER;

        CopyRepeat(m_key, e_KEYMAX, key, keylen);

        m_keysize = e_KEYMIN; 

        while (m_keysize < (unsigned)keylen)
            m_keysize += e_KEYINC;

        length += m_keysize;

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
        return length;
    }

    /**
     **********************************************************************
     * Function: Encrypt
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    virtual int Encrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        eError error;
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+e_BLOCKSIZE-1)/e_BLOCKSIZE)*e_BLOCKSIZE;

        if (outsize < outlen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        if ((error = InitEncryptKeySchedule(m_key, m_keysize)))
            return -error;

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
     *     Date: 11/3/2007
     **********************************************************************
     */
    virtual int Decrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        eError error;
        tBlock block;
        int outlen,size;

        if (0 > inlen)
            inlen = (int)strlen((const char*)in);

        outlen = ((inlen+e_BLOCKSIZE-1)/e_BLOCKSIZE)*e_BLOCKSIZE;

        if (outsize < outlen)
            return -e_ERROR_PARAMETER_SIZE_UNDER;

        if ((error = InitDecryptKeySchedule(m_key, m_keysize)))
            return -error;

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

//protected:

    /**
     **********************************************************************
     * Function: InitEncryptKeySchedule
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    eError InitEncryptKeySchedule
    (const BYTE* key,
     unsigned keysize);
    /**
     **********************************************************************
     * Function: InitDecryptKeySchedule
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    eError InitDecryptKeySchedule
    (const BYTE* key,
     unsigned keysize);
    /**
     **********************************************************************
     * Function: EncryptBlock
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    void EncryptBlock
    (tBlock out,
     const tBlock in);
    /**
     **********************************************************************
     * Function: DecryptBlock
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    void DecryptBlock
    (tBlock out,
     const tBlock in);
    /**
     **********************************************************************
     * Function: EncodeBlock
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    void EncodeBlock
    (tBlock output,
     const tBlock input);
    /**
     **********************************************************************
     * Function: DecodeBlock
     *
     *   Author: $author$
     *     Date: 11/3/2007
     **********************************************************************
     */
    void DecodeBlock
    (tBlock output,
     const tBlock input);
};
#endif /* _CAES_HXX */

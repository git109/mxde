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
 *   File: cx509verifier.hxx
 *
 * Author: $author$
 *   Date: 2/3/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509VERIFIER_HXX
#define _CX509VERIFIER_HXX

#include "cpkcs1encryptionblock.hxx"
#include "cx509signatureparser.hxx"
#include "cx509publickey.hxx"
#include "cx509signature.hxx"
#include "cRSApublickey.hxx"
#include "cMD5.hxx"
#include "cSHA1.hxx"

/**
 **********************************************************************
 *  Class: cX509Verifier
 *
 * Author: $author$
 *   Date: 2/3/2005
 **********************************************************************
 */
class cX509Verifier
{
public:
    typedef eError (cX509Verifier::*mVerify)
    (const cX509Signature &signature,
     const cX509PublicKey &public_key);

    cHash &m_md5, &m_sha1;
    cRSAPublicKey &m_rsa_public_key;
    cBYTEBuffer m_decrypted_signature;
    cPKCS1EncryptionBlock m_encryption_block;
    cX509Hash m_signature_hash;
    cX509SignatureParser m_signature_parser;

    mVerify m_verify;

    /**
     **********************************************************************
     * Constructor: cX509Verifier
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cX509Verifier
    (cHash &md5, cHash &sha1,
     cRSAPublicKey &rsa_public_key) 
    : m_md5(md5),
      m_sha1(sha1),
      m_rsa_public_key(rsa_public_key),
      m_signature_parser(&m_signature_hash),
      m_verify(DefaultVerify)
    {
    }
    /**
     **********************************************************************
     * Function: Verify
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    virtual eError Verify
    (const cX509Signature &signature,
     const cX509PublicKey &public_key)
    {
        eError error = e_ERROR_FAILED;

        if (m_verify)
            error = (this->*m_verify)
            (signature, public_key);

        return error;
    }

    /**
     **********************************************************************
     * Function: RSAMD5Verify
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError RSAMD5Verify
    (const cX509Signature &signature,
     const cX509PublicKey &public_key)
    {
        eError error;

        if (!(error = RSADecryptHash(signature, public_key)))
            error = RSAMD5VerifyHash(signature);

        return error;
    }
    /**
     **********************************************************************
     * Function: RSASHA1Verify
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    eError RSASHA1Verify
    (const cX509Signature &signature,
     const cX509PublicKey &public_key)
    {
        eError error;

        if (!(error = RSADecryptHash(signature, public_key)))
            error = RSASHA1VerifyHash(signature);

        return error;
    }
    /**
     **********************************************************************
     * Function: DefaultVerify
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    eError DefaultVerify
    (const cX509Signature &signature,
     const cX509PublicKey &public_key)
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: RSADecryptHash
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    eError RSADecryptHash
    (const cX509Signature &signature,
     const cX509PublicKey &public_key)
    {
        eError error = e_ERROR_FAILED;
        BYTE *decrypted_signature;
        const BYTE *rsa_signature, *rsa_modulus, *rsa_exponent;
        int rsa_signature_length, rsa_modulus_length, rsa_exponent_length;

        if ((rsa_signature = signature.
            GetSignature(rsa_signature_length)))

        if ((rsa_modulus = public_key.
            GetRSAModulus(rsa_modulus_length)))

        if (rsa_signature_length == rsa_modulus_length)

        if (rsa_modulus_length == (rsa_signature_length
            = m_decrypted_signature.SetLength(rsa_modulus_length)))

        if ((decrypted_signature = m_decrypted_signature
            .GetWriteBuffer()))

        if ((rsa_exponent = public_key.
            GetRSAExponent(rsa_exponent_length)))

        if (!(error = m_rsa_public_key.CreateMSB
            (rsa_modulus, rsa_modulus_length,
             rsa_exponent, rsa_exponent_length)))
        {
            for (int i=0; i<rsa_modulus_length; i++)
                printf("%2.2X", rsa_signature[i]);
            printf("\n");
            for (i=0; i<rsa_modulus_length; i++)
                printf("%2.2X", rsa_modulus[i]);
            printf("\n");
            for (i=0; i<rsa_exponent_length; i++)
                printf("%2.2X", rsa_exponent[i]);
            printf("\n");

            if (rsa_modulus_length == (rsa_signature_length =
                m_rsa_public_key.Decrypt
                (decrypted_signature, rsa_modulus_length,
                 rsa_signature, rsa_modulus_length)))
            {
                for (i=0; i<rsa_modulus_length; i++)
                    printf("%2.2X", decrypted_signature[i]);
                printf("\n");

                error = e_ERROR_NONE;
            }
            m_rsa_public_key.Destroy();
        }

        return error;
    }

    /**
     **********************************************************************
     * Function: RSAMD5VerifyHash
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    eError RSAMD5VerifyHash
    (const cX509Signature &signature)
    {
        eError error;
        const BYTE *hash;
        int length;

        if (!(error = ParseHash(signature)))
        if ((hash = signature.GetHash(length)))
            error = m_signature_hash.MD5Verify(hash, length);
        else error = e_ERROR_FAILED;

        return error;
    }
    /**
     **********************************************************************
     * Function: RSASHA1VerifyHash
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError RSASHA1VerifyHash
    (const cX509Signature &signature)
    {
        eError error;
        const BYTE *hash;
        int length;

        if (!(error = ParseHash(signature)))
        if ((hash = signature.GetHash(length)))
            error = m_signature_hash.SHA1Verify(hash, length);
        else error = e_ERROR_FAILED;

        return error;
    }
    /**
     **********************************************************************
     * Function: ParseHash
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError ParseHash
    (const cX509Signature &signature)
    {
        eError error = e_ERROR_NONE;
        cBYTEStream &signature_data = m_encryption_block.m_data;
        int length;

        if (0 > (length = m_decrypted_signature.Seek(0)))
            return -length;

        if (0 > (length = m_encryption_block.
            Read(m_decrypted_signature)))
           return -length;

        if (0 > (length = m_signature_parser.Parse(signature_data)))
            return -length;

        return error;
    }

    /**
     **********************************************************************
     * Function: SetRSAMD5Verify
     *
     *   Author: $author$
     *     Date: 2/4/2005
     **********************************************************************
     */
    inline eError SetRSAMD5Verify() 
    {
        eError error = e_ERROR_NONE;
        m_verify = RSAMD5Verify;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetRSASHA1Verify
     *
     *   Author: $author$
     *     Date: 2/4/2005
     **********************************************************************
     */
    inline eError SetRSASHA1Verify() 
    {
        eError error = e_ERROR_NONE;
        m_verify = RSASHA1Verify;
        return error;
    }
};

#endif /* _CX509VERIFIER_HXX */
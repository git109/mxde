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
 *   File: cx509parser.hxx
 *
 * Author: $author$
 *   Date: 1/30/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509PARSER_HXX
#define _CX509PARSER_HXX

#include "casn1parser.hxx"
#include "chash.hxx"
#include "cx509verifier.hxx"
#include "cx509publickey.hxx"
#include "cx509signature.hxx"
#include "cx509hashedbytestream.hxx"

/**
 **********************************************************************
 *  Class: cX509Parser
 *
 * Author: $author$
 *   Date: 1/30/2005
 **********************************************************************
 */
class cX509Parser
: public cASN1Parser
{
public:
    typedef cASN1Parser cIs;

    typedef eError (cX509Parser::*mOnLengthof)
    (cASN1Lengthof &lengthof);

    typedef eError (cX509Parser::*mOnInteger)
    (cBYTEStream &stream, unsigned length);

    typedef eError (cX509Parser::*mOnOctetString)
    (cBYTEStream &stream, unsigned length);

    typedef eError (cX509Parser::*mOnBitString)
    (cBYTEStream &stream, unsigned length, unsigned minus_bits);

    cHash &m_md5, &m_sha1;
    cX509Verifier *m_verifier;
    cX509PublicKey *m_public_key;
    cX509Signature *m_signature;

    mOnLengthof m_on_lengthof;
    mOnInteger m_on_integer;
    mOnOctetString m_on_octet_string;
    mOnBitString m_on_bit_string;

    unsigned m_hashed;

    /**
     **********************************************************************
     * Constructor: cX509Parser
     *
     *      Author: $author$
     *        Date: 1/30/2005
     **********************************************************************
     */
    cX509Parser(cHash &md5, cHash &sha1)
    : m_md5(md5),
      m_sha1(sha1),
      m_verifier(0),
      m_public_key(0),
      m_signature(0),
      m_on_lengthof(DefaultOnLengthof),
      m_on_integer(DefaultOnInteger),
      m_on_octet_string(DefaultOnOctetString),
      m_on_bit_string(DefaultOnBitString),
      m_hashed(0)
    {
    }
    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int Parse
    (cX509Verifier &verifier,
     cX509PublicKey &public_key, 
     cX509Signature &signature,
     cBYTEStream &stream) 
    {
        cX509Verifier *old_verifier = m_verifier;
        cX509PublicKey *old_public_key = m_public_key;
        cX509Signature *old_signature = m_signature;
        int length;

        public_key.SetNoneAlgorithm();

        m_verifier = &verifier;
        m_public_key = &public_key;
        m_signature = &signature;

        length = Parse(stream);

        m_signature = old_signature;
        m_public_key = old_public_key;
        m_verifier = old_verifier;
        return length;
    }
    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int Parse(cBYTEStream &stream) 
    {
        int length;

        m_hashed = 0;

        if (0 > (length = m_md5.Initialize()))
            return length;

        if (0 > (length = m_sha1.Initialize()))
            return length;

        m_on_lengthof = StartOnLengthof;
        length = ParseHashed(stream);
        return length;
    }
    /**
     **********************************************************************
     * Function: ParseHashed
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int ParseHashed(cBYTEStream &stream) 
    {
        cX509HashedBYTEStream hashed
        (m_hashed, stream, m_md5, m_sha1);

        int length = ParseInto(hashed);
        return length;
    }

    /**
     **********************************************************************
     * Function: OnRSAModulus
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnRSAModulus
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        int byte, size;

        if (!m_public_key)
            return error;

        if (0 > (size = m_public_key->
            m_rsa_modulus.Clear()))
            return -size;

        for (; length>0; --length)
        {
            if (0 > (byte = stream.Getb()))
                return -byte;

            if (0 < byte)
            if (0 > (byte = m_public_key->
                m_rsa_modulus.Putb(byte)))
                return -byte;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRSAExponent
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnRSAExponent
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        int byte, size;

        if (!m_public_key)
            return error;

        if (0 > (size = m_public_key->
            m_rsa_exponent.Clear()))
            return -size;

        for (; length>0; --length)
        {
            if (0 > (byte = stream.Getb()))
                return -byte;

            //if (0 < byte)
            if (0 > (byte = m_public_key->
                m_rsa_exponent.Putb(byte)))
                return -byte;
        }

        m_public_key->SetRSAAlgorithm();
        return error;
    }

    /**
     **********************************************************************
     * Function: OnRSAMD5Signature
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnRSAMD5Signature
    (cBYTEStream &stream, unsigned length) 
    {
        eError error;

        if (!(error = OnSignature(m_md5, stream, length)))
        if (m_verifier)
            error = m_verifier->SetRSAMD5Verify();

        return error;
    }
    /**
     **********************************************************************
     * Function: OnRSASHA1Signature
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnRSASHA1Signature
    (cBYTEStream &stream, unsigned length) 
    {
        eError error;

        if (!(error = OnSignature(m_sha1, stream, length)))
        if (m_verifier)
            error = m_verifier->SetRSASHA1Verify();

        return error;
    }
    /**
     **********************************************************************
     * Function: OnSignature
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnSignature
    (cHash &hash, cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        BYTE *hash_value;
        int size;

        if (!m_signature)
            return error;

        if (length != (size = m_signature->
            m_signature.CopyStream(stream, length)))
        if (0 > size)
            return -size;
        else return e_ERROR_FAILED;

        length = hash.GetHashSize();

        if (length != (size = m_signature->
            m_hash.SetLength(length)))
        if (0 > size)
            return -size;
        else return e_ERROR_FAILED;

        if (!(hash_value = m_signature->
            m_hash.GetWriteBuffer()))
            return e_ERROR_FAILED;

        if (length != (size = hash
            .Finalize(hash_value, length)))
        if (0 > size)
            return -size;
        else return e_ERROR_FAILED;

        for (int i=0; i<length; i++)
            printf("%2.2X", hash_value[i]);
        printf("\n");

        return error;
    }

    /**
     **********************************************************************
     * Function: OnTypeof
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnTypeof(cASN1Typeof &typeof) 
    {
        eError error = e_ERROR_NONE;
        const char *name = typeof.GetName();

        printf("%s", name);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLengthof
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnLengthof(cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        unsigned length = lengthof.GetValue();

        printf("[%u]\n", length);

        if (m_on_lengthof)
            error = (this->*m_on_lengthof)(lengthof);

        return error;
    }
    /**
     **********************************************************************
     * Function: DefaultOnLengthof
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    eError DefaultOnLengthof(cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: StartOnLengthof
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    eError StartOnLengthof(cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        m_hashed = lengthof.GetValue();
        m_on_lengthof = HashedOnLengthof;
        return error;
    }
    /**
     **********************************************************************
     * Function: HashedOnLengthof
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    eError HashedOnLengthof(cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        m_hashed = lengthof.GetValue();
        m_on_lengthof = DefaultOnLengthof;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnObjectIDValue
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnObjectIDValue
    (const cASN1ObjectIdentifier &id) 
    {
        eError error = e_ERROR_NONE;
        const char *id_name = id.GetName();
        int id_type = id.GetType();

        printf("%s\n", id_name);

        switch(id_type)
        {
        case cASN1ObjectIdentifier::e_authorityKeyIdentifier:
            m_on_octet_string = authorityKeyIdentifierOnOctetString;
            break;

        case cASN1ObjectIdentifier::e_rsaEncryption:
            m_on_bit_string = rsaEncryptionOnBitString;
            break;

        case cASN1ObjectIdentifier::e_md5WithRSA:
        case cASN1ObjectIdentifier::e_md5WithRSAEncryption:
            m_on_bit_string = md5WithRSAEncryptionOnBitString;
            break;

        case cASN1ObjectIdentifier::e_sha1WithRSA:
        case cASN1ObjectIdentifier::e_sha1WithRSAEncryption:
            m_on_bit_string = sha1WithRSAEncryptionOnBitString;
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnInteger
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnInteger
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = (this->*m_on_integer)(stream, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: DefaultOnInteger
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError DefaultOnInteger
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: rsaModulusOnInteger
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError rsaModulusOnInteger
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = OnRSAModulus(stream, length);
        m_on_integer = rsaExponentOnInteger;
        return error;
    }
    /**
     **********************************************************************
     * Function: rsaExponentOnInteger
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError rsaExponentOnInteger
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = OnRSAExponent(stream, length);
        m_on_integer = DefaultOnInteger;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOctetString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = (this->*m_on_octet_string)(stream, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: DefaultOnOctetString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError DefaultOnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: authorityKeyIdentifierOnOctetString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError authorityKeyIdentifierOnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        m_on_octet_string = DefaultOnOctetString;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitStringValue
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnBitStringValue
    (cBYTEStream &stream, unsigned length, unsigned minus_bits) 
    {
        eError error = (this->*m_on_bit_string)
        (stream, length, minus_bits);
        return error;
    }
    /**
     **********************************************************************
     * Function: DefaultOnBitString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError DefaultOnBitString
    (cBYTEStream &stream, unsigned length, unsigned minus_bits) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: rsaEncryptionOnBitString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError rsaEncryptionOnBitString
    (cBYTEStream &stream, unsigned length, unsigned minus_bits) 
    {
        eError error = e_ERROR_NONE;
        int count;

        m_on_integer = rsaModulusOnInteger;

        if (0 > (count = ParseInto(stream)))
            error = -count;

        m_on_integer = DefaultOnInteger;
        m_on_bit_string = DefaultOnBitString;
        return error;
    }
    /**
     **********************************************************************
     * Function: md5WithRSAEncryptionOnBitString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError md5WithRSAEncryptionOnBitString
    (cBYTEStream &stream, unsigned length, unsigned minus_bits) 
    {
        eError error = OnRSAMD5Signature(stream, length);
        m_on_bit_string = DefaultOnBitString;
        return error;
    }
    /**
     **********************************************************************
     * Function: sha1WithRSAEncryptionOnBitString
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    eError sha1WithRSAEncryptionOnBitString
    (cBYTEStream &stream, unsigned length, unsigned minus_bits) 
    {
        eError error = OnRSASHA1Signature(stream, length);
        m_on_bit_string = DefaultOnBitString;
        return error;
    }
};

#endif /* _CX509PARSER_HXX */
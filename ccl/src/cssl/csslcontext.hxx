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
 *   File: csslcontext.hxx
 *
 * Author: $author$
 *   Date: 1/18/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCONTEXT_HXX
#define _CSSLCONTEXT_HXX

#include "csslserverkey.hxx"
#include "csslclientkey.hxx"
#include "csslkeyblock.hxx"
#include "csslsecret.hxx"
#include "csslmastersecret.hxx"
#include "csslchangecipherspec.hxx"
#include "csslrsaclientkeyexchangetype.hxx"
#include "csslclientkeyexchange.hxx"
#include "cssltime.hxx"
#include "csslhandshake.hxx"
#include "csslpad.hxx"
#include "chashstream.hxx"
#include "cx509parser.hxx"
#include "casn1parser.hxx"
#include "crsapublickey.hxx"

/**
 **********************************************************************
 *  Class: cSSLContext
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
class cSSLContext
{
public:
    cSSLTime &m_time;
    cBYTEStream &m_random;

    cHash &m_md5;
    cHash &m_sha1;

    cHashStream m_finished_md5;
    cHashStream m_finished_sha1;

    cRSAPublicKey &m_rsa_public_key;

    cSSLSignatureType *m_suite_signature_type;
    cSSLKeyExchangeType *m_suite_key_exchange_type;
    cSSLCipherType *m_suite_cipher_type;
    cSSLHashType *m_suite_hash_type;

    cSSLMD5Pad1 m_md5_pad1;
    cSSLMD5Pad2 m_md5_pad2;
    cSSLSHA1Pad1 m_sha1_pad1;
    cSSLSHA1Pad2 m_sha1_pad2;
    cSSLPad *m_pad1, *m_pad2;

    cSSLPlaintext m_plaintext;

    cX509PublicKey m_certificate_public_key[2];
    cX509Signature m_certificate_signature[2];
    cX509Verifier m_certificate_verifier_1,
                  m_certificate_verifier_2;
    cX509Parser m_certificate_parser;

    cSSLVersion m_version;
    cSSLMasterSecret m_master_secret;
    cSSLPreMasterSecret m_pre_master_secret;
    cSSLKeyExchangeType m_key_exchange_type;

    cSSLKeyBlock m_keyblock;
    cSSLSecret m_client_MAC_secret,
               m_server_MAC_secret;

    cSSLClientKey m_client_key;
    cSSLServerKey m_server_key;

    cSSLChangeCipherSpec m_change_cipher_spec;

    /**
     **********************************************************************
     * Constructor: cSSLContext
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cSSLContext
    (cSSLTime &time,
     cBYTEStream &random,
     cHash &md5, cHash &finished_md5,
     cHash &sha1, cHash &finished_sha1,
     cRSAPublicKey &rsa_public_key)
    : m_time(time),
      m_random(random),

      m_md5(md5), 
      m_sha1(sha1),

      m_finished_md5(finished_md5), 
      m_finished_sha1(finished_sha1),

      m_rsa_public_key(rsa_public_key),

      m_suite_signature_type(0),
      m_suite_key_exchange_type(0),
      m_suite_cipher_type(0),
      m_suite_hash_type(0),

      m_pad1(&m_md5_pad1),
      m_pad2(&m_md5_pad2),

      m_certificate_verifier_1(md5, sha1, rsa_public_key),
      m_certificate_verifier_2(md5, sha1, rsa_public_key),
      m_certificate_parser(md5, sha1),

      m_keyblock(md5, sha1)
    {
    }

    /**
     **********************************************************************
     * Function: AcceptCertificateChain
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    virtual eError AcceptCertificateChain(cSSLHandshake &handshake) 
    {
        eError error = e_ERROR_NONE;
        cSSLCertificateChain &certificate_chain = handshake.GetCertificateChain();
        const cSSLCertificate *certificate, *last_certificate;
        cX509Verifier *certificate_verifier[2];
        int certificate_index, 
            certificate_authority_index,
            last_certificate_index;

        if ((certificate = certificate_chain.GetFirstCertificate()))
        {
            last_certificate = 0;
            last_certificate_index = 0;
            certificate_authority_index = 0;
            certificate_index = 1;
            certificate_verifier[0] = &m_certificate_verifier_1;
            certificate_verifier[1] = &m_certificate_verifier_2;

            do
            {
                if ((error = ParseCertificate
                    (*certificate_verifier[certificate_authority_index],
                     m_certificate_public_key[certificate_authority_index],
                     m_certificate_signature[certificate_authority_index],
                     *certificate)))
                    return error;

                if (last_certificate)
                {
                    if ((error = VerifyCertificate
                        (m_certificate_public_key[certificate_authority_index],
                         *certificate_verifier[certificate_index],
                         m_certificate_signature[certificate_index],
                         *last_certificate)))
                         return error;
                }
                else
                {
                    if ((error = AcceptFirstCertificate
                        (m_certificate_public_key[certificate_authority_index],
                         *certificate_verifier[certificate_authority_index],
                         m_certificate_signature[certificate_authority_index],
                         *certificate)))
                         return error;
                }
                last_certificate = certificate;
                last_certificate_index = certificate_authority_index;

                if ((certificate = certificate_chain.GetNextCertificate()))
                {
                    certificate_authority_index = (certificate_authority_index+1) & 1;
                    certificate_index = (certificate_index+1) & 1;
                }
            }
            while (certificate);

            if (last_certificate)
                error = VerifyLastCertificate
                (m_certificate_public_key[last_certificate_index],
                 *certificate_verifier[last_certificate_index],
                 m_certificate_signature[last_certificate_index],
                 *last_certificate);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: VerifyCertificate
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    virtual eError VerifyCertificate
    (cX509PublicKey &certificate_authority_public_key,
     cX509Verifier &certificate_verifier,
     cX509Signature &certificate_signature,
     const cSSLCertificate &certificate) 
    {
        eError error = certificate_verifier.Verify
        (certificate_signature, certificate_authority_public_key);
        return error;
    }
    /**
     **********************************************************************
     * Function: VerifyLastCertificate
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    virtual eError VerifyLastCertificate
    (cX509PublicKey &certificate_public_key,
     cX509Verifier &certificate_verifier,
     cX509Signature &certificate_signature,
     const cSSLCertificate &certificate) 
    {
        eError error = VerifyCertificate
        (certificate_public_key, certificate_verifier, 
         certificate_signature, certificate);
        return error;
    }
    /**
     **********************************************************************
     * Function: AcceptFirstCertificate
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    virtual eError AcceptFirstCertificate
    (cX509PublicKey &certificate_public_key,
     cX509Verifier &certificate_verifier,
     cX509Signature &certificate_signature,
     const cSSLCertificate &certificate) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseCertificate
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    virtual eError ParseCertificate
    (cX509Verifier &certificate_verifier,
     cX509PublicKey &certificate_public_key,
     cX509Signature &certificate_signature,
     const cSSLCertificate &certificate) 
    {
        eError error = e_ERROR_NONE;
        const BYTE *bytes;
        int length;

        if ((bytes = certificate.GetBytes(length)))
        {
            cBYTEBuffer buffer(bytes, length, length);

            if (0 > (length = m_certificate_parser.Parse
                (certificate_verifier, certificate_public_key, 
                 certificate_signature, buffer)))
                error = -length;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: FinishedInitialize
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    int FinishedInitialize() 
    {
        int length;

        if (0 > (length = m_finished_md5.Initialize()))
            return length;

        length = m_finished_sha1.Initialize();
        return length;
    }
    /**
     **********************************************************************
     * Function: FinishedFinalize
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    int FinishedFinalize() 
    {
        int length;
        return length;
    }
    /**
     **********************************************************************
     * Function: FinishedHash
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    int FinishedHash
    (const cSSLHandshake &handshake, bool no_finished=false) 
    {
        int length;

        if (no_finished)
        if (handshake.e_FINISHED == handshake.m_type)
            return 0;

        if (0 > (length = handshake.Write(m_finished_md5)))
            return length;

        length = handshake.Write(m_finished_sha1);
        return length;
    }

    /**
     **********************************************************************
     * Function: CreateSecrets
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    virtual eError CreateSecrets() 
    {
        cSSLHandshake &handshake = m_plaintext.GetHandshake();
        cSSLClientHello &client_hello = handshake.GetClientHello();
        cSSLServerHello &server_hello = handshake.GetServerHello();
        eError error = e_ERROR_FAILED;
        int hash_size, size;

        if (m_suite_cipher_type)
        if (m_suite_hash_type)
        if (0 < (hash_size = m_suite_hash_type->GetHashSize()))
        if (0 <= (size = m_keyblock.Initialize()))

        if (0 < (size = m_master_secret.Set
            (m_pre_master_secret, client_hello, 
             server_hello, m_md5, m_sha1)))

        if (0 < (size = m_client_MAC_secret.Set
            (m_keyblock, m_master_secret, 
             client_hello, server_hello, hash_size)))

        if (0 < (size = m_server_MAC_secret.Set
            (m_keyblock, m_master_secret, 
             client_hello, server_hello, hash_size)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: CreateKeys
     *
     *   Author: $author$
     *     Date: 3/12/2005
     **********************************************************************
     */
    virtual eError CreateKeys() 
    {
        cSSLHandshake &handshake = m_plaintext.GetHandshake();
        cSSLClientHello &client_hello = handshake.GetClientHello();
        cSSLServerHello &server_hello = handshake.GetServerHello();
        eError error = e_ERROR_FAILED;
        int size;

        if (m_suite_cipher_type)

        if (0 < (size = m_client_key.Set
            (m_keyblock, m_master_secret, 
             client_hello, server_hello, 
             *m_suite_cipher_type, m_md5)))

        if (0 < (size = m_server_key.Set
            (m_keyblock, m_master_secret, 
             client_hello, server_hello, 
             *m_suite_cipher_type, m_md5)))
             error = e_ERROR_NONE;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cSSLClientContext
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
class cSSLClientContext
: public cSSLContext
{
public:
    typedef cSSLContext cIs;

    typedef int 
    (cSSLClientContext::*mOnReceiveHandshake)
    (cSSLHandshake& handshake);

    typedef int (cSSLClientContext::*mOnRespondHello)
    (cBYTEStream &stream);

    cSSLCipherSuites& m_suites;
    cSSLCompressionMethods& m_methods;

    mOnReceiveHandshake m_on_receive_handshake;
    mOnRespondHello m_on_respond_hello, 
                    m_on_respond_certificate, 
                    m_on_respond_certificate_verify;

    bool m_am_receiving_hello, 
         m_am_responding_hello;

    cSSLRSAClientKeyExchangeType m_rsa_client_key_exchange_type;

    /**
     **********************************************************************
     * Constructor: cSSLClientContext
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cSSLClientContext
    (cSSLTime &time,
     cBYTEStream &random,
     cHash &md5, cHash &finished_md5,
     cHash &sha1, cHash &finished_sha1,
     cRSAPublicKey &rsa_public_key,
     cSSLCipherSuites& suites,
     cSSLCompressionMethods& methods) 
    : cIs
      (time, random, 
       md5, finished_md5, 
       sha1, finished_sha1,
       rsa_public_key),
      m_suites(suites),
      m_methods(methods),
      m_on_receive_handshake(0),
      m_on_respond_hello(0),
      m_on_respond_certificate(0),
      m_on_respond_certificate_verify(0),
      m_am_receiving_hello(false),
      m_am_responding_hello(false)
    {
    }

    /**
     **********************************************************************
     * Function: AcceptFirstCertificate
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    virtual eError AcceptFirstCertificate
    (cX509PublicKey &certificate_public_key,
     cX509Verifier &certificate_verifier,
     cX509Signature &certificate_signature,
     const cSSLCertificate &certificate) 
    {
        eError error = e_ERROR_FAILED;
        int suite_algorithm, 
            exchange_algorithm, 
            certificate_algorithm;
        cSSLRSAClientKeyExchangeType *rsa_client;
        const BYTE *modulus, *exponent;
        int modsize, expsize;

        if (m_suite_key_exchange_type)
        if ((suite_algorithm = m_suite_key_exchange_type->GetAlgorithm())
            == (exchange_algorithm = m_key_exchange_type.GetAlgorithm()))
        if (exchange_algorithm == (certificate_algorithm = certificate_public_key.GetAlgorithm()))            
        {
            switch(exchange_algorithm)
            {
            case cKeyExchangeAlgorithm::e_RSA:
                if ((rsa_client = m_key_exchange_type.GetRSAClient()))
                if ((modulus = certificate_public_key.
                    GetRSAModulus(modsize)))
                if ((exponent = certificate_public_key.
                    GetRSAExponent(expsize)))
                    error = rsa_client->Set
                    (modulus, modsize, exponent, expsize);
                break;

            default:
                return e_ERROR_INVALID_PARAMETER_TYPE;
            }
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: SendHello
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    virtual int SendHello(cBYTEStream &stream) 
    {
        cSSLHandshake& handshake = m_plaintext.GetHandshake();
        cSSLClientHello& hello = handshake.GetClientHello();
        cSSLHelloHeader& header = hello.GetHeader();
        cSSLVersion& version = header.GetVersion();
        cSSLRandom& random = header.GetRandom();
        cSSLSessionID& session = header.GetSession();
        cSSLCipherSuites& suites = hello.GetSuites();
        cSSLCompressionMethods& methods = hello.GetMethods();
        int size;

        if (0 > (size = FinishedInitialize()))
            return size;

        if (0 > (size = version.Set()))
            return size;

        if (0 > (size = random.Set
            (m_time.GetGMTUnixTime(), m_random)))
            return size;

        if (0 > (size = session.Set()))
            return size;

        if (0 > (size = header.Set(version, random, session)))
            return size;

        if (0 > (size = suites.Copy(m_suites)))
            return size;

        if (0 > (size = methods.Copy(m_methods)))
            return size;

        if (0 > (size = hello.Set(header, suites, methods)))
            return size;

        if (0 > (size = handshake.Set(hello)))
            return size;

        if (0 > (size = FinishedHash(handshake)))
            return size;

        if (0 > (size = m_plaintext.Set(version, handshake)))
            return size;

        size = m_plaintext.Write(stream);
        return size;
    }
    /**
     **********************************************************************
     * Function: ReceiveHello
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    virtual int ReceiveHello(cBYTEStream &stream) 
    {
        int size;
        uint8 type;

        m_am_receiving_hello = true;
        m_on_receive_handshake = OnReceiveHello;
        m_on_respond_certificate = OnRespondClientKeyExchange;
        m_on_respond_certificate_verify = OnRespondNoCertificateVerify;

        do
        {
            if (0 >  (size = m_plaintext.Read(stream)))
                return size;

            if (m_plaintext.e_HANDSHAKE != 
                (type = m_plaintext.GetType()))
                return size = -e_ERROR_INVALID_RETURN_TYPE;
            else
            {
                cSSLHandshake& handshake = m_plaintext.GetHandshake();

                if (0 > (size = FinishedHash(handshake, true)))
                    return size;

                if (0 > (size = OnReceiveHandshake(handshake)))
                    return size;
            }
        }
        while (m_am_receiving_hello);
        return size;
    }
    /**
     **********************************************************************
     * Function: RespondHello
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    virtual int RespondHello(cBYTEStream &stream) 
    {
        int count, size = 0;

        m_am_responding_hello = true;
        m_on_respond_hello = m_on_respond_certificate;

        do
        {
            if (0 > (count = OnRespondHello(stream)))
                return count;

            size += count;
        }
        while (m_am_responding_hello);

        return size;
    }

    /**
     **********************************************************************
     * Function: OnRespondHello
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    virtual int OnRespondHello(cBYTEStream &stream) 
    {
        int size = -e_ERROR_NOT_INITIALIZED;

        if (m_on_respond_hello)
            size = (this->*m_on_respond_hello)(stream);

        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondCertificate
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int OnRespondCertificate(cBYTEStream &stream) 
    {
        int size = -e_ERROR_NOT_INITIALIZED;
        m_on_respond_hello = OnRespondClientKeyExchange;
        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondClientKeyExchange
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int OnRespondClientKeyExchange(cBYTEStream &stream) 
    {
        int size = -e_ERROR_NOT_INITIALIZED;

        m_on_respond_hello = m_on_respond_certificate_verify;

        switch(m_key_exchange_type.GetAlgorithm())
        {
        case cKeyExchangeAlgorithm::e_RSA:
            size = OnRespondRSAClientKeyExchange(stream);
            break;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondRSAClientKeyExchange
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    int OnRespondRSAClientKeyExchange(cBYTEStream &stream) 
    {
        cSSLVersion &version = m_plaintext.GetVersion();
        cSSLHandshake &handshake = m_plaintext.GetHandshake();
        cSSLClientKeyExchange &key_exchange = handshake.GetClientKeyExchange();
        int size = -e_ERROR_NOT_INITIALIZED;
        cSSLRSAClientKeyExchangeType *rsa_client;
        const BYTE *modulus, *exponent;
        int modsize, expsize;
        eError error;

        if ((rsa_client = m_key_exchange_type.GetRSAClient()))
        if ((modulus = rsa_client->GetModulus(modsize)))
        if ((exponent = rsa_client->GetExponent(expsize)))
        if (0 < (size = m_pre_master_secret.Set(m_version, m_random)))
        if (!(error = m_rsa_public_key.CreateMSB
            (modulus, modsize, exponent, expsize)))
        {
            if (0 < (size = key_exchange.
                Set(m_random, m_pre_master_secret, m_rsa_public_key)))
            if (0 < (size = handshake.Set(key_exchange)))
            if (0 < (size = m_plaintext.Set(version, handshake)))
                size = m_plaintext.Write(stream);
            m_rsa_public_key.Destroy();
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondNoCertificateVerify
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int OnRespondNoCertificateVerify(cBYTEStream &stream) 
    {
        int size = 0;
        m_on_respond_hello = OnRespondChangeCipherSpec;
        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondCertificateVerify
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int OnRespondCertificateVerify(cBYTEStream &stream) 
    {
        int size = -e_ERROR_NOT_INITIALIZED;
        m_on_respond_hello = OnRespondChangeCipherSpec;
        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondChangeCipherSpec
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int OnRespondChangeCipherSpec(cBYTEStream &stream) 
    {
        int size = -e_ERROR_FAILED;
        eError error;

        m_on_respond_hello = OnRespondFinished;

        if (!(error = CreateSecrets()))
        if (!(error = CreateKeys()))
            size = m_change_cipher_spec.Write(stream);

        return size;
    }
    /**
     **********************************************************************
     * Function: OnRespondFinished
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int OnRespondFinished(cBYTEStream &stream) 
    {
        int size = -e_ERROR_NOT_INITIALIZED;
        m_am_responding_hello = false;
        m_on_respond_hello = 0;
        return size;
    }

    /**
     **********************************************************************
     * Function: OnReceiveHandshake
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    virtual int OnReceiveHandshake(cSSLHandshake& handshake) 
    {
        int size = -e_ERROR_NOT_INITIALIZED;

        if (m_on_receive_handshake)
            size = (this->*m_on_receive_handshake)(handshake);

        return size;
    }
    /**
     **********************************************************************
     * Function: OnReceiveHello
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    virtual int OnReceiveHello(cSSLHandshake& handshake) 
    {
        uint8 type = handshake.GetType();
        int size = handshake.Sizeof();
        eError error;

        m_on_receive_handshake = OnReceiveCertificate;

        if (handshake.e_SERVER_HELLO != type)
            return size = -e_ERROR_INVALID_RETURN_TYPE;

        if ((error = AcceptHello(handshake)))
            size = -error;

        return size;
    }
    /**
     **********************************************************************
     * Function: OnReceiveCertificate
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    virtual int OnReceiveCertificate(cSSLHandshake& handshake) 
    {
        uint8 type = handshake.GetType();
        int size = handshake.Sizeof();
        eError error;

        m_on_receive_handshake = OnReceiveServerKeyExchange;

        switch(type)
        {
        case handshake.e_CERTIFICATE:
            if ((error = AcceptCertificateChain(handshake)))
                size = -error;
            break;

        case handshake.e_SERVER_KEY_EXCHANGE:
            size = OnReceiveServerKeyExchange(handshake);
            break;

        case handshake.e_CERTIFICATE_REQUEST:
            size = OnReceiveCertificateRequest(handshake);
            break;

        case handshake.e_SERVER_HELLO_DONE:
            size = OnReceiveServerHelloDone(handshake);
            break;

        default:
            return size = -e_ERROR_INVALID_RETURN_TYPE;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OnReceiveServerKeyExchange
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    virtual int OnReceiveServerKeyExchange(cSSLHandshake& handshake) 
    {
        uint8 type = handshake.GetType();
        int size = handshake.Sizeof();

        m_on_receive_handshake = OnReceiveCertificateRequest;

        switch(type)
        {
        case handshake.e_SERVER_KEY_EXCHANGE:
            break;

        case handshake.e_CERTIFICATE_REQUEST:
            size = OnReceiveCertificateRequest(handshake);
            break;

        case handshake.e_SERVER_HELLO_DONE:
            size = OnReceiveServerHelloDone(handshake);
            break;

        default:
            return size = -e_ERROR_INVALID_RETURN_TYPE;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OnReceiveCertificateRequest
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    virtual int OnReceiveCertificateRequest(cSSLHandshake& handshake) 
    {
        uint8 type = handshake.GetType();
        int size = handshake.Sizeof();

        m_on_receive_handshake = OnReceiveServerHelloDone;

        switch(type)
        {
        case handshake.e_CERTIFICATE_REQUEST:
            break;

        case handshake.e_SERVER_HELLO_DONE:
            size = OnReceiveServerHelloDone(handshake);
            break;

        default:
            return size = -e_ERROR_INVALID_RETURN_TYPE;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OnReceiveServerHelloDone
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    virtual int OnReceiveServerHelloDone(cSSLHandshake& handshake) 
    {
        uint8 type = handshake.GetType();
        int size = handshake.Sizeof();
        eError error;

        if (handshake.e_SERVER_HELLO_DONE != type)
            return size = -e_ERROR_INVALID_RETURN_TYPE;

        if ((error = AcceptHelloDone(handshake)))
            size = -error;

        return size;
    }
    /**
     **********************************************************************
     * Function: OnReceiveFinished
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    virtual int OnReceiveFinished(cSSLHandshake& handshake) 
    {
        uint8 type = handshake.GetType();
        int size = handshake.Sizeof();

        if (handshake.e_FINISHED != handshake.m_type)
            return size = -e_ERROR_INVALID_RETURN_TYPE;
        else
        {
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: AcceptHello
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    virtual eError AcceptHello(cSSLHandshake &handshake) 
    {
        eError error = e_ERROR_NOT_FOUND;
        cSSLServerHello& hello = handshake.GetServerHello();
        cSSLHelloHeader& hello_header = hello.GetHeader();
        cSSLVersion& hello_version = hello_header.GetVersion();
        cSSLRandom& hello_random = hello_header.GetRandom();
        cSSLSessionID& hello_session = hello_header.GetSession();
        cSSLCipherSuite& hello_suite = hello.GetSuite();
        cSSLCompressionMethod& hello_method = hello.GetMethod();
        const cSSLCipherSuite *suite;

        if ((suite = m_suites.Get(hello_suite)))
            error = SelectCipherSuite(*suite);

        return error;
    }
    /**
     **********************************************************************
     * Function: AcceptHelloDone
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    virtual eError AcceptHelloDone(cSSLHandshake &handshake) 
    {
        eError error = e_ERROR_NONE;
        m_am_receiving_hello = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: SelectCipherSuite
     *
     *   Author: $author$
     *     Date: 1/24/2005
     **********************************************************************
     */
    virtual eError SelectCipherSuite
    (const cSSLCipherSuite &suite) 
    {
        eError error = e_ERROR_NOT_FOUND;
        const cSSLCipherSuite *got_suite;
        int algorithm;

        if ((got_suite = m_suites.Get(suite)))
        {
            m_suite_signature_type = got_suite->GetSignatureType();
            m_suite_key_exchange_type = got_suite->GetKeyExchangeType();
            m_suite_cipher_type = got_suite->GetCipherType();
            m_suite_hash_type = got_suite->GetHashType();
            error = e_ERROR_NONE;

            if (m_suite_key_exchange_type)
            switch (algorithm = m_suite_key_exchange_type->GetAlgorithm())
            {
            case cKeyExchangeAlgorithm::e_RSA:
                m_key_exchange_type.SetRSAClient
                (m_rsa_client_key_exchange_type);
                break;

            default:
                return error = e_ERROR_INVALID_RETURN_TYPE;
            }

            if (m_suite_hash_type)
            switch (algorithm = m_suite_hash_type->GetAlgorithm())
            {
            case cHashAlgorithm::e_MD5:
                m_pad1 = &m_md5_pad1;
                m_pad2 = &m_md5_pad2;
                break;

            case cHashAlgorithm::e_SHA1:
                m_pad1 = &m_sha1_pad1;
                m_pad2 = &m_sha1_pad2;
                break;

            default:
                error = e_ERROR_INVALID_RETURN_TYPE;
            }
        }
        return error;
    }
};

#endif /* _CSSLCONTEXT_HXX */
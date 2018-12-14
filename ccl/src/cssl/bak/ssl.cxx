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
 *   File: ssl.cxx
 *
 * Author: $author$
 *   Date: 1/11/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <time.h>
#include "cmainarg.hxx"
#include "cmain.hxx"
#include "csocket.hxx"
#include "cmd5.hxx"
#include "csha1.hxx"
#include "casn1objectidentifier.hxx"
#include "casn1parser.hxx"
#include "casn1primative.hxx"
#include "casn1typeof.hxx"
#include "casn1lengthof.hxx"
#include "cpseudorandomstream.hxx"
#include "csslversion.hxx"
#include "csslrandom.hxx"
#include "csslsessionid.hxx"
#include "csslalgorithm.hxx"
#include "csslcompressionmethod.hxx"
#include "csslciphersuite.hxx"
#include "csslclienthello.hxx"
#include "csslalert.hxx"
#include "csslhandshake.hxx"
#include "csslplaintext.hxx"
#include "chashstream.hxx"
#include "csslcontext.hxx"
#include "csslrsasignaturetype.hxx"
#include "csslrsakeyexchangetype.hxx"
#include "cssldesciphertype.hxx"
#include "csslrc4ciphertype.hxx"
#include "csslmd5hashtype.hxx"
#include "csslsha1hashtype.hxx"

class c0X: public cBYTEStream
{
public:
    cCharStream &m_s;

    c0X(cCharStream &s): m_s(s)
    {
    }
    int Write(const BYTE *buffer, int length)
    {
        int i;

        for (i=0; i<length; i++)
            m_s.PrintFormatted("%2.2X", buffer[i]);

        return length;
    }
};

class cEchoBYTEStream
: public cBYTEStream
{
public:
    cBYTEStream &m_stream, &m_echo_stream;

    cEchoBYTEStream
    (cBYTEStream &stream, cBYTEStream &echo_stream)
    : m_stream(stream),
      m_echo_stream(echo_stream)
    {
    }
    int Read(BYTE *buffer, int length)
    {
        if (0 < (length = m_stream.Read(buffer, length)))
            m_echo_stream.Write(buffer, length);
        return length;
    }
    int Write(const BYTE *buffer, int length)
    {
        m_echo_stream.Write(buffer, length);
        length = m_stream.Write(buffer, length);
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cSSLMain
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */
class cSSLMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    const char *m_host;
    int m_port;
    cBYTESocket m_socket;

    /**
     **********************************************************************
     * Constructor: cSSLMain
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cSSLMain()
    : m_usage(false),
      m_host("localhost"),
      m_port(443)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        if (m_usage)
            return OnUsage(argc, argv);
/*
        {
unsigned char e[]=
{
0x01,0x00,0x01,
};
unsigned char n[] = 
{
  0xe1, 0xa1, 0x24, 0xe8, 0xd1, 0xb0, 0xd5, 0x81, 0xe7, 0xa5, 0x8a, 0x3b,
  0xb4, 0xb5, 0x84, 0xca, 0x71, 0x07, 0x36, 0x28, 0x67, 0x0b, 0x02, 0x1f,
  0x84, 0xc6, 0x70, 0x10, 0xed, 0xb1, 0x69, 0xa6, 0xc2, 0x1d, 0x7d, 0xe1,
  0x3f, 0xac, 0x8c, 0xd0, 0x04, 0x94, 0x9e, 0x5e, 0x47, 0xab, 0x7b, 0x2e,
  0x9f, 0x58, 0x69, 0x02, 0xb3, 0x6f, 0x4f, 0x79, 0xe6, 0x9c, 0x67, 0xb2,
  0xc7, 0x31, 0xf4, 0xeb, 0x9f, 0x83, 0xf9, 0xef, 0xec, 0x7e, 0xa4, 0x02,
  0x11, 0x11, 0x7d, 0x4f, 0x50, 0x57, 0x64, 0x3c, 0x22, 0x5c, 0x7d, 0x4d,
  0x8b, 0x41, 0xcf, 0x10, 0xf6, 0x23, 0x0f, 0x7b, 0xdf, 0xe6, 0x65, 0xff,
  0x63, 0x81, 0x25, 0x7f, 0xaa, 0x6e, 0xcd, 0x2c, 0xab, 0x91, 0xdf, 0x4d,
  0x22, 0xac, 0xc2, 0x8d, 0x78, 0x62, 0x21, 0x61, 0x73, 0xe8, 0x2b, 0x16,
  0x76, 0xa3, 0xa7, 0x2e, 0x87, 0xae, 0x32, 0x01, 
};
unsigned char in[] = 
{ 
  0x01, 0xA2, 0xA7, 0x73, 0xDD, 0xF2, 0xE1, 0x9D, 0x74, 0x09, 0xEA, 
  0x2C, 0x47, 0x61, 0xD6, 0x8B, 0x71, 0xFB, 0x79, 0xD8, 0x2C, 0x9A, 
  0x94, 0xCA, 0xD3, 0x7F, 0x2B, 0xD3, 0x3E, 0x3A, 0xC0, 0x11, 0x06, 
  0x2E, 0xDF, 0xD8, 0x22, 0x92, 0x5D, 0x1A, 0xE4, 0x6B, 0x60, 0x85, 
  0x1E, 0x1D, 0xAE, 0x2A, 0xD6, 0x78, 0xB2, 0xF5, 0x97, 0x84, 0x5E, 
  0xE7, 0x2B, 0x5F, 0x67, 0x94, 0x9F, 0x19, 0xAC, 0xB4, 0xC8, 0x5C, 
  0xB5, 0x00, 0xC6, 0x04, 0xD4, 0xDD, 0xE8, 0xE9, 0xCD, 0x8E, 0xBE, 
  0xE0, 0xB1, 0x24, 0xB3, 0x7D, 0x76, 0x34, 0xFF, 0x67, 0x2D, 0x69, 
  0x3F, 0xAD, 0x25, 0xAD, 0x71, 0xE2, 0x8D, 0x4F, 0x25, 0xDC, 0xF6, 
  0x59, 0xB1, 0xD6, 0x91, 0x88, 0xEF, 0xC0, 0x11, 0xA8, 0x37, 0xAF, 
  0xD3, 0xB7, 0x2F, 0xBE, 0x12, 0xC7, 0x2E, 0x79, 0xCE, 0x3E, 0x3A, 
  0xAE, 0xE2, 0xD7, 0xAE, 0x7C, 0x3F, 0x78, 
};

unsigned char out[sizeof(in)];

            cRSAPublicKey rsa;
            eError error;

            if (!(error = rsa.CreateMSB(n, sizeof(n), e, sizeof(e))))
            {
                rsa.Decrypt(out, sizeof(n), in, sizeof(n));

                for (int j=0; j<sizeof(n); j++)
                    printf("%2.2x", out[j]);
                printf("\n");
            }
        }
*/
/*
        for (int i=cASN1ObjectIdentifier::e_FIRST; 
             i<cASN1ObjectIdentifier::e_ALL; i++)
        {
            const cASN1ObjectIdentifier &id = cASN1ObjectIdentifier::m_table[i];
            printf("    {\"%s\", e_%s,\n     {",id.m_name, id.m_name);

            for (int k=cASN1ObjectIdentifier::e_SIZE; k>1; --k)
            {
                if (id.m_value[k-1])
                    break;
                if (id.m_value[k-2])
                    break;
            }
            for (int j=0; j<k; j++)
                printf("%luL, ", id.m_value[j]);

            printf("}},\n");
        }
*/
        {
            eError error;
            int size;
            time_t t = time(&t);
            cPseudoRandomSeed seed(t);
            cPseudoRandomStream stream(seed);
            c0X x(m_out);
            cSSLVersion version(3,0);
            cSSLRandom random(t, stream);
            cSSLSessionID session;
            cSSLCompressionMethod method(cSSLCompressionMethod::e_NULL);
            cSSLCompressionMethods methods(&method, 1);

            cSSLRSASignatureType rsa_signature_type;
            cSSLRSAKeyExchangeType rsa_key_exchange_type;
            cSSLDES3CipherType des3_cipher_type;
            cSSLSHA1HashType sha1_hash_type;

            cSSLCipherSuite suite
            (cSSLCipherSuite::e_RSA_3DES_SHA1,
             &rsa_signature_type, &rsa_key_exchange_type, 
             &des3_cipher_type, &sha1_hash_type);

            cSSLCipherSuites suites(&suite, 1);
            cSSLHelloHeader header(version, random, session);
            cSSLClientHello client_hello(header, suites, methods);
            cSSLAlert alert;
            cSSLHandshake handshake(client_hello);
            cSSLPlaintext plaintext(version, handshake);

            cSSLTime ssltime;
            cMD5 md5, fmd5;
            cSHA1 sha1, fsha1;
            cRSAPublicKey rsa_public_key;

            cSSLClientContext context
            (ssltime, stream, md5, fmd5, 
             sha1, fsha1, rsa_public_key, suites, methods);

            if (!(error = m_socket.Create()))
            {
                if (!(error = m_socket.Connect(m_host, m_port)))
                {
                    cEchoBYTEStream echo(m_socket, x);

                    if (0 < (size= context.SendHello(echo)))
                    {
                        printf("\n");

                        if (0 <= (size = context.ReceiveHello(echo)))
                        {
                            size = context.RespondHello(echo);
                        }
                    }
                }
                m_socket.Close();
            }
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int OnUsage(int argc, char **argv)
    {
        int result=0;
        cMainArg *a;

        printf("usage: %s", argv[0]);

        if ((a = cMainArg::m_list.GetFirst()))
        do
        {
            a->OnUsage();
        }
        while ((a = a->GetNext()));

        printf("\n");
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        cMainArg *a;

        if ((a = cMainArg::m_list.FindFirstByName(arg)))
            return a->OnMainArgSwitch
            (args, argn, arg, argc, argv);

        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_ssl_main;

/**
 **********************************************************************
 *  Class: cSSLMainArg
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */
class cSSLMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cSSLMain &m_main;

    /**
     **********************************************************************
     * Constructor: cSSLMainArg
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cSSLMainArg(cSSLMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

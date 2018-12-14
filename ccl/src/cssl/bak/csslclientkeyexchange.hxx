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
 *   File: csslclientkeyexchange.hxx
 *
 * Author: $author$
 *   Date: 1/21/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCLIENTKEYEXCHANGE_HXX
#define _CSSLCLIENTKEYEXCHANGE_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "csslencryptedpremastersecret.hxx"
#include "csslpremastersecret.hxx"
#include "crsapublickey.hxx"
#include "ckeyexchangealgorithm.hxx"

/**
 **********************************************************************
 *  Class: cSSLClientKeyExchange
 *
 * Author: $author$
 *   Date: 1/21/2005
 **********************************************************************
 */
class cSSLClientKeyExchange
{
public:

    int m_algorithm;
    cBYTEBuffer m_buffer;
    cSSLEncryptedPreMasterSecret m_secret;

    /**
     **********************************************************************
     * Constructor: cSSLClientKeyExchange
     *
     *      Author: $author$
     *        Date: 1/21/2005
     **********************************************************************
     */
    cSSLClientKeyExchange()
    : m_algorithm(cKeyExchangeAlgorithm::e_NONE),
      m_secret(m_buffer)
    {
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Copy(const cSSLClientKeyExchange &key_exchange)
    {
        int count, length, size = -e_ERROR_FAILED;
        const BYTE *buffer;

        if (&key_exchange == this)
            return size = Sizeof();

        if ((buffer = key_exchange.m_buffer.GetBuffer(length)))
        if (length == (count = m_buffer.Copy(buffer, length)))
        {
            m_algorithm = key_exchange.m_algorithm;
            size = length;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Set
    (cBYTEStream &random,
     const cSSLPreMasterSecret &secret,
     cRSAPublicKey &rsa_public_key)
    {
        int count, size = -e_ERROR_FAILED;

        if (0 < (count = m_secret.
            Set(random, secret, rsa_public_key)))
        {
            m_algorithm = cKeyExchangeAlgorithm::e_RSA;
            size = count;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size = -e_ERROR_FAILED;
        
        switch(m_algorithm)
        {
        case cKeyExchangeAlgorithm::e_RSA:
            size = m_secret.Write(stream);
            break;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = -e_ERROR_NOT_INITIALIZED;

        switch(m_algorithm)
        {
        case cKeyExchangeAlgorithm::e_RSA:
            size = m_secret.Sizeof();
            break;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: GetEncryptedPreMasterSecret
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    inline cSSLEncryptedPreMasterSecret& 
    GetEncryptedPreMasterSecret() 
    {
        return m_secret;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int operator != (const cSSLClientKeyExchange &key_exchange) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLCLIENTKEYEXCHANGE_HXX */

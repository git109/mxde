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
 *   File: csslkeyexchangetype.hxx
 *
 * Author: $author$
 *   Date: 2/8/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLKEYEXCHANGETYPE_HXX
#define _CSSLKEYEXCHANGETYPE_HXX

#include "ckeyexchangealgorithm.hxx"

class cSSLRSAClientKeyExchangeType;

/**
 **********************************************************************
 *  Class: cSSLKeyExchangeType
 *
 * Author: $author$
 *   Date: 1/23/2005
 **********************************************************************
 */
class cSSLKeyExchangeType
{
public:
    int m_algorithm;
    cSSLKeyExchangeType *m_key_exchange;
    cSSLRSAClientKeyExchangeType *m_rsa_client;

    /**
     **********************************************************************
     * Constructor: cSSLKeyExchangeType
     *
     *      Author: $author$
     *        Date: 2/8/2005
     **********************************************************************
     */
    cSSLKeyExchangeType
    (int algorithm=cKeyExchangeAlgorithm::e_NONE) 
    : m_algorithm(algorithm),
      m_key_exchange(0),
      m_rsa_client(0)
    {
    }
    /**
     **********************************************************************
     * Function: GetAlgorithm
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    virtual int GetAlgorithm() const 
    {
        if (m_key_exchange)
            return m_key_exchange->GetAlgorithm();

        return m_algorithm;
    }
    /**
     **********************************************************************
     * Function: GetRSAClient
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    virtual cSSLRSAClientKeyExchangeType* GetRSAClient() const 
    {
        return m_rsa_client;
    }
    /**
     **********************************************************************
     * Function: SetNone
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    inline eError SetNone() 
    {
        eError error = e_ERROR_NONE;
        m_key_exchange = 0;
        m_rsa_client = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetRSAClient
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    inline cSSLRSAClientKeyExchangeType* SetRSAClient
    (cSSLKeyExchangeType &key_exchange) 
    {
        m_rsa_client = key_exchange.GetRSAClient();
        m_key_exchange = &key_exchange;
        return m_rsa_client;
    }
};

#endif /* _CSSLKEYEXCHANGETYPE_HXX */
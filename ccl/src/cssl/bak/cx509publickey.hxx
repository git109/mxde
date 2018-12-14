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
 *   File: cx509publickey.hxx
 *
 * Author: $author$
 *   Date: 2/3/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509PUBLICKEY_HXX
#define _CX509PUBLICKEY_HXX

#include "ckeyexchangealgorithm.hxx"
#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cX509PublicKey
 *
 * Author: $author$
 *   Date: 2/3/2005
 **********************************************************************
 */
class cX509PublicKey
{
public:
    int m_algorithm;
    cBYTEBuffer m_rsa_modulus, m_rsa_exponent;

    /**
     **********************************************************************
     * Constructor: cX509PublicKey
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cX509PublicKey
    (int algorithm=cKeyExchangeAlgorithm::e_NONE) 
    : m_algorithm(algorithm)
    {
    }
    /**
     **********************************************************************
     * Function: SetNoneAlgorithm
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    inline int SetNoneAlgorithm()
    {
        return m_algorithm = cKeyExchangeAlgorithm::e_NONE;
    }
    /**
     **********************************************************************
     * Function: SetRSAAlgorithm
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    inline int SetRSAAlgorithm()
    {
        return m_algorithm = cKeyExchangeAlgorithm::e_RSA;
    }
    /**
     **********************************************************************
     * Function: GetAlgorithm
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    inline int GetAlgorithm() const 
    {
        return m_algorithm;
    }
    /**
     **********************************************************************
     * Function: GetRSAModulus
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    inline const BYTE* GetRSAModulus(int &length) const 
    {
        return m_rsa_modulus.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetRSAExponent
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    inline const BYTE* GetRSAExponent(int &length) const 
    {
        return m_rsa_exponent.GetBuffer(length);
    }
};

#endif /* _CX509PUBLICKEY_HXX */
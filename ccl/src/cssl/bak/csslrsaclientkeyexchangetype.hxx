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
 *   File: csslrsaclientkeyexchangetype.hxx
 *
 * Author: $author$
 *   Date: 2/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLRSACLIENTKEYEXCHANGETYPE_HXX
#define _CSSLRSACLIENTKEYEXCHANGETYPE_HXX

#include "csslkeyexchangetype.hxx"

/**
 **********************************************************************
 *  Class: cSSLRSAClientKeyExchangeType
 *
 * Author: $author$
 *   Date: 2/9/2005
 **********************************************************************
 */
class cSSLRSAClientKeyExchangeType
: public cSSLKeyExchangeType
{
public:
    typedef cSSLKeyExchangeType cIs;

    cBYTEBuffer m_modulus, m_exponent;

    /**
     **********************************************************************
     * Constructor: cSSLRSAClientKeyExchangeType
     *
     *      Author: $author$
     *        Date: 2/9/2005
     **********************************************************************
     */
    cSSLRSAClientKeyExchangeType() 
    : cIs(cKeyExchangeAlgorithm::e_RSA)
    {
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
        return (cSSLRSAClientKeyExchangeType*)this;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    virtual eError Set
    (const BYTE *modulus, int modsize,
     const BYTE *exponent, int expsize) 
    {
        eError error = e_ERROR_NONE;

        if (0 > (modsize = m_modulus.Copy(modulus, modsize)))
            return -modsize;

        if (0 > (expsize = m_exponent.Copy(exponent, expsize)))
            return -expsize;

        return error;
    }
    /**
     **********************************************************************
     * Function: GetModulus
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    inline const BYTE* GetModulus(int &length) const 
    {
        const BYTE* modulus = m_modulus.GetBuffer(length);
        return modulus;
    }
    /**
     **********************************************************************
     * Function: GetExponent
     *
     *   Author: $author$
     *     Date: 2/9/2005
     **********************************************************************
     */
    inline const BYTE* GetExponent(int &length) const 
    {
        const BYTE* exponent = m_exponent.GetBuffer(length);
        return exponent;
    }
};

#endif /* _CSSLRSACLIENTKEYEXCHANGETYPE_HXX */
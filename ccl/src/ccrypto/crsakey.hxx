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
 *   File: crsakey.hxx
 *
 * Author: $author$
 *   Date: 1/31/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CRSAKEY_HXX
#define _CRSAKEY_HXX

#include "platform.h"
#include "ccipher.hxx"

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
#include "bn_msb.h"
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
#include "mpz_msb.h"
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#include "cmpunsigned.hxx"
#endif /* defined(_CRSA_BN) */

/**
 **********************************************************************
 *  Class: cRSAKey
 *
 * Author: $author$
 *   Date: 1/31/2005
 **********************************************************************
 */
class cRSAKey
: public cCipher
{
public:
    typedef cCipher cIs, cExtends;
    typedef cRSAKey cAs, cDerives;

    bool m_is_created;
    unsigned m_modbytes;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM *m_temp;
    BN_CTX *m_ctx;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_temp;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
    cMPUnsigned m_temp;
#endif /* defined(_CRSA_BN) */

    /**
     **********************************************************************
     * Constructor: cRSAKey
     *
     *      Author: $author$
     *        Date: 1/31/2005
     **********************************************************************
     */
    cRSAKey() 
    : m_is_created(false),
      m_modbytes(0)
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
     ,m_temp(0),
      m_ctx(0)
#endif
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cRSAKey
     *
     *      Author: $author$
     *        Date: 1/31/2005
     **********************************************************************
     */
    virtual ~cRSAKey()
    {
        eError error;

        if (m_is_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 1/31/2005
     **********************************************************************
     */
    virtual eError Create() 
    {
        eError error;

        if (m_is_created)
            return e_ERROR_ALREADY_CREATED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        error = e_ERROR_NEW;

        if ((m_temp = BN_new()))
        {
            if ((m_ctx = BN_CTX_new()))
            {
                m_is_created = true;
                return e_ERROR_NONE;
            }
            BN_free(m_temp);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_temp,0);
        m_is_created = true;
        error = e_ERROR_NONE;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
        m_is_created = true;
        error = e_ERROR_NONE;
#endif /* defined(_CRSA_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/19/2007
     **********************************************************************
     */
    virtual eError Create(unsigned modbytes) 
    {
        eError error;
        if (!(error = cAs::Create()))
            m_modbytes = modbytes;
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 1/31/2005
     **********************************************************************
     */
    virtual eError Destroy() 
    {
        eError error = e_ERROR_NOT_CREATED;

        if (m_is_created)
        {
#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
            BN_free(m_temp);
            BN_CTX_free(m_ctx);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
            mpz_clear(&m_temp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
            m_modbytes = 0;
            m_is_created = false;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

#endif /* _CRSAKEY_HXX */

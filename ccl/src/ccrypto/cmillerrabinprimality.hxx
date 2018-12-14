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
 *   File: cmillerrabinprimality.hxx
 *
 * Author: $author$
 *   Date: 10/21/2007
 *
 **********************************************************************
 */
#ifndef _CMILLERRABINPRIMALITY_HXX
#define _CMILLERRABINPRIMALITY_HXX

#include "cprimereader.hxx"
#include "cbytestreaminterface.hxx"
#include "cerror.h"

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */


#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/

/**
 **********************************************************************
 *  Class: cMillerRabinPrimality
 *
 * Author: $author$
 *   Date: 10/21/2007
 **********************************************************************
 */
class cMillerRabinPrimality
: public cPrimeReader
{
public:
    typedef cPrimeReader cExtends;
    typedef cMillerRabinPrimality cDerives;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/21/2007
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR = ::e_NEXT_ERROR,

        e_ERROR_NOT_PRIME = e_FIRST_ERROR,

        e_NEXT_ERROR,
        e_LAST_ERROR = e_NEXT_ERROR-1,

        e_ERRORS = e_LAST_ERROR-e_FIRST_ERROR+1
    };

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM *m_n_minus_1;
    BIGNUM *m_x;
    BIGNUM *m_one;
    BIGNUM *m_z;
    BIGNUM *m_q;
    BN_CTX *m_ctx;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_n_minus_1;
    MP_INT m_x;
    MP_INT m_one;
    MP_INT m_z;
    MP_INT m_q;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */


#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/

    bool m_is_created;

    /**
     **********************************************************************
     * Constructor: cMillerRabinPrimality
     *
     *      Author: $author$
     *        Date: 10/21/2007
     **********************************************************************
     */
    cMillerRabinPrimality
    (cPrimeReaderEventsInterface* events=0) 
    : cExtends(events),
      m_is_created(false)
    {
    }
    /**
     **********************************************************************
     * Destructor: cMillerRabinPrimality
     *
     *     Author: $author$
     *       Date: 10/21/2007
     **********************************************************************
     */
    virtual ~cMillerRabinPrimality()
    {
        eError error;
        if (m_is_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 10/21/2007
     **********************************************************************
     */
    virtual eError Destroy() 
    {
        eError error = e_ERROR_FAILED;

        if (!m_is_created)
            return e_ERROR_NOT_CREATED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_CTX_free(m_ctx);
        BN_free(m_q);
        BN_free(m_z);
        BN_free(m_one);
        BN_free(m_x);
        BN_free(m_n_minus_1);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&m_q);
        mpz_clear(&m_z);
        mpz_clear(&m_one);
        mpz_clear(&m_x);
        mpz_clear(&m_n_minus_1);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */


#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
        error = e_ERROR_NONE;
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/

        m_is_created = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/21/2007
     **********************************************************************
     */
    virtual eError Create() 
    {
        eError error = e_ERROR_FAILED;

        if (m_is_created)
            return e_ERROR_ALREADY_CREATED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        if ((m_n_minus_1=BN_new()))
        {
            if ((m_x=BN_new()))
            {
                if ((m_one=BN_new()))
                {
                    if ((m_z=BN_new()))
                    {
                        if ((m_q=BN_new()))
                        {
                            if ((m_ctx=BN_CTX_new()))
                            {
                                BN_set_word(m_one,1);
                                m_is_created = true;
                                return e_ERROR_NONE;

                                BN_CTX_free(m_ctx);
                            }
                            BN_free(m_q);
                        }
                        BN_free(m_z);
                    }
                    BN_free(m_one);
                }
                BN_free(m_x);
            }
            BN_free(m_n_minus_1);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_n_minus_1,0);
        mpz_init_set_ui(&m_x,0);
        mpz_init_set_ui(&m_one,1);
        mpz_init_set_ui(&m_z,0);
        mpz_init_set_ui(&m_q,0);

        m_is_created = true;
        return e_ERROR_NONE;

        mpz_clear(&m_n_minus_1);
        mpz_clear(&m_x);
        mpz_clear(&m_one);
        mpz_clear(&m_z);
        mpz_clear(&m_q);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */


#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/
        return error;
    }
    /**
     **********************************************************************
     * Function: ProbablyPrime
     *
     *   Author: $author$
     *     Date: 10/21/2007
     **********************************************************************
     */
    virtual eError ProbablyPrime
    (BIGPRIME *n, unsigned bytes, 
     unsigned reps, cBYTEStreamInterface &random) 
    {
        eError error = e_ERROR_FAILED;
        unsigned i,j,k;
        unsigned bits=(bytes<<3);

        if (!m_is_created)
            return e_ERROR_NOT_CREATED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_sub(m_n_minus_1, n, m_one);

        /* find q and k, such that n = 1 + 2^k * q
         * ie q = (n-1)/2^k
         */
        for (k=0; !BN_is_bit_set(m_n_minus_1,k); k++);

        BN_rshift(m_q,m_n_minus_1,k);

        for (i = 0; i < reps ; i++)
        {
            /* find random x such that 1 < x < n 
             */
            do
            {
                if ((error=ReadMSB(m_x,bytes,random)))
                    return error;

                /* make x < n
                 */
                BN_clear_bit(m_x,bits-1);
            }
            while (BN_cmp(m_x, m_one) <= 0);

            /* z =  x^q mod n
             */
            BN_mod_exp(m_z, m_x, m_q, n, m_ctx);

            /* if z == 0 or z == n-1 then possibly prime
            */
            if ((BN_cmp(m_z, m_one) == 0)
                || (BN_cmp(m_z, m_n_minus_1) == 0))
                continue;

            for (j = 1; j < k; j++)
            {
                /* z = z^2 mod n
                 */
                BN_mod_mul(m_z, m_z, m_z, n, m_ctx);

                /* if z == n-1 then possibly prime
                 */
                if (BN_cmp(m_z, m_n_minus_1) == 0)
                    break;

                /* if z == 1 then not prime
                 */
                if (BN_cmp(m_z, m_one) == 0)
                    return e_ERROR_NOT_PRIME;
            }

            if (j>=k)
                return e_ERROR_NOT_PRIME;
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_sub(&m_n_minus_1, n, &m_one);

        /* find q and k, such that n = 1 + 2^k * q
         * ie q = (n-1)/2^k
         */
        mpz_set(&m_q,&m_n_minus_1);

        for(k=0; (mpz_get_ui(&m_q)&1)==0; k++)
            mpz_tdiv_q_2exp(&m_q,&m_q,1);

        for (i = 0; i < reps ; i++)
        {
            /* find random x such that 1 < x < n 
             */
            do
            {
                if ((error=ReadMSB(&m_x,bytes,random)))
                    return error;

                /* make x < n
                 */
                mpz_clrbit(&m_x,bits-1);
            }
            while (mpz_cmp(&m_x, &m_one) <= 0);

            /* z =  x^q mod n
             */
            mpz_powm(&m_z, &m_x, &m_q, n);

            /* if z == 0 or z == n-1 then possibly prime
             */
            if ((mpz_cmp(&m_z, &m_one) == 0)
                || (mpz_cmp(&m_z, &m_n_minus_1) == 0))
                continue;

            for (j = 1; j < k; j++)
            {
                /* z = z^2 mod n
                 */
                mpz_powm_ui(&m_z, &m_z, 2, n);

                /* if z == n-1 then possibly prime
                 */
                if (mpz_cmp(&m_z, &m_n_minus_1) == 0)
                    break;

                /* if z == 1 then not prime
                 */
                if (mpz_cmp(&m_z, &m_one) == 0)
                    return e_ERROR_NOT_PRIME;
            }

            if (j>=k)
                return e_ERROR_NOT_PRIME;
        }
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */


#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/
        return error;
    }
};
#endif /* _CMILLERRABINPRIMALITY_HXX */

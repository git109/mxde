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
 *   File: crsaprivatekey.hxx
 *
 * Author: $author$
 *   Date: 10/19/2007
 *
 **********************************************************************
 */
#ifndef _CRSAPRIVATEKEY_HXX
#define _CRSAPRIVATEKEY_HXX

#include "crsapublickey.hxx"
#include "crsakey.hxx"

void dump(const void *buff,unsigned long bytes);

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

class c_INTERFACE_CLASS cPrimeReaderEventsInterface;

/**
 **********************************************************************
 *  Class: cRSAPrivateKey
 *
 * Author: $author$
 *   Date: 10/19/2007
 **********************************************************************
 */
class cRSAPrivateKey
: public cRSAKey
{
public:
    typedef cRSAKey cIs, cExtends;
    typedef cRSAPrivateKey cAs, cDerives;

    unsigned m_pbytes;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM *m_p;
    BIGNUM *m_q;
    BIGNUM *m_dmp1;
    BIGNUM *m_dmq1;
    BIGNUM *m_iqmp;
    BIGNUM *m_ptemp;
    BIGNUM *m_qtemp;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_p;
    MP_INT m_q;
    MP_INT m_dmp1;
    MP_INT m_dmq1;
    MP_INT m_iqmp;
    MP_INT m_ptemp;
    MP_INT m_qtemp;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
    cMPUnsigned m_p;
    cMPUnsigned m_q;
    cMPUnsigned m_dmp1;
    cMPUnsigned m_dmq1;
    cMPUnsigned m_iqmp;
    cMPUnsigned m_ptemp;
    cMPUnsigned m_qtemp;
#endif /* defined(_CRSA_BN) */

    /**
     **********************************************************************
     * Constructor: cRSAPrivateKey
     *
     *      Author: $author$
     *        Date: 10/19/2007
     **********************************************************************
     */
    cRSAPrivateKey()
    : m_pbytes(0)
    {
    }
    /**
     **********************************************************************
     * Constructor: cRSAPrivateKey
     *
     *      Author: $author$
     *        Date: 10/19/2007
     **********************************************************************
     */
    cRSAPrivateKey(unsigned pbytes)
    : m_pbytes(0)
    {
        eError error;

        if ((error = Create(pbytes)))
            throw(error);
    }
    /**
     **********************************************************************
     * Destructor: cRSAPrivateKey
     *
     *     Author: $author$
     *       Date: 10/19/2007
     **********************************************************************
     */
    virtual ~cRSAPrivateKey()
    {
        eError error;

        if (m_is_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Generate
     *
     *   Author: $author$
     *     Date: 10/22/2007
     **********************************************************************
     */
    eError Generate
    (cRSAPublicKey& publicKey, 
     cBYTEStreamInterface& random,
     const BYTE* exponent, unsigned expbytes, unsigned modbytes,
     cPrimeReaderEventsInterface* prime_reader_events=0);

    /**
     **********************************************************************
     * Function: Crypt
     *
     *   Author: $author$
     *     Date: 10/19/2007
     **********************************************************************
     */
    virtual int Crypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1) 
    {
        int outlen = -e_ERROR_FAILED;
        unsigned inbytes;
        bool subp;

        if (!m_is_created)
            return -e_ERROR_NOT_CREATED;

        if (0 > inlen)
            inlen = (int)(strlen((const char*)in));

        if (outsize < inlen)
            return e_ERROR_INVALID_PARAMETER_SIZE;

        if (m_modbytes != (inbytes = inlen))
            return e_ERROR_BLOCK_SIZE;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_set_msb(m_temp,(const unsigned char*)in,inbytes);

        /* Compute q2 = (value mod q) ^ dmq1 mod q. 
         */
        BN_mod(m_qtemp,m_temp,m_q,m_ctx);
        BN_mod_exp(m_qtemp,m_qtemp,m_dmq1,m_q,m_ctx);

        /* Compute p2 = (value mod p) ^ dmp1 mod p. 
         */
        BN_mod(m_ptemp,m_temp,m_p,m_ctx);
        BN_mod_exp(m_ptemp,m_ptemp,m_dmp1,m_p,m_ctx);

        /* if q2 > p then q2 = q2 - p
         */
        if ((subp=(BN_cmp(m_qtemp,m_p)>0))!=0)
            BN_sub(m_qtemp,m_qtemp,m_p);

        /* Compute k = (((p2 + p) - q2) mod p) * iqmp mod p. 
         */
        BN_add(m_temp,m_ptemp,m_p);
        BN_sub(m_temp,m_temp,m_qtemp);
        BN_mul(m_ptemp,m_temp,m_iqmp);
        BN_mod(m_temp,m_ptemp,m_p,m_ctx);

        /* Compute value = q2 + q * k. 
         */
        BN_mul(m_ptemp,m_temp,m_q);
        BN_add(m_temp,m_ptemp,m_qtemp);

        /* if we subtracted p before the add it back here
         */
        if (subp)
            BN_add(m_temp,m_temp,m_p);

        BN_get_msb(m_temp,(unsigned char*)out,inbytes);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_msb(&m_temp,(const unsigned char*)in,inbytes);

        /* Compute q2 = (value mod q) ^ dmq1 mod q. 
         */
        mpz_mod(&m_qtemp,&m_temp,&m_q);
        mpz_powm(&m_qtemp,&m_qtemp,&m_dmq1,&m_q);

        /* Compute p2 = (value mod p) ^ dmp1 mod p. 
         */
        mpz_mod(&m_ptemp,&m_temp,&m_p);
        mpz_powm(&m_ptemp,&m_ptemp,&m_dmp1,&m_p);

        /* if q2 > p then q2 = q2 - p
         */
        if ((subp=(mpz_cmp(&m_qtemp,&m_p)>0))!=0)
            mpz_sub(&m_qtemp,&m_qtemp,&m_p);

        /* Compute k = (((p2 + p) - q2) mod p) * iqmp mod p. 
         */
        mpz_add(&m_temp,&m_ptemp,&m_p);
        mpz_sub(&m_temp,&m_temp,&m_qtemp);
        mpz_mul(&m_ptemp,&m_temp,&m_iqmp);
        mpz_mmod(&m_temp,&m_ptemp,&m_p);

        /* Compute value = q2 + q * k. 
         */
        mpz_mul(&m_ptemp,&m_temp,&m_q);
        mpz_add(&m_temp,&m_ptemp,&m_qtemp);

        /* if we subtracted p before then add it back here
         */
        if (subp)
            mpz_add(&m_temp,&m_temp,&m_p);

        mpz_get_msb((unsigned char*)out,inbytes,&m_temp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
        m_temp.SetMSB(in,inbytes);

        /* Compute q2 = (value mod q) ^ dmq1 mod q. 
         */
        m_qtemp = m_temp;
        m_qtemp %= m_q;
        m_qtemp.ModExp(m_dmq1,m_q);

        /* Compute p2 = (value mod p) ^ dmp1 mod p. 
         */
        m_ptemp = m_temp;
        m_ptemp %= m_p;
        m_ptemp.ModExp(m_dmp1,m_p);

        /* if q2 > p then q2 = q2 - p
         */
        if ((subp = (((m_qtemp != m_p)>0) != 0)))
            m_qtemp -= m_p;

        /* Compute k = (((p2 + p) - q2) mod p) * iqmp mod p. 
         */
        m_temp = m_ptemp;
        m_temp += m_p;
        m_temp -= m_qtemp;
        m_temp *= m_iqmp;
        m_temp %= m_p;

        /* Compute value = q2 + q * k. 
         */
        m_temp *= m_q;
        m_temp += m_qtemp;

        /* if we subtracted p before the add it back here
         */
        if (subp)
            m_temp += m_p;

        m_temp.GetMSB(out,inbytes);

        outlen = inbytes;
#endif /* defined(_CRSA_BN) */


#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
        outlen = inbytes;
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/

        return outlen;
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/19/2007
     **********************************************************************
     */
    virtual eError Create() 
    {
        eError error = e_ERROR_NOT_ALLOWED;
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
    virtual eError Create(unsigned pbytes) 
    {
        eError error = e_ERROR_FAILED;

        if (m_is_created)
        if (m_pbytes != pbytes)
            return e_ERROR_ALREADY_CREATED;
        else return e_ERROR_NONE;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        error = e_ERROR_NEW;

        if ((m_p=BN_new()))
        {
            if ((m_q=BN_new()))
            {
                if ((m_dmp1=BN_new()))
                {
                    if ((m_dmq1=BN_new()))
                    {
                        if ((m_iqmp=BN_new()))
                        {
                            if ((m_ptemp=BN_new()))
                            {
                                if ((m_qtemp=BN_new()))
                                {
                                    if (!(error = cIs::Create(pbytes*2)))
                                    {
                                        m_pbytes = pbytes;
                                        return error;
                                    }

                                    BN_free(m_qtemp);
                                }
                                BN_free(m_ptemp);
                            }
                            BN_free(m_iqmp);
                        }
                        BN_free(m_dmq1);
                    }
                    BN_free(m_dmp1);
                }
                BN_free(m_q);
            }
            BN_free(m_p);
        }
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_p,0);
        mpz_init_set_ui(&m_q,0);
        mpz_init_set_ui(&m_dmp1,0);
        mpz_init_set_ui(&m_dmq1,0);
        mpz_init_set_ui(&m_iqmp,0);
        mpz_init_set_ui(&m_ptemp,0);
        mpz_init_set_ui(&m_qtemp,0);

        if (!(error = cIs::Create(pbytes*2)))
        {
            m_pbytes = pbytes;
            return error;
        }

        mpz_clear(&m_p);
        mpz_clear(&m_q);
        mpz_clear(&m_dmp1);
        mpz_clear(&m_dmq1);
        mpz_clear(&m_iqmp);
        mpz_clear(&m_ptemp);
        mpz_clear(&m_qtemp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
        if (!(error = cIs::Create(pbytes*2)))
            m_pbytes = pbytes;
#endif /* defined(_CRSA_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 10/19/2007
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
        BN_free(m_p);
        BN_free(m_q);
        BN_free(m_dmp1);
        BN_free(m_dmq1);
        BN_free(m_iqmp);
        BN_free(m_ptemp);
        BN_free(m_qtemp);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&m_p);
        mpz_clear(&m_q);
        mpz_clear(&m_dmp1);
        mpz_clear(&m_dmq1);
        mpz_clear(&m_iqmp);
        mpz_clear(&m_ptemp);
        mpz_clear(&m_qtemp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        m_pbytes = 0;
        error = cIs::Destroy();
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateMSB
     *
     *   Author: $author$
     *     Date: 10/19/2007
     **********************************************************************
     */
    virtual eError CreateMSB
    (const unsigned char *p,
     const unsigned char *q,
     const unsigned char *dmp1,
     const unsigned char *dmq1,
     const unsigned char *iqmp,
     unsigned psize) 
    {
        eError error = e_ERROR_FAILED;

        if (!(error = Create(psize)))
        {
            if (!(error = SetMSB(p,q,dmp1,dmq1,iqmp,psize)))
                return error;

            Destroy();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: SetMSB
     *
     *   Author: $author$
     *     Date: 10/19/2007
     **********************************************************************
     */
    virtual eError SetMSB
    (const unsigned char *p,
     const unsigned char *q,
     const unsigned char *dmp1,
     const unsigned char *dmq1,
     const unsigned char *iqmp,
     unsigned psize) 
    {
        eError error = e_ERROR_FAILED;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_set_msb(m_p,p,psize);
        BN_set_msb(m_q,q,psize);
        BN_set_msb(m_dmp1,dmp1,psize);
        BN_set_msb(m_dmq1,dmq1,psize);
        BN_set_msb(m_iqmp,iqmp,psize);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_msb(&m_p,p,psize);
        mpz_set_msb(&m_q,q,psize);
        mpz_set_msb(&m_dmp1,dmp1,psize);
        mpz_set_msb(&m_dmq1,dmq1,psize);
        mpz_set_msb(&m_iqmp,iqmp,psize);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
        if (!(error = m_p.SetMSB(p,psize)))
        if (!(error = m_q.SetMSB(q,psize)))
        if (!(error = m_dmp1.SetMSB(dmp1,psize)))
        if (!(error = m_dmq1.SetMSB(dmq1,psize)))
        if (!(error = m_iqmp.SetMSB(iqmp,psize)))
        {
        m_modbytes = psize*2;
        m_pbytes = psize;
        }
#endif /* defined(_CRSA_BN) */

#if defined(_CRSA_BN) | defined(_CRSA_MP) 
        m_modbytes = psize*2;
        m_pbytes = psize;
        error = e_ERROR_NONE;
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/

        return error;
    }
    /**
     **********************************************************************
     * Function: GetMSB
     *
     *   Author: $author$
     *     Date: 10/19/2007
     **********************************************************************
     */
    virtual eError GetMSB
    (unsigned &plength,
     unsigned char *p,
     unsigned char *q,
     unsigned char *dmp1,
     unsigned char *dmq1,
     unsigned char *iqmp,
     unsigned psize) const 
    {
        eError error = e_ERROR_FAILED;

        if (psize < m_pbytes)
            return e_ERROR_KEY_SIZE_UNDER;

        if (psize > m_pbytes)
            psize = m_pbytes;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
        BN_get_msb(m_p,p,psize);
        BN_get_msb(m_q,q,psize);
        BN_get_msb(m_dmp1,dmp1,psize);
        BN_get_msb(m_dmq1,dmq1,psize);
        BN_get_msb(m_iqmp,iqmp,psize);
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_get_msb(p,psize,&m_p);
        mpz_get_msb(q,psize,&m_q);
        mpz_get_msb(dmp1,psize,&m_dmp1);
        mpz_get_msb(dmq1,psize,&m_dmq1);
        mpz_get_msb(iqmp,psize,&m_iqmp);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
        if (!(error = m_p.GetMSB(p,psize)))
        if (!(error = m_q.GetMSB(q,psize)))
        if (!(error = m_dmp1.GetMSB(dmp1,psize)))
        if (!(error = m_dmq1.GetMSB(dmq1,psize)))
        if (!(error = m_iqmp.GetMSB(iqmp,psize)))
            plength = m_pbytes;
#endif /* defined(_CRSA_BN) */

#if defined(_CRSA_BN) | defined(_CRSA_MP) 
/*
 * BIGNUM or MP_INT implementation
 */
        plength = m_pbytes;
        error = e_ERROR_NONE;
#endif /* defined(_CRSA_BN) | defined(_CRSA_MP)*/
        return error;
    }
};
#endif /* _CRSAPRIVATEKEY_HXX */

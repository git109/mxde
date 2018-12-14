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
 *   File: rsa.cxx
 *
 * Author: $author$
 *   Date: 10/19/2007
 *
 **********************************************************************
 */
#include <stdio.h>

#include "cprimereaderevents.hxx"
#include "crsapublickey.hxx"
#include "crsaprivatekey.hxx"
#include "cpseudorandomstream.hxx"
#include "cutctime.hxx"

#include "rsa-test-keys.cxx"

#ifndef DUMP_COLS
#define DUMP_COLS 32
#endif

void dump(const void *buff,unsigned long bytes)
{
    unsigned long i,j;

    for (j=0,i=0; i<bytes; i++)
    {
        if (j<DUMP_COLS) 
            j++;
        else 
        { 
            j=1; 
            printf("\n"); 
        }
        printf("%2.2x",((const unsigned char*)buff)[i]);
    }
    printf("\n\n");
}

void dump0x(const void *buff,unsigned long bytes)
{
    unsigned long i,j;

    for (j=0,i=0; i<bytes; i++)
    {
        if (j<DUMP_COLS) 
            j++;
        else 
        { 
            j=1; 
            printf(("\n")); 
        }
        printf("0x%2.2x,",((const unsigned char*)buff)[i]);
    }
    printf("\n\n");
}

/**
 **********************************************************************
 *  Class: cRSAPrimeReaderEvents
 *
 * Author: $author$
 *   Date: 10/23/2007
 **********************************************************************
 */
class cRSAPrimeReaderEvents
: public cPrimeReaderEvents
{
public:
    typedef cPrimeReaderEvents cExtends;
    typedef cRSAPrimeReaderEvents cDerives;

    BYTE m_byte[1024];

    /**
     **********************************************************************
     * Function: OnReadPrime
     *
     *   Author: $author$
     *     Date: 10/23/2007
     **********************************************************************
     */
    virtual eError OnReadPrime
    (BIGPRIME *n,
     unsigned bytes) 
    {
        eError error = e_ERROR_NONE;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
        mpz_get_msb(m_byte, bytes, n);
        printf("prime:\n");
        dump(m_byte, bytes);
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CRSA_BN) */
        return error;
    }
};

int main(int argc, const char**argv, const char*env)
{
    int err = 0;
    int len;
    eError error;
    cRSAPrimeReaderEvents rsaEvents;
    cRSAPublicKey rsaPublic;
    cRSAPrivateKey rsaPrivate;
    cUTCTime utc_time(true);
    cPseudoRandomSeed p_random_seed(utc_time);
    cPseudoRandomStream p_random(p_random_seed);

    BYTE in[sizeof(rsa_public_m)];
    BYTE eout[sizeof(rsa_public_m)];
    BYTE dout[sizeof(rsa_public_m)];

    memset(in, 0x12, sizeof(in));

    dump(in, sizeof(in));

    if (!(error = rsaPublic.CreateMSB
        (rsa_public_m, sizeof(rsa_public_m), 
         rsa_public_e, sizeof(rsa_public_e))))

    if (!(error = rsaPrivate.CreateMSB
        (rsa_private_p, rsa_private_q, 
         rsa_private_dmp1, rsa_private_dmq1, 
         rsa_private_iqmp, sizeof(rsa_private_p))))

    {
        if (0 < (len = rsaPublic.Crypt
            (eout, sizeof(eout), in, sizeof(in))))
        {
            dump(eout, sizeof(eout));

            if (0 < (len = rsaPrivate.Crypt
                (dout, sizeof(dout), eout, sizeof(eout))))
            {
                dump(dout, sizeof(dout));
            }
        }

        return err;

        if (!(error = rsaPrivate.Generate
            (rsaPublic, p_random, 
             rsa_public_e, sizeof(rsa_public_e), 
             sizeof(rsa_private_p)*2, &rsaEvents)))
        {
        dump(in, sizeof(in));

        if (0 < (len = rsaPublic.Crypt
            (eout, sizeof(eout), in, sizeof(in))))
        {
            dump(eout, sizeof(eout));

            if (0 < (len = rsaPrivate.Crypt
                (dout, sizeof(dout), eout, sizeof(eout))))
            {
                dump(dout, sizeof(dout));
            }
        }
        }
    }
    return err;
}

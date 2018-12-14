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
 *   File: cprimereadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 10/23/2007
 *
 **********************************************************************
 */
#ifndef _CPRIMEREADEREVENTSINTERFACE_HXX
#define _CPRIMEREADEREVENTSINTERFACE_HXX

#include "cinterface.hxx"

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
 *  Class: cPrimeReaderEventsInterface
 *
 * Author: $author$
 *   Date: 10/23/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cPrimeReaderEventsInterface
{
public:
    typedef cPrimeReaderEventsInterface cDerives;

#if defined(_CRSA_BN)
/*
 * BIGNUM implementation
 */
    typedef BIGNUM BIGPRIME;
#elif defined(_CRSA_MP) 
/*
 * MP_INT implementation
 */
    typedef MP_INT BIGPRIME;
#else /* defined(_CRSA_BN) */
/*
 * Otherwise 
 */
    typedef cMPUnsigned BIGPRIME;
#endif /* defined(_CRSA_BN) */

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
     unsigned bytes) = 0;
};
#endif /* _CPRIMEREADEREVENTSINTERFACE_HXX */

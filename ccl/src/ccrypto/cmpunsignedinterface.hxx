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
 *   File: cmpunsignedinterface.hxx
 *
 * Author: $author$
 *   Date: 10/24/2007
 *
 **********************************************************************
 */
#ifndef _CMPUNSIGNEDINTERFACE_HXX
#define _CMPUNSIGNEDINTERFACE_HXX

#include "cinterface.hxx"

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
#include "bn_msb.h"
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
#include "mpz_msb.h"
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */

/**
 **********************************************************************
 *  Class: cMPUnsignedInterface
 *
 * Author: $author$
 *   Date: 10/24/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cMPUnsignedInterface
{
public:
    typedef cMPUnsignedInterface cDerives;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
typedef BIGNUM* MPUNSIGNED;
typedef BIGNUM* PMPUNSIGNED;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
typedef MP_INT MPUNSIGNED;
typedef MP_INT* PMPUNSIGNED;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
typedef cMPUnsignedInterface* MPUNSIGNED;
typedef cMPUnsignedInterface* PMPUNSIGNED;
#endif /* defined(_CMPUNSIGNED_BN) */
};
#endif /* _CMPUNSIGNEDINTERFACE_HXX */

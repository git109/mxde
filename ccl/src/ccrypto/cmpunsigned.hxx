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
 *   File: cmpunsigned.hxx
 *
 * Author: $author$
 *   Date: 10/24/2007
 *
 **********************************************************************
 */
#ifndef _CMPUNSIGNED_HXX
#define _CMPUNSIGNED_HXX

#include "cmpunsignedinterface.hxx"

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */

/**
 **********************************************************************
 *  Class: cMPUnsigned
 *
 * Author: $author$
 *   Date: 10/24/2007
 **********************************************************************
 */
class cMPUnsigned
: virtual public cMPUnsignedInterface
{
public:
    typedef cMPUnsignedInterface cImplements;
    typedef cMPUnsigned cDerives;

    bool m_is_created;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
    BIGNUM* m_value;
    BIGNUM* m_temp;
    BN_CTX *m_ctx;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
    MP_INT m_value;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */

    /**
     **********************************************************************
     * Constructor: cMPUnsigned
     *
     *      Author: $author$
     *        Date: 10/24/2007
     **********************************************************************
     */
    cMPUnsigned() 
    : m_is_created(false)
    {
    }
    /**
     **********************************************************************
     * Destructor: cMPUnsigned
     *
     *     Author: $author$
     *       Date: 10/24/2007
     **********************************************************************
     */
    virtual ~cMPUnsigned()
    {
        eError error;
        if (m_is_created)
        if ((error = Destroy(true)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError Destroy(bool only_is_created=false) 
    {
        eError error = e_ERROR_FAILED;

        if (!m_is_created)
        if (only_is_created)
            return e_ERROR_NOT_CREATED;
        else return e_ERROR_NONE;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_CTX_free(m_ctx);
        BN_free(m_temp);
        BN_free(m_value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&m_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */

        m_is_created = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError Create(bool only_is_not_created=false) 
    {
        eError error = e_ERROR_FAILED;

        if (m_is_created)
        if (only_is_not_created)
            return e_ERROR_ALREADY_CREATED;
        else return e_ERROR_NONE;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        if ((m_value=BN_new()))
        {
        if ((m_temp=BN_new()))
        {
        if ((m_ctx=BN_CTX_new()))
        {
        BN_set_word(m_value,0);
        m_is_created = true;
        return error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_init_set_ui(&m_value,0);
        m_is_created = true;
        return error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_CTX_free(m_ctx);
        }
        BN_free(m_temp);
        }
        BN_free(m_value);
        }
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_clear(&m_value);
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: SetMSB
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError SetMSB
    (const BYTE* value, unsigned size) 
    {
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_set_msb(m_value, value, size);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_msb(&m_value, value, size);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: GetMSB
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError GetMSB
    (BYTE* value, unsigned size) const
    {
        eError error = e_ERROR_FAILED;

        if (!m_is_created)
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_get_msb(m_value, value, size);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_get_msb(value, &m_value, size);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual PMPUNSIGNED SetValue(PMPUNSIGNED value) 
    {
        PMPUNSIGNED new_value = 0;
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return 0;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_copy(m_value, value);
        new_value = m_value;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_set(&m_value, value);
        new_value = &m_value;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return new_value;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual PMPUNSIGNED GetValue() const 
    {
        PMPUNSIGNED value = 0;

        if (!m_is_created)
            return 0;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        value = m_value;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        value = &m_value;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return value;
    }

    /**
     **********************************************************************
     * Function: ModExp
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError ModExp
    (const cMPUnsigned& exponent, 
     const cMPUnsigned& modulus) 
    {
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_exponent = exponent.GetValue();
        PMPUNSIGNED l_modulus = modulus.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_mod_exp(m_value, m_value, l_exponent, l_modulus, m_ctx);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_powm(&m_value, &m_value, l_exponent, l_modulus);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: =
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator =(unsigned long value) 
    {
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_set_word(m_value, value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_set_ui(&m_value, value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: =
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator =(const cMPUnsigned& value) 
    {
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_value = value.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_copy(m_value, l_value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_set(&m_value, l_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: !=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual int operator !=(unsigned long value) 
    {
        int unequal = 0;
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        /*unequal = BN_cmp_word(m_value, value);
        error = e_ERROR_NONE;*/
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        unequal = mpz_cmp_ui(&m_value, value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return unequal;
    }
    /**
     **********************************************************************
     * Function: !=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual int operator !=(const cMPUnsigned& value) 
    {
        int unequal = 0;
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_value = value.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        unequal = BN_cmp(m_value, l_value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        unequal = mpz_cmp(&m_value, l_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return unequal;
    }

    /**
     **********************************************************************
     * Function: +=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator +=(unsigned long value) 
    {
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_add_word(m_value, value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_add_ui(&m_value, value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: +=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator +=(const cMPUnsigned& value) 
    {
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_value = value.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_add(m_value, m_value, l_value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_add(&m_value, &m_value, l_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: -=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator -=(unsigned long value) 
    {
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_sub_word(m_value, value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_sub_ui(&m_value, value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: -=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator -=(const cMPUnsigned& value) 
    {
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_value = value.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_sub(m_value, m_value, l_value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_sub(&m_value, &m_value, l_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: *=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator *=(unsigned long value) 
    {
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_mul_word(m_value, value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_mul_ui(&m_value, value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: *=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator *=(const cMPUnsigned& value) 
    {
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_value = value.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_mul(m_temp, m_value, l_value);
        BN_copy(m_value, m_temp);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_mul(&m_value, &m_value, l_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }

    /**
     **********************************************************************
     * Function: %=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator %=(unsigned long value) 
    {
        eError error = e_ERROR_FAILED;

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_mod_word(m_value, value);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_mod_ui(&m_value, value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
    /**
     **********************************************************************
     * Function: %=
     *
     *   Author: $author$
     *     Date: 10/24/2007
     **********************************************************************
     */
    virtual eError operator %=(const cMPUnsigned& value) 
    {
        eError error = e_ERROR_FAILED;
        PMPUNSIGNED l_value = value.GetValue();

        if ((error = Create()))
            return error;

#if defined(_CMPUNSIGNED_BN)
/*
 * BIGNUM implementation
 */
        BN_mod(m_temp, m_value, l_value, m_ctx);
        BN_copy(m_value, m_temp);
        error = e_ERROR_NONE;
#elif defined(_CMPUNSIGNED_MP) 
/*
 * MP_INT implementation
 */
        mpz_mmod(&m_value, &m_value, l_value);
        error = e_ERROR_NONE;
#else /* defined(_CMPUNSIGNED_BN) */
/*
 * Otherwise 
 */
#endif /* defined(_CMPUNSIGNED_BN) */
        return error;
    }
};
#endif /* _CMPUNSIGNED_HXX */

/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ccryptohashinterface.hxx
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#if !defined(_CCRYPTOHASHINTERFACE_HXX) || defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY)
#if !defined(_CCRYPTOHASHINTERFACE_HXX) && !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY)
#define _CCRYPTOHASHINTERFACE_HXX
#endif /* !defined(_CCRYPTOHASHINTERFACE_HXX) && !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY)
/* cCryptoHashInterface definition
 */
#include "ccryptointerface.hxx"
/**
 **********************************************************************
 *  Class: cCryptoHashInterface
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cCryptoHashInterface
: virtual public cCryptoInterface
{
public:
    typedef cCryptoInterface cImplements;
    typedef cCryptoHashInterface cDerives;
#else /* !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual TLENGTH Initialize
    (const BYTE *key=0,
     TLENGTH keylen=-1) 
#if !defined(CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
#endif /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual TLENGTH Finalize
    (BYTE* out,
     TSIZE outsize) 
#if !defined(CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
#endif /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    virtual TLENGTH Hash
    (const BYTE* in,
     TLENGTH inlen=-1) 
#if !defined(CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
#endif /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */

#if !defined(CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     * Function: HashSize
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual TLENGTH HashSize() const = 0;
#else /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */
#endif /* CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT */

#if !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) 
};
/**
 **********************************************************************
 *  Class: cCryptoHashImplement
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cCryptoHashImplement
: virtual public cCryptoHashInterface
{
public:
    typedef cCryptoHashInterface cImplements;
    typedef cCryptoHashImplement cDerives;

/* include cCryptoHashInterface member functions implement
 */
#define CCRYPTOHASHINTERFACE_MEMBERS_ONLY
#define CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT
#include "ccryptohashinterface.hxx"
#undef CCRYPTOHASHINTERFACE_MEMBER_FUNCS_IMPLEMENT
#undef CCRYPTOHASHINTERFACE_MEMBERS_ONLY
};
#else /* !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOHASHINTERFACE_HXX) || defined(CCRYPTOHASHINTERFACE_MEMBERS_ONLY) */

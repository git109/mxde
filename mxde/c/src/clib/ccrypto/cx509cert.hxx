/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cx509cert.hxx
 *
 * Author: $author$
 *   Date: 4/2/2010
 **********************************************************************
 */
#if !defined(_CX509CERT_HXX) || defined(CX509CERT_MEMBERS_ONLY)
#if !defined(_CX509CERT_HXX) && !defined(CX509CERT_MEMBERS_ONLY)
#define _CX509CERT_HXX
#endif /* !defined(_CX509CERT_HXX) && !defined(CX509CERT_MEMBERS_ONLY) */

#if !defined(CX509CERT_MEMBERS_ONLY)
#include "ccryptobase.hxx"
#include "cx509certinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cX509CertExtend
 *
 *  Author: $author$
 *    Date: 4/2/2010
 **********************************************************************
 */
typedef cCryptoBase
cX509CertExtend;
/**
 **********************************************************************
 *  Class: cX509Cert
 *
 * Author: $author$
 *   Date: 4/2/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cX509Cert
: virtual public cX509CertImplement,
  public cX509CertExtend
{
public:
    typedef cX509CertImplement cImplements;
    typedef cX509CertExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cX509Cert
     *
     *       Author: $author$
     *         Date: 4/2/2010
     **********************************************************************
     */
    cX509Cert()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cX509Cert
     *
     *      Author: $author$
     *        Date: 4/2/2010
     **********************************************************************
     */
    virtual ~cX509Cert()
    {
    }
#else /* !defined(CX509CERT_MEMBERS_ONLY) */
#endif /* !defined(CX509CERT_MEMBERS_ONLY) */

#if !defined(CX509CERT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CX509CERT_MEMBERS_ONLY) */
#endif /* !defined(CX509CERT_MEMBERS_ONLY) */

#endif /* !defined(_CX509CERT_HXX) || defined(CX509CERT_MEMBERS_ONLY) */

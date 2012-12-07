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
 *   File: casn1base.hxx
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
#if !defined(_CASN1BASE_HXX) || defined(CASN1BASE_MEMBERS_ONLY)
#if !defined(_CASN1BASE_HXX) && !defined(CASN1BASE_MEMBERS_ONLY)
#define _CASN1BASE_HXX
#endif /* !defined(_CASN1BASE_HXX) && !defined(CASN1BASE_MEMBERS_ONLY) */

#if !defined(CASN1BASE_MEMBERS_ONLY)
#include "cbase.hxx"
#include "casn1.h"

#define c_ASN1_CLASS c_INSTANCE_CLASS

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1Base
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Base
{
public:
#else /* !defined(CASN1BASE_MEMBERS_ONLY) */
#endif /* !defined(CASN1BASE_MEMBERS_ONLY) */

#if !defined(CASN1BASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1BASE_MEMBERS_ONLY) */
#endif /* !defined(CASN1BASE_MEMBERS_ONLY) */

#endif /* !defined(_CASN1BASE_HXX) || defined(CASN1BASE_MEMBERS_ONLY) */

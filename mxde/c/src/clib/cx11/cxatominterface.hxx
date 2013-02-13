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
 *   File: cxatominterface.hxx
 *
 * Author: $author$           
 *   Date: 6/26/2010
 **********************************************************************
 */
#if !defined(_CXATOMINTERFACE_HXX) || defined(CXATOMINTERFACE_MEMBERS_ONLY)
#if !defined(_CXATOMINTERFACE_HXX) && !defined(CXATOMINTERFACE_MEMBERS_ONLY)
#define _CXATOMINTERFACE_HXX
#endif /* !defined(_CXATOMINTERFACE_HXX) && !defined(CXATOMINTERFACE_MEMBERS_ONLY) */

#if !defined(CXATOMINTERFACE_MEMBERS_ONLY)
#include "cxatomattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXAtomInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/26/2010
 **********************************************************************
 */
typedef cXAtomCreatedInterface
cXAtomInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXAtomInterface
 *
 * Author: $author$           
 *   Date: 6/26/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXAtomInterface
: virtual public cXAtomInterfaceImplement
{
public:
    typedef cXAtomInterfaceImplement cImplements;
#else /* !defined(CXATOMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXATOMINTERFACE_MEMBERS_ONLY) */

#if !defined(CXATOMINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXATOMIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXAtomImplement
 *
 * Author: $author$           
 *   Date: 6/26/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXAtomImplement
: virtual public cXAtomInterface
{
public:
    typedef cXAtomInterface cImplements;
#else /* !defined(CXATOMIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXATOMIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXATOMIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXATOMIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXATOMIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXATOMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXATOMINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXATOMINTERFACE_HXX) || defined(CXATOMINTERFACE_MEMBERS_ONLY) */

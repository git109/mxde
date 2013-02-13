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
 *   File: cxmmanagerinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMMANAGERINTERFACE_HXX) || defined(CXMMANAGERINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMMANAGERINTERFACE_HXX) && !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY)
#define _CXMMANAGERINTERFACE_HXX
#endif /* !defined(_CXMMANAGERINTERFACE_HXX) && !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY)
#include "cxtconstraintinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmManagerInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXtConstraintInterface
cXmManagerInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmManagerInterface
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmManagerInterface
: virtual public cXmManagerInterfaceImplement
{
public:
    typedef cXmManagerInterfaceImplement cImplements;
#else /* !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXMMANAGERIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXmManagerImplement
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmManagerImplement
: virtual public cXmManagerInterface
{
public:
    typedef cXmManagerInterface cImplements;
#else /* !defined(CXMMANAGERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMMANAGERIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMMANAGERIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXMMANAGERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMMANAGERIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMMANAGERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMMANAGERINTERFACE_HXX) || defined(CXMMANAGERINTERFACE_MEMBERS_ONLY) */

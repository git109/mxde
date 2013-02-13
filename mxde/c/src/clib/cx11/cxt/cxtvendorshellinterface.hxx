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
 *   File: cxtvendorshellinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTVENDORSHELLINTERFACE_HXX) || defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTVENDORSHELLINTERFACE_HXX) && !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY)
#define _CXTVENDORSHELLINTERFACE_HXX
#endif /* !defined(_CXTVENDORSHELLINTERFACE_HXX) && !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY)
#include "cxtwmshellinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtVendorShellInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtWMShellInterface
cXtVendorShellInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtVendorShellInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtVendorShellInterface
: virtual public cXtVendorShellInterfaceImplement
{
public:
    typedef cXtVendorShellInterfaceImplement cImplements;
#else /* !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY)
/* include cXtVendorShell member functions interface
 */
#define CXTVENDORSHELL_MEMBERS_ONLY
#define CXTVENDORSHELL_MEMBER_FUNCS_INTERFACE
//#include "cxtvendorshell.hxx"
#undef CXTVENDORSHELL_MEMBER_FUNCS_INTERFACE
#undef CXTVENDORSHELL_MEMBERS_ONLY
};

#if !defined(CXTVENDORSHELLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtVendorShellImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtVendorShellImplement
: virtual public cXtVendorShellInterface
{
public:
    typedef cXtVendorShellInterface cImplements;
#else /* !defined(CXTVENDORSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTVENDORSHELLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTVENDORSHELLIMPLEMENT_MEMBERS_ONLY)
/* include cXtVendorShell member functions implement
 */
#define CXTVENDORSHELL_MEMBERS_ONLY
#define CXTVENDORSHELL_MEMBER_FUNCS_IMPLEMENT
//#include "cxtvendorshell.hxx"
#undef CXTVENDORSHELL_MEMBER_FUNCS_IMPLEMENT
#undef CXTVENDORSHELL_MEMBERS_ONLY
};
#else /* !defined(CXTVENDORSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTVENDORSHELLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTVENDORSHELLINTERFACE_HXX) || defined(CXTVENDORSHELLINTERFACE_MEMBERS_ONLY) */

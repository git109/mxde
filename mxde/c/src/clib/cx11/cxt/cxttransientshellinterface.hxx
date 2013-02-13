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
 *   File: cxttransientshellinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTTRANSIENTSHELLINTERFACE_HXX) || defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTTRANSIENTSHELLINTERFACE_HXX) && !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY)
#define _CXTTRANSIENTSHELLINTERFACE_HXX
#endif /* !defined(_CXTTRANSIENTSHELLINTERFACE_HXX) && !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY)
#include "cxtvendorshellinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTransientShellInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtVendorShellInterface
cXtTransientShellInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtTransientShellInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtTransientShellInterface
: virtual public cXtTransientShellInterfaceImplement
{
public:
    typedef cXtTransientShellInterfaceImplement cImplements;
#else /* !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY)
/* include cXtTransientShell member functions interface
 */
#define CXTTRANSIENTSHELL_MEMBERS_ONLY
#define CXTTRANSIENTSHELL_MEMBER_FUNCS_INTERFACE
#include "cxttransientshell.hxx"
#undef CXTTRANSIENTSHELL_MEMBER_FUNCS_INTERFACE
#undef CXTTRANSIENTSHELL_MEMBERS_ONLY
};

#if !defined(CXTTRANSIENTSHELLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtTransientShellImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtTransientShellImplement
: virtual public cXtTransientShellInterface
{
public:
    typedef cXtTransientShellInterface cImplements;
#else /* !defined(CXTTRANSIENTSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTTRANSIENTSHELLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTTRANSIENTSHELLIMPLEMENT_MEMBERS_ONLY)
/* include cXtTransientShell member functions implement
 */
#define CXTTRANSIENTSHELL_MEMBERS_ONLY
#define CXTTRANSIENTSHELL_MEMBER_FUNCS_IMPLEMENT
#include "cxttransientshell.hxx"
#undef CXTTRANSIENTSHELL_MEMBER_FUNCS_IMPLEMENT
#undef CXTTRANSIENTSHELL_MEMBERS_ONLY
};
#else /* !defined(CXTTRANSIENTSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTTRANSIENTSHELLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTTRANSIENTSHELLINTERFACE_HXX) || defined(CXTTRANSIENTSHELLINTERFACE_MEMBERS_ONLY) */

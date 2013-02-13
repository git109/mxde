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
 *   File: cxttoplevelshellinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTTOPLEVELSHELLINTERFACE_HXX) || defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTTOPLEVELSHELLINTERFACE_HXX) && !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY)
#define _CXTTOPLEVELSHELLINTERFACE_HXX
#endif /* !defined(_CXTTOPLEVELSHELLINTERFACE_HXX) && !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY)
#include "cxtvendorshellinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTopLevelShellInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtVendorShellInterface
cXtTopLevelShellInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtTopLevelShellInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtTopLevelShellInterface
: virtual public cXtTopLevelShellInterfaceImplement
{
public:
    typedef cXtTopLevelShellInterfaceImplement cImplements;
#else /* !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY)
/* include cXtTopLevelShell member functions interface
 */
#define CXTTOPLEVELSHELL_MEMBERS_ONLY
#define CXTTOPLEVELSHELL_MEMBER_FUNCS_INTERFACE
//#include "cxttoplevelshell.hxx"
#undef CXTTOPLEVELSHELL_MEMBER_FUNCS_INTERFACE
#undef CXTTOPLEVELSHELL_MEMBERS_ONLY
};

#if !defined(CXTTOPLEVELSHELLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtTopLevelShellImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtTopLevelShellImplement
: virtual public cXtTopLevelShellInterface
{
public:
    typedef cXtTopLevelShellInterface cImplements;
#else /* !defined(CXTTOPLEVELSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTTOPLEVELSHELLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTTOPLEVELSHELLIMPLEMENT_MEMBERS_ONLY)
/* include cXtTopLevelShell member functions implement
 */
#define CXTTOPLEVELSHELL_MEMBERS_ONLY
#define CXTTOPLEVELSHELL_MEMBER_FUNCS_IMPLEMENT
//#include "cxttoplevelshell.hxx"
#undef CXTTOPLEVELSHELL_MEMBER_FUNCS_IMPLEMENT
#undef CXTTOPLEVELSHELL_MEMBERS_ONLY
};
#else /* !defined(CXTTOPLEVELSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTTOPLEVELSHELLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTTOPLEVELSHELLINTERFACE_HXX) || defined(CXTTOPLEVELSHELLINTERFACE_MEMBERS_ONLY) */

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
 *   File: cxtoverrideshellinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTOVERRIDESHELLINTERFACE_HXX) || defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTOVERRIDESHELLINTERFACE_HXX) && !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY)
#define _CXTOVERRIDESHELLINTERFACE_HXX
#endif /* !defined(_CXTOVERRIDESHELLINTERFACE_HXX) && !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY)
#include "cxtshellinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtOverrideShellInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtShellInterface
cXtOverrideShellInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtOverrideShellInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtOverrideShellInterface
: virtual public cXtOverrideShellInterfaceImplement
{
public:
    typedef cXtOverrideShellInterfaceImplement cImplements;
#else /* !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY)
/* include cXtOverrideShell member functions interface
 */
#define CXTOVERRIDESHELL_MEMBERS_ONLY
#define CXTOVERRIDESHELL_MEMBER_FUNCS_INTERFACE
#include "cxtoverrideshell.hxx"
#undef CXTOVERRIDESHELL_MEMBER_FUNCS_INTERFACE
#undef CXTOVERRIDESHELL_MEMBERS_ONLY
};

#if !defined(CXTOVERRIDESHELLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtOverrideShellImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtOverrideShellImplement
: virtual public cXtOverrideShellInterface
{
public:
    typedef cXtOverrideShellInterface cImplements;
#else /* !defined(CXTOVERRIDESHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTOVERRIDESHELLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTOVERRIDESHELLIMPLEMENT_MEMBERS_ONLY)
/* include cXtOverrideShell member functions implement
 */
#define CXTOVERRIDESHELL_MEMBERS_ONLY
#define CXTOVERRIDESHELL_MEMBER_FUNCS_IMPLEMENT
#include "cxtoverrideshell.hxx"
#undef CXTOVERRIDESHELL_MEMBER_FUNCS_IMPLEMENT
#undef CXTOVERRIDESHELL_MEMBERS_ONLY
};
#else /* !defined(CXTOVERRIDESHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTOVERRIDESHELLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTOVERRIDESHELLINTERFACE_HXX) || defined(CXTOVERRIDESHELLINTERFACE_MEMBERS_ONLY) */

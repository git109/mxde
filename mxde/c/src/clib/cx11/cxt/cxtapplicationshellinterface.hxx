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
 *   File: cxtapplicationshellinterface.hxx
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
#if !defined(_CXTAPPLICATIONSHELLINTERFACE_HXX) || defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTAPPLICATIONSHELLINTERFACE_HXX) && !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY)
#define _CXTAPPLICATIONSHELLINTERFACE_HXX
#endif /* !defined(_CXTAPPLICATIONSHELLINTERFACE_HXX) && !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY)
#include "cxtwmshellinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtApplicationShellInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 5/19/2010
 **********************************************************************
 */
typedef cXtWMShellInterface
cXtApplicationShellInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtApplicationShellInterface
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtApplicationShellInterface
: virtual public cXtApplicationShellInterfaceImplement
{
public:
    typedef cXtApplicationShellInterfaceImplement cImplements;
#else /* !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY)
/* include cXtApplicationShell member functions interface
 */
#define CXTAPPLICATIONSHELL_MEMBERS_ONLY
#define CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE
#include "cxtapplicationshell.hxx"
#undef CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE
#undef CXTAPPLICATIONSHELL_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXtApplicationShellImplement
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtApplicationShellImplement
: virtual public cXtApplicationShellInterface
{
public:
    typedef cXtApplicationShellInterface cImplements;
/* include cXtApplicationShell member functions implement
 */
#define CXTAPPLICATIONSHELL_MEMBERS_ONLY
#define CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT
#include "cxtapplicationshell.hxx"
#undef CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT
#undef CXTAPPLICATIONSHELL_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTAPPLICATIONSHELLINTERFACE_HXX) || defined(CXTAPPLICATIONSHELLINTERFACE_MEMBERS_ONLY) */

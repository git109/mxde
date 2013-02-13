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
 *   File: cxtwmshellinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTWMSHELLINTERFACE_HXX) || defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTWMSHELLINTERFACE_HXX) && !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY)
#define _CXTWMSHELLINTERFACE_HXX
#endif /* !defined(_CXTWMSHELLINTERFACE_HXX) && !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY)
#include "cplatform_X11_Shell.h"
#include "cxtwindowobjinterface.hxx"
#include "cxmwmhintsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWMShellInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtWindowObjInterface
cXtWMShellInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtWMShellInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWMShellInterface
: virtual public cXtWMShellInterfaceImplement
{
public:
    typedef cXtWMShellInterfaceImplement cImplements;
#else /* !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY)
/* include cXtWMShell member functions interface
 */
#define CXTWMSHELL_MEMBERS_ONLY
#define CXTWMSHELL_MEMBER_FUNCS_INTERFACE
#include "cxtwmshell.hxx"
#undef CXTWMSHELL_MEMBER_FUNCS_INTERFACE
#undef CXTWMSHELL_MEMBERS_ONLY
};

#if !defined(CXTWMSHELLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtWMShellImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWMShellImplement
: virtual public cXtWMShellInterface
{
public:
    typedef cXtWMShellInterface cImplements;
#else /* !defined(CXTWMSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWMSHELLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTWMSHELLIMPLEMENT_MEMBERS_ONLY)
/* include cXtWMShell member functions implement
 */
#define CXTWMSHELL_MEMBERS_ONLY
#define CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT
#include "cxtwmshell.hxx"
#undef CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT
#undef CXTWMSHELL_MEMBERS_ONLY
};
#else /* !defined(CXTWMSHELLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWMSHELLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTWMSHELLINTERFACE_HXX) || defined(CXTWMSHELLINTERFACE_MEMBERS_ONLY) */

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
 *   File: cxttransientshell.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTTRANSIENTSHELL_HXX) || defined(CXTTRANSIENTSHELL_MEMBERS_ONLY)
#if !defined(_CXTTRANSIENTSHELL_HXX) && !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY)
#define _CXTTRANSIENTSHELL_HXX
#endif /* !defined(_CXTTRANSIENTSHELL_HXX) && !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY) */

#if !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY)
#include "cxttransientshellinterface.hxx"
#include "cxtvendorshell.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTransientShellExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtVendorShell
cXtTransientShellExtend;
/**
 **********************************************************************
 *  Class: cXtTransientShell
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtTransientShell
: virtual public cXtTransientShellImplement,
  public cXtTransientShellExtend
{
public:
    typedef cXtTransientShellImplement cImplements;
    typedef cXtTransientShellExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtTransientShell
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtTransientShell
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtTransientShell
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtTransientShell()
    {
    }
#else /* !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY) */

#if !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTTRANSIENTSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTTRANSIENTSHELL_HXX) || defined(CXTTRANSIENTSHELL_MEMBERS_ONLY) */

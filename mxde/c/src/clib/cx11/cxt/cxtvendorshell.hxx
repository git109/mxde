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
 *   File: cxtvendorshell.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTVENDORSHELL_HXX) || defined(CXTVENDORSHELL_MEMBERS_ONLY)
#if !defined(_CXTVENDORSHELL_HXX) && !defined(CXTVENDORSHELL_MEMBERS_ONLY)
#define _CXTVENDORSHELL_HXX
#endif /* !defined(_CXTVENDORSHELL_HXX) && !defined(CXTVENDORSHELL_MEMBERS_ONLY) */

#if !defined(CXTVENDORSHELL_MEMBERS_ONLY)
#include "cxtvendorshellinterface.hxx"
#include "cxtwmshell.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtVendorShellExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtWMShell
cXtVendorShellExtend;
/**
 **********************************************************************
 *  Class: cXtVendorShell
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtVendorShell
: virtual public cXtVendorShellImplement,
  public cXtVendorShellExtend
{
public:
    typedef cXtVendorShellImplement cImplements;
    typedef cXtVendorShellExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtVendorShell
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtVendorShell
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtVendorShell
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtVendorShell()
    {
    }
#else /* !defined(CXTVENDORSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTVENDORSHELL_MEMBERS_ONLY) */

#if !defined(CXTVENDORSHELL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTVENDORSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTVENDORSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTVENDORSHELL_HXX) || defined(CXTVENDORSHELL_MEMBERS_ONLY) */

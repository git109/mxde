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
 *   File: cxtoverrideshell.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTOVERRIDESHELL_HXX) || defined(CXTOVERRIDESHELL_MEMBERS_ONLY)
#if !defined(_CXTOVERRIDESHELL_HXX) && !defined(CXTOVERRIDESHELL_MEMBERS_ONLY)
#define _CXTOVERRIDESHELL_HXX
#endif /* !defined(_CXTOVERRIDESHELL_HXX) && !defined(CXTOVERRIDESHELL_MEMBERS_ONLY) */

#if !defined(CXTOVERRIDESHELL_MEMBERS_ONLY)
#include "cxtoverrideshellinterface.hxx"
#include "cxtshell.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtOverrideShellExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtShell
cXtOverrideShellExtend;
/**
 **********************************************************************
 *  Class: cXtOverrideShell
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtOverrideShell
: virtual public cXtOverrideShellImplement,
  public cXtOverrideShellExtend
{
public:
    typedef cXtOverrideShellImplement cImplements;
    typedef cXtOverrideShellExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtOverrideShell
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtOverrideShell
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtOverrideShell
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtOverrideShell()
    {
    }
#else /* !defined(CXTOVERRIDESHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTOVERRIDESHELL_MEMBERS_ONLY) */

#if !defined(CXTOVERRIDESHELL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTOVERRIDESHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTOVERRIDESHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTOVERRIDESHELL_HXX) || defined(CXTOVERRIDESHELL_MEMBERS_ONLY) */

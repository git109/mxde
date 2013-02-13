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
 *   File: cxmapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
#if !defined(_CXMAPPLICATIONSHELL_HXX) || defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXMAPPLICATIONSHELL_HXX) && !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXMAPPLICATIONSHELL_HXX
#endif /* !defined(_CXMAPPLICATIONSHELL_HXX) && !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cplatform_Xm_Protocols.h"
#include "cxtapplicationshell.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cXtApplicationShell
cXmApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXmApplicationShell
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmApplicationShell
: /*virtual public cXmApplicationShellImplement,
  */public cXmApplicationShellExtend
{
public:
    /*typedef cXmApplicationShellImplement cImplements;
    */typedef cXmApplicationShellExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmApplicationShell
     *
     *       Author: $author$           
     *         Date: 5/1/2010
     **********************************************************************
     */
    cXmApplicationShell
    (cXDisplayInterface& display,
     const XtChar* name = CXTWIDGET_NAME,
     const XtChar* className = CXTWIDGET_CLASS_NAME,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, name, className,
       widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmApplicationShell
     *
     *      Author: $author$           
     *        Date: 5/1/2010
     **********************************************************************
     */
    virtual ~cXmApplicationShell()
    {
    }
#else /* !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXMAPPLICATIONSHELL_HXX) || defined(CXMAPPLICATIONSHELL_MEMBERS_ONLY) */

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
 *   File: cxtapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
#if !defined(_CXTAPPLICATIONSHELL_HXX) || defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXTAPPLICATIONSHELL_HXX) && !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXTAPPLICATIONSHELL_HXX
#endif /* !defined(_CXTAPPLICATIONSHELL_HXX) && !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cxtapplicationshellinterface.hxx"
#include "cxttoplevelshell.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cXtTopLevelShell
cXtApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXtApplicationShell
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtApplicationShell
: virtual public cXtApplicationShellImplement,
  public cXtApplicationShellExtend
{
public:
    typedef cXtApplicationShellImplement cImplements;
    typedef cXtApplicationShellExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtApplicationShell
     *
     *       Author: $author$           
     *         Date: 5/1/2010
     **********************************************************************
     */
    cXtApplicationShell
    (cXDisplayInterface& display,
     const XtChar* name = CXTWIDGET_NAME,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, name,
       widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtApplicationShell
     *
     *      Author: $author$           
     *        Date: 5/1/2010
     **********************************************************************
     */
    virtual ~cXtApplicationShell()
    {
    }
#else /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: WidgetClassToAttach
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual WidgetClass WidgetClassToAttach() const
    {
        return applicationShellWidgetClass;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTAPPLICATIONSHELL_HXX) || defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

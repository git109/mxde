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
 *   File: cxmmanager.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMMANAGER_HXX) || defined(CXMMANAGER_MEMBERS_ONLY)
#if !defined(_CXMMANAGER_HXX) && !defined(CXMMANAGER_MEMBERS_ONLY)
#define _CXMMANAGER_HXX
#endif /* !defined(_CXMMANAGER_HXX) && !defined(CXMMANAGER_MEMBERS_ONLY) */

#if !defined(CXMMANAGER_MEMBERS_ONLY)
#include "cxmmanagerinterface.hxx"
#include "cxtconstraint.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmManagerExtend
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXtConstraint
cXmManagerExtend;
/**
 **********************************************************************
 *  Class: cXmManager
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmManager
: virtual public cXmManagerImplement,
  public cXmManagerExtend
{
public:
    typedef cXmManagerImplement cImplements;
    typedef cXmManagerExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmManager
     *
     *       Author: $author$           
     *         Date: 6/27/2010
     **********************************************************************
     */
    cXmManager
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmManager
     *
     *      Author: $author$           
     *        Date: 6/27/2010
     **********************************************************************
     */
    virtual ~cXmManager()
    {
    }
#else /* !defined(CXMMANAGER_MEMBERS_ONLY) */
#endif /* !defined(CXMMANAGER_MEMBERS_ONLY) */

#if !defined(CXMMANAGER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMMANAGER_MEMBERS_ONLY) */
#endif /* !defined(CXMMANAGER_MEMBERS_ONLY) */

#endif /* !defined(_CXMMANAGER_HXX) || defined(CXMMANAGER_MEMBERS_ONLY) */

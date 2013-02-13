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
 *   File: cxtobject.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTOBJECT_HXX) || defined(CXTOBJECT_MEMBERS_ONLY)
#if !defined(_CXTOBJECT_HXX) && !defined(CXTOBJECT_MEMBERS_ONLY)
#define _CXTOBJECT_HXX
#endif /* !defined(_CXTOBJECT_HXX) && !defined(CXTOBJECT_MEMBERS_ONLY) */

#if !defined(CXTOBJECT_MEMBERS_ONLY)
#include "cxtobjectinterface.hxx"
#include "cxtwidget.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtObjectExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtWidget
cXtObjectExtend;
/**
 **********************************************************************
 *  Class: cXtObject
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtObject
: virtual public cXtObjectImplement,
  public cXtObjectExtend
{
public:
    typedef cXtObjectImplement cImplements;
    typedef cXtObjectExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtObject
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtObject
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtObject
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtObject
    (cXDisplayInterface& display,
     const XtChar* name,
     WidgetClass widgetClassAttached,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtObject
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtObject()
    {
    }
#else /* !defined(CXTOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CXTOBJECT_MEMBERS_ONLY) */

#if !defined(CXTOBJECT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CXTOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CXTOBJECT_HXX) || defined(CXTOBJECT_MEMBERS_ONLY) */

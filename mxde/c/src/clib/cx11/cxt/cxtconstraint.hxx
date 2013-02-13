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
 *   File: cxtconstraint.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTCONSTRAINT_HXX) || defined(CXTCONSTRAINT_MEMBERS_ONLY)
#if !defined(_CXTCONSTRAINT_HXX) && !defined(CXTCONSTRAINT_MEMBERS_ONLY)
#define _CXTCONSTRAINT_HXX
#endif /* !defined(_CXTCONSTRAINT_HXX) && !defined(CXTCONSTRAINT_MEMBERS_ONLY) */

#if !defined(CXTCONSTRAINT_MEMBERS_ONLY)
#include "cxtconstraintinterface.hxx"
#include "cxtcomposite.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtConstraintExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtComposite
cXtConstraintExtend;
/**
 **********************************************************************
 *  Class: cXtConstraint
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtConstraint
: virtual public cXtConstraintImplement,
  public cXtConstraintExtend
{
public:
    typedef cXtConstraintImplement cImplements;
    typedef cXtConstraintExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtConstraint
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtConstraint
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtConstraint
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtConstraint
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
     *  Destructor: ~cXtConstraint
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtConstraint()
    {
    }
#else /* !defined(CXTCONSTRAINT_MEMBERS_ONLY) */
#endif /* !defined(CXTCONSTRAINT_MEMBERS_ONLY) */

#if !defined(CXTCONSTRAINT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCONSTRAINT_MEMBERS_ONLY) */
#endif /* !defined(CXTCONSTRAINT_MEMBERS_ONLY) */

#endif /* !defined(_CXTCONSTRAINT_HXX) || defined(CXTCONSTRAINT_MEMBERS_ONLY) */

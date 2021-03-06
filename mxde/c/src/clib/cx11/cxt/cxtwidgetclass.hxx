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
 *   File: cxtwidgetclass.hxx
 *
 * Author: $author$           
 *   Date: 6/24/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETCLASS_HXX) || defined(CXTWIDGETCLASS_MEMBERS_ONLY)
#if !defined(_CXTWIDGETCLASS_HXX) && !defined(CXTWIDGETCLASS_MEMBERS_ONLY)
#define _CXTWIDGETCLASS_HXX
#endif /* !defined(_CXTWIDGETCLASS_HXX) && !defined(CXTWIDGETCLASS_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCLASS_MEMBERS_ONLY)
#include "cxtwidgetclassinterface.hxx"
#include "cxtwidgetclassattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWidgetClassExtend
 *
 *  Author: $author$           
 *    Date: 6/24/2010
 **********************************************************************
 */
typedef cXtWidgetClassAttached
cXtWidgetClassExtend;
/**
 **********************************************************************
 *  Class: cXtWidgetClass
 *
 * Author: $author$           
 *   Date: 6/24/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWidgetClass
: virtual public cXtWidgetClassImplement,
  public cXtWidgetClassExtend
{
public:
    typedef cXtWidgetClassImplement cImplements;
    typedef cXtWidgetClassExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtWidgetClass
     *
     *       Author: $author$           
     *         Date: 6/24/2010
     **********************************************************************
     */
    cXtWidgetClass
    (WidgetClass attached = 0)
    : cExtends(attached)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtWidgetClass
     *
     *      Author: $author$           
     *        Date: 6/24/2010
     **********************************************************************
     */
    virtual ~cXtWidgetClass()
    {
    }
#else /* !defined(CXTWIDGETCLASS_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASS_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGETCLASS_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETCLASS_HXX) || defined(CXTWIDGETCLASS_MEMBERS_ONLY) */

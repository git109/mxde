/**
 **********************************************************************
 * Copyright (c) 1988-2013 $organization$
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
 *   File: cxawform.hxx
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
#if !defined(_CXAWFORM_HXX) || defined(CXAWFORM_MEMBERS_ONLY)
#if !defined(_CXAWFORM_HXX) && !defined(CXAWFORM_MEMBERS_ONLY)
#define _CXAWFORM_HXX
#endif /* !defined(_CXAWFORM_HXX) && !defined(CXAWFORM_MEMBERS_ONLY) */

#if !defined(CXAWFORM_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Form.h"
#include "cxtconstraint.hxx"

#define CXAWFORM_WIDGET_NAME "formWidget"
#define CXAWFORM_WIDGET_CLASS formWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXtConstraintImplement cXawFormImplement;
typedef cXtConstraint cXawFormExtend;
/**
 **********************************************************************
 *  Class: cXawForm
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXawForm
: virtual public cXawFormImplement,
  public cXawFormExtend
{
public:
    typedef cXawFormImplement cImplements;
    typedef cXawFormExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXawForm
     *
     *       Author: $author$
     *         Date: 6/24/2013
     **********************************************************************
     */
    cXawForm
    (cXDisplayInterface& display,
     const XtChar* name = CXAWFORM_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXAWFORM_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXawForm
     *
     *      Author: $author$
     *        Date: 6/24/2013
     **********************************************************************
     */
    virtual ~cXawForm()
    {
    }
#else /* !defined(CXAWFORM_MEMBERS_ONLY) */
#endif /* !defined(CXAWFORM_MEMBERS_ONLY) */

#if !defined(CXAWFORM_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXAWFORM_MEMBERS_ONLY) */
#endif /* !defined(CXAWFORM_MEMBERS_ONLY) */

#endif /* !defined(_CXAWFORM_HXX) || defined(CXAWFORM_MEMBERS_ONLY) */
        


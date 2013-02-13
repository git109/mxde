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
 *   File: cxmform.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMFORM_HXX) || defined(CXMFORM_MEMBERS_ONLY)
#if !defined(_CXMFORM_HXX) && !defined(CXMFORM_MEMBERS_ONLY)
#define _CXMFORM_HXX
#endif /* !defined(_CXMFORM_HXX) && !defined(CXMFORM_MEMBERS_ONLY) */

#if !defined(CXMFORM_MEMBERS_ONLY)
#include "cxmforminterface.hxx"
#include "cxmbulletinboard.hxx"

#define CXMFORM_WIDGET_NAME "xmFormWidget"
#define CXMFORM_WIDGET_CLASS xmFormWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmFormExtend
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXmBulletinBoard
cXmFormExtend;
/**
 **********************************************************************
 *  Class: cXmForm
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmForm
: virtual public cXmFormImplement,
  public cXmFormExtend
{
public:
    typedef cXmFormImplement cImplements;
    typedef cXmFormExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmForm
     *
     *       Author: $author$           
     *         Date: 6/27/2010
     **********************************************************************
     */
    cXmForm
    (cXDisplayInterface& display,
     const XtChar* name = CXMFORM_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXMFORM_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmForm
     *
     *      Author: $author$           
     *        Date: 6/27/2010
     **********************************************************************
     */
    virtual ~cXmForm()
    {
    }
#else /* !defined(CXMFORM_MEMBERS_ONLY) */
#endif /* !defined(CXMFORM_MEMBERS_ONLY) */

#if !defined(CXMFORM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMFORM_MEMBERS_ONLY) */
#endif /* !defined(CXMFORM_MEMBERS_ONLY) */

#endif /* !defined(_CXMFORM_HXX) || defined(CXMFORM_MEMBERS_ONLY) */

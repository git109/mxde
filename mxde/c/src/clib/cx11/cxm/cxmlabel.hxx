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
 *   File: cxmlabel.hxx
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
#if !defined(_CXMLABEL_HXX) || defined(CXMLABEL_MEMBERS_ONLY)
#if !defined(_CXMLABEL_HXX) && !defined(CXMLABEL_MEMBERS_ONLY)
#define _CXMLABEL_HXX
#endif /* !defined(_CXMLABEL_HXX) && !defined(CXMLABEL_MEMBERS_ONLY) */

#if !defined(CXMLABEL_MEMBERS_ONLY)
#include "cxmlabelinterface.hxx"
#include "cxmprimitive.hxx"

#define CXMLABEL_WIDGET_NAME "cXmLabel"
#define CXMLABEL_WIDGET_CLASS xmLabelWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmLabelExtend
 *
 *  Author: $author$           
 *    Date: 7/12/2010
 **********************************************************************
 */
typedef cXmPrimitive
cXmLabelExtend;
/**
 **********************************************************************
 *  Class: cXmLabel
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmLabel
: virtual public cXmLabelImplement,
  public cXmLabelExtend
{
public:
    typedef cXmLabelImplement cImplements;
    typedef cXmLabelExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmLabel
     *
     *       Author: $author$           
     *         Date: 7/12/2010
     **********************************************************************
     */
    cXmLabel
    (cXDisplayInterface& display,
     const XtChar* name = CXMLABEL_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXMLABEL_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmLabel
     *
     *      Author: $author$           
     *        Date: 7/12/2010
     **********************************************************************
     */
    virtual ~cXmLabel()
    {
    }
#else /* !defined(CXMLABEL_MEMBERS_ONLY) */
#endif /* !defined(CXMLABEL_MEMBERS_ONLY) */

#if !defined(CXMLABEL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMLABEL_MEMBERS_ONLY) */
#endif /* !defined(CXMLABEL_MEMBERS_ONLY) */

#endif /* !defined(_CXMLABEL_HXX) || defined(CXMLABEL_MEMBERS_ONLY) */

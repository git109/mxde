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
 *   File: cxawlabel.hxx
 *
 * Author: $author$
 *   Date: 6/25/2013
 **********************************************************************
 */
#if !defined(_CXAWLABEL_HXX) || defined(CXAWLABEL_MEMBERS_ONLY)
#if !defined(_CXAWLABEL_HXX) && !defined(CXAWLABEL_MEMBERS_ONLY)
#define _CXAWLABEL_HXX
#endif /* !defined(_CXAWLABEL_HXX) && !defined(CXAWLABEL_MEMBERS_ONLY) */

#if !defined(CXAWLABEL_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Label.h"
#include "cxawsimple.hxx"

#define CXAWLABEL_WIDGET_NAME "labelWidget"
#define CXAWLABEL_WIDGET_CLASS labelWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXawSimpleImplement cXawLabelImplement;
typedef cXawSimple cXawLabelExtend;
/**
 **********************************************************************
 *  Class: cXawLabel
 *
 * Author: $author$
 *   Date: 6/25/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXawLabel
: virtual public cXawLabelImplement,
  public cXawLabelExtend
{
public:
    typedef cXawLabelImplement cImplements;
    typedef cXawLabelExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXawLabel
     *
     *       Author: $author$
     *         Date: 6/25/2013
     **********************************************************************
     */
    cXawLabel
    (cXDisplayInterface& display,
     const XtChar* name = CXAWLABEL_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXAWLABEL_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXawLabel
     *
     *      Author: $author$
     *        Date: 6/25/2013
     **********************************************************************
     */
    virtual ~cXawLabel()
    {
    }
#else /* !defined(CXAWLABEL_MEMBERS_ONLY) */
#endif /* !defined(CXAWLABEL_MEMBERS_ONLY) */

#if !defined(CXAWLABEL_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXAWLABEL_MEMBERS_ONLY) */
#endif /* !defined(CXAWLABEL_MEMBERS_ONLY) */

#endif /* !defined(_CXAWLABEL_HXX) || defined(CXAWLABEL_MEMBERS_ONLY) */
        


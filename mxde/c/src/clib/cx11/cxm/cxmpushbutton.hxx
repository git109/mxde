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
 *   File: cxmpushbutton.hxx
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
#if !defined(_CXMPUSHBUTTON_HXX) || defined(CXMPUSHBUTTON_MEMBERS_ONLY)
#if !defined(_CXMPUSHBUTTON_HXX) && !defined(CXMPUSHBUTTON_MEMBERS_ONLY)
#define _CXMPUSHBUTTON_HXX
#endif /* !defined(_CXMPUSHBUTTON_HXX) && !defined(CXMPUSHBUTTON_MEMBERS_ONLY) */

#if !defined(CXMPUSHBUTTON_MEMBERS_ONLY)
#include "cxmpushbuttoninterface.hxx"
#include "cxmlabel.hxx"

#define CXMPUSHBUTTON_WIDGET_NAME "xmPushButton"
#define CXMPUSHBUTTON_WIDGET_CLASS xmPushButtonWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmPushButtonExtend
 *
 *  Author: $author$           
 *    Date: 7/12/2010
 **********************************************************************
 */
typedef cXmLabel
cXmPushButtonExtend;
/**
 **********************************************************************
 *  Class: cXmPushButton
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmPushButton
: virtual public cXmPushButtonImplement,
  public cXmPushButtonExtend
{
public:
    typedef cXmPushButtonImplement cImplements;
    typedef cXmPushButtonExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmPushButton
     *
     *       Author: $author$           
     *         Date: 7/12/2010
     **********************************************************************
     */
    cXmPushButton
    (cXDisplayInterface& display,
     const XtChar* name = CXMPUSHBUTTON_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXMPUSHBUTTON_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmPushButton
     *
     *      Author: $author$           
     *        Date: 7/12/2010
     **********************************************************************
     */
    virtual ~cXmPushButton()
    {
    }
#else /* !defined(CXMPUSHBUTTON_MEMBERS_ONLY) */
#endif /* !defined(CXMPUSHBUTTON_MEMBERS_ONLY) */

#if !defined(CXMPUSHBUTTON_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMPUSHBUTTON_MEMBERS_ONLY) */
#endif /* !defined(CXMPUSHBUTTON_MEMBERS_ONLY) */

#endif /* !defined(_CXMPUSHBUTTON_HXX) || defined(CXMPUSHBUTTON_MEMBERS_ONLY) */

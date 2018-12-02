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
 *   File: cxmscrolledwindow.hxx
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
#if !defined(_CXMSCROLLEDWINDOW_HXX) || defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY)
#if !defined(_CXMSCROLLEDWINDOW_HXX) && !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY)
#define _CXMSCROLLEDWINDOW_HXX
#endif /* !defined(_CXMSCROLLEDWINDOW_HXX) && !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY) */

#if !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY)
#include "cplatform_Xm_ScrolledW.h"
#include "cxmmanager.hxx"

#define CXMSCROLLEDWINDOW_WIDGET_CLASS xmScrolledWindowWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXmManagerImplement cXmScrolledWindowImplement;
typedef cXmManager cXmScrolledWindowExtend;
/**
 **********************************************************************
 *  Class: cXmScrolledWindow
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmScrolledWindow
: virtual public cXmScrolledWindowImplement,
  public cXmScrolledWindowExtend
{
public:
    typedef cXmScrolledWindowImplement cImplements;
    typedef cXmScrolledWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmScrolledWindow
     *
     *       Author: $author$
     *         Date: 6/24/2013
     **********************************************************************
     */
    cXmScrolledWindow
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     WidgetClass widgetClassAttached = CXMSCROLLEDWINDOW_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmScrolledWindow
     *
     *      Author: $author$
     *        Date: 6/24/2013
     **********************************************************************
     */
    virtual ~cXmScrolledWindow()
    {
    }
#else /* !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY) */

#if !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CXMSCROLLEDWINDOW_HXX) || defined(CXMSCROLLEDWINDOW_MEMBERS_ONLY) */
        


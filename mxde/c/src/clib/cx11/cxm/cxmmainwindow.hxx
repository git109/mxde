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
 *   File: cxmmainwindow.hxx
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
#if !defined(_CXMMAINWINDOW_HXX) || defined(CXMMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CXMMAINWINDOW_HXX) && !defined(CXMMAINWINDOW_MEMBERS_ONLY)
#define _CXMMAINWINDOW_HXX
#endif /* !defined(_CXMMAINWINDOW_HXX) && !defined(CXMMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CXMMAINWINDOW_MEMBERS_ONLY)
#include "cplatform_Xm_MainW.h"
#include "cxmscrolledwindow.hxx"

#define CXMMAINWINDOW_WIDGET_NAME "xmMainWindow"
#define CXMMAINWINDOW_WIDGET_CLASS xmMainWindowWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXmScrolledWindowImplement cXmMainWindowImplement;
typedef cXmScrolledWindow cXmMainWindowExtend;
/**
 **********************************************************************
 *  Class: cXmMainWindow
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmMainWindow
: virtual public cXmMainWindowImplement,
  public cXmMainWindowExtend
{
public:
    typedef cXmMainWindowImplement cImplements;
    typedef cXmMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmMainWindow
     *
     *       Author: $author$
     *         Date: 6/24/2013
     **********************************************************************
     */
    cXmMainWindow
    (cXDisplayInterface& display,
     const XtChar* name = CXMMAINWINDOW_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXMMAINWINDOW_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmMainWindow
     *
     *      Author: $author$
     *        Date: 6/24/2013
     **********************************************************************
     */
    virtual ~cXmMainWindow()
    {
    }
#else /* !defined(CXMMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXMMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CXMMAINWINDOW_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXMMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CXMMAINWINDOW_HXX) || defined(CXMMAINWINDOW_MEMBERS_ONLY) */
        


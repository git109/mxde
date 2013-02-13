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
 *   File: cxtcommandwidget.hxx
 *
 * Author: $author$           
 *   Date: 5/17/2010
 **********************************************************************
 */
#if !defined(_CXTCOMMANDWIDGET_HXX) || defined(CXTCOMMANDWIDGET_MEMBERS_ONLY)
#if !defined(_CXTCOMMANDWIDGET_HXX) && !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY)
#define _CXTCOMMANDWIDGET_HXX
#endif /* !defined(_CXTCOMMANDWIDGET_HXX) && !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY) */

#if !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Command.h"
#include "cxtwidget.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCommandWidgetExtend
 *
 *  Author: $author$           
 *    Date: 5/17/2010
 **********************************************************************
 */
typedef cXtWidget
cXtCommandWidgetExtend;
/**
 **********************************************************************
 *  Class: cXtCommandWidget
 *
 * Author: $author$           
 *   Date: 5/17/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtCommandWidget
: /*virtual public cXtCommandWidgetImplement,
  */public cXtCommandWidgetExtend
{
public:
    /*typedef cXtCommandWidgetImplement cImplements;
    */typedef cXtCommandWidgetExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cXtCommandWidget
     *
     *       Author: $author$           
     *         Date: 5/17/2010
     **********************************************************************
     */
    cXtCommandWidget
    (cXDisplayInterface& display,
     const XtChar* name = CXTWIDGET_NAME,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, name, 
       widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtCommandWidget
     *
     *      Author: $author$           
     *        Date: 5/17/2010
     **********************************************************************
     */
    virtual ~cXtCommandWidget()
    {
    }
#else /* !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY) */

#if !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: WidgetClassToAttach
     *
     *    Author: $author$           
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual WidgetClass WidgetClassToAttach() const
    {
        WidgetClass widgetClass = commandWidgetClass;
        return widgetClass;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTCOMMANDWIDGET_MEMBERS_ONLY) */

#endif /* !defined(_CXTCOMMANDWIDGET_HXX) || defined(CXTCOMMANDWIDGET_MEMBERS_ONLY) */

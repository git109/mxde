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
 *   File: cxawcommand.hxx
 *
 * Author: $author$
 *   Date: 6/25/2013
 **********************************************************************
 */
#if !defined(_CXAWCOMMAND_HXX) || defined(CXAWCOMMAND_MEMBERS_ONLY)
#if !defined(_CXAWCOMMAND_HXX) && !defined(CXAWCOMMAND_MEMBERS_ONLY)
#define _CXAWCOMMAND_HXX
#endif /* !defined(_CXAWCOMMAND_HXX) && !defined(CXAWCOMMAND_MEMBERS_ONLY) */

#if !defined(CXAWCOMMAND_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Command.h"
#include "cxawlabel.hxx"

#define CXAWCOMMAND_WIDGET_NAME "commandWidget"
#define CXAWCOMMAND_WIDGET_CLASS commandWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXawLabelImplement cXawCommandImplement;
typedef cXawLabel cXawCommandExtend;
/**
 **********************************************************************
 *  Class: cXawCommand
 *
 * Author: $author$
 *   Date: 6/25/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXawCommand
: virtual public cXawCommandImplement,
  public cXawCommandExtend
{
public:
    typedef cXawCommandImplement cImplements;
    typedef cXawCommandExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXawCommand
     *
     *       Author: $author$
     *         Date: 6/25/2013
     **********************************************************************
     */
    cXawCommand
    (cXDisplayInterface& display,
     const XtChar* name = CXAWCOMMAND_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXAWCOMMAND_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXawCommand
     *
     *      Author: $author$
     *        Date: 6/25/2013
     **********************************************************************
     */
    virtual ~cXawCommand()
    {
    }
#else /* !defined(CXAWCOMMAND_MEMBERS_ONLY) */
#endif /* !defined(CXAWCOMMAND_MEMBERS_ONLY) */

#if !defined(CXAWCOMMAND_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXAWCOMMAND_MEMBERS_ONLY) */
#endif /* !defined(CXAWCOMMAND_MEMBERS_ONLY) */

#endif /* !defined(_CXAWCOMMAND_HXX) || defined(CXAWCOMMAND_MEMBERS_ONLY) */
        


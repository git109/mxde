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
 *   File: cxawsimple.hxx
 *
 * Author: $author$
 *   Date: 6/25/2013
 **********************************************************************
 */
#if !defined(_CXAWSIMPLE_HXX) || defined(CXAWSIMPLE_MEMBERS_ONLY)
#if !defined(_CXAWSIMPLE_HXX) && !defined(CXAWSIMPLE_MEMBERS_ONLY)
#define _CXAWSIMPLE_HXX
#endif /* !defined(_CXAWSIMPLE_HXX) && !defined(CXAWSIMPLE_MEMBERS_ONLY) */

#if !defined(CXAWSIMPLE_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Simple.h"
#include "cxtcore.hxx"

#define CXAWSIMPLE_WIDGET_NAME "simpleWidget"
#define CXAWSIMPLE_WIDGET_CLASS simpleWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXtCoreImplement cXawSimpleImplement;
typedef cXtCore cXawSimpleExtend;
/**
 **********************************************************************
 *  Class: cXawSimple
 *
 * Author: $author$
 *   Date: 6/25/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXawSimple
: virtual public cXawSimpleImplement,
  public cXawSimpleExtend
{
public:
    typedef cXawSimpleImplement cImplements;
    typedef cXawSimpleExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXawSimple
     *
     *       Author: $author$
     *         Date: 6/25/2013
     **********************************************************************
     */
    cXawSimple
    (cXDisplayInterface& display,
     const XtChar* name = CXAWSIMPLE_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXAWSIMPLE_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXawSimple
     *
     *      Author: $author$
     *        Date: 6/25/2013
     **********************************************************************
     */
    virtual ~cXawSimple()
    {
    }
#else /* !defined(CXAWSIMPLE_MEMBERS_ONLY) */
#endif /* !defined(CXAWSIMPLE_MEMBERS_ONLY) */

#if !defined(CXAWSIMPLE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXAWSIMPLE_MEMBERS_ONLY) */
#endif /* !defined(CXAWSIMPLE_MEMBERS_ONLY) */

#endif /* !defined(_CXAWSIMPLE_HXX) || defined(CXAWSIMPLE_MEMBERS_ONLY) */
        


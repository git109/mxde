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
 *   File: cxtcore.hxx
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
#if !defined(_CXTCORE_HXX) || defined(CXTCORE_MEMBERS_ONLY)
#if !defined(_CXTCORE_HXX) && !defined(CXTCORE_MEMBERS_ONLY)
#define _CXTCORE_HXX
#endif /* !defined(_CXTCORE_HXX) && !defined(CXTCORE_MEMBERS_ONLY) */

#if !defined(CXTCORE_MEMBERS_ONLY)
#include "cxtcoreinterface.hxx"
#include "cxtwindowobj.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCoreExtend
 *
 *  Author: $author$           
 *    Date: 6/22/2010
 **********************************************************************
 */
typedef cXtWindowObj
cXtCoreExtend;
/**
 **********************************************************************
 *  Class: cXtCore
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtCore
: virtual public cXtCoreImplement,
  public cXtCoreExtend
{
public:
    typedef cXtCoreImplement cImplements;
    typedef cXtCoreExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cXtCore
     *
     *       Author: $author$           
     *         Date: 6/22/2010
     **********************************************************************
     */
    cXtCore
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtCore
     *
     *       Author: $author$           
     *         Date: 6/22/2010
     **********************************************************************
     */
    cXtCore
    (cXDisplayInterface& display,
     const XtChar* name,
     WidgetClass widgetClassAttached,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtCore
     *
     *      Author: $author$           
     *        Date: 6/22/2010
     **********************************************************************
     */
    virtual ~cXtCore()
    {
    }
#else /* !defined(CXTCORE_MEMBERS_ONLY) */
#endif /* !defined(CXTCORE_MEMBERS_ONLY) */

#if !defined(CXTCORE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCORE_MEMBERS_ONLY) */
#endif /* !defined(CXTCORE_MEMBERS_ONLY) */

#endif /* !defined(_CXTCORE_HXX) || defined(CXTCORE_MEMBERS_ONLY) */

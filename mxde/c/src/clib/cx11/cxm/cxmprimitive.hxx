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
 *   File: cxmprimitive.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMPRIMITIVE_HXX) || defined(CXMPRIMITIVE_MEMBERS_ONLY)
#if !defined(_CXMPRIMITIVE_HXX) && !defined(CXMPRIMITIVE_MEMBERS_ONLY)
#define _CXMPRIMITIVE_HXX
#endif /* !defined(_CXMPRIMITIVE_HXX) && !defined(CXMPRIMITIVE_MEMBERS_ONLY) */

#if !defined(CXMPRIMITIVE_MEMBERS_ONLY)
#include "cxmprimitiveinterface.hxx"
#include "cxtwindowobj.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmPrimitiveExtend
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXtWindowObj
cXmPrimitiveExtend;
/**
 **********************************************************************
 *  Class: cXmPrimitive
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmPrimitive
: virtual public cXmPrimitiveImplement,
  public cXmPrimitiveExtend
{
public:
    typedef cXmPrimitiveImplement cImplements;
    typedef cXmPrimitiveExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmPrimitive
     *
     *       Author: $author$           
     *         Date: 6/27/2010
     **********************************************************************
     */
    cXmPrimitive
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
     *  Destructor: ~cXmPrimitive
     *
     *      Author: $author$           
     *        Date: 6/27/2010
     **********************************************************************
     */
    virtual ~cXmPrimitive()
    {
    }
#else /* !defined(CXMPRIMITIVE_MEMBERS_ONLY) */
#endif /* !defined(CXMPRIMITIVE_MEMBERS_ONLY) */

#if !defined(CXMPRIMITIVE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMPRIMITIVE_MEMBERS_ONLY) */
#endif /* !defined(CXMPRIMITIVE_MEMBERS_ONLY) */

#endif /* !defined(_CXMPRIMITIVE_HXX) || defined(CXMPRIMITIVE_MEMBERS_ONLY) */

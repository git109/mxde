/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$     
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
 *   File: cxobject.hxx
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
#if !defined(_CXOBJECT_HXX) || defined(CXOBJECT_MEMBERS_ONLY)
#if !defined(_CXOBJECT_HXX) && !defined(CXOBJECT_MEMBERS_ONLY)
#define _CXOBJECT_HXX
#endif /* !defined(_CXOBJECT_HXX) && !defined(CXOBJECT_MEMBERS_ONLY) */

#if !defined(CXOBJECT_MEMBERS_ONLY)
#include "cxobjectinterface.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXObject
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
class cXObject
: virtual public cXObjectImplement,
  public cXBase
{
public:
    typedef cXObjectImplement cImplements;
    typedef cXBase cExtends;

    cXDisplayInterface& m_display;

    /**
     **********************************************************************
     *  Constructor: cXObject
     *
     *       Author: $author$           
     *         Date: 7/2/2009
     **********************************************************************
     */
    cXObject
    (cXDisplayInterface& display)
    : m_display(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXObject
     *
     *      Author: $author$           
     *        Date: 7/2/2009
     **********************************************************************
     */
    virtual ~cXObject()
    {
    }
#else /* !defined(CXOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CXOBJECT_MEMBERS_ONLY) */

#if !defined(CXOBJECT_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: DisplayInterface
     *
     *    Author: $author$           
     *      Date: 4/26/2010
     **********************************************************************
     */
    virtual cXDisplayInterface& DisplayInterface() const
#if defined(CXOBJECT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXOBJECT_MEMBER_FUNCS_INTERFACE) */
    {
        return (cXDisplayInterface&)(m_display);
    }
#endif /* defined(CXOBJECT_MEMBER_FUNCS_INTERFACE) */
#endif /* !defined(CXOBJECT_MEMBER_FUNCS_IMPLEMENT) */
    /**
     **********************************************************************
     *  Function: DisplayAttached
     *
     *    Author: $author$           
     *      Date: 4/26/2010
     **********************************************************************
     */
    virtual Display* DisplayAttached() const
#if defined(CXOBJECT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXOBJECT_MEMBER_FUNCS_INTERFACE) */
    {
        cXDisplayInterface& display = DisplayInterface();
        Display* xDisplay = display.Attached();
#if !defined(CXOBJECT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return xDisplay;
    }
#endif /* defined(CXOBJECT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXOBJECT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CXOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CXOBJECT_HXX) || defined(CXOBJECT_MEMBERS_ONLY) */

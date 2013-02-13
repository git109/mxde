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
 *   File: cxtwindowobj.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTWINDOWOBJ_HXX) || defined(CXTWINDOWOBJ_MEMBERS_ONLY)
#if !defined(_CXTWINDOWOBJ_HXX) && !defined(CXTWINDOWOBJ_MEMBERS_ONLY)
#define _CXTWINDOWOBJ_HXX
#endif /* !defined(_CXTWINDOWOBJ_HXX) && !defined(CXTWINDOWOBJ_MEMBERS_ONLY) */

#if !defined(CXTWINDOWOBJ_MEMBERS_ONLY)
#include "cxtwindowobjinterface.hxx"
#include "cxtrectobj.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWindowObjExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtRectObj
cXtWindowObjExtend;
/**
 **********************************************************************
 *  Class: cXtWindowObj
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWindowObj
: virtual public cXtWindowObjImplement,
  public cXtWindowObjExtend
{
public:
    typedef cXtWindowObjImplement cImplements;
    typedef cXtWindowObjExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtWindowObj
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtWindowObj
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtWindowObj
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtWindowObj
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
     *  Destructor: ~cXtWindowObj
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtWindowObj()
    {
    }
#else /* !defined(CXTWINDOWOBJ_MEMBERS_ONLY) */
#endif /* !defined(CXTWINDOWOBJ_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Realize
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError Realize()
#if defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
        {
            SetIsCreated(false);
            XtRealizeWidget(attached);
        }
        else
        error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: UnRealize
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError UnRealize()
#if defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
            XtUnrealizeWidget(attached);
        else
        error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: WindowAttached
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual Window WindowAttached() const
#if defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE) */
    {
        Window xWindow = None;
#if !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT)
        Widget attached;
        if (None != (attached = Attached()))
            xWindow = XtWindow(attached);
#else /* !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return xWindow;
    }
#endif /* defined(CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTWINDOWOBJ_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWINDOWOBJ_MEMBERS_ONLY) */
#endif /* !defined(CXTWINDOWOBJ_MEMBERS_ONLY) */

#endif /* !defined(_CXTWINDOWOBJ_HXX) || defined(CXTWINDOWOBJ_MEMBERS_ONLY) */

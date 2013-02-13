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
 *   File: cxmtext.hxx
 *
 * Author: $author$           
 *   Date: 7/2/2010
 **********************************************************************
 */
#if !defined(_CXMTEXT_HXX) || defined(CXMTEXT_MEMBERS_ONLY)
#if !defined(_CXMTEXT_HXX) && !defined(CXMTEXT_MEMBERS_ONLY)
#define _CXMTEXT_HXX
#endif /* !defined(_CXMTEXT_HXX) && !defined(CXMTEXT_MEMBERS_ONLY) */

#if !defined(CXMTEXT_MEMBERS_ONLY)
#include "cxmtextinterface.hxx"
#include "cxmprimitive.hxx"

#define CXMTEXT_WIDGET_NAME "cXmText"
#define CXMTEXT_WIDGET_CLASS xmTextWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmTextExtend
 *
 *  Author: $author$           
 *    Date: 7/2/2010
 **********************************************************************
 */
typedef cXmPrimitive
cXmTextExtend;
/**
 **********************************************************************
 *  Class: cXmText
 *
 * Author: $author$           
 *   Date: 7/2/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmText
: virtual public cXmTextImplement,
  public cXmTextExtend
{
public:
    typedef cXmTextImplement cImplements;
    typedef cXmTextExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmText
     *
     *       Author: $author$           
     *         Date: 7/2/2010
     **********************************************************************
     */
    cXmText
    (cXDisplayInterface& display,
     const XtChar* name = CXMTEXT_WIDGET_NAME,
     WidgetClass widgetClassAttached = CXMTEXT_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmText
     *
     *      Author: $author$           
     *        Date: 7/2/2010
     **********************************************************************
     */
    virtual ~cXmText()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CXMTEXT_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$           
     *      Date: 7/2/2010
     **********************************************************************
     */
    virtual Widget CreateDetached
    (eError& error, 
     const String name, Widget parentWidget, 
     ArgList argList = 0, Cardinal argCount = 0,
     bool isManaged = false) const
#if defined(CXMTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMTEXT_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXMTEXT_MEMBER_FUNCS_IMPLEMENT)

        error = e_ERROR_FAILED;

        if (None != (detached = XmCreateText
            (parentWidget, name, argList, argCount)))
        {
            if (isManaged)
                XtManageChild(detached);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXMTEXT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMTEXT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXMTEXT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMTEXT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTEXT_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXT_MEMBERS_ONLY) */

#endif /* !defined(_CXMTEXT_HXX) || defined(CXMTEXT_MEMBERS_ONLY) */

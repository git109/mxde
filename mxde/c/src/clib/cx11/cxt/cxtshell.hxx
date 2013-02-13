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
 *   File: cxtshell.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTSHELL_HXX) || defined(CXTSHELL_MEMBERS_ONLY)
#if !defined(_CXTSHELL_HXX) && !defined(CXTSHELL_MEMBERS_ONLY)
#define _CXTSHELL_HXX
#endif /* !defined(_CXTSHELL_HXX) && !defined(CXTSHELL_MEMBERS_ONLY) */

#if !defined(CXTSHELL_MEMBERS_ONLY)
#include "cxtshellinterface.hxx"
#include "cxtcomposite.hxx"

#define CXTSHELL_NAME "cXtShell"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtShellExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtComposite
cXtShellExtend;
/**
 **********************************************************************
 *  Class: cXtShell
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtShell
: virtual public cXtShellImplement,
  public cXtShellExtend
{
public:
    typedef cXtShellImplement cImplements;
    typedef cXtShellExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cXtShell
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtShell
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtShell
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtShell()
    {
    }
#else /* !defined(CXTSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTSHELL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreatePopupShell
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual eError CreatePopupShell
    (const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTSHELL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreatePopupShellAttached
        (error, name, parentWidget, widgetClass, 
         argList, argCount, onlyDestroyed);
#else /* !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreatePopupShellAttached
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual Widget CreatePopupShellAttached
    (eError& error, const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTSHELL_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT)

        if ((error = Destroyed(onlyDestroyed)))
            return None;

        if (None != (detached = CreatePopupShellDetached
            (error, name, parentWidget, widgetClass, argList, argCount)))
        {
            if (detached == (AttachCreated(detached)))
                return detached;

            DestroyDetached(detached);
        }
#else /* !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreatePopupShellDetached
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual Widget CreatePopupShellDetached
    (eError& error, const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool isManaged = false)
#if defined(CXTSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTSHELL_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_FAILED;

        if (None != (detached = XtCreatePopupShell
            (name, widgetClass, parentWidget, argList, argCount)))
        {
            if (isManaged)
                XtManageChild(detached);
            error = e_ERROR_NONE;
        }
        else
        DBE(("() failed on XtCreatePopupShell()\n"));
#else /* !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTSHELL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTSHELL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTSHELL_HXX) || defined(CXTSHELL_MEMBERS_ONLY) */

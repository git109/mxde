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
 *   File: cxtapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
#if !defined(_CXTAPPLICATIONSHELL_HXX) || defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXTAPPLICATIONSHELL_HXX) && !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXTAPPLICATIONSHELL_HXX
#endif /* !defined(_CXTAPPLICATIONSHELL_HXX) && !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cxtapplicationshellinterface.hxx"
#include "cxtwmshell.hxx"

#define CXTAPPLICATIONSHELL_NAME "cXtApplicationShell"
#define CXTAPPLICATIONSHELL_CLASS_NAME CXTAPPLICATIONSHELL_NAME
#define CXTAPPLICATIONSHELL_WIDGET_CLASS applicationShellWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cXtWMShell
cXtApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXtApplicationShell
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtApplicationShell
: virtual public cXtApplicationShellImplement,
  public cXtApplicationShellExtend
{
public:
    typedef cXtApplicationShellImplement cImplements;
    typedef cXtApplicationShellExtend cExtends;

    cXtString m_className;
    String m_classNameString;
    const XtChar* m_classNameChars;

    /**
     **********************************************************************
     *  Constructor: cXtApplicationShell
     *
     *       Author: $author$           
     *         Date: 5/1/2010
     **********************************************************************
     */
    cXtApplicationShell
    (cXDisplayInterface& display,
     const XtChar* name = CXTAPPLICATIONSHELL_NAME,
     const XtChar* className = CXTAPPLICATIONSHELL_CLASS_NAME,
     WidgetClass widgetClassAttached = CXTAPPLICATIONSHELL_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false)
    : cExtends(display, name, attached, isCreated)
    {
        eError error;
        TLENGTH count;

        if (className)
        if (0 > (count = SetClassName(className)))
            DBE_THROW_ERROR(error, -count);

        if (widgetClassAttached)
            m_widgetClass.Attach(widgetClassAttached);
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtApplicationShell
     *
     *      Author: $author$           
     *        Date: 5/1/2010
     **********************************************************************
     */
    virtual ~cXtApplicationShell()
    {
    }
#else /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateShell
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual eError CreateShell
    (const String name, const String className,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateShellAttached
        (error, name, className, widgetClass, 
         argList, argCount, onlyDestroyed);
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateShellAttached
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual Widget CreateShellAttached
    (eError& error, const String name, const String className,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)

        if ((error = Destroyed(onlyDestroyed)))
            return None;

        if (None != (detached = CreateShellDetached
            (error, name, className, widgetClass, argList, argCount)))
        {
            DBT(("() detached = %p\n", detached));
            if (detached == (AttachCreated(detached)))
            {
                DBT(("() attached = %p\n", Attached()));
                return detached;
            }
            DestroyDetached(detached);
        }
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateShellDetached
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual Widget CreateShellDetached
    (eError& error, const String name, const String className,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount) const
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;

        error = e_ERROR_FAILED;

        if (!(xDisplay = DisplayAttached()))
            error = e_ERROR_NOT_ATTACHED;
        else
        if (None != (detached = XtAppCreateShell
            (name, className, widgetClass, xDisplay, argList, argCount)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XtAppCreateShell()\n"));
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetClassName
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual TLENGTH SetClassName
    (const XtChar* name,
     TLENGTH length=UNDEFINED_LENGTH)
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)
        if (name)
        if (!(name != m_classNameChars))
            count = m_className.length();
        else
        if (0 < (count = m_className.assign(name, length)))
        {
            m_classNameString = m_className.str();
            m_classNameChars = m_className.c_str();
        }
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ClassName
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual const XtChar* ClassName() const
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
        const XtChar* name = 0;
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)
        name = (m_classNameChars);
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ClassNameString
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual const String ClassNameString() const
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)
        const String name = (m_classNameString);
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        const String name = 0;
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ClassNameToAttach
     *
     *    Author: $author$           
     *      Date: 6/24/2010
     **********************************************************************
     */
    virtual const String ClassNameToAttach() const
#if defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT)
        const String name = CXTAPPLICATIONSHELL_NAME;
#else /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        const String name = 0;
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXTAPPLICATIONSHELL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTAPPLICATIONSHELL_HXX) || defined(CXTAPPLICATIONSHELL_MEMBERS_ONLY) */

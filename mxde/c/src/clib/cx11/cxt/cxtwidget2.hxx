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
 *   File: cxtwidget.hxx
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGET_HXX) || defined(CXTWIDGET_MEMBERS_ONLY)
#if !defined(_CXTWIDGET_HXX) && !defined(CXTWIDGET_MEMBERS_ONLY)
#define _CXTWIDGET_HXX
#endif /* !defined(_CXTWIDGET_HXX) && !defined(CXTWIDGET_MEMBERS_ONLY) */

#if !defined(CXTWIDGET_MEMBERS_ONLY)
#include "cxtwidgetinterface.hxx"
#include "cxtwidgetcreated.hxx"
#include "cxtwidgetattached.hxx"
#include "cxtwidgetclass.hxx"
#include "cxtstring.hxx"
#include "cxdisplay.hxx"

#define CXTWIDGET_NAME "cXtWidget"
#define CXTWIDGET_CLASS_NAME CXTWIDGET_NAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWidgetExtend
 *
 *  Author: $author$           
 *    Date: 6/22/2010
 **********************************************************************
 */
typedef cXtWidgetCreated
cXtWidgetExtend;
/**
 **********************************************************************
 *  Class: cXtWidget
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWidget
: virtual public cXtWidgetImplement,
  public cXtWidgetExtend
{
public:
    typedef cXtWidgetImplement cImplements;
    typedef cXtWidgetExtend cExtends;

    cXDisplayInterface& m_display;
    cXtString m_name;
    String m_nameString;
    const XtChar* m_nameChars;
    cXtWidgetClass m_widgetClass;
    cXtArgList m_argList;

    /**
     **********************************************************************
     *  Constructor: cXtWidget
     *
     *       Author: $author$           
     *         Date: 6/22/2010
     **********************************************************************
     */
    cXtWidget
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(attached, isCreated),
      m_display(display),
      m_nameString(0),
      m_nameChars(0)
    {
        eError error;
        TLENGTH count;
        if (name)
        if (0 > (count = SetName(name)))
            DBE_THROW_ERROR(error, -count);
    }
    /**
     **********************************************************************
     *  Constructor: cXtWidget
     *
     *       Author: $author$           
     *         Date: 6/22/2010
     **********************************************************************
     */
    cXtWidget
    (cXDisplayInterface& display,
     const XtChar* name,
     WidgetClass widgetClassAttached,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(attached, isCreated),
      m_display(display),
      m_nameString(0),
      m_nameChars(0)
    {
        eError error;
        TLENGTH count;

        if (name)
        if (0 > (count = SetName(name)))
            DBE_THROW_ERROR(error, -count);

        if (widgetClassAttached)
            m_widgetClass.Attach(widgetClassAttached);
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtWidget
     *
     *      Author: $author$           
     *        Date: 6/22/2010
     **********************************************************************
     */
    virtual ~cXtWidget()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CXTWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGET_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$           
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual eError Create
    (const String name, Widget parentWidget,
     ArgList argList, Cardinal argCount,
     bool isManaged = false, bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        CreateAttached
        (error, name, parentWidget,
         argList, argCount, isManaged, onlyDestroyed);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError Create
    (const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool isManaged = false, bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        CreateAttached
        (error, name, parentWidget, widgetClass, 
         argList, argCount, isManaged, onlyDestroyed);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual Widget CreateAttached
    (eError& error, const String name, Widget parentWidget,
     ArgList argList, Cardinal argCount,
     bool isManaged = false, bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        WidgetClass widgetClass;

        error = e_ERROR_FAILED;

        if ((widgetClass = WidgetClassToAttach()))
            detached = CreateAttached
            (error, name, parentWidget, widgetClass, 
             argList, argCount, isManaged, onlyDestroyed);

#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual Widget CreateAttached
    (eError& error, const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool isManaged = false, bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)

        if ((error = Destroyed(onlyDestroyed)))
            return None;

        if (None != (detached = CreateDetached
            (error, name, parentWidget, widgetClass, 
             argList, argCount, isManaged)))
        {
            if (detached == (AttachCreated(detached)))
                return detached;

            DestroyDetached(detached);
        }
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$           
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual Widget CreateDetached
    (eError& error, Widget parentWidget,
     ArgList argList, Cardinal argCount, bool isManaged = false) const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        const String name = NameToAttach();

        error = e_ERROR_FAILED;

        if ((name))
            detached = CreateDetached
            (error, name, parentWidget, 
             argList, argCount, isManaged);

#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$           
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual Widget CreateDetached
    (eError& error, const String name, Widget parentWidget,
     ArgList argList, Cardinal argCount, bool isManaged = false) const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        WidgetClass widgetClass;

        error = e_ERROR_FAILED;

        if ((widgetClass = WidgetClassToAttach()))
            detached = CreateDetached
            (error, name, parentWidget, widgetClass, 
             argList, argCount, isManaged);

#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual Widget CreateDetached
    (eError& error, const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool isManaged = false) const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_FAILED;

        if (!(widgetClass))
        if (!(widgetClass = WidgetClassToAttach()))
            return detached;

        if (None != (detached = XtCreateWidget
            (name, widgetClass, parentWidget, argList, argCount)))
        {
            if (isManaged)
                XtManageChild(detached);
            error = e_ERROR_NONE;
        }
        else
        DBE(("() failed on XtCreateWidget()\n"));
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        Widget detached;

        if (IsCreated())
            SetIsCreated(false);
        else
        if (onlyCreated)
            return e_ERROR_NOT_CREATED;

        if (None != (detached = Detach()))
            error = DestroyDetached(detached);
        else
        if (onlyCreated)
            return e_ERROR_NOT_ATTACHED;

#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyDetached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (Widget detached) const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        if (None != detached)
            XtDestroyWidget(detached);
        else
        error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetValues
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList SetValues
    (const XtChar* argName, XtArgVal argValue)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = SetValuesL(argName, argValue, 0);
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetValuesL
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList SetValuesL
    (const XtChar* argName, XtArgVal argValue, ...)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, argValue);
        argList = SetValuesV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetValuesV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList SetValuesV
    (const XtChar* argName, XtArgVal argValue, va_list va)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        Widget xWidget;
        if (None != (xWidget = Attached()))
        if ((argList = m_argList.SetV(argName, argValue, va)))
            XtSetValues(xWidget, argList, m_argList.Length());
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetValues
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList SetValues
    (ArgList argList, TLENGTH length)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        Widget xWidget;

        if ((!argList) || (0 >= length))
            argList = 0;
        else
        if (None != (xWidget = Attached()))
            XtSetValues(xWidget, argList, length);
        else
        argList = 0;

#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        argList = 0;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetValues
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH GetValues
    (const XtChar* argName, XtArgVal* argValue)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = GetValuesL(argName, argValue, 0);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetValuesL
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH GetValuesL
    (const XtChar* argName, XtArgVal* argValue, ...)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        va_list va;
        va_start(va, argValue);
        count = GetValuesV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetValuesV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH GetValuesV
    (const XtChar* argName, XtArgVal* argValue, va_list va)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        Widget xWidget;
        ArgList argList;
        if (None != (xWidget = Attached()))
        if ((argList = m_argList.SetGetV(argName, argValue, va)))
        {
            XtGetValues(xWidget, argList, m_argList.Length());
            count = m_argList.GetSetV(argName, argValue, va);
        }
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetValues
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual TLENGTH GetValues
    (ArgList argList, TLENGTH length)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        Widget xWidget;

        if (!argList)
            length = -e_ERROR_NULL_PARAMETER;
        else
        if (0 >= length)
            length = -e_ERROR_INVALID_PARAMETER;
        else
        if (None != (xWidget = Attached()))
            XtGetValues(xWidget, argList, length);
        else
        length = -e_ERROR_NOT_ATTACHED;

#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetArgValues
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList SetArgValues
    (const XtChar* argName, XtArgVal argValue)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = SetArgValuesL(argName, argValue, 0);
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetArgValuesL
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList SetArgValuesL
    (const XtChar* argName, XtArgVal argValue, ...)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, argValue);
        argList = SetArgValuesV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetArgValuesV
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList SetArgValuesV
    (const XtChar* argName, XtArgVal argValue, va_list va)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        argList = m_argList.SetV(argName, argValue, va);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AppendArgValues
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList AppendArgValues
    (const XtChar* argName, XtArgVal argValue)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = AppendArgValuesL(argName, argValue, 0);
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppendArgValuesL
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList AppendArgValuesL
    (const XtChar* argName, XtArgVal argValue, ...)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, argValue);
        argList = AppendArgValuesV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppendArgValuesV
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList AppendArgValuesV
    (const XtChar* argName, XtArgVal argValue, va_list va)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        argList = m_argList.AppendV(argName, argValue, va);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ClearArgValues
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual TLENGTH ClearArgValues()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = m_argList.Clear();
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ArgValues
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList ArgValues(TLENGTH& length) const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        argList = m_argList.List(length);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetName
     *
     *    Author: $author$           
     *      Date: 6/22/2010
     **********************************************************************
     */
    virtual TLENGTH SetName
    (const XtChar* name, 
     TLENGTH length = UNDEFINED_LENGTH)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        if (name)
        if (!(name != m_nameChars))
            count = m_name.length();
        else
        if (0 < (count = m_name.assign(name, length)))
        {
            m_nameString = m_name.str();
            m_nameChars = m_name.c_str();
        }
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Name
     *
     *    Author: $author$           
     *      Date: 6/22/2010
     **********************************************************************
     */
    virtual String Name() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        String name = (String)(m_nameString);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        String name = 0;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: NameChars
     *
     *    Author: $author$           
     *      Date: 6/22/2010
     **********************************************************************
     */
    virtual const XtChar* NameChars() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        const XtChar* name = (m_nameChars);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        const XtChar* name = 0;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: NameToAttach
     *
     *    Author: $author$           
     *      Date: 6/23/2010
     **********************************************************************
     */
    virtual const String NameToAttach() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        const String name = CXTWIDGET_NAME;
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        const String name = 0;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: WidgetClassToAttach
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual WidgetClass WidgetClassToAttach() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        WidgetClass widgetClass = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        widgetClass = (m_widgetClass.Attached());
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return widgetClass;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTWIDGET_MEMBERS_ONLY)
#include "cxobjectimplement_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGET_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGET_HXX) || defined(CXTWIDGET_MEMBERS_ONLY) */

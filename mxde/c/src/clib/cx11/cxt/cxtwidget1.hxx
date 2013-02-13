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
 *   Date: 4/26/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGET_HXX) || defined(CXTWIDGET_MEMBERS_ONLY)
#if !defined(_CXTWIDGET_HXX) && !defined(CXTWIDGET_MEMBERS_ONLY)
#define _CXTWIDGET_HXX
#endif /* !defined(_CXTWIDGET_HXX) && !defined(CXTWIDGET_MEMBERS_ONLY) */

#if !defined(CXTWIDGET_MEMBERS_ONLY)
#include "cplatform_X11_StringDefs.h"
#include "cxobjectinterface.hxx"
#include "cxgetgcinterface.hxx"
#include "cxteventhandlerinterface.hxx"
#include "cxtwidgetclassattached.hxx"
#include "cxtwidgetinterface.hxx"
#include "cxtwidgetattached.hxx"
#include "cxtarglist.hxx"

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
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cXtWidgetCreated
cXtWidgetExtend;
/**
 **********************************************************************
 *  Class: cXtWidget
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWidget
: virtual public cXtWidgetImplement,
  virtual public cXtEventHandlerImplement,
  virtual public cXGetGCImplement,
  virtual public cXObjectImplement,
  public cXtWidgetExtend
{
public:
    typedef cXtEventHandlerImplement cEventImplements;
    typedef cXtWidgetImplement cImplements;
    typedef cXtWidgetExtend cExtends;

    cXDisplayInterface& m_display;
    const XtChar* m_nameChars;
    const XtChar* m_classNameChars;
    cXtWidgetClassAttached m_widgetClass;
    cXtArgList m_argList;

    /**
     **********************************************************************
     *  Constructor: cXtWidget
     *
     *       Author: $author$           
     *         Date: 4/26/2010
     **********************************************************************
     */
    cXtWidget
    (cXDisplayInterface& display,
     const XtChar* name = CXTWIDGET_NAME,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false)
    : cExtends(attached, isCreated),
      m_display(display),
      m_nameChars(name),
      m_classNameChars(name),
      m_widgetClass(widgetClassAttached)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtWidget
     *
     *       Author: $author$           
     *         Date: 4/26/2010
     **********************************************************************
     */
    cXtWidget
    (cXDisplayInterface& display,
     const XtChar* name,
     const XtChar* className,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false)
    : cExtends(attached, isCreated),
      m_display(display),
      m_nameChars(name),
      m_classNameChars(className),
      m_widgetClass(widgetClassAttached)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtWidget
     *
     *       Author: $author$           
     *         Date: 5/18/2010
     **********************************************************************
     */
    cXtWidget
    (cXDisplayInterface& display,
     Widget attached,
     bool isCreated = false,
     WidgetClass widgetClassAttached = 0,
     const XtChar* name = CXTWIDGET_NAME,
     const XtChar* className = CXTWIDGET_CLASS_NAME)
    : cExtends(attached, isCreated),
      m_display(display),
      m_nameChars(name),
      m_classNameChars(className),
      m_widgetClass(widgetClassAttached)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtWidget
     *
     *      Author: $author$           
     *        Date: 4/26/2010
     **********************************************************************
     */
    virtual ~cXtWidget()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("() throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXTWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGET_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateShell
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError CreateShell
    (const String name, const String className,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        CreateShellAttached
        (error, name, className, widgetClass, 
         argList, argCount, onlyDestroyed);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateShellAttached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual Widget CreateShellAttached
    (eError& error, const String name, const String className,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)

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
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateShellDetached
     *
     *    Author: $author$           
     *      Date: 4/26/2010
     **********************************************************************
     */
    virtual Widget CreateShellDetached
    (eError& error, const String name, const String className,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount) const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
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
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreatePopupShell
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError CreatePopupShell
    (const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        CreatePopupShellAttached
        (error, name, parentWidget, widgetClass, 
         argList, argCount, onlyDestroyed);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreatePopupShellAttached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual Widget CreatePopupShellAttached
    (eError& error, const String name, Widget parentWidget,
     WidgetClass widgetClass, ArgList argList, Cardinal argCount,
     bool onlyDestroyed = false)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Widget detached = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)

        if ((error = Destroyed(onlyDestroyed)))
            return None;

        if (None != (detached = CreatePopupShellDetached
            (error, name, parentWidget, widgetClass, argList, argCount)))
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
     *  Function: CreatePopupShellDetached
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual Widget CreatePopupShellDetached
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

        if (None != (detached = XtCreatePopupShell
            (name, widgetClass, parentWidget, argList, argCount)))
        {
            if (isManaged)
                XtManageChild(detached);
            error = e_ERROR_NONE;
        }
        else
        DBE(("() failed on XtCreatePopupShell()\n"));
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

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
     *  Function: SetRectangle
     *
     *    Author: $author$           
     *      Date: 6/19/2010
     **********************************************************************
     */
    virtual eError SetRectangle
    (XRectangle& rect)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        ArgList values = 0;
        XtArgVal argValX = rect.x;
        XtArgVal argValY = rect.y;
        XtArgVal argValWidth = rect.width;
        XtArgVal argValHeight = rect.height;

        DBF(("()...\n"));

        if (!(values = SetValuesL
            (XtNx, argValX, XtNy, argValY, 
             XtNwidth, argValWidth, XtNheight, argValHeight, 0)))
             error = error = e_ERROR_FAILED;
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetRectangle
     *
     *    Author: $author$           
     *      Date: 6/19/2010
     **********************************************************************
     */
    virtual eError GetRectangle
    (XRectangle& rect)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        TLENGTH values = 0;
        XtArgVal argValX = 0;
        XtArgVal argValY = 0;
        XtArgVal argValWidth = 0;
        XtArgVal argValHeight = 0;

        DBF(("()...\n"));

        if (0 > (values = GetValuesL
            (XtNx, &argValX, XtNy, &argValY, 
             XtNwidth, &argValWidth, XtNheight, &argValHeight, 0)))
             error = -values;
        else
        {
            rect.x = (TOFFSET)(argValX);
            rect.y = (TOFFSET)(argValY);
            rect.width = (TSIZE)(argValWidth);
            rect.height = (TSIZE)(argValHeight);
        }
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetX
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetX()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNx, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetY
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetY()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNy, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetWidth
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetWidth()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNwidth, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetHeight
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetHeight()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNheight, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return value;
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
     *  Function: AddCallback
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError AddCallback
    (const String name, 
     XtCallbackProc callbackProc, XtPointer callbackData)
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
            XtAddCallback
            (attached, name, callbackProc, callbackData);
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
     *  Function: ManageChild
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError ManageChild()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
        {
            SetIsCreated(false);
            XtManageChild(attached);
        }
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
     *  Function: UnManageChild
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError UnManageChild()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
            XtUnmanageChild(attached);
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
     *  Function: Realize
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError Realize()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
        {
            SetIsCreated(false);
            XtRealizeWidget(attached);
        }
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
     *  Function: UnRealize
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError UnRealize()
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Widget attached;
        if (None != (attached = Attached()))
            XtUnrealizeWidget(attached);
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
     *  Function: IsManaged
     *
     *    Author: $author$           
     *      Date: 6/20/2010
     **********************************************************************
     */
    virtual bool IsManaged() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        bool isTrue = false;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        Widget attached;
        if (None != (attached = Attached()))
            isTrue = (False != XtIsManaged(attached));
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: IsRealized
     *
     *    Author: $author$           
     *      Date: 6/20/2010
     **********************************************************************
     */
    virtual bool IsRealized() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        bool isTrue = false;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        Widget attached;
        if (None != (attached = Attached()))
            isTrue = (False != XtIsRealized(attached));
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: WindowAttached
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual Window WindowAttached() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        Window xWindow = None;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        Widget attached;
        if (None != (attached = Attached()))
            xWindow = XtWindow(attached);
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return xWindow;
    }
#endif /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Name
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual const XtChar* Name() const
#if defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        const XtChar* xChars = 0;
#if !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        xChars = m_nameChars;
#else /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return xChars;
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

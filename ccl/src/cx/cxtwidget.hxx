/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cxtwidget.hxx
 *
 * Author: $author$
 *   Date: 4/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXTWIDGET_HXX
#define _CXTWIDGET_HXX

#include <stdio.h>
#include <stdarg.h>
#include <X11/Intrinsic.h>

#include "clistt.hxx"
#include "chandlet.hxx"
#include "cbuffert.hxx"
#include "cxobject.hxx"

/**
 **********************************************************************
 *  Class: cXtArg
 *
 * Author: $author$
 *   Date: 4/25/2004
 **********************************************************************
 */
class cXtArg
: public Arg
{
public:
    typedef Arg cIs;

    /**
     **********************************************************************
     * Constructor: cXtArg
     *
     *      Author: $author$
     *        Date: 4/25/2004
     **********************************************************************
     */
    cXtArg() 
    {
        Set(0, 0);
    }
    /**
     **********************************************************************
     * Constructor: cXtArg
     *
     *      Author: $author$
     *        Date: 4/25/2004
     **********************************************************************
     */
    cXtArg(String xt_name, XtArgVal xt_value) 
    {
        Set(xt_name, xt_value);
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 4/25/2004
     **********************************************************************
     */
    cXtArg &Set(String xt_name, XtArgVal xt_value)
    {
        XtSetArg((*this), xt_name, xt_value);
        return *this;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 4/25/2004
     **********************************************************************
     */
    String GetName() const
    {
        return name;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 4/25/2004
     **********************************************************************
     */
    XtArgVal GetValue() const
    {
        return value;
    }

    /**
     **********************************************************************
     * Operator: <
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    bool operator < (const cXtArg &arg) const
    {
        if ((GetName() < arg.GetName())
            ||(GetValue() < arg.GetValue()))
            return true;

        return false;
    }
    /**
     **********************************************************************
     * Operator: >
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    bool operator > (const cXtArg &arg) const
    {
        if ((GetName() > arg.GetName())
            ||(GetValue() > arg.GetValue()))
            return true;

        return false;
    }
    /**
     **********************************************************************
     * Operator: ==
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    bool operator == (const cXtArg &arg) const
    {
        if ((GetName() == arg.GetName())
            && (GetValue() == arg.GetValue()))
            return true;

        return false;
    }
    /**
     **********************************************************************
     * Operator: ==
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    bool operator == (int name_value) const
    {
        if (GetName() == (String)name_value)
        if (GetValue() == (XtArgVal)name_value)
            return true;

        return false;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    bool operator != (int name_value) const
    {
        if (GetName() == (String)name_value)
        if (GetValue() == (XtArgVal)name_value)
            return false;

        return true;
    }
    /**
     **********************************************************************
     * Operator: =
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    cXtArg &operator = (int name_value)
    {
        Set((String)name_value, (XtArgVal)name_value);
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cXtArgsT
 *
 * Author: $author$
 *   Date: 4/25/2004
 **********************************************************************
 */
template <int VDefaultSize>
class cXtArgsT
: public cBufferT<VDefaultSize, cXtArg, 0>
{
public:
    typedef cBufferT<VDefaultSize, cXtArg, 0> cIs;

    /**
     **********************************************************************
     * Constructor: cXtArgsT
     *
     *      Author: $author$
     *        Date: 4/25/2004
     **********************************************************************
     */
    cXtArgsT(const cXtArg *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer , size, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXtArgsT
     *
     *      Author: $author$
     *        Date: 4/25/2004
     **********************************************************************
     */
    cXtArgsT(String xt_name, XtArgVal xt_value, ...) 
    {
        va_list va;
        int args;
        eError error;

        va_start(va, xt_value);
        args = VCount(xt_name, xt_value, va);
        va_end(va);

        if (0 > (args = SetSize(args)))
            throw(error = -args);

        va_start(va, xt_value);
        args = VSet(xt_name, xt_value, va);
        va_end(va);

        if (0 > args)
            throw(error = -args);
    }
    /**
     **********************************************************************
     * Destructor: ~cXtArgsT
     *
     *     Author: $author$
     *       Date: 4/25/2004
     **********************************************************************
     */
    virtual ~cXtArgsT()
    {
    }

    /**
     **********************************************************************
     * Function: VSet
     *
     *   Author: $author$
     *     Date: 4/25/2004
     **********************************************************************
     */
    virtual int VSet
    (String xt_name, XtArgVal xt_value, va_list va)
    {
        int arg,args;
        eError error;
        cXtArg *xtarg;

        if (!(xtarg = GetWriteBuffer(args)))
            return -e_ERROR_FAILED;

        if (0 < args)
        {
            xtarg[0].Set(xt_name, xt_value);

            for (arg = 1, xt_name = va_arg(va, String); 
                 xt_name && (arg<args); xt_name = va_arg(va, String), arg++)
            {
                xt_value = va_arg(va, XtArgVal);

                xtarg[arg].Set(xt_name, xt_value);
            }
        }
        return args;
    }
    /**
     **********************************************************************
     * Function: VCount
     *
     *   Author: $author$
     *     Date: 4/25/2004
     **********************************************************************
     */
    virtual int VCount
    (String xt_name, XtArgVal xt_value, va_list va)
    {
        int args;

        for (args=1, xt_name=va_arg(va,String); 
             xt_name; xt_name=va_arg(va,String), args++)
            xt_value=va_arg(va,XtArgVal);

        return args;
    }
};

/**
 **********************************************************************
 *  Class: cXtArgs
 *
 * Author: $author$
 *   Date: 4/26/2004
 **********************************************************************
 */
class cXtArgs
: public cXtArgsT<8>
{
public:
    typedef cXtArgsT<8> cIs;

    static cXtArgs m_null;

    /**
     **********************************************************************
     * Constructor: cXtArgs
     *
     *      Author: $author$
     *        Date: 4/26/2004
     **********************************************************************
     */
    cXtArgs() 
    {
    }
};

class cXtWidget;

/**
 **********************************************************************
 *  Class: cXtWidgetSibling
 *
 * Author: $author$
 *   Date: 4/26/2004
 **********************************************************************
 */
class cXtWidgetSibling
: public cListItemT<cXtWidgetSibling>
{
public:
    typedef cListItemT<cXtWidgetSibling> cIs;

    cXtWidget &m_widget;

    /**
     **********************************************************************
     * Constructor: cXtWidgetSibling
     *
     *      Author: $author$
     *        Date: 4/26/2004
     **********************************************************************
     */
    cXtWidgetSibling(cXtWidget &widget) 
    : m_widget(widget) 
    {
    }

    /**
     **********************************************************************
     * Function: GetWidget
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual cXtWidget &GetWidget() const
    {
        return m_widget;
    }
};

/**
 **********************************************************************
 *  Class: cXtWidgetChildren
 *
 * Author: $author$
 *   Date: 4/26/2004
 **********************************************************************
 */
class cXtWidgetChildren
: public cListT<cXtWidgetSibling,cXtWidgetChildren>
{
public:
    typedef cListT<cXtWidgetSibling,cXtWidgetChildren> cIs;

    /**
     **********************************************************************
     * Constructor: cXtWidgetChildren
     *
     *      Author: $author$
     *        Date: 4/26/2004
     **********************************************************************
     */
    cXtWidgetChildren() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtWidget
 *
 * Author: $author$
 *   Date: 4/26/2004
 **********************************************************************
 */
class cXtWidget
: public cXObject
{
public:
    typedef cXObject cIs;

    Widget m_xt_widget;
    WidgetClass m_xt_widget_class;
    String m_xt_class_name;
    String m_xt_name;

    cXtWidgetChildren m_children;
    cXtWidgetSibling m_sibling;
    cXtWidget *m_parent;
    bool m_managed;
    int m_id;

    /**
     **********************************************************************
     * Constructor: cXtWidget
     *
     *      Author: $author$
     *        Date: 4/26/2004
     **********************************************************************
     */
    cXtWidget
    (String xt_name="cXtWidget",
     String xt_class_name="cXtWidget",
     WidgetClass xt_widget_class=0) 
    : m_xt_widget(0),
      m_xt_widget_class(xt_widget_class),
      m_xt_class_name(xt_class_name),
      m_xt_name(xt_name),
      m_sibling(*this),
      m_parent(0),
      m_managed(false),
      m_id(0) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXtWidget
     *
     *     Author: $author$
     *       Date: 4/26/2004
     **********************************************************************
     */
    virtual ~cXtWidget()
    {
    }

    /**
     **********************************************************************
     * Function: CreateShell
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError CreateShell
    (Display *x_display, String xt_name, String xt_class_name,
     WidgetClass xt_widget_class, const cXtArgs &args=cXtArgs::m_null)
    {
        eError error;
        Arg *xt_arg;
        int xt_args;

        if (xt_name && xt_class_name && xt_widget_class)

        if ((xt_arg = args.GetWriteBuffer(xt_args)))

        if (!(error = !(m_xt_widget = XtAppCreateShell
            (xt_name, xt_class_name, xt_widget_class,
             x_display, xt_arg, xt_args))))
             return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: CreateManaged
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError CreateManaged
    (cXtWidget &parent, const cXtArgs &args=cXtArgs::m_null)
    {
        return CreateManaged
        (GetXtName(), GetXtWidgetClass(), parent, args);
    }
    /**
     **********************************************************************
     * Function: CreateManaged
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError CreateManaged
    (String xt_name, WidgetClass xt_widget_class,
     cXtWidget &parent, const cXtArgs &args=cXtArgs::m_null)
    {
        eError error;
        Arg *xt_arg;
        int xt_args;

        if (xt_name && xt_widget_class)

        if ((xt_arg = args.GetWriteBuffer(xt_args)))

        if (!(error = !(m_xt_widget = XtCreateManagedWidget
            (xt_name, xt_widget_class,
             parent.GetXtWidget(), xt_arg, xt_args))))
        {
            m_parent = &parent;
            m_managed = true;
            return error;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual eError Create
    (String xt_name, WidgetClass xt_widget_class,
     cXtWidget &parent, const cXtArgs &args=cXtArgs::m_null)
    {
        eError error;
        Arg *xt_arg;
        int xt_args;

        if (xt_name && xt_widget_class)

        if ((xt_arg = args.GetWriteBuffer(xt_args)))

        if (!(error = !(m_xt_widget = XtCreateWidget
            (xt_name, xt_widget_class,
             parent.GetXtWidget(), xt_arg, xt_args))))
        {
            m_parent=&parent;
            return error;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        if (m_xt_widget)
        {
            XtDestroyWidget(m_xt_widget);
            m_xt_widget=0;
            return e_ERROR_NONE;
        }
        return e_ERROR_NOT_CREATED;
    }
    /**
     **********************************************************************
     * Function: AddCallback
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError AddCallback
    (String xt_name, XtCallbackProc xt_call, XtPointer xt_data)
    {
        if (m_xt_widget)
        {
            XtAddCallback(m_xt_widget,xt_name,xt_call,xt_data);
            return e_ERROR_NONE;
        }
        return e_ERROR_NOT_ATTACHED;
    }
    /**
     **********************************************************************
     * Function: Realize
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError Realize()
    {
        if (m_xt_widget)
        {
            XtRealizeWidget(m_xt_widget);
            return e_ERROR_NONE;
        }
        return e_ERROR_NOT_ATTACHED;
    }

    /**
     **********************************************************************
     * Function: OnActivateChild
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual void OnActivateChild
    (cXtWidget &child, cXtWidget &parent, XtPointer xt_data=0)
    {
    }

    /**
     **********************************************************************
     * Function: GetXtClassName
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual String GetXtClassName() const
    {
        return m_xt_class_name;
    }
    /**
     **********************************************************************
     * Function: GetXtName
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual String GetXtName() const
    {
        return m_xt_name;
    }
    /**
     **********************************************************************
     * Function: GetXtWidget
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual Widget GetXtWidget() const
    {
        return m_xt_widget;
    }
    /**
     **********************************************************************
     * Function: GetXtWidgetClass
     *
     *   Author: $author$
     *     Date: 4/26/2004
     **********************************************************************
     */
    virtual WidgetClass GetXtWidgetClass() const
    {
        return m_xt_widget_class;
    }
};

/**
 **********************************************************************
 *  Class: cXtObject
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXtObject
: public cXtWidget
{
public:
    typedef cXtWidget cIs;

    /**
     **********************************************************************
     * Constructor: cXtObject
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXtObject
    (String xt_name="cXtObject",
     String xt_class_name="cXtObject",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtRectObj
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXtRectObj
: public cXtObject
{
public:
    typedef cXtObject cIs;

    /**
     **********************************************************************
     * Constructor: cXtRectObj
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXtRectObj
    (String xt_name="cXtRectObj",
     String xt_class_name="cXtRectObj",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtWindowObj
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXtWindowObj
: public cXtRectObj
{
public:
    typedef cXtRectObj cIs;

    /**
     **********************************************************************
     * Constructor: cXtWindowObj
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXtWindowObj
    (String xt_name="cXtWindowObj",
     String xt_class_name="cXtWindowObj",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtComposit
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXtComposit
: public cXtWindowObj
{
public:
    typedef cXtWindowObj cIs;

    /**
     **********************************************************************
     * Constructor: cXtComposit
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXtComposit
    (String xt_name="cXtComposit",
     String xt_class_name="cXtComposit",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtConstraint
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXtConstraint
: public cXtComposit
{
public:
    typedef cXtComposit cIs;

    /**
     **********************************************************************
     * Constructor: cXtConstraint
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXtConstraint
    (String xt_name="cXtConstraint",
     String xt_class_name="cXtConstraint",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtShell
: public cXtComposit
{
public:
    typedef cXtComposit cIs;

    /**
     **********************************************************************
     * Constructor: cXtShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtShell
    (String xt_name="cXtShell",
     String xt_class_name="cXtShell",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtWMShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtWMShell
: public cXtShell
{
public:
    typedef cXtShell cIs;

    /**
     **********************************************************************
     * Constructor: cXtWMShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtWMShell
    (String xt_name="cXtWMShell",
     String xt_class_name="cXtWMShell",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtOverrideShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtOverrideShell
: public cXtShell
{
public:
    typedef cXtShell cIs;

    /**
     **********************************************************************
     * Constructor: cXtOverrideShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtOverrideShell
    (String xt_name="cXtOverrideShell",
     String xt_class_name="cXtOverrideShell",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtVendorShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtVendorShell
: public cXtWMShell
{
public:
    typedef cXtWMShell cIs;

    /**
     **********************************************************************
     * Function: DeleteCallback
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    static void DeleteCallback
    (Widget xt_widget, XtPointer xt_data, XtPointer xt_call)
    {
        cXtVendorShell *shell;

        if ((shell = (cXtVendorShell*)xt_data))
            shell->OnDeleteCallback(xt_call);
    }

    /**
     **********************************************************************
     * Constructor: cXtVendorShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtVendorShell
    (String xt_name="cXtVendorShell",
     String xt_class_name="cXtVendorShell",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }

    /**
     **********************************************************************
     * Function: OnDeleteCallback
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual void OnDeleteCallback(XtPointer xt_call=0)
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtTransientShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtTransientShell
: public cXtVendorShell
{
public:
    typedef cXtVendorShell cIs;

    /**
     **********************************************************************
     * Constructor: cXtTransientShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtTransientShell
    (String xt_name="cXtTransientShell",
     String xt_class_name="cXtTransientShell",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXtTopLevelShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtTopLevelShell
: public cXtVendorShell
{
public:
    typedef cXtVendorShell cIs;

    /**
     **********************************************************************
     * Constructor: cXtTopLevelShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtTopLevelShell
    (String xt_name="cXtTopLevelShell",
     String xt_class_name="cXtTopLevelShell",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

#include <X11/Shell.h>

/**
 **********************************************************************
 *  Class: cXtApplicationShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXtApplicationShell
: public cXtTopLevelShell
{
public:
    typedef cXtTopLevelShell cIs;

    /**
     **********************************************************************
     * Constructor: cXtApplicationShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXtApplicationShell
    (String xt_name="cXtApplicationShell",
     String xt_class_name="cXtApplicationShell",
     WidgetClass xt_widget_class=applicationShellWidgetClass)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError Create
    (Display *x_display, const cXtArgs &args=cXtArgs::m_null)
    {
        return CreateShell
        (x_display, GetXtName(), GetXtClassName(), 
         GetXtWidgetClass(), args);
    }
};





#endif /* ndef _CXTWIDGET_HXX */

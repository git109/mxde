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
 *   File: cxmwidget.hxx
 *
 * Author: $author$
 *   Date: 4/28/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMWIDGET_HXX
#define _CXMWIDGET_HXX

#include <Xm/Xm.h>

#include "cxtwidget.hxx"

/**
 **********************************************************************
 *  Class: cXmString
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
class cXmString
: public cCreatedHandleT<XmString, 0>
{
public:
    typedef cCreatedHandleT<XmString, 0> cIs;

    /**
     **********************************************************************
     * Constructor: cXmString
     *
     *      Author: $author$
     *        Date: 4/29/2004
     **********************************************************************
     */
    cXmString(XmString handle=0, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXmString
     *
     *     Author: $author$
     *       Date: 4/29/2004
     **********************************************************************
     */
    virtual ~cXmString()
    {
        eError error;

        if (m_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError Create(char *text)
    {
        eError error;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (!(error = !(m_handle = XmStringCreateSimple(text))))
        {
            m_created = true;
            return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        XmStringFree(m_handle);
        m_handle = 0;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Operator: XmString
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual operator XmString() const
    {
        return m_handle;
    }
};

/**
 **********************************************************************
 *  Class: cXmGadget
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmGadget
: public cXtRectObj
{
public:
    typedef cXtRectObj cIs;

    /**
     **********************************************************************
     * Constructor: cXmGadget
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmGadget
    (String xt_name="cXmGadget",
     String xt_class_name="cXmGadget",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXmPrimitive
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmPrimitive
: public cXtWindowObj
{
public:
    typedef cXtWindowObj cIs;

    /**
     **********************************************************************
     * Constructor: cXmPrimitive
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmPrimitive
    (String xt_name="cXmPrimitive",
     String xt_class_name="cXmPrimitive",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }

    /**
     **********************************************************************
     * Function: ActivateCallback
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    static void ActivateCallback
    (Widget xt_widget, XtPointer xt_data, 
     XmAnyCallbackStruct *xm_call)
    {
        cXmPrimitive *primative;

        if ((primative = (cXmPrimitive*)xt_data))
            primative->OnActivateCallback(xm_call);
    }

    /**
     **********************************************************************
     * Function: OnActivateCallback
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual void OnActivateCallback(XmAnyCallbackStruct *xm_call)
    {
        if (m_parent)
            m_parent->OnActivateChild
            (*this, *m_parent, xm_call);
    }
    /**
     **********************************************************************
     * Function: AddActivateCallback
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError AddActivateCallback()
    {
        AddCallback
        (XmNactivateCallback,
         (XtCallbackProc)ActivateCallback, this);
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cXmManager
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmManager
: public cXtConstraint
{
public:
    typedef cXtConstraint cIs;

    /**
     **********************************************************************
     * Constructor: cXmManager
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmManager
    (String xt_name="cXmManager",
     String xt_class_name="cXmManager",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXmScrolledWindow
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmScrolledWindow
: public cXmManager
{
public:
    typedef cXmManager cIs;

    /**
     **********************************************************************
     * Constructor: cXmScrolledWindow
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmScrolledWindow
    (String xt_name="cXmScrolledWindow",
     String xt_class_name="cXmScrolledWindow",
     WidgetClass xt_widget_class=0)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

#include <Xm/PanedW.h>

/**
 **********************************************************************
 *  Class: cXmPanedWindow
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmPanedWindow
: public cXmManager
{
public:
    typedef cXmManager cIs;

    /**
     **********************************************************************
     * Constructor: cXmPanedWindow
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmPanedWindow
    (String xt_name="cXmPanedWindow",
     String xt_class_name="cXmPanedWindow",
     WidgetClass xt_widget_class=xmPanedWindowWidgetClass)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

#include <Xm/MainW.h>

/**
 **********************************************************************
 *  Class: cXmMainWindow
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmMainWindow
: public cXmScrolledWindow
{
public:
    typedef cXmScrolledWindow cIs;

    /**
     **********************************************************************
     * Constructor: cXmMainWindow
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmMainWindow
    (String xt_name="cXmMainWindow",
     String xt_class_name="cXmMainWindow",
     WidgetClass xt_widget_class=xmMainWindowWidgetClass)
    : cIs(xt_name, xt_class_name, xt_widget_class) 
    {
    }
};

#include <Xm/Protocols.h>

/**
 **********************************************************************
 *  Class: cXmApplicationShell
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmApplicationShell
: public cXtApplicationShell
{
public:
    typedef cXtApplicationShell cIs;

    /**
     **********************************************************************
     * Constructor: cXmApplicationShell
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmApplicationShell
    (String xt_name="cXmApplicationShell",
     String xt_class_name="cXmApplicationShell")
    : cIs(xt_name, xt_class_name) 
    {
    }

    /**
     **********************************************************************
     * Function: AddProtocolCallback
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError AddProtocolCallback
    (Atom property, Atom protocol, 
     XtCallbackProc callback, XtPointer pointer)
    {
        if (!m_xt_widget)
            return e_ERROR_NOT_ATTACHED;

        XmAddProtocolCallback
        (m_xt_widget, property, 
         protocol, callback, pointer);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: RemoveProtocolCallback
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError RemoveProtocolCallback
    (Atom property, Atom protocol, 
     XtCallbackProc callback, XtPointer pointer)
    {
        if (!m_xt_widget)
            return e_ERROR_NOT_ATTACHED;

        XmRemoveProtocolCallback
        (m_xt_widget, property, 
         protocol, callback, pointer);
        return e_ERROR_NONE;
    }
};





#endif /* ndef _CXMWIDGET_HXX */

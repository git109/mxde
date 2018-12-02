/**
 **********************************************************************
 * Copyright (c) 1988-2013 $organization$
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
 *   File: cxmhellomain.hxx
 *
 * Author: $author$
 *   Date: 6/22/2013
 **********************************************************************
 */
#if !defined(_CXMHELLOMAIN_HXX) || defined(CXMHELLOMAIN_MEMBERS_ONLY)
#if !defined(_CXMHELLOMAIN_HXX) && !defined(CXMHELLOMAIN_MEMBERS_ONLY)
#define _CXMHELLOMAIN_HXX
#endif /* !defined(_CXMHELLOMAIN_HXX) && !defined(CXMHELLOMAIN_MEMBERS_ONLY) */

#if !defined(CXMHELLOMAIN_MEMBERS_ONLY)
#include "cxmapplicationshell.hxx"
#include "cxmmainwindow.hxx"
#include "cxmmain.hxx"
#include "cxmwmhintsinterface.hxx"
#include "cxmtextfield.hxx"
#include "cxmpushbutton.hxx"
#include "cxmlabel.hxx"
#include "cxmform.hxx"
#include "cxmstring.hxx"
#include "cxmdropsite.hxx"
#include "cxatom.hxx"

#define DEFAULT_CXMHELLOMAIN_NAME "cXmHelloMain"
#define DEFAULT_CXMHELLOMAIN_CLASS_NAME DEFAULT_CXMHELLOMAIN_NAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

//typedef cXmMainImplement cXmHelloMainImplement;
class cXmHelloMainImplement
: virtual public cXmMainImplement,
  virtual public cXtCallbackImplement
{
public:
};
typedef cXmMain cXmHelloMainExtend;
/**
 **********************************************************************
 *  Class: cXmHelloMain
 *
 * Author: $author$
 *   Date: 6/22/2013
 **********************************************************************
 */
class cXmHelloMain
: virtual public cXmHelloMainImplement,
  public cXmHelloMainExtend
{
public:
    typedef cXmHelloMainImplement cImplements;
    typedef cXmHelloMainExtend cExtends;

    cXmApplicationShell m_shellWidget;
    cXmMainWindow m_formWidget;
    //cXmForm m_formWidget;
    cXmPushButton m_helloWidget;
    cXAtom m_atomWmProtocols;
    cXAtom m_atomWmDeleteWindow;

    /**
     **********************************************************************
     *  Constructor: cXmHelloMain
     *
     *       Author: $author$
     *         Date: 6/22/2013
     **********************************************************************
     */
    cXmHelloMain
    (const String xtNameChars = DEFAULT_CXMHELLOMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXMHELLOMAIN_CLASS_NAME,
     const tChar* displayNameChars = DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen = DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends
      (xtNameChars, xtClassNameChars, 
       displayNameChars, displayScreen),
      m_shellWidget(m_display),
      m_formWidget(m_display),
      m_helloWidget(m_display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmHelloMain
     *
     *      Author: $author$
     *        Date: 6/22/2013
     **********************************************************************
     */
    virtual ~cXmHelloMain()
    {
    }
#else /* !defined(CXMHELLOMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMHELLOMAIN_MEMBERS_ONLY) */

#if !defined(CXMHELLOMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: AfterOpenDisplay
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError AfterOpenDisplay
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        cXtArgList argList
        (XtNallowShellResize,False, 
         XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, cXtNend);

        cXtArgList formArgList
        (XtNinput,True, XmNmargin,0, XmNshadowThickness,0,
         XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, cXtNend);

        cXmString buttonString("Hello");

        cXtArgList buttonArgList
        (XmNlabelString,(XtArgVal)(buttonString.Attached()), 
         XmNmargin,0, XtNx,0, XtNy,0, XtNwidth,50, XtNheight,50, cXtNend);

        eError error = e_ERROR_NONE;
        Widget parentWidget;
        Widget formWidget;
        Widget buttonWidget;
        Atom atom;
        eError error2;

        if (None != (atom = m_atomWmProtocols.AttachIntern(display, "WM_PROTOCOLS", False)))
        if (None != (atom = m_atomWmDeleteWindow.AttachIntern(display, "WM_DELETE_WINDOW", False)))
        if (None != (parentWidget = m_shellWidget.CreateShellAttached
            (error2, m_appName.str(), m_appClassName.str(), argList, argList.Length())))
        {
            m_shellWidget.SetIsCreated(false);

            if (None != (formWidget = m_formWidget.CreateAttached
                (error2, parentWidget, formArgList, formArgList.Length())))
            {
                m_formWidget.SetIsCreated(false);
                m_formWidget.ManageChild();

                if (None != (buttonWidget = m_helloWidget.CreateAttached
                    (error2, formWidget, buttonArgList, buttonArgList.Length())))
                {
                    m_helloWidget.SetIsCreated(false);
                    m_helloWidget.ManageChild();
                    m_helloWidget.AddCallback
                    (XmNactivateCallback, (cXtCallbackInterface*)(this));

                    m_shellWidget.Realize();
                    XtAddEventHandler
                    (parentWidget, NoEventMask, True,
                     HandleXtEvent, (XtPointer)((cXtEventHandlerInterface*)(this)));
                    XSetWMProtocols
                    (display.Attached(), XtWindow(parentWidget),
                     &atom, 1);
                    return error;
                }
            }
            m_shellWidget.Destroy(true);
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnHandleXtEvent
     *
     *    Author: $author$           
     *      Date: 6/23/2013
     **********************************************************************
     */
    virtual eError OnHandleXtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;

        if (xEvent.type == ClientMessage)
        if (xEvent.xclient.message_type == m_atomWmProtocols.Attached())
        if (xEvent.xclient.data.l[0] == m_atomWmDeleteWindow.Attached())
        if (xWidget == m_shellWidget.Attached())
        {
            DBI(("() WM_DELETE_WINDOW\n"));
            SetQuit();
        }
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMHELLOMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMHELLOMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXMHELLOMAIN_HXX) || defined(CXMHELLOMAIN_MEMBERS_ONLY) */
        


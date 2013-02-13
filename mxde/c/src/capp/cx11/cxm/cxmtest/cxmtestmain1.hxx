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
 *   File: cxmtestmain.hxx
 *
 * Author: $author$           
 *   Date: 5/14/2010
 **********************************************************************
 */
#if !defined(_CXMTESTMAIN_HXX) || defined(CXMTESTMAIN_MEMBERS_ONLY)
#if !defined(_CXMTESTMAIN_HXX) && !defined(CXMTESTMAIN_MEMBERS_ONLY)
#define _CXMTESTMAIN_HXX
#endif /* !defined(_CXMTESTMAIN_HXX) && !defined(CXMTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXMTESTMAIN_MEMBERS_ONLY)
#include "cplatform_Xm_MainW.h"
#include "cplatform_Xm_PushB.h"
#include "cxtapplicationshell.hxx"
#include "cxmmain.hxx"
#include "cxtmain.hxx"
#include "cargmain.hxx"
#include "cmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmTestMainExtend
 *
 *  Author: $author$           
 *    Date: 5/14/2010
 **********************************************************************
 */
typedef cXmMain
cXmTestMainExtend;
/**
 **********************************************************************
 *  Class: cXmTestMain
 *
 * Author: $author$           
 *   Date: 5/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmTestMain
: /*virtual public cXmTestMainImplement,
  */public cXmTestMainExtend
{
public:
    /*typedef cXmTestMainImplement cImplements;
    */typedef cXmTestMainExtend cExtends;

    cXtApplicationShell m_shellWidget;
    cXtWidget m_formWidget;
    cXtWidget m_buttonWidget;

    /**
     **********************************************************************
     *  Constructor: cXmTestMain
     *
     *       Author: $author$           
     *         Date: 5/14/2010
     **********************************************************************
     */
    cXmTestMain
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME,
     const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends
      (xtNameChars, xtClassNameChars, 
       displayNameChars, displayScreen),

      m_shellWidget(m_display),
      m_formWidget(m_display),
      m_buttonWidget(m_display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmTestMain
     *
     *      Author: $author$           
     *        Date: 5/14/2010
     **********************************************************************
     */
    virtual ~cXmTestMain()
    {
    }
#else /* !defined(CXMTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXMTESTMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: AfterOpenDisplay
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError AfterOpenDisplay
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;

        cXtArgList shellArgList
        (XtNinput, True, XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);

        cXtArgList formArgList
        (XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);

        cXtArgList buttonArgList
        (XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);

        Widget xShellWidget;
        Widget xMainWidget;
        String xtNameChars;
        String xtClassNameChars;
        eError error2;

        DBF(("()...\n"));

        if ((xtNameChars = AppName()))
        if ((xtClassNameChars = AppClassName()))
        if (None != (xShellWidget = m_shellWidget.CreateShellAttached
            (error2, xtNameChars, xtClassNameChars,
             applicationShellWidgetClass, shellArgList, shellArgList.Length())))
        {
            if (None != (xMainWidget = m_formWidget.CreateAttached
                (error2, xtNameChars, xShellWidget,
                 xmMainWindowWidgetClass, formArgList, formArgList.Length(), true)))
            {
                m_buttonWidget.CreateAttached
                (error2, xtNameChars, xMainWidget,
                 xmPushButtonWidgetClass, buttonArgList, buttonArgList.Length(), true);
            }
            m_shellWidget.Realize();
            return error;
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMTESTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXMTESTMAIN_HXX) || defined(CXMTESTMAIN_MEMBERS_ONLY) */

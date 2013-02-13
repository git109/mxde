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
#include "cxmtestapplicationshell.hxx"
#include "cxtshapedmain.hxx"

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
typedef cXtShapedMain
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
: /*virtual public cXmTestMainImplement,*/
  public cXmTestMainExtend
{
public:
    /*typedef cXmTestMainImplement cImplements;*/
    typedef cXmTestMainExtend cExtends;

    unsigned m_cornerRadius;
    unsigned m_edgeThickness;
    cXmTestApplicationShell m_shapedShellWidget;

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

      m_cornerRadius(24),
      m_edgeThickness(4),

      m_shapedShellWidget
      (m_mwmHints, m_display, 
       m_cornerRadius,m_cornerRadius, m_edgeThickness)
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
     * Function: OnHandleXtEvent
     *
     *   Author: $author$           
     *     Date: 5/24/2010
     **********************************************************************
     */
    virtual eError OnHandleXtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        if (xWidget == (m_shapedShellWidget.Attached()))
        {
            DBF(("()\n m_shapedShellWidget.OnHandleXtEvent()...\n"));
            error = m_shapedShellWidget.OnHandleXtEvent
            (xWidget, xPointer, xEvent,continueToDispatch );
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: BeforeCreateShapedApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError BeforeCreateShapedApplicationShell
    (cXImageSolidBrush& fgRegionBrush,
     cXImageSolidBrush& bgRegionBrush,
     cXImageSolidBrush& fgBrush,
     cXImageSolidBrush& bgBrush,
     cXColormap& colormap,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;

        m_shapedShellWidget.BeforeCreateShapedApplicationShell
        (fgRegionBrush, bgRegionBrush, fgBrush, bgBrush,
         colormap,display,rootXWindow,argc,argv,env);

        return error;
    }
    /**
     **********************************************************************
     *  Function: AfterCreateShapedApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError AfterCreateShapedApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXImageSolidBrush& fgRegionBrush,
     cXImageSolidBrush& bgRegionBrush,
     cXImageSolidBrush& fgBrush,
     cXImageSolidBrush& bgBrush,
     cXColormap& colormap,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        cXtApplicationShellInterface& shapedShellWidget 
        = (cXtApplicationShellInterface&)(m_shapedShellWidget);
        eError error = e_ERROR_NONE;
        Window xWindow;

        if (&shellWidget != &shapedShellWidget)
            shapedShellWidget.Attach(shellWidget.Attached());

        m_shapedShellWidget.AfterCreateShapedApplicationShell
        (shellWidget, fgRegionBrush, bgRegionBrush, fgBrush, bgBrush,
         colormap,display,rootXWindow,argc,argv,env);

        return error;
    }
    /**
     **********************************************************************
     *  Function: MainEventHandlerMask
     *
     *    Author: $author$           
     *      Date: 5/25/2010
     **********************************************************************
     */
    virtual EventMask MainEventHandlerMask() const
    {
        EventMask xEventMask 
        = ButtonPressMask | ButtonReleaseMask 
        | cExtends::MainEventHandlerMask();
        return xEventMask;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMTESTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXMTESTMAIN_HXX) || defined(CXMTESTMAIN_MEMBERS_ONLY) */

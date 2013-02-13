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
 *   File: cxttestmain.hxx
 *
 * Author: $author$           
 *   Date: 5/13/2010
 **********************************************************************
 */
#if !defined(_CXTTESTMAIN_HXX) || defined(CXTTESTMAIN_MEMBERS_ONLY)
#if !defined(_CXTTESTMAIN_HXX) && !defined(CXTTESTMAIN_MEMBERS_ONLY)
#define _CXTTESTMAIN_HXX
#endif /* !defined(_CXTTESTMAIN_HXX) && !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXTTESTMAIN_MEMBERS_ONLY)
#include "cxtmain.hxx"
#include "cxteventhandler.hxx"
#include "cxtarglist.hxx"
#include "cxtwidget.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTestMainExtend
 *
 *  Author: $author$           
 *    Date: 5/13/2010
 **********************************************************************
 */
typedef cXtMain
cXtTestMainExtend;
/**
 **********************************************************************
 *  Class: cXtTestMain
 *
 * Author: $author$           
 *   Date: 5/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtTestMain
: public cXtTestMainExtend
{
public:
    typedef cXtTestMainExtend cExtends;

    cXtWidget m_shellWidget;

    /**
     **********************************************************************
     *  Constructor: cXtTestMain
     *
     *       Author: $author$           
     *         Date: 5/13/2010
     **********************************************************************
     */
    cXtTestMain
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME)
    : cExtends(xtNameChars, xtClassNameChars),
      m_shellWidget(m_display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtTestMain
     *
     *      Author: $author$           
     *        Date: 5/13/2010
     **********************************************************************
     */
    virtual ~cXtTestMain()
    {
    }
#else /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXTTESTMAIN_MEMBERS_ONLY)
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
        eError error = e_ERROR_NONE;

        cXtArgList shellArgList
        (XtNinput, True, XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);

        Widget xShellWidget;
        eError error2;

        if (None != (xShellWidget = m_shellWidget.CreateShellAttached
            (error2, m_xtNameChars, m_xtClassNameChars,
             applicationShellWidgetClass, shellArgList, shellArgList.Length())))
        {
            m_shellWidget.Realize();
            return error;
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTTESTMAIN_HXX) || defined(CXTTESTMAIN_MEMBERS_ONLY) */

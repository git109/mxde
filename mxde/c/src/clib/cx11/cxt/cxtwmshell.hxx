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
 *   File: cxtwmshell.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTWMSHELL_HXX) || defined(CXTWMSHELL_MEMBERS_ONLY)
#if !defined(_CXTWMSHELL_HXX) && !defined(CXTWMSHELL_MEMBERS_ONLY)
#define _CXTWMSHELL_HXX
#endif /* !defined(_CXTWMSHELL_HXX) && !defined(CXTWMSHELL_MEMBERS_ONLY) */

#if !defined(CXTWMSHELL_MEMBERS_ONLY)
#include "cxtwmshellinterface.hxx"
#include "cxtwindowobj.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWMShellExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtWindowObj
cXtWMShellExtend;
/**
 **********************************************************************
 *  Class: cXtWMShell
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWMShell
: virtual public cXtWMShellImplement,
  public cXtWMShellExtend
{
public:
    typedef cXtWMShellImplement cImplements;
    typedef cXtWMShellExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtWMShell
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtWMShell
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtWMShell
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtWMShell()
    {
    }
#else /* !defined(CXTWMSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTWMSHELL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: ChangeWMDecorations
     *
     *    Author: $author$           
     *      Date: 6/26/2010
     **********************************************************************
     */
    virtual eError ChangeWMDecorations
    (cXMwmHintsInterface& mwmHints,
     CARD32 decorations)
#if defined(CXTWMSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWMSHELL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT)
        eError error = ChangeWMHints
        (mwmHints, MWM_HINTS_DECORATIONS, 0, decorations);
#else /* !defined(CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWMSHELL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ChangeWMHints
     *
     *    Author: $author$           
     *      Date: 6/26/2010
     **********************************************************************
     */
    virtual eError ChangeWMHints
    (cXMwmHintsInterface& mwmHints,
     CARD32 flags = 0, CARD32 functions = 0, 
     CARD32 decorations = 0, INT32 inputMode = 0)
#if defined(CXTWMSHELL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTWMSHELL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Window xWindow;

        if (None != (xWindow = WindowAttached()))
        if ((xDisplay = DisplayAttached()))
        {
            if (MWM_HINTS_DECORATIONS == (flags & MWM_HINTS_DECORATIONS))
                XUnmapWindow(xDisplay, xWindow);

            error = mwmHints.ChangeHints
            (*xDisplay, xWindow, flags, 
             functions, decorations, inputMode);

            if (MWM_HINTS_DECORATIONS == (flags & MWM_HINTS_DECORATIONS))
                XMapWindow(xDisplay, xWindow);
        }
#else /* !defined(CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTWMSHELL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTWMSHELL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTWMSHELL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWMSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTWMSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTWMSHELL_HXX) || defined(CXTWMSHELL_MEMBERS_ONLY) */

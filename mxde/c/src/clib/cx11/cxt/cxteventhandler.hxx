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
 *   File: cxteventhandler.hxx
 *
 * Author: $author$           
 *   Date: 4/28/2010
 **********************************************************************
 */
#if !defined(_CXTEVENTHANDLER_HXX) || defined(CXTEVENTHANDLER_MEMBERS_ONLY)
#if !defined(_CXTEVENTHANDLER_HXX) && !defined(CXTEVENTHANDLER_MEMBERS_ONLY)
#define _CXTEVENTHANDLER_HXX
#endif /* !defined(_CXTEVENTHANDLER_HXX) && !defined(CXTEVENTHANDLER_MEMBERS_ONLY) */

#if !defined(CXTEVENTHANDLER_MEMBERS_ONLY)
#include "cxteventhandlerinterface.hxx"
#include "cxbase.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtEventHandlerExtend
 *
 *  Author: $author$           
 *    Date: 4/28/2010
 **********************************************************************
 */
typedef cXBase
cXtEventHandlerExtend;
/**
 **********************************************************************
 *  Class: cXtEventHandler
 *
 * Author: $author$           
 *   Date: 4/28/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtEventHandler
: virtual public cXtEventHandlerImplement,
  public cXtEventHandlerExtend
{
public:
    typedef cXtEventHandlerImplement cImplements;
    typedef cXtEventHandlerExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtEventHandler
     *
     *       Author: $author$           
     *         Date: 4/28/2010
     **********************************************************************
     */
    cXtEventHandler()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtEventHandler
     *
     *      Author: $author$           
     *        Date: 4/28/2010
     **********************************************************************
     */
    virtual ~cXtEventHandler()
    {
    }
#else /* !defined(CXTEVENTHANDLER_MEMBERS_ONLY) */
#endif /* !defined(CXTEVENTHANDLER_MEMBERS_ONLY) */

#include "cxteventhandler_members.hxx"

    /**
     **********************************************************************
     *  Function: OnHandleXtEvent
     *
     *    Author: $author$           
     *      Date: 4/28/2010
     **********************************************************************
     */
    virtual eError OnHandleXtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        continueToDispatch = True;
        switch (xEvent.type)
        {
#include "cxteventhandler_cases.hxx"
        }
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */

#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     *  Function: HandleXtEvent
     *
     *    Author: $author$           
     *      Date: 4/28/2010
     **********************************************************************
     */
    static void HandleXtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent* xEvent, Boolean* continueToDispatch)
    {
        cXtEventHandlerInterface* handler;

        DBT(("()...\n"));

        *continueToDispatch = True;

        if ((handler = (cXtEventHandlerInterface*)(xPointer)))
            handler->OnHandleXtEvent(xWidget, xPointer, *xEvent, *continueToDispatch);
    }
#endif /* !defined(CXTEVENTHANDLER_MEMBERS_ONLY) */

#if !defined(CXTEVENTHANDLER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTEVENTHANDLER_MEMBERS_ONLY) */
#endif /* !defined(CXTEVENTHANDLER_MEMBERS_ONLY) */

#endif /* !defined(_CXTEVENTHANDLER_HXX) || defined(CXTEVENTHANDLER_MEMBERS_ONLY) */

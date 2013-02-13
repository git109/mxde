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
 *   File: cxtcallback.hxx
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
#if !defined(_CXTCALLBACK_HXX) || defined(CXTCALLBACK_MEMBERS_ONLY)
#if !defined(_CXTCALLBACK_HXX) && !defined(CXTCALLBACK_MEMBERS_ONLY)
#define _CXTCALLBACK_HXX
#endif /* !defined(_CXTCALLBACK_HXX) && !defined(CXTCALLBACK_MEMBERS_ONLY) */

#if !defined(CXTCALLBACK_MEMBERS_ONLY)
#include "cxtcallbackinterface.hxx"
#include "cxtbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCallbackExtend
 *
 *  Author: $author$           
 *    Date: 5/19/2010
 **********************************************************************
 */
typedef cXtBase
cXtCallbackExtend;
/**
 **********************************************************************
 *  Class: cXtCallback
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtCallback
: virtual public cXtCallbackImplement,
  public cXtCallbackExtend
{
public:
    typedef cXtCallbackImplement cImplements;
    typedef cXtCallbackExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtCallback
     *
     *       Author: $author$           
     *         Date: 5/19/2010
     **********************************************************************
     */
    cXtCallback()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtCallback
     *
     *      Author: $author$           
     *        Date: 5/19/2010
     **********************************************************************
     */
    virtual ~cXtCallback()
    {
    }
#else /* !defined(CXTCALLBACK_MEMBERS_ONLY) */
#endif /* !defined(CXTCALLBACK_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: OnXtCallback
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError OnXtCallback
    (Widget xWidget, XtPointer clientData, XtPointer callData)
#if defined(CXTCALLBACK_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTCALLBACK_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTCALLBACK_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTCALLBACK_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTCALLBACK_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTCALLBACK_MEMBER_FUNCS_INTERFACE) */

#if defined(CXTCALLBACK_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     *  Function: XtCallback
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    static void XtCallback
    (Widget xWidget, XtPointer clientData, XtPointer callData)
    {
        cXtCallbackInterface* callback;
        eError error;

        DBI(("()...\n"));

        if ((callback = (cXtCallbackInterface*)(clientData)))
        if ((error = callback->OnXtCallback(xWidget, clientData, callData)))
            throw (error);
    }
#endif /* defined(CXTCALLBACK_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTCALLBACK_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCALLBACK_MEMBERS_ONLY) */
#endif /* !defined(CXTCALLBACK_MEMBERS_ONLY) */

#endif /* !defined(_CXTCALLBACK_HXX) || defined(CXTCALLBACK_MEMBERS_ONLY) */

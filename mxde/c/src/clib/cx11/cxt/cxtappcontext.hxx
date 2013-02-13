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
 *   File: cxtappcontext.hxx
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
#if !defined(_CXTAPPCONTEXT_HXX) || defined(CXTAPPCONTEXT_MEMBERS_ONLY)
#if !defined(_CXTAPPCONTEXT_HXX) && !defined(CXTAPPCONTEXT_MEMBERS_ONLY)
#define _CXTAPPCONTEXT_HXX
#endif /* !defined(_CXTAPPCONTEXT_HXX) && !defined(CXTAPPCONTEXT_MEMBERS_ONLY) */

#if !defined(CXTAPPCONTEXT_MEMBERS_ONLY)
#include "cxtappcontextattached.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if !defined(CXTAPPCONTEXTINTERFACE_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cXtAppContextInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cXtAppContextCreatedInterface
cXtAppContextInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtAppContextInterface
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtAppContextInterface
: virtual public cXtAppContextInterfaceImplement
{
public:
    typedef cXtAppContextInterfaceImplement cImplements;
#else /* !defined(CXTAPPCONTEXTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPCONTEXTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTAPPCONTEXTINTERFACE_MEMBERS_ONLY)
};
/**
 **********************************************************************
 *  Class: cXtAppContextImplement
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtAppContextImplement
: virtual public cXtAppContextInterface
{
public:
    typedef cXtAppContextInterface cImplements;
};
#else /* !defined(CXTAPPCONTEXTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPCONTEXTINTERFACE_MEMBERS_ONLY) */

/**
 **********************************************************************
 * Typedef: cXtAppContextExtend
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cXtAppContextCreated
cXtAppContextExtend;
/**
 **********************************************************************
 *  Class: cXtAppContext
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtAppContext
: virtual public cXtAppContextImplement,
  public cXtAppContextExtend
{
public:
    typedef cXtAppContextImplement cImplements;
    typedef cXtAppContextExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtAppContext
     *
     *       Author: $author$           
     *         Date: 4/22/2010
     **********************************************************************
     */
    cXtAppContext
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtAppContext
     *
     *      Author: $author$           
     *        Date: 4/22/2010
     **********************************************************************
     */
    virtual ~cXtAppContext()
    {
        eError error;
        if ((error = Destroyed()))
            throw (error);
    }
#else /* !defined(CXTAPPCONTEXT_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPCONTEXT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: operator XtAppContext
     *
     *    Author: $author$           
     *      Date: 4/22/2010
     **********************************************************************
     */
    virtual operator XtAppContext() const
#if defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE) */
    {
        XtAppContext xtAppContext = (XtAppContext)(Attached());
#if !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT) */
        return xtAppContext;
    }
#endif /* defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTAPPCONTEXT_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$           
     *      Date: 4/22/2010
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed = false)
#if defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((detached = XtCreateApplicationContext()))
        {
            if (detached == (Attach(detached)))
            if ((SetIsCreated()))
                return error;

            XtDestroyApplicationContext(detached);
            error = e_ERROR_FAILED;
        }
#else /* !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$           
     *      Date: 4/22/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached;

        if ((error = Created(onlyCreated, true)))
            return error;

        SetIsCreated(false);

        if ((detached = Attached()))
            XtDestroyApplicationContext(detached);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPCONTEXT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPCONTEXT_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTAPPCONTEXT_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPCONTEXT_MEMBERS_ONLY) */

#endif /* !defined(_CXTAPPCONTEXT_HXX) || defined(CXTAPPCONTEXT_MEMBERS_ONLY) */

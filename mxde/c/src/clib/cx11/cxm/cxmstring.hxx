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
 *   File: cxmstring.hxx
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
#if !defined(_CXMSTRING_HXX) || defined(CXMSTRING_MEMBERS_ONLY)
#if !defined(_CXMSTRING_HXX) && !defined(CXMSTRING_MEMBERS_ONLY)
#define _CXMSTRING_HXX
#endif /* !defined(_CXMSTRING_HXX) && !defined(CXMSTRING_MEMBERS_ONLY) */

#if !defined(CXMSTRING_MEMBERS_ONLY)
#include "cxmstringcreated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmStringExtend
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cXmStringCreated
cXmStringExtend;
/**
 **********************************************************************
 *  Class: cXmString
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmString
: /*virtual public cXmStringImplement,*/
  public cXmStringExtend
{
public:
    /*typedef cXmStringImplement cImplements;*/
    typedef cXmStringExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmString
     *
     *       Author: $author$           
     *         Date: 7/13/2010
     **********************************************************************
     */
    cXmString
    (const String chars)
    {
        eError error;
        if (chars)
        DBE_THROW_ERROR(error, Create(chars));
    }
    /**
     **********************************************************************
     *  Constructor: cXmString
     *
     *       Author: $author$           
     *         Date: 7/13/2010
     **********************************************************************
     */
    cXmString
    (XmString attached=0,
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmString
     *
     *      Author: $author$           
     *        Date: 7/13/2010
     **********************************************************************
     */
    virtual ~cXmString()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CXMSTRING_MEMBERS_ONLY) */
#endif /* !defined(CXMSTRING_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$           
     *      Date: 7/13/2010
     **********************************************************************
     */
    virtual eError Create
    (const String chars, 
     bool onlyDestroyed = false) 
#if defined(CXMSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateAttached(error, chars, onlyDestroyed);
#else /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$           
     *      Date: 7/13/2010
     **********************************************************************
     */
    virtual XmString CreateAttached
    (eError& error, const String chars, 
     bool onlyDestroyed = false)
#if defined(CXMSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        XmString detached = 0;
#if !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = Destroyed(onlyDestroyed)))
        if ((detached = CreateDetached(error, chars)))
        if (detached != (AttachCreated(detached)))
        {
            DestroyDetached(detached);
            error = e_ERROR_FAILED;
        }
#else /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$           
     *      Date: 7/13/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CXMSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        XmString detached;
        
        if ((detached = Detach()))
            error = DestroyDetached(detached);
        else
        if (!onlyCreated)
            error = e_ERROR_NONE;
            
#else /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$           
     *      Date: 7/13/2010
     **********************************************************************
     */
    virtual XmString CreateDetached
    (eError& error, const String chars) const
#if defined(CXMSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        XmString detached = 0;
#if !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_FAILED;
        if (chars)
        if ((detached = XmStringCreateSimple(chars)))
            error = e_ERROR_NONE;
#else /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyDetached
     *
     *    Author: $author$           
     *      Date: 7/13/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (XmString detached) const
#if defined(CXMSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        if (detached)
        {
            XmStringFree(detached);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMSTRING_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMSTRING_MEMBERS_ONLY) */
#endif /* !defined(CXMSTRING_MEMBERS_ONLY) */

#endif /* !defined(_CXMSTRING_HXX) || defined(CXMSTRING_MEMBERS_ONLY) */

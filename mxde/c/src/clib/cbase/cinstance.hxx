/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cinstance.hxx
 *
 * Author: $author$
 *   Date: 8/16/2009
 **********************************************************************
 */
#if !defined(_CINSTANCE_HXX) || defined(CINSTANCE_MEMBERS_ONLY)
#if !defined(_CINSTANCE_HXX) && !defined(CINSTANCE_MEMBERS_ONLY)
#define _CINSTANCE_HXX
#endif /* !defined(_CINSTANCE_HXX) && !defined(CINSTANCE_MEMBERS_ONLY) */

#if !defined(CINSTANCE_MEMBERS_ONLY)
#include "cinstanceinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cInstance
 *
 * Author: $author$
 *   Date: 8/16/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cInstance
: virtual public cInstanceImplement,
  public cInstanceBase
{
public:
    typedef cInstanceImplement cImplements;
    typedef cInstanceBase cExtends;
    /**
     **********************************************************************
     *  Constructor: cInstance
     *
     *       Author: $author$
     *         Date: 8/16/2009
     **********************************************************************
     */
    cInstance()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cInstance
     *
     *      Author: $author$
     *        Date: 8/16/2009
     **********************************************************************
     */
    virtual ~cInstance()
    {
    }
#else /* !defined(CINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CINSTANCE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 8/16/2009
     **********************************************************************
     */
    virtual TCOUNT HoldInstance() 
#if defined(CINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        TCOUNT count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 8/16/2009
     **********************************************************************
     */
    virtual TCOUNT FreeInstance() 
#if defined(CINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        TCOUNT count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/16/2009
     **********************************************************************
     */
    virtual eError DeleteInstance() 
#if defined(CINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = DeleteThis();
#if !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 8/16/2009
     **********************************************************************
     */
    virtual eError DeleteThis() 
#if defined(CINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_ALLOWED;
#if !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CINSTANCE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CINSTANCE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CINSTANCE_MEMBERS_ONLY) */

#endif /* !defined(_CINSTANCE_HXX) || defined(CINSTANCE_MEMBERS_ONLY) */

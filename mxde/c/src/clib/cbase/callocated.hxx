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
 *   File: callocated.hxx
 *
 * Author: $author$
 *   Date: 7/2/2009
 **********************************************************************
 */
#if !defined(_CALLOCATED_HXX) || defined(CALLOCATED_MEMBERS_ONLY)
#if !defined(_CALLOCATED_HXX) && !defined(CALLOCATED_MEMBERS_ONLY)
#define _CALLOCATED_HXX
#endif /* !defined(_CALLOCATED_HXX) && !defined(CALLOCATED_MEMBERS_ONLY) */

#if !defined(CALLOCATED_MEMBERS_ONLY)
#include "callocatedinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cAllocated definition
 */
class c_INSTANCE_CLASS cAllocated;

#undef CDB_CLASS
#define CDB_CLASS "cAllocatedT"
/**
 **********************************************************************
 *  Class: cAllocatedT
 *
 * Author: $author$
 *   Date: 7/2/2009
 **********************************************************************
 */
template
<class TDerives=cAllocated,
 class TAllocatedImplement=cAllocatedImplement,
 class TBase=cBase,
 class TImplements=TAllocatedImplement,
 class TExtends=TBase>

class c_INSTANCE_CLASS cAllocatedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;

/* include cAllocated interface member definitions
 */
#define CALLOCATEDINTERFACE_MEMBERS_ONLY
#include "callocatedinterface.hxx"
#undef CALLOCATEDINTERFACE_MEMBERS_ONLY

    bool m_isAllocated;

    /**
     **********************************************************************
     *  Constructor: cAllocatedT
     *
     *       Author: $author$
     *         Date: 7/2/2009
     **********************************************************************
     */
    cAllocatedT
    (bool isAllocated=false)
    : m_isAllocated(isAllocated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cAllocatedT
     *
     *      Author: $author$
     *        Date: 7/2/2009
     **********************************************************************
     */
    virtual ~cAllocatedT()
    {
        eError error;
        if ((error = Freed()))
            throw(error);
    }
#else /* !defined(CALLOCATED_MEMBERS_ONLY) */
#endif /* !defined(CALLOCATED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Allocate
     *
     *   Author: $author$
     *     Date: 7/3/2009
     **********************************************************************
     */
    virtual eError Allocate
    (bool onlyFreed=false) 
#if defined(CALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error;
#if !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        int isTrue;

        if (!(error = Freed(onlyFreed)))
        if (0 > (isTrue = SetIsAllocated()))
            error = -isTrue;
        return error;
    }
#endif /* defined(CALLOCATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 7/3/2009
     **********************************************************************
     */
    virtual eError Free
    (bool onlyAllocated=false) 
#if defined(CALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error;
#if !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        int isTrue;

        if (!(error = Allocated(onlyAllocated, false)))
        if (0 > (isTrue = SetIsAllocated(false)))
            error = -isTrue;
        return error;
    }
#endif /* defined(CALLOCATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Allocated
     *
     *   Author: $author$
     *     Date: 7/3/2009
     **********************************************************************
     */
    virtual eError Allocated
    (bool onlyAllocated=false,
     bool dontAllocate=false) 
#if defined(CALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */

        if (!(IsAllocated()))
        if (onlyAllocated)
            error = e_ERROR_NOT_ALLOCATED;
        else
        if (!dontAllocate)
            error = Allocate(true);

        return error;
    }
#endif /* defined(CALLOCATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Freed
     *
     *   Author: $author$
     *     Date: 7/3/2009
     **********************************************************************
     */
    virtual eError Freed
    (bool onlyFreed=false,
     bool dontFree=false) 
#if defined(CALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */

        if ((IsAllocated()))
        if (onlyFreed)
            error = e_ERROR_ALREADY_ALLOCATED;
        else
        if (!dontFree)
            error = Free(true);

        return error;
    }
#endif /* defined(CALLOCATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIsAllocated
     *
     *   Author: $author$
     *     Date: 7/3/2009
     **********************************************************************
     */
    virtual int SetIsAllocated
    (bool isTrue=true) 
#if defined(CALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        int isAllocated = false;
#if !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
        isAllocated = (m_isAllocated = isTrue);
#else /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return isAllocated;
    }
#endif /* defined(CALLOCATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: IsAllocated
     *
     *   Author: $author$
     *     Date: 7/3/2009
     **********************************************************************
     */
    virtual bool IsAllocated() const 
#if defined(CALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        bool isAllocated = false;
#if !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
        isAllocated = m_isAllocated;
#else /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return isAllocated;
    }
#endif /* defined(CALLOCATED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CALLOCATED_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cAllocatedExtends
 *
 *  Author: $author$
 *    Date: 7/3/2009
 **********************************************************************
 */
typedef cAllocatedT<>
cAllocatedExtends;
/**
 **********************************************************************
 *  Class: cAllocated
 *
 * Author: $author$
 *   Date: 7/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cAllocated
: public cAllocatedExtends
{
public:
    typedef cAllocatedExtends cExtends;
    typedef cAllocated cDerives;
    /**
     **********************************************************************
     * Constructor: cAllocated
     *
     *      Author: $author$
     *        Date: 7/3/2009
     **********************************************************************
     */
    cAllocated
    (bool isAllocated=false) 
    : cExtends(isAllocated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CALLOCATED_MEMBERS_ONLY) */
#endif /* !defined(CALLOCATED_MEMBERS_ONLY) */

#endif /* !defined(_CALLOCATED_HXX) || defined(CALLOCATED_MEMBERS_ONLY) */

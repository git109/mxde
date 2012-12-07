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
 *   File: ccreated.hxx
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
#if !defined(_CCREATED_HXX) || defined(CCREATED_MEMBERS_ONLY)
#if !defined(_CCREATED_HXX) && !defined(CCREATED_MEMBERS_ONLY)
#define _CCREATED_HXX
#endif /* !defined(_CCREATED_HXX) && !defined(CCREATED_MEMBERS_ONLY) */

#if !defined(CCREATED_MEMBERS_ONLY)
#include "ccreatedinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cCreated definition
 */
class c_INSTANCE_CLASS cCreated;

#undef CDB_CLASS
#define CDB_CLASS "cCreatedT"
/**
 **********************************************************************
 *  Class: cCreatedT
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
template
<class TDerives=cCreated,
 class TCreatedImplement=cCreatedImplement,
 class TBase=cBase,
 class TImplements=TCreatedImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cCreatedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cCreated interface member definitions
 */
#define CCREATEDINTERFACE_MEMBERS_ONLY
#include "ccreatedinterface.hxx"
#undef CCREATEDINTERFACE_MEMBERS_ONLY

    bool m_isCreated;

    /**
     **********************************************************************
     * Constructor: cCreatedT
     *
     *      Author: $author$
     *        Date: 5/4/2009
     **********************************************************************
     */
    cCreatedT
    (bool isCreated=false) 
    : m_isCreated(isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCreatedT
     *
     *     Author: $author$
     *       Date: 5/4/2009
     **********************************************************************
     */
    virtual ~cCreatedT()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CCREATED_MEMBERS_ONLY) */
#endif /* !defined(CCREATED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Created
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual eError Created
    (bool onlyCreated=false,
     bool dontCreate=false) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isCreated;

        if (!(isCreated = IsCreated()))
        if (onlyCreated)
            return e_ERROR_NOT_CREATED;
        else
        if (!dontCreate)
        if ((error = Create(!isCreated)))
            return error;
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroyed
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Destroyed
    (bool onlyDestroyed=false,
     bool dontDestroy=false) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isCreated;

        if ((isCreated = IsCreated()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if (!dontDestroy)
        if ((error = Destroy(isCreated)))
            return error;
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isCreated;
        int is;

        if ((isCreated = IsCreated()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(isCreated)))
            return error;

        if (!(error = CreateDestroyed()))
        if (0 > (is = SetIsCreated()))
        {
            DestroyCreated();
            error = -is;
        }
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual eError Destroy(bool onlyCreated=false) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isCreated;
        int is;

        if ((isCreated = IsCreated()))
        {
            if (0 > (is = SetIsCreated(false)))
                error = -is;
            else
            error = DestroyCreated();
        }
        else
        if (onlyCreated)
            error = e_ERROR_NOT_CREATED;

        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CreateDestroyed
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError CreateDestroyed() 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyCreated
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError DestroyCreated() 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual int SetIsCreated
    (bool is=true) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) 
        int isCreated = (m_isCreated = is);
#else /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        int isCreated = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return isCreated;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: IsCreated
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual bool IsCreated() const 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
        bool isCreated = false;
#if !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) 
        isCreated = m_isCreated;
#else /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return isCreated;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCREATED_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cCreatedExtends
 *
 *  Author: $author$
 *    Date: 5/4/2009
 **********************************************************************
 */
typedef cCreatedT<>
cCreatedExtends;
/**
 **********************************************************************
 *  Class: cCreated
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cCreated
: public cCreatedExtends
{
public:
    typedef cCreatedExtends cExtends;
    typedef cCreated cDerives;
    /**
     **********************************************************************
     * Constructor: cCreated
     *
     *      Author: $author$
     *        Date: 5/4/2009
     **********************************************************************
     */
    cCreated
    (bool isCreated=false) 
    : cExtends(isCreated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCREATED_MEMBERS_ONLY) */
#endif /* !defined(CCREATED_MEMBERS_ONLY) */

#endif /* !defined(_CCREATED_HXX) || defined(CCREATED_MEMBERS_ONLY) */

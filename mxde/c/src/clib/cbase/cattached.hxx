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
 *   File: cattached.hxx
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
#if !defined(_CATTACHED_HXX) || defined(CATTACHED_MEMBERS_ONLY)
#if !defined(_CATTACHED_HXX) && !defined(CATTACHED_MEMBERS_ONLY)
#define _CATTACHED_HXX
#endif /* !defined(_CATTACHED_HXX) && !defined(CATTACHED_MEMBERS_ONLY) */

#if !defined(CATTACHED_MEMBERS_ONLY)
#include "cattachedinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cAttached definition
 */
class c_INSTANCE_CLASS cAttached;

#undef CDB_CLASS
#define CDB_CLASS "cAttachedT"
/**
 **********************************************************************
 *  Class: cAttachedT
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
template
<class TDerives=cAttached,
 class TAttachedImplement=cAttachedImplement,
 class TAttachedInterface=cAttachedInterface,
 class TAttachedTo=PVOID,
 class TUnattached=INT,
 TUnattached VUnattached=0,
 class TBase=cBase,
 class TImplements=TAttachedImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cAttachedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cAttachedT cDerives;

/* include cAttached interface member definitions
 */
#define CATTACHEDINTERFACE_MEMBERS_ONLY
#include "cattachedinterface.hxx"
#undef CATTACHEDINTERFACE_MEMBERS_ONLY

    tAttachedTo m_attached;

    /**
     **********************************************************************
     * Constructor: cAttachedT
     *
     *      Author: $author$
     *        Date: 5/6/2009
     **********************************************************************
     */
    cAttachedT
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : m_attached(attached)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAttachedT
     *
     *     Author: $author$
     *       Date: 5/6/2009
     **********************************************************************
     */
    virtual ~cAttachedT()
    {
        eError error;
        if ((error = Detached()))
            throw(error);
    }
#else /* !defined(CATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CATTACHED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Detached
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Detached
    (bool onlyDetached=false,
     bool onlyAttached=false) 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CATTACHED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        tAttachedTo detached = Detached
        (error, onlyDetached, onlyAttached);
        return error;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Detached
     *
     *   Author: $author$
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual tAttachedTo Detached
    (eError& error, 
     bool onlyDetached=false, 
     bool onlyAttached=false) 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CATTACHED_MEMBER_FUNCS_INTERFACE */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
        tAttachedTo attached;

        error = e_ERROR_NONE;

        if ((tAttachedTo)(vUnattached) 
            != (attached = Attached()))
        {
            if (onlyDetached)
                error = e_ERROR_ALREADY_ATTACHED;
            else
            if (attached != (detached = Detach()))
                error = e_ERROR_NOT_ATTACHED;
        }
        else
        if (onlyAttached)
            error = e_ERROR_NOT_ATTACHED;

        return detached;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SelectAttached
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual tAttachedTo SelectAttached
    (tAttachedTo attached,
     bool onlyUnattached=false) 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CATTACHED_MEMBER_FUNCS_INTERFACE */
    {
        tAttachedTo prevAttached = Attached();
        Attach(attached, onlyUnattached);
#if !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return prevAttached;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 3/18/2009
     **********************************************************************
     */
    virtual tAttachedTo Attach
    (tAttachedTo attachedTo,
     bool onlyUnattached=false) 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = ((tAttachedTo)vUnattached);
#if !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) 
        if (!((attached = Attached()) && onlyUnattached))
        if (CanAttach())
            attached = (m_attached = attachedTo);
#else /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 3/18/2009
     **********************************************************************
     */
    virtual tAttachedTo Detach() 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = ((tAttachedTo)vUnattached);
#if !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) 
        if (CanDetach())
        {
            attached = m_attached;
            m_attached = ((tAttachedTo)vUnattached);
        }
#else /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CanAttach
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual bool CanAttach() const 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CATTACHED_MEMBER_FUNCS_INTERFACE */
    {
        bool can = true;
        return can;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CanDetach
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual bool CanDetach() const 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CATTACHED_MEMBER_FUNCS_INTERFACE */
    {
        bool can = true;
        return can;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 3/18/2009
     **********************************************************************
     */
    virtual tAttachedTo Attached() const 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) 
        tAttachedTo attached = m_attached;
#else /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        tAttachedTo attached = ((tAttachedTo)vUnattached);
#endif /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CATTACHED_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/6/2009
 **********************************************************************
 */
typedef cAttachedT
<cAttached, cAttachedImplement, 
 cAttachedInterface, cAttachedInterface*>
cAttachedExtends;
/**
 **********************************************************************
 *  Class: cAttached
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cAttached
: public cAttachedExtends
{
public:
    typedef cAttachedExtends cExtends;
    typedef cAttached cDerives;
    /**
     **********************************************************************
     * Constructor: cAttached
     *
     *      Author: $author$
     *        Date: 5/6/2009
     **********************************************************************
     */
    cAttached
    (tAttachedTo attachedTo=(tAttachedTo)(vUnattached)) 
    : cExtends(attachedTo) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CATTACHED_HXX) || defined(CATTACHED_MEMBERS_ONLY) */


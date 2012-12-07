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
 *   Date: 3/13/2009
 **********************************************************************
 */
#if !defined(_CATTACHED_HXX) || defined(CATTACHED_MEMBERS_ONLY)
#if !defined(_CATTACHED_HXX) && !defined(CATTACHED_MEMBERS_ONLY)
#define _CATTACHED_HXX
#endif /* !defined(_CATTACHED_HXX) && !defined(CATTACHED_MEMBERS_ONLY) */

#if !defined(CATTACHED_MEMBERS_ONLY)
#include "cattachedinterface.hxx"
#include "cbase.hxx"

/* cAttached definition
 */
class cAttached;

#undef CDB_CLASS
#define CDB_CLASS "cAttachedT"
/**
 **********************************************************************
 *  Class: cAttachedT
 *
 * Author: $author$
 *   Date: 3/13/2009
 **********************************************************************
 */
template
<class TDerives=cAttached,
 class TAttachedInterface=cAttachedInterface,
 class TAttachedImplement=cAttachedImplement,
 class TAttachedTo=PVOID,
 class TUnattached=INT,
 TUnattached VUnattached=100,
 class TBase=cBase,
 class TImplements=TAttachedImplement,
 class TExtends=TBase>
 
class cAttachedT
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
     *        Date: 3/13/2009
     **********************************************************************
     */
    cAttachedT
    (tAttachedTo attachedTo=vUnattached) 
    : m_attached(attachedTo)
    {
    }
#else /* !defined(CATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CATTACHED_MEMBERS_ONLY) */

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
#if !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) 
        tAttachedTo attached;
        if ((attached = Attached()) && onlyUnattached)
            attached = ((tAttachedTo)vUnattached);
        else
        attached = (m_attached = attachedTo);
#else /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        tAttachedTo attached = ((tAttachedTo)vUnattached);
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
    virtual tAttachedTo Detach
    (bool onlyAttached=false) 
#if defined(CATTACHED_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) 
        tAttachedTo attached = m_attached;
        m_attached = ((tAttachedTo)vUnattached);
#else /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        tAttachedTo attached = ((tAttachedTo)vUnattached);
#endif /* !defined(CATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
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
typedef cAttachedT<>
cAttachedExtends;
/**
 **********************************************************************
 *  Class: cAttached
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class cAttached
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
    (tAttachedTo attachedTo=vUnattached) 
    : cExtends(attachedTo) 
    {
    }
};
#else /* !defined(CATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CATTACHED_HXX) || defined(CATTACHED_MEMBERS_ONLY) */

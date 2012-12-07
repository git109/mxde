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
 *   File: cdelegated.hxx
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
#if !defined(_CDELEGATED_HXX) || defined(CDELEGATED_MEMBERS_ONLY)
#if !defined(_CDELEGATED_HXX) && !defined(CDELEGATED_MEMBERS_ONLY)
#define _CDELEGATED_HXX
#endif /* !defined(_CDELEGATED_HXX) && !defined(CDELEGATED_MEMBERS_ONLY) */

#if !defined(CDELEGATED_MEMBERS_ONLY)
#include "cdelegatedinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cDelegated;

#undef CDB_CLASS
#define CDB_CLASS "cDelegatedT"
/**
 **********************************************************************
 *  Class: cDelegatedT
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
template
<class TDerives=cDelegated,
 class TDelegatedImplement=cDelegatedImplement,
 class TDelegatedInterface=cDelegatedInterface,
 class TDelegated=TDelegatedInterface,
 class TBase=cInstanceBase,
 class TImplements=TDelegatedImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cDelegatedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cDelegatedT cDerives;
    typedef TDelegated tDelegated;

    tDelegated* m_delegated;

    /**
     **********************************************************************
     * Constructor: cDelegatedT
     *
     *      Author: $author$
     *        Date: 11/11/2010
     **********************************************************************
     */
    cDelegatedT
    (tDelegated* delegated=0) 
    : m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDelegatedT
     *
     *     Author: $author$
     *       Date: 11/11/2010
     **********************************************************************
     */
    virtual ~cDelegatedT()
    {
    }
#else /* !defined(CDELEGATED_MEMBERS_ONLY) */
#endif /* !defined(CDELEGATED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Delegate
     *
     *   Author: $author$
     *     Date: 11/11/2010
     **********************************************************************
     */
    virtual tDelegated* Delegate
    (tDelegated* delegated) 
#if defined(CDELEGATED_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CDELEGATED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDELEGATED_MEMBER_FUNCS_IMPLEMENT) 
        tDelegated* delegatedTo = (m_delegated = delegated);
#else /* !defined(CDELEGATED_MEMBER_FUNCS_IMPLEMENT) */
        tDelegated* delegatedTo = 0;
#endif /* !defined(CDELEGATED_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CDELEGATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 11/11/2010
     **********************************************************************
     */
    virtual tDelegated* Delegated
    (tDelegated* delegator) const 
#if defined(CDELEGATED_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CDELEGATED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDELEGATED_MEMBER_FUNCS_IMPLEMENT) 
        tDelegated* delegatedTo = m_delegated;
#else /* !defined(CDELEGATED_MEMBER_FUNCS_IMPLEMENT) */
        tDelegated* delegatedTo = 0;
#endif /* !defined(CDELEGATED_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CDELEGATED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CDELEGATED_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDelegatedExtends
 *
 *  Author: $author$
 *    Date: 11/11/2010
 **********************************************************************
 */
typedef cDelegatedT
<cDelegated>
cDelegatedExtends;
/**
 **********************************************************************
 *  Class: cDelegated
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
class cDelegated
: public cDelegatedExtends
{
public:
    typedef cDelegatedExtends cExtends;
    typedef cDelegated cDerives;
    /**
     **********************************************************************
     * Constructor: cDelegated
     *
     *      Author: $author$
     *        Date: 11/11/2010
     **********************************************************************
     */
    cDelegated
    (tDelegated* delegated=0) 
    : cExtends(delegated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDELEGATED_MEMBERS_ONLY) */
#endif /* !defined(CDELEGATED_MEMBERS_ONLY) */

#endif /* !defined(_CDELEGATED_HXX) || defined(CDELEGATED_MEMBERS_ONLY) */

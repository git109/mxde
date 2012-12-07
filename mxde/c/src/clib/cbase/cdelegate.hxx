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
 *   File: cdelegate.hxx
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
#if defined(CDELEGATE_MEMBER_FUNCS_ONLY) 
#if defined(_CDELEGATE_HXX) 
#define _CDELEGATE_HXX_OLD 
#undef _CDELEGATE_HXX
#endif /* defined(_CDELEGATE_HXX) */
#endif /* defined(CDELEGATE_MEMBER_FUNCS_ONLY) */

#ifndef _CDELEGATE_HXX
#define _CDELEGATE_HXX

#if !defined(CDELEGATE_MEMBER_FUNCS_ONLY) 
#include "cbase.hxx"
#include "cdelegateinterface.hxx"

class cDelegate;

#undef CDB_CLASS
#define CDB_CLASS "cDelegateT"
/**
 **********************************************************************
 *  Class: cDelegateT
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
template
<class TDerives=cDelegate,
 class TDelegated=cDelegateInterface,
 class TDelegateImplement=cDelegateImplement,
 class TBase=cBase,
 class TImplements=TDelegateImplement,
 class TExtends=TBase>
 
class cDelegateT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cDelegateT cDerives;
    typedef TDelegated tDelegated;

    tDelegated* m_delegated;

    /**
     **********************************************************************
     * Constructor: cDelegateT
     *
     *      Author: $author$
     *        Date: 3/1/2009
     **********************************************************************
     */
    cDelegateT
    (tDelegated* delegated=0) 
    : m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDelegateT
     *
     *     Author: $author$
     *       Date: 3/1/2009
     **********************************************************************
     */
    virtual ~cDelegateT()
    {
    }
#else /* !defined(CDELEGATE_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CDELEGATE_MEMBER_FUNCS_ONLY) */

    /**
     **********************************************************************
     * Function: SetDelegate
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tDelegated* SetDelegate
    (tDelegated* delegated) 
#if defined(CDELEGATE_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CDELEGATE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDELEGATE_MEMBER_FUNCS_IMPLEMENT) 
        tDelegated* delegatedTo = (m_delegated = delegated);
#else /* !defined(CDELEGATE_MEMBER_FUNCS_IMPLEMENT) */
        tDelegated* delegatedTo = 0;
#endif /* !defined(CDELEGATE_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CDELEGATE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 3/1/2009
     **********************************************************************
     */
    virtual tDelegated* GetDelegate
    (tDelegated* delegator) const 
#if defined(CDELEGATE_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CDELEGATE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDELEGATE_MEMBER_FUNCS_IMPLEMENT) 
        tDelegated* delegatedTo = m_delegated;
#else /* !defined(CDELEGATE_MEMBER_FUNCS_IMPLEMENT) */
        tDelegated* delegatedTo = 0;
#endif /* !defined(CDELEGATE_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CDELEGATE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CDELEGATE_MEMBER_FUNCS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDelegateExtends
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegateT
<cDelegate,cDelegateInterface,cDelegateImplement>
cDelegateExtends;
/**
 **********************************************************************
 *  Class: cDelegate
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class cDelegate
: public cDelegateExtends
{
public:
    typedef cDelegateExtends cExtends;
    typedef cDelegate cDerives;
    /**
     **********************************************************************
     * Constructor: cDelegate
     *
     *      Author: $author$
     *        Date: 3/1/2009
     **********************************************************************
     */
    cDelegate
    (tDelegated* delegated=0) 
    : cExtends(delegated)
    {
    }
};
#else /* !defined(CDELEGATE_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CDELEGATE_MEMBER_FUNCS_ONLY) */
#endif /* _CDELEGATE_HXX */

#if defined(CDELEGATE_MEMBER_FUNCS_ONLY) 
#if defined(_CDELEGATE_HXX_OLD) 
#define _CDELEGATE_HXX 
#undef _CDELEGATE_HXX_OLD
#endif /* defined(_CDELEGATE_HXX_OLD) */
#endif /* defined(CDELEGATE_MEMBER_FUNCS_ONLY) */

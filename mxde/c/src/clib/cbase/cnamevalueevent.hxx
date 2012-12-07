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
 *   File: cnamevalueevent.hxx
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
#if !defined(_CNAMEVALUEEVENT_HXX) || defined(CNAMEVALUEEVENT_MEMBERS_ONLY)
#if !defined(_CNAMEVALUEEVENT_HXX) && !defined(CNAMEVALUEEVENT_MEMBERS_ONLY)
#define _CNAMEVALUEEVENT_HXX
#endif /* !defined(_CNAMEVALUEEVENT_HXX) && !defined(CNAMEVALUEEVENT_MEMBERS_ONLY) */

#if !defined(CNAMEVALUEEVENT_MEMBERS_ONLY)
/* cNameValueEvent definition
 */
#include "cnamevalueeventinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cNameValueEvent;

#undef CDB_CLASS
#define CDB_CLASS "cNameValueEventT"
/**
 **********************************************************************
 *  Class: cNameValueEventT
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
template
<class TDerives=cNameValueEvent,
 class TNameValueEventImplement=cNameValueEventImplement,
 class TNameValueEventInterface=cNameValueEventInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cBase,
 class TImplements=TNameValueEventImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cNameValueEventT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cNameValueEvent interface member definitions
 */
#define CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY
#include "cnamevalueeventinterface.hxx"
#undef CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY

    tNameValueEventInterface* m_delegated;

    /**
     **********************************************************************
     * Constructor: cNameValueEventT
     *
     *      Author: $author$
     *        Date: 3/29/2009
     **********************************************************************
     */
    cNameValueEventT
    (tNameValueEventInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
#else /* !defined(CNAMEVALUEEVENT_MEMBERS_ONLY) */
#endif /* !defined(CNAMEVALUEEVENT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnNameValue
     *
     *   Author: $author$
     *     Date: 3/22/2009
     **********************************************************************
     */
    virtual eError OnNameValue
    (const tChar* name,
     const tChar* value=0) 
#if defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) */
        tNameValueEventInterface* delegated;
        if ((delegated = NameValueEventDelegate()))
            error = delegated->OnNameValue(name, value);
        return error;
    }
#endif /* defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DelegateNameValueEvent
     *
     *   Author: $author$
     *     Date: 3/29/2009
     **********************************************************************
     */
    virtual tNameValueEventInterface* DelegateNameValueEvent
    (tNameValueEventInterface* delegateTo) 
#if defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) 
        tNameValueEventInterface* delegated = (m_delegated);
        m_delegated = delegateTo;
#else /* !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) */
        tNameValueEventInterface* delegated = 0;
#endif /* !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NameValueEventDelegate
     *
     *   Author: $author$
     *     Date: 3/29/2009
     **********************************************************************
     */
    virtual tNameValueEventInterface* NameValueEventDelegate() const 
#if defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) 
        tNameValueEventInterface* delegated = m_delegated;
#else /* !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) */
        tNameValueEventInterface* delegated = 0;
#endif /* !defined(CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CNAMEVALUEEVENT_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cNameValueEventExtends
 *
 *  Author: $author$
 *    Date: 3/29/2009
 **********************************************************************
 */
typedef cNameValueEventT
<cNameValueEvent, cNameValueEventImplement, 
 cNameValueEventInterface, CHAR>
cNameValueEventExtends;
/**
 **********************************************************************
 *  Class: cNameValueEvent
 *
 * Author: $author$
 *   Date: 3/29/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cNameValueEvent
: public cNameValueEventExtends
{
public:
    typedef cNameValueEventExtends cExtends;
    typedef cNameValueEvent cDerives;
    /**
     **********************************************************************
     * Constructor: cNameValueEvent
     *
     *      Author: $author$
     *        Date: 3/29/2009
     **********************************************************************
     */
    cNameValueEvent
    (tNameValueEventInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CNAMEVALUEEVENT_MEMBERS_ONLY) */
#endif /* !defined(CNAMEVALUEEVENT_MEMBERS_ONLY) */

#endif /* !defined(_CNAMEVALUEEVENT_HXX) || defined(CNAMEVALUEEVENT_MEMBERS_ONLY) */

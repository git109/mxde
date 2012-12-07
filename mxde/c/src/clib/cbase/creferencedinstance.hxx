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
 *   File: creferencedinstance.hxx
 *
 * Author: $author$
 *   Date: 3/18/2010
 **********************************************************************
 */
#if !defined(_CREFERENCEDINSTANCE_HXX) || defined(CREFERENCEDINSTANCE_MEMBERS_ONLY)
#if !defined(_CREFERENCEDINSTANCE_HXX) && !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY)
#define _CREFERENCEDINSTANCE_HXX
#endif /* !defined(_CREFERENCEDINSTANCE_HXX) && !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY) */

#if !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY)
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cReferencedInstance;

#undef CDB_CLASS
#define CDB_CLASS "cReferencedInstanceT"
/**
 **********************************************************************
 *  Class: cReferencedInstanceT
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
template
<class TDerives=cReferencedInstance,
 class TBase=cBase,
 class TCount=INT,
 TCount VUnreferenced=-1,
 class TExtends=TBase>

class c_INSTANCE_CLASS cReferencedInstanceT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives tDerives;
    typedef TCount tCount;
    enum { vUnreferenced = VUnreferenced };

    TCount m_referenced;

    /**
     **********************************************************************
     *  Constructor: cReferencedInstanceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferencedInstanceT(TCount referenced = VUnreferenced) 
    : m_referenced(referenced)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cReferencedInstanceT
     *
     *      Author: $author$
     *        Date: 3/16/2010
     **********************************************************************
     */
    virtual ~cReferencedInstanceT()
    {
    }
#else /* !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY) */

#if !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: Referenced
     *
     *    Author: $author$
     *      Date: 3/16/2010
     **********************************************************************
     */
    virtual TCount Referenced() const
    {
        return m_referenced;
    }
    /**
     **********************************************************************
     *  Function: Increment
     *
     *    Author: $author$
     *      Date: 3/16/2010
     **********************************************************************
     */
    virtual TCount Increment()
    {
        if (0 <= m_referenced)
            return ++m_referenced;
        return m_referenced;
    }
    /**
     **********************************************************************
     *  Function: Decrement
     *
     *    Author: $author$
     *      Date: 3/16/2010
     **********************************************************************
     */
    virtual TCount Decrement()
    {
        if (0 < m_referenced)
            return --m_referenced;
        return m_referenced;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        eError error = DeleteThis();
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator == (tCount to) const
	{
		return (m_referenced == to);
	}
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator != (tCount to) const
	{
		return (m_referenced != to);
	}
    /**
     **********************************************************************
     * Function: operator !
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator ! () const
	{
		return (!m_referenced);
	}
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cReferencedInstanceExtend
 *
 *  Author: $author$
 *    Date: 3/16/2010
 **********************************************************************
 */
typedef cReferencedInstanceT
<cReferencedInstance, cBase>
cReferencedInstanceExtend;
/**
 **********************************************************************
 *  Class: cReferencedInstance
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cReferencedInstance
: public cReferencedInstanceExtend
{
public:
    typedef cReferencedInstanceExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cReferencedInstance
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferencedInstance
    (tCount referenced = vUnreferenced)
    : cExtends(referenced)
    {
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NONE;
        if (!m_referenced)
            delete this;
        else
        error = e_ERROR_NOT_ALLOWED;
        return error;
    }

    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    static tDerives* NewInstance(tCount referenced=0)
    {
        tDerives* instance = new tDerives(referenced);
        return instance;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCEDINSTANCE_MEMBERS_ONLY) */

#endif /* !defined(_CREFERENCEDINSTANCE_HXX) || defined(CREFERENCEDINSTANCE_MEMBERS_ONLY) */

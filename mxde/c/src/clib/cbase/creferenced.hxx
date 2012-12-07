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
 *   File: creferenced.hxx
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
#if !defined(_CREFERENCED_HXX) || defined(CREFERENCED_MEMBERS_ONLY)
#if !defined(_CREFERENCED_HXX) && !defined(CREFERENCED_MEMBERS_ONLY)
#define _CREFERENCED_HXX
#endif /* !defined(_CREFERENCED_HXX) && !defined(CREFERENCED_MEMBERS_ONLY) */

#if !defined(CREFERENCED_MEMBERS_ONLY)
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cReferencedT"
/**
 **********************************************************************
 *  Class: cReferencedT
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
template
<class TBase=cBase,
 class TCount=UINT,
 class TExtends=TBase>

class c_INSTANCE_CLASS cReferencedT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TCount tCount;

    TCount m_referenced;

    /**
     **********************************************************************
     *  Constructor: cReferencedT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferencedT(TCount referenced=0) 
    : m_referenced(referenced)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cReferencedT
     *
     *      Author: $author$
     *        Date: 3/16/2010
     **********************************************************************
     */
    virtual ~cReferencedT()
    {
    }
#else /* !defined(CREFERENCED_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCED_MEMBERS_ONLY) */

#if !defined(CREFERENCED_MEMBERS_ONLY)
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
    virtual cReferencedT Increment()
    {
        return cReferencedT(++m_referenced);
    }
    /**
     **********************************************************************
     *  Function: Decrement
     *
     *    Author: $author$
     *      Date: 3/16/2010
     **********************************************************************
     */
    virtual cReferencedT Decrement()
    {
        return cReferencedT(--m_referenced);
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
		return !operator == (to);
	}
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cReferencedExtend
 *
 *  Author: $author$
 *    Date: 3/16/2010
 **********************************************************************
 */
typedef cReferencedT<cBase>
cReferencedExtend;
/**
 **********************************************************************
 *  Class: cReferenced
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cReferenced
: public cReferencedExtend
{
public:
    typedef cReferencedExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cReferenced
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferenced
    (tCount referenced=0)
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
        delete this;
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
		return !operator == (to);
	}

    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    static cReferenced* NewInstance(tCount referenced=0)
    {
        cReferenced* instance = new cReferenced(referenced);
        return instance;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREFERENCED_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCED_MEMBERS_ONLY) */

#endif /* !defined(_CREFERENCED_HXX) || defined(CREFERENCED_MEMBERS_ONLY) */

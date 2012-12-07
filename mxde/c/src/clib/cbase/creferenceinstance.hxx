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
 *   File: creferenceinstance.hxx
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
#if !defined(_CREFERENCEINSTANCE_HXX) || defined(CREFERENCEINSTANCE_MEMBERS_ONLY)
#if !defined(_CREFERENCEINSTANCE_HXX) && !defined(CREFERENCEINSTANCE_MEMBERS_ONLY)
#define _CREFERENCEINSTANCE_HXX
#endif /* !defined(_CREFERENCEINSTANCE_HXX) && !defined(CREFERENCEINSTANCE_MEMBERS_ONLY) */

#if !defined(CREFERENCEINSTANCE_MEMBERS_ONLY)
#include "creferencedinstance.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cReferenceInstanceT"
/**
 **********************************************************************
 *  Class: cReferenceInstanceT
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
template
<class TReferenced=cReferencedInstance,
 class TBase=cBase,
 class TExtends=TBase>

class c_INSTANCE_CLASS cReferenceInstanceT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TReferenced tReferenced;

    TReferenced* m_referenced;

    /**
     **********************************************************************
     *  Constructor: cReferenceInstanceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferenceInstanceT
    (TReferenced* referenced=0) 
    : m_referenced(referenced)
    {
        if (m_referenced)
            m_referenced->Increment();
    }
    /**
     **********************************************************************
     *  Constructor: cReferenceInstanceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferenceInstanceT
    (const cReferenceInstanceT& reference) 
    : m_referenced(0)
    {
        if (reference.m_referenced != 0)
        {
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    /**
     **********************************************************************
     *  Constructor: cReferenceInstanceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    template <class TDerivedReferenced>
    cReferenceInstanceT
    (const cReferenceInstanceT<TDerivedReferenced>& reference) 
    : m_referenced(0)
    {
        if (reference.m_referenced != 0)
        {
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    /**
     **********************************************************************
     *  Destructor: ~cReferenceInstanceT
     *
     *      Author: $author$
     *        Date: 3/16/2010
     **********************************************************************
     */
    virtual ~cReferenceInstanceT()
    {
        eError error;
        if ((error = Clear()))
            throw(error);
    }
#else /* !defined(CREFERENCEINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCEINSTANCE_MEMBERS_ONLY) */

#if !defined(CREFERENCEINSTANCE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual int Compare(const void* to) const
    {
        int unequal = 0;
        if (((void*)(m_referenced) > to))
            unequal = 1;
        else
        if (((void*)(m_referenced) < to))
            unequal = -1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual int Compare(const cReferenceInstanceT& to) const
    {
        TReferenced* toReferenced = to.Referenced();
        int unequal = 0;
        if ((m_referenced > toReferenced))
            unequal = 1;
        else
        if ((m_referenced < toReferenced))
            unequal = -1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual eError Copy(const cReferenceInstanceT& reference) 
    {
        cReferenceInstanceT& thisReference = *this;
        TReferenced* referenced = reference.Referenced();
        eError error = e_ERROR_NONE;

        if (&reference != &thisReference)
        if (!(error = Clear()))
        if ((m_referenced = referenced))
            m_referenced->Increment();
        return error;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual eError Set(TReferenced* referenced) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = Clear()))
        if ((m_referenced = referenced))
            m_referenced->Increment();
        return error;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    virtual eError Clear() 
    {
        eError error = e_ERROR_NONE;

        if (m_referenced)
        {
            if ((m_referenced->Decrement()) == 0)
                error = m_referenced->DeleteInstance();
            m_referenced = 0;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Referenced
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    TReferenced* Referenced() const
    {
        return (TReferenced*)(m_referenced);
    }

    /**
     **********************************************************************
     * Function: operator =
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    cReferenceInstanceT& operator = (const cReferenceInstanceT& reference) 
    {
        cReferenceInstanceT& thisReference = *this;
        eError error;
        if ((error = Copy(reference)))
            throw(error);
        return thisReference;
    }

    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator == (const cReferenceInstanceT& to) const
	{
		return (!Compare(to));
	}
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator != (const cReferenceInstanceT& to) const
	{
		return (Compare(to)!=0);
	}

    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator == (const void* to) const
	{
		return (!Compare(to));
	}
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
	bool operator != (const void* to) const
	{
		return (Compare(to)!=0);
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
		return (!Referenced());
	}

    /**
     **********************************************************************
     * Function: operator ->
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    TReferenced* operator -> () const
    {
        return Referenced();
    }
    /**
     **********************************************************************
     * Function: operator *
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    TReferenced& operator * () const
    {
        TReferenced* referenced;

        if (!(referenced = Referenced()))
        {
            eError error = e_ERROR_NOT_ATTACHED;
            throw(error);
        }
        return *referenced;
    }
    /**
     **********************************************************************
     * Function: operator bool
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    operator bool () const
    {
        return (Referenced());
    }
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREFERENCEINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCEINSTANCE_MEMBERS_ONLY) */

#endif /* !defined(_CREFERENCEINSTANCE_HXX) || defined(CREFERENCEINSTANCE_MEMBERS_ONLY) */

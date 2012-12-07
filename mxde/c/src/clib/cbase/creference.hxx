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
 *   File: creference.hxx
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
#if !defined(_CREFERENCE_HXX) || defined(CREFERENCE_MEMBERS_ONLY)
#if !defined(_CREFERENCE_HXX) && !defined(CREFERENCE_MEMBERS_ONLY)
#define _CREFERENCE_HXX
#endif /* !defined(_CREFERENCE_HXX) && !defined(CREFERENCE_MEMBERS_ONLY) */

#if !defined(CREFERENCE_MEMBERS_ONLY)
#include "creferenced.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cReferenceT"
/**
 **********************************************************************
 *  Class: cReferenceT
 *
 * Author: $author$
 *   Date: 3/16/2010
 **********************************************************************
 */
template
<class TInstance,
 class TReferenced=cReferenced,
 class TBase=cBase,
 class TExtends=TBase>

class c_INSTANCE_CLASS cReferenceT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TInstance tInstance;
    typedef TReferenced tReferenced;

    TInstance* m_instance;
    TReferenced* m_referenced;

    /**
     **********************************************************************
     *  Constructor: cReferenceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferenceT
    (TInstance* instance=0) 
    : m_instance(instance),
      m_referenced(0)
    {
        if (m_instance)
            m_referenced = TReferenced::NewInstance(1);
    }
    /**
     **********************************************************************
     *  Constructor: cReferenceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    cReferenceT
    (const cReferenceT& reference) 
    : m_instance(0),
      m_referenced(0)
    {
        if (reference.m_referenced != 0)
        {
            m_instance = reference.m_instance;
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    /**
     **********************************************************************
     *  Constructor: cReferenceT
     *
     *       Author: $author$
     *         Date: 3/16/2010
     **********************************************************************
     */
    template <class TDerivedInstance>
    cReferenceT
    (const cReferenceT<TDerivedInstance>& reference) 
    : m_instance(0),
      m_referenced(0)
    {
        TInstance* instance;

        if ((instance = (TInstance*)(reference.operator->())) != 0)
        {
            m_instance = instance;
            m_referenced = reference.m_referenced;
            m_referenced->Increment();
        }
    }
    /**
     **********************************************************************
     *  Destructor: ~cReferenceT
     *
     *      Author: $author$
     *        Date: 3/16/2010
     **********************************************************************
     */
    virtual ~cReferenceT()
    {
        eError error;
        if ((error = Clear()))
            throw(error);
    }
#else /* !defined(CREFERENCE_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCE_MEMBERS_ONLY) */

#if !defined(CREFERENCE_MEMBERS_ONLY)
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
        if (((void*)(m_instance) > to))
            unequal = 1;
        else
        if (((void*)(m_instance) < to))
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
    virtual int Compare(const cReferenceT& to) const
    {
        int unequal = 0;
        if ((m_instance > to.m_instance))
            unequal = 1;
        else
        if ((m_instance < to.m_instance))
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
    virtual eError Copy(const cReferenceT& reference) 
    {
        eError error = e_ERROR_NONE;
        cReferenceT& thisReference = *this;

        if (&reference != &thisReference)
        if (!(error = Clear()))
        {
            if (reference.m_referenced)
            {
                m_instance = reference.m_instance;
                m_referenced = reference.m_referenced;
                m_referenced->Increment();
            }
        }
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
    virtual eError Set(TInstance* instance) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = Clear()))
        if ((m_instance = instance))
        if (!(m_referenced = TReferenced::NewInstance(1)))
        {
            m_instance = 0;
            error = e_ERROR_NEW;
        }
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
        eError error2;

        if (m_referenced)
        {
            if (m_instance)
            {
                if ((m_referenced->Decrement()) == 0)
                {
                    error = m_referenced->DeleteInstance();
                    if ((error2 = m_instance->DeleteInstance())
                        && !error)
                        error = error2;
                }
                m_instance = 0;
            }
            m_referenced = 0;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: operator =
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    cReferenceT& operator = (const cReferenceT& reference) 
    {
        cReferenceT& thisReference = *this;
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
	bool operator == (const cReferenceT& to) const
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
	bool operator != (const cReferenceT& to) const
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
     * Function: operator ->
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    TInstance* operator -> () const
    {
        return (TInstance*)(m_instance);
    }
    /**
     **********************************************************************
     * Function: operator *
     *
     *   Author: $author$
     *     Date: 3/16/2010
     **********************************************************************
     */
    TInstance& operator * () const
    {
        return (TInstance&)(*m_instance);
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
        return (0 != m_instance);
    }
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREFERENCE_MEMBERS_ONLY) */
#endif /* !defined(CREFERENCE_MEMBERS_ONLY) */

#endif /* !defined(_CREFERENCE_HXX) || defined(CREFERENCE_MEMBERS_ONLY) */

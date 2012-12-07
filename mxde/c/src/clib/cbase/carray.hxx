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
 *   File: carray.hxx
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
#if !defined(_CARRAY_HXX) || defined(CARRAY_MEMBERS_ONLY)
#if !defined(_CARRAY_HXX) && !defined(CARRAY_MEMBERS_ONLY)
#define _CARRAY_HXX
#endif /* !defined(_CARRAY_HXX) && !defined(CARRAY_MEMBERS_ONLY) */

#if !defined(CARRAY_MEMBERS_ONLY)
#include "carrayinterface.hxx"
#include "cinstancebase.hxx"

#define CARRAY_DEFAULT_SIZE 128

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cArray;

#undef CDB_CLASS
#define CDB_CLASS "cArrayT"
/**
 **********************************************************************
 *  Class: cArrayT
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
template
<class TDerives=cArray,
 class TArrayImplement=cArrayImplement,
 class TArrayInterface=cArrayInterface,
 class TWhat=CHAR,
 TSIZE VDefaultSize=CARRAY_DEFAULT_SIZE,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TArrayExtend=cInstanceBase,
 class TImplements=TArrayImplement,
 class TExtends=TArrayExtend>

class c_INSTANCE_CLASS cArrayT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cArray interface member definitions
 */
#define CARRAYINTERFACE_MEMBERS_ONLY
#include "carrayinterface.hxx"
#undef CARRAYINTERFACE_MEMBERS_ONLY

    enum { vDefaultSize = VDefaultSize };
    
    tWhat m_defaultElements[vDefaultSize];
    tWhat* m_elements;
    tSize m_elementsSize;
    tSize m_elementsLength;
    
    /**
     **********************************************************************
     *  Constructor: cArrayT
     *
     *       Author: $author$
     *         Date: 1/25/2010
     **********************************************************************
     */
    cArrayT
    (const tWhat* elements=0, 
     tSize elementsLength=0)
    : m_elements(m_defaultElements),
      m_elementsSize(vDefaultSize),
      m_elementsLength(0)
    {
        eError error;
        tLength count;
        if (elements)
        if (0 > (count = Copy(elements, elementsLength)))
            throw (error = -count);
    }
    /**
     **********************************************************************
     *  Destructor: ~cArrayT
     *
     *      Author: $author$
     *        Date: 1/25/2010
     **********************************************************************
     */
    virtual ~cArrayT()
    {
        if (m_elements)
        if (m_elements != m_defaultElements)
            delete m_elements;
    }
#else /* !defined(CARRAY_MEMBERS_ONLY) */
#endif /* !defined(CARRAY_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: QSort
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength QSort() 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = Length();
        if (0 < (count))
            QSort(0, count-1);
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength Copy
    (const tWhat* elements,
     tSize elementsLength) 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;

        if (!elements)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_elements)
            return -e_ERROR_NOT_ATTACHED;

        if (elementsLength < 1)
            return 0;

        if (m_elementsSize < elementsLength)
        if (0 >= (count = AdjustToSize(NewSize(elementsLength))))
            return count;
            
        count = (m_elementsLength = elementsLength);
        CopyElements(m_elements, elements, elementsLength);
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Elements
     *
     *   Author: $author$
     *     Date: 4/26/2010
     **********************************************************************
     */
    virtual tWhat* Elements() const 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
        tLength elementsSize = 0;
        tLength elementsLength = 0;
        tWhat* elements = Elements(elementsSize, elementsLength);
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return elements;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Elements
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tWhat* Elements
    (tLength& elementsSize, tLength& elementsLength) const 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tWhat* elements = (tWhat*)(m_elements);
        elementsSize = (m_elementsSize);
        elementsLength = (m_elementsLength);
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tWhat* elements = 0;
        elementsSize = (elementsLength = -e_ERROR_NOT_IMPLEMENTED);
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return elements;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength SetSize
    (tSize toSize) 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tLength size = (tLength)(m_elementsSize);
        if (toSize != m_elementsSize)
            size = (tLength)(AdjustToSize(NewSize(toSize)));
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tLength size = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Size
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength Size() const 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tLength size = (tLength)(m_elementsSize);
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tLength size = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetLength
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength SetLength
    (tLength toLength) 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tLength length = (tLength)(m_elementsLength);
        tSize toSize;
        
        if (!m_elements)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > toLength)
            toLength = (tLength)(vDefaultSize);
            
        if ((toSize = (tSize)(toLength)) > m_elementsSize)
        if (toLength > (length = SetSize(toSize)))
        if (0 > length)
            return length;
        else 
        return -e_ERROR_FULL;
        
        length = (m_elementsLength = toLength);
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tLength length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength Length() const 
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) 
        tLength length = (tLength)(m_elementsLength);
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        tLength length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */

#if !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: operator[]
     *
     *    Author: $author$
     *      Date: 11/20/2010
     **********************************************************************
     */
    virtual tWhat& operator[](tSize index) const
#if defined(CARRAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
    {
        tWhat& what = (tWhat&)(m_elements[index]);
        return what;
    }
#endif /* defined(CARRAY_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CARRAY_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CARRAY_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: QSort
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual void QSort
    (tSize iFirst, tSize iLast) 
    {
	    tSize iNext, iPrev;
    	
	    if (iFirst<iLast)
	    if (iLast-iFirst>1)
	    {
	        for (iNext=iFirst, iPrev=iLast-1; iNext<iPrev;)
	        {
	            for (;iNext<=iPrev; iNext++)
	            {
	                if (Compare(iNext, iLast)>0)
	                    break;
	            }
	            for (;iPrev>iNext; iPrev--)
	            {
	                if (Compare(iPrev,iLast)<0)
	                {
	                    Swap(iNext++, iPrev--);
	                    break;
	                }
	            }
	        }
	        if (iNext<iLast)
	        {
	            Swap(iNext, iLast);
	            QSort(iNext+1, iLast);
	        }
	        if (iNext > iFirst)
	            QSort(iFirst, iNext-1);
	    }
	    else 
	    if (Compare(iFirst, iLast)>0)
	        Swap(iFirst, iLast);
    }
    /**
     **********************************************************************
     * Function: Swap
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual void Swap
    (tSize iFirst, tSize iLast) 
    {
        tWhat temp = m_elements[iFirst];
        m_elements[iFirst] = m_elements[iLast];
        m_elements[iLast] = temp;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual int Compare
    (tSize iFirst, tSize iLast) const
    {
        int unequal = 0;
        return unequal;
    }
    
    /**
     **********************************************************************
     * Function: AdjustToSize
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength AdjustToSize(tSize size)
    {
        tLength length = -e_ERROR_FAILED;
        TWhat* elements;

        if (!m_elements)
            return -e_ERROR_NOT_ATTACHED;

        if (size <= m_elementsSize)
            /* elements is already big enough
             */
            return m_elementsSize;

        if (!(elements = new tWhat[size]))
            return -e_ERROR_NEW;

        if (m_elements)
        {
            if (m_elementsLength > 0)
                CopyElements(elements, m_elements, m_elementsLength);

            if (m_elements != m_defaultElements)
                delete m_elements;
        }

        m_elements = elements;
        m_elementsSize = size;
        return m_elementsSize;
    }
    /**
     **********************************************************************
     * Function: NewSize
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tSize NewSize(tSize size) const
    {
        /* Lets increase the buffer size by default buffer 
         * sized chunks. Note the desired new size is always
         * needed size + 1. The size in chunks is calculated
         * as (new size + (chunk size - 1)) / chunk size.
         * since new size = needed size + 1 then we have
         * chunks = (needed size + chunk size) / chunk size.
         * Finally we need bytes which is chunks * chunk size
         * which can be reduced to 
         * ((needed size / chunk size) + 1) * chunk size
         */
        size = ((size/vDefaultSize)+1)*vDefaultSize;
        return size;
    }
    /**
     **********************************************************************
     * Function: CopyElements
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual tLength CopyElements
    (tWhat* to, const tWhat* from, tSize size) const
    {
		tLength length;
        for (length = 0; size > 0; --size, length++)
            (*to++) = (*from++);
		return length;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cArrayExtend
 *
 *  Author: $author$
 *    Date: 1/25/2010
 **********************************************************************
 */
typedef cArrayT<>
cArrayExtend;
/**
 **********************************************************************
 *  Class: cArray
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cArray
: public cArrayExtend
{
public:
    typedef cArrayExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cArray
     *
     *       Author: $author$
     *         Date: 1/25/2010
     **********************************************************************
     */
    cArray
    (const tWhat* elements=0, 
     tSize elementsSize=0)
    : cExtends(m_defaultElements)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cArray
     *
     *      Author: $author$
     *        Date: 1/25/2010
     **********************************************************************
     */
    virtual ~cArray()
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/25/2010
     **********************************************************************
     */
    virtual int Compare
    (tSize iFirst, tSize iLast) const
    {
        int unequal = 0;
        if (m_elements[iFirst] > m_elements[iLast])
            unequal = 1;
        else
        if (m_elements[iFirst] < m_elements[iLast])
            unequal = -1;
        return unequal;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CARRAY_MEMBERS_ONLY) */
#endif /* !defined(CARRAY_MEMBERS_ONLY) */

#endif /* !defined(_CARRAY_HXX) || defined(CARRAY_MEMBERS_ONLY) */

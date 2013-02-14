///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosArray.hpp
///
/// Author: $author$
///   Date: 5/14/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSARRAY_HPP) || defined(XOSARRAYT_MEMBERS_ONLY)
#if !defined(_XOSARRAY_HPP) && !defined(XOSARRAYT_MEMBERS_ONLY)
#define _XOSARRAY_HPP
#endif // !defined(_XOSARRAY_HPP) && !defined(XOSARRAYT_MEMBERS_ONLY) 

#if !defined(XOSARRAYT_MEMBERS_ONLY)
#include "XosArrayInterface.hpp"
#include "XosExportBase.hpp"

#define XOSARRAY_DEFAULT_SIZE 128

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosArrayT"
///////////////////////////////////////////////////////////////////////
///  Class: XosArrayT
///
/// Author: $author$
///   Date: 5/14/2012
///////////////////////////////////////////////////////////////////////
template
<class TWhat,
 class TInterface,
 class TImplement,
 size_t VDefaultSize=XOSARRAY_DEFAULT_SIZE,
 class TExtend=XosExportBase>

class _EXPORT_CLASS XosArrayT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

// include XosArrayT interface member definitions
//
#define XOSARRAYINTERFACET_MEMBERS_ONLY
#include "XosArrayInterface.hpp"
#undef XOSARRAYINTERFACET_MEMBERS_ONLY

    typedef TInterface tInterface;
    enum { vDefaultSize = VDefaultSize };
    
    tWhat m_defaultElements[vDefaultSize];
    tWhat* m_elements;
    tSize m_elementsSize;
    tSize m_elementsLength;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosArrayT
    ///
    ///       Author: $author$
    ///         Date: 5/14/2012
    ///////////////////////////////////////////////////////////////////////
    XosArrayT()
    : m_elements(m_defaultElements),
      m_elementsSize(vDefaultSize),
      m_elementsLength(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosArrayT
    ///
    ///      Author: $author$
    ///        Date: 5/14/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosArrayT()
    {
        if (m_elements)
        if (m_elements != m_defaultElements)
            delete m_elements;
    }
#else // !defined(XOSARRAYT_MEMBERS_ONLY) 
#endif // !defined(XOSARRAYT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Copy
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Copy
    (const tWhat* elements,
     tSize elementsLength)
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        if (!elements)
            return -XOS_ERROR_NULL_PARAMETER;

        if (!m_elements)
            return -XOS_ERROR_NOT_ATTACHED;

        if (elementsLength < 1)
            return 0;

        if (m_elementsSize < elementsLength)
        if (0 >= (count = AdjustToSize(NewSize(elementsLength))))
            return count;
            
        count = (m_elementsLength = elementsLength);
        CopyElements(m_elements, elements, elementsLength);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Append
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Append
    (const tWhat* elements,
     tSize elementsLength)
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        tSize newElementsLength;

        if (!elements)
            return -XOS_ERROR_NULL_PARAMETER;

        if (!m_elements)
            return -XOS_ERROR_NOT_ATTACHED;

        if (elementsLength < 1)
            return 0;

        if (m_elementsSize < (newElementsLength = (m_elementsLength + elementsLength)))
        if (0 >= (count = AdjustToSize(NewSize(newElementsLength))))
            return count;
            
        CopyElements(m_elements+m_elementsLength, elements, elementsLength);
        m_elementsLength += (count = elementsLength);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Clear
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Clear()
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        count = m_elementsLength;
        if (m_elements)
        if (m_elements != m_defaultElements)
            delete m_elements;
        m_elements = m_defaultElements;
        m_elementsSize = vDefaultSize;
        m_elementsLength = 0;
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Elements
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tWhat* Elements() const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        tLength elementsSize = 0;
        tLength elementsLength = 0;
        tWhat* elements = Elements(elementsSize, elementsLength);
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return elements;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Elements
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tWhat* Elements
    (tLength& elementsLength) const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        tLength elementsSize = 0;
        tWhat* elements = Elements(elementsSize, elementsLength);
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return elements;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Elements
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tWhat* Elements
    (tLength& elementsSize,
     tLength& elementsLength) const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        tWhat* elements = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        elements = (tWhat*)(m_elements);
        elementsSize = (m_elementsSize);
        elementsLength = (m_elementsLength);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return elements;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetLength
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetLength
    (ssize_t toLength)
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t length = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        tSize toSize;

        length = (tLength)(m_elementsLength);
        
        if (!m_elements)
            return -XOS_ERROR_NOT_ATTACHED;

        if (0 > toLength)
            toLength = (tLength)(vDefaultSize);
            
        if ((toSize = (tSize)(toLength)) > m_elementsSize)
        if (toLength > (length = SetSize(toSize)))
        if (0 > length)
            return length;
        else 
        return -XOS_ERROR_FAILED;
        
        length = (m_elementsLength = toLength);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return length;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Length
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Length() const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t length = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        length = (tLength)(m_elementsLength);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return length;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetSize
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetSize
    (ssize_t toSize)
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t size = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        size = (tLength)(m_elementsSize);
        if (toSize != m_elementsSize)
            size = (tLength)(AdjustToSize(NewSize(toSize)));
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return size;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Size
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Size() const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t size = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        size = (tLength)(m_elementsSize);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return size;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator[]
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tWhat& operator[]
    (ssize_t index) const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    { return (tWhat&)(m_elements[index]); }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AdjustToSize
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t AdjustToSize(size_t size)
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        TWhat* elements;

        if (!m_elements)
            return -XOS_ERROR_NOT_ATTACHED;

        if (size <= m_elementsSize)
            // elements is already big enough
            //
            return m_elementsSize;

        if (!(elements = new tWhat[size]))
            return -XOS_ERROR_NEW;

        if (m_elements)
        {
            if (m_elementsLength > 0)
                CopyElements(elements, m_elements, m_elementsLength);

            if (m_elements != m_defaultElements)
                delete m_elements;
        }

        m_elements = elements;
        m_elementsSize = size;
        count = (tLength)(m_elementsSize);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: NewSize
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual size_t NewSize(tSize size) const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        size_t count = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        // Lets increase the buffer size by default buffer 
        // sized chunks. Note the desired new size is always
        // needed size + 1. The size in chunks is calculated
        // as (new size + (chunk size - 1)) / chunk size.
        // since new size = needed size + 1 then we have
        // chunks = (needed size + chunk size) / chunk size.
        // Finally we need bytes which is chunks * chunk size
        // which can be reduced to 
        // ((needed size / chunk size) + 1) * chunk size
        //
        count = (size = ((size/vDefaultSize)+1)*vDefaultSize);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: CopyElements
    ///
    ///    Author: $author$
    ///      Date: 8/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t CopyElements
    (tWhat* to, const tWhat* from, tSize size) const
#if defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT)
        if ((to) && (from))
        for (count = 0; size > 0; --size, count++)
            (*to++) = (*from++);
#else // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSARRAYT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSARRAYT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSARRAYT_MEMBERS_ONLY)
};
#undef CDB_CLASS

typedef XosArrayInterfaceT<TCHAR> XosTCHARArrayInterface;
typedef XosArrayImplementT<TCHAR, XosTCHARArrayInterface> XosTCHARArrayImplement;
typedef XosArrayT<TCHAR, XosTCHARArrayInterface, XosTCHARArrayImplement> XosTCHARArray;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSARRAYT_MEMBERS_ONLY) 
#endif // !defined(XOSARRAYT_MEMBERS_ONLY) 

#endif // !defined(_XOSARRAY_HPP) || defined(XOSARRAYT_MEMBERS_ONLY) 
        


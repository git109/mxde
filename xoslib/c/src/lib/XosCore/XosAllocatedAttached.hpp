///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
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
///   File: XosAllocatedAttached.hpp
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSALLOCATEDATTACHED_HPP) || defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY)
#if !defined(_XOSALLOCATEDATTACHED_HPP) && !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY)
#define _XOSALLOCATEDATTACHED_HPP
#endif // !defined(_XOSALLOCATEDATTACHED_HPP) && !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY) 

#if !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY)
#include "XosAllocatedAttachedInterface.hpp"
#include "XosAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosAllocatedAttachedT"
///////////////////////////////////////////////////////////////////////
///  Class: XosAllocatedAttachedT
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosAttachedInterfaceT
 <TAttachedTo, TUnattached, VUnattached, XosInterfaceBase>,
 class TExtend=XosAttachedT
 <TAttachedTo, TUnattached, VUnattached, XosExportBase> >

class c_EXPORT_CLASS XosAllocatedAttachedT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

    bool m_isAllocated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosAllocatedAttachedT
    ///
    ///       Author: $author$
    ///         Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosAllocatedAttachedT
    (tAttachedTo attached=vUnattached,
     bool isAllocated=false)
    : Extends(attached),
      m_isAllocated(isAllocated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosAllocatedAttachedT
    ///
    ///      Author: $author$
    ///        Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosAllocatedAttachedT()
    {
    }
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (tAttachedTo attached,
     bool isAllocated=false)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        this->m_attached = attached;
        m_isAllocated = isAllocated;
    return this->m_attached;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach(bool& isAllocated)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = this->m_attached;
        this->m_attached = vUnattached;
        isAllocated = m_isAllocated;
        m_isAllocated = false;
        return detached;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach()
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = this->m_attached;
        this->m_attached = vUnattached;
        m_isAllocated = false;
        return detached;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetIsAllocated
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsAllocated
    (bool isTrue=true)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        m_isAllocated = isTrue;
        return m_isAllocated;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return false;
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetIsAllocated
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsAllocated() const
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        return m_isAllocated;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return false;
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Allocate
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Allocate
    (tAttachedTo detached,
     bool onlyFreed=false)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        if (!(this->m_attached != vUnattached))
        if ((onlyFreed))
            return error = XOS_ERROR_FAILED;
        if ((m_isAllocated = ((this->m_attached = detached) != vUnattached)))
            error = XOS_ERROR_NONE;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Free
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Free(bool onlyAllocated=false)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        this->m_attached = vUnattached;
        m_isAllocated = false;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Freed
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Freed(bool onlyFreed=false)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        if ((vUnattached != this->m_attached))
        if ((onlyFreed))
            return error = XOS_ERROR_FAILED;
        else
        if ((m_isAllocated))
            error = Free();
        this->m_attached = vUnattached;
        m_isAllocated = false;
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsAllocate
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsAllocate
    (tAttachedTo detached,
     bool onlyFreed=false)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isSuccess = false;
        XosError error;
        isSuccess = !(error = Allocate(detached, onlyFreed));
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isSuccess;
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsFree
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsFree
    (bool onlyAllocated=false)
#if defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isSuccess = false;
        XosError error;
        isSuccess = !(error = Free(onlyAllocated));
#if !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isSuccess;
    }
#endif // defined(XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY) 

#endif // !defined(_XOSALLOCATEDATTACHED_HPP) || defined(XOSALLOCATEDATTACHEDT_MEMBERS_ONLY) 

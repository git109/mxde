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
///   File: XosCreatedAttached.hpp
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSCREATEDATTACHED_HPP) || defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY)
#if !defined(_XOSCREATEDATTACHED_HPP) && !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY)
#define _XOSCREATEDATTACHED_HPP
#endif // !defined(_XOSCREATEDATTACHED_HPP) && !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY) 

#if !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY)
#include "XosCreatedAttachedInterface.hpp"
#include "XosAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosCreatedAttachedT"
///////////////////////////////////////////////////////////////////////
///  Class: XosCreatedAttachedT
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosAttachedInterfaceT
 <TAttachedTo, TUnattached, VUnattached, XosInterfaceBase>,
 class TExtend=XosAttachedT
 <TAttachedTo, TUnattached, VUnattached, XosExportBase> >

class c_EXPORT_CLASS XosCreatedAttachedT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

    bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosCreatedAttachedT
    ///
    ///       Author: $author$
    ///         Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    XosCreatedAttachedT
    (tAttachedTo attached=vUnattached,
     bool isCreated=false)
    : Extends(attached),
      m_isCreated(isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosCreatedAttachedT
    ///
    ///      Author: $author$
    ///        Date: 11/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosCreatedAttachedT()
    {
    }
#else // !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (tAttachedTo attached,
     bool isCreated=false)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        this->m_attached = attached;
        m_isCreated = isCreated;
    return this->m_attached;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach(bool& isCreated)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = this->m_attached;
        this->m_attached = vUnattached;
        isCreated = m_isCreated;
        m_isCreated = false;
        return detached;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach()
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = this->m_attached;
        this->m_attached = vUnattached;
        m_isCreated = false;
        return detached;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetIsCreated
    ///
    ///    Author: $author$
    ///      Date: 11/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated
    (bool isTrue=true)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        m_isCreated = isTrue;
        return m_isCreated;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return false;
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetIsCreated
    ///
    ///    Author: $author$
    ///      Date: 11/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCreated() const
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        return m_isCreated;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return false;
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (tAttachedTo detached,
     bool onlyDestroyed=false)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        if (!(this->m_attached != vUnattached))
        if ((onlyDestroyed))
            return error = XOS_ERROR_FAILED;
        if ((m_isCreated = ((this->m_attached = detached) != vUnattached)))
            error = XOS_ERROR_NONE;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 11/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy(bool onlyCreated=false)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        this->m_attached = vUnattached;
        m_isCreated = false;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroyed
    ///
    ///    Author: $author$
    ///      Date: 11/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroyed(bool onlyDestroyed=false)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        if ((vUnattached != this->m_attached))
        if ((onlyDestroyed))
            return error = XOS_ERROR_FAILED;
        else
        if ((m_isCreated))
            error = Destroy();
        this->m_attached = vUnattached;
        m_isCreated = false;
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsCreate
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsCreate
    (tAttachedTo detached,
     bool onlyDestroyed=false)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isSuccess = false;
        XosError error;
        isSuccess = !(error = Create(detached, onlyDestroyed));
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isSuccess;
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsDestroy
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsDestroy
    (bool onlyCreated=false)
#if defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isSuccess = false;
        XosError error;
        isSuccess = !(error = Destroy(onlyCreated));
#if !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isSuccess;
    }
#endif // defined(XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY) 

#endif // !defined(_XOSCREATEDATTACHED_HPP) || defined(XOSCREATEDATTACHEDT_MEMBERS_ONLY) 

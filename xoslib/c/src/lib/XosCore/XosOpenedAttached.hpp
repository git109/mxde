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
///   File: XosOpenedAttached.hpp
///
/// Author: $author$
///   Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSOPENEDATTACHED_HPP) || defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY)
#if !defined(_XOSOPENEDATTACHED_HPP) && !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY)
#define _XOSOPENEDATTACHED_HPP
#endif // !defined(_XOSOPENEDATTACHED_HPP) && !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY) 

#if !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY)
#include "XosOpenedAttachedInterface.hpp"
#include "XosAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosOpenedAttachedT"
///////////////////////////////////////////////////////////////////////
///  Class: XosOpenedAttachedT
///
/// Author: $author$
///   Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosAttachedInterfaceT
 <TAttachedTo, TUnattached, VUnattached, XosInterfaceBase>,
 class TExtend=XosAttachedT
 <TAttachedTo, TUnattached, VUnattached, XosExportBase> >

class c_EXPORT_CLASS XosOpenedAttachedT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosOpenedAttachedT
    ///
    ///       Author: $author$
    ///         Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    XosOpenedAttachedT
    (tAttachedTo attached=vUnattached,
     bool isOpen=false)
    : Extends(attached),
      m_isOpen(isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosOpenedAttachedT
    ///
    ///      Author: $author$
    ///        Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosOpenedAttachedT()
    {
    }
#else // !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (tAttachedTo attached,
     bool isOpen=false)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        this->m_attached = attached;
        m_isOpen = isOpen;
    return this->m_attached;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach(bool& isOpen)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = this->m_attached;
        this->m_attached = vUnattached;
        isOpen = m_isOpen;
        m_isOpen = false;
        return detached;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach()
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = this->m_attached;
        this->m_attached = vUnattached;
        m_isOpen = false;
        return detached;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetIsOpen
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen
    (bool isTrue=true)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        m_isOpen = isTrue;
        return m_isOpen;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return false;
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetIsOpen
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOpen() const
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        return m_isOpen;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return false;
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (tAttachedTo detached,
     bool onlyClosed=false)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        if (!(this->m_attached != vUnattached))
        if ((onlyClosed))
            return error = XOS_ERROR_FAILED;
        if ((m_isOpen = ((this->m_attached = detached) != vUnattached)))
            error = XOS_ERROR_NONE;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close(bool onlyOpened=false)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        this->m_attached = vUnattached;
        m_isOpen = false;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Closed
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Closed(bool onlyClosed=false)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        if ((vUnattached != this->m_attached))
        if ((onlyClosed))
            return error = XOS_ERROR_FAILED;
        else
        if ((m_isOpen))
            error = Close();
        this->m_attached = vUnattached;
        m_isOpen = false;
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsOpen
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsOpen
    (tAttachedTo detached,
     bool onlyClosed=false)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isSuccess = false;
        XosError error;
        isSuccess = !(error = Open(detached, onlyClosed));
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isSuccess;
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsDestroy
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsDestroy
    (bool onlyOpened=false)
#if defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isSuccess = false;
        XosError error;
        isSuccess = !(error = Close(onlyOpened));
#if !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return isSuccess;
    }
#endif // defined(XOSOPENEDATTACHEDT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY) 

#endif // !defined(_XOSOPENEDATTACHED_HPP) || defined(XOSOPENEDATTACHEDT_MEMBERS_ONLY) 

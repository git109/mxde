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
///   File: XosAttached.hpp
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSATTACHED_HPP) || defined(XOSATTACHEDT_MEMBERS_ONLY)
#if !defined(_XOSATTACHED_HPP) && !defined(XOSATTACHEDT_MEMBERS_ONLY)
#define _XOSATTACHED_HPP
#endif // !defined(_XOSATTACHED_HPP) && !defined(XOSATTACHEDT_MEMBERS_ONLY) 

#if !defined(XOSATTACHEDT_MEMBERS_ONLY)
#include "XosAttachedInterface.hpp"
#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosAttachedT"
///////////////////////////////////////////////////////////////////////
///  Class: XosAttachedT
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosInterfaceBase,
 class TExtend=XosExportBase>

class c_EXPORT_CLASS XosAttachedT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

    tAttachedTo m_attached;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosAttachedT
    ///
    ///       Author: $author$
    ///         Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    XosAttachedT
    (tAttachedTo attached=vUnattached)
    : m_attached(attached)
    {
    }
#else // !defined(XOSATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSATTACHEDT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (tAttachedTo attached)
#if defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        m_attached = attached;
        return m_attached;
#else // !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach()
#if defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo detached = m_attached;
        return detached;
#else // !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attached
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attached() const
#if defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT)
        return m_attached;
#else // !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
        return vUnattached;
#endif // !defined(XOSATTACHEDT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSATTACHEDT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSATTACHEDT_MEMBERS_ONLY)
};
#undef CDB_CLASS


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSATTACHEDT_MEMBERS_ONLY) 
#endif // !defined(XOSATTACHEDT_MEMBERS_ONLY) 

#endif // !defined(_XOSATTACHED_HPP) || defined(XOSATTACHEDT_MEMBERS_ONLY) 
        


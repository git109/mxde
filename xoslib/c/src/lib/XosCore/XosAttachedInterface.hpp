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
///   File: XosAttachedInterface.hpp
///
/// Author: $author$
///   Date: 11/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSATTACHEDINTERFACE_HPP) || defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY)
#if !defined(_XOSATTACHEDINTERFACE_HPP) && !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY)
#define _XOSATTACHEDINTERFACE_HPP
#endif // !defined(_XOSATTACHEDINTERFACE_HPP) && !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY) 

#if !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY)
#include "XosInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS XosAttachedInterface;

#undef CDB_CLASS
#define CDB_CLASS "XosAttachedInterfaceT"
///////////////////////////////////////////////////////////////////////
///  Class: XosAttachedInterfaceT
///
/// Author: $author$
///   Date: 11/24/2011
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosInterfaceBase>

class c_INTERFACE_CLASS XosAttachedInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement Implements;
#else // !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY) 

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

#if !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY)
// include XosAttachedT member functions interface
//
#define XOSATTACHEDT_MEMBERS_ONLY
#define XOSATTACHEDT_MEMBER_FUNCS_INTERFACE
#include "XosAttached.hpp"
#undef XOSATTACHEDT_MEMBER_FUNCS_INTERFACE
#undef XOSATTACHEDT_MEMBERS_ONLY
};
#undef CDB_CLASS


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_XOSATTACHEDINTERFACE_HPP) || defined(XOSATTACHEDINTERFACET_MEMBERS_ONLY) 
        


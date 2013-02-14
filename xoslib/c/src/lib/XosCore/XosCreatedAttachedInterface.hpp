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
///   File: XosCreatedAttachedInterface.hpp
///
/// Author: $author$
///   Date: 11/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSCREATEDATTACHEDINTERFACE_HPP) || defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY)
#if !defined(_XOSCREATEDATTACHEDINTERFACE_HPP) && !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY)
#define _XOSCREATEDATTACHEDINTERFACE_HPP
#endif // !defined(_XOSCREATEDATTACHEDINTERFACE_HPP) && !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY) 

#if !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY)
#include "XosAttachedInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosCreatedAttachedInterfaceT"
///////////////////////////////////////////////////////////////////////
///  Class: XosCreatedAttachedInterfaceT
///
/// Author: $author$
///   Date: 11/24/2011
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosAttachedInterfaceT
 <TAttachedTo, TUnattached, VUnattached, XosInterfaceBase> >

class c_INTERFACE_CLASS XosCreatedAttachedInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement Implements;
#else // !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY) 

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

#if !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY)
// include XosCreatedAttachedT member functions interface
//
#define XOSCREATEDATTACHEDT_MEMBERS_ONLY
#define XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE
#include "XosCreatedAttached.hpp"
#undef XOSCREATEDATTACHEDT_MEMBER_FUNCS_INTERFACE
#undef XOSCREATEDATTACHEDT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_XOSCREATEDATTACHEDINTERFACE_HPP) || defined(XOSCREATEDATTACHEDINTERFACET_MEMBERS_ONLY) 
        


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
///   File: XosAllocatedAttachedInterface.hpp
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSALLOCATEDATTACHEDINTERFACE_HPP) || defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY)
#if !defined(_XOSALLOCATEDATTACHEDINTERFACE_HPP) && !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY)
#define _XOSALLOCATEDATTACHEDINTERFACE_HPP
#endif // !defined(_XOSALLOCATEDATTACHEDINTERFACE_HPP) && !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY) 

#if !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY)
#include "XosAttachedInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosAllocatedAttachedInterfaceT"
///////////////////////////////////////////////////////////////////////
///  Class: XosAllocatedAttachedInterfaceT
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
template
<class TAttachedTo,
 class TUnattached,
 TUnattached VUnattached,
 class TImplement=XosAttachedInterfaceT
 <TAttachedTo, TUnattached, VUnattached, XosInterfaceBase> >

class c_INTERFACE_CLASS XosAllocatedAttachedInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement Implements;
#else // !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY) 

    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    static const tUnattached vUnattached = VUnattached;

#if !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY)
// include XosAllocatedAttachedT member functions interface
//
#define XOSALLOCATEDATTACHEDT_MEMBERS_ONLY
#define XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE
#include "XosAllocatedAttached.hpp"
#undef XOSALLOCATEDATTACHEDT_MEMBER_FUNCS_INTERFACE
#undef XOSALLOCATEDATTACHEDT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_XOSALLOCATEDATTACHEDINTERFACE_HPP) || defined(XOSALLOCATEDATTACHEDINTERFACET_MEMBERS_ONLY) 
        


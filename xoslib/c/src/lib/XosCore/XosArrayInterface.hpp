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
///   File: XosArrayInterface.hpp
///
/// Author: $author$
///   Date: 5/14/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSARRAYINTERFACE_HPP) || defined(XOSARRAYINTERFACET_MEMBERS_ONLY)
#if !defined(_XOSARRAYINTERFACE_HPP) && !defined(XOSARRAYINTERFACET_MEMBERS_ONLY)
#define _XOSARRAYINTERFACE_HPP
#endif // !defined(_XOSARRAYINTERFACE_HPP) && !defined(XOSARRAYINTERFACET_MEMBERS_ONLY) 

#if !defined(XOSARRAYINTERFACET_MEMBERS_ONLY)
#include "XosInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "XosArrayInterfaceT"
///////////////////////////////////////////////////////////////////////
///  Class: XosArrayInterfaceT
///
/// Author: $author$
///   Date: 5/14/2012
///////////////////////////////////////////////////////////////////////
template
<class TWhat,
 class TImplement=XosInterfaceBase>

class _INTERFACE_CLASS XosArrayInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement Implements;
#else // !defined(XOSARRAYINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSARRAYINTERFACET_MEMBERS_ONLY) 

    typedef TWhat tWhat;
    typedef ssize_t tLength;
    typedef size_t tSize;

#if !defined(XOSARRAYINTERFACET_MEMBERS_ONLY)
// include XosArrayT member functions interface
//
#define XOSARRAYT_MEMBERS_ONLY
#define XOSARRAYT_MEMBER_FUNCS_INTERFACE
#include "XosArray.hpp"
#undef XOSARRAYT_MEMBER_FUNCS_INTERFACE
#undef XOSARRAYT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(XOSARRAYIMPLEMENTT_MEMBERS_ONLY)
#undef CDB_CLASS
#define CDB_CLASS "XosArrayImplementT"
///////////////////////////////////////////////////////////////////////
///  Class: XosArrayImplementT
///
/// Author: $author$
///   Date: 5/14/2012
///////////////////////////////////////////////////////////////////////
template
<class TWhat,
 class TImplement>

class _IMPLEMENT_CLASS XosArrayImplementT
: virtual public TImplement
{
public:
    typedef TImplement Implements;
#else // !defined(XOSARRAYIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(XOSARRAYIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(XOSARRAYIMPLEMENTT_MEMBERS_ONLY)
// include XosArrayT interface member definitions
//
#define XOSARRAYINTERFACET_MEMBERS_ONLY
#include "XosArrayInterface.hpp"
#undef XOSARRAYINTERFACET_MEMBERS_ONLY

// include XosArrayT member functions implement
//
#define XOSARRAYT_MEMBERS_ONLY
#define XOSARRAYT_MEMBER_FUNCS_IMPLEMENT
#include "XosArray.hpp"
#undef XOSARRAYT_MEMBER_FUNCS_IMPLEMENT
#undef XOSARRAYT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(XOSARRAYIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(XOSARRAYIMPLEMENTT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSARRAYINTERFACET_MEMBERS_ONLY) 
#endif // !defined(XOSARRAYINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_XOSARRAYINTERFACE_HPP) || defined(XOSARRAYINTERFACET_MEMBERS_ONLY) 
        


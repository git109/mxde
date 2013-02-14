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
///   File: XosLibPngReaderEventsInterface.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGREADEREVENTSINTERFACE_HPP) || defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGREADEREVENTSINTERFACE_HPP) && !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _XOSLIBPNGREADEREVENTSINTERFACE_HPP
#endif // !defined(_XOSLIBPNGREADEREVENTSINTERFACE_HPP) && !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "XosLibPngInterfaceBase.hpp"
#include "XosPixel.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngReaderEventsInterfaceImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngInterfaceBase
XosLibPngReaderEventsInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngReaderEventsInterface
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosLibPngReaderEventsInterface
: virtual public XosLibPngReaderEventsInterfaceImplement
{
public:
    typedef XosLibPngReaderEventsInterfaceImplement Implements;
#else // !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
// include XosLibPngReaderEvents member functions interface
//
#define XOSLIBPNGREADEREVENTS_MEMBERS_ONLY
#define XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "XosLibPngReaderEvents.hpp"
#undef XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef XOSLIBPNGREADEREVENTS_MEMBERS_ONLY
};

#if !defined(XOSLIBPNGREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngReaderEventsImplement
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS XosLibPngReaderEventsImplement
: virtual public XosLibPngReaderEventsInterface
{
public:
    typedef XosLibPngReaderEventsInterface Implements;
#else // !defined(XOSLIBPNGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
// include XosLibPngReaderEvents member functions implement
//
#define XOSLIBPNGREADEREVENTS_MEMBERS_ONLY
#define XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "XosLibPngReaderEvents.hpp"
#undef XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef XOSLIBPNGREADEREVENTS_MEMBERS_ONLY
};
#else // !defined(XOSLIBPNGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGREADEREVENTSINTERFACE_HPP) || defined(XOSLIBPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) 
        


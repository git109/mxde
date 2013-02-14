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
///   File: XosLibPngInfoReaderInterface.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGINFOREADERINTERFACE_HPP) || defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGINFOREADERINTERFACE_HPP) && !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY)
#define _XOSLIBPNGINFOREADERINTERFACE_HPP
#endif // !defined(_XOSLIBPNGINFOREADERINTERFACE_HPP) && !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY)
#include "XosLibPngInfoInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class _EXPORT_CLASS XosLibPngInfoReader;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoReaderInterfaceImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngInfoInterface
XosLibPngInfoReaderInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfoReaderInterface
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosLibPngInfoReaderInterface
: virtual public XosLibPngInfoReaderInterfaceImplement
{
public:
    typedef XosLibPngInfoReaderInterfaceImplement Implements;
#else // !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY)
// include XosLibPngInfoReader member functions interface
//
#define XOSLIBPNGINFOREADER_MEMBERS_ONLY
#define XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE
#include "XosLibPngInfoReader.hpp"
#undef XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE
#undef XOSLIBPNGINFOREADER_MEMBERS_ONLY
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGINFOREADERINTERFACE_HPP) || defined(XOSLIBPNGINFOREADERINTERFACE_MEMBERS_ONLY) 
        


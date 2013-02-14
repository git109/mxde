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
///   File: XosLibPngInfoInterface.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGINFOINTERFACE_HPP) || defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGINFOINTERFACE_HPP) && !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY)
#define _XOSLIBPNGINFOINTERFACE_HPP
#endif // !defined(_XOSLIBPNGINFOINTERFACE_HPP) && !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY)
#include "XosLibPngInterfaceBase.hpp"
#include "XosCreatedAttachedInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoAttachedInterfaceImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<png_infop, int, 0, XosLibPngInterfaceBase>
XosLibPngInfoAttachedInterfaceImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoAttachedInterface
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<png_infop, int, 0, XosLibPngInfoAttachedInterfaceImplement>
XosLibPngInfoAttachedInterface;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoInterfaceImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngInfoAttachedInterface
XosLibPngInfoInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfoInterface
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosLibPngInfoInterface
: virtual public XosLibPngInfoInterfaceImplement
{
public:
    typedef XosLibPngInfoInterfaceImplement Implements;
#else // !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY)
// include XosLibPngInfo member functions interface
//
#define XOSLIBPNGINFO_MEMBERS_ONLY
#define XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE
#include "XosLibPngInfo.hpp"
#undef XOSLIBPNGINFO_MEMBER_FUNCS_INTERFACE
#undef XOSLIBPNGINFO_MEMBERS_ONLY
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGINFOINTERFACE_HPP) || defined(XOSLIBPNGINFOINTERFACE_MEMBERS_ONLY) 
        


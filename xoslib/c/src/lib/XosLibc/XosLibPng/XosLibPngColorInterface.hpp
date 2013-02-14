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
///   File: XosLibPngColorInterface.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGCOLORINTERFACE_HPP) || defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGCOLORINTERFACE_HPP) && !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY)
#define _XOSLIBPNGCOLORINTERFACE_HPP
#endif // !defined(_XOSLIBPNGCOLORINTERFACE_HPP) && !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY)
#include "XosLibPngColorAttached.hpp"
#include "XosLibPngInfoInterface.hpp"
#include "XosLibPngStructInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngColorInterfaceImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngColorAttachedInterface
XosLibPngColorInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngColorInterface
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosLibPngColorInterface
: virtual public XosLibPngColorInterfaceImplement
{
public:
    typedef XosLibPngColorInterfaceImplement Implements;
#else // !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY)
// include XosLibPngColor member functions interface
//
#define XOSLIBPNGCOLOR_MEMBERS_ONLY
#define XOSLIBPNGCOLOR_MEMBER_FUNCS_INTERFACE
#include "XosLibPngColor.hpp"
#undef XOSLIBPNGCOLOR_MEMBER_FUNCS_INTERFACE
#undef XOSLIBPNGCOLOR_MEMBERS_ONLY
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGCOLORINTERFACE_HPP) || defined(XOSLIBPNGCOLORINTERFACE_MEMBERS_ONLY) 
        


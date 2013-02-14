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
///   File: XosLibPngStructInterface.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGSTRUCTINTERFACE_HPP) || defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGSTRUCTINTERFACE_HPP) && !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY)
#define _XOSLIBPNGSTRUCTINTERFACE_HPP
#endif // !defined(_XOSLIBPNGSTRUCTINTERFACE_HPP) && !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY)
#include "XosLibPngStructAttachedInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngStructInterfaceImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngStructAttachedInterface
XosLibPngStructInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngStructInterface
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosLibPngStructInterface
: virtual public XosLibPngStructInterfaceImplement
{
public:
    typedef XosLibPngStructInterfaceImplement Implements;
#else // !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY)
// include XosLibPngStruct member functions interface
//
#define XOSLIBPNGSTRUCT_MEMBERS_ONLY
#define XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE
#include "XosLibPngStruct.hpp"
#undef XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE
#undef XOSLIBPNGSTRUCT_MEMBERS_ONLY
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGSTRUCTINTERFACE_HPP) || defined(XOSLIBPNGSTRUCTINTERFACE_MEMBERS_ONLY) 
        


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
///   File: XosMainInterface.hpp
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSMAININTERFACE_HPP) || defined(XOSMAININTERFACE_MEMBERS_ONLY)
#if !defined(_XOSMAININTERFACE_HPP) && !defined(XOSMAININTERFACE_MEMBERS_ONLY)
#define _XOSMAININTERFACE_HPP
#endif // !defined(_XOSMAININTERFACE_HPP) && !defined(XOSMAININTERFACE_MEMBERS_ONLY) 

#if !defined(XOSMAININTERFACE_MEMBERS_ONLY)
#include "XosInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosMainInterfaceImplement
///
///  Author: $author$
///    Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosMainInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosMainInterface
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS XosMainInterface
: virtual public XosMainInterfaceImplement
{
public:
    typedef XosMainInterfaceImplement Implements;
#else // !defined(XOSMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSMAININTERFACE_MEMBERS_ONLY) 

#if !defined(XOSMAININTERFACE_MEMBERS_ONLY)
// include XosMain member functions interface
//
#define XOSMAIN_MEMBERS_ONLY
#define XOSMAIN_MEMBER_FUNCS_INTERFACE
#include "XosMain.hpp"
#undef XOSMAIN_MEMBER_FUNCS_INTERFACE
#undef XOSMAIN_MEMBERS_ONLY
};

#if !defined(XOSMAINIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
///  Class: XosMainImplement
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS XosMainImplement
: virtual public XosMainInterface
{
public:
    typedef XosMainInterface Implements;
#else // !defined(XOSMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(XOSMAINIMPLEMENT_MEMBERS_ONLY) 

#if !defined(XOSMAINIMPLEMENT_MEMBERS_ONLY)
// include XosMain member functions implement
//
#define XOSMAIN_MEMBERS_ONLY
#define XOSMAIN_MEMBER_FUNCS_IMPLEMENT
#include "XosMain.hpp"
#undef XOSMAIN_MEMBER_FUNCS_IMPLEMENT
#undef XOSMAIN_MEMBERS_ONLY
};
#else // !defined(XOSMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(XOSMAINIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(XOSMAININTERFACE_MEMBERS_ONLY) 

#endif // !defined(_XOSMAININTERFACE_HPP) || defined(XOSMAININTERFACE_MEMBERS_ONLY) 
        


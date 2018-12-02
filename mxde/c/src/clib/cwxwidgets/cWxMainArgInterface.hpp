///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2010 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cWxMainArgInterface.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXMAINARGINTERFACE_HPP) || defined(CWXMAINARGINTERFACE_MEMBERS_ONLY)
#if !defined(_CWXMAINARGINTERFACE_HPP) && !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY)
#define _CWXMAINARGINTERFACE_HPP
#endif // !defined(_CWXMAINARGINTERFACE_HPP) && !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY)
#include "cWxCharStringInterface.hpp"
#include "cmainarginterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWxMainArgInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgInterfaceImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cMainArgInterfaceT
<cWxMainArgInterface, wxChar, int>
cWxMainArgInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxMainArgInterface
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxMainArgInterface
: virtual public cWxMainArgInterfaceImplement
{
public:
    typedef cWxMainArgInterfaceImplement cImplements;
#else // !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWXMAINARGIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cWxMainArgImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgImplementImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cMainArgImplementT
<cWxMainArgImplement,
 cWxMainArgInterface,
 wxChar, int>
cWxMainArgImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxMainArgImplement
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWxMainArgImplement
: virtual public cWxMainArgImplementImplement
{
public:
    typedef cWxMainArgImplementImplement cImplements;
#else // !defined(CWXMAINARGIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWXMAINARGIMPLEMENT_MEMBERS_ONLY)
};
#else // !defined(CWXMAINARGIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWXMAINARGINTERFACE_HPP) || defined(CWXMAINARGINTERFACE_MEMBERS_ONLY) 

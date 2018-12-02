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
//   File: cWxCharStringInterface.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXCHARSTRINGINTERFACE_HPP) || defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY)
#if !defined(_CWXCHARSTRINGINTERFACE_HPP) && !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY)
#define _CWXCHARSTRINGINTERFACE_HPP
#endif // !defined(_CWXCHARSTRINGINTERFACE_HPP) && !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY)
#include "cplatform_wxwidgets.h"
#include "wx/intl.h"
#include "cstringbaseinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWxCharStringInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxCharStringInterfaceImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cStringBaseInterfaceT
<cWxCharStringInterface, wxChar>
cWxCharStringInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxCharStringInterface
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxCharStringInterface
: virtual public cWxCharStringInterfaceImplement
{
public:
    typedef cWxCharStringInterfaceImplement cImplements;
#else // !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWXCHARSTRINGIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWxCharStringImplementImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cWxCharStringInterface
cWxCharStringImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxCharStringImplement
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWxCharStringImplement
: virtual public cWxCharStringImplementImplement
{
public:
    typedef cWxCharStringImplementImplement cImplements;
#else // !defined(CWXCHARSTRINGIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWXCHARSTRINGIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWXCHARSTRINGIMPLEMENT_MEMBERS_ONLY)
};
#else // !defined(CWXCHARSTRINGIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWXCHARSTRINGIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWXCHARSTRINGINTERFACE_HPP) || defined(CWXCHARSTRINGINTERFACE_MEMBERS_ONLY) 

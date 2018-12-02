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
//   File: cWxWinServiceControlInterface.hpp
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWINSERVICECONTROLINTERFACE_HPP) || defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY)
#if !defined(_CWXWINSERVICECONTROLINTERFACE_HPP) && !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY)
#define _CWXWINSERVICECONTROLINTERFACE_HPP
#endif // !defined(_CWXWINSERVICECONTROLINTERFACE_HPP) && !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY)
#include "cWxWin_SC_HANDLE_Opened.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxWinServiceControlInterfaceImplement
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cWxWin_SC_HANDLE_OpenedInterface
cWxWinServiceControlInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWinServiceControlInterface
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxWinServiceControlInterface
: virtual public cWxWinServiceControlInterfaceImplement
{
public:
    typedef cWxWinServiceControlInterfaceImplement cImplements;
#else // !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWXWINSERVICECONTROLIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWinServiceControlImplementImplement
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cWxWinServiceControlInterface
cWxWinServiceControlImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWinServiceControlImplement
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWxWinServiceControlImplement
: virtual public cWxWinServiceControlImplementImplement
{
public:
    typedef cWxWinServiceControlImplementImplement cImplements;
#else // !defined(CWXWINSERVICECONTROLIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICECONTROLIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWXWINSERVICECONTROLIMPLEMENT_MEMBERS_ONLY)
};
#else // !defined(CWXWINSERVICECONTROLIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICECONTROLIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWXWINSERVICECONTROLINTERFACE_HPP) || defined(CWXWINSERVICECONTROLINTERFACE_MEMBERS_ONLY) 

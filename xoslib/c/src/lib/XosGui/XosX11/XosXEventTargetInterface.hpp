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
///   File: XosXEventTargetInterface.hpp
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXEVENTTARGETINTERFACE_HPP
#define _XOSXEVENTTARGETINTERFACE_HPP

#include "XosXInterfaceBase.hpp"
#include "XosXlib.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXEventTargetInterfaceImplement
///
///  Author: $author$
///    Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosXInterfaceBase
XosXEventTargetInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosXEventTargetInterface
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosXEventTargetInterface
: virtual public XosXEventTargetInterfaceImplement
{
public:
    typedef XosXEventTargetInterfaceImplement Implements;

#define XOSONXEVENTINTERFACE_MEMBERS_DEFAULT
#define XOSONXEVENTINTERFACE_MEMBERS_ONXEVENT
#include "XosOnXEventInterfaceMembers.hpp"
#undef XOSONXEVENTINTERFACE_MEMBERS_ONXEVENT
#undef XOSONXEVENTINTERFACE_MEMBERS_DEFAULT
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXEventTargetImplementImplement
///
///  Author: $author$
///    Date: 5/19/2012
///////////////////////////////////////////////////////////////////////
typedef XosXEventTargetInterface
XosXEventTargetImplementImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosXEventTargetImplement
///
/// Author: $author$
///   Date: 5/19/2012
///////////////////////////////////////////////////////////////////////
class _IMPLEMENT_CLASS XosXEventTargetImplement
: virtual public XosXEventTargetImplementImplement
{
public:
    typedef XosXEventTargetImplementImplement Implements;

#define XOSONXEVENT_MEMBERS_DEFAULT
#define XOSONXEVENT_MEMBERS_ONXEVENT
#include "XosOnXEventMembers.hpp"
#undef XOSONXEVENT_MEMBERS_ONXEVENT
#undef XOSONXEVENT_MEMBERS_DEFAULT
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXEVENTTARGETINTERFACE_HPP 
        


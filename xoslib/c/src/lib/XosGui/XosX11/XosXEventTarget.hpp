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
///   File: XosXEventTarget.hpp
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXEVENTTARGET_HPP
#define _XOSXEVENTTARGET_HPP

#include "XosXEventTargetInterface.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXEventTargetImplements
///
///  Author: $author$
///    Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosXEventTargetInterface
XosXEventTargetImplements;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXEventTargetExtend
///
///  Author: $author$
///    Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosXBase
XosXEventTargetExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXEventTarget
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXEventTarget
: virtual public XosXEventTargetImplements,
  public XosXEventTargetExtend
{
public:
    typedef XosXEventTargetImplements Implements;
    typedef XosXEventTargetExtend Extends;

    XosXEventTargetInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXEventTarget
    ///
    ///       Author: $author$
    ///         Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    XosXEventTarget
    (XosXEventTargetInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXEventTarget
    ///
    ///      Author: $author$
    ///        Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXEventTarget()
    {
    }

#define XOSONXEVENT_MEMBERS_DELEGATED
#define XOSONXEVENT_MEMBERS_DEFAULT
#define XOSONXEVENT_MEMBERS_ONXEVENT
#include "XosOnXEventMembers.hpp"
#undef XOSONXEVENT_MEMBERS_ONXEVENT
#undef XOSONXEVENT_MEMBERS_DEFAULT
#undef XOSONXEVENT_MEMBERS_DELEGATED
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXEVENTTARGET_HPP 
        


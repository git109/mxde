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
///   File: XosXWindowAttached.hpp
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXWINDOWATTACHED_HPP
#define _XOSXWINDOWATTACHED_HPP

#include "XosCreatedAttached.hpp"
#include "XosXEventTargetInterface.hpp"
#include "XosXEventTarget.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"
#include "XosXlib.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowAttachedImplement
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Window, int, None, XosXEventTargetInterface>
XosXWindowAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowAttachedExtend
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Window, int, None, 
 XosXWindowAttachedImplement, XosXEventTarget>
XosXWindowAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWindowAttached
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXWindowAttached
: virtual public XosXWindowAttachedImplement,
  public XosXWindowAttachedExtend
{
public:
    typedef XosXWindowAttachedImplement Implements;
    typedef XosXWindowAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXWindowAttached
    ///
    ///       Author: $author$
    ///         Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    XosXWindowAttached
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXWindowAttached
    ///
    ///      Author: $author$
    ///        Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXWindowAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowCreatedAttachedImplement
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<Window, int, None, XosXWindowAttachedImplement>
XosXWindowCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowCreatedAttachedExtend
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<Window, int, None, 
 XosXWindowCreatedAttachedImplement, XosXWindowAttached>
XosXWindowCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWindowCreatedAttached
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXWindowCreatedAttached
: virtual public XosXWindowCreatedAttachedImplement,
  public XosXWindowCreatedAttachedExtend
{
public:
    typedef XosXWindowCreatedAttachedImplement Implements;
    typedef XosXWindowCreatedAttachedExtend Extends;

    Display* m_xDisplay;
    Window m_xWindow;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXWindowCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    XosXWindowCreatedAttached
    (Display* xDisplay=0,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated),
      m_xDisplay(xDisplay)
    {
        m_xWindow = m_attached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (Display* xDisplay, tAttachedTo attachedTo, bool isCreated=false)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        if ((xDisplay) && (None  != (attachedTo)))
        {
            m_xDisplay = xDisplay;
            m_xWindow = (m_attached = (attached  = attachedTo));
            m_isCreated = isCreated;
        }
        return attached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach
    (Display*& xDisplay, bool& isCreated)
    {
        tAttachedTo detached = m_attached;
        xDisplay = m_xDisplay;
        isCreated = m_isCreated;
        m_xDisplay = 0;
        m_xWindow = (m_attached = None);
        m_isCreated = false;
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attached
    ///
    ///    Author: $author$
    ///      Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attached
    (Display*& xDisplay) const
    {
        tAttachedTo attached = m_attached;
        xDisplay = m_xDisplay;
        return attached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attached
    ///
    ///    Author: $author$
    ///      Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    using Extends::Attached;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXWINDOWATTACHED_HPP 
        


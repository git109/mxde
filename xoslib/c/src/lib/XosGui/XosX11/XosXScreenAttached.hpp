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
///   File: XosXScreenAttached.hpp
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXSCREENATTACHED_HPP
#define _XOSXSCREENATTACHED_HPP

#include "XosAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXScreenAttachedImplement
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Screen*, int, 0, XosXInterfaceBase>
XosXScreenAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXScreenAttachedExtend
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Screen*, int, 0, 
 XosXScreenAttachedImplement, XosXBase>
XosXScreenAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXScreenAttached
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXScreenAttached
: virtual public XosXScreenAttachedImplement,
  public XosXScreenAttachedExtend
{
public:
    typedef XosXScreenAttachedImplement Implements;
    typedef XosXScreenAttachedExtend Extends;

    Display* m_xDisplay;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXScreenAttached
    ///
    ///      Author: $author$
    ///        Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    XosXScreenAttached
    (Display* xDisplay=0,
     tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (Display* xDisplay, tAttachedTo attachedTo)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        if ((xDisplay) && (None  != (attachedTo)))
        {
            m_xDisplay = xDisplay;
            m_attached = (attached  = attachedTo);
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
    (Display*& xDisplay)
    {
        tAttachedTo detached = m_attached;
        xDisplay = m_xDisplay;
        m_xDisplay = 0;
        m_attached = 0;
        return detached;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXSCREENATTACHED_HPP 
        


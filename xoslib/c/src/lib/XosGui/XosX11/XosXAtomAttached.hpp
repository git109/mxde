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
///   File: XosXAtomAttached.hpp
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXATOMATTACHED_HPP
#define _XOSXATOMATTACHED_HPP

#include "XosCreatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXAtomAttachedImplement
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Atom, int, None, XosXInterfaceBase>
XosXAtomAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXAtomAttachedExtend
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Atom, int, None, 
 XosXAtomAttachedImplement, XosXBase>
XosXAtomAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXAtomAttached
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXAtomAttached
: virtual public XosXAtomAttachedImplement,
  public XosXAtomAttachedExtend
{
public:
    typedef XosXAtomAttachedImplement Implements;
    typedef XosXAtomAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXAtomAttached
    ///
    ///      Author: $author$
    ///        Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    XosXAtomAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXAtomCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<Atom, int, None, XosXAtomAttachedImplement>
XosXAtomCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXAtomCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<Atom, int, None, 
 XosXAtomCreatedAttachedImplement, XosXAtomAttached>
XosXAtomCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXAtomCreatedAttached
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXAtomCreatedAttached
: virtual public XosXAtomCreatedAttachedImplement,
  public XosXAtomCreatedAttachedExtend
{
public:
    typedef XosXAtomCreatedAttachedImplement Implements;
    typedef XosXAtomCreatedAttachedExtend Extends;

    Display* m_xDisplay;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXAtomCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    XosXAtomCreatedAttached
    (Display* xDisplay=0,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
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
            m_attached = (attached  = attachedTo);
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
        m_attached = None;
        m_isCreated = false;
        return detached;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXATOMATTACHED_HPP 
        


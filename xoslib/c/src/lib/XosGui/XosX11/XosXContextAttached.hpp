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
///   File: XosXContextAttached.hpp
///
/// Author: $author$
///   Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXCONTEXTATTACHED_HPP
#define _XOSXCONTEXTATTACHED_HPP

#include "XosCreatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXContextAttachedImplement
///
///  Author: $author$
///    Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<XContext, int, None, XosXInterfaceBase>
XosXContextAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXContextAttachedExtend
///
///  Author: $author$
///    Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<XContext, int, None, 
 XosXContextAttachedImplement, XosXBase>
XosXContextAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXContextAttached
///
/// Author: $author$
///   Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXContextAttached
: virtual public XosXContextAttachedImplement,
  public XosXContextAttachedExtend
{
public:
    typedef XosXContextAttachedImplement Implements;
    typedef XosXContextAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXContextAttached
    ///
    ///      Author: $author$
    ///        Date: 5/22/2012
    ///////////////////////////////////////////////////////////////////////
    XosXContextAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXContextCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<XContext, int, None, XosXContextAttachedImplement>
XosXContextCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXContextCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<XContext, int, None, 
 XosXContextCreatedAttachedImplement, XosXContextAttached>
XosXContextCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXContextCreatedAttached
///
/// Author: $author$
///   Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXContextCreatedAttached
: virtual public XosXContextCreatedAttachedImplement,
  public XosXContextCreatedAttachedExtend
{
public:
    typedef XosXContextCreatedAttachedImplement Implements;
    typedef XosXContextCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXContextCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/22/2012
    ///////////////////////////////////////////////////////////////////////
    XosXContextCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXCONTEXTATTACHED_HPP 

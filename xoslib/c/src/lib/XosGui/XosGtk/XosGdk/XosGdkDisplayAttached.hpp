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
///   File: XosGdkDisplayAttached.hpp
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGDKDISPLAYATTACHED_HPP
#define _XOSGDKDISPLAYATTACHED_HPP
#include "XosGdk.hpp"

#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkDisplayAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<GdkDisplay*, int, 0, XosInterfaceBase>
XosGdkDisplayAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkDisplayAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<GdkDisplay*, int, 0, 
 XosGdkDisplayAttachedImplement, XosExportBase>
XosGdkDisplayAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkDisplayAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkDisplayAttached
: virtual public XosGdkDisplayAttachedImplement,
  public XosGdkDisplayAttachedExtend
{
public:
    typedef XosGdkDisplayAttachedImplement Implements;
    typedef XosGdkDisplayAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkDisplayAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkDisplayAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkDisplayCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<GdkDisplay*, int, 0, XosGdkDisplayAttachedImplement>
XosGdkDisplayCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkDisplayCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<GdkDisplay*, int, 0, 
 XosGdkDisplayCreatedAttachedImplement, XosGdkDisplayAttached>
XosGdkDisplayCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkDisplayCreatedAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkDisplayCreatedAttached
: virtual public XosGdkDisplayCreatedAttachedImplement,
  public XosGdkDisplayCreatedAttachedExtend
{
public:
    typedef XosGdkDisplayCreatedAttachedImplement Implements;
    typedef XosGdkDisplayCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkDisplayCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkDisplayCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGDKDISPLAYATTACHED_HPP 
        


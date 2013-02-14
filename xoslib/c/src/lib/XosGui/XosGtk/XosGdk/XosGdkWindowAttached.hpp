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
///   File: XosGdkWindowAttached.hpp
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGDKWINDOWATTACHED_HPP
#define _XOSGDKWINDOWATTACHED_HPP

#include "XosGdk.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkWindowAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<GdkWindow*, int, 0, XosInterfaceBase>
XosGdkWindowAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkWindowAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<GdkWindow*, int, 0, 
 XosGdkWindowAttachedImplement, XosExportBase>
XosGdkWindowAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkWindowAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkWindowAttached
: virtual public XosGdkWindowAttachedImplement,
  public XosGdkWindowAttachedExtend
{
public:
    typedef XosGdkWindowAttachedImplement Implements;
    typedef XosGdkWindowAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkWindowAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkWindowAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkWindowCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<GdkWindow*, int, 0, XosGdkWindowAttachedImplement>
XosGdkWindowCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkWindowCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<GdkWindow*, int, 0, 
 XosGdkWindowCreatedAttachedImplement, XosGdkWindowAttached>
XosGdkWindowCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkWindowCreatedAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkWindowCreatedAttached
: virtual public XosGdkWindowCreatedAttachedImplement,
  public XosGdkWindowCreatedAttachedExtend
{
public:
    typedef XosGdkWindowCreatedAttachedImplement Implements;
    typedef XosGdkWindowCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkWindowCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkWindowCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGDKWINDOWATTACHED_HPP 
        


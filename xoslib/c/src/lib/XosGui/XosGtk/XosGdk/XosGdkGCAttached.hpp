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
///   File: XosGdkGCAttached.hpp
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGDKGCATTACHED_HPP
#define _XOSGDKGCATTACHED_HPP
#include "XosGdk.hpp"

#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkGCAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<GdkGC*, int, 0, XosInterfaceBase>
XosGdkGCAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkGCAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<GdkGC*, int, 0, 
 XosGdkGCAttachedImplement, XosExportBase>
XosGdkGCAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkGCAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkGCAttached
: virtual public XosGdkGCAttachedImplement,
  public XosGdkGCAttachedExtend
{
public:
    typedef XosGdkGCAttachedImplement Implements;
    typedef XosGdkGCAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkGCAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkGCAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkGCCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<GdkGC*, int, 0, XosGdkGCAttachedImplement>
XosGdkGCCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkGCCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<GdkGC*, int, 0, 
 XosGdkGCCreatedAttachedImplement, XosGdkGCAttached>
XosGdkGCCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkGCCreatedAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkGCCreatedAttached
: virtual public XosGdkGCCreatedAttachedImplement,
  public XosGdkGCCreatedAttachedExtend
{
public:
    typedef XosGdkGCCreatedAttachedImplement Implements;
    typedef XosGdkGCCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkGCCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkGCCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGDKGCATTACHED_HPP 
        


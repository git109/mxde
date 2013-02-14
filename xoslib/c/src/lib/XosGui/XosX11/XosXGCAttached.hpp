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
///   File: XosXGCAttached.hpp
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXGCATTACHED_HPP
#define _XOSXGCATTACHED_HPP

#include "XosCreatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXGCAttachedImplement
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<GC, int, 0, XosXInterfaceBase>
XosXGCAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXGCAttachedExtend
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<GC, int, 0, 
 XosXGCAttachedImplement, XosXBase>
XosXGCAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXGCAttached
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXGCAttached
: virtual public XosXGCAttachedImplement,
  public XosXGCAttachedExtend
{
public:
    typedef XosXGCAttachedImplement Implements;
    typedef XosXGCAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXGCAttached
    ///
    ///      Author: $author$
    ///        Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosXGCAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXGCCreatedAttachedImplement
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<GC, int, 0, XosXGCAttachedImplement>
XosXGCCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXGCCreatedAttachedExtend
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<GC, int, 0, 
 XosXGCCreatedAttachedImplement, XosXGCAttached>
XosXGCCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXGCCreatedAttached
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXGCCreatedAttached
: virtual public XosXGCCreatedAttachedImplement,
  public XosXGCCreatedAttachedExtend
{
public:
    typedef XosXGCCreatedAttachedImplement Implements;
    typedef XosXGCCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXGCCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosXGCCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXGCATTACHED_HPP 
        


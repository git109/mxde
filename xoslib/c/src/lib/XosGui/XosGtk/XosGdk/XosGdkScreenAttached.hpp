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
///   File: XosGdkScreenAttached.hpp
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGDKSCREENATTACHED_HPP
#define _XOSGDKSCREENATTACHED_HPP
#include "XosGdk.hpp"

#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkScreenAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<GdkScreen*, int, 0, XosInterfaceBase>
XosGdkScreenAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkScreenAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<GdkScreen*, int, 0, 
 XosGdkScreenAttachedImplement, XosExportBase>
XosGdkScreenAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkScreenAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkScreenAttached
: virtual public XosGdkScreenAttachedImplement,
  public XosGdkScreenAttachedExtend
{
public:
    typedef XosGdkScreenAttachedImplement Implements;
    typedef XosGdkScreenAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkScreenAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkScreenAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkScreenCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<GdkScreen*, int, 0, XosGdkScreenAttachedImplement>
XosGdkScreenCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkScreenCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<GdkScreen*, int, 0, 
 XosGdkScreenCreatedAttachedImplement, XosGdkScreenAttached>
XosGdkScreenCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkScreenCreatedAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGdkScreenCreatedAttached
: virtual public XosGdkScreenCreatedAttachedImplement,
  public XosGdkScreenCreatedAttachedExtend
{
public:
    typedef XosGdkScreenCreatedAttachedImplement Implements;
    typedef XosGdkScreenCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGdkScreenCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkScreenCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGDKSCREENATTACHED_HPP 
        


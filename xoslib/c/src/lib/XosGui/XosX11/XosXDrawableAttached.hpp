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
///   File: XosXDrawableAttached.hpp
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXDRAWABLEATTACHED_HPP
#define _XOSXDRAWABLEATTACHED_HPP

#include "XosCreatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"
#include "XosXlib.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDrawableAttachedImplement
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Drawable, int, None, XosXInterfaceBase>
XosXDrawableAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDrawableAttachedExtend
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Drawable, int, None, 
 XosXDrawableAttachedImplement, XosXBase>
XosXDrawableAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXDrawableAttached
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXDrawableAttached
: virtual public XosXDrawableAttachedImplement,
  public XosXDrawableAttachedExtend
{
public:
    typedef XosXDrawableAttachedImplement Implements;
    typedef XosXDrawableAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXDrawableAttached
    ///
    ///       Author: $author$
    ///         Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    XosXDrawableAttached
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXDrawableAttached
    ///
    ///      Author: $author$
    ///        Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXDrawableAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDrawableCreatedAttachedImplement
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<Drawable, int, None, XosXDrawableAttachedImplement>
XosXDrawableCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDrawableCreatedAttachedExtend
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<Drawable, int, None, 
 XosXDrawableCreatedAttachedImplement, XosXDrawableAttached>
XosXDrawableCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXDrawableCreatedAttached
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXDrawableCreatedAttached
: virtual public XosXDrawableCreatedAttachedImplement,
  public XosXDrawableCreatedAttachedExtend
{
public:
    typedef XosXDrawableCreatedAttachedImplement Implements;
    typedef XosXDrawableCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXDrawableCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    XosXDrawableCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXDRAWABLEATTACHED_HPP 
        


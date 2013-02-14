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
///   File: XosXDisplayAttached.hpp
///
/// Author: $author$
///   Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXDISPLAYATTACHED_HPP
#define _XOSXDISPLAYATTACHED_HPP

#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"
#include "XosCreatedAttached.hpp"
#include "XosOpenedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayAttachedImplement
///
///  Author: $author$
///    Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Display*, int, 0, XosXInterfaceBase>
XosXDisplayAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayAttachedExtend
///
///  Author: $author$
///    Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Display*, int, 0, XosXDisplayAttachedImplement, XosXBase>
XosXDisplayAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXDisplayAttached
///
/// Author: $author$
///   Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXDisplayAttached
: virtual public XosXDisplayAttachedImplement,
  public XosXDisplayAttachedExtend
{
public:
    typedef XosXDisplayAttachedImplement Implements;
    typedef XosXDisplayAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXDisplayAttached
    ///
    ///       Author: $author$
    ///         Date: 3/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosXDisplayAttached
    (Display* attached=0)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXDisplayAttached
    ///
    ///      Author: $author$
    ///        Date: 3/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXDisplayAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayCreatedAttachedImplement
///
///  Author: $author$
///    Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<Display*, int, 0, XosXDisplayAttachedImplement>
XosXDisplayCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayCreatedAttachedExtend
///
///  Author: $author$
///    Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<Display*, int, 0, XosXDisplayCreatedAttachedImplement, XosXDisplayAttached>
XosXDisplayCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXDisplayCreatedAttached
///
/// Author: $author$
///   Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXDisplayCreatedAttached
: virtual public XosXDisplayCreatedAttachedImplement,
  public XosXDisplayCreatedAttachedExtend
{
public:
    typedef XosXDisplayCreatedAttachedImplement Implements;
    typedef XosXDisplayCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXDisplayCreatedAttached
    ///
    ///       Author: $author$
    ///         Date: 3/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosXDisplayCreatedAttached
    (Display* attached=0,
     bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXDisplayCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 3/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXDisplayCreatedAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayOpenedAttachedImplement
///
///  Author: $author$
///    Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
typedef XosOpenedAttachedInterfaceT
<Display*, int, 0, XosXDisplayAttachedImplement>
XosXDisplayOpenedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayOpenedAttachedExtend
///
///  Author: $author$
///    Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
typedef XosOpenedAttachedT
<Display*, int, 0, 
 XosXDisplayOpenedAttachedImplement, XosXDisplayAttached>
XosXDisplayOpenedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXDisplayOpenedAttached
///
/// Author: $author$
///   Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXDisplayOpenedAttached
: virtual public XosXDisplayOpenedAttachedImplement,
  public XosXDisplayOpenedAttachedExtend
{
public:
    typedef XosXDisplayOpenedAttachedImplement Implements;
    typedef XosXDisplayOpenedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXDisplayOpenedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    XosXDisplayOpenedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : Extends(attached, isOpen) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXDISPLAYATTACHED_HPP 

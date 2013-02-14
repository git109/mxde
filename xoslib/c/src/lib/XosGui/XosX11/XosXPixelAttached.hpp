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
///   File: XosXPixelAttached.hpp
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXPIXELATTACHED_HPP
#define _XOSXPIXELATTACHED_HPP

#include "XosAllocatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"
#include "XosXlib.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixelAttachedImplement
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Pixel, int, 0, XosXInterfaceBase>
XosXPixelAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixelAttachedExtend
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Pixel, int, 0, 
 XosXPixelAttachedImplement, XosXBase>
XosXPixelAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXPixelAttached
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXPixelAttached
: virtual public XosXPixelAttachedImplement,
  public XosXPixelAttachedExtend
{
public:
    typedef XosXPixelAttachedImplement Implements;
    typedef XosXPixelAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXPixelAttached
    ///
    ///       Author: $author$
    ///         Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    XosXPixelAttached
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXPixelAttached
    ///
    ///      Author: $author$
    ///        Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXPixelAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixelAllocatedAttachedImplement
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosAllocatedAttachedInterfaceT
<Pixel, int, 0, XosXPixelAttachedImplement>
XosXPixelAllocatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixelAllocatedAttachedExtend
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosAllocatedAttachedT
<Pixel, int, 0, 
 XosXPixelAllocatedAttachedImplement, XosXPixelAttached>
XosXPixelAllocatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXPixelAllocatedAttached
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXPixelAllocatedAttached
: virtual public XosXPixelAllocatedAttachedImplement,
  public XosXPixelAllocatedAttachedExtend
{
public:
    typedef XosXPixelAllocatedAttachedImplement Implements;
    typedef XosXPixelAllocatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXPixelAllocatedAttached
    ///
    ///      Author: $author$
    ///        Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    XosXPixelAllocatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isAllocated=false) 
    : Extends(attached, isAllocated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXPIXELATTACHED_HPP 
        


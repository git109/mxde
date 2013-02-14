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
///   File: XosXPixmapAttached.hpp
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXPIXMAPATTACHED_HPP
#define _XOSXPIXMAPATTACHED_HPP

#include "XosCreatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"
#include "XosXlib.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixmapAttachedImplement
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Pixmap, int, None, XosXInterfaceBase>
XosXPixmapAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixmapAttachedExtend
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Pixmap, int, None, 
 XosXPixmapAttachedImplement, XosXBase>
XosXPixmapAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXPixmapAttached
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXPixmapAttached
: virtual public XosXPixmapAttachedImplement,
  public XosXPixmapAttachedExtend
{
public:
    typedef XosXPixmapAttachedImplement Implements;
    typedef XosXPixmapAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXPixmapAttached
    ///
    ///       Author: $author$
    ///         Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    XosXPixmapAttached
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXPixmapAttached
    ///
    ///      Author: $author$
    ///        Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXPixmapAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixmapCreatedAttachedImplement
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<Pixmap, int, None, XosXPixmapAttachedImplement>
XosXPixmapCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixmapCreatedAttachedExtend
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<Pixmap, int, None, 
 XosXPixmapCreatedAttachedImplement, XosXPixmapAttached>
XosXPixmapCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXPixmapCreatedAttached
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXPixmapCreatedAttached
: virtual public XosXPixmapCreatedAttachedImplement,
  public XosXPixmapCreatedAttachedExtend
{
public:
    typedef XosXPixmapCreatedAttachedImplement Implements;
    typedef XosXPixmapCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXPixmapCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    XosXPixmapCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXPIXMAPATTACHED_HPP 
        


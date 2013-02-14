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
///   File: XosXColormapAttached.hpp
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXCOLORMAPATTACHED_HPP
#define _XOSXCOLORMAPATTACHED_HPP

#include "XosXDisplayAttached.hpp"
#include "XosCreatedAttached.hpp"
#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"
#include "XosXlib.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColormapAttachedImplement
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<Colormap, int, None, XosXInterfaceBase>
XosXColormapAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColormapAttachedExtend
///
///  Author: $author$
///    Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<Colormap, int, None, 
 XosXColormapAttachedImplement, XosXBase>
XosXColormapAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXColormapAttached
///
/// Author: $author$
///   Date: 4/23/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXColormapAttached
: virtual public XosXColormapAttachedImplement,
  public XosXColormapAttachedExtend
{
public:
    typedef XosXColormapAttachedImplement Implements;
    typedef XosXColormapAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXColormapAttached
    ///
    ///       Author: $author$
    ///         Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    XosXColormapAttached
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXColormapAttached
    ///
    ///      Author: $author$
    ///        Date: 4/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXColormapAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColormapCreatedAttachedImplement
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<Colormap, int, None, XosXColormapAttachedImplement>
XosXColormapCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColormapCreatedAttachedExtend
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<Colormap, int, None, 
 XosXColormapCreatedAttachedImplement, XosXColormapAttached>
XosXColormapCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXColormapCreatedAttached
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
class _INSTANCE_CLASS XosXColormapCreatedAttached
: virtual public XosXColormapCreatedAttachedImplement,
  public XosXColormapCreatedAttachedExtend
{
public:
    typedef XosXColormapCreatedAttachedImplement Implements;
    typedef XosXColormapCreatedAttachedExtend Extends;

    XosXDisplayAttached m_display;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosXColormapCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    XosXColormapCreatedAttached
    (Display* xDisplayAttached=0, 
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated),
      m_display(xDisplayAttached)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (Display* xDisplayAttached, tAttachedTo attached)
    {
        m_display.Attach(xDisplayAttached);
        return Extends::Attach(attached);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach
    (Display*& xDisplayAttached)
    {
        tAttachedTo detached = Extends::Detach();
        xDisplayAttached = m_display.Detach();
        return detached;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXCOLORMAPATTACHED_HPP 
        


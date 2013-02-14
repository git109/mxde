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
///   File: XosGtkWidgetAttached.hpp
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGTKWIDGETATTACHED_HPP
#define _XOSGTKWIDGETATTACHED_HPP

#include "XosGtk.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGtkWidgetAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<GtkWidget*, int, 0, XosInterfaceBase>
XosGtkWidgetAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGtkWidgetAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<GtkWidget*, int, 0, 
 XosGtkWidgetAttachedImplement, XosExportBase>
XosGtkWidgetAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGtkWidgetAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGtkWidgetAttached
: virtual public XosGtkWidgetAttachedImplement,
  public XosGtkWidgetAttachedExtend
{
public:
    typedef XosGtkWidgetAttachedImplement Implements;
    typedef XosGtkWidgetAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGtkWidgetAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGtkWidgetAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : Extends(attached) 
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGtkWidgetCreatedAttachedImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<GtkWidget*, int, 0, XosGtkWidgetAttachedImplement>
XosGtkWidgetCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGtkWidgetCreatedAttachedExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<GtkWidget*, int, 0, 
 XosGtkWidgetCreatedAttachedImplement, XosGtkWidgetAttached>
XosGtkWidgetCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGtkWidgetCreatedAttached
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosGtkWidgetCreatedAttached
: virtual public XosGtkWidgetCreatedAttachedImplement,
  public XosGtkWidgetCreatedAttachedExtend
{
public:
    typedef XosGtkWidgetCreatedAttachedImplement Implements;
    typedef XosGtkWidgetCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: XosGtkWidgetCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGtkWidgetCreatedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(attached, isCreated) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGTKWIDGETATTACHED_HPP 
        


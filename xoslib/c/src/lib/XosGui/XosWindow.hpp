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
///   File: XosWindow.hpp
///
/// Author: $author$
///   Date: 3/19/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINDOW_HPP
#define _XOSWINDOW_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWindowImplement
///
///  Author: $author$
///    Date: 3/19/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWindowExtend
///
///  Author: $author$
///    Date: 3/19/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWindow
///
/// Author: $author$
///   Date: 3/19/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWindow
: virtual public XosWindowImplement,
  public XosWindowExtend
{
public:
    typedef XosWindowImplement Implements;
    typedef XosWindowExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWindow
    ///
    ///       Author: $author$
    ///         Date: 3/19/2012
    ///////////////////////////////////////////////////////////////////////
    XosWindow()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWindow
    ///
    ///      Author: $author$
    ///        Date: 3/19/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWindow()
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINDOW_HPP 
        


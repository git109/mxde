///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   File: XosQMainWindow.hpp
///
/// Author: $author$
///   Date: 2/4/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSQMAINWINDOW_HPP
#define _XOSQMAINWINDOW_HPP

#include <QtGui>
#include "XosInterfaceBase.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosInterfaceBase XosQMainWindowImplement;
typedef QMainWindow XosQMainWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosQMainWindow
///
/// Author: $author$
///   Date: 2/4/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosQMainWindow
: virtual public XosQMainWindowImplement,
  public XosQMainWindowExtend
{
public:
    typedef XosQMainWindowImplement Implements;
    typedef XosQMainWindowExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosQMainWindow
    ///
    ///       Author: $author$
    ///         Date: 2/4/2013
    ///////////////////////////////////////////////////////////////////////
    XosQMainWindow()
    {
    }
    virtual ~XosQMainWindow()
    {
    }
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSQMAINWINDOW_HPP 

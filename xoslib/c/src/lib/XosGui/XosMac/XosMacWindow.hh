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
///   File: XosMacWindow.hh
///
/// Author: $author$
///   Date: 4/12/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACWINDOW_HH
#define _XOSMACWINDOW_HH

#include "XosWindow.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef XosWindowImplement XosMacWindowImplement;
typedef XosWindow XosMacWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosMacWindow
///
/// Author: $author$
///   Date: 4/12/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosMacWindow
: virtual public XosMacWindowImplement,
  public XosMacWindowExtend
{
public:
    typedef XosMacWindowImplement Implements;
    typedef XosMacWindowExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosMacWindow
    ///
    ///       Author: $author$
    ///         Date: 4/12/2012
    ///////////////////////////////////////////////////////////////////////
    XosMacWindow()
    {
    }
    virtual ~XosMacWindow()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMACWINDOW_HH 

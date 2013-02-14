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
///   File: XosXWindowInterface.hpp
///
/// Author: $author$
///   Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXWINDOWINTERFACE_HPP
#define _XOSXWINDOWINTERFACE_HPP

#include "XosXWindowAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowInterfaceImplement
///
///  Author: $author$
///    Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosXWindowCreatedAttachedImplement
XosXWindowInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWindowInterface
///
/// Author: $author$
///   Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
class _INTERFACE_CLASS XosXWindowInterface
: virtual public XosXWindowInterfaceImplement
{
public:
    typedef XosXWindowInterfaceImplement Implements;

// include XosXWindow member functions interface
//
#define XOSXWINDOW_MEMBERS_ONLY
#define XOSXWINDOW_MEMBER_FUNCS_INTERFACE
#include "XosXWindow.hpp"
#undef XOSXWINDOW_MEMBER_FUNCS_INTERFACE
#undef XOSXWINDOW_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXWINDOWINTERFACE_HPP 

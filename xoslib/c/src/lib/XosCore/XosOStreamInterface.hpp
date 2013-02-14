///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
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
///   File: XosOStreamInterface.hpp
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
#ifndef _XOSOSTREAMINTERFACE_HPP
#define _XOSOSTREAMINTERFACE_HPP

#include "XosInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosOStreamInterfaceT
///
/// Author: $author$
///   Date: 12/28/2011
///////////////////////////////////////////////////////////////////////
template 
<class TWhat=char, 
 class TImplement=XosInterfaceBase>

class c_EXPORT_CLASS XosOStreamInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement Implements;
	typedef TImplement tImplement;
	typedef TWhat tWhat;

	///////////////////////////////////////////////////////////////////////
    ///  Function: Write
    ///
    ///    Author: $author$
    ///      Date: 12/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const tWhat* what, ssize_t length=-1)
    {
        ssize_t count = -XOS_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};

//
// char
//

///////////////////////////////////////////////////////////////////////
/// Typedef: XosOStreamInterfaceImplement
///
///  Author: $author$
///    Date: 12/28/2011
///////////////////////////////////////////////////////////////////////
typedef XosOStreamInterfaceT<char, XosInterfaceBase>
XosOStreamInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosOStreamInterface
///
/// Author: $author$
///   Date: 12/28/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosOStreamInterface
: virtual public XosOStreamInterfaceImplement
{
public:
    typedef XosOStreamInterfaceImplement Implements;
};

//
// wchar_t
//

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWOStreamInterfaceImplement
///
///  Author: $author$
///    Date: 12/28/2011
///////////////////////////////////////////////////////////////////////
typedef XosOStreamInterfaceT<wchar_t, XosInterfaceBase>
XosWOStreamInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosWOStreamInterface
///
/// Author: $author$
///   Date: 12/28/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWOStreamInterface
: virtual public XosWOStreamInterfaceImplement
{
public:
    typedef XosWOStreamInterfaceImplement Implements;
};

//
// uint8_t (byte)
//

///////////////////////////////////////////////////////////////////////
/// Typedef: XosByteOStreamInterfaceImplement
///
///  Author: $author$
///    Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
typedef XosOStreamInterfaceT<uint8_t, XosInterfaceBase>
XosByteOStreamInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosByteOStreamInterface
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosByteOStreamInterface
: virtual public XosByteOStreamInterfaceImplement
{
public:
    typedef XosByteOStreamInterfaceImplement Implements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSOSTREAMINTERFACE_HPP 

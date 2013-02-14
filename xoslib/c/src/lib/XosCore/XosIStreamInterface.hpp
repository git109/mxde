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
///   File: XosIStreamInterface.hpp
///
/// Author: $author$
///   Date: 11/22/2011
///////////////////////////////////////////////////////////////////////
#ifndef _XOSISTREAMINTERFACE_HPP
#define _XOSISTREAMINTERFACE_HPP

#include "XosInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosByteIStreamInterfaceImplement
///
///  Author: $author$
///    Date: 11/22/2011
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosByteIStreamInterfaceImplement;
///////////////////////////////////////////////////////////////////////
///  Class: XosByteIStreamInterface
///
/// Author: $author$
///   Date: 11/22/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosByteIStreamInterface
: virtual public XosByteIStreamInterfaceImplement
{
public:
    typedef XosByteIStreamInterfaceImplement Implements;
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 11/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (uint8_t* bytes,
     size_t size)
    {
        ssize_t count = -XOS_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSISTREAMINTERFACE_HPP 

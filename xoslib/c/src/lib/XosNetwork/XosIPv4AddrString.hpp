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
///   File: XosIPv4AddrString.hpp
///
/// Author: $author$
///   Date: 1/31/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSIPV4ADDRSTRING_HPP
#define _XOSIPV4ADDRSTRING_HPP

#include "XosPlatform.hpp"
#include "XosString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosIPv4AddrStringExtend
///
///  Author: $author$
///    Date: 1/31/2012
///////////////////////////////////////////////////////////////////////
typedef XosString
XosIPv4AddrStringExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosIPv4AddrString
///
/// Author: $author$
///   Date: 1/31/2012
///////////////////////////////////////////////////////////////////////
class XosIPv4AddrString
: public XosIPv4AddrStringExtend
{
public:
    typedef XosIPv4AddrStringExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosIPv4AddrString
    ///
    ///       Author: $author$
    ///         Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    XosIPv4AddrString
    (const std::string& copy)
    : Extends(copy)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosIPv4AddrString
    ///
    ///       Author: $author$
    ///         Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    XosIPv4AddrString
    (const tChar* chars=0,
     ssize_t length=-1)
    : Extends(chars, length)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ToUInt32
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual uint32_t ToUInt32() const
    {
        uint32_t addr = 0;
        uint8_t octet;
        size_t octetLen;
        const char* chars;
        size_t len;
        char c;

        if (0 < (len = length()))
        if ((chars = c_str()))
        {
            for (octet = 0, octetLen = 0; len; ++chars, --len)
            {
                switch(c = *chars)
                {
                case '.':
                    addr = ((addr << 8) | octet);
                    octet = 0;
                    octetLen = 0;
                    break;

                default:
                    if ((c < '0') || (c > '9'))
                        return 0;
                    octet = ((octet * 10) + (c - '0'));
                    ++octetLen;
                }
            }
            if ((octetLen))
                addr = ((addr << 8) | octet);
        }
        return addr;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator uint32_t
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual operator uint32_t() const
    {
        uint32_t addr = ToUInt32();
        return addr;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSIPV4ADDRSTRING_HPP 

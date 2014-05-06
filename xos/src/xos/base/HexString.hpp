///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: HexString.hpp
///
/// Author: $author$
///   Date: 2/17/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_HEXSTRING_HPP
#define _XOS_BASE_HEXSTRING_HPP

#include "xos/base/String.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: HexStringT
///////////////////////////////////////////////////////////////////////
template
<char VA, typename TChar = char,
 class TExtend = String, class TImplement = StringImplement>

class _EXPORT_CLASS HexStringT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    using Extends::AppendX;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    HexStringT(const uint8_t* bytes, size_t length, char A, char between) {
        this->AppendX(bytes, length, between, A);
    }
    HexStringT(const uint8_t* bytes, size_t length, char between) {
        this->AppendX(bytes, length, between, VA);
    }
    HexStringT(const uint8_t* bytes, size_t length) {
        this->AppendX(bytes, length, VA);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    HexStringT& AppendX(const uint8_t* bytes, size_t length, char between, char A) {
        if ((between)) {
            const uint8_t* b;
            if ((b = bytes)) {
                TChar t = (TChar)(between);
                if ((length)) {
                    do {
                        if ((b != bytes))
                            this->Append(&t, 1);
                        this->AppendX(b++, 1, A);
                    } while (--length);
                } else {
                    while (*b) {
                        if ((b != bytes))
                            this->Append(&t, 1);
                        this->AppendX(b++, 1, A);
                    }
                }
            }
        } else {
            this->AppendX(bytes, length, A);
        }
        return *this;
    }
};

//typedef HexStringT<'A'> XString;
typedef HexStringT<'a'> xString;

} // namespace xos 

#endif // _XOS_BASE_HEXSTRING_HPP 

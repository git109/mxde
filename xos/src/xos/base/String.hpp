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
///   File: String.hpp
///
/// Author: $author$
///   Date: Aug 14, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_STRING_HPP_
#define _XOS_STRING_HPP_

#include "xos/base/Base.hpp"
#include <string>

namespace xos {

typedef InterfaceBase StringImplement;

template 
<typename TChar, 
 class TExtend=std::basic_string<TChar>, 
 class TImplement=StringImplement>

class EXPORT_CLASS StringT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    StringT(const StringT& copy): Extends(copy){}
    StringT(const Extends& copy): Extends(copy){}
    StringT(const char* chars, size_t length){
        Append(chars);
    }
    StringT(const char* chars){
        Append(chars);
    }
    StringT(const wchar_t* chars, size_t length){
        Append(chars);
    }
    StringT(const wchar_t* chars){
        Append(chars);
    }
    StringT(){}
    virtual ~StringT(){}

    StringT& Assign(const Extends& string) {
        this->clear();
        Append(string);
        return *this; }
    StringT& Assign(const char* chars, size_t length) {
        this->clear();
        Append(chars, length);
        return *this; }
    StringT& Assign(const char* chars) {
        this->clear();
        Append(chars);
        return *this; }
    StringT& Assign(const wchar_t* chars, size_t length) {
        this->clear();
        Append(chars, length);
        return *this; }
    StringT& Assign(const wchar_t* chars) {
        this->clear();
        Append(chars);
        return *this; }

    StringT& Append(const Extends& string) {
        this->append(string);
        return *this; }
    StringT& Append(const char* chars, size_t length) {
        if ((chars)) {
            TChar c;
            while (0 < (length--)) {
                c = (TChar)(*chars++);
                this->append(&c, 1);
            }
        }
        return *this; }
    StringT& Append(const char* chars) {
        if ((chars)) {
            TChar c;
            while ((c = (TChar)(*chars++))) {
                this->append(&c, 1);
            }
        }
        return *this; }
    StringT& Append(const wchar_t* chars, size_t length) {
        if ((chars)) {
            TChar c;
            while (0 < (length--)) {
                c = (TChar)(*chars++);
                this->append(&c, 1);
            }
        }
        return *this; }
    StringT& Append(const wchar_t* chars) {
        if ((chars)) {
            TChar c;
            while ((c = (TChar)(*chars++))) {
                this->append(&c, 1);
            }
        }
        return *this; }

    size_t Clear() {
        size_t count = this->length();
        this->clear();
        return count;
    }

    const TChar* Chars(size_t& length) const {
        length = this->length();
        return this->c_str();
    }
    const TChar* Chars() const {
        return this->c_str();
    }
    size_t Length() const  {
        return this->length();
    }

    StringT& operator << (const Extends& str){ this->append(str); return *this; }
    StringT& operator << (const char* chars){ Append(chars); return *this; }
    StringT& operator << (const wchar_t* chars){ Append(chars); return *this; }
};

typedef StringT<char> String;
typedef StringT<wchar_t> WString;
typedef StringT<tchar_t> TString;

} // namespace xos

#endif // _XOS_STRING_HPP_ 

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
///   File: string.hpp
///
/// Author: $author$
///   Date: 8/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_STRING_HPP
#define _XOS_NADIR_XOS_BASE_STRING_HPP

#include "xos/base/types.hpp"
#include "xos/base/base.hpp"
#include <string>

namespace xos {
namespace base {

typedef implement_base string_implement;
typedef std::basic_string<char> string_extend;
typedef std::basic_string<tchar_t> tstring_extend;
typedef std::basic_string<wchar_t> wstring_extend;
///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string<TChar>, class TImplements = string_implement>

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TChar Char;

    using TExtends::append;
    using TExtends::assign;
    using TExtends::compare;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const wchar_t* chars, size_t length) {
        this->append(chars, length);
    }
    stringt(const wchar_t* chars) {
        this->append(chars);
    }
    stringt(const char* chars, size_t length) {
        this->append(chars, length);
    }
    stringt(const char* chars) {
        this->append(chars);
    }
    stringt(const wstring_extend& copy) {
        this->append(copy.c_str());
    }
    stringt(const string_extend& copy) {
        this->append(copy.c_str());
    }
    stringt(const stringt& copy): Extends(copy) {
    }
    stringt() {
    }
    virtual ~stringt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign(const wchar_t* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assign(const wchar_t* chars, size_t length) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& append(const wchar_t* chars) {
        if ((chars)) {
            for (wchar_t c = *chars; c != 0; ++chars) {
                TChar tc = ((TChar)c);
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& append(const wchar_t* chars, size_t length) {
        if ((chars) && (length)) {
            for (; length > 0; --length, ++chars) {
                TChar tc = ((TChar)(*chars));
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign(const char* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assign(const char* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual stringt& append(const char* chars) {
        if ((chars)) {
            for (char c = *chars++; c != 0; c = *chars++) {
                TChar tc = ((TChar)c);
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& append(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (; length > 0; --length, ++chars) {
                TChar tc = ((TChar)(*chars));
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assignx(const void* in, size_t length, bool upper_case = false) {
        this->clear();
        this->appendx(in, length, upper_case);
        return *this;
    }
    virtual stringt& assign0x(const void* in, size_t length, bool upper_case = false) {
        this->clear();
        this->append0x(in, length, upper_case);
        return *this;
    }
    virtual stringt& appendx(const void* in, size_t length, bool upper_case = false) {
        const byte_t* bytes = (const byte_t*)(in);
        if ((bytes) && (length)) {
            TChar x[2];
            byte_t b;
            for (; 0 < length; --length) {
                b = (*bytes++);
                x[0] = dtox(b >> 4, upper_case);
                x[1] = dtox(b & 15, upper_case);
                append(x, 2);
            }
        }
        return *this;
    }
    virtual stringt& append0x(const void* in, size_t length, bool upper_case = false) {
        const byte_t* bytes = (const byte_t*)(in);
        if ((bytes) && (length)) {
            byte_t b = (*bytes);
            TChar x[5];

            x[0] = ((TChar)',');
            x[1] = ((TChar)'0');
            x[2] = ((TChar)((upper_case)?('X'):('x')));
            x[3] = dtox(b >> 4, upper_case);
            x[4] = dtox(b & 15, upper_case);
            append(x+1, 4);

            for (++bytes, --length; length > 0; --length, ++bytes) {
                b = (*bytes);
                x[3] = dtox(b >> 4, upper_case);
                x[4] = dtox(b & 15, upper_case);
                append(x, 5);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TChar dtox(byte_t d, bool upper_case = false) const {
        char a = (upper_case)?('A'):('a');
        TChar x = (TChar)(0);
        if ((0 <= d) && (9 >= d))
            x = (TChar)(('0') +  d);
        else
        if ((10 <= d) && (15 >= d))
            x = (TChar)((a) + (d - 10));
        return x;
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare_begin
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin_case(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin_case(const char* to_chars) const {
        return this->compare_begin_case(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin_case(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin_case(const wchar_t* to_chars) const {
        return this->compare_begin_case(to_chars, wchars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin(const char* to_chars) const {
        return this->compare_begin(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin(const wchar_t* to_chars) const {
        return this->compare_begin(to_chars, wchars_t::size(to_chars));
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare_end
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end_case(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end_case(const char* to_chars) const {
        return this->compare_end_case(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end_case(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end_case(const wchar_t* to_chars) const {
        return this->compare_end_case(to_chars, wchars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end(const char* to_chars) const {
        return this->compare_end(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end(const wchar_t* to_chars) const {
        return this->compare_end(to_chars, wchars_t::size(to_chars));
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_case(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_case(const char* to_chars) const {
        return this->compare_case(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_case(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_case(const wchar_t* to_chars) const {
        return this->compare_case(to_chars, wchars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare(const char* to_chars) const {
        return this->compare(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare(const wchar_t* to_chars) const {
        return this->compare(to_chars, wchars_t::size(to_chars));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TChar to_lower(TChar c) const {
        static const TChar A = ((TChar)'A');
        static const TChar Z = ((TChar)'Z');
        static const TChar a = ((TChar)'a');
        if ((c >= A) && (c <= Z))
            c = a + (c - A);
        return c;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* chars(size_t& length) const {
        length = this->length();
        return this->c_str();
    }
    virtual const TChar* chars() const {
        return this->c_str();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* end_chars
    (const char* chars, size_t length, size_t to_length) const {
        if ((chars) && (length >= to_length))
            return chars + length - to_length;
        return chars;
    }
    virtual const wchar_t* end_chars
    (const wchar_t* chars, size_t length, size_t to_length) const {
        if ((chars) && (length >= to_length))
            return chars + length - to_length;
        return chars;
    }
};

typedef stringt<char> string;
typedef stringt<wchar_t> wstring;
typedef stringt<tchar_t> tstring;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_STRING_HPP 

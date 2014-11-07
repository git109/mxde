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
///   File: name.hpp
///
/// Author: $author$
///   Date: 11/6/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_PATH_DIRECTORY_NAME_HPP
#define _EV_FS_PATH_DIRECTORY_NAME_HPP

#include "ev/base/base.hpp"

#define EV_FS_PATH_DIRECTORY_NORMAL_NAME_SEPARATOR '/'

#define EV_FS_PATH_DIRECTORY_NAME_SEPARATOR \
    EV_FS_PATH_DIRECTORY_NORMAL_NAME_SEPARATOR

namespace ev {
namespace fs {
namespace path {
namespace directory {

typedef string_implements name_implements;
typedef string_t name_extends;
///////////////////////////////////////////////////////////////////////
///  Class: namet
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = name_extends, class TImplements = name_implements>

class _EXPORT_CLASS namet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    namet(const char* chars, size_t length)
    : Extends(chars, length),
      separator_((char_t)(EV_FS_PATH_DIRECTORY_NAME_SEPARATOR)) {
    }
    namet(const char* chars)
    : Extends(chars),
      separator_((char_t)(EV_FS_PATH_DIRECTORY_NAME_SEPARATOR)) {
    }
    namet(const wchar_t* chars, size_t length)
    : Extends(chars, length),
      separator_((char_t)(EV_FS_PATH_DIRECTORY_NAME_SEPARATOR)) {
    }
    namet(const wchar_t* chars)
    : Extends(chars),
      separator_((char_t)(EV_FS_PATH_DIRECTORY_NAME_SEPARATOR)) {
    }
    namet(const namet& copy)
    : Extends(copy),
      separator_((char_t)(EV_FS_PATH_DIRECTORY_NAME_SEPARATOR)) {
    }
    namet(): separator_((char_t)(EV_FS_PATH_DIRECTORY_NAME_SEPARATOR)) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TExtends& assign(const char* chars, size_t length) {
        this->clear();
        return TExtends::append(chars, length);
    }
    virtual TExtends& assign(const char* chars) {
        this->clear();
        return TExtends::append(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual TExtends& assign(const wchar_t* chars, size_t length) {
        this->clear();
        return TExtends::append(chars, length);
    }
    virtual TExtends& assign(const wchar_t* chars) {
        this->clear();
        return TExtends::append(chars);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TExtends& append(const char* chars, size_t length) {
        append_separator();
        return TExtends::append(chars, length);
    }
    virtual TExtends& append(const char* chars) {
        append_separator();
        return TExtends::append(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual TExtends& append(const wchar_t* chars, size_t length) {
        append_separator();
        return TExtends::append(chars, length);
    }
    virtual TExtends& append(const wchar_t* chars) {
        append_separator();
        return TExtends::append(chars);
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool append_separator() {
        const char_t* chars;
        size_t length;
        if ((chars = this->chars(length)) && (0 < (length))) {
            if (separator_ != (chars[length-1])) {
                Extends::append(&separator_, 1);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t separator_;
};
typedef namet<> name;

} // namespace directory 
} // namespace path 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_PATH_DIRECTORY_NAME_HPP 

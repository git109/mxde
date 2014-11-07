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
///   File: parts.hpp
///
/// Author: $author$
///   Date: 11/3/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_PATH_PARTS_HPP
#define _EV_FS_PATH_PARTS_HPP

#include "ev/fs/path/separator.hpp"
#include "ev/base/base.hpp"

namespace ev {
namespace fs {
namespace path {

typedef separate::events parts_events;
typedef separator parts_separator;
typedef string_implements parts_implements;
typedef string_t parts_extends;
///////////////////////////////////////////////////////////////////////
///  Class: partst
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t,
 class TEvents = parts_events, class TSeparator = parts_separator,
 class TImplements = parts_implements, class TExtends = parts_extends>

class _EXPORT_CLASS partst
: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TEvents events_t;
    typedef TSeparator separator_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    partst(): directory_separator_((char_t)'/'), extension_separator_((char_t)'.') {
    }
    virtual ~partst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual partst& assign(const char_t* chars, size_t length) {
        clear();
        Extends::assign(chars, length);
        separate();
        return *this;
    }
    virtual partst& assign(const char_t* chars) {
        clear();
        Extends::assign(chars);
        separate();
        return *this;
    }
    virtual partst& clear() {
        Extends::clear();
        host_.clear();
        volume_.clear();
        directory_.clear();
        file_name_.clear();
        file_base_.clear();
        file_extension_.clear();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_directory(const char_t* chars, size_t length) {
        directory_.assign(chars, length);
        return directory_;
    }
    virtual const string_t& set_directory(const char_t* chars) {
        directory_.assign(chars);
        return directory_;
    }
    virtual const string_t& directory() const {
        return directory_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_name(const char_t* chars, size_t length) {
        file_name_.assign(chars, length);
        return file_name_;
    }
    virtual const string_t& set_file_name(const char_t* chars) {
        file_name_.assign(chars);
        return file_name_;
    }
    virtual const string_t& file_name() const {
        return file_name_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_base(const char_t* chars, size_t length) {
        file_base_.assign(chars, length);
        return file_base_;
    }
    virtual const string_t& set_file_base(const char_t* chars) {
        file_base_.assign(chars);
        return file_base_;
    }
    virtual const string_t& file_base() const {
        return file_base_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& set_file_extension(const char_t* chars, size_t length) {
        file_extension_.assign(chars, length);
        return file_extension_;
    }
    virtual const string_t& set_file_extension(const char_t* chars) {
        file_extension_.assign(chars);
        return file_extension_;
    }
    virtual const string_t& file_extension() const {
        return file_extension_;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool separate() {
        separator_t separator(*this);
        return separator.separate(this->c_str(), this->length());
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_host(const char_t* chars, size_t length) {
        host_.assign(chars, length);
    }
    virtual void on_volume(const char_t* chars, size_t length) {
        volume_.assign(chars, length);
    }
    virtual void on_root_directory() {
        directory_.assign(&directory_separator_, 1);
    }
    virtual void on_current_directory() {
        on_append_directory();
        directory_.append(&extension_separator_, 1);
    }
    virtual void on_parent_directory() {
        on_append_directory();
        directory_.append(&extension_separator_, 1);
        directory_.append(&extension_separator_, 1);
    }
    virtual void on_directory_name(const char_t* chars, size_t length) {
        on_append_directory();
        directory_.append(chars, length);
    }
    virtual void on_file_name(const char_t* chars, size_t length) {
        file_name_.assign(chars, length);
    }
    virtual void on_file_base(const char_t* chars, size_t length) {
        file_base_.assign(chars, length);
    }
    virtual void on_file_extension(const char_t* chars, size_t length) {
        file_extension_.assign(chars, length);
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_append_directory() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = directory_.c_str()) && (d_length = directory_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                directory_.append(&directory_separator_, 1);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t directory_separator_, extension_separator_;
    string_t host_, volume_, directory_, file_name_, file_base_, file_extension_;
};
typedef partst<> parts;

} // namespace path 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_PATH_PARTS_HPP 

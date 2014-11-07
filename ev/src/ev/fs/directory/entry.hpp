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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_DIRECTORY_ENTRY_HPP
#define _EV_FS_DIRECTORY_ENTRY_HPP

#include "ev/fs/entry.hpp"

#define EV_FS_DIRECTORY_SEPARATOR_CHAR '/'
#define EV_FS_DIRECTORY_PARENT_CHARS ".."
#define EV_FS_DIRECTORY_CURRENT_CHARS "."

namespace ev {
namespace fs {
namespace directory {

typedef fs::entry_implements entry_implements;
typedef fs::entry entry_extends;
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = entry_implements, class TExtends = entry_extends>

class _EXPORT_CLASS entryt
: virtual public TImplements, virtual public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    entryt()
    : separator_((char_t)(EV_FS_DIRECTORY_SEPARATOR_CHAR)),
      parent_(EV_FS_DIRECTORY_PARENT_CHARS),
      current_(EV_FS_DIRECTORY_CURRENT_CHARS) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_path(const char_t* chars, size_t length) {
        path_.assign(chars, length);
        on_set_path(path_.c_str(), path_.length());
        return path_.c_str();
    }
    virtual const char_t* set_path(const char_t* chars) {
        path_.assign(chars);
        on_set_path(path_.c_str(), path_.length());
        return path_.c_str();
    }
    virtual const char_t* path(size_t& length) const {
        length = path_.length();
        return path_.c_str();
    }
    virtual const char_t* path() const {
        return path_.c_str();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_directory(const char_t* chars, size_t length) {
        directory_.assign(chars, length);
        on_set_directory(directory_.c_str(), directory_.length());
        return directory_.c_str();
    }
    virtual const char_t* set_directory(const char_t* chars) {
        directory_.assign(chars);
        on_set_directory(directory_.c_str(), directory_.length());
        return directory_.c_str();
    }
    virtual const char_t* directory(size_t& length) const {
        length = directory_.length();
        return directory_.c_str();
    }
    virtual const char_t* directory() const {
        return directory_.c_str();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* parent(size_t& length) const {
        length = parent_.length();
        return parent_.c_str();
    }
    virtual const char_t* parent() const {
        return parent_.c_str();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* current(size_t& length) const {
        length = current_.length();
        return current_.c_str();
    }
    virtual const char_t* current() const {
        return current_.c_str();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t& separator() const {
        return separator_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_circular() const {
        return is_circular_;
    }
    virtual bool is_parent() const {
        return is_parent_;
    }
    virtual bool is_current() const {
        return is_current_;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_set_path(const char_t* chars, size_t length) {
    }
    virtual void on_set_directory(const char_t* chars, size_t length) {
    }
    virtual void on_set_name(const char_t* chars, size_t length) {
        const char_t* pchars; size_t plength;
        if ((pchars = path(plength)) && (0 < (plength))) {
            if ((pchars[plength-1]) != (separator())) {
                path_.append(&separator(),1);
            }
        }
        path_.append(chars, length);
        is_current_ = !(current_.compare(chars, length));
        is_parent_ = !(parent_.compare(chars, length));
        is_circular_ = (is_current_ || is_parent_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t separator_;
    const string_t parent_, current_;
    string_t path_, directory_;
    bool_t is_circular_, is_current_, is_parent_;
};
typedef entryt<> entry;

} // namespace directory 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_DIRECTORY_ENTRY_HPP 

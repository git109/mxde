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
#ifndef _EV_FS_ENTRY_HPP
#define _EV_FS_ENTRY_HPP

#include "ev/fs/time.hpp"
#include "ev/base/date.hpp"
#include "ev/base/time.hpp"
#include "ev/base/base.hpp"

namespace ev {
namespace fs {

typedef uint64_t entry_size_t;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef int entry_type;
enum {
    entry_type_none = 0,

    entry_type_file          = 1,
    entry_type_directory     = (1 << 1),
    entry_type_symbolic_link = (1 << 2),
    entry_type_hard_link     = (1 << 3),
    entry_type_block_device  = (1 << 4),
    entry_type_char_device   = (1 << 5),
    entry_type_pipe          = (1 << 6),
    entry_type_socket        = (1 << 7),

    entry_type_next,
    entry_type_any = (((entry_type_next-1) << 1) - 1)
};

typedef implement_base entry_implements;
typedef base entry_extends;
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = entry_implements, class TExtends = entry_extends>

class _EXPORT_CLASS entryt: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS contents {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        contents(const entryt& of_entry): of_entry_(of_entry) {}
        virtual ~contents() {}

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual entry_size_t copy(contents& to) {
            entry_size_t count = 0;
            return count;
        }

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual int compare(contents& to) {
            int unequal = 0;
            return unequal;
        }

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        const entryt& of_entry_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    entryt()
    : size_(0), type_(entry_type_none), times_(when_none),
      time_modified_(when_modified), time_accessed_(when_accessed),
      time_changed_(when_changed), time_created_(when_created) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool exists_is_type
    (const char_t* path, ev::fs::entry_type is_type) {
        ev::fs::entry_type type = exists(path);
        if ((ev::fs::entry_type_none == type) || (type != is_type))
            return false;
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::entry_type exists(const char_t* path) {
        return ev::fs::entry_type_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void clear() {
        size_ = 0;
        type_ = entry_type_none;
        times_ = when_none;
        name_.clear();
        time_modified_.clear();
        time_accessed_.clear();
        time_changed_.clear();
        time_created_.clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual time_when set_times_to_set(const entryt& e, bool is_local = false) {
        time_when times = when_none;
        const time& time_modified = e.time_modified();
        const time& time_accessed = e.time_accessed();
        const time& time_changed = e.time_changed();
        const time& time_created = e.time_created();
        times = set_times_to_set
        (time_modified, time_accessed,
         time_changed, time_created, is_local);
        return times;
    }
    virtual time_when set_times_to_set
    (const time& time_modified, const time& time_accessed,
     const time& time_changed, const time& time_created,
     bool is_local = false) {
        time_when times = when_none;
        return times;
    }
    virtual time_when set_times_set() {
        time_when times = when_none;
        return times;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_size_t copy
    (contents& _contents, contents& to_contents) const {
        entry_size_t count = _contents.copy(to_contents);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare
    (contents& _contents, contents& to_contents, const entryt& to) const {
        int unequal = 0;
        if ((size_ < to.size_)) {
            unequal = -1;
        } else {
            if ((size_ > to.size_)) {
                unequal = 1;
            } else {
                unequal = compare_contents(_contents, to_contents);
            }
        }
        return unequal;
    }
    virtual int compare_contents
    (contents& _contents, contents& to_contents) const {
        int unequal = _contents.compare(to_contents);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_newer_than_or_equal(const entryt& e) const {
        if ((time_modified_) && (e.time_modified_)) {
            int unequal;
            if (0 <= (unequal = time_modified_.compare(e.time_modified_))) {
                return true;
            }
        }
        return false;
    }
    virtual bool is_older_than_or_equal(const entryt& e) const {
        if ((time_modified_) && (e.time_modified_)) {
            int unequal;
            if (0 >= (unequal = time_modified_.compare(e.time_modified_))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_newer_than(const entryt& e) const {
        if ((time_modified_) && (e.time_modified_)) {
            int unequal;
            if (0 < (unequal = time_modified_.compare(e.time_modified_))) {
                return true;
            }
        }
        return false;
    }
    virtual bool is_older_than(const entryt& e) const {
        if ((time_modified_) && (e.time_modified_)) {
            int unequal;
            if (0 > (unequal = time_modified_.compare(e.time_modified_))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* path(size_t& length) const {
        length = 0;
        return 0;
    }
    virtual const char_t* path() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_name(const char_t* chars, size_t length) {
        name_.assign(chars, length);
        on_set_name(name_.c_str(), name_.length());
        return name_.c_str();
    }
    virtual const char_t* set_name(const char_t* chars) {
        name_.assign(chars);
        on_set_name(name_.c_str(), name_.length());
        return name_.c_str();
    }
    virtual const char_t* name(size_t& length) const {
        length = name_.length();
        return name_.c_str();
    }
    virtual const char_t* name() const {
        return name_.c_str();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_size_t set_size(entry_size_t size) {
        size_ = size;
        on_set_size(size);
        return size_;
    }
    virtual entry_size_t size() const {
        return size_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_type set_type(entry_type type) {
        type_ = type;
        on_set_type(type);
        return type_;
    }
    virtual entry_type type() const {
        return type_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const time& set_time_modified(const time& to) {
        times_ |= when_modified;
        time_modified_ = to;
        return time_modified_;
    }
    virtual const time& time_modified() const {
        return time_modified_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const time& set_time_accessed(const time& to) {
        times_ |= when_accessed;
        time_accessed_ = to;
        return time_accessed_;
    }
    virtual const time& time_accessed() const {
        return time_accessed_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const time& set_time_changed(const time& to) {
        times_ |= when_changed;
        time_changed_ = to;
        return time_changed_;
    }
    virtual const time& time_changed() const {
        return time_changed_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const time& set_time_created(const time& to) {
        times_ |= when_created;
        time_created_ = to;
        return time_created_;
    }
    virtual const time& time_created() const {
        return time_created_;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_set_name(const char_t* chars, size_t length) {
    }
    virtual void on_set_size(entry_size_t size) {
    }
    virtual void on_set_type(entry_type type) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    entry_type type_;
    entry_size_t size_;
    string_t name_;
    time_when times_;
    time time_modified_, time_accessed_, time_changed_, time_created_;
};
typedef entryt<> entry;

} // namespace fs 
} // namespace ev 

#endif // _EV_FS_ENTRY_HPP 

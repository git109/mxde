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
///   Date: 11/2/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_OS_UNIX_FS_ENTRY_HPP
#define _EV_OS_UNIX_FS_ENTRY_HPP

#include "ev/fs/entry.hpp"

#include <sys/stat.h>
#include <utime.h>

namespace ev {
namespace os {
namespace unix {
namespace fs {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS stat_t {
public:
    stat_t() { memset(&stat_, 0, sizeof(stat_)); }
    virtual ~stat_t() {}
    ///////////////////////////////////////////////////////////////////////
    virtual struct stat* operator & () const { return (struct stat*)(&stat_); }
    virtual operator struct stat&() const { return (struct stat&)(stat_); }
    ///////////////////////////////////////////////////////////////////////
protected:
    struct stat stat_;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS utimbuf_t {
public:
    utimbuf_t() { memset(&utimbuf_, 0, sizeof(utimbuf_)); }
    virtual ~utimbuf_t() {}
    ///////////////////////////////////////////////////////////////////////
    virtual struct utimbuf* operator & () const { return (struct utimbuf*)(&utimbuf_); }
    virtual operator struct utimbuf&() const { return (struct utimbuf&)(utimbuf_); }
    ///////////////////////////////////////////////////////////////////////
protected:
    struct utimbuf utimbuf_;
};

typedef ev::fs::entry_implements entry_implements;
typedef ev::fs::entry entry_extends;
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
    entryt() {
    }
    virtual ~entryt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::entry_type exists(const char_t* path) {
        int err = 0;
        if (!(err = stat(path, &st_))) {
            if (!(err = lstat(path, &lst_))) {
                if ((get_found_attributes())) {
                    return this->type();
                }
            } else {
                EV_LOG_DEBUG("failed " << errno << " on lstat(\"" << path << "\",...)");
            }
        } else {
            EV_LOG_DEBUG("failed " << errno << " on stat(\"" << path << "\",...)");
        }
        return ev::fs::entry_type_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::entry_type get_found() {
        const char_t* path;
        if ((path = this->path())) {
            int err = 0;
            if (!(err = stat(path, &st_))) {
                if (!(err = lstat(path, &lst_))) {
                    if ((get_found_attributes())) {
                        return this->type();
                    }
                } else {
                    EV_LOG_ERROR("failed " << errno << " on lstat(\"" << path << "\",...)");
                }
            } else {
                EV_LOG_ERROR("failed " << errno << " on stat(\"" << path << "\",...)");
            }
        }
        return ev::fs::entry_type_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::time_when get_found_attributes() {
        if ((get_found_type())) {
            if ((get_found_times())) {
                return this->type();
            }
        }
        return ev::fs::entry_type_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::time_when set_times_to_set
    (const ev::fs::time& time_modified, const ev::fs::time& time_accessed,
     const ev::fs::time& time_changed, const ev::fs::time& time_created,
     bool is_local = false) {
        struct stat& st = to_st_;
        ev::fs::time_when times = ev::fs::when_none;
        struct tm tm;
        time_t t;

        from_time(tm, time_modified, is_local);
        if (0 <= (from_system_time(t, tm, is_local))) {
            st.st_mtime = t;
            times |= ev::fs::when_modified;
        }
        from_time(tm, time_accessed, is_local);
        if (0 <= (from_system_time(t, tm, is_local))) {
            st.st_atime = t;
            times |= ev::fs::when_accessed;
        }
        return times;
    }
    virtual ev::fs::time_when set_times_set() {
        ev::fs::time_when times = ev::fs::when_none;
        const char_t* chars;
        size_t length;

        if ((chars = this->path(length)) && (0 < length)) {
            const struct stat& st = st_;
            struct utimbuf ut = ut_;
            int err;

            ut.actime = st.st_atime;
            ut.modtime = st.st_mtime;

            if (!(err = utime(chars, &ut))) {
                times |= (ev::fs::when_accessed | ev::fs::when_modified);
            } else {
                EV_LOG_ERROR("failed on " << errno << " on utime()");
            }
        }
        return times;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::time_when get_found_times() {
        const struct stat& st = st_;
        bool is_local = 0;
        ev::fs::time_when when = ev::fs::when_none;
        struct tm tm;

        if ((to_system_time(tm, st.st_mtime, is_local))) {
            to_time(this->time_modified_, tm, is_local);
            when |= ev::fs::when_modified;
        }
        if ((to_system_time(tm, st.st_atime, is_local))) {
            to_time(this->time_accessed_, tm, is_local);
            when |= ev::fs::when_accessed;
        }
        if ((to_system_time(tm, st.st_ctime, is_local))) {
            to_time(this->time_changed_, tm, is_local);
            when |= ev::fs::when_changed;
        }
        return when;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::entry_type get_found_type() {
        const struct stat& st = st_;
        const struct stat& lst = lst_;
        off_t size;
        mode_t fmt;

        if (S_IFDIR == (S_IFDIR & st.st_mode)) {
            this->set_type(this->type() & ~(ev::fs::entry_type_file));
            this->set_type(this->type() | ev::fs::entry_type_directory);
        } else {
            this->set_type(this->type() & ~(ev::fs::entry_type_directory));
            this->set_type(this->type() | ev::fs::entry_type_file);
        }

        if (S_IFLNK == (fmt = (S_IFMT & (lst.st_mode)))) {
            this->set_type(this->type() | ev::fs::entry_type_symbolic_link);
        }

        if (0 <= (size = st.st_size)) {
            this->set_size((ev::fs::entry_size_t)(size));
        }
        return this->type();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::time& to_time
    (ev::fs::time& to, const struct tm& from, bool is_local = false) {
        to.set_year(from.tm_year+1900);
        to.set_month(from.tm_mon+1);
        to.set_day(from.tm_mday);
        to.set_hour(from.tm_hour);
        to.set_minute(from.tm_min);
        to.set_second(from.tm_sec);
        EV_LOG_DEBUG("time " << to.when_name() << " = " << to.month() << "/" << to.day() << "/" << to.year());
        return to;
    }
    virtual struct tm& from_time
    (struct tm& to, const ev::fs::time& from, bool is_local = false) {
        memset(&to, 0, sizeof(struct tm));
        to.tm_year = from.year()-1900;
        to.tm_mon = from.month()-1;
        to.tm_mday = from.day();
        to.tm_hour = from.hour();
        to.tm_min = from.minute();
        to.tm_sec = from.second();
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual struct tm* to_system_time
    (struct tm& tm, const time_t& time, bool is_local = false) {
        struct tm* t = 0;
        if (is_local) {
            if (!(t = localtime_r(&time, &tm))) {
                EV_LOG_ERROR("failed " << errno << " on localtime_r()");
            }
        } else {
            if (!(t = gmtime_r(&time, &tm))) {
                EV_LOG_ERROR("failed " << errno << " on gmtime_r()");
            }
        }
        return t;
    }
    virtual time_t& from_system_time
    (time_t& to, const struct tm& from, bool is_local = false) {
        struct tm tm = from;
        if ((is_local)) {
            if (0 > (to = mktime(&tm))) {
                EV_LOG_ERROR("failed " << errno << " on mktime()");
            }
        } else {
            if (0 > (to = timegm(&tm))) {
                EV_LOG_ERROR("failed " << errno << " on timegm()");
            }
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    stat_t st_, lst_, to_st_;
    utimbuf_t ut_;
};
typedef entryt<> entry;

} // namespace fs 
} // namespace unix 
} // namespace os 
} // namespace ev 

#endif // _EV_OS_UNIX_FS_ENTRY_HPP 

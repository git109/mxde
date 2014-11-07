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
///   File: time.hpp
///
/// Author: $author$
///   Date: 11/2/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_BASE_TIME_HPP
#define _EV_BASE_TIME_HPP

#include "ev/base/timezone.hpp"
#include "ev/base/base.hpp"

namespace ev {

typedef implement_base time_implements;
typedef base time_extends;
///////////////////////////////////////////////////////////////////////
///  Class: timet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = time_implements, class TExtends = time_extends>

class _EXPORT_CLASS timet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    timet()
    : hour_(0), minute_(0), second_(0),
      msecond_(0), usecond_(0), timezone_(0) {
    }
    virtual ~timet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const timet& to) const {
        return compare_time(to);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_time(const timet& to) const {
        int unequal = 0;
        if (!(unequal = compare_hour(to.hour())))
            if (!(unequal = compare_minute(to.minute())))
                if (!(unequal = compare_second(to.second())))
                    if (!(unequal = compare_msecond(to.msecond())))
                        unequal = compare_usecond(to.usecond());
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void clear() {
        set_hour(0);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual hours_t set_hour(hours_t to) {
        hour_= to;
        set_minute(0);
        return hour_;
    }
    virtual hours_t hour() const {
        return hour_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual minutes_t set_minute(minutes_t to) {
        minute_= to;
        set_second(0);
        return minute_;
    }
    virtual minutes_t minute() const {
        return minute_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual seconds_t set_second(seconds_t to) {
        second_= to;
        set_msecond(0);
        return second_;
    }
    virtual seconds_t second() const {
        return second_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual mseconds_t set_msecond(mseconds_t to) {
        msecond_= to;
        set_usecond(0);
        return msecond_;
    }
    virtual mseconds_t msecond() const {
        return msecond_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual useconds_t set_usecond(useconds_t to) {
        usecond_= to;
        return usecond_;
    }
    virtual useconds_t usecond() const {
        return usecond_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_hour(hours_t to) const {
        if ((hour_ < to)) {
            return -1;
        } else {
            if ((hour_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_minute(minutes_t to) const {
        if ((minute_ < to)) {
            return -1;
        } else {
            if ((minute_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_second(seconds_t to) const {
        if ((second_ < to)) {
            return -1;
        } else {
            if ((second_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_msecond(mseconds_t to) const {
        if ((msecond_ < to)) {
            return -1;
        } else {
            if ((msecond_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_usecond(useconds_t to) const {
        if ((usecond_ < to)) {
            return -1;
        } else {
            if ((usecond_ > to)) {
                return 1;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int operator != (const timet& to) const {
        return this->compare(to);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    hours_t hour_;
    minutes_t minute_;
    seconds_t second_;
    mseconds_t msecond_;
    useconds_t usecond_;
    timezone* timezone_;
    bool_t is_local, is_12, is_pm;
};
typedef timet<> time;

} // namespace ev 

#endif // _EV_BASE_TIME_HPP 

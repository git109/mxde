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
#ifndef _EV_FS_TIME_HPP
#define _EV_FS_TIME_HPP

#include "ev/base/date.hpp"

namespace ev {
namespace fs {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef int time_when;
enum {
    when_none     = 0,
    when_modified = 1,
    when_accessed = (1 << 1),
    when_changed  = (1 << 2),
    when_created  = (1 << 3)
};

typedef date_implements time_implements;
typedef date time_extends;
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
    timet(time_when when = when_none): when_(when) {
    }
    virtual ~timet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* when_name() const {
        switch (when_) {
        case when_modified: return "modified";
        case when_accessed: return "accessed";
        case when_changed: return "changed";
        case when_created: return "created";
        }
        return "none";
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    time_when when_;
};
typedef timet<> time;

} // namespace fs 
} // namespace ev 

#endif // _EV_FS_TIME_HPP 

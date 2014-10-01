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
///   File: process.hpp
///
/// Author: $author$
///   Date: 9/18/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_PROCESS_HPP
#define _XOS_NADIR_XOS_MT_UNIX_PROCESS_HPP

#include "xos/mt/process.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

namespace xos {
namespace mt {
namespace unix {

typedef base::attachert<pid_t, int, -1, mt::process> process_attacher;
typedef base::creatort<pid_t, int, -1, process_attacher> process_creator;
typedef base::attachedt<pid_t, int, -1, process_creator, base::base> process_attached;
typedef base::createdt<pid_t, int, -1, process_creator, process_attached> process_created;
typedef process_creator process_implements;
typedef process_created process_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = process_implements, class TExtends = process_extends>

class _EXPORT_CLASS processt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processt() {
    }
    virtual ~processt() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (const char_t* path, char_t** argv, char_t** env,
     const int* fdup, bool is_detached = false) {
        if ((this->destroyed())) {
            pid_t pid = (pid_t)(-1);

            XOS_LOG_TRACE("fork()...");
            if (0 < (pid = fork())) {
                XOS_LOG_TRACE("...fork() pid = " << pid << "");
                this->attach_created(pid);
                return true;
            } else {
                if (0 > (pid)) {
                    XOS_LOG_ERROR("failed " << errno << "on fork()");
                } else {
                    int err = 1;

                    XOS_LOG_TRACE("chlid process...");
                    XOS_LOG_TRACE("...chlid process");
                    exit(err);
                }
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->joined())) {
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool joined() {
        if ((this->is_forked())) {
            return this->join();
        }
        return true;
    }
    virtual bool join() {
        this->set_is_forked(false);
        return false;
    }
    virtual wait_status try_join() {
        return wait_failed;
    }
    virtual wait_status timed_join(mseconds_t milliseconds) {
        return wait_failed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() {
        pid_t pid = (pid_t)(-1);

        if (0 < (pid = this->attached_to())) {
            int options = 0;
            int status = 0;

            XOS_LOG_TRACE("waitpid(" << pid << ",...)...");
            if (!(pid != waitpid(pid, &status, options))) {
                XOS_LOG_TRACE("...waitpid(" << pid << ",...)");
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on waitpid(" << pid << ",...)");
            }
        }
        return false;
    }
    virtual wait_status try_wait() {
        pid_t pid = (pid_t)(-1);

        if (0 < (pid = this->attached_to())) {
            int options = WNOHANG;
            int status = 0;

            XOS_LOG_TRACE("waitpid(" << pid << ",...)...");
            if (!(pid != waitpid(pid, &status, options))) {
                XOS_LOG_TRACE("...waitpid(" << pid << ",...)");
                return wait_success;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on waitpid(" << pid << ",...)");
            }
        }
        return wait_failed;
    }
    virtual wait_status timed_wait(mseconds_t milliseconds) {
        return wait_invalid;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_forked(bool to = true) {
        is_forked_ = to;
        return is_forked_;
    }
    virtual bool is_forked() const {
        return is_forked_;
    }
    virtual bool is_joined() const {
        return !is_forked_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pid_t attach_created(pid_t detached, bool is_created = true) {
        pid_t attached = Extends::attach_created(detached);
        this->set_is_forked(is_created);
        return attached;
    }
    virtual pid_t detach_created(bool& is_created) {
        pid_t detached = Extends::detach_created(is_created);
        this->set_is_forked(false);
        return detached;
    }
    virtual pid_t detach() {
        pid_t detached = Extends::detach();
        this->set_is_forked(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_forked_;
};
typedef processt<> process;

} // namespace unix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_UNIX_PROCESS_HPP 
        


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
///   File: Thread.hpp
///
/// Author: $author$
///   Date: 10/7/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_OS_WINDOWS_CRT_THREAD_HPP
#define _XOS_OS_WINDOWS_CRT_THREAD_HPP

#include "xos/os/windows/Thread.hpp"

namespace xos {
namespace windows {
namespace crt {

typedef xos::Thread ThreadImplement;
typedef Attached<uintptr_t, int, 0, ExportBase, ThreadImplement> ThreadAttached;
typedef Opened<uintptr_t, int, 0, ThreadAttached, ThreadImplement> ThreadExtend;

class _EXPORT_CLASS Thread
: virtual public ThreadImplement,
  public ThreadExtend
{
public:
    typedef ThreadImplement Implements;
    typedef ThreadExtend Extends;

    Thread(Run& run): m_run(run) {
        if (!(Start())) {
            XOS_LOG_ERROR("failed on Start()");
            throw (Error(Error::Failed));
        }
    }
    virtual ~Thread() {
        if ((m_isOpen)) {
            if (!(Close())) {
                XOS_LOG_ERROR("failed on Close()");
            }
        }
    }

    virtual bool Start() {
        bool isStarted = false;
        uintptr_t detached = 0;
        void* security_attributes=0;
        unsigned stack_size=0;
        unsigned init_flag=0;
        unsigned tid;

        if ((isStarted = (0 != (detached = (_beginthreadex
            (security_attributes, stack_size, StartRoutine, 
             (void*)(this), init_flag, &tid)))))) {
            Attach(detached, isStarted);
        }
        return isStarted;
    }
    virtual bool Close() {
        if (!(Join())) {
            XOS_LOG_ERROR("failed on Join()");
            return false;
        }
        return true;
    }
    virtual bool Join() {
        return (Success == (TimedJoin(INFINITE)));
    }
    virtual Status TryJoin() {
        return TimedJoin(0);
    }
    virtual Status TimedJoin(mseconds_t waitMilliSeconds) {
        Status status = Failed;
        bool isOpen = false;
        uintptr_t detached = 0;
        DWORD result;
        if ((detached = m_attachedTo)) {
            XOS_LOG_TRACE("wait on WaitForSingleObject()...");
            if (WAIT_OBJECT_0 == (result = WaitForSingleObject((HANDLE)(detached), (DWORD)(waitMilliSeconds)))) {
                XOS_LOG_TRACE("...WAIT_OBJECT_0 on WaitForSingleObject()");
                Detach(isOpen);
                if ((CloseHandle((HANDLE)(detached)))) {
                    status = Success;
                } else {
                    XOS_LOG_ERROR("failed on CloseHandle()");
                }
            } else {
                switch(result) {
                case WAIT_TIMEOUT:
                    XOS_LOG_TRACE("...WAIT_TIMEOUT on WaitForSingleObject()");
                    status = Busy;
                    break;
                case WAIT_ABANDONED:
                    XOS_LOG_ERROR("...WAIT_ABANDONED on WaitForSingleObject()");
                    status = Interrupted;
                    break;
                }
            }
        }
        return status;
    }

protected:
    static unsigned __stdcall StartRoutine(void* param) {
        unsigned result = 0;
        Thread* t = 0;
        XOS_LOG_TRACE("in...");
        if ((t = (Thread*)(param))) {
            XOS_LOG_TRACE("t->m_run()...");
            t->m_run();
            XOS_LOG_TRACE("...t->m_run()");
        } else {
            XOS_LOG_ERROR("void* param == 0");
        }
        XOS_LOG_TRACE("...out");
        return result;
    }
    Run& m_run;
};

} // namespace crt 
} // namespace windows 
} // namespace xos 

#endif // _XOS_OS_WINDOWS_CRT_THREAD_HPP 

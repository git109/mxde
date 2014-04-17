////////////////////////////////////////////////////////////////////////
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
///   File: Clock.hpp
///
/// Author: $author$
///   Date: 1/7/2014
////////////////////////////////////////////////////////////////////////
#if !defined(_RESTAPP_EXAMPLES_CLOCK_IMPLEMENT_CLOCK_HPP)
#define _RESTAPP_EXAMPLES_CLOCK_IMPLEMENT_CLOCK_HPP

#include "examples/clock/Clock.hpp"
#include "xos/os/os/Thread.hpp"
#include "xos/os/os/Semaphore.hpp"
#include "xos/os/os/Mutex.hpp"
#include "xos/os/os/Time.hpp"

namespace restapp {
namespace examples {
namespace clock {
namespace server {
namespace implement {

typedef examples::Clock ClockExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Clock: public ClockExtend {
public:
    typedef ClockExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Clock(): m_waitMilliseconds(1000), m_tickThreadRun(*this), m_tickThread(0) {
        if (!(m_tickThreadLock.Create())) {
            XOS_LOG_ERROR("failed on m_tickThreadLock.Create()");
        }
        if (!(m_tickThreadStop.Create())) {
            XOS_LOG_ERROR("failed on m_tickThreadStop.Create()");
        }
    }
    virtual ~Clock() {
        if (!(m_tickThreadStop.Destroy())) {
            XOS_LOG_ERROR("failed on m_tickThreadStop.Destroy()");
        }
        if (!(m_tickThreadLock.Destroy())) {
            XOS_LOG_ERROR("failed on m_tickThreadLock.Destroy()");
        }
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool RestartService() {
        Daemon& daemon = Daemon::GetTheInstance();
        bool result = daemon.Restart();
        return result;
    }
    virtual bool StopService() {
        Daemon& daemon = Daemon::GetTheInstance();
        bool result = daemon.Stop();
        return result;
    }
    virtual bool Start() {
        bool result = false;
        try {
            volatile Locker lockr(m_tickThreadLock);
            if ((m_tickThread)) {
                XOS_LOG_ERROR("already started");
            } else {
                if ((m_tickThread = new TickThread(m_tickThreadRun))) {
                    result = true;
                }
            }
        } catch (const Error& error) {
            XOS_LOG_ERROR("caught error = " << error << " on lockr(m_tickThreadLock)");
            return false;
        }
        EventId id = (result)?(EventIdStart):(EventIdError);
        String what((result)?("started"):("already started"));
        Time when(GetCurrentTime());
        EventInfo info(what, when);
        OnEvent(id, info);
        return result;
    }
    virtual bool Stop() {
        bool result = false;
        try {
            volatile Locker lockr(m_tickThreadLock);
            if ((m_tickThread)) {
                m_tickThreadStop.Release();
                delete m_tickThread;
                m_tickThread = 0;
                result = true;
            } else {
                XOS_LOG_ERROR("already stopped");
            }
        } catch (const Error& error) {
            XOS_LOG_ERROR("caught error = " << error << " on lockr(m_tickThreadLock)");
            return false;
        }
        EventId id = (result)?(EventIdStop):(EventIdError);
        String what((result)?("stopped"):("already stopped"));
        Time when(GetCurrentTime());
        EventInfo info(what, when);
        OnEvent(id, info);
        return result;
    }
    virtual bool Tick() {
        bool result = true;
        Time theTime;
        GetCurrentTime(theTime);
        OnTickEvent(theTime);
        return result;
    }
    virtual int SetTickSeconds(const int& to) {
        int result = 0;
        if (0 < (to)) {
            try {
                volatile Locker lockr(m_tickThreadLock);
                m_waitMilliseconds = ((result = to) * 1000);
            } catch (const Error& error) {
                XOS_LOG_ERROR("caught error = " << error << " on lockr(m_tickThreadLock)");
                return result;
            }
        }
        EventId id = (0 < (to))?(EventIdSetTickSeconds):(EventIdError);
        String what((0 < (to))?("set tick seconds"):("set tick seconds < 1"));
        Time when(GetCurrentTime());
        EventInfo info(what, when);
        OnEvent(id, info);
        return result;
    }
    virtual int GetTickSeconds() {
        int result = 0;
        try {
            volatile Locker lockr(m_tickThreadLock);
            result = (m_waitMilliseconds)/1000;
        } catch (const Error& error) {
            XOS_LOG_ERROR("caught error = " << error << " on lockr(m_tickThreadLock)");
        }
        return result;
    }
    virtual int AddTickEventListener() {
        int result = 0;
        return result;
    }
    virtual int RemoveTickEventListener() {
        int result = 0;
        return result;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void RunTickThread() {
        mseconds_t waitMilliseconds = m_waitMilliseconds;
        Time theTime(2,2,2, 2,2,2);
        XOS_LOG_TRACE("in...");
        for (bool done = false; !done;) {
            try {
                volatile Locker lockr(m_tickThreadLock);
                waitMilliseconds = m_waitMilliseconds;
            } catch (const Error& error) {
                XOS_LOG_ERROR("caught error = " << error << " on lockr(m_tickThreadLock)");
                break;
            }
            XOS_LOG_TRACE("waiting on m_tickThreadStop...");
            try {
                volatile Waiter waitr(m_tickThreadStop, waitMilliseconds);
                XOS_LOG_TRACE("...waited on m_tickThreadStop");
                done = true;
            } catch (const WaitInterface::Status& status) {
                if (WaitInterface::Busy != (status)) {
                    XOS_LOG_TRACE("...interrupted on m_tickThreadStop");
                    done = true;
                } else {
                    XOS_LOG_TRACE("...busy on m_tickThreadStop");
                    GetCurrentTime(theTime);
                    OnTickEvent(theTime);
                }
            } catch (const Error& error) {
                XOS_LOG_ERROR("...failed " << error << " on wait");
                done = true;
            }
        }
        XOS_LOG_TRACE("...out");
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual Time GetCurrentTime() {
        Time theTime;
        return GetCurrentTime(theTime);
    }
    virtual Time& GetCurrentTime(Time& theTime) {
        xos::os::Time t(true);
        theTime.year = t.GetYear();
        theTime.month = t.GetMonth();
        theTime.day = t.GetDay();
        theTime.hour = t.GetHour();
        theTime.minute = t.GetMinute();
        theTime.second = t.GetSecond();
        return theTime;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef xos::os::Thread TickThread;
    typedef xos::os::Mutex TickThreadLock;
    typedef xos::os::Semaphore TickThreadStop;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS TickThreadRun: public xos::os::Thread::Run {
    public:
        typedef xos::os::Thread::Run Extends;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        TickThreadRun(Clock& clock): m_clock(clock) {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void operator()() {
            m_clock.RunTickThread();
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        Clock& m_clock;
    };
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
protected:
    mseconds_t m_waitMilliseconds;
    TickThreadLock m_tickThreadLock;
    TickThreadStop m_tickThreadStop;
    TickThreadRun m_tickThreadRun;
    TickThread* m_tickThread;
};

} // namespace implement
} // namespace server
} // namespace clock
} // namespace examples
} // namespace restapp

#endif // !defined(_RESTAPP_EXAMPLES_CLOCK_IMPLEMENT_CLOCK_HPP)

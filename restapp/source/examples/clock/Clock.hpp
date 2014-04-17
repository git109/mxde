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
///   Date: 1/5/2014
////////////////////////////////////////////////////////////////////////
#if !defined(_RESTAPP_EXAMPLES_CLOCK_CLOCK_HPP)
#define _RESTAPP_EXAMPLES_CLOCK_CLOCK_HPP

#include "RestApp.hpp"

namespace restapp {
namespace examples {

typedef InterfaceBase ClockImplement;
typedef ExportBase ClockExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Clock: virtual public ClockImplement, public ClockExtend {
public:
    typedef ClockImplement Implements;
    typedef ClockExtend Extends;

    typedef int EventId;
    enum {
        EventIdNone = 0,
        EventIdStart = 1,
        EventIdStop = 2,
        EventIdTick = 3,
        EventIdSetTickSeconds = 4,
        EventIdError = 5
    };

    typedef int Hour;
    typedef int Minute;
    typedef int Second;
    typedef int Year;
    typedef int Month;
    typedef int Day;

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    struct _EXPORT_CLASS Time {
        int hour;
        int minute;
        int second;
        int month;
        int day;
        int year;
        Time(int p_hour, int p_minute, int p_second, int p_month, int p_day, int p_year)
        : hour(p_hour), minute(p_minute), second(p_second), month(p_month), day(p_day), year(p_year) {
        }
        Time(const Time& copy)
        : hour(copy.hour), minute(copy.minute), second(copy.second), month(copy.month), day(copy.day), year(copy.year) {
        }
        Time()
        : hour(0), minute(0), second(0), month(0), day(0), year(0) {
        }
        Variant& To(Variant& to) const {
            to.Put("hour", hour);
            to.Put("minute", minute);
            to.Put("second", second);
            to.Put("month", month);
            to.Put("day", day);
            to.Put("year", year);
            return to;
        }
        String& To(String& to) const {
            Variant from;
            To(from);
            from.To(to);
            return to;
        }
        operator String() const {
            String to;
            To(to);
            return to;
        }
    };

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    struct _EXPORT_CLASS EventInfo {
        String what;
        Time when;
        EventInfo(String p_what, Time p_when)
        : what(p_what), when(p_when) {
        }
        EventInfo(const EventInfo& copy)
        : what(copy.what), when(copy.when) {
        }
        EventInfo()
        : what("Unknown") {
        }
        Variant& To(Variant& to) const {
            to.Put("what", what);
            Variant whenFrom;
            when.To(whenFrom);
            to.Put("when", whenFrom);
            return to;
        }
        String& To(String& to) const {
            Variant from;
            To(from);
            from.To(to);
            return to;
        }
        operator String() const {
            String to;
            To(to);
            return to;
        }
    };

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    class TickEventCallbackInterface: virtual public InterfaceBase {
    public:
        virtual void OnClockTickEvent(const Time& time) {
        }
        void operator()(const Time& time) {
            OnClockTickEvent(time);
        }
    };
    typedef TickEventCallbackInterface* TickEventCallback;

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    class EventCallbackInterface: virtual public InterfaceBase {
    public:
        virtual void OnClockEvent(const EventId& id, const EventInfo& info) {
        }
        void operator()(const EventId& id, const EventInfo& info) {
            OnClockEvent(id, info);
        }
    };
    typedef EventCallbackInterface* EventCallback;

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    Clock() {
    }
    virtual ~Clock() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool RestartService() {
        bool result = false;
        return result;
    }
    virtual bool StopService() {
        bool result = false;
        return result;
    }
    virtual bool Start() {
        bool result = false;
        return result;
    }
    virtual bool Stop() {
        bool result = false;
        return result;
    }
    virtual bool Tick() {
        bool result = false;
        return result;
    }
    virtual int SetTickSeconds
    (const int& to) {
        int result = 0;
        return result;
    }
    virtual int GetTickSeconds() {
        int result = 0;
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
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool OnTickEvent(const Time& time) {
        bool success = false;
        TickEventMessage m(time);
        m_tickeventQueue.PostMessage(m, true);
        return success;
    }
    virtual bool DispatchTickEvent(const Time& time) {
        bool success = false;
        Locker lockr(m_tickeventListeners);
        TickEventListeners::iterator begin = m_tickeventListeners.begin();
        TickEventListeners::iterator end = m_tickeventListeners.end();
        TickEventListeners::iterator i;
        for (i = begin; i != end; ++i) {
            TickEventCallback cb;
            if ((cb = (TickEventCallback)(*i))) {
                (*cb)(time);
            }
        }
        return success;
    }
    virtual bool GetTickEvent(Time& time) {
        bool success = false;
        TickEventMessage m(time);
        if ((m_tickeventQueue.GetMessage(m, true))) {
            time = m.time;
            success = true;
        }
        return success;
    }
    virtual bool PeekTickEvent(Time& time) {
        bool success = false;
        TickEventMessage m(time);
        if ((m_tickeventQueue.PeekMessage(m, true))) {
            time = m.time;
            success = true;
        }
        return success;
    }
    virtual bool ProcessGetTickEvent() {
        bool success = false;
        Time time;
        if ((GetTickEvent(time))) {
            DispatchTickEvent(time);
            success = true;
        }
        return success;
    }
    virtual bool ProcessPeekTickEvent() {
        bool success = false;
        Time time;
        if ((PeekTickEvent(time))) {
            DispatchTickEvent(time);
            success = true;
        }
        return success;
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool OnEvent(const EventId& id, const EventInfo& info) {
        bool success = false;
        EventMessage m(id, info);
        m_eventQueue.PostMessage(m, true);
        return success;
    }
    virtual bool DispatchEvent(const EventId& id, const EventInfo& info) {
        bool success = false;
        Locker lockr(m_eventListeners);
        EventListeners::iterator begin = m_eventListeners.begin();
        EventListeners::iterator end = m_eventListeners.end();
        EventListeners::iterator i;
        for (i = begin; i != end; ++i) {
            EventCallback cb;
            if ((cb = (EventCallback)(*i))) {
                (*cb)(id, info);
            }
        }
        return success;
    }
    virtual bool GetEvent(EventId& id, EventInfo& info) {
        bool success = false;
        EventMessage m(id, info);
        if ((m_eventQueue.GetMessage(m, true))) {
            id = m.id;
            info = m.info;
            success = true;
        }
        return success;
    }
    virtual bool PeekEvent(EventId& id, EventInfo& info) {
        bool success = false;
        EventMessage m(id, info);
        if ((m_eventQueue.PeekMessage(m, true))) {
            id = m.id;
            info = m.info;
            success = true;
        }
        return success;
    }
    virtual bool ProcessGetEvent() {
        bool success = false;
        EventId id = EventIdNone;
        EventInfo info;
        if ((GetEvent(id, info))) {
            DispatchEvent(id, info);
            success = true;
        }
        return success;
    }
    virtual bool ProcessPeekEvent() {
        bool success = false;
        EventId id = EventIdNone;
        EventInfo info;
        if ((PeekEvent(id, info))) {
            DispatchEvent(id, info);
            success = true;
        }
        return success;
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool ProcessGet() {
        bool success = true;
        if (!(ProcessGetTickEvent())) {
            success = false;
        }
        if (!(ProcessGetEvent())) {
            success = false;
        }
        return success;
    }
    virtual bool ProcessPeek() {
        bool success = true;
        if (!(ProcessPeekTickEvent())) {
            success = false;
        }
        if (!(ProcessPeekEvent())) {
            success = false;
        }
        return success;
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool AddTickEventListener(TickEventCallback& callback) {
        bool success = true;
        m_tickeventListeners.Add(callback);
        return success;
    }
    virtual bool RemoveTickEventListener(TickEventCallback& callback) {
        bool success = true;
        m_tickeventListeners.Remove(callback);
        return success;
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool AddEventListener(EventCallback& callback) {
        bool success = true;
        m_eventListeners.Add(callback);
        return success;
    }
    virtual bool RemoveEventListener(EventCallback& callback) {
        bool success = true;
        m_eventListeners.Remove(callback);
        return success;
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    static Clock& GetTheInstance();
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
protected:
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    struct TickEventMessage {
        Time time;
        TickEventMessage(const Time& p_time)
        : time(p_time) {
        }
        TickEventMessage(const TickEventMessage& copy)
        : time(copy.time) {
        }
    };
    typedef MessageQueueT<TickEventMessage> TickEventQueue;
    typedef CallbackListT<TickEventCallback> TickEventListeners;
    ////////////////////////////////////////////////////////////////////////
    TickEventQueue m_tickeventQueue;
    TickEventListeners m_tickeventListeners;
protected:
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    struct EventMessage {
        EventId id;
        EventInfo info;
        EventMessage(const EventId& p_id, const EventInfo& p_info)
        : id(p_id), info(p_info) {
        }
        EventMessage(const EventMessage& copy)
        : id(copy.id), info(copy.info) {
        }
    };
    typedef MessageQueueT<EventMessage> EventQueue;
    typedef CallbackListT<EventCallback> EventListeners;
    ////////////////////////////////////////////////////////////////////////
    EventQueue m_eventQueue;
    EventListeners m_eventListeners;
};

} // namespace examples
} // namespace restapp

#endif // !defined(_RESTAPP_EXAMPLES_CLOCK_CLOCK_HPP)

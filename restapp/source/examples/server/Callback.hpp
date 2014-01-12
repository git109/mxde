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
///   File: Callback.hpp
///
/// Author: $author$
///   Date: 1/8/2014
////////////////////////////////////////////////////////////////////////
#if !defined(_RESTAPP_EXAMPLES_CLOCK_SERVER_CALLBACK_HPP)
#define _RESTAPP_EXAMPLES_CLOCK_SERVER_CALLBACK_HPP

#include "examples/clock/Clock.hpp"

namespace restapp {
namespace examples {
namespace server {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class EventCallbackImplement
: virtual public examples::Clock::TickEventCallbackInterface,
  virtual public examples::Clock::EventCallbackInterface,
  virtual public InterfaceBase {
public:
    typedef InterfaceBase Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnClockTickEvent(const examples::Clock::Time& time) {
        Json json("{\"object\":\"examples.Clock\",\"callback\":{\"TickEventCallback\":{");
        json.Append("\"time\":");
        json.Append(time);
        json.Append("}}}");
        OnEventData(json);
    }
    virtual void OnClockEvent
    (const examples::Clock::EventId& id,
     const examples::Clock::EventInfo& info) {
        Json json("{\"object\":\"examples.Clock\",\"callback\":{\"EventCallback\":{");
        json.Append("\"id\":");
        json.Append(id);
        json.Append(",");
        json.Append("\"info\":");
        json.Append(info);
        json.Append("}}}");
        OnEventData(json);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void ProcessGetEvents() {
        examples::Clock::GetTheInstance().ProcessGet();
    }
    virtual void ProcessPeekEvents() {
        examples::Clock::GetTheInstance().ProcessPeek();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void AddEventListeners() {
        examples::Clock::TickEventCallback thisClockTickEventCallback = this;
        examples::Clock::GetTheInstance().AddTickEventListener(thisClockTickEventCallback);
        examples::Clock::EventCallback thisClockEventCallback = this;
        examples::Clock::GetTheInstance().AddEventListener(thisClockEventCallback);
    }
    virtual void RemoveEventListeners() {
        examples::Clock::TickEventCallback thisClockTickEventCallback = this;
        examples::Clock::GetTheInstance().RemoveTickEventListener(thisClockTickEventCallback);
        examples::Clock::EventCallback thisClockEventCallback = this;
        examples::Clock::GetTheInstance().RemoveEventListener(thisClockEventCallback);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnEventData(const String& event) {
    }
};

} // namespace server
} // namespace examples
} // namespace restapp

#endif // !defined(_RESTAPP_EXAMPLES_CLOCK_SERVER_CALLBACK_HPP)

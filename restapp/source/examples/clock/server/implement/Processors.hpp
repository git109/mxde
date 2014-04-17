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
///   File: Processors.hpp
///
/// Author: $author$
///   Date: 1/7/2014
////////////////////////////////////////////////////////////////////////
#if !defined(_RESTAPP_EXAMPLES_CLOCK_SERVER_IMPLEMENT_PROCESSORS_HPP)
#define _RESTAPP_EXAMPLES_CLOCK_SERVER_IMPLEMENT_PROCESSORS_HPP

#include "examples/clock/server/Processors.hpp"
#include "examples/clock/Clock.hpp"

namespace restapp {
namespace examples {
namespace clock {
namespace server {
namespace implement {

typedef restapp::examples::clock::server::RestartServiceProcessor RestartServiceProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS RestartServiceProcessor: public RestartServiceProcessorExtend {
public:
    typedef RestartServiceProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    RestartServiceProcessor(const String& path): Extends(path) {
    }
    RestartServiceProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, bool& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.RestartService();
        XOS_LOG_TRACE("...out");
    }
};

typedef restapp::examples::clock::server::StopServiceProcessor StopServiceProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS StopServiceProcessor: public StopServiceProcessorExtend {
public:
    typedef StopServiceProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    StopServiceProcessor(const String& path): Extends(path) {
    }
    StopServiceProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, bool& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.StopService();
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::StartProcessor StartProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS StartProcessor: public StartProcessorExtend {
public:
    typedef StartProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    StartProcessor(const String& path): Extends(path) {
    }
    StartProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, bool& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.Start();
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::StopProcessor StopProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS StopProcessor: public StopProcessorExtend {
public:
    typedef StopProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    StopProcessor(const String& path): Extends(path) {
    }
    StopProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, bool& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.Stop();
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::TickProcessor TickProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS TickProcessor: public TickProcessorExtend {
public:
    typedef TickProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    TickProcessor(const String& path): Extends(path) {
    }
    TickProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, bool& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.Tick();
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::SetTickSecondsProcessor SetTickSecondsProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS SetTickSecondsProcessor: public SetTickSecondsProcessorExtend {
public:
    typedef SetTickSecondsProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    SetTickSecondsProcessor(const String& path): Extends(path) {
    }
    SetTickSecondsProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, int& result, const int& to) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.SetTickSeconds(to);
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::GetTickSecondsProcessor GetTickSecondsProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GetTickSecondsProcessor: public GetTickSecondsProcessorExtend {
public:
    typedef GetTickSecondsProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    GetTickSecondsProcessor(const String& path): Extends(path) {
    }
    GetTickSecondsProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, int& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.GetTickSeconds();
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::AddTickEventListenerProcessor AddTickEventListenerProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS AddTickEventListenerProcessor: public AddTickEventListenerProcessorExtend {
public:
    typedef AddTickEventListenerProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    AddTickEventListenerProcessor(const String& path): Extends(path) {
    }
    AddTickEventListenerProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, int& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.AddTickEventListener();
        XOS_LOG_TRACE("...out");
    }
};

typedef examples::clock::server::RemoveTickEventListenerProcessor RemoveTickEventListenerProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS RemoveTickEventListenerProcessor: public RemoveTickEventListenerProcessorExtend {
public:
    typedef RemoveTickEventListenerProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    RemoveTickEventListenerProcessor(const String& path): Extends(path) {
    }
    RemoveTickEventListenerProcessor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool& processed, int& result) {
        XOS_LOG_TRACE("in...");
        Clock& theClock = Clock::GetTheInstance();
        result = theClock.RemoveTickEventListener();
        XOS_LOG_TRACE("...out");
    }
};

} // namespace implement
} // namespace server
} // namespace clock
} // namespace examples
} // namespace restapp

#endif // !defined(_RESTAPP_EXAMPLES_CLOCK_SERVER_IMPLEMENT_PROCESSORS_HPP)

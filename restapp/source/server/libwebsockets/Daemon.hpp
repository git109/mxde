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
///   File: Daemon.hpp
///
/// Author: $author$
///   Date: 1/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_HPP
#define _RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_HPP

#include "RestApp.hpp"
#include "xos/inet/http/server/libwebsockets/Daemon.hpp"
#include "xos/inet/http/server/Daemon.hpp"
#include "xos/os/server/Daemon.hpp"
#include "xos/os/Daemon.hpp"

#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_NAME "event-callback"
#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_CALLBACK LwsCallbackEvent
#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_SESSION_DATA_SIZE sizeof(EventSessionData)
#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_RX_BUFFER_SIZE 0

#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT \
{ RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_NAME,\
  RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_CALLBACK,\
  RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_SESSION_DATA_SIZE,\
  RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_RX_BUFFER_SIZE},

#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOLS \
    XOS_HTTP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOLS \
    RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT \
    XOS_HTTP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOLS_END

#define RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_INDEX \
    XOS_HTTP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOLS_COUNT

namespace restapp {
namespace server {
namespace libwebsockets {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TCallbackImplement, class TImplement, class TExtend>
class _EXPORT_CLASS DaemonT
: virtual public TCallbackImplement, virtual public TImplement, public TExtend {
protected:
    typedef std::deque<struct libwebsocket*> WsiQueue;
public:
    typedef TCallbackImplement CallbackImplements;
    typedef TImplement Implements;
    typedef TExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DaemonT(xos::http::server::Processor& delegatedToProcessor)
    : Extends(delegatedToProcessor), m_eventDataSize(0), m_eventDataBuffer(0) {
        m_eventDataSize = this->m_lwsSendBuffer.Size();
        m_eventDataBuffer = this->m_lwsSendBuffer.Elements();
    }
    virtual ~DaemonT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRunLwsServer(int argc, char** argv, char** env) {
        int err = 0;
        err = Extends::BeforeRunLwsServer(argc, argv, env);
        this->AddEventListeners();
        return err;
    }
    virtual int AfterRunLwsServer(int argc, char** argv, char** env) {
        int err = 0;
        this->RemoveEventListeners();
        err = Extends::AfterRunLwsServer(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool LwsServiced
    (struct libwebsocket_context *context, int timeout_ms) {
        this->ProcessPeekEvents();
        return (Extends::LwsServiced(context, timeout_ms));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnEventData(const String& event) {
        XOS_LOG_TRACE("queueing event data \"" << event << "\"...");
        EventQueueData q_data(event);
        AddWsiQueue(m_wsiQueue, q_data.wsiWriteable);
        m_eventDataQueue.push_back(q_data);
        ProcessEventData();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetEventData(String& event, struct libwebsocket* wsi) {
        const char* chars = 0;
        if (!(m_eventDataQueue.empty())) {
            EventQueueData eventQueueData = m_eventDataQueue.front();
            event = eventQueueData.data;
            chars = event.c_str();
            m_eventDataQueue.pop_front();
            XOS_LOG_TRACE("...removed event data \"" << event << "\"");
            RemoveWsiWriteable(eventQueueData.wsiWriteable, wsi);
            if (0 < (eventQueueData.wsiWriteable.size())) {
                XOS_LOG_TRACE("requeueing event data \"" << event << "\"...");
                m_eventDataQueue.push_front(eventQueueData);
            }
        }
        return chars;
    }
    virtual void ProcessEventData() {
        if (!(m_eventDataQueue.empty())) {
            struct libwebsocket_protocols* protocol;
            if ((protocol = LwsCallbackEventProtocol()))
                libwebsocket_callback_on_writable_all_protocol(protocol);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnLwsCallbackEvent_LWS_CALLBACK_SERVER_WRITEABLE
    (struct libwebsocket_context *context, struct libwebsocket *wsi,
     enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
    {
        int result = 0;
        unsigned char* eventData = m_eventDataBuffer + LWS_SEND_BUFFER_PRE_PADDING;
        const char* eventDataChars;
        size_t eventDataLength;
        String event;
        int count;

        if ((eventDataChars = (GetEventData(event, wsi)))
            && (0 < (eventDataLength = event.length()))
            && (eventDataLength < m_eventDataSize)) {

            XOS_LOG_DEBUG("libwebsocket_write(...,\"" << eventDataChars << "\",...)...");

            memcpy(eventData, eventDataChars, eventDataLength);
            count = libwebsocket_write(wsi, eventData, eventDataLength, LWS_WRITE_TEXT);

            if (count < (eventDataLength)) {
                XOS_LOG_ERROR("...failed on libwebsocket_write()");
                result = -1;
            }
            ProcessEventData();
        }
        return result;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnLwsCallbackEvent
    (struct libwebsocket_context *context, struct libwebsocket *wsi,
     enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len) {
        int result = 0;
        switch (reason) {

        case LWS_CALLBACK_ESTABLISHED:
            XOS_LOG_TRACE("LWS_CALLBACK_ESTABLISHED...");
            AddWsi(wsi);
            break;

        case LWS_CALLBACK_CLOSED:
            XOS_LOG_TRACE("LWS_CALLBACK_CLOSED...");
            RemoveWsi(wsi);
            break;

        case LWS_CALLBACK_SERVER_WRITEABLE:
            XOS_LOG_TRACE("LWS_CALLBACK_SERVER_WRITEABLE...");
            result = OnLwsCallbackEvent_LWS_CALLBACK_SERVER_WRITEABLE(context, wsi, reason, user, in, len);
            break;

        case LWS_CALLBACK_RECEIVE:
            XOS_LOG_TRACE("LWS_CALLBACK_RECEIVE...");
            break;
        }
        return result;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int LwsCallbackEvent
    (struct libwebsocket_context *context, struct libwebsocket *wsi,
     enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len) {
        int result = -1;
        DaemonT* daemon = 0;
        if ((daemon = (DaemonT*)(libwebsocket_context_user(context))))
            result = daemon->OnLwsCallbackEvent(context, wsi, reason, user, in, len);
        return result;
    }
    virtual struct libwebsocket_protocols* LwsCallbackEventProtocol() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void AddWsi(struct libwebsocket* wsi) {
        m_wsiQueue.push_back(wsi);
    }
    virtual struct libwebsocket* RemoveWsi(struct libwebsocket* wsi) {
        RemoveWsiWriteable(wsi);
        return RemoveWsi(m_wsiQueue, wsi);
    }
    virtual void AddWsiQueue(WsiQueue& wsiQueue, WsiQueue& toWsiQueue) {
        WsiQueue::iterator begin = wsiQueue.begin();
        WsiQueue::iterator end = wsiQueue.end();
        struct libwebsocket* wsi;
        for (WsiQueue::iterator i = begin; i != end; ++i) {
            if (0 != (wsi = (*i))) {
                toWsiQueue.push_back(wsi);
            }
        }
    }
    virtual void RemoveWsiWriteable(struct libwebsocket* wsi) {
    }
    virtual struct libwebsocket* RemoveWsiWriteable(WsiQueue& wsiQueue, struct libwebsocket* wsi) {
        WsiQueue::iterator begin = wsiQueue.begin();
        WsiQueue::iterator end = wsiQueue.end();
        wsi = RemoveWsi(wsiQueue, wsi);
        for (WsiQueue::iterator i = begin; i != end; ++i) {
            if (!(FindWsi(m_wsiQueue, (*i)))) {
                wsiQueue.erase(i);
            }
        }
        return wsi;
    }
    virtual struct libwebsocket* RemoveWsi(WsiQueue& wsiQueue, struct libwebsocket* wsi) {
        WsiQueue::iterator begin = wsiQueue.begin();
        WsiQueue::iterator end = wsiQueue.end();
        for (WsiQueue::iterator i = begin; i != end; ++i) {
            if (wsi == ((*i))) {
                wsiQueue.erase(i);
                return wsi;
            }
        }
        return 0;
    }
    virtual struct libwebsocket* FindWsi(WsiQueue& wsiQueue, struct libwebsocket* wsi) {
        WsiQueue::iterator begin = wsiQueue.begin();
        WsiQueue::iterator end = wsiQueue.end();
        for (WsiQueue::iterator i = begin; i != end; ++i) {
            if (wsi == ((*i))) {
                return wsi;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    struct EventSessionData {
        void* data;
    };
    struct EventQueueData {
        String data;
        WsiQueue wsiWriteable;
        EventQueueData(const String& p_data): data(p_data) {
        }
        EventQueueData(const EventQueueData& copy)
        : data(copy.data), wsiWriteable(copy.wsiWriteable) {
        }
    };
    typedef std::deque<EventQueueData> EventDataQueue;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    WsiQueue m_wsiQueue;
    EventDataQueue m_eventDataQueue;
    size_t m_eventDataSize;
    unsigned char* m_eventDataBuffer;
};

} // namespace libwebsockets
} // namespace server 
} // namespace restapp 

#endif // _RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_HPP 

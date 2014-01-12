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
///   File: RestApp.hpp
///
/// Author: $author$
///   Date: 1/5/2014
///////////////////////////////////////////////////////////////////////
#ifndef _RESTAPP_RESTAPP_HPP
#define _RESTAPP_RESTAPP_HPP

#include "xos/inet/http/server/Processor.hpp"
#include "xos/inet/http/server/Daemon.hpp"
#include "xos/inet/http/Response.hpp"
#include "xos/os/os/Semaphore.hpp"
#include "xos/os/os/Mutex.hpp"
#include "xos/base/Locked.hpp"
#include "xos/base/Locker.hpp"
#include "xos/base/Acquired.hpp"
#include "xos/base/Wait.hpp"
#include "xos/base/Waiter.hpp"
#include "xos/base/Variant.hpp"
#include "xos/base/Named.hpp"
#include <deque>

namespace restapp {

typedef xos::InterfaceBase InterfaceBase;
typedef xos::ExportBase ExportBase;
typedef xos::Error Error;
typedef xos::String String;
typedef xos::StringImplement StringImplement;
typedef xos::Variant Variant;
typedef xos::LockedInterface LockedInterface;
typedef xos::Locker<LockedInterface> Locker;
typedef xos::WaitInterface WaitInterface;
typedef xos::Waiter<WaitInterface> Waiter;
typedef xos::os::Semaphore Semaphore;
typedef xos::os::Mutex Mutex;
typedef xos::Daemon Daemon;

namespace http {

typedef xos::http::Form Form;
typedef xos::http::Request Request;
typedef xos::http::Response Response;

namespace server {

typedef xos::http::server::ProcessorImplement ProcessorImplement;
typedef xos::http::server::Processor Processor;
typedef xos::http::server::Daemon Daemon;

} // namespace server
} // namespace http

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TMessage,
 class TExtend =  ExportBase,
 class TImplement = InterfaceBase>

class MessageQueueT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    enum Exception {
        FailedToCreateMutex=1,
        FailedToDestroyMutex,
        FailedToCreateSemaphore,
        FailedToDestroySemaphore
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MessageQueueT() {
        if (!(m_mutex.Create())) {
            XOS_LOG_ERROR("failed to create mutex");
            throw(FailedToCreateMutex);
        }
        if (!(m_semaphore.Create())) {
            XOS_LOG_ERROR("failed to create semaphore");
            throw(FailedToCreateSemaphore);
        }
    }
    virtual ~MessageQueueT() {
        if (!(m_semaphore.Destroyed())) {
            XOS_LOG_ERROR("failed to detroy semaphore");
            throw(FailedToDestroySemaphore);
        }
        if (!(m_mutex.Destroyed())) {
            XOS_LOG_ERROR("failed to detroy mutex");
            throw(FailedToDestroyMutex);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetMessage(TMessage& msg, bool removeMsg = false) {
        bool success = false;
        XOS_LOG_TRACE("waiting for message...");
        try {
            volatile Waiter waitr(m_semaphore);
            XOS_LOG_TRACE("...waited for message");
            success = PeekMessage(msg, removeMsg);
        } catch (const xos::Error&) {
            success = false;
        }
        return success;
    }
    virtual bool PeekMessage(TMessage& msg, bool removeMsg = false) {
        bool success = false;
        try {
            volatile Locker lockr(m_mutex);
            if ((success = !(m_queue.empty()))) {
                msg = m_queue.front();
                XOS_LOG_TRACE("...peeked message");
                if (removeMsg)
                    m_queue.pop_front();
            }
        } catch (const Error&) {
            success = false;
        }
        return success;
    }
    virtual bool PostMessage(TMessage& msg, bool notifyMsg = true) {
        bool success = false;
        XOS_LOG_TRACE("posting message...");
        try {
            volatile Locker lockr(m_mutex);
            m_queue.push_back(msg);
            XOS_LOG_TRACE("...posted message");
            if (!(success = !(notifyMsg)))
                success = m_semaphore.Release();
        } catch (const Error&) {
            success = false;
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Mutex m_mutex;
    Semaphore m_semaphore;
    std::deque<TMessage> m_queue;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TCallback,
 class TExtend = ExportBase,
 class TImplement = LockedInterface>

class CallbackListT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    enum Exception {
        FailedToCreateMutex,
        FailedToDestroyMutex
    };
    typedef std::list<TCallback> List;
    typedef typename List::iterator iterator;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CallbackListT() {
        if (!(m_mutex.Create())) {
            XOS_LOG_ERROR("failed on m_mutex.Create()");
            throw (FailedToCreateMutex);
        }
    }
    virtual ~CallbackListT() {
        if (!(m_mutex.Destroy())) {
            XOS_LOG_ERROR("failed on m_mutex.Destroy()");
            throw (FailedToDestroyMutex);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Add(TCallback callback) {
        volatile Locker lockr(m_mutex);
        m_list.push_back(callback);
        return true;
    }
    virtual bool Remove(TCallback callback) {
        volatile Locker lockr(m_mutex);
        iterator b = begin();
        iterator e = end();
        for (iterator i = b; i != e; ++i) {
            TCallback cb;
            if (callback == (cb = (TCallback)(*i))) {
                m_list.erase(i);
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual iterator begin() {
        return m_list.begin();
    }
    virtual iterator end() {
        return m_list.end();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        return m_mutex.Lock();
    }
    virtual bool Unlock() {
        return m_mutex.Unlock();
    }
    virtual WaitInterface::Status TryLock() {
        return m_mutex.TryLock();
    }
    virtual WaitInterface::Status TimedLock(mseconds_t waitMilliseconds) {
        return m_mutex.TimedLock(waitMilliseconds);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Mutex m_mutex;
    List m_list;
};

typedef StringImplement JsonImplement;
typedef String JsonExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Json: virtual public JsonImplement, public JsonExtend {
public:
    typedef JsonImplement Implements;
    typedef JsonExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Json(const String& copy): Extends(copy) {
    }
    Json(const Json& copy): Extends(copy) {
    }
    Json() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Variant& To(Variant& v) const;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef InterfaceBase RequestImplement;
typedef ExportBase RequestExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Request
: virtual public RequestImplement, public RequestExtend {
public:
    typedef RequestImplement Implements;
    typedef RequestExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Request
    (const http::Request& httpRequest)
    : m_httpRequest(httpRequest) {
    }
    virtual ~Request() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Get(int &value, const String& name) const {
        http::Form::Field field;
        if ((m_httpRequest.GetForm().GetField(field, name))) {
            const http::Form::Field::ValueT& fieldValue = field.GetValue();
            XOS_LOG_TRACE("field value = \"" << fieldValue << "\"");
            value = fieldValue.ToInt();
            return true;
        }
        return false;
    }
    virtual bool Get(bool &value, const String& name) const {
        http::Form::Field field;
        if ((m_httpRequest.GetForm().GetField(field, name))) {
            const http::Form::Field::ValueT& fieldValue = field.GetValue();
            XOS_LOG_TRACE("field value = \"" << fieldValue << "\"");
            value = !(fieldValue.Compare("true"));
            return true;
        }
        return false;
    }
    virtual bool Get(String &value, const String& name) const {
        http::Form::Field field;
        if ((m_httpRequest.GetForm().GetField(field, name))) {
            const http::Form::Field::ValueT& fieldValue = field.GetValue();
            XOS_LOG_TRACE("field value = \"" << fieldValue << "\"");
            value = fieldValue;
            return true;
        }
        return false;
    }
    virtual bool Get(Variant &value, const String& name) const {
        http::Form::Field field;
        if ((m_httpRequest.GetForm().GetField(field, name))) {
            const http::Form::Field::ValueT& fieldValue = field.GetValue();
            Json json(fieldValue);
            XOS_LOG_TRACE("field value = \"" << fieldValue << "\"");
            json.To(value);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const String& GetMethod() const {
        return m_httpRequest.GetMethod();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const http::Request& m_httpRequest;
};

typedef InterfaceBase ResponseImplement;
typedef ExportBase ResponseExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Response
: virtual public ResponseImplement, public ResponseExtend {
public:
    typedef ResponseImplement Implements;
    typedef ResponseExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Response
    (const http::Response& httpResponse)
    : m_httpResponse(httpResponse) {
    }
    virtual ~Response() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Put(const String& name, const int &value) {
        m_httpResponse.message().Assign("{\"");
        m_httpResponse.message().Append(name);
        m_httpResponse.message().Append("\":");
        m_httpResponse.message().Append(value);
        m_httpResponse.message().Append("}");
        return true;
    }
    virtual bool Put(const String& name, const bool &value) {
        m_httpResponse.message().Assign("{\"");
        m_httpResponse.message().Append(name);
        m_httpResponse.message().Append("\":");
        m_httpResponse.message().Append((value)?("true"):("false"));
        m_httpResponse.message().Append("}");
        return true;
    }
    virtual bool Put(const String& name, const String &value) {
        m_httpResponse.message().Assign("{\"");
        m_httpResponse.message().Append(name);
        m_httpResponse.message().Append("\":\"");
        m_httpResponse.message().Append(value);
        m_httpResponse.message().Append("\"}");
        return true;
    }
    virtual bool Put(const String& name, const Variant &value) {
        String json;
        value.To(json);
        m_httpResponse.message().Assign("{\"");
        m_httpResponse.message().Append(name);
        m_httpResponse.message().Append("\":");
        m_httpResponse.message().Append(json);
        m_httpResponse.message().Append("}");
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Put(const int &value) {
        m_httpResponse.message().Assign(value);
        return true;
    }
    virtual bool Put(const bool &value) {
        m_httpResponse.message().Assign((value)?("true"):("false"));
        return true;
    }
    virtual bool Put(const String &value) {
        m_httpResponse.message().Assign("\"");
        m_httpResponse.message().Append(value);
        m_httpResponse.message().Append("\"");
        return true;
    }
    virtual bool Put(const Variant &value) {
        String json;
        value.To(json);
        m_httpResponse.message().Assign(json);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Set(const int &value) {
        m_httpResponse.message().Assign(value);
        return true;
    }
    virtual bool Set(const bool &value) {
        m_httpResponse.message().Assign((value)?("true"):("false"));
        return true;
    }
    virtual bool Set(const String &value) {
        m_httpResponse.message().Assign(value);
        return true;
    }
    virtual bool Set(const Variant &value) {
        String json;
        value.To(json);
        m_httpResponse.message().Assign(json);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const http::Response& m_httpResponse;
};

typedef InterfaceBase ProcessorImplement;
typedef ExportBase ProcessorExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Processor
: virtual public ProcessorImplement, public ProcessorExtend {
public:
    typedef ProcessorImplement Implements;
    typedef ProcessorExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Processor(const String& path)
    : m_path(path) {
        Add();
    }
    virtual ~Processor()  {
        Remove();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Process(Response& response, const Request& request) {
        String method(request.GetMethod());
        bool processed = false;
        XOS_LOG_TRACE("in...");
        processed = Any(response, request, method);
        XOS_LOG_TRACE("...out");
        return processed;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Get
    (Response& response, const Request& request, const String& method) {
        bool processed = Any(response,request,method);
        return processed;
    }
    virtual bool Put
    (Response& response, const Request& request, const String& method) {
        bool processed = Any(response,request,method);
        return processed;
    }
    virtual bool Post
    (Response& response, const Request& request, const String& method) {
        bool processed = Any(response,request,method);
        return processed;
    }
    virtual bool Delete
    (Response& response, const Request& request, const String& method) {
        bool processed = Any(response,request,method);
        return processed;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool Head
    (Response& response, const Request& request, const String& method) {
        bool processed = Any(response,request,method);
        return processed;
    }
    virtual bool Options
    (Response& response, const Request& request, const String& method) {
        bool processed = Any(response,request,method);
        return processed;
    }
    virtual bool Any
    (Response& response, const Request& request, const String& method) {
        bool processed = false;
        return processed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Add();
    virtual bool Remove();
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static Processor* Match(const String& path);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_path;
};

namespace server {

typedef http::server::ProcessorImplement ProcessorImplement;
typedef http::server::Processor ProcessorExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Processor
: virtual public ProcessorImplement, public ProcessorExtend {
public:
    typedef ProcessorImplement Implements;
    typedef ProcessorExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Processor() {
    }
    virtual ~Processor() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Process(http::Response& response, const http::Request& request) {
        bool processed = false;
        Extends* delegatedToProcessor;
        if ((delegatedToProcessor = DelegatedToProcessor()))
            processed = delegatedToProcessor->Process(response, request);
        else {
            const String& path = request.GetPath();
            const Request restRequest(request);
            Response restResponse(response);
            restapp::Processor* restProcessor;
            if ((restProcessor = restapp::Processor::Match(path))) {
                processed = restProcessor->Process(restResponse, restRequest);
            }
        }
        return processed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace server
} // namespace restapp

#endif // _RESTAPP_RESTAPP_HPP 

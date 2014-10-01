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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 8/24/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_LOGGER_HPP
#define _XOS_NADIR_XOS_IO_LOGGER_HPP

#include "xos/mt/locker.hpp"
#include "xos/base/string.hpp"
#include <sstream>

#if defined(XOS_USE_LOG4CXX)
// Use log4cxx logging
//
#include "log4cxx/logger.h"
#endif // defined(XOS_USE_LOG4CXX)

namespace xos {
namespace io {

typedef mt::locker logger_implement;
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger: virtual public logger_implement {
public:
    typedef logger_implement Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS level {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        typedef unsigned enable;
        enum {
            none  = 0,

            fatal = (1 << 0),
            error = (1 << 1),
            warn  = (1 << 2),
            info  = (1 << 3),
            debug = (1 << 4),
            trace = (1 << 5),

            next  = (1 << 6),
            all   = (next - 1)
        };
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        level(enable _enable = none): enable_(_enable){}
        level(const level& copy): enable_(copy.enable_){}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        inline level& operator = (enable _enable){
            enable_ = _enable;
            return *this;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        enable enable_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS levels {
    public:
        enum {
            none  = 0,

            fatal = ((1 << 1) - 1),
            error = ((1 << 2) - 1),
            warn  = ((1 << 3) - 1),
            info  = ((1 << 4) - 1),
            debug = ((1 << 5) - 1),
            trace = ((1 << 6) - 1),

            next  = ((1 << 7) - 1),
            all   = (next)
        };
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS location {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        location
        (const char* function_name, const char* file_name, size_t line_number)
        : function_name_(function_name),
          file_name_(file_name),
          line_number_(line_number) {
        }
        location
        (const location& copy)
        : function_name_(copy.function_name_),
          file_name_(copy.file_name_),
          line_number_(copy.line_number_) {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        inline base::string get_function_name() const { return function_name_; }
        inline base::string get_file_name() const { return file_name_; }
        inline base::string get_line_number() const {
            std::stringstream ss;
            ss << line_number_;
            return ss.str();
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        base::string function_name_;
        base::string file_name_;
        size_t line_number_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS message: public base::string {
    public:
        message& operator << (const Extends& str){ append(str); return *this; }
        message& operator << (const char* chars){ append(chars); return *this; }
        message& operator << (int i){
            std::stringstream ss;
            ss << i;
            append(ss.str());
            return *this;
        }
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS class_name: public base::string {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        class_name(const base::string& fully_qualified_function_name) {
            assign(class_name_of(fully_qualified_function_name));
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual base::string class_name_of
        (const base::string& fully_qualified_function_name) {
            base::string class_name;
            base::string name;
            const char* chars;
            size_t length;
            if ((chars = fully_qualified_function_name.c_str())
                && (length = fully_qualified_function_name.length())) {
                for (int state = 0, i = 0; i < length; ++i) {
                    char c=chars[i];
                    switch(state) {
                    case 1:
                        switch(c) {
                        case '(':
                            return class_name;
                        case ' ':
                            name.clear();
                            break;
                        case ':':
                            class_name.append(name);
                            name.assign("::");
                            state = 0;
                            break;
                        default:
                            state = 0;
                            name.append(":");
                            name.append(&c,1);
                        }
                        break;
                    default:
                        switch(c) {
                        case '(':
                            return class_name;
                        case ' ':
                            name.clear();
                            break;
                        case ':':
                            state = 1;
                            break;
                        default:
                            name.append(&c,1);
                        }
                    }
                }
            }
            return class_name;
        }
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() { return true; }
    virtual bool fini() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {}
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {}
    virtual level enabled_for() const { return level(level::none); }
    virtual bool is_enabled_for(const level& _level) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static logger* get_default();
    static void set_default(logger* _logger);
};

} // namespace io 
} // namespace xos 

#if !defined(XOS_LOGGER_LOCATION)
#if defined(_MSC_VER)
#if (_MSC_VER >= 1300)
#define __XOS_LOGGER_FUNC__ __FUNCSIG__
#endif // (_MSC_VER >= 1300)
#else // defined(_MSC_VER)
#if defined(__GNUC__)
#define __XOS_LOGGER_FUNC__ __PRETTY_FUNCTION__
#endif // defined(__GNUC__)
#endif // (_MSC_VER >= 1300)
#if !defined(__XOS_LOGGER_FUNC__)
#define __XOS_LOGGER_FUNC__ ""
#define __XOS_LOGGER_CLASS__ ""
#else // !defined(__XOS_LOGGER_FUNC__)
#define __XOS_LOGGER_CLASS__ ::xos::io::logger::class_name(__XOS_LOGGER_FUNC__)
#endif // !defined(__XOS_LOGGER_FUNC__)
#define XOS_LOGGER_LOCATION ::xos::io::logger::location(__XOS_LOGGER_FUNC__, __FILE__, __LINE__)
#endif // !defined(XOS_LOGGER_LOCATION)

#define XOS_INIT_LOGGER(logger_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) { logger->init(); } }

#define XOS_FINI_LOGGER(logger_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) { logger->fini(); } }

#define XOS_SET_LOGGER_LEVEL(logger_, level_) { \
::xos::io::logger* logger = logger_; \
if ((logger)) { logger->enable_for(level_); } }

#define XOS_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::xos::io::logger::level\
(::xos::io::logger::levels::none)))

#define XOS_LOG(logger_, level_, message_) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::io::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOGF(logger_, level_, format_, ...) { \
::xos::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level, XOS_LOGGER_LOCATION, format, ##__VA_ARGS__); } }

#if !defined(XOS_USE_LOG4CXX)
// Use xos logging
//
#if !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::io::logger::get_default()
#else // !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::io::logger::get_default()
#endif // !defined(XOS_USE_LOGGER)

#define XOS_LOGGER_INIT() XOS_INIT_LOGGER(XOS_DEFAULT_LOGGER)
#define XOS_LOGGER_FINI() XOS_FINI_LOGGER(XOS_DEFAULT_LOGGER)

#define XOS_SET_LOGGING_LEVEL(level)  XOS_SET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER, level)
#define XOS_GET_LOGGING_LEVEL(level)  (level = XOS_GET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER))
#define XOS_LOGGING_LEVELS ::xos::io::logger::level::enable

#define XOS_LOGGING_LEVELS_ALL ::xos::io::logger::levels::all
#define XOS_LOGGING_LEVELS_NONE ::xos::io::logger::levels::none
#define XOS_LOGGING_LEVELS_FATAL ::xos::io::logger::levels::fatal
#define XOS_LOGGING_LEVELS_ERROR ::xos::io::logger::levels::error
#define XOS_LOGGING_LEVELS_WARN ::xos::io::logger::levels::warn
#define XOS_LOGGING_LEVELS_INFO ::xos::io::logger::levels::info
#define XOS_LOGGING_LEVELS_DEBUG ::xos::io::logger::levels::debug
#define XOS_LOGGING_LEVELS_TRACE ::xos::io::logger::levels::trace

#define XOS_LOG_FATAL(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal, message)
#define XOS_LOG_ERROR(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error, message)
#define XOS_LOG_WARN(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn, message)
#define XOS_LOG_INFO(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info, message)
#define XOS_LOG_DEBUG(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug, message)
#define XOS_LOG_TRACE(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace, message)

#define XOS_LOG_FATALF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::fatal, message, ##__VA_ARGS__)
#define XOS_LOG_ERRORF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::error, message, ##__VA_ARGS__)
#define XOS_LOG_WARNF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::warn, message, ##__VA_ARGS__)
#define XOS_LOG_INFOF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::info, message, ##__VA_ARGS__)
#define XOS_LOG_DEBUGF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::debug, message, ##__VA_ARGS__)
#define XOS_LOG_TRACEF(message, ...) XOS_LOGF(XOS_DEFAULT_LOGGER, ::xos::io::logger::level::trace, message, ##__VA_ARGS__)

// default logging levels
//
#define XOS_DEFAULT_LOGGING_LEVELS XOS_LOGGING_LEVELS_INFO
#endif // !defined(XOS_USE_LOG4CXX)

#endif // _XOS_NADIR_XOS_IO_LOGGER_HPP

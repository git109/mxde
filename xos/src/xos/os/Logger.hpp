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
///   File: Logger.hpp
///
/// Author: $author$
///   Date: Aug 14, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_HPP_
#define _XOS_LOGGER_HPP_

#include "xos/base/Base.hpp"
#include "xos/base/String.hpp"
#include <sstream>

#if defined(LOG4CXX)
// Use log4cxx logging
//
#include "log4cxx/logger.h"
#else // defined(LOG4CXX)
// Use xos logging
//
#endif // defined(LOG4CXX)

#if defined(None)
#define LOGGER_None None
#undef None
#endif // defined(None)

namespace xos {

typedef InterfaceBase LoggerImplement;

class EXPORT_CLASS LoggerImplemented;

class EXPORT_CLASS Logger: virtual public LoggerImplement {
public:
    typedef LoggerImplement Implements;

    class EXPORT_CLASS Level {
    public:
        typedef unsigned Enable;
        enum {
            None  = 0,

            Fatal = (1 << 0), 
            Error = (1 << 1), 
            Warn  = (1 << 2), 
            Info  = (1 << 3), 
            Debug = (1 << 4), 
            Trace = (1 << 5), 

            Next  = (1 << 6), 
            All   = (Next - 1)
        };
        Level(Enable enable = None): m_enable(enable){}
        inline Level& operator = (Enable enable){
            m_enable = enable;
            return *this;
        }
        inline operator Enable() const { return m_enable; }
    protected:
        Enable m_enable;
    };

    class EXPORT_CLASS Levels {
    public:
        enum {
            None  = 0,

            Fatal = ((1 << 1) - 1), 
            Error = ((1 << 2) - 1), 
            Warn  = ((1 << 3) - 1), 
            Info  = ((1 << 4) - 1), 
            Debug = ((1 << 5) - 1), 
            Trace = ((1 << 6) - 1), 

            Next  = ((1 << 7) - 1), 
            All   = (Next)
        };
    };

    class EXPORT_CLASS Location {
    public:
        Location
        (const char* functionName, const char* fileName, size_t lineNumber)
        : m_functionName(functionName),
          m_fileName(fileName), 
          m_lineNumber(lineNumber)
        {
        }
        Location
        (const Location& copy)
        : m_functionName(copy.m_functionName), 
          m_fileName(copy.m_fileName), 
          m_lineNumber(copy.m_lineNumber)
        {
        }
        inline String getFunctionName() const { return m_functionName; }
        inline String getFileName() const { return m_fileName; }
        inline String getLineNumber() const { 
            std::stringstream ss;
            ss << m_lineNumber; 
            return ss.str();
        }
    protected:
        String m_functionName;
        String m_fileName;
        size_t m_lineNumber;
    };

    class EXPORT_CLASS Message: public String {
    public:
        Message& operator << (const Extends& str){ append(str); return *this; }
        Message& operator << (const char* chars){ append(chars); return *this; }
        Message& operator << (int i){
            std::stringstream ss;
            ss << i;
            append(ss.str());
            return *this;
        }
    };

    virtual bool Init() = 0;
    virtual bool Fini() = 0;

    virtual void Log
   (const Level& level, const Message& message, const Location& location) = 0; 

    virtual void EnableFor(const Level& level) = 0;
    virtual bool IsEnabledFor(const Level& level) const = 0;

    static Logger* GetDefault();

protected:
    static void SetDefault(Logger* logger);
};

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
#endif // !defined(__XOS_LOGGER_FUNC__)
#define XOS_LOGGER_LOCATION ::xos::Logger::Location(__XOS_LOGGER_FUNC__, __FILE__, __LINE__)
#endif // !defined(XOS_LOGGER_LOCATION)

#define XOS_INIT_LOGGER(logger) { \
if ((logger)) {\
   logger->Init(); } }

#define XOS_FINI_LOGGER(logger) { \
if ((logger)) {\
   logger->Fini(); } }

#define XOS_SET_LOGGER_LEVEL(logger, level) { \
if ((logger)) {\
    ::xos::Logger::Level loggerLevel(level);\
   logger->EnableFor(loggerLevel); } }

#define XOS_LOG(logger, level, message) { \
if ((logger)?(logger->IsEnabledFor(level)):(false)) {\
   ::xos::Logger::Message oss_; \
   logger->Log(level, oss_ << message, XOS_LOGGER_LOCATION); } }

#if defined(LOG4CXX)
// Use log4cxx logging
//
#else // defined(LOG4CXX)
// Use xos logging
//
#if !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::Logger::GetDefault()
#else // !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::Logger::GetDefault()
#endif // !defined(XOS_USE_LOGGER)

#define XOS_LOGGER_INIT() XOS_INIT_LOGGER(XOS_DEFAULT_LOGGER)
#define XOS_LOGGER_FINI() XOS_FINI_LOGGER(XOS_DEFAULT_LOGGER)

#define  XOS_SET_LOGGING_LEVEL(level)  XOS_SET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER, level)

#define XOS_LOGGING_LEVELS_ALL ::xos::Logger::Levels::All
#define XOS_LOGGING_LEVELS_NONE ::xos::Logger::Levels::None
#define XOS_LOGGING_LEVELS_FATAL ::xos::Logger::Levels::Fatal
#define XOS_LOGGING_LEVELS_ERROR ::xos::Logger::Levels::Error
#define XOS_LOGGING_LEVELS_WARN ::xos::Logger::Levels::Warn
#define XOS_LOGGING_LEVELS_INFO ::xos::Logger::Levels::Info
#define XOS_LOGGING_LEVELS_DEBUG ::xos::Logger::Levels::Debug
#define XOS_LOGGING_LEVELS_TRACE ::xos::Logger::Levels::Trace

#define XOS_LOG_FATAL(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::Logger::Level::Fatal, message)
#define XOS_LOG_ERROR(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::Logger::Level::Error, message)
#define XOS_LOG_WARN(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::Logger::Level::Warn, message)
#define XOS_LOG_INFO(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::Logger::Level::Info, message)
#define XOS_LOG_DEBUG(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::Logger::Level::Debug, message)
#define XOS_LOG_TRACE(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::Logger::Level::Trace, message)
#endif // defined(LOG4CXX)

#if defined(LOGGER_None)
#define None LOGGER_None
#undef LOGGER_None
#endif // defined(None)

#endif // _XOS_LOGGER_HPP_ 

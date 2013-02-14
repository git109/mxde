///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
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
///   File: XosDebug.hpp
///
/// Author: $author$
///   Date: 11/22/2011
///////////////////////////////////////////////////////////////////////
#ifndef _XOSDEBUG_HPP
#define _XOSDEBUG_HPP

#include "XosError.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if !defined(NO_XOS_DEBUG) 
typedef unsigned XOS_DEBUG_LEVELS_T;
enum
{
    XOS_DEBUG_LEVELS_FIRST = 0,

    XOS_DEBUG_LEVELS_NONE = XOS_DEBUG_LEVELS_FIRST,
    XOS_DEBUG_LEVELS_ERROR,
    XOS_DEBUG_LEVELS_WARN,
    XOS_DEBUG_LEVELS_INFO,
    XOS_DEBUG_LEVELS_FUNC,
    XOS_DEBUG_LEVELS_TRACE,

    XOS_DEBUG_LEVELS_NEXT,
    XOS_DEBUG_LEVELS_LAST = XOS_DEBUG_LEVELS_NEXT-1,
    XOS_DEBUG_LEVELS_COUNT = XOS_DEBUG_LEVELS_LAST-XOS_DEBUG_LEVELS_FIRST+1
};
enum
{
    XOS_DEBUG_LEVEL_NONE  = 0,

    XOS_DEBUG_LEVEL_ERROR = (1 << (XOS_DEBUG_LEVELS_ERROR-1)),
    XOS_DEBUG_LEVEL_WARN  = (1 << (XOS_DEBUG_LEVELS_WARN-1)), 
    XOS_DEBUG_LEVEL_INFO  = (1 << (XOS_DEBUG_LEVELS_INFO-1)), 
    XOS_DEBUG_LEVEL_FUNC  = (1 << (XOS_DEBUG_LEVELS_FUNC-1)),
    XOS_DEBUG_LEVEL_TRACE = (1 << (XOS_DEBUG_LEVELS_TRACE-1)),

    XOS_DEBUG_LEVEL_NEXT  = (1 << (XOS_DEBUG_LEVELS_NEXT-1)),
    XOS_DEBUG_LEVEL_ALL   = (XOS_DEBUG_LEVEL_NEXT-1),
};

#if defined(__MSC__) 
#if (_MSC_VER <= MSC_VER_6) 
#define DF(name) static const char __FUNCTION__[]=""#name;
#else // (_MSC_VER <= MSC_VER_6)
#define DF(name)
#endif // (_MSC_VER <= MSC_VER_6)
#define XOS_DB_FUNCTION __FUNCTION__
#define XOS_CDB_FUNCTION (strrchr(__FUNCTION__,':')?(strrchr(__FUNCTION__,':')+1):(__FUNCTION__))
#endif // defined(__MSC__)

#if defined(__GNUC__) 
#if defined(DB_USE_PRETTY_FUNCTION)
#define XOS_DB_FUNCTION __PRETTY_FUNCTION__
#else
#define XOS_DB_FUNCTION __FUNCTION__
#endif // defined(DB_USE_PRETTY_FUNCTION)
#define DF(name)
#define XOS_CDB_FUNCTION __FUNCTION__
#endif // defined(__GNUC__)

#define xos_debug_printf printf
#define XOS_DB_PRINTF(args) xos_debug_printf args

#define XOS_DEFAULT_DEBUG_LEVEL XOS_DEBUG_LEVELS_TRACE
#define XOS_DEBUG_LEVELS(level) (XOS_DEBUG_LEVELS_T)((1 << level) - 1)
#define XOS_DEFAULT_DEBUG_LEVELS XOS_DEBUG_LEVELS(XOS_DEFAULT_DEBUG_LEVEL)

#define XOS_GET_DEBUG_LEVELS() g_cdebug_levels
#define XOS_SET_DEBUG_LEVELS(levels) g_cdebug_levels = (levels)
#define XOS_IS_DEBUG_LEVELS(levels) (g_cdebug_levels & levels)
#define XOS_SET_DEBUG_LEVEL(level) g_cdebug_levels = XOS_DEBUG_LEVELS(level)

#define XOS_DEBUGL(levels, type) \
    ((g_cdebug_levels & levels) \
    && XOS_DB_PRINTF(("%s:%d: %s", __FILE__, __LINE__, type)))

#define XOS_DBX(levels, name, args) \
    XOS_DEBUGL(levels, name) \
    && (XOS_DB_PRINTF(("%s", XOS_DB_FUNCTION))||1) \
    && XOS_DB_PRINTF(args)

#define XOS_DEBUG_NON_EXPORT

#if !defined(XOS_DEBUG_EXPORT) 
#if !defined(XOS_DEBUG_NON_EXPORT) 
#define XOS_DEBUG_EXPORT PLATFORM_IMPORT
#else // !defined(DEBUG_NON_EXPORT)
#define XOS_DEBUG_EXPORT
#endif // !defined(DEBUG_NON_EXPORT)
#else // !defined(DEBUG_EXPORT)
#endif // !defined(DEBUG_EXPORT)

#if !defined(DEBUG_EXPORT)
#define DEBUG_EXPORT XOS_DEBUG_EXPORT
#endif // !defined(DEBUG_EXPORT)

XOS_DEBUG_EXPORT extern XOS_DEBUG_LEVELS_T g_cdebug_levels;
#else // !defined(NO_XOS_DEBUG) 
#define XOS_DBX(levels, name, args)
#endif // !defined(NO_XOS_DEBUG) 

#define XOS_DBE(args) XOS_DBX(XOS_DEBUG_LEVEL_ERROR, "Error ", args)
#define XOS_DBW(args) XOS_DBX(XOS_DEBUG_LEVEL_WARN, "Warning ", args)
#define XOS_DBI(args) XOS_DBX(XOS_DEBUG_LEVEL_INFO, "", args)
#define XOS_DBT(args) XOS_DBX(XOS_DEBUG_LEVEL_TRACE, "", args)

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSDEBUG_HPP 

/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cdebug.h
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
#ifndef _CDEBUG_H
#define _CDEBUG_H

#include "cplatform.h"

#if !defined(DEBUG_EXPORT) 
#if !defined(DEBUG_NON_EXPORT) 
#define DEBUG_EXPORT PLATFORM_IMPORT
#else /* !defined(DEBUG_NON_EXPORT) */
#define DEBUG_EXPORT
#endif /* !defined(DEBUG_NON_EXPORT) */
#else /* !defined(DEBUG_EXPORT) */
#endif /* !defined(DEBUG_EXPORT) */

#if !defined(NO_DEBUG) 
#define DB_PRINTF(args) c_debug_printf args
#else /* !defined(NO_DEBUG) */
#define DB_PRINTF(args)
#endif /* !defined(NO_DEBUG) */

/**
 **********************************************************************
 *   Enum: e_DEBUG_LEVELS
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
typedef unsigned e_DEBUG_LEVELS_T;
enum e_DEBUG_LEVELS
{
    e_DEBUG_LEVELS_FIRST = 0,

    e_DEBUG_LEVELS_NONE = e_DEBUG_LEVELS_FIRST,
    e_DEBUG_LEVELS_ERROR,
    e_DEBUG_LEVELS_WARN,
    e_DEBUG_LEVELS_INFO,
    e_DEBUG_LEVELS_FUNC,
    e_DEBUG_LEVELS_TRACE,

    e_DEBUG_LEVELS_NEXT,
    e_DEBUG_LEVELS_LAST = e_DEBUG_LEVELS_NEXT-1,
    e_DEBUG_LEVELS_COUNT = e_DEBUG_LEVELS_LAST-e_DEBUG_LEVELS_FIRST+1
};

/**
 **********************************************************************
 *   Enum: e_DEBUG_LEVEL
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
enum e_DEBUG_LEVEL
{
    e_DEBUG_LEVEL_NONE  = 0,

    e_DEBUG_LEVEL_ERROR = (1 << (e_DEBUG_LEVELS_ERROR-1)),
    e_DEBUG_LEVEL_WARN  = (1 << (e_DEBUG_LEVELS_WARN-1)), 
    e_DEBUG_LEVEL_INFO  = (1 << (e_DEBUG_LEVELS_INFO-1)), 
    e_DEBUG_LEVEL_FUNC  = (1 << (e_DEBUG_LEVELS_FUNC-1)),
    e_DEBUG_LEVEL_TRACE = (1 << (e_DEBUG_LEVELS_TRACE-1)),

    e_DEBUG_LEVEL_NEXT  = (1 << (e_DEBUG_LEVELS_NEXT-1)),
    e_DEBUG_LEVEL_ALL   = (e_DEBUG_LEVEL_NEXT-1),
};

#define e_DEBUG_LEVEL_NAME_NONE "NONE"
#define e_DEBUG_LEVEL_NAME_ERROR "ERROR"
#define e_DEBUG_LEVEL_NAME_WARN "WARN"
#define e_DEBUG_LEVEL_NAME_INFO "INFO"
#define e_DEBUG_LEVEL_NAME_FUNC "FUNC"
#define e_DEBUG_LEVEL_NAME_TRACE "TRACE"

#define e_DEBUG_LEVEL_LABEL_ERROR "error: "
#define e_DEBUG_LEVEL_LABEL_WARN "warning: "
#define e_DEBUG_LEVEL_LABEL_INFO ""
#define e_DEBUG_LEVEL_LABEL_FUNC ""
#define e_DEBUG_LEVEL_LABEL_TRACE ""

#if !defined(DEFAULT_DEBUG_LEVELS) 
#if defined(NO_DEBUG_LEVELS) 
#define DEFAULT_DEBUG_LEVELS e_DEBUG_LEVELS_NONE
#else /* defined(NO_DEBUG_LEVELS) */
#define DEFAULT_DEBUG_LEVELS e_DEBUG_LEVELS_INFO
#endif /* defined(NO_DEBUG_LEVELS) */
#endif /* !defined(DEFAULT_DEBUG_LEVELS) */

#if !defined(DEFAULT_DEBUG_LEVEL_VALUE) 
#if defined(NO_DEBUG_LEVELS) 
#define DEFAULT_DEBUG_LEVEL_VALUE 0
#else /* defined(NO_DEBUG_LEVELS) */
#define DEFAULT_DEBUG_LEVEL_VALUE e_DEBUG_LEVEL_ALL
#endif /* defined(NO_DEBUG_LEVELS) */
#endif /* !defined(DEFAULT_DEBUG_LEVELS_VALUE) */

#if !defined(NO_DEBUG)
#define GET_DEBUG_LEVELS() g_cdebug_levels
#define SET_DEBUG_LEVELS(n) g_cdebug_levels = (e_DEBUG_LEVELS_T)((1 << n) - 1)
#define IS_DEBUGL(level) (g_cdebug_levels & level)
#define DEBUGL(level,type) \
    ((g_cdebug_levels & level) \
    && DB_PRINTF(("%s:%d: %s", __FILE__, __LINE__, type)))
#else /* !defined(NO_DEBUG) */
#define GET_DEBUG_LEVELS() 0
#define SET_DEBUG_LEVELS(n) 0
#define IS_DEBUGL(level) 0
#define DEBUGL(level,type)
#endif /* !defined(NO_DEBUG) */

#define IS_DBE IS_DEBUGL(e_DEBUG_LEVEL_ERROR)
#define IS_DBW IS_DEBUGL(e_DEBUG_LEVEL_WARN)
#define IS_DBI IS_DEBUGL(e_DEBUG_LEVEL_INFO)
#define IS_DBF IS_DEBUGL(e_DEBUG_LEVEL_FUNC)
#define IS_DBT IS_DEBUGL(e_DEBUG_LEVEL_TRACE)

#if !defined(NO_DEBUG) 
#if defined(__MSC__) 
/* 
 * Visual C++
 * ...
 */
#if (_MSC_VER <= MSC_VER_6) 
/* Visual C++ <= 6.0
 */
#define DF(name) static const char __FUNCTION__[]=""#name;
#else /* (_MSC_VER <= MSC_VER_6) */
/* Visual C++ >= 7.0
 */
#define DF(name)
#endif /* (_MSC_VER <= MSC_VER_6) */
#define DB_FUNCTION __FUNCTION__
#define CDB_FUNCTION (strrchr(__FUNCTION__,':')?(strrchr(__FUNCTION__,':')+1):(__FUNCTION__))
/* 
 * ...
 * Visual C++
 */
#else /* defined(__MSC__) */
#endif /* defined(__MSC__) */

#if defined(__GNUC__) 
/*
 * Gcc
 * ...
 */
#if defined(DB_USE_PRETTY_FUNCTION)
#define DB_FUNCTION __PRETTY_FUNCTION__
#else
#define DB_FUNCTION __FUNCTION__
#endif /* defined(DB_USE_PRETTY_FUNCTION) */
#define DF(name)
#define CDB_FUNCTION __FUNCTION__
/*
 * ...
 * Gcc
 */
#else /* defined(__GNUC__) */
#endif /* defined(__GNUC__) */
#else /* !defined(NO_DEBUG) */
#define DF(name)
#define DB_FUNCTION
#define CDB_FUNCTION
#endif /* !defined(NO_DEBUG) */

#if !defined(NO_DEBUG) 
#define DBE(args) DEBUGL(e_DEBUG_LEVEL_ERROR, e_DEBUG_LEVEL_LABEL_ERROR) && (DB_PRINTF(("%s", DB_FUNCTION))||1) && DB_PRINTF(args)
#define DBW(args) DEBUGL(e_DEBUG_LEVEL_WARN, e_DEBUG_LEVEL_LABEL_WARN) && (DB_PRINTF(("%s", DB_FUNCTION))||1) && DB_PRINTF(args)
#define DBI(args) DEBUGL(e_DEBUG_LEVEL_INFO, e_DEBUG_LEVEL_LABEL_INFO) && (DB_PRINTF(("%s", DB_FUNCTION))||1) && DB_PRINTF(args)
#define DBF(args) DEBUGL(e_DEBUG_LEVEL_FUNC, e_DEBUG_LEVEL_LABEL_FUNC) && (DB_PRINTF(("%s", DB_FUNCTION))||1) && DB_PRINTF(args)
#define DBT(args) DEBUGL(e_DEBUG_LEVEL_TRACE, e_DEBUG_LEVEL_LABEL_TRACE) && (DB_PRINTF(("%s", DB_FUNCTION))||1) && DB_PRINTF(args)
#else /* !defined(NO_DEBUG) */
#define DBE(args)
#define DBW(args)
#define DBI(args)
#define DBF(args)
#define DBT(args)
#endif /* !defined(NO_DEBUG) */

#if defined(__cplusplus)
/* C++
 */
#if !defined(NO_DEBUG) 
#define CBB_CLASS "cClass"
#define CDBE(args) DEBUGL(e_DEBUG_LEVEL_ERROR, e_DEBUG_LEVEL_LABEL_ERROR) && (DB_PRINTF((" %s::%s", CDB_CLASS, CDB_FUNCTION))||1) && DB_PRINTF(args)
#define CDBW(args) DEBUGL(e_DEBUG_LEVEL_WARN, e_DEBUG_LEVEL_LABEL_WARN) && (DB_PRINTF((" %s::%s", CDB_CLASS, CDB_FUNCTION))||1) && DB_PRINTF(args)
#define CDBI(args) DEBUGL(e_DEBUG_LEVEL_INFO, e_DEBUG_LEVEL_LABEL_INFO) && (DB_PRINTF((" %s::%s", CDB_CLASS, CDB_FUNCTION))||1) && DB_PRINTF(args)
#define CDBF(args) DEBUGL(e_DEBUG_LEVEL_FUNC, e_DEBUG_LEVEL_LABEL_FUNC) && (DB_PRINTF((" %s::%s", CDB_CLASS, CDB_FUNCTION))||1) && DB_PRINTF(args)
#define CDBT(args) DEBUGL(e_DEBUG_LEVEL_TRACE, e_DEBUG_LEVEL_LABEL_TRACE) && (DB_PRINTF((" %s::%s", CDB_CLASS, CDB_FUNCTION))||1) && DB_PRINTF(args)
#else /* !defined(NO_DEBUG) */
#define CBB_CLASS 
#define CDBE(args)
#define CDBW(args)
#define CDBI(args)
#define CDBF(args)
#define CDBT(args)
#endif /* !defined(NO_DEBUG) */

extern "C" {
#endif /* defined(__cplusplus) */

#if !defined(NO_DEBUG) 
DEBUG_EXPORT extern e_DEBUG_LEVELS_T g_cdebug_levels;
DEBUG_EXPORT extern e_DEBUG_LEVELS_T g_cdebug_level_value[e_DEBUG_LEVELS_COUNT];
DEBUG_EXPORT extern const char* g_cdebug_level_name[e_DEBUG_LEVELS_COUNT];
DEBUG_EXPORT int c_debug_printf(const char* format, ...);
#endif /* !defined(NO_DEBUG) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CDEBUG_H */

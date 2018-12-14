/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: debug.h
 *
 * Author: $author$
 *   Date: 2/13/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _DEBUG_H
#define _DEBUG_H

#include "platform.h"
#include <stdio.h>

/**
 **********************************************************************
 * enum
 *
 * Author: $author$
 *   Date: 2/13/2007
 **********************************************************************
 */
enum
{
    DEBUG_LEVEL_NONE  = 0, 
    DEBUG_LEVEL_ERROR = 1, 
    DEBUG_LEVEL_WARN  = (1 << 1), 
    DEBUG_LEVEL_INFO  = (1 << 2), 
    DEBUG_LEVEL_FUNC  = (1 << 3),
    DEBUG_LEVEL_TRACE = (1 << 4),

	NEXT_DEBUG_LEVEL  = (1 << 5),
	ALL_DEBUG_LEVELS  = (NEXT_DEBUG_LEVEL - 1)
};

#define DEFAULT_DEBUG_LEVELS ALL_DEBUG_LEVELS

typedef UINT TDEBUG_LEVEL;

#define DEBUG_LEVEL_ERROR_NAME "error: "
#define DEBUG_LEVEL_WARN_NAME "warning: "
#define DEBUG_LEVEL_INFO_NAME ""
#define DEBUG_LEVEL_FUNC_NAME ""
#define DEBUG_LEVEL_TRACE_NAME ""

#define GET_DEBUG_LEVELS() g_debugLevels
#define SET_DEBUG_LEVELS(n) g_debugLevels = ((1 << n) - 1)
#define IS_DEBUGL(level) (g_evDebugLevels & level)
#define DEBUGL(level,type) ((g_debugLevels & level) && printf("%s:%d: %s", __FILE__, __LINE__, type))

#define IS_DBE IS_DEBUGL(DEBUG_LEVEL_ERROR)
#define IS_DBW IS_DEBUGL(DEBUG_LEVEL_WARN)
#define IS_DBI IS_DEBUGL(DEBUG_LEVEL_INFO)
#define IS_DBF IS_DEBUGL(DEBUG_LEVEL_FUNC)
#define IS_DBT IS_DEBUGL(DEBUG_LEVEL_TRACE)

#if defined(WIN32)
#if (_MSC_VER <= MSC_VER_6) 
#define DB_FUNCTION __FUNCTION__
#define DF(name) static const char __FUNCTION__[]=""#name;
#else /* (_MSC_VER <= MSC_VER_6) */
#define DB_FUNCTION __FUNCTION__
#define DF(name)
#endif /* (_MSC_VER <= MSC_VER_6) */
#define CDB_FUNCTION (strrchr(__FUNCTION__,':')?(strrchr(__FUNCTION__,':')+1):(__FUNCTION__))
#else /* defined(WIN32) */
#if defined(DB_USE_PRETTY_FUNCTION)
#define DB_FUNCTION __PRETTY_FUNCTION__
#else
#define DB_FUNCTION __FUNCTION__
#endif /* defined(DB_USE_PRETTY_FUNCTION) */
#define DF(name)
#define CDB_FUNCTION __FUNCTION__
#endif /* defined(WIN32) */

#define DBE DEBUGL(DEBUG_LEVEL_ERROR, DEBUG_LEVEL_ERROR_NAME) && (printf("%s", DB_FUNCTION)||1) && printf
#define DBW DEBUGL(DEBUG_LEVEL_WARN, DEBUG_LEVEL_WARN_NAME) && (printf("%s", DB_FUNCTION)||1) && printf
#define DBI DEBUGL(DEBUG_LEVEL_INFO, DEBUG_LEVEL_INFO_NAME) && (printf("%s", DB_FUNCTION)||1) && printf
#define DBF DEBUGL(DEBUG_LEVEL_FUNC, DEBUG_LEVEL_FUNC_NAME) && (printf("%s", DB_FUNCTION)||1) && printf
#define DBT DEBUGL(DEBUG_LEVEL_TRACE, DEBUG_LEVEL_TRACE_NAME) && (printf("%s", DB_FUNCTION)||1) && printf

#define CDBE DEBUGL(DEBUG_LEVEL_ERROR, DEBUG_LEVEL_ERROR_NAME) && (printf(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBW DEBUGL(DEBUG_LEVEL_WARN, DEBUG_LEVEL_WARN_NAME) && (printf(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBI DEBUGL(DEBUG_LEVEL_INFO, DEBUG_LEVEL_INFO_NAME) && (printf(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBF DEBUGL(DEBUG_LEVEL_FUNC, DEBUG_LEVEL_FUNC_NAME) && (printf(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBT DEBUGL(DEBUG_LEVEL_TRACE, DEBUG_LEVEL_TRACE_NAME) && (printf(" %s::%s", CDB_CLASS, CDB_FUNCTION)||1) && printf

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(DEBUG_EXPORT)
PLATFORM_EXPORT extern
#else /* defined(DEBUG_EXPORT) */
PLATFORM_IMPORT extern
#endif /* defined(DEBUG_EXPORT) */
TDEBUG_LEVEL g_debugLevels;

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _DEBUG_H */

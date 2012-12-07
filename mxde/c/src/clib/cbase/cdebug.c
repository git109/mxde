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
 *   File: cdebug.c
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
#include "cplatform.h"

#if !defined(DEBUG_EXPORT) 
#if !defined(DEBUG_NON_EXPORT) 
#define DEBUG_EXPORT PLATFORM_EXPORT
#else /* !defined(DEBUG_NON_EXPORT) */
#define DEBUG_EXPORT
#endif /* !defined(DEBUG_NON_EXPORT) */
#else /* !defined(DEBUG_EXPORT) */
#endif /* !defined(DEBUG_EXPORT) */

#include "cdebug.h"

/**
 **********************************************************************
 *   Enum: e_DEBUG_LEVEL
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
#if !defined(NO_DEBUG) 
e_DEBUG_LEVELS_T g_cdebug_levels = DEFAULT_DEBUG_LEVEL_VALUE;
e_DEBUG_LEVELS_T g_cdebug_level_value[e_DEBUG_LEVELS_COUNT] = 
{
    e_DEBUG_LEVEL_NONE,
    e_DEBUG_LEVEL_ERROR,
    e_DEBUG_LEVEL_WARN,
    e_DEBUG_LEVEL_INFO,
    e_DEBUG_LEVEL_FUNC,
    e_DEBUG_LEVEL_TRACE
};
const char* g_cdebug_level_name[e_DEBUG_LEVELS_COUNT] = 
{
    e_DEBUG_LEVEL_NAME_NONE,
    e_DEBUG_LEVEL_NAME_ERROR,
    e_DEBUG_LEVEL_NAME_WARN,
    e_DEBUG_LEVEL_NAME_INFO,
    e_DEBUG_LEVEL_NAME_FUNC,
    e_DEBUG_LEVEL_NAME_TRACE
};
#endif /* !defined(NO_DEBUG) */

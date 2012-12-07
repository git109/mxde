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
 *   File: cdebug.cxx
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

#include "cdebug.hxx"
#include "cdebug.c"

static cStreamInterface* c_debug_stream = 0;

/**
 **********************************************************************
 *  Function: c_debug_set_stream
 *
 *    Author: $author$
 *      Date: 10/21/2011
 **********************************************************************
 */
DEBUG_EXPORT cStreamInterface* c_debug_set_stream
(cStreamInterface* stream)
{
    c_debug_stream = stream;
    return c_debug_stream;
}
/**
 **********************************************************************
 *  Function: c_debug_get_stream
 *
 *    Author: $author$
 *      Date: 10/21/2011
 **********************************************************************
 */
DEBUG_EXPORT cStreamInterface* c_debug_get_stream()
{
    return c_debug_stream;
}

/**
 **********************************************************************
 *  Function: c_debug_printf
 *
 *    Author: $author$
 *      Date: 10/21/2011
 **********************************************************************
 */
DEBUG_EXPORT int c_debug_printf
(const char* format, ...)
{
    int len = 0;
    va_list va;
    va_start(va, format);
    if ((c_debug_stream))
        len = c_debug_stream->VWriteFormatted(format, va);
    else
    len = vprintf(format, va);
    va_end(va);
    return len;
}

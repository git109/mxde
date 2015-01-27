/**
 **********************************************************************
 * Copyright (c) 1988-2015 $organization$
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
 *   File: cdebug_printf.c
 *
 * Author: $author$
 *   Date: 1/22/2015
 **********************************************************************
 */
#include "cdebug_printf.h"

#if defined(CDEBUG_PRINTF)
#include <stdarg.h>
int CDEBUG_PRINTF(const char* format, ...) {
    int count = 0;
    va_list va;
    va_start(va, format);
    count = vprintf(format, va);
    va_end(va);
    return count;
}
#else /* defined(CDEBUG_PRINTF) */
#endif /* defined(CDEBUG_PRINTF) */

/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: platform.c
 *
 * Author: $author$
 *   Date: 1/19/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "platform.h"
#include "platform_time.h"

#if defined(EMBEDDED) 
#else /* defined(EMBEDDED) */
int platform_forever = 1;
#endif /* defined(EMBEDDED) */

#if defined(WIN32)
#else /* defined(WIN32) */
DWORD platform_militime(void) {
    return platform_microtime()/1000;
}
DWORD platform_microtime(void) {
    return (DWORD)utime();
}
#endif /* defined(WIN32) */


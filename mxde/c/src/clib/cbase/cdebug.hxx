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
 *   File: cdebug.hxx
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
#ifndef _CDEBUG_HXX
#define _CDEBUG_HXX

#include "cdebug.h"
#include "cstreaminterface.hxx"

#define DBE_THROW_ERROR(error, expr) \
if ((error = (expr))) \
{ \
    DBE(("() throwing error = %d\n", error)); \
    throw (error); \
}

#if !defined(NO_DEBUG) 
#define SET_DEBUG_STREAM(stream) c_debug_set_stream(stream)
#define GET_DEBUG_STREAM() c_debug_get_stream()
#else /* !defined(NO_DEBUG) */
#define SET_DEBUG_STREAM(stream)
#define GET_DEBUG_STREAM() 0
#endif /* !defined(NO_DEBUG) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if !defined(NO_DEBUG) 
/**
 **********************************************************************
 *  Function: c_debug_set_stream
 *
 *    Author: $author$
 *      Date: 10/21/2011
 **********************************************************************
 */
DEBUG_EXPORT cStreamInterface* c_debug_set_stream
(cStreamInterface* stream);
/**
 **********************************************************************
 *  Function: c_debug_get_stream
 *
 *    Author: $author$
 *      Date: 10/21/2011
 **********************************************************************
 */
DEBUG_EXPORT cStreamInterface* c_debug_get_stream();
#endif /* !defined(NO_DEBUG) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CDEBUG_HXX */

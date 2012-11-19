/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cHttpRequestMethod.h
 *
 * Author: $author$
 *   Date: 10/27/2011
 **********************************************************************
 */
#ifndef _CHTTPREQUESTMETHOD_H
#define _CHTTPREQUESTMETHOD_H

/**
 **********************************************************************
 *    Enum: eHttpRequestMethod
 *
 *  Author: $author$
 *    Date: 10/27/2011
 **********************************************************************
 */
typedef int eHttpRequestMethod;
enum
{
    e_HTTP_REQUEST_METHOD_NONE = 0,
    e_FIRST_HTTP_REQUEST_METHOD = 1,

    e_HTTP_REQUEST_METHOD_GET = e_FIRST_HTTP_REQUEST_METHOD,
    e_HTTP_REQUEST_METHOD_POST,
    e_HTTP_REQUEST_METHOD_PUT,
    e_HTTP_REQUEST_METHOD_DELETE,
    e_HTTP_REQUEST_METHOD_TRACE,
    e_HTTP_REQUEST_METHOD_HEAD,
    e_HTTP_REQUEST_METHOD_OPTIONS,

    e_NEXT_HTTP_REQUEST_METHOD,
    e_LAST_HTTP_REQUEST_METHOD = e_NEXT_HTTP_REQUEST_METHOD-1,
    e_COUNT_HTTP_REQUEST_METHOD = e_LAST_HTTP_REQUEST_METHOD-e_FIRST_HTTP_REQUEST_METHOD+1,
};

#define c_HTTP_REQUEST_METHOD_NAME_GET     "GET"
#define c_HTTP_REQUEST_METHOD_NAME_POST    "POST"
#define c_HTTP_REQUEST_METHOD_NAME_PUT     "PUT"
#define c_HTTP_REQUEST_METHOD_NAME_DELETE  "DELETE"
#define c_HTTP_REQUEST_METHOD_NAME_TRACE   "TRACE"
#define c_HTTP_REQUEST_METHOD_NAME_HEAD    "HEAD"
#define c_HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CHTTPREQUESTMETHOD_H */
        


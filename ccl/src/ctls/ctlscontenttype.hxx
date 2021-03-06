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
 *   File: ctlscontenttype.hxx
 *
 * Author: $author$
 *   Date: 10/18/2007
 *
 **********************************************************************
 */

#ifndef _CTLSCONTENTTYPE_HXX
#define _CTLSCONTENTTYPE_HXX

#include "platform.h"

/**
 **********************************************************************
 *   Enum:  
 *
 * Author: $author$
 *   Date: 10/18/2007
 **********************************************************************
 */
enum 
{
    e_TLS_CONTENT_TYPE_FIRST,

    e_TLS_CONTENT_TYPE_CHANGE_CIPHER_SPEC = e_TLS_CONTENT_TYPE_FIRST,
    e_TLS_CONTENT_TYPE_ALERT,
    e_TLS_CONTENT_TYPE_HANDSHAKE,
    e_TLS_CONTENT_TYPE_APPLICATION_DATA,

    e_TLS_CONTENT_TYPE_NEXT,
    e_TLS_CONTENT_TYPE_LAST = e_TLS_CONTENT_TYPE_NEXT-1,
    e_TLS_CONTENT_TYPE_COUNT = e_TLS_CONTENT_TYPE_LAST-e_TLS_CONTENT_TYPE_FIRST+1
};

/**
 **********************************************************************
 *   Enum: 
 *
 * Author: $author$
 *   Date: 10/18/2007
 **********************************************************************
 */
enum
{
    e_TLS_CONTENT_TYPE_VALUE_CHANGE_CIPHER_SPEC = 20,
    e_TLS_CONTENT_TYPE_VALUE_ALERT = 21,
    e_TLS_CONTENT_TYPE_VALUE_HANDSHAKE = 22,
    e_TLS_CONTENT_TYPE_VALUE_APPLICATION_DATA = 23
};

#define e_TLS_CONTENT_TYPE_NAME_CHANGE_CIPHER_SPEC "CHANGE_CIPHER_SPEC"
#define e_TLS_CONTENT_TYPE_NAME_ALERT "ALERT"
#define e_TLS_CONTENT_TYPE_NAME_HANDSHAKE "HANDSHAKE"
#define e_TLS_CONTENT_TYPE_NAME_APPLICATION_DATA "APPLICATION_DATA"

extern int g_e_tls_content_type_value[e_TLS_CONTENT_TYPE_COUNT];
extern const char* g_e_tls_content_type_name[e_TLS_CONTENT_TYPE_COUNT];

/**
 **********************************************************************
 * Typedef: eTLSContentType
 *
 *  Author: $author$
 *    Date: 10/18/2007
 **********************************************************************
 */
typedef uint8
eTLSContentType;

#endif /* _CTLSCONTENTTYPE_HXX */

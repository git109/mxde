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
 *   File: ctlsclientcertificatetype.hxx
 *
 * Author: $author$
 *   Date: 10/18/2007
 *
 **********************************************************************
 */


#ifndef _CTLSCLIENTCERTIFICATETYPE_HXX
#define _CTLSCLIENTCERTIFICATETYPE_HXX


#if !defined() 
#else /* !defined() */
#endif /* !defined() */
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
    e_TLS_CERTIFICATE_TYPE_FIRST,

    e_TLS_CERTIFICATE_TYPE_RSA_SIGN,
    e_TLS_CERTIFICATE_TYPE_DSS_SIGN,
    e_TLS_CERTIFICATE_TYPE_RSA_FIXED_DH,
    e_TLS_CERTIFICATE_TYPE_DSS_FIXED_DH,

    e_TLS_CERTIFICATE_TYPE_NEXT,
    e_TLS_CERTIFICATE_TYPE_LAST = e_TLS_CERTIFICATE_TYPE_NEXT-1,
    e_TLS_CERTIFICATE_TYPE_COUNT = e_TLS_CERTIFICATE_TYPE_LAST-e_TLS_CERTIFICATE_TYPE_FIRST+1
};

#define e_TLS_CERTIFICATE_TYPE_NAME_RSA_SIGN "RSA_SIGN"
#define e_TLS_CERTIFICATE_TYPE_NAME_DSS_SIGN "DSS_SIGN"
#define e_TLS_CERTIFICATE_TYPE_NAME_RSA_FIXED_DH "RSA_FIXED_DH"
#define e_TLS_CERTIFICATE_TYPE_NAME_DSS_FIXED_DH "DSS_FIXED_DH"

extern int g_e_tls_certificate_type_value[e_TLS_CERTIFICATE_TYPE_COUNT];
extern const char* g_e_tls_certificate_type_name[e_TLS_CERTIFICATE_TYPE_COUNT];


/**
 **********************************************************************
 * Typedef: eTLSClientCertificateType
 *
 *  Author: $author$
 *    Date: 10/18/2007
 **********************************************************************
 */
typedef int
eTLSClientCertificateType;

#endif /* _CTLSCLIENTCERTIFICATETYPE_HXX */

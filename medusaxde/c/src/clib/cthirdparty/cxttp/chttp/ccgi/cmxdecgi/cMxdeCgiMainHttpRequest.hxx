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
 *   File: cMxdeCgiMainHttpRequest.hxx
 *
 * Author: $author$
 *   Date: 10/27/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINHTTPREQUEST_HXX
#define _CMXDECGIMAINHTTPREQUEST_HXX

#include "cplatform.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *    Enum: eMxdeCgiHttpRequestMethod
 *
 *  Author: $author$
 *    Date: 10/27/2011
 **********************************************************************
 */
typedef int eMxdeCgiHttpRequestMethod;
enum 
{
    e_MXDE_CGI_HTTP_REQUEST_METHOD_NONE = 0,
    e_FIRST_MXDE_CGI_HTTP_REQUEST_METHOD = 1,

    e_MXDE_CGI_HTTP_REQUEST_METHOD_GET = e_FIRST_MXDE_CGI_HTTP_REQUEST_METHOD,
    e_MXDE_CGI_HTTP_REQUEST_METHOD_POST,
    e_MXDE_CGI_HTTP_REQUEST_METHOD_PUT,
    e_MXDE_CGI_HTTP_REQUEST_METHOD_DELETE,
    e_MXDE_CGI_HTTP_REQUEST_METHOD_TRACE,
    e_MXDE_CGI_HTTP_REQUEST_METHOD_HEAD,
    e_MXDE_CGI_HTTP_REQUEST_METHOD_OPTIONS,

    e_NEXT_MXDE_CGI_HTTP_REQUEST_METHOD,
    e_LAST_MXDE_CGI_HTTP_REQUEST_METHOD = (e_NEXT_MXDE_CGI_HTTP_REQUEST_METHOD-1),
    e_COUNT_MXDE_CGI_HTTP_REQUEST_METHOD = (e_LAST_MXDE_CGI_HTTP_REQUEST_METHOD-e_FIRST_MXDE_CGI_HTTP_REQUEST_METHOD+1)
};

/**
 **********************************************************************
 *  Class: cMxdeCgiMainHttpRequest
 *
 * Author: $author$
 *   Date: 10/27/2011
 **********************************************************************
 */
class c_INTERFACE_CLASS cMxdeCgiMainHttpRequest
{
public:
    /**
     **********************************************************************
     *  Function: GetRequestMethod
     *
     *    Author: $author$
     *      Date: 10/27/2011
     **********************************************************************
     */
    virtual eMxdeCgiHttpRequestMethod GetRequestMethod() const
    {
        eMxdeCgiHttpRequestMethod requestMethod = e_MXDE_CGI_HTTP_REQUEST_METHOD_NONE;
        return requestMethod;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINHTTPREQUEST_HXX */
        


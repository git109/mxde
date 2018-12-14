/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: ccgi.hxx
 *
 * Author: $author$
 *   Date: 12/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCGI_HXX
#define _CCGI_HXX

#include "chttpcontent.hxx"
#include "ccgiinterface.hxx"

/**
 **********************************************************************
 *  Class: cCGI
 *
 * Author: $author$
 *   Date: 12/5/2003
 **********************************************************************
 */
class cCGI
: virtual public cCGIInterface,
  public cHTTPContent
{
public:
    typedef cHTTPContent cIs;

    /**
     **********************************************************************
     *   Enum: eEnv
     *
     * Author: $author$
     *   Date: 8/9/2003
     **********************************************************************
     */
    enum eEnv
    {
        e_FIRST_ENV,

        e_ENV_GATEWAY_INTERFACE = e_FIRST_ENV,
		e_ENV_SERVER_NAME,
		e_ENV_SERVER_PORT,
		e_ENV_SERVER_PROTOCOL,
		e_ENV_SERVER_SOFTWARE,
		e_ENV_AUTH_TYPE,
		e_ENV_CONTENT_FILE,
		e_ENV_CONTENT_LENGTH,
		e_ENV_CONTENT_TYPE,
		e_ENV_OUTPUT_FILE,
		e_ENV_PATH_INFO,
		e_ENV_PATH_TRANSLATED,
		e_ENV_QUERY_STRING,
		e_ENV_REMOTE_ADDR,
		e_ENV_REMOTE_USER,
		e_ENV_REQUEST_LINE,
		e_ENV_REQUEST_METHOD,
		e_ENV_REMOTE_HOST,
		e_ENV_REMOTE_IDENT,
		e_ENV_HTTP_ACCEPT,
		e_ENV_HTTP_USER_AGENT,
		e_ENV_SCRIPT_NAME,

        e_NUMBEROF_ENV,
        e_LAST_ENV = e_NUMBEROF_ENV-1
    };

    /**
     **********************************************************************
     *   Enum: eRequestMethod
     *
     * Author: $author$
     *   Date: 8/9/2003
     **********************************************************************
     */
    enum eRequestMethod
    {
        e_FIRST_REQUEST_METHOD,
        e_REQUEST_METHOD_GET = e_FIRST_REQUEST_METHOD,
        e_REQUEST_METHOD_POST,
        e_REQUEST_METHOD_UNKNOWN,
        e_NUMBEROF_REQUEST_METHODS = e_REQUEST_METHOD_UNKNOWN,
        e_LAST_REQUEST_METHOD = e_NUMBEROF_REQUEST_METHODS-1
    };

    static const char *m_env_name[e_NUMBEROF_ENV];
    static const char *m_request_method_name[e_NUMBEROF_REQUEST_METHODS];

    /**
     **********************************************************************
     * Constructor: cCGI
     *
     *      Author: $author$
     *        Date: 12/5/2003
     **********************************************************************
     */
    cCGI() 
    : cHTTPContent() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCGI
     *
     *     Author: $author$
     *       Date: 12/5/2003
     **********************************************************************
     */
    virtual ~cCGI()
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 12/5/2003
     **********************************************************************
     */
};

#endif /* ndef _CCGI_HXX */

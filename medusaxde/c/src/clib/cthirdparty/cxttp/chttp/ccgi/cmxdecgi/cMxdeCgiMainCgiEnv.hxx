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
 *   File: cMxdeCgiMainCgiEnv.hxx
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINCGIENV_HXX
#define _CMXDECGIMAINCGIENV_HXX

#include "cplatform.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef int eMxdeCgiMainCgiEnv;
/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgiEnv
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
class c_INTERFACE_CLASS cMxdeCgiMainCgiEnv
{
public:
    /**
     **********************************************************************
     *  Function: GetCgiEnvName
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    virtual const char* GetCgiEnvName
    (eMxdeCgiMainCgiEnv env) const
    {
        const char* envName = 0;
        return envName;
    }
    /**
     **********************************************************************
     *  Function: GetCgiEnvValue
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    virtual const char* GetCgiEnvValue
    (eMxdeCgiMainCgiEnv env) const
    {
        const char* envValue = 0;
        return envValue;
    }

    /**
     **********************************************************************
     *  Function: GetFirstCgiEnv
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    virtual const char* GetFirstCgiEnv
    (eMxdeCgiMainCgiEnv& env, const char*& envValue) const
    {
        const char* envName = 0;
        return envName;
    }
    /**
     **********************************************************************
     *  Function: GetNextCgiEnv
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    virtual const char* GetNextCgiEnv
    (eMxdeCgiMainCgiEnv& env, const char*& envValue) const
    {
        const char* envName = 0;
        return envName;
    }

    /**
     **********************************************************************
     *  Function: GetLastCgiEnv
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    virtual const char* GetLastCgiEnv
    (eMxdeCgiMainCgiEnv& env, const char*& envValue) const
    {
        const char* envName = 0;
        return envName;
    }
    /**
     **********************************************************************
     *  Function: GetPrevCgiEnv
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    virtual const char* GetPrevCgiEnv
    (eMxdeCgiMainCgiEnv& env, const char*& envValue) const
    {
        const char* envName = 0;
        return envName;
    }
};

/**
 **********************************************************************
 *    Enum: eMxdeCgiMainCgiEnv
 *
 *  Author: $author$
 *    Date: 10/3/2011
 **********************************************************************
 */
enum
{
    e_UNKNOWN_MXDECGIMAIN_CGI_ENV = -1,
    e_FIRST_MXDECGIMAIN_CGI_ENV = 0,

    e_MXDECGIMAIN_CGI_ENV_GATEWAY_INTERFACE = e_FIRST_MXDECGIMAIN_CGI_ENV,
	e_MXDECGIMAIN_CGI_ENV_SERVER_NAME,
	e_MXDECGIMAIN_CGI_ENV_SERVER_PORT,
	e_MXDECGIMAIN_CGI_ENV_SERVER_PROTOCOL,
	e_MXDECGIMAIN_CGI_ENV_SERVER_SOFTWARE,
	e_MXDECGIMAIN_CGI_ENV_AUTH_TYPE,
	e_MXDECGIMAIN_CGI_ENV_CONTENT_FILE,
	e_MXDECGIMAIN_CGI_ENV_CONTENT_LENGTH,
	e_MXDECGIMAIN_CGI_ENV_CONTENT_TYPE,
	e_MXDECGIMAIN_CGI_ENV_OUTPUT_FILE,
	e_MXDECGIMAIN_CGI_ENV_PATH_INFO,
	e_MXDECGIMAIN_CGI_ENV_PATH_TRANSLATED,
	e_MXDECGIMAIN_CGI_ENV_QUERY_STRING,
	e_MXDECGIMAIN_CGI_ENV_REMOTE_ADDR,
	e_MXDECGIMAIN_CGI_ENV_REMOTE_USER,
	e_MXDECGIMAIN_CGI_ENV_REQUEST_LINE,
	e_MXDECGIMAIN_CGI_ENV_REQUEST_METHOD,
	e_MXDECGIMAIN_CGI_ENV_REMOTE_HOST,
	e_MXDECGIMAIN_CGI_ENV_REMOTE_IDENT,
	e_MXDECGIMAIN_CGI_ENV_HTTP_ACCEPT,
	e_MXDECGIMAIN_CGI_ENV_HTTP_USER_AGENT,
	e_MXDECGIMAIN_CGI_ENV_SCRIPT_NAME,

    e_NEXT_MXDECGIMAIN_CGI_ENV,
    e_LAST_MXDECGIMAIN_CGI_ENV = e_NEXT_MXDECGIMAIN_CGI_ENV-1,
    e_COUNT_MXDECGIMAIN_CGI_ENV = e_LAST_MXDECGIMAIN_CGI_ENV-e_FIRST_MXDECGIMAIN_CGI_ENV+1
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINCGIENV_HXX */
        


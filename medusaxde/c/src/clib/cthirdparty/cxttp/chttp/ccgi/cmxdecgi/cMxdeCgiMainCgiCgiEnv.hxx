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
 *   File: cMxdeCgiMainCgiCgiEnv.hxx
 *
 * Author: $author$
 *   Date: 10/4/2011
 **********************************************************************
 */
#if !defined(_CMXDECGIMAINCGICGIENV_HXX) || defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY)
#if !defined(_CMXDECGIMAINCGICGIENV_HXX) && !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY)
#define _CMXDECGIMAINCGICGIENV_HXX
#endif /* !defined(_CMXDECGIMAINCGICGIENV_HXX) && !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY)
#include "cCgiEnvInterface.hpp"
#include "cInstanceBase.hpp"
#include "cMxdeCgiMainCgiEnv.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiCgiEnvImplement
 *
 *  Author: $author$
 *    Date: 10/4/2011
 **********************************************************************
 */
typedef cCgiEnvImplement
cMxdeCgiMainCgiCgiEnvImplement;
/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiCgiEnvExtend
 *
 *  Author: $author$
 *    Date: 10/4/2011
 **********************************************************************
 */
typedef cInstanceBase
cMxdeCgiMainCgiCgiEnvExtend;
/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgiCgiEnv
 *
 * Author: $author$
 *   Date: 10/4/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cMxdeCgiMainCgiCgiEnv
: virtual public cMxdeCgiMainCgiCgiEnvImplement,
  public cMxdeCgiMainCgiCgiEnvExtend
{
public:
    typedef cMxdeCgiMainCgiCgiEnvImplement cImplements;
    typedef cMxdeCgiMainCgiCgiEnvExtend cExtends;

    cMxdeCgiMainCgiEnv& m_env;

    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMainCgiCgiEnv
     *
     *       Author: $author$
     *         Date: 10/4/2011
     **********************************************************************
     */
    cMxdeCgiMainCgiCgiEnv
    (cMxdeCgiMainCgiEnv& env)
    : m_env(env)
    {
    }
#else /* !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: Get
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* Get
    (eCgiEnv e) const
    {
        const char* chars = 0;
        eMxdeCgiMainCgiEnv cgiEnv = ToMxdeCgiMainCgiEnv(e);
        if ((chars = m_env.GetCgiEnvValue(cgiEnv)))
            e = ToCgiEnv(cgiEnv);
        return chars;
    }
    /**
     **********************************************************************
     *  Function: GetName
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetName
    (eCgiEnv e) const
    {
        const char* chars = 0;
        eMxdeCgiMainCgiEnv cgiEnv = ToMxdeCgiMainCgiEnv(e);
        if ((chars = m_env.GetCgiEnvName(cgiEnv)))
            e = ToCgiEnv(cgiEnv);
        return chars;
    }

    /**
     **********************************************************************
     *  Function: GetFirst
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetFirst
    (eCgiEnv& e, const char*& valueChars) const
    {
        const char* chars = 0;
        eMxdeCgiMainCgiEnv cgiEnv;
        if ((chars = m_env.GetFirstCgiEnv(cgiEnv, valueChars)))
            e = ToCgiEnv(cgiEnv);
        return chars;
    }
    /**
     **********************************************************************
     *  Function: GetNext
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetNext
    (eCgiEnv& e, const char*& valueChars) const
    {
        const char* chars = 0;
        eMxdeCgiMainCgiEnv cgiEnv = ToMxdeCgiMainCgiEnv(e);
        if ((chars = m_env.GetNextCgiEnv(cgiEnv, valueChars)))
            e = ToCgiEnv(cgiEnv);
        return chars;
    }

    /**
     **********************************************************************
     *  Function: GetLast
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetLast
    (eCgiEnv& e, const char*& valueChars) const
    {
        const char* chars = 0;
        eMxdeCgiMainCgiEnv cgiEnv;
        if ((chars = m_env.GetLastCgiEnv(cgiEnv, valueChars)))
            e = ToCgiEnv(cgiEnv);
        return chars;
    }
    /**
     **********************************************************************
     *  Function: GetPrev
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetPrev
    (eCgiEnv& e, const char*& valueChars) const
    {
        const char* chars = 0;
        eMxdeCgiMainCgiEnv cgiEnv = ToMxdeCgiMainCgiEnv(e);
        if ((chars = m_env.GetPrevCgiEnv(cgiEnv, valueChars)))
            e = ToCgiEnv(cgiEnv);
        return chars;
    }

    /**
     **********************************************************************
     *  Function: ToCgiEnv
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual eCgiEnv ToCgiEnv
    (eMxdeCgiMainCgiEnv env) const
    {
        switch (env)
        {
            case e_MXDECGIMAIN_CGI_ENV_GATEWAY_INTERFACE: return e_CGI_ENV_GATEWAY_INTERFACE;
            case e_MXDECGIMAIN_CGI_ENV_SERVER_NAME: return e_CGI_ENV_SERVER_NAME;
            case e_MXDECGIMAIN_CGI_ENV_SERVER_PORT: return e_CGI_ENV_SERVER_PORT;
            case e_MXDECGIMAIN_CGI_ENV_SERVER_PROTOCOL: return e_CGI_ENV_SERVER_PROTOCOL;
            case e_MXDECGIMAIN_CGI_ENV_SERVER_SOFTWARE: return e_CGI_ENV_SERVER_SOFTWARE;
            case e_MXDECGIMAIN_CGI_ENV_AUTH_TYPE: return e_CGI_ENV_AUTH_TYPE;
            case e_MXDECGIMAIN_CGI_ENV_CONTENT_FILE: return e_CGI_ENV_CONTENT_FILE;
            case e_MXDECGIMAIN_CGI_ENV_CONTENT_LENGTH: return e_CGI_ENV_CONTENT_LENGTH;
            case e_MXDECGIMAIN_CGI_ENV_CONTENT_TYPE: return e_CGI_ENV_CONTENT_TYPE;
            case e_MXDECGIMAIN_CGI_ENV_OUTPUT_FILE: return e_CGI_ENV_OUTPUT_FILE;
            case e_MXDECGIMAIN_CGI_ENV_PATH_INFO: return e_CGI_ENV_PATH_INFO;
            case e_MXDECGIMAIN_CGI_ENV_PATH_TRANSLATED: return e_CGI_ENV_PATH_TRANSLATED;
            case e_MXDECGIMAIN_CGI_ENV_QUERY_STRING: return e_CGI_ENV_QUERY_STRING;
            case e_MXDECGIMAIN_CGI_ENV_REMOTE_ADDR: return e_CGI_ENV_REMOTE_ADDR;
            case e_MXDECGIMAIN_CGI_ENV_REMOTE_USER: return e_CGI_ENV_REMOTE_USER;
            case e_MXDECGIMAIN_CGI_ENV_REQUEST_LINE: return e_CGI_ENV_REQUEST_LINE;
            case e_MXDECGIMAIN_CGI_ENV_REQUEST_METHOD: return e_CGI_ENV_REQUEST_METHOD;
            case e_MXDECGIMAIN_CGI_ENV_REMOTE_HOST: return e_CGI_ENV_REMOTE_HOST;
            case e_MXDECGIMAIN_CGI_ENV_REMOTE_IDENT: return e_CGI_ENV_REMOTE_IDENT;
            case e_MXDECGIMAIN_CGI_ENV_HTTP_ACCEPT: return e_CGI_ENV_HTTP_ACCEPT;
            case e_MXDECGIMAIN_CGI_ENV_HTTP_USER_AGENT: return e_CGI_ENV_HTTP_USER_AGENT;
            case e_MXDECGIMAIN_CGI_ENV_SCRIPT_NAME: return e_CGI_ENV_SCRIPT_NAME;
        }
        return e_INVALID_CGI_ENV;
    }
    /**
     **********************************************************************
     *  Function: ToMxdeCgiMainCgiEnv
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual eMxdeCgiMainCgiEnv ToMxdeCgiMainCgiEnv
    (eCgiEnv env) const
    {
        switch (env)
        {
            case e_CGI_ENV_GATEWAY_INTERFACE: return e_MXDECGIMAIN_CGI_ENV_GATEWAY_INTERFACE;
            case e_CGI_ENV_SERVER_NAME: return e_MXDECGIMAIN_CGI_ENV_SERVER_NAME;
            case e_CGI_ENV_SERVER_PORT: return e_MXDECGIMAIN_CGI_ENV_SERVER_PORT;
            case e_CGI_ENV_SERVER_PROTOCOL: return e_MXDECGIMAIN_CGI_ENV_SERVER_PROTOCOL;
            case e_CGI_ENV_SERVER_SOFTWARE: return e_MXDECGIMAIN_CGI_ENV_SERVER_SOFTWARE;
            case e_CGI_ENV_AUTH_TYPE: return e_MXDECGIMAIN_CGI_ENV_AUTH_TYPE;
            case e_CGI_ENV_CONTENT_FILE: return e_MXDECGIMAIN_CGI_ENV_CONTENT_FILE;
            case e_CGI_ENV_CONTENT_LENGTH: return e_MXDECGIMAIN_CGI_ENV_CONTENT_LENGTH;
            case e_CGI_ENV_CONTENT_TYPE: return e_MXDECGIMAIN_CGI_ENV_CONTENT_TYPE;
            case e_CGI_ENV_OUTPUT_FILE: return e_MXDECGIMAIN_CGI_ENV_OUTPUT_FILE;
            case e_CGI_ENV_PATH_INFO: return e_MXDECGIMAIN_CGI_ENV_PATH_INFO;
            case e_CGI_ENV_PATH_TRANSLATED: return e_MXDECGIMAIN_CGI_ENV_PATH_TRANSLATED;
            case e_CGI_ENV_QUERY_STRING: return e_MXDECGIMAIN_CGI_ENV_QUERY_STRING;
            case e_CGI_ENV_REMOTE_ADDR: return e_MXDECGIMAIN_CGI_ENV_REMOTE_ADDR;
            case e_CGI_ENV_REMOTE_USER: return e_MXDECGIMAIN_CGI_ENV_REMOTE_USER;
            case e_CGI_ENV_REQUEST_LINE: return e_MXDECGIMAIN_CGI_ENV_REQUEST_LINE;
            case e_CGI_ENV_REQUEST_METHOD: return e_MXDECGIMAIN_CGI_ENV_REQUEST_METHOD;
            case e_CGI_ENV_REMOTE_HOST: return e_MXDECGIMAIN_CGI_ENV_REMOTE_HOST;
            case e_CGI_ENV_REMOTE_IDENT: return e_MXDECGIMAIN_CGI_ENV_REMOTE_IDENT;
            case e_CGI_ENV_HTTP_ACCEPT: return e_MXDECGIMAIN_CGI_ENV_HTTP_ACCEPT;
            case e_CGI_ENV_HTTP_USER_AGENT: return e_MXDECGIMAIN_CGI_ENV_HTTP_USER_AGENT;
            case e_CGI_ENV_SCRIPT_NAME: return e_MXDECGIMAIN_CGI_ENV_SCRIPT_NAME;
        }
        return e_UNKNOWN_MXDECGIMAIN_CGI_ENV;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY) */

#endif /* !defined(_CMXDECGIMAINCGICGIENV_HXX) || defined(CMXDECGIMAINCGICGIENV_MEMBERS_ONLY) */
        


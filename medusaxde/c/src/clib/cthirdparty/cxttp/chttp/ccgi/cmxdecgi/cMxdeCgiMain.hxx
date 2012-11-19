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
 *   File: cMxdeCgiMain.hxx
 *
 * Author: $author$
 *   Date: 9/13/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAIN_HXX
#define _CMXDECGIMAIN_HXX

#include "cdiagnosticcgimain.hxx"
#include "curlencodedstream.hxx"
#include "cMxdeCgiMainContentStream.hxx"
#include "cMxdeCgiMainToHttpFormFields.hxx"
#include "cMxdeCgiMainToHttpFormField.hxx"
#include "cMxdeCgiMainHttpFormFields.hxx"
#include "cMxdeCgiMainHttpFormField.hxx"
#include "cMxdeCgiMainHttpRequest.hxx"
#include "cMxdeCgiMainCgiEnv.hxx"
#include "cMxdeCgiMainCgi.hxx"

#define CMXDECGIMAIN_DEFAULT_NAME "cMxdeCgiMain"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMxdeCgiMain
 *
 * Author: $author$
 *   Date: 9/13/2011
 **********************************************************************
 */
class cMxdeCgiMain
: virtual public cMxdeCgiMainContentStream,
  virtual public cMxdeCgiMainHttpFormFields,
  virtual public cMxdeCgiMainHttpRequest,
  virtual public cMxdeCgiMainCgiEnv,
  public cDiagnosticCGIMain
{
public:
    typedef cDiagnosticCGIMain cExtends;

    cMxdeCgiMainToHttpFormField m_toFormField;
    cMxdeCgiMainHttpFormFieldsIterator m_atFormField;

    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMain
     *
     *       Author: $author$
     *         Date: 9/13/2011
     **********************************************************************
     */
    cMxdeCgiMain
    (const tChar* cgiNameChars=CMXDECGIMAIN_DEFAULT_NAME) 
    : cExtends(cgiNameChars),
      m_atFormField(m_toFormField)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cMxdeCgiMain
     *
     *      Author: $author$
     *        Date: 9/13/2011
     **********************************************************************
     */
    virtual ~cMxdeCgiMain()
    {
    }

    /**
     **********************************************************************
     *  Function: RunCommandOrCGI
     *
     *    Author: $author$
     *      Date: 9/13/2011
     **********************************************************************
     */
    virtual tInt RunCommandOrCGI
    (tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        cMxdeCgiMainContentStream& contentOutput = (cMxdeCgiMainContentStream&)(*this);
        cMxdeCgiMainHttpFormFields& formFields = (cMxdeCgiMainHttpFormFields&)(*this);
        cMxdeCgiMainHttpRequest& request = (cMxdeCgiMainHttpRequest&)(*this);
        cMxdeCgiMainCgiEnv& cgiEnv = (cMxdeCgiMainCgiEnv&)(*this);
        cMxdeCgiMainCgi* cgi = 0;
        tInt err = 0;        
        tInt err2;

        if ((cgi = cMxdeCgiMainCgi::GetInstance()))
        {
            err = cgi->Run
            (contentOutput, formFields, request, 
             cgiEnv, m_argc, m_argv, m_env);
            return err;
        }

        OutputContentType(GetContentTypeHTML());
        OutputContentL(H1_, m_cgiNameChars, _H1, 0);
        OutputHTTPFormFields(argc, argv, env);
        OutputCGIEnv(argc, argv, env);
        OutputArgv(argc, argv, env);
        OutputEnv(argc, argv, env);
        return err;
    }

    /**
     **********************************************************************
     *  Function: FindFirstFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* FindFirstFormField
    (cMxdeCgiMainHttpFormFieldsIterator*& i,
     const char* nameChars, ssize_t nameLength=-1)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        cHTTPFormFieldInterface* detached;
        if ((detached = cExtends::FindFirstHTTPFormField
            (nameChars, (TLENGTH)(nameLength))))
        {
            m_toFormField.Attach(detached);
            i = &m_atFormField;
            return &m_toFormField;
        }
        return formField;
    }
    /**
     **********************************************************************
     *  Function: FindNextFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* FindNextFormField
    (cMxdeCgiMainHttpFormFieldsIterator* i,
     const char* nameChars, ssize_t nameLength=-1)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        cHTTPFormFieldInterface* attached;
        cHTTPFormFieldInterface* detached;
        if ((i))
        if ((attached = i->m_toFormField.Attached()))
        if ((detached = cExtends::FindNextHTTPFormField
            (*attached, nameChars, (TLENGTH)(nameLength))))
        {
            m_toFormField.Attach(detached);
            return &m_toFormField;
        }
        return formField;
    }

    /**
     **********************************************************************
     *  Function: GetFirstFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* GetFirstFormField
    (cMxdeCgiMainHttpFormFieldsIterator*& i)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        cHTTPFormFieldInterface* detached;
        if ((detached = cExtends::FirstHTTPFormField()))
        {
            m_toFormField.Attach(detached);
            i = &m_atFormField;
            return &m_toFormField;
        }
        return formField;
    }
    /**
     **********************************************************************
     *  Function: GetNextFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* GetNextFormField
    (cMxdeCgiMainHttpFormFieldsIterator* i)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        cHTTPFormFieldInterface* attached;
        cHTTPFormFieldInterface* detached;
        if ((i))
        if ((attached = i->m_toFormField.Attached()))
        if ((detached = cExtends::NextHTTPFormField(*attached)))
        {
            m_toFormField.Attach(detached);
            return &m_toFormField;
        }
        return formField;
    }

    /**
     **********************************************************************
     *  Function: GetRequestMethod
     *
     *    Author: $author$
     *      Date: 10/29/2011
     **********************************************************************
     */
    virtual eMxdeCgiHttpRequestMethod GetRequestMethod() const
    {
        return ToMxdeCgiHttpRequestMethod(GetHTTPRequestMethod());
    }

    /**
     **********************************************************************
     *  Function: GetCgiEnvName
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetCgiEnvName
    (eMxdeCgiMainCgiEnv env) const
    {
        const char* envName = 0;
        eCGIEnv cgiEnv = ToCGIEnv(env);
        TLENGTH length;
        if ((envName = CGIEnvName(length, cgiEnv)))
            env = ToMxdeCgiMainCgiEnv(cgiEnv);
        return envName;
    }
    /**
     **********************************************************************
     *  Function: GetCgiEnvValue
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual const char* GetCgiEnvValue
    (eMxdeCgiMainCgiEnv env) const
    {
        const char* envValue = 0;
        eCGIEnv cgiEnv = ToCGIEnv(env);
        TLENGTH length;
        if ((envValue = CGIEnv(length, cgiEnv)))
            env = ToMxdeCgiMainCgiEnv(cgiEnv);
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
        eCGIEnv cgiEnv;
        if ((envName = FirstCGIEnv(cgiEnv, envValue)))
            env = ToMxdeCgiMainCgiEnv(cgiEnv);
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
        eCGIEnv cgiEnv = ToCGIEnv(env);
        if ((envName = NextCGIEnv(cgiEnv, envValue)))
            env = ToMxdeCgiMainCgiEnv(cgiEnv);
        return envName;
    }

    /**
     **********************************************************************
     *  Function: SetContentType
     *
     *    Author: $author$
     *      Date: 9/16/2011
     **********************************************************************
     */
    virtual ssize_t SetContentType
    (const char* type)
    {
        ssize_t count = 0;
        cExtends::SetContentType(type);
        return count;
    }
    /**
     **********************************************************************
     *  Function: Write
     *
     *    Author: $author$
     *      Date: 9/16/2011
     **********************************************************************
     */
    virtual ssize_t Write
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = OutputContent(chars, length);
        return count;
    }
    /**
     **********************************************************************
     *  Function: WriteFormattedV
     *
     *    Author: $author$
     *      Date: 9/16/2011
     **********************************************************************
     */
    virtual ssize_t WriteFormattedV
    (const char* format, va_list va)
    {
        ssize_t count = OutputContentFormattedV(format, va);
        return count;
    }

    /**
     **********************************************************************
     *  Function: ToMxdeCgiMainCgiEnv
     *
     *    Author: $author$
     *      Date: 10/3/2011
     **********************************************************************
     */
    eMxdeCgiMainCgiEnv ToMxdeCgiMainCgiEnv(eCGIEnv env) const
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
    /**
     **********************************************************************
     *  Function: ToCGIEnv
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    eCGIEnv ToCGIEnv(eMxdeCgiMainCgiEnv env) const
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
        return e_UNKNOWN_CGI_ENV;
    }

    /**
     **********************************************************************
     *  Function: ToMxdeCgiHttpRequestMethod
     *
     *    Author: $author$
     *      Date: 10/29/2011
     **********************************************************************
     */
    eMxdeCgiHttpRequestMethod ToMxdeCgiHttpRequestMethod
    (eHTTPRequestMethod requestMethod) const
    {
        switch(requestMethod)
        {
        case e_HTTP_REQUEST_METHOD_GET: return e_MXDE_CGI_HTTP_REQUEST_METHOD_GET;
        case e_HTTP_REQUEST_METHOD_POST: return e_MXDE_CGI_HTTP_REQUEST_METHOD_POST;
        case e_HTTP_REQUEST_METHOD_PUT: return e_MXDE_CGI_HTTP_REQUEST_METHOD_PUT;
        case e_HTTP_REQUEST_METHOD_DELETE: return e_MXDE_CGI_HTTP_REQUEST_METHOD_DELETE;
        case e_HTTP_REQUEST_METHOD_TRACE: return e_MXDE_CGI_HTTP_REQUEST_METHOD_TRACE;
        case e_HTTP_REQUEST_METHOD_HEAD: return e_MXDE_CGI_HTTP_REQUEST_METHOD_HEAD;
        case e_HTTP_REQUEST_METHOD_OPTIONS: return e_MXDE_CGI_HTTP_REQUEST_METHOD_OPTIONS;
        }
        return e_MXDE_CGI_HTTP_REQUEST_METHOD_NONE;
    }
    /**
     **********************************************************************
     *  Function: ToHTTPRequestMethod
     *
     *    Author: $author$
     *      Date: 10/29/2011
     **********************************************************************
     */
    eHTTPRequestMethod ToHTTPRequestMethod
    (eMxdeCgiHttpRequestMethod requestMethod) const
    {
        switch(requestMethod)
        {
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_GET: return e_HTTP_REQUEST_METHOD_GET;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_POST: return e_HTTP_REQUEST_METHOD_POST;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_PUT: return e_HTTP_REQUEST_METHOD_PUT;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_DELETE: return e_HTTP_REQUEST_METHOD_DELETE;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_TRACE: return e_HTTP_REQUEST_METHOD_TRACE;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_HEAD: return e_HTTP_REQUEST_METHOD_HEAD;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_OPTIONS: return e_HTTP_REQUEST_METHOD_OPTIONS;
        }
        return e_HTTP_REQUEST_METHOD_NONE;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAIN_HXX */
        


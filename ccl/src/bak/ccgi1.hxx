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
 *   Date: 8/6/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCGI_HXX
#define _CCGI_HXX

#include <stdlib.h>

#include "cargswitch.hxx"
#include "cmaint.hxx"
#include "ccgiinterface.hxx"
#include "chttpform.hxx"
#include "chttpcontent.hxx"
#include "ccharbuffer.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cCGI
 *
 * Author: $author$
 *   Date: 8/6/2003
 **********************************************************************
 */
class cCGI
: virtual public cCGIInterface,
  public cMainT<cCGI, cHTTPContent>
{
public:
    typedef cMainT<cCGI, cHTTPContent> cMainIs, cIs;

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
        e_ENV_GATEWAY_INTERFACE=e_FIRST_ENV,
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
        e_LAST_ENV=e_NUMBEROF_ENV-1
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

    /**
     **********************************************************************
     *   Enum: eMode
     *
     * Author: $author$
     *   Date: 8/11/2003
     **********************************************************************
     */
    enum eMode
    {
        e_FIRST_MODE,
        e_MODE_COMMAND = e_FIRST_MODE,
        e_MODE_CGI,
        e_MODE_UNKNOWN,
        e_NUMBEROF_MODES = e_MODE_UNKNOWN,
        e_LAST_MODE = e_NUMBEROF_MODES-1
    };

    static const char *m_env_name[e_NUMBEROF_ENV];
    static const char *m_request_method_name[e_NUMBEROF_REQUEST_METHODS];
    static const char *m_mode_name[e_NUMBEROF_MODES];

    const char *m_env[e_NUMBEROF_ENV];
    cCharBuffer m_env_buffer[e_NUMBEROF_ENV];

    const char *m_env_filename;
    const char *m_stdin_filename;

    eMode m_mode;

    cHTTPForm m_form;

    /**
     **********************************************************************
     * Constructor: cCGI
     *
     *      Author: $author$
     *        Date: 8/6/2003
     **********************************************************************
     */
    cCGI() 
    : cIs(this),
      m_mode(e_MODE_UNKNOWN),
      m_env_filename(0),
      m_stdin_filename(0)
    {
		int env;

        for (env=e_FIRST_ENV; env<=e_LAST_ENV; env++)
			m_env[env]="";
    }
    /**
     **********************************************************************
     * Destructor: ~cCGI
     *
     *     Author: $author$
     *       Date: 8/6/2003
     **********************************************************************
     */
    virtual ~cCGI()
    {
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        GetEnv();
        return cIs::OnMain(argc, argv);
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        int count;
        cCharStream *old_out;
        cCharStream *old_err;
        cCharFile out(stdout);
        cCharFile err(stderr);

        old_out = SetOut(&out);
        old_err = SetErr(&err);

        if ((count = GetForm()) >= 0)

        if (GetMode() == e_MODE_COMMAND)
            count = OnCommand();

        else 
        {
            SetErr(&out);
            count = OnCGI();
        }

        SetErr(old_err);
        SetOut(old_out);

        if (count < 0)
            return 1;

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
    virtual int OnCommand()
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnCGI()
    {
        return OutputContentType();
    }
    /**
     **********************************************************************
     * Function: GetForm
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int GetForm()
    {
        int count,result = 0;
        const char *env_string;
        eRequestMethod request_method;

        if (GetMode() != e_MODE_COMMAND)

        if ((env_string = GetEnvGatewayInterface()))
        {
            if ((count = AddFormFieldsFromQueryString()) < 0)
                return count;

            result += count;

            if ((count = AddFormFieldsFromInput()) < 0)
                return count;

            result += count;
        }
        else if (GetMode() == e_MODE_CGI)
        {
            if (m_env_filename)
            {
                if ((count = GetEnvFromFile(m_env_filename)) < 0)
                    return count;

                if ((count = AddFormFieldsFromQueryString()) < 0)
                    return count;

                result += count;

                if (m_stdin_filename)
                if (e_REQUEST_METHOD_POST == (request_method = GetEnvRequestMethod()))
                if ((count = AddFormFieldsFromFile(m_stdin_filename)) < 0)
                    return count;

                else result += count;
            }
        }
        else SetMode(e_MODE_COMMAND);

        return result;
    }
    /**
     **********************************************************************
     * Function: AddFormFieldsFromQueryString
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int AddFormFieldsFromQueryString()
    {
        const char *env_string;
        int count = 0;

        if ((env_string = GetEnvQueryString()))
        {
            cCharBuffer query_string(env_string);

            count = m_form.AddFieldsFromURLEncodedStream(query_string);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: AddFormFieldsFromInput
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int AddFormFieldsFromInput()
    {
        int content_length;
        eContentType content_type;
        cCharFile in(stdin);

        if ((content_length = GetEnvContentLength()) > 0)

        switch(content_type = GetEnvContentType())
        {
        case e_CONTENT_TYPE_URLENCODED:
            return m_form.AddFieldsFromURLEncodedInput(in, content_length);

        case e_CONTENT_TYPE_MULTIPART:
            return m_form.AddFieldsFromMultipartInput(in, content_length);
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: AddFormFieldsFromFile
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int AddFormFieldsFromFile(const char *filename)
    {
        eContentType content_type;

        switch(content_type = GetEnvContentType())
        {
        case e_CONTENT_TYPE_URLENCODED:
            return m_form.AddFieldsFromURLEncodedFile(filename);

        case e_CONTENT_TYPE_MULTIPART:
            return m_form.AddFieldsFromMultipartFile(filename);
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (argn > 0)
        {
            if (!m_env_filename)
                m_env_filename = arg;

            else if (!m_stdin_filename)
                    m_stdin_filename = arg;
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        int argon;

        if ((argon = cArgSwitch::OnArgSwitch
            (args, argn, arg, argc, argv)) >= 0)
            return argon;

        return cIs::OnMainArgSwitch
        (args, argn, arg, argc, argv);
    }
    /**
     **********************************************************************
     * Function: OnMainArgAssign
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgAssign
    (int args, int argn, char *arg, 
     const char *equal, int argc, char **argv)
    {
        AddFormField(arg, equal-arg, equal+1);
        return argn;
    }
    /**
     **********************************************************************
     * Function: GetFirstFormFieldByName
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
    virtual cHTTPForm::cField *GetFirstFormFieldByName
    (const char *name, int namelen=-1) const
    {
        return m_form.GetFirstFieldByName(name, namelen);
    }
    /**
     **********************************************************************
     * Function: GetFirstFormField
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual cHTTPForm::cField *GetFirstFormField() const
    {
        return m_form.GetFirstField();
    }
    /**
     **********************************************************************
     * Function: AddFormField
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual cHTTPForm::cField *AddFormField
    (const char *name, int namelen=-1,
     const char *value="", int valuelen=-1)
    {
        return m_form.AddField
        (name, namelen, value, valuelen);
    }
    /**
     **********************************************************************
     * Function: GetEnvFromFile
     *
     *   Author: $author$
     *     Date: 8/11/2003
     **********************************************************************
     */
    int GetEnvFromFile(const char *filename)
    {
        int count;
        eError error;
        cCharFile file;

        if ((error = file.Open(filename)))
            return -e_ERROR_OPEN;

        count = GetEnvFromStream(file);
        file.Close();
        return count;
    }
    /**
     **********************************************************************
     * Function: GetEnvFromStream
     *
     *   Author: $author$
     *     Date: 8/10/2003
     **********************************************************************
     */
	int GetEnvFromStream(cCharStream &stream, int length=-1)
	{
		enum eState
		{
			e_STATE_NAME,
			e_STATE_VALUE
		};

        int namelen, valuelen;
        const char *name, *value;
		cCharBuffer name_buffer;
		cCharBuffer value_buffer;
		cCharBuffer *buffer;
		eState state;
		bool oneline;
        int count;
        int total;
		char c;
    
        total = 0;
		oneline = true;
		state = e_STATE_NAME;
		buffer = &name_buffer;

		do
		{
			if ((count = stream.Get(c)) < 1)
				break;

			switch(state)
			{
			case e_STATE_NAME:
				switch(c)
				{
				case '\n':
					oneline = false;
					if ((count = buffer->Clear()) < 0)
						return -e_ERROR_CLEAR;
					break;

				case '=':
					buffer = &value_buffer;
					if ((count = buffer->Clear()) < 0)
						return -e_ERROR_CLEAR;

					state = e_STATE_VALUE;
					break;

				case '&':
					if (oneline)
					{
						if ((count = buffer->Clear()) < 0)
							return -e_ERROR_CLEAR;
						break;
					}

				default:
					if ((count = buffer->Put(c)) < 1)
						return -e_ERROR_PUT;
				}
				break;

			case e_STATE_VALUE:
				switch(c)
				{
				case '\n':
					oneline = false;

                    if ((name = name_buffer.GetBuffer(namelen)))
                    if ((value = value_buffer.GetBuffer(valuelen)))
					if ((count = PutEnv
						(name, namelen, value, valuelen)) < 0)
						return count;
                    else total++;

					buffer = &name_buffer;

					if ((count = buffer->Clear()) < 0)
						return -e_ERROR_CLEAR;

					state=e_STATE_NAME;
					break;

				case '&':
					if (oneline)
					{
                        if ((name = name_buffer.GetBuffer(namelen)))
                        if ((value = value_buffer.GetBuffer(valuelen)))
					    if ((count = PutEnv
						    (name, namelen, value, valuelen)) < 0)
						    return count;
                        else total++;

						buffer = &name_buffer;

						if ((count = buffer->Clear()) < 0)
							return -e_ERROR_CLEAR;

						state = e_STATE_NAME;
						break;
					}

				default:
					if ((count = buffer->Put(c)) < 1)
						return -e_ERROR_PUT;
				}
				break;

			default:
				return -e_ERROR_FAILED;
			}
		}
		while (count >= 0);

		if (state == e_STATE_VALUE)
        if ((name = name_buffer.GetBuffer(namelen)))
        if ((value = value_buffer.GetBuffer(valuelen)))
		if ((count = PutEnv
			(name, namelen, value, valuelen)) < 0)
			return count;
        else total++;

		return total;
	}
    /**
     **********************************************************************
     * Function: PutEnv
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
	int PutEnv
    (const char *name, int namelen,
     const char *value, int valuelen=-1)
	{
		int env;
		int length;
		int count = 0;

        if (namelen>0)
		for (env = e_FIRST_ENV; env <= e_LAST_ENV; env++)
		{
			if ((length=strlen(m_env_name[env])) == namelen)
			if (strncmp(m_env_name[env], name, length)==0)
			{
				if ((count = m_env_buffer[env].Copy(value, valuelen)) < 0)
					return -e_ERROR_COPY;

				m_env[env] = m_env_buffer[env].GetBuffer();
				break;
			}
		}
		return count;
	}
    /**
     **********************************************************************
     * Function: GetEnv
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    int GetEnv()
    {
		const char *name;
		const char *value;
		int env, count;

        count = 0;

        for (env = e_FIRST_ENV; env <= e_LAST_ENV; env++)
        {
            if ((value = getenv(name = m_env_name[env])))
                count++;
            else value="";

			m_env[env]=value;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: GetEnvGatewayInterface
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    const char *GetEnvGatewayInterface() const
    {
        const char *env_string;

        if ((env_string = m_env[e_ENV_GATEWAY_INTERFACE]))
        if (env_string[0])
            return env_string;

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetEnvQueryString
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    const char *GetEnvQueryString() const
    {
        const char *env_query_string;

        if ((env_query_string = m_env[e_ENV_QUERY_STRING]))
        if (env_query_string[0])
            return env_query_string;

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetEnvRequestMethod
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    eRequestMethod GetEnvRequestMethod() const
    {
        const char *env_request_method;
        int request_method;

        if ((env_request_method = m_env[e_ENV_REQUEST_METHOD]))
        if (env_request_method[0])
        for (request_method = e_FIRST_REQUEST_METHOD; 
             request_method <= e_LAST_REQUEST_METHOD; request_method++)
        {
            if (!strcmp
                (env_request_method, 
                 m_request_method_name[request_method]))
                return (eRequestMethod)request_method;
        }

        return e_REQUEST_METHOD_UNKNOWN;
    }
    /**
     **********************************************************************
     * Function: GetEnvContentType
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    eContentType GetEnvContentType() const
    {
        const char *env_content_type;
        int content_type;

        if ((env_content_type = m_env[e_ENV_CONTENT_TYPE]))
        if (env_content_type[0])
        for (content_type = e_FIRST_CONTENT_TYPE; 
             content_type <= e_LAST_CONTENT_TYPE; content_type++)
        {
            if (strstr
                (env_content_type, 
                 m_content_types[content_type]))
                return (eContentType)content_type;
        }

        return e_CONTENT_TYPE_UNKNOWN;
    }
    /**
     **********************************************************************
     * Function: GetEnvContentLength
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    int GetEnvContentLength() const
    {
        const char *env_content_length;
        int content_length = -1;

        if ((env_content_length = m_env[e_ENV_CONTENT_LENGTH]))
            content_length = atoi(env_content_length);

        return content_length;
    }
    /**
     **********************************************************************
     * Function: SetMode
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    eMode SetMode(eMode mode)
    {
        eMode old_mode = m_mode;

        m_mode = mode;
        return old_mode;
    }
    /**
     **********************************************************************
     * Function: GetMode
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    eMode GetMode() const
    {
        return m_mode;
    }
};


#endif

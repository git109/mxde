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
 *   File: ccgi.cxx
 *
 * Author: $author$
 *   Date: 8/9/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ccgi.hxx"

#define CCGI_MODE_NAME_COMMAND "command"
#define CCGI_MODE_NAME_CGI     "cgi"

/**
 **********************************************************************
 *  Class: cCGIModeArgSwitch
 *
 * Author: $author$
 *   Date: 8/15/2003
 **********************************************************************
 */
class cCGIModeArgSwitch
: public cArgSwitch
{
public:
    typedef cArgSwitch cIs;

    cCGI::eMode m_mode;

    /**
     **********************************************************************
     * Constructor: cCGIModeArgSwitch
     *
     *      Author: $author$
     *        Date: 8/15/2003
     **********************************************************************
     */
    cCGIModeArgSwitch
    (const char *name, cCGI::eMode mode) 
    : cIs(name),
      m_mode(mode)
    {
    }
    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        cCGI *cgi;

        if ((cgi = cCGI::m_instance))
            cgi->SetMode(m_mode);

        return argn;
    }
};

cCGIModeArgSwitch g_cgi_command_switch
 (CCGI_MODE_NAME_COMMAND, cCGI::e_MODE_COMMAND);

cCGIModeArgSwitch g_cgi_cgi_switch
 (CCGI_MODE_NAME_CGI, cCGI::e_MODE_CGI);

/*
 **********************************************************************
 *  Class: cCGI
 *
 * Author: $author$
 *   Date: 8/9/2003
 **********************************************************************
 */

cCGI *cCGI::cInstanceIs::m_instance = 0;

const char *cCGI::m_env_name[e_NUMBEROF_ENV]=
{
    "GATEWAY_INTERFACE",
	"SERVER_NAME",
	"SERVER_PORT",
	"SERVER_PROTOCOL",
	"SERVER_SOFTWARE",
	"AUTH_TYPE",
	"CONTENT_FILE",
	"CONTENT_LENGTH",
	"CONTENT_TYPE",
	"OUTPUT_FILE",
	"PATH_INFO",
	"PATH_TRANSLATED",
	"QUERY_STRING",
	"REMOTE_ADDR",
	"REMOTE_USER",
	"REQUEST_LINE",
	"REQUEST_METHOD",
	"REMOTE_HOST",
	"REMOTE_IDENT",
	"HTTP_ACCEPT",
	"HTTP_USER_AGENT",
	"SCRIPT_NAME"
};

const char *cCGI::m_request_method_name[e_NUMBEROF_REQUEST_METHODS]=
{
    "GET",
    "POST"
};

const char *cCGI::m_mode_name[e_NUMBEROF_MODES]=
{
    CCGI_MODE_NAME_COMMAND,
    CCGI_MODE_NAME_CGI
};

/**
 **********************************************************************
 *    Function: cCGI::
 *
 *      Author: $author$
 *        Date: 8/9/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: main
 *
 *      Author: $author$
 *        Date: 8/13/2003
 **********************************************************************
 */
int main(int argc, char **argv)
{
    cCGI *cmain;

    if ((cmain = cCGI::GetInstance()))
        return cmain->OnMain(argc, argv);

    return 1;
}

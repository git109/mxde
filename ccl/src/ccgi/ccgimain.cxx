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
 *   File: ccgimain.cxx
 *
 * Author: $author$
 *   Date: 12/5/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ccgimain.hxx"
#include "cargswitch.hxx"

#define CCGIMAIN_MODE_NAME_COMMAND "command"
#define CCGIMAIN_MODE_NAME_CGI     "cgi"

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

    cCGIMain::eMode m_mode;

    /**
     **********************************************************************
     * Constructor: cCGIModeArgSwitch
     *
     *      Author: $author$
     *        Date: 8/15/2003
     **********************************************************************
     */
    cCGIModeArgSwitch
    (const char *name, cCGIMain::eMode mode) 
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
        cCGIMain *cgi;

        if ((cgi = cCGIMain::m_instance))
            cgi->SetMode(m_mode);

        return argn;
    }
};

cCGIModeArgSwitch g_cgi_command_switch
 (CCGIMAIN_MODE_NAME_COMMAND, cCGIMain::e_MODE_COMMAND);

cCGIModeArgSwitch g_cgi_cgi_switch
 (CCGIMAIN_MODE_NAME_CGI, cCGIMain::e_MODE_CGI);

/*
 **********************************************************************
 *  Class: cCGIMain
 *
 * Author: $author$
 *   Date: 12/5/2003
 **********************************************************************
 */

const char *cCGIMain::m_mode_name[e_NUMBEROF_MODES]=
{
    CCGIMAIN_MODE_NAME_COMMAND,
    CCGIMAIN_MODE_NAME_CGI
};

cCGIMain *cCGIMain::cInstanceIs::m_instance = 0;

/**
 **********************************************************************
 *    Function: cCGIMain::
 *
 *      Author: $author$
 *        Date: 12/5/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 12/5/2003
 **********************************************************************
 */
int main(int argc, char **argv)
{
    cCGIMain *instance;

    if ((instance = cCGIMain::GetInstance()))
        return instance->OnMain(argc, argv);

    return 1;
}

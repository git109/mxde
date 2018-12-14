/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: javaservice.cxx
 *
 * Author: $author$
 *   Date: 1/20/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _JAVASERVICE_CXX
#define _JAVASERVICE_CXX

#include "cservice.hxx"

#define JAVASERVICE_NAME "JavaService"
#define JAVASERVICE_LABEL "Java Service"
#define JAVASERVICE_TYPE SERVICE_WIN32_OWN_PROCESS

/**
 **********************************************************************
 *  Class: cJavaService
 *
 * Author: $author$
 *   Date: 1/20/2004
 **********************************************************************
 */
class cJavaService
: public cService
{
public:
    typedef cService cIs;

    const char *m_start;
    const char *m_stop;
    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cJavaService
     *
     *      Author: $author$
     *        Date: 1/20/2004
     **********************************************************************
     */
    cJavaService() 
    : cIs(_T(JAVASERVICE_NAME), _T(JAVASERVICE_LABEL), JAVASERVICE_TYPE),
      m_start("start"),
      m_stop("stop"),
      m_name("name")
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/20/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 1/20/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        int nextarg;
        eError error;

        if (0 == strcmp(arg, m_start))
            OnStart();

        else if (0 == strcmp(arg, m_stop))
                OnStop();

        else if (0 == strcmp(arg, m_name))
        {
            if (argc > (nextarg = argn+1))
            {
                if ((error = SetName(argv[nextarg])))
                    return -error;

                return nextarg;
            }
        }

        return argn;
    }
} g_java_service;

#endif /* ndef _JAVASERVICE_CXX */

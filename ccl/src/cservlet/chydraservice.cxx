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
 *   File: chydraservice.cxx
 *
 * Author: $author$
 *   Date: 10/8/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cevent.hxx"
#include "cservice.hxx"

/**
 **********************************************************************
 *  Class: cHydraService
 *
 * Author: $author$
 *   Date: 10/8/2004
 **********************************************************************
 */
class cHydraService
: public cService
{
public:
    typedef cService cIs;

    const char *m_command;
    const char *m_service;
    const char *m_install;
    const char *m_remove;
    const char *m_query;
    const char *m_start;
    const char *m_stop;

    bool m_running_as_service;
    cEvent m_stop_event;

    /**
     **********************************************************************
     * Constructor: cHydraService
     *
     *      Author: $author$
     *        Date: 10/8/2004
     **********************************************************************
     */
    cHydraService() 
    : cIs(_T("Hydra")),
      m_service("service"),
      m_install("install"),
      m_remove("remove"),
      m_query("query"),
      m_start("start"),
      m_stop("stop"),
      m_running_as_service(false)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cHydraService
     *
     *     Author: $author$
     *       Date: 10/8/2004
     **********************************************************************
     */
    virtual ~cHydraService()
    {
    }

    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        eError error;

        if (m_running_as_service)
        {
            if ((error = StartServiceCtrlDispatcher()))
                return 1;
        }

        return 0;
    }

    /**
     **********************************************************************
     * Function: OnServiceStarting
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual eError OnServiceStarting
    (SERVICE_ARGC argc, SERVICE_ARGV argv) 
    {
        eError error;

        if ((error = m_stop_event.Create()))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnServiceStopping
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual eError OnServiceStopping
    (SERVICE_ARGC argc, SERVICE_ARGV argv) 
    {
        eError error;

        if ((error = m_stop_event.Close()))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnServiceRunning
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual eError OnServiceRunning
    (SERVICE_ARGC argc, SERVICE_ARGV argv) 
    {
        eError error;

        do
        {
            error = m_stop_event.Wait(500);
        }
        while (e_ERROR_WAIT_TIMEOUT == error);

        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: OnServiceCtrlStop
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual void OnServiceCtrlStop()
    {
        m_stop_event.Set();
    }

    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        int service_arg_len;
        const TCHAR *service_arg;
        cTCHARBuffer service_arg_buffer;

        if (0 == strcmp(arg, m_install))
        {
            if (0 <= (service_arg_len = service_arg_buffer.WriteL(_T("-"), m_service, 0)))
            if ((service_arg = service_arg_buffer.GetBuffer(service_arg_len)))
                OnInstall(service_arg, service_arg_len);
        }
        else if (0 == strcmp(arg, m_remove))
                OnRemove();

        else if (0 == strcmp(arg, m_query))
                OnQuery();

        else if (0 == strcmp(arg, m_start))
                OnStart();

        else if (0 == strcmp(arg, m_stop))
                OnStop();

        else if (0 == strcmp(arg, m_service))
                m_running_as_service = true;

        else if (0 == strcmp(arg, m_command))
                m_running_as_service = false;

        return argn;
    }
} g_hydra_service;

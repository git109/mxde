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
 *   File: service.cxx
 *
 * Author: $author$
 *   Date: 11/22/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ceventt.hxx"
#include "cservice.hxx"

/**
 **********************************************************************
 *  Class: cTheService
 *
 * Author: $author$
 *   Date: 11/22/2003
 **********************************************************************
 */
class cTheService
: public cService
{
public:
    typedef cService cIs;

    const char *m_install;
    const char *m_remove;
    const char *m_query;
    const char *m_test;
    const char *m_start;
    const char *m_stop;

    cEventT<> m_stop_event;

    /**
     **********************************************************************
     * Constructor: cTheService
     *
     *      Author: $author$
     *        Date: 11/22/2003
     **********************************************************************
     */
    cTheService() 
    : cIs(_T("cTheService")),
      m_install("install"),
      m_remove("remove"),
      m_query("query"),
      m_test("test"),
      m_start("start"),
      m_stop("stop")
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTheService
     *
     *     Author: $author$
     *       Date: 11/22/2003
     **********************************************************************
     */
    virtual ~cTheService()
    {
    }

    /**
     **********************************************************************
     * Function: OnServiceStarting
     *
     *   Author: $author$
     *     Date: 11/25/2003
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
     *     Date: 11/25/2003
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
     *     Date: 11/25/2003
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
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual void OnServiceCtrlStop()
    {
        m_stop_event.Set();
    }

    /**
     **********************************************************************
     * Function: OnTest
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual int OnTest()
    {
        SetTypeIsDriver();
        return 0;
    }

    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 11/22/2003
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (0 == strcmp(arg, m_install))
            OnInstall();

        else if (0 == strcmp(arg, m_remove))
                OnRemove();

        else if (0 == strcmp(arg, m_query))
                OnQuery();

        else if (0 == strcmp(arg, m_test))
                OnTest();

        else if (0 == strcmp(arg, m_start))
                OnStart();

        else if (0 == strcmp(arg, m_stop))
                OnStop();

        return argn;
    }
} g_the_service;

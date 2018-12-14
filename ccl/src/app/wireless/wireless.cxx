/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: wireless.cxx
 *
 * Author: $author$
 *   Date: 9/15/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cservice.hxx"

/**
 **********************************************************************
 *  Class: cWirelessDriver
 *
 * Author: $author$
 *   Date: 9/15/2005
 **********************************************************************
 */
class cWirelessDriver
: public cService
{
public:
    typedef cService cIs;

    /**
     **********************************************************************
     * Constructor: cWirelessDriver
     *
     *      Author: $author$
     *        Date: 9/15/2005
     **********************************************************************
     */
    cWirelessDriver() 
    : cIs(_T("BCMWL5"), 0, _T("C:\\WINNT\\System32\\DRIVERS\\BCMWL5.SYS"), SERVICE_KERNEL_DRIVER)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/28/2003
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cWireless
 *
 * Author: $author$
 *   Date: 9/15/2005
 **********************************************************************
 */
class cWireless
: public cService
{
public:
    typedef cService cIs;

    const char *m_query;
    const char *m_start;
    const char *m_stop;

    const char *m_install_driver;
    const char *m_remove_driver;
    const char *m_query_driver;
    const char *m_start_driver;
    const char *m_stop_driver;

    cIs *m_old_instance;
    cWirelessDriver m_driver;

    /**
     **********************************************************************
     * Constructor: cWireless
     *
     *      Author: $author$
     *        Date: 9/15/2005
     **********************************************************************
     */
    cWireless() 
    : cIs(_T("WMP54GSVC"), 0, 0, SERVICE_WIN32_OWN_PROCESS),
      m_query("query"),
      m_start("start"),
      m_stop("stop"),
      m_install_driver("install_driver"),
      m_remove_driver("remove_driver"),
      m_start_driver("start_driver"),
      m_stop_driver("stop_driver")
    {
        m_old_instance = m_instance;
        m_instance = this;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWireless
     *
     *      Author: $author$
     *        Date: 9/15/2005
     **********************************************************************
     */
    virtual ~cWireless()
    {
        m_instance = m_old_instance;
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/28/2003
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
     *     Date: 9/15/2003
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (0 == strcmp(arg, m_query))
            OnQuery();

        else if (0 == strcmp(arg, m_start))
                OnStart();

        else if (0 == strcmp(arg, m_stop))
                OnStop();
/*
        else if (0 == strcmp(arg, m_install_driver))
                m_driver.OnInstall();

        else if (0 == strcmp(arg, m_remove_driver))
                m_driver.OnRemove();

        else if (0 == strcmp(arg, m_stop_driver))
                m_driver.OnStop();
*/
        return argn;
    }
} g_wireless;

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
 *   File: windriver.cxx
 *
 * Author: $author$
 *   Date: 11/28/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <windows.h>
#include <winioctl.h>

#include "cservice.hxx"
#include "cdevicet.hxx"
#include "windriver_ioctl.h"

/**
 **********************************************************************
 *  Class: cWinDriver
 *
 * Author: $author$
 *   Date: 11/28/2003
 **********************************************************************
 */
class cWinDriver
: public cService
{
public:
    typedef cService cIs;

    const char *m_install;
    const char *m_remove;
    const char *m_query;
    const char *m_start;
    const char *m_stop;
    const char *m_version;

    /**
     **********************************************************************
     * Constructor: cWinDriver
     *
     *      Author: $author$
     *        Date: 11/28/2003
     **********************************************************************
     */
    cWinDriver() 
    : cIs(_T("WinDriver"), 0, SERVICE_KERNEL_DRIVER),
      m_install("install"),
      m_remove("remove"),
      m_query("query"),
      m_start("start"),
      m_stop("stop"),
      m_version("version")
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
    /**
     **********************************************************************
     * Function: OnVersion
     *
     *   Author: $author$
     *     Date: 11/28/2003
     **********************************************************************
     */
    virtual int OnVersion()
    {
        DWORD version;
        eError error;
        cDeviceT<char> d;

        if (!(error = d.Open("\\\\.\\WinDriver")))
        {
            if (!(error = d.Ioctl
                (WINDRIVER_IOCTL_VERSION, 
                 &version, 0, sizeof(version))))
                 printf("Version = 0x%x\n", version);

            d.Close();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 11/28/2003
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

        else if (0 == strcmp(arg, m_start))
                OnStart();

        else if (0 == strcmp(arg, m_stop))
                OnStop();

        else if (0 == strcmp(arg, m_version))
                OnVersion();

        return argn;
    }
} g_win_driver;

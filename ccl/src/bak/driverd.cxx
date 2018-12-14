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
 *   File: driverd.cxx
 *
 * Author: $author$
 *   Date: 3/1/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _DRIVERD_CXX
#define _DRIVERD_CXX

#include <stdio.h>

#include "cmain.hxx"
#include "cchardevice.hxx"
#include "driver.h"

/**
 **********************************************************************
 *  Main: cDriverDaemon
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cDriverDaemon
: public cMain
{
public:
    typedef cMain cIs;

    const char *m_device_name;
    cCharDevice m_device;

    /**
     **********************************************************************
     * Constructor: cDriverDaemon
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cDriverDaemon(const char *device_name="/dev/driver") 
    : m_device_name(device_name) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDriverDaemon
     *
     *     Author: $author$
     *       Date: 3/1/2004
     **********************************************************************
     */
    virtual ~cDriverDaemon()
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnOpenDevice
     *
     *   Author: $author$
     *     Date: 3/2/2004
     **********************************************************************
     */
    virtual int OnOpenDevice()
    {
        eError error;

        if ((error = m_device.Open(m_device_name)))
            printf("Unable to open device \"%s\"\n", m_device_name);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCloseDevice
     *
     *   Author: $author$
     *     Date: 3/2/2004
     **********************************************************************
     */
    virtual int OnCloseDevice()
    {
        eError error;

        if ((error = m_device.Close()))
            printf("Unable to close device \"%s\"\n", m_device_name);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommandReset
     *
     *   Author: $author$
     *     Date: 3/2/2004
     **********************************************************************
     */
    virtual int OnCommandReset
    (int args, int argn, const char *arg, 
     int argc, const char **argv)
    {
        int err;

        if (!(err = OnOpenDevice()))
        {
            m_device.Ioctl(DRIVER_IOC_RESET);
            OnCloseDevice();
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: OnCommandTest
     *
     *   Author: $author$
     *     Date: 3/2/2004
     **********************************************************************
     */
    virtual int OnCommandTest
    (int args, int argn, const char *arg, 
     int argc, const char **argv)
    {
        int err;

        if (!(err = OnOpenDevice()))
        {
            m_device.Ioctl(DRIVER_IOC_TEST);
            OnCloseDevice();
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 3/2/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (0 == strcmp("r", arg))
            return OnCommandReset
            (args, argn, arg, argc, argv);

        if (0 == strcmp("t", arg))
            return OnCommandTest
            (args, argn, arg, argc, argv);

        return argn;
    }
} g_driver_daemon;

#endif /* ndef _DRIVERD_CXX */

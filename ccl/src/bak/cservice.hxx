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
 *   File: cservice.hxx
 *
 * Author: $author$
 *   Date: 11/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVICE_HXX
#define _CSERVICE_HXX

#include <windows.h>
#include <tchar.h>
#define SERVICE_ARGC DWORD
#define SERVICE_ARGV LPTSTR*

#include "cservicecontrolmanager.hxx"
#include "cservicestatus.hxx"
#include "ctcharbuffer.hxx"
#include "ccharfile.hxx"
#include "coutput.hxx"
#include "cmaint.hxx"

#define CSERVICE_DEFAULT_TYPE SERVICE_WIN32_OWN_PROCESS

/**
 **********************************************************************
 *  Class: cService
 *
 * Author: $author$
 *   Date: 11/22/2003
 **********************************************************************
 */
class cService
: public cMainT<cService, cOutput>
{
public:
    typedef cMainT<cService, cOutput> cIs;

    TCHAR *m_name;
    cTCHARBuffer m_name_buffer;

    TCHAR *m_label;
    cTCHARBuffer m_label_buffer;

    TCHAR *m_path;
    cTCHARBuffer m_path_buffer;

    TCHAR *m_driver_extension;
    cTCHARBuffer m_driver_extension_buffer;

    cTCHARBuffer m_command_buffer;

    SC_SERVICE_TYPE m_service_type;

    cServiceStatus m_service_status;
    cServiceControlManager m_scm;

    /**
     **********************************************************************
     * Constructor: cService
     *
     *      Author: $author$
     *        Date: 11/22/2003
     **********************************************************************
     */
    cService
    (const TCHAR *name, const TCHAR *label=0,
     SC_SERVICE_TYPE service_type=CSERVICE_DEFAULT_TYPE,
     const TCHAR *driver_extension=_T("sys"))
    : cIs(this),
      m_name(_T("")),
      m_label(_T("")),
      m_path(0),
      m_driver_extension(_T("")),
      m_service_type(service_type)
    {
        eError error;

        if (name)
        {
            if ((error = SetName(name)))
                throw(error);

            if (!label)
                label = name;
        }

        if (label)
        {
            if ((error = SetLabel(label)))
                throw(error);
        }

        if (driver_extension)
        {
            if ((error = SetDriverExtension(driver_extension)))
                throw(error);
        }
    }
    /**
     **********************************************************************
     * Destructor: ~cService
     *
     *     Author: $author$
     *       Date: 11/22/2003
     **********************************************************************
     */
    virtual ~cService()
    {
    }

    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        SetOut(&m_out);
        SetErr(&m_err);
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
    virtual int OnRun(int argc, const char **argv)
    {
        eError error;

        if (argc < 2)
        if ((error = StartServiceCtrlDispatcher()))
            return 1;

        return 0;
    }

    /**
     **********************************************************************
     * Function: OnInstall
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual int OnInstall(const TCHAR *arg=0, int arglen=-1)
    {
        const TCHAR *path;
        eError error;
        cServiceControl service;

        if ((path = GetCommand(arg, arglen)))

        if (!(error = OnOpenSCM()))
        {
            if (!(error = m_scm.CreateService
                (service, m_name, m_name, path, m_service_type)))
            {
                service.Close();
            }
            OnCloseSCM();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnRemove
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual int OnRemove()
    {
        eError error;
        cServiceControl service;

        if (!(error = OnOpenSCM()))
        {
            if (!(error = m_scm.OpenService(service, m_name)))
            {
                service.DeleteService();
                service.Close();
            }
            OnCloseSCM();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnQuery
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual int OnQuery()
    {
        const TCHAR *path;

        if (!(path = GetPath()))
            path = "";

        OutputL
        (  " Name: ", m_name, 
         "\nLabel: ", m_label, 
         "\n Path: ", path, 
         "\n Type: ", (SERVICE_KERNEL_DRIVER == m_service_type)?"driver":"service",
         "\n", 0);

        return 0;
    }

    /**
     **********************************************************************
     * Function: OnStart
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OnStart()
    {
        eError error;
        cServiceControl service;
        cServiceStatus status;
        SERVICE_STATE state;

        if (!(error = OnOpenSCM()))
        {
            if ((error = m_scm.OpenService(service, m_name)))
                OutputErrorL
                ("Unable to open service \"", m_name, "\"\n", 0);
            else
            {
                OutputL("Starting service \"", m_name, "\"...\n", 0);

                if ((error = service.StartService()))
                    OutputErrorL
                    ("Unable to start service \"", m_name, "\"\n", 0);

                else do
                {
                    if ((error = service.QueryServiceStatus(status)))
                    {
                        OutputErrorL
                        ("Unable to query service \"", 
                         m_name, "\" status\n", 0);
                        break;
                    }

                    if (SERVICE_RUNNING == (state = status.GetState()))
                        OutputL("...Service \"", m_name, "\" started\n", 0);
                }
                while (SERVICE_START_PENDING == state);

                service.Close();
            }
            OnCloseSCM();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnStop
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual int OnStop()
    {
        eError error;
        cServiceControl service;
        cServiceStatus status;
        SERVICE_STATE state;

        if (!(error = OnOpenSCM()))
        {
            if ((error = m_scm.OpenService(service, m_name)))
                OutputErrorL
                ("Unable to open service \"", m_name, "\"\n", 0);
            else
            {
                OutputL("Stopping service \"", m_name, "\"...\n", 0);

                if ((error = service.ControlService
                    (status, SERVICE_CONTROL_STOP)))
                    OutputErrorL
                    ("Unable to control service \"", m_name, "\"\n", 0);

                else do
                {
                    if (SERVICE_STOPPED == (state = status.GetState()))
                    {
                        OutputL("...Service \"", m_name, "\" stopped\n", 0);
                        break;
                    }
                    else if ((error = service.QueryServiceStatus(status)))
                    {
                        OutputErrorL
                        ("Unable to query service \"", 
                         m_name, "\" status\n", 0);
                    }
                }
                while (!error);

                service.Close();
            }
            OnCloseSCM();
        }
        return 0;
    }

    /**
     **********************************************************************
     * Function: OnOpenSCM
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual int OnOpenSCM()
    {
        eError error;

        if (!(error = m_scm.Open()))
            return 0;

        OutputError("Unable to open Service Control Manager\n");
        return 1;
    }
    /**
     **********************************************************************
     * Function: OnCloseSCM
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual int OnCloseSCM()
    {
        eError error;

        if (!(error = m_scm.Close()))
            return 0;

        OutputError("Unable to close Service Control Manager\n");
        return 1;
    }

    /**
     **********************************************************************
     * Function: SetTypeIsDriver
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual SC_SERVICE_TYPE SetTypeIsDriver(bool is_driver=true)
    {
        if (is_driver)
            m_service_type = SERVICE_KERNEL_DRIVER;

        else m_service_type = SERVICE_WIN32_OWN_PROCESS;

        return m_service_type;
    }
    /**
     **********************************************************************
     * Function: GetTypeIsDriver
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual bool GetTypeIsDriver() const
    {
        return (SERVICE_KERNEL_DRIVER == m_service_type);
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual eError SetName(const TCHAR *name, int length=-1)
    {
        eError error=e_ERROR_NONE;

        if (0 > (length = m_name_buffer.Copy(name, length)))
            return (error = -length);

        if (!(m_name = m_name_buffer.GetWriteBuffer(length, length)))
            return (error = -length);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual const TCHAR *GetName() const
    {
        return m_name;
    }

    /**
     **********************************************************************
     * Function: SetLabel
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual eError SetLabel(const TCHAR *label, int length=-1)
    {
        eError error=e_ERROR_NONE;

        if (0 > (length = m_label_buffer.Copy(label, length)))
            return (error = -length);

        if (!(m_label = m_label_buffer.GetWriteBuffer(length, length)))
            return (error = -length);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetLabel
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual const TCHAR *GetLabel() const
    {
        return m_label;
    }

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual eError SetPath(const TCHAR *path, int length=-1)
    {
        eError error=e_ERROR_NONE;

        if (0 > (length = m_path_buffer.Copy(path, length)))
            return (error = -length);

        if (!(m_path = m_path_buffer.GetWriteBuffer(length, length)))
            return (error = -length);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual const TCHAR *GetPath()
    {
        const TCHAR *extension;
        int pathlength,pathsize;

        if (m_path)
            return m_path;

        if ((m_path = m_path_buffer.GetWriteBuffer
            (pathsize, pathlength)))

        if (0 >= (pathlength = GetModuleFileName
            (NULL, m_path, pathsize-1)))
            m_path = 0;

        else if (0 >= (pathlength = m_path_buffer
                 .SetLength(pathlength)))
                m_path = 0;

        else if (SERVICE_KERNEL_DRIVER == m_service_type)
        {
            if ((extension = m_path_buffer.In('.', true)))
                pathlength = extension-m_path;

            if (0 >= (pathlength = m_path_buffer
                .SetLength(pathlength+1)))
                m_path = 0;

            if (0 >= (pathlength = m_path_buffer
                .Write(m_driver_extension)))
                m_path = 0;
        }

        return m_path;
    }
    /**
     **********************************************************************
     * Function: GetCommand
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual const TCHAR *GetCommand(const TCHAR *arg, int arglen=-1)
    {
        const TCHAR *path;
        int len;

        if ((path = GetPath()))
        if (arg)
        if (0 > (len = m_command_buffer.CopyL(path, " ", 0)))
            path = 0;

        else if (0 > (len = m_command_buffer.Write(arg, arglen)))
                path = 0;

        else path = m_command_buffer.GetBuffer();

        return path;
    }

    /**
     **********************************************************************
     * Function: SetDriverExtension
     *
     *   Author: $author$
     *     Date: 11/30/2003
     **********************************************************************
     */
    virtual eError SetDriverExtension
    (const TCHAR *driver_extension, int length=-1)
    {
        eError error=e_ERROR_NONE;

        if (0 > (length = m_driver_extension_buffer
            .Copy(driver_extension, length)))
            return (error = -length);

        if (!(m_driver_extension = m_driver_extension_buffer
            .GetWriteBuffer(length, length)))
            return (error = -length);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetDriverExtension
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual const TCHAR *GetDriverExtension() const
    {
        return m_driver_extension;
    }

    /**
     **********************************************************************
     * Function: StartServiceCtrlDispatcher
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual eError StartServiceCtrlDispatcher()
    {
        SERVICE_TABLE_ENTRY service_table[] =
        {
            {m_name, ServiceMain},
            {NULL, NULL}
        };

        if (::StartServiceCtrlDispatcher(service_table))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnServiceStarting
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual eError OnServiceStarting
    (SERVICE_ARGC argc, SERVICE_ARGV argv)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnServiceStopping
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual eError OnServiceStopping
    (SERVICE_ARGC argc, SERVICE_ARGV argv)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnServiceRunning
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual eError OnServiceRunning
    (SERVICE_ARGC argc, SERVICE_ARGV argv)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnServiceMain
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual void OnServiceMain
    (SERVICE_ARGC argc, SERVICE_ARGV argv)
    {
        eError error;

        if (!(error = RegisterServiceCtrlHandler()))
        {
            m_service_status.SetState(SERVICE_START_PENDING);
            if (!(error = m_service_status.Set()))
            {
                if (!(error = OnServiceStarting(argc, argv)))
                {
                    m_service_status.SetState(SERVICE_RUNNING);
                    if (!(error = m_service_status.Set()))
                    {
                        OnServiceRunning(argc, argv);
                        m_service_status.SetState(SERVICE_STOP_PENDING);
                        m_service_status.Set();
                        OnServiceStopping(argc, argv);
                    }
                }
            }
            m_service_status.SetState(SERVICE_STOPPED);
            m_service_status.Set();
        }
    }
    /**
     **********************************************************************
     * Function: ServiceMain
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    static void WINAPI ServiceMain
    (SERVICE_ARGC argc, SERVICE_ARGV argv)
    {
        cService *instance;

        if ((instance = GetInstance()))
            instance->OnServiceMain(argc, argv);
    }
    /**
     **********************************************************************
     * Function: RegisterServiceCtrlHandler
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual eError RegisterServiceCtrlHandler()
    {
        eError error;
        SERVICE_STATUS_HANDLE handle;

        if (INVALID_SERVICE_STATUS_HANDLE
            != (handle = ::RegisterServiceCtrlHandler
            (m_name, ServiceCtrlHandler)))
        {
            if (!(error = m_service_status.Attach(handle)))
                return error;
        }
        return e_ERROR_FAILED;
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
    }
    /**
     **********************************************************************
     * Function: OnServiceCtrlPause
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual void OnServiceCtrlPause()
    {
    }
    /**
     **********************************************************************
     * Function: OnServiceCtrlContinue
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual void OnServiceCtrlContinue()
    {
    }
    /**
     **********************************************************************
     * Function: OnServiceCtrl
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual void OnServiceCtrl(SC_CONTROL control)
    {
        switch(control)
        {
        case SERVICE_CONTROL_STOP:
            OnServiceCtrlStop();
            break;

        case SERVICE_CONTROL_PAUSE:
            OnServiceCtrlPause();
            break;

        case SERVICE_CONTROL_CONTINUE:
            OnServiceCtrlContinue();
            break;
        }
    }
    /**
     **********************************************************************
     * Function: ServiceCtrlHandler
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    static void WINAPI ServiceCtrlHandler(SC_CONTROL control)
    {
        cService *instance;

        if ((instance = GetInstance()))
            instance->OnServiceCtrl(control);
    }
};

#endif /* ndef _CSERVICE_HXX */

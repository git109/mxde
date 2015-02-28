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
 *   File: cservicecontrolmanager.hxx
 *
 * Author: $author$
 *   Date: 11/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVICECONTROLMANAGER_HXX
#define _CSERVICECONTROLMANAGER_HXX

#include <windows.h>

#include "cservicestatus.hxx"
#include "chandlet.hxx"

#define INVALID_SC_HANDLE NULL
#define SC_LOCAL_HOST NULL
#define SC_SERVICE_TYPE DWORD
#define SC_START_TYPE DWORD
#define SC_ACCESS DWORD
#define SC_CONTROL DWORD

/**
 **********************************************************************
 *  Class: cServiceControlHandle
 *
 * Author: $author$
 *   Date: 11/23/2003
 **********************************************************************
 */
class cServiceControlHandle
: public cOpenedHandleT<SC_HANDLE, INVALID_SC_HANDLE>
{
public:
    typedef cOpenedHandleT<SC_HANDLE, INVALID_SC_HANDLE> cIs;

    /**
     **********************************************************************
     * Constructor: cServiceControlHandle
     *
     *      Author: $author$
     *        Date: 11/23/2003
     **********************************************************************
     */
    cServiceControlHandle
    (SC_HANDLE handle=INVALID_SC_HANDLE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cServiceControlHandle
     *
     *     Author: $author$
     *       Date: 11/23/2003
     **********************************************************************
     */
    virtual ~cServiceControlHandle()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/23/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        SC_HANDLE handle;

        if (INVALID_SC_HANDLE == (handle = m_handle))
            return e_ERROR_NOT_ATTACHED;

        m_handle = INVALID_SC_HANDLE;
        m_opened = false;

        if (CloseServiceHandle(handle))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cServiceControl
 *
 * Author: $author$
 *   Date: 11/23/2003
 **********************************************************************
 */
class cServiceControl
: public cServiceControlHandle
{
public:
    typedef cServiceControlHandle cIs;

    /**
     **********************************************************************
     * Constructor: cServiceControl
     *
     *      Author: $author$
     *        Date: 11/23/2003
     **********************************************************************
     */
    cServiceControl
    (SC_HANDLE handle=INVALID_SC_HANDLE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }

    /**
     **********************************************************************
     * Function: DeleteService
     *
     *   Author: $author$
     *     Date: 11/23/2003
     **********************************************************************
     */
    virtual eError DeleteService()
    {
        if (INVALID_SC_HANDLE != m_handle)

        if (::DeleteService(m_handle))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: StartService
     *
     *   Author: $author$
     *     Date: 11/23/2003
     **********************************************************************
     */
    virtual eError StartService
    (int argc=0, const char **argv=NULL)
    {
        if (INVALID_SC_HANDLE != m_handle)

        if (::StartService(m_handle, argc, argv))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: ControlService
     *
     *   Author: $author$
     *     Date: 11/23/2003
     **********************************************************************
     */
    virtual eError ControlService
    (cServiceStatus &status, SC_CONTROL control)
    {
        if (INVALID_SC_HANDLE != m_handle)

        if (::ControlService
            (m_handle, control, &status.StatusIs()))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: QueryServiceStatus
     *
     *   Author: $author$
     *     Date: 11/23/2003
     **********************************************************************
     */
    virtual eError QueryServiceStatus(cServiceStatus &status)
    {
        if (INVALID_SC_HANDLE != m_handle)

        if (::QueryServiceStatus
            (m_handle, &status.StatusIs()))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cServiceControlManager
 *
 * Author: $author$
 *   Date: 11/22/2003
 **********************************************************************
 */
class cServiceControlManager
: public cServiceControlHandle
{
public:
    typedef cServiceControlHandle cIs;

    /**
     **********************************************************************
     * Constructor: cServiceControlManager
     *
     *      Author: $author$
     *        Date: 11/22/2003
     **********************************************************************
     */
    cServiceControlManager
    (SC_HANDLE handle=INVALID_SC_HANDLE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 11/22/2003
     **********************************************************************
     */
    virtual eError Open
    (const char *host=SC_LOCAL_HOST,
     const char *database=SERVICES_ACTIVE_DATABASE,
     SC_ACCESS access=SC_MANAGER_ALL_ACCESS)
    {
        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if (INVALID_SC_HANDLE != (m_handle = OpenSCManager
            (host, database, access)))
        {
            m_opened = true;
            return e_ERROR_NONE;
        }

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: CreateService
     *
     *   Author: $author$
     *     Date: 11/22/2003
     **********************************************************************
     */
    virtual eError CreateService
    (cServiceControl &service,
     const char *name, const char *label, const char *path, 
     SC_SERVICE_TYPE service_type=SERVICE_WIN32_OWN_PROCESS, 
     SC_START_TYPE start_type=SERVICE_DEMAND_START)
    {
        eError error;
        DWORD access=SERVICE_ALL_ACCESS;
        DWORD error_control=SERVICE_ERROR_NORMAL;
        LPCSTR load_order=NULL;
        LPDWORD tag_id=NULL;
        LPCSTR dependencies=NULL;
        LPCSTR user=NULL;
        LPCSTR password=NULL;
        SC_HANDLE handle;

        if (INVALID_SC_HANDLE != m_handle)

        if (INVALID_SC_HANDLE != (handle = ::CreateService
            (m_handle, name, label, access, service_type,
             start_type, error_control, path, load_order, 
             tag_id, dependencies, user, password)))
        {
            if (!(error = service.Attach(handle, true)))
                return error;

            CloseServiceHandle(handle);
        }
        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: OpenService
     *
     *   Author: $author$
     *     Date: 11/23/2003
     **********************************************************************
     */
    virtual eError OpenService
    (cServiceControl &service, const char *name)
    {
        DWORD access=SERVICE_ALL_ACCESS;
        SC_HANDLE handle;
        eError error;

        if (INVALID_SC_HANDLE != m_handle)

        if (INVALID_SC_HANDLE != (handle = ::OpenService
            (m_handle, name, access)))
        {
            if (!(error = service.Attach(handle, true)))
                return e_ERROR_NONE;

            CloseServiceHandle(handle);
        }
        return e_ERROR_FAILED;
    }
};

#endif /* ndef _CSERVICECONTROLMANAGER_HXX */

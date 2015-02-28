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
 *   File: cservicestatus.hxx
 *
 * Author: $author$
 *   Date: 11/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVICESTATUS_HXX
#define _CSERVICESTATUS_HXX

#include <windows.h>
#define INVALID_SERVICE_STATUS_HANDLE NULL
#define SERVICE_STATE DWORD

#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cSERVICE_STATUS
 *
 * Author: $author$
 *   Date: 11/25/2003
 **********************************************************************
 */
class cSERVICE_STATUS
: public SERVICE_STATUS
{
public:
    typedef SERVICE_STATUS cIs;

    /**
     **********************************************************************
     * Constructor: cSERVICE_STATUS
     *
     *      Author: $author$
     *        Date: 11/25/2003
     **********************************************************************
     */
    cSERVICE_STATUS() 
    {
        dwServiceType = SERVICE_WIN32_OWN_PROCESS;
        dwCurrentState = SERVICE_STOPPED;
        dwControlsAccepted 
        = SERVICE_ACCEPT_STOP 
        | SERVICE_ACCEPT_PAUSE_CONTINUE
        | SERVICE_ACCEPT_SHUTDOWN;
        dwWin32ExitCode = 0;
        dwServiceSpecificExitCode = 0;
        dwCheckPoint = 0;
        dwWaitHint = 0;
    }
};

/**
 **********************************************************************
 *  Class: cServiceStatus
 *
 * Author: $author$
 *   Date: 11/22/2003
 **********************************************************************
 */
class cServiceStatus
: public cOpenedHandleT<SERVICE_STATUS_HANDLE , INVALID_SERVICE_STATUS_HANDLE >
{
public:
    typedef cOpenedHandleT<SERVICE_STATUS_HANDLE , INVALID_SERVICE_STATUS_HANDLE > cIs;

    cSERVICE_STATUS m_status;

    /**
     **********************************************************************
     * Constructor: cServiceStatus
     *
     *      Author: $author$
     *        Date: 11/22/2003
     **********************************************************************
     */
    cServiceStatus
    (SERVICE_STATUS_HANDLE handle=INVALID_SERVICE_STATUS_HANDLE, 
     bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cServiceStatus
     *
     *     Author: $author$
     *       Date: 11/22/2003
     **********************************************************************
     */
    virtual ~cServiceStatus()
    {
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual eError Set()
    {
        if (INVALID_SERVICE_STATUS_HANDLE != m_handle)

        if (SetServiceStatus(m_handle, &m_status))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: SetState
     *
     *   Author: $author$
     *     Date: 11/24/2003
     **********************************************************************
     */
    virtual SERVICE_STATE SetState(SERVICE_STATE state)
    {
        m_status.dwCurrentState = state;
        return m_status.dwCurrentState;
    }
    /**
     **********************************************************************
     * Function: GetState
     *
     *   Author: $author$
     *     Date: 11/22/2003
     **********************************************************************
     */
    virtual SERVICE_STATE GetState() const
    {
        return m_status.dwCurrentState;
    }
    /**
     **********************************************************************
     * Function: StatusIs
     *
     *   Author: $author$
     *     Date: 11/22/2003
     **********************************************************************
     */
    virtual SERVICE_STATUS &StatusIs()
    {
        return m_status;
    }
};

#endif /* ndef _CSERVICESTATUS_HXX */

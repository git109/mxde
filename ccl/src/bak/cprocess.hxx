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
 *   File: cprocess.hxx
 *
 * Author: $author$
 *   Date: 10/28/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPROCESS_HXX
#define _CPROCESS_HXX

#if defined(WIN32)
#include "cwinprocess.hxx"
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "platformio.h"
#include "platformprocess.h"
#include "platformthread.h"
#include "ctcharbuffer.hxx"
#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cProcessT
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cProcessT
: public cOpenedHandleT
  <PROCESS, (int)INVALID_PROCESS, TIs>
{
public:
    typedef cOpenedHandleT
    <PROCESS, (int)INVALID_PROCESS, TIs> cIs;

    bool m_created, m_started, m_suspended;
    cTCHARBuffer m_command;
    THREAD m_thread;

    /**
     **********************************************************************
     * Constructor: cProcessT
     *
     *      Author: $author$
     *        Date: 10/28/2004
     **********************************************************************
     */
    cProcessT
    (PROCESS process=INVALID_PROCESS, 
     bool opened=false, bool created=false, 
     bool started=false, bool suspended=false) 
    : cIs(process, opened),
      m_created(created),
      m_started(started),
      m_suspended(suspended),
      m_thread(INVALID_THREAD)
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError Create
    (const char *command, 
     bool suspended=false, 
     bool detached=false,
     HANDLE stdin=INVALID_HANDLE, 
     HANDLE stdout=INVALID_HANDLE,
     HANDLE stderr=INVALID_HANDLE) 
    {
        eError error = e_ERROR_FAILED;

        LPCTSTR lpApplicationName = NULL;
        LPTSTR lpCommandLine = NULL;
        LPSECURITY_ATTRIBUTES lpProcessAttributes = NULL;
        LPSECURITY_ATTRIBUTES lpThreadAttributes = NULL;
        BOOL bInheritHandles = FALSE;
        DWORD dwCreationFlags = 0;
        LPVOID lpEnvironment = NULL;
        LPSTR lpCurrentDirectory = NULL;
        DWORD err;
        int length;

        cWinStartupInfo sinfo;
        cWinProcessInformation pinfo;

        if (0 > (length = m_command.Copy(command)))
            return error;

        lpCommandLine = m_command.GetWriteBuffer(length);

        if (!lpCommandLine || (0 > length))
            return error;

        if (detached)
            dwCreationFlags |= DETACHED_PROCESS;

        if (suspended)
            dwCreationFlags |= CREATE_SUSPENDED;

        if (INVALID_HANDLE != stdin)
        {
            bInheritHandles = TRUE;
            sinfo.SetStdInput(stdin);
        }

        if (INVALID_HANDLE != stdout)
        {
            bInheritHandles = TRUE;
            sinfo.SetStdOutput(stdout);
        }

        if (INVALID_HANDLE != stderr)
        {
            bInheritHandles = TRUE;
            sinfo.SetStdError(stderr);
        }

        if (CreateProcess
            (lpApplicationName, lpCommandLine, 
             lpProcessAttributes,lpThreadAttributes, 
             bInheritHandles, dwCreationFlags,
             lpEnvironment, lpCurrentDirectory, 
             &sinfo, &pinfo))
        {
            m_created = true;
            m_started = !suspended;
            m_suspended = suspended;
            m_handle = pinfo.hProcess;
            m_thread = pinfo.hThread;
            error = e_ERROR_NONE;
        }
        else err = GetLastError();

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_FAILED;

        if (INVALID_PROCESS == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (INVALID_THREAD != m_thread)
            CloseHandle(m_thread);

        CloseHandle(m_handle);
        m_handle = INVALID_PROCESS;
        m_thread = INVALID_THREAD;
        m_created = false;
        m_started = false;
        m_suspended = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError Start() 
    {
        eError error = e_ERROR_FAILED;

        if (INVALID_PROCESS == m_handle)
            return e_ERROR_NOT_ATTACHED;

        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError Finish(long milisecond_timeout=WAIT_INFINITE) 
    {
        eError error = e_ERROR_FAILED;

        if (INVALID_PROCESS == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((error = Wait(milisecond_timeout)))
            return error;

        error = Close();
        return error;
    }
    /**
     **********************************************************************
     * Function: Wait
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError Wait(long milisecond_timeout=WAIT_INFINITE) 
    {
        eError error = e_ERROR_FAILED;
        DWORD result;

        if (INVALID_PROCESS == m_handle)
            return e_ERROR_NOT_ATTACHED;

        result = WaitForSingleObject
        (m_handle, milisecond_timeout);

        switch(result)
        {
        case WAIT_OBJECT_0:
            return e_ERROR_NONE;

        case WAIT_TIMEOUT:
            return e_ERROR_WAIT_TIMEOUT;

        case WAIT_ABANDONED:
            return e_ERROR_WAIT_ABANDONED;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cProcess
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cProcess
: public cProcessT<>
{
public:
    typedef cProcessT<> cIs;

    /**
     **********************************************************************
     * Constructor: cProcess
     *
     *      Author: $author$
     *        Date: 10/28/2004
     **********************************************************************
     */
    cProcess
    (PROCESS process=INVALID_PROCESS,
     bool opened=false, bool created=false, 
     bool started=false, bool suspended=false) 
    : cIs(process, opened, created, started, suspended) 
    {
    }
};

#endif /* ndef _CPROCESS_HXX */

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
 *   File: cthreadt.hxx
 *
 * Author: $author$
 *   Date: 11/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTHREADT_HXX
#define _CTHREADT_HXX

#include "platform.h"

#if defined(WIN32)
/* 
 * Windows threads
 */
#include <windows.h>
#if defined(_WIN32_WCE)
#else /* defined(_WIN32_WCE) */
#include <process.h>
#endif /* defined(_WIN32_WCE) */

#define THREAD HANDLE
#define INVALID_THREAD NULL
#else /* defined(WIN32) */
/* 
 * Posix threads
 */
#define THREAD pthread_t
#define INVALID_THREAD -1
#endif /* defined(WIN32) */

#define CREATE_STARTED 0

#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cThreadT
 *
 * Author: $author$
 *   Date: 11/26/2003
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cThreadT
: public cOpenedHandleT<THREAD, INVALID_THREAD, TIs>
{
public:
    typedef cOpenedHandleT<THREAD, INVALID_THREAD, TIs> cIs;

    /**
     **********************************************************************
     * Function: ThreadOnRun
     *
     *   Author: $author$
     *     Date: 10/10/2004
     **********************************************************************
     */
#if defined(_WIN32_WCE)
static DWORD ThreadOnRun(LPVOID param)
#elif defined(WIN32)
static unsigned __stdcall ThreadOnRun(void *param)
#else /* defined(WIN32) */
static void* ThreadOnRun(void *param)
#endif /* defined(WIN32) */
    {
        TAs *thread;

        if ((thread = ((TAs*)param)))
            thread->OnRun();

#if defined(WIN32)
        return 0;
#else /* defined(WIN32) */
        return 0;
#endif /* defined(WIN32) */
    }

    /**
     **********************************************************************
     * Function: Sleep
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    static eError Sleep(int miliseconds=-1) 
    {
        eError error = e_ERROR_NONE;
        
#if defined(WIN32)
        ::Sleep(miliseconds);
#else /* defined(WIN32) */
        error = e_ERROR_NOT_SUPPORTED;
#endif /* defined(WIN32) */

        return error;
    }

    TAs *m_instance;
    int m_started;

    /**
     **********************************************************************
     * Constructor: cThreadT
     *
     *      Author: $author$
     *        Date: 11/26/2003
     **********************************************************************
     */
    cThreadT
    (TAs *instance, THREAD handle=INVALID_THREAD, 
     bool opened=false, bool started=false) 
    : cIs(handle, opened),
      m_instance(instance),
      m_started(started)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cThreadT
     *
     *     Author: $author$
     *       Date: 11/26/2003
     **********************************************************************
     */
    virtual ~cThreadT()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Create()
    {
        eError error = e_ERROR_FAILED;
        THREAD handle = m_handle;

        if (m_opened)
        if (INVALID_THREAD != m_handle)
            return e_ERROR_ALREADY_CREATED;
        else return e_ERROR_NOT_ATTACHED;

        if (!(error = PlatformCreateThread(CREATE_SUSPENDED)))
            m_opened = true;

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error=e_ERROR_FAILED;
        THREAD handle=m_handle;

        if (INVALID_THREAD == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
/* 
 * Windows threads
 */
        BOOL ok;

        if ((ok = CloseHandle(m_handle)))
            error = e_ERROR_NONE;

#else /* defined(WIN32) */
/* 
 * Posix threads
 */
#endif /* defined(WIN32) */

        m_opened = false;
        m_started = false;
        m_handle = INVALID_THREAD;

        return error;
    }

    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Start()
    {
        eError error=e_ERROR_FAILED;
        THREAD handle=m_handle;

        if (m_opened)
        if (INVALID_THREAD != m_handle)
            if (m_started)
                return e_ERROR_ALREADY_STARTED;
            else
            {
                int suspended;

                if (1 == (suspended = Resume()))
                {
                    m_started = true;
                    error = e_ERROR_NONE;
                }
                return error;
            }
        else return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
/* 
 * Windows threads
 */
        if (!(error = PlatformCreateThread(CREATE_STARTED)))
        {
            m_opened = true;
            m_started = true;
        }
#else /* defined(WIN32) */
/* 
 * Posix threads
 */
        int err;
        pthread_t tid;
        pthread_attr_t tattr;

        if (!(err = pthread_attr_init(&tattr)))
        if (!(err = pthread_create
            (&tid, &tattr, ThreadOnRun, m_instance)))
        {
            m_handle = tid;
            m_opened = true;
            error = e_ERROR_NONE;
        }
#endif /* defined(WIN32) */

        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Finish(int miliseconds=-1)
    {
        eError error2,error=e_ERROR_FAILED;

        if (INVALID_THREAD == m_handle)
            return e_ERROR_NOT_ATTACHED;

        error = Wait(miliseconds);

        if ((error2 = Close()))
        if (!error)
            error = error2;

        return error;
    }

    /**
     **********************************************************************
     * Function: Wait
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Wait(int miliseconds=-1)
    {
        eError error=e_ERROR_FAILED;

        if (INVALID_THREAD == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
/* 
 * Windows threads
 */
        DWORD result;

        result = WaitForSingleObject
        (m_handle,(miliseconds<0)?INFINITE:miliseconds);

        switch(result)
        {
        case WAIT_OBJECT_0:
            error = e_ERROR_NONE;
            break;

        case WAIT_TIMEOUT:
            error = e_ERROR_WAIT_TIMEOUT;
            break;

        case WAIT_ABANDONED:
            error = e_ERROR_WAIT_ABANDONED;
            break;
        }
#else /* defined(WIN32) */
/* 
 * Posix threads
 */
#endif /* defined(WIN32) */

        return error;
    }

    /**
     **********************************************************************
     * Function: Suspend
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual int Suspend()
    {
        eError result=-e_ERROR_FAILED;

        if (INVALID_THREAD == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
/* 
 * Windows threads
 */
        DWORD suspended;

        if (((DWORD)-1) != (suspended = SuspendThread(m_handle)))
            result = suspended;

#else /* defined(WIN32) */
/* 
 * Posix threads
 */
        result = -e_ERROR_NOT_SUPPORTED;
#endif /* defined(WIN32) */

        return result;
    }
    /**
     **********************************************************************
     * Function: Resume
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual int Resume()
    {
        eError result=-e_ERROR_FAILED;

        if (INVALID_THREAD == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
/* 
 * Windows threads
 */
        DWORD suspended;

        if (((DWORD)-1) != (suspended = ResumeThread(m_handle)))
            result = suspended;

#else /* defined(WIN32) */
/* 
 * Posix threads
 */
        result = -e_ERROR_NOT_SUPPORTED;
#endif /* defined(WIN32) */

        return result;
    }

    /**
     **********************************************************************
     * Function: PlatformCreateThread
     *
     *   Author: $author$
     *     Date: 1/17/2006
     **********************************************************************
     */
#if defined(_WIN32_WCE)
    virtual eError PlatformCreateThread(DWORD init_flag) 
#else /* defined(_WIN32_WCE) */
    virtual eError PlatformCreateThread(unsigned init_flag) 
#endif /* defined(_WIN32_WCE) */
    {
#if defined(WIN32)
        eError error = e_ERROR_FAILED;
#if defined(_WIN32_WCE)
/* 
 * Windows CE threads
 */
        LPSECURITY_ATTRIBUTES security_attributes=NULL;
        DWORD stack_size=0;
        DWORD tid;

        if (INVALID_THREAD != (m_handle = CreateThread
            (security_attributes, stack_size, 
			 ThreadOnRun, m_instance, init_flag, &tid)))
#else /* defined(_WIN32_WCE) */
/* 
 * Windows threads
 */
        void* security_attributes=NULL;
        unsigned stack_size=0;
        unsigned tid;

        if (INVALID_THREAD != (m_handle =(THREAD)_beginthreadex
            (security_attributes, stack_size, 
			 ThreadOnRun, m_instance, init_flag, &tid)))
#endif /* defined(_WIN32_WCE) */
             error = e_ERROR_NONE;
#else /* defined(WIN32) */
/* 
 * Posix threads
 */
        eError error = e_ERROR_NOT_SUPPORTED;
#endif /* defined(WIN32) */

        return error;
    }
};

#endif /* ndef _CTHREADT_HXX */

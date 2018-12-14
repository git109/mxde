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
 *   File: cmutex.hxx
 *
 * Author: $author$
 *   Date: 11/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMUTEX_HXX
#define _CMUTEX_HXX

#include "chandlet.hxx"
#include "platformprocess.h"
#include "platformmutex.h"

#if defined(WIN32) 
#include "cwinsecurity.hxx"
#else /* defined(WIN32) */
#endif /* defined(WIN32) */
        
/**
 **********************************************************************
 *  Class: cMutexT
 *
 * Author: $author$
 *   Date: 11/2/2004
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cMutexT
: public cOpenedHandleT<MUTEX, INVALID_MUTEX, TIs>
{
public:
    typedef cOpenedHandleT<MUTEX, INVALID_MUTEX, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cMutexT
     *
     *      Author: $author$
     *        Date: 11/2/2004
     **********************************************************************
     */
    cMutexT(MUTEX handle=INVALID_MUTEX, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Create
    (bool acquired=false, const TCHAR *named=0) 
    {
        eError error = e_ERROR_FAILED;
        BOOL bInitialOwner = acquired;
        LPCTSTR lpName = named;
        cWinSecurityAttributes sa;

        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if (INVALID_MUTEX != (m_handle = CreateMutex
            (&sa, bInitialOwner, lpName)))
        {
            m_opened = true;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Open(const TCHAR *named=0) 
    {
#if defined(_WIN32_WCE)
        eError error = e_ERROR_NOT_IMPLEMENTED;
#else /* defined(_WIN32_WCE) */
        eError error = e_ERROR_FAILED;
        DWORD dwDesiredAccess = MUTEX_ALL_ACCESS;
        BOOL bInheritHandle = FALSE;
        LPCTSTR lpName = named;

        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if (INVALID_MUTEX != (m_handle = OpenMutex
            (dwDesiredAccess, bInheritHandle, lpName)))
        {
            m_opened = true;
            error = e_ERROR_NONE;
        }
#endif /* defined(_WIN32_WCE) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_FAILED;

        if (INVALID_MUTEX == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (CloseHandle(m_handle))
            error = e_ERROR_NONE;

        m_handle = INVALID_MUTEX;
        m_opened = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Acquire(long milisecond_timeout=-1) 
    {
        eError error = e_ERROR_FAILED;
        DWORD dwMilliseconds = (milisecond_timeout>0)?milisecond_timeout:INFINITE;
        DWORD result;

        if (INVALID_MUTEX == m_handle)
            return e_ERROR_NOT_ATTACHED;

        result = WaitForSingleObject(m_handle, dwMilliseconds);

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
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Release() 
    {
        eError error = e_ERROR_FAILED;

        if (INVALID_MUTEX == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (ReleaseMutex(m_handle))
            error = e_ERROR_NONE;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cMutex
 *
 * Author: $author$
 *   Date: 11/2/2004
 **********************************************************************
 */
class cMutex
: public cMutexT<cMutex>
{
public:
    typedef cMutexT<cMutex> cIs;

    /**
     **********************************************************************
     * Constructor: cMutex
     *
     *      Author: $author$
     *        Date: 11/2/2004
     **********************************************************************
     */
    cMutex(MUTEX handle=INVALID_MUTEX, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
};

#endif /* ndef _CMUTEX_HXX */

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
 *   File: cpipe.hxx
 *
 * Author: $author$
 *   Date: 10/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPIPE_HXX
#define _CPIPE_HXX

#if defined(WIN32)
#include "cwinsecurity.hxx"
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "platformio.h"
#include "cerror.hxx"
#include "cbase.hxx"

#define DEFAULT_PIPE_BUFFER_SIZE 4096

/**
 **********************************************************************
 *  Class: cPipeT
 *
 * Author: $author$
 *   Date: 10/29/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cPipeT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/29/2004
     **********************************************************************
     */
    enum
    {
        e_PIPE_READ = 0,
        e_PIPE_WRITE = 1
    };

    HANDLE m_handle[2];

    bool m_is_open;
    int m_buffer_size;
    bool m_is_inheritable;
    cWinSecurityAttributes m_security;

    /**
     **********************************************************************
     * Constructor: cPipeT
     *
     *      Author: $author$
     *        Date: 10/29/2004
     **********************************************************************
     */
    cPipeT
    (HANDLE read_handle=INVALID_HANDLE, 
     HANDLE write_handle=INVALID_HANDLE,
     bool is_open=false,
     int buffer_size=DEFAULT_PIPE_BUFFER_SIZE,
     bool is_inheritable=true)
    : m_is_open(is_open),
      m_buffer_size(buffer_size),
      m_is_inheritable(is_inheritable)
    {
        m_handle[e_PIPE_READ] = read_handle;
        m_handle[e_PIPE_WRITE] = write_handle;
    }
    /**
     **********************************************************************
     * Destructor: ~cPipeT
     *
     *     Author: $author$
     *       Date: 10/29/2004
     **********************************************************************
     */
    virtual ~cPipeT()
    {
        eError error;

        if (m_is_open)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    virtual eError Create
    (int buffer_size=DEFAULT_PIPE_BUFFER_SIZE,
     bool is_inheritable=true) 
    {
        eError error = e_ERROR_FAILED;

        BOOL bInheritHandle = is_inheritable?TRUE:FALSE;
        PHANDLE hReadPipe = m_handle+e_PIPE_READ;
        PHANDLE hWritePipe = m_handle+e_PIPE_WRITE;
        LPSECURITY_ATTRIBUTES lpPipeAttributes = &m_security;
        DWORD nSize = buffer_size;

        if (m_is_open)
            return e_ERROR_ALREADY_OPEN;

        m_security.SetInheritHandle(bInheritHandle);

        if (CreatePipe
            (hReadPipe, hWritePipe, 
             lpPipeAttributes, nSize))
        {
            m_is_open = true;
            return e_ERROR_NONE;
        }

        m_handle[e_PIPE_READ] = INVALID_HANDLE;
        m_handle[e_PIPE_WRITE] = INVALID_HANDLE;
        m_is_open = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_FAILED;
        BOOL closed_read = TRUE;
        BOOL closed_write = TRUE;

        if ((INVALID_HANDLE == m_handle[e_PIPE_READ])
            && (INVALID_HANDLE == m_handle[e_PIPE_WRITE]))
            return e_ERROR_NOT_ATTACHED;

        if (INVALID_HANDLE != m_handle[e_PIPE_READ])
            closed_read = CloseHandle(m_handle[e_PIPE_READ]);

        if (INVALID_HANDLE != m_handle[e_PIPE_WRITE])
            closed_write = CloseHandle(m_handle[e_PIPE_WRITE]);

        if (closed_read && closed_write)
            error = e_ERROR_NONE;

        m_handle[e_PIPE_READ] = INVALID_HANDLE;
        m_handle[e_PIPE_WRITE] = INVALID_HANDLE;
        m_is_open = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: CloseRead
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    virtual eError CloseRead() 
    {
        eError error = e_ERROR_FAILED;

        if ((INVALID_HANDLE == m_handle[e_PIPE_READ]))
            return e_ERROR_NOT_ATTACHED;

        if (CloseHandle(m_handle[e_PIPE_READ]))
            error = e_ERROR_NONE;

        m_handle[e_PIPE_READ] = INVALID_HANDLE;
        return error;
    }
    /**
     **********************************************************************
     * Function: CloseWrite
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    virtual eError CloseWrite() 
    {
        eError error = e_ERROR_FAILED;

        if ((INVALID_HANDLE == m_handle[e_PIPE_WRITE]))
            return e_ERROR_NOT_ATTACHED;

        if (CloseHandle(m_handle[e_PIPE_WRITE]))
            error = e_ERROR_NONE;

        m_handle[e_PIPE_WRITE] = INVALID_HANDLE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual size_t Read(void *buffer, size_t size) 
    {
        size_t result = -e_ERROR_FAILED;
        LPOVERLAPPED lpOverlapped = NULL;
        DWORD count;

        if (INVALID_HANDLE == m_handle[e_PIPE_READ])
            return -e_ERROR_NOT_ATTACHED;

        if (ReadFile
            (m_handle[e_PIPE_READ], 
             buffer, size, &count, lpOverlapped))
            result = count;

        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual size_t Write(const void *buffer, size_t size) 
    {
        size_t result = -e_ERROR_FAILED;
        LPOVERLAPPED lpOverlapped = NULL;
        DWORD count;

        if (INVALID_HANDLE == m_handle[e_PIPE_WRITE])
            return -e_ERROR_NOT_ATTACHED;

        if (WriteFile
            (m_handle[e_PIPE_WRITE], 
             buffer, size, &count, lpOverlapped))
            result = count;

        return result;
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual eError Attach
    (HANDLE read_handle, 
     HANDLE write_handle, bool is_open=false) 
    {
        eError error = e_ERROR_NONE;

        if (m_is_open)
            return e_ERROR_ALREADY_OPEN;

        if ((INVALID_HANDLE == read_handle)
            || (INVALID_HANDLE == write_handle))
            return e_ERROR_INVALID_PARAMETER;

        m_handle[e_PIPE_READ] = read_handle;
        m_handle[e_PIPE_WRITE] = write_handle;
        m_is_open = is_open;
        return error;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual eError Detach
    (HANDLE &read_handle, 
     HANDLE &write_handle, bool &is_open) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        read_handle = m_handle[e_PIPE_READ];
        write_handle = m_handle[e_PIPE_WRITE];
        is_open = m_is_open;

        if ((INVALID_HANDLE != m_handle[e_PIPE_READ])
            && (INVALID_HANDLE != m_handle[e_PIPE_WRITE]))
            error = e_ERROR_NONE;

        m_handle[e_PIPE_READ] = INVALID_HANDLE;
        m_handle[e_PIPE_WRITE] = INVALID_HANDLE;
        m_is_open = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetReadHandle
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual HANDLE SetReadHandle(HANDLE handle) 
    {
        m_handle[e_PIPE_READ] = handle;
        return m_handle[e_PIPE_READ];
    }
    /**
     **********************************************************************
     * Function: GetReadHandle
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual HANDLE GetReadHandle() const
    {
        return m_handle[e_PIPE_READ];
    }

    /**
     **********************************************************************
     * Function: SetWriteHandle
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual HANDLE SetWriteHandle(HANDLE handle) 
    {
        m_handle[e_PIPE_WRITE] = handle;
        return m_handle[e_PIPE_WRITE];
    }
    /**
     **********************************************************************
     * Function: GetWriteHandle
     *
     *   Author: $author$
     *     Date: 10/30/2004
     **********************************************************************
     */
    virtual HANDLE GetWriteHandle() const
    {
        return m_handle[e_PIPE_WRITE];
    }
};

/**
 **********************************************************************
 *  Class: cPipe
 *
 * Author: $author$
 *   Date: 10/30/2004
 **********************************************************************
 */
class cPipe
: public cPipeT<>
{
public:
    typedef cPipeT<> cIs;

    /**
     **********************************************************************
     * Constructor: cPipe
     *
     *      Author: $author$
     *        Date: 10/30/2004
     **********************************************************************
     */
    cPipe
    (HANDLE read_handle=INVALID_HANDLE, 
     HANDLE write_handle=INVALID_HANDLE,
     bool is_open=false,
     int buffer_size=DEFAULT_PIPE_BUFFER_SIZE,
     bool is_inheritable=true) 
    : cIs
      (read_handle, write_handle, 
       is_open, buffer_size, is_inheritable)
    {
    }
};

#endif /* ndef _CPIPE_HXX */

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
 *   File: cdevicet.hxx
 *
 * Author: $author$
 *   Date: 7/18/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDEVICET_HXX
#define _CDEVICET_HXX

#if defined(WIN32)
#include <windows.h>
#include <winioctl.h>
#define DEVICE HANDLE
#define INVALID_DEVICE INVALID_HANDLE_VALUE
#else /* defined(WIN32) */
#include <sys/ioctl.h>
#include <unistd.h>
#define DEVICE int
#define INVALID_DEVICE -1
#endif /* defined(WIN32) */

#include "chandlet.hxx"
#include "cio.hxx"

#if defined(_WIN32_WCE)
#include "ctcharbuffer.hxx"
#endif /* defined(_WIN32_WCE) */

/**
 **********************************************************************
 *  Class: cDeviceT
 *
 * Author: $author$
 *   Date: 7/18/2003
 **********************************************************************
 */
template <class TOf, int VSizeof=1, class TIs=cIo>
class cDeviceT
: public cOpenedHandleT<DEVICE, (int)INVALID_DEVICE, TIs>
{
public:
    typedef cOpenedHandleT<DEVICE, (int)INVALID_DEVICE, TIs> cIs;
    typedef TOf tOf;

    /**
     **********************************************************************
     * Constructor: cDeviceT
     *
     *      Author: $author$
     *        Date: 7/18/2003
     **********************************************************************
     */
    cDeviceT(DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDeviceT
     *
     *     Author: $author$
     *       Date: 7/18/2003
     **********************************************************************
     */
    virtual ~cDeviceT()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    virtual eError Open
    (const char *path, int flags=e_O_RDWR, int mode=e_S_IRWXU)
    {
        DEVICE handle;

#if defined(WIN32)
        DWORD access=0;
        DWORD shared=0;
        PSECURITY_ATTRIBUTES security=NULL;
        DWORD creation=OPEN_EXISTING;
        DWORD attributes=0;
        HANDLE templatefile=NULL;

        if (0 != (flags & (e_O_RDWR | e_O_RDONLY)))
            access |= GENERIC_READ;

        if (0 != (flags & (e_O_RDWR | e_O_WRONLY)))
            access |= GENERIC_WRITE;

        if (0 == (flags & e_O_EXCL))
            shared |= (FILE_SHARE_READ | FILE_SHARE_WRITE);

#if defined(_WIN32_WCE)
		{
			cTCHARBuffer tbuffer(path);
			const TCHAR* tpath = tbuffer.GetBuffer();

        if (INVALID_DEVICE == (handle = CreateFile
            (tpath, access, shared, security, 
             creation, attributes, templatefile)))
            return e_ERROR_OPEN;
		}
#else /* defined(WIN32) */
        if (INVALID_DEVICE == (handle = CreateFile
            (path, access, shared, security, 
             creation, attributes, templatefile)))
            return e_ERROR_OPEN;
#endif /* defined(_WIN32_WCE) */

#else /* defined(WIN32) */
        eError error;

        if ((error = FlagsToPlatform(flags, flags)))
            return e_ERROR_INVALID_OPTION;

        if ((error = ModesToPlatform(mode, mode)))
            return e_ERROR_INVALID_MODE;

        if ((handle = open(path, flags, mode)) < 0)
            return e_ERROR_OPEN;
#endif /* defined(WIN32) */

        m_handle = handle;
        m_opened = true;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        if (INVALID_DEVICE == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        if (!CloseHandle(m_handle))
            return e_ERROR_CLOSE;
#else /* defined(WIN32) */
        int err;

        if ((err = close(m_handle)))
            return e_ERROR_CLOSE;
#endif /* defined(WIN32) */

        m_opened = false;
        m_handle = INVALID_DEVICE;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/21/2003
     **********************************************************************
     */
    virtual int Read(TOf *buffer, int size)
    {
        int count=0;
#if defined(WIN32)
        DWORD read;
#endif /* defined(WIN32) */

        if (size < 0)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        if (ReadFile(m_handle, buffer, VSizeof*size, &read, NULL))
            count = read;
#else /* defined(WIN32) */
        if (0 > (count = read
            (m_handle, buffer, VSizeof*size)))
            return -e_ERROR_READ;
#endif /* defined(WIN32) */

        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/21/2003
     **********************************************************************
     */
    virtual int Write(const TOf *buffer, int size=-1)
    {
        int count=0;
#if defined(WIN32)
        DWORD written;
#endif /* defined(WIN32) */

        if (size < 0)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;
        
#if defined(WIN32)
        if (WriteFile(m_handle, buffer, VSizeof*size, &written, NULL))
            count = written;
#else /* defined(WIN32) */
        if (0 > (count = write
            (m_handle, buffer, VSizeof*size)))
            return -e_ERROR_WRITE;
#endif /* defined(WIN32) */
        
        return count;
    }
    /**
     **********************************************************************
     * Function: Flush
     *
     * Author: $author$
     * Date:   9/13/2005
     **********************************************************************
     */
    virtual int Flush()
    {
        int count = 0;
        
        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;
        
#if defined(WIN32)
        if (!FlushFileBuffers(m_handle))
            count = -e_ERROR_FAILED;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return count;
    }

    /**
     **********************************************************************
     * Function: Ioctl
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    virtual int Ioctl
    (int cmd, void *arg, int argsize, int retsize=-1) const
    {
        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        DWORD bytes_returned;
        LPOVERLAPPED overlapped=NULL;

        if ((0 >= argsize) && (0 >= retsize))
            return e_ERROR_IOCTL_PARAMETER_SIZE;

        if (0 > retsize)
            retsize = argsize;

        if (!DeviceIoControl
            (m_handle, cmd, arg, argsize, 
             arg, retsize, &bytes_returned, overlapped))
             return e_ERROR_IOCTL;

        if ((DWORD)retsize != bytes_returned)
            return e_ERROR_IOCTL_RETURN_SIZE;

        return e_ERROR_NONE;
#else
        return ioctl(m_handle, cmd, arg);
#endif
    }
    /**
     **********************************************************************
     * Function: Ioctl
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    virtual int Ioctl(int cmd) const
    {
        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        return Ioctl(cmd, NULL, 0);
#else
        return ioctl(m_handle, cmd);
#endif
    }
};

#endif /* ndef _CDEVICET_HXX */

/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: device.hxx
 * 
 * author: $author$
 *   date: 3/18/2003
 *
 * This file provides a class wrapper for file descriptor
 * based devices like those in Unix.
 ************************************************************
 */
#ifndef _DEVICE_HXX
#define _DEVICE_HXX

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

/*
 ************************************************************
 *
 *  class: DeviceBase
 * 
 * author: $author$
 *   date: 3/18/2003
 *
 ************************************************************
 */
class DeviceBase
{
};

#include "handle.hxx"
#include "error.hxx"

/*
 ************************************************************
 *
 *  class: DeviceT
 * 
 * author: $author$
 *   date: 3/18/2003
 *
 ************************************************************
 */
template <class TIs=DeviceBase>
class DeviceT: public OpenedHandleT<int, -1, int, 0, TIs>
{
public:
    typedef OpenedHandleT<int, -1, int, 0, TIs> Is;
    
    /*
     ************************************************************
     *
     * function: DeviceT
     * 
     *   author: $author$
     *     date: 3/18/2003
     *
     ************************************************************
     */
    DeviceT(int fd=-1)
    : Is(fd)
    {
    }
    /*
     ************************************************************
     *
     * function: Open
     * 
     *   author: $author$
     *     date: 3/18/2003
     *
     ************************************************************
     */
    virtual int Open
    (const char *pathname, 
     int flags=O_RDONLY, 
     mode_t mode=S_IROTH| S_IRGRP| S_IRUSR| S_IWUSR)
    {
        int fd;
        
        if (m_handle >=0 )
            return -1;
            
        if ((fd = open(pathname, flags, mode)) < 0)
            return fd;
            
        m_handle=fd;
        return 0;
    }
    /*
     ************************************************************
     *
     * function: Close
     * 
     *   author: $author$
     *     date: 3/18/2003
     *
     ************************************************************
     */
    virtual int Close(void)
    {
        int err;
        
        if (m_handle < 0)
            return -1;
            
        err=close(m_handle);
        m_handle=-1;
        return err;
    }
    /*
     ************************************************************
     *
     * function: Ioctl
     * 
     *   author: $author$
     *     date: 3/18/2003
     *
     ************************************************************
     */
    virtual int Ioctl(int cmd, void *arg) const
    {
        int err;
        
        if (m_handle < 0)
            return -1;
            
        return ioctl(m_handle, cmd, arg);
    }
    /*
     ************************************************************
     *
     * function: Ioctl
     * 
     *   author: $author$
     *     date: 3/18/2003
     *
     ************************************************************
     */
    virtual int Ioctl(int cmd) const
    {
        int err;
        
        if (m_handle < 0)
            return -1;
            
        return ioctl(m_handle, cmd);
    }
};

/*
 ************************************************************
 *
 *  class: Device
 * 
 * author: $author$
 *   date: 3/18/2003
 *
 ************************************************************
 */
class Device: public DeviceT<DeviceBase>
{
public:
    typedef DeviceT<DeviceBase> Is;
    
    /*
     ************************************************************
     *
     * function: Device
     * 
     *   author: $author$
     *     date: 3/18/2003
     *
     ************************************************************
     */
    Device(int fd=-1)
    : Is(fd)
    {
    }
};

#endif

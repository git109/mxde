/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cdevice.hxx
 *
 * Author: $author$
 *   Date: 8/6/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDEVICE_HXX
#define _CDEVICE_HXX

#include "cdevicet.hxx"
#include "ccharstream.hxx"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cDevice
 *
 * Author: $author$
 *   Date: 8/6/2005
 **********************************************************************
 */
class cDevice
: public cDeviceT<void>
{
public:
    typedef cDeviceT<void> cIs;

    /**
     **********************************************************************
     * Constructor: cDevice
     *
     *      Author: $author$
     *        Date: 8/6/2005
     **********************************************************************
     */
    cDevice(DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cCharDevice
 *
 * Author: $author$
 *   Date: 9/10/2005
 **********************************************************************
 */
class cCharDevice
: public cDeviceT<char, 1, cCharStream>
{
public:
    typedef cDeviceT<char, 1, cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharDevice
     *
     *      Author: $author$
     *        Date: 9/10/2005
     **********************************************************************
     */
    cCharDevice(DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 9/10/2003
     **********************************************************************
     */
    virtual int Write(const tOf *buffer, int size=-1)
    {
        int length;

        if (0 > size)
            for (size=0; buffer[size]; size++);

        length = cIs::Write(buffer, size);
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cBYTEDevice
 *
 * Author: $author$
 *   Date: 9/13/2005
 **********************************************************************
 */
class cBYTEDevice
: public cDeviceT<BYTE, 1, cBYTEStream>
{
public:
    typedef cDeviceT<BYTE, 1, cBYTEStream> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEDevice
     *
     *      Author: $author$
     *        Date: 9/13/2005
     **********************************************************************
     */
    cBYTEDevice(DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Function: WaitRead
     *
     *   Author: $author$
     *     Date: 9/16/2005
     **********************************************************************
     */
    virtual int xWaitRead
    (tOf *buffer, int size, DWORD miliseconds=0)
    {
        int count,length = 0;
        DWORD t1,t2;

        if (0 < miliseconds)
            t1 = GetTickCount();

        while(0 < size)
        {
            if (0 < (count = cIs::Read(buffer, size)))
            {
                buffer += count;
                length += count;
                size -= count;
            }
            else if (0 > count)
            {
                if (length)
                    return length;
                else return count;
            }
            else if (0 < miliseconds)
            {
                t2 = GetTickCount();

                if (t2 < t1)
                {
                    if (t1-t2 >= miliseconds)
                        return -e_ERROR_WAIT_TIMEOUT;
                }
                else if (t2-t1 >= miliseconds)
                        return -e_ERROR_WAIT_TIMEOUT;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 9/13/2003
     **********************************************************************
     */
    virtual int Write(const tOf *buffer, int size=-1)
    {
        int length;

        if (0 > size)
            for (size=0; buffer[size]; size++);

        length = cIs::Write(buffer, size);
        return length;
    }
};

#endif /* _CDEVICE_HXX */

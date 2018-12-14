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
 *   File: mydevice.hxx
 *
 * Author: $author$
 *   Date: 8/1/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _MYDEVICE_HXX
#define _MYDEVICE_HXX

#include "mydriver.h"
#include "device.hxx"

/**
 **********************************************************************
 *  Class: MyDevice
 *
 * Author: $author$
 *   Date: 8/1/2005
 **********************************************************************
 */
class MyDevice
: public Device
{
public:
    typedef Device cIs;

    /**
     **********************************************************************
     * Function: SendRequest
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    int SendRequest(mydriver_request_t& request) 
    {
        int err = Ioctl(MYDRIVER_IOCTL_SEND_REQUEST, &request);
        return err;
    }
    /**
     **********************************************************************
     * Function: ReceiveRequest
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    int ReceiveRequest(mydriver_request_t& request) 
    {
        int err;
        
        if (!(err = Ioctl(MYDRIVER_IOCTL_RECEIVE_REQUEST, &request)))
            err = Ioctl(MYDRIVER_IOCTL_SERVICE_REQUEST, &request);

        return err;
    }
    /**
     **********************************************************************
     * Function: ResetModule
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    int ResetModule(void) 
    {
        int err = Ioctl(MYDRIVER_IOCTL_RESETMOD);
        return err;
    }
};

#endif /* _MYDEVICE_HXX */

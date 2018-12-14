/**
 **********************************************************************
 * Copyright (c) $author$ 1988-2005
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
 *   File: cmydisk.hxx
 *
 * Author: $author$
 *   Date: 8/6/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMYDISK_HXX
#define _CMYDISK_HXX

#include "mydisk.h"
#include "cdevice.hxx"

/**
 **********************************************************************
 *  Class: cMydisk
 *
 * Author: $author$
 *   Date: 8/6/2005
 **********************************************************************
 */
class cMydisk
: public cDevice
{
public:
    typedef cDevice cIs;

    /**
     **********************************************************************
     * Function: ResetModule
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    int ResetModule(void) 
    {
        int err = Ioctl(MYDISK_IOCTL_RESETMOD);
        return err;
    }

    /**
     **********************************************************************
     * Function: SendRequest
     *
     *   Author: $author$
     *     Date: 8/8/2005
     **********************************************************************
     */
    int SendRequest(mydisk_request_t& request) 
    {
        int err = Ioctl
        (MYDISK_IOCTL_SEND_REQUEST, 
         &request, sizeof(mydisk_request_t));
        return err;
    }
    /**
     **********************************************************************
     * Function: ReceiveRequest
     *
     *   Author: $author$
     *     Date: 8/8/2005
     **********************************************************************
     */
    int ReceiveRequest(mydisk_request_t& request) 
    {
        int err = Ioctl
        (MYDISK_IOCTL_RECEIVE_REQUEST, 
         &request, sizeof(mydisk_request_t));
        return err;
    }
    /**
     **********************************************************************
     * Function: ServiceRequest
     *
     *   Author: $author$
     *     Date: 8/8/2005
     **********************************************************************
     */
    int ServiceRequest(mydisk_request_t& request) 
    {
        int err = Ioctl
        (MYDISK_IOCTL_SERVICE_REQUEST, 
         &request, sizeof(mydisk_request_t));
        return err;
    }
};

#endif /* _CMYDISK_HXX */

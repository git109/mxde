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
 *   File: cssltime.hxx
 *
 * Author: $author$
 *   Date: 1/19/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLTIME_HXX
#define _CSSLTIME_HXX

#include <stdlib.h>
#include <time.h>
#include "platform.h"

/**
 **********************************************************************
 *  Class: cSSLTime
 *
 * Author: $author$
 *   Date: 1/19/2005
 **********************************************************************
 */
class cSSLTime
{
public:
    /**
     **********************************************************************
     * Function: GetGMTUnixTime
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    virtual uint32 GetGMTUnixTime() 
    {
        time_t t;
        uint32 gmt = time(&t);
        return gmt;
    }
};

#endif /* _CSSLTIME_HXX */
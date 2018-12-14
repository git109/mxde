/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cinetaddressinterface.hxx
 *
 * Author: $author$
 *   Date: 3/8/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CINETADDRESSINTERFACE_HXX
#define _CINETADDRESSINTERFACE_HXX

#include "platformsocket.h"
#include "cnetaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cInetAddressInterface
 *
 * Author: $author$
 *   Date: 3/8/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cInetAddressInterface
: virtual public cNetAddressInterface
{
public:
    /**
     **********************************************************************
     * Function: SetToInAddr
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetToInAddr(const IN_ADDR& in_addr) = 0;
    /**
     **********************************************************************
     * Function: SetToInAddrAny
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetToInAddrAny() = 0;
    /**
     **********************************************************************
     * Function: GetInAddr
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual const IN_ADDR& GetInAddr(int& length) const = 0;
    /**
     **********************************************************************
     * Function: GetInAddrAny
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    static const IN_ADDR& GetInAddrAny(int& length);
};

/**
 **********************************************************************
 *  Class: cInetAddressImplement
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cInetAddressImplement
: virtual public cInetAddressInterface
{
public:
    /**
     **********************************************************************
     * Function: SetToInAddr
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetToInAddr(const IN_ADDR& in_addr) 
    {
        int length = e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetToInAddrAny
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetToInAddrAny() 
    {
        int length = e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetInAddr
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual const IN_ADDR& GetInAddr(int& length) const 
    {
        const IN_ADDR& addr = GetInAddrAny(length);
        return addr;
    }
};

#endif /* _CINETADDRESSINTERFACE_HXX */

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
 *   File: cnetaddressinterface.hxx
 *
 * Author: $author$
 *   Date: 3/8/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CNETADDRESSINTERFACE_HXX
#define _CNETADDRESSINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cNetAddressInterface
 *
 * Author: $author$
 *   Date: 3/8/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cNetAddressInterface
: virtual public cInterfaceBase
{
public:
    /**
     **********************************************************************
     * Function: SetByHostName
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetByHostName
    (const char* hostname, int interfaceno=-1) = 0;
    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 3/8/2006
     **********************************************************************
     */
    virtual const BYTE& GetAddress(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetNullAddress
     *
     *   Author: $author$
     *     Date: 3/8/2006
     **********************************************************************
     */
    static const BYTE& GetNullAddress(int &length);
};

/**
 **********************************************************************
 *  Class: cNetAddressImplement
 *
 * Author: $author$
 *   Date: 3/8/2006
 **********************************************************************
 */
class cNetAddressImplement
: virtual public cNetAddressInterface
{
public:
    /**
     **********************************************************************
     * Function: SetByHostName
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetByHostName
    (const char* hostname, int interfaceno=-1) 
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 3/8/2006
     **********************************************************************
     */
    virtual const BYTE& GetAddress(int &length) const 
    {
        const BYTE& addr = GetNullAddress(length);
        length = -e_ERROR_NOT_IMPLEMENTED;
        return addr;
    }
};

#endif /* _CNETADDRESSINTERFACE_HXX */

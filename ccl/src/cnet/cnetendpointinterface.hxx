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
 *   File: cnetendpointinterface.hxx
 *
 * Author: $author$
 *   Date: 3/19/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CNETENDPOINTINTERFACE_HXX
#define _CNETENDPOINTINTERFACE_HXX

#include "cnetaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cNetEndpointInterface
 *
 * Author: $author$
 *   Date: 3/19/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cNetEndpointInterface
: virtual public cInterfaceBase
{
public:
    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Bind() = 0;
    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Listen() = 0;
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Connect() = 0;
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Accept(cNetEndpointInterface& endpoint) = 0;

    /**
     **********************************************************************
     * Function: SetNetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual int SetNetAddress
    (const cNetAddressInterface& address) = 0;
    /**
     **********************************************************************
     * Function: GetNetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual const cNetAddressInterface& 
    GetNetAddress(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetNetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    static const cNetAddressInterface& 
    GetNullNetAddress(int &length);
};

/**
 **********************************************************************
 *  Class: cNetEndpointImplement
 *
 * Author: $author$
 *   Date: 3/19/2006
 **********************************************************************
 */
class cNetEndpointImplement
: virtual public cNetEndpointInterface
{
public:
    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Bind() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Listen() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Connect() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 3/29/2006
     **********************************************************************
     */
    virtual eError Accept(cNetEndpointInterface& endpoint) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetNetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual int SetNetAddress
    (const cNetAddressInterface& address) 
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual const cNetAddressInterface& 
    GetNetAddress(int &length) const
    {
        const cNetAddressInterface& 
        m_address = GetNullNetAddress(length);
        return m_address;
    }
};

#endif /* _CNETENDPOINTINTERFACE_HXX */

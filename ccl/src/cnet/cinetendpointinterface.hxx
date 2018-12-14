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
 *   File: cinetendpointinterface.hxx
 *
 * Author: $author$
 *   Date: 3/19/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CINETENDPOINTINTERFACE_HXX
#define _CINETENDPOINTINTERFACE_HXX

#include "cnetendpointinterface.hxx"
#include "cinetaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cInetEndpointInterface
 *
 * Author: $author$
 *   Date: 3/19/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cInetEndpointInterface
: virtual public cNetEndpointInterface
{
public:
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 3/30/2006
     **********************************************************************
     */
    virtual eError Accept
    (cInetEndpointInterface& endpoint) = 0;

    /**
     **********************************************************************
     * Function: SetInetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual int SetInetAddress
    (const cInetAddressInterface& address) = 0;
    /**
     **********************************************************************
     * Function: GetInetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual const cInetAddressInterface& 
    GetInetAddress(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetInetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    static const cInetAddressInterface& 
    GetNullInetAddress(int &length);
};

/**
 **********************************************************************
 *  Class: cInetEndpointImplement
 *
 * Author: $author$
 *   Date: 3/19/2006
 **********************************************************************
 */
class cInetEndpointImplement
: virtual public cInetEndpointInterface
{
public:
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 3/30/2006
     **********************************************************************
     */
    virtual eError Accept
    (cInetEndpointInterface& endpoint) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetInetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual int SetInetAddress
    (const cInetAddressInterface& address) 
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetInetAddress
     *
     *   Author: $author$
     *     Date: 3/19/2006
     **********************************************************************
     */
    virtual const cInetAddressInterface& 
    GetInetAddress(int &length) const 
    {
        const cInetAddressInterface& m_address = GetNullInetAddress(length);
        return m_address;
    }
};

#endif /* _CINETENDPOINTINTERFACE_HXX */

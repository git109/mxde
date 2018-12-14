/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cinetaddressinterface.hxx
 *
 * Author: $author$
 *   Date: 10/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETADDRESSINTERFACE_HXX
#define _CINETADDRESSINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cInetAddressInterfaceT
 *
 * Author: $author$
 *   Date: 10/12/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cInetAddressInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetByName
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetByName(const char *name) = 0;
    /**
     **********************************************************************
     * Function: SetByInAddr
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& SetByInAddr(IN_ADDR& in_addr) = 0;
    /**
     **********************************************************************
     * Function: SetByInAddrAny
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& SetByInAddrAny() = 0;
    /**
     **********************************************************************
     * Function: GetInAddr
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& GetInAddr() = 0;
    /**
     **********************************************************************
     * Function: GetInAddrAny
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& GetInAddrAny() = 0;
    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetAddress() const = 0;
    /**
     **********************************************************************
     * Function: GetNullAddress
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetNullAddress() const = 0;
};

/**
 **********************************************************************
 *  Class: cInetAddressInterface
 *
 * Author: $author$
 *   Date: 10/13/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cInetAddressInterface
: virtual public cInetAddressInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cInetAddressImplementT
 *
 * Author: $author$
 *   Date: 10/12/2004
 **********************************************************************
 */
template <class TIs=cInetAddressInterface>
class cInetAddressImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetByName
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetByName(const char *name) 
    {
        const unsigned char& addr = GetNullAddress();
        return addr;
    }
    /**
     **********************************************************************
     * Function: SetByInAddr
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& SetByInAddr(IN_ADDR& in_addr) 
    {
        IN_ADDR& in_addr_any = GetInAddrAny();
        return in_addr_any;
    }
    /**
     **********************************************************************
     * Function: SetByInAddrAny
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& SetByInAddrAny() 
    {
        IN_ADDR& in_addr = GetInAddrAny();
        return in_addr;
    }
    /**
     **********************************************************************
     * Function: GetInAddr
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& GetInAddr() 
    {
        IN_ADDR& in_addr = GetInAddrAny();
        return in_addr;
    }
    /**
     **********************************************************************
     * Function: GetInAddrAny
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& GetInAddrAny() 
    {
        static IN_ADDR in_addr = {INADDR_ANY};
        return in_addr;
    }
    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetAddress() const
    {
        const unsigned char& addr = GetNullAddress();
        return addr;
    }
    /**
     **********************************************************************
     * Function: GetNullAddress
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetNullAddress() const
    {
        static const unsigned char addr[8] = {0,0,0,0,0,0,0,0};
        return addr[0];
    }
};

/**
 **********************************************************************
 *  Class: cInetAddressImplement
 *
 * Author: $author$
 *   Date: 10/13/2004
 **********************************************************************
 */
class cInetAddressImplement
: virtual public cInetAddressImplementT<>
{
public:
};

#endif /* ndef _CINETADDRESSINTERFACE_HXX */

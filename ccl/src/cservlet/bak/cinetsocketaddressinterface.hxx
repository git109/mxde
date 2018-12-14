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
 *   File: cinetsocketaddressinterface.hxx
 *
 * Author: $author$
 *   Date: 10/18/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETSOCKETADDRESSINTERFACE_HXX
#define _CINETSOCKETADDRESSINTERFACE_HXX

#include "csocketaddressinterface.hxx"
#include "cinetaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cInetSocketAddressInterfaceT
 *
 * Author: $author$
 *   Date: 10/18/2004
 **********************************************************************
 */
template <class TIs=cSocketAddressInterface>
class c_INTERFACE_CLASS cInetSocketAddressInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual unsigned char& Set
    (cInetAddressInterface &address, const char *host, int port) = 0;
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual unsigned char& Set
    (cInetAddressInterface &address, int port) = 0;
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual unsigned char& Set(int port=0) = 0;

    /**
     **********************************************************************
     * Function: GetSockAddrIn
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual SOCKADDR_IN& GetSockAddrIn() = 0;
};

/**
 **********************************************************************
 *  Class: cInetSocketAddressInterface
 *
 * Author: $author$
 *   Date: 10/18/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cInetSocketAddressInterface
: virtual public cInetSocketAddressInterfaceT<>
{
public:
};

#endif /* ndef _CINETSOCKETADDRESSINTERFACE_HXX */

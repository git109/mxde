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
 *   File: csocketaddressinterface.hxx
 *
 * Author: $author$
 *   Date: 10/18/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSOCKETADDRESSINTERFACE_HXX
#define _CSOCKETADDRESSINTERFACE_HXX

#include "platformsocket.h"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cSocketAddressInterfaceT
 *
 * Author: $author$
 *   Date: 10/18/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cSocketAddressInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetSockAddr
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual SOCKADDR &GetSockAddr() = 0;
};

/**
 **********************************************************************
 *  Class: cSocketAddressInterface
 *
 * Author: $author$
 *   Date: 10/18/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cSocketAddressInterface
: virtual public cSocketAddressInterfaceT<>
{
public:
};

#endif /* ndef _CSOCKETADDRESSINTERFACE_HXX */

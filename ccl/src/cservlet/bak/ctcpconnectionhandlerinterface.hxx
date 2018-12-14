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
 *   File: ctcpconnectionhandlerinterface.hxx
 *
 * Author: $author$
 *   Date: 10/19/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPCONNECTIONHANDLERINTERFACE_HXX
#define _CTCPCONNECTIONHANDLERINTERFACE_HXX

#include "cinetsocketinterface.hxx"

/**
 **********************************************************************
 *  Class: cTcpConnectionHandlerInterfaceT
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cTcpConnectionHandlerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cInetSocketInterface &socket) = 0;
};

/**
 **********************************************************************
 *  Class: cTcpConnectionHandlerInterface
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cTcpConnectionHandlerInterface
: virtual public cTcpConnectionHandlerInterfaceT<>
{
public:
};

#endif /* ndef _CTCPCONNECTIONHANDLERINTERFACE_HXX */

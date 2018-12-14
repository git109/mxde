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
 *   File: ctcpconnectioninterface.hxx
 *
 * Author: $author$
 *   Date: 8/21/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPCONNECTIONINTERFACE_HXX
#define _CTCPCONNECTIONINTERFACE_HXX

#include "cconnectioninterface.hxx"
#include "cinetsocketinterface.hxx"

/**
 **********************************************************************
 *  Class: cTcpConnectionInterfaceT
 *
 * Author: $author$
 *   Date: 8/21/2005
 **********************************************************************
 */
template 
<class TIs=cConnectionInterface>

class c_INTERFACE_CLASS cTcpConnectionInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetSocket
     *
     *   Author: $author$
     *     Date: 8/21/2005
     **********************************************************************
     */
    virtual cInetSocketInterface& GetSocket() const = 0;
};

/**
 **********************************************************************
 *  Class: cTcpConnectionInterface
 *
 * Author: $author$
 *   Date: 8/21/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cTcpConnectionInterface
: public cTcpConnectionInterfaceT<>
{
public:
    typedef cTcpConnectionInterfaceT<> cIs;
};

#endif /* _CTCPCONNECTIONINTERFACE_HXX */

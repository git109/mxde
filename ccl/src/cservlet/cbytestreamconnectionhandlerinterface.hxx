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
 *   File: cbytestreamconnectionhandlerinterface.hxx
 *
 * Author: $author$
 *   Date: 9/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMCONNECTIONHANDLERINTERFACE_HXX
#define _CBYTESTREAMCONNECTIONHANDLERINTERFACE_HXX

#include "cbytestreamconnectioninterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandlerInterfaceT
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
template
<class TIs=cInterface>
class c_INTERFACE_CLASS cBYTEStreamConnectionHandlerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 8/21/2005
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cBYTEStreamConnectionInterface &connection) = 0;
    /**
     **********************************************************************
     * Function: ProcessConnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessConnect
    (cBYTEStreamConnectionInterface &connection) = 0;
    /**
     **********************************************************************
     * Function: ProcessDisconnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnect
    (cBYTEStreamConnectionInterface &connection) = 0;

    /**
     **********************************************************************
     * Function: ProcessConnectionStream
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError ProcessConnectionStream
    (cBYTEStreamInterface &stream) = 0;
    /**
     **********************************************************************
     * Function: ProcessConnectStream
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessConnectStream
    (cBYTEStreamInterface &stream) = 0;
    /**
     **********************************************************************
     * Function: ProcessDisconnectStream
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnectStream
    (cBYTEStreamInterface &stream) = 0;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandlerInterface
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamConnectionHandlerInterface
: virtual public cBYTEStreamConnectionHandlerInterfaceT<>
{
public:
    typedef cBYTEStreamConnectionHandlerInterfaceT<> cIs;
};

#endif /* _CBYTESTREAMCONNECTIONHANDLERINTERFACE_HXX */

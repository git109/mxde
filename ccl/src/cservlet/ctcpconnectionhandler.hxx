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
 *   File: ctcpconnectionhandler.hxx
 *
 * Author: $author$
 *   Date: 8/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPCONNECTIONHANDLER_HXX
#define _CTCPCONNECTIONHANDLER_HXX

#include "ctcpconnectionhandlerinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cTcpConnectionHandlerImplementT
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
template
<class TInterfaceIs=cTcpConnectionHandlerInterface>
class cTcpConnectionHandlerImplementT
: virtual public TInterfaceIs
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
    (cTcpConnectionInterface &connection)
    {
        cInetSocketInterface &socket = connection.GetSocket();
        eError error = ProcessConnectionSocket(socket);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessConnect
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessConnect
    (cTcpConnectionInterface &connection)
    {
        cInetSocketInterface &socket = connection.GetSocket();
        eError error = ProcessConnectSocket(socket);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessDisconnect
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnect
    (cTcpConnectionInterface &connection)
    {
        cInetSocketInterface &socket = connection.GetSocket();
        eError error = ProcessDisconnectSocket(socket);
        return error;
    }

    /**
     **********************************************************************
     * Function: ProcessConnectionSocket
     *
     *   Author: $author$
     *     Date: 8/15/2005
     **********************************************************************
     */
    virtual eError ProcessConnectionSocket
    (cInetSocketInterface &socket) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessConnectSocket
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessConnectSocket
    (cInetSocketInterface &socket) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessDisconnectSocket
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnectSocket
    (cInetSocketInterface &socket) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cTcpConnectionHandlerImplement
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
class cTcpConnectionHandlerImplement
: virtual public cTcpConnectionHandlerImplementT<>
{
public:
    typedef cTcpConnectionHandlerImplementT<> cIs;
};

/**
 **********************************************************************
 *  Class: cTcpConnectionHandlerT
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
template
<class TIs=cInstance>
class cTcpConnectionHandlerT
: virtual public cTcpConnectionHandlerImplement,
  public TIs
{
public:
    typedef TIs cIs;
};

/**
 **********************************************************************
 *  Class: cTcpConnectionHandler
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
class cTcpConnectionHandler
: public cTcpConnectionHandlerT<>
{
public:
    typedef cTcpConnectionHandlerT<> cIs;
};

/**
 **********************************************************************
 *  Class: cTcpConnectionHandlerProxy
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
class cTcpConnectionHandlerProxy
: public cTcpConnectionHandler
{
public:
    typedef cTcpConnectionHandler cIs;

    cTcpConnectionHandlerInterface& m_connection_handler;

    /**
     **********************************************************************
     * Constructor: cTcpConnectionHandlerProxy
     *
     *      Author: $author$
     *        Date: 8/15/2005
     **********************************************************************
     */
    cTcpConnectionHandlerProxy
    (cTcpConnectionHandlerInterface& connection_handler) 
    : m_connection_handler(connection_handler)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 8/15/2005
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cTcpConnectionInterface &connection) 
    {
        eError error = m_connection_handler
        .ProcessConnection(connection);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessConnect
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessConnect
    (cTcpConnectionInterface &connection) 
    {
        eError error = m_connection_handler
        .ProcessConnect(connection);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessDisconnect
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnect
    (cTcpConnectionInterface &connection) 
    {
        eError error = m_connection_handler
        .ProcessDisconnect(connection);
        return error;
    }
};

#endif /* _CTCPCONNECTIONHANDLER_HXX */

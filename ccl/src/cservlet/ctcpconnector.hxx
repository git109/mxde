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
 *   File: ctcpconnector.hxx
 *
 * Author: $author$
 *   Date: 8/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPCONNECTOR_HXX
#define _CTCPCONNECTOR_HXX

#include "ctcpendpoint.hxx"
#include "ctcplistener.hxx"
#include "ctcpconnectionhandler.hxx"

/**
 **********************************************************************
 *  Class: cTcpConnector
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
class cTcpConnector
: public cTcpConnectionHandler
{
public:
    typedef cTcpConnectionHandler cIs;

    const char *m_host;
    cInetAddress m_host_address;
    cTcpEndpoint m_tcp_endpoint;
    cTcpConnectionHandlerProxy m_tcp_connection_handler;
    cTcpListener m_tcp_listener;

    /**
     **********************************************************************
     * Constructor: cTcpConnector
     *
     *      Author: $author$
     *        Date: 8/15/2005
     **********************************************************************
     */
    cTcpConnector
    (int port=80, const char *host="localhost") 
    : m_host(host),
      m_tcp_endpoint(port),
      m_tcp_connection_handler(*this),
      m_tcp_listener
      (m_tcp_endpoint, m_tcp_connection_handler) 
    {
    }
    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 8/15/2005
     **********************************************************************
     */
    virtual eError Listen(void) 
    {
        eError error = e_ERROR_NONE;

        m_host_address.GetByName(m_host);
        m_tcp_endpoint.SetAddress(m_host_address);
        m_tcp_endpoint.SetListener(&m_tcp_listener);

        if (!(error = m_tcp_endpoint.InitEndpoint()))
        {
            if (!(error = m_tcp_endpoint.StartEndpoint()))
            {
                m_tcp_endpoint.FinishEndpoint();
            }
            m_tcp_endpoint.FinalEndpoint();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 8/15/2005
     **********************************************************************
     */
    virtual eError Connect(void) 
    {
        eError error = e_ERROR_NONE;

        m_host_address.GetByName(m_host);
        m_tcp_endpoint.SetAddress(m_host_address);
        m_tcp_endpoint.SetConnectionHandler(&m_tcp_connection_handler);

        if (!(error = m_tcp_endpoint.InitEndpoint()))
        {
            if ((error = m_tcp_endpoint.ConnectEndpoint()))
                m_tcp_endpoint.FinalEndpoint();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Disconnect
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError Disconnect(void) 
    {
        eError error2, error = e_ERROR_NONE;

        error = m_tcp_endpoint.DisconnectEndpoint();

        if ((error2 = m_tcp_endpoint.FinalEndpoint()))
        if (!error)
            error = error2;

        return error;
    }
    /**
     **********************************************************************
     * Function: SetHost
     *
     *   Author: $author$
     *     Date: 8/30/2005
     **********************************************************************
     */
    virtual const char *SetHost(const char *host) 
    {
        m_host = host;
        return host;
    }
    /**
     **********************************************************************
     * Function: SetPort
     *
     *   Author: $author$
     *     Date: 8/30/2005
     **********************************************************************
     */
    virtual int SetPort(int port) 
    {
        port = m_tcp_endpoint.SetPort(port);
        return port;
    }
};

/**
 **********************************************************************
 *  Class: cTcpConnectorProxy
 *
 * Author: $author$
 *   Date: 8/16/2005
 **********************************************************************
 */
class cTcpConnectorProxy
: public cTcpConnector
{
public:
    typedef cTcpConnector cIs;

    cTcpConnectionHandlerInterface &m_tcp_connection_handler;

    /**
     **********************************************************************
     * Constructor: cTcpConnectorProxy
     *
     *      Author: $author$
     *        Date: 8/16/2005
     **********************************************************************
     */
    cTcpConnectorProxy
    (cTcpConnectionHandlerInterface &tcp_connection_handler,
     int port=80, const char *host="localhost") 
    : cIs(port, host),
      m_tcp_connection_handler(tcp_connection_handler) 
    {
    }
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 8/16/2005
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cTcpConnectionInterface &connection) 
    {
        eError error = m_tcp_connection_handler
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
        eError error = m_tcp_connection_handler
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
        eError error = m_tcp_connection_handler
        .ProcessDisconnect(connection);
        return error;
    }
};

#endif /* _CTCPCONNECTOR_HXX */

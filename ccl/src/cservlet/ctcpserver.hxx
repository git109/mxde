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
 *   File: ctcpserver.hxx
 *
 * Author: $author$
 *   Date: 8/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPSERVER_HXX
#define _CTCPSERVER_HXX

#include "ctcpendpoint.hxx"
#include "ctcplistener.hxx"
#include "ctcpconnector.hxx"

/**
 **********************************************************************
 *  Class: cTcpServer
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
class cTcpServer
: public cTcpConnector
{
public:
    typedef cTcpConnector cIs;

    /**
     **********************************************************************
     * Constructor: cTcpServer
     *
     *      Author: $author$
     *        Date: 8/15/2005
     **********************************************************************
     */
    cTcpServer
    (int port=80, const char *host="localhost") 
    : cIs(port, host)
    {
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 8/15/2005
     **********************************************************************
     */
    virtual eError Run(void) 
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
};

/**
 **********************************************************************
 *  Class: cTcpServerProxy
 *
 * Author: $author$
 *   Date: 8/15/2005
 **********************************************************************
 */
class cTcpServerProxy
: public cTcpServer
{
public:
    typedef cTcpServer cIs;

    cTcpConnectionHandlerInterface &m_tcp_connection_handler;

    /**
     **********************************************************************
     * Constructor: cTcpServerProxy
     *
     *      Author: $author$
     *        Date: 8/15/2005
     **********************************************************************
     */
    cTcpServerProxy
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
     *     Date: 8/15/2005
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cInetSocketInterface &socket) 
    {
        eError error = m_tcp_connection_handler
        .ProcessConnection(socket);
        return error;
    }
};

#endif /* _CTCPSERVER_HXX */
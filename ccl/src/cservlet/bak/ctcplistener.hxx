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
 *   File: ctcplistener.hxx
 *
 * Author: $author$
 *   Date: 10/19/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPLISTENER_HXX
#define _CTCPLISTENER_HXX

#include "cverboseinterface.hxx"
#include "ctcpconnectionhandlerinterface.hxx"
#include "ctcplistenerinterface.hxx"
#include "ctcpendpoint.hxx"
#include "cinetsocket.hxx"

/**
 **********************************************************************
 *  Class: cTcpListenerT
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cTcpListenerInterface,
 class TIs=cTcpListenerImplement>

class cTcpListenerT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    const char *m_class;

    cTcpEndpoint &m_tcp_endpoint;
    cTcpConnectionHandlerInterface &m_connection_handler;
    cInetSocket m_socket;

    /**
     **********************************************************************
     * Constructor: cTcpListenerT
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cTcpListenerT
    (cTcpEndpoint &tcp_endpoint,
     cTcpConnectionHandlerInterface &connection_handler,
     cVerboseInterface *verbose=0,
     const char *p_class="cTcpListenerT") 
    : cIs(verbose),
      m_tcp_endpoint(tcp_endpoint),
      m_connection_handler(connection_handler),
      m_class(p_class)
    {
    }

    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Start() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Finish() 
    {
        eError error, error2;

        do
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: Accepting connection...\n", m_class);
        
            if (!(error = Accept(m_socket)))
            {
                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: ...Accepted connection\n", m_class);
        
                error = m_connection_handler
                .ProcessConnection(m_socket);

                if ((error2 = m_socket.Close()))
                if (e_ERROR_NOT_ATTACHED != error2)
                if (!error)
                    error = error2;
            }
        }
        while(!error);

        return error;
    }

    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Accept
    (cInetSocketInterface &socket) 
    {
        eError error = m_tcp_endpoint.Accept(socket);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cTcpListener
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
class cTcpListener
: public cTcpListenerT<>
{
public:
    typedef cTcpListenerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cTcpListener
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cTcpListener
    (cTcpEndpoint &tcp_endpoint,
     cTcpConnectionHandlerInterface &connection_handler,
     cVerboseInterface *verbose=0,
     const char *p_class="cTcpListener") 
    : cIs(tcp_endpoint, connection_handler, verbose, p_class) 
    {
    }
};

#endif /* ndef _CTCPLISTENER_HXX */

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
 *   File: ctcpendpoint.hxx
 *
 * Author: $author$
 *   Date: 10/19/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPENDPOINT_HXX
#define _CTCPENDPOINT_HXX

#include "cinetendpoint.hxx"
#include "ctcplistenerinterface.hxx"

/**
 **********************************************************************
 *  Class: cTcpEndpointT
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
template <class TIs=cInetEndpoint>
class cTcpEndpointT
: public TIs
{
public:
    typedef TIs cIs;

    const char *m_class;

    int m_backlog;
    bool m_tcp_no_delay;
    bool m_so_dont_linger;
    int m_so_linger;
    bool m_initialized;

    cTcpListenerInterface *m_listener;

    /**
     **********************************************************************
     * Constructor: cTcpEndpointT
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cTcpEndpointT
    (cInetAddressInterface& address, 
     int port=0, cVerboseInterface *verbose=0,
     int backlog=DEFAULT_SOCKET_BACKLOG,
     bool tcp_no_delay=true, bool so_dont_linger=true,
     int so_linger=0, const char *p_class="cTcpEndpointT") 
    : cIs(address, port, verbose),
      m_backlog(backlog),
      m_tcp_no_delay(tcp_no_delay),
      m_so_dont_linger(so_dont_linger),
      m_so_linger(so_linger),
      m_initialized(false),
      m_listener(0),
      m_class(p_class)
    {
    }
    /**
     **********************************************************************
     * Constructor: cTcpEndpointT
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cTcpEndpointT
    (int port=0, cVerboseInterface *verbose=0,
     int backlog=DEFAULT_SOCKET_BACKLOG,
     bool tcp_no_delay=true, bool so_dont_linger=true,
     int so_linger=0, const char *p_class="cTcpEndpointT") 
    : cIs(port, verbose),
      m_backlog(backlog),
      m_tcp_no_delay(tcp_no_delay),
      m_so_dont_linger(so_dont_linger),
      m_so_linger(so_linger),
      m_initialized(false),
      m_listener(0),
      m_class(p_class)
    {
    }

    /**
     **********************************************************************
     * Function: SetBacklog
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual int SetBacklog
    (int backlog=DEFAULT_SOCKET_BACKLOG) 
    {
        int m_backlog = backlog;
        return m_backlog;
    }
    /**
     **********************************************************************
     * Function: GetBacklog
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual int GetBacklog() const
    {
        return m_backlog;
    }

    /**
     **********************************************************************
     * Function: SetTcpNoDelay
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual bool SetTcpNoDelay(bool on=true) 
    {
        m_tcp_no_delay = on;
        return m_tcp_no_delay;
    }
    /**
     **********************************************************************
     * Function: GetTcpNoDelay
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual bool GetTcpNoDelay() const
    {
        return m_tcp_no_delay;
    }

    /**
     **********************************************************************
     * Function: SetSoDontLinger
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual bool SetSoDontLinger
    (bool on=true, int linger=0) 
    {
        m_so_dont_linger = on;
        m_so_linger = linger;
        return m_so_dont_linger;
    }
    /**
     **********************************************************************
     * Function: GetSoDontLinger
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual bool GetSoDontLinger() 
    {
        return m_so_dont_linger;
    }

    /**
     **********************************************************************
     * Function: SetSoLinger
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual int SetSoLinger(int linger=0) 
    {
        int m_so_linger = linger;
        m_so_dont_linger = false;
        return m_so_linger;
    }
    /**
     **********************************************************************
     * Function: GetSoLinger
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual int GetSoLinger() const
    {
        return m_so_linger;
    }

    /**
     **********************************************************************
     * Function: SetListener
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual cTcpListenerInterface* SetListener
    (cTcpListenerInterface *listener) 
    {
        m_listener = listener;
        return m_listener;
    }
    /**
     **********************************************************************
     * Function: GetListener
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual cTcpListenerInterface* GetListener() const
    {
        return m_listener;
    }

    /**
     **********************************************************************
     * Function: InitEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError InitEndpoint() 
    {
        eError error2, error = e_ERROR_FAILED;
        const unsigned char &null_address=m_address.GetNullAddress();

        if (&null_address != &m_socket_address
            .Set(m_address, m_port))

        if (!(error2 = m_socket.Open()))
        {
            m_socket.SetKeepAlive(true);
            m_socket.SetNoDelay(true);
            m_socket.SetDontLinger(true);

            if (!(error2 = m_socket.Bind(m_socket_address)))
            if (!(error2 = m_socket.Listen(m_backlog)))
            {
                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Listening at port %d...\n", m_class, m_port);

                return e_ERROR_NONE;
            }
            m_socket.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError FinalEndpoint() 
    {
        eError error2, error = e_ERROR_FAILED;

        if (!(error2 = m_socket.Close()))
            error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: StartEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError StartEndpoint() 
    {
        eError error = e_ERROR_FAILED;

        if (m_listener)
            error = m_listener->Start();

        return error;
    }
    /**
     **********************************************************************
     * Function: StopEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError StopEndpoint() 
    {
        eError error = e_ERROR_FAILED;

        if (m_listener)
            error = m_listener->Stop();

        return error;
    }
    /**
     **********************************************************************
     * Function: FinishEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError FinishEndpoint() 
    {
        eError error = e_ERROR_FAILED;

        if (m_listener)
            error = m_listener->Finish();

        return error;
    }

    /**
     **********************************************************************
     * Function: PauseEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError PauseEndpoint() 
    {
        eError error = e_ERROR_FAILED;

        if (m_listener)
            error = m_listener->Pause();

        return error;
    }
    /**
     **********************************************************************
     * Function: ResumeEndpoint
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError ResumeEndpoint() 
    {
        eError error = e_ERROR_FAILED;

        if (m_listener)
            error = m_listener->Resume();

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
        eError error;

        if (!(error = m_socket.Accept(socket)))
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: ...Accepted connection at port %d\n", m_class, m_port);

            socket.UpdateAcceptContext(m_socket);
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cTcpEndpoint
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
class cTcpEndpoint
: public cTcpEndpointT<>
{
public:
    typedef cTcpEndpointT<> cIs;

    /**
     **********************************************************************
     * Constructor: cTcpEndpoint
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cTcpEndpoint
    (cInetAddressInterface& address, 
     int port=0, cVerboseInterface *verbose=0,
     int backlog=DEFAULT_SOCKET_BACKLOG,
     bool tcp_no_delay=true, bool so_dont_linger=true,
     int so_linger=0, const char *p_class="cTcpEndpoint") 
    : cIs
      (address, port, verbose, backlog, 
       tcp_no_delay, so_dont_linger, so_linger, p_class) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cTcpEndpoint
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cTcpEndpoint
    (int port=0, cVerboseInterface *verbose=0,
     int backlog=DEFAULT_SOCKET_BACKLOG,
     bool tcp_no_delay=true, bool so_dont_linger=true,
     int so_linger=0, const char *p_class="cTcpEndpoint") 
    : cIs
      (port, verbose, backlog, 
       tcp_no_delay, so_dont_linger, so_linger, p_class) 
    {
    }
};

#endif /* ndef _CTCPENDPOINT_HXX */

/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: csockett.hxx
 *
 * Author: $author$
 *   Date: 10/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSOCKETT_HXX
#define _CSOCKETT_HXX

#if defined(WIN32)
/*
 * Windows sockets
 */
//#include <winsock2.h>
//#include <mswsock.h>
#include <windows.h>
#include "cwsastartup.hxx"
#define socklen_t int
#define CSOCKETT_GET_H_ERRNO() WSAGetLastError()
#define CSOCKETT_NODELAY_ON(on) !on
#if !defined(SD_RECEIVE)
#define SD_RECEIVE      0x00
#endif
#if !defined(SD_SEND)
#define SD_SEND         0x01
#endif
#if !defined(SD_BOTH)
#define SD_BOTH         0x02
#endif
#else /* defined(WIN32) */
/*
 * Unix sockets
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SOCKET int
#define INVALID_SOCKET -1
#define SD_RECEIVE SHUT_RD
#define SD_SEND SHUT_WR
#define SD_BOTH SHUT_RDWR
#define CSOCKETT_GET_H_ERRNO() h_errno
#define CSOCKETT_NODELAY_ON(on) on
#define closesocket(handle) close(handle)
#endif /* defined(WIN32) */

#include "ccharstreamt.hxx"
#include "chandlet.hxx"

#define CSOCKETT_DEFAULT_BACKLOG 5

/**
 **********************************************************************
 *  Class: cSocketT
 *
 * Author: $author$
 *   Date: 10/26/2003
 **********************************************************************
 */
template 
<class TAs, class TChar=char, class TIs=cCharStreamT<cStream> >
class cSocketT
: public cOpenedHandleT<SOCKET, INVALID_SOCKET, TIs>
{
public:
    typedef cOpenedHandleT<SOCKET, INVALID_SOCKET, TIs> cIs;

    int m_address_family;
    int m_type;
    int m_protocol;
    int m_port;
    const char *m_host;

    /**
     **********************************************************************
     * Constructor: cSocketT
     *
     *      Author: $author$
     *        Date: 10/26/2003
     **********************************************************************
     */
    cSocketT(SOCKET handle = INVALID_SOCKET)
    : cIs(handle),
      m_address_family(AF_INET),
      m_type(SOCK_STREAM),
      m_protocol(0),
      m_port(-1),
      m_host(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cSocketT
     *
     *     Author: $author$
     *       Date: 10/26/2003
     **********************************************************************
     */
    virtual ~cSocketT()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/26/2003
     **********************************************************************
     */
    virtual eError Create()
    {
        if (INVALID_SOCKET != m_handle)
            return e_ERROR_ALREADY_ATTACHED;

#if defined(WIN32)
        eError error;
        cWSAStartup *wsa;

        if ((wsa = cWSAStartup::GetInstance()))
        if ((error = wsa->Startup()))
            return e_ERROR_STARTUP;
#endif /* defined(WIN32) */

        if (INVALID_SOCKET != (m_handle = socket
            (m_address_family, m_type, m_protocol)))
        {
            m_opened = true;
            return e_ERROR_NONE;
        }

#if defined(WIN32)
        if (wsa)
            wsa->Cleanup();
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/26/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error = e_ERROR_NONE;
        eError error2;
        int err;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((err = closesocket(m_handle)))
            error = e_ERROR_CLOSE;

#if defined(WIN32)
        cWSAStartup *wsa;

        if ((wsa = cWSAStartup::GetInstance()))
        if ((error2 = wsa->Cleanup()))
        if (!error)
            error = e_ERROR_CLEANUP;
#endif /* defined(WIN32) */

        m_opened = false;
        m_handle = INVALID_SOCKET;
        return error;
    }

    /**
     **********************************************************************
     * Function: Shutdown
     *
     *   Author: $author$
     *     Date: 10/29/2003
     *
     * enum {
     *     SD_RECEIVE,
     *     SD_SEND,
     *     SD_BOTH
     * }
     **********************************************************************
     */
    virtual eError Shutdown(int how=SD_BOTH)
    {
        int err;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((err = shutdown(m_handle, how)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 10/28/2003
     **********************************************************************
     */
    virtual eError Connect(const char *host, int port)
    {
        int err;
        eError error;
        struct sockaddr_in sockaddr_in;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((error = SetSockAddrIn(sockaddr_in, host, port)))
            return error;

        if ((err = connect(m_handle, (sockaddr*)&sockaddr_in, sizeof(sockaddr_in))))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual eError Bind(const char *host, int port)
    {
        int err;
        eError error;
        struct sockaddr_in sockaddr_in;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((error = SetSockAddrIn(sockaddr_in, host, port)))
            return error;

        if ((err = bind(m_handle, (sockaddr*)&sockaddr_in, sizeof(sockaddr_in))))
            return On_bind_Error
            (err, m_handle, (sockaddr*)&sockaddr_in, sizeof(sockaddr_in));

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual eError Listen(int backlog=CSOCKETT_DEFAULT_BACKLOG)
    {
        int err;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((err = listen(m_handle, backlog)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual eError Accept(TAs &socket)
    {
        SOCKET handle;
        socklen_t socklen;
        struct sockaddr_in sockaddr_in;
        eError error;

#if defined(WIN32)
        cWSAStartup *wsa;
#endif /* defined(WIN32) */

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        socklen = sizeof(sockaddr_in);

        if (INVALID_SOCKET == (handle = accept
            (m_handle, (struct sockaddr*)&sockaddr_in, &socklen)))
            return e_ERROR_FAILED;

#if defined(WIN32)
        /* Increment startup count for new socket
         */
        if ((wsa = cWSAStartup::GetInstance()))
        if ((error = wsa->Startup()))
        {
            closesocket(handle);
            return e_ERROR_STARTUP;
        }
#endif /* defined(WIN32) */

        if ((error = socket.Attach(handle, true)))
        {
            closesocket(handle);

#if defined(WIN32)
            /* Decrement startup count for new socket
             */
            if (wsa)
                wsa->Cleanup();
#endif /* defined(WIN32) */

            return error;
        }

        socket.m_port = ntohs(sockaddr_in.sin_port);
        socket.m_host = inet_ntoa(sockaddr_in.sin_addr);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: UpdateAcceptContext
     *
     *   Author: $author$
     *     Date: 11/16/2004
     **********************************************************************
     */
    virtual eError UpdateAcceptContext(TAs &socket)
    {
        SOCKET optval = socket.GetHandle();

        return SetSockOpt
        (SOL_SOCKET, 
         SO_UPDATE_ACCEPT_CONTEXT, 
         &optval, sizeof(optval));
    }
    /**
     **********************************************************************
     * Function: SetSockAddrIn
     *
     *   Author: $author$
     *     Date: 10/28/2003
     *
     **********************************************************************
     * struct sockaddr {
     *     unsigned short sa_family;
     *     char           sa_data[14];
     * };
     *
     * struct sockaddr_in {
     *     short            sin_family;
     *     unsigned short   sin_port;
     *     struct   in_addr sin_addr;
     *     char             sin_zero[8];
     * };
     *
     * struct in_addr {
     *     unsigned long s_addr;
     * };
     *
     * struct hostent {
     *     char  *h_name;
     *     char **h_aliases;
     *     short  h_addrtype;
     *     short  h_length;
     *     char **h_addr_list;
     * };
     * define h_addr h_addr_list[0]
     **********************************************************************
     */
    virtual eError SetSockAddrIn
    (struct sockaddr_in &sockaddr_in, 
     const char *host, int port) const
    {
        struct hostent *hostent;

        sockaddr_in.sin_addr.s_addr=INADDR_ANY;

        if (host)
        if (host[0])
        {
            if ((hostent = gethostbyname(host)))
                sockaddr_in.sin_addr.s_addr=*(unsigned long*)hostent->h_addr;
            else
            {
                On_gethostbyname_Error
                (CSOCKETT_GET_H_ERRNO(), host);

#if defined(WIN32)
                if (INADDR_NONE == (sockaddr_in.sin_addr.s_addr=inet_addr(host)))
                    return e_ERROR_INVALID_PARAMETER;
#else /* defined(WIN32) */
                if (inet_aton(host, &sockaddr_in.sin_addr))
                    return e_ERROR_INVALID_PARAMETER;
#endif /* defined(WIN32) */
            }
        }

        /*
        printf("inaddr = %s\n", inet_ntoa(sockaddr_in.sin_addr));
        */

        sockaddr_in.sin_family = m_address_family;
        sockaddr_in.sin_port = htons(port);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetSockName
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual eError GetSockName
    (struct sockaddr &sockaddr, socklen_t &socklen) const
    {
        int err;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((err = getsockname(m_handle, &sockaddr, &socklen)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetKeepAlive
     *
     *   Author: $author$
     *     Date: 11/16/2004
     **********************************************************************
     */
    virtual eError SetKeepAlive(bool on=true)
    {
        int optval = on;

        return SetSockOpt
        (SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));
    }
    /**
     **********************************************************************
     * Function: SetNoDelay
     *
     *   Author: $author$
     *     Date: 11/2/2003
     **********************************************************************
     */
    virtual eError SetNoDelay(bool on=true)
    {
        int optval = CSOCKETT_NODELAY_ON(on);

        return SetSockOpt
        (IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
    }
    /**
     **********************************************************************
     * Function: SetDontLinger
     *
     *   Author: $author$
     *     Date: 11/2/2003
     *
     * struct linger {
     *     u_short    l_onoff;
     *     u_short    l_linger;
     * }
     **********************************************************************
     */
    virtual eError SetDontLinger(bool on=true, int linger=0)
    {
        struct linger optval;

        optval.l_onoff = !on;
        optval.l_linger = linger;

        return SetSockOpt
        (SOL_SOCKET, SO_LINGER, &optval, sizeof(optval));
    }
    /**
     **********************************************************************
     * Function: SetSockOpt
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual eError SetSockOpt
    (int level, int optname,
     const void *optval, socklen_t optlen)
    {
        int err;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((err = setsockopt
            (m_handle, level, optname,
             (const char*)optval, optlen)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetSockOpt
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual eError GetSockOpt
    (int level, int optname, 
     void *optval, socklen_t &optlen) const
    {
        int err;

        if (INVALID_SOCKET == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((err = getsockopt
            (m_handle, level, optname,
             (char*)optval, &optlen)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetPort
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual int GetPort() const
    {
        return m_port;
    }
    /**
     **********************************************************************
     * Function: GetHost
     *
     *   Author: $author$
     *     Date: 10/29/2003
     **********************************************************************
     */
    virtual const char *GetHost() const
    {
        if (m_host)
            return m_host;

        return "";
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int Read(TChar *buffer, int size)
    {
		int left, count;

        if (INVALID_SOCKET == m_handle)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > size)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

		if (size < 1)
            return 0;

		for (left = size; left > 0; left -= count, buffer += count)
		{
			if (0 > (count = recv
                (m_handle, (char*)buffer, left, 0)))
				return count;

			if (count > left)
                return -e_ERROR_FAILED;

			if (1 > count)
                break;
		}

		return size-left;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/11/2004
     **********************************************************************
     */
    virtual int Write(const TChar *buffer, int size=-1)
    {
		int left, count;

        if (INVALID_SOCKET == m_handle)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > size)
            size = strlen((const char*)buffer);

		if (size < 1)
            return size;

		for (left = size; left > 0; left -= count, buffer += count)
		{
			if (0 > (count = send
                (m_handle, (const char*)buffer, left, 0)))
				return count;

			if (count > left)
                return -e_ERROR_FAILED;
		}

		return size-left;
    }
    /**
     **********************************************************************
     * Function: On_gethostbyname_Error
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError On_gethostbyname_Error
    (int err, const char *host) const
    {
        eError error=e_ERROR_FAILED;

        return error;
    }
    /**
     **********************************************************************
     * Function: On_bind_Error
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError On_bind_Error
    (int err, SOCKET socket, 
     struct sockaddr *addr, socklen_t addrlen) const
    {
        eError error=e_ERROR_FAILED;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnError
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError OnError()
    {
        eError error=e_ERROR_FAILED;

        return error;
    }
};


#endif

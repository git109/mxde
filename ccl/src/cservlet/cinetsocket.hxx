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
 *   File: cinetsocket.hxx
 *
 * Author: $author$
 *   Date: 10/16/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETSOCKET_HXX
#define _CINETSOCKET_HXX

#include "coutputstreaminterface.hxx"
#include "cinputstreaminterface.hxx"
#include "cinetsocketinterface.hxx"
#include "cinetsocketaddress.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cInetSocketT
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
template 
<class TOutputStreamInterfaceIs=cOutputStreamInterface,
 class TOutputStreamImplementIs=cOutputStreamImplement, 
 class TInputStreamInterfaceIs=cInputStreamInterface,
 class TInputStreamImplementIs=cInputStreamImplement, 
 class TInterfaceIs=cInetSocketInterface,
 class TImplementIs=cInetSocketImplement, 
 class TIs=cImplement>

class cInetSocketT
: virtual public TImplementIs,
  virtual public TInputStreamImplementIs,
  virtual public TOutputStreamImplementIs,
  public TIs
{
public:
    typedef TImplementIs cImplementIs;
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cInetSocketT
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cInetSocketT
    (SOCKET attached=INVALID_SOCKET, bool opened=false) 
    : cImplementIs(attached, opened) 
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Open
    (int type=SOCK_STREAM, int protocol=IPPROTO_TCP) 
    {
        eError error = e_ERROR_FAILED;
        int address_family = AF_INET;

        if (INVALID_SOCKET != (this->m_attached = socket
            (address_family, type, protocol)))
        {
            this->m_opened = true;
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (!(err = closesocket(this->m_attached)))
        {
            this->m_attached = INVALID_SOCKET;
            this->m_opened = false;
            error = e_ERROR_NONE;
        }

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
        eError error = e_ERROR_NONE;
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if ((err = shutdown(this->m_attached, how)))
            error = e_ERROR_FAILED;

        return error;
    }

    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Bind
    (cInetSocketAddressInterface &address) 
    {
        eError error = e_ERROR_FAILED;
        SOCKADDR_IN &sockaddr_in = address.GetSockAddrIn();
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (!(err = bind(this->m_attached, (SOCKADDR*)&sockaddr_in, sizeof(sockaddr_in))))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Connect
    (cInetSocketAddressInterface &address) 
    {
        eError error = e_ERROR_FAILED;
        SOCKADDR_IN &sockaddr_in = address.GetSockAddrIn();
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (!(err = connect(this->m_attached, (SOCKADDR*)&sockaddr_in, sizeof(sockaddr_in))))
            error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual eError Listen
    (int backlog=DEFAULT_SOCKET_BACKLOG) 
    {
        eError error = e_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (!(err = listen(this->m_attached, backlog)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual eError Accept
    (TInterfaceIs &socket) 
    {
        eError error = e_ERROR_FAILED;
        socklen_t socklen;
        SOCKADDR_IN sockaddr_in;
        SOCKET attached;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if (socket.IsOpen())
            return e_ERROR_ALREADY_OPEN;

        socklen = sizeof(sockaddr_in);

        if (INVALID_SOCKET != (attached = accept
            (this->m_attached, (SOCKADDR*)&sockaddr_in, &socklen)))
        {
            socket.AttachOpen(attached);
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: UpdateAcceptContext
     *
     *   Author: $author$
     *     Date: 11/16/2004
     **********************************************************************
     */
    virtual eError UpdateAcceptContext
    (TInterfaceIs &socket)
    {
#if defined(WIN32) 
        SOCKET optval = socket.Attached();

        return SetSockOpt
        (SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, 
         &optval, sizeof(optval));
#else /* defined(WIN32) */
        return e_ERROR_NONE;
#endif /* defined(WIN32) */
    }

    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int Send(const BYTE *buf, int len=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_SOCKET == this->m_attached)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > len)
            len = strlen((const char*)buf);

		if (0 > (count = send
            (this->m_attached, (const char*)buf, len, 0)))
			return -e_ERROR_FAILED;

        return count;
    }
    /**
     **********************************************************************
     * Function: Receive
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int Receive(BYTE *buf, int len=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;

        if (INVALID_SOCKET == this->m_attached)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > len)
            len = strlen((char*)buf);

		if (0 > (count = recv
            (this->m_attached, (char*)buf, len, 0)))
			return -e_ERROR_FAILED;

        return count;
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
     * Function: SetNonBlocking
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError SetNonBlocking(bool on=true)
    {
#if defined(WIN32)
        unsigned long optval = on;
#else /* defined(WIN32) */
        int optval = on?O_NONBLOCK:0;
#endif /* defined(WIN32) */
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        if ((err = ioctlsocket
            (m_attached, FIONBIO, &optval)))
#else /* defined(WIN32) */
        if (0 > (err = fcntl
            (this->m_attached, F_GETFL, 0)))
            return e_ERROR_FAILED;

        optval |= err;

        if (0 > (err = fcntl
            (this->m_attached, F_SETFL, optval)))
#endif /* defined(WIN32) */
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetNoDelay
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError SetNoDelay(bool on=true)
    {
        int optval = SOCKET_NODELAY_ON(on);

        return SetSockOpt
        (IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
    }
    /**
     **********************************************************************
     * Function: SetDontLinger
     *
     *   Author: $author$
     *     Date: 11/15/2004
     *
     * struct linger {
     *     u_short    l_onoff;
     *     u_short    l_linger;
     * }
     **********************************************************************
     */
    virtual eError SetDontLinger
    (bool on=true, int linger=0)
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
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError SetSockOpt
    (int level, int optname,
     const void *optval, socklen_t optlen)
    {
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if ((err = setsockopt
            (this->m_attached, level, optname,
             (const char*)optval, optlen)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetSockOpt
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError GetSockOpt
    (int level, int optname, 
     void *optval, socklen_t &optlen) const
    {
        int err;

        if (INVALID_SOCKET == this->m_attached)
            return e_ERROR_NOT_ATTACHED;

        if ((err = getsockopt
            (this->m_attached, level, optname,
             (char*)optval, &optlen)))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual int Write(const BYTE *buf,  int len=-1) 
    {
        int left, count;

        if (INVALID_SOCKET == this->m_attached)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > len)
            len = strlen((const char*)buf);

        if (1 > len)
            return len;

		for (left = len; left > 0; left -= count, buf += count)
		{
			if (0 > (count = send
                (this->m_attached, (const char*)buf, left, 0)))
				return -e_ERROR_FAILED;

			if (count > left)
            {
                left = 0;
				break;
            }
		}

        return len-left;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 9/26/2004
     **********************************************************************
     */
    virtual int Read(BYTE *buf, int len=-1)
    {
        int left, count;

        if (INVALID_SOCKET == this->m_attached)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > len)
            len = strlen((char*)buf);

        if (1 > len)
            return len;

		for (left = len; left > 0; left -= count, buf += count)
		{
			if (0 > (count = recv
                (this->m_attached, (char*)buf, left, 0)))
				return -e_ERROR_FAILED;

			if (count <= left)
            {
                left -= count;
				break;
            }
		}

		return len-left;
    }

    /**
     **********************************************************************
     * Function: GetOutputStream
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual cOutputStreamInterface &GetOutputStream() 
    {
        cOutputStreamInterface &stream = *this;
        return stream;
    }
    /**
     **********************************************************************
     * Function: GetInputStream
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual cInputStreamInterface &GetInputStream() 
    {
        cInputStreamInterface &stream = *this;
        return stream;
    }
};

/**
 **********************************************************************
 *  Class: cInetSocket
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class cInetSocket
: public cInetSocketT
  <cOutputStreamInterface, cOutputStreamImplement,
   cInputStreamInterface, cInputStreamImplement,
   cInetSocketInterface, cInetSocketImplement, cImplement>
{
public:
    typedef cInetSocketT
    <cOutputStreamInterface, cOutputStreamImplement,
     cInputStreamInterface, cInputStreamImplement,
     cInetSocketInterface, cInetSocketImplement, cImplement> cIs;

    /**
     **********************************************************************
     * Constructor: cInetSocket
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cInetSocket
    (SOCKET attached=INVALID_SOCKET, bool opened=false) 
    : cIs(attached, opened) 
    {
    }
};

#endif /* ndef _CINETSOCKET_HXX */

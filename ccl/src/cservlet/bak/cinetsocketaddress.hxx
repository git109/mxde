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
 *   File: cinetsocketaddress.hxx
 *
 * Author: $author$
 *   Date: 10/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETSOCKETADDRESS_HXX
#define _CINETSOCKETADDRESS_HXX

#include "csocketaddress.hxx"
#include "cinetsocketaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cInetSocketAddressT
 *
 * Author: $author$
 *   Date: 10/12/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cInetSocketAddressInterface,
 class TIs=cSocketAddress>

class cInetSocketAddressT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    SOCKADDR_IN &m_sockaddr_in;

    /**
     **********************************************************************
     * Constructor: cInetSocketAddressT
     *
     *      Author: $author$
     *        Date: 10/12/2004
     **********************************************************************
     */
    cInetSocketAddressT
    (cInetAddressInterface &address, const char *host, int port) 
    : cIs(AF_INET),
      m_sockaddr_in((SOCKADDR_IN&)m_sockaddr)
    {
	    m_sockaddr_in.sin_addr = *((IN_ADDR*)&address.GetByName(host));
        m_sockaddr_in.sin_port = htons(port);
    }
    /**
     **********************************************************************
     * Constructor: cInetSocketAddressT
     *
     *      Author: $author$
     *        Date: 10/12/2004
     **********************************************************************
     */
    cInetSocketAddressT(cInetAddressInterface &address, int port) 
    : cIs(AF_INET),
      m_sockaddr_in((SOCKADDR_IN&)m_sockaddr)
    {
	    m_sockaddr_in.sin_addr = *((IN_ADDR*)&address.GetAddress());
        m_sockaddr_in.sin_port = htons(port);
    }
    /**
     **********************************************************************
     * Constructor: cInetSocketAddressT
     *
     *      Author: $author$
     *        Date: 10/12/2004
     **********************************************************************
     */
    cInetSocketAddressT(int port=0) 
    : cIs(AF_INET),
      m_sockaddr_in((SOCKADDR_IN&)m_sockaddr)
    {
	    m_sockaddr_in.sin_addr.s_addr = INADDR_ANY;
        m_sockaddr_in.sin_port = htons(port);
    }


    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/14/2004
     **********************************************************************
     */
    virtual unsigned char& Set
    (cInetAddressInterface &address, const char *host, int port) 
    {
	    m_sockaddr_in.sin_addr = *((IN_ADDR*)&address.GetByName(host));
        m_sockaddr_in.sin_port = htons(port);
        return m_sockaddr_in.sin_addr.S_un.S_un_b.s_b1;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/14/2004
     **********************************************************************
     */
    virtual unsigned char& Set
    (cInetAddressInterface &address, int port) 
    {
	    m_sockaddr_in.sin_addr = *((IN_ADDR*)&address.GetAddress());
        m_sockaddr_in.sin_port = htons(port);
        return m_sockaddr_in.sin_addr.S_un.S_un_b.s_b1;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/14/2004
     **********************************************************************
     */
    virtual unsigned char& Set(int port=-1) 
    {
	    m_sockaddr_in.sin_addr.s_addr = INADDR_ANY;
        m_sockaddr_in.sin_port = htons(port);
        return m_sockaddr_in.sin_addr.S_un.S_un_b.s_b1;
    }

    /**
     **********************************************************************
     * Function: GetSockAddrIn
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual SOCKADDR_IN &GetSockAddrIn() 
    {
        SOCKADDR_IN &sockaddr_in = m_sockaddr_in;
        return sockaddr_in;
    }
};

/**
 **********************************************************************
 *  Class: cInetSocketAddress
 *
 * Author: $author$
 *   Date: 10/14/2004
 **********************************************************************
 */
class cInetSocketAddress
: public cInetSocketAddressT<>
{
public:
    typedef cInetSocketAddressT<> cIs;

    /**
     **********************************************************************
     * Constructor: cInetSocketAddress
     *
     *      Author: $author$
     *        Date: 10/14/2004
     **********************************************************************
     */
    cInetSocketAddress
    (cInetAddressInterface &address, const char *host, int port) 
    : cIs(address, host, port) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cInetSocketAddress
     *
     *      Author: $author$
     *        Date: 10/14/2004
     **********************************************************************
     */
    cInetSocketAddress
    (cInetAddressInterface &address, int port) 
    : cIs(address, port) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cInetSocketAddress
     *
     *      Author: $author$
     *        Date: 10/14/2004
     **********************************************************************
     */
    cInetSocketAddress(int port=-1) 
    : cIs(port) 
    {
    }
};

#endif /* ndef _CINETSOCKETADDRESS_HXX */

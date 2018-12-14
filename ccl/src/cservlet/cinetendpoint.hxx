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
 *   File: cinetendpoint.hxx
 *
 * Author: $author$
 *   Date: 10/18/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETENDPOINT_HXX
#define _CINETENDPOINT_HXX

#include "cinetsocket.hxx"
#include "cinetaddress.hxx"
#include "cinetaddressinterface.hxx"
#include "cverboseinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cInetEndpointT
 *
 * Author: $author$
 *   Date: 10/18/2004
 **********************************************************************
 */
template 
<class TIs=cVerboseContainerImplement>

class cInetEndpointT
: public TIs
{
public:
    typedef TIs cIs;

    int m_port;
    cInetAddress m_address;
    cInetSocketAddress m_socket_address;
    cInetSocket m_socket;

    /**
     **********************************************************************
     * Constructor: cInetEndpointT
     *
     *      Author: $author$
     *        Date: 10/18/2004
     **********************************************************************
     */
    cInetEndpointT
    (cInetAddressInterface& address, 
     int port=0, cVerboseInterface *verbose=0)
    : cIs(verbose),
      m_address(address),
      m_port(port)
    {
    }
    /**
     **********************************************************************
     * Constructor: cInetEndpointT
     *
     *      Author: $author$
     *        Date: 10/18/2004
     **********************************************************************
     */
    cInetEndpointT
    (int port=0, cVerboseInterface *verbose=0)
    : cIs(verbose),
      m_port(port)
    {
    }

    /**
     **********************************************************************
     * Function: SetAddress
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual cInetAddressInterface& SetAddress
    (cInetAddressInterface& address) 
    {
        m_address.SetByInAddr(address.GetInAddr());
        return m_address;
    }
    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual cInetAddressInterface& GetAddress()
    {
        return m_address;
    }

    /**
     **********************************************************************
     * Function: SetPort
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int SetPort(int port) 
    {
        m_port = port;
        return m_port;
    }
    /**
     **********************************************************************
     * Function: GetPort
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int GetPort() const
    {
        return m_port;
    }
};

/**
 **********************************************************************
 *  Class: cInetEndpoint
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
class cInetEndpoint
: public cInetEndpointT<>
{
public:
    typedef cInetEndpointT<> cIs;

    /**
     **********************************************************************
     * Constructor: cInetEndpoint
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cInetEndpoint
    (cInetAddressInterface& address, 
     int port=0, cVerboseInterface *verbose=0) 
    : cIs(address, port, verbose) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cInetEndpoint
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cInetEndpoint
    (int port=0, cVerboseInterface *verbose=0) 
    : cIs(port, verbose) 
    {
    }
};

#endif /* ndef _CINETENDPOINT_HXX */

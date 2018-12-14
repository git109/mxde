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
 *   File: cinetaddress.hxx
 *
 * Author: $author$
 *   Date: 10/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETADDRESS_HXX
#define _CINETADDRESS_HXX

#include "platformsocket.h"
#include "cinetaddressinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cInetAddressT
 *
 * Author: $author$
 *   Date: 10/13/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cInetAddressInterface, 
 class TImplementIs=cInetAddressImplement, 
 class TIs=cImplement>
class cInetAddressT
: virtual public TInterfaceIs,
  virtual public TImplementIs,
  public TIs
{
public:
    typedef TIs cIs;

    IN_ADDR m_in_addr;

    /**
     **********************************************************************
     * Constructor: cInetAddressT
     *
     *      Author: $author$
     *        Date: 10/13/2004
     **********************************************************************
     */
    cInetAddressT(TInterfaceIs &address) 
    {
        m_in_addr = address.GetInAddr();
    }
    /**
     **********************************************************************
     * Constructor: cInetAddressT
     *
     *      Author: $author$
     *        Date: 10/13/2004
     **********************************************************************
     */
    cInetAddressT(const char *host=0) 
    {
        m_in_addr.s_addr = INADDR_ANY;

        if (host)
        if (host[0])
            GetByName(host);
    }

    /**
     **********************************************************************
     * Function: GetByName
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual const unsigned char& GetByName(const char *name) 
    {
        const unsigned char& addr = GetNullAddress();
        HOSTENT *hostent;

        if ((hostent = gethostbyname(name)))
        {
            m_in_addr = *((IN_ADDR*)(hostent->h_addr));
            return m_in_addr.S_un.S_un_b.s_b1;
        }

        return addr;
    }

    /**
     **********************************************************************
     * Function: SetByInAddr
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& SetByInAddr(IN_ADDR& in_addr) 
    {
        m_in_addr = in_addr;
        return m_in_addr;
    }
    /**
     **********************************************************************
     * Function: SetByInAddrAny
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& SetByInAddrAny() 
    {
        m_in_addr.s_addr = INADDR_ANY;
        return m_in_addr;
    }
    /**
     **********************************************************************
     * Function: GetInAddr
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual IN_ADDR& GetInAddr() 
    {
        return m_in_addr;
    }

    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual const unsigned char& GetAddress() const
    {
        return m_in_addr.S_un.S_un_b.s_b1;
    }
};

/**
 **********************************************************************
 *  Class: cInetAddress
 *
 * Author: $author$
 *   Date: 10/13/2004
 **********************************************************************
 */
class cInetAddress
: public cInetAddressT<>
{
public:
    typedef cInetAddressT<> cIs;

    /**
     **********************************************************************
     * Constructor: cInetAddress
     *
     *      Author: $author$
     *        Date: 10/13/2004
     **********************************************************************
     */
    cInetAddress(cInetAddressInterface &address) 
    : cIs(address)
    {
    }
    /**
     **********************************************************************
     * Constructor: cInetAddress
     *
     *      Author: $author$
     *        Date: 10/13/2004
     **********************************************************************
     */
    cInetAddress(const char *host=0) 
    : cIs(host) 
    {
    }
};

#endif /* ndef _CINETADDRESS_HXX */

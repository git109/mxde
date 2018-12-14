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
 *   File: csocketaddress.hxx
 *
 * Author: $author$
 *   Date: 10/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSOCKETADDRESS_HXX
#define _CSOCKETADDRESS_HXX

#include "csocketaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cSocketAddressT
 *
 * Author: $author$
 *   Date: 10/12/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cSocketAddressInterface, 
 class TIs=cImplement>

class cSocketAddressT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    SOCKADDR m_sockaddr;

    /**
     **********************************************************************
     * Constructor: cSocketAddressT
     *
     *      Author: $author$
     *        Date: 10/12/2004
     **********************************************************************
     */
    cSocketAddressT(unsigned sa_family=0) 
    {
        memset(&m_sockaddr, 0, sizeof(m_sockaddr));
        m_sockaddr.sa_family = sa_family;
    }

    /**
     **********************************************************************
     * Function: GetSockAddr
     *
     *   Author: $author$
     *     Date: 10/12/2004
     **********************************************************************
     */
    virtual SOCKADDR &GetSockAddr() 
    {
        SOCKADDR &sockaddr = m_sockaddr;
        return sockaddr;
    }
};

/**
 **********************************************************************
 *  Class: cSocketAddress
 *
 * Author: $author$
 *   Date: 10/14/2004
 **********************************************************************
 */
class cSocketAddress
: public cSocketAddressT<>
{
public:
    typedef cSocketAddressT<> cIs;

    /**
     **********************************************************************
     * Constructor: cSocketAddress
     *
     *      Author: $author$
     *        Date: 10/14/2004
     **********************************************************************
     */
    cSocketAddress(unsigned sa_family=0) 
    : cIs(sa_family) 
    {
    }
};

#endif /* ndef _CSOCKETADDRESS_HXX */

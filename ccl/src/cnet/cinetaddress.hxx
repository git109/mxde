/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cinetaddress.hxx
 *
 * Author: $author$
 *   Date: 3/13/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CINETADDRESS_HXX
#define _CINETADDRESS_HXX

#include "cinetaddressinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cInetAddress
 *
 * Author: $author$
 *   Date: 3/13/2006
 **********************************************************************
 */
class cInetAddress
: virtual public cNetAddressImplement,
  virtual public cInetAddressImplement,
  public cInstanceBase
{
public:
    typedef cInstanceBase cIs;

    IN_ADDR m_in_addr;

    /**
     **********************************************************************
     * Constructor: cInetAddress
     *
     *      Author: $author$
     *        Date: 3/13/2006
     **********************************************************************
     */
    cInetAddress(const char* hostname=0, int interfaceno=-1) 
    {
        IN_ADDR_SET_INADDR_ANY(m_in_addr);

        if (hostname)
        if (hostname[0])
            SetByHostName(hostname, interfaceno);
    }
    /**
     **********************************************************************
     *  Destructor: ~cInetAddress
     *
     *      Author: $author$
     *        Date: 3/13/2006
     **********************************************************************
     */
    virtual ~cInetAddress()
    {
    }
    /**
     **********************************************************************
     * Function: SetByHostName
     *
     *   Author: $author$
     *     Date: 3/15/2006
     **********************************************************************
     */
    virtual int SetByHostName
    (const char* hostname, int interfaceno=-1) 
    {
        int length = -e_ERROR_FAILED;
        HOSTENT *hostent;

        if (hostname)
        if (hostname[0])
        {
            if (!(hostent = gethostbyname(hostname)))
                return length;

            length = SetToInAddr
            (HOSTENT_GET_IN_ADDR_INDEX(hostent, interfaceno));
            return length;
        }

        length = SetToInAddrAny();
        return length;
    }
    /**
     **********************************************************************
     * Function: SetToInAddr
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetToInAddr(const IN_ADDR& in_addr) 
    {
        int length = sizeof(m_in_addr);
        m_in_addr = in_addr;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetToInAddrAny
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int SetToInAddrAny() 
    {
        int length = sizeof(m_in_addr);
        IN_ADDR_SET_INADDR_ANY(m_in_addr);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetAddress
     *
     *   Author: $author$
     *     Date: 3/15/2006
     **********************************************************************
     */
    virtual const BYTE& GetAddress
    (int &length) const 
    {
        const BYTE& addr = *IN_ADDR_GET_ADDRESS(m_in_addr);
        return addr;
    }
};

#endif /* _CINETADDRESS_HXX */



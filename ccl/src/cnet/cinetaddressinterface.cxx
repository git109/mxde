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
 *   File: cinetaddressinterface.cxx
 *
 * Author: $author$
 *   Date: 3/20/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "cinetaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cInetAddressInterface
 *
 * Author: $author$
 *   Date: 3/20/2006
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cInetAddressInterface::GetInAddrAny
 *
 *   Author: $author$
 *     Date: 3/12/2006
 **********************************************************************
 */
const IN_ADDR& cInetAddressInterface::GetInAddrAny(int& length)
{
    static bool in_addr_is_any = false;
    static IN_ADDR in_addr;
    const IN_ADDR& addr = in_addr;

    if (!in_addr_is_any)
    {
        in_addr.s_addr = INADDR_ANY;
        in_addr_is_any = true;
    }

    length = sizeof(in_addr);
    return addr;
}

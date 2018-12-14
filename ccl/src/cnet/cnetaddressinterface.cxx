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
 *   File: cnetaddressinterface.cxx
 *
 * Author: $author$
 *   Date: 3/20/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "cnetaddressinterface.hxx"

/**
 **********************************************************************
 *  Class: cNetAddressInterface
 *
 * Author: $author$
 *   Date: 3/20/2006
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cNetAddressInterface::GetNullAddress
 *
 *   Author: $author$
 *     Date: 3/20/2006
 **********************************************************************
 */
const BYTE& cNetAddressInterface::GetNullAddress
(int &length) 
{
    static const BYTE null_address = 0;
    const BYTE& address = null_address;
    length = 0;
    return address;
}

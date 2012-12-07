/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ccryptohmac.h
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#ifndef _CCRYPTOHMAC_H
#define _CCRYPTOHMAC_H

/**
 **********************************************************************
 *   Enum:  eCryptoHMAC
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
typedef int eCryptoHMAC;
enum
{
    e_CRYPTO_HMAC_IPAD = 0x36,
    e_CRYPTO_HMAC_OPAD = 0x5c,
};

#define e_CRYPTO_HMAC_NAME_IPAD "IPAD"
#define e_CRYPTO_HMAC_NAME_OPAD "OPAD"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CCRYPTOHMAC_H */


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
 *   File: ccryptoerror.h
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#ifndef _CCRYPTOERROR_H
#define _CCRYPTOERROR_H

#include "cerror.h"

/**
 **********************************************************************
 *   Enum:  e
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
typedef enum e
{
    e_FIRST_ERROR_CRYPTO =  e_NEXT_ERROR,

    e_ERROR_CRYPTO_KEY_SIZE = e_FIRST_ERROR_CRYPTO,
    e_ERROR_CRYPTO_KEY_SIZE_UNDER,
    e_ERROR_CRYPTO_KEY_SIZE_OVER,

    e_ERROR_CRYPTO_IV_SIZE,
    e_ERROR_CRYPTO_IV_SIZE_UNDER,
    e_ERROR_CRYPTO_IV_SIZE_OVER,

    e_ERROR_CRYPTO_BLOCK_SIZE,
    e_ERROR_CRYPTO_BLOCK_SIZE_UNDER,
    e_ERROR_CRYPTO_BLOCK_SIZE_OVER,

    e_NEXT_ERROR_CRYPTO,
    e_LAST_ERROR_CRYPTO = e_NEXT_ERROR_CRYPTO-1,
    e_COUNT_ERROR_CRYPTO = e_LAST_ERROR_CRYPTO-e_FIRST_ERROR_CRYPTO+1
}  e;

#define e_ERROR_NAME_CRYPTO_KEY_SIZE "CRYPTO_KEY_SIZE"
#define e_ERROR_NAME_CRYPTO_KEY_SIZE_UNDER "CRYPTO_KEY_SIZE_UNDER"
#define e_ERROR_NAME_CRYPTO_KEY_SIZE_OVER "CRYPTO_KEY_SIZE_OVER"

#define e_ERROR_NAME_CRYPTO_IV_SIZE "CRYPTO_IV_SIZE"
#define e_ERROR_NAME_CRYPTO_IV_SIZE_UNDER "CRYPTO_IV_SIZE_UNDER"
#define e_ERROR_NAME_CRYPTO_IV_SIZE_OVER "CRYPTO_IV_SIZE_OVER"

#define e_ERROR_NAME_CRYPTO_BLOCK_SIZE "CRYPTO_BLOCK_SIZE"
#define e_ERROR_NAME_CRYPTO_BLOCK_SIZE_UNDER "CRYPTO_BLOCK_SIZE_UNDER"
#define e_ERROR_NAME_CRYPTO_BLOCK_SIZE_OVER "CRYPTO_BLOCK_SIZE_OVER"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern const char* g_e_crypto_error_name[e_COUNT_ERROR_CRYPTO];

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CCRYPTOERROR_H */

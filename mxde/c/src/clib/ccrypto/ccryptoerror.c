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
 *   File: ccryptoerror.c
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#include "ccryptoerror.h"

/**
 **********************************************************************
 *   Enum:  eCryptoError
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
const char* g_e_crypto_error_name[e_COUNT_ERROR_CRYPTO] = 
{
    e_ERROR_NAME_CRYPTO_KEY_SIZE,
    e_ERROR_NAME_CRYPTO_KEY_SIZE_UNDER,
    e_ERROR_NAME_CRYPTO_KEY_SIZE_OVER,
            
    e_ERROR_NAME_CRYPTO_IV_SIZE,
    e_ERROR_NAME_CRYPTO_IV_SIZE_UNDER,
    e_ERROR_NAME_CRYPTO_IV_SIZE_OVER,
            
    e_ERROR_NAME_CRYPTO_BLOCK_SIZE,
    e_ERROR_NAME_CRYPTO_BLOCK_SIZE_UNDER,
    e_ERROR_NAME_CRYPTO_BLOCK_SIZE_OVER
};

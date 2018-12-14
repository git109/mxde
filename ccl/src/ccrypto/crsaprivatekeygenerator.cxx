/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: crsaprivatekeygenerator.cxx
 *
 * Author: $author$
 *   Date: 10/22/2007
 *
 **********************************************************************
 */

#include "crsaprivatekeygenerator.hxx"

/**
 **********************************************************************
 *  Class: cRSAPrivateKeyGenerator
 *
 * Author: $author$
 *   Date: 10/22/2007
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cRSAPrivateKey
 *
 * Author: $author$
 *   Date: 10/22/2007
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cRSAPrivateKey::Generate
 *
 *   Author: $author$
 *     Date: 10/22/2007
 **********************************************************************
 */
eError cRSAPrivateKey::Generate
(cRSAPublicKey& publicKey, 
 cBYTEStreamInterface& random,
 const BYTE* exponent, unsigned expbytes, unsigned modbytes,
 cPrimeReaderEventsInterface* prime_reader_events) 
{
    cRSAPrivateKeyGenerator generator(prime_reader_events);
    eError error = generator.Generate
    (*this, publicKey, random, exponent, expbytes, modbytes);
    return error;
}


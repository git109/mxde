/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: ccipher.hxx
 *
 * Author: $author$
 *   Date: 1/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCIPHER_HXX
#define _CCIPHER_HXX

#include "ccipherinterface.hxx"
#include "ccrypto.hxx"

/**
 **********************************************************************
 *  Class: cCipher
 *
 * Author: $author$
 *   Date: 1/9/2005
 **********************************************************************
 */
class cCipher
: virtual public cCipherImplement,
  public cCrypto
{
public:
    typedef cCrypto cIs;

    BYTE m_padding;

    /**
     **********************************************************************
     * Constructor: cCipher
     *
     *      Author: $author$
     *        Date: 1/9/2005
     **********************************************************************
     */
    cCipher(BYTE padding=0)
    : m_padding(padding)
    {
    }
};

#endif /* _CCIPHER_HXX */
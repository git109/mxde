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
 *   File: csslciphertype.hxx
 *
 * Author: $author$
 *   Date: 2/13/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCIPHERTYPE_HXX
#define _CSSLCIPHERTYPE_HXX

#include "ccipheralgorithm.hxx"
#include "ccipher.hxx"

/**
 **********************************************************************
 *  Class: cSSLCipherType
 *
 * Author: $author$
 *   Date: 1/23/2005
 **********************************************************************
 */
class cSSLCipherType
{
public:
    int m_algorithm, m_keysize, m_ivsize;
    bool m_is_exportable;
    cCipher *m_read_cipher, *m_write_cipher;

    /**
     **********************************************************************
     * Constructor: cSSLCipherType
     *
     *      Author: $author$
     *        Date: 2/13/2005
     **********************************************************************
     */
    cSSLCipherType
    (int algorithm=cCipherAlgorithm::e_NONE,
     int keysize=0, int ivsize=0, bool is_exportable=false,
     cCipher *read_cipher=0, cCipher *write_cipher=0) 
    : m_algorithm(algorithm),
      m_keysize(keysize),
      m_ivsize(ivsize),
      m_is_exportable(is_exportable),
      m_read_cipher(read_cipher),
      m_write_cipher(write_cipher)
    {
    }
    /**
     **********************************************************************
     * Function: GetAlgorithm
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    virtual int GetAlgorithm() const 
    {
        return m_algorithm;
    }
    /**
     **********************************************************************
     * Function: GetIsExportable
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    virtual int GetIsExportable() const 
    {
        return m_is_exportable;
    }
};

#endif /* _CSSLCIPHERTYPE_HXX */
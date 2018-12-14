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
 *   File: csslhashtype.hxx
 *
 * Author: $author$
 *   Date: 2/13/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLHASHTYPE_HXX
#define _CSSLHASHTYPE_HXX

#include "chash.hxx"
#include "chashalgorithm.hxx"

/**
 **********************************************************************
 *  Class: cSSLHashType
 *
 * Author: $author$
 *   Date: 1/23/2005
 **********************************************************************
 */
class cSSLHashType
{
public:
    int m_algorithm;
    cHash *m_hash;

    /**
     **********************************************************************
     * Constructor: cSSLHashType
     *
     *      Author: $author$
     *        Date: 2/13/2005
     **********************************************************************
     */
    cSSLHashType
    (int algorithm=cHashAlgorithm::e_NONE,
     cHash *hash=0) 
    : m_algorithm(algorithm),
      m_hash(hash)
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
     * Function: GetHashSize
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    virtual int GetHashSize() const 
    {
        int size = -1;

        if (m_hash)
            size = m_hash->GetHashSize();

        return size;
    }
};

#endif /* _CSSLHASHTYPE_HXX */

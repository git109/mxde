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
 *   File: cx509hash.hxx
 *
 * Author: $author$
 *   Date: 2/6/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509HASH_HXX
#define _CX509HASH_HXX

#include "chashalgorithm.hxx"
#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cX509Hash
 *
 * Author: $author$
 *   Date: 2/6/2005
 **********************************************************************
 */
class cX509Hash
{
public:
    cBYTEBuffer m_buffer;

    int m_algorithm;

    /**
     **********************************************************************
     * Constructor: cX509Hash
     *
     *      Author: $author$
     *        Date: 2/6/2005
     **********************************************************************
     */
    cX509Hash
    (const BYTE *hash=0, int length=-1, 
     int algorithm=cHashAlgorithm::e_NONE) 
    : m_algorithm(algorithm)
    {
        eError error;

        if (hash)
        if (0 > (length = Set(hash, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream, int length=-1) 
    {
        length = m_buffer.CopyStream(stream, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    int Set(const BYTE *hash, int length=-1) 
    {
        length = m_buffer.Copy(hash, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: MD5Verify
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError MD5Verify(const BYTE *hash, int length=-1) 
    {
        eError error = e_ERROR_FAILED;

        if (cHashAlgorithm::e_MD5 == m_algorithm)
            error = Verify(hash, length);

        return error;
    }
    /**
     **********************************************************************
     * Function: SHA1Verify
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError SHA1Verify(const BYTE *hash, int length=-1) 
    {
        eError error = e_ERROR_FAILED;

        if (cHashAlgorithm::e_SHA1 == m_algorithm)
            error = Verify(hash, length);

        return error;
    }
    /**
     **********************************************************************
     * Function: Verify
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    eError Verify(const BYTE *hash, int length=-1) 
    {
        eError error = e_ERROR_FAILED;
        int cmp;

        if (!(cmp = m_buffer.Compare(hash, length)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: SetMD5Verify
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError SetMD5Verify() 
    {
        eError error = e_ERROR_NONE;
        m_algorithm = cHashAlgorithm::e_MD5;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetSHA1Verify
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    eError SetSHA1Verify() 
    {
        eError error = e_ERROR_NONE;
        m_algorithm = cHashAlgorithm::e_SHA1;
        return error;
    }
};

#endif /* _CX509HASH_HXX */
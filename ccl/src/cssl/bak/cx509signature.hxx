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
 *   File: cx509signature.hxx
 *
 * Author: $author$
 *   Date: 2/2/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509SIGNATURE_HXX
#define _CX509SIGNATURE_HXX

#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cX509Signature
 *
 * Author: $author$
 *   Date: 2/2/2005
 **********************************************************************
 */
class cX509Signature
{
public:
    cBYTEBuffer 
        m_signature, m_hash;

    /**
     **********************************************************************
     * Constructor: cX509Signature
     *
     *      Author: $author$
     *        Date: 2/2/2005
     **********************************************************************
     */
    cX509Signature() 
    {
    }
    /**
     **********************************************************************
     * Function: GetSignature
     *
     *   Author: $author$
     *     Date: 2/2/2005
     **********************************************************************
     */
    inline const BYTE* GetSignature(int &length) const 
    {
        const BYTE* buffer = m_signature.GetBuffer(length);
        return buffer;
    }
    /**
     **********************************************************************
     * Function: GetHash
     *
     *   Author: $author$
     *     Date: 2/2/2005
     **********************************************************************
     */
    inline const BYTE* GetHash(int &length) const 
    {
        const BYTE* buffer = m_hash.GetBuffer(length);
        return buffer;
    }
};

#endif /* _CX509SIGNATURE_HXX */
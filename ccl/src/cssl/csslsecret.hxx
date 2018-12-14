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
 *   File: csslsecret.hxx
 *
 * Author: $author$
 *   Date: 2/12/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLSECRET_HXX
#define _CSSLSECRET_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "csslkeyblock.hxx"

/**
 **********************************************************************
 *  Class: cSSLSecret
 *
 * Author: $author$
 *   Date: 2/12/2005
 **********************************************************************
 */
class cSSLSecret
{
public:
    cBYTEBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cSSLSecret
     *
     *      Author: $author$
     *        Date: 2/12/2005
     **********************************************************************
     */
    cSSLSecret() 
    {
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Set
    (cSSLKeyBlock &keyblock,
     const cSSLMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello,
     int length)
    {
        int count, size = -e_ERROR_FAILED;
        BYTE *buffer;

        if (0 < (count = m_buffer.SetLength(length)))
        if ((buffer = m_buffer.GetWriteBuffer(count)))
        if (count == length)
        if (0 < (count = keyblock.Read
            (buffer, length, secret, 
             client_hello, server_hello)))
            size = count;

        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int operator != (const cSSLSecret &secret) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLSECRET_HXX */

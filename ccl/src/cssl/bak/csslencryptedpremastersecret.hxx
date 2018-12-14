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
 *   File: csslencryptedpremastersecret.hxx
 *
 * Author: $author$
 *   Date: 2/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLENCRYPTEDPREMASTERSECRET_HXX
#define _CSSLENCRYPTEDPREMASTERSECRET_HXX

#include "platform.h"
#include "cbytebuffer.hxx"
#include "cbytestream.hxx"
#include "csslpremastersecret.hxx"
#include "crsapublickey.hxx"

/**
 **********************************************************************
 *  Class: cSSLEncryptedPreMasterSecret
 *
 * Author: $author$
 *   Date: 2/7/2005
 **********************************************************************
 */
class cSSLEncryptedPreMasterSecret
{
public:

    cBYTEBuffer &m_buffer;

    /**
     **********************************************************************
     * Constructor: cSSLEncryptedPreMasterSecret
     *
     *      Author: $author$
     *        Date: 2/7/2005
     **********************************************************************
     */
    cSSLEncryptedPreMasterSecret(cBYTEBuffer &buffer) 
    : m_buffer(buffer)
    {
    }
    /**
     **********************************************************************
     * Constructor: cSSLEncryptedPreMasterSecret
     *
     *      Author: $author$
     *        Date: 2/7/2005
     **********************************************************************
     */
    cSSLEncryptedPreMasterSecret
    (cBYTEBuffer &buffer,
     cBYTEStream &random,
     const cSSLPreMasterSecret &secret,
     cRSAPublicKey &rsa_public) 
    : m_buffer(buffer) 
    {
        eError error;
        int size;

        if (0 > (size = Set(random, secret, rsa_public)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Copy(const cSSLEncryptedPreMasterSecret &secret)
    {
        int length, size = -e_ERROR_FAILED;;
        const BYTE *buffer;

        if ((&secret == this) 
            || (&m_buffer == &secret.m_buffer))
            return size = Sizeof();

        if ((buffer = secret.m_buffer.GetBuffer(length)))
            size = m_buffer.Copy(buffer, length);

        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Set
    (cBYTEStream &random,
     const cSSLPreMasterSecret &secret,
     cRSAPublicKey &rsa_public)
    {
        static const BYTE block_type[2] = {'\x00', '\x02'};
        int count, random_size, secret_size, modulus_size, size = -e_ERROR_FAILED;
        BYTE *buffer;

        if (0 < (secret_size = secret.Sizeof()))
        if (0 < (modulus_size = rsa_public.GetModulusSize()))
        if (modulus_size >= secret_size+4)
        {
            random_size = modulus_size-secret_size-3;

            if (0 <= (count = m_buffer.Clear()))
            if (2 == (count = m_buffer.Write(block_type, 2)))
            if (random_size == (count = m_buffer.WriteStream(random, random_size)))
            if (1 == (count = m_buffer.Write(block_type, 1)))
            if (secret_size == (count = secret.Write(m_buffer)))
            if ((buffer = m_buffer.GetWriteBuffer()))
            if (modulus_size == (count = rsa_public.
                Encrypt(buffer, modulus_size, buffer, modulus_size)))
                size = count;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream, int size=-1) 
    {
        size = m_buffer.CopyStream(stream, size);
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int length, size = -e_ERROR_FAILED;
        const BYTE *buffer;

        if ((buffer = m_buffer.GetBuffer(length)))
            size = stream.Write(buffer, length);

        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = m_buffer.GetLength();
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 2/7/2005
     **********************************************************************
     */
    int operator != (const cSSLEncryptedPreMasterSecret &secret) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLENCRYPTEDPREMASTERSECRET_HXX */

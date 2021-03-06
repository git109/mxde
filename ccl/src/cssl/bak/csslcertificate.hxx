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
 *   File: csslcertificate.hxx
 *
 * Author: $author$
 *   Date: 1/21/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCERTIFICATE_HXX
#define _CSSLCERTIFICATE_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "cssltofrom.hxx"

/**
 **********************************************************************
 *  Class: cSSLCertificate
 *
 * Author: $author$
 *   Date: 1/21/2005
 **********************************************************************
 */
class cSSLCertificate
{
public:
    uint32 m_size;
    uint24 m_sizeof;
    cBYTEBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cSSLCertificate
     *
     *      Author: $author$
     *        Date: 1/21/2005
     **********************************************************************
     */
    cSSLCertificate() 
    {
        fromint(m_sizeof, 0);
        m_size = toint(m_sizeof);
    }
    /**
     **********************************************************************
     * Constructor: cSSLCertificate
     *
     *      Author: $author$
     *        Date: 1/21/2005
     **********************************************************************
     */
    cSSLCertificate(const BYTE *buffer, int length) 
    {
        eError error;
        int size;

        if (0 > (size = Set(buffer, length)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_sizeof)+toint(m_sizeof);
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Copy(const cSSLCertificate &certificate)
    {
        int size;
        const BYTE *buffer;
        
        if (&certificate == this)
            return size = Sizeof();

        if (0 > (size = certificate.GetSizeof()))
            return size;

        if (!(buffer = certificate.GetBytes()))
            return size = -e_ERROR_FAILED;

        size = Set(buffer, size);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Set(const BYTE *buffer, int length)
    {
        int size;

        if (0 > (size = m_buffer.Copy(buffer, length)))
            return size;

        fromint(m_sizeof, size);
        m_size = toint(m_sizeof);
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int length, size;
        BYTE *buffer;

        if (0 > (size = stream.ReadUInt24MSB(m_sizeof)))
            return size;

        length = toint(m_sizeof);

        if (0 > (size = m_buffer.SetLength(length)))
            return size;

        if (0 > (size = m_buffer.Seek(0)))
            return size;

        if (!(buffer = m_buffer.GetWriteBuffer()))
            return size = -e_ERROR_FAILED;

        if ((size = stream.Read(buffer, length)) < length)
        if (size > 0)
            return size = -e_ERROR_RETURN_SIZE_UNDER;
        else return size;

        m_size = toint(m_sizeof);
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int length,size;
        const BYTE *buffer;

        length = toint(m_sizeof);

        if (!(buffer = m_buffer.GetBuffer()))
            return size = -e_ERROR_FAILED;

        if (0 > (size = stream.WriteUInt24MSB(m_sizeof)))
            return size;

        if ((size = stream.Write(buffer, length)) < length)
        if (size > 0)
            return size = -e_ERROR_RETURN_SIZE_UNDER;
        else return size;

        return size;
    }
    /**
     **********************************************************************
     * Function: GetSizeof
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    inline int GetSizeof() const
    {
        return toint(m_sizeof);
    }
    /**
     **********************************************************************
     * Function: GetBytes
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    inline const BYTE *GetBytes() const
    {
        return m_buffer.GetBuffer();
    }
    /**
     **********************************************************************
     * Function: GetBytes
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    inline const BYTE *GetBytes(int &length) const
    {
        return m_buffer.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    inline cBYTEBuffer &GetBuffer()
    {
        return m_buffer;
    }
};

#endif /* _CSSLCERTIFICATE_HXX */

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
 *   File: csslplaintext.hxx
 *
 * Author: $author$
 *   Date: 1/17/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLPLAINTEXT_HXX
#define _CSSLPLAINTEXT_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "csslversion.hxx"
#include "csslalert.hxx"
#include "csslhandshake.hxx"
#include "cssl2plaintext.hxx"

/**
 **********************************************************************
 *  Class: cSSLPlaintext
 *
 * Author: $author$
 *   Date: 1/17/2005
 **********************************************************************
 */
class cSSLPlaintext
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/17/2005
     **********************************************************************
     */
    enum
    {
        e_NONE                  = -1,
        e_CHANGE_CIPHER_SPEC    = 20,
        e_ALERT                 = 21,
        e_HANDSHAKE             = 22,
        e_APPLICATION_DATA      = 23,
        e_VERSION2_MESSAGE_MASK = 127,
        e_VERSION2_MESSAGE_BIT  = 128,
        e_VERSION2_MESSAGE      = e_VERSION2_MESSAGE_BIT
    };

	bool m_is_version2;
    uint8 m_type;
    cSSLVersion m_version;
    uint16 m_sizeof;
    cBYTEBuffer m_buffer;

    cSSLAlert m_alert;
    cSSLHandshake m_handshake;
    cSSL2Plaintext m_version2_plaintext;

    /**
     **********************************************************************
     * Constructor: cSSLPlaintext
     *
     *      Author: $author$
     *        Date: 1/17/2005
     **********************************************************************
     */
    cSSLPlaintext() 
    : m_is_version2(false),
	  m_type(e_NONE),
      m_sizeof(0)
    {
    }
    /**
     **********************************************************************
     * Constructor: cSSLPlaintext
     *
     *      Author: $author$
     *        Date: 1/17/2005
     **********************************************************************
     */
    cSSLPlaintext
    (const cSSLVersion &version, 
     const cSSLHandshake &handshake) 
    {
        eError error;
        int size;

        if (0 > (size = Set(version, handshake)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/17/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_type)
                   +m_version.Sizeof()
                   +sizeof(m_sizeof)+m_sizeof;
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/17/2005
     **********************************************************************
     */
    int Copy(const cSSLPlaintext &plaintext)
    {
        int size;
        
        if (&plaintext == this)
            return size = Sizeof();

        size = -e_ERROR_NOT_IMPLEMENTED;
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/17/2005
     **********************************************************************
     */
    int Set
    (const cSSLVersion &version, 
     const cSSLHandshake &handshake)
    {
        int size;

        if (0 > (size = m_version.Copy(version)))
            return size;

        if (0 > (size = m_handshake.Copy(handshake)))
            return size;

        m_type = e_HANDSHAKE;
        m_sizeof = size;
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: ReadVersion2
     *
     *   Author: $author$
     *     Date: 1/17/2005
     **********************************************************************
     */
    int ReadVersion2(cBYTEStream &stream) 
    {
        int size;
        uint16 version2_size;

        if (0 > (size = stream.Getb()))
            return size;

        version2_size = (e_VERSION2_MESSAGE_MASK & m_type);
        version2_size = (version2_size << 8) | size;

        if (0 > (size = m_version2_plaintext.Read(stream, version2_size)))
            return size;

        m_type = e_VERSION2_MESSAGE;
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/17/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;
        BYTE *buffer;

        if (0 > (size = stream.Getb()))
            return size;

        if ((m_is_version2 = (e_VERSION2_MESSAGE_BIT 
			== (e_VERSION2_MESSAGE_BIT & (m_type = size)))))
            return size = ReadVersion2(stream);

        if (0 > (size = m_version.Read(stream)))
            return size;

        if ((size = stream.ReadUInt16MSB(m_sizeof)) < sizeof(m_sizeof))
        if (size > 0)
            return size = -e_ERROR_RETURN_SIZE_UNDER;
        else return size;

        if (0 > (size = m_buffer.SetLength(m_sizeof)))
            return size;

        if (0 > (size = m_buffer.Seek(0)))
            return size;

        if (!(buffer = m_buffer.GetWriteBuffer()))
            return size = -e_ERROR_FAILED;

        if ((size = stream.Read(buffer, m_sizeof)) < m_sizeof)
        if (size > 0)
            return -e_ERROR_RETURN_SIZE_UNDER;
        else return size;

        switch(m_type)
        {
        case e_HANDSHAKE:
            if (0 > (size = m_handshake.Read(m_buffer)))
                return size;
            break;
        default:
            return size = -e_ERROR_INVALID_RETURN_TYPE;
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/17/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = stream.Putb(m_type)))
            return size;

        if (0 > (size = m_version.Write(stream)))
            return size;

        if ((size = stream.WriteUInt16MSB(m_sizeof)) < sizeof(m_sizeof))
        if (size > 0)
            return size = -e_ERROR_RETURN_SIZE_UNDER;
        else return size;

        switch(m_type)
        {
        case e_HANDSHAKE:
            if (0 > (size = m_handshake.Write(stream)))
                return size;
            break;
        default:
            return size = -e_ERROR_INVALID_PARAMETER_TYPE;
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    inline uint8 GetType() const 
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetVersion
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    inline cSSLVersion& GetVersion() 
    {
        return m_version;
    }
    /**
     **********************************************************************
     * Function: GetHandshake
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    inline cSSLHandshake& GetHandshake() 
    {
        return m_handshake;
    }
    /**
     **********************************************************************
     * Function: GetVersion2Plaintext
     *
     *   Author: $author$
     *     Date: 10/16/2007
     **********************************************************************
     */
    inline cSSL2Plaintext& GetVersion2Plaintext() 
    {
        return m_version2_plaintext;
    }
    /**
     **********************************************************************
     * Function: GetIsVersion2
     *
     *   Author: $author$
     *     Date: 10/16/2007
     **********************************************************************
     */
    inline bool GetIsVersion2() const
    {
        return m_is_version2;
    }
};

#endif /* _CSSLPLAINTEXT_HXX */

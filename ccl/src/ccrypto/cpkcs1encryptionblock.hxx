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
 *   File: cpkcs1encryptionblock.hxx
 *
 * Author: $author$
 *   Date: 2/5/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPKCS1ENCRYPTIONBLOCK_HXX
#define _CPKCS1ENCRYPTIONBLOCK_HXX

#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cPKCS1EncryptionBlock
 *
 * Author: $author$
 *   Date: 2/5/2005
 **********************************************************************
 */
class cPKCS1EncryptionBlock
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/5/2005
     **********************************************************************
     */
    enum
    {
        e_TYPE_NONE  = -1,
        e_FIRST_TYPE = 0,

        e_TYPE_00_PADDED = 0,
        e_TYPE_FF_PADDED = 1,
        e_TYPE_XX_PADDED = 2,

        e_NEXT_TYPE,
        e_LAST_TYPE = e_NEXT_TYPE-1
    };

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/5/2005
     **********************************************************************
     */
    enum
    {
        e_PUBLIC_KEY_OPERATION_TYPE_MIN = e_TYPE_XX_PADDED,
        e_PUBLIC_KEY_OPERATION_TYPE_MAX = e_TYPE_XX_PADDED
    };

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/5/2005
     **********************************************************************
     */
    enum
    {
        e_PRIVATE_KEY_OPERATION_TYPE_MIN = e_TYPE_00_PADDED,
        e_PRIVATE_KEY_OPERATION_TYPE_MAX = e_TYPE_FF_PADDED
    };

    BYTE m_type;
    cBYTEBuffer m_padding, m_data;

    /**
     **********************************************************************
     * Constructor: cPKCS1EncryptionBlock
     *
     *      Author: $author$
     *        Date: 2/5/2005
     **********************************************************************
     */
    cPKCS1EncryptionBlock() 
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream)
    {
        int byte, count, length = 0;

        if (0 > (count = m_padding.Clear()))
            return count;

        if (0 > (count = m_data.Clear()))
            return count;

        if (0 > (byte = stream.Getb()))
            return byte;

        if (byte)
            return -e_ERROR_INVALID_RETURN_TYPE;

        if (0 > (byte = stream.Getb()))
            return byte;

        switch(byte)
        {
        case e_TYPE_00_PADDED:
            if (0 > (length = Read00(stream)))
                return length;
            break;

        case e_TYPE_FF_PADDED:
            if (0 > (length = ReadFF(stream)))
                return length;
            break;

        case e_TYPE_XX_PADDED:
            if (0 > (length = ReadXX(stream)))
                return length;
            break;

        default:
            return -e_ERROR_INVALID_RETURN_TYPE;
        }

        m_type = byte;
        return length+2;
    }
    /**
     **********************************************************************
     * Function: Read00
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    int Read00(cBYTEStream &stream)
    {
        int byte, count, length = 0;

        do
        {
            if (0 > (byte = stream.Getb()))
                return byte;

            if (byte)
            {
                if (0 > (byte = m_data.Putb(byte)))
                    return byte;
            }
            else if (0 > (byte = m_padding.Putb(byte)))
                    return byte;

            length++;
        }
        while (!byte);

        if (0 > (count = ReadData(stream)))
            return count;

        return length+count;
    }
    /**
     **********************************************************************
     * Function: ReadFF
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    int ReadFF(cBYTEStream &stream)
    {
        int byte, count, length = 0;

        do
        {
            if (0 > (byte = stream.Getb()))
                return byte;

            if ((byte) && (0xFF != byte))
                return -e_ERROR_INVALID_RETURN_TYPE;

            if (0 > (byte = m_padding.Putb(byte)))
                return byte;

            length++;
        }
        while (byte);

        if (0 > (count = ReadData(stream)))
            return count;

        return length+count;
    }
    /**
     **********************************************************************
     * Function: ReadXX
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    int ReadXX(cBYTEStream &stream)
    {
        int byte, count, length = 0;

        do
        {
            if (0 > (byte = stream.Getb()))
                return byte;

            if (0 > (byte = m_padding.Putb(byte)))
                return byte;

            length++;
        }
        while (byte);

        if (0 > (count = ReadData(stream)))
            return count;

        return length+count;
    }
    /**
     **********************************************************************
     * Function: ReadData
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    int ReadData(cBYTEStream &stream)
    {
        int count, length;
            
        if (0 < (length = m_data.WriteStream(stream)))
        if (0 > (count = m_data.Seek(0)))
            return count;

        return length;
    }
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    inline const BYTE *GetData(int &length) const
    {
        const BYTE *data = m_data.GetBuffer(length);
        return data;
    }
    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    inline int SetType(int type) 
    {
        m_type = type;
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 2/5/2005
     **********************************************************************
     */
    inline int GetType() const 
    {
        return m_type;
    }
};

#endif /* _CPKCS1ENCRYPTIONBLOCK_HXX */
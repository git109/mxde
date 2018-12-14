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
 *   File: cssl2plaintext.hxx
 *
 * Author: $author$
 *   Date: 1/17/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSL2PLAINTEXT_HXX
#define _CSSL2PLAINTEXT_HXX

#include "cssl2message.hxx"
#include "cssl2recordheader.hxx"
#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cSSL2Plaintext
 *
 * Author: $author$
 *   Date: 1/17/2005
 **********************************************************************
 */
class cSSL2Plaintext
{
public:
    cSSL2RecordHeader m_record_header;
    cSSL2Message m_message;
    cBYTEBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cSSL2Plaintext
     *
     *      Author: $author$
     *        Date: 1/17/2005
     **********************************************************************
     */
    cSSL2Plaintext() 
    {
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
        int size = m_record_header.Sizeof();
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
    int Copy(const cSSL2Plaintext &plaintext)
    {
        int size = Sizeof();
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
    int Set()
    {
        int size = Sizeof();
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
    int Read(cBYTEStream &stream, uint16 size) 
    {
        int count, length;
        BYTE *buffer;

        if (0 > (count = m_record_header.Read(stream, size)))
            return count;

        size = m_record_header.GetLength();

        if (0 > (length = m_buffer.SetLength(size)))
            return length;

        if (0 > (length = m_buffer.Seek(0)))
            return length;

        if (!(buffer = m_buffer.GetWriteBuffer()))
            return -e_ERROR_FAILED;

        if ((length = stream.Read(buffer, size)) < size)
        if (length > 0)
            return -e_ERROR_RETURN_SIZE_UNDER;

        m_message.Read(m_buffer);
        count += length;
        return count;
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
        return size;
    }
};

#endif /* _CSSL2PLAINTEXT_HXX */

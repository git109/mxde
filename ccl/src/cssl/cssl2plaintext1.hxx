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
    uint16 m_sizeof;
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
    : m_sizeof(0)
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
        int size = sizeof(m_sizeof)+m_sizeof;
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
     *     Date: 10/17/2007
     **********************************************************************
     */
    int Read(cBYTEStreamInterface &stream) 
    {
        int count = m_record_header.Read(stream);
        return count;
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
        int count;
        BYTE *buffer;

        if (0 > (count = m_buffer.SetLength(size)))
            return count;

        if (0 > (count = m_buffer.Seek(0)))
            return count;

        if (!(buffer = m_buffer.GetWriteBuffer()))
            return count = -e_ERROR_FAILED;

        if ((count = stream.Read(buffer, size)) < size)
        if (count > 0)
            return count = -e_ERROR_RETURN_SIZE_UNDER;

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

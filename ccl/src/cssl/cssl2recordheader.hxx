/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cssl2recordheader.hxx
 *
 * Author: $author$
 *   Date: 10/17/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSSL2RECORDHEADER_HXX
#define _CSSL2RECORDHEADER_HXX

#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSL2RecordHeader
 *
 * Author: $author$
 *   Date: 10/17/2007
 **********************************************************************
 */
class cSSL2RecordHeader
{
public:
    typedef cSSL2RecordHeader cDerives;

    enum { e_PADDED_MASK = 0x80};
    enum { e_ESCAPE_MASK = 0x40};

    bool m_is_padded;
    bool m_is_escape;
    uint16 m_length;
    uint8 m_padded;
    uint8 m_padding;
    uint8 m_byte[2];

    /**
     **********************************************************************
     * Constructor: cSSL2RecordHeader
     *
     *      Author: $author$
     *        Date: 10/17/2007
     **********************************************************************
     */
    cSSL2RecordHeader() 
    : m_is_padded(false),
      m_is_escape(false),
      m_length(0),
      m_padded(0)
    {
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
        int count, length;

        if (2 <= (count = stream.Read(m_byte, 2)))
        if (0 <= (length = ReadPadding(stream)))
            count += length;
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/17/2007
     **********************************************************************
     */
    int Read(cBYTEStreamInterface &stream, uint16 size) 
    {
        int count, length;

        m_byte[0] = (size >> 8);
        m_byte[1] = (size & 0xFF);

        if (0 > (length = ReadPadding(stream)))
            return length;

        count = length + 2;
        return count;
    }
    /**
     **********************************************************************
     * Function: ReadPadding
     *
     *   Author: $author$
     *     Date: 10/17/2007
     **********************************************************************
     */
    int ReadPadding(cBYTEStreamInterface &stream) 
    {
        int length = 0;
        uint8 padded_mask;

        m_is_escape = false;
        m_padded = 0;

        if ((m_is_padded = (e_PADDED_MASK
            != ((padded_mask = e_PADDED_MASK) & m_byte[0]))))
        {
            if (1 > (length = stream.Read(&m_padding, (m_padded = 1))))
                return -e_ERROR_FAILED;

            m_is_escape = (e_ESCAPE_MASK 
            == (e_ESCAPE_MASK & m_byte[0]));

            padded_mask |= e_ESCAPE_MASK;
        }

        m_length = ((m_byte[0] & ~padded_mask) << 8) | m_byte[1];
        return length;
    }

    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 10/17/2007
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_length)+m_padded+m_length;
        return size;
    }

    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 10/17/2007
     **********************************************************************
     */
    inline uint16 GetLength() const
    {
        return m_length;
    }
};

#endif /* _CSSL2RECORDHEADER_HXX */

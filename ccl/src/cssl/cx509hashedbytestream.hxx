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
 *   File: cx509hashedbytestream.hxx
 *
 * Author: $author$
 *   Date: 2/1/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509HASHEDBYTESTREAM_HXX
#define _CX509HASHEDBYTESTREAM_HXX

#include "cbytestream.hxx"
#include "chash.hxx"

/**
 **********************************************************************
 *  Class: cX509HashedBYTEStream
 *
 * Author: $author$
 *   Date: 2/1/2005
 **********************************************************************
 */
class cX509HashedBYTEStream
: public cBYTEStream
{
public:
    typedef cBYTEStream cIs;

    unsigned &m_hashed;
    cBYTEStream &m_stream;
    cHash &m_md5, &m_sha1;

    unsigned m_count;

    /**
     **********************************************************************
     * Constructor: cX509HashedBYTEStream
     *
     *      Author: $author$
     *        Date: 2/1/2005
     **********************************************************************
     */
    cX509HashedBYTEStream
    (unsigned &hashed, cBYTEStream &stream, 
     cHash &md5, cHash &sha1) 
    : m_hashed(hashed),
      m_stream(stream),
      m_md5(md5),
      m_sha1(sha1),
      m_count(0)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int Read(BYTE *buffer, int size=-1) 
    {
        int byte, result;

        if (0 > size)
            size = strlen((const char*)buffer);

        for (result=0; size>0; --size, result++)
        {
            if (0 > (byte = Getb()))
                return byte;

            buffer[result] = byte;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int Getb() 
    {
        int byte, result;
        BYTE hashed;

        if (0 <= (byte = m_stream.Getb()))
        {
            if (m_hashed)
            {
                hashed = byte;

                if (0 > (result = m_md5.Hash(&hashed, sizeof(hashed))))
                    return result;

                if (0 > (result = m_sha1.Hash(&hashed, sizeof(hashed))))
                    return result;

                m_count++;
                --m_hashed;

                if (!m_hashed)
                    hashed = 0;
            }
        }
        return byte;
    }
};

#endif /* _CX509HASHEDBYTESTREAM_HXX */
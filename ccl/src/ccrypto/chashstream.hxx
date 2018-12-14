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
 *   File: chashstream.hxx
 *
 * Author: $author$
 *   Date: 1/18/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHASHSTREAM_HXX
#define _CHASHSTREAM_HXX

#include "ccharstream.hxx"
#include "cbytestream.hxx"
#include "chash.hxx"

/**
 **********************************************************************
 *  Class: cHashStreamT
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
template
<class TAs,
 class THash=cHash,
 class TChar=BYTE,
 class TBuffer=cBYTEBuffer,
 class TIs=cBYTEStream>
class cHashStreamT
: public TIs
{
public:
    typedef TIs cIs;

    THash &m_hash;
    TBuffer m_write_cache, m_read_cache;
    int m_write_cachesize, m_read_cachesize, m_read_cachelen;

    /**
     **********************************************************************
     * Constructor: cHashStreamT
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cHashStreamT(THash &hash) 
    : m_hash(hash)
    {
        m_write_cachesize = hash.GetBlockSize();
        m_read_cachesize = hash.GetHashSize();
        m_read_cachelen = 0;
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key=0, int keylen=-1)
    {
        int cachesize;

        if (0 > (cachesize = m_write_cache.Clear()))
            return cachesize;

        if (0 > (cachesize = m_read_cache.Clear()))
            return cachesize;

        m_read_cachelen = 0;
        keylen = m_hash.Initialize(key, keylen);
        return keylen;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    virtual int Finalize
    (BYTE *out, int outsize)
    {
        int cachesize;

        if (0 > (cachesize = Flush()))
            return cachesize;

        outsize = m_hash.Finalize(out, outsize);
        return outsize;
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 3/6/2005
     **********************************************************************
     */
    virtual int Fill() 
    {
        int length, cachesize;
        TChar *cache;

        if (0 < m_read_cachelen)
            return 0;

        if (0 > (cachesize = m_read_cache.SetLength(m_read_cachesize)))
            return cachesize;

        if ((m_read_cachesize != (cachesize = m_read_cache.GetLength()))
            || !(cache = m_read_cache.GetWriteBuffer()))
            return -e_ERROR_FAILED;

        if (m_read_cachesize != (length = Finalize(cache, cachesize)))
        if (0 > length)
            return length;
        else return -e_ERROR_FAILED;

        m_read_cachelen = cachesize;
        return cachesize;
    }
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    virtual int Flush() 
    {
        int length, cachesize;
        const TChar *cache;

        if (0 >= (cachesize = m_write_cache.GetLength()))
            return cachesize;

        if (!(cache = m_write_cache.GetBuffer()))
            return -e_ERROR_FAILED;

        if ((length = m_hash.Hash
            (cache, cachesize)) < cachesize)
        if (length > 0)
            return -e_ERROR_RETURN_SIZE_UNDER;
        else return length;

        if (0 > (length = m_write_cache.Clear()))
            return length;

        return cachesize;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/1/2005
     **********************************************************************
     */
    virtual int Read
    (TChar* buffer, int size=-1) 
    {
        int length, count = 0;

        if (0 > (length = Fill()))
            return length;

        count = m_read_cache.Read(buffer, size);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/18/2005
     **********************************************************************
     */
    virtual int Write
    (const TChar* buffer, int size=-1) 
    {
        int count, fill, length;
        const TChar *cache;

        if (0 > size)
            size = strlen((const char*)buffer);

        count = 0;

        while (m_write_cachesize <= size+(length = m_write_cache.GetLength()))
        {
            fill = m_write_cachesize-length;

            if (fill != (length = m_write_cache.Write(buffer, fill)))
            if (length > 0)
                return -e_ERROR_RETURN_SIZE_UNDER;
            else return length;

            if (0 > (length = Flush()))
                return length;

            buffer += fill;
            size -= fill;
            count += fill;
        }

        if (0 < size)
        if (size != (length = m_write_cache.Write(buffer, size)))
        if (length > 0)
            return -e_ERROR_RETURN_SIZE_UNDER;
        else return length;
        else count += size;

        return count;
    }
};

/**
 **********************************************************************
 *  Class: cHashStream
 *
 * Author: $author$
 *   Date: 1/18/2005
 **********************************************************************
 */
class cHashStream
: public cHashStreamT<cHashStream>
{
public:
    typedef cHashStreamT<cHashStream> cIs;

    /**
     **********************************************************************
     * Constructor: cHashStream
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cHashStream(cHash &hash) 
    : cIs(hash) 
    {
    }
};

#endif /* _CHASHSTREAM_HXX */
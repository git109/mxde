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
 class TChar=BYTE,
 class TBuffer=cBYTEBuffer,
 class TIs=cBYTEStream>
class cHashStreamT
: public TIs
{
public:
    typedef TIs cIs;

    cHash &m_hash;
    TBuffer m_cache;
    int m_cachesize;

    /**
     **********************************************************************
     * Constructor: cHashStreamT
     *
     *      Author: $author$
     *        Date: 1/18/2005
     **********************************************************************
     */
    cHashStreamT(cHash &hash) 
    : m_hash(hash)
    {
        m_cachesize = hash.GetBlockSize();
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

        if (0 > (cachesize = m_cache.Clear()))
            return cachesize;

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

        if (0 >= (cachesize = m_cache.GetLength()))
            return cachesize;

        if (!(cache = m_cache.GetBuffer()))
            return -e_ERROR_FAILED;

        if ((length = m_hash.Hash
            (cache, cachesize)) < cachesize)
        if (length > 0)
            return -e_ERROR_RETURN_SIZE_UNDER;
        else return length;

        if (0 > (length = m_cache.Clear()))
            return length;

        return cachesize;
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

        while (m_cachesize <= (fill = size)+(length = m_cache.GetLength()))
        {
            fill = m_cachesize-length;

            if ((length = m_cache.Write(buffer, fill)) < fill)
            if (length > 0)
                return -e_ERROR_RETURN_SIZE_UNDER;
            else return length;

            if (!(cache = m_cache.GetBuffer()))
                return -e_ERROR_FAILED;

            if ((length = m_hash.Hash
                (cache, m_cachesize)) < m_cachesize)
            if (length > 0)
                return -e_ERROR_RETURN_SIZE_UNDER;
            else return length;

            if (0 > (length = m_cache.Clear()))
                return length;

            buffer += fill;
            size -= fill;
            count += fill;
        }

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
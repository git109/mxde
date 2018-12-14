/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cbuffert.hxx
 *
 * Author: $author$
 *   Date: 7/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBUFFERT_HXX
#define _CBUFFERT_HXX

#include <string.h>

#include "cstreamt.hxx"

/**
 **********************************************************************
 *  Class: cBufferT
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
template 
<int VDefaultSize, class TOf,
 int VNull=0, class TIs=cStreamT<TOf,cStream> >
class cBufferT
: public TIs
{
public:
    typedef TIs cIs;

    bool m_free_buffer;
    bool m_fixed_size;
    int m_size;
    int m_length;
    int m_tell;

    const TOf *m_read_buffer;
    TOf *m_write_buffer;

    int m_default_buffer_size;
    TOf m_default_buffer[VDefaultSize];

    /**
     **********************************************************************
     * Constructor: cBufferT
     *
     *      Author: $author$
     *        Date: 7/5/2003
     **********************************************************************
     */
    cBufferT(const TOf *buffer=0, int size=-1, int length=-1) 
    : m_default_buffer_size(VDefaultSize),
      m_write_buffer(m_default_buffer),
      m_read_buffer(m_default_buffer),
      m_tell(0),
      m_length(0),
      m_size(VDefaultSize),
      m_fixed_size(false),
      m_free_buffer(false)
    {
        eError error;

        if (buffer)
        {
            if (size < 0)
            if ((size = GetLengthOf(buffer)) >= 0)
                size++;
            else throw(error = e_ERROR_INVALID_PARAMETER_SIZE);

            if (length < 0)
            if ((length = GetLengthOf(buffer)) < 0)
                throw(error = e_ERROR_INVALID_PARAMETER_SIZE);

            m_write_buffer = 0;
            m_read_buffer = buffer;
            m_size = size;
            m_length = length;
        }

        if (m_write_buffer && (m_size > 0) && (m_length < m_size))
            m_write_buffer[m_length] = VNull;
    }
    /**
     **********************************************************************
     * Destructor: ~cBufferT
     *
     *     Author: $author$
     *       Date: 7/5/2003
     **********************************************************************
     */
    virtual ~cBufferT()
    {
    }


    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/9/2003
     **********************************************************************
     */
    virtual int Compare(const TOf *buffer, int length=-1) const
    {
        const TOf *mbuffer;
        TOf of1,of2;
        int lendiff;

        if (!(mbuffer = m_read_buffer))
            return buffer?1:-1;

        if (length < 0)
            length = GetLengthOf(buffer);

        if (0 < (lendiff = (length - m_length)))
            length = m_length;
 
        if (length > 0)
        do
        {
            if ((of1 = *(buffer++)) > (of2 = *(mbuffer++)))
                return 1;

            if (of1 < of2)
                return -1;
        }
        while (--length > 0);

        return lendiff;
    }
    /**
     **********************************************************************
     * Function: In
     *
     *   Author: $author$
     *     Date: 11/29/2003
     **********************************************************************
     */
    virtual const TOf *In(TOf of, bool from_end=false) const
    {
        int i;
        const TOf *in;

        if ((in = m_read_buffer))
        if (from_end)
        {
            if (m_length > 0)
            for (in += m_length, i = m_length; i > 0; --i)
                if (of == *--in)
                    return in;
        }
        else
        {
            for (i = 0; i < m_length; i++, in++)
                if (of == *in)
                    return in;
        }
        return 0;
    }

    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    inline const TOf *GetBuffer() const
    {
        int size, length;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    inline const TOf *GetBuffer(int &length) const
    {
        int size;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    inline TOf *GetWriteBuffer(int &length) const
    {
        int size;
        return GetWriteBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual TOf *GetWriteBuffer(int &size, int &length) const
    {
        if (m_write_buffer)
        {
            size = m_size;
            length = m_length;
            return m_write_buffer;
        }
        size = -e_ERROR_NOT_DEFINED;
        length = -e_ERROR_NOT_DEFINED;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 12/7/2003
     **********************************************************************
     */
    inline TOf *GetWriteBuffer() const
    {
        int size, length;
        return GetWriteBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual const TOf *GetBuffer(int &size, int &length) const
    {
        size = m_size;
        length = m_length;
        return m_read_buffer;
    }
    /**
     **********************************************************************
     * Function: GetSize
     *
     *   Author: $author$
     *     Date: 7/17/2003
     **********************************************************************
     */
    virtual long GetSize() const
    {
        return m_size;
    }
    /**
     **********************************************************************
     * Function: SetLength
     *
     *   Author: $author$
     *     Date: 7/17/2003
     **********************************************************************
     */
    virtual long SetLength(long length)
    {
        long size;

        if (!m_write_buffer)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > length)
        if (0 > (length = GetLengthOf(m_write_buffer)))
            return -e_ERROR_FAILED;

        if (length > m_size)
        if (length > (size = SetSize(length)))
        if (size < 0)
            return size;
        else return -e_ERROR_FULL;

        m_tell=length;

        if ((m_length=m_tell)<m_size)
            m_write_buffer[m_tell]=0;

        return m_length;
    }
    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 7/17/2003
     **********************************************************************
     */
    virtual long GetLength() const
    {
        return m_length;
    }
    /**
     **********************************************************************
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual long GetLengthOf(const TOf *buffer) const
    {
        long length;
        TOf of;

        for (length = 0; (of = *buffer) != VNull; buffer++)
            length++;

        return length;
    }
    /**
     **********************************************************************
     * Function: Tell
     *
     * Author: $author$
     * Date:   7/17/2003
     **********************************************************************
     */
    virtual long Tell() const
    {
        return m_tell;
    }
    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual long Seek(long offset, int origin=e_SEEK_SET)
    {
        long tell;

        switch(origin)
        {
        case e_SEEK_SET:
            if (offset < 0)
                tell = -e_ERROR_BEGINOF;

            else if (offset > m_length)
                    tell = -e_ERROR_ENDOF;

            else tell = (m_tell = offset);
            break;

        case e_SEEK_CUR:
            if ((tell = m_tell+offset) < 0)
                tell = -e_ERROR_BEGINOF;

            else if (tell > m_length)
                    tell = -e_ERROR_ENDOF;

            else m_tell = tell;
            break;

        case e_SEEK_END:
            if (offset > 0)
                tell = -e_ERROR_ENDOF;

            else if ((tell = m_length-offset) < 0)
                    tell = -e_ERROR_BEGINOF;

            else m_tell = tell;
            break;

        default:
            tell = -e_ERROR_INVALID_PARAMETER;
        }

        return tell;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual int Clear()
    {
        int length;

        if (!m_write_buffer)
            return -e_ERROR_NOT_ATTACHED;

        length = m_length;

        if ((m_length = (m_tell = 0)) < m_size)
            m_write_buffer[m_tell] = VNull;

        return length;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual int Read(TOf *buffer, int size)
    {
        if (size<1)
            return 0;

        if (!buffer)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_read_buffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_tell >= m_length)
            return -e_ERROR_ENDOF;

        if (m_tell+size >= m_length)
            size=m_length-m_tell;

        CopyBuffer(buffer, m_read_buffer+m_tell, size);

        m_tell+=size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual int Write(const TOf *buffer, int size=-1)
    {
        eError error;
        int newsize;

        if (size<0)
            size = GetLengthOf(buffer);

        if (size<1)
            return 0;

        if (!buffer)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_write_buffer)
            return -e_ERROR_NOT_ATTACHED;

        if ((newsize = (m_tell+size)) >= m_size)
        if (m_fixed_size)
            return -e_ERROR_FULL;

        else if ((error = AdjustSize(NewSize(newsize))))
                return -error;

        CopyBuffer(m_write_buffer+m_tell, buffer, size);

        if ((m_tell += size) > m_length)
        if ((m_length = m_tell) < m_size)
            m_write_buffer[m_tell] = VNull;

        return size;
    }
    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual long SetSize(long size)
    {
        eError error;

        if (size >= m_size)
        if (m_fixed_size)
            return -e_ERROR_FULL;

        else if ((error = AdjustSize(NewSize(size))))
                return -error;

        return m_size;
    }
    /**
     **********************************************************************
     * Function: AdjustSize
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError AdjustSize(int size)
    {
        bool alloc_buffer;
        TOf *buffer;

        if (!m_write_buffer)
            return e_ERROR_NOT_ATTACHED;

        if (size<=m_size)
            return e_ERROR_NONE;

        /* Set m_free_buffer here if it has not already been
         * done to make sure the buffer will be freed upon 
         * destruction.
         */
        if ((alloc_buffer = !m_free_buffer))
            m_free_buffer = true;

        if (!(buffer = new TOf[size]))
        {
            if (alloc_buffer)
                m_free_buffer = false;

            return e_ERROR_NEW;
        }

        if (m_write_buffer)
        {
            if (m_length>0)
                CopyBuffer(buffer, m_write_buffer, m_length);

            if (m_write_buffer != m_default_buffer)
                delete m_write_buffer;
        }

        m_write_buffer=buffer;
        m_read_buffer=buffer;
        m_size=size;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: CopyBuffer
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual void CopyBuffer(TOf *to, const TOf *from, int size)
    {
        memcpy(to, from, sizeof(TOf)*size);
    }
    /**
     **********************************************************************
     * Function: NewSize
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual int NewSize(int size)
    {
        /* Lets increase the buffer size by default buffer 
         * sized chunks. Note the desired new size is always
         * needed size + 1. The size in chunks is calculated
         * as (new size + (chunk size - 1)) / chunk size.
         * since new size = needed size + 1 then we have
         * chunks = (needed size + chunk size) / chunk size.
         * Finally we need bytes which is chunks * chunk size
         * which can be reduced to 
         * ((needed size / chunk size) + 1) * chunk size
         */
        return ((size/m_default_buffer_size)+1)*m_default_buffer_size;
    }
};


#endif

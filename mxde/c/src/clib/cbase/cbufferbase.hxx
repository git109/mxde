/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cbufferbase.hxx
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
#if !defined(_CBUFFERBASE_HXX) || defined(CBUFFERBASE_MEMBERS_ONLY)
#if !defined(_CBUFFERBASE_HXX) && !defined(CBUFFERBASE_MEMBERS_ONLY)
#define _CBUFFERBASE_HXX
#endif /* !defined(_CBUFFERBASE_HXX) && !defined(CBUFFERBASE_MEMBERS_ONLY) */

#if !defined(CBUFFERBASE_MEMBERS_ONLY)
#include "cbufferbaseinterface.hxx"
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CBUFFERBASE_DEFAULT_BUFFER_SIZE 128

class c_EXPORT_CLASS cBufferBase;

#undef CDB_CLASS
#define CDB_CLASS "cBufferBaseT"
/**
 **********************************************************************
 *  Class: cBufferBaseT
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
template
<class TDerives=cBufferBase,
 class TBufferBaseImplement=cBufferBaseImplement,
 class TBufferBaseInterface=cBufferBaseInterface,
 class TBufferExtend=cExportBase,
 UINT VDefaultBufferSize=CBUFFERBASE_DEFAULT_BUFFER_SIZE,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TBufferBaseImplement,
 class TExtends=TBufferExtend>

class c_EXPORT_CLASS cBufferBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cBufferBase interface member definitions
 */
#define CBUFFERBASEINTERFACE_MEMBERS_ONLY
#include "cbufferbaseinterface.hxx"
#undef CBUFFERBASEINTERFACE_MEMBERS_ONLY

    enum { vDefaultBufferSize = VDefaultBufferSize };

    tWhat m_defaultBuffer[vDefaultBufferSize];

    tWhat* m_writeBuffer;
    const tWhat* m_readBuffer;

    tSize m_bufferSize;
    tLength m_bufferLength;
    tLength m_bufferTell;

    bool m_fixedSize;
    bool m_freeBuffer;

    /**
     **********************************************************************
     *  Constructor: cBufferBaseT
     *
     *       Author: $author$
     *         Date: 1/19/2010
     **********************************************************************
     */
    cBufferBaseT()
    : m_writeBuffer(m_defaultBuffer),
      m_readBuffer(m_defaultBuffer),
      m_bufferSize(vDefaultBufferSize),
      m_bufferLength(0),
      m_bufferTell(0),
      m_fixedSize(false),
      m_freeBuffer(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cBufferBaseT
     *
     *      Author: $author$
     *        Date: 1/19/2010
     **********************************************************************
     */
    virtual ~cBufferBaseT()
    {
        if (m_writeBuffer && m_freeBuffer)
        if (m_writeBuffer != m_defaultBuffer)
            delete m_writeBuffer;
    }
#else /* !defined(CBUFFERBASE_MEMBERS_ONLY) */
#endif /* !defined(CBUFFERBASE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength SetSize
    (tSize size) 
#if defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFERBASE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) 
        tLength bufferSize = (tLength)(m_bufferSize);

        if (size >= m_bufferSize)
        if (m_fixedSize)
            return -e_ERROR_FULL;
        else
        bufferSize = AdjustToSize(NewSize(size));

#else /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength bufferSize = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        return bufferSize;
    }
#endif /* defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Size
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength Size() const 
#if defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFERBASE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) 
        tLength bufferSize = m_bufferSize;
#else /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength bufferSize = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        return bufferSize;
    }
#endif /* defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetLength
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength SetLength
    (tLength length) 
#if defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFERBASE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) 
        tLength count;
        tSize size;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > length)
            length = m_bufferSize;
            
        if ((size = (tSize)(length)) > m_bufferSize)
        if (length > (count = SetSize(size)))
        if (0 > count)
            return count;
        else 
        return -e_ERROR_FULL;

        count = (m_bufferTell = (m_bufferLength = length));
#else /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Length() const 
#if defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFERBASE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) 
        tLength length = m_bufferLength;
#else /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: ReadBuffer
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual const tWhat* ReadBuffer
    (tLength& size, tLength& length) const 
#if defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFERBASE_MEMBER_FUNCS_INTERFACE */
    {
        const tWhat* readBuffer = 0;
#if !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) 
        readBuffer = m_readBuffer;
        size = (tLength)(m_bufferSize);
        length = m_bufferLength;
#else /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        size = -e_ERROR_NOT_IMPLEMENTED;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        return readBuffer;
    }
#endif /* defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteBuffer
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tWhat* WriteBuffer
    (tLength& size, tLength& length) const 
#if defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFERBASE_MEMBER_FUNCS_INTERFACE */
    {
        tWhat* writeBuffer = 0;
#if !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) 
        writeBuffer = (tWhat*)(m_writeBuffer);
        size = (tLength)(m_bufferSize);
        length = m_bufferLength;
#else /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        size = -e_ERROR_NOT_IMPLEMENTED;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT) */
        return writeBuffer;
    }
#endif /* defined(CBUFFERBASE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBUFFERBASE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: AdjustToSize
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength AdjustToSize(tSize size)
    {
        tLength length = -e_ERROR_FAILED;
        bool allocBuffer;
        TWhat* buffer;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (size <= m_bufferSize)
            /* buffer is already big enough
             */
            return m_bufferSize;

        /* Set m_free_buffer here if it has not already been
         * done to indicate that the buffer should be freed upon 
         * destruction.
         */
        if ((allocBuffer = !m_freeBuffer))
            m_freeBuffer = true;

        if (!(buffer = new tWhat[size]))
        {
            if (allocBuffer)
                m_freeBuffer = false;

            return -e_ERROR_NEW;
        }

        if (m_writeBuffer)
        {
            if (m_bufferLength > 0)
                CopyBuffer(buffer, m_writeBuffer, m_bufferLength);

            if (m_writeBuffer != m_defaultBuffer)
                delete m_writeBuffer;
        }

        m_writeBuffer = buffer;
        m_readBuffer = buffer;
        m_bufferSize = size;
        return m_bufferSize;
    }
    /**
     **********************************************************************
     * Function: NewSize
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tSize NewSize(tSize size) const
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
        size = ((size/vDefaultBufferSize)+1)*vDefaultBufferSize;
        return size;
    }
    /**
     **********************************************************************
     * Function: CopyBuffer
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength CopyBuffer
    (tWhat* to, const tWhat* from, tSize size) const
    {
		tLength length;
        for (length = 0; size > 0; --size, length++)
            (*to++) = (*from++);
		return length;
    }
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBUFFERBASE_MEMBERS_ONLY) */
#endif /* !defined(CBUFFERBASE_MEMBERS_ONLY) */

#endif /* !defined(_CBUFFERBASE_HXX) || defined(CBUFFERBASE_MEMBERS_ONLY) */

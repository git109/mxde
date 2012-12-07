/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cbuffer.hxx
 *
 * Author: $author$
 *   Date: 5/12/2009
 **********************************************************************
 */
#if !defined(_CBUFFER_HXX) || defined(CBUFFER_MEMBERS_ONLY)
#if !defined(_CBUFFER_HXX) && !defined(CBUFFER_MEMBERS_ONLY)
#define _CBUFFER_HXX
#endif /* !defined(_CBUFFER_HXX) && !defined(CBUFFER_MEMBERS_ONLY) */

#if !defined(CBUFFER_MEMBERS_ONLY)
#include "cbufferinterface.hxx"
#include "cstore.hxx"

#define CBUFFER_DEFAULT_BUFFER_SIZE 128

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cBuffer definition
 */
class c_INSTANCE_CLASS cBuffer;

#undef CDB_CLASS
#define CDB_CLASS "cBufferT"
/**
 **********************************************************************
 *  Class: cBufferT
 *
 * Author: $author$
 *   Date: 5/12/2009
 **********************************************************************
 */
template
<class TDerives=cBuffer,
 class TBufferImplement=cBufferImplement,
 class TBufferInterface=cBufferInterface,
 class TStore=cStore,
 class TWhat=CHAR,
 UINT VDefaultBufferSize=CBUFFER_DEFAULT_BUFFER_SIZE,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TBufferImplement,
 class TExtends=TStore>
 
class c_INSTANCE_CLASS cBufferT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cBufferT cDerives;

/* include cBuffer interface member definitions
 */
#define CBUFFERINTERFACE_MEMBERS_ONLY
#include "cbufferinterface.hxx"
#undef CBUFFERINTERFACE_MEMBERS_ONLY

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
     * Constructor: cBufferT
     *
     *      Author: $author$
     *        Date: 5/12/2009
     **********************************************************************
     */
    cBufferT()
    : m_writeBuffer(m_defaultBuffer),
      m_readBuffer(m_defaultBuffer),
      m_bufferSize(vDefaultBufferSize),
      m_bufferLength(0),
      m_bufferTell(0),
      m_fixedSize(false),
      m_freeBuffer(false)
    {
        m_defaultBuffer[0] = (tWhat)(vEndWhat);
    }
    /**
     **********************************************************************
     * Destructor: ~cBufferT
     *
     *     Author: $author$
     *       Date: 5/12/2009
     **********************************************************************
     */
    virtual ~cBufferT()
    {
    }
#else /* !defined(CBUFFER_MEMBERS_ONLY) */
#endif /* !defined(CBUFFER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CopySigned
     *
     *   Author: $author$
     *     Date: 9/22/2009
     **********************************************************************
     */
    virtual tLength CopySigned
    (tLength value) 
#if defined(CBUFFFER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        if (0 <= (count = Clear()))
            count = WriteSigned(value);
#else /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CopyUnsigned
     *
     *   Author: $author$
     *     Date: 9/22/2009
     **********************************************************************
     */
    virtual tLength CopyUnsigned
    (tSize value) 
#if defined(CBUFFFER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        if (0 <= (count = Clear()))
            count = WriteUnsigned(value);
#else /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: WriteSigned
     *
     *   Author: $author$
     *     Date: 9/22/2009
     **********************************************************************
     */
    virtual tLength WriteSigned
    (tLength value) 
#if defined(CBUFFFER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) 
        tWhat sign = (tWhat)((0 > value)?('-'):(vEndWhat));
        tSize uValue = (tSize)((0 > value)?(-value):(value));
        tLength count = 0;
        tLength length;
        
        if (0 <= (count = Write(&sign)))
        if (0 > (length = WriteUnsigned(uValue)))
            count = length;
        else
        count += length;
        
#else /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteUnsigned
     *
     *   Author: $author$
     *     Date: 9/22/2009
     **********************************************************************
     */
    virtual tLength WriteUnsigned
    (tSize value) 
#if defined(CBUFFFER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) 
        tWhat c = ((tWhat)('0'));
        tLength count = 0;
        tSize digits;
        tSize msdValue;

        if (0 == value)
            count = Write(&c, 1);
        else
        {
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
                
            for (; msdValue; msdValue /= 10, --digits)
            {
                tWhat d = c + (tWhat)(msdValue%10);
                count += Write(&d, 1);
            }
            
            for (; digits; --digits)
                count += Write(&c, 1);
        }
#else /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFFER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual int Compare
    (const tBufferInterface& to,
     tLength length=vUndefinedLength) const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        int unequal = 0;
        const tWhat* toBuffer;
        tLength toLength;

        if (!(toBuffer = to.Buffer(toLength)))
            return -e_ERROR_FAILED-1;

        if ((0 > length) || (length > toLength))
            length = toLength;

        unequal = Compare(toBuffer, length);

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual int Compare
    (const tWhat* toBuffer,
     tLength length=vUndefinedLength) const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        int unequal = 0;
        const tWhat* whatBuffer;
        tLength whatLength,diffLength;
        tWhat to,what;

        if (!(whatBuffer = Buffer(whatLength)))
            return toBuffer?-1:1;

        if (length < 0)
        if (0 > (length = GetLengthOf(toBuffer)))
            return length-1;

        if (0 < (diffLength = (length - whatLength)))
        {
            unequal = -1;
            length = whatLength;
        }
        else if (diffLength)
                unequal = 1;
 
        if (length > 0)
        do
        {
            if ((what = *(whatBuffer++)) > (to = *(toBuffer++)))
                return 1;

            if (what < to)
                return -1;
        }
        while (--length > 0);

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Copy
    (const tWhat* buffer,
     tLength length=vUndefinedLength) 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count;

        if (0 > (count = Clear()))
            return count;

        count = Write(buffer, length);

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* buffer,
     tSize size) 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;

        if (size < 1)
            return 0;

        if (!buffer)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_readBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_bufferTell >= m_bufferLength)
            return 0;

        if (m_bufferTell + (count = (tLength)(size)) >= m_bufferLength)
            size = (tSize)(count = (m_bufferLength - m_bufferTell));

        CopyBuffer(buffer, m_readBuffer+m_bufferTell, size);
        m_bufferTell += count;

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* buffer,
     tLength length=vUndefinedLength) 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tSize newSize;

        if (!buffer)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (length < 0)
            length = GetLengthOf(buffer);

        if (length < 1)
            return 0;

        if (m_bufferSize < (newSize = (m_bufferTell+length)))
        if (m_fixedSize)
            return -e_ERROR_FULL;

        else 
        if (0 >= (count = AdjustToSize(NewSize(newSize))))
            return count;

        CopyBuffer(m_writeBuffer+m_bufferTell, buffer, length);
        count = length;

        if ((m_bufferTell += length) > m_bufferLength)
        if ((tSize)(m_bufferLength = m_bufferTell) < m_bufferSize)
            m_writeBuffer[m_bufferTell] = (tWhat)(vEndWhat);

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Clear() 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_bufferLength;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_bufferSize > (tSize)(m_bufferLength = (m_bufferTell = 0)))
            m_writeBuffer[m_bufferTell] = (tWhat)(vEndWhat);

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Seek
    (tLength count,
     tWhence whence=vWhenceCurrent) 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        switch(whence)
        {
        case vWhenceCurrent:
            if ((count = m_bufferTell+count) < 0)
                count = -e_ERROR_BEGINOF;

            else if (count > m_bufferLength)
                    count = -e_ERROR_ENDOF;

            else m_bufferTell = count;
            break;

        case vWhenceBegin:
            if ((count) < 0)
                count = -e_ERROR_BEGINOF;

            else if (count > m_bufferLength)
                    count = -e_ERROR_ENDOF;

            else m_bufferTell = count;
            break;

        case vWhenceEnd:
            if ((count) > 0)
                count = -e_ERROR_ENDOF;

            else if ((count = m_bufferLength-count) < 0)
                    count = -e_ERROR_BEGINOF;

            else m_bufferTell = count;
            break;

        default:
            count = -e_ERROR_INVALID_PARAMETER;
        }
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Tell
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Tell() const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_bufferTell;
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength bufferSize = (tLength)(m_bufferSize);

        if (size >= m_bufferSize)
        if (m_fixedSize)
            return -e_ERROR_FULL;
        else
        bufferSize = AdjustToSize(NewSize(size));

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength bufferSize = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return bufferSize;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Size
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tLength Size() const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength bufferSize = m_bufferSize;
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength bufferSize = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return bufferSize;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetSize
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength GetSize() const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength bufferSize = Size();
        return bufferSize;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count;
        tSize size;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > length)
        if (0 > (length = GetLengthOf(m_writeBuffer)))
            return -e_ERROR_FAILED;

        if ((size = (tSize)(length)) > m_bufferSize)
        if (length > (count = SetSize(size)))
        if (0 > count)
            return count;
        else 
        return -e_ERROR_FULL;

        count = (m_bufferTell = length);

        if (m_bufferSize > (tSize)(m_bufferLength = m_bufferTell))
            m_writeBuffer[m_bufferTell] = (tWhat)(vEndWhat);

#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Length() const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length = m_bufferLength;
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        tLength length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength GetLength() const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength length = Length();
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBuffer
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual tWhat* SetBuffer
    (tWhat* buffer,
     tLength length=vUndefinedLength) 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tWhat* writeBuffer = 0;
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return writeBuffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Buffer
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual const tWhat* Buffer
    (tLength& size, tLength& length) const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        const tWhat* readBuffer = 0;
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        readBuffer = m_readBuffer;
        size = (tLength)(m_bufferSize);
        length = m_bufferLength;
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        size = -e_ERROR_NOT_IMPLEMENTED;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return readBuffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Buffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual const tWhat* Buffer
    (tLength &length) const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength size;
        const tWhat* buffer = Buffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Buffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual const tWhat* Buffer() const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength size;
        tLength length;
        const tWhat* buffer = Buffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual const tWhat* GetBuffer
    (tLength& size, tLength &length) const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        const tWhat* buffer = Buffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual const tWhat* GetBuffer
    (tLength &length) const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength size;
        const tWhat* buffer = Buffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual const tWhat* GetBuffer() const
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength size;
        tLength length;
        const tWhat* buffer = Buffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tWhat* writeBuffer = 0;
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
        writeBuffer = (tWhat*)(m_writeBuffer);
        size = (tLength)(m_bufferSize);
        length = m_bufferLength;
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        size = -e_ERROR_NOT_IMPLEMENTED;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return writeBuffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteBuffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tWhat* WriteBuffer
    (tLength& size) const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tLength length;
        tWhat* buffer = WriteBuffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tWhat* GetWriteBuffer
    (tLength& size, tLength &length) const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tWhat* buffer = WriteBuffer(size,length);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tWhat* GetWriteBuffer
    (tLength& size) const 
#if defined(CBUFFER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBUFFER_MEMBER_FUNCS_INTERFACE */
    {
        tWhat* buffer = WriteBuffer(size);
#if !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBUFFER_MEMBER_FUNCS_IMPLEMENT) */
        return buffer;
    }
#endif /* defined(CBUFFER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBUFFER_MEMBERS_ONLY) 
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
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength GetLengthOf
    (const tWhat* buffer) const
    {
        tLength length;
        tWhat what;

        for (length = 0; (what = *buffer) != (tWhat)(vEndWhat); buffer++)
            length++;
        return length;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cBufferExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cBufferT<>
cBufferExtends;
/**
 **********************************************************************
 *  Class: cBuffer
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBuffer
: public cBufferExtends
{
public:
    typedef cBufferExtends cExtends;
};

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARBuffer;
/**
 **********************************************************************
 * Typedef: cTCHARBufferExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferT
<cTCHARBuffer, 
 cTCHARBufferImplement,
 cTCHARBufferInterface,
 cTCHARStore, TCHAR>
cTCHARBufferExtends;
/**
 **********************************************************************
 *  Class: cTCHARBuffer
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARBuffer
: public cTCHARBufferExtends
{
public:
    typedef cTCHARBufferExtends cExtends;
    typedef cTCHARBuffer cDerives;
};

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARBuffer;
/**
 **********************************************************************
 * Typedef: cWCHARBufferExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferT
<cWCHARBuffer, 
 cWCHARBufferImplement,
 cWCHARBufferInterface,
 cWCHARStore, WCHAR>
cWCHARBufferExtends;
/**
 **********************************************************************
 *  Class: cWCHARBuffer
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARBuffer
: public cWCHARBufferExtends
{
public:
    typedef cWCHARBufferExtends cExtends;
    typedef cWCHARBuffer cDerives;
};

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEBuffer;
/**
 **********************************************************************
 * Typedef: cBYTEBufferExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferT
<cBYTEBuffer, 
 cBYTEBufferImplement,
 cBYTEBufferInterface,
 cBYTEStore, BYTE>
cBYTEBufferExtends;
/**
 **********************************************************************
 *  Class: cBYTEBuffer
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEBuffer
: public cBYTEBufferExtends
{
public:
    typedef cBYTEBufferExtends cExtends;
    typedef cBYTEBuffer cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBUFFER_MEMBERS_ONLY) */
#endif /* !defined(CBUFFER_MEMBERS_ONLY) */

#endif /* !defined(_CBUFFER_HXX) || defined(CBUFFER_MEMBERS_ONLY) */

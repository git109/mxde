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
 *   File: cstringbase.hxx
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
#if !defined(_CSTRINGBASE_HXX) || defined(CSTRINGBASE_MEMBERS_ONLY)
#if !defined(_CSTRINGBASE_HXX) && !defined(CSTRINGBASE_MEMBERS_ONLY)
#define _CSTRINGBASE_HXX
#endif /* !defined(_CSTRINGBASE_HXX) && !defined(CSTRINGBASE_MEMBERS_ONLY) */

#if !defined(CSTRINGBASE_MEMBERS_ONLY)
#include "cstringbaseinterface.hxx"
#include "cbase.hxx"

#define CSTRINGBASE_DEFAULT_SIZE 128

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cStringBase;

#undef CDB_CLASS
#define CDB_CLASS "cStringBaseT"
/**
 **********************************************************************
 *  Class: cStringBaseT
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
template
<class TDerives=cStringBase,
 class TStringBaseImplement=cStringBaseImplement,
 class TStringBaseExtend=cBase,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 TSize VDefaultSize=CSTRINGBASE_DEFAULT_SIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TStringBaseImplement,
 class TExtends=TStringBaseExtend>

class c_INSTANCE_CLASS cStringBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cStringBase interface member definitions
 */
#define CSTRINGBASEINTERFACE_MEMBERS_ONLY
#include "cstringbaseinterface.hxx"
#undef CSTRINGBASEINTERFACE_MEMBERS_ONLY

    enum { vDefaultSize = VDefaultSize };

    bool m_freeBuffer;
    bool m_fixedSize;

    tSize m_size;
    tLength m_length;
    tLength m_tell;

    const tChar* m_readBuffer;
    tChar* m_writeBuffer;
    tChar m_defaultBuffer[vDefaultSize];

    /**
     **********************************************************************
     *  Constructor: cStringBaseT
     *
     *       Author: $author$
     *         Date: 4/7/2010
     **********************************************************************
     */
    cStringBaseT
    (const tChar* chars = 0,
     tLength length = vUndefinedLength) 
    : m_freeBuffer(false),
      m_fixedSize(false),
      m_size(VDefaultSize),
      m_length(0),
      m_tell(0),
      m_readBuffer(m_defaultBuffer),
      m_writeBuffer(m_defaultBuffer)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cStringBaseT
     *
     *      Author: $author$
     *        Date: 4/7/2010
     **********************************************************************
     */
    virtual ~cStringBaseT()
    {
    }
#else /* !defined(CSTRINGBASE_MEMBERS_ONLY) */
#endif /* !defined(CSTRINGBASE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: assign
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual tLength assign
    (const tChar* chars,
     tLength length = vUndefinedLength)
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
        if (0 > (count = clear()))
            return count;
        count = append(chars, length);
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: append
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual tLength append
    (const tChar* chars,
     tLength length = vUndefinedLength)
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;
        tSize newSize;
        eError error;

        if ((count = length) < 0)
            count = (length = _length_of(chars));

        if (length < 1)
            return 0;

        if (!chars)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_size < (newSize = (m_tell+length)))
        if (m_fixedSize)
            return -e_ERROR_FULL;

        else if ((error = _adjust_to_size(_new_size_of(newSize))))
                return -error;

        _copy_to(m_writeBuffer+m_tell, chars, length);

        if ((m_tell += length) > m_length)
        if ((tSize)(m_length = m_tell) < m_size)
            m_writeBuffer[m_tell] = (tChar)(vEndChar);

#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: adjust_size
     *
     *    Author: $author$
     *      Date: 7/29/2010
     **********************************************************************
     */
    virtual tLength adjust_size(tSize newSize)
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;
        eError error;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_size < (newSize))
        if (m_fixedSize)
            return -e_ERROR_FULL;

        else if ((error = _adjust_to_size(_new_size_of(newSize))))
                return -error;

        count = m_size;
        
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: clear
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual tLength clear()
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        count = m_length;

        if (m_size > (tSize)(m_length = (m_tell = 0)))
            m_writeBuffer[m_tell] = (tChar)(vEndChar);

#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: compare
     *
     *    Author: $author$
     *      Date: 4/8/2010
     **********************************************************************
     */
    virtual int compare
    (const tChar* toChars, 
     tLength length = vUndefinedLength) const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        int unequal = 0;
        const tChar* thisChars;
        tChar toChar, thisChar;
        tLength lendiff, thisLength;

        if (!(thisChars = c_str(thisLength)))
            return (toChars)?(-1):(1);

        if (length < 0)
            length = _length_of(toChars);

        if (0 < (lendiff = (length - thisLength)))
        {
            length = thisLength;
            unequal = -1;
        }
        else if (lendiff)
                unequal = 1;
 
        if (length > 0)
        do
        {
            if ((thisChar = *(thisChars++)) 
                > (toChar = *(toChars++)))
                return 1;
            else
            if (thisChar < toChar)
                return -1;
        }
        while (--length > 0);

#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: str
     *
     *    Author: $author$
     *      Date: 4/24/2010
     **********************************************************************
     */
    virtual tChar* str() const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength size = 0;
        tChar* chars = str(size);
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        size = 0;
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        size = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: str
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual tChar* str(tLength& size) const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
        tChar* chars = 0;
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        size = 0;
        if ((chars = m_writeBuffer))
            size = m_size;
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        size = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: c_str
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual const tChar* c_str() const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength length = 0;
        const tChar* chars = c_str(length);
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: c_str
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual const tChar* c_str(tLength& length) const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        length = 0;
        if ((chars = m_readBuffer))
            length = m_length;
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: length
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual tLength length() const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSTRINGBASE_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: compare
     *
     *    Author: $author$
     *      Date: 4/8/2010
     **********************************************************************
     */
    virtual int compare
    (const cDerives& to, 
     tLength length = vUndefinedLength) const
#if defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT)
        int unequal = 0;
        tLength toCharsLength;
        const tChar* toChars;

        if ((toChars = to.c_str(toCharsLength)))
        {
            if (length > (toCharsLength))
                length = toCharsLength;

            unequal = compare(toChars, length);
        }
        else if (c_str())
                unequal = 1;
#else /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
#endif /* !defined(CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CSTRINGBASE_MEMBER_FUNCS_INTERFACE) */

protected:

    /**
     **********************************************************************
     * Function: _adjust_to_size
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual eError _adjust_to_size(TSize size)
    {
        bool allocBuffer;
        TChar* buffer;

        if (!m_writeBuffer)
            return e_ERROR_NOT_ATTACHED;

        if (size <= m_size)
            return e_ERROR_NONE;

        /* Set m_free_buffer here if it has not already been
         * done to make sure the buffer will be freed upon 
         * destruction.
         */
        if ((allocBuffer = !m_freeBuffer))
            m_freeBuffer = true;

        if (!(buffer = _alloc_buffer(size)))
        {
            if (allocBuffer)
                m_freeBuffer = false;

            return e_ERROR_NEW;
        }

        if (m_writeBuffer)
        {
            if (m_length > 0)
                _copy_to(buffer, m_writeBuffer, m_length);

            if (m_writeBuffer != m_defaultBuffer)
                _free_buffer(m_writeBuffer);
        }

        m_writeBuffer = buffer;
        m_readBuffer = buffer;
        m_size = size;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: _alloc_buffer
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual tChar* _alloc_buffer(tSize size) const
    {
        tChar* chars = new tChar[size];
        return chars;
    }
    /**
     **********************************************************************
     * Function: _free_buffer
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual eError _free_buffer(tChar* buffer) const
    {
        delete[] buffer;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: _new_size_of
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual TSize _new_size_of(TSize size) const
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
        return ((size/VDefaultSize)+1)*VDefaultSize;
    }
    /**
     **********************************************************************
     * Function: _copy_to
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual TLength _copy_to
    (TChar* to, const TChar* from, TSize size) const
    {
		TLength length;
        for (length = size; size; --size)
            (*to++) = (*from++);
		return length;
    }
    /**
     **********************************************************************
     * Function: _length_of
     *
     *    Author: $author$
     *      Date: 4/7/2010
     **********************************************************************
     */
    virtual TLength _length_of
    (const TChar* chars) const
    {
        const TChar endChar((TChar)(VEndChar));
        TLength length;

        for (length = 0; (*chars != endChar); chars++)
            length++;
        return length;
    }
};
#undef CDB_CLASS

/*
 * CHAR
 */
 
class c_INSTANCE_CLASS cStringBase;
/**
 **********************************************************************
 * Typedef: cStringBaseExtend
 *
 *  Author: $author$
 *    Date: 4/24/2010
 **********************************************************************
 */
typedef cStringBaseT
<cStringBase, 
 cStringBaseImplement, 
 cBase, CHAR, CHAR>
cStringBaseExtend;
/**
 **********************************************************************
 *  Class: cStringBase
 *
 * Author: $author$
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cStringBase
: public cStringBaseExtend
{
public:
    typedef cStringBaseExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cStringBase
     *
     *       Author: $author$
     *         Date: 4/7/2010
     **********************************************************************
     */
    cStringBase
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
};

/*
 * TCHAR
 */
 
#if !defined(CTCHARSTRINGBASE_MEMBERS_ONLY)
class c_INSTANCE_CLASS cTCHARStringBase;
/**
 **********************************************************************
 * Typedef: cTCHARStringBaseExtend
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cStringBaseT
<cTCHARStringBase, 
 cTCHARStringBaseImplement, 
 cBase, TCHAR, TCHAR>
cTCHARStringBaseExtend;
/**
 **********************************************************************
 *  Class: cTCHARStringBase
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARStringBase
: //virtual public cTCHARStringBaseImplement,
  public cTCHARStringBaseExtend
{
public:
    //typedef cTCHARStringBaseImplement cImplements;
    typedef cTCHARStringBaseExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cTCHARStringBase
     *
     *       Author: $author$
     *         Date: 7/29/2010
     **********************************************************************
     */
    cTCHARStringBase
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cTCHARStringBase
     *
     *      Author: $author$
     *        Date: 7/29/2010
     **********************************************************************
     */
    virtual ~cTCHARStringBase()
    {
    }
#else /* !defined(CTCHARSTRINGBASE_MEMBERS_ONLY) */
#endif /* !defined(CTCHARSTRINGBASE_MEMBERS_ONLY) */

#if !defined(CTCHARSTRINGBASE_MEMBERS_ONLY)
};
#else /* !defined(CTCHARSTRINGBASE_MEMBERS_ONLY) */
#endif /* !defined(CTCHARSTRINGBASE_MEMBERS_ONLY) */

/*
 * WCHAR
 */
 
#if !defined(CWCHARSTRINGBASE_MEMBERS_ONLY)
class c_INSTANCE_CLASS cWCHARStringBase;
/**
 **********************************************************************
 * Typedef: cWCHARStringBaseExtend
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cStringBaseT
<cWCHARStringBase, 
 cWCHARStringBaseImplement, 
 cBase, WCHAR, WCHAR>
cWCHARStringBaseExtend;
/**
 **********************************************************************
 *  Class: cWCHARStringBase
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARStringBase
: //virtual public cWCHARStringBaseImplement,
  public cWCHARStringBaseExtend
{
public:
    //typedef cWCHARStringBaseImplement cImplements;
    typedef cWCHARStringBaseExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWCHARStringBase
     *
     *       Author: $author$
     *         Date: 7/29/2010
     **********************************************************************
     */
    cWCHARStringBase
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWCHARStringBase
     *
     *      Author: $author$
     *        Date: 7/29/2010
     **********************************************************************
     */
    virtual ~cWCHARStringBase()
    {
    }
#else /* !defined(CWCHARSTRINGBASE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARSTRINGBASE_MEMBERS_ONLY) */

#if !defined(CWCHARSTRINGBASE_MEMBERS_ONLY)
};
#else /* !defined(CWCHARSTRINGBASE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARSTRINGBASE_MEMBERS_ONLY) */

/*
 * cChar
 */
 
class c_INSTANCE_CLASS ccCharStringBase;
/**
 **********************************************************************
 * Typedef: ccCharStringBaseExtend
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cStringBaseT
<ccCharStringBase, 
 ccCharStringBaseImplement, 
 cBase, cChar, WCHAR>
ccCharStringBaseExtend;
/**
 **********************************************************************
 *  Class: ccCharStringBase
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS ccCharStringBase
: public ccCharStringBaseExtend
{
public:
    typedef ccCharStringBaseExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: ccCharStringBase
     *
     *       Author: $author$
     *         Date: 4/7/2010
     **********************************************************************
     */
    ccCharStringBase
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTRINGBASE_MEMBERS_ONLY) */
#endif /* !defined(CSTRINGBASE_MEMBERS_ONLY) */

#endif /* !defined(_CSTRINGBASE_HXX) || defined(CSTRINGBASE_MEMBERS_ONLY) */

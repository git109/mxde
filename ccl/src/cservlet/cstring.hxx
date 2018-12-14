/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cstring.hxx
 *
 * Author: $author$
 *   Date: 11/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTRING_HXX
#define _CSTRING_HXX

#include "cccharbuffer.hxx"
#include "cinterface.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cStringInterfaceT
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
template <class TAs, class TIs=cInterfaceBase>
class c_INTERFACE_CLASS cStringInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual int Set(const TAs &string) = 0;
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char *chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const WCHAR *chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const cChar *chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual const cChar* GetChars(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual const cChar* GetChars() const = 0;
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual int Length() const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual int Compare(const TAs &to) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2004
     **********************************************************************
     */
    virtual int Compare
    (const char *to, int length=-1) const = 0;
};

/**
 **********************************************************************
 *  Class: cStringInterface
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cStringInterface
: virtual public cStringInterfaceT<cStringInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cStringImplementT
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
template <class TIs=cStringInterface>
class cStringImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual int Set(const TIs &string) 
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char *chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const WCHAR *chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const cChar *chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual const cChar* GetChars(int &length) const
    {
        const cChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual const cChar* GetChars() const
    {
        int length;
        const cChar* chars = GetChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual int Length() const
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual int Compare(const TIs &to) const
    {
        int unequal = -1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2004
     **********************************************************************
     */
    virtual int Compare
    (const char *to, int length=-1) const
    {
        int unequal = -1;
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cStringImplement
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
class cStringImplement
: virtual public cStringImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cStringT
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cStringInterface,
 class TImplementIs=cStringImplement,
 class TIs=cBase>

class cStringT
: virtual public TInterfaceIs,
  virtual public TImplementIs,
  public TIs
{
public:
    typedef TIs cIs;

    cCCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cStringT(const cChar *chars=0, int length=-1) 
    {
        eError error;

        if (chars)
        if (0 > (length = SetChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cStringT(const WCHAR *chars, int length=-1) 
    {
        eError error;

        if (chars)
        if (0 > (length = SetChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cStringT(const char *chars, int length=-1) 
    {
        eError error;

        if (chars)
        if (0 > (length = SetChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cStringT(const TInterfaceIs &string) 
    {
        eError error;
        int length;
        const cChar *chars;

        if ((chars = string.GetChars(length)))
        if (0 > (length = SetChars(chars, length)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual int Set(const TInterfaceIs &string) 
    {
        int length, count = -e_ERROR_FAILED;
        const cChar *chars;

        if ((chars = string.GetChars(length)))
            count = SetChars(chars, length);

        return count;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char *chars, int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 <= (count = m_buffer.Clear()))
        if (0 <= length)
        {
            for (count=0; count<length; count++)
                m_buffer.Put(cChar(chars[count]));
        }
        else
        {
            for (count=0; chars[count]; count++)
                m_buffer.Put(cChar(chars[count]));
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const WCHAR *chars, int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 <= (count = m_buffer.Clear()))
        if (0 <= length)
        {
            for (count=0; count<length; count++)
                m_buffer.Put(cChar(chars[count]));
        }
        else
        {
            for (count=0; chars[count]; count++)
                m_buffer.Put(cChar(chars[count]));
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int SetChars
    (const cChar *chars, int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 <= (count = m_buffer.Clear()))
        if (0 <= length)
        {
            for (count=0; count<length; count++)
                m_buffer.Put(chars[count]);
        }
        else
        {
            for (count=0; chars[count].m_char; count++)
                m_buffer.Put(chars[count]);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual const cChar* GetChars(int &length) const
    {
        const cChar* chars = m_buffer.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual int Length() const
    {
        int length = m_buffer.GetLength();
        return length;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual int Compare(const TInterfaceIs &to) const
    {
        int length;
        const cChar* to_chars = to.GetChars(length);
        int unequal = m_buffer.Compare(to_chars, length);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2004
     **********************************************************************
     */
    virtual int Compare
    (const char *to, int length=-1) const
    {
        int unequal = m_buffer.Comparec(to, length);
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cString
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
class cString
: public cStringT<>
{
public:
    typedef cStringT<> cIs;

    /**
     **********************************************************************
     * Constructor: cString
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cString(const cChar *chars=0, int length=-1) 
    : cIs(chars, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cString
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cString(const WCHAR *chars, int length=-1) 
    : cIs(chars, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cString
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cString(const char *chars, int length=-1) 
    : cIs(chars, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cString
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cString(const cStringInterface &string) 
    : cIs(string) 
    {
    }
};

#endif /* ndef _CSTRING_HXX */

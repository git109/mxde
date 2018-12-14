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
 *   File: ccharstring.hxx
 *
 * Author: $author$
 *   Date: 10/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARSTRING_HXX
#define _CCHARSTRING_HXX

#include "ccharbuffer.hxx"
#include "cinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cCharStringInterfaceT
 *
 * Author: $author$
 *   Date: 10/5/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cCharStringInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char* chars,  int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual const char* GetChars(int &length) const = 0;
    /**
     **********************************************************************
     * Function: CharAt
     *
     *   Author: $author$
     *     Date: 10/5/2004
     **********************************************************************
     */
    virtual int CharAt(int index) const = 0;
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int Length() const = 0;
};

/**
 **********************************************************************
 *  Class: cCharStringInterface
 *
 * Author: $author$
 *   Date: 10/5/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharStringInterface
: virtual public cCharStringInterfaceT<cInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cCharStringImplementT
 *
 * Author: $author$
 *   Date: 10/5/2004
 **********************************************************************
 */
template <class TIs=cCharStringInterface>
class cCharStringImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char* chars,  int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual const char* GetChars(int &length) const
    {
        const char* chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: CharAt
     *
     *   Author: $author$
     *     Date: 10/5/2004
     **********************************************************************
     */
    virtual int CharAt(int index) const
    {
        int result = -e_ERROR_ENDOF;
        return result;
    }
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int Length() const
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cCharStringImplement
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cCharStringImplement
: public cCharStringImplementT<>
{
public:
    typedef cCharStringImplementT<> cIs;
};

/**
 **********************************************************************
 *  Class: cCharStringT
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cCharStringInterface,
 class TImplementIs=cCharStringImplement,
 class TIs=cImplement>

class cCharStringT
: virtual public TInterfaceIs,
  virtual public TImplementIs,
  public TIs
{
public:
    typedef TIs cIs;

    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cCharStringT
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cCharStringT(const char *chars=0, int length=-1) 
    {
        if (chars)
        if (0 > (length = SetChars(chars, length)))
            throw(-length);
    }
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual int ClearChars() 
    {
        int count = m_buffer.Clear();
        return count;
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char* chars,  int length=-1) 
    {
        int count = m_buffer.Copy(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual const char* GetChars(int &length) const
    {
        const char* chars = m_buffer.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: CharAt
     *
     *   Author: $author$
     *     Date: 10/5/2004
     **********************************************************************
     */
    virtual int CharAt(int index) const
    {
        int result = -e_ERROR_ENDOF;
        int length;
        const char* chars;

        if ((chars = m_buffer.GetBuffer(length)))
        if ((index > 0) && (index < length))
            result = chars[length];

        return result;
    }
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int Length() const
    {
        int length = m_buffer.GetLength();
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cCharString
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cCharString
: public cCharStringT<>
{
public:
    typedef cCharStringT<> cIs;

    /**
     **********************************************************************
     * Constructor: cCharString
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cCharString(const char *chars=0, int length=-1)
    : cIs(chars, length) 
    {
    }
};

#endif /* ndef _CCHARSTRING_HXX */

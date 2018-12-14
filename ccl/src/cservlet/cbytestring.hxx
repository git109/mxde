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
 *   File: cbytestring.hxx
 *
 * Author: $author$
 *   Date: 11/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTRING_HXX
#define _CBYTESTRING_HXX

#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStringInterfaceT
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cBYTEStringInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int SetBytes
    (const BYTE *bytes, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual const BYTE *GetBytes(int &length) const = 0;
};

/**
 **********************************************************************
 *  Class: cBYTEStringInterface
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStringInterface
: virtual public cBYTEStringInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cBYTEStringT
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cBYTEStringInterface,
 class TIs=cImplement>

class cBYTEStringT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cBYTEBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cBYTEStringT
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cBYTEStringT
    (const BYTE *bytes=0, int length=-1) 
    {
        eError error;

        if (bytes)
        if (0 > (length = SetBytes(bytes, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: ClearBytes
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual int ClearBytes()
    {
        int length = m_buffer.Clear();
        return length;
    }
    /**
     **********************************************************************
     * Function: SetBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int SetBytes
    (const BYTE *bytes, int length=-1)
    {
        length = m_buffer.Copy(bytes, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual const BYTE *GetBytes(int &length) const
    {
        const BYTE *bytes = m_buffer.GetBuffer(length);
        return bytes;
    }
};

/**
 **********************************************************************
 *  Class: cBYTEString
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cBYTEString
: public cBYTEStringT<>
{
public:
    typedef cBYTEStringT<> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEString
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cBYTEString
    (const BYTE *bytes=0, int length=-1) 
    : cIs(bytes, length) 
    {
    }
};

#endif /* ndef _CBYTESTRING_HXX */

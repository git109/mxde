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
 *   File: ccharwriterinterface.hxx
 *
 * Author: $author$
 *   Date: 11/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARWRITERINTERFACE_HXX
#define _CCHARWRITERINTERFACE_HXX

#include "cwriterinterface.hxx"
#include "cinitializeinterface.hxx"

/**
 **********************************************************************
 *  Class: cPutcInterfaceT
 *
 * Author: $author$
 *   Date: 12/28/2005
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cPutcInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 6/29/2005
     **********************************************************************
     */
    virtual int Putc(int c) = 0;
    /**
     **********************************************************************
     * Function: WriteInt
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int WriteInt(int value) = 0;
};

/**
 **********************************************************************
 *  Class: cPutcInterface
 *
 * Author: $author$
 *   Date: 12/28/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cPutcInterface
: virtual public cPutcInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cPutcImplementT
 *
 * Author: $author$
 *   Date: 12/28/2005
 **********************************************************************
 */
template <class TIs=cPutcInterface>
class cPutcImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 6/29/2005
     **********************************************************************
     *
    virtual int Putc(int c)
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteInt
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int WriteInt(int value)
    {
        int c, count, result = 0;
        char digit[32];

        if (0 > value)
        if (0 > (c = this->Putc('-')))
            return c;
        else 
        {
            value = -value;
            result++;
        }

        if (1 > value)
        {
            if (0 > (c = this->Putc('0')))
                return c;
            result++;
        }
        else 
        {
            for (count=0; value; value/=10, count++)
                digit[count] = '0'+(value % 10);

            for (;0 < count; result++)
                if (0 > (c = this->Putc(digit[--count])))
                    return c;
        }
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cPutcImplement
 *
 * Author: $author$
 *   Date: 12/28/2005
 **********************************************************************
 */
class cPutcImplement
: virtual public cPutcImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cCharWriterInterface
 *
 * Author: $author$
 *   Date: 10/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharWriterInterface
: virtual public cInitializeInterface,
  virtual public cPutcInterface,
  virtual public cWriterInterfaceT<char>
{
public:
};

/**
 **********************************************************************
 *  Class: cCharWriterImplement
 *
 * Author: $author$
 *   Date: 10/26/2004
 **********************************************************************
 */
class cCharWriterImplement
: virtual public cWriterImplementT
  <char, cCharWriterInterface>
{
public:
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 6/29/2005
     **********************************************************************
     */
    virtual int Putc(int c)
    {
        char cc = (char)c;
        int result;
        
        if (0 <= (result = Put(cc)))
            result = c;
        return result;
    }
};

#endif /* ndef _CCHARWRITERINTERFACE_HXX */

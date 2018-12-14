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
 *   File: cbytestreamt.hxx
 *
 * Author: $author$
 *   Date: 11/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMT_HXX
#define _CBYTESTREAMT_HXX

#include "cstream.hxx"
#include "cstreamt.hxx"
#include "cbytestreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamT
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
template <class TIs=cStream>
class cBYTEStreamT
: virtual public cBYTEStreamInterface,
  public cStreamT<BYTE, TIs>
{
public:
    typedef cStreamT<BYTE, TIs> cIs;

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Read
    (BYTE *buffer,  int size=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Write
    (const BYTE *buffer,  int size=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Getb() 
    {
        int count;
        BYTE of;

        if (sizeof(of) != (count = Read(&of, sizeof(of))))
        if (count < 0)
            return count;
        else return -e_ERROR_ENDOF;

        return of;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Putb(int b) 
    {
        BYTE of = b;
        int count;

        if (sizeof(of) != (count = Write(&of, sizeof(of))))
        if (count < 0)
            return count;
        else return -e_ERROR_ENDOF;

        return of;
    }

    /**
     **********************************************************************
     * Function: ReadUInt16LSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int ReadUInt16LSB(uint16 &value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint16)];

        if (sizeof(buffer) == (size = Read(buffer, sizeof(buffer))))
        {
            for (value=0,i=sizeof(buffer); i>0;)
                value = (value << 8) | buffer[--i];
        }
        else if (0 < size)
                size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: WriteUInt16LSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int WriteUInt16LSB(uint16 value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint16)];

        for (i=0; i<sizeof(buffer); i++,value>>=8)
            buffer[i] = (uint8)value;

        if (sizeof(buffer) != (size = Write(buffer, sizeof(buffer))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: ReadUInt16MSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int ReadUInt16MSB(uint16 &value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint16)];

        if (sizeof(buffer) == (size = Read(buffer, sizeof(buffer))))
        {
            for (value=0,i=0; i<size; i++)
                value = (value << 8) | buffer[i];
        }
        else if (0 < size)
                size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: WriteUInt16MSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int WriteUInt16MSB(uint16 value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint16)];

        for (i=sizeof(buffer); i>0; value>>=8)
            buffer[--i] = (uint8)value;

        if (sizeof(buffer) != (size = Write(buffer, sizeof(buffer))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }

    /**
     **********************************************************************
     * Function: ReadUInt24LSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int ReadUInt24LSB(uint24 &value) 
    {
        int i,j,size;
        uint8 buffer[sizeof(uint24)];

        if (sizeof(buffer) == (size = Read(buffer, sizeof(buffer))))
        {
            for (j=0,i=sizeof(buffer); i>0; j++)
                value[j] = buffer[--i];
        }
        else if (0 < size)
                size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: WriteUInt24LSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int WriteUInt24LSB(const uint24 value) 
    {
        int i,j,size;
        uint8 buffer[sizeof(uint24)];

        for (j=sizeof(buffer),
             i=0; i<sizeof(buffer); i++)
            buffer[i] = value[--j];

        if (sizeof(buffer) != (size = Write(buffer, sizeof(buffer))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: ReadUInt24MSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int ReadUInt24MSB(uint24 &value) 
    {
        int size;

        if (sizeof(uint24) != (size = Read(value, sizeof(uint24))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: WriteUInt24MSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int WriteUInt24MSB(const uint24 value) 
    {
        int size;

        if (sizeof(uint24) != (size = Write(value, sizeof(uint24))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }

    /**
     **********************************************************************
     * Function: ReadUInt32LSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int ReadUInt32LSB(uint32 &value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint32)];

        if (sizeof(buffer) == (size = Read(buffer, sizeof(buffer))))
        {
            for (value=0,i=sizeof(buffer); i>0;)
                value = (value << 8) | buffer[--i];
        }
        else if (0 < size)
                size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: WriteUInt32LSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int WriteUInt32LSB(uint32 value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint32)];

        for (i=0; i<sizeof(buffer); i++,value>>=8)
            buffer[i] = (uint8)value;

        if (sizeof(buffer) != (size = Write(buffer, sizeof(buffer))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: ReadUInt32MSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int ReadUInt32MSB(uint32 &value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint32)];

        if (sizeof(buffer) == (size = Read(buffer, sizeof(buffer))))
        {
            for (value=0,i=0; i<size; i++)
                value = (value << 8) | buffer[i];
        }
        else if (0 < size)
                size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: WriteUInt32MSB
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int WriteUInt32MSB(uint32 value) 
    {
        int i,size;
        uint8 buffer[sizeof(uint32)];

        for (i=sizeof(buffer); i>0; value>>=8)
            buffer[--i] = (uint8)value;

        if (sizeof(buffer) != (size = Write(buffer, sizeof(buffer))))
        if (0 < size)
            size = -e_ERROR_FAILED;

        return size;
    }

};

#endif /* ndef _CBYTESTREAMT_HXX */

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
 * File:   cstreamt.hxx
 *
 * Author: $author$
 * Date:   7/1/2003
 *
 **********************************************************************
 */
#ifndef _CSTREAMT_HXX
#define _CSTREAMT_HXX

#include <stdarg.h>

#include "cerror.h"
#include "cstream.hxx"
#include "cstreaminterface.hxx"

/**
 **********************************************************************
 * Class: cStreamT
 *
 * Author: $author$
 * Date:   7/1/2003
 **********************************************************************
 */
template <class TOf, class TIs=cStream>
class cStreamT
: virtual public cStreamInterface,
  public TIs
{
public:
    typedef TIs cIs;

    int m_mode;

    /**
     **********************************************************************
     * Constructor: cStreamT
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    cStreamT()
    : m_mode(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cStreamT
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual ~cStreamT()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual eError Open(const char *path, int flags, int mode=e_S_IRWXU)
    {
        return e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual eError Open(const char *path, const char *mode="r")
    {
        return e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        return e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: SetMode
     *
     *   Author: $author$
     *     Date: 12/6/2003
     **********************************************************************
     */
    virtual int SetMode(int mode)
    {
        return m_mode = mode;
    }
    /**
     **********************************************************************
     * Function: GetMode
     *
     *   Author: $author$
     *     Date: 12/6/2003
     **********************************************************************
     */
    virtual int GetMode() const
    {
        return m_mode;
    }
    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 7/17/2003
     **********************************************************************
     */
    virtual long SetSize(long size)
    {
        return -e_ERROR_NOT_DEFINED;
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
        return -e_ERROR_NOT_DEFINED;
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
        return -e_ERROR_NOT_DEFINED;
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
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual long GetLengthOf(const TOf *buffer) const
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Tell
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual long Tell() const
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Seek
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual long Seek(long offset, int origin=e_SEEK_SET)
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual int Fill()
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual int Flush()
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual int Clear()
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int Read(TOf *buffer, int size)
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int Write(const TOf *buffer, int size=-1)
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual int Copy(const TOf *buffer, int size=-1)
    {
        int count;

        if ((count = Clear()) < 0)
            return count;

        return Write(buffer, size);
    }
    /**
     **********************************************************************
     * Function: Get
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int Get(TOf &of)
    {
        return Read(&of, 1);
    }
    /**
     **********************************************************************
     * Function: Put
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int Put(const TOf &of)
    {
        return Write(&of, 1);
    }
    /**
     **********************************************************************
     * Function: PutValue
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int PutValue(TOf of)
    {
        return Write(&of, 1);
    }
    /**
     **********************************************************************
     * Function: ReadAt
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int ReadAt
    (TOf *buffer, int size,
     long offset, int origin=e_SEEK_SET)
    {
        long at;

        if ((at = Seek(offset, origin)) < 0)
            return at;

        return Read(buffer, size);
    }
    /**
     **********************************************************************
     * Function: WriteAt
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    virtual int WriteAt
    (const TOf *buffer, int size,
     long offset, int origin=e_SEEK_SET)
    {
        long at;

        if ((at = Seek(offset, origin)) < 0)
            return at;

        return Write(buffer, size);
    }
    /**
     **********************************************************************
     * Function: GetAt
     *
     * Author: $author$
     * Date:   7/6/2003
     **********************************************************************
     */
    virtual int GetAt
    (TOf &of, long offset, int origin=e_SEEK_SET)
    {
        return ReadAt(&of, 1, offset, origin);
    }
    /**
     **********************************************************************
     * Function: PutAt
     *
     * Author: $author$
     * Date:   7/6/2003
     **********************************************************************
     */
    virtual int PutAt
    (const TOf &of, long offset, int origin=e_SEEK_SET)
    {
        return WriteAt(&of, 1, offset, origin);
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
     *     Date: 7/17/2003
     **********************************************************************
     */
    virtual const TOf *GetBuffer(int &size, int &length) const
    {
        size = -e_ERROR_NOT_DEFINED;
        length = -e_ERROR_NOT_DEFINED;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 7/17/2003
     **********************************************************************
     */
    inline const TOf *GetBuffer(int &length) const
    {
        int size;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 7/17/2003
     **********************************************************************
     */
    inline const TOf *GetBuffer() const
    {
        int size, length;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: WriteStream
     *
     * Author: $author$
     * Date:   7/21/2003
     **********************************************************************
     */
    virtual int WriteStream
    (cStreamT<TOf,TIs> &stream, int size=-1)
    {
        int count, length;
        TOf of;

        if (0 > size)
        {
            for (count=0; 0 < (length = stream.Get(of)); count++)
                if (0 > (length = Put(of)))
                    return length;
        }
        else
        {
            for (count=0; count<size; count++)
                if (0 < (length = stream.Get(of)))
                if (0 > (length = Put(of)))
                    return length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CopyStream
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    virtual int CopyStream
    (cStreamT<TOf,TIs> &stream, int size=-1)
    {
        int count;

        if ((count = Clear()) < 0)
            return count;

        return WriteStream(stream, size);
    }

    /**
     **********************************************************************
     * Function: WriteStreamEnded
     *
     * Author: $author$
     * Date:   6/15/2004
     **********************************************************************
     */
    int WriteStreamEnded
    (cStreamT<TOf,TIs> &stream, const TOf ended[], int endsize)
    {
        int i,count,length=0,matched=0;
        TOf of;

        do
        {
            if (0 > (count = stream.Read(&of, 1)))
                return count;

            if (of != ended[matched])
            {
                if (matched > 0)
                {
                    for (i=1; i<matched; i++)
                    {
                        if (!memcmp(ended+i, ended, matched-i))
                        if (of == ended[matched-i])
                            break;
                    }

                    if (0 > (count = Write(ended, i)))
                        return count;

                    length += count;

                    if (0 == (matched -= i))
                    if (of != ended[0])
                    {
                        if (0 > (count = Write(&of, 1)))
                            return count;

                        length += count;
                        continue;
                    }

                    matched++;
                }
                else
                {
                    if (0 > (count = Write(&of, 1)))
                        return count;

                    length += count;
                }
            }
            else if (++matched >= endsize)
            {
                if (0 > (count = Write(ended, matched)))
                    return count;

                length += count;
                break;
            }
        }
        while (count > 0);

        return length;
    }
    /**
     **********************************************************************
     * Function: CopyStreamEnded
     *
     *   Author: $author$
     *     Date: 7/16/2003
     **********************************************************************
     */
    int CopyStreamEnded
    (cStreamT<TOf,TIs> &stream, const TOf ended[], int size)
    {
        int count;

        if ((count = Clear()) < 0)
            return count;

        return WriteStreamEnded(stream, ended, size);
    }

    /**
     **********************************************************************
     * Function: CopyL
     *
     * Author: $author$
     * Date:   8/25/2003
     **********************************************************************
     */
    int CopyL(const TOf *buffer,...)
    {
        int count, result;
        va_list arg;

        va_start(arg,buffer);

        if ((result = Clear()) >= 0)
        if ((count = (result = Write(buffer))) >= 0)
        if ((result = WriteV(arg)) >= 0)
            result += count;

        va_end(arg);
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteL
     *
     * Author: $author$
     * Date:   8/23/2003
     **********************************************************************
     */
    int WriteL(const TOf *buffer,...)
    {
        int count, result;
        va_list arg;

        va_start(arg,buffer);

        if ((count = (result = Write(buffer))) >= 0)
        if ((result = WriteV(arg)) >= 0)
            result += count;

        va_end(arg);
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteV
     *
     * Author: $author$
     * Date:   8/23/2003
     **********************************************************************
     */
    int WriteV(va_list va)
    {
        int count, result=0;
        const TOf *buffer;

        while ((buffer=va_arg(va,const TOf *)))
        {
            if ((count = Write(buffer)) < 0)
                return count;

            result += count;
        }

        return result;
    }
};

#endif

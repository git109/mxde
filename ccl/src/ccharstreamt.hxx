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
 *   File: ccharstreamt.hxx
 *
 * Author: $author$
 *   Date: 7/2/2003
 *
 **********************************************************************
 */
#ifndef _CCHARSTREAMT_HXX
#define _CCHARSTREAMT_HXX

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "cstream.hxx"
#include "cstreamt.hxx"
#include "ccharstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cCharStreamT
 *
 * Author: $author$
 *   Date: 7/2/2003
 **********************************************************************
 */
template <class TIs=cStream>
class cCharStreamT
: virtual public cCharStreamInterface,
  public cStreamT<char, TIs>
{
public:
    typedef cStreamT<char, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamT
     *
     *      Author: $author$
     *        Date: 7/2/2003
     **********************************************************************
     */
    cCharStreamT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCharStreamT
     *
     *     Author: $author$
     *       Date: 7/2/2003
     **********************************************************************
     */
    virtual ~cCharStreamT()
    {
    }

    /**
     **********************************************************************
     * Function: PrintFormatted
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int PrintFormatted(const char *format,...)
    {
        int count;
        va_list va;

        va_start(va,format);
        count = VPrintFormatted(format, va);
        va_end(va);

        return count;
    }
    /**
     **********************************************************************
     * Function: VPrintFormatted
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int VPrintFormatted(const char *format, va_list va)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual long GetLengthOf(const char *buffer) const
    {
        return (long)(strlen(buffer));
    }

    /**
     **********************************************************************
     * Function: Read
     *
     * Author: $author$
     * Date:   11/6/2003
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        return -e_ERROR_NOT_DEFINED;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     * Author: $author$
     * Date:   11/6/2003
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        return -e_ERROR_NOT_DEFINED;
    }

    /**
     **********************************************************************
     * Function: Getc
     *
     *   Author: $author$
     *     Date: 7/1/2003
     **********************************************************************
     */
    virtual int Getc()
    {
        int count;
        unsigned char of;

        if ((count = Read((char*)&of, 1)) > 0)
            return of;

        if (count < 0)
            return count;

        return -e_ERROR_ENDOF;
    }
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 7/1/2003
     **********************************************************************
     */
    virtual int Putc(int c)
    {
        unsigned char of = c;
        int count;

        if ((count = Write((char*)&of, 1)) > 0)
            return of;

        if (count < 0)
            return count;

        return -e_ERROR_ENDOF;
    }
    /**
     **********************************************************************
     * Function: GetcAt
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual int GetcAt(long offset, int origin=e_SEEK_SET)
    {
        int count;
        unsigned char of;

        if ((count = this->ReadAt
            ((char*)&of, (int)1, offset, origin)) > 0)
            return of;

        if (count < 0)
            return count;

        return -e_ERROR_ENDOF;
    }
    /**
     **********************************************************************
     * Function: PutcAt
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual int PutcAt(int c, long offset, int origin=e_SEEK_SET)
    {
        unsigned char of = c;
        int count;

        if ((count = this->WriteAt((char*)&of, 1, offset, origin)) > 0)
            return of;

        if (count < 0)
            return count;

        return -e_ERROR_ENDOF;
    }

    /**
     **********************************************************************
     * Function: Putx
     *
     *   Author: $author$
     *     Date: 8/4/2004
     **********************************************************************
     */
    int Putx(int c)
    {
        int i;
        char nibble[2];

        nibble[1] = c & 15;
        nibble[0] = (c >> 4) & 15;

        for (i=0; i<2; i++)
        {
            if ((nibble[i]>=0)&(nibble[i]<=9))
                nibble[i] += '0';

            else nibble[i] = 'a' + (nibble[i]-10);
        }
        return Write(nibble,2);
    }
    /**
     **********************************************************************
     * Function: CopyStreamEndc
     *
     * Author: $author$
     * Date:   6/16/2004
     **********************************************************************
     */
    int CopyStreamEndc
    (cCharStreamT<TIs> &stream, char endc, int skipc=-1)
    {
        int length;

        if (0 <= (length = Clear()))
            length = WriteStreamEndc(stream, endc, skipc);

        return length;
    }
    /**
     **********************************************************************
     * Function: WriteStreamEndc
     *
     * Author: $author$
     * Date:   6/16/2004
     **********************************************************************
     */
    int WriteStreamEndc
    (cCharStreamT<TIs> &stream, char endc, int skipc=-1)
    {
        int c,length=0;

        do
        {
            if (0 > (c = stream.Getc()))
            {
                if (endc < 0)
                    return length;

                return c;
            }

            if ((c != endc) && (c != skipc))
            {
                if (0 > (c = Putc(c)))
                    return c;

                length++;
            }
        }
        while (c != endc);

        return length;
    }

    /**
     **********************************************************************
     * Function: CopyUpper
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    int CopyUpper(const char *buffer,int size=-1)
    {
        int length;

        if ((length=Clear()) >= 0)
            length=WriteUpper(buffer,size);

        return length;
    }
    /**
     **********************************************************************
     * Function: WriteUpper
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    int WriteUpper(const char *buffer, int size=-1)
    {
        char c;
        int length,count;

        if (size<0)
            size=strlen(buffer);

        for (length=0; length<size; length++)
        {
            c=*(buffer++);
            if (0 > (count=this->Put(toupper(c))))
               return count;
        }
        return length;
    }

    /**
     **********************************************************************
     * Function: CopyEscaped
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    int CopyEscaped(const char *buffer,int size=-1)
    {
        int length;

        if ((length=Clear()) >= 0)
            length=WriteEscaped(buffer,size);

        return length;
    }
    /**
     **********************************************************************
     * Function: WriteEscaped
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    int WriteEscaped(const char *buffer,int size=-1)
    {
        /**
         **********************************************************************
         *   Enum: eState
         *
         * Author: $author$
         *   Date: 8/25/2003
         **********************************************************************
         */
        enum eState
        {
            e_STATE_CHAR,
            e_STATE_ESC
        };

        char c;
        int i,len,length;
        eState s;

        length=0;

        if (size<0)
            size=strlen(buffer);

        s=e_STATE_CHAR;

        for (i=0; i<size; i++)
        {
            switch(s)
            {
            case e_STATE_ESC:
                s=e_STATE_CHAR;
                switch(c=buffer[i])
                {
                case 'n': 
                    c='\n'; 
                    break;
                case 'r': 
                    c='\r'; 
                    break;
                case 't': 
                    c='\t'; 
                    break;
                case 'v': 
                    c='\v'; 
                    break;
                }
                if ((len=this->Put(c)) < 0)
                   return len;
                length++;
                break;

            default:
                if ('\\'==(c=buffer[i]))
                    s=e_STATE_ESC;
                else if ((len=this->Put(buffer[i])) < 0)
                        return len;
                else length++;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteInt
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    int CopyInt(int i)
    {
        int length;

        if (0 <= (length = Clear()))
            length = WriteInt(i);

        return length;
    }
    /**
     **********************************************************************
     * Function: WriteInt
     *
     *   Author: $author$
     *     Date: 1/5/2004
     **********************************************************************
     */
    int WriteInt(int i)
    {
        int length;
        bool negative;
        char digits[16];

        if ((negative = (0 > i)))
            i = -i;

        for (length = sizeof(digits); length > 0;)
        {
            digits[--length] = (i % 10) + '0';

            if (0 >= (i /= 10))
                break;
        }

        if (negative && (length > 0))
            digits[--length] = '-';

        return Write(digits+length, sizeof(digits)-length);
    }
};


#endif

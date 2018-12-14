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
 *   File: cstreaminterface.hxx
 *
 * Author: $author$
 *   Date: 8/24/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTREAMINTERFACE_HXX
#define _CSTREAMINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cStreamInterface
 *
 * Author: $author$
 *   Date: 8/24/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cStreamInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    enum
    {
        e_O_APPEND      = 0x0001,
        e_O_BINARY      = 0x0002,
        e_O_CREAT       = 0x0004,
        e_O_EXCL        = 0x0008,
        e_O_NONBLOCK    = 0x0010,
        e_O_RANDOM      = 0x0020,
        e_O_RDONLY      = 0x0040,
        e_O_RDWR        = 0x0080,
        e_O_SEQUENTIAL  = 0x0100,
        e_O_SYNC        = 0x0200,
        e_O_TEMPORARY   = 0x0400,
        e_O_TEXT        = 0x0800,
        e_O_TRUNC       = 0x1000,
        e_O_WRONLY      = 0x2000,

        e_FIRST_O       = e_O_APPEND,
        e_LAST_O        = e_O_WRONLY 
    };

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    enum
    {
        e_S_IREAD  = 00400,
        e_S_IWRITE = 00200,
        e_S_IEXEC  = 00100,
        e_S_IRUSR  = 00400,
        e_S_IWUSR  = 00200,
        e_S_IXUSR  = 00100,
        e_S_IRGRP  = 00040,
        e_S_IWGRP  = 00020,
        e_S_IXGRP  = 00010,
        e_S_IROTH  = 00004,
        e_S_IWOTH  = 00002,
        e_S_IXOTH  = 00001,
        e_S_IRWXU  = 00700,
        e_S_IRWXG  = 00070,
        e_S_IRWXO  = 00007,

        e_FIRST_S  = e_S_IXOTH,
        e_LAST_S   = e_S_IRUSR
    };

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     * Date:   7/1/2003
     **********************************************************************
     */
    enum
    {
        e_SEEK_SET = 0,
        e_SEEK_CUR,
        e_SEEK_END
    };

    /**
     **********************************************************************
     * Function: Close
     *
     * Author: $author$
     * Date:   10/25/2003
     **********************************************************************
     */
    virtual eError Close() = 0;

    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual long SetSize(long size) = 0;
    /**
     **********************************************************************
     * Function: GetSize
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual long GetSize() const = 0;
    /**
     **********************************************************************
     * Function: SetLength
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual long SetLength(long length) = 0;
    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual long GetLength() const = 0;

    /**
     **********************************************************************
     * Function: Tell
     *
     * Author: $author$
     * Date:   11/6/2003
     **********************************************************************
     */
    virtual long Tell() const = 0;
    /**
     **********************************************************************
     * Function: Seek
     *
     * Author: $author$
     * Date:   11/6/2003
     **********************************************************************
     */
    virtual long Seek(long offset, int origin=e_SEEK_SET) = 0;

    /**
     **********************************************************************
     * Function: Fill
     *
     * Author: $author$
     * Date:   11/20/2003
     **********************************************************************
     */
    virtual int Fill() = 0;
    /**
     **********************************************************************
     * Function: Flush
     *
     * Author: $author$
     * Date:   11/20/2003
     **********************************************************************
     */
    virtual int Flush() = 0;
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual int Clear() = 0;
};


#endif

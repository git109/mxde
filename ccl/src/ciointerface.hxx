/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: ciointerface.hxx
 *
 * Author: $author$
 *   Date: 8/5/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIOINTERFACE_HXX
#define _CIOINTERFACE_HXX

#include "cerror.h"
#include "platform.h"
#include "platformio.h"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cIoInterface
 *
 * Author: $author$
 *   Date: 8/5/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cIoInterface
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
     * Function: FlagsToPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static eError FlagsToPlatform(int &pflags, int flags)
    {
        int flag;

        pflags = 0;

        for (flag = e_FIRST_O; flag <= e_LAST_O; flag <<= 1)
        {
            if (flag & flags)
            if (FlagOnPlatform(flag))
                pflags |= FlagToPlatform(flag);
            else
            {
                pflags = flag;
                return e_ERROR_NOT_DEFINED;
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FlagOnPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static int FlagOnPlatform(int flag)
    {
        switch(flag)
        {
        case e_O_APPEND    : return PLATFORMIO_HAS_O_APPEND    ;
        case e_O_BINARY    : return PLATFORMIO_HAS_O_BINARY    ;
        case e_O_CREAT     : return PLATFORMIO_HAS_O_CREAT     ;
        case e_O_EXCL      : return PLATFORMIO_HAS_O_EXCL      ;
        case e_O_NONBLOCK  : return PLATFORMIO_HAS_O_NONBLOCK  ;
        case e_O_RANDOM    : return PLATFORMIO_HAS_O_RANDOM    ;
        case e_O_RDONLY    : return PLATFORMIO_HAS_O_RDONLY    ;
        case e_O_RDWR      : return PLATFORMIO_HAS_O_RDWR      ;
        case e_O_SEQUENTIAL: return PLATFORMIO_HAS_O_SEQUENTIAL;
        case e_O_SYNC      : return PLATFORMIO_HAS_O_SYNC      ;
        case e_O_TEMPORARY : return PLATFORMIO_HAS_O_TEMPORARY ;
        case e_O_TEXT      : return PLATFORMIO_HAS_O_TEXT      ;
        case e_O_TRUNC     : return PLATFORMIO_HAS_O_TRUNC     ;
        case e_O_WRONLY    : return PLATFORMIO_HAS_O_WRONLY    ;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: FlagToPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static int FlagToPlatform(int flag)
    {
        switch(flag)
        {
        case e_O_APPEND    : return PLATFORMIO_O_APPEND    ;
        case e_O_BINARY    : return PLATFORMIO_O_BINARY    ;
        case e_O_CREAT     : return PLATFORMIO_O_CREAT     ;
        case e_O_EXCL      : return PLATFORMIO_O_EXCL      ;
        case e_O_NONBLOCK  : return PLATFORMIO_O_NONBLOCK  ;
        case e_O_RANDOM    : return PLATFORMIO_O_RANDOM    ;
        case e_O_RDONLY    : return PLATFORMIO_O_RDONLY    ;
        case e_O_RDWR      : return PLATFORMIO_O_RDWR      ;
        case e_O_SEQUENTIAL: return PLATFORMIO_O_SEQUENTIAL;
        case e_O_SYNC      : return PLATFORMIO_O_SYNC      ;
        case e_O_TEMPORARY : return PLATFORMIO_O_TEMPORARY ;
        case e_O_TEXT      : return PLATFORMIO_O_TEXT      ;
        case e_O_TRUNC     : return PLATFORMIO_O_TRUNC     ;
        case e_O_WRONLY    : return PLATFORMIO_O_WRONLY    ;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: ModesToPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static eError ModesToPlatform(int &pmodes, int modes)
    {
        int mode;

        pmodes = 0;

        for (mode = e_FIRST_S; mode <= e_LAST_S; mode <<= 1)
        {
            if (mode & modes)
            if (ModeOnPlatform(mode))
                pmodes |= ModeToPlatform(mode);
            else
            {
                pmodes = mode;
                return e_ERROR_NOT_DEFINED;
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: ModeOnPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static int ModeOnPlatform(int mode)
    {
        switch(mode)
        {
        case e_S_IREAD  : return PLATFORMIO_HAS_S_IREAD ;
        case e_S_IWRITE : return PLATFORMIO_HAS_S_IWRITE;
        case e_S_IEXEC  : return PLATFORMIO_HAS_S_IEXEC ;
        case e_S_IRGRP  : return PLATFORMIO_HAS_S_IRGRP ;
        case e_S_IWGRP  : return PLATFORMIO_HAS_S_IWGRP ;
        case e_S_IXGRP  : return PLATFORMIO_HAS_S_IXGRP ;
        case e_S_IROTH  : return PLATFORMIO_HAS_S_IROTH ;
        case e_S_IWOTH  : return PLATFORMIO_HAS_S_IWOTH ;
        case e_S_IXOTH  : return PLATFORMIO_HAS_S_IXOTH ;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: ModeToPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static int ModeToPlatform(int mode)
    {
        switch(mode)
        {
        case e_S_IREAD  : return PLATFORMIO_S_IREAD ;
        case e_S_IWRITE : return PLATFORMIO_S_IWRITE;
        case e_S_IEXEC  : return PLATFORMIO_S_IEXEC ;
        case e_S_IRGRP  : return PLATFORMIO_S_IRGRP ;
        case e_S_IWGRP  : return PLATFORMIO_S_IWGRP ;
        case e_S_IXGRP  : return PLATFORMIO_S_IXGRP ;
        case e_S_IROTH  : return PLATFORMIO_S_IROTH ;
        case e_S_IWOTH  : return PLATFORMIO_S_IWOTH ;
        case e_S_IXOTH  : return PLATFORMIO_S_IXOTH ;
        }
        return 0;
    }
};

#endif /* _CIOINTERFACE_HXX */

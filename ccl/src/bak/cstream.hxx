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
 *   File: cstream.hxx
 *
 * Author: $author$
 *   Date: 7/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTREAM_HXX
#define _CSTREAM_HXX

#include "cerror.h"
#include "platform.h"
#include "platformio.h"
#include "cstreaminterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cStream
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class cStream
: virtual public cStreamInterface,
  public cImplement
{
public:
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


#endif

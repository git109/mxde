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

#include "ciointerface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 * Enum:
 *
 * Author: $author$
 * Date:   5/23/2014
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
 *  Class: cStreamInterface
 *
 * Author: $author$
 *   Date: 8/24/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cStreamInterface
: virtual public cInterface,
  virtual public cIoInterface
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
        e_SEEK_SET = ::e_SEEK_SET,
        e_SEEK_CUR = ::e_SEEK_CUR,
        e_SEEK_END = ::e_SEEK_END
    };

    /**
     **********************************************************************
     * Function: OriginToPlatform
     *
     *   Author: $author$
     *     Date: 7/18/2003
     **********************************************************************
     */
    static int OriginToPlatform(int origin)
    {
        switch(origin)
        {
        case e_SEEK_SET: return PLATFORMIO_SEEK_SET;
        case e_SEEK_CUR: return PLATFORMIO_SEEK_CUR;
        case e_SEEK_END: return PLATFORMIO_SEEK_END;
        }
        return PLATFORMIO_SEEK_SET;
    }

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

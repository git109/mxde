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
 *   File: cfiletimesetinterface.hxx
 *
 * Author: $author$
 *   Date: 4/25/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILETIMESETINTERFACE_HXX
#define _CFILETIMESETINTERFACE_HXX

#include "cfiletimeinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileTimeSetInterface
 *
 * Author: $author$
 *   Date: 4/18/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileTimeSetInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetFirstFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetFirstFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const = 0;
    /**
     **********************************************************************
     * Function: GetLastFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetLastFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const = 0;

    /**
     **********************************************************************
     * Function: AddFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *AddFileTime
    (cTimeInterface &time, int type=cFileTimeInterface::e_TYPE_MODIFIED) = 0;
    /**
     **********************************************************************
     * Function: DeleteFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual eError DeleteFileTime(cFileTimeInterface &time) = 0;
    /**
     **********************************************************************
     * Function: DeleteAllFileTimes
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual int DeleteAllFileTimes() = 0;
};

#endif /* _CFILETIMESETINTERFACE_HXX */
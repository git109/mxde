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
 *   File: cfiletimesetimplement.hxx
 *
 * Author: $author$
 *   Date: 6/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILETIMESETIMPLEMENT_HXX
#define _CFILETIMESETIMPLEMENT_HXX

#include "cfiletimesetinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileTimeSetImplement
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cFileTimeSetImplement
: virtual public cFileTimeSetInterface
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
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetLastFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetLastFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: AddFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *AddFileTime
    (cTimeInterface &time, 
     int type=cFileTimeInterface::e_TYPE_MODIFIED)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: DeleteFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual eError DeleteFileTime(cFileTimeInterface &time)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: DeleteAllFileTimes
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual int DeleteAllFileTimes()
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
};

#endif /* _CFILETIMESETIMPLEMENT_HXX */
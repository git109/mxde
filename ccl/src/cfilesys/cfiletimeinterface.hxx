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
 *   File: cfiletimeinterface.hxx
 *
 * Author: $author$
 *   Date: 4/22/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILETIMEINTERFACE_HXX
#define _CFILETIMEINTERFACE_HXX

#include "ctimeinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileTimeInterface
 *
 * Author: $author$
 *   Date: 4/17/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileTimeInterface
: virtual public cTimeInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 4/17/2004
     **********************************************************************
     */
    enum
    {
        e_TYPE_NONE     = 0,
        e_TYPE_MODIFIED = 1,
        e_TYPE_CREATED  = 2,
        e_TYPE_ACCESSED = 4,
        e_TYPE_NEXT,
        e_TYPE_ANY = ((e_TYPE_NEXT-1) << 1) - 1
    };

    /**
     **********************************************************************
     * Function: SetTimeType
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetTimeType(int type) = 0;
    /**
     **********************************************************************
     * Function: GetTimeType
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetTimeType() const = 0;
    /**
     **********************************************************************
     * Function: GetTimeTypeName
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual const char *GetTimeTypeName() const = 0;

    /**
     **********************************************************************
     * Function: GetNextFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetNextFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetPreviousFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const = 0;
};

#endif /* _CFILETIMEINTERFACE_HXX */
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
 *   File: cfiletimeimplement.hxx
 *
 * Author: $author$
 *   Date: 6/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILETIMEIMPLEMENT_HXX
#define _CFILETIMEIMPLEMENT_HXX

#include "cfiletimeinterface.hxx"
#include "ctimeimplement.hxx"

/**
 **********************************************************************
 *  Class: cFileTimeImplement
 *
 * Author: $author$
 *   Date: 4/20/2004
 **********************************************************************
 */
class cFileTimeImplement
: virtual public cFileTimeInterface,
  virtual public cTimeImplement
{
public:
    /**
     **********************************************************************
     * Function: SetTimeType
     *
     *   Author: $author$
     *     Date: 4/21/2004
     **********************************************************************
     */
    virtual int SetTimeType(int type)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetTimeType
     *
     *   Author: $author$
     *     Date: 4/21/2004
     **********************************************************************
     */
    virtual int GetTimeType() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetTimeTypeName
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual const char *GetTimeTypeName() const
    {
        switch(GetTimeType())
        {
        case e_TYPE_MODIFIED:
            return "modified";

        case e_TYPE_CREATED:
            return "created";

        case e_TYPE_ACCESSED:
            return "accessed";
        }
        return "";
    }

    /**
     **********************************************************************
     * Function: GetNextFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetNextFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetPreviousFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetPreviousFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        return 0;
    }
};

#endif /* _CFILETIMEIMPLEMENT_HXX */
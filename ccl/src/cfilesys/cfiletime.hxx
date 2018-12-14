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
 *   File: cfiletime.hxx
 *
 * Author: $author$
 *   Date: 6/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILETIME_HXX
#define _CFILETIME_HXX

#include "cfiletimeimplement.hxx"
#include "ctime.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cFileTime
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cFileTime
: virtual public cFileTimeInterface,
  virtual public cFileTimeImplement,
  public cDynamicListItemT<cFileTime, cTime>
{
public:
    typedef cDynamicListItemT<cFileTime, cTime> cIs;

    int m_type;

    /**
     **********************************************************************
     * Constructor: cFileTime
     *
     *      Author: $author$
     *        Date: 4/21/2004
     **********************************************************************
     */
    cFileTime(int type=e_TYPE_MODIFIED)
    : m_type(type)
    {
    }

    /**
     **********************************************************************
     * Function: GetNextFileTime
     *
     *   Author: $author$
     *     Date: 4/21/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetNextFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        int time_type;
        cFileTime *file_time;

        if ((file_time = cListItemIs::GetNext()))
        do
        {
            if (0 < (time_type = file_time->GetTimeType()))
            if (0 != (time_type &= type))
                return file_time;
        }
        while ((file_time = file_time->GetNext()));

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetPreviousFileTime
     *
     *   Author: $author$
     *     Date: 4/21/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetPreviousFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        int time_type;
        cFileTime *file_time;

        while ((file_time = cListItemIs::GetPrevious()))
        do
        {
            if (0 < (time_type = file_time->GetTimeType()))
            if (0 != (time_type &= type))
                return file_time;
        }
        while ((file_time = file_time->GetPrevious()));

        return 0;
    }

    /**
     **********************************************************************
     * Function: SetTimeType
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetTimeType(int type)
    {
        return m_type = type;
    }
    /**
     **********************************************************************
     * Function: GetTimeType
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetTimeType() const
    {
        return m_type;
    }
};

#endif /* _CFILETIME_HXX */
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
 *   File: cfiletimeset.hxx
 *
 * Author: $author$
 *   Date: 6/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILETIMESET_HXX
#define _CFILETIMESET_HXX

#include "cfiletimesetimplement.hxx"
#include "cfiletime.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cFileTimeSetT
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
template
<class TAs, class TIs=cInstance>
class cFileTimeSetT
: virtual public cFileTimeSetInterface,
  virtual public cFileTimeSetImplement,
  public cDynamicListT<cFileTime,TAs,TIs>
{
public:
    typedef cDynamicListT<cFileTime,TAs,TIs> cIs;

    int m_count;

    /**
     **********************************************************************
     * Constructor: cFileTimeSetT
     *
     *      Author: $author$
     *        Date: 4/21/2004
     **********************************************************************
     */
    cFileTimeSetT()
    : m_count(0)
    {
    }

#if defined(WIN32)
    /**
     **********************************************************************
     * Function: AddFileTime
     *
     *   Author: $author$
     *     Date: 4/18/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *AddFileTime
    (FILETIME &file_time, 
     int type=cFileTimeInterface::e_TYPE_MODIFIED)
    {
        int t;
        cFileTimeInterface *file_time_interface=0;
        SYSTEMTIME system_time;
        cTime time;

        if (FileTimeToSystemTime(&file_time, &system_time))
        if (0 <= (t = time.SetYear(system_time.wYear)))
        if (0 <= (t = time.SetMonth(system_time.wMonth)))
        if (0 <= (t = time.SetDay(system_time.wDay)))
        if (0 <= (t = time.SetHour(system_time.wHour)))
        if (0 <= (t = time.SetMinute(system_time.wMinute)))
        if (0 <= (t = time.SetSecond(system_time.wSecond)))
            file_time_interface = AddFileTime(time, type);

        return file_time_interface;
    }
#endif /* defined(WIN32) */
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
        int year,month,day,hour,minute,second;
        cFileTime *file_time;

        if ((file_time = new cFileTime(type)))
        {
            if (0 <= (year = file_time->SetYear(year=time.GetYear())))
            if (0 <= (month = file_time->SetMonth(month=time.GetMonth())))
            if (0 <= (day = file_time->SetDay(day=time.GetDay())))
            if (0 <= (hour = file_time->SetHour(hour=time.GetHour())))
            if (0 <= (minute = file_time->SetMinute(minute=time.GetMinute())))
            if (0 <= (second = file_time->SetSecond(second=time.GetSecond())))
            {
                Add(file_time);
                m_count++;
                return file_time;
            }

            delete file_time;
            file_time = 0;
        }
        return file_time;
    }
    /**
     **********************************************************************
     * Function: DeleteFileTime
     *
     *   Author: $author$
     *     Date: 4/22/2004
     **********************************************************************
     */
    virtual eError DeleteFileTime(cFileTimeInterface &time)
    {
        eError error=e_ERROR_NOT_INSTANTIATED;
        cFileTime *file_time;

        if ((file_time = GetFirst()))
        do
        {
            if (&time == file_time)
            {
                Delete(file_time);
                error = Free(file_time);
                break;
            }
        }
        while ((file_time = file_time->GetNext()));

        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteAllFileTimes
     *
     *   Author: $author$
     *     Date: 4/22/2004
     **********************************************************************
     */
    virtual int DeleteAllFileTimes()
    {
        int old_count=m_count;
        eError error;

        m_count = 0;

        if ((error = Clear()))
            return -error;

        return old_count;
    }

    /**
     **********************************************************************
     * Function: GetFirstFileTime
     *
     *   Author: $author$
     *     Date: 4/21/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetFirstFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        int time_type;
        cFileTimeInterface *file_time;

        if ((file_time = GetFirst()))
        if (0 < (time_type = file_time->GetTimeType()))
        if (0 == (time_type & type))
            return file_time->GetNextFileTime(type);
        else return file_time;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetLastFileTime
     *
     *   Author: $author$
     *     Date: 4/21/2004
     **********************************************************************
     */
    virtual cFileTimeInterface *GetLastFileTime
    (int type=cFileTimeInterface::e_TYPE_ANY) const
    {
        int time_type;
        cFileTimeInterface *file_time;

        if ((file_time = GetLast()))
        if (0 < (time_type = file_time->GetTimeType()))
        if (0 == (time_type & type))
            return file_time->GetPreviousFileTime(type);
        else return file_time;
        return 0;
    }

};

/**
 **********************************************************************
 *  Class: cFileTimeSet
 *
 * Author: $author$
 *   Date: 6/12/2005
 **********************************************************************
 */
class cFileTimeSet
: public cFileTimeSetT<cFileTimeSet, cInstance>
{
public:
    typedef cFileTimeSetT<cFileTimeSet, cInstance> cIs;

    /**
     **********************************************************************
     * Constructor: cFileTimeSet
     *
     *      Author: $author$
     *        Date: 6/12/2005
     **********************************************************************
     */
    cFileTimeSet() 
    {
    }
};

#endif /* _CFILETIMESET_HXX */
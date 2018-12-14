/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cfileentry.hxx
 *
 * Author: $author$
 *   Date: 4/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEENTRY_HXX
#define _CFILEENTRY_HXX

#if defined(WIN32)
/* Windows
 */
#include <windows.h>
#else /* defined(WIN32) */
/* Unix
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define HANDLE DIR*
#define INVALID_HANDLE_VALUE NULL
#endif /* defined(WIN32) */

#include "cfileentryimplement.hxx"
#include "cfileentryinterface.hxx"
#include "ctime.hxx"
#include "cinstance.hxx"
#include "clistt.hxx"
#include "ccharbuffer.hxx"

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
        cFileTimeInterface *file_time;

        while ((file_time = cListItemIs::GetNext()))
        {
            if (0 < (time_type = file_time->GetTimeType()))
            if (0 != (time_type & type))
                return file_time;
        }
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
        cFileTimeInterface *file_time;

        while ((file_time = cListItemIs::GetPrevious()))
        {
            if (0 < (time_type = file_time->GetTimeType()))
            if (0 != (time_type & type))
                return file_time;
        }
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

/**
 **********************************************************************
 *  Class: cFileTimeSet
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cFileTimeSet
: virtual public cFileTimeSetInterface,
  virtual public cFileTimeSetImplement,
  public cDynamicListT<cFileTime,cFileTimeSet>
{
public:
    typedef cDynamicListT<cFileTime,cFileTimeSet> cIs;

    int m_count;

    /**
     **********************************************************************
     * Constructor: cFileTimeSet
     *
     *      Author: $author$
     *        Date: 4/21/2004
     **********************************************************************
     */
    cFileTimeSet()
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
    (FILETIME &file_time, int type=cFileTimeInterface::e_TYPE_MODIFIED)
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
 *  Class: cFileEntry
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cFileEntry
: virtual public cFileEntryInterface,
  virtual public cFileEntryImplement,
  public cFileTimeSet,
  public cDynamicListItemT<cFileEntry,cInstance>
{
public:
    typedef cDynamicListItemT<cFileEntry,cInstance> cIs;

    /**
     **********************************************************************
     * Constructor: cFileEntry
     *
     *      Author: $author$
     *        Date: 4/21/2004
     **********************************************************************
     */
    cFileEntry() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cFileEntrySet
 *
 * Author: $author$
 *   Date: 4/26/2005
 **********************************************************************
 */
class cFileEntrySet
: virtual public cFileEntrySetInterface,
  virtual public cFileEntrySetImplement,
  public cDynamicListT<cFileEntry,cFileEntrySet,cInstance>
{
public:
    typedef cDynamicListT<cFileEntry,cFileEntrySet,cInstance> cIs;

    /**
     **********************************************************************
     * Constructor: cFileEntrySet
     *
     *      Author: $author$
     *        Date: 4/26/2005
     **********************************************************************
     */
    cFileEntrySet() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cDirectoryEntry
 *
 * Author: $author$
 *   Date: 4/22/2004
 **********************************************************************
 */
class cDirectoryEntry
: virtual public cDirectoryEntryImplement,
  public cFileEntry
{
public:
    typedef cFileEntry cIs;

    /**
     **********************************************************************
     * Constructor: cDirectoryEntry
     *
     *      Author: $author$
     *        Date: 4/22/2004
     **********************************************************************
     */
    cDirectoryEntry() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cDirectory
 *
 * Author: $author$
 *   Date: 4/22/2004
 **********************************************************************
 */
class cDirectory
: virtual public cDirectoryImplement,
  public cDirectoryEntry
{
public:
    typedef cDirectoryEntry cIs;

    HANDLE m_handle;

#if defined(WIN32)
/* Windows
 */
	WIN32_FIND_DATA m_ff;
	struct
	{
		SECURITY_DESCRIPTOR m_sd;
		char m_data[4096];
	} m_sd;
#else /* defined(WIN32) */
/* Unix
 */
    struct stat m_st;
    struct dirent *m_dirent;
#endif /* defined(WIN32) */

    cCharBuffer m_path;

    /**
     **********************************************************************
     * Constructor: cDirectory
     *
     *      Author: $author$
     *        Date: 4/22/2004
     **********************************************************************
     */
    cDirectory
    (const char *path=0, int pathlen=-1,
     HANDLE handle=INVALID_HANDLE_VALUE)
    : m_handle(handle) 
    {
        eError error;

        if (path)
        if (0 > (pathlen = m_path.Copy(path, pathlen)))
            throw(error = -pathlen);
    }
    /**
     **********************************************************************
     * Destructor: ~cDirectory
     *
     *     Author: $author$
     *       Date: 4/22/2004
     **********************************************************************
     */
    virtual ~cDirectory()
    {
		if (INVALID_HANDLE_VALUE != m_handle)
#if defined(WIN32)
/* Windows
 */
			FindClose(m_handle);
#else /* defined(WIN32) */
/* Unix
 */
			closedir(m_handle);
#endif /* defined(WIN32) */
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 4/22/2004
     **********************************************************************
     */
    virtual eError Open(const char *path, int pathlen=-1)
    {
        int count;
        eError error=e_ERROR_FAILED;

        if (0 > (pathlen = m_path.Copy(path, pathlen)))
            error = -pathlen;

        else if (0 > (count = DeleteAllFileTimes()))
                error = -count;

        else if (0 > (count = DeleteAllEntries()))
                error = -count;

        else
        {
#if defined(WIN32)
/* Windows
 */
            HANDLE handle;

		    if (INVALID_HANDLE_VALUE == 
                (handle = FindFirstFile(path, &m_ff)))
                return error;

            else
            {
                FindClose(handle);

                if (!(FILE_ATTRIBUTE_DIRECTORY 
                      & m_ff.dwFileAttributes))
                    return e_ERROR_FAILED;

#endif /* defined(WIN32) */

                error = IsFound(path);

#if defined(WIN32)
            }
#endif /* defined(WIN32) */
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/22/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: IsFound
     *
     *   Author: $author$
     *     Date: 4/22/2004
     **********************************************************************
     */
    virtual eError IsFound(const char *path)
    {
        eError error=e_ERROR_NONE;
        cFileTimeInterface *file_time;

#if defined(WIN32)
/* Windows
 */
        if (!(file_time = AddFileTime
            (m_ff.ftLastWriteTime, 
             cFileTimeInterface::e_TYPE_MODIFIED)))
            error = e_ERROR_FAILED;

        else if (!(file_time = AddFileTime
                (m_ff.ftCreationTime, 
                 cFileTimeInterface::e_TYPE_CREATED)))
                error = e_ERROR_FAILED;

        else if (!(file_time = AddFileTime
                (m_ff.ftLastAccessTime, 
                 cFileTimeInterface::e_TYPE_ACCESSED)))
                error = e_ERROR_FAILED;

#else /* defined(WIN32) */
/* Unix
 */
        int err;

        if ((err = stat(path, &m_st)))
            error = e_ERROR_FAILED;
#endif /* defined(WIN32) */

        return error;
    }
};

#endif /* ndef _CFILEENTRY_HXX */

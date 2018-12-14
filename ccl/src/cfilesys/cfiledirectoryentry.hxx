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
 *   File: cfiledirectoryentry.hxx
 *
 * Author: $author$
 *   Date: 5/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDIRECTORYENTRY_HXX
#define _CFILEDIRECTORYENTRY_HXX

#if defined(WIN32)
/*
 * Windows
 */
#include <windows.h>
#define DIRECTORY HANDLE
#define INVALID_DIRECTORY_VALUE INVALID_HANDLE_VALUE
#define DIRECTORY_SEPARATOR_CHAR '\\'
#define SECURITY_DESCRIPTOR_DATA_SIZE 4096
#else /* defined(WIN32) */
/*
 * Unix
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define DIRECTORY DIR*
#define INVALID_DIRECTORY_VALUE NULL
#define DIRECTORY_SEPARATOR_CHAR '/'
#endif /* defined(WIN32) */

#define DIRECTORY_WILDCARD_CHAR '*'
#define DIRECTORY_DOT_CHAR '.'

#include "cfiledirectoryentryinterface.hxx"
#include "cfiletimeset.hxx"
#include "cfilesize.hxx"
#include "cfilecompare.hxx"
#include "ccchartocharbuffer.hxx"
#include "cccharbuffer.hxx"
#include "chandlet.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cFileDirectoryEntrySize
 *
 * Author: $author$
 *   Date: 6/10/2005
 **********************************************************************
 */
class cFileDirectoryEntrySize
: public cFileSizeT<cFileTimeSet>
{
public:
    typedef cFileSizeT<cFileTimeSet> cIs;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryCompare
 *
 * Author: $author$
 *   Date: 6/12/2005
 **********************************************************************
 */
class cFileDirectoryEntryCompare
: public cFileCompareT<cFileDirectoryEntrySize>
{
public:
    typedef cFileCompareT<cFileDirectoryEntrySize> cIs;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntry
 *
 * Author: $author$
 *   Date: 5/4/2005
 **********************************************************************
 */
class cFileDirectoryEntry
: virtual public cFileDirectoryEntryImplement,
  public cOpenedHandleT
  <DIRECTORY, (int)INVALID_DIRECTORY_VALUE, 
   cFileDirectoryEntryCompare>
{
public:
    typedef cOpenedHandleT
    <DIRECTORY, (int)INVALID_DIRECTORY_VALUE, 
     cFileDirectoryEntryCompare> cIs;

#if defined(WIN32)
/*
 * Windows
 */
	WIN32_FIND_DATA m_ff;
	struct
	{
		SECURITY_DESCRIPTOR m_sd;
		BYTE m_data[SECURITY_DESCRIPTOR_DATA_SIZE];
	} m_sd;
#else /* defined(WIN32) */
/*
 * Unix
 */
    struct stat m_stat;
    struct dirent *m_dirent;
#endif /* defined(WIN32) */

    cFileDirectoryInterface *m_directory;
    bool m_is_expanded;
    int m_type;
    cCCharBuffer m_name;
    cCCharToCharBuffer m_name_toc;

    /**
     **********************************************************************
     * Constructor: cFileDirectoryEntry
     *
     *      Author: $author$
     *        Date: 5/4/2005
     **********************************************************************
     */
    cFileDirectoryEntry
    (cFileDirectoryInterface *directory=0,
     int type=e_TYPE_NONE, const cChar* name=0, 
     int length=-1, const cFileTimeSetInterface *times = 0,
     tHandle handle=INVALID_DIRECTORY_VALUE, bool opened=false) 
    : m_directory(directory),
      m_type(type),
      m_is_expanded(false)
    {
        eError error;
        cFileTimeInterface *entrytime;

        if (name)
        {
            if (0 > (length = m_name.Write(name, length)))
                throw(error = -length);

            if (0 > (length = m_name_toc.WriteCChar(name, length)))
                throw(error = -length);
        }

        if (times)
        for (entrytime=times->GetFirstFileTime(); 
             entrytime; entrytime=entrytime->GetNextFileTime())
            AddFileTime(*entrytime, entrytime->GetTimeType());

        if (INVALID_DIRECTORY_VALUE != handle)
        if ((error = Attach(handle, opened)))
            throw(error);
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileDirectoryEntry
     *
     *      Author: $author$
     *        Date: 5/4/2005
     **********************************************************************
     */
    virtual ~cFileDirectoryEntry()
    {
        eError error;

        if (INVALID_DIRECTORY_VALUE != m_handle)
        if ((error = Detach()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: GetEntryAttributes
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual eError GetEntryAttributes
#if defined(WIN32)
/*
 * Windows
 */
    (tHandle handle, WIN32_FIND_DATA &ff) 
#else /* defined(WIN32) */
/*
 * Unix
 */
    (tHandle handle) 
#endif /* defined(WIN32) */
    {
        eError error = e_ERROR_FAILED;
        int length;

        if (0 > (length = DeleteAllFileTimes()))
            return error;

#if defined(WIN32)
/*
 * Windows
 */
        cFileTimeInterface *file_time;

        if ((file_time = AddFileTime
            (ff.ftLastWriteTime, 
             cFileTimeInterface::e_TYPE_MODIFIED)))

        if ((file_time = AddFileTime
            (ff.ftCreationTime, 
             cFileTimeInterface::e_TYPE_CREATED)))

        if ((file_time = AddFileTime
            (ff.ftLastAccessTime, 
             cFileTimeInterface::e_TYPE_ACCESSED)))

        if (0 < (length = m_name_toc.Copy(ff.cFileName)))

        if (0 < (length = m_name.Copyc(ff.cFileName)))
        {
            if (ff.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                m_type = e_TYPE_DIRECTORY;
            else m_type = e_TYPE_FILE;

            error = e_ERROR_NONE;
        }
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        return error;
    }

    /**
     **********************************************************************
     * Function: GetNextEntry
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual eError GetNextEntry() 
    {
        eError error = e_ERROR_ENDOF;

        if (INVALID_DIRECTORY_VALUE == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
/*
 * Windows
 */
        if (FindNextFile(m_handle, &m_ff))
            error = GetEntryAttributes(m_handle, m_ff);
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        return error;
    }

    /**
     **********************************************************************
     * Function: GetEntryType
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual int GetEntryType() const
    {
        return m_type;
    }

    /**
     **********************************************************************
     * Function: GetEntryNamec
     *
     *   Author: $author$
     *     Date: 8/4/2005
     **********************************************************************
     */
    virtual const char *GetEntryNamec(int &length) const 
    {
        const char *chars = m_name_toc.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetEntryName
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual const cChar *GetEntryName(int &length) const 
    {
        const cChar *chars = m_name.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetIsExpanded
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual bool SetIsExpanded(bool is=true) 
    {
        return m_is_expanded = is;
    }
    /**
     **********************************************************************
     * Function: GetIsExpanded
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual bool GetIsExpanded() const 
    {
        return m_is_expanded;
    }

    /**
     **********************************************************************
     * Function: GetIsCircular
     *
     *   Author: $author$
     *     Date: 6/20/2005
     **********************************************************************
     */
    virtual bool GetIsCircular() const 
    {
        bool is = false;
        int namelen;
        const cChar *name;

        if ((name = GetEntryName(namelen)))
        if (0 < namelen)
        if (name[0] == DIRECTORY_DOT_CHAR)
        if (!(is = (2 > namelen)))
        if (name[1] == DIRECTORY_DOT_CHAR)
            is = (3 > namelen);

        return is;
    }

    /**
     **********************************************************************
     * Function: GetIsDirectory
     *
     *   Author: $author$
     *     Date: 6/25/2005
     **********************************************************************
     */
    virtual bool GetIsDirectory() const 
    {
        bool is = (0 != (cFileDirectoryEntryInterface::
                   e_TYPE_DIRECTORY & m_type));

        return is;
    }

    /**
     **********************************************************************
     * Function: SetParentDirectory
     *
     *   Author: $author$
     *     Date: 6/16/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface* SetParentDirectory
    (cFileDirectoryInterface *directory) 
    {
        return m_directory = directory;
    }
    /**
     **********************************************************************
     * Function: GetParentDirectory
     *
     *   Author: $author$
     *     Date: 6/16/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface* GetParentDirectory() const 
    {
        return m_directory;
    }

    /**
     **********************************************************************
     * Function: GetFileTimeSet
     *
     *   Author: $author$
     *     Date: 6/22/2005
     **********************************************************************
     */
    virtual cFileTimeSetInterface& GetFileTimeSet()
    {
        return *this;
    }

    /**
     **********************************************************************
     * Function: GetFileCompare
     *
     *   Author: $author$
     *     Date: 6/24/2005
     **********************************************************************
     */
    virtual cFileCompareInterface& GetFileCompare() 
    {
        return *this;
    }

    /**
     **********************************************************************
     * Function: CompareByFileTime
     *
     *   Author: $author$
     *     Date: 6/23/2005
     **********************************************************************
     */
    virtual int CompareByFileTime
    (cFileTimeSetInterface &to, 
     int type=cFileTimeInterface::e_TYPE_ANY)
    {
        int unequal = 1;
        cFileTimeInterface *t1, *t2;

        if ((t1 = GetFirstFileTime(type)))
        if ((t2 = to.GetFirstFileTime(type)))
        {
            do
            {
                if (!(unequal = t1->CompareTime(*t2)))
                if ((t1 = t1->GetNextFileTime(type)))
                    continue;

                break;
            }
            while ((t2 = t2->GetNextFileTime(type)));
        }
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicFileDirectoryEntry
 *
 * Author: $author$
 *   Date: 5/19/2005
 **********************************************************************
 */
class cDynamicFileDirectoryEntry
: public cFileDirectoryEntry
{
public:
    typedef cFileDirectoryEntry cIs;

    /**
     **********************************************************************
     * Constructor: cDynamicFileDirectoryEntry
     *
     *      Author: $author$
     *        Date: 5/19/2005
     **********************************************************************
     */
    cDynamicFileDirectoryEntry
    (cFileDirectoryInterface *directory=0,
     int type=e_TYPE_NONE, const cChar* name=0, 
     int length=-1, const cFileTimeSetInterface *times=0,
     tHandle handle=INVALID_DIRECTORY_VALUE, bool opened=false) 
    : cIs(directory, type, name, length, times, handle, opened)
    {
    }
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 6/8/2005
     **********************************************************************
     */
    static cDynamicFileDirectoryEntry *CreateInstance
    (cFileDirectoryInterface *directory=0,
     int type=e_TYPE_NONE, const cChar* name=0, 
     int length=-1, const cFileTimeSetInterface *times=0,
     tHandle handle=INVALID_DIRECTORY_VALUE, bool opened=false) 
    {
        cDynamicFileDirectoryEntry *instance = 0;

        instance = new cDynamicFileDirectoryEntry
        (directory, type, name, length, times, handle, opened);
        return instance;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NONE;
        delete this;
        return error;
    }
};

#endif /* _CFILEDIRECTORYENTRY_HXX */
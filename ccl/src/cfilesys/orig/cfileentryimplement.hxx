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
 *   File: cfileentryimplement.hxx
 *
 * Author: $author$
 *   Date: 4/20/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEENTRYIMPLEMENT_HXX
#define _CFILEENTRYIMPLEMENT_HXX

#include "ctimeimplement.hxx"
#include "cfileentryinterface.hxx"

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

/**
 **********************************************************************
 *  Class: cFileEntryImplement
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cFileEntryImplement
: virtual public cFileEntryInterface
{
public:
    /**
     **********************************************************************
     * Function: SetParentDirectory
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError SetParentDirectory(cDirectoryEntryInterface *directory)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetParentDirectory
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cDirectoryEntryInterface *GetParentDirectory() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetDirectory
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cDirectoryEntryInterface *GetDirectory() const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetIsDirectory
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetIsDirectory(bool is_directory=true)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetIsDirectory
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual bool GetIsDirectory() const
    {
        return false;
    }

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual int SetType(int type)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetName(const char *name, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual const char *GetName(int &length) const
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }

    /**
     **********************************************************************
     * Function: GetNextEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cFileEntryInterface *GetNextEntry
    (int type=cFileEntryInterface::e_TYPE_ANY,
     const char *name=0, int namelen=-1) const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetPreviousEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cFileEntryInterface *GetPreviousEntry
    (int type=cFileEntryInterface::e_TYPE_ANY,
     const char *name=0, int namelen=-1) const
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cFileEntrySetImplement
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cFileEntrySetImplement
: virtual public cFileEntrySetInterface
{
public:
    /**
     **********************************************************************
     * Function: AddEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cFileEntryInterface *AddEntry
    (const char *name, int namelen=-1, 
     int type=cFileEntryInterface::e_TYPE_FILE)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: DeleteEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError DeleteEntry(cFileEntryInterface &entry)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: DeleteAllEntries
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual int DeleteAllEntries()
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cFileEntryInterface *GetFirstEntry
    (int type=cFileEntryInterface::e_TYPE_ANY,
     const char *name=0, int namelen=-1) const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetLastEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cFileEntryInterface *GetLastEntry
    (int type=cFileEntryInterface::e_TYPE_ANY,
     const char *name=0, int namelen=-1) const
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cDirectoryEntryImplement
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cDirectoryEntryImplement
: virtual public cDirectoryEntryInterface,
  virtual public cFileEntrySetImplement,
  virtual public cFileEntryImplement
{
public:
};

/**
 **********************************************************************
 *  Class: cDirectoryImplement
 *
 * Author: $author$
 *   Date: 4/21/2004
 **********************************************************************
 */
class cDirectoryImplement
: virtual public cDirectoryInterface
{
public:
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError Open(const char *path, int pathlen=-1)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
};

#endif /* ndef _CFILEENTRYIMPLEMENT_HXX */

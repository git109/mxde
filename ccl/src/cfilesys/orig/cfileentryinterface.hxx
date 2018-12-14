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
 *   File: cfileentryinterface.hxx
 *
 * Author: $author$
 *   Date: 4/17/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEENTRYINTERFACE_HXX
#define _CFILEENTRYINTERFACE_HXX

#include "cfiletimesetinterface.hxx"
#include "cfiletimeinterface.hxx"
#include "ctimeinterface.hxx"
#include "cinterface.hxx"

class c_INTERFACE_CLASS cDirectoryEntryInterface;

/**
 **********************************************************************
 *  Class: cFileEntryInterface
 *
 * Author: $author$
 *   Date: 4/17/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileEntryInterface
: virtual public cFileTimeSetInterface
{
public:

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 4/19/2004
     **********************************************************************
     */
    enum
    {
        e_TYPE_NONE      = 0,
        e_TYPE_FILE      = 1,
        e_TYPE_DIRECTORY = 2,
        e_TYPE_NEXT,
        e_TYPE_ANY = ((e_TYPE_NEXT-1) << 1) - 1
    };

    /**
     **********************************************************************
     * Function: SetParentDirectory
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError SetParentDirectory(cDirectoryEntryInterface *directory) = 0;
    /**
     **********************************************************************
     * Function: GetParentDirectory
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cDirectoryEntryInterface *GetParentDirectory() const = 0;
    /**
     **********************************************************************
     * Function: GetDirectory
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual cDirectoryEntryInterface *GetDirectory() const = 0;

    /**
     **********************************************************************
     * Function: SetIsDirectory
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetIsDirectory(bool is_directory=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsDirectory
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual bool GetIsDirectory() const = 0;

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual int SetType(int type) = 0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual int GetType() const = 0;

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetName(const char *name, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual const char *GetName(int &length) const = 0;

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
     const char *name=0, int namelen=-1) const = 0;
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
     const char *name=0, int namelen=-1) const = 0;
};

/**
 **********************************************************************
 *  Class: cFileEntrySetInterface
 *
 * Author: $author$
 *   Date: 4/19/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileEntrySetInterface
: virtual public cInterface
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
     int type=cFileEntryInterface::e_TYPE_FILE) = 0;
    /**
     **********************************************************************
     * Function: DeleteEntry
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError DeleteEntry(cFileEntryInterface &entry) = 0;
    /**
     **********************************************************************
     * Function: DeleteAllEntries
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual int DeleteAllEntries() = 0;

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
     const char *name=0, int namelen=-1) const = 0;
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
     const char *name=0, int namelen=-1) const = 0;
};

/**
 **********************************************************************
 *  Class: cDirectoryEntryInterface
 *
 * Author: $author$
 *   Date: 4/19/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDirectoryEntryInterface
: virtual public cFileEntrySetInterface,
  virtual public cFileEntryInterface
{
public:
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
};

/**
 **********************************************************************
 *  Class: cDirectoryInterface
 *
 * Author: $author$
 *   Date: 4/19/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDirectoryInterface
: virtual public cDirectoryEntryInterface
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
    virtual eError Open(const char *path, int pathlen=-1) = 0;
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/19/2004
     **********************************************************************
     */
    virtual eError Close() = 0;
};

#endif /* ndef _CFILEENTRYINTERFACE_HXX */

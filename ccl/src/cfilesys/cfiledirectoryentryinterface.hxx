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
 *   File: cfiledirectoryentryinterface.hxx
 *
 * Author: $author$
 *   Date: 4/30/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDIRECTORYENTRYINTERFACE_HXX
#define _CFILEDIRECTORYENTRYINTERFACE_HXX

#include "cfilecompareinterface.hxx"
#include "cfiletimesetinterface.hxx"
#include "cfiletimeinterface.hxx"
#include "cchar.hxx"

class c_INTERFACE_CLASS cFileDirectoryInterface;

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterface
 *
 * Author: $author$
 *   Date: 4/30/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileDirectoryEntryInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 5/1/2005
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
     * Function: SetEntryType
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual int SetEntryType(int type) = 0;
    /**
     **********************************************************************
     * Function: GetEntryType
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual int GetEntryType() const = 0;

    /**
     **********************************************************************
     * Function: SetEntryName
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual int SetEntryName
    (const cChar *chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetEntryName
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual const cChar *GetEntryName(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetEntryNamec
     *
     *   Author: $author$
     *     Date: 8/4/2005
     **********************************************************************
     */
    virtual const char *GetEntryNamec(int &length) const = 0;

    /**
     **********************************************************************
     * Function: GetNextEntry
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual eError GetNextEntry() = 0;

    /**
     **********************************************************************
     * Function: SetIsExpanded
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual bool SetIsExpanded(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsExpanded
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual bool GetIsExpanded() const = 0;

    /**
     **********************************************************************
     * Function: SetIsCircular
     *
     *   Author: $author$
     *     Date: 6/20/2005
     **********************************************************************
     */
    virtual bool SetIsCircular(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsCircular
     *
     *   Author: $author$
     *     Date: 6/20/2005
     **********************************************************************
     */
    virtual bool GetIsCircular() const = 0;

    /**
     **********************************************************************
     * Function: SetIsDirectory
     *
     *   Author: $author$
     *     Date: 6/25/2005
     **********************************************************************
     */
    virtual bool SetIsDirectory(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsDirectory
     *
     *   Author: $author$
     *     Date: 6/25/2005
     **********************************************************************
     */
    virtual bool GetIsDirectory() const = 0;

    /**
     **********************************************************************
     * Function: SetParentDirectory
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface* SetParentDirectory
    (cFileDirectoryInterface* directory) = 0;
    /**
     **********************************************************************
     * Function: GetParentDirectory
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface* GetParentDirectory() const = 0;

    /**
     **********************************************************************
     * Function: GetFileTimeSet
     *
     *   Author: $author$
     *     Date: 6/22/2005
     **********************************************************************
     */
    virtual cFileTimeSetInterface& GetFileTimeSet() = 0;

    /**
     **********************************************************************
     * Function: GetFileCompare
     *
     *   Author: $author$
     *     Date: 6/24/2005
     **********************************************************************
     */
    virtual cFileCompareInterface& GetFileCompare() = 0;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryImplement
 *
 * Author: $author$
 *   Date: 4/30/2005
 **********************************************************************
 */
class cFileDirectoryEntryImplement
: virtual public cFileDirectoryEntryInterface
{
public:
    /**
     **********************************************************************
     * Function: SetEntryType
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual int SetEntryType(int type) 
    {
        type = e_TYPE_NONE;
        return type;
    }
    /**
     **********************************************************************
     * Function: GetEntryType
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual int GetEntryType() const
    {
        int type = e_TYPE_NONE;
        return type;
    }

    /**
     **********************************************************************
     * Function: SetEntryName
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual int SetEntryName
    (const cChar *chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetEntryName
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual const cChar *GetEntryName(int &length) const 
    {
        const cChar *chars = 0;
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
        return is = false;
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
        bool is = false;
        return is;
    }

    /**
     **********************************************************************
     * Function: SetIsCircular
     *
     *   Author: $author$
     *     Date: 6/20/2005
     **********************************************************************
     */
    virtual bool SetIsCircular(bool is=true) 
    {
        return is = false;
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
        return is;
    }

    /**
     **********************************************************************
     * Function: SetIsDirectory
     *
     *   Author: $author$
     *     Date: 6/25/2005
     **********************************************************************
     */
    virtual bool SetIsDirectory(bool is=true) 
    {
        return is = false;
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
        bool is = false;
        return is;
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
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetParentDirectory
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface* SetParentDirectory
    (cFileDirectoryInterface *directory) 
    {
        return directory = 0;
    }
    /**
     **********************************************************************
     * Function: GetParentDirectory
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface* GetParentDirectory() const 
    {
        cFileDirectoryInterface* directory = 0;
        return directory;
    }
};

#endif /* _CFILEDIRECTORYENTRYINTERFACE_HXX */
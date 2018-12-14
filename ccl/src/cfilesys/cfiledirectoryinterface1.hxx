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
 *   File: cfiledirectoryinterface.hxx
 *
 * Author: $author$
 *   Date: 4/30/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDIRECTORYINTERFACE_HXX
#define _CFILEDIRECTORYINTERFACE_HXX

#include "cfiledirectoryentryinterface.hxx"
#include "cfiletimesetimplement.hxx"
#include "cfiletimesetinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileDirectoryInterface
 *
 * Author: $author$
 *   Date: 4/30/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileDirectoryInterface
: virtual public cFileTimeSetInterface
{
public:
    /**
     **********************************************************************
     * Function: OpenPath
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual eError OpenPath
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual eError Open() = 0;
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual eError Close() = 0;

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual int SetPath
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual const cChar* GetPath(int &length) const = 0;

    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 5/1/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetFirstEntry() = 0;
    /**
     **********************************************************************
     * Function: GetLastEntry
     *
     *   Author: $author$
     *     Date: 5/1/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetLastEntry() = 0;

    /**
     **********************************************************************
     * Function: SetEntry
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* SetEntry
    (cFileDirectoryEntryInterface* entry) = 0;
    /**
     **********************************************************************
     * Function: GetEntry
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetEntry() const = 0;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryImplement
 *
 * Author: $author$
 *   Date: 4/30/2005
 **********************************************************************
 */
class cFileDirectoryImplement
: virtual public cFileDirectoryInterface,
  virtual public cFileTimeSetImplement
{
public:
    /**
     **********************************************************************
     * Function: OpenPath
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual eError OpenPath
    (const cChar* chars, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual eError Open() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/30/2005
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual int SetPath
    (const cChar* chars, int length=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual const cChar* GetPath(int &length) const 
    {
        const cChar* chars = 0;
        length = 0;
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 5/1/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetFirstEntry() 
    {
        cFileDirectoryEntryInterface* entry = 0;
        return entry;
    }
    /**
     **********************************************************************
     * Function: GetLastEntry
     *
     *   Author: $author$
     *     Date: 5/1/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetLastEntry() 
    {
        cFileDirectoryEntryInterface* entry = 0;
        return entry;
    }

    /**
     **********************************************************************
     * Function: SetEntry
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* SetEntry
    (cFileDirectoryEntryInterface* entry) 
    {
        return entry = 0;
    }
    /**
     **********************************************************************
     * Function: GetEntry
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetEntry() const 
    {
        cFileDirectoryEntryInterface* entry = 0;
        return entry;
    }
};

#endif /* _CFILEDIRECTORYINTERFACE_HXX */
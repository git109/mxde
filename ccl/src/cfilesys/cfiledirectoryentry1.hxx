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

#include "cfiledirectoryentrycontext.hxx"
#include "cfiledirectoryinterface.hxx"
#include "cfiledirectoryentryinterface.hxx"
#include "cfiletimeset.hxx"
#include "cfilesize.hxx"
#include "cfilecompare.hxx"
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
  public cHandleT
  <DIRENTRY, (int)INVALID_DIRENTRY_VALUE, 
   cFileDirectoryEntryCompare>
{
public:
    typedef cHandleT
    <DIRENTRY, (int)INVALID_DIRENTRY_VALUE, 
     cFileDirectoryEntryCompare> cIs;

    cFileDirectoryInterface &m_directory;

    bool m_is_expanded;
    int m_type;
    cCCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cFileDirectoryEntry
     *
     *      Author: $author$
     *        Date: 5/4/2005
     **********************************************************************
     */
    cFileDirectoryEntry
    (cFileDirectoryInterface &directory,
     int type=e_TYPE_NONE, const cChar* name=0, int length=-1,
     tHandle handle=INVALID_DIRENTRY_VALUE) 
    : m_directory(directory),
      m_type(type),
      m_is_expanded(false)
    {
        eError error;

        if (name)
        if (0 > (length = m_name.Write(name, length)))
            throw(error = -length);

        if (INVALID_DIRENTRY_VALUE != handle)
        if ((error = Attach(handle)))
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

        if (INVALID_DIRENTRY_VALUE != m_handle)
        if ((error = Detach()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual eError Attach(tHandle handle)
    {
        eError error;

        if ((error = FoundEntry(handle)))
            return error;

        m_handle=handle;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: FoundEntry
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual eError FoundEntry(tHandle handle) 
    {
        eError error = e_ERROR_NONE;
        int length;

#if defined(WIN32)
/*
 * Windows
 */
        length = m_name.Copyc(handle->m_ff.cFileName);

        if (handle->m_ff.dwFileAttributes 
            & FILE_ATTRIBUTE_DIRECTORY)
            m_type = e_TYPE_DIRECTORY;
        else m_type = e_TYPE_FILE;

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
        eError error;

        if (INVALID_DIRENTRY_VALUE == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (!(error = m_handle->GetNextEntry()))
            error = FoundEntry(m_handle);

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
     * Function: GetDirectory
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual cFileDirectoryInterface& GetDirectory() 
    {
        return m_directory;
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
    (cFileDirectoryInterface &directory,
     int type=e_TYPE_NONE, const cChar* name=0, int length=-1,
     tHandle handle=INVALID_DIRENTRY_VALUE) 
    : cIs(directory, type, name, length, handle)
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
    (cFileDirectoryInterface &directory,
     int type=e_TYPE_NONE, const cChar* name=0, int length=-1,
     tHandle handle=INVALID_DIRENTRY_VALUE) 
    {
        cDynamicFileDirectoryEntry *instance = 0;

        instance = new cDynamicFileDirectoryEntry
        (directory, type, name, length, handle);
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
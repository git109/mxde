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
 *   File: cfiledirectory.hxx
 *
 * Author: $author$
 *   Date: 5/1/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDIRECTORY_HXX
#define _CFILEDIRECTORY_HXX

#include "cfiledirectoryentrycontext.hxx"
#include "cfiledirectoryentry.hxx"
#include "cfiledirectoryinterface.hxx"
#include "chandlet.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cFileDirectory
 *
 * Author: $author$
 *   Date: 5/1/2005
 **********************************************************************
 */
class cFileDirectory
: virtual public cFileDirectoryImplement,
  public cOpenedHandleT
  <DIRECTORY, (int)INVALID_DIRECTORY_VALUE, 
   cFileDirectoryEntryCompare>
{
public:
    typedef cOpenedHandleT
    <DIRECTORY, (int)INVALID_DIRECTORY_VALUE, 
     cFileDirectoryEntryCompare> cIs;

    cFileDirectoryEntryContext m_context;

#if defined(WIN32)
/*
 * Windows
 */
    cCharBuffer m_pattern_buffer;
    const char *m_pattern;
    char m_wildcard[3];
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

    cFileDirectoryEntryInterface* m_super_entry;

    int m_path_length;
    const cChar *m_path_chars;
    cCCharBuffer m_path;

    const char *m_path_toc_chars;
    cCCharToCharBuffer m_path_toc;

    cFileDirectoryEntry m_entry;

    /**
     **********************************************************************
     * Constructor: cFileDirectory
     *
     *      Author: $author$
     *        Date: 5/1/2005
     **********************************************************************
     */
    cFileDirectory
    (DIRECTORY handle=INVALID_DIRECTORY_VALUE,
     bool opened=false,
     cFileDirectoryEntryInterface* entry=0) 
    : cIs(handle, opened),
      m_super_entry(entry),
      m_context(handle),
      m_path_length(0),
      m_path_chars(0),
      m_path_toc_chars(0),
      m_entry(*this)
    {
#if defined(WIN32)
        m_wildcard[0] = DIRECTORY_SEPARATOR_CHAR;
        m_wildcard[1] = DIRECTORY_WILDCARD_CHAR;
        m_wildcard[2] = 0;
#endif /* defined(WIN32) */
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileDirectory
     *
     *      Author: $author$
     *        Date: 5/1/2005
     **********************************************************************
     */
    virtual ~cFileDirectory()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: OpenPath
     *
     *   Author: $author$
     *     Date: 5/3/2005
     **********************************************************************
     */
    virtual eError OpenPath
    (const cChar* chars, int length=-1) 
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (0 > (count = SetPath(chars, length)))
            return error = -length;

        error = Open();
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
        eError error = e_ERROR_FAILED;
        int count;

#if defined(WIN32)
/*
 * Windows
 */
        DIRECTORY handle;

		if (INVALID_DIRECTORY_VALUE == 
            (handle = FindFirstFile
            (m_path_toc_chars, &m_context.m_ff)))
            return error;

        if ((error = Opened(m_path_chars, m_path_length)))
            return error;

        FindClose(handle);

        if (0 > (count = m_pattern_buffer.CopyL
            (m_path_toc_chars, m_wildcard, 0)))
            return error;

        if (!(m_pattern = m_pattern_buffer.GetBuffer(count)))
            return error;

		if (INVALID_DIRECTORY_VALUE == 
            (m_handle = FindFirstFile(m_pattern, &m_context.m_ff)))
            return error;

        m_context.Attach(m_handle);
        m_opened = true;
        error = e_ERROR_NONE;
#endif /* defined(WIN32) */

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 5/3/2005
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_ATTACHED;

        if (INVALID_DIRECTORY_VALUE != m_handle)
        {
            if ((FindClose(m_handle)))
                error = e_ERROR_NONE;
            else error = e_ERROR_FAILED;

            m_handle = INVALID_DIRECTORY_VALUE;
            m_opened = false;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: Opened
     *
     *   Author: $author$
     *     Date: 5/19/2005
     **********************************************************************
     */
    virtual eError Opened
    (const cChar* chars, int length=-1) 
    {
        eError error = e_ERROR_NONE;
        cFileTimeInterface *file_time;

#if defined(WIN32)
/* Windows
 */
        if (!(file_time = AddFileTime
            (m_context.m_ff.ftLastWriteTime, 
             cFileTimeInterface::e_TYPE_MODIFIED)))
            error = e_ERROR_FAILED;

        else if (!(file_time = AddFileTime
                (m_context.m_ff.ftCreationTime, 
                 cFileTimeInterface::e_TYPE_CREATED)))
                error = e_ERROR_FAILED;

        else if (!(file_time = AddFileTime
                (m_context.m_ff.ftLastAccessTime, 
                 cFileTimeInterface::e_TYPE_ACCESSED)))
                error = e_ERROR_FAILED;
#else /* defined(WIN32) */
/* Unix
 */
        int err;

        if ((err = stat(path, &m_context.m_st)))
            error = e_ERROR_FAILED;
#endif /* defined(WIN32) */

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
        eError error = e_ERROR_FAILED;
        int count;

        if (0 > (count = m_path.Copy(chars, length)))
            return -error;

        if (!(m_path_chars = m_path.GetBuffer(m_path_length)))
            return -error;

        if (0 > (count = m_path_toc.CopyCChar(chars, length)))
            return -error;

        if (!(m_path_toc_chars = m_path_toc.GetBuffer(count)))
            return -error;

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
        length = m_path_length;
        return m_path_chars;
    }

    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 5/3/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetFirstEntry() 
    {
        cFileDirectoryEntryInterface* entry = 0;
        eError error;

#if defined(WIN32)
/*
 * Windows
 */
        if (!(error = m_entry.Attach(&m_context)))
            entry = &m_entry;

#endif /* defined(WIN32) */

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
        return m_super_entry = entry;
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
        return m_super_entry;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicFileDirectory
 *
 * Author: $author$
 *   Date: 6/9/2005
 **********************************************************************
 */
class cDynamicFileDirectory
: public cFileDirectory
{
public:
    typedef cFileDirectory cIs;

    /**
     **********************************************************************
     * Constructor: cDynamicFileDirectory
     *
     *      Author: $author$
     *        Date: 6/9/2005
     **********************************************************************
     */
    cDynamicFileDirectory
    (DIRECTORY handle=INVALID_DIRECTORY_VALUE,
     bool opened=false,
     cFileDirectoryEntryInterface* entry=0) 
    : cIs(handle, opened, entry)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDynamicFileDirectory
     *
     *      Author: $author$
     *        Date: 6/9/2005
     **********************************************************************
     */
    cDynamicFileDirectory
    (cFileDirectoryEntryInterface* entry) 
    : cIs(INVALID_DIRECTORY_VALUE, false, entry)
    {
    }
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    static cDynamicFileDirectory* CreateInstance
    (DIRECTORY handle=INVALID_DIRECTORY_VALUE,
     bool opened=false,
     cFileDirectoryEntryInterface* entry=0) 
    {
        cDynamicFileDirectory* instance=0;

        instance = new cDynamicFileDirectory
        (handle, opened, entry);
        return instance;
    }
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    static cDynamicFileDirectory* CreateInstance
    (cFileDirectoryEntryInterface* entry) 
    {
        cDynamicFileDirectory* instance=0;

        instance = new cDynamicFileDirectory
        (INVALID_DIRECTORY_VALUE, false, entry);
        return instance;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 6/9/2005
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NONE;

        delete this;
        return error;
    }
};

#endif /* _CFILEDIRECTORY_HXX */
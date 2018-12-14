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

#include "cfiledirectoryentry.hxx"
#include "cfiledirectoryinterface.hxx"
#include "ccchartocharbuffer.hxx"
#include "cccharbuffer.hxx"

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
  public cFileDirectoryEntry
{
public:
    typedef cFileDirectoryEntry cIs;

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
    (cFileDirectoryInterface *directory=0,
     const cChar* name=0, int length=-1, 
     const cFileTimeSetInterface *times=0,
     tHandle handle=INVALID_DIRECTORY_VALUE, bool opened=false) 
    : cIs(directory, e_TYPE_DIRECTORY, name, length, times, handle, opened),
      m_path_length(0),
      m_path_chars(0),
      m_path_toc_chars(0),
      m_entry(this)
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
     * Function: OpenPathc
     *
     *   Author: $author$
     *     Date: 8/4/2005
     **********************************************************************
     */
    virtual eError OpenPathc
    (const char* chars, int length=-1) 
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (0 > (count = SetPathc(chars, length)))
            return error = -length;

        error = Open();
        return error;
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
             (m_path_toc_chars, &m_ff)))
            return error;

        if ((error = GetEntryAttributes(handle, m_ff)))
            return error;

        FindClose(handle);

        if (0 > (count = m_pattern_buffer.CopyL
            (m_path_toc_chars, m_wildcard, 0)))
            return error;

        if (!(m_pattern = m_pattern_buffer.GetBuffer(count)))
            return error;

		if (INVALID_DIRECTORY_VALUE == 
            (handle = FindFirstFile
             (m_pattern, &m_ff)))
            return error;

        error = Attach(handle, true);
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
     * Function: SetPathc
     *
     *   Author: $author$
     *     Date: 8/4/2005
     **********************************************************************
     */
    virtual int SetPathc
    (const char* chars, int length=-1) 
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (0 > (count = m_path.Copyc(chars, length)))
            return -error;

        if (!(m_path_chars = m_path.GetBuffer(m_path_length)))
            return -error;

        if (0 > (count = m_path_toc.Copy(chars, length)))
            return -error;

        if (!(m_path_toc_chars = m_path_toc.GetBuffer(count)))
            return -error;

        return count;
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

#if defined(WIN32)
/*
 * Windows
 */
        eError error;

        if (!(error = m_entry.GetEntryAttributes(m_handle, m_ff)))
        if (!(error = m_entry.Attach(m_handle)))
            entry = &m_entry;

#endif /* defined(WIN32) */

        return entry;
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
    (cFileDirectoryInterface *directory=0,
     const cChar* name=0, int length=-1,
     const cFileTimeSetInterface *times=0,
     tHandle handle=INVALID_DIRECTORY_VALUE, bool opened=false) 
    : cIs(directory, name, length, times, handle, opened)
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
    (cFileDirectoryInterface *directory=0,
     const cChar* name=0, int length=-1,
     cFileTimeSetInterface *times=0,
     tHandle handle=INVALID_DIRECTORY_VALUE, bool opened=false) 
    {
        cDynamicFileDirectory* instance=0;

        instance = new cDynamicFileDirectory
        (directory, name, length, times, handle, opened);
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
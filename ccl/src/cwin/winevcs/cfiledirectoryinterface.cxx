/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cfiledirectoryinterface.cxx
 *
 * Author: $author$
 *   Date: 6/8/2007
 *
 *    $Id$
 **********************************************************************
 */
#include "cfiledirectoryinterface.hxx"

#include "evx/os/cevfiledirectory.hpp"
#include "evx/os/cevfiledirectoryentry.hpp"

/**
 **********************************************************************
 *  Class: cEvFileDirectoryEntry
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
class cEvFileDirectoryEntry
: virtual public cFileDirectoryEntryImplement,
  virtual public cFileSystemEntryImplement,
  virtual public cInstanceImplement
{
public:
    typedef cFileDirectoryEntryImplement cImplements;
    typedef cEvFileDirectoryEntry cDerives;

    cFileDirectoryInterface& m_directory;
    EvFileDirectoryEntry*& m_ev_file_directory_entry;

    /**
     **********************************************************************
     * Constructor: cEvFileDirectoryEntry
     *
     *      Author: $author$
     *        Date: 6/8/2007
     **********************************************************************
     */
    cEvFileDirectoryEntry
    (cFileDirectoryInterface& directory,
     EvFileDirectoryEntry*& ev_file_directory_entry) 
    : m_directory(directory),
      m_ev_file_directory_entry(ev_file_directory_entry)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cEvFileDirectoryEntry
     *
     *      Author: $author$
     *        Date: 6/8/2007
     **********************************************************************
     */
    virtual ~cEvFileDirectoryEntry()
    {
    }

    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual int GetType
    (eError &error) const 
    {
        int type = e_TYPE_NONE;
        int evtype;

        if (m_ev_file_directory_entry)
        switch((evtype = m_ev_file_directory_entry->GetType()))
        {
        case EvFileDirectoryEntry::EV_TYPE_FILE:
            type = e_TYPE_FILE;
            break;

        case EvFileDirectoryEntry::EV_TYPE_DIRECTORY:
            type = e_TYPE_DIRECTORY;
            break;
        }
        return type;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual const TCHAR* GetName
    (int &length) const 
    {
        const TCHAR* name = 0;
        LONG evlength;

        if (m_ev_file_directory_entry)
        if ((name = m_ev_file_directory_entry->GetName(evlength)))
            length = evlength;
        return name;
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteInstance
    (cInstanceInterface& instance) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};


/**
 **********************************************************************
 *  Class: cEvFileDirectory
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
class cEvFileDirectory
: virtual public cFileDirectoryImplement,
  virtual public cInstanceImplement
{
public:
    typedef cFileDirectoryImplement cImplements;
    typedef cEvFileDirectory cDerives;

    EvFileDirectoryEntry* m_ev_file_directory_entry;
    cEvFileDirectoryEntry m_file_directory_entry;

    CEvFileDirectory m_ev_file_directory;

    /**
     **********************************************************************
     * Constructor: cEvFileDirectory
     *
     *      Author: $author$
     *        Date: 6/8/2007
     **********************************************************************
     */
    cEvFileDirectory() 
    : m_ev_file_directory_entry(0),
      m_file_directory_entry
      (*this, m_ev_file_directory_entry)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cEvFileDirectory
     *
     *      Author: $author$
     *        Date: 6/8/2007
     **********************************************************************
     */
    virtual ~cEvFileDirectory()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual eError Open
    (const TCHAR* chars,
     int length=-1) 
    {
        eError error = e_ERROR_FAILED;
        EvError everror;

        if (!(everror = m_ev_file_directory.OpenPath(chars, length)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual eError Close() const 
    {
        eError error = e_ERROR_FAILED;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetFirstEntry
    (eError &error) 
    {
        cFileDirectoryEntryInterface* instance = 0;
        EvError everror;

        if ((m_ev_file_directory_entry = m_ev_file_directory.
            GetFirstEntry(everror)))
            instance = &m_file_directory_entry;
        return instance;
    }
    /**
     **********************************************************************
     * Function: GetNextEntry
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetNextEntry
    (cFileDirectoryEntryInterface& entry,
     eError &error)  
    {
        cFileDirectoryEntryInterface* instance = 0;
        EvError everror;

        if (m_ev_file_directory_entry)
        if (!(everror = m_ev_file_directory_entry->GetNextEntry()))
            instance = &m_file_directory_entry;
        return instance;
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteInstance
    (cInstanceInterface& instance) 
    {
        eError error = e_ERROR_NONE;
        delete this;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cFileDirectoryInterface
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cFileDirectoryInterface::NewInstance
 *
 *   Author: $author$
 *     Date: 6/8/2007
 **********************************************************************
 */
cFileDirectoryInterface* 
cFileDirectoryInterface::NewInstance(eError &error) 
{
    cFileDirectoryInterface* instance = new cEvFileDirectory();
    return instance;
}

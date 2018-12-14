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
 *   File: cfilesystementryinterface.cxx
 *
 * Author: $author$
 *   Date: 6/7/2007
 *
 *    $Id$
 **********************************************************************
 */

#include "cfilesystementryinterface.hxx"

#include "evx/os/cevfilepath.hpp"

/**
 **********************************************************************
 *  Class: cEvFileSystemEntry
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
class cEvFileSystemEntry
: virtual public cInstanceImplement,
  virtual public cFileSystemEntryImplement
{
public:
    typedef cFileSystemEntryImplement cImplements;
    typedef cEvFileSystemEntry cDerives;

    mutable CEvFilePath m_file_path;

    /**
     **********************************************************************
     * Constructor: cEvFileSystemEntry
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    cEvFileSystemEntry() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cEvFileSystemEntry
     *
     *      Author: $author$
     *        Date: 6/7/2007
     **********************************************************************
     */
    virtual ~cEvFileSystemEntry()
    {
    }
    /**
     **********************************************************************
     * Function: Exists
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual int Exists
    (const TCHAR* chars, int length=-1) const
    {
        int type = m_file_path.Exists(chars, length);
        return type;
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
 *  Class: cFileSystemEntryInterface
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cFileSystemEntryInterface::NewInstance
 *
 *   Author: $author$
 *     Date: 6/7/2007
 **********************************************************************
 */
cFileSystemEntryInterface* 
cFileSystemEntryInterface::NewInstance(eError& error) 
{
    cFileSystemEntryInterface* instance = 0;
    instance = new cEvFileSystemEntry();
    return instance;
}

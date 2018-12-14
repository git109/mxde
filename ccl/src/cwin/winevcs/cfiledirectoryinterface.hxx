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
 *   File: cfiledirectoryinterface.hxx
 *
 * Author: $author$
 *   Date: 6/8/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEDIRECTORYINTERFACE_HXX
#define _CFILEDIRECTORYINTERFACE_HXX

#include "cfiledirectoryentryinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileDirectoryInterface
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileDirectoryInterface
: virtual public cInstanceInterface
{
public:
    typedef cInstanceInterface cImplements;
    typedef cFileDirectoryInterface cDerives;

    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    static cFileDirectoryInterface* NewInstance
    (eError &error);

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
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual eError Close() const = 0;

    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterface* GetFirstEntry
    (eError &error) = 0;
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
     eError &error) = 0;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryImplement
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
class cFileDirectoryImplement
: virtual public cFileDirectoryInterface
{
public:
    typedef cFileDirectoryInterface cImplements;
    typedef cFileDirectoryImplement cDerives;
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
        return instance;
    }
};

#endif /* _CFILEDIRECTORYINTERFACE_HXX */

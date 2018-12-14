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
 *   File: cfiledirectoryentryinterface.hxx
 *
 * Author: $author$
 *   Date: 6/8/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEDIRECTORYENTRYINTERFACE_HXX
#define _CFILEDIRECTORYENTRYINTERFACE_HXX

#include "cfilesystementryinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterface
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileDirectoryEntryInterface
: virtual public cFileSystemEntryInterface
{
public:
    typedef cFileSystemEntryInterface cImplements;
    typedef cFileDirectoryEntryInterface cDerives;

    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual int GetType
    (eError &error) const = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 6/8/2007
     **********************************************************************
     */
    virtual const TCHAR* GetName
    (int &length) const = 0;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryImplement
 *
 * Author: $author$
 *   Date: 6/8/2007
 **********************************************************************
 */
class cFileDirectoryEntryImplement
: virtual public cFileDirectoryEntryInterface
{
public:
    typedef cFileDirectoryEntryInterface cImplements;
    typedef cFileDirectoryEntryImplement cDerives;
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
        return name;
    }
};

#endif /* _CFILEDIRECTORYENTRYINTERFACE_HXX */

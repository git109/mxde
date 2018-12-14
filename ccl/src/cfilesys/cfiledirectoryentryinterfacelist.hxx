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
 *   File: cfiledirectoryentryinterfacelist.hxx
 *
 * Author: $author$
 *   Date: 6/22/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDIRECTORYENTRYINTERFACELIST_HXX
#define _CFILEDIRECTORYENTRYINTERFACELIST_HXX

#include "cfiledirectoryentryinterface.hxx"
#include "clistt.hxx"

class cFileDirectoryEntryInterfaceItem;

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterfaceItemFactoryInterface
 *
 * Author: $author$
 *   Date: 6/23/2005
 **********************************************************************
 */
class cFileDirectoryEntryInterfaceItemFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 6/23/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterfaceItem* CreateInstance
    (cFileDirectoryEntryInterface& entry) = 0;
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 6/23/2005
     **********************************************************************
     */
    virtual eError FreeInstance
    (cFileDirectoryEntryInterfaceItem* item) = 0;
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterfaceList
 *
 * Author: $author$
 *   Date: 6/22/2005
 **********************************************************************
 */
class cFileDirectoryEntryInterfaceList
: public cDynamicListT
  <cFileDirectoryEntryInterfaceItem, cFileDirectoryEntryInterfaceList>
{
public:
    typedef cDynamicListT
    <cFileDirectoryEntryInterfaceItem, cFileDirectoryEntryInterfaceList> cIs;

    typedef bool (*fFilter)(int unequal);

    /**
     **********************************************************************
     * Function: FilterByTimeNewer
     *
     *   Author: $author$
     *     Date: 6/26/2005
     **********************************************************************
     */
    static bool FilterByTimeNewer(int unequal)
    {
        return (unequal <= 0);
    }
    /**
     **********************************************************************
     * Function: FilterByTimeOlder
     *
     *   Author: $author$
     *     Date: 6/26/2005
     **********************************************************************
     */
    static bool FilterByTimeOlder(int unequal)
    {
        return (unequal >= 0);
    }

    /**
     **********************************************************************
     * Function: AddCompared
     *
     *   Author: $author$
     *     Date: 6/23/2005
     **********************************************************************
     */
    int AddCompared
    (cFileDirectoryEntryInterfaceItemFactoryInterface &factory,
     cFileDirectoryEntryInterfaceList& to,
     cFileDirectoryEntryInterfaceList& from,
     fFilter filter_by_time);

    /**
     **********************************************************************
     * Function: AddAll
     *
     *   Author: $author$
     *     Date: 6/25/2005
     **********************************************************************
     */
    int AddAll
    (cFileDirectoryEntryInterfaceItemFactoryInterface &factory,
     cFileDirectoryEntryInterfaceList& to,
     cFileDirectoryEntryInterfaceList& from);

    /**
     **********************************************************************
     * Function: FindFirstItemByName
     *
     *   Author: $author$
     *     Date: 6/24/2005
     **********************************************************************
     */
    cFileDirectoryEntryInterfaceItem* FindFirstItemByName
    (const cChar *name, int namelen);
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterfaceItem
 *
 * Author: $author$
 *   Date: 6/22/2005
 **********************************************************************
 */
class cFileDirectoryEntryInterfaceItem
: public cDynamicListItemT<cFileDirectoryEntryInterfaceItem>
{
public:
    typedef cDynamicListItemT<cFileDirectoryEntryInterfaceItem> cIs;

    cFileDirectoryEntryInterface &m_entry;
    cFileDirectoryEntryInterfaceList m_list;

    /**
     **********************************************************************
     * Constructor: cFileDirectoryEntryInterfaceItem
     *
     *      Author: $author$
     *        Date: 6/22/2005
     **********************************************************************
     */
    cFileDirectoryEntryInterfaceItem
    (cFileDirectoryEntryInterface &entry)
    : m_entry(entry)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileDirectoryEntryInterfaceItem
     *
     *      Author: $author$
     *        Date: 6/22/2005
     **********************************************************************
     */
    virtual ~cFileDirectoryEntryInterfaceItem()
    {
        eError error;

        if ((error = m_list.Clear()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: GetEntry
     *
     *   Author: $author$
     *     Date: 6/24/2005
     **********************************************************************
     */
    cFileDirectoryEntryInterface& GetEntry() 
    {
        return m_entry;
    }
    /**
     **********************************************************************
     * Function: GetList
     *
     *   Author: $author$
     *     Date: 6/25/2005
     **********************************************************************
     */
    cFileDirectoryEntryInterfaceList& GetList() 
    {
        return m_list;
    }
};

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterfaceItemFactory
 *
 * Author: $author$
 *   Date: 6/23/2005
 **********************************************************************
 */
class cFileDirectoryEntryInterfaceItemFactory
: virtual public cFileDirectoryEntryInterfaceItemFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 6/23/2005
     **********************************************************************
     */
    virtual cFileDirectoryEntryInterfaceItem* CreateInstance
    (cFileDirectoryEntryInterface& entry) 
    {
        cFileDirectoryEntryInterfaceItem* item;

        item = new cFileDirectoryEntryInterfaceItem(entry);
        return item;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 6/23/2005
     **********************************************************************
     */
    virtual eError FreeInstance
    (cFileDirectoryEntryInterfaceItem* item) 
    {
        eError error = e_ERROR_NONE;

        delete item;
        return error;
    }
};

#endif /* ndef _CFILEDIRECTORYENTRYINTERFACELIST_HXX */


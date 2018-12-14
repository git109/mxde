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
 *   File: cfiledirectoryentryinterfacelist.cxx
 *
 * Author: $author$
 *   Date: 6/23/2005
 *
 *    $Id$
 **********************************************************************
 */
#include "cfiledirectoryentryinterfacelist.hxx"
#include "ccchartocharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryInterfaceList
 *
 * Author: $author$
 *   Date: 6/23/2005
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cFileDirectoryEntryInterfaceList::AddCompared
 *
 *   Author: $author$
 *     Date: 6/23/2005
 **********************************************************************
 */
int cFileDirectoryEntryInterfaceList::AddCompared
(cFileDirectoryEntryInterfaceItemFactoryInterface &factory,
 cFileDirectoryEntryInterfaceList& to,
 cFileDirectoryEntryInterfaceList& from,
 fFilter filter_by_time) 
{
    int count = 0;
    int types = cFileTimeInterface::e_TYPE_MODIFIED;
    cFileDirectoryEntryInterfaceItem *item;
    const cChar *name;
    int namelen;

    for (item=from.GetFirst(); item; item=item->GetNext())
    {
        cFileDirectoryEntryInterfaceList &list = item->GetList();
        cFileDirectoryEntryInterface &entry = item->GetEntry();
        int entry_type = entry.GetEntryType();
        cFileDirectoryEntryInterfaceItem *item2 = item;
        cFileDirectoryEntryInterfaceItem *item1;

        if (entry.GetIsCircular())
            continue;

        if (!(name = entry.GetEntryName(namelen)))
            continue;

        if (0 >= namelen)
            continue;

        cCCharToCharBuffer buffer(name);
        const char *cname = buffer.GetBuffer();

        if ((item1 = FindFirstItemByName(name, namelen)))
        {
            cFileDirectoryEntryInterface &entry1 = item1->GetEntry();
            int entry_type1 = entry1.GetEntryType();

            if (entry_type == entry_type1)
            if (!entry.GetIsDirectory())
            {
                cFileCompareInterface &compare = entry.GetFileCompare();
                cFileTimeSetInterface &times = entry1.GetFileTimeSet();
                int unequal = compare.CompareByFileTime(times, types);

                if (filter_by_time(unequal))
                    item2 = 0;
            }
        }

        if (item2)
        {
            cFileDirectoryEntryInterface &entry2 = item2->GetEntry();
            cFileDirectoryEntryInterfaceItem *newitem;

            if ((newitem = factory.CreateInstance(entry2)))
            {
                cFileDirectoryEntryInterfaceList &newlist = newitem->GetList();

                cCCharToCharBuffer buffer(name);
                const char *cname = buffer.GetBuffer();

                if (entry2.GetIsDirectory())
                if (item1)
                {
                    cFileDirectoryEntryInterfaceList &list1 = item1->GetList();
                    int newcount = list1.AddCompared
                        (factory, newlist, list, filter_by_time);

                    if (0 >= (newcount))
                    {
                        factory.FreeInstance(newitem);
                        newitem = 0;
                    }
                }
                else list.AddAll(factory, newlist, list);

                if (newitem)
                {
                    to.Add(newitem);
                    count++;
                }
            }
        }
    }
    return count;
}

/**
 **********************************************************************
 * Function: cFileDirectoryEntryInterfaceList::AddAll
 *
 *   Author: $author$
 *     Date: 6/25/2005
 **********************************************************************
 */
int cFileDirectoryEntryInterfaceList::AddAll
(cFileDirectoryEntryInterfaceItemFactoryInterface &factory,
 cFileDirectoryEntryInterfaceList& to,
 cFileDirectoryEntryInterfaceList& from) 
{
    int count = 0;
    cFileDirectoryEntryInterfaceItem *item;

    for (item=from.GetFirst(); item; item=item->GetNext())
    {
        cFileDirectoryEntryInterfaceList &list = item->GetList();
        cFileDirectoryEntryInterface &entry = item->GetEntry();
        cFileDirectoryEntryInterfaceItem *newitem;

        if (entry.GetIsCircular())
            continue;

        if ((newitem = factory.CreateInstance(entry)))
        {
            cFileDirectoryEntryInterfaceList &newlist = newitem->GetList();

            if (entry.GetIsDirectory())
                AddAll(factory, newlist, list);

            to.Add(newitem);
            count++;
        }
    }
    return count;
}

/**
 **********************************************************************
 * Function: cFileDirectoryEntryInterfaceList::FindFirstItemByName
 *
 *   Author: $author$
 *     Date: 6/24/2005
 **********************************************************************
 */
cFileDirectoryEntryInterfaceItem* 
cFileDirectoryEntryInterfaceList::FindFirstItemByName
(const cChar *name, int namelen) 
{
    cFileDirectoryEntryInterfaceItem* item = 0;
    const cChar *name2;
    int namelen2;

    for (item=GetFirst(); item; item=item->GetNext())
    {
        cFileDirectoryEntryInterface &entry = item->GetEntry();

        if ((name2 = entry.GetEntryName(namelen2)))
        if (namelen == namelen2)
        if (0 == cChar::CompareN(name, name2, namelen2))
            break;
    }
    return item;
}

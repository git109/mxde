/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: clist.hxx
 *
 * Author: $author$
 *   Date: 2/24/2009
 **********************************************************************
 */
#if !defined(_CLIST_HXX) || defined(CLIST_MEMBERS_ONLY)
#if !defined(_CLIST_HXX) && !defined(CLIST_MEMBERS_ONLY)
#define _CLIST_HXX
#endif /* !defined(_CLIST_HXX) && !defined(CLIST_MEMBERS_ONLY) */

#if !defined(CLIST_MEMBERS_ONLY)
#include "clistitem.hxx"
#include "cbase.hxx"

class cList;

#undef CDB_CLASS
#define CDB_CLASS "cListT"
/**
 **********************************************************************
 *  Class: cListT
 *
 * Author: $author$
 *   Date: 2/24/2009
 **********************************************************************
 */
template
<class TDerives=cList,
 class TItem=cListItem,
 class TBase=cBase,
 class TExtends=TBase>
 
class cListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TItem tItem;
    typedef TBase tBase;

	TItem *m_firstItem, *m_lastItem;

    /**
     **********************************************************************
     * Constructor: cListT
     *
     *      Author: $author$
     *        Date: 2/24/2009
     **********************************************************************
     */
    cListT
    (TItem* firstItem=0, TItem* lastItem=0)
    : m_firstItem(firstItem),
      m_lastItem(lastItem) 
    {
    }
#else /* !defined(CLIST_MEMBERS_ONLY) */
#endif /* !defined(CLIST_MEMBERS_ONLY) */

#if !defined(CLIST_MEMBER_FUNCS_INTERFACE)
#if !defined(CLIST_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: AddItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* AddItem
    (TItem& item) 
    {
        TItem* memberItem = &item;
		item.m_nextItem = 0;

		if ((item.m_prevItem = m_lastItem))
			m_lastItem->m_nextItem = &item;
		else m_firstItem = &item;

		m_lastItem = &item;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: PushItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* PushItem
    (TItem& item) 
    {
        TItem* memberItem = &item;
		item.m_prevItem = 0;

		if ((item.m_nextItem = m_firstItem))
			m_firstItem->m_prevItem = &item;
		else m_lastItem = &item;

		m_firstItem = &item;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: InsertBeforeItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* InsertBeforeItem
    (TItem& otherItem,
     TItem& item) 
    {
        TItem* memberItem = &item;
        if ((item.m_prevItem = otherItem.m_prevItem))
            otherItem.m_prevItem->m_nextItem = &item;
        else m_firstItem = &item;

        item.m_nextItem = &otherItem;
        otherItem.m_prevItem = &item;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: InsertAfterItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* InsertAfterItem
    (TItem& otherItem,
     TItem& item) 
    {
        TItem* memberItem = &item;
        if ((item.m_nextItem = otherItem.m_nextItem))
            otherItem.m_nextItem->m_prevItem = &item;
        else m_lastItem = &item;

        item.m_prevItem = &otherItem;
        otherItem.m_nextItem = &item;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: DeleteItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* DeleteItem
    (TItem& item) 
    {
        TItem* memberItem = &item;
		if (item.m_nextItem)
			item.m_nextItem->m_prevItem = item.m_prevItem;
		else m_lastItem = item.m_prevItem;

		if (item.m_prevItem)
			item.m_prevItem->m_nextItem = item.m_nextItem;
		else m_firstItem = item.m_nextItem;

		item.m_nextItem = 0;
		item.m_prevItem = 0;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: PopItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* PopItem() 
    {
        TItem* item = 0;

		if ((item = m_firstItem))
		{
			TItem* nextItem;

			if ((nextItem = item->m_nextItem))
				nextItem->m_prevItem = 0;
			else m_lastItem = 0;

			m_firstItem = nextItem;
			item->m_nextItem = 0;
			item->m_prevItem = 0;
		}
        return item;
    }
    /**
     **********************************************************************
     * Function: PullItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* PullItem() 
    {
        TItem* item = 0;

		if ((item = m_lastItem))
		{
			TItem* prevItem;

			if ((prevItem = item->m_prevItem))
				prevItem->m_nextItem = 0;
			else m_firstItem = 0;

			m_lastItem = prevItem;
			item->m_nextItem = 0;
			item->m_prevItem = 0;
		}
        return item;
    }

    /**
     **********************************************************************
     * Function: AddItems
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* AddItems
    (TItem& firstItem,
     TItem& lastItem) 
    {
        TItem* memberItem = &firstItem;
		lastItem.m_nextItem = 0;

		if ((firstItem.m_prevItem = m_lastItem) != 0)
			m_lastItem->m_nextItem = &firstItem;
		else m_firstItem = &firstItem;

		m_lastItem = &lastItem;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: PushItems
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* PushItems
    (TItem& firstItem,
     TItem& lastItem) 
    {
        TItem* memberItem = &firstItem;
		firstItem.m_prevItem = 0;

		if ((lastItem.m_nextItem = m_firstItem) != 0)
			m_firstItem->m_prevItem = &lastItem;
		else m_lastItem = &lastItem;

		m_firstItem = &firstItem;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: InsertItemsBefore
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* InsertItemsBefore
    (TItem& otherItem,
     TItem& firstItem,
     TItem& lastItem) 
    {
        TItem* memberItem = &firstItem;
        if ((firstItem.m_prevItem = otherItem.m_prevItem) != 0)
            otherItem.m_prevItem->m_nextItem = &firstItem;
        else m_firstItem = &firstItem;

        lastItem.m_nextItem = &otherItem;
        otherItem.m_prevItem = &lastItem;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: InsertItemsAfter
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* InsertItemsAfter
    (TItem& otherItem,
     TItem& firstItem,
     TItem& lastItem) 
    {
        TItem* memberItem = &otherItem;
        if ((lastItem.m_nextItem = otherItem.m_nextItem) != 0)
            otherItem.m_nextItem->m_prevItem = &lastItem;
        else m_lastItem = &lastItem;

        firstItem.m_prevItem = &otherItem;
        otherItem.m_nextItem = &firstItem;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: DeleteItems
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* DeleteItems
    (TItem& firstItem,
     TItem& lastItem) 
    {
        TItem* memberItem = &firstItem;
		if (lastItem.m_nextItem)
			lastItem.m_nextItem->m_prevItem = firstItem.m_prevItem;
		else m_lastItem = firstItem.m_prevItem;

		if (firstItem.m_prevItem)
			firstItem.m_prevItem->m_nextItem = lastItem.m_nextItem;
		else m_firstItem = lastItem.m_nextItem;

		lastItem.m_nextItem = 0;
		firstItem.m_prevItem = 0;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: DeleteAllItems
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* DeleteAllItems() 
    {
        TItem* memberItem = m_firstItem;
        m_firstItem = m_lastItem = 0;
        return memberItem;
    }
    /**
     **********************************************************************
     * Function: ClearItems
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    eError ClearItems() 
    {
        eError error = e_ERROR_NONE;
        DeleteAllItems();
        return error;
    }

    /**
     **********************************************************************
     * Function: SetFirstItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* SetFirstItem
    (TItem* toItem) 
    {
        m_firstItem = toItem;
        return m_firstItem;
    }
    /**
     **********************************************************************
     * Function: GetFirstItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* GetFirstItem() const 
    {
        return m_firstItem;
    }
    /**
     **********************************************************************
     * Function: SetLastItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* SetLastItem
    (TItem* toItem) 
    {
        m_lastItem = toItem;
        return m_lastItem;
    }
    /**
     **********************************************************************
     * Function: GetLastItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TItem* GetLastItem() const 
    {
        return m_lastItem;
    }
#endif /* !defined(CLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CLIST_MEMBER_FUNCS_INTERFACE) */

#if !defined(CLIST_MEMBERS_ONLY) 
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cListExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cListT<cList,cListItem>
cListExtends;
/**
 **********************************************************************
 *  Class: cList
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cList
: public cListExtends
{
public:
    typedef cListExtends cExtends;
    typedef cList cDerives;
};

/*
 * Static
 */
class cStaticList;

#undef CDB_CLASS
#define CDB_CLASS "cStaticListT"
/**
 **********************************************************************
 *  Class: cStaticListT
 *
 * Author: $author$
 *   Date: 2/24/2009
 **********************************************************************
 */
template
<class TDerives=cStaticList,
 class TItem=cListItem,
 class TBase=cBase,
 class TExtends=TBase>
 
class cStaticListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

	static TItem *m_firstItem, *m_lastItem;

/* include cList member functions
 */
#define CLIST_MEMBERS_ONLY
#include "clist.hxx"
#undef CLIST_MEMBERS_ONLY
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cStaticListExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStaticListT<cStaticList,cListItem>
cStaticListExtends;
/**
 **********************************************************************
 *  Class: cStaticList
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cStaticList
: public cStaticListExtends
{
public:
    typedef cStaticListExtends cExtends;
    typedef cStaticList cDerives;
};

/*
 * Export
 */
class c_EXPORT_CLASS cExportList;

#undef CDB_CLASS
#define CDB_CLASS "cExportListT"
/**
 **********************************************************************
 *  Class: cExportListT
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
template
<class TDerives=cExportList,
 class TItem=cExportListItem,
 class TBase=cExportBase,
 class TExtends=TBase>

class c_EXPORT_CLASS cExportListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TItem tItem;
    typedef TBase tBase;
    
	tItem *m_firstItem, *m_lastItem;

    /**
     **********************************************************************
     *  Constructor: cExportListT
     *
     *       Author: $author$
     *         Date: 8/23/2009
     **********************************************************************
     */
    cExportListT
    (tItem* firstItem=0,
     tItem* lastItem=0)
    : m_firstItem(firstItem),
      m_lastItem(lastItem)
    {
    }
    
/* include cList member functions
 */
#define CLIST_MEMBERS_ONLY
#include "clist.hxx"
#undef CLIST_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * Static Export
 */
class c_EXPORT_CLASS cStaticExportList;

#undef CDB_CLASS
#define CDB_CLASS "cStaticExportListT"
/**
 **********************************************************************
 *  Class: cStaticExportListT
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
template
<class TDerives=cStaticExportList,
 class TItem=cExportListItem,
 class TBase=cExportBase,
 class TExtends=TBase>

class c_EXPORT_CLASS cStaticExportListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TItem tItem;
    typedef TBase tBase;
    
	static tItem *m_firstItem;
	static tItem *m_lastItem;

/* include cList member functions
 */
#define CLIST_MEMBERS_ONLY
#include "clist.hxx"
#undef CLIST_MEMBERS_ONLY
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cStaticExportListExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cStaticExportListT<>
cStaticExportListExtends;
/**
 **********************************************************************
 *  Class: cStaticExportList
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cStaticExportList
: public cStaticExportListExtends
{
public:
    typedef cStaticExportListExtends cExtends;
    typedef cStaticExportList cDerives;
};

/*
 * Instance
 */
class c_INSTANCE_CLASS cInstanceList;

#undef CDB_CLASS
#define CDB_CLASS "cInstanceListT"
/**
 **********************************************************************
 *  Class: cInstanceListT
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
template
<class TDerives=cInstanceList,
 class TItem=cInstanceListItem,
 class TBase=cInstanceBase,
 class TExtends=TBase>

class c_INSTANCE_CLASS cInstanceListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TItem tItem;
    typedef TBase tBase;
    
	tItem *m_firstItem, *m_lastItem;

    /**
     **********************************************************************
     *  Constructor: cInstanceListT
     *
     *       Author: $author$
     *         Date: 8/23/2009
     **********************************************************************
     */
    cInstanceListT
    (tItem* firstItem=0,
     tItem* lastItem=0)
    : m_firstItem(firstItem),
      m_lastItem(lastItem)
    {
    }
    
/* include cList member functions
 */
#define CLIST_MEMBERS_ONLY
#include "clist.hxx"
#undef CLIST_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: FreeAllItems
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    eError FreeAllItems() 
    {
        eError error = e_ERROR_NONE;
        TItem* firstItem;
        TItem* lastItem;

        if ((firstItem = GetFirstItem())
            && (lastItem = GetLastItem()))
            error = FreeItems(*firstItem, *lastItem);
        return error;
    }
    /**
     **********************************************************************
     * Function: FreeItems
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    eError FreeItems
    (TItem& firstItem,
     TItem& lastItem) 
    {
        eError error = e_ERROR_NONE;
        TItem* prevItem = 0;
        TItem* item;

        for (item = &lastItem; item; item = prevItem)
        {
            if (&firstItem != item)
                prevItem = item->GetPrevItem();
            else
            prevItem = 0;

            if ((error = FreeItem(*item)))
                return e_ERROR_FREE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: FreeItem
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    eError FreeItem
    (TItem& item) 
    {
        eError error = e_ERROR_NONE;
        
        DeleteItem(item);
        error = item.Free();
        return error;
    }
};
#undef CDB_CLASS

#else /* !defined(CLIST_MEMBERS_ONLY) */
#endif /* !defined(CLIST_MEMBERS_ONLY) */

#endif /* !defined(_CLIST_HXX) || defined(CLIST_MEMBERS_ONLY) */

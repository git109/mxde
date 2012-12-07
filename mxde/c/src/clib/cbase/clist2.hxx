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
#include "cerror.hxx"
#include "cbase.hxx"

class cListItem;

#undef CDB_CLASS
#define CDB_CLASS "cListItemT"
/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 2/24/2009
 **********************************************************************
 */
template
<class TDerives=cListItem,
 class TBase=cBase,
 class TExtends=TBase>
 
class cListItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    TDerives *m_prevItem, *m_nextItem;

    /**
     **********************************************************************
     * Constructor: cListItemT
     *
     *      Author: $author$
     *        Date: 2/24/2009
     **********************************************************************
     */
    cListItemT
    (TDerives *prevItem=0, TDerives *nextItem=0)
    :m_prevItem(prevItem),
     m_nextItem(nextItem) 
    {
    }
    /**
     **********************************************************************
     * Function: SetNextItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TDerives* SetNextItem
    (TDerives* toItem) 
    {
        return m_nextItem = toItem;
    }
    /**
     **********************************************************************
     * Function: GetNextItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TDerives* GetNextItem() const 
    {
        return m_nextItem;
    }
    /**
     **********************************************************************
     * Function: SetPrevItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TDerives* SetPrevItem
    (TDerives* toItem) 
    {
        return m_prevItem = toItem;
    }
    /**
     **********************************************************************
     * Function: GetPrevItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    TDerives* GetPrevItem() const 
    {
        return m_prevItem;
    }
};
#undef CDB_CLASS

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
    typedef cListT cDerives;

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

#if !defined(CLIST_MEMBERS_ONLY) 
};
#undef CDB_CLASS

class cListItem;
/**
 **********************************************************************
 * Typedef: cListItemExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cListItemT<cListItem>
cListItemExtends;
/**
 **********************************************************************
 *  Class: cListItem
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cListItem
: public cListItemExtends
{
public:
    typedef cListItemExtends cExtends;
    typedef cListItem cDerives;
};

class cList;
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

class cDynamicListItem;

#undef CDB_CLASS
#define CDB_CLASS "cDynamicListItemT"
/**
 **********************************************************************
 *  Class: cDynamicListItemT
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
template
<class TDerives=cDynamicListItem,
 class TBase=cBase,
 class TItem=cListItemT<TDerives, TBase>,
 class TExtends=TItem>
 
class cDynamicListItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    bool m_isStatic, m_isPersistant;

    /**
     **********************************************************************
     * Constructor: cDynamicListItemT
     *
     *      Author: $author$
     *        Date: 2/25/2009
     **********************************************************************
     */
    cDynamicListItemT
    (bool isStatic=false, bool isPersistant=false, 
     TDerives *previous=0, TDerives *next=0)
    : cExtends(previous, next),
      m_isStatic(isStatic),
      m_isPersistant(isPersistant) 
    {
    }

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    eError Free() 
    {
        eError error = e_ERROR_NONE;
        if (!(GetIsStatic()))
            delete this;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    bool SetIsStatic
    (bool is=true) 
    {
        bool m_isStatic = is;
        return m_isStatic;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    bool GetIsStatic() const 
    {
        return m_isStatic;
    }
    /**
     **********************************************************************
     * Function: SetIsPersistant
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    bool SetIsPersistant
    (bool is=true) 
    {
        bool m_isPersistant = is;
        return m_isPersistant;
    }
    /**
     **********************************************************************
     * Function: GetIsPersistant
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    bool GetIsPersistant() const 
    {
        return m_isPersistant;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDynamicListItemExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cDynamicListItemT<cDynamicListItem>
cDynamicListItemExtends;
/**
 **********************************************************************
 *  Class: cDynamicListItem
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cDynamicListItem
: public cDynamicListItemExtends
{
public:
    typedef cDynamicListItemExtends cExtends;
    typedef cDynamicListItem cDerives;
};

class cDynamicList;

#undef CDB_CLASS
#define CDB_CLASS "cDynamicListT"
/**
 **********************************************************************
 *  Class: cDynamicListT
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
template
<class TDerives,
 class TItem,
 class TBase=cBase,
 class TList=cListT<TDerives, TItem, TBase>,
 class TExtends=TList>
 
class cDynamicListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    bool m_isStatic;

    /**
     **********************************************************************
     * Constructor: cDynamicListT
     *
     *      Author: $author$
     *        Date: 2/25/2009
     **********************************************************************
     */
    cDynamicListT
    (bool isStatic=false,
     TItem *firstItem=0, TItem *lastItem=0)
    : cExtends(firstItem, lastItem),
      m_isStatic(isStatic) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDynamicListT
     *
     *     Author: $author$
     *       Date: 2/25/2009
     **********************************************************************
     */
    virtual ~cDynamicListT()
    {
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
        if (GetIsStatic())
            CTHIS DeleteAllItems();
        else
        FreeAllItems();
        return error;
    }
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

        if ((firstItem = CTHIS GetFirstItem())
            && (lastItem = CTHIS GetLastItem()))
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

        if (!item.GetIsPersistant())
        {
            CTHIS DeleteItem(item);

            if (!item.GetIsStatic())
                error = item.Free();
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    bool SetIsStatic
    (bool is=true) 
    {
        bool m_isStatic = is;
        return m_isStatic;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    bool GetIsStatic() const 
    {
        return m_isStatic;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDynamicListExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cDynamicListT<cDynamicList,cDynamicListItem>
cDynamicListExtends;
/**
 **********************************************************************
 *  Class: cDynamicList
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cDynamicList
: public cDynamicListExtends
{
public:
    typedef cDynamicListExtends cExtends;
    typedef cDynamicList cDerives;
};

#else /* !defined(CLIST_MEMBERS_ONLY) */
#endif /* !defined(CLIST_MEMBERS_ONLY) */

#endif /* !defined(_CLIST_HXX) || defined(CLIST_MEMBERS_ONLY) */

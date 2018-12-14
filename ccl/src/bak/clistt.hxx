/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: clistt.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CLISTT_HXX
#define _CLISTT_HXX

#include "cerror.h"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class TAs,class TIs=cBase>
class cListItemT
: public TIs
{
public:
    typedef TIs cIs;

    TAs *m_previous,*m_next;

    /**
     **********************************************************************
     * Constructor: cListItemT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cListItemT(TAs *previous=0,TAs *next=0)
    :m_previous(previous),
     m_next(next) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cListItemT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cListItemT()
    {
    }
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *GetPrevious() const
    {
        return m_previous;
    }
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *GetNext() const
    {
        return m_next;
    }
};

/**
 **********************************************************************
 *  Class: cListT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class TOf,class TAs,class TIs=cBase>
class cListT
: public TIs
{
public:
    typedef TIs cIs;

    TOf *m_first,*m_last;

    /**
     **********************************************************************
     * Constructor: cListT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cListT(TOf *first=0,TOf *last=0)
    : m_first(first),
      m_last(last) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cListT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cListT()
    {
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Clear()
    {
        m_first = m_last = 0;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Add(TOf *item)
    {
        if (item)
        {
            item->m_next=0;
            if ((item->m_previous=m_last)!=0)
                m_last->m_next=item;
            else m_first=item;
            m_last=item;
        }
    }
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Push(TOf *item)
    {
        if (item)
        {
            item->m_previous=0;
            if ((item->m_next=m_first)!=0)
                m_first->m_previous=item;
            else m_last=item;
            m_first=item;
        }
    }
    /**
     **********************************************************************
     * Function: InsertBefore
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void InsertBefore(TOf *before,TOf *item)
    {
        if ((item->m_next=before)!=0)
        {
            if ((item->m_previous=before->m_previous)!=0)
                before->m_previous->m_next=item;
            else m_first=item;
            before->m_previous=item;
        }
        else
        {
            if ((item->m_previous=m_last)!=0)
                m_last->m_next=item;
            else m_first=item;
            m_last=item;
        }
    }
    /**
     **********************************************************************
     * Function: InsertAfter
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void InsertAfter(TOf *after,TOf *item)
    {
        if ((item->m_previous=after)!=0)
        {
            if ((item->m_next=after->m_next)!=0)
                after->m_next->m_previous=item;
            else m_last=item;
            after->m_next=item;
        }
        else
        {
            if ((item->m_next=m_first)!=0)
                m_first->m_previous=item;
            else m_last=item;
            m_first=item;
        }
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Delete(TOf *item)
    {
        if (item)
        {
            if (item->m_previous)
                item->m_previous->m_next=item->m_next;
            else m_first=item->m_next;

            if (item->m_next)
                item->m_next->m_previous=item->m_previous;
            else m_last=item->m_previous;
        }
    }
    /**
     **********************************************************************
     * Function: Pull
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf* Pull()
    {
        TOf *item;

        if ((item=m_last)!=0)
        {
            if ((m_last=item->m_previous)!=0)
                m_last->m_next=0;
            else m_first=0;
            item->m_previous=0;
        }
        return item;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf* Pop()
    {
        TOf *item;

        if ((item=m_first)!=0)
        {
            if ((m_first=item->m_next)!=0)
                m_first->m_previous=0;
            else m_last=0;
            item->m_next=0;
        }
        return item;
    }
    /**
     **********************************************************************
     * Function: SetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *SetFirst(TOf *first)
    {
        return m_first=first;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *GetFirst() const
    {
        return m_first;
    }
    /**
     **********************************************************************
     * Function: SetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *SetLast(TOf *last)
    {
        return m_last=last;
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *GetLast() const
    {
        return m_last;
    }
};

/**
 **********************************************************************
 *  Class: cStaticListT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class TOf,class TAs,class TIs=cBase>
class cStaticListT
: public TIs
{
public:
    typedef TIs cIs;

    static TOf *m_first,*m_last;

    /**
     **********************************************************************
     * Destructor: ~cStaticListT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cStaticListT()
    {
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Clear()
    {
        m_first = m_last = 0;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Add(TOf *item)
    {
        if (item)
        {
            item->m_next=0;
            if ((item->m_previous=m_last)!=0)
                m_last->m_next=item;
            else m_first=item;
            m_last=item;
        }
    }
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Push(TOf *item)
    {
        if (item)
        {
            item->m_previous=0;
            if ((item->m_next=m_first)!=0)
                m_first->m_previous=item;
            else m_last=item;
            m_first=item;
        }
    }
    /**
     **********************************************************************
     * Function: InsertBefore
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void InsertBefore(TOf *before,TOf *item)
    {
        if ((item->m_next=before)!=0)
        {
            if ((item->m_previous=before->m_previous)!=0)
                before->m_previous->m_next=item;
            else m_first=item;
            before->m_previous=item;
        }
        else
        {
            if ((item->m_previous=m_last)!=0)
                m_last->m_next=item;
            else m_first=item;
            m_last=item;
        }
    }
    /**
     **********************************************************************
     * Function: InsertAfter
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void InsertAfter(TOf *after,TOf *item)
    {
        if ((item->m_previous=after)!=0)
        {
            if ((item->m_next=after->m_next)!=0)
                after->m_next->m_previous=item;
            else m_last=item;
            after->m_next=item;
        }
        else
        {
            if ((item->m_next=m_first)!=0)
                m_first->m_previous=item;
            else m_last=item;
            m_first=item;
        }
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Delete(TOf *item)
    {
        if (item)
        {
            if (item->m_previous)
                item->m_previous->m_next=item->m_next;
            else m_first=item->m_next;

            if (item->m_next)
                item->m_next->m_previous=item->m_previous;
            else m_last=item->m_previous;
        }
    }
    /**
     **********************************************************************
     * Function: Pull
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf* Pull()
    {
        TOf *item;

        if ((item=m_last)!=0)
        {
            if ((m_last=item->m_previous)!=0)
                m_last->m_next=0;
            else m_first=0;
            item->m_previous=0;
        }
        return item;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf* Pop()
    {
        TOf *item;

        if ((item=m_first)!=0)
        {
            if ((m_first=item->m_next)!=0)
                m_first->m_previous=0;
            else m_last=0;
            item->m_next=0;
        }
        return item;
    }
    /**
     **********************************************************************
     * Function: SetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *SetFirst(TOf *first)
    {
        return m_first=first;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *GetFirst() const
    {
        return m_first;
    }
    /**
     **********************************************************************
     * Function: SetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *SetLast(TOf *last)
    {
        return m_last=last;
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *GetLast() const
    {
        return m_last;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicListItemT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template <class TAs,class TIs=cBase>
class cDynamicListItemT
: public cListItemT<TAs,TIs>
{
public:
    typedef cListItemT<TAs,TIs> cListItemIs,cIs;

    bool m_is_static,m_is_persistant;

    /**
     **********************************************************************
     * Constructor: cDynamicListItemT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cDynamicListItemT
    (bool is_static=false, bool is_persistant=false, 
     TAs *previous=0, TAs *next=0)
    : cIs(previous,next),
      m_is_static(is_static),
      m_is_persistant(is_persistant)
    {
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool GetIsStatic() const
    {
        return m_is_static;
    }

    /**
     **********************************************************************
     * Function: SetIsPersistant
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool SetIsPersistant(bool is_persistant=true)
    {
        m_is_persistant=is_persistant;
        return m_is_persistant;
    }
    /**
     **********************************************************************
     * Function: GetIsPersistant
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool GetIsPersistant() const
    {
        return m_is_persistant;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicListT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template <class TOf,class TAs,class TIs=cBase>
class cDynamicListT
: public cListT<TOf,TAs,TIs>
{
public:
    typedef cListT<TOf,TAs,TIs> cListIs,cIs;

    bool m_is_static;

    /**
     **********************************************************************
     * Constructor: cDynamicListT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cDynamicListT
    (bool is_static=false,TOf *first=0,TOf *last=0)
    : cIs(first,last),
      m_is_static(is_static) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDynamicListT
     *
     *     Author: $author$
     *       Date: 7/13/2003
     **********************************************************************
     */
    virtual ~cDynamicListT()
    {
        Destruct();
    }
    /**
     **********************************************************************
     * Function: Destruct
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual void Destruct()
    {
        eError error;

        if ((error=Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Clear()
    {
        eError error;
        TOf *item,*previous;

        if (m_is_static)
            m_first = m_last = 0;

        else for (item=m_last; item; item=previous)
        {
            previous=item->m_previous;

            if (!item->m_is_persistant)
            {
                Delete(item);

                if (!item->m_is_static)
                if ((error=Free(item)))
                    return e_ERROR_FREE;
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Free(TOf *item)
    {
        delete item;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool GetIsStatic() const
    {
        return m_is_static;
    }
};

/**
 **********************************************************************
 *  Class: cStaticDynamicListT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template <class TOf,class TAs,class TIs=cBase>
class cStaticDynamicListT
: public cStaticListT<TOf,TAs,TIs>
{
public:
    typedef cStaticListT<TOf,TAs,TIs> cListIs,cIs;

    bool m_is_static;

    /**
     **********************************************************************
     * Constructor: cStaticDynamicListT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cStaticDynamicListT(bool is_static=false)
    : m_is_static(is_static)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cStaticDynamicListT
     *
     *     Author: $author$
     *       Date: 7/13/2003
     **********************************************************************
     */
    virtual ~cStaticDynamicListT()
    {
        Destruct();
    }
    /**
     **********************************************************************
     * Function: Destruct
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual void Destruct()
    {
        eError error;

        if ((error=Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Clear()
    {
        eError error;
        TOf *item,*previous;

        if (m_is_static)
            m_first = m_last = 0;

        else for (item=m_last; item; item=previous)
        {
            previous=item->m_previous;

            if (!item->m_is_static)
            {
                Delete(item);

                if ((error=Free(item)))
                    return e_ERROR_FREE;
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Free(TOf *item)
    {
        delete item;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool GetIsStatic() const
    {
        return m_is_static;
    }
};

#endif

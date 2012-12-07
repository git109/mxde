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
 *   File: clistitem.hxx
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
#if !defined(_CLISTITEM_HXX) || defined(CLISTITEM_MEMBERS_ONLY)
#if !defined(_CLISTITEM_HXX) && !defined(CLISTITEM_MEMBERS_ONLY)
#define _CLISTITEM_HXX
#endif /* !defined(_CLISTITEM_HXX) && !defined(CLISTITEM_MEMBERS_ONLY) */

#if !defined(CLISTITEM_MEMBERS_ONLY)
#include "cinstancebase.hxx"
#include "cexportbase.hxx"
#include "cbase.hxx"
#include "cerror.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class cListItem;

#undef CDB_CLASS
#define CDB_CLASS "cListItemT"
/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 8/23/2009
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
    typedef TDerives tDerives;
    typedef TBase tBase;
    
    tDerives *m_prevItem, *m_nextItem;

    /**
     **********************************************************************
     *  Constructor: cListItemT
     *
     *       Author: $author$
     *         Date: 8/23/2009
     **********************************************************************
     */
    cListItemT
    (tDerives *prevItem=0, 
     tDerives *nextItem=0)
    :m_prevItem(prevItem),
     m_nextItem(nextItem)
    {
    }
#else /* !defined(CLISTITEM_MEMBERS_ONLY) */
#endif /* !defined(CLISTITEM_MEMBERS_ONLY) */

#if !defined(CLISTITEM_MEMBER_FUNCS_INTERFACE)
#if !defined(CLISTITEM_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: SetNextItem
     *
     *   Author: $author$
     *     Date: 2/24/2009
     **********************************************************************
     */
    tDerives* SetNextItem
    (tDerives* toItem) 
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
    tDerives* GetNextItem() const 
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
    tDerives* SetPrevItem
    (tDerives* toItem) 
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
    tDerives* GetPrevItem() const 
    {
        return m_prevItem;
    }
#endif /* !defined(CLISTITEM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CLISTITEM_MEMBER_FUNCS_INTERFACE) */
    
#if !defined(CLISTITEM_MEMBERS_ONLY)
};
#undef CDB_CLASS
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

/*
 * Export
 */ 
class c_EXPORT_CLASS cExportListItem;

#undef CDB_CLASS
#define CDB_CLASS "cExportListItemT"
/**
 **********************************************************************
 *  Class: cExportListItemT
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
template
<class TDerives=cExportListItem,
 class TBase=cExportBase,
 class TExtends=TBase>

class c_EXPORT_CLASS cExportListItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives tDerives;
    typedef TBase tBase;
    
    tDerives *m_prevItem, *m_nextItem;

    /**
     **********************************************************************
     *  Constructor: cExportListItemT
     *
     *       Author: $author$
     *         Date: 8/23/2009
     **********************************************************************
     */
    cExportListItemT
    (tDerives *prevItem=0, 
     tDerives *nextItem=0)
    :m_prevItem(prevItem),
     m_nextItem(nextItem)
    {
    }
    
/* include cListItem member functions
 */
#define CLISTITEM_MEMBERS_ONLY
#include "clistitem.hxx"
#undef CLISTITEM_MEMBERS_ONLY
};
/**
 **********************************************************************
 * Typedef: cExportListItemExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cExportListItemT<>
cExportListItemExtends;
/**
 **********************************************************************
 *  Class: cExportListItem
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cExportListItem
: public cExportListItemExtends
{
public:
    typedef cExportListItemExtends cExtends;
    typedef cExportListItem cDerives;
};

/*
 * Instance
 */
class c_INSTANCE_CLASS cInstanceListItem;

#undef CDB_CLASS
#define CDB_CLASS "cInstanceListItemT"
/**
 **********************************************************************
 *  Class: cInstanceListItemT
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
template
<class TDerives=cInstanceListItem,
 class TBase=cInstanceBase,
 class TExtends=TBase>

class c_INSTANCE_CLASS cInstanceListItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives tDerives;
    typedef TBase tBase;
    
    tDerives *m_prevItem, *m_nextItem;
    bool m_isStatic;

    /**
     **********************************************************************
     *  Constructor: cInstanceListItemT
     *
     *       Author: $author$
     *         Date: 8/23/2009
     **********************************************************************
     */
    cInstanceListItemT
    (bool isStatic=false,
     tDerives *prevItem=0, 
     tDerives *nextItem=0)
    : m_prevItem(prevItem),
      m_nextItem(nextItem),
      m_isStatic(isStatic)
    {
    }
    
/* include cListItem member functions
 */
#define CLISTITEM_MEMBERS_ONLY
#include "clistitem.hxx"
#undef CLISTITEM_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    virtual eError Free() 
    {
        eError error = e_ERROR_NONE;
        if (!(GetIsStatic()))
            error = DeleteThis();
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    virtual eError DeleteThis() 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    bool SetIsStatic
    (bool isTrue=true) 
    {
        m_isStatic = isTrue;
        return m_isStatic;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    bool GetIsStatic() const 
    {
        return m_isStatic;
    }
};
/**
 **********************************************************************
 * Typedef: cInstanceListItemExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cInstanceListItemT<>
cInstanceListItemExtends;
/**
 **********************************************************************
 *  Class: cInstanceListItem
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cInstanceListItem
: public cInstanceListItemExtends
{
public:
    typedef cInstanceListItemExtends cExtends;
    typedef cInstanceListItem cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CLISTITEM_MEMBERS_ONLY) */
#endif /* !defined(CLISTITEM_MEMBERS_ONLY) */

#endif /* !defined(_CLISTITEM_HXX) || defined(CLISTITEM_MEMBERS_ONLY) */

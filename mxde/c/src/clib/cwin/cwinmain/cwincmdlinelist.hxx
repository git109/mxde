/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cwincmdlinelist.hxx
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
#if !defined(_CWINCMDLINELIST_HXX) || defined(CWINCMDLINELIST_MEMBERS_ONLY)
#if !defined(_CWINCMDLINELIST_HXX) && !defined(CWINCMDLINELIST_MEMBERS_ONLY)
#define _CWINCMDLINELIST_HXX
#endif /* !defined(_CWINCMDLINELIST_HXX) && !defined(CWINCMDLINELIST_MEMBERS_ONLY) */

#if !defined(CWINCMDLINELIST_MEMBERS_ONLY)
#include "clistitem.hxx"
#include "clist.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if !defined(CWINCMDLINEITEM_MEMBERS_ONLY)
class c_INSTANCE_CLASS cWinCmdLineItem;
/**
 **********************************************************************
 * Typedef: cWinCmdLineItemExtend
 *
 *  Author: $author$
 *    Date: 10/6/2010
 **********************************************************************
 */
typedef cListItemT<cWinCmdLineItem, cTCHARString>
cWinCmdLineItemExtend;
/**
 **********************************************************************
 *  Class: cWinCmdLineItem
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCmdLineItem
: public cWinCmdLineItemExtend
{
public:
    typedef cWinCmdLineItemExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinCmdLineItem
     *
     *       Author: $author$
     *         Date: 10/6/2010
     **********************************************************************
     */
    cWinCmdLineItem
    (const WCHAR* chars, 
     TLENGTH length=UNDEFINED_LENGTH)
    {
        eError error;
        if (chars)
        if (0 > (length = AppendWChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     *  Constructor: cWinCmdLineItem
     *
     *       Author: $author$
     *         Date: 10/6/2010
     **********************************************************************
     */
    cWinCmdLineItem
    (const CHAR* chars=0, 
     TLENGTH length=UNDEFINED_LENGTH)
    {
        eError error;
        if (chars)
        if (0 > (length = AppendCHARS(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCmdLineItem
     *
     *      Author: $author$
     *        Date: 10/6/2010
     **********************************************************************
     */
    virtual ~cWinCmdLineItem()
    {
    }
#else /* !defined(CWINCMDLINEITEM_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEITEM_MEMBERS_ONLY) */

#if !defined(CWINCMDLINEITEM_MEMBERS_ONLY)
};
#else /* !defined(CWINCMDLINEITEM_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEITEM_MEMBERS_ONLY) */

class c_INSTANCE_CLASS cWinCmdLineList;
/**
 **********************************************************************
 * Typedef: cWinCmdLineListExtend
 *
 *  Author: $author$
 *    Date: 10/6/2010
 **********************************************************************
 */
typedef cListT<cWinCmdLineList, cWinCmdLineItem>
cWinCmdLineListExtend;
/**
 **********************************************************************
 *  Class: cWinCmdLineList
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCmdLineList
: public cWinCmdLineListExtend
{
public:
    typedef cWinCmdLineListExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinCmdLineList
     *
     *       Author: $author$
     *         Date: 10/6/2010
     **********************************************************************
     */
    cWinCmdLineList()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCmdLineList
     *
     *      Author: $author$
     *        Date: 10/6/2010
     **********************************************************************
     */
    virtual ~cWinCmdLineList()
    {
        eError error;
        if ((error = ClearItems()))
            throw(error);
    }
#else /* !defined(CWINCMDLINELIST_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINELIST_MEMBERS_ONLY) */

#if !defined(CWINCMDLINELIST_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: ClearItems
     *
     *   Author: $author$
     *     Date: 10/6/2010
     **********************************************************************
     */
    eError ClearItems() 
    {
        eError error = e_ERROR_NONE;
        tItem* prevItem;
        tItem* nextItem;
        
        if ((nextItem = DeleteAllItems()))
        do
        {
            prevItem = nextItem;
            nextItem = nextItem->GetNextItem();
            delete prevItem;
        }
        while (nextItem);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCMDLINELIST_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINELIST_MEMBERS_ONLY) */

#endif /* !defined(_CWINCMDLINELIST_HXX) || defined(CWINCMDLINELIST_MEMBERS_ONLY) */

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
 *   File: cmainarglist.hxx
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
#if !defined(_CMAINARGLIST_HXX) || defined(CMAINARGLIST_MEMBERS_ONLY)
#if !defined(_CMAINARGLIST_HXX) && !defined(CMAINARGLIST_MEMBERS_ONLY)
#define _CMAINARGLIST_HXX
#endif /* !defined(_CMAINARGLIST_HXX) && !defined(CMAINARGLIST_MEMBERS_ONLY) */

#if !defined(CMAINARGLIST_MEMBERS_ONLY)
#include "cmainargitem.hxx"
#include "clist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cMainArgList;
/**
 **********************************************************************
 * Typedef: cMainArgListListExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cStaticExportListT
<cMainArgList, cMainArgItem>
cMainArgListListExtends;

#undef CDB_CLASS
#define CDB_CLASS "cMainArgListT"
/**
 **********************************************************************
 *  Class: cMainArgListT
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
template
<class TDerives=cMainArgList,
 class TListExtends=cMainArgListListExtends,
 class TMainArgItem=cMainArgItem,
 class TMainArg=cMainArg,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TExtends=TListExtends>
 
class c_INSTANCE_CLASS cMainArgListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: FindFirstArgByShortName
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* FindFirstArgByShortName
    (const tChar* chars,
     tLength length=-1) 
    {
        const TMainArg* arg = 0;
        TMainArgItem* argItem;
        int diff;

        for (argItem=CTHIS GetFirstItem(); 
             argItem; argItem=argItem->GetNextItem())
        {
            const TMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareShortName(chars, length)))
                return arg = &mainArg;
        }
        return arg;
    }
    /**
     **********************************************************************
     * Function: FindFirstArgByName
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* FindFirstArgByName
    (const tChar* chars,
     tLength length=-1) 
    {
        TMainArg* arg = 0;
        TMainArgItem *argItem;
        int diff;

        for (argItem=CTHIS GetFirstItem(); 
             argItem; argItem=argItem->GetNextItem())
        {
            TMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareName(chars, length)))
                return arg = &mainArg;
        }
        return arg;
    }

    /**
     **********************************************************************
     * Function: GetFirstArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetFirstArg
    (const TMainArgItem*& argItem) const
    {
        const TMainArg* mainArg = 0;
        if ((argItem = CTHIS GetFirstItem()))
            mainArg = &argItem->GetMainArg();
        return mainArg;
    }
    /**
     **********************************************************************
     * Function: GetLastArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetLastArg
    (const TMainArgItem*& argItem) const
    {
        const TMainArg* mainArg = 0;
        if ((argItem = CTHIS GetLastItem()))
            mainArg = &argItem->GetMainArg();
        return mainArg;
    }
    /**
     **********************************************************************
     * Function: GetNextArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetNextArg
    (const TMainArgItem*& argItem) const
    {
        const TMainArg* mainArg = 0;
        if (argItem)
        if ((argItem = argItem->GetNextItem()))
            mainArg = &argItem->GetMainArg();
        return mainArg;
    }
    /**
     **********************************************************************
     * Function: GetPrevArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetPrevArg
    (const TMainArgItem*& argItem) const
    {
        const TMainArg* mainArg = 0;
        if (argItem)
        if ((argItem = argItem->GetPrevItem()))
            mainArg = &argItem->GetMainArg();
        return mainArg;
    }
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMAINARGLIST_MEMBERS_ONLY) */
#endif /* !defined(CMAINARGLIST_MEMBERS_ONLY) */

#endif /* !defined(_CMAINARGLIST_HXX) || defined(CMAINARGLIST_MEMBERS_ONLY) */

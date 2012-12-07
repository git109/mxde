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
 *   File: cmainargitem.hxx
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
#if !defined(_CMAINARGITEM_HXX) || defined(CMAINARGITEM_MEMBERS_ONLY)
#if !defined(_CMAINARGITEM_HXX) && !defined(CMAINARGITEM_MEMBERS_ONLY)
#define _CMAINARGITEM_HXX
#endif /* !defined(_CMAINARGITEM_HXX) && !defined(CMAINARGITEM_MEMBERS_ONLY) */

#if !defined(CMAINARGITEM_MEMBERS_ONLY)
#include "clistitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cMainArg;
class c_INSTANCE_CLASS cMainArgItem;
/**
 **********************************************************************
 * Typedef: cMainArgItemItemExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cExportListItemT<cMainArgItem>
cMainArgItemItemExtends;

#undef CDB_CLASS
#define CDB_CLASS "cMainArgItemT"
/**
 **********************************************************************
 *  Class: cMainArgItemT
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
template
<class TDerives=cMainArgItem,
 class TItemExtends=cMainArgItemItemExtends,
 class TMainArg=cMainArg,
 class TExtends=TItemExtends>
 
class c_INSTANCE_CLASS cMainArgItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    TMainArg& m_mainArg;

    /**
     **********************************************************************
     * Constructor: cMainArgItemT
     *
     *      Author: $author$
     *        Date: 2/25/2009
     **********************************************************************
     */
    cMainArgItemT(TMainArg& mainArg)
    : m_mainArg(mainArg) 
    {
    }

    /**
     **********************************************************************
     * Function: GetMainArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual TMainArg& GetMainArg() const 
    {
        return m_mainArg;
    }
};
#undef CDB_CLASS

/*
 * main
 */
/**
 **********************************************************************
 * Typedef: cMainArgItemExtends
 *
 *  Author: $author$
 *    Date: 2/25/2009
 **********************************************************************
 */
typedef cMainArgItemT
<cMainArgItem, cMainArgItemItemExtends, cMainArg>
cMainArgItemExtends;
/**
 **********************************************************************
 *  Class: cMainArgItem
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cMainArgItem
: public cMainArgItemExtends
{
public:
    typedef cMainArgItemExtends cExtends;
    typedef cMainArgItem cDerives;
    /**
     **********************************************************************
     * Constructor: cMainArgItem
     *
     *      Author: $author$
     *        Date: 2/25/2009
     **********************************************************************
     */
    cMainArgItem
    (cMainArg& mainArg) 
    : cExtends(mainArg)
    {
    }
};

/*
 * tmain
 */
class c_INSTANCE_CLASS cTMainArg;
class c_INSTANCE_CLASS cTMainArgItem;
/**
 **********************************************************************
 * Typedef: cTMainArgItemItemExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cExportListItemT<cTMainArgItem>
cTMainArgItemItemExtends;
/**
 **********************************************************************
 * Typedef: cTMainArgItemExtends
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgItemT
<cTMainArgItem,cTMainArgItemItemExtends,cTMainArg>
cTMainArgItemExtends;
/**
 **********************************************************************
 *  Class: cTMainArgItem
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTMainArgItem
: public cTMainArgItemExtends
{
public:
    typedef cTMainArgItemExtends cExtends;
    typedef cTMainArgItem cDerives;
    /**
     **********************************************************************
     * Constructor: cTMainArgItem
     *
     *      Author: $author$
     *        Date: 3/5/2009
     **********************************************************************
     */
    cTMainArgItem
    (cTMainArg& mainArg) 
    : cExtends(mainArg)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMAINARGITEM_MEMBERS_ONLY) */
#endif /* !defined(CMAINARGITEM_MEMBERS_ONLY) */

#endif /* !defined(_CMAINARGITEM_HXX) || defined(CMAINARGITEM_MEMBERS_ONLY) */

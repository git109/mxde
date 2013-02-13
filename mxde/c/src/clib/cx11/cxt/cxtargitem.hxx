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
 *   File: cxtargitem.hxx
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
#if !defined(_CXTARGITEM_HXX) || defined(CXTARGITEM_MEMBERS_ONLY)
#if !defined(_CXTARGITEM_HXX) && !defined(CXTARGITEM_MEMBERS_ONLY)
#define _CXTARGITEM_HXX
#endif /* !defined(_CXTARGITEM_HXX) && !defined(CXTARGITEM_MEMBERS_ONLY) */

#if !defined(CXTARGITEM_MEMBERS_ONLY)
#include "cplatform_X11_Intrinsic.h"
#include "cxtarg.hxx"
#include "cxbase.hxx"
#include "carray.hxx"
#include "clist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Struct: sXtArg
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
struct c_INSTANCE_CLASS sXtArg
: public Arg
{
public:
    typedef Arg cExtends;
    typedef sXtArg cDerives;
    /**
     **********************************************************************
     * Constructor: sXtArg
     *
     *      Author: $author$           
     *        Date: 4/26/2010
     **********************************************************************
     */
    sXtArg
    (String p_name=0,
     XtArgVal p_value=0) 
    {
        name = p_name;
        value = p_value;
    }
};

/**
 **********************************************************************
 * Typedef: tXtArgArrayElement
 *
 *  Author: $author$           
 *    Date: 4/25/2010
 **********************************************************************
 */
typedef sXtArg
tXtArgArrayElement;

class c_INTERFACE_CLASS cXtArgArrayInterface;
/**
 **********************************************************************
 * Typedef: cXtArgArrayInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/25/2010
 **********************************************************************
 */
typedef cArrayInterfaceT
<cXtArgArrayInterface, 
 tXtArgArrayElement>
cXtArgArrayInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtArgArrayInterface
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtArgArrayInterface
: virtual public cXtArgArrayInterfaceImplement
{
public:
    typedef cXtArgArrayInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cXtArgArrayImplement;
/**
 **********************************************************************
 * Typedef: cXtArgArrayImplementImplement
 *
 *  Author: $author$           
 *    Date: 4/25/2010
 **********************************************************************
 */
typedef cArrayImplementT
<cXtArgArrayImplement, 
 cXtArgArrayInterface, 
 tXtArgArrayElement>
cXtArgArrayImplementImplement;
/**
 **********************************************************************
 *  Class: cXtArgArrayImplement
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtArgArrayImplement
: virtual public cXtArgArrayImplementImplement
{
public:
    typedef cXtArgArrayImplementImplement cImplements;
};
class c_INSTANCE_CLASS cXtArgArray;
/**
 **********************************************************************
 * Typedef: cXtArgArrayExtend
 *
 *  Author: $author$           
 *    Date: 4/25/2010
 **********************************************************************
 */
typedef cArrayT
<cXtArgArray,
 cXtArgArrayImplement, 
 cXtArgArrayInterface, 
 tXtArgArrayElement>
cXtArgArrayExtend;
/**
 **********************************************************************
 *  Class: cXtArgArray
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtArgArray
: public cXtArgArrayExtend
{
public:
    typedef cXtArgArrayExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtArgArray
     *
     *       Author: $author$           
     *         Date: 4/25/2010
     **********************************************************************
     */
    cXtArgArray()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtArgArray
     *
     *      Author: $author$           
     *        Date: 4/25/2010
     **********************************************************************
     */
    virtual ~cXtArgArray()
    {
    }
    /**
     **********************************************************************
     *  Function: operator ArgList
     *
     *    Author: $author$           
     *      Date: 4/26/2010
     **********************************************************************
     */
    virtual operator ArgList() const
#if defined(CXTARGARRAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGARRAY_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGARRAY_MEMBER_FUNCS_IMPLEMENT)
        argList = Elements();
#else /* !defined(CXTARGARRAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGARRAY_MEMBER_FUNCS_INTERFACE) */
};

class c_INSTANCE_CLASS cXtArgItem;
/**
 **********************************************************************
 * Typedef: cXtArgItemExtend
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cListItemT
<cXtArgItem, cXBase>
cXtArgItemExtend;
/**
 **********************************************************************
 *  Class: cXtArgItem
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtArgItem
: public cXtArgItemExtend
{
public:
    typedef cXtArgItemExtend cExtends;

    cXtArg m_arg;

    /**
     **********************************************************************
     *  Constructor: cXtArgItem
     *
     *       Author: $author$           
     *         Date: 4/26/2010
     **********************************************************************
     */
    cXtArgItem
    (Arg& xtArg,
     const XtChar* argName = 0,
     XtArgVal argValue = 0)
    : m_arg(xtArg, argName, argValue)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtArgItem
     *
     *      Author: $author$           
     *        Date: 4/26/2010
     **********************************************************************
     */
    virtual ~cXtArgItem()
    {
    }
#else /* !defined(CXTARGITEM_MEMBERS_ONLY) */
#endif /* !defined(CXTARGITEM_MEMBERS_ONLY) */

#if !defined(CXTARGITEM_MEMBERS_ONLY)
};

class c_INSTANCE_CLASS cXtArgItemList;
/**
 **********************************************************************
 * Typedef: cXtArgItemListExtend
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cListT
<cXtArgItemList, cXtArgItem, cXBase>
cXtArgItemListExtend;
/**
 **********************************************************************
 *  Class: cXtArgItemList
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtArgItemList
: public cXtArgItemListExtend
{
public:
    typedef cXtArgItemListExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtArgItemList
     *
     *       Author: $author$           
     *         Date: 4/26/2010
     **********************************************************************
     */
    cXtArgItemList()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtArgItemList
     *
     *      Author: $author$           
     *        Date: 4/26/2010
     **********************************************************************
     */
    virtual ~cXtArgItemList()
    {
    }
#else /* !defined(CXTARGITEMLIST_MEMBERS_ONLY) */
#endif /* !defined(CXTARGITEMLIST_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Clear
     *
     *    Author: $author$           
     *      Date: 4/26/2010
     **********************************************************************
     */
    virtual eError Clear()
#if defined(CXTARGITEMLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGITEMLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGITEMLIST_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        tItem* item;
        while ((item = PullItem()))
        {
            try { delete item; }
            catch (eError e)
            {
                DBE(("() caught error = %d\n", e));
                throw;
            }
        }
#else /* !defined(CXTARGITEMLIST_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGITEMLIST_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTARGITEMLIST_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTARGITEMLIST_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTARGITEM_MEMBERS_ONLY) */
#endif /* !defined(CXTARGITEM_MEMBERS_ONLY) */

#endif /* !defined(_CXTARGITEM_HXX) || defined(CXTARGITEM_MEMBERS_ONLY) */

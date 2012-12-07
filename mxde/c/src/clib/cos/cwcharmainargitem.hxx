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
 *   File: cwcharmainargitem.hxx
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
#if !defined(_CWCHARMAINARGITEM_HXX) || defined(CWCHARMAINARGITEM_MEMBERS_ONLY)
#if !defined(_CWCHARMAINARGITEM_HXX) && !defined(CWCHARMAINARGITEM_MEMBERS_ONLY)
#define _CWCHARMAINARGITEM_HXX
#endif /* !defined(_CWCHARMAINARGITEM_HXX) && !defined(CWCHARMAINARGITEM_MEMBERS_ONLY) */

#if !defined(CWCHARMAINARGITEM_MEMBERS_ONLY)
#include "cmainargitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWCHARMainArg;
class c_INSTANCE_CLASS cWCHARMainArgItem;
/**
 **********************************************************************
 * Typedef: cWCHARMainArgItemItemExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cExportListItemT
<cWCHARMainArgItem>
cWCHARMainArgItemItemExtend;
/**
 **********************************************************************
 * Typedef: cWCHARMainArgItemExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cMainArgItemT
<cWCHARMainArgItem, 
 cWCHARMainArgItemItemExtend, 
 cWCHARMainArg>
cWCHARMainArgItemExtend;
/**
 **********************************************************************
 *  Class: cWCHARMainArgItem
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARMainArgItem
: public cWCHARMainArgItemExtend
{
public:
    typedef cWCHARMainArgItemExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWCHARMainArgItem
     *
     *       Author: $author$
     *         Date: 8/7/2010
     **********************************************************************
     */
    cWCHARMainArgItem
    (cWCHARMainArg& mainArg) 
    : cExtends(mainArg)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWCHARMainArgItem
     *
     *      Author: $author$
     *        Date: 8/7/2010
     **********************************************************************
     */
    virtual ~cWCHARMainArgItem()
    {
    }
#else /* !defined(CWCHARMAINARGITEM_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAINARGITEM_MEMBERS_ONLY) */

#if !defined(CWCHARMAINARGITEM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWCHARMAINARGITEM_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAINARGITEM_MEMBERS_ONLY) */

#endif /* !defined(_CWCHARMAINARGITEM_HXX) || defined(CWCHARMAINARGITEM_MEMBERS_ONLY) */

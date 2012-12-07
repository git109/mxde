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
 *   File: cwcharmainarg.hxx
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
#if !defined(_CWCHARMAINARG_HXX) || defined(CWCHARMAINARG_MEMBERS_ONLY)
#if !defined(_CWCHARMAINARG_HXX) && !defined(CWCHARMAINARG_MEMBERS_ONLY)
#define _CWCHARMAINARG_HXX
#endif /* !defined(_CWCHARMAINARG_HXX) && !defined(CWCHARMAINARG_MEMBERS_ONLY) */

#if !defined(CWCHARMAINARG_MEMBERS_ONLY)
#include "cwcharmainarginterface.hxx"
#include "cwcharmainargitem.hxx"
#include "cmainarglist.hxx"
#include "cmainarg.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWCHARMainArg;
class c_INSTANCE_CLASS cWCHARMainArgList;
/**
 **********************************************************************
 * Typedef: cWCHARMainArgListListExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cStaticExportListT
<cWCHARMainArgList, cWCHARMainArgItem>
cWCHARMainArgListListExtend;
/**
 **********************************************************************
 * Typedef: cWCHARMainArgListExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cMainArgListT
<cWCHARMainArgList, cWCHARMainArgListListExtend, 
 cWCHARMainArgItem, cWCHARMainArg, WCHAR, int>
cWCHARMainArgListExtend;
/**
 **********************************************************************
 *  Class: cWCHARMainArgList
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARMainArgList
: public cWCHARMainArgListExtend
{
public:
    typedef cWCHARMainArgListExtend cExtends;
};
/**
 **********************************************************************
 * Typedef: cWCHARMainArgExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cMainArgT
<cWCHARMainArg, cWCHARMainArgImplement,
 cWCHARMainArgList, cWCHARMainArgItem, 
 cWCHARString, WCHAR, int>
cWCHARMainArgExtend;
/**
 **********************************************************************
 *  Class: cWCHARMainArg
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARMainArg
: virtual public cWCHARMainArgImplement,
  public cWCHARMainArgExtend
{
public:
    typedef cWCHARMainArgImplement cImplements;
    typedef cWCHARMainArgExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWCHARMainArg
     *
     *       Author: $author$
     *         Date: 8/7/2010
     **********************************************************************
     */
    cWCHARMainArg
    (const tChar* shortName,
     const tChar* name,
     const tChar* description=0,
     const tChar* parameters=0) 
    : cExtends(shortName, name, description, parameters)
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.AddItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     *  Destructor: ~cWCHARMainArg
     *
     *      Author: $author$
     *        Date: 8/7/2010
     **********************************************************************
     */
    virtual ~cWCHARMainArg()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.DeleteItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
#else /* !defined(CWCHARMAINARG_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAINARG_MEMBERS_ONLY) */

#if !defined(CWCHARMAINARG_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWCHARMAINARG_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAINARG_MEMBERS_ONLY) */

#endif /* !defined(_CWCHARMAINARG_HXX) || defined(CWCHARMAINARG_MEMBERS_ONLY) */

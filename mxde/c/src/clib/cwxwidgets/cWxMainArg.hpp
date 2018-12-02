///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2010 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cWxMainArg.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXMAINARG_HPP) || defined(CWXMAINARG_MEMBERS_ONLY)
#if !defined(_CWXMAINARG_HPP) && !defined(CWXMAINARG_MEMBERS_ONLY)
#define _CWXMAINARG_HPP
#endif // !defined(_CWXMAINARG_HPP) && !defined(CWXMAINARG_MEMBERS_ONLY) 

#if !defined(CWXMAINARG_MEMBERS_ONLY)
#include "cWxMainArgInterface.hpp"
#include "cWxMainArgItem.hpp"
#include "cWxCharString.hpp"
#include "cmainarglist.hxx"
#include "cmainarg.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cWxMainArg;
class c_INSTANCE_CLASS cWxMainArgList;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgListListExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cStaticExportListT
<cWxMainArgList, cWxMainArgItem>
cWxMainArgListListExtend;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgListExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cMainArgListT
<cWxMainArgList, 
 cWxMainArgListListExtend, 
 cWxMainArgItem,
 cWxMainArg,
 wxChar, int>
cWxMainArgListExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxMainArgList
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxMainArgList
: public cWxMainArgListExtend
{
public:
    typedef cWxMainArgListExtend cExtends;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cMainArgT
<cWxMainArg,
 cWxMainArgImplement,
 cWxMainArgList,
 cWxMainArgItem,
 cWxCharString,
 wxChar, int>
cWxMainArgExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxMainArg
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxMainArg
: virtual public cWxMainArgImplement,
  public cWxMainArgExtend
{
public:
    typedef cWxMainArgImplement cImplements;
    typedef cWxMainArgExtend cExtends;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
    static cWxMainArgList m_list;
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxMainArg
    //
    //       Author: $author$
    //         Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxMainArg
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
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWxMainArg
    //
    //      Author: $author$
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxMainArg()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.DeleteItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
#else // !defined(CWXMAINARG_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARG_MEMBERS_ONLY) 

#if !defined(CWXMAINARG_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXMAINARG_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARG_MEMBERS_ONLY) 

#endif // !defined(_CWXMAINARG_HPP) || defined(CWXMAINARG_MEMBERS_ONLY) 

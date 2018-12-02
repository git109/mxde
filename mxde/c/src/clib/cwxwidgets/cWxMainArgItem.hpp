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
//   File: cWxMainArgItem.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXMAINARGITEM_HPP) || defined(CWXMAINARGITEM_MEMBERS_ONLY)
#if !defined(_CWXMAINARGITEM_HPP) && !defined(CWXMAINARGITEM_MEMBERS_ONLY)
#define _CWXMAINARGITEM_HPP
#endif // !defined(_CWXMAINARGITEM_HPP) && !defined(CWXMAINARGITEM_MEMBERS_ONLY) 

#if !defined(CWXMAINARGITEM_MEMBERS_ONLY)
#include "cplatform_wxwidgets.h"
#include "wx/intl.h"
#include "cmainargitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cWxMainArg;
class c_INSTANCE_CLASS cWxMainArgItem;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgItemItemExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cExportListItemT<cWxMainArgItem>
cWxMainArgItemItemExtend;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxMainArgItemExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cMainArgItemT
<cWxMainArgItem, cWxMainArgItemItemExtend, cWxMainArg>
cWxMainArgItemExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxMainArgItem
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxMainArgItem
: public cWxMainArgItemExtend
{
public:
    typedef cWxMainArgItemExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxMainArgItem
    //
    //       Author: $author$
    //         Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxMainArgItem
    (cWxMainArg& mainArg)
    : cExtends(mainArg)
    {
    }
#else // !defined(CWXMAINARGITEM_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGITEM_MEMBERS_ONLY) 

#if !defined(CWXMAINARGITEM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXMAINARGITEM_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGITEM_MEMBERS_ONLY) 

#endif // !defined(_CWXMAINARGITEM_HPP) || defined(CWXMAINARGITEM_MEMBERS_ONLY) 

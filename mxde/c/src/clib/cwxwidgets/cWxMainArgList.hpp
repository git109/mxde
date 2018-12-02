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
//   File: cWxMainArgList.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXMAINARGLIST_HPP) || defined(CWXMAINARGLIST_MEMBERS_ONLY)
#if !defined(_CWXMAINARGLIST_HPP) && !defined(CWXMAINARGLIST_MEMBERS_ONLY)
#define _CWXMAINARGLIST_HPP
#endif // !defined(_CWXMAINARGLIST_HPP) && !defined(CWXMAINARGLIST_MEMBERS_ONLY) 

#if !defined(CWXMAINARGLIST_MEMBERS_ONLY)
#include "cWxMainArg.hpp"
#include "cmainarglist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

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
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxMainArgList
    //
    //       Author: $author$
    //         Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxMainArgList()
    {
    }
#else // !defined(CWXMAINARGLIST_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGLIST_MEMBERS_ONLY) 

#if !defined(CWXMAINARGLIST_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXMAINARGLIST_MEMBERS_ONLY) 
#endif // !defined(CWXMAINARGLIST_MEMBERS_ONLY) 

#endif // !defined(_CWXMAINARGLIST_HPP) || defined(CWXMAINARGLIST_MEMBERS_ONLY) 

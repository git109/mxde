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
//   File: cWxWin_SERVICE_STATUS_Attached.hpp
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWIN_SERVICE_STATUS_ATTACHED_HPP) || defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY)
#if !defined(_CWXWIN_SERVICE_STATUS_ATTACHED_HPP) && !defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY)
#define _CWXWIN_SERVICE_STATUS_ATTACHED_HPP
#endif // !defined(_CWXWIN_SERVICE_STATUS_ATTACHED_HPP) && !defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY) 

#if !defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY)
#include "cplatform_wxwidgets.h"
#include "cattached.hxx"

#define INVALID_SERVICE_STATUS_HANDLE NULL
#define SERVICE_STATE DWORD

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWxWin_SERVICE_STATUS_AttachedInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_AttachedInterfaceImplements
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedInterfaceT
<cWxWin_SERVICE_STATUS_AttachedInterface, 
 SERVICE_STATUS_HANDLE, UINT, NULL, cInterfaceBase>
cWxWin_SERVICE_STATUS_AttachedInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS_AttachedInterface
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxWin_SERVICE_STATUS_AttachedInterface
: virtual public cWxWin_SERVICE_STATUS_AttachedInterfaceImplements
{
public:
    typedef cWxWin_SERVICE_STATUS_AttachedInterfaceImplements cImplements;
    typedef cWxWin_SERVICE_STATUS_AttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cWxWin_SERVICE_STATUS_AttachedImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_AttachedImplementImplements
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedImplementT
<cWxWin_SERVICE_STATUS_AttachedImplement, 
 cWxWin_SERVICE_STATUS_AttachedInterface, 
 SERVICE_STATUS_HANDLE, UINT, NULL>
cWxWin_SERVICE_STATUS_AttachedImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS_AttachedImplement
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWxWin_SERVICE_STATUS_AttachedImplement
: virtual public cWxWin_SERVICE_STATUS_AttachedImplementImplements
{
public:
    typedef cWxWin_SERVICE_STATUS_AttachedImplementImplements cImplements;
    typedef cWxWin_SERVICE_STATUS_AttachedImplement cDerives;
};
class c_INSTANCE_CLASS cWxWin_SERVICE_STATUS_Attached;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_AttachedExtends
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedT
<cWxWin_SERVICE_STATUS_Attached, 
 cWxWin_SERVICE_STATUS_AttachedImplement, 
 cWxWin_SERVICE_STATUS_AttachedInterface,
 SERVICE_STATUS_HANDLE, UINT, NULL, cBase>
cWxWin_SERVICE_STATUS_AttachedExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS_Attached
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxWin_SERVICE_STATUS_Attached
: public cWxWin_SERVICE_STATUS_AttachedExtends
{
public:
    typedef cWxWin_SERVICE_STATUS_AttachedExtends cExtends;
    typedef cWxWin_SERVICE_STATUS_Attached cDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxWin_SERVICE_STATUS_Attached
    //
    //      Author: $author$
    //        Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    cWxWin_SERVICE_STATUS_Attached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY) 
#endif // !defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY) 

#endif // !defined(_CWXWIN_SERVICE_STATUS_ATTACHED_HPP) || defined(CWXWIN_SERVICE_STATUS_ATTACHED_MEMBERS_ONLY) 

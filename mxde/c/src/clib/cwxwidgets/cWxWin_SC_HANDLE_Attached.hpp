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
//   File: cWxWin_SC_HANDLE_Attached.hpp
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWIN_SC_HANDLE_ATTACHED_HPP) || defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY)
#if !defined(_CWXWIN_SC_HANDLE_ATTACHED_HPP) && !defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY)
#define _CWXWIN_SC_HANDLE_ATTACHED_HPP
#endif // !defined(_CWXWIN_SC_HANDLE_ATTACHED_HPP) && !defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY) 

#if !defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY)
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWxWin_SC_HANDLE_AttachedInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SC_HANDLE_AttachedInterfaceImplements
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedInterfaceT
<cWxWin_SC_HANDLE_AttachedInterface, 
 SC_HANDLE, UINT, NULL, cInterfaceBase>
cWxWin_SC_HANDLE_AttachedInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SC_HANDLE_AttachedInterface
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxWin_SC_HANDLE_AttachedInterface
: virtual public cWxWin_SC_HANDLE_AttachedInterfaceImplements
{
public:
    typedef cWxWin_SC_HANDLE_AttachedInterfaceImplements cImplements;
    typedef cWxWin_SC_HANDLE_AttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cWxWin_SC_HANDLE_AttachedImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SC_HANDLE_AttachedImplementImplements
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedImplementT
<cWxWin_SC_HANDLE_AttachedImplement, 
 cWxWin_SC_HANDLE_AttachedInterface, 
 SC_HANDLE, UINT, NULL>
cWxWin_SC_HANDLE_AttachedImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SC_HANDLE_AttachedImplement
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWxWin_SC_HANDLE_AttachedImplement
: virtual public cWxWin_SC_HANDLE_AttachedImplementImplements
{
public:
    typedef cWxWin_SC_HANDLE_AttachedImplementImplements cImplements;
    typedef cWxWin_SC_HANDLE_AttachedImplement cDerives;
};
class c_INSTANCE_CLASS cWxWin_SC_HANDLE_Attached;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SC_HANDLE_AttachedExtends
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedT
<cWxWin_SC_HANDLE_Attached, 
 cWxWin_SC_HANDLE_AttachedImplement, 
 cWxWin_SC_HANDLE_AttachedInterface,
 SC_HANDLE, UINT, NULL, cBase>
cWxWin_SC_HANDLE_AttachedExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SC_HANDLE_Attached
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxWin_SC_HANDLE_Attached
: public cWxWin_SC_HANDLE_AttachedExtends
{
public:
    typedef cWxWin_SC_HANDLE_AttachedExtends cExtends;
    typedef cWxWin_SC_HANDLE_Attached cDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxWin_SC_HANDLE_Attached
    //
    //      Author: $author$
    //        Date: 8/31/2010
    ///////////////////////////////////////////////////////////////////////
    cWxWin_SC_HANDLE_Attached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY) 
#endif // !defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY) 

#endif // !defined(_CWXWIN_SC_HANDLE_ATTACHED_HPP) || defined(CWXWIN_SC_HANDLE_ATTACHED_MEMBERS_ONLY) 

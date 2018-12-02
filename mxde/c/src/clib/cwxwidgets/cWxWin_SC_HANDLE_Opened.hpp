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
//   File: cWxWin_SC_HANDLE_Opened.hpp
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWIN_SC_HANDLE_OPENED_HPP) || defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY)
#if !defined(_CWXWIN_SC_HANDLE_OPENED_HPP) && !defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY)
#define _CWXWIN_SC_HANDLE_OPENED_HPP
#endif // !defined(_CWXWIN_SC_HANDLE_OPENED_HPP) && !defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY) 

#if !defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY)
#include "cWxWin_SC_HANDLE_Attached.hpp"
#include "copened.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWxWin_SC_HANDLE_OpenedInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SC_HANDLE_OpenedInterfaceImplements
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cOpenedInterfaceT
<cWxWin_SC_HANDLE_OpenedInterface, cWxWin_SC_HANDLE_AttachedInterface>
cWxWin_SC_HANDLE_OpenedInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SC_HANDLE_OpenedInterface
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxWin_SC_HANDLE_OpenedInterface
: virtual public cWxWin_SC_HANDLE_OpenedInterfaceImplements
{
public:
    typedef cWxWin_SC_HANDLE_OpenedInterfaceImplements cImplements;
    typedef cWxWin_SC_HANDLE_OpenedInterface cDerives;
};
class c_EXPORT_CLASS cWxWin_SC_HANDLE_OpenedImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SC_HANDLE_OpenedImplementImplements
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cOpenedImplementT
<cWxWin_SC_HANDLE_OpenedImplement, cWxWin_SC_HANDLE_OpenedInterface>
cWxWin_SC_HANDLE_OpenedImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SC_HANDLE_OpenedImplement
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cWxWin_SC_HANDLE_OpenedImplement
: virtual public cWxWin_SC_HANDLE_OpenedImplementImplements
{
public:
    typedef cWxWin_SC_HANDLE_OpenedImplementImplements cImplements;
    typedef cWxWin_SC_HANDLE_OpenedImplement cDerives;
};
class c_EXPORT_CLASS cWxWin_SC_HANDLE_Opened;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SC_HANDLE_OpenedExtends
//
//  Author: $author$
//    Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
typedef cOpenedT
<cWxWin_SC_HANDLE_Opened, 
 cWxWin_SC_HANDLE_OpenedImplement, 
 cWxWin_SC_HANDLE_Attached>
cWxWin_SC_HANDLE_OpenedExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SC_HANDLE_Opened
//
// Author: $author$
//   Date: 8/31/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cWxWin_SC_HANDLE_Opened
: public cWxWin_SC_HANDLE_OpenedExtends
{
public:
    typedef cWxWin_SC_HANDLE_OpenedExtends cExtends;
    typedef cWxWin_SC_HANDLE_Opened cDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxWin_SC_HANDLE_Opened
    //
    //      Author: $author$
    //        Date: 8/31/2010
    ///////////////////////////////////////////////////////////////////////
    cWxWin_SC_HANDLE_Opened
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cWxWin_SC_HANDLE_Opened
    //
    //     Author: $author$
    //       Date: 8/31/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxWin_SC_HANDLE_Opened()
    {
        eError error;
        if ((error = Closed()))
            throw(error);
    }
#include "copenedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY) 
#endif // !defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY) 

#endif // !defined(_CWXWIN_SC_HANDLE_OPENED_HPP) || defined(CWXWIN_SC_HANDLE_OPENED_MEMBERS_ONLY) 

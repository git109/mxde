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
//   File: cWxWin_SERVICE_STATUS_Opened.hpp
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWIN_SERVICE_STATUS_OPENED_HPP) || defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY)
#if !defined(_CWXWIN_SERVICE_STATUS_OPENED_HPP) && !defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY)
#define _CWXWIN_SERVICE_STATUS_OPENED_HPP
#endif // !defined(_CWXWIN_SERVICE_STATUS_OPENED_HPP) && !defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY) 

#if !defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY)
#include "cWxWin_SERVICE_STATUS_Attached.hpp"
#include "copened.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cWxWin_SERVICE_STATUS_OpenedInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_OpenedInterfaceImplements
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cOpenedInterfaceT
<cWxWin_SERVICE_STATUS_OpenedInterface, cWxWin_SERVICE_STATUS_AttachedInterface>
cWxWin_SERVICE_STATUS_OpenedInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS_OpenedInterface
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxWin_SERVICE_STATUS_OpenedInterface
: virtual public cWxWin_SERVICE_STATUS_OpenedInterfaceImplements
{
public:
    typedef cWxWin_SERVICE_STATUS_OpenedInterfaceImplements cImplements;
    typedef cWxWin_SERVICE_STATUS_OpenedInterface cDerives;
};
class c_EXPORT_CLASS cWxWin_SERVICE_STATUS_OpenedImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_OpenedImplementImplements
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cOpenedImplementT
<cWxWin_SERVICE_STATUS_OpenedImplement, cWxWin_SERVICE_STATUS_OpenedInterface>
cWxWin_SERVICE_STATUS_OpenedImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS_OpenedImplement
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cWxWin_SERVICE_STATUS_OpenedImplement
: virtual public cWxWin_SERVICE_STATUS_OpenedImplementImplements
{
public:
    typedef cWxWin_SERVICE_STATUS_OpenedImplementImplements cImplements;
    typedef cWxWin_SERVICE_STATUS_OpenedImplement cDerives;
};
class c_EXPORT_CLASS cWxWin_SERVICE_STATUS_Opened;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_OpenedExtends
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cOpenedT
<cWxWin_SERVICE_STATUS_Opened, 
 cWxWin_SERVICE_STATUS_OpenedImplement, 
 cWxWin_SERVICE_STATUS_Attached>
cWxWin_SERVICE_STATUS_OpenedExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS_Opened
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cWxWin_SERVICE_STATUS_Opened
: public cWxWin_SERVICE_STATUS_OpenedExtends
{
public:
    typedef cWxWin_SERVICE_STATUS_OpenedExtends cExtends;
    typedef cWxWin_SERVICE_STATUS_Opened cDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxWin_SERVICE_STATUS_Opened
    //
    //      Author: $author$
    //        Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    cWxWin_SERVICE_STATUS_Opened
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cWxWin_SERVICE_STATUS_Opened
    //
    //     Author: $author$
    //       Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxWin_SERVICE_STATUS_Opened()
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

#else // !defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY) 
#endif // !defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY) 

#endif // !defined(_CWXWIN_SERVICE_STATUS_OPENED_HPP) || defined(CWXWIN_SERVICE_STATUS_OPENED_MEMBERS_ONLY) 

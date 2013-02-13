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
//   File: cQWidgetCreated.hpp
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQWIDGETCREATED_HPP) || defined(CQWIDGETCREATED_MEMBERS_ONLY)
#if !defined(_CQWIDGETCREATED_HPP) && !defined(CQWIDGETCREATED_MEMBERS_ONLY)
#define _CQWIDGETCREATED_HPP
#endif // !defined(_CQWIDGETCREATED_HPP) && !defined(CQWIDGETCREATED_MEMBERS_ONLY) 

#if !defined(CQWIDGETCREATED_MEMBERS_ONLY)
#include "cQWidgetAttached.hpp"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cQWidgetCreatedInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cQWidgetCreatedInterfaceImplements
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cCreatedInterfaceT
<cQWidgetCreatedInterface, cQWidgetAttachedInterface>
cQWidgetCreatedInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cQWidgetCreatedInterface
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cQWidgetCreatedInterface
: virtual public cQWidgetCreatedInterfaceImplements
{
public:
    typedef cQWidgetCreatedInterfaceImplements cImplements;
    typedef cQWidgetCreatedInterface cDerives;
};
class c_EXPORT_CLASS cQWidgetCreatedImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cQWidgetCreatedImplementImplements
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cCreatedImplementT
<cQWidgetCreatedImplement, cQWidgetCreatedInterface>
cQWidgetCreatedImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cQWidgetCreatedImplement
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cQWidgetCreatedImplement
: virtual public cQWidgetCreatedImplementImplements
{
public:
    typedef cQWidgetCreatedImplementImplements cImplements;
    typedef cQWidgetCreatedImplement cDerives;
};
class c_EXPORT_CLASS cQWidgetCreated;
///////////////////////////////////////////////////////////////////////
// Typedef: cQWidgetCreatedExtends
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cCreatedT
<cQWidgetCreated, 
 cQWidgetCreatedImplement, 
 cQWidgetAttached>
cQWidgetCreatedExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cQWidgetCreated
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cQWidgetCreated
: public cQWidgetCreatedExtends
{
public:
    typedef cQWidgetCreatedExtends cExtends;
    typedef cQWidgetCreated cDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cQWidgetCreated
    //
    //      Author: $author$           
    //        Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    cQWidgetCreated
    (QWidget* attached=0,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cQWidgetCreated
    //
    //     Author: $author$           
    //       Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cQWidgetCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CQWIDGETCREATED_MEMBERS_ONLY) 
#endif // !defined(CQWIDGETCREATED_MEMBERS_ONLY) 

#endif // !defined(_CQWIDGETCREATED_HPP) || defined(CQWIDGETCREATED_MEMBERS_ONLY) 

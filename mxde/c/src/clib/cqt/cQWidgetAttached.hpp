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
//   File: cQWidgetAttached.hpp
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQWIDGETATTACHED_HPP) || defined(CQWIDGETATTACHED_MEMBERS_ONLY)
#if !defined(_CQWIDGETATTACHED_HPP) && !defined(CQWIDGETATTACHED_MEMBERS_ONLY)
#define _CQWIDGETATTACHED_HPP
#endif // !defined(_CQWIDGETATTACHED_HPP) && !defined(CQWIDGETATTACHED_MEMBERS_ONLY) 

#if !defined(CQWIDGETATTACHED_MEMBERS_ONLY)
#include <QtGui>
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cQWidgetAttachedInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cQWidgetAttachedInterfaceImplements
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedInterfaceT
<cQWidgetAttachedInterface, 
 QWidget*, UINT, NULL, cInterfaceBase>
cQWidgetAttachedInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cQWidgetAttachedInterface
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cQWidgetAttachedInterface
: virtual public cQWidgetAttachedInterfaceImplements
{
public:
    typedef cQWidgetAttachedInterfaceImplements cImplements;
    typedef cQWidgetAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cQWidgetAttachedImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cQWidgetAttachedImplementImplements
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedImplementT
<cQWidgetAttachedImplement, 
 cQWidgetAttachedInterface, 
 QWidget*, UINT, NULL>
cQWidgetAttachedImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cQWidgetAttachedImplement
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cQWidgetAttachedImplement
: virtual public cQWidgetAttachedImplementImplements
{
public:
    typedef cQWidgetAttachedImplementImplements cImplements;
    typedef cQWidgetAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cQWidgetAttached;
///////////////////////////////////////////////////////////////////////
// Typedef: cQWidgetAttachedExtends
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cAttachedT
<cQWidgetAttached, 
 cQWidgetAttachedImplement, 
 cQWidgetAttachedInterface,
 QWidget*, UINT, NULL, cBase>
cQWidgetAttachedExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cQWidgetAttached
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cQWidgetAttached
: public cQWidgetAttachedExtends
{
public:
    typedef cQWidgetAttachedExtends cExtends;
    typedef cQWidgetAttached cDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cQWidgetAttached
    //
    //      Author: $author$           
    //        Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    cQWidgetAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CQWIDGETATTACHED_MEMBERS_ONLY) 
#endif // !defined(CQWIDGETATTACHED_MEMBERS_ONLY) 

#endif // !defined(_CQWIDGETATTACHED_HPP) || defined(CQWIDGETATTACHED_MEMBERS_ONLY) 

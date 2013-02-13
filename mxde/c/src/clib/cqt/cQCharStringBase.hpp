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
//   File: cQCharStringBase.hpp
//
// Author: $author$           
//   Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQCHARSTRINGBASE_HPP) || defined(CQCHARSTRINGBASE_MEMBERS_ONLY)
#if !defined(_CQCHARSTRINGBASE_HPP) && !defined(CQCHARSTRINGBASE_MEMBERS_ONLY)
#define _CQCHARSTRINGBASE_HPP
#endif // !defined(_CQCHARSTRINGBASE_HPP) && !defined(CQCHARSTRINGBASE_MEMBERS_ONLY) 

#if !defined(CQCHARSTRINGBASE_MEMBERS_ONLY)
#include <QtCore>
#include "cstringbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cQStringBaseInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cQStringBaseInterfaceImplement
//
//  Author: $author$           
//    Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
typedef cStringBaseInterfaceT
<cQStringBaseInterface, QChar, char>
cQStringBaseInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cQStringBaseInterface
//
// Author: $author$           
//   Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cQStringBaseInterface
: virtual public cQStringBaseInterfaceImplement
{
public:
    typedef cQStringBaseInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cQCharStringBaseImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStringBaseImplementImplement
//
//  Author: $author$           
//    Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
typedef cStringBaseImplementT
<cQCharStringBaseImplement, 
 cQStringBaseInterface, QChar, char>
cQCharStringBaseImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cQCharStringBaseImplement
//
// Author: $author$           
//   Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cQCharStringBaseImplement
: virtual public cQCharStringBaseImplementImplement
{
public:
    typedef cQCharStringBaseImplementImplement cImplements;
};
class c_INSTANCE_CLASS cQCharStringBase;
///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStringBaseExtend
//
//  Author: $author$           
//    Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
typedef cStringBaseT
<cQCharStringBase, 
 cQCharStringBaseImplement, 
 cBase, QChar, char>
cQCharStringBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cQCharStringBase
//
// Author: $author$           
//   Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cQCharStringBase
: public cQCharStringBaseExtend
{
public:
    typedef cQCharStringBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQCharStringBase
    //
    //       Author: $author$           
    //         Date: 4/7/2010
    ///////////////////////////////////////////////////////////////////////
    cQCharStringBase
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CQCHARSTRINGBASE_MEMBERS_ONLY) 
#endif // !defined(CQCHARSTRINGBASE_MEMBERS_ONLY) 

#endif // !defined(_CQCHARSTRINGBASE_HPP) || defined(CQCHARSTRINGBASE_MEMBERS_ONLY) 

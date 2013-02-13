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
//   File: cQCharString.hpp
//
// Author: $author$           
//   Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQCHARSTRING_HPP) || defined(CQCHARSTRING_MEMBERS_ONLY)
#if !defined(_CQCHARSTRING_HPP) && !defined(CQCHARSTRING_MEMBERS_ONLY)
#define _CQCHARSTRING_HPP
#endif // !defined(_CQCHARSTRING_HPP) && !defined(CQCHARSTRING_MEMBERS_ONLY) 

#if !defined(CQCHARSTRING_MEMBERS_ONLY)
#include <QtCore>
#include "cQCharStringBase.hpp"
#include "cimplementbase.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStreamInterface
//
//  Author: $author$           
//    Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase cQCharStreamInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStreamInterface
//
//  Author: $author$           
//    Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
typedef cImplementBase cQCharStreamImplement;

class c_INTERFACE_CLASS cQCharStringInterface;
///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStringInterfaceImplement
//
//  Author: $author$           
//    Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
typedef cStringInterfaceT
<cQCharStringInterface, cQCharStreamInterface, 
 QChar, char>
cQCharStringInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cQCharStringInterface
//
// Author: $author$           
//   Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cQCharStringInterface
: virtual public cQCharStringInterfaceImplement
{
public:
    typedef cQCharStringInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cQCharStringImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStringImplementImplement
//
//  Author: $author$           
//    Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
typedef cStringImplementT
<cQCharStringImplement, 
 cQCharStringInterface, 
 cQCharStreamImplement, 
 QChar, char>
cQCharStringImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cQCharStringImplement
//
// Author: $author$           
//   Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cQCharStringImplement
: virtual public cQCharStringImplementImplement
{
public:
    typedef cQCharStringImplementImplement cImplements;
};
class c_INSTANCE_CLASS cQCharString;
///////////////////////////////////////////////////////////////////////
// Typedef: cQCharStringExtend
//
//  Author: $author$           
//    Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
typedef cStringT
<cQCharString, 
 cQCharStringImplement,
 cQCharStringInterface,
 cQCharStringBase,
 QChar, char>
cQCharStringExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cQCharString
//
// Author: $author$           
//   Date: 4/8/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cQCharString
: public cQCharStringExtend
{
public:
    typedef cQCharStringExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQCharString
    //
    //       Author: $author$           
    //         Date: 4/8/2010
    ///////////////////////////////////////////////////////////////////////
    cQCharString
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQCharString
    //
    //       Author: $author$           
    //         Date: 4/8/2010
    ///////////////////////////////////////////////////////////////////////
    cQCharString
    (const char* chars,
     tLength length = vUndefinedLength)
    {
        eError error;
        if (chars)
        if (0 > (length = Append_chars(chars, length)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQCharString
    //
    //       Author: $author$           
    //         Date: 4/8/2010
    ///////////////////////////////////////////////////////////////////////
    cQCharString
    (const WCHAR* chars,
     tLength length = vUndefinedLength)
    {
        eError error;
        if (chars)
        if (0 > (length = AppendWChars(chars, length)))
            throw(error = -length);
    }
#else // !defined(CQCHARSTRING_MEMBERS_ONLY) 
#endif // !defined(CQCHARSTRING_MEMBERS_ONLY) 

#if !defined(CQCHARSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CQCHARSTRING_MEMBERS_ONLY) 
#endif // !defined(CQCHARSTRING_MEMBERS_ONLY) 

#endif // !defined(_CQCHARSTRING_HPP) || defined(CQCHARSTRING_MEMBERS_ONLY) 

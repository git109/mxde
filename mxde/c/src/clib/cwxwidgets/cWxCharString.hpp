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
//   File: cWxCharString.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXCHARSTRING_HPP) || defined(CWXCHARSTRING_MEMBERS_ONLY)
#if !defined(_CWXCHARSTRING_HPP) && !defined(CWXCHARSTRING_MEMBERS_ONLY)
#define _CWXCHARSTRING_HPP
#endif // !defined(_CWXCHARSTRING_HPP) && !defined(CWXCHARSTRING_MEMBERS_ONLY) 

#if !defined(CWXCHARSTRING_MEMBERS_ONLY)
#include "cWxCharStringInterface.hpp"
#include "cstringbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cWxCharString;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxCharStringExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cStringBaseT
<cWxCharString, 
 cWxCharStringImplement, 
 cBase, wxChar>
cWxCharStringExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxCharString
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxCharString
: virtual public cWxCharStringImplement,
  public cWxCharStringExtend
{
public:
    typedef cWxCharStringImplement cImplements;
    typedef cWxCharStringExtend cExtends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxCharString
    //
    //       Author: $author$
    //         Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxCharString
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWxCharString
    //
    //      Author: $author$
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxCharString()
    {
    }
#else // !defined(CWXCHARSTRING_MEMBERS_ONLY) 
#endif // !defined(CWXCHARSTRING_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Assign
    //
    //    Author: $author$
    //      Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tLength Assign
    (const tChar* chars, tLength length=vUndefinedLength)
#if defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE) 
    {
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT)
        count = assign(chars, length);
#else // !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: HasChars
    //
    //    Author: $author$
    //      Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual const tChar* HasChars
    (tLength& length) const
#if defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE) 
    {
        const tChar* chars = 0;
#if !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT)
        if ((chars = c_str(length)))
        if (0 >= (length))
            chars = 0;
#else // !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT) 
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Compare
    //
    //    Author: $author$
    //      Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (const tChar* toChars, 
     tLength length = vUndefinedLength) const
#if defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT)
        int unequal = compare(toChars, length);
#else // !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT) 
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
#endif // !defined(CWXCHARSTRING_MEMBER_FUNCS_IMPLEMENT) 
        return unequal;
    }
#endif // defined(CWXCHARSTRING_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWXCHARSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXCHARSTRING_MEMBERS_ONLY) 
#endif // !defined(CWXCHARSTRING_MEMBERS_ONLY) 

#endif // !defined(_CWXCHARSTRING_HPP) || defined(CWXCHARSTRING_MEMBERS_ONLY) 

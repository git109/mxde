///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosWinInstanceBase.hpp
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWININSTANCEBASE_HPP) || defined(XOSWININSTANCEBASE_MEMBERS_ONLY)
#if !defined(_XOSWININSTANCEBASE_HPP) && !defined(XOSWININSTANCEBASE_MEMBERS_ONLY)
#define _XOSWININSTANCEBASE_HPP
#endif // !defined(_XOSWININSTANCEBASE_HPP) && !defined(XOSWININSTANCEBASE_MEMBERS_ONLY) 

#if !defined(XOSWININSTANCEBASE_MEMBERS_ONLY)
#include "XosWinInterfaceBase.hpp"
#include "XosWinBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinInstanceBaseImplement
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinImplementBase
XosWinInstanceBaseImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinInstanceBaseExtend
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinBase
XosWinInstanceBaseExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinInstanceBase
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS XosWinInstanceBase
: virtual public XosWinInstanceBaseImplement,
  public XosWinInstanceBaseExtend
{
public:
    typedef XosWinInstanceBaseImplement Implements;
    typedef XosWinInstanceBaseExtend Extends;
#else // !defined(XOSWININSTANCEBASE_MEMBERS_ONLY) 
#endif // !defined(XOSWININSTANCEBASE_MEMBERS_ONLY) 

#if !defined(XOSWININSTANCEBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWININSTANCEBASE_MEMBERS_ONLY) 
#endif // !defined(XOSWININSTANCEBASE_MEMBERS_ONLY) 

#endif // !defined(_XOSWININSTANCEBASE_HPP) || defined(XOSWININSTANCEBASE_MEMBERS_ONLY) 
        


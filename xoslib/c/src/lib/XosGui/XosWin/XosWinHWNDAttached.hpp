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
///   File: XosWinHWNDAttached.hpp
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINHWNDATTACHED_HPP) || defined(XOSWINHWNDATTACHED_MEMBERS_ONLY)
#if !defined(_XOSWINHWNDATTACHED_HPP) && !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY)
#define _XOSWINHWNDATTACHED_HPP
#endif // !defined(_XOSWINHWNDATTACHED_HPP) && !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY) 

#if !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY)
#include "XosWinInterfaceBase.hpp"
#include "XosWinBase.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHWNDAttachedImplement
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<HWND, INT, NULL, XosWinInterfaceBase>
XosWinHWNDAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHWNDAttachedExtend
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<HWND, INT, NULL, XosWinHWNDAttachedImplement, XosWinBase>
XosWinHWNDAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinHWNDAttached
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinHWNDAttached
: virtual public XosWinHWNDAttachedImplement,
  public XosWinHWNDAttachedExtend
{
public:
    typedef XosWinHWNDAttachedImplement Implements;
    typedef XosWinHWNDAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinHWNDAttached
    ///
    ///       Author: $author$
    ///         Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinHWNDAttached
    (HWND attached=NULL)
	: Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinHWNDAttached
    ///
    ///      Author: $author$
    ///        Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinHWNDAttached()
    {
    }
#else // !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY) 

#if !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY)
};

#if !defined(XOSWINHWNDCREATEDATTACHED_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHWNDCreatedAttachedImplement
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<HWND, INT, NULL, XosWinHWNDAttachedImplement>
XosWinHWNDCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHWNDCreatedAttachedExtend
///
///  Author: $author$
///    Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<HWND, INT, NULL, XosWinHWNDCreatedAttachedImplement, XosWinHWNDAttached>
XosWinHWNDCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinHWNDCreatedAttached
///
/// Author: $author$
///   Date: 12/7/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinHWNDCreatedAttached
: virtual public XosWinHWNDCreatedAttachedImplement,
  public XosWinHWNDCreatedAttachedExtend
{
public:
    typedef XosWinHWNDCreatedAttachedImplement Implements;
    typedef XosWinHWNDCreatedAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinHWNDCreatedAttached
    ///
    ///       Author: $author$
    ///         Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinHWNDCreatedAttached
    (HWND attached=NULL,
     bool isCreated=false)
	: Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinHWNDCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 12/7/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinHWNDCreatedAttached()
    {
    }
#else // !defined(XOSWINHWNDCREATEDATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHWNDCREATEDATTACHED_MEMBERS_ONLY) 

#if !defined(XOSWINHWNDCREATEDATTACHED_MEMBERS_ONLY)
};
#else // !defined(XOSWINHWNDCREATEDATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHWNDCREATEDATTACHED_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHWNDATTACHED_MEMBERS_ONLY) 

#endif // !defined(_XOSWINHWNDATTACHED_HPP) || defined(XOSWINHWNDATTACHED_MEMBERS_ONLY) 

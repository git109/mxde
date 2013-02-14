///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
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
///   File: XosWinATOMAttached.hpp
///
/// Author: $author$
///   Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINATOMATTACHED_HPP
#define _XOSWINATOMATTACHED_HPP

#include "XosWinInterfaceBase.hpp"
#include "XosWinBase.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinATOMAttachedImplement
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<ATOM, INT, NULL, XosWinInterfaceBase>
XosWinATOMAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinATOMAttachedExtend
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<ATOM, INT, NULL, XosWinATOMAttachedImplement, XosBase>
XosWinATOMAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinATOMAttached
///
/// Author: $author$
///   Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinATOMAttached
: virtual public XosWinATOMAttachedImplement,
  public XosWinATOMAttachedExtend
{
public:
    typedef XosWinATOMAttachedImplement Implements;
    typedef XosWinATOMAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinATOMAttached
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinATOMAttached
    (ATOM attached=NULL)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinATOMAttached
    ///
    ///      Author: $author$
    ///        Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinATOMAttached()
    {
    }
};


///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinATOMCreatedAttachedImplement
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<ATOM, INT, NULL, XosWinATOMAttachedImplement>
XosWinATOMCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinATOMCreatedAttachedExtend
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<ATOM, INT, NULL, XosWinATOMCreatedAttachedImplement, XosWinATOMAttached>
XosWinATOMCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinATOMCreatedAttached
///
/// Author: $author$
///   Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinATOMCreatedAttached
: virtual public XosWinATOMCreatedAttachedImplement,
  public XosWinATOMCreatedAttachedExtend
{
public:
    typedef XosWinATOMCreatedAttachedImplement Implements;
    typedef XosWinATOMCreatedAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinATOMCreatedAttached
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinATOMCreatedAttached
    (ATOM attached=NULL, bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinATOMCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinATOMCreatedAttached()
    {
        XosError error;
        if ((error = Destroyed()))
            throw(error);
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINATOMATTACHED_HPP 
        


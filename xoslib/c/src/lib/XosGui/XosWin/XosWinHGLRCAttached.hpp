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
///   File: XosWinHGLRCAttached.hpp
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINHGLRCATTACHED_HPP) || defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY)
#if !defined(_XOSWINHGLRCATTACHED_HPP) && !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY)
#define _XOSWINHGLRCATTACHED_HPP
#endif // !defined(_XOSWINHGLRCATTACHED_HPP) && !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY) 

#if !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY)
#include "XosWinInterfaceBase.hpp"
#include "XosWinBase.hpp"
#include "XosWinGL.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHGLRCAttachedImplement
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<HGLRC, INT, NULL, XosWinInterfaceBase>
XosWinHGLRCAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHGLRCAttachedExtend
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<HGLRC, INT, NULL, XosWinHGLRCAttachedImplement, XosWinBase>
XosWinHGLRCAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinHGLRCAttached
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinHGLRCAttached
: virtual public XosWinHGLRCAttachedImplement,
  public XosWinHGLRCAttachedExtend
{
public:
    typedef XosWinHGLRCAttachedImplement Implements;
    typedef XosWinHGLRCAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinHGLRCAttached
    ///
    ///       Author: $author$
    ///         Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinHGLRCAttached
    (HGLRC attached=NULL)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinHGLRCAttached
    ///
    ///      Author: $author$
    ///        Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinHGLRCAttached()
    {
    }
#else // !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY) 

#if !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY)
};

#if !defined(XOSWINHGLRCCREATEDATTACHED_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHGLRCCreatedAttachedImplement
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<HGLRC, INT, NULL, XosWinHGLRCAttachedImplement>
XosWinHGLRCCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHGLRCCreatedAttachedExtend
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<HGLRC, INT, NULL, XosWinHGLRCCreatedAttachedImplement, XosWinHGLRCAttached>
XosWinHGLRCCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinHGLRCCreatedAttached
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinHGLRCCreatedAttached
: virtual public XosWinHGLRCCreatedAttachedImplement,
  public XosWinHGLRCCreatedAttachedExtend
{
public:
    typedef XosWinHGLRCCreatedAttachedImplement Implements;
    typedef XosWinHGLRCCreatedAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinHGLRCCreatedAttached
    ///
    ///       Author: $author$
    ///         Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinHGLRCCreatedAttached
    (HGLRC attached=NULL,
     bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinHGLRCCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinHGLRCCreatedAttached()
    {
        XosError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else // !defined(XOSWINHGLRCCREATEDATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHGLRCCREATEDATTACHED_MEMBERS_ONLY) 

#if !defined(XOSWINHGLRCCREATEDATTACHED_MEMBERS_ONLY)
};
#else // !defined(XOSWINHGLRCCREATEDATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHGLRCCREATEDATTACHED_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY) 

#endif // !defined(_XOSWINHGLRCATTACHED_HPP) || defined(XOSWINHGLRCATTACHED_MEMBERS_ONLY) 
        


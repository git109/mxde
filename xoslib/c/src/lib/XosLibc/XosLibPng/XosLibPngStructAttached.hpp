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
///   File: XosLibPngStructAttached.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGSTRUCTATTACHED_HPP) || defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGSTRUCTATTACHED_HPP) && !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY)
#define _XOSLIBPNGSTRUCTATTACHED_HPP
#endif // !defined(_XOSLIBPNGSTRUCTATTACHED_HPP) && !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY)
#include "XosLibPngStructAttachedInterface.hpp"
#include "XosLibPngBase.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngStructAttachedExtendExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<png_structp, int, 0, 
 XosLibPngStructAttachedInterfaceImplementImplement,
 XosLibPngBase>
XosLibPngStructAttachedExtendExtend;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngStructAttachedExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<png_structp, int, 0, 
 XosLibPngStructAttachedInterface, 
 XosLibPngStructAttachedExtendExtend>
XosLibPngStructAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngStructAttached
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngStructAttached
: virtual public XosLibPngStructAttachedInterface,
  public XosLibPngStructAttachedExtend
{
public:
    typedef XosLibPngStructAttachedInterface Implements;
    typedef XosLibPngStructAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngStructAttached
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngStructAttached
    (tAttachedTo attached=vUnattached,
     bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngStructAttached
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngStructAttached()
    {
    }
#else // !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGSTRUCTATTACHED_HPP) || defined(XOSLIBPNGSTRUCTATTACHED_MEMBERS_ONLY) 
        


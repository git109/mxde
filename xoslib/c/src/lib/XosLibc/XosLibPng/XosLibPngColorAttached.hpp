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
///   File: XosLibPngColorAttached.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGCOLORATTACHED_HPP) || defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGCOLORATTACHED_HPP) && !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY)
#define _XOSLIBPNGCOLORATTACHED_HPP
#endif // !defined(_XOSLIBPNGCOLORATTACHED_HPP) && !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY)
#include "XosLibPngInterfaceBase.hpp"
#include "XosLibPngBase.hpp"
#include "XosAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngColorAttachedInterface
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<png_colorp, int, 0, XosLibPngInterfaceBase>
XosLibPngColorAttachedInterface;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngColorAttachedExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<png_colorp, int, 0,
 XosLibPngColorAttachedInterface,
 XosLibPngBase>
XosLibPngColorAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngColorAttached
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngColorAttached
: public XosLibPngColorAttachedExtend
{
public:
    typedef XosLibPngColorAttachedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngColorAttached
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngColorAttached
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
#else // !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGCOLORATTACHED_HPP) || defined(XOSLIBPNGCOLORATTACHED_MEMBERS_ONLY) 
        


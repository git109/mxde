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
///   File: XosLibPngColor.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGCOLOR_HPP) || defined(XOSLIBPNGCOLOR_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGCOLOR_HPP) && !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY)
#define _XOSLIBPNGCOLOR_HPP
#endif // !defined(_XOSLIBPNGCOLOR_HPP) && !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY)
#include "XosLibPngColorInterface.hpp"
#include "XosLibPngColorAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngColorImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngColorInterface
XosLibPngColorImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngColorExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngColorAttached
XosLibPngColorExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngColor
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngColor
: virtual public XosLibPngColorImplement,
  public XosLibPngColorExtend
{
public:
    typedef XosLibPngColorImplement Implements;
    typedef XosLibPngColorExtend Extends;

    XosLibPngStructInterface& m_pngStruct;
    XosLibPngInfoInterface& m_pngInfo;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngColor
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngColor
    (XosLibPngStructInterface& pngStruct,
     XosLibPngInfoInterface& pngInfo,
     tAttachedTo attached=vUnattached)
    : Extends(attached),
      m_pngStruct(pngStruct),
      m_pngInfo(pngInfo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngColor
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngColor()
    {
    }
#else // !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLOR_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGCOLOR_HPP) || defined(XOSLIBPNGCOLOR_MEMBERS_ONLY) 
        


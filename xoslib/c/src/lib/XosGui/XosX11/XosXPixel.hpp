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
///   File: XosXPixel.hpp
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXPIXEL_HPP
#define _XOSXPIXEL_HPP

#include "XosXPixelAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixelImplement
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosXPixelAttachedImplement
XosXPixelImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXPixelExtend
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosXPixelAttached
XosXPixelExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXPixel
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXPixel
: virtual public XosXPixelImplement,
  public XosXPixelExtend
{
public:
    typedef XosXPixelImplement Implements;
    typedef XosXPixelExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXPixel
    ///
    ///       Author: $author$
    ///         Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosXPixel
    (tAttachedTo attached=vUnattached)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXPixel
    ///
    ///      Author: $author$
    ///        Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXPixel()
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXPIXEL_HPP 
        


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
///   File: XosPixel.hpp
///
/// Author: $author$
///   Date: 11/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSPIXEL_HPP) || defined(XOSPIXEL_MEMBERS_ONLY)
#if !defined(_XOSPIXEL_HPP) && !defined(XOSPIXEL_MEMBERS_ONLY)
#define _XOSPIXEL_HPP
#endif // !defined(_XOSPIXEL_HPP) && !defined(XOSPIXEL_MEMBERS_ONLY) 

#if !defined(XOSPIXEL_MEMBERS_ONLY)
#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosPixelImplement
///
///  Author: $author$
///    Date: 11/27/2011
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosPixelImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosPixelExtend
///
///  Author: $author$
///    Date: 11/27/2011
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosPixelExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosPixel
///
/// Author: $author$
///   Date: 11/27/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosPixel
: virtual public XosPixelImplement,
  public XosPixelExtend
{
public:
    typedef XosPixelImplement Implements;
    typedef XosPixelExtend Extends;

    typedef UINT tColorSample;
    typedef UINT tColorChannel;
    enum
    {
        XOS_COLOR_CHANNEL_RED,
        XOS_COLOR_CHANNEL_GREEN,
        XOS_COLOR_CHANNEL_BLUE,
        XOS_COLOR_CHANNEL_ALPHA,
        XOS_COLOR_CHANNELS
    };
    enum { XOS_COLOR_SAMPLE_SATURATED = -1 };
    static const tColorChannel vColorChannels = XOS_COLOR_CHANNELS;

    tColorChannel m_channel[vColorChannels];

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosPixel
    ///
    ///       Author: $author$
    ///         Date: 11/27/2011
    ///////////////////////////////////////////////////////////////////////
    XosPixel
    (tColorSample red=0,
     tColorSample green=0,
     tColorSample blue=0,
     tColorSample alpha=XOS_COLOR_SAMPLE_SATURATED)
    {
        m_channel[XOS_COLOR_CHANNEL_RED] = red;
        m_channel[XOS_COLOR_CHANNEL_GREEN] = green;
        m_channel[XOS_COLOR_CHANNEL_BLUE] = blue;
        m_channel[XOS_COLOR_CHANNEL_ALPHA] = alpha;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosPixel
    ///
    ///      Author: $author$
    ///        Date: 11/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosPixel()
    {
    }
#else // !defined(XOSPIXEL_MEMBERS_ONLY) 
#endif // !defined(XOSPIXEL_MEMBERS_ONLY) 

#if !defined(XOSPIXEL_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSPIXEL_MEMBERS_ONLY) 
#endif // !defined(XOSPIXEL_MEMBERS_ONLY) 

#endif // !defined(_XOSPIXEL_HPP) || defined(XOSPIXEL_MEMBERS_ONLY) 
        


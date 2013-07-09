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
///   File: XosXColor.hpp
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXCOLOR_HPP
#define _XOSXCOLOR_HPP

#include "XosXColormap.hpp"
#include "XosXPixelAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColorImplement
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosXPixelAllocatedAttachedImplement
XosXColorImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColorExtend
///
///  Author: $author$
///    Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
typedef XosXPixelAllocatedAttached
XosXColorExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXColor
///
/// Author: $author$
///   Date: 4/25/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXColor
: virtual public XosXColorImplement,
  public XosXColorExtend
{
public:
    typedef XosXColorImplement Implements;
    typedef XosXColorExtend Extends;

    Colormap m_xColormap;
    Display* m_xDisplay;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXColor
    ///
    ///       Author: $author$
    ///         Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    XosXColor
    (tAttachedTo attached=vUnattached,
     bool isAllocated=false)
    : Extends(attached, isAllocated),
      m_xColormap(None),
      m_xDisplay(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXColor
    ///
    ///      Author: $author$
    ///        Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXColor()
    {
        XosError error;
        if ((error = Freed()))
            throw (error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AllocateRGB8
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError AllocateRGB8
    (Display* xDisplay, Colormap xColormap,
     uint8_t r, uint8_t g, uint8_t b,
     bool onlyFreed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        XColor xColor;
        Pixel detached;
        Status success;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        RGB8ToXColor(xColor, r,g,b);

        if ((xDisplay) && (None != (xColormap)))
        if ((success = XAllocColor
            (xDisplay, xColormap, &xColor)))
        {
            m_xDisplay = xDisplay;
            m_xColormap = xColormap;
            Attach(detached = xColor.pixel, true);
            error = XOS_ERROR_NONE;
        }
        else
        {   XOS_DBE(("()\n failed on XAllocColor()\n")); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Free
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Free
    (bool onlyAllocatred=false)
    {
        XosError error = XOS_ERROR_FAILED;
        Pixel detached;
        int err;

        if ((detached = Detach()))
        {
            if ((m_xDisplay) && (None != (m_xColormap)))
            {
                XFreeColors(m_xDisplay, m_xColormap, &detached, 1, 0);
                error = XOS_ERROR_NONE;
            }
        }
        else
        if ((onlyAllocatred))
            error = XOS_ERROR_FAILED;
        else
        error = XOS_ERROR_NONE;

        m_xColormap = None;
        m_xDisplay = 0;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Lookup
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Lookup
    (Display* xDisplay, Colormap xColormap,
     const char* colorName,
     bool onlyFreed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        XColor xColorDefinition;
        XColor xColor;
        Pixel detached;
        Status success;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        if ((xDisplay) && (None != (xColormap)) && (colorName))
        if ((success = XLookupColor
            (xDisplay, xColormap, colorName,
             &xColorDefinition, &xColor)))
        {
            m_xDisplay = xDisplay;
            m_xColormap = xColormap;
            Attach(detached = xColor.pixel);
            error = XOS_ERROR_NONE;
        }
        else
        {   XOS_DBE(("()\n failed on XLookupColor()\n")); }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: QueryRGB8
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError QueryRGB8
    (Display* xDisplay, Colormap xColormap,
     uint8_t r, uint8_t g, uint8_t b,
     bool onlyFreed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        XColor xColor;
        Pixel detached;
        int err;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        RGB8ToXColor(xColor, r,g,b);

        if ((xDisplay) && (None != (xColormap)))
        {
            XQueryColor(xDisplay, xColormap, &xColor);
            if ((xColor.pixel)) {
                m_xDisplay = xDisplay;
                m_xColormap = xColormap;
                Attach(detached = xColor.pixel);
                error = XOS_ERROR_NONE;
            }
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachWhiteOfScreen
    ///
    ///    Author: $author$
    ///      Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError AttachWhiteOfScreen(Screen* xScreen, bool onlyFreed=false) 
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        if ((xScreen)) {
            Attach(XWhitePixelOfScreen(xScreen));
            error = XOS_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachBlackOfScreen
    ///
    ///    Author: $author$
    ///      Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError AttachBlackOfScreen(Screen* xScreen, bool onlyFreed=false) 
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        if ((xScreen)) {
            Attach(XBlackPixelOfScreen(xScreen));
            error = XOS_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: RGB8ToXColor
    ///
    ///    Author: $author$
    ///      Date: 4/25/2012
    ///////////////////////////////////////////////////////////////////////
    inline void RGB8ToXColor
    (XColor& color,
     uint8_t r, uint8_t g, uint8_t b) const
    {
        unsigned long iL = (1 << (16))-1;
        unsigned short iS = (1 << (8))-1;
        unsigned short rS = (unsigned short)((iL*r)/iS);
        unsigned short gS = (unsigned short)((iL*g)/iS);
        unsigned short bS = (unsigned short)((iL*b)/iS);

        memset(&color, 0, sizeof(XColor));
        color.red = rS;
        color.green = gS;
        color.blue = bS;
    }
    inline operator Pixel() const {
        return m_attached;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXCOLOR_HPP 
        


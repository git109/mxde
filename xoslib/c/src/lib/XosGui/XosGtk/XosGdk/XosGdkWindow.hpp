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
///   File: XosGdkWindow.hpp
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGDKWINDOW_HPP
#define _XOSGDKWINDOW_HPP

#include "XosGdkWindowAttached.hpp"
#include "XosGdkScreenAttached.hpp"
#include "XosGdkDisplayAttached.hpp"
#include "XosGdkColormapAttached.hpp"
#include "XosGdkGCAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkWindowImplement
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosGdkWindowCreatedAttachedImplement
XosGdkWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGdkWindowExtend
///
///  Author: $author$
///    Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
typedef XosGdkWindowCreatedAttached
XosGdkWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGdkWindow
///
/// Author: $author$
///   Date: 5/6/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosGdkWindow
: virtual public XosGdkWindowImplement,
  public XosGdkWindowExtend
{
public:
    typedef XosGdkWindowImplement Implements;
    typedef XosGdkWindowExtend Extends;

    XosGdkDisplayAttached m_display;
    XosGdkScreenAttached m_screen;
    XosGdkColormapCreatedAttached m_colormap;
    XosGdkGCCreatedAttached m_gc;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosGdkWindow
    ///
    ///       Author: $author$
    ///         Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkWindow
    (GdkDisplay* gdkDisplay=0, GdkScreen* gdkScreen=0, 
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     GdkColormap* gdkColormap=0, GdkGC* gdkGC=0,
     bool isCreated=false,
     bool colormapIsCreated=false,
     bool gcIsCreated=false)
    : Extends(attached, isCreated),
      m_display(gdkDisplay),
      m_screen(gdkScreen),
      m_colormap(gdkColormap, colormapIsCreated),
      m_gc(gdkGC, gcIsCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosGdkWindow
    ///
    ///      Author: $author$
    ///        Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosGdkWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (GdkDisplay* gdkDisplay, GdkScreen* gdkScreen,
     tAttachedTo detached, GdkColormap* gdkColormap, GdkGC* gdkGC,
     bool isCreated=false, bool colormapIsCreated=false, bool gcIsCreated=false)
    {
        m_display.Attach(gdkDisplay);
        m_screen.Attach(gdkScreen);
        m_colormap.Attach(gdkColormap, colormapIsCreated);
        m_gc.Attach(gdkGC, gcIsCreated);
        Extends::Attach(detached, isCreated);
        return m_attached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 5/6/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach
    (GdkDisplay*& gdkDisplay, GdkScreen*& gdkScreen, 
     GdkColormap*& gdkColormap, GdkGC*& gdkGC)
    {
        tAttachedTo detached = Extends::Detach();
        gdkDisplay = m_display.Detach();
        gdkScreen = m_screen.Detach();
        gdkColormap = m_colormap.Detach();
        gdkGC = m_gc.Detach();
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: FillRectangleRGB8
    ///
    ///    Author: $author$
    ///      Date: 5/7/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError FillRectangleRGB8
    (uint8_t red, uint8_t green, uint8_t blue,
     int x,int y, int width,int height)
    {
        XosError error = XOS_ERROR_FAILED;
        GdkColor gdkColor = {0, red*256, green*256, blue*256};
        GdkDisplay* gdkDisplay;
        GdkScreen* gdkScreen; 
        GdkColormap* gdkColormap;
        GdkWindow* gdkWindow;
        GdkGC* gdkGC;

        if ((gdkDisplay = m_display.Attached()) 
            && (gdkScreen = m_screen.Attached()) 
            && (gdkWindow = Attached())
            && (gdkColormap = m_colormap.Attached())
            && (gdkGC = m_gc.Attached()))
        {
            if ((gdk_colormap_alloc_color
                (gdkColormap, &gdkColor, TRUE, TRUE)))
            {
                gdk_gc_set_foreground(gdkGC, &gdkColor);

                XOS_DBT(("() gdk_draw_rectangle(...,%d,%d, %d,%d)...\n", x,y, width,height));

                gdk_draw_rectangle
                (gdkWindow, gdkGC, TRUE, x,y, width,height);

                gdk_colormap_free_colors
                (gdkColormap, &gdkColor, 1);

                error = XOS_ERROR_NONE;
            }
        }
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGDKWINDOW_HPP 
        


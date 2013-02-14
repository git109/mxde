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
///   File: XosGtkWidget.hpp
///
/// Author: $author$
///   Date: 5/7/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGTKWIDGET_HPP
#define _XOSGTKWIDGET_HPP

#include "XosGtkWidgetAttached.hpp"
#include "XosGdkWindow.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosGtkWidgetImplement
///
///  Author: $author$
///    Date: 5/7/2012
///////////////////////////////////////////////////////////////////////
typedef XosGtkWidgetCreatedAttachedImplement
XosGtkWidgetImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosGtkWidgetExtend
///
///  Author: $author$
///    Date: 5/7/2012
///////////////////////////////////////////////////////////////////////
typedef XosGtkWidgetCreatedAttached
XosGtkWidgetExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosGtkWidget
///
/// Author: $author$
///   Date: 5/7/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosGtkWidget
: virtual public XosGtkWidgetImplement,
  public XosGtkWidgetExtend
{
public:
    typedef XosGtkWidgetImplement Implements;
    typedef XosGtkWidgetExtend Extends;

    XosGdkWindow m_window;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosGtkWidget
    ///
    ///       Author: $author$
    ///         Date: 5/7/2012
    ///////////////////////////////////////////////////////////////////////
    XosGtkWidget
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosGtkWidget
    ///
    ///      Author: $author$
    ///        Date: 5/7/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosGtkWidget()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 5/7/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (tAttachedTo detached, bool isCreated=false)
    {
        tAttachedTo attached = Extends::Attach(detached, isCreated);
        GdkDisplay* gdkDisplay=0;
        GdkScreen* gdkScreen=0;
        GdkWindow* gdkWindow=0;
        GdkColormap* gdkColormap = 0;
        GdkGC* gdkGC=0;
        GtkStyle* gtkStyle = 0;
        if ((attached))
        {
            gdkDisplay = gtk_widget_get_display(attached);
            gdkScreen = gtk_widget_get_screen(attached);
            gdkWindow = gtk_widget_get_window(attached);

            if ((gdkScreen))
                gdkColormap = gdk_screen_get_default_colormap(gdkScreen);

            if ((gtkStyle = gtk_widget_get_style(attached)))
                gdkGC = gtkStyle->fg_gc[GTK_STATE_NORMAL];
        }
        m_window.Attach(gdkDisplay, gdkScreen, gdkWindow, gdkColormap, gdkGC);
        return m_attached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 5/7/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach()
    {
        tAttachedTo detached = Extends::Detach();
        GdkDisplay* gdkDisplay=0;
        GdkScreen* gdkScreen=0;
        GdkWindow* gdkWindow=0;
        GdkColormap* gdkColormap = 0;
        GdkGC* gdkGC=0;
        m_window.Detach(gdkDisplay, gdkScreen, gdkColormap, gdkGC);
        return detached;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGTKWIDGET_HPP 
        


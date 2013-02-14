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
///   File: XosXColormap.hpp
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXCOLORMAP_HPP
#define _XOSXCOLORMAP_HPP

#include "XosXColormapAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColormapImplement
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosXColormapCreatedAttachedImplement
XosXColormapImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXColormapExtend
///
///  Author: $author$
///    Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
typedef XosXColormapCreatedAttached
XosXColormapExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXColormap
///
/// Author: $author$
///   Date: 4/24/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXColormap
: virtual public XosXColormapImplement,
  public XosXColormapExtend
{
public:
    typedef XosXColormapImplement Implements;
    typedef XosXColormapExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXColormap
    ///
    ///       Author: $author$
    ///         Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    XosXColormap
    (Display* xDisplayAttached=0, 
     tAttachedTo attached=vUnattached,
     bool isCreated=false)
    : Extends(xDisplayAttached, attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXColormap
    ///
    ///      Author: $author$
    ///        Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXColormap()
    {
        XosError error;
        if ((GetIsCreated()))
        if ((error = Destroy(true)))
            throw (error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (Display* xDisplay, Window xWindow, 
     Visual* xVisual, int allocEntries=AllocAll,
     bool onlyDestroyed=false) 
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        Colormap detached;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if (None != (detached = XCreateColormap
            (xDisplay, xWindow, xVisual, allocEntries)))
        {
            Attach(xDisplay, detached);
            error = XOS_ERROR_NONE;
        }
        else
        XOS_DBE(("() failed on XCreateColormap()\n"));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy
    (bool onlyCreated=false) 
    {
        XosError error = XOS_ERROR_FAILED;
        Display* xDisplay;
        Colormap detached;
        int err;

        if ((detached = Detach(xDisplay)) != vUnattached)
        {
            if ((err = XFreeColormap(xDisplay, detached)))
            {   XOS_DBE(("() failed err = %d on XFreeColormap()\n", err)); }
            //
            // Always seem to get error code...
            //
            //else
            error = XOS_ERROR_NONE;
        }
        else
        if (!(onlyCreated))
            error = XOS_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachDefault
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual Colormap AttachDefault
    (Display* xDisplay, bool onlyDestroyed=false)
    {
        Colormap detached = None;
        unsigned int screen;
        if ((xDisplay))
            detached = AttachDefaultOfScreen
            (xDisplay, (screen = (DefaultScreen(xDisplay))), onlyDestroyed);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachDefaultOfScreen
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual Colormap AttachDefaultOfScreen
    (Display* xDisplay, unsigned int screen, bool onlyDestroyed=false)
    {
        Colormap detached = None;
        Screen* xScreen;

        if ((xDisplay))
        if ((xScreen = XScreenOfDisplay(xDisplay, screen)))
            detached = AttachDefaultOfScreen(xDisplay, xScreen, onlyDestroyed);
        else
        XOS_DBE(("() failed on XScreenOfDisplay()\n"));
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachDefaultOfScreen
    ///
    ///    Author: $author$
    ///      Date: 4/24/2012
    ///////////////////////////////////////////////////////////////////////
    virtual Colormap AttachDefaultOfScreen
    (Display* xDisplay, Screen* xScreen, bool onlyDestroyed=false)
    {
        Colormap detached = None;
        XosError error;

        if ((error = Destroyed(onlyDestroyed)))
            return None;

        if ((xDisplay) && (xScreen))
        if (None != (detached = XDefaultColormapOfScreen(xScreen)))
            Attach(xDisplay, detached);
        else
        XOS_DBE(("() failed on XDefaultColormapOfScreen()\n"));
        return detached;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXCOLORMAP_HPP 
        


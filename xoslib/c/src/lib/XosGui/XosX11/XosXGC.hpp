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
///   File: XosXGC.hpp
///
/// Author: $author$
///   Date: 4/26/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXGC_HPP
#define _XOSXGC_HPP
#include "XosXGCAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXGCImplement
///
///  Author: $author$
///    Date: 4/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosXGCCreatedAttachedImplement
XosXGCImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXGCExtend
///
///  Author: $author$
///    Date: 4/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosXGCCreatedAttached
XosXGCExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXGC
///
/// Author: $author$
///   Date: 4/26/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXGC
: virtual public XosXGCImplement,
  public XosXGCExtend
{
public:
    typedef XosXGCImplement Implements;
    typedef XosXGCExtend Extends;

    Display* m_xDisplay;
    Drawable m_xDrawable;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXGC
    ///
    ///       Author: $author$
    ///         Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosXGC
    (Display* xDisplay=0,
     Drawable xDrawable=None,
     tAttachedTo attached=vUnattached,
     bool isCreated=false)
    : Extends(attached, isCreated),
      m_xDisplay(xDisplay),
      m_xDrawable(xDrawable)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXGC
    ///
    ///      Author: $author$
    ///        Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXGC()
    {
        XosError error;
        if ((m_isCreated))
        if ((error = Destroy()))
            throw (error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (Display* xDisplay, Drawable xDrawable, 
     unsigned long xGCValueMask=0, 
     XGCValues* xGCValues=0, 
     bool onlyDestroyed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        tAttachedTo detached;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if ((xDisplay) && (xDrawable != None))
        if ((detached = XCreateGC
            (xDisplay, xDrawable, xGCValueMask, xGCValues)) != vUnattached)
        {
            Attach(xDisplay, xDrawable, detached);
            error = XOS_ERROR_NONE;
        }
        else
        { XOS_DBE(("() failed on XCreateGC()\n")); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy
    (bool onlyCreated=false)
    {
        XosError error = XOS_ERROR_FAILED;
        Display* xDisplay;
        Drawable xDrawable;
        tAttachedTo detached;

        if ((detached = Detach(xDisplay, xDrawable)))
        {
            XFreeGC(xDisplay, detached);
            error = XOS_ERROR_NONE;
        }
        else
        if (!(onlyCreated))
            error = XOS_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: FillRectangle
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError FillRectangle
    (unsigned long colorPixel,
     int x, int y,
     unsigned int width,
     unsigned int height)
    {
        XosError error = XOS_ERROR_FAILED;
        if (!(error = SetForeground(colorPixel)))
            error = FillRectangle(x,y, width,height);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: FillRectangle
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError FillRectangle
    (int x, int y,
     unsigned int width,
     unsigned int height)
    {
        XosError error = XOS_ERROR_FAILED;

        if ((m_xDisplay) && (m_xDrawable != None) && (m_attached != vUnattached))
        {
            XFillRectangle
            (m_xDisplay, m_xDrawable, m_attached, x,y, width,height);
            error = XOS_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetForeground
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetForeground
    (unsigned long toColor)
    {
        XosError error = XOS_ERROR_FAILED;

        if ((m_xDisplay) && (m_attached != vUnattached))
        {
            XSetForeground(m_xDisplay, m_attached, toColor);
            error = XOS_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetForeground
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned long GetForeground() const
    {
        unsigned long color = 0;
        return color;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetBackground
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetBackground
    (unsigned long toColor)
    {
        XosError error = XOS_ERROR_FAILED;

        if ((m_xDisplay) && (m_attached != vUnattached))
        {
            XSetBackground(m_xDisplay, m_attached, toColor);
            error = XOS_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetBackground
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned long GetBackground() const
    {
        unsigned long color = 0;
        return color;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Attach
    (Display* xDisplay, Drawable xDrawable, 
     tAttachedTo detached, bool isCreated=false)
    {
        tAttachedTo attached = 0;
        if ((xDisplay) && (detached != vUnattached))
        {
            m_xDisplay = xDisplay;
            m_xDrawable = xDrawable;
            attached = (m_attached = detached);
            m_isCreated = isCreated;
        }
        return attached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 4/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo Detach
    (Display*& xDisplay, Drawable& xDrawable)
    {
        tAttachedTo detached = m_attached;
        xDisplay = m_xDisplay;
        xDrawable = m_xDrawable;
        m_xDisplay = 0;
        m_xDrawable = None;
        m_attached = vUnattached;
        m_isCreated = false;
        return detached;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXGC_HPP 
        


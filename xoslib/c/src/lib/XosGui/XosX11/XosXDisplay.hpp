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
///   File: XosXDisplay.hpp
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXDISPLAY_HPP
#define _XOSXDISPLAY_HPP

#include "XosXDisplayAttached.hpp"
#include "XosXScreen.hpp"
#include "XosString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayImplement
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosXDisplayOpenedAttachedImplement
XosXDisplayImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXDisplayExtend
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosXDisplayOpenedAttached
XosXDisplayExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXDisplay
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXDisplay
: virtual public XosXDisplayImplement,
  public XosXDisplayExtend
{
public:
    typedef XosXDisplayImplement Implements;
    typedef XosXDisplayExtend Extends;

    XosXScreen m_screen;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXDisplay
    ///
    ///       Author: $author$
    ///         Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    XosXDisplay
    (Screen* screen=0,
     Display* attached=0,
     bool isOpen=false)
    : Extends(attached, isOpen),
      m_screen(attached, screen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXDisplay
    ///
    ///      Author: $author$
    ///        Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXDisplay()
    {
        XosError error;
        if ((error = Closed()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (const std::string name,
     bool onlyClosed=false)
    {
        XosError error = Open(name.c_str(), onlyClosed);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (const char* name,
     bool onlyClosed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        Display* detached;

        if ((error2 = Closed(onlyClosed)))
            return error2;
 
        if ((name))
        if ((detached = XOpenDisplay(name)))
        {
            m_screen.AttachDisplay(detached);
            Attach(detached, true);
            error = XOS_ERROR_NONE;
        }
        else
        XOS_DBE(("() failed on XOpenDisplay(\"%s\")", name));

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close
    (bool onlyOpen=false)
    {
        XosError error = XOS_ERROR_FAILED;
        Display* detached;
        bool isOpen;

        if ((detached = Detach(isOpen)))
        {
            XCloseDisplay(detached);
            error = XOS_ERROR_NONE;
        }
        else
        if (!(onlyOpen))
            error = XOS_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: RootWindowAttached
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual Window RootWindowAttached() const
    {
        Window xWindow = None;
        Screen* xScreen = 0;
        if ((xScreen = m_screen.Attached()))
            xWindow = XRootWindowOfScreen(xScreen);

        XOS_DBT(("() ...xWindow = 0x%x\n", xWindow));

        return xWindow;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ScreenAttached
    ///
    ///    Author: $author$
    ///      Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual Screen* ScreenAttached() const
    {
        Screen* xScreen = 0;
        xScreen = m_screen.Attached();
        return  xScreen;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXDISPLAY_HPP 
        


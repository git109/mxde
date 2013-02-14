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
///   File: XosXScreen.hpp
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXSCREEN_HPP
#define _XOSXSCREEN_HPP

#include "XosXScreenAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXScreenImplement
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosXScreenAttachedImplement
XosXScreenImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXScreenExtend
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosXScreenAttached
XosXScreenExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXScreen
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXScreen
: virtual public XosXScreenImplement,
  public XosXScreenExtend
{
public:
    typedef XosXScreenImplement Implements;
    typedef XosXScreenExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXScreen
    ///
    ///       Author: $author$
    ///         Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    XosXScreen
    (Display* xDisplay=0,
     tAttachedTo attached=(tAttachedTo)(vUnattached))
    : Extends(xDisplay, attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXScreen
    ///
    ///      Author: $author$
    ///        Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXScreen()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachDisplay
    ///
    ///    Author: $author$
    ///      Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo AttachDisplay
    (Display* xDisplay, int screenNumber=-1)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        tAttachedTo detached;

        if (!(xDisplay))
            return attached;

        if (0 > (screenNumber))
            screenNumber =  XDefaultScreen(xDisplay);

        if ((detached = XScreenOfDisplay(xDisplay, screenNumber)))
            attached = Attach(xDisplay, detached);
        else
        XOS_DBE(("() failed on XScreenOfDisplay(%p, %d)\n", xDisplay, screenNumber));

        return attached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Number
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Number() const
    {
        int number = -1;
        if ((m_attached))
            number = XScreenNumberOfScreen(m_attached);
        return number;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXSCREEN_HPP 

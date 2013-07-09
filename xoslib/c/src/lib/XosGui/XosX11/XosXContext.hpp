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
///   File: XosXContext.hpp
///
/// Author: $author$
///   Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXCONTEXT_HPP
#define _XOSXCONTEXT_HPP

#include "XosXContextAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXContextImplement
///
///  Author: $author$
///    Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
typedef XosXContextCreatedAttachedImplement
XosXContextImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXContextExtend
///
///  Author: $author$
///    Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
typedef XosXContextCreatedAttached
XosXContextExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXContext
///
/// Author: $author$
///   Date: 5/22/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXContext
: virtual public XosXContextImplement,
  public XosXContextExtend
{
public:
    typedef XosXContextImplement Implements;
    typedef XosXContextExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXContext
    ///
    ///       Author: $author$
    ///         Date: 5/22/2012
    ///////////////////////////////////////////////////////////////////////
    XosXContext
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
      bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Save
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosError Save(Display& xDisplay, XID xID, XPointer data)
    {
        XosError error = XOS_ERROR_FAILED;
        XSaveContext(&xDisplay, xID, m_attached, data);
        error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Delete
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosError Delete(Display& xDisplay, XID xID)
    {
        XosError error = XOS_ERROR_FAILED;
        XDeleteContext(&xDisplay, xID, m_attached);
        error = XOS_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Find
    ///
    ///    Author: $author$
    ///      Date: 5/22/2012
    ///////////////////////////////////////////////////////////////////////
    XPointer Find(Display& xDisplay, XID xID)
    {
        XPointer found = 0;
        int err;
        if ((err = XFindContext(&xDisplay, xID, m_attached, &found)))
        { XOS_DBT(("() returned %d on XFindContext(%p, %ul, %d, ...) found=%p \n", (void*)(&xDisplay), xID, m_attached, (void*)(found))); }
        return found;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: CreateUnique
    ///
    ///    Author: $author$
    ///      Date: 5/22/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError CreateUnique
    (bool onlyDestroyed=false)
    {
        XosError error;
        tAttachedTo detached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        detached = XUniqueContext();
        Attach(detached, true);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/22/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy
    (bool onlyCreated=false)
    {
        bool isCreated = false;
        tAttachedTo detached = Detach(isCreated);
        XosError error = XOS_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXCONTEXT_HPP 

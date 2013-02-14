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
///   File: XosXAtom.hpp
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXATOM_HPP
#define _XOSXATOM_HPP

#include "XosXAtomAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXAtomImplement
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosXAtomCreatedAttachedImplement
XosXAtomImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXAtomExtend
///
///  Author: $author$
///    Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
typedef XosXAtomCreatedAttached
XosXAtomExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXAtom
///
/// Author: $author$
///   Date: 5/17/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXAtom
: virtual public XosXAtomImplement,
  public XosXAtomExtend
{
public:
    typedef XosXAtomImplement Implements;
    typedef XosXAtomExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXAtom
    ///
    ///       Author: $author$
    ///         Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    XosXAtom
    (Display* xDisplay=0,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
      bool isCreated=false)
    : Extends(xDisplay, attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXAtom
    ///
    ///      Author: $author$
    ///        Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXAtom()
    {
        XosError error;
        if ((error = Destroyed()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachIntern
    ///
    ///    Author: $author$
    ///      Date: 5/17/2012
    ///////////////////////////////////////////////////////////////////////
    virtual Atom AttachIntern
    (Display* xDisplay,
     const char* name, 
     Bool onlyExists = False,
     bool onlyDetached = false)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        tAttachedTo detached;
        XosError error;

        if (!(xDisplay) || !(name))
            return attached;

        if ((error = Destroyed(onlyDetached)))
            return attached;

        XOS_DBT(("() XInternAtom(%p, \"%s\", %s)...\n", xDisplay, name, (onlyExists)?("True"):("False")));

        if ((tAttachedTo)(vUnattached) != (detached = XInternAtom(xDisplay, name, onlyExists)))
            attached = Attach(xDisplay, detached);
        else
        XOS_DBE(("() failed on XInternAtom(%p, \"%s\", %s)\n", xDisplay, name, (onlyExists)?("True"):("False")));

        return attached;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXATOM_HPP 

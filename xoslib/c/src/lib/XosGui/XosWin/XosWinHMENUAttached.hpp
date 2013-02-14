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
///   File: XosWinHMENUAttached.hpp
///
/// Author: $author$
///   Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINHMENUATTACHED_HPP
#define _XOSWINHMENUATTACHED_HPP

#include "XosWinInterfaceBase.hpp"
#include "XosWinBase.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHMENUAttachedImplement
///
///  Author: $author$
///    Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<HMENU, INT, NULL, XosWinInterfaceBase>
XosWinHMENUAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHMENUAttachedExtend
///
///  Author: $author$
///    Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<HMENU, INT, NULL, XosWinHMENUAttachedImplement, XosWinBase>
XosWinHMENUAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinHMENUAttached
///
/// Author: $author$
///   Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinHMENUAttached
: virtual public XosWinHMENUAttachedImplement,
  public XosWinHMENUAttachedExtend
{
public:
    typedef XosWinHMENUAttachedImplement Implements;
    typedef XosWinHMENUAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinHMENUAttached
    ///
    ///       Author: $author$
    ///         Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinHMENUAttached
    (HMENU attached=NULL)
    : Extends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinHMENUAttached
    ///
    ///      Author: $author$
    ///        Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinHMENUAttached()
    {
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHMENUCreatedAttachedImplement
///
///  Author: $author$
///    Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedInterfaceT
<HMENU, INT, NULL, XosWinHMENUAttachedImplement>
XosWinHMENUCreatedAttachedImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinHMENUCreatedAttachedExtend
///
///  Author: $author$
///    Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<HMENU, INT, NULL, XosWinHMENUCreatedAttachedImplement, XosWinHMENUAttached>
XosWinHMENUCreatedAttachedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinHMENUCreatedAttached
///
/// Author: $author$
///   Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinHMENUCreatedAttached
: virtual public XosWinHMENUCreatedAttachedImplement,
  public XosWinHMENUCreatedAttachedExtend
{
public:
    typedef XosWinHMENUCreatedAttachedImplement Implements;
    typedef XosWinHMENUCreatedAttachedExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinHMENUCreatedAttached
    ///
    ///       Author: $author$
    ///         Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinHMENUCreatedAttached
    (HMENU attached=NULL,
     bool isCreated=false)
    : Extends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinHMENUCreatedAttached
    ///
    ///      Author: $author$
    ///        Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinHMENUCreatedAttached()
    {
        XosError error;
        if ((error = Destroyed()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
    {
        XosError error = XOS_ERROR_FAILED;
        HMENU detached;

        if ((error = Destroyed()))
            return error;

        if ((detached = CreateMenu()))
            Attach(detached, true);
        else
        error = XOS_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy(bool onlyCreated=false)
    {
        XosError error = XOS_ERROR_NONE;
        HMENU detached;

        if ((detached = Detach()))
        if (!(DestroyMenu(detached)))
            error = XOS_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: InsertItem
    ///
    ///    Author: $author$
    ///      Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError InsertItem
    (UINT uItem, BOOL fByPosition, MENUITEMINFO& mii)
    {
        XosError error = XOS_ERROR_FAILED;
        HMENU attached;

        if ((attached = Attached()))
        if ((InsertMenuItem(attached, uItem, fByPosition, &mii)))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: InsertItemsL
    ///
    ///    Author: $author$
    ///      Date: 2/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError InsertItemsL
    (UINT uItem, BOOL fByPosition, MENUITEMINFO* mii,...)
    {
        XosError error = XOS_ERROR_FAILED;
        va_list va;
        va_start(va, mii);
        if ((mii))
        if (!(error = InsertItem(uItem, fByPosition, *mii)))
            error = InsertItemsV(++uItem, fByPosition, va);
        va_end(va);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: InsertItemsV
    ///
    ///    Author: $author$
    ///      Date: 2/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError InsertItemsV
    (UINT uItem, BOOL fByPosition, va_list va)
    {
        XosError error = XOS_ERROR_NONE;
        MENUITEMINFO* mii;
        while ((mii = va_arg(va, MENUITEMINFO*)))
        {
            if ((error = InsertItem(uItem, fByPosition, *mii)))
                break;
            ++uItem;
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINHMENUATTACHED_HPP 
        


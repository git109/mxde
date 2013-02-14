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
///   File: XosMutexBase.hpp
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMUTEXBASE_HPP
#define _XOSMUTEXBASE_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"
#include "XosPlatform_time.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosMutexBaseImplement
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosMutexBaseImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosMutexBaseExtend
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosMutexBaseExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosMutexBase
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosMutexBase
: virtual public XosMutexBaseImplement,
  public XosMutexBaseExtend
{
public:
    typedef XosMutexBaseImplement Implements;
    typedef XosMutexBaseExtend Extends;
    enum
    {
        XOS_ERROR_TIMEDOUT = XOS_NEXT_ERROR,
        XOS_ERROR_DEADLOCK,
        XOS_ERROR_AGAIN,
    };
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosMutexBase
    ///
    ///       Author: $author$
    ///         Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosMutexBase
    (bool create=false,
     bool initiallyLocked=false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosMutexBase
    ///
    ///      Author: $author$
    ///        Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosMutexBase()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create
    (bool initiallyLocked=false,
     bool onlyDestroyed=false)
    {
        bool isSuccess = true;
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Destroy
    (bool onlyCreated=false)
    {
        bool isSuccess = true;
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Lock
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Lock()
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Lock
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Lock
    (mseconds_t waitMilliseconds)
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TryLock
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TryLock()
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Unlock
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Unlock()
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMUTEXBASE_HPP 
        


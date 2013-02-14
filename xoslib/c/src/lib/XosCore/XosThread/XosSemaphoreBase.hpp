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
///   File: XosSemaphoreBase.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSSEMAPHOREBASE_HPP
#define _XOSSEMAPHOREBASE_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"
#include "XosPlatform_time.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosSemaphoreBaseImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosSemaphoreBaseImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosSemaphoreBaseExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosSemaphoreBaseExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosSemaphoreBase
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosSemaphoreBase
: virtual public XosSemaphoreBaseImplement,
  public XosSemaphoreBaseExtend
{
public:
    typedef XosSemaphoreBaseImplement Implements;
    typedef XosSemaphoreBaseExtend Extends;
    enum
    {
        XOS_ERROR_TIMEDOUT = XOS_NEXT_ERROR,
        XOS_ERROR_INTERRUPTED,
        XOS_ERROR_AGAIN,
    };

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosSemaphoreBase
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosSemaphoreBase
    (bool create=false,
     int initiallyReleased=0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosSemaphoreBase
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosSemaphoreBase()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create
    (int initiallyReleased=0,
     bool onlyDestroyed=false)
    {
        bool isSuccess = false;
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Destroy
    (bool onlyCreated=false)
    {
        bool isSuccess = false;
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Acquire
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Acquire
    (mseconds_t waitMilliseconds)
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Acquire
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Acquire()
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TryAcquire
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TryAcquire()
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Release
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Release
    (int count=1)
    {
        XosError error = XOS_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSSEMAPHOREBASE_HPP 
        


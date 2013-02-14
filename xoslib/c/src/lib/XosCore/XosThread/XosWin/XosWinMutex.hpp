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
///   File: XosWinMutex.hpp
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINMUTEX_HPP
#define _XOSWINMUTEX_HPP

#include "XosWinSecurityAttributes.hpp"
#include "XosMutexBase.hpp"
#include "XosDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinMutexImplement
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosMutexBaseImplement
XosWinMutexImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinMutexExtend
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosMutexBase
XosWinMutexExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinMutex
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinMutex
: virtual public XosWinMutexImplement,
  public XosWinMutexExtend
{
public:
    typedef XosWinMutexImplement Implements;
    typedef XosWinMutexExtend Extends;

    HANDLE m_attached;
    bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinMutex
    ///
    ///       Author: $author$
    ///         Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinMutex
    (bool create=false,
     bool initiallyLocked=false)
    : m_attached(NULL),
      m_isCreated(false)
    {
        if ((create))
        if (!(Create(initiallyLocked)))
        {
            XosError error = XOS_ERROR_FAILED;
            XOS_DBE(("() failed on Create()\n"));
            throw (error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinMutex
    ///
    ///      Author: $author$
    ///        Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinMutex()
    {
        if ((m_isCreated))
        if (!(Destroy()))
        {
            XosError error = XOS_ERROR_FAILED;
            XOS_DBE(("() failed on Destroy()\n"));
            throw (error);
        }
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
        BOOL bInitialOwner = (initiallyLocked)?TRUE:FALSE;
        LPCTSTR lpName = NULL;
        SECURITY_ATTRIBUTES attr;
        XosWinSecurityAttributes sa(attr);

        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

        if (!(isSuccess = (m_isCreated = (0 != (m_attached = CreateMutex
            (&attr, bInitialOwner, lpName))))))
        {   XOS_DBE(("() failed on CreateMutex()\n")); }

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
        bool isSuccess = false;
        HANDLE detached;

        m_isCreated = false;

        if (!(detached = m_attached))
        if ((isSuccess = !(onlyCreated)))
            return true;

        m_attached = NULL;

        if (!(isSuccess = (FALSE != (CloseHandle(detached)))))
        {   XOS_DBE(("() failed on CloseHandle()\n")); }

        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Wait
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Wait
    (mseconds_t waitMilliseconds=-1)
    {
        XosError error = XOS_ERROR_FAILED;
        LONG lWaitMilliSeconds = (LONG)((0 > waitMilliseconds)?(INFINITE):(waitMilliseconds));
        DWORD result = 0;

        if ((m_attached))
        if (WAIT_OBJECT_0 == (result = WaitForSingleObject
            (m_attached, lWaitMilliSeconds)))
            error = XOS_ERROR_NONE;
        else
        if (WAIT_TIMEOUT == result)
        {
            XOS_DBT(("() timeout on WaitForSingleObject()\n"));
            error = XOS_ERROR_TIMEDOUT;
        }
        else
        XOS_DBE(("() failed on WaitForSingleObject()\n"));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Release
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Release()
    {
        XosError error = XOS_ERROR_FAILED;

        if ((m_attached))
        if ((ReleaseMutex(m_attached)))
            error = XOS_ERROR_NONE;
        else
        XOS_DBE(("() failed on ReleaseMutex()\n"));
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Lock
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Lock()
    {
        XosError error = Wait();
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
        XosError error = Wait(waitMilliseconds);
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
        XosError error = Wait(0);
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
        XosError error = Release();
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINMUTEX_HPP 
        


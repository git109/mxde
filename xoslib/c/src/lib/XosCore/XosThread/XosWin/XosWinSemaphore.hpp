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
///   File: XosWinSemaphore.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINSEMAPHORE_HPP
#define _XOSWINSEMAPHORE_HPP

#include "XosWinSecurityAttributes.hpp"
#include "XosSemaphoreBase.hpp"
#include "XosDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinSemaphoreImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosSemaphoreBaseImplement
XosWinSemaphoreImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinSemaphoreExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosSemaphoreBase
XosWinSemaphoreExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinSemaphore
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinSemaphore
: virtual public XosWinSemaphoreImplement,
  public XosWinSemaphoreExtend
{
public:
    typedef XosWinSemaphoreImplement Implements;
    typedef XosWinSemaphoreExtend Extends;

    HANDLE m_attached;
    bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinSemaphore
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinSemaphore
    (bool create=false,
     int initiallyReleased=0)
    : m_attached(NULL),
      m_isCreated(false)
    {
        if ((create))
        if (!(Create(initiallyReleased)))
        {
            XosError error = XOS_ERROR_FAILED;
            XOS_DBE(("() failed on Create()\n"));
            throw (error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinSemaphore
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinSemaphore()
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
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create
    (int initialCount, int maximumCount,
     bool onlyDestroyed=false)
    {
        bool isSuccess = false;
        LONG lInitialCount = (LONG)(initialCount);
        LONG lMaximumCount =(LONG)((0 > maximumCount)?(((ULONG)(-1))>>1):(maximumCount));
        LPCTSTR lpName = NULL;
        SECURITY_ATTRIBUTES attr;
        XosWinSecurityAttributes sa(attr);

        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

        if (!(isSuccess = (m_isCreated = (0 != (m_attached = CreateSemaphore
            (&attr, lInitialCount, lMaximumCount, lpName))))))
        {   XOS_DBE(("() failed on CreateSemaphore()\n")); }

        return isSuccess;
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
        isSuccess = Create(initiallyReleased, -1, onlyDestroyed);
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
    ///  Function: Acquire
    ///
    ///    Author: $author$
    ///      Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Acquire()
    {
        XosError error = Wait();
        return error;
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
        XosError error = Wait(waitMilliseconds);
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
        XosError error = Wait(0);
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
        XosError error = XOS_ERROR_FAILED;
        LONG lReleaseCount = (LONG)(count);
        LONG lPreviousCount = 0;

        if ((m_attached))
        if ((ReleaseSemaphore(m_attached, lReleaseCount, &lPreviousCount)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed on ReleaseSemaphore()\n")); }

        return error;
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
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINSEMAPHORE_HPP 
        


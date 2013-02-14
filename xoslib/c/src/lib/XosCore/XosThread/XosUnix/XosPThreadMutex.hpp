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
///   File: XosPThreadMutex.hpp
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPTHREADMUTEX_HPP
#define _XOSPTHREADMUTEX_HPP

#include "XosMutexBase.hpp"
#include "XosPlatform_pthread.hpp"
#include "XosDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosPThreadMutexImplement
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosMutexBaseImplement
XosPThreadMutexImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosPThreadMutexExtend
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosMutexBase
XosPThreadMutexExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosPThreadMutex
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosPThreadMutex
: virtual public XosPThreadMutexImplement,
  public XosPThreadMutexExtend
{
public:
    typedef XosPThreadMutexImplement Implements;
    typedef XosPThreadMutexExtend Extends;

    pthread_mutex_t m_mutex;
    pthread_mutexattr_t m_mutexAttr;
    bool m_isCreated;
    
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosPThreadMutex
    ///
    ///       Author: $author$
    ///         Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosPThreadMutex
    (bool create=false,
     bool initiallyLocked=false)
    : m_isCreated(false)
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
    ///  Destructor: ~XosPThreadMutex
    ///
    ///      Author: $author$
    ///        Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosPThreadMutex()
    {
        if (!(Destroy()))
        {
            XosError error = XOS_ERROR_FAILED;
            XOS_DBE(("() failed on Destroy()\n"));
            throw (error);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Init
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init
    (int mutexType=PTHREAD_MUTEX_RECURSIVE,
     int processShared=PTHREAD_PROCESS_PRIVATE,
     bool onlyDestroyed=false)
    {
        bool isSuccess = false;
        int err;
        
        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

	    if (!(err = pthread_mutexattr_init(&m_mutexAttr)))
	    {
            pthread_mutexattr_settype(&m_mutexAttr, mutexType);
            pthread_mutexattr_setpshared(&m_mutexAttr, processShared);

            if ((m_isCreated = !(err = pthread_mutex_init(&m_mutex, &m_mutexAttr))))
                return m_isCreated;
            else
            XOS_DBE(("() failed on pthread_mutex_init()\n"));

		    pthread_mutexattr_destroy(&m_mutexAttr);
	    }
        else
        XOS_DBE(("() failed on pthread_mutexattr_init()\n"));
        return isSuccess;
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
        bool isSuccess = false;
        XosError error;

        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

        if ((isSuccess = Init()))
        {
            if ((initiallyLocked))
            if (!(isSuccess = (0 != (error = TryLock()))))
                Destroy();
        }
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
        int err;

        if (!(m_isCreated))
            return !(onlyCreated);

        m_isCreated = false;

        if (!(isSuccess = !(err = pthread_mutex_destroy(&m_mutex))))
        {    XOS_DBE(("() failed on pthread_mutex_destroy()\n")); }

        if (!(isSuccess = !(err = pthread_mutexattr_destroy(&m_mutexAttr))))
        {    XOS_DBE(("() failed on pthread_mutexattr_destroy()\n")); }

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
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = pthread_mutex_lock(&m_mutex)))
            error = XOS_ERROR_NONE;
        else
        if ((EDEADLK) != err)
        {
            if ((EAGAIN) != err)
            {   XOS_DBE(("() failed (%d) on pthread_mutex_lock()\n", err)); }
            else
            {
                error = XOS_ERROR_AGAIN;
                XOS_DBE(("() failed (EAGAIN) on pthread_mutex_lock()\n"));
            }
        }
        else
        {
            error = XOS_ERROR_DEADLOCK;
            XOS_DBE(("() failed (EDEADLK) on pthread_mutex_lock()\n"));
        }
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
        XosError error = XOS_ERROR_FAILED;

        if ((m_isCreated))
        if (0 < (waitMilliseconds))
        {
            int err;
            struct timespec untilTime;
            if (!(err = clock_gettime(CLOCK_REALTIME, &untilTime)))
            {
                untilTime.tv_sec += waitMilliseconds/1000;
                untilTime.tv_nsec += (waitMilliseconds%1000)*1000;
                error = TimedLock(untilTime);
            }
            else
            {   XOS_DBE(("() failed on clock_gettime()\n")); }
        }
        else
        if (0 > (waitMilliseconds))
            error = TryLock();
        else
        error = Lock();

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
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = pthread_mutex_trylock(&m_mutex)))
            error = XOS_ERROR_NONE;
        else
        if ((EDEADLK) != err)
        {
            if ((EAGAIN) != err)
            {   XOS_DBE(("() failed (%d) on pthread_mutex_trylock()\n", err)); }
            else
            {
                error = XOS_ERROR_AGAIN;
                XOS_DBE(("() failed (EAGAIN) on pthread_mutex_trylock()\n"));
            }
        }
        else
        {
            error = XOS_ERROR_DEADLOCK;
            XOS_DBE(("() failed (EDEADLK) on pthread_mutex_trylock()\n"));
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TimedLock
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TimedLock
    (const struct timespec& untilTime)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = pthread_mutex_timedlock(&m_mutex, &untilTime)))
            error = XOS_ERROR_NONE;
        else
        if ((ETIMEDOUT) != err)
        {
            if ((EDEADLK) != err)
            {
                if ((EAGAIN) != err)
                {   XOS_DBE(("() failed (%d) on pthread_mutex_timedlock()\n", err)); }
                else
                {
                    error = XOS_ERROR_AGAIN;
                    XOS_DBE(("() failed (EAGAIN) on pthread_mutex_timedlock()\n"));
                }
            }
            else
            {
                error = XOS_ERROR_DEADLOCK;
                XOS_DBE(("() failed (EDEADLK) on pthread_mutex_timedlock()\n"));
            }
        }
        else
        {
            error = XOS_ERROR_TIMEDOUT;
            XOS_DBT(("() timed out on pthread_mutex_timedlock()\n"));
        }
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
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = pthread_mutex_unlock(&m_mutex)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on pthread_mutex_unlock()\n", err)); }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSPTHREADMUTEX_HPP 

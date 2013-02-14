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
///   File: XosPThreadSemaphore.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPTHREADSEMAPHORE_HPP
#define _XOSPTHREADSEMAPHORE_HPP

#include "XosSemaphoreBase.hpp"
#include "XosPlatform_semaphore.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosPThreadSemaphoreImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosSemaphoreBaseImplement
XosPThreadSemaphoreImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosPThreadSemaphoreExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosSemaphoreBase
XosPThreadSemaphoreExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosPThreadSemaphore
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosPThreadSemaphore
: virtual public XosPThreadSemaphoreImplement,
  public XosPThreadSemaphoreExtend
{
public:
    typedef XosPThreadSemaphoreImplement Implements;
    typedef XosPThreadSemaphoreExtend Extends;

    sem_t m_sem;
    bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosPThreadSemaphore
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosPThreadSemaphore
    (bool create=false,
     int initiallyReleased=0)
    : m_isCreated(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosPThreadSemaphore
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosPThreadSemaphore()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Init
    ///
    ///    Author: $author$
    ///      Date: 3/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init
    (int processShared=SEMAPHORE_PROCESS_PRIVATE,
     unsigned int initialCount=0,
     bool onlyDestroyed=false)
    {
        bool isSuccess = false;
        int err;
        
        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

        if (!(isSuccess = (m_isCreated = !(err = sem_init
            (&m_sem, processShared, initialCount)))))
        {   XOS_DBE(("() failed on sem_init()\n")); }

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
        int processShared=SEMAPHORE_PROCESS_PRIVATE;
        bool isSuccess = Init
        (processShared, initiallyReleased, onlyDestroyed);
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
        int err;

        if (!(m_isCreated))
            return !(onlyCreated);

        m_isCreated = false;

        if (!(isSuccess = !(err = sem_destroy(&m_sem))))
        {    XOS_DBE(("() failed on sem_destroy()\n")); }

        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Post
    ///
    ///    Author: $author$
    ///      Date: 3/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Post()
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = sem_post(&m_sem)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on sem_post()\n", err)); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Wait
    ///
    ///    Author: $author$
    ///      Date: 3/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Wait()
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = sem_wait(&m_sem)))
            error = XOS_ERROR_NONE;
        else
        if (EINTR == err)
        {
            error = XOS_ERROR_INTERRUPTED;
            XOS_DBT(("() interrupted on sem_wait()\n"));
        }
        else
        {   XOS_DBE(("() failed (%d) on sem_wait()\n", err)); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TryWait
    ///
    ///    Author: $author$
    ///      Date: 3/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TryWait()
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = sem_trywait(&m_sem)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on sem_trywait()\n", err)); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TimedWait
    ///
    ///    Author: $author$
    ///      Date: 3/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TimedWait
    (const struct timespec& untilTime)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        if (!(err = sem_timedwait(&m_sem, &untilTime)))
            error = XOS_ERROR_NONE;
        else
        if (ETIMEDOUT == err)
        {
            error = XOS_ERROR_TIMEDOUT;
            XOS_DBT(("() timed out on sem_timedwait()\n"));
        }
        else
        if (EINTR == err)
        {
            error = XOS_ERROR_INTERRUPTED;
            XOS_DBT(("() interrupted on sem_timedwait()\n"));
        }
        else
        {   XOS_DBE(("() failed (%d) on sem_timedwait()\n", err)); }

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
                error = TimedWait(untilTime);
            }
            else
            {   XOS_DBE(("() failed on clock_gettime()\n")); }
        }
        else
        if (0 > (waitMilliseconds))
            error = TryWait();
        else
        error = Wait();

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
        XosError error = Wait();
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
        XosError error = TryWait();
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
        int countRemain;

        if ((m_isCreated) && (0 < (countRemain = count)))
        do
        {
            if ((error = Post()))
            {
                if (1 < (count))
                {   XOS_DBE(("() failed on count %d\n", count-countRemain+1)); }
                return error;
            }
        }
        while (0 < (--countRemain));

        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSPTHREADSEMAPHORE_HPP 

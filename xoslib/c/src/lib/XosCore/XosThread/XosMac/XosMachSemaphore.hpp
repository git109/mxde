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
///   File: XosMachSemaphore.hpp
///
/// Author: $author$
///   Date: 4/9/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACHSEMAPHORE_HPP
#define _XOSMACHSEMAPHORE_HPP

#include "XosSemaphoreBase.hpp"
#include "XosPlatform_semaphore.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosMachSemaphoreImplement
///
///  Author: $author$
///    Date: 4/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosSemaphoreBaseImplement
XosMachSemaphoreImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosMachSemaphoreExtend
///
///  Author: $author$
///    Date: 4/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosSemaphoreBase
XosMachSemaphoreExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosMachSemaphore
///
/// Author: $author$
///   Date: 4/9/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosMachSemaphore
: virtual public XosMachSemaphoreImplement,
  public XosMachSemaphoreExtend
{
public:
    typedef XosMachSemaphoreImplement Implements;
    typedef XosMachSemaphoreExtend Extends;

    semaphore_t m_sem;
    bool m_isCreated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosMachSemaphore
    ///
    ///       Author: $author$
    ///         Date: 4/9/2012
    ///////////////////////////////////////////////////////////////////////
    XosMachSemaphore
    (bool create=false,
     int initiallyReleased=0)
    : m_isCreated(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosMachSemaphore
    ///
    ///      Author: $author$
    ///        Date: 4/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosMachSemaphore()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create
    (task_t task, sync_policy_t syncPolicy=SYNC_POLICY_FIFO, 
     int initialValue=0, bool onlyDestroyed=false)
    {
        bool isSuccess = false;
        kern_return_t err;

        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

        if (!(isSuccess = (m_isCreated = 
            (KERN_SUCCESS == (err = semaphore_create
             (task, &m_sem, syncPolicy, initialValue))))))
        {   XOS_DBE(("() failed on semaphore_create()\n")); }

        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Destroy
    (task_t task, bool onlyCreated=false)
    {
        bool isSuccess = false;
        kern_return_t err;

        if (!(m_isCreated))
            return !(onlyCreated);

        m_isCreated = false;

        if (!(isSuccess = (KERN_SUCCESS == (err = semaphore_destroy(task, m_sem)))))
        {    XOS_DBE(("() failed on semaphore_destroy()\n")); }

        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create
    (int initiallyReleased=0,
     bool onlyDestroyed=false)
    {
        sync_policy_t syncPolicy=SYNC_POLICY_FIFO;
        task_t task = mach_task_self();
        bool isSuccess = Create(task, syncPolicy, initiallyReleased, onlyDestroyed);
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Destroy
    (bool onlyCreated=false)
    {
        task_t task = mach_task_self();
        bool isSuccess = Destroy(task, onlyCreated);
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: TimedWait
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TimedWait(mach_timespec_t& waitTime)
    {
        XosError error = XOS_ERROR_FAILED;
        kern_return_t err;

        if ((m_isCreated))
        if (KERN_SUCCESS == (err = semaphore_timedwait(m_sem, waitTime)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on semaphore_timedwait()\n", err)); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Wait
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Wait()
    {
        XosError error = XOS_ERROR_FAILED;
        kern_return_t err;

        if ((m_isCreated))
        if (KERN_SUCCESS == (err = semaphore_wait(m_sem)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on semaphore_wait()\n", err)); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Signal
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Signal()
    {
        XosError error = XOS_ERROR_FAILED;
        kern_return_t err;

        if ((m_isCreated))
        if (KERN_SUCCESS == (err = semaphore_signal(m_sem)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on semaphore_signal()\n", err)); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SignalAll
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SignalAll()
    {
        XosError error = XOS_ERROR_FAILED;
        kern_return_t err;

        if ((m_isCreated))
        if (KERN_SUCCESS == (err = semaphore_signal_all(m_sem)))
            error = XOS_ERROR_NONE;
        else
        {   XOS_DBE(("() failed (%d) on semaphore_signal_all()\n", err)); }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: TryAcquire
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TryAcquire()
    {
        XosError error = XOS_ERROR_FAILED;
        mach_timespec_t waitTime;

        waitTime.tv_sec = 0;
        waitTime.tv_nsec = 0;
        error = TimedWait(waitTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Acquire
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Acquire(mseconds_t waitMilliseconds)
    {
        XosError error = XOS_ERROR_FAILED;
        mach_timespec_t waitTime;

        waitTime.tv_sec = waitMilliseconds/1000;
        waitTime.tv_nsec = (waitMilliseconds%1000)*1000;
        error = TimedWait(waitTime);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Acquire
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Acquire()
    {
        XosError error = Wait();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Release
    ///
    ///    Author: $author$
    ///      Date: 4/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Release(int count=1)
    {
        XosError error = XOS_ERROR_FAILED;
        int countRemain;

        if ((m_isCreated) && (0 < (countRemain = count)))
        do
        {
            if ((error = Signal()))
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

#endif // _XOSMACHSEMAPHORE_HPP 

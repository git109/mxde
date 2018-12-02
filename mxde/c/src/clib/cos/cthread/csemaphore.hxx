/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: csemaphore.hxx
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
#if !defined(_CSEMAPHORE_HXX) || defined(CSEMAPHORE_MEMBERS_ONLY)
#if !defined(_CSEMAPHORE_HXX) && !defined(CSEMAPHORE_MEMBERS_ONLY)
#define _CSEMAPHORE_HXX
#endif /* !defined(_CSEMAPHORE_HXX) && !defined(CSEMAPHORE_MEMBERS_ONLY) */

#if !defined(CSEMAPHORE_MEMBERS_ONLY)
#include "csemaphoreinterface.hxx"
#include "csemaphoreattached.hxx"
#include "cdebug.hxx"

#if defined(WINDOWS_SEMAPHORE_API) 
/* Windows
 */
#include "cwinsecurityattributes.hxx"
#else /* defined(WINDOWS_SEMAPHORE_API) */
/* Unix
 */
#endif /* defined(WINDOWS_SEMAPHORE_API) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cSemaphoreExtend
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cSEMAPHORECreated
cSemaphoreExtend;
/**
 **********************************************************************
 *  Class: cSemaphore
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cSemaphore
: virtual public cSemaphoreImplement,
  public cSemaphoreExtend
{
public:
    typedef cSemaphoreImplement cImplements;
    typedef cSemaphoreExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cSemaphore
     *
     *       Author: $author$
     *         Date: 10/24/2010
     **********************************************************************
     */
    cSemaphore
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
        memset(&m_sem, 0, sizeof(m_sem));
    }
    /**
     **********************************************************************
     *  Destructor: ~cSemaphore
     *
     *      Author: $author$
     *        Date: 10/24/2010
     **********************************************************************
     */
    virtual ~cSemaphore()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CSEMAPHORE_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHORE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Acquire
     *
     *    Author: $author$
     *      Date: 10/24/2010
     **********************************************************************
     */
    virtual eError Acquire
    (TLENGTH waitMilliSeconds=-1)
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        
        DBF(("()...\n"));
        
        if (((tAttachedTo)(vUnattached)) == (attached = Attached()))
            error = e_ERROR_NOT_ATTACHED;
        else
        {
#if defined(WINDOWS_SEMAPHORE_API) 
/* Windows
 */
            LONG lWaitMilliSeconds = (LONG)(waitMilliSeconds);
            DWORD result;
            
            if (0 > lWaitMilliSeconds)
                lWaitMilliSeconds = INFINITE;
                
            if (WAIT_OBJECT_0 == (result = WaitForSingleObject
                (attached, lWaitMilliSeconds)))
                error = e_ERROR_NONE;
            else
            if (WAIT_TIMEOUT == result)
                error = e_ERROR_WAIT_TIMEOUT;
#elif defined(MACOSX)
            int err = 0;
            if (0 > waitMilliSeconds) {
                if (KERN_SUCCESS == (err = semaphore_wait(*attached))) {
                    error = e_ERROR_NONE;
                }
            } else {
                mach_timespec_t wait_time;
                wait_time.tv_sec = waitMilliSeconds/1000;
                wait_time.tv_nsec = ((waitMilliSeconds%1000)*1000)*1000;
                if (KERN_SUCCESS == (err = semaphore_timedwait(*attached, wait_time))) {
                    error = e_ERROR_NONE;
                } else {
                    if (KERN_OPERATION_TIMED_OUT == (err)) {
                        error = e_ERROR_WAIT_TIMEOUT;
                    } else {
                        if (KERN_ABORTED == (err)) {
                            error = e_ERROR_WAIT_ABANDONED;
                        }
                    }
                }
            }
#else /* defined(WINDOWS_SEMAPHORE_API) */
/* Unix
 */
            int err = 0;
            if (0 < waitMilliSeconds)
            {
                time_t seconds = (waitMilliSeconds/1000);
                long nseconds = ((waitMilliSeconds%1000)*1000)*1000;
                struct timespec ts;
                
                if (!(err = clock_gettime(CLOCK_REALTIME, &ts)))
                {
                    ts.tv_sec += seconds;
                    ts.tv_nsec += nseconds;
                    if (!(err = sem_timedwait(attached, &ts)))
                        error = e_ERROR_NONE;
                    else
                    if (errno == ETIMEDOUT)
                        error = e_ERROR_WAIT_TIMEOUT;
                }
            }
            else
            if (0 > waitMilliSeconds)
            {
                if (!(err = sem_wait(attached)))
                    error = e_ERROR_NONE;
                    
                DBT(("() %d = sem_wait(%p)\n", err, attached));
            }
            else
            {
                if (!(err = sem_trywait(attached)))
                    error = e_ERROR_NONE;
                else
                if (errno == EAGAIN)
                    error = e_ERROR_WAIT_TIMEOUT;
            }
#endif /* defined(WINDOWS_SEMAPHORE_API) */
        }
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Release
     *
     *    Author: $author$
     *      Date: 10/24/2010
     **********************************************************************
     */
    virtual eError Release
    (TSIZE count=1)
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        
        DBF(("()...\n"));
        
        if (((tAttachedTo)(vUnattached)) == (attached = Attached()))
            error = e_ERROR_NOT_ATTACHED;
        else
        {
#if defined(WINDOWS_SEMAPHORE_API) 
/* Windows
 */
		    LONG oldcount;
		    if (ReleaseSemaphore(attached, count, &oldcount))
		        error = e_ERROR_NONE;
#elif defined(MACOSX)
            int err = 0;
		    for (TSIZE i = 0; i < count; i++) {
                if (KERN_SUCCESS != (err = semaphore_signal(*attached))) {
				    return error;
                }
		    }
		    error = e_ERROR_NONE;
#else /* defined(WINDOWS_SEMAPHORE_API) */
/* Unix
 */
            int err = 0;
		    for (TSIZE i = 0; i < count; i++) {
			    if ((err = sem_post(attached)))
				    return error;
		    }
		    error = e_ERROR_NONE;
#endif /* defined(WINDOWS_SEMAPHORE_API) */
        }
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$
     *      Date: 10/26/2010
     **********************************************************************
     */
    virtual eError Create
    (TCOUNT initialCount=0, TCOUNT maximumCount=-1, 
     bool onlyDestroyed=false)
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        CreateAttached
        (error, initialCount, maximumCount, onlyDestroyed);
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$
     *      Date: 10/24/2010
     **********************************************************************
     */
    virtual tAttachedTo CreateAttached
    (eError& error, TCOUNT initialCount=0, 
     TCOUNT maximumCount=-1, bool onlyDestroyed=false) 
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)

        if ((error = Destroyed(onlyDestroyed)))
            return detached;

        if (((tAttachedTo)(vUnattached)) != (detached = CreateDetached
            (error, initialCount, maximumCount)))
        if (detached != (AttachCreated(detached)))
        {
            DestroyDetached(detached);
            detached = (tAttachedTo)(vUnattached);
        }
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$
     *      Date: 10/24/2010
     **********************************************************************
     */
    virtual tAttachedTo CreateDetached
    (eError& error, TCOUNT initialCount=0, TCOUNT maximumCount=-1) const
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
        error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
#if defined(WINDOWS_SEMAPHORE_API) 
/* Windows
 */
        LONG lInitialCount = (LONG)(initialCount);
        LONG lMaximumCount =(LONG)(maximumCount);
        LPCTSTR lpName = NULL;
        cWinSecurityAttributes sa;
        
        if (0 < lMaximumCount)
            lMaximumCount = (LONG)(((ULONG)(-1))>>1);
            
        if (((tAttachedTo)(vUnattached)) != (detached = 
            CreateSemaphore
            (&(SECURITY_ATTRIBUTES&)(sa), 
             lInitialCount, lMaximumCount, lpName)))
            error = e_ERROR_NONE;
#elif defined(MACOSX)
        int err = 0;
        task_t task = mach_task_self();
        sync_policy_t sync_policy = SYNC_POLICY_FIFO;
        if ((KERN_SUCCESS == (err = semaphore_create
             (task, &m_sem, sync_policy, initialCount)))) {
            detached = &m_sem;
            error = e_ERROR_NONE;
        }
#else /* defined(WINDOWS_SEMAPHORE_API) */
/* Unix
 */
        int pshared = 0;
        int err = 0;
        if (!(err = sem_init(&m_sem, pshared, initialCount))) {
            detached = &m_sem;
            error = e_ERROR_NONE;
        }
#endif /* defined(WINDOWS_SEMAPHORE_API) */
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$
     *      Date: 10/26/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        tAttachedTo detached;

        if (((tAttachedTo)(vUnattached)) != (detached = Detach()))
            error = DestroyDetached(detached);
        else
        if (onlyCreated)
            return e_ERROR_NOT_ATTACHED;
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyDetached
     *
     *    Author: $author$
     *      Date: 10/26/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (tAttachedTo detached) const
#if defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        if (!(((tAttachedTo)(vUnattached)) != detached))
            error = e_ERROR_NOT_ATTACHED;
#if defined(WINDOWS_SEMAPHORE_API) 
/* Windows
 */
        if ((CloseHandle(detached)))
            error = e_ERROR_NONE;
#elif defined(MACOSX)
        int err = 0;
        task_t task = mach_task_self();
        if (KERN_SUCCESS == (err = semaphore_destroy(task, *detached))) {
            error = e_ERROR_NONE;
        }
#else /* defined(WINDOWS_SEMAPHORE_API) */
/* Unix
 */
        int err = 0;
        if (!(err = sem_destroy(detached)))
            error = e_ERROR_NONE;
#endif /* defined(WINDOWS_SEMAPHORE_API) */
#else /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSEMAPHORE_MEMBER_FUNCS_INTERFACE) */
#if !defined(CSEMAPHORE_MEMBERS_ONLY)
protected:
    mutable SEM_T m_sem;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSEMAPHORE_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHORE_MEMBERS_ONLY) */

#endif /* !defined(_CSEMAPHORE_HXX) || defined(CSEMAPHORE_MEMBERS_ONLY) */

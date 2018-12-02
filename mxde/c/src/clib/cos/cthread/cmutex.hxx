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
 *   File: cmutex.hxx
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
#if !defined(_CMUTEX_HXX) || defined(CMUTEX_MEMBERS_ONLY)
#if !defined(_CMUTEX_HXX) && !defined(CMUTEX_MEMBERS_ONLY)
#define _CMUTEX_HXX
#endif /* !defined(_CMUTEX_HXX) && !defined(CMUTEX_MEMBERS_ONLY) */

#if !defined(CMUTEX_MEMBERS_ONLY)
#include "cmutexinterface.hxx"
#include "cdebug.hxx"

#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
#include "cwinsecurityattributes.hxx"
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
#endif /* defined(WINDOWS_MUTEX_API) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cMutexExtend
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cMUTEXCreated
cMutexExtend;
/**
 **********************************************************************
 *  Class: cMutex
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cMutex
: virtual public cMutexImplement,
  public cMutexExtend
{
public:
    typedef cMutexImplement cImplements;
    typedef cMutexExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cMutex
     *
     *       Author: $author$
     *         Date: 10/31/2010
     **********************************************************************
     */
    cMutex
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cMutex
     *
     *      Author: $author$
     *        Date: 10/31/2010
     **********************************************************************
     */
    virtual ~cMutex()
    {
    }
#else /* !defined(CMUTEX_MEMBERS_ONLY) */
#endif /* !defined(CMUTEX_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Acquire
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual eError Acquire
    (TLENGTH waitMilliSeconds=-1)
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        if (((tAttachedTo)(vUnattached)) == (attached = Attached()))
            return error = e_ERROR_NOT_ATTACHED;
#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
        DWORD milliSeconds = (0 > waitMilliSeconds)
        ?INFINITE:waitMilliSeconds;
		DWORD result;

		if (WAIT_OBJECT_0 != (result = WaitForSingleObject
            (attached, milliSeconds)))
		if (WAIT_TIMEOUT != result)
            return error;
        else 
        return e_ERROR_WAIT_TIMEOUT;
        error = e_ERROR_NONE;
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
        int err;
        if (0 < waitMilliSeconds)
        {
            time_t seconds = (waitMilliSeconds/1000);
            long nseconds = ((waitMilliSeconds%1000)*1000)*1000;
            struct timespec ts;
            
            DBT(("() seconds = %ld, nseconds = %ld\n", seconds, nseconds));

            if (!(err = clock_gettime(CLOCK_REALTIME, &ts)))
            {
                ts.tv_sec += seconds;
                ts.tv_nsec += nseconds;
                if (!(err = pthread_mutex_timedlock(attached, &ts)))
                    error = e_ERROR_NONE;
                else
                if (err == ETIMEDOUT)
                {
                    DBT(("() timeout on pthread_mutex_timedlock(%p)\n", attached));
                    error = e_ERROR_WAIT_TIMEOUT;
                }
                else
                DBE(("() failed on pthread_mutex_timedlock(%p)\n", attached));
            }
        }
        else
        if (0 > waitMilliSeconds)
        {
            if (!(err = pthread_mutex_lock(attached)))
                error = e_ERROR_NONE;
            else 
            DBE(("() failed on pthread_mutex_lock(%p)\n", attached));
        }
        else
        {
            if (!(err = pthread_mutex_trylock(attached)))
                error = e_ERROR_NONE;
            else
            if (EBUSY != err)
                DBE(("() failed on pthread_mutex_trylock(%p)\n", attached));
            else
            DBT(("() timeout on pthread_mutex_trylock(%p)\n", attached));
        }
#endif /* defined(WINDOWS_MUTEX_API) */
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Release
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual eError Release()
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        if (((tAttachedTo)(vUnattached)) == (attached = Attached()))
            return error = e_ERROR_NOT_ATTACHED;
#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
        int err;
        if (!(err = pthread_mutex_unlock(attached)))
            error = e_ERROR_NONE;
        else 
        DBE(("() failed on pthread_mutex_unlock(%p)\n", attached));
#endif /* defined(WINDOWS_MUTEX_API) */
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual eError Create
    (bool initiallyLocked=false, 
     bool onlyDestroyed=false)
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        CreateAttached(error, initiallyLocked, onlyDestroyed);
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual tAttachedTo CreateAttached
    (eError& error, bool initiallyLocked=false, 
     bool onlyDestroyed=false)
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        if ((error = Destroyed(onlyDestroyed)))
            return attached;

        if (((tAttachedTo)(vUnattached)) 
            != (attached = CreateDetached(error, initiallyLocked)))
        if (attached != (AttachCreated(attached)))
        {
            DestroyDetached(attached);
            attached = (tAttachedTo)(vUnattached);
        }
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual tAttachedTo CreateDetached
    (eError& error, bool initiallyLocked=false) const
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        MUTEX_ATTR mutexAttr;
#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
        BOOL bInitialOwner = (initiallyLocked)?TRUE:FALSE;
        LPCTSTR lpName = NULL;
        cWinSecurityAttributes sa(mutexAttr);

        if (((tAttachedTo)(vUnattached)) 
            != (detached = CreateMutex
            (&mutexAttr, bInitialOwner, lpName)))
        {
            error = e_ERROR_NONE;
            return detached;
        }
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
		int err;
		if ((err = pthread_mutexattr_settype
			(&mutexAttr, PTHREAD_MUTEX_RECURSIVE)))
            DBE(("() failed on pthread_mutexattr_settype()\n"));
        else
        {
            if (((tAttachedTo)(vUnattached)) 
                != (detached = new pthread_mutex_t))
            {
                DBT(("() detached = %p\n", detached));
                if ((err = pthread_mutex_init(detached, &mutexAttr)))
                    DBE(("() failed on pthread_mutex_init(%p,...)\n", detached));
                else
                {
                    pthread_mutexattr_destroy(&mutexAttr);
                    if (initiallyLocked)
                    if ((err = pthread_mutex_lock(detached)))
                        DBE(("() failed on pthread_mutex_lock(%p)\n", detached));
                    if (!err)
                    {
                        error = e_ERROR_NONE;
                        return detached;
                    }
                }
                delete detached;
                detached = (tAttachedTo)(vUnattached);
            }
            pthread_mutexattr_destroy(&mutexAttr);
        }
#endif /* defined(WINDOWS_MUTEX_API) */
        error = e_ERROR_FAILED;
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        tAttachedTo detached = (tAttachedTo)(vUnattached);
        if (((tAttachedTo)(vUnattached)) != (detached = Detach()))
            error = DestroyDetached(detached);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyDetached
     *
     *    Author: $author$
     *      Date: 10/31/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (tAttachedTo detached) const
#if defined(CMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;

        if (((tAttachedTo)(vUnattached)) == detached)
            return error = e_ERROR_NOT_ATTACHED;

#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
        if ((CloseHandle(detached)))
            error = e_ERROR_NONE;
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
        int err;
        if ((err = pthread_mutex_destroy(detached)))
            DBE(("() failed on pthread_mutex_destroy(%p)\n", detached));
        delete detached;
        if (!err)
            error = e_ERROR_NONE;
#endif /* defined(WINDOWS_MUTEX_API) */
#else /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMUTEX_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMUTEX_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMUTEX_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMUTEX_MEMBERS_ONLY) */
#endif /* !defined(CMUTEX_MEMBERS_ONLY) */

#endif /* !defined(_CMUTEX_HXX) || defined(CMUTEX_MEMBERS_ONLY) */

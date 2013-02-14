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
///   File: XosPThread.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPTHREAD_HPP
#define _XOSPTHREAD_HPP

#include "XosThreadBase.hpp"
#include "XosPlatform_pthread.hpp"
#include "XosDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosPThreadImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosThreadBaseImplement
XosPThreadImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosPThreadExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosThreadBase
XosPThreadExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosPThread
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosPThread
: virtual public XosPThreadImplement,
  public XosPThreadExtend
{
public:
    typedef XosPThreadImplement Implements;
    typedef XosPThreadExtend Extends;

    pthread_t m_thread;
    pthread_attr_t m_threadAttr;
    bool m_isCreated;
    bool m_isForked;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosPThread
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosPThread
    (bool create=false,
     bool initiallyStopped=false)
    : m_isCreated(false),
      m_isForked(false)
    {
        if ((create))
        if ((initiallyStopped))
        {
            XosError error = XOS_ERROR_NOT_IMPLEMENTED;
            XOS_DBE(("() initiallyStopped NOT Implemented\n"));
            throw (error);
        }
        else
        if (!(Create()))
        {
            XosError error = XOS_ERROR_FAILED;
            XOS_DBE(("() failed on Create()\n"));
            throw (error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosPThread
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosPThread()
    {
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
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create
    (bool onlyDestroyed=false)
    {
        bool isSuccess = false;
        int err;
        
        if ((m_isCreated))
        if ((onlyDestroyed))
            return false;

        if (!(Destroy()))
            return false;

        if (!(err = pthread_attr_init(&m_threadAttr)))
        {
            if ((isSuccess = (m_isCreated = (m_isForked = !(err = pthread_create
                (&m_thread, &m_threadAttr, ThreadRoutine, 
                 (void*)((XosPThread*)(this))))))))
                 return isSuccess;
            else
            {   XOS_DBE(("() failed on pthread_create()")); }

            if ((err = pthread_attr_destroy(&m_threadAttr)))
            {   XOS_DBE(("() failed on pthread_attr_destroy()")); }
        }
        else
        {   XOS_DBE(("() failed on pthread_xattr_init()")); }
        return isSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Join
    ///
    ///    Author: $author$
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Join(void*& result)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        {
            if (!(err = pthread_join(m_thread, &result)))
                error = XOS_ERROR_NONE;
            else
            {   XOS_DBE(("() failed on pthread_join()")); }

            m_isForked = false;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TryJoin
    ///
    ///    Author: $author$
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TryJoin(void*& result)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        {
            if (!(err = pthread_tryjoin_np(m_thread, &result)))
                error = XOS_ERROR_NONE;
            else
            if (EBUSY == (err))
            {   
                XOS_DBT(("() busy on pthread_tryjoin_np()")); 
                error = XOS_ERROR_BUSY;
            }
            else
            {   XOS_DBE(("() failed on pthread_tryjoin_np()")); }

            if (EBUSY != (err))
            m_isForked = false;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TimedJoin
    ///
    ///    Author: $author$
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError TimedJoin
    (void*& result, const struct timespec& untilTime)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if ((m_isCreated))
        {
            if (!(err = pthread_timedjoin_np
                (m_thread, &result, &untilTime)))
                error = XOS_ERROR_NONE;
            else
            if (ETIMEDOUT == (err))
            {   
                XOS_DBT(("() timedout on pthread_timedjoin_np()")); 
                error = XOS_ERROR_TIMEDOUT;
            }
            else
            {   XOS_DBE(("() failed on pthread_timedjoin_np()")); }

            if (ETIMEDOUT != (err))
            m_isForked = false;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Destroy
    (bool onlyCreated=false)
    {
        XosError error = XOS_ERROR_NONE;
        bool isSuccess = false;
        void* result;
        int err;

        if (!(m_isCreated))
            return !(onlyCreated);

        if ((m_isForked))
            error = Join(result);

        m_isCreated = false;

        if (!(err = pthread_attr_destroy(&m_threadAttr)))
            isSuccess = !(error);
        else
        {   XOS_DBE(("() failed on pthread_destroy_attr()")); }

        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ThreadRoutine
    ///
    ///    Author: $author$
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    static void* ThreadRoutine(void* arg)
    {
        void* result = 0;
        XosPThread* thread;

        if ((thread = (XosPThread*)(arg)))
            thread->Run();
        else
        {   XOS_DBE(("() arg == 0")); }

        return result;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSPTHREAD_HPP 
        


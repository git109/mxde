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
///   File: XosWinThread.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINTHREAD_HPP
#define _XOSWINTHREAD_HPP

#include "XosThreadBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinThreadImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosThreadBaseImplement
XosWinThreadImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinThreadExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosThreadBase
XosWinThreadExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinThread
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinThread
: virtual public XosWinThreadImplement,
  public XosWinThreadExtend
{
public:
    typedef XosWinThreadImplement Implements;
    typedef XosWinThreadExtend Extends;

    DWORD m_tid;
    HANDLE m_trd;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinThread
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinThread
    (bool create=false,
     bool initiallyStopped=false)
    : m_tid(0), m_trd(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinThread
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinThread()
    {
    }

    virtual bool Create
    (bool initiallyStopped=false)
    {
        bool isSuccess = false;
        HANDLE trd;
        DWORD tid;

        if (!(m_trd))
        {
            if ((trd = CreateThread
                (NULL, 0, Thread, (LPVOID)(this), 0, &tid)))
            {
                m_trd = trd;
                m_tid = tid;
                isSuccess = true;
            }
        }
        return isSuccess;
    }
    virtual bool Destroy()
    {
        bool isSuccess = false;
        if ((m_trd))
        {
            WaitForSingleObject(m_trd, INFINITE);
            CloseHandle(m_trd);
            m_trd = 0;
            m_tid = 0;
            isSuccess = true;
        }
        return isSuccess;
    }
    static DWORD WINAPI Thread(LPVOID lpParameter)
    {
        DWORD result = 1;
        XosWinThread* thread;

        if ((thread = (XosWinThread*)(lpParameter)))
            thread->Run();
        return result;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINTHREAD_HPP 
        


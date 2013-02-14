///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   File: XosThreadSafeNSAutoreleasePool.hh
///
/// Author: $author$
///   Date: 1/29/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSTHREADSAFENSAUTORELEASEPOOL_HH
#define _XOSTHREADSAFENSAUTORELEASEPOOL_HH

#include "XosPlatform_cocoa.hh"
#include "XosPThreadMutex.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosInterfaceBase XosThreadSafeNSAutoreleasePoolImplement;
typedef XosExportBase XosThreadSafeNSAutoreleasePoolExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosThreadSafeNSAutoreleasePool
/// 
/// Author: $author$
///   Date: 1/29/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosThreadSafeNSAutoreleasePool
: virtual public XosThreadSafeNSAutoreleasePoolImplement,
  public XosThreadSafeNSAutoreleasePoolExtend
{
public:
    typedef XosThreadSafeNSAutoreleasePoolImplement Implements;
    typedef XosThreadSafeNSAutoreleasePoolExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: XosThreadSafeNSAutoreleasePool
    //
    //       Author: $author$
    //         Date: 1/29/2013
    ///////////////////////////////////////////////////////////////////////
    XosThreadSafeNSAutoreleasePool(): m_pool(0) {
        m_lock.Create();
    }
    virtual ~XosThreadSafeNSAutoreleasePool() {
        Release();
        m_lock.Destroy();
    }

    virtual NSAutoreleasePool* Allocate() {
        NSAutoreleasePool* pool = 0;
        if (!(m_pool)) {
            if ((m_lock.Lock())) {
                if (!(m_pool)) {
#if defined(OBJC)
                    m_pool = [[NSAutoreleasePool alloc] init];
#endif // defined(OBJC)
                }
                pool = m_pool;
                m_lock.Unlock();
            }
        }
        return pool;
    }
    virtual bool Release() {
        bool isSuccess = false;
        if ((m_lock.Lock())) {
            if ((isSuccess = (0 != m_pool))) {
#if defined(OBJC)
                [m_pool release];
#endif // defined(OBJC)
                m_pool = 0;
            }
            m_lock.Unlock();
        }
        return isSuccess;
    }

protected:
    NSAutoreleasePool* m_pool;
    XosPThreadMutex m_lock;
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSTHREADSAFENSAUTORELEASEPOOL_HH 

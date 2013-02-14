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
///   File: XosPlatform_pthread.cpp
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
#include "XosPlatform_pthread.hpp"

#if defined(WINDOWS) 
// Windows 

//
// mutex
//

int pthread_mutexattr_init
(pthread_mutexattr_t* mutexattr)
{
    int err = 1;
    return err;
}
int pthread_mutexattr_destroy
(pthread_mutexattr_t* mutexattr)
{
    int err = 1;
    return err;
}
int pthread_mutexattr_settype
(pthread_mutexattr_t* mutexattr, int type)
{
    int err = EINVAL;
    return err;
}
int pthread_mutexattr_gettype
(const pthread_mutexattr_t* mutexattr, int* type)
{
    int err = EINVAL;
    return err;
}
int pthread_mutexattr_setpshared
(pthread_mutexattr_t* mutexattr, int type)
{
    int err = EINVAL;
    return err;
}
int pthread_mutexattr_getpshared
(const pthread_mutexattr_t* mutexattr, int* type)
{
    int err = EINVAL;
    return err;
}

int pthread_mutex_init
(pthread_mutex_t* mutex, 
 const pthread_mutexattr_t* mutexattr)
{
    int err = 1;
    return err;
}
int pthread_mutex_destroy
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}
int pthread_mutex_lock
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}
int pthread_mutex_trylock
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}
int pthread_mutex_unlock
(pthread_mutex_t* mutex)
{
    int err = 1;
    return err;
}

//
// thread
//
int pthread_attr_init(pthread_attr_t *attr)
{
    int err = EINVAL;
    return err;
}
int pthread_attr_destroy(pthread_attr_t *attr)
{
    int err = EINVAL;
    return err;
}

int pthread_create
(pthread_t *thread, const pthread_attr_t *attr,
 void *(*start_routine)(void*), void *arg)
{
    int err = EINVAL;
    return err;
}
int pthread_join
(pthread_t thread, void **value_ptr)
{
    int err = EINVAL;
    return err;
}

int pthread_detach(pthread_t thread)
{
    int err = EINVAL;
    return err;
}
void pthread_exit(void *value_ptr)
{
}

#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 

#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
int pthread_mutex_timedlock
(pthread_mutex_t* mutex, const struct timespec* timespec)
{
    int err = 1;
    return err;
}
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)

#if !defined(PTHREAD_HAS_TIMEDJOIN)
int pthread_timedjoin_np
(pthread_t thread, void **value_ptr, const struct timespec* timespec)
{
    int err = EINVAL;
    return err;
}
#endif // !defined(PTHREAD_HAS_TIMEDJOIN)

#if !defined(PTHREAD_HAS_TRYJOIN)
int pthread_tryjoin_np(pthread_t thread, void **value_ptr)
{
    int err = EINVAL;
    return err;
}
#endif // !defined(PTHREAD_HAS_TTYJOIN)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(WINDOWS) 
// Windows 
#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

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
///   File: XosPlatform_semaphore.cpp
///
/// Author: $author$
///   Date: 3/31/2012
///////////////////////////////////////////////////////////////////////
#include "XosPlatform_semaphore.hpp"

#if defined(WINDOWS) 
// Windows 

int sem_init
(sem_t* sem, int pshared, unsigned int value)
{
    int err = EINVAL;
    return err;
}
int sem_destroy
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}

int sem_post
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}
int sem_getvalue
(sem_t* sem, int *sval)
{
    int err = EINVAL;
    return err;
}
int sem_trywait
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}
int sem_wait
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}

sem_t* sem_open
(const char* name, int oflag, ...)
{
    sem_t* sem = 0;
    return sem;
}
int sem_close
(sem_t* sem)
{
    int err = EINVAL;
    return err;
}
int sem_unlink
(const char* name)
{
    int err = EINVAL;
    return err;
}
#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 

#if !defined(SEM_HAS_TIMEDWAIT)
int sem_timedwait
(sem_t* sem, const struct timespec *abs_timeout)
{
    int err = EINVAL;
    return err;
}
#endif // !defined(SEM_HAS_TIMEDWAIT)

#if defined(MACOSX) 
// Mac OSX 
#else // defined(MACOSX) 
// Otherwise 
task_t mach_task_self()
{ return 0; }

kern_return_t semaphore_create
(task_t task, semaphore_t* new_semaphore, sync_policy_t policy, int value)
{ return -1; }
kern_return_t semaphore_destroy(task_t task, semaphore_t semaphore)
{ return -1; }

kern_return_t semaphore_signal(semaphore_t semaphore)
{ return -1; }
kern_return_t semaphore_signal_all(semaphore_t semaphore)
{ return -1; }
kern_return_t semaphore_wait(semaphore_t semaphore)
{ return -1; }

kern_return_t semaphore_timedwait
(semaphore_t semaphore, mach_timespec_t wait_time)
{ return -1; }
kern_return_t semaphore_timedwait_signal
(semaphore_t wait_semaphore, semaphore_t signal_semaphore, mach_timespec_t wait_time)
{ return -1; }
kern_return_t semaphore_wait_signal
(semaphore_t wait_semaphore, semaphore_t signal_semaphore)
{ return -1; }
kern_return_t semaphore_signal_thread
(semaphore_t semaphore, thread_t thread)
{ return -1; }
#endif // defined(MACOSX) 

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

        


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
///   File: XosPlatform_semaphore.hpp
///
/// Author: $author$
///   Date: 3/31/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPLATFORM_SEMAPHORE_HPP
#define _XOSPLATFORM_SEMAPHORE_HPP

#include "XosPlatform_errno.hpp"
#include "XosPlatform_time.hpp"

#if defined(WINDOWS) 
// Windows 
typedef HANDLE sem_t;
#else // defined(WINDOWS) 
// Unix 
// ...
#include <semaphore.h>
#endif // defined(WINDOWS) 

#if defined(MACOSX) 
// Mac OSX 
#include <mach/task.h>
#include <mach/mach.h>
#include <mach/semaphore.h>
#else // defined(MACOSX) 
// Otherwise 
typedef int kern_return_t;
typedef void* task_t;
typedef void* thread_t;
typedef void* semaphore_t;
typedef int sync_policy_t;
typedef timespec_t mach_timespec_t;
#define SYNC_POLICY_FIFO 0
#define SYNC_POLICY_FIXED_PRIORITY 1
#define KERN_SUCCESS 0
#define KERN_INVALID_ARGUMENT 1
#define KERN_RESOURCE_SHORTAGE 2
#define KERN_INVALID_RIGHT 3
#define KERN_TERMINATED 4
#define KERN_ABORTED 5
#endif // defined(MACOSX) 

#define SEMAPHORE_PROCESS_PRIVATE 0
#define SEMAPHORE_PROCESS_SHARED  1

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)

#if defined(WINDOWS) 
// Windows 
int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_destroy(sem_t *sem);
int sem_post(sem_t *sem);
int sem_getvalue(sem_t *sem, int *sval);
int sem_trywait(sem_t *sem);
int sem_wait(sem_t *sem);

sem_t *sem_open(const char *name, int oflag, ...);
int    sem_close(sem_t *);
int    sem_unlink(const char *);
#else // defined(WINDOWS) 
// Unix 
#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define SEM_HAS_TIMEDWAIT
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#endif // defined(WINDOWS) 

#if !defined(SEM_HAS_TIMEDWAIT)
int sem_timedwait
(sem_t *sem, const struct timespec *abs_timeout);
#endif // !defined(SEM_HAS_TIMEDWAIT)

#if defined(MACOSX) 
// Mac OSX 
#else // defined(MACOSX) 
// Otherwise 
task_t mach_task_self();

kern_return_t semaphore_create
(task_t task, semaphore_t* new_semaphore, sync_policy_t policy, int value);

kern_return_t semaphore_destroy(task_t task, semaphore_t semaphore);

kern_return_t semaphore_signal(semaphore_t semaphore);

kern_return_t semaphore_signal_all(semaphore_t semaphore);

kern_return_t semaphore_wait(semaphore_t semaphore);

kern_return_t semaphore_timedwait
(semaphore_t semaphore, mach_timespec_t wait_time);

kern_return_t semaphore_timedwait_signal
(semaphore_t wait_semaphore, semaphore_t signal_semaphore, mach_timespec_t wait_time);

kern_return_t semaphore_wait_signal
(semaphore_t wait_semaphore, semaphore_t signal_semaphore);

kern_return_t semaphore_signal_thread
(semaphore_t semaphore, thread_t thread);
#endif // defined(MACOSX) 

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

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

#endif // _XOSPLATFORM_SEMAPHORE_HPP 
        


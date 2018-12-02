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
 *   File: cplatform_semaphore.h
 *
 * Author: $author$
 *   Date: 10/23/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_SEMAPHORE_H
#define _CPLATFORM_SEMAPHORE_H

#include "cplatform.h"

#if !defined(WINDOWS_SEMAPHORE_API) 
#if defined(WINDOWS) 
#define WINDOWS_SEMAPHORE_API
#endif /* defined(WINDOWS) */
#endif /* !defined(WINDOWS_SEMAPHORE_API) */

#if defined(WINDOWS_SEMAPHORE_API) 
/* Windows
 */
#define INVALID_SEMAPHORE NULL
typedef HANDLE SEM_T;
typedef HANDLE SEMAPHORE;
typedef SECURITY_ATTRIBUTES SEMAPHORE_ATTR;
#else /* defined(WINDOWS_SEMAPHORE_API) */
/* Unix
 * ...
 */
#if defined(MACOSX)
/* Mac OSX
 * ..
 */
#include <mach/task.h>
#include <mach/mach.h>
#include <mach/semaphore.h>

#define INVALID_SEMAPHORE 0
typedef semaphore_t SEM_T;
typedef semaphore_t* SEMAPHORE;
/* ...
 * Mac OSX
 */
#else /* defined(MACOSX) */
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <semaphore.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#define SEM_HAS_TIMEDWAIT
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

#define INVALID_SEMAPHORE 0
typedef sem_t SEM_T;
typedef sem_t* SEMAPHORE;
typedef int SEMAPHORE_ATTR;
enum 
{
    SEMAPHORE_ATTR_SHARED_THREAD  = 0,
    SEMAPHORE_ATTR_SHARED_PROCESS = 1
};
/* ...
 * Unix
 */
#endif /* defined(MACOSX) */
#endif /* defined(WINDOWS_SEMAPHORE_API) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS) 
/* Windows
 */
typedef struct sem sem_t;

int sem_init
(sem_t *sem, int pshared, unsigned int value);
int sem_destroy(sem_t *sem);

sem_t *sem_open
(const char *name, int oflag, ...
 /* mode_t mode, unsigned int value */);
int sem_close(sem_t *sem);

int sem_post(sem_t *sem);
int sem_getvalue(sem_t *sem, int *sval);

int sem_timedwait
(sem_t *sem, const struct timespec *abs_timeout);
int sem_trywait(sem_t *sem);
int sem_wait(sem_t *sem);
/* Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 */
typedef struct SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;
HANDLE CreateSemaphore
(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
 LONG lInitialCount, LONG lMaximumCount, 
 LPCTSTR lpName);

HANDLE OpenSemaphore
(DWORD dwDesiredAccess,
 BOOL bInheritHandle,
 LPCTSTR lpName);

BOOL ReleaseSemaphore
(HANDLE hSemaphore,
 LONG lReleaseCount,
 LPLONG lpPreviousCount);
/* Unix
 */
#endif /* defined(WINDOWS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_SEMAPHORE_H */

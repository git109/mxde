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
 *   File: cplatform_mutex.h
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_MUTEX_H
#define _CPLATFORM_MUTEX_H

#include "cplatform.h"

#if !defined(WINDOWS_MUTEX_API) 
#if defined(WINDOWS) 
#define WINDOWS_MUTEX_API
#endif /* defined(WINDOWS) */
#endif /* !defined(WINDOWS_MUTEX_API) */

#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
#define INVALID_MUTEX NULL
typedef HANDLE MUTEX;
typedef SECURITY_ATTRIBUTES MUTEX_ATTR;

typedef struct pthread_mutex 
pthread_mutex_t;

typedef struct pthread_mutexattr 
pthread_mutexattr_t;
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
#include <errno.h>
#include <time.h>
#include <pthread.h>
#define INVALID_MUTEX 0
typedef struct SECURITY_ATTRIBUTES* LPSECURITY_ATTRIBUTES;
typedef pthread_mutex_t* MUTEX;
typedef pthread_mutexattr_t MUTEX_ATTR;
#endif /* defined(WINDOWS_MUTEX_API) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WINDOWS_MUTEX_API) 
/* Windows
 */
int pthread_mutex_init
(pthread_mutex_t *mutex,
 const pthread_mutexattr_t *attr);

int pthread_mutex_destroy
(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

int pthread_mutexattr_settype
(pthread_mutexattr_t *attr, int type);

int pthread_mutexattr_gettype
(const pthread_mutexattr_t *attr, int *type);

int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
#else /* defined(WINDOWS_MUTEX_API) */
/* Unix
 */
HANDLE CreateMutex
(LPSECURITY_ATTRIBUTES lpMutexAttributes,
 BOOL bInitialOwner,
 LPCTSTR lpName);

HANDLE OpenMutex
(DWORD dwDesiredAccess,
 BOOL bInheritHandle,
 LPCTSTR lpName);

BOOL ReleaseMutex
(HANDLE hMutex);
#endif /* defined(WINDOWS_MUTEX_API) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_MUTEX_H */

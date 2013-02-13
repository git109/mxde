/* $Xorg: Xw32defs.h,v 1.3 2000/08/18 04:05:44 coskrey Exp $ */

/**
 **********************************************************************
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
 *   File: cplatform_X11_Xw32defs.h
 *
 * Author: $author$           
 *   Date: 5/4/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_XW32DEFS_H
#define _CPLATFORM_X11_XW32DEFS_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/Xw32defs.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#ifdef __GNUC__ /* mingw is more close to unix than msvc */
#if !defined(__daddr_t_defined) 
typedef char *caddr_t;
#endif
#define lstat stat

#else
typedef char *caddr_t;

#define access	   _access
#define alloca	   _alloca
#define chdir	_chdir
#define chmod	   _chmod
#define close	   _close
#define creat	   _creat
#define dup	   _dup
#define dup2	   _dup2
#define environ     _environ
#define execl	 _execl
#define execle	 _execle
#define execlp	 _execlp
#define execlpe  _execlpe
#define execv	 _execv
#define execve	 _execve
#define execvp	 _execvp
#define execvpe  _execvpe
#define fdopen	  _fdopen
#define fileno	  _fileno
#define fstat	 _fstat
#define getcwd	_getcwd
#define getpid	 _getpid
#define hypot		_hypot
#define isascii __isascii
#define isatty	   _isatty
#define lseek	   _lseek
#define mkdir	_mkdir
#define mktemp	   _mktemp
#define open	   _open
#define putenv	    _putenv
#define read	   _read
#define rmdir	_rmdir
#define sleep(x) _sleep((x) * 1000)
#define stat	 _stat
#define sys_errlist _sys_errlist
#define sys_nerr    _sys_nerr
#define umask	   _umask
#define unlink	   _unlink
#define write	   _write
#define random   rand
#define srandom  srand

#define O_RDONLY    _O_RDONLY
#define O_WRONLY    _O_WRONLY
#define O_RDWR	    _O_RDWR
#define O_APPEND    _O_APPEND
#define O_CREAT     _O_CREAT
#define O_TRUNC     _O_TRUNC
#define O_EXCL	    _O_EXCL
#define O_TEXT	    _O_TEXT
#define O_BINARY    _O_BINARY
#define O_RAW	    _O_BINARY

#define S_IFMT	 _S_IFMT
#define S_IFDIR  _S_IFDIR
#define S_IFCHR  _S_IFCHR
#define S_IFREG  _S_IFREG
#define S_IREAD  _S_IREAD
#define S_IWRITE _S_IWRITE
#define S_IEXEC  _S_IEXEC

#define	F_OK	0
#define	X_OK	1
#define	W_OK	2
#define	R_OK	4
#endif /* __GNUC__ */

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_XW32DEFS_H */

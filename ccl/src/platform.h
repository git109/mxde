/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: platform.h
 *
 * Author: $author$
 *   Date: 12/8/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _PLATFORM_H
#define _PLATFORM_H

#if !defined(WIN32)
#if defined(_WIN32_WCE) || defined(_WIN32)
#define WIN32
#endif /* defined(_WIN32_WCE) || defined(_WIN32_WCE) */
#endif /* !defined(WIN32) */

#if !defined(WIN32_API) 
#if !defined(UNIX_API) 
#define WIN32_API
#else /* !defined(UNIX_API) */
#endif /* !defined(UNIX_API) */
#else /* !defined(WIN32_API) */
#undef UNIX_API
#endif /* !defined(WIN32_API) */

#if defined(WIN32)
/*
 * Windows
 */
#include <windows.h>
#include <tchar.h>
#include <wchar.h>

#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

#define MSC_VER_6 1200
#define MSC_VER_7 1300
#define MSC_VER_8 1400

#if (_MSC_VER >= MSC_VER_8) 
#define WIN32_MSC_VER_8
#elif (_MSC_VER >= MSC_VER_7) 
#define WIN32_MSC_VER_7
#else /* (_MSC_VER >= MSC_VER_8) */
#define WIN32_MSC_VER_6
#endif /* (_MSC_VER >= MSC_VER_8) */

#define PLATFORM_EXPORT __declspec(dllexport)
#define PLATFORM_IMPORT __declspec(dllimport)

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>
#define PLATFORM_RCAST(type) reinterpret_cast<type>

#if defined(_WIN32_WCE)
/*
 * Windows CE
 */
#if defined(__cplusplus)
#include "cexception.hxx"
#define throw(ex) cException::Throw(ex)
#endif
#endif /* defined(_WIN32_WCE) */

#define _W(str) L##str
typedef ULONG64 QWORD;

#define wdt_enable(time)
#define wdt_disable()
#define wdt_reset()

#pragma warning(disable:4250) /* derived 'class' inherits 'base::member' via dominance */
#pragma warning(disable:4355) /* 'this' used in base member initializer list */
#pragma warning(disable:4996) /* 'function' was declared deprecated */

#elif defined(ATMEGA128)
/*
 * AVR atmega128
 */
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/signal.h>
#include <avr/wdt.h>

#else /* defined(WIN32) */
/*
 * Unix
 */
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#if !defined(UNIX)
#define UNIX
#endif /* !defined(UNIX) */

#if !defined(UNIX_API) 
#if !defined(WIN32_API) 
#define UNIX_API
#endif /* !defined(WIN32_API) */
#else /* !defined(UNIX_API) */
#undef WIN32_API
#endif /* !defined(UNIX_API) */

#define NO_TEMPLATE_STATIC_MEMBERS

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>

#if defined(__GNUC__)
#if (__GNUC__ < 4)
#define PLATFORM_RCAST(type) (type)
#else /* (__GNUC__ < 4) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* (__GNUC__ < 4) */
#else /* defined(__GNUC__) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* defined(__GNUC__) */

#define _T(str) str

typedef int BOOL;

typedef char CHAR;
typedef char TCHAR;
typedef short WCHAR;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef uint32_t DWORD;
typedef uint64_t QWORD;

typedef int INT;
typedef int32_t LONG;
typedef int64_t LONGLONG;

typedef unsigned int UINT;
typedef uint32_t ULONG;
typedef uint64_t ULONGLONG;

typedef short SHORT;
typedef unsigned short USHORT;

typedef int32_t INT32;
typedef int64_t INT64;

typedef uint32_t UINT32;
typedef uint64_t UINT64;

typedef void* PVOID;
typedef PVOID LPVOID;
typedef PVOID HANDLE;
typedef PVOID HMODULE;
typedef PVOID HINSTANCE;

typedef INT INVALID_HANDLE_T;

typedef char* PCHAR;
typedef PCHAR LPCHAR;

typedef BYTE* PBYTE;
typedef PBYTE LPBYTE;

typedef char* PSTR;
typedef PSTR LPSTR;

typedef const char* PCSTR;
typedef PCSTR LPCSTR;

typedef TCHAR* PTSTR;
typedef PTSTR LPTSTR;

typedef const TCHAR* PCTSTR;
typedef PCTSTR LPCTSTR;

#define INFINITE -1
#define INVALID_HANDLE_VALUE (0)
#endif /* defined(WIN32) */

typedef unsigned char byte;
typedef unsigned char octet;
typedef unsigned char opaque;

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef int8 int24[3];
typedef uint8 uint24[3];

#if defined(WIN32)
/*
 * Windows
 */
typedef long int32;
typedef unsigned long uint32;

typedef int8 int64[8];
typedef uint8 uint64[8];

typedef int8 int128[16];
typedef uint8 uint128[16];

#else /* defined(WIN32) */
/*
 * Unix
 */
typedef int32_t int32;
typedef uint32_t uint32;

typedef int64_t int64;
typedef uint64_t uint64;
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(EMBEDDED) 
#define platform_forever 1
#define platform_void_main main
#else /* defined(EMBEDDED) */

extern int platform_forever;

/**
 **********************************************************************
 * Function: platform_void_main
 *
 *   Author: $author$
 *     Date: 8/14/2005
 **********************************************************************
 */
void platform_void_main(void);
#endif /* defined(EMBEDDED) */

#if defined(__cplusplus)
}
#endif

#endif

/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cplatform.h
 *
 * Author: $author$
 *   Date: 10/12/2007
 *
 **********************************************************************
 */
#ifndef _CPLATFORM_H
#define _CPLATFORM_H
#define _PLATFORM_H

/* Define WIN64 if any of the Win64
 * variants are selected
 */
#if !defined(WIN64)
#if defined(_WIN64) || defined(__WIN64__) || defined(__Win64__) || defined(__win64__)
#define WIN64
#else /*  defined(_WIN64) || defined(__WIN64__) || defined(__Win64__) || defined(__win64__) */
#endif /*  defined(_WIN64) || defined(__WIN64__) || defined(__Win64__) || defined(__win64__) */
#else /*  !defined(WIN64) */
#endif /*  !defined(WIN64) */

/* Define WIN32 if any of the Win32
 * variants are selected
 */
#if !defined(WIN32)
#if defined(_WIN32) || defined(__WIN32__) || defined(__Win32__) || defined(__win32__)
#define WIN32
#else /*  defined(_WIN32) || defined(__WIN32__) || defined(__Win32__) || defined(__win32__) */
#endif /*  defined(_WIN32) || defined(__WIN32__) || defined(__Win32__) || defined(__win32__) */
#else /*  !defined(WIN32) */
#endif /*  !defined(WIN32) */

/* Define LINUX if any of the Linux
 * variants are selected
 */
#if !defined(LINUX)
#if defined(__LINUX__) || defined(__Linux__) || defined(__linux__)
#define LINUX
#else /*  defined(__LINUX__) || defined(__Linux__) || defined(__linux__) */
#endif /*  defined(__LINUX__) || defined(__Linux__) || defined(__linux__) */
#else /*  !defined(LINUX) */
#endif /*  !defined(LINUX) */

/* Define MACOSX if any of the Mac OSX
 * variants are selected
 */
#if !defined(MACOSX)
#if defined(__APPLE__) || defined(__MACOS__) || defined(__MACOSX__) || defined(__MacOSX__) || defined(__macosx__)
#define MACOSX
#else /*  defined(__MACOS__) || defined(__MacOSX__) || defined(__macosx__) */
#endif /*  defined(__MACOS__) || defined(__MacOSX__) || defined(__macosx__) */
#else /*  !defined(MACOSX) */
#endif /*  !defined(MACOSX) */

/* Define WIN64_WCE if any of the Windows CE 64bit 
 * variants are selected
 */
#if !defined(WIN64_WCE) 
#if defined(_WIN64_WCE)
#define WIN64_WCE
#if !defined(WIN64) 
#define WIN64
#endif /* !defined(WIN64) */
#endif /* defined(_WIN64_WCE)*/
#endif /* !defined(WIN64_WCE) */

/* Define WIN32_WCE if any of the Windows CE 32bit 
 * variants are selected
 */
#if !defined(WIN32_WCE) 
#if defined(_WIN32_WCE)
#define WIN32_WCE
#if !defined(WIN32) 
#define WIN32
#endif /* !defined(WIN32) */
#endif /* defined(_WIN32_WCE)*/
#endif /* !defined(WIN32_WCE) */

/* Define WINDOWS if any of the Windows
 * variants are selected
 */
#if !defined(WINDOWS) 
#if defined(WIN64) || defined(WIN32) 
#define WINDOWS 
#else /* defined(WIN64) || defined(WIN32) */
#endif /* defined(WIN64) || defined(WIN32) */
#else /* !defined(WINDOWS) */
#endif /* !defined(WINDOWS) */

/* Select which API is to be used (Windows/Unix)
 */
#if defined(WIN32) 
/* Windows host
 */
#if !defined(WIN32_API) 
#if !defined(UNIX_API) 
#define WIN32_API
#if !defined(WINDOWS_API) 
#define WINDOWS_API 
#endif /* !defined(WINDOWS_API) */
#if defined(WIN32_WCE) 
/* Windows CE host
 */
#if !defined(WIN32_WCE_API) 
#define WIN32_WCE_API
#endif /* !defined(WIN32_WCE_API) */
#endif /* defined(WIN32_WCE) */
#endif /* !defined(UNIX_API) */
#else /* !defined(WIN32_API) */
#undef UNIX_API
#undef WIN64_API
#endif /* !defined(WIN32_API) */
#else /* defined(WIN32) */
/* Unix host
 */
#if !defined(UNIX_API) 
#if !defined(WIN32_API) 
#define UNIX_API
#else /* !defined(WIN32_API) */
#endif /* !defined(WIN32_API) */
#else /* !defined(UNIX_API) */
#undef WINDOWS_API
#undef WIN64_API
#undef WIN32_API
#undef WIN32_CE_API
#endif /* !defined(UNIX_API) */
#endif /* defined(WIN32) */

#if defined(WIN32) 
/** 
 * Windows 
 */
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <wchar.h>

#define CTHIS
#define restrict

#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

#define MSC_VER_6 1200
#define MSC_VER_7 1300
#define MSC_VER_8 1400

#if !defined(MSC_VER)
#define MSC_VER _MSC_VER
#endif /* !defined(MSC_VER) */

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

#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 */
#elif defined(WIN32_MSC_VER_7) 
/* Visual C++ 7.0 */
#elif defined(WIN32_MSC_VER_8) 
/* Visual C++ 8.0 */
#else // defined(WIN32_MSC_VER_6) 
/* Otherwise */
#endif /* defined(WIN32_MSC_VER_6) */

#if defined(WIN32_MSC_VER_6) 
/* Visual C++ 6.0 */
#pragma warning(disable:4786) /* identifier was truncated to '255'
                                 characters in the debug information */
#define NO_TEMPLATE_PARAMETER_CAST
#define NO_STD_STRING_CLEAR
#define __FUNCTION__ __function__
#define DF(name) static const char __function__[]=""#name;
typedef char INT8;
typedef short INT16;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
#else /* defined(WIN32_MSC_VER_6) */
/* Otherwise */
#define DF(name)
#pragma warning(disable:4503) /* decorated name length exceeded, name was truncated */
#pragma warning(disable:4996) /* 'function' was declared deprecated */
#endif /* defined(WIN32_MSC_VER_6) */

#pragma warning(disable:4250) // derived 'class' inherits 'base::member' via dominance
#pragma warning(disable:4355) // 'this' used in base member initializer list

typedef ULONGLONG QWORD;
typedef DWORD MODE;
typedef int MODE_T;

typedef HANDLE INVALID_HANDLE_T;
typedef HANDLE NULL_HANDLE_T;

typedef ATOM INVALID_ATOM_T;
typedef ATOM NULL_ATOM_T;

typedef SSIZE_T ssize_t;
typedef MODE_T mode_t;

typedef INT8 int8_t;
typedef INT16 int16_t;
typedef INT32 int32_t;
typedef INT64 int64_t;

typedef UINT8 uint8_t;
typedef UINT16 uint16_t;
typedef UINT32 uint32_t;
typedef UINT64 uint64_t;

#define NULL_HANDLE_VALUE NULL
#define NULL_ATOM_VALUE 0
/*
 * Windows
 **/
#else /* defined(WIN32) */
/**
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

#define DF(name)
#define NO_TEMPLATE_STATIC_MEMBERS

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

#define PLATFORM_CCAST(type) const_cast<type>
#define PLATFORM_DCAST(type) dynamic_cast<type>
#define PLATFORM_SCAST(type) static_cast<type>

#if defined(__GNUC__)
/* Gcc
 */
#define CTHIS (*this).
#if (__GNUC__ < 4)
#define PLATFORM_RCAST(type) (type)
#else /* (__GNUC__ < 4) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* (__GNUC__ < 4) */
#else /* defined(__GNUC__) */
#define PLATFORM_RCAST(type) reinterpret_cast<type>
#endif /* defined(__GNUC__) */

#if !defined(TRUE) 
#define TRUE 1
#else /* !defined(TRUE) */
#endif /* !defined(TRUE) */

#if !defined(FALSE) 
#define FALSE 0
#else /* !defined(FALSE) */
#endif /* !defined(FALSE) */

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

typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;

typedef void* PVOID;
typedef PVOID LPVOID;
typedef PVOID HMODULE;
typedef PVOID HINSTANCE;

typedef INT HANDLE;
typedef INT INVALID_HANDLE_T;
typedef INT NULL_HANDLE_T;

typedef INT ATOM;
typedef INT INVALID_ATOM_T;
typedef INT NULL_ATOM_T;

typedef char* PCHAR;
typedef PCHAR LPCHAR;

typedef TCHAR* PTCHAR;
typedef PTCHAR LPTCHAR;

typedef WCHAR* PWCHAR;
typedef PWCHAR LPWCHAR;

typedef BYTE* PBYTE;
typedef PBYTE LPBYTE;

typedef WORD* PWORD;
typedef PWORD LPWORD;

typedef DWORD* PDWORD;
typedef PDWORD LPDWORD;

typedef SHORT* PSHORT;
typedef PSHORT LPSHORT;

typedef LONG* PLONG;
typedef PLONG LPLONG;

typedef USHORT* PUSHORT;
typedef PUSHORT LPUSHORT;

typedef ULONG* PULONG;
typedef PULONG LPULONG;

typedef char* PSTR;
typedef PSTR LPSTR;

typedef const char* PCSTR;
typedef PCSTR LPCSTR;

typedef TCHAR* PTSTR;
typedef PTSTR LPTSTR;

typedef const TCHAR* PCTSTR;
typedef PCTSTR LPCTSTR;

typedef WCHAR* PWSTR;
typedef PWSTR LPWSTR;

typedef const WCHAR* PCWSTR;
typedef PCWSTR LPCWSTR;

typedef int MODE;
typedef mode_t MODE_T;
typedef size_t SIZE_T;
typedef ssize_t SSIZE_T;

#define WINAPI
#define INFINITE -1

#define INVALID_HANDLE_VALUE -1
#define NULL_HANDLE_VALUE 0

#define INVALID_ATOM_VALUE -1
#define NULL_ATOM_VALUE 0

typedef struct _SECURITY_ATTRIBUTES 
{
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, 
  *PSECURITY_ATTRIBUTES, 
  *LPSECURITY_ATTRIBUTES;

/*
 * Unix
 **/
#endif /* defined(WIN32) */

#define NULL_POINTER_VALUE ((void*)(0))
#define UNDEFINED -1
#define INVALID_HANDLE INVALID_HANDLE_VALUE
#define NULL_HANDLE NULL_HANDLE_VALUE
#define NULL_ATOM NULL_ATOM_VALUE
#define NULL_POINTER NULL_POINTER_VALUE

#if defined(NO_TEMPLATE_PARAMETER_CAST) 
/* Can't cast template parameters
 */
#define V_UNDEFINED -1
#define V_INVALID_HANDLE 0
#define V_NULL_HANDLE 0
#define V_NULL_ATOM 0
#else /* defined(NO_TEMPLATE_PARAMETER_CAST) */
#define V_UNDEFINED UNDEFINED
#define V_INVALID_HANDLE INVALID_HANDLE
#define V_NULL_HANDLE NULL_HANDLE
#define V_NULL_ATOM NULL_ATOM
#endif /* defined(NO_TEMPLATE_PARAMETER_CAST) */

#if !defined(CPLATFORM_NO_int) 
typedef INT8 int8;
typedef INT16 int16;
typedef INT32 int32;
typedef INT64 int64;
#endif /* !defined(CPLATFORM_NO_int) */

#if !defined(CPLATFORM_NO_uint) 
typedef UINT8 uint8;
typedef UINT16 uint16;
typedef UINT32 uint32;
typedef UINT64 uint64;
#endif /* !defined(CPLATFORM_NO_uint) */

typedef const CHAR* PCCHAR;
typedef const PCCHAR* PCPCCHAR;
typedef PCCHAR* PPCCHAR;
typedef PCHAR* PPCHAR;

typedef const TCHAR* PCTCHAR;
typedef const PCTCHAR* PCPCTCHAR;
typedef PCTCHAR* PPCTCHAR;
typedef PTCHAR* PPTCHAR;

typedef const WCHAR* PCWCHAR;
typedef const PCWCHAR* PCPCWCHAR;
typedef PCWCHAR* PPCWCHAR;
typedef PWCHAR* PPWCHAR;

typedef ULONG TUNSIGNED;
typedef LONG TSIGNED;
typedef ULONG TSIZE;
typedef LONG TLENGTH;
#define NULL_BYTE 0
#define NULL_CHAR 0
#define NULL_TCHAR 0
#define NULL_WCHAR 0
#define UNDEFINED_LENGTH ((TLENGTH)(-1))

typedef MODE_T MODET;
typedef SIZE_T SIZET;
typedef SSIZE_T SSIZET;

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
#else /* defined(WIN32) */
/* Unix
 */
BOOL CloseHandle(HANDLE hObject);

#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_H */

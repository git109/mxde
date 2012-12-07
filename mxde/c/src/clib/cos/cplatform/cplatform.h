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
 *   File: cplatform.h
 *
 * Author: $author$
 *   Date: 2/18/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_H
#define _CPLATFORM_H

#ifndef _PLATFORM_H
#define _PLATFORM_H
#endif /* _PLATFORM_H */

/*
 **********************************************************************
 *
 * Build Environment
 *
 **********************************************************************
 */
#include "cplatform_build.h"

/*
 **********************************************************************
 *
 * Compiler
 *
 **********************************************************************
 */
#include "cplatform_compiler.h"

/*
 **********************************************************************
 *
 * Includes
 *
 **********************************************************************
 */
 
#if defined(WINDOWS) 
/* Windows
 */

#if !defined(_WINDOWS_) 
#define _INC_WINDOWS
#include <windows.h>
#if !defined(_WIN32_WINNT) 
#if (WINVER >= 0x0500)
#define _WIN32_WINNT WINVER
#endif /* (WINVER >= 0x500) */
#endif /* !defined(_WIN32_WINNT) */
#undef _INC_WINDOWS
#undef _WINDOWS_
#else /* !defined(_WINDOWS_) */
#endif /* !defined(_WINDOWS_) */

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <wchar.h>
#include <stdarg.h>
#include <stdio.h>
#else /* defined(WINDOWS) */
/* Unix
 */
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#endif /* defined(WINDOWS) */

/*
 **********************************************************************
 *
 * Defines
 *
 **********************************************************************
 */
 
#if defined(WINDOWS) 
/* Windows
 * ...
 */
 
#if !defined(__GNUC__) 
/* Visual C++
 * ...
 */
/* ...
 * Visual C++
 */
#else /* !defined(__GNUC__) */
/*
 * Gcc
 * ...
 */
#if defined(CPLATFORM_DEFINED_DEBUG) 
#warning Compiler other than Visual C++ (Gcc) being used
#endif /* defined(CPLATFORM_DEFINED_DEBUG) */
/*
 * ...
 * Gcc
 */
#endif /* !defined(__GNUC__) */
 
#if defined(UNICODE) 
#define TCHAR_NOT_CHAR
#endif /* defined(UNICODE) */

#define PLATFORM_EXPORT __declspec(dllexport)
#define PLATFORM_IMPORT __declspec(dllimport)

/* ...
 * Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 * ...
 */
 
#if defined(__GNUC__) 
/* Gcc
 * ...
 */
/* ...
 * Gcc
 */
#else /* defined(__GNUC__) */
#error Compiler other than Gcc not supported
#endif /* defined(__GNUC__) */

#define PLATFORM_EXPORT
#define PLATFORM_IMPORT

/* ...
 * Unix
 */
#endif /* defined(WINDOWS) */

/* Generic
 * ...
 */
#define c_EXPORT PLATFORM_EXPORT

#define UNDEFINED -1

#define INVALID_HANDLE INVALID_HANDLE_VALUE
#define NULL_HANDLE NULL_HANDLE_VALUE
#define NULL_ATOM NULL_ATOM_VALUE

#define NULL_BYTE 0
#define NULL_CHAR 0
#define NULL_TCHAR 0
#define NULL_WCHAR 0

#if defined(NO_TEMPLATE_PARAMETER_CAST) 
/* Can't cast template parameters
 */
#define V_INVALID_HANDLE 0
#define V_NULL_HANDLE 0
#define V_NULL_ATOM 0
#else /* defined(NO_TEMPLATE_PARAMETER_CAST) */
#define V_INVALID_HANDLE INVALID_HANDLE
#define V_NULL_HANDLE NULL_HANDLE
#define V_NULL_ATOM NULL_ATOM
#endif /* defined(NO_TEMPLATE_PARAMETER_CAST) */
/* ...
 * Generic
 */

/*
 **********************************************************************
 *
 * Types
 *
 **********************************************************************
 */
 
#if defined(WINDOWS) 
/* Windows
 * ...
 */
 
#if !defined(__GNUC__) 
/* Visual C++
 * ...
 */
 
/* Visual C++ version specific definitions
 */
#if defined(WINDOWS_MSC_VER_6) 
/* Visual C++ 6.0 
 */
typedef char INT8;
typedef short INT16;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
#else /* defined(WINDOWS_MSC_VER_6) */
/* Visual C++ 7.0 or greater 
 */
#endif /* defined(WINDOWS_MSC_VER_6) */

typedef INT8 int8_t;
typedef INT16 int16_t;
typedef INT32 int32_t;
typedef INT64 int64_t;

typedef UINT8 uint8_t;
typedef UINT16 uint16_t;
typedef UINT32 uint32_t;
typedef UINT64 uint64_t;

typedef int MODE_T;
typedef MODE_T mode_t;

/* ...
 * Visual C++
 */
#else /* !defined(__GNUC__) */
/* Gcc
 * ...
 */
#if defined(CPLATFORM_DEFINED_DEBUG) 
#warning Compiler other than Visual C++ (Gcc) being used
#endif /* defined(CPLATFORM_DEFINED_DEBUG) */

typedef char INT8;
typedef short INT16;
typedef unsigned char UINT8;
typedef unsigned short UINT16;

typedef int MODE_T;
#define PCCHAR PCCHAR_T

/* ...
 * Gcc
 */
#endif /* !defined(__GNUC__) */
 
typedef ULONGLONG QWORD;

typedef DWORD MODE;

typedef SSIZE_T ssize_t;

typedef HANDLE INVALID_HANDLE_T;
typedef HANDLE NULL_HANDLE_T;
#define NULL_HANDLE_VALUE NULL

typedef ATOM INVALID_ATOM_T;
typedef ATOM NULL_ATOM_T;
#define NULL_ATOM_VALUE 0

/* ...
 * Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 * ...
 */

typedef int BOOL;

typedef char CHAR;
typedef char TCHAR;
typedef wchar_t WCHAR;

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

#define INFINITE -1

#define INVALID_HANDLE_VALUE -1
#define NULL_HANDLE_VALUE 0

#define INVALID_ATOM_VALUE -1
#define NULL_ATOM_VALUE 0

/* ...
 * Unix
 */
#endif /* defined(WINDOWS) */

/* Generic
 * ...
 */
typedef ULONG TUNSIGNED;
typedef LONG TSIGNED;
typedef ULONG TSIZE;
typedef LONG TCOUNT;
typedef LONG TOFFSET;
typedef LONG TLENGTH;
#define UNDEFINED_LENGTH ((TLENGTH)(-1))

typedef MODE_T MODET;
typedef SIZE_T SIZET;
typedef SSIZE_T SSIZET;

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

typedef const BYTE* PCBYTE;
typedef const PCBYTE* PCPCBYTE;
typedef PCBYTE* PPCBYTE;
typedef PBYTE* PPBYTE;
/* ...
 * Generic
 */
 
#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_H */

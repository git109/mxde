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

#if defined(WIN32)
/*
 * Windows
 */
#include <windows.h>
#include <tchar.h>
#include <wchar.h>

#if defined(_WIN32_WCE)
/*
 * Windows CE
 */
#if defined(__cplusplus)
#define throw(ex) cException::Throw(ex)
#endif
#endif /* defined(_WIN32_WCE) */

#define _W(str) L##str
typedef ULONG64 QWORD;

#define wdt_enable(time)
#define wdt_disable()
#define wdt_reset()

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
#include <stdint.h>

#define _T(str) str
typedef char TCHAR;
typedef short WCHAR;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef uint32_t DWORD;
typedef uint64_t QWORD;
#endif /* defined(WIN32) */

typedef unsigned char byte;
typedef unsigned char octet;
typedef unsigned char opaque;

#if defined(WIN32)
/*
 * Windows
 */
typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef int8 int24[3];
typedef uint8 uint24[3];

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
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(EMBEDDED) 
#define platform_void_main main
#else /* defined(EMBEDDED) */
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

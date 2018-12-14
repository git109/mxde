/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: platform.h
 * 
 * These are platform specific types and definitions.
 ************************************************************
 */
 
#ifndef _PLATFORM_H
#define _PLATFORM_H

#if defined(__cplusplus)
#else
#define bool int
#define false 0
#define true  1
#endif

#if defined(LINUX)
#include <linux/types.h>
#else

/* Let's follow the linux model. For user space only use __u*.
 * For kernel space use __u* and u*.
 */
#if defined(__KERNEL__)
#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned long
#endif

#define __u8 unsigned char
#define __u16 unsigned short
#define __u32 unsigned long

#endif

#endif

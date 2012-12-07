/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cplatform_time.h
 *
 * Author: $author$
 *   Date: 9/27/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_TIME_H
#define _CPLATFORM_TIME_H

#include "cplatform.h"

#if defined(CPLATFORM_HAS_NO_TIME_H) 
#else /* defined(CPLATFORM_HAS_NO_TIME_H) */
#include <time.h>
#endif /* defined(CPLATFORM_HAS_NO_TIME_H) */

#if defined(CPLATFORM_HAS_NO_TIME_H) 
struct tm 
{
    int tm_sec;   /* Seconds [0..60] */
    int tm_min;   /* Minutes [0..59] */
    int tm_hour;  /* Hour [0..23] */
    int tm_mday;  /* Day of month [1..31] */
    int tm_mon;   /* Month of year [0..11] */
    int tm_year;  /* Years since 1900 */
    int tm_wday;  /* Day of week [0..6] (Sunday = 0) */
    int tm_yday;  /* Day of year [0..365] */
    int tm_isdst; /* Daylight Savings [0..1] */
};
#else /* defined(CPLATFORM_HAS_NO_TIME_H) */
#endif /* defined(CPLATFORM_HAS_NO_TIME_H) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(CPLATFORM_HAS_NO_TIME_H) 
extern time_t time(time_t *t);
extern struct tm *localtime(const time_t *);
#else /* defined(CPLATFORM_HAS_NO_TIME_H) */
#endif /* defined(CPLATFORM_HAS_NO_TIME_H) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_TIME_H */

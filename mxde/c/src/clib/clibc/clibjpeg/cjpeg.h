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
 *   File: cjpeg.h
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#ifndef _CJPEG_H
#define _CJPEG_H

#include "cplatform.h"

#define OLD_FAR FAR
#undef FAR

#define OLD_INT32 INT32
#undef INT32
#define INT32 JPEG_INT32

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#include "jpeglib.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#undef INT32
#define INT32 OLD_INT32
#undef OLD_INT32

#undef FAR
#define FAR OLD_FAR
#undef OLD_FAR

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CJPEG_H */

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
 *   File: cplatform_path.h
 *
 * Author: $author$
 *   Date: 9/26/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_PATH_H
#define _CPLATFORM_PATH_H

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 */
#define CPLATFORM_PATH_SEPARATOR_CHAR ';'
#define CPLATFORM_FOREIGN_PATH_SEPARATOR_CHAR ':'

#define CPLATFORM_VOLUME_SEPARATOR_CHAR ':'
#define CPLATFORM_FOREIGN_VOLUME_SEPARATOR_CHAR 0

#define CPLATFORM_DIRECTORY_SEPARATOR_CHAR '\\'
#define CPLATFORM_FOREIGN_DIRECTORY_SEPARATOR_CHAR '/'
#else /* defined(WINDOWS) */
/* Unix
 */
#define CPLATFORM_PATH_SEPARATOR_CHAR ':'
#define CPLATFORM_FOREIGN_PATH_SEPARATOR_CHAR ';'

#define CPLATFORM_VOLUME_SEPARATOR_CHAR 0
#define CPLATFORM_FOREIGN_VOLUME_SEPARATOR_CHAR ':'

#define CPLATFORM_DIRECTORY_SEPARATOR_CHAR '/'
#define CPLATFORM_FOREIGN_DIRECTORY_SEPARATOR_CHAR '\\'
#endif /* defined(WINDOWS) */

#define CPLATFORM_EXTENSION_SEPARATOR_CHAR '.'
#define CPLATFORM_FOREIGN_EXTENSION_SEPARATOR_CHAR CPLATFORM_EXTENSION_SEPARATOR_CHAR

#define CPLATFORM_PATH_WILDCARD_CHAR '*'
#define CPLATFORM_FOREIGN_PATH_WILDCARD_CHAR CPLATFORM_PATH_WILDCARD_CHAR

#define CPLATFORM_PATH_ENV_NAME "PATH"
#define CPLATFORM_FOREIGN_PATH_ENV_NAME CPLATFORM_PATH_ENV_NAME

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_PATH_H */

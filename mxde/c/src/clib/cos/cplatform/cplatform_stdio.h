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
 *   File: cplatform_stdio.h
 *
 * Author: $author$
 *   Date: 3/13/2009
 **********************************************************************
 */
#ifndef _CPLATFORM_STDIO_H
#define _CPLATFORM_STDIO_H

#include "cplatform.h"
#include <stdio.h>

#if defined(WINDOWS) 
/* Windows
 */
#define CPLATFORM_FILE_MODE_BINARY "b"
#else /* defined(WINDOWS) */
/* Unix
 */
#define CPLATFORM_FILE_MODE_BINARY
#endif /* defined(WINDOWS) */

#define CPLATFORM_FILE_MODE_READ "r"
#define CPLATFORM_FILE_MODE_WRITE "w"

#define CPLATFORM_FILE_MODE_READ_BINARY \
        CPLATFORM_FILE_MODE_READ \
        CPLATFORM_FILE_MODE_BINARY
        
#define CPLATFORM_FILE_MODE_WRITE_BINARY \
        CPLATFORM_FILE_MODE_WRITE \
        CPLATFORM_FILE_MODE_BINARY
        
/**
 **********************************************************************
 *   Enum:  eSeek
 *
 * Author: $author$
 *   Date: 3/13/2009
 **********************************************************************
 */
typedef int eSeek;
enum
{
    e_FIRST_SEEK = 0,

    e_SEEK_SET = e_FIRST_SEEK,
    e_SEEK_CUR,
    e_SEEK_END,

    e_NEXT_SEEK,
    e_LAST_SEEK = e_NEXT_SEEK-1,
    e_COUNT_SEEK = e_LAST_SEEK-e_FIRST_SEEK+1
};

#define e_SEEK_NAME_SET "SET"
#define e_SEEK_NAME_CUR "CUR"
#define e_SEEK_NAME_END "END"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern int g_e_seek_value[e_COUNT_SEEK];
extern const char* g_e_seek_name[e_COUNT_SEEK];

#if defined(FIRMWARE) 
FILE *cplatform_fopen(const char *path, const char *mode);
FILE *cplatform_fdopen(int fildes, const char *mode);
FILE *cplatform_freopen(const char *path, const char *mode, FILE *stream);
int cplatform_fclose(FILE *fp);
size_t cplatform_fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t cplatform_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int cplatform_fseek(FILE *stream, long offset, int whence);
long cplatform_ftell(FILE *stream);
void cplatform_rewind(FILE *stream);
int cplatform_fgetpos(FILE *stream, fpos_t *pos);
int cplatform_fsetpos(FILE *stream, fpos_t *pos);
#else /* defined(FIRMWARE) */
#endif /* defined(FIRMWARE) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_STDIO_H */

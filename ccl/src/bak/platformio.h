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
 *   File: platformio.h
 *
 * Author: $author$
 *   Date: 7/19/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _PLATFORMIO_H
#define _PLATFORMIO_H

#include <sys/stat.h>
#include <fcntl.h>

#if defined(WIN32)
#include <io.h>
#define INVALID_HANDLE NULL
#else /* defined(WIN32) */
#define INVALID_HANDLE -1
#define HANDLE int
#endif /* defined(WIN32) */

#if defined(WIN32)
/*
 * Windows oflags
 */
#define PLATFORMIO_O_APPEND     _O_APPEND    
#define PLATFORMIO_O_BINARY     _O_BINARY    
#define PLATFORMIO_O_CREAT      _O_CREAT     
#define PLATFORMIO_O_EXCL       _O_EXCL      
#define PLATFORMIO_O_NONBLOCK   0  
#define PLATFORMIO_O_RANDOM     _O_RANDOM    
#define PLATFORMIO_O_RDONLY     _O_RDONLY    
#define PLATFORMIO_O_RDWR       _O_RDWR      
#define PLATFORMIO_O_SEQUENTIAL _O_SEQUENTIAL
#define PLATFORMIO_O_SYNC       0      
#define PLATFORMIO_O_TEMPORARY  _O_TEMPORARY 
#define PLATFORMIO_O_TEXT       _O_TEXT      
#define PLATFORMIO_O_TRUNC      _O_TRUNC     
#define PLATFORMIO_O_WRONLY     _O_WRONLY    

#define PLATFORMIO_HAS_O_APPEND     1    
#define PLATFORMIO_HAS_O_BINARY     1   
#define PLATFORMIO_HAS_O_CREAT      1    
#define PLATFORMIO_HAS_O_EXCL       1     
#define PLATFORMIO_HAS_O_NONBLOCK   0  
#define PLATFORMIO_HAS_O_RANDOM     1   
#define PLATFORMIO_HAS_O_RDONLY     1    
#define PLATFORMIO_HAS_O_RDWR       1     
#define PLATFORMIO_HAS_O_SEQUENTIAL 1
#define PLATFORMIO_HAS_O_SYNC       0      
#define PLATFORMIO_HAS_O_TEMPORARY  1
#define PLATFORMIO_HAS_O_TEXT       1      
#define PLATFORMIO_HAS_O_TRUNC      1  
#define PLATFORMIO_HAS_O_WRONLY     1   

/*
 * Windows omodes
 */
#define PLATFORMIO_S_IREAD  _S_IREAD 
#define PLATFORMIO_S_IWRITE _S_IWRITE
#define PLATFORMIO_S_IEXEC  0
#define PLATFORMIO_S_IRUSR  _S_IREAD 
#define PLATFORMIO_S_IWUSR  _S_IWRITE
#define PLATFORMIO_S_IXUSR  0
#define PLATFORMIO_S_IRGRP  0
#define PLATFORMIO_S_IWGRP  0
#define PLATFORMIO_S_IXGRP  0
#define PLATFORMIO_S_IROTH  0
#define PLATFORMIO_S_IWOTH  0
#define PLATFORMIO_S_IXOTH  0
#define PLATFORMIO_S_IRWXU  0
#define PLATFORMIO_S_IRWXG  0
#define PLATFORMIO_S_IRWXO  0

#define PLATFORMIO_HAS_S_IREAD  1
#define PLATFORMIO_HAS_S_IWRITE 1
#define PLATFORMIO_HAS_S_IEXEC  1
#define PLATFORMIO_HAS_S_IRUSR  1
#define PLATFORMIO_HAS_S_IWUSR  1
#define PLATFORMIO_HAS_S_IXUSR  1
#define PLATFORMIO_HAS_S_IRGRP  0
#define PLATFORMIO_HAS_S_IWGRP  0
#define PLATFORMIO_HAS_S_IXGRP  0
#define PLATFORMIO_HAS_S_IROTH  0
#define PLATFORMIO_HAS_S_IWOTH  0
#define PLATFORMIO_HAS_S_IXOTH  0
#define PLATFORMIO_HAS_S_IRWXU  0
#define PLATFORMIO_HAS_S_IRWXG  0
#define PLATFORMIO_HAS_S_IRWXO  0

#else /* defined(WIN32) */
/*
 * Unix oflags
 */
#define PLATFORMIO_O_APPEND     O_APPEND    
#define PLATFORMIO_O_BINARY     0    
#define PLATFORMIO_O_CREAT      O_CREAT     
#define PLATFORMIO_O_EXCL       O_EXCL      
#define PLATFORMIO_O_NONBLOCK   O_NONBLOCK  
#define PLATFORMIO_O_RANDOM     0    
#define PLATFORMIO_O_RDONLY     O_RDONLY    
#define PLATFORMIO_O_RDWR       O_RDWR      
#define PLATFORMIO_O_SEQUENTIAL 0
#define PLATFORMIO_O_SYNC       O_SYNC      
#define PLATFORMIO_O_TEMPORARY  0
#define PLATFORMIO_O_TEXT       0      
#define PLATFORMIO_O_TRUNC      O_TRUNC     
#define PLATFORMIO_O_WRONLY     O_WRONLY    

#define PLATFORMIO_HAS_O_APPEND     1    
#define PLATFORMIO_HAS_O_BINARY     0   
#define PLATFORMIO_HAS_O_CREAT      1    
#define PLATFORMIO_HAS_O_EXCL       1     
#define PLATFORMIO_HAS_O_NONBLOCK   1  
#define PLATFORMIO_HAS_O_RANDOM     0   
#define PLATFORMIO_HAS_O_RDONLY     1    
#define PLATFORMIO_HAS_O_RDWR       1     
#define PLATFORMIO_HAS_O_SEQUENTIAL 0
#define PLATFORMIO_HAS_O_SYNC       1      
#define PLATFORMIO_HAS_O_TEMPORARY  0
#define PLATFORMIO_HAS_O_TEXT       0      
#define PLATFORMIO_HAS_O_TRUNC      1  
#define PLATFORMIO_HAS_O_WRONLY     1   

/*
 * Unix omodes
 */
#define PLATFORMIO_S_IREAD  S_IREAD 
#define PLATFORMIO_S_IWRITE S_IWRITE
#define PLATFORMIO_S_IEXEC  S_IEXEC 
#define PLATFORMIO_S_IRUSR  S_IRUSR 
#define PLATFORMIO_S_IWUSR  S_IWUSR 
#define PLATFORMIO_S_IXUSR  S_IXUSR 
#define PLATFORMIO_S_IRGRP  S_IRGRP 
#define PLATFORMIO_S_IWGRP  S_IWGRP 
#define PLATFORMIO_S_IXGRP  S_IXGRP 
#define PLATFORMIO_S_IROTH  S_IROTH 
#define PLATFORMIO_S_IWOTH  S_IWOTH 
#define PLATFORMIO_S_IXOTH  S_IXOTH 
#define PLATFORMIO_S_IRWXU  S_IRWXU 
#define PLATFORMIO_S_IRWXG  S_IRWXG 
#define PLATFORMIO_S_IRWXO  S_IRWXO 

#define PLATFORMIO_HAS_S_IREAD  1
#define PLATFORMIO_HAS_S_IWRITE 1
#define PLATFORMIO_HAS_S_IEXEC  1
#define PLATFORMIO_HAS_S_IRUSR  1
#define PLATFORMIO_HAS_S_IWUSR  1
#define PLATFORMIO_HAS_S_IXUSR  1
#define PLATFORMIO_HAS_S_IRGRP  1
#define PLATFORMIO_HAS_S_IWGRP  1
#define PLATFORMIO_HAS_S_IXGRP  1
#define PLATFORMIO_HAS_S_IROTH  1
#define PLATFORMIO_HAS_S_IWOTH  1
#define PLATFORMIO_HAS_S_IXOTH  1
#define PLATFORMIO_HAS_S_IRWXU  1
#define PLATFORMIO_HAS_S_IRWXG  1
#define PLATFORMIO_HAS_S_IRWXO  1

#endif /* defined(WIN32) */

#define PLATFORMIO_SEEK_SET SEEK_SET 
#define PLATFORMIO_SEEK_CUR SEEK_CUR 
#define PLATFORMIO_SEEK_END SEEK_END 

#endif

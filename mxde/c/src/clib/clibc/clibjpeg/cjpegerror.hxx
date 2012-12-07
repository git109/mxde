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
 *   File: cjpegerror.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#ifndef _CJPEGERROR_HXX
#define _CJPEGERROR_HXX

/**
 **********************************************************************
 *   Enum: eJPEGError
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
enum eJPEGError
{
    e_JPEG_ERROR_FIRST,

    e_JPEG_ERROR_NONE = 0,
    e_JPEG_ERROR_FAILED = 1,

    e_JPEG_ERROR_NEXT,
    e_JPEG_ERROR_LAST = e_JPEG_ERROR_NEXT-1,
    e_JPEG_ERROR_COUNT = e_JPEG_ERROR_LAST-e_JPEG_ERROR_FIRST+1
};

#endif /* _CJPEGERROR_HXX */

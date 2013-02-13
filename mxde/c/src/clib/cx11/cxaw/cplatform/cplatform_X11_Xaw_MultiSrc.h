/* $Xorg: MultiSrc.h,v 1.4 2001/02/09 02:03:44 xorgcvs Exp $ */

/*
 * Copyright 1991 by OMRON Corporation
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name OMRON not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  OMRON makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * OMRON DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL OMRON BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTUOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 *      Author: Li Yuhong	 OMRON Corporation
 */

/*

Copyright 1989, 1991, 1994, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/
/* $XFree86: xc/lib/Xaw/MultiSrc.h,v 1.6 2001/01/17 19:42:28 dawes Exp $ */

/*
 * This file was modified from AsciiSrc.h.
 *
 * By Li Yuhong, Sept. 18, 1990
 */

/**
 **********************************************************************
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
 *   File: cplatform_X11_Xaw_MultiSrc.h
 *
 * Author: $author$           
 *   Date: 5/5/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_XAW_MULTISRC_H
#define _CPLATFORM_X11_XAW_MULTISRC_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/Xaw/MultiSrc.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_X11_Xaw_TextSrc.h"

/* Resources:

 Name		     Class		RepType		Default Value
 ----		     -----		-------		-------------
 dataCompression     DataCompression	Boolean		True
 length		     Length		int		(internal)
 pieceSize	     PieceSize		int		BUFSIZ
 string		     String		String		NULL
 type		     Type		XawAsciiType	XawAsciiString
 useStringInPlace    UseStringInPlace	Boolean		False

*/
 
extern WidgetClass multiSrcObjectClass;

typedef struct _MultiSrcClassRec *MultiSrcObjectClass;
typedef struct _MultiSrcRec      *MultiSrcObject;

#define MultiSourceObjectClass MultiSrcObjectClass
#define MultiSourceObject      MultiSrcObject

#define XtCDataCompression "DataCompression"
#define XtCPieceSize "PieceSize"
#define XtCType "Type"
#define XtCUseStringInPlace "UseStringInPlace"

#define XtNdataCompression "dataCompression"
#define XtNpieceSize "pieceSize"
#define XtNtype "type"
#define XtNuseStringInPlace "useStringInPlace"

#define XtRMultiType "MultiType"

#define XtEstring "string"
#define XtEfile "file"

/************************************************************
 *
 * THESE ROUTINES ARE NOT PUBLIC: Source should call
 *
 * the AsciiSrc API which currently forwards requests here.
 *
 * future versions (like theres going to be an R7 Xaw!) may
 *
 * eliminate this file or at least these functions entirely.
 *
 ************************************************************/

_XFUNCPROTOBEGIN

void XawMultiSourceFreeString
(
 Widget			w
 );

Bool _XawMultiSave
(
 Widget			w
);

Bool _XawMultiSaveAsFile
(
 Widget			w,
 _Xconst char		*name
 );

_XFUNCPROTOEND

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_XAW_MULTISRC_H */

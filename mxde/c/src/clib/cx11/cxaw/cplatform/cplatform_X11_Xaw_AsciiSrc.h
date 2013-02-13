/* $Xorg: AsciiSrc.h,v 1.4 2001/02/09 02:03:42 xorgcvs Exp $ */

/*

Copyright 1989, 1994, 1998  The Open Group

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
/* $XFree86: xc/lib/Xaw/AsciiSrc.h,v 1.7 2001/01/17 19:42:25 dawes Exp $ */


/*
 * AsciiSrc.h - Public Header file for Ascii Text Source.
 *
 * This is the public header file for the Ascii Text Source.
 * It is intended to be used with the Text widget, the simplest way to use
 * this text source is to use the AsciiText Object.
 *
 * Date:    June 29, 1989
 *
 * By:      Chris D. Peterson
 *          MIT X Consortium 
 *          kit@expo.lcs.mit.edu
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
 *   File: cplatform_X11_Xaw_AsciiSrc.h
 *
 * Author: $author$           
 *   Date: 5/5/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_XAW_ASCIISRC_H
#define _CPLATFORM_X11_XAW_ASCIISRC_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/Xaw/AsciiSrc.h>
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
 
extern WidgetClass asciiSrcObjectClass;

typedef struct _AsciiSrcClassRec *AsciiSrcObjectClass;
typedef struct _AsciiSrcRec      *AsciiSrcObject;

#define AsciiSourceObjectClass AsciiSrcObjectClass
#define AsciiSourceObject      AsciiSrcObject

/*
 * Resource Definitions
 */
#define XtCDataCompression "DataCompression"
#define XtCPieceSize "PieceSize"
#define XtCType "Type"
#define XtCUseStringInPlace "UseStringInPlace"

#define XtNdataCompression "dataCompression"
#define XtNpieceSize "pieceSize"
#define XtNtype "type"
#define XtNuseStringInPlace "useStringInPlace"

#define XtRAsciiType "AsciiType"

#define XtEstring "string"
#define XtEfile "file"

typedef enum {
  XawAsciiFile,
  XawAsciiString
} XawAsciiType;

/*
 * Public routines
 */

_XFUNCPROTOBEGIN

/*
 * Function:
 *	XawAsciiSourceFreeString
 *
 * Parameters:
 *	w - AsciiSrc object
 *
 * Description:
 *	  Frees the string returned by a get values call
 *		     on the string when the source is of type string.
 */
void XawAsciiSourceFreeString
(
 Widget		w
 );

/*
 * Function:
 *	XawAsciiSave
 *
 * Arguments:
 *	w - asciiSrc Object.
 *
 * Description:
 *	Saves all the pieces into a file or string as required.
 *
 * Returns:
 *	True if the save was successful
 */
Bool XawAsciiSave
(
 Widget		w
 );

/*
 * Function:
 *	XawAsciiSaveAsFile
 *
 * Parameters:
 *	w    - asciiSrc object
 *	name - name of the file to save this file into
 *
 * Description:
 *	Save the current buffer as a file.
 *
 * Returns:
 *	True if the save was successful
 */
Bool XawAsciiSaveAsFile
(
 Widget		w,
 _Xconst char	*name
 );

/*
 * Function:
 *	XawAsciiSourceChanged
 *
 * Parameters:
 *	w - asciiSource object
 *
 * Description:
 *	Returns true if the source has changed since last saved.
 *
 * Returns:
 *	a Boolean (see description)
 */
Bool XawAsciiSourceChanged
(
 Widget		w
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

#endif /* _CPLATFORM_X11_XAW_ASCIISRC_H */

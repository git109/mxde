/*
 * $Xorg: AsciiText.h,v 1.4 2001/02/09 02:03:42 xorgcvs Exp $
 */

/***********************************************************

Copyright 1987, 1988, 1994, 1998  The Open Group

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


Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/
/* $XFree86: xc/lib/Xaw/AsciiText.h,v 1.5 2001/01/17 19:42:25 dawes Exp $ */

/*
 * AsciiText.h - Public header file for AsciiText Widget
 *
 * This Widget is intended to be used as a simple front end to the 
 * text widget with an ascii source and ascii sink attached to it
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
 *   File: cplatform_X11_Xaw_AsciiText.h
 *
 * Author: $author$           
 *   Date: 5/5/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_XAW_ASCIITEXT_H
#define _CPLATFORM_X11_XAW_ASCIITEXT_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/Xaw/AsciiText.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_X11_Xaw_Text.h"
#include "cplatform_X11_Xaw_AsciiSrc.h"
#include "cplatform_X11_Xaw_MultiSrc.h"

/* Resources:

 Name		     Class		RepType		  Default Value
 ----		     -----		-------		  -------------
 autoFill	     AutoFill		Boolean		  False
 background	     Background		Pixel		  XtDefaultBackground
 border		     BorderColor	Pixel		  XtDefaultForeground
 borderWidth	     BorderWidth	Dimension	  1
 bottomMargin	     Margin		Position	  2
 cursor		     Cursor		Cursor		  xterm
 destroyCallback     Callback		Pointer		  NULL
 displayCaret	     Output		Boolean		  True
 displayPosition     TextPosition	int		  0
 editType	     EditType		XawTextEditType	  XawtextRead
 font		     Font		XFontStruct*	  Fixed
 foreground	     Foreground		Pixel		  Black
 height		     Height		Dimension	  font height
 insertPosition	     TextPosition	int		  0
 international	     International		Boolean		false
 leftMargin	     Margin		Position	  2
 mappedWhenManaged   MappedWhenManaged	Boolean		  True
 resize		     Resize		XawTextResizeMode XawtextResizeNever
 rightMargin	     Margin		Position	  4
 scrollHorizontal    Scroll		XawTextScrollMode XawtextScrollNever
 scrollVertical	     Scroll		XawTextScrollMode XawtextScrollNever
 selectTypes	     SelectTypes	Pointer		  pos/word/line/par/all
 selection	     Selection		Pointer		  (empty selection)
 sensitive	     Sensitive		Boolean		  True
 sink		     TextSink		Widget		  (none)
 source		     TextSource		Widget		  (none)
 string		     String		String		  NULL
 topMargin	     Margin		Position	  2
 width		     Width		Dimension	  100
 wrap		     Wrap		XawTextWrapMode	  XawtextWrapNever
 x		     Position		Position	  0
 y		     Position		Position	  0

 (see also *Src.h and *Sink.h)
*/

typedef struct _AsciiTextClassRec	*AsciiTextWidgetClass;
typedef struct _AsciiRec	        *AsciiWidget;

extern WidgetClass asciiTextWidgetClass;

/*
 * Disk and String Emulation Info
 */
#ifdef ASCII_STRING
extern WidgetClass asciiStringWidgetClass;
#endif

#ifdef ASCII_DISK
extern WidgetClass asciiDiskWidgetClass;
#endif

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_XAW_ASCIITEXT_H */

/* $Xorg: Converters.h,v 1.5 2001/02/09 02:03:51 xorgcvs Exp $ */

/*
 
Copyright 1988, 1998  The Open Group

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

/* $XFree86: xc/lib/Xmu/Converters.h,v 1.5 2001/01/17 19:42:53 dawes Exp $ */

/*
 * The interfaces described by this header file are for miscellaneous utilities
 * and are not part of the Xlib standard.
 */

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
 *   File: cplatform_X11_Xmu_Converters.h
 *
 * Author: $author$           
 *   Date: 5/5/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_XMU_CONVERTERS_H
#define _CPLATFORM_X11_XMU_CONVERTERS_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/Xmu/Converters.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_X11_Intrinsic.h"
#include "cplatform_X11_Xfuncproto.h"

_XFUNCPROTOBEGIN

void XmuCvtFunctionToCallback
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

#define XtNbackingStore "backingStore"
#define XtCBackingStore "BackingStore"
#define XtRBackingStore "BackingStore"
#define XtEnotUseful "notUseful"
#define XtEwhenMapped "whenMapped"
#define XtEalways "always"
#define XtEdefault "default"
void XmuCvtStringToBackingStore
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

Boolean XmuCvtBackingStoreToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

void XmuCvtStringToCursor
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

#define XtRColorCursor "ColorCursor"
#define XtNpointerColor "pointerColor"
#define XtNpointerColorBackground "pointerColorBackground"
Boolean XmuCvtStringToColorCursor
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

typedef int XtGravity;

#ifndef XtRGravity
#define XtRGravity "Gravity"
#endif
#define XtEForget "forget"
#define XtENorthWest "northwest"
#define XtENorth "north"
#define XtENorthEast "northeast"
#define XtEWest "west"
#define XtECenter "center"
#define XtEEast "east"
#define XtESouthWest "southwest"
#define XtESouth "south"
#define XtESouthEast "southeast"
#define XtEStatic "static"
#define XtEUnmap "unmap"
void XmuCvtStringToGravity
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

Boolean XmuCvtGravityToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

typedef enum {
    XtJustifyLeft,       /* justify text to left side of button   */
    XtJustifyCenter,     /* justify text in center of button      */
    XtJustifyRight       /* justify text to right side of button  */
} XtJustify;
#ifndef XtRJustify
#define XtRJustify "Justify"
#endif
#define XtEleft "left"
#define XtEcenter "center"
#define XtEright "right"
#define XtEtop "top"
#define XtEbottom "bottom"
void XmuCvtStringToJustify
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

Boolean XmuCvtJustifyToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

#define XtRLong "Long"
void XmuCvtStringToLong
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );
Boolean XmuCvtLongToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

typedef enum {
  XtorientHorizontal,
  XtorientVertical
} XtOrientation;
void XmuCvtStringToOrientation
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

Boolean XmuCvtOrientationToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

void XmuCvtStringToBitmap
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

#define XtRShapeStyle "ShapeStyle"
#define XtERectangle "Rectangle"
#define XtEOval "Oval"
#define XtEEllipse "Ellipse"
#define XtERoundedRectangle "RoundedRectangle"

#define XmuShapeRectangle 1
#define XmuShapeOval 2
#define XmuShapeEllipse 3
#define XmuShapeRoundedRectangle 4

Boolean XmuCvtStringToShapeStyle
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

Boolean XmuCvtShapeStyleToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal,
 XtPointer		*converter_data
 );

Boolean XmuReshapeWidget
(
 Widget			w,
 int			shape_style,
 int			corner_width,
 int			corner_height
 );

void XmuCvtStringToWidget
(
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValuePtr		fromVal,
 XrmValuePtr		toVal
 );

Boolean XmuNewCvtStringToWidget
(
 Display		*display,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValue		*fromVal,
 XrmValue		*toVal,
 XtPointer		*converter_data
 );

Boolean XmuCvtWidgetToString
(
 Display		*dpy,
 XrmValue		*args,
 Cardinal		*num_args,
 XrmValue		*fromVal,
 XrmValue		*toVal,
 XtPointer		*converter_data
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

#endif /* _CPLATFORM_X11_XMU_CONVERTERS_H */

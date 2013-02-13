/* $XFree86: xc/include/extensions/shape.h,v 1.3 2001/12/14 19:53:29 dawes Exp $ */
/************************************************************

Copyright 1989, 1998  The Open Group

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

********************************************************/

/* $Xorg: shape.h,v 1.4 2001/02/09 02:03:24 xorgcvs Exp $ */

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
 *   File: cplatform_X11_extensions_shape.h
 *
 * Author: $author$           
 *   Date: 5/4/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_EXTENSIONS_SHAPE_H
#define _CPLATFORM_X11_EXTENSIONS_SHAPE_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/extensions/shape.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_X11_Xfuncproto.h"

#define X_ShapeQueryVersion		0
#define X_ShapeRectangles		1
#define X_ShapeMask			2
#define X_ShapeCombine			3
#define X_ShapeOffset			4
#define X_ShapeQueryExtents		5
#define X_ShapeSelectInput		6
#define X_ShapeInputSelected		7
#define X_ShapeGetRectangles		8

#define ShapeSet			0
#define ShapeUnion			1
#define ShapeIntersect			2
#define ShapeSubtract			3
#define ShapeInvert			4

#define ShapeBounding			0
#define ShapeClip			1
#define ShapeInput			2

#define ShapeNotifyMask			(1L << 0)
#define ShapeNotify			0

#define ShapeNumberEvents		(ShapeNotify + 1)

#ifndef _SHAPE_SERVER_

#include "cplatform_X11_Xutil.h"

typedef struct {
    int	type;		    /* of event */
    unsigned long serial;   /* # of last request processed by server */
    Bool send_event;	    /* true if this came frome a SendEvent request */
    Display *display;	    /* Display the event was read from */
    Window window;	    /* window of event */
    int kind;		    /* ShapeBounding or ShapeClip */
    int x, y;		    /* extents of new region */
    unsigned width, height;
    Time time;		    /* server timestamp when region changed */
    Bool shaped;	    /* true if the region exists */
} XShapeEvent;

_XFUNCPROTOBEGIN

extern Bool XShapeQueryExtension (
    Display*	/* display */,
    int*	/* event_base */,
    int*	/* error_base */
);

extern Status XShapeQueryVersion (
    Display*	/* display */,
    int*	/* major_version */,
    int*	/* minor_version */
);

extern void XShapeCombineRegion (
    Display*	/* display */,
    Window	/* dest */,
    int		/* dest_kind */,
    int		/* x_off */,
    int		/* y_off */,
    Region	/* region */,
    int		/* op */
);

extern void XShapeCombineRectangles (
    Display*	/* display */,
    Window	/* dest */,
    int		/* dest_kind */,
    int		/* x_off */,
    int		/* y_off */,
    XRectangle*	/* rectangles */,
    int		/* n_rects */,
    int		/* op */,
    int		/* ordering */
);

extern void XShapeCombineMask (
    Display*	/* display */,
    Window	/* dest */,
    int		/* dest_kind */,
    int		/* x_off */,
    int		/* y_off */,
    Pixmap	/* src */,
    int		/* op */
);

extern void XShapeCombineShape (
    Display*	/* display */,
    Window	/* dest */,
    int		/* dest_kind */,
    int		/* x_off */,
    int		/* y_off */,
    Window	/* src */,
    int		/* src_kind */,
    int		/* op */
);

extern void XShapeOffsetShape (
    Display*	/* display */,
    Window	/* dest */,
    int		/* dest_kind */,
    int		/* x_off */,
    int		/* y_off */
);

extern Status XShapeQueryExtents (
    Display*		/* display */,
    Window		/* window */,
    Bool*		/* bounding_shaped */,
    int*		/* x_bounding */,
    int*		/* y_bounding */,
    unsigned int*	/* w_bounding */,
    unsigned int*	/* h_bounding */,
    Bool*		/* clip_shaped */,
    int*		/* x_clip */,
    int*		/* y_clip */,
    unsigned int*	/* w_clip */,
    unsigned int*	/* h_clip */
);

extern void XShapeSelectInput (
    Display*		/* display */,
    Window		/* window */,
    unsigned long	/* mask */
);

extern unsigned long XShapeInputSelected (
    Display*	/* display */,
    Window	/* window */
);

extern XRectangle *XShapeGetRectangles (
    Display*	/* display */,
    Window	/* window */,
    int		/* kind */,
    int*	/* count */,
    int*	/* ordering */
);

_XFUNCPROTOEND

#endif /* _SHAPE_SERVER_ */

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_EXTENSIONS_SHAPE_H */

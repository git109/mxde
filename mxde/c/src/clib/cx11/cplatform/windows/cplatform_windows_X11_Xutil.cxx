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
 *   File: cplatform_windows_X11_Xutil.cxx
 *
 * Author: $author$           
 *   Date: 11/27/2010
 **********************************************************************
 */
#include "cplatform_windows_X11_Xutil.hxx"

/* The following declarations are alphabetized. */

XClassHint *XAllocClassHint (
    void
){XClassHint* result = 0; return result;}

XIconSize *XAllocIconSize (
    void
){XIconSize* result = 0; return result;}

XSizeHints *XAllocSizeHints (
    void
){XSizeHints* result = 0; return result;}

XStandardColormap *XAllocStandardColormap (
    void
){XStandardColormap* result = 0; return result;}

XWMHints *XAllocWMHints (
    void
){XWMHints* result = 0; return result;}

int XClipBox(
    Region		/* r */,
    XRectangle*		/* rect_return */
){int result = 0; return result;}

Region XCreateRegion(
    void
){Region result = 0; return result;}

const char *XDefaultString (void){char* result = 0; return result;}

int XDeleteContext(
    Display*		/* display */,
    XID			/* rid */,
    XContext		/* context */
){int result = 0; return result;}

int XDestroyRegion(
    Region		/* r */
){int result = 0; return result;}

int XEmptyRegion(
    Region		/* r */
){int result = 0; return result;}

int XEqualRegion(
    Region		/* r1 */,
    Region		/* r2 */
){int result = 0; return result;}

int XFindContext(
    Display*		/* display */,
    XID			/* rid */,
    XContext		/* context */,
    XPointer*		/* data_return */
){int result = 0; return result;}

Status XGetClassHint(
    Display*		/* display */,
    Window		/* w */,
    XClassHint*		/* class_hints_return */
){int result = 0; return result;}

Status XGetIconSizes(
    Display*		/* display */,
    Window		/* w */,
    XIconSize**		/* size_list_return */,
    int*		/* count_return */
){int result = 0; return result;}

Status XGetNormalHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */
){int result = 0; return result;}

Status XGetRGBColormaps(
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap** /* stdcmap_return */,
    int*		/* count_return */,
    Atom		/* property */
){int result = 0; return result;}

Status XGetSizeHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */,
    Atom		/* property */
){int result = 0; return result;}

Status XGetStandardColormap(
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap*	/* colormap_return */,
    Atom		/* property */			    
){int result = 0; return result;}

Status XGetTextProperty(
    Display*		/* display */,
    Window		/* window */,
    XTextProperty*	/* text_prop_return */,
    Atom		/* property */
){int result = 0; return result;}

XVisualInfo *XGetVisualInfo(
    Display*		/* display */,
    long		/* vinfo_mask */,
    XVisualInfo*	/* vinfo_template */,
    int*		/* nitems_return */
){XVisualInfo* result = 0; return result;}

Status XGetWMClientMachine(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop_return */
){int result = 0; return result;}

XWMHints *XGetWMHints(
    Display*		/* display */,
    Window		/* w */		      
){XWMHints* result = 0; return result;}

Status XGetWMIconName(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop_return */
){int result = 0; return result;}

Status XGetWMName(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop_return */
){int result = 0; return result;}

Status XGetWMNormalHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */,
    long*		/* supplied_return */ 
){int result = 0; return result;}

Status XGetWMSizeHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */,
    long*		/* supplied_return */,
    Atom		/* property */
){int result = 0; return result;}

Status XGetZoomHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* zhints_return */
){int result = 0; return result;}

int XIntersectRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
){int result = 0; return result;}

void XConvertCase(
    KeySym		/* sym */,
    KeySym*		/* lower */,
    KeySym*		/* upper */
){}

int XLookupString(
    XKeyEvent*		/* event_struct */,
    char*		/* buffer_return */,
    int			/* bytes_buffer */,
    KeySym*		/* keysym_return */,
    XComposeStatus*	/* status_in_out */
){int result = 0; return result;}

Status XMatchVisualInfo(
    Display*		/* display */,
    int			/* screen */,
    int			/* depth */,
    int			/* class */,
    XVisualInfo*	/* vinfo_return */
){int result = 0; return result;}

int XOffsetRegion(
    Region		/* r */,
    int			/* dx */,
    int			/* dy */
){int result = 0; return result;}

Bool XPointInRegion(
    Region		/* r */,
    int			/* x */,
    int			/* y */
){int result = 0; return result;}

Region XPolygonRegion(
    XPoint*		/* points */,
    int			/* n */,
    int			/* fill_rule */
){Region result = 0; return result;}

int XRectInRegion(
    Region		/* r */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}

int XSaveContext(
    Display*		/* display */,
    XID			/* rid */,
    XContext		/* context */,
    _Xconst char*	/* data */
){int result = 0; return result;}

int XSetClassHint(
    Display*		/* display */,
    Window		/* w */,
    XClassHint*		/* class_hints */
){int result = 0; return result;}

int XSetIconSizes(
    Display*		/* display */,
    Window		/* w */,
    XIconSize*		/* size_list */,
    int			/* count */    
){int result = 0; return result;}

int XSetNormalHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */
){int result = 0; return result;}

void XSetRGBColormaps(
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap*	/* stdcmaps */,
    int			/* count */,
    Atom		/* property */
){}

int XSetSizeHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */,
    Atom		/* property */
){int result = 0; return result;}

int XSetStandardProperties(
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* window_name */,
    _Xconst char*	/* icon_name */,
    Pixmap		/* icon_pixmap */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* hints */
){int result = 0; return result;}

void XSetTextProperty(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */,
    Atom		/* property */
){}

void XSetWMClientMachine(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */
){}

int XSetWMHints(
    Display*		/* display */,
    Window		/* w */,
    XWMHints*		/* wm_hints */
){int result = 0; return result;}

void XSetWMIconName(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */
){}

void XSetWMName(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */
){}

void XSetWMNormalHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */
){}

void XSetWMProperties(
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* window_name */,
    XTextProperty*	/* icon_name */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* normal_hints */,
    XWMHints*		/* wm_hints */,
    XClassHint*		/* class_hints */
){}

void XmbSetWMProperties(
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* window_name */,
    _Xconst char*	/* icon_name */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* normal_hints */,
    XWMHints*		/* wm_hints */,
    XClassHint*		/* class_hints */
){}

void Xutf8SetWMProperties(
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* window_name */,
    _Xconst char*	/* icon_name */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* normal_hints */,
    XWMHints*		/* wm_hints */,
    XClassHint*		/* class_hints */
){}

void XSetWMSizeHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */,
    Atom		/* property */
){}

int XSetRegion(
    Display*		/* display */,
    GC			/* gc */,
    Region		/* r */
){int result = 0; return result;}

void XSetStandardColormap(
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap*	/* colormap */,
    Atom		/* property */
){}

int XSetZoomHints(
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* zhints */
){int result = 0; return result;}

int XShrinkRegion(
    Region		/* r */,
    int			/* dx */,
    int			/* dy */
){int result = 0; return result;}

Status XStringListToTextProperty(
    char**		/* list */,
    int			/* count */,
    XTextProperty*	/* text_prop_return */
){int result = 0; return result;}

int XSubtractRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
){int result = 0; return result;}

int XmbTextListToTextProperty(
    Display*		display,
    char**		list,
    int			count,
    XICCEncodingStyle	style,
    XTextProperty*	text_prop_return
){int result = 0; return result;}

int XwcTextListToTextProperty(
    Display*		display,
    wchar_t**		list,
    int			count,
    XICCEncodingStyle	style,
    XTextProperty*	text_prop_return
){int result = 0; return result;}

int Xutf8TextListToTextProperty(
    Display*		display,
    char**		list,
    int			count,
    XICCEncodingStyle	style,
    XTextProperty*	text_prop_return
){int result = 0; return result;}

void XwcFreeStringList(
    wchar_t**		list
){}

Status XTextPropertyToStringList(
    XTextProperty*	/* text_prop */,
    char***		/* list_return */,
    int*		/* count_return */
){int result = 0; return result;}

int XmbTextPropertyToTextList(
    Display*		display,
    const XTextProperty* text_prop,
    char***		list_return,
    int*		count_return
){int result = 0; return result;}

int XwcTextPropertyToTextList(
    Display*		display,
    const XTextProperty* text_prop,
    wchar_t***		list_return,
    int*		count_return
){int result = 0; return result;}

int Xutf8TextPropertyToTextList(
    Display*		display,
    const XTextProperty* text_prop,
    char***		list_return,
    int*		count_return
){int result = 0; return result;}

int XUnionRectWithRegion(
    XRectangle*		/* rectangle */,
    Region		/* src_region */,
    Region		/* dest_region_return */
){int result = 0; return result;}

int XUnionRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
){int result = 0; return result;}

int XWMGeometry(
    Display*		/* display */,
    int			/* screen_number */,
    _Xconst char*	/* user_geometry */,
    _Xconst char*	/* default_geometry */,
    unsigned int	/* border_width */,
    XSizeHints*		/* hints */,
    int*		/* x_return */,
    int*		/* y_return */,
    int*		/* width_return */,
    int*		/* height_return */,
    int*		/* gravity_return */
){int result = 0; return result;}

int XXorRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
){int result = 0; return result;}

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

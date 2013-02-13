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
 *   File: cplatform_windows_X11_Xlib.cxx
 *
 * Author: $author$           
 *   Date: 11/27/2010
 **********************************************************************
 */
#include "cplatform_windows_X11_Xlib.hxx"

int _Xdebug;

XFontStruct *XLoadQueryFont(
    Display*		/* display */,
    _Xconst char*	/* name */
){XFontStruct* result = 0; return result;}

XFontStruct *XQueryFont(
    Display*		/* display */,
    XID			/* font_ID */
){XFontStruct* result = 0; return result;}


XTimeCoord *XGetMotionEvents(
    Display*		/* display */,
    Window		/* w */,
    Time		/* start */,
    Time		/* stop */,
    int*		/* nevents_return */
){XTimeCoord* result = 0; return result;}

XModifierKeymap *XDeleteModifiermapEntry(
    XModifierKeymap*	/* modmap */,
#if NeedWidePrototypes
    unsigned int	/* keycode_entry */,
#else
    KeyCode		/* keycode_entry */,
#endif
    int			/* modifier */
){XModifierKeymap* result = 0; return result;}

XModifierKeymap	*XGetModifierMapping(
    Display*		/* display */
){XModifierKeymap* result = 0; return result;}

XModifierKeymap	*XInsertModifiermapEntry(
    XModifierKeymap*	/* modmap */,
#if NeedWidePrototypes
    unsigned int	/* keycode_entry */,
#else
    KeyCode		/* keycode_entry */,
#endif
    int			/* modifier */
){XModifierKeymap* result = 0; return result;}

XModifierKeymap *XNewModifiermap(
    int			/* max_keys_per_mod */
){XModifierKeymap* result = 0; return result;}

XImage *XCreateImage(
    Display*		/* display */,
    Visual*		/* visual */,
    unsigned int	/* depth */,
    int			/* format */,
    int			/* offset */,
    char*		/* data */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    int			/* bitmap_pad */,
    int			/* bytes_per_line */
){XImage* result = 0; return result;}
Status XInitImage(
    XImage*		/* image */
){int result = 0; return result;}
XImage *XGetImage(
    Display*		/* display */,
    Drawable		/* d */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned long	/* plane_mask */,
    int			/* format */
){XImage* result = 0; return result;}
XImage *XGetSubImage(
    Display*		/* display */,
    Drawable		/* d */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned long	/* plane_mask */,
    int			/* format */,
    XImage*		/* dest_image */,
    int			/* dest_x */,
    int			/* dest_y */
){XImage* result = 0; return result;}

/*
 * X function declarations.
 */
Display *XOpenDisplay(
    _Xconst char*	/* display_name */
){Display* result = 0; return result;}

void XrmInitialize(
    void
){}

char *XFetchBytes(
    Display*		/* display */,
    int*		/* nbytes_return */
){char* result = 0; return result;}
char *XFetchBuffer(
    Display*		/* display */,
    int*		/* nbytes_return */,
    int			/* buffer */
){char* result = 0; return result;}
char *XGetAtomName(
    Display*		/* display */,
    Atom		/* atom */
){char* result = 0; return result;}
Status XGetAtomNames(
    Display*		/* dpy */,
    Atom*		/* atoms */,
    int			/* count */,
    char**		/* names_return */
){int result = 0; return result;}
char *XGetDefault(
    Display*		/* display */,
    _Xconst char*	/* program */,
    _Xconst char*	/* option */
){char* result = 0; return result;}
char *XDisplayName(
    _Xconst char*	/* string */
){char* result = 0; return result;}
char *XKeysymToString(
    KeySym		/* keysym */
){char* result = 0; return result;}

int (*XSynchronize(
    Display*		/* display */,
    Bool		/* onoff */
))(
    Display*		/* display */
);
int (*XSetAfterFunction(
    Display*		/* display */,
    int (*) (
	     Display*	/* display */
            )		/* procedure */
))(
    Display*		/* display */
);
Atom XInternAtom(
    Display*		/* display */,
    _Xconst char*	/* atom_name */,
    Bool		/* only_if_exists */
){int result = 0; return result;}
Status XInternAtoms(
    Display*		/* dpy */,
    char**		/* names */,
    int			/* count */,
    Bool		/* onlyIfExists */,
    Atom*		/* atoms_return */
){int result = 0; return result;}
Colormap XCopyColormapAndFree(
    Display*		/* display */,
    Colormap		/* colormap */
){int result = 0; return result;}
Colormap XCreateColormap(
    Display*		/* display */,
    Window		/* w */,
    Visual*		/* visual */,
    int			/* alloc */
){int result = 0; return result;}
Cursor XCreatePixmapCursor(
    Display*		/* display */,
    Pixmap		/* source */,
    Pixmap		/* mask */,
    XColor*		/* foreground_color */,
    XColor*		/* background_color */,
    unsigned int	/* x */,
    unsigned int	/* y */
){int result = 0; return result;}
Cursor XCreateGlyphCursor(
    Display*		/* display */,
    Font		/* source_font */,
    Font		/* mask_font */,
    unsigned int	/* source_char */,
    unsigned int	/* mask_char */,
    XColor _Xconst *	/* foreground_color */,
    XColor _Xconst *	/* background_color */
){int result = 0; return result;}
Cursor XCreateFontCursor(
    Display*		/* display */,
    unsigned int	/* shape */
){int result = 0; return result;}
Font XLoadFont(
    Display*		/* display */,
    _Xconst char*	/* name */
){int result = 0; return result;}
GC XCreateGC(
    Display*		/* display */,
    Drawable		/* d */,
    unsigned long	/* valuemask */,
    XGCValues*		/* values */
){GC result = 0; return result;}
GContext XGContextFromGC(
    GC			/* gc */
){int result = 0; return result;}
void XFlushGC(
    Display*		/* display */,
    GC			/* gc */
){}
Pixmap XCreatePixmap(
    Display*		/* display */,
    Drawable		/* d */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int	/* depth */
){int result = 0; return result;}
Pixmap XCreateBitmapFromData(
    Display*		/* display */,
    Drawable		/* d */,
    _Xconst char*	/* data */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}
Pixmap XCreatePixmapFromBitmapData(
    Display*		/* display */,
    Drawable		/* d */,
    char*		/* data */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned long	/* fg */,
    unsigned long	/* bg */,
    unsigned int	/* depth */
){int result = 0; return result;}
Window XCreateSimpleWindow(
    Display*		/* display */,
    Window		/* parent */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int	/* border_width */,
    unsigned long	/* border */,
    unsigned long	/* background */
){int result = 0; return result;}
Window XGetSelectionOwner(
    Display*		/* display */,
    Atom		/* selection */
){int result = 0; return result;}
Window XCreateWindow(
    Display*		/* display */,
    Window		/* parent */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int	/* border_width */,
    int			/* depth */,
    unsigned int	/* class */,
    Visual*		/* visual */,
    unsigned long	/* valuemask */,
    XSetWindowAttributes*	/* attributes */
){int result = 0; return result;}
Colormap *XListInstalledColormaps(
    Display*		/* display */,
    Window		/* w */,
    int*		/* num_return */
){Colormap* result = 0; return result;}
char **XListFonts(
    Display*		/* display */,
    _Xconst char*	/* pattern */,
    int			/* maxnames */,
    int*		/* actual_count_return */
){char** result = 0; return result;}
char **XListFontsWithInfo(
    Display*		/* display */,
    _Xconst char*	/* pattern */,
    int			/* maxnames */,
    int*		/* count_return */,
    XFontStruct**	/* info_return */
){char** result = 0; return result;}
char **XGetFontPath(
    Display*		/* display */,
    int*		/* npaths_return */
){char** result = 0; return result;}
char **XListExtensions(
    Display*		/* display */,
    int*		/* nextensions_return */
){char** result = 0; return result;}
Atom *XListProperties(
    Display*		/* display */,
    Window		/* w */,
    int*		/* num_prop_return */
){Atom* result = 0; return result;}
XHostAddress *XListHosts(
    Display*		/* display */,
    int*		/* nhosts_return */,
    Bool*		/* state_return */
){XHostAddress* result = 0; return result;}
KeySym XKeycodeToKeysym(
    Display*		/* display */,
#if NeedWidePrototypes
    unsigned int	/* keycode */,
#else
    KeyCode		/* keycode */,
#endif
    int			/* index */
){int result = 0; return result;}
KeySym XLookupKeysym(
    XKeyEvent*		/* key_event */,
    int			/* index */
){int result = 0; return result;}
KeySym *XGetKeyboardMapping(
    Display*		/* display */,
#if NeedWidePrototypes
    unsigned int	/* first_keycode */,
#else
    KeyCode		/* first_keycode */,
#endif
    int			/* keycode_count */,
    int*		/* keysyms_per_keycode_return */
){KeySym* result = 0; return result;}
KeySym XStringToKeysym(
    _Xconst char*	/* string */
){int result = 0; return result;}
long XMaxRequestSize(
    Display*		/* display */
){int result = 0; return result;}
long XExtendedMaxRequestSize(
    Display*		/* display */
){int result = 0; return result;}
char *XResourceManagerString(
    Display*		/* display */
){char* result = 0; return result;}
char *XScreenResourceString(
	Screen*		/* screen */
){char* result = 0; return result;}
unsigned long XDisplayMotionBufferSize(
    Display*		/* display */
){int result = 0; return result;}
VisualID XVisualIDFromVisual(
    Visual*		/* visual */
){int result = 0; return result;}

/* multithread routines */

Status XInitThreads(
    void
){int result = 0; return result;}

void XLockDisplay(
    Display*		/* display */
){}

void XUnlockDisplay(
    Display*		/* display */
){}

/* routines for dealing with extensions */

XExtCodes *XInitExtension(
    Display*		/* display */,
    _Xconst char*	/* name */
){XExtCodes* result = 0; return result;}

XExtCodes *XAddExtension(
    Display*		/* display */
){XExtCodes* result = 0; return result;}
XExtData *XFindOnExtensionList(
    XExtData**		/* structure */,
    int			/* number */
){XExtData* result = 0; return result;}
XExtData **XEHeadOfExtensionList(
    XEDataObject	/* object */
){XExtData** result = 0; return result;}

/* these are routines for which there are also macros */
Window XRootWindow(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}
Window XDefaultRootWindow(
    Display*		/* display */
){int result = 0; return result;}
Window XRootWindowOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}
Visual *XDefaultVisual(
    Display*		/* display */,
    int			/* screen_number */
){Visual* result = 0; return result;}
Visual *XDefaultVisualOfScreen(
    Screen*		/* screen */
){Visual* result = 0; return result;}
GC XDefaultGC(
    Display*		/* display */,
    int			/* screen_number */
){GC result = 0; return result;}
GC XDefaultGCOfScreen(
    Screen*		/* screen */
){GC result = 0; return result;}
unsigned long XBlackPixel(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}
unsigned long XWhitePixel(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}
unsigned long XAllPlanes(
    void
){int result = 0; return result;}
unsigned long XBlackPixelOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}
unsigned long XWhitePixelOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}
unsigned long XNextRequest(
    Display*		/* display */
){int result = 0; return result;}
unsigned long XLastKnownRequestProcessed(
    Display*		/* display */
){int result = 0; return result;}
char *XServerVendor(
    Display*		/* display */
){char* result = 0; return result;}
char *XDisplayString(
    Display*		/* display */
){char* result = 0; return result;}
Colormap XDefaultColormap(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}
Colormap XDefaultColormapOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}
Display *XDisplayOfScreen(
    Screen*		/* screen */
){Display* result = 0; return result;}
Screen *XScreenOfDisplay(
    Display*		/* display */,
    int			/* screen_number */
){Screen* result = 0; return result;}
Screen *XDefaultScreenOfDisplay(
    Display*		/* display */
){Screen* result = 0; return result;}
long XEventMaskOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XScreenNumberOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

XErrorHandler XSetErrorHandler (
    XErrorHandler	/* handler */
){XErrorHandler result = 0; return result;}


XIOErrorHandler XSetIOErrorHandler (
    XIOErrorHandler	/* handler */
){XIOErrorHandler result = 0; return result;}


XPixmapFormatValues *XListPixmapFormats(
    Display*		/* display */,
    int*		/* count_return */
){XPixmapFormatValues* result = 0; return result;}
int *XListDepths(
    Display*		/* display */,
    int			/* screen_number */,
    int*		/* count_return */
){int* result = 0; return result;}

/* ICCCM routines for things that don't require special include files; */
/* other declarations are given in Xutil.h                             */
Status XReconfigureWMWindow(
    Display*		/* display */,
    Window		/* w */,
    int			/* screen_number */,
    unsigned int	/* mask */,
    XWindowChanges*	/* changes */
){int result = 0; return result;}

Status XGetWMProtocols(
    Display*		/* display */,
    Window		/* w */,
    Atom**		/* protocols_return */,
    int*		/* count_return */
){int result = 0; return result;}
Status XSetWMProtocols(
    Display*		/* display */,
    Window		/* w */,
    Atom*		/* protocols */,
    int			/* count */
){int result = 0; return result;}
Status XIconifyWindow(
    Display*		/* display */,
    Window		/* w */,
    int			/* screen_number */
){int result = 0; return result;}
Status XWithdrawWindow(
    Display*		/* display */,
    Window		/* w */,
    int			/* screen_number */
){int result = 0; return result;}
Status XGetCommand(
    Display*		/* display */,
    Window		/* w */,
    char***		/* argv_return */,
    int*		/* argc_return */
){int result = 0; return result;}
Status XGetWMColormapWindows(
    Display*		/* display */,
    Window		/* w */,
    Window**		/* windows_return */,
    int*		/* count_return */
){int result = 0; return result;}
Status XSetWMColormapWindows(
    Display*		/* display */,
    Window		/* w */,
    Window*		/* colormap_windows */,
    int			/* count */
){int result = 0; return result;}
void XFreeStringList(
    char**		/* list */
){}
int XSetTransientForHint(
    Display*		/* display */,
    Window		/* w */,
    Window		/* prop_window */
){int result = 0; return result;}

/* The following are given in alphabetical order */

int XActivateScreenSaver(
    Display*		/* display */
){int result = 0; return result;}

int XAddHost(
    Display*		/* display */,
    XHostAddress*	/* host */
){int result = 0; return result;}

int XAddHosts(
    Display*		/* display */,
    XHostAddress*	/* hosts */,
    int			/* num_hosts */
){int result = 0; return result;}

int XAddToExtensionList(
    struct _XExtData**	/* structure */,
    XExtData*		/* ext_data */
){int result = 0; return result;}

int XAddToSaveSet(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

Status XAllocColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    XColor*		/* screen_in_out */
){int result = 0; return result;}

Status XAllocColorCells(
    Display*		/* display */,
    Colormap		/* colormap */,
    Bool	        /* contig */,
    unsigned long*	/* plane_masks_return */,
    unsigned int	/* nplanes */,
    unsigned long*	/* pixels_return */,
    unsigned int 	/* npixels */
){int result = 0; return result;}

Status XAllocColorPlanes(
    Display*		/* display */,
    Colormap		/* colormap */,
    Bool		/* contig */,
    unsigned long*	/* pixels_return */,
    int			/* ncolors */,
    int			/* nreds */,
    int			/* ngreens */,
    int			/* nblues */,
    unsigned long*	/* rmask_return */,
    unsigned long*	/* gmask_return */,
    unsigned long*	/* bmask_return */
){int result = 0; return result;}

Status XAllocNamedColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    _Xconst char*	/* color_name */,
    XColor*		/* screen_def_return */,
    XColor*		/* exact_def_return */
){int result = 0; return result;}

int XAllowEvents(
    Display*		/* display */,
    int			/* event_mode */,
    Time		/* time */
){int result = 0; return result;}

int XAutoRepeatOff(
    Display*		/* display */
){int result = 0; return result;}

int XAutoRepeatOn(
    Display*		/* display */
){int result = 0; return result;}

int XBell(
    Display*		/* display */,
    int			/* percent */
){int result = 0; return result;}

int XBitmapBitOrder(
    Display*		/* display */
){int result = 0; return result;}

int XBitmapPad(
    Display*		/* display */
){int result = 0; return result;}

int XBitmapUnit(
    Display*		/* display */
){int result = 0; return result;}

int XCellsOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XChangeActivePointerGrab(
    Display*		/* display */,
    unsigned int	/* event_mask */,
    Cursor		/* cursor */,
    Time		/* time */
){int result = 0; return result;}

int XChangeGC(
    Display*		/* display */,
    GC			/* gc */,
    unsigned long	/* valuemask */,
    XGCValues*		/* values */
){int result = 0; return result;}

int XChangeKeyboardControl(
    Display*		/* display */,
    unsigned long	/* value_mask */,
    XKeyboardControl*	/* values */
){int result = 0; return result;}

int XChangeKeyboardMapping(
    Display*		/* display */,
    int			/* first_keycode */,
    int			/* keysyms_per_keycode */,
    KeySym*		/* keysyms */,
    int			/* num_codes */
){int result = 0; return result;}

int XChangePointerControl(
    Display*		/* display */,
    Bool		/* do_accel */,
    Bool		/* do_threshold */,
    int			/* accel_numerator */,
    int			/* accel_denominator */,
    int			/* threshold */
){int result = 0; return result;}

int XChangeProperty(
    Display*		/* display */,
    Window		/* w */,
    Atom		/* property */,
    Atom		/* type */,
    int			/* format */,
    int			/* mode */,
    _Xconst unsigned char*	/* data */,
    int			/* nelements */
){int result = 0; return result;}

int XChangeSaveSet(
    Display*		/* display */,
    Window		/* w */,
    int			/* change_mode */
){int result = 0; return result;}

int XChangeWindowAttributes(
    Display*		/* display */,
    Window		/* w */,
    unsigned long	/* valuemask */,
    XSetWindowAttributes* /* attributes */
){int result = 0; return result;}

Bool XCheckIfEvent(
    Display*		/* display */,
    XEvent*		/* event_return */,
    Bool (*) (
	       Display*			/* display */,
               XEvent*			/* event */,
               XPointer			/* arg */
             )		/* predicate */,
    XPointer		/* arg */
){int result = 0; return result;}

Bool XCheckMaskEvent(
    Display*		/* display */,
    long		/* event_mask */,
    XEvent*		/* event_return */
){int result = 0; return result;}

Bool XCheckTypedEvent(
    Display*		/* display */,
    int			/* event_type */,
    XEvent*		/* event_return */
){int result = 0; return result;}

Bool XCheckTypedWindowEvent(
    Display*		/* display */,
    Window		/* w */,
    int			/* event_type */,
    XEvent*		/* event_return */
){int result = 0; return result;}

Bool XCheckWindowEvent(
    Display*		/* display */,
    Window		/* w */,
    long		/* event_mask */,
    XEvent*		/* event_return */
){int result = 0; return result;}

int XCirculateSubwindows(
    Display*		/* display */,
    Window		/* w */,
    int			/* direction */
){int result = 0; return result;}

int XCirculateSubwindowsDown(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XCirculateSubwindowsUp(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XClearArea(
    Display*		/* display */,
    Window		/* w */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    Bool		/* exposures */
){int result = 0; return result;}

int XClearWindow(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XCloseDisplay(
    Display*		/* display */
){int result = 0; return result;}

int XConfigureWindow(
    Display*		/* display */,
    Window		/* w */,
    unsigned int	/* value_mask */,
    XWindowChanges*	/* values */
){int result = 0; return result;}

int XConnectionNumber(
    Display*		/* display */
){int result = 0; return result;}

int XConvertSelection(
    Display*		/* display */,
    Atom		/* selection */,
    Atom 		/* target */,
    Atom		/* property */,
    Window		/* requestor */,
    Time		/* time */
){int result = 0; return result;}

int XCopyArea(
    Display*		/* display */,
    Drawable		/* src */,
    Drawable		/* dest */,
    GC			/* gc */,
    int			/* src_x */,
    int			/* src_y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    int			/* dest_x */,
    int			/* dest_y */
){int result = 0; return result;}

int XCopyGC(
    Display*		/* display */,
    GC			/* src */,
    unsigned long	/* valuemask */,
    GC			/* dest */
){int result = 0; return result;}

int XCopyPlane(
    Display*		/* display */,
    Drawable		/* src */,
    Drawable		/* dest */,
    GC			/* gc */,
    int			/* src_x */,
    int			/* src_y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    int			/* dest_x */,
    int			/* dest_y */,
    unsigned long	/* plane */
){int result = 0; return result;}

int XDefaultDepth(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDefaultDepthOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XDefaultScreen(
    Display*		/* display */
){int result = 0; return result;}

int XDefineCursor(
    Display*		/* display */,
    Window		/* w */,
    Cursor		/* cursor */
){int result = 0; return result;}

int XDeleteProperty(
    Display*		/* display */,
    Window		/* w */,
    Atom		/* property */
){int result = 0; return result;}

int XDestroyWindow(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XDestroySubwindows(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XDoesBackingStore(
    Screen*		/* screen */
){int result = 0; return result;}

Bool XDoesSaveUnders(
    Screen*		/* screen */
){int result = 0; return result;}

int XDisableAccessControl(
    Display*		/* display */
){int result = 0; return result;}


int XDisplayCells(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDisplayHeight(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDisplayHeightMM(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDisplayKeycodes(
    Display*		/* display */,
    int*		/* min_keycodes_return */,
    int*		/* max_keycodes_return */
){int result = 0; return result;}

int XDisplayPlanes(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDisplayWidth(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDisplayWidthMM(
    Display*		/* display */,
    int			/* screen_number */
){int result = 0; return result;}

int XDrawArc(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    int			/* angle1 */,
    int			/* angle2 */
){int result = 0; return result;}

int XDrawArcs(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XArc*		/* arcs */,
    int			/* narcs */
){int result = 0; return result;}

int XDrawImageString(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* string */,
    int			/* length */
){int result = 0; return result;}

int XDrawImageString16(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst XChar2b*	/* string */,
    int			/* length */
){int result = 0; return result;}

int XDrawLine(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x1 */,
    int			/* y1 */,
    int			/* x2 */,
    int			/* y2 */
){int result = 0; return result;}

int XDrawLines(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XPoint*		/* points */,
    int			/* npoints */,
    int			/* mode */
){int result = 0; return result;}

int XDrawPoint(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */
){int result = 0; return result;}

int XDrawPoints(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XPoint*		/* points */,
    int			/* npoints */,
    int			/* mode */
){int result = 0; return result;}

int XDrawRectangle(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}

int XDrawRectangles(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XRectangle*		/* rectangles */,
    int			/* nrectangles */
){int result = 0; return result;}

int XDrawSegments(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XSegment*		/* segments */,
    int			/* nsegments */
){int result = 0; return result;}

int XDrawString(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* string */,
    int			/* length */
){int result = 0; return result;}

int XDrawString16(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst XChar2b*	/* string */,
    int			/* length */
){int result = 0; return result;}

int XDrawText(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XTextItem*		/* items */,
    int			/* nitems */
){int result = 0; return result;}

int XDrawText16(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XTextItem16*	/* items */,
    int			/* nitems */
){int result = 0; return result;}

int XEnableAccessControl(
    Display*		/* display */
){int result = 0; return result;}

int XEventsQueued(
    Display*		/* display */,
    int			/* mode */
){int result = 0; return result;}

Status XFetchName(
    Display*		/* display */,
    Window		/* w */,
    char**		/* window_name_return */
){int result = 0; return result;}

int XFillArc(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    int			/* angle1 */,
    int			/* angle2 */
){int result = 0; return result;}

int XFillArcs(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XArc*		/* arcs */,
    int			/* narcs */
){int result = 0; return result;}

int XFillPolygon(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XPoint*		/* points */,
    int			/* npoints */,
    int			/* shape */,
    int			/* mode */
){int result = 0; return result;}

int XFillRectangle(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}

int XFillRectangles(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XRectangle*		/* rectangles */,
    int			/* nrectangles */
){int result = 0; return result;}

int XFlush(
    Display*		/* display */
){int result = 0; return result;}

int XForceScreenSaver(
    Display*		/* display */,
    int			/* mode */
){int result = 0; return result;}

int XFree(
    void*		/* data */
){int result = 0; return result;}

int XFreeColormap(
    Display*		/* display */,
    Colormap		/* colormap */
){int result = 0; return result;}

int XFreeColors(
    Display*		/* display */,
    Colormap		/* colormap */,
    unsigned long*	/* pixels */,
    int			/* npixels */,
    unsigned long	/* planes */
){int result = 0; return result;}

int XFreeCursor(
    Display*		/* display */,
    Cursor		/* cursor */
){int result = 0; return result;}

int XFreeExtensionList(
    char**		/* list */
){int result = 0; return result;}

int XFreeFont(
    Display*		/* display */,
    XFontStruct*	/* font_struct */
){int result = 0; return result;}

int XFreeFontInfo(
    char**		/* names */,
    XFontStruct*	/* free_info */,
    int			/* actual_count */
){int result = 0; return result;}

int XFreeFontNames(
    char**		/* list */
){int result = 0; return result;}

int XFreeFontPath(
    char**		/* list */
){int result = 0; return result;}

int XFreeGC(
    Display*		/* display */,
    GC			/* gc */
){int result = 0; return result;}

int XFreeModifiermap(
    XModifierKeymap*	/* modmap */
){int result = 0; return result;}

int XFreePixmap(
    Display*		/* display */,
    Pixmap		/* pixmap */
){int result = 0; return result;}

int XGeometry(
    Display*		/* display */,
    int			/* screen */,
    _Xconst char*	/* position */,
    _Xconst char*	/* default_position */,
    unsigned int	/* bwidth */,
    unsigned int	/* fwidth */,
    unsigned int	/* fheight */,
    int			/* xadder */,
    int			/* yadder */,
    int*		/* x_return */,
    int*		/* y_return */,
    int*		/* width_return */,
    int*		/* height_return */
){int result = 0; return result;}

int XGetErrorDatabaseText(
    Display*		/* display */,
    _Xconst char*	/* name */,
    _Xconst char*	/* message */,
    _Xconst char*	/* default_string */,
    char*		/* buffer_return */,
    int			/* length */
){int result = 0; return result;}

int XGetErrorText(
    Display*		/* display */,
    int			/* code */,
    char*		/* buffer_return */,
    int			/* length */
){int result = 0; return result;}

Bool XGetFontProperty(
    XFontStruct*	/* font_struct */,
    Atom		/* atom */,
    unsigned long*	/* value_return */
){int result = 0; return result;}

Status XGetGCValues(
    Display*		/* display */,
    GC			/* gc */,
    unsigned long	/* valuemask */,
    XGCValues*		/* values_return */
){int result = 0; return result;}

Status XGetGeometry(
    Display*		/* display */,
    Drawable		/* d */,
    Window*		/* root_return */,
    int*		/* x_return */,
    int*		/* y_return */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */,
    unsigned int*	/* border_width_return */,
    unsigned int*	/* depth_return */
){int result = 0; return result;}

Status XGetIconName(
    Display*		/* display */,
    Window		/* w */,
    char**		/* icon_name_return */
){int result = 0; return result;}

int XGetInputFocus(
    Display*		/* display */,
    Window*		/* focus_return */,
    int*		/* revert_to_return */
){int result = 0; return result;}

int XGetKeyboardControl(
    Display*		/* display */,
    XKeyboardState*	/* values_return */
){int result = 0; return result;}

int XGetPointerControl(
    Display*		/* display */,
    int*		/* accel_numerator_return */,
    int*		/* accel_denominator_return */,
    int*		/* threshold_return */
){int result = 0; return result;}

int XGetPointerMapping(
    Display*		/* display */,
    unsigned char*	/* map_return */,
    int			/* nmap */
){int result = 0; return result;}

int XGetScreenSaver(
    Display*		/* display */,
    int*		/* timeout_return */,
    int*		/* interval_return */,
    int*		/* prefer_blanking_return */,
    int*		/* allow_exposures_return */
){int result = 0; return result;}

Status XGetTransientForHint(
    Display*		/* display */,
    Window		/* w */,
    Window*		/* prop_window_return */
){int result = 0; return result;}

int XGetWindowProperty(
    Display*		/* display */,
    Window		/* w */,
    Atom		/* property */,
    long		/* long_offset */,
    long		/* long_length */,
    Bool		/* delete */,
    Atom		/* req_type */,
    Atom*		/* actual_type_return */,
    int*		/* actual_format_return */,
    unsigned long*	/* nitems_return */,
    unsigned long*	/* bytes_after_return */,
    unsigned char**	/* prop_return */
){int result = 0; return result;}

Status XGetWindowAttributes(
    Display*		/* display */,
    Window		/* w */,
    XWindowAttributes*	/* window_attributes_return */
){int result = 0; return result;}

int XGrabButton(
    Display*		/* display */,
    unsigned int	/* button */,
    unsigned int	/* modifiers */,
    Window		/* grab_window */,
    Bool		/* owner_events */,
    unsigned int	/* event_mask */,
    int			/* pointer_mode */,
    int			/* keyboard_mode */,
    Window		/* confine_to */,
    Cursor		/* cursor */
){int result = 0; return result;}

int XGrabKey(
    Display*		/* display */,
    int			/* keycode */,
    unsigned int	/* modifiers */,
    Window		/* grab_window */,
    Bool		/* owner_events */,
    int			/* pointer_mode */,
    int			/* keyboard_mode */
){int result = 0; return result;}

int XGrabKeyboard(
    Display*		/* display */,
    Window		/* grab_window */,
    Bool		/* owner_events */,
    int			/* pointer_mode */,
    int			/* keyboard_mode */,
    Time		/* time */
){int result = 0; return result;}

int XGrabPointer(
    Display*		/* display */,
    Window		/* grab_window */,
    Bool		/* owner_events */,
    unsigned int	/* event_mask */,
    int			/* pointer_mode */,
    int			/* keyboard_mode */,
    Window		/* confine_to */,
    Cursor		/* cursor */,
    Time		/* time */
){int result = 0; return result;}

int XGrabServer(
    Display*		/* display */
){int result = 0; return result;}

int XHeightMMOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XHeightOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XIfEvent(
    Display*		/* display */,
    XEvent*		/* event_return */,
    Bool (*) (
	       Display*			/* display */,
               XEvent*			/* event */,
               XPointer			/* arg */
             )		/* predicate */,
    XPointer		/* arg */
){int result = 0; return result;}

int XImageByteOrder(
    Display*		/* display */
){int result = 0; return result;}

int XInstallColormap(
    Display*		/* display */,
    Colormap		/* colormap */
){int result = 0; return result;}

KeyCode XKeysymToKeycode(
    Display*		/* display */,
    KeySym		/* keysym */
){int result = 0; return result;}

int XKillClient(
    Display*		/* display */,
    XID			/* resource */
){int result = 0; return result;}

Status XLookupColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    _Xconst char*	/* color_name */,
    XColor*		/* exact_def_return */,
    XColor*		/* screen_def_return */
){int result = 0; return result;}

int XLowerWindow(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XMapRaised(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XMapSubwindows(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XMapWindow(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XMaskEvent(
    Display*		/* display */,
    long		/* event_mask */,
    XEvent*		/* event_return */
){int result = 0; return result;}

int XMaxCmapsOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XMinCmapsOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XMoveResizeWindow(
    Display*		/* display */,
    Window		/* w */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}

int XMoveWindow(
    Display*		/* display */,
    Window		/* w */,
    int			/* x */,
    int			/* y */
){int result = 0; return result;}

int XNextEvent(
    Display*		/* display */,
    XEvent*		/* event_return */
){int result = 0; return result;}

int XNoOp(
    Display*		/* display */
){int result = 0; return result;}

Status XParseColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    _Xconst char*	/* spec */,
    XColor*		/* exact_def_return */
){int result = 0; return result;}

int XParseGeometry(
    _Xconst char*	/* parsestring */,
    int*		/* x_return */,
    int*		/* y_return */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */
){int result = 0; return result;}

int XPeekEvent(
    Display*		/* display */,
    XEvent*		/* event_return */
){int result = 0; return result;}

int XPeekIfEvent(
    Display*		/* display */,
    XEvent*		/* event_return */,
    Bool (*) (
	       Display*		/* display */,
               XEvent*		/* event */,
               XPointer		/* arg */
             )		/* predicate */,
    XPointer		/* arg */
){int result = 0; return result;}

int XPending(
    Display*		/* display */
){int result = 0; return result;}

int XPlanesOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XProtocolRevision(
    Display*		/* display */
){int result = 0; return result;}

int XProtocolVersion(
    Display*		/* display */
){int result = 0; return result;}


int XPutBackEvent(
    Display*		/* display */,
    XEvent*		/* event */
){int result = 0; return result;}

int XPutImage(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    XImage*		/* image */,
    int			/* src_x */,
    int			/* src_y */,
    int			/* dest_x */,
    int			/* dest_y */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}

int XQLength(
    Display*		/* display */
){int result = 0; return result;}

Status XQueryBestCursor(
    Display*		/* display */,
    Drawable		/* d */,
    unsigned int        /* width */,
    unsigned int	/* height */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */
){int result = 0; return result;}

Status XQueryBestSize(
    Display*		/* display */,
    int			/* class */,
    Drawable		/* which_screen */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */
){int result = 0; return result;}

Status XQueryBestStipple(
    Display*		/* display */,
    Drawable		/* which_screen */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */
){int result = 0; return result;}

Status XQueryBestTile(
    Display*		/* display */,
    Drawable		/* which_screen */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */
){int result = 0; return result;}

int XQueryColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    XColor*		/* def_in_out */
){int result = 0; return result;}

int XQueryColors(
    Display*		/* display */,
    Colormap		/* colormap */,
    XColor*		/* defs_in_out */,
    int			/* ncolors */
){int result = 0; return result;}

Bool XQueryExtension(
    Display*		/* display */,
    _Xconst char*	/* name */,
    int*		/* major_opcode_return */,
    int*		/* first_event_return */,
    int*		/* first_error_return */
){int result = 0; return result;}

int XQueryKeymap(
    Display*		/* display */,
    char [32]		/* keys_return */
){int result = 0; return result;}

Bool XQueryPointer(
    Display*		/* display */,
    Window		/* w */,
    Window*		/* root_return */,
    Window*		/* child_return */,
    int*		/* root_x_return */,
    int*		/* root_y_return */,
    int*		/* win_x_return */,
    int*		/* win_y_return */,
    unsigned int*       /* mask_return */
){int result = 0; return result;}

int XQueryTextExtents(
    Display*		/* display */,
    XID			/* font_ID */,
    _Xconst char*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
){int result = 0; return result;}

int XQueryTextExtents16(
    Display*		/* display */,
    XID			/* font_ID */,
    _Xconst XChar2b*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
){int result = 0; return result;}

Status XQueryTree(
    Display*		/* display */,
    Window		/* w */,
    Window*		/* root_return */,
    Window*		/* parent_return */,
    Window**		/* children_return */,
    unsigned int*	/* nchildren_return */
){int result = 0; return result;}

int XRaiseWindow(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XReadBitmapFile(
    Display*		/* display */,
    Drawable 		/* d */,
    _Xconst char*	/* filename */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */,
    Pixmap*		/* bitmap_return */,
    int*		/* x_hot_return */,
    int*		/* y_hot_return */
){int result = 0; return result;}

int XReadBitmapFileData(
    _Xconst char*	/* filename */,
    unsigned int*	/* width_return */,
    unsigned int*	/* height_return */,
    unsigned char**	/* data_return */,
    int*		/* x_hot_return */,
    int*		/* y_hot_return */
){int result = 0; return result;}

int XRebindKeysym(
    Display*		/* display */,
    KeySym		/* keysym */,
    KeySym*		/* list */,
    int			/* mod_count */,
    _Xconst unsigned char*	/* string */,
    int			/* bytes_string */
){int result = 0; return result;}

int XRecolorCursor(
    Display*		/* display */,
    Cursor		/* cursor */,
    XColor*		/* foreground_color */,
    XColor*		/* background_color */
){int result = 0; return result;}

int XRefreshKeyboardMapping(
    XMappingEvent*	/* event_map */
){int result = 0; return result;}

int XRemoveFromSaveSet(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XRemoveHost(
    Display*		/* display */,
    XHostAddress*	/* host */
){int result = 0; return result;}

int XRemoveHosts(
    Display*		/* display */,
    XHostAddress*	/* hosts */,
    int			/* num_hosts */
){int result = 0; return result;}

int XReparentWindow(
    Display*		/* display */,
    Window		/* w */,
    Window		/* parent */,
    int			/* x */,
    int			/* y */
){int result = 0; return result;}

int XResetScreenSaver(
    Display*		/* display */
){int result = 0; return result;}

int XResizeWindow(
    Display*		/* display */,
    Window		/* w */,
    unsigned int	/* width */,
    unsigned int	/* height */
){int result = 0; return result;}

int XRestackWindows(
    Display*		/* display */,
    Window*		/* windows */,
    int			/* nwindows */
){int result = 0; return result;}

int XRotateBuffers(
    Display*		/* display */,
    int			/* rotate */
){int result = 0; return result;}

int XRotateWindowProperties(
    Display*		/* display */,
    Window		/* w */,
    Atom*		/* properties */,
    int			/* num_prop */,
    int			/* npositions */
){int result = 0; return result;}

int XScreenCount(
    Display*		/* display */
){int result = 0; return result;}

int XSelectInput(
    Display*		/* display */,
    Window		/* w */,
    long		/* event_mask */
){int result = 0; return result;}

Status XSendEvent(
    Display*		/* display */,
    Window		/* w */,
    Bool		/* propagate */,
    long		/* event_mask */,
    XEvent*		/* event_send */
){int result = 0; return result;}

int XSetAccessControl(
    Display*		/* display */,
    int			/* mode */
){int result = 0; return result;}

int XSetArcMode(
    Display*		/* display */,
    GC			/* gc */,
    int			/* arc_mode */
){int result = 0; return result;}

int XSetBackground(
    Display*		/* display */,
    GC			/* gc */,
    unsigned long	/* background */
){int result = 0; return result;}

int XSetClipMask(
    Display*		/* display */,
    GC			/* gc */,
    Pixmap		/* pixmap */
){int result = 0; return result;}

int XSetClipOrigin(
    Display*		/* display */,
    GC			/* gc */,
    int			/* clip_x_origin */,
    int			/* clip_y_origin */
){int result = 0; return result;}

int XSetClipRectangles(
    Display*		/* display */,
    GC			/* gc */,
    int			/* clip_x_origin */,
    int			/* clip_y_origin */,
    XRectangle*		/* rectangles */,
    int			/* n */,
    int			/* ordering */
){int result = 0; return result;}

int XSetCloseDownMode(
    Display*		/* display */,
    int			/* close_mode */
){int result = 0; return result;}

int XSetCommand(
    Display*		/* display */,
    Window		/* w */,
    char**		/* argv */,
    int			/* argc */
){int result = 0; return result;}

int XSetDashes(
    Display*		/* display */,
    GC			/* gc */,
    int			/* dash_offset */,
    _Xconst char*	/* dash_list */,
    int			/* n */
){int result = 0; return result;}

int XSetFillRule(
    Display*		/* display */,
    GC			/* gc */,
    int			/* fill_rule */
){int result = 0; return result;}

int XSetFillStyle(
    Display*		/* display */,
    GC			/* gc */,
    int			/* fill_style */
){int result = 0; return result;}

int XSetFont(
    Display*		/* display */,
    GC			/* gc */,
    Font		/* font */
){int result = 0; return result;}

int XSetFontPath(
    Display*		/* display */,
    char**		/* directories */,
    int			/* ndirs */
){int result = 0; return result;}

int XSetForeground(
    Display*		/* display */,
    GC			/* gc */,
    unsigned long	/* foreground */
){int result = 0; return result;}

int XSetFunction(
    Display*		/* display */,
    GC			/* gc */,
    int			/* function */
){int result = 0; return result;}

int XSetGraphicsExposures(
    Display*		/* display */,
    GC			/* gc */,
    Bool		/* graphics_exposures */
){int result = 0; return result;}

int XSetIconName(
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* icon_name */
){int result = 0; return result;}

int XSetInputFocus(
    Display*		/* display */,
    Window		/* focus */,
    int			/* revert_to */,
    Time		/* time */
){int result = 0; return result;}

int XSetLineAttributes(
    Display*		/* display */,
    GC			/* gc */,
    unsigned int	/* line_width */,
    int			/* line_style */,
    int			/* cap_style */,
    int			/* join_style */
){int result = 0; return result;}

int XSetModifierMapping(
    Display*		/* display */,
    XModifierKeymap*	/* modmap */
){int result = 0; return result;}

int XSetPlaneMask(
    Display*		/* display */,
    GC			/* gc */,
    unsigned long	/* plane_mask */
){int result = 0; return result;}

int XSetPointerMapping(
    Display*		/* display */,
    _Xconst unsigned char*	/* map */,
    int			/* nmap */
){int result = 0; return result;}

int XSetScreenSaver(
    Display*		/* display */,
    int			/* timeout */,
    int			/* interval */,
    int			/* prefer_blanking */,
    int			/* allow_exposures */
){int result = 0; return result;}

int XSetSelectionOwner(
    Display*		/* display */,
    Atom	        /* selection */,
    Window		/* owner */,
    Time		/* time */
){int result = 0; return result;}

int XSetState(
    Display*		/* display */,
    GC			/* gc */,
    unsigned long 	/* foreground */,
    unsigned long	/* background */,
    int			/* function */,
    unsigned long	/* plane_mask */
){int result = 0; return result;}

int XSetStipple(
    Display*		/* display */,
    GC			/* gc */,
    Pixmap		/* stipple */
){int result = 0; return result;}

int XSetSubwindowMode(
    Display*		/* display */,
    GC			/* gc */,
    int			/* subwindow_mode */
){int result = 0; return result;}

int XSetTSOrigin(
    Display*		/* display */,
    GC			/* gc */,
    int			/* ts_x_origin */,
    int			/* ts_y_origin */
){int result = 0; return result;}

int XSetTile(
    Display*		/* display */,
    GC			/* gc */,
    Pixmap		/* tile */
){int result = 0; return result;}

int XSetWindowBackground(
    Display*		/* display */,
    Window		/* w */,
    unsigned long	/* background_pixel */
){int result = 0; return result;}

int XSetWindowBackgroundPixmap(
    Display*		/* display */,
    Window		/* w */,
    Pixmap		/* background_pixmap */
){int result = 0; return result;}

int XSetWindowBorder(
    Display*		/* display */,
    Window		/* w */,
    unsigned long	/* border_pixel */
){int result = 0; return result;}

int XSetWindowBorderPixmap(
    Display*		/* display */,
    Window		/* w */,
    Pixmap		/* border_pixmap */
){int result = 0; return result;}

int XSetWindowBorderWidth(
    Display*		/* display */,
    Window		/* w */,
    unsigned int	/* width */
){int result = 0; return result;}

int XSetWindowColormap(
    Display*		/* display */,
    Window		/* w */,
    Colormap		/* colormap */
){int result = 0; return result;}

int XStoreBuffer(
    Display*		/* display */,
    _Xconst char*	/* bytes */,
    int			/* nbytes */,
    int			/* buffer */
){int result = 0; return result;}

int XStoreBytes(
    Display*		/* display */,
    _Xconst char*	/* bytes */,
    int			/* nbytes */
){int result = 0; return result;}

int XStoreColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    XColor*		/* color */
){int result = 0; return result;}

int XStoreColors(
    Display*		/* display */,
    Colormap		/* colormap */,
    XColor*		/* color */,
    int			/* ncolors */
){int result = 0; return result;}

int XStoreName(
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* window_name */
){int result = 0; return result;}

int XStoreNamedColor(
    Display*		/* display */,
    Colormap		/* colormap */,
    _Xconst char*	/* color */,
    unsigned long	/* pixel */,
    int			/* flags */
){int result = 0; return result;}

int XSync(
    Display*		/* display */,
    Bool		/* discard */
){int result = 0; return result;}

int XTextExtents(
    XFontStruct*	/* font_struct */,
    _Xconst char*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
){int result = 0; return result;}

int XTextExtents16(
    XFontStruct*	/* font_struct */,
    _Xconst XChar2b*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
){int result = 0; return result;}

int XTextWidth(
    XFontStruct*	/* font_struct */,
    _Xconst char*	/* string */,
    int			/* count */
){int result = 0; return result;}

int XTextWidth16(
    XFontStruct*	/* font_struct */,
    _Xconst XChar2b*	/* string */,
    int			/* count */
){int result = 0; return result;}

Bool XTranslateCoordinates(
    Display*		/* display */,
    Window		/* src_w */,
    Window		/* dest_w */,
    int			/* src_x */,
    int			/* src_y */,
    int*		/* dest_x_return */,
    int*		/* dest_y_return */,
    Window*		/* child_return */
){int result = 0; return result;}

int XUndefineCursor(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XUngrabButton(
    Display*		/* display */,
    unsigned int	/* button */,
    unsigned int	/* modifiers */,
    Window		/* grab_window */
){int result = 0; return result;}

int XUngrabKey(
    Display*		/* display */,
    int			/* keycode */,
    unsigned int	/* modifiers */,
    Window		/* grab_window */
){int result = 0; return result;}

int XUngrabKeyboard(
    Display*		/* display */,
    Time		/* time */
){int result = 0; return result;}

int XUngrabPointer(
    Display*		/* display */,
    Time		/* time */
){int result = 0; return result;}

int XUngrabServer(
    Display*		/* display */
){int result = 0; return result;}

int XUninstallColormap(
    Display*		/* display */,
    Colormap		/* colormap */
){int result = 0; return result;}

int XUnloadFont(
    Display*		/* display */,
    Font		/* font */
){int result = 0; return result;}

int XUnmapSubwindows(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XUnmapWindow(
    Display*		/* display */,
    Window		/* w */
){int result = 0; return result;}

int XVendorRelease(
    Display*		/* display */
){int result = 0; return result;}

int XWarpPointer(
    Display*		/* display */,
    Window		/* src_w */,
    Window		/* dest_w */,
    int			/* src_x */,
    int			/* src_y */,
    unsigned int	/* src_width */,
    unsigned int	/* src_height */,
    int			/* dest_x */,
    int			/* dest_y */
){int result = 0; return result;}

int XWidthMMOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XWidthOfScreen(
    Screen*		/* screen */
){int result = 0; return result;}

int XWindowEvent(
    Display*		/* display */,
    Window		/* w */,
    long		/* event_mask */,
    XEvent*		/* event_return */
){int result = 0; return result;}

int XWriteBitmapFile(
    Display*		/* display */,
    _Xconst char*	/* filename */,
    Pixmap		/* bitmap */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    int			/* x_hot */,
    int			/* y_hot */
){int result = 0; return result;}

Bool XSupportsLocale (void){int result = 0; return result;}

char *XSetLocaleModifiers(
    const char*		/* modifier_list */
){char* result = 0; return result;}

XOM XOpenOM(
    Display*			/* display */,
    struct _XrmHashBucketRec*	/* rdb */,
    _Xconst char*		/* res_name */,
    _Xconst char*		/* res_class */
){XOM result = 0; return result;}

Status XCloseOM(
    XOM			/* om */
){int result = 0; return result;}

char *XSetOMValues(
    XOM			/* om */,
    ...
) _X_SENTINEL(0){char* result = 0; return result;}

char *XGetOMValues(
    XOM			/* om */,
    ...
) _X_SENTINEL(0){char* result = 0; return result;}

Display *XDisplayOfOM(
    XOM			/* om */
){Display* result = 0; return result;}

char *XLocaleOfOM(
    XOM			/* om */
){char* result = 0; return result;}

XOC XCreateOC(
    XOM			/* om */,
    ...
) _X_SENTINEL(0){XOC result = 0; return result;}

void XDestroyOC(
    XOC			/* oc */
){}

XOM XOMOfOC(
    XOC			/* oc */
){XOM result = 0; return result;}

char *XSetOCValues(
    XOC			/* oc */,
    ...
) _X_SENTINEL(0){char* result = 0; return result;}

char *XGetOCValues(
    XOC			/* oc */,
    ...
) _X_SENTINEL(0){char* result = 0; return result;}

XFontSet XCreateFontSet(
    Display*		/* display */,
    _Xconst char*	/* base_font_name_list */,
    char***		/* missing_charset_list */,
    int*		/* missing_charset_count */,
    char**		/* def_string */
){XFontSet result = 0; return result;}

void XFreeFontSet(
    Display*		/* display */,
    XFontSet		/* font_set */
){}

int XFontsOfFontSet(
    XFontSet		/* font_set */,
    XFontStruct***	/* font_struct_list */,
    char***		/* font_name_list */
){int result = 0; return result;}

char *XBaseFontNameListOfFontSet(
    XFontSet		/* font_set */
){char* result = 0; return result;}

char *XLocaleOfFontSet(
    XFontSet		/* font_set */
){char* result = 0; return result;}

Bool XContextDependentDrawing(
    XFontSet		/* font_set */
){int result = 0; return result;}

Bool XDirectionalDependentDrawing(
    XFontSet		/* font_set */
){int result = 0; return result;}

Bool XContextualDrawing(
    XFontSet		/* font_set */
){int result = 0; return result;}

XFontSetExtents *XExtentsOfFontSet(
    XFontSet		/* font_set */
){XFontSetExtents* result = 0; return result;}

int XmbTextEscapement(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
){int result = 0; return result;}

int XwcTextEscapement(
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */
){int result = 0; return result;}

int Xutf8TextEscapement(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
){int result = 0; return result;}

int XmbTextExtents(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
){int result = 0; return result;}

int XwcTextExtents(
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
){int result = 0; return result;}

int Xutf8TextExtents(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
){int result = 0; return result;}

Status XmbTextPerCharExtents(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */,
    XRectangle*		/* ink_extents_buffer */,
    XRectangle*		/* logical_extents_buffer */,
    int			/* buffer_size */,
    int*		/* num_chars */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
){int result = 0; return result;}

Status XwcTextPerCharExtents(
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */,
    XRectangle*		/* ink_extents_buffer */,
    XRectangle*		/* logical_extents_buffer */,
    int			/* buffer_size */,
    int*		/* num_chars */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
){int result = 0; return result;}

Status Xutf8TextPerCharExtents(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */,
    XRectangle*		/* ink_extents_buffer */,
    XRectangle*		/* logical_extents_buffer */,
    int			/* buffer_size */,
    int*		/* num_chars */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
){int result = 0; return result;}

void XmbDrawText(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XmbTextItem*	/* text_items */,
    int			/* nitems */
){}

void XwcDrawText(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XwcTextItem*	/* text_items */,
    int			/* nitems */
){}

void Xutf8DrawText(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XmbTextItem*	/* text_items */,
    int			/* nitems */
){}

void XmbDrawString(
    Display*		/* display */,
    Drawable		/* d */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
){}

void XwcDrawString(
    Display*		/* display */,
    Drawable		/* d */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */
){}

void Xutf8DrawString(
    Display*		/* display */,
    Drawable		/* d */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
){}

void XmbDrawImageString(
    Display*		/* display */,
    Drawable		/* d */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
){}

void XwcDrawImageString(
    Display*		/* display */,
    Drawable		/* d */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */
){}

void Xutf8DrawImageString(
    Display*		/* display */,
    Drawable		/* d */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
){}

XIM XOpenIM(
    Display*			/* dpy */,
    struct _XrmHashBucketRec*	/* rdb */,
    char*			/* res_name */,
    char*			/* res_class */
){XIM result = 0; return result;}

Status XCloseIM(
    XIM /* im */
){int result = 0; return result;}

char *XGetIMValues(
    XIM /* im */, ...
) _X_SENTINEL(0){char* result = 0; return result;}

char *XSetIMValues(
    XIM /* im */, ...
) _X_SENTINEL(0){char* result = 0; return result;}

Display *XDisplayOfIM(
    XIM /* im */
){Display* result = 0; return result;}

char *XLocaleOfIM(
    XIM /* im*/
){char* result = 0; return result;}

XIC XCreateIC(
    XIM /* im */, ...
) _X_SENTINEL(0){XIC result = 0; return result;}

void XDestroyIC(
    XIC /* ic */
){}

void XSetICFocus(
    XIC /* ic */
){}

void XUnsetICFocus(
    XIC /* ic */
){}

wchar_t *XwcResetIC(
    XIC /* ic */
){wchar_t* result = 0; return result;}

char *XmbResetIC(
    XIC /* ic */
){char* result = 0; return result;}

char *Xutf8ResetIC(
    XIC /* ic */
){char* result = 0; return result;}

char *XSetICValues(
    XIC /* ic */, ...
) _X_SENTINEL(0){char* result = 0; return result;}

char *XGetICValues(
    XIC /* ic */, ...
) _X_SENTINEL(0){char* result = 0; return result;}

XIM XIMOfIC(
    XIC /* ic */
){XIM result = 0; return result;}

Bool XFilterEvent(
    XEvent*	/* event */,
    Window	/* window */
){int result = 0; return result;}

int XmbLookupString(
    XIC			/* ic */,
    XKeyPressedEvent*	/* event */,
    char*		/* buffer_return */,
    int			/* bytes_buffer */,
    KeySym*		/* keysym_return */,
    Status*		/* status_return */
){int result = 0; return result;}

int XwcLookupString(
    XIC			/* ic */,
    XKeyPressedEvent*	/* event */,
    wchar_t*		/* buffer_return */,
    int			/* wchars_buffer */,
    KeySym*		/* keysym_return */,
    Status*		/* status_return */
){int result = 0; return result;}

int Xutf8LookupString(
    XIC			/* ic */,
    XKeyPressedEvent*	/* event */,
    char*		/* buffer_return */,
    int			/* bytes_buffer */,
    KeySym*		/* keysym_return */,
    Status*		/* status_return */
){int result = 0; return result;}

XVaNestedList XVaCreateNestedList(
    int /*unused*/, ...
) _X_SENTINEL(0){XVaNestedList result = 0; return result;}

/* internal connections for IMs */

Bool XRegisterIMInstantiateCallback(
    Display*			/* dpy */,
    struct _XrmHashBucketRec*	/* rdb */,
    char*			/* res_name */,
    char*			/* res_class */,
    XIDProc			/* callback */,
    XPointer			/* client_data */
){int result = 0; return result;}

Bool XUnregisterIMInstantiateCallback(
    Display*			/* dpy */,
    struct _XrmHashBucketRec*	/* rdb */,
    char*			/* res_name */,
    char*			/* res_class */,
    XIDProc			/* callback */,
    XPointer			/* client_data */
){int result = 0; return result;}

Status XInternalConnectionNumbers(
    Display*			/* dpy */,
    int**			/* fd_return */,
    int*			/* count_return */
){int result = 0; return result;}

void XProcessInternalConnection(
    Display*			/* dpy */,
    int				/* fd */
){}

Status XAddConnectionWatch(
    Display*			/* dpy */,
    XConnectionWatchProc	/* callback */,
    XPointer			/* client_data */
){int result = 0; return result;}

void XRemoveConnectionWatch(
    Display*			/* dpy */,
    XConnectionWatchProc	/* callback */,
    XPointer			/* client_data */
){}

void XSetAuthorization(
    char *			/* name */,
    int				/* namelen */,
    char *			/* data */,
    int				/* datalen */
){}

int _Xmbtowc(
    wchar_t *			/* wstr */,
#ifdef ISC
    char const *		/* str */,
    size_t			/* len */
#else
    char *			/* str */,
    int				/* len */
#endif
){int result = 0; return result;}

int _Xwctomb(
    char *			/* str */,
    wchar_t			/* wc */
){int result = 0; return result;}

Bool XGetEventData(
    Display*			/* dpy */,
    XGenericEventCookie*	/* cookie*/
){int result = 0; return result;}

void XFreeEventData(
    Display*			/* dpy */,
    XGenericEventCookie*	/* cookie*/
){}

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

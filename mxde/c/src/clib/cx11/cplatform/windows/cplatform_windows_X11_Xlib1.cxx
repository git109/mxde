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

/*
 * Display
 */

Display *XOpenDisplay(_Xconst char*)
{
    Display* display = 0;
    return display;
}
int XCloseDisplay(Display* display)
{
    int err = 0;
    return err;
}
unsigned long XBlackPixel(Display* display, int screenNo)
{
    long pixel = 0;
    return pixel;
}
int XScreenNumberOfScreen(Screen* screen)
{
    int screenNo = 0;
    return screenNo;
}
Screen *XDefaultScreenOfDisplay(Display* display)
{
    Screen* screen = 0;
    return screen;
}
int XNextEvent(Display* display, XEvent* xEvent)
{
    int err = 0;
    return err;
}

/*
 * Window
 */

Window XCreateSimpleWindow
(Display* display, Window parent,
 int x, int y, unsigned int width, unsigned int height,
 unsigned int border_width, unsigned long border, unsigned long background)
{
    Window window = None;
    return window;
}
int XDestroyWindow(Display* display, Window window)
{
    int err = 0;
    return err;
}

int XMapWindow(Display* display, Window window)
{
    int err = 0;
    return err;
}
int XUnmapWindow(Display* display, Window window)
{
    int err = 0;
    return err;
}

int XMoveWindow
(Display* display, Window window, int x, int y)
{
    int err = 0;
    return err;
}
int XResizeWindow
(Display* display, Window window, 
 unsigned int width, unsigned int height)
{
    int err = 0;
    return err;
}
int XMoveResizeWindow
(Display* display, Window window, int x, int y,
 unsigned int width, unsigned int height)
{
    int err = 0;
    return err;
}
int XChangeWindowAttributes
(Display* display, Window window,
 unsigned long valuemask, XSetWindowAttributes* attributes)
{
    int err = 0;
    return err;
}
int XGetWindowAttributes
(Display* display, Window window,
 XWindowAttributes* attributes)
{
    int err = 0;
    return err;
}
Status XQueryTree
(Display* display, Window window,
 Window* root_window, Window* parent_window, 
 Window** child_window, unsigned int* child_windows)
{
    Status status = Success;
    return status;
}

/*
 * GC
 */

GC XCreateGC
(Display* display, Drawable drawable, 
 unsigned long valuemask, XGCValues* values)
{
    GC gc = None;
    return gc;
}
int XFreeGC(Display* display, GC gc)
{
    int err = 0;
    return err;
}

/*
 * Text
 */

int XDrawText(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XTextItem*		/* items */,
    int			/* nitems */
)
int XDrawText16(
    Display*		/* display */,
    Drawable		/* d */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    XTextItem16*	/* items */,
    int			/* nitems */
)
int XQueryTextExtents(
    Display*		/* display */,
    XID			/* font_ID */,
    _Xconst char*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
)
int XQueryTextExtents16(
    Display*		/* display */,
    XID			/* font_ID */,
    _Xconst XChar2b*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
)
int XTextExtents(
    XFontStruct*	/* font_struct */,
    _Xconst char*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
)
int XTextExtents16(
    XFontStruct*	/* font_struct */,
    _Xconst XChar2b*	/* string */,
    int			/* nchars */,
    int*		/* direction_return */,
    int*		/* font_ascent_return */,
    int*		/* font_descent_return */,
    XCharStruct*	/* overall_return */
)
int XTextWidth(
    XFontStruct*	/* font_struct */,
    _Xconst char*	/* string */,
    int			/* count */
)
int XTextWidth16(
    XFontStruct*	/* font_struct */,
    _Xconst XChar2b*	/* string */,
    int			/* count */
)
int XmbTextEscapement(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
)
int XwcTextEscapement(
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */
)
int Xutf8TextEscapement(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */
)
int XmbTextExtents(
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* bytes_text */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
)
int XwcTextExtents(
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* num_wchars */,
    XRectangle*		/* overall_ink_return */,
    XRectangle*		/* overall_logical_return */
)

/*
 * Font
 */

XFontStruct *XLoadQueryFont(
    Display*		/* display */,
    _Xconst char*	/* name */
)
{
    XFontStruct* err = 0;
    return err;
}
XFontStruct *XQueryFont(
    Display*		/* display */,
    XID			/* font_ID */
)
{
    XFontStruct* err = 0;
    return err;
}
Font XLoadFont(
    Display*		/* display */,
    _Xconst char*	/* name */
)
{
    Font err = 0;
    return err;
}
char **XListFonts(
    Display*		/* display */,
    _Xconst char*	/* pattern */,
    int			/* maxnames */,
    int*		/* actual_count_return */
)
{
    char** err = 0;
    return err;
}
char **XListFontsWithInfo(
    Display*		/* display */,
    _Xconst char*	/* pattern */,
    int			/* maxnames */,
    int*		/* count_return */,
    XFontStruct**	/* info_return */
)
{
    char** err = 0;
    return err;
}
char **XGetFontPath(
    Display*		/* display */,
    int*		/* npaths_return */
)
{
    char** err = 0;
    return err;
}
int XFreeFont(
    Display*		/* display */,
    XFontStruct*	/* font_struct */
)
{
    int err = 0;
    return err;
}
int XFreeFontInfo(
    char**		/* names */,
    XFontStruct*	/* free_info */,
    int			/* actual_count */
)
{
    int err = 0;
    return err;
}
int XFreeFontNames(
    char**		/* list */
)
{
    int err = 0;
    return err;
}
int XFreeFontPath(
    char**		/* list */
)
{
    int err = 0;
    return err;
}
Bool XGetFontProperty(
    XFontStruct*	/* font_struct */,
    Atom		/* atom */,
    unsigned long*	/* value_return */
)
{
    Bool err = 0;
    return err;
}
int XSetFont(
    Display*		/* display */,
    GC			/* gc */,
    Font		/* font */
)
{
    int err = 0;
    return err;
}
int XSetFontPath(
    Display*		/* display */,
    char**		/* directories */,
    int			/* ndirs */
)
{
    int err = 0;
    return err;
}
int XUnloadFont(
    Display*		/* display */,
    Font		/* font */
)
{
    int err = 0;
    return err;
}
XFontSet XCreateFontSet(
    Display*		/* display */,
    _Xconst char*	/* base_font_name_list */,
    char***		/* missing_charset_list */,
    int*		/* missing_charset_count */,
    char**		/* def_string */
)
{
    XFontSet err = 0;
    return err;
}
void XFreeFontSet(
    Display*		/* display */,
    XFontSet		/* font_set */
)
{
}
int XFontsOfFontSet(
    XFontSet		/* font_set */,
    XFontStruct***	/* font_struct_list */,
    char***		/* font_name_list */
)
{
    int err = 0;
    return err;
}
char *XBaseFontNameListOfFontSet(
    XFontSet		/* font_set */
)
{
    char* err = 0;
    return err;
}
char *XLocaleOfFontSet(
    XFontSet		/* font_set */
)
{
    char* err = 0;
    return err;
}
XFontSetExtents *XExtentsOfFontSet(
    XFontSet		/* font_set */
)
{
    XFontSetExtents* err = 0;
    return err;
}

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

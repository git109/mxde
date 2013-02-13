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

int XSaveContext
(Display*display, XID rid, XContext context, _Xconst char* data)
{
    int err = 0;
    return err;
}
int XDeleteContext
(Display* display,  XID rid,  XContext context)
{
    int err = 0;
    return err;
}
int XFindContext
(Display* display, XID rid, XContext context, XPointer* data_return)
{
    int err = 0;
    return err;
}

/*
 * Region
 */

Region XCreateRegion(void)
{
    Region r = 0;
    return r;
}
int XDestroyRegion(Region r)
{
    int err = 0;
    return err;
}
int XSetRegion(Display* display, GC gc, Region r)
{
    int err = 0;
    return err;
}
int XEmptyRegion(
    Region		/* r */
)
{
    int err = 0;
    return err;
}
int XEqualRegion(
    Region		/* r1 */,
    Region		/* r2 */
)
{
    int err = 0;
    return err;
}
int XOffsetRegion(
    Region		/* r */,
    int			/* dx */,
    int			/* dy */
)
{
    int err = 0;
    return err;
}
Bool XPointInRegion(
    Region		/* r */,
    int			/* x */,
    int			/* y */
)
{
    int err = 0;
    return err;
}
Region XPolygonRegion(
    XPoint*		/* points */,
    int			/* n */,
    int			/* fill_rule */
)
{
    Region r = 0;
    return r;
}
int XRectInRegion(
    Region		/* r */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */
)
{
    int err = 0;
    return err;
}
int XIntersectRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
)
{
    int err = 0;
    return err;
}
int XShrinkRegion(
    Region		/* r */,
    int			/* dx */,
    int			/* dy */
)
{
    int err = 0;
    return err;
}
int XSubtractRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
)
{
    int err = 0;
    return err;
}
int XUnionRectWithRegion(
    XRectangle*		/* rectangle */,
    Region		/* src_region */,
    Region		/* dest_region_return */
)
{
    int err = 0;
    return err;
}
int XUnionRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
)
{
    int err = 0;
    return err;
}
int XXorRegion(
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
)
{
    int err = 0;
    return err;
}
#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

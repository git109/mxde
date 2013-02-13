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
 *   File: cxpixmap.hxx
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
#if !defined(_CXPIXMAP_HXX) || defined(CXPIXMAP_MEMBERS_ONLY)
#if !defined(_CXPIXMAP_HXX) && !defined(CXPIXMAP_MEMBERS_ONLY)
#define _CXPIXMAP_HXX
#endif /* !defined(_CXPIXMAP_HXX) && !defined(CXPIXMAP_MEMBERS_ONLY) */

#if !defined(CXPIXMAP_MEMBERS_ONLY)
#include "cplatform_X11_xpm.h"
#include "cxpixmapinterface.hxx"
#include "cstringbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXPixmapExtend
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cXPixmapCreated
cXPixmapExtend;
/**
 **********************************************************************
 *  Class: cXPixmap
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXPixmap
: virtual public cXPixmapImplement,
  public cXPixmapExtend
{
public:
    typedef cXPixmapImplement cImplements;
    typedef cXPixmapExtend cExtends;

    cXDisplayInterface& m_display;
    unsigned int m_width, m_height, m_depth;

    /**
     **********************************************************************
     *  Constructor: cXPixmap
     *
     *       Author: $author$           
     *         Date: 6/1/2010
     **********************************************************************
     */
    cXPixmap
    (cXDisplayInterface& display,
     tAttachedTo attached=None,
     unsigned int width=0, 
     unsigned int height=0,
     unsigned int depth=0,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_display(display),
      m_width(width),
      m_height(height),
      m_depth(depth)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXPixmap
     *
     *      Author: $author$           
     *        Date: 6/1/2010
     **********************************************************************
     */
    virtual ~cXPixmap()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("()\n throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXPIXMAP_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAP_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CopyArea
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CopyArea
    (Drawable xDrawable, 
     cXPixmapInterface& pixmapMask,
     int toX=0, int toY=0, int x=0, int y=0) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
        Pixmap xPixmapMask = pixmapMask.Attached();
        eError error = CopyArea
        (xDrawable, xPixmapMask, toX,toY, x,y);
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CopyArea
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CopyArea
    (Drawable xDrawable, GC xGC,
     cXPixmapInterface& pixmapMask,
     int toX=0, int toY=0, int x=0, int y=0) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
        Pixmap xPixmapMask = pixmapMask.Attached();
        eError error = CopyArea
        (xDrawable, xGC, xPixmapMask, toX,toY, x,y);
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CopyArea
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CopyArea
    (Drawable xDrawable, 
     int toX=0, int toY=0, int x=0, int y=0) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Pixmap xPixmap;
        GC xGC;
        unsigned width;
        unsigned height;

        eError error = e_ERROR_FAILED;

        if (None != (xDrawable))
        if ((xDisplay = m_display.Attached()))
        if (None != (xPixmap = Attached()))
        if ((width = m_width) && (height = m_height))
        if ((xGC = XCreateGC(xDisplay, xDrawable, 0,0)))
        {
            XCopyArea
            (xDisplay, xPixmap, xDrawable, xGC, 
             x,y, width,height, toX,toY);

            XFreeGC(xDisplay, xGC);

            error = e_ERROR_NONE;
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CopyArea
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CopyArea
    (Drawable xDrawable, Pixmap xPixmapMask,
     int toX=0, int toY=0, int x=0, int y=0) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Pixmap xPixmap;
        GC xGC;
        unsigned width;
        unsigned height;
        bool masked;

        eError error = e_ERROR_FAILED;

        if (None != (xDrawable))
        if ((xDisplay = m_display.Attached()))
        if (None != (xPixmap = Attached()))
        if ((width = m_width) && (height = m_height))
        if ((xGC = XCreateGC(xDisplay, xDrawable, 0,0)))
        {
            if (masked = (None != xPixmapMask))
            {
                XSetClipMask(xDisplay, xGC, xPixmapMask);
                XSetClipOrigin(xDisplay, xGC, toX,toY);
            }
            XCopyArea
            (xDisplay, xPixmap, xDrawable, xGC, 
             x,y, width,height, toX,toY);

            if (masked)
            {
                XSetClipMask(xDisplay, xGC, None);
                XSetClipOrigin(xDisplay, xGC, 0,0);
            }
            XFreeGC(xDisplay, xGC);

            error = e_ERROR_NONE;
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CopyArea
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CopyArea
    (Drawable xDrawable, GC xGC,
     int toX=0, int toY=0, int x=0, int y=0) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Pixmap xPixmap;
        unsigned width;
        unsigned height;

        eError error = e_ERROR_FAILED;

        if ((xGC))
        if (None != (xDrawable))
        if ((xDisplay = m_display.Attached()))
        if (None != (xPixmap = Attached()))
        if ((width = m_width) && (height = m_height))
        {
            XCopyArea
            (xDisplay, xPixmap, xDrawable, xGC, 
             x,y, width,height, toX,toY);

            error = e_ERROR_NONE;
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CopyArea
     *
     *    Author: $author$           
     *      Date: 6/2/2010
     **********************************************************************
     */
    virtual eError CopyArea
    (Drawable xDrawable, GC xGC, Pixmap xPixmapMask,
     int toX=0, int toY=0, int x=0, int y=0) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Pixmap xPixmap;
        unsigned int width;
        unsigned int height;
        bool masked;

        eError error = e_ERROR_FAILED;

        if ((xGC))
        if (None != (xDrawable))
        if ((xDisplay = m_display.Attached()))
        if (None != (xPixmap = Attached()))
        if ((width = m_width) && (height = m_height))
        {
            if (masked = (None != xPixmapMask))
            {
                XSetClipMask(xDisplay, xGC, xPixmapMask);
                XSetClipOrigin(xDisplay, xGC, toX,toY);
            }
            XCopyArea
            (xDisplay, xPixmap, xDrawable, xGC, 
             x,y, width,height, toX,toY);

            if (masked)
            {
                XSetClipMask(xDisplay, xGC, None);
                XSetClipOrigin(xDisplay, xGC, 0,0);
            }
            error = e_ERROR_NONE;
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreateFromFile
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CreateFromFile
    (cXPixmapInterface& mask, 
     Drawable xDrawable,
     const char* filename,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        Pixmap detachedMask = None;
        Pixmap attached;
        
        if (None != (attached = CreateFromFileAttached
            (detachedMask, error, xDrawable, filename, onlyDestroyed)))
        {
            if (detachedMask == (mask.Attach(detachedMask)))
            if (0 < (mask.SetIsCreated()))
                return error;

            DestroyDetached(detachedMask);
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateFromFile
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CreateFromFile
    (Drawable xDrawable,
     const char* filename,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        Pixmap attached = CreateFromFileAttached
        (error, xDrawable, filename, onlyDestroyed);
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateFromFile
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual eError CreateFromFile
    (Pixmap& detachedMask, 
     Drawable xDrawable,
     const char* filename,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        Pixmap attached = CreateFromFileAttached
        (detachedMask, error, xDrawable, filename, onlyDestroyed);
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateFromFileAttached
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual Pixmap CreateFromFileAttached
    (eError& error,
     Drawable xDrawable,
     const char* filename,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Pixmap xPixmap;
        unsigned int width, height, depth;

        if (!(error = Destroyed(onlyDestroyed)))
        if (None != (xPixmap = CreateDetachedFromFile
            (width,height,depth, error, xDrawable,filename)))
        {
            if (xPixmap == (Attach(xPixmap)))
            if (0 < (SetIsCreated()))
            {
                m_width = width;
                m_height = height;
                m_depth = depth;
                return xPixmap;
            }
            else
            Detach();

            DestroyDetached(xPixmap);
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return None;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateFromFileAttached
     *
     *    Author: $author$           
     *      Date: 6/3/2010
     **********************************************************************
     */
    virtual Pixmap CreateFromFileAttached
    (Pixmap& detachedMask, 
     eError& error,
     Drawable xDrawable,
     const char* filename,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Pixmap xPixmap;
        Pixmap xPixmapMask;
        unsigned int width, height, depth;

        if (!(error = Destroyed(onlyDestroyed)))
        if (None != (xPixmap = CreateDetachedFromFile
            (xPixmapMask, width,height,depth, 
             error, xDrawable,filename)))
        {
            if (xPixmap == (Attach(xPixmap)))
            if (0 < (SetIsCreated()))
            {
                m_width = width;
                m_height = height;
                m_depth = depth;
                detachedMask  = xPixmapMask;
                return xPixmap;
            }
            else
            Detach();

            DestroyDetached(xPixmapMask);
            DestroyDetached(xPixmap);
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return None;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError Create
    (Drawable xDrawable, 
     unsigned int width, 
     unsigned int height, 
     unsigned int depth = 1,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateAttached
        (error, xDrawable, width, height, depth, onlyDestroyed);
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        Pixmap detached;

        if (None != (detached =  Detach()))
            error = DestroyDetached(detached);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual Pixmap CreateAttached
    (eError& error,
     Drawable xDrawable, 
     unsigned int width, 
     unsigned int height, 
     unsigned int depth = 1,
     bool onlyDestroyed = false)
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Pixmap detached;

        if (!(error = Destroyed(onlyDestroyed)))
        if (None != (detached = CreateDetached
            (error, xDrawable, width, height, depth)))
        {
            if (detached == (Attach(detached)))
            if (0 < (SetIsCreated()))
                return detached;
            else Detach();

            DestroyDetached(detached);
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return None;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreateDetachedFromFile
     *
     *    Author: $author$           
     *      Date: 6/2/2010
     **********************************************************************
     */
    virtual Pixmap CreateDetachedFromFile
    (unsigned int& width, 
     unsigned int& height, 
     unsigned int& depth,
     eError& error,
     Drawable xDrawable,
     const char* filename) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
        Pixmap detachedMask = None;
        Pixmap detached = None;

        if (None != (detached  = CreateDetachedFromFile
            (detachedMask, width, height, depth, 
             error, xDrawable, filename)))
        if (None != (detachedMask))
            DestroyDetached(detachedMask);

#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetachedFromFile
     *
     *    Author: $author$           
     *      Date: 6/2/2010
     **********************************************************************
     */
    virtual Pixmap CreateDetachedFromFile
    (Pixmap& detachedMask, 
     unsigned int& width, 
     unsigned int& height, 
     unsigned int& depth,
     eError& error,
     Drawable xDrawable,
     const char* filename) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
        Pixmap detached = None;
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Screen* xScreen;
        Pixmap pixmap;
        Pixmap pixmapMask;
        XpmAttributes xpmAttributes;
        int err;
        char* fileNameStr;
        cStringBase fileName;

        detachedMask = None;
        error = e_ERROR_FAILED;

        if (0 < (fileName.assign(filename)))
        if ((fileNameStr = fileName.str()))
        if (None != (xDrawable))
        if ((xDisplay = m_display.Attached()))
        if ((xScreen = DefaultScreenOfDisplay(xDisplay)))
        if (0 < (depth = DefaultDepthOfScreen(xScreen)))
        {
            DBT(("() DefaultDepthOfScreen(xScreen) = %u\n", depth));

            xpmAttributes.valuemask = ( XpmSize | XpmDepth );
            xpmAttributes.depth = depth;
            
            if (XpmSuccess != (err = XpmReadFileToPixmap
                (xDisplay, xDrawable, fileNameStr, 
                 &pixmap, &pixmapMask, &xpmAttributes)))
                 DBE
                 (("()\n failed err = %d on XpmReadFileToPixmap(%p, 0x%Xd, \"%s\",...)\n", 
                  err, xDisplay, xDrawable, fileNameStr));
            else
            {
                DBT
                (("()\n width=%u height=%u depth=%u\n", 
                 xpmAttributes.width, xpmAttributes.height, xpmAttributes.depth));

                detached = pixmap;
                detachedMask = pixmapMask;
                width = xpmAttributes.width;
                height = xpmAttributes.height;
                depth = xpmAttributes.depth;
                error = e_ERROR_NONE;
            }
        }
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        detachedMask = None;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual Pixmap CreateDetached
    (eError& error,
     Drawable xDrawable, 
     unsigned int width, 
     unsigned int height, 
     unsigned int depth = 1) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
        Pixmap detached = None;
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;

        error = e_ERROR_FAILED;

        if (None != (xDrawable))
        if ((xDisplay = m_display.Attached()))
        if (None != (detached = XCreatePixmap
            (xDisplay, xDrawable, width, height, depth)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed on XCreatePixmap()\n"));
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyDetached
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (Pixmap detached) const
#if defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        Display* xDisplay;
        int err;
        if (None != (detached))
        if ((xDisplay = m_display.Attached()))
        if ((err = XFreePixmap(xDisplay, detached)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed err = %d on XFreePixmap()\n", err));
#else /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPIXMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPIXMAP_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXPIXMAP_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPIXMAP_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAP_MEMBERS_ONLY) */

#endif /* !defined(_CXPIXMAP_HXX) || defined(CXPIXMAP_MEMBERS_ONLY) */

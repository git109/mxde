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
 *   File: cxwindow.hxx
 *
 * Author: $author$           
 *   Date: 6/28/2010
 **********************************************************************
 */
#if !defined(_CXWINDOW_HXX) || defined(CXWINDOW_MEMBERS_ONLY)
#if !defined(_CXWINDOW_HXX) && !defined(CXWINDOW_MEMBERS_ONLY)
#define _CXWINDOW_HXX
#endif /* !defined(_CXWINDOW_HXX) && !defined(CXWINDOW_MEMBERS_ONLY) */

#if !defined(CXWINDOW_MEMBERS_ONLY)
#include "cxwindowinterface.hxx"
#include "cxwindowcreated.hxx"
#include "cxregion.hxx"
#include "cxrectangle.hxx"
#include "cxgc.hxx"
#include "cdebug.hxx"

#define CXWINDOW_DEFAULT_XCONTEXT 1

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXWindowExtend
 *
 *  Author: $author$           
 *    Date: 6/28/2010
 **********************************************************************
 */
typedef cXWindowCreated
cXWindowExtend;
/**
 **********************************************************************
 *  Class: cXWindow
 *
 * Author: $author$           
 *   Date: 6/28/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXWindow
: virtual public cXWindowImplement,
  public cXWindowExtend
{
public:
    typedef cXWindowImplement cImplements;
    typedef cXWindowExtend cExtends;

    static long m_defaultXEventMask;
    static long m_defaultGrabXEventMask;
    static XContext m_defaultXContext;

    cXDisplayInterface& m_display;

    XContext m_xContext, m_savedXContext;
    long m_xEventMask, m_selectedXEventMask;
    long m_grabXEventMask, m_grabbedXEventMask;
    unsigned int m_exposeEventCount;

    cXEventTargetInterface* m_delegateAfterTo;
    cXEventTargetInterface* m_delegateBeforeTo;

    cXRegion m_paintRegion;
    cXRectangle m_paintRect;

    cXGC m_gc;

    /**
     **********************************************************************
     *  Constructor: cXWindow
     *
     *       Author: $author$           
     *         Date: 6/28/2010
     **********************************************************************
     */
    cXWindow
    (cXDisplayInterface& display,
     Window attached = None,
     bool isCreated = false,
     cXEventTargetInterface* delegateAfterTo=0,
     cXEventTargetInterface* delegateBeforeTo=0) 
    : cExtends(attached, isCreated),
      m_display(display),

      m_xContext(m_defaultXContext),
      m_savedXContext(None),

      m_xEventMask(m_defaultXEventMask),
      m_selectedXEventMask(0),
      m_grabXEventMask(m_defaultGrabXEventMask),
      m_grabbedXEventMask(0),
      m_exposeEventCount(0),

      m_paintRegion(display),
      m_gc(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXWindow
     *
     *      Author: $author$           
     *        Date: 6/28/2010
     **********************************************************************
     */
    virtual ~cXWindow()
    {
    }
#else /* !defined(CXWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateSimple
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError CreateSimple
    (Window parentXWindow, int x,int y, 
     unsigned int width,unsigned int height, 
     unsigned int borderWidth, Pixel border, 
     Pixel background, bool onlyDestroyed = false)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateSimpleAttached
        (error, parentXWindow, x,y, width,height, 
         borderWidth, border, background);
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateSimpleAttached
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual Window CreateSimpleAttached
    (eError& error, Window parentXWindow, int x,int y, 
     unsigned int width,unsigned int height, 
     unsigned int borderWidth, Pixel border, 
     Pixel background, bool onlyDestroyed = false)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Window detached;

        if (!(error = Destroyed(onlyDestroyed)))

        if (None != (detached = CreateSimpleDetached
            (error, parentXWindow, x,y, width,height, 
             borderWidth, border, background)))
        {
            if (detached == (AttachCreated(detached)))
            {
                if (!(error = SaveXContext(m_xContext)))
                {
                    if (!(error = SelectInput(m_xEventMask)))
                        return detached;

                    DeleteXContext();
                }

                Detach();
            }

            DestroyDetached(detached);
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return None;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateSimpleDetached
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual Window CreateSimpleDetached
    (eError& error, Window parentXWindow, int x,int y, 
     unsigned int width,unsigned int height, 
     unsigned int borderWidth, Pixel border, Pixel background) const
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        Window detached = None;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;

        error = e_ERROR_NOT_ATTACHED;

        if ((xDisplay = DisplayAttached()))
        if (None != (detached = XCreateSimpleWindow
            (xDisplay, parentXWindow, x,y, width,height, 
             borderWidth,border, background)))
             error = e_ERROR_NONE;
        else
        {
            DBE(("()\n failed on XCreateSimpleWindow()\n"));
            error = e_ERROR_FAILED;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        eError error2;
        Window detached;

        if (None != (detached = Detach()))
        {
            error = m_gc.Destroy();

            if ((error2 = DeleteXContext()))
            if (!error)
                error = error2;

            if ((error2 = DestroyDetached(detached)))
            if (!error)
                error = error2;
        }
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyDetached
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (Window detached) const
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Status status;

        if (None != (detached))
        if ((xDisplay = DisplayAttached()))
        if (!(status = XDestroyWindow(xDisplay, detached)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n status = %d on XDestroyWindow"
             "(xDisplay=%p, detached=0x%x)", 
             status, xDisplay, detached));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Map
     *
     *   Author: $author$           
     *     Date: 6/23/2009
     **********************************************************************
     */
    virtual eError Map() 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        int err;
        if (None != (xWindow = Attached()))
        if ((xDisplay = DisplayAttached()))
        {
            err = XMapWindow(xDisplay,xWindow);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Unmap
     *
     *   Author: $author$           
     *     Date: 6/23/2009
     **********************************************************************
     */
    virtual eError Unmap() 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        int err;
        if (None != (xWindow = Attached()))
        if ((xDisplay = DisplayAttached()))
        {
            err = XUnmapWindow(xDisplay,xWindow);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnPaint
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual eError OnPaint
    (const XEvent& xEvent) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        eError error2;
        cXRectangle* rect;
        cXRegionInterface* region;
        cXGCInterface* gc;

        DBI(("() \n"));

        if ((gc = BeginPaint(region, rect, error)))
        {
            error = Paint(*gc, *region, *rect);
            if ((error2 = EndPaint(*gc, *region, *rect)))
            if (!error)
                error = error2;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BeginPaint
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual cXGCInterface* BeginPaint
    (cXRegionInterface*& region,
     cXRectangle*& rect,
     eError& error) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        cXGCInterface* gc = 0;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Region xRegion;

        DBI(("() \n"));

        region = 0; rect = 0; 
        error = e_ERROR_NOT_ATTACHED;

        if (None != (xRegion = m_paintRegion.Attached()))
        if ((gc = GetGC(error)))
        {
            region = &m_paintRegion;
            rect = &m_paintRect;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        region = 0; rect = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return gc;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: EndPaint
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual eError EndPaint
    (cXGCInterface& gc,
     cXRegionInterface& region,
     cXRectangle& rect) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        eError error = FreeGC(gc);

        DBI(("() \n"));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual eError Paint
    (cXGCInterface& gc,
     cXRegionInterface& region,
     cXRectangle& rect) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 

        DBI(("() \n"));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetRootWindow
     *
     *    Author: $author$           
     *      Date: 6/29/2010
     **********************************************************************
     */
    virtual Window GetRootWindow
    (eError& error)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        Window xWindow = None;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Window xRootWindow;
        Window xParentWindow;
        Window* xWindowChild;
        unsigned xWindowChildren;

        if (!(error = QueryTree
            (xRootWindow, xParentWindow, 
             xWindowChild, xWindowChildren)))
            xWindow = xRootWindow;

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return xWindow;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetParentWindow
     *
     *    Author: $author$           
     *      Date: 6/29/2010
     **********************************************************************
     */
    virtual Window GetParentWindow
    (eError& error)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        Window xWindow = None;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Window xRootWindow;
        Window xParentWindow;
        Window* xWindowChild;
        unsigned xWindowChildren;

        if (!(error = QueryTree
            (xRootWindow, xParentWindow, 
             xWindowChild, xWindowChildren)))
            xWindow = xParentWindow;

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return xWindow;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryTree
     *
     *    Author: $author$           
     *      Date: 6/29/2010
     **********************************************************************
     */
    virtual eError QueryTree
    (Window& xRootWindow, Window& xParentWindow, 
     Window*& xWindowChild, unsigned int& xWindowChildren)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = DisplayAttached()))
        if ((xWindow = Attached()))
        if ((status = XQueryTree
            (xDisplay, xWindow, &xRootWindow, 
             &xParentWindow, &xWindowChild, &xWindowChildren)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XQueryTree\n"
             "(%p,0x%x,...)\n", status, xDisplay, xWindow));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: MoveWindow
     *
     *    Author: $author$           
     *      Date: 6/29/2010
     **********************************************************************
     */
    virtual eError MoveWindow
    (int x,int y)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = DisplayAttached()))
        if ((xWindow = Attached()))
        if ((status = XMoveWindow(xDisplay, xWindow, x,y)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XMoveWindow\n"
             "(%p,0x%x,...)\n", status, xDisplay, xWindow));
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ResizeWindow
     *
     *    Author: $author$           
     *      Date: 6/29/2010
     **********************************************************************
     */
    virtual eError ResizeWindow
    (unsigned int width, unsigned int height)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = DisplayAttached()))
        if ((xWindow = Attached()))
        if ((status = XResizeWindow
            (xDisplay, xWindow, width,height)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XResizeWindow\n"
             "(%p,0x%x,...)\n", status, xDisplay, xWindow));
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: MoveResizeWindow
     *
     *    Author: $author$           
     *      Date: 6/29/2010
     **********************************************************************
     */
    virtual eError MoveResizeWindow
    (int x,int y, unsigned int width,unsigned int height)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = DisplayAttached()))
        if ((xWindow = Attached()))
        if ((status = XMoveResizeWindow
            (xDisplay, xWindow, x,y, width,height)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XMoveResizeWindow\n"
             "(%p,0x%x,...)\n", status, xDisplay, xWindow));
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowRectangle
     *
     *   Author: $author$           
     *     Date: 6/29/2010
     **********************************************************************
     */
    virtual eError SetWindowRectangle
    (XRectangle& xRectangle) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        error = MoveResizeWindow
        (xRectangle.x,xRectangle.y, 
         xRectangle.width,xRectangle.height);
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetWindowRectangle
     *
     *   Author: $author$           
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual eError GetWindowRectangle
    (XRectangle& xRectangle) const 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        XWindowAttributes xWindowAttributes;

        if (!(error = GetWindowAttributes(xWindowAttributes)))
        {
            xRectangle.x = xWindowAttributes.x;
            xRectangle.y = xWindowAttributes.y;
            xRectangle.width = xWindowAttributes.width;
            xRectangle.height = xWindowAttributes.height;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: ChangeWindowAttributes
     *
     *   Author: $author$           
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual eError ChangeWindowAttributes
    (unsigned long xSetWindowAttributesValues, 
     XSetWindowAttributes& xSetWindowAttributes) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = m_display.Attached()))
        if ((xWindow = Attached()))
        if ((status = XChangeWindowAttributes
            (xDisplay, xWindow, xSetWindowAttributesValues, &xSetWindowAttributes)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XChangeWindowAttributes\n"
             "(%p,0x%x,...)\n", status, xDisplay, (int)xWindow));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetWindowAttributes
     *
     *   Author: $author$           
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual eError GetWindowAttributes
    (XWindowAttributes& xWindowAttributes) const 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = m_display.Attached()))
        if ((xWindow = Attached()))
        if ((status = XGetWindowAttributes
            (xDisplay, xWindow, &xWindowAttributes)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XGetWindowAttributes\n"
             "(%p,0x%x,...)\n", status, xDisplay, (int)xWindow));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWMProtocols
     *
     *   Author: $author$           
     *     Date: 2/12/2013
     **********************************************************************
     */
    virtual eError SetWMProtocols
    (Atom* protocols, int count)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        Status status;

        if ((xDisplay = m_display.Attached()))
        if ((xWindow = Attached()))
        if ((status = XSetWMProtocols(xDisplay, xWindow, protocols, count)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XSetWMProtocols\n"
             "(%p,0x%x,...)\n", status, xDisplay, (int)xWindow));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetGC
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual cXGCInterface* GetGC
    (eError& error,
     bool onlyFreed=false) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        cXGCInterface* gc = 0;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        GC xGC;

        if (None != (xGC = m_gc.Attached()))
        {
            if (onlyFreed)
                error = e_ERROR_ALREADY_ACQUIRED;
            else
            {
                gc = &m_gc;
                error = e_ERROR_NONE;
            }
            return gc;
        }

        error = e_ERROR_NOT_ATTACHED;

        if (None != (xWindow = Attached()))
        if ((xDisplay = DisplayAttached()))

        if (!(error = m_gc.Create(xWindow)))
            gc = &m_gc;

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return gc;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FreeGC
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual eError FreeGC
    (cXGCInterface& gc,
     bool onlyGotten=false) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        if (&gc != &m_gc)
        if (onlyGotten)
            error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SaveXContext
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError SaveXContext
    (XContext xContext=1, bool onlyDeleted=false)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Window xWindow;
        XPointer xPointer;
        XContext savedXContext;
        eError error2;
        int status;

        if (None != (savedXContext = SavedXContext()))
        if (onlyDeleted)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error2 = DeleteXContext(true)))
            return error2;

        if (None != (xWindow = Attached()))
        if ((xDisplay = DisplayAttached()))

        if ((status = XSaveContext
            (xDisplay, xWindow, xContext, 
             xPointer = (XPointer)((cXEventTargetInterface*)(this)))))
        {
            DBE(("()\n failed status = %d on XSaveContext\n"
                 "(xDisplay=%p, xWindow=0x%x, xContext=0x%x, xPointer=%p)\n", 
                 status, xDisplay,xWindow, xContext,xPointer));
            error = e_ERROR_FAILED;
        }
        else
        if ((status = XFindContext
            (xDisplay, xWindow, xContext, &xPointer)))
        {
            DBE(("()\n failed status = %d on XFindContext\n"
                "(xDisplay=%p, xWindow=0x%x, xContext=0x%x, xPointer=%p)\n",
                status, xDisplay,xWindow, xContext,&xPointer));
            error = e_ERROR_FAILED;
        }
        else
        {
            SetSavedXContext(xContext);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DeleteXContext
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError DeleteXContext
    (bool onlySaved=false)
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Window xWindow;
        XContext xContext;
        int status;

        if (None != (xContext = SavedXContext()))
            SetSavedXContext(None);
        else
        if (!(onlySaved))
            return e_ERROR_NONE;

        if (None != (xWindow = Attached()))
        if ((xDisplay = DisplayAttached()))

        if ((status = XDeleteContext
            (xDisplay, xWindow, xContext)))
        {
            DBE(("()\n failed status = %d on XDeleteContext\n"
                "(xDisplay=%p, xWindow=0x%x, xContext=0x%x)\n", 
                status, xDisplay,xWindow, xContext));
            error = e_ERROR_FAILED;
        }
        else
        error = e_ERROR_NONE;

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetSavedXContext
     *
     *   Author: $author$           
     *     Date: 6/24/2009
     **********************************************************************
     */
    virtual XContext SetSavedXContext
    (XContext xContext) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        m_savedXContext = xContext;
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        xContext = 0;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return xContext;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SavedXContext
     *
     *   Author: $author$           
     *     Date: 6/24/2009
     **********************************************************************
     */
    virtual XContext SavedXContext() const 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        XContext xContext = 0;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        xContext = m_savedXContext;
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return xContext;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SelectInput
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual eError SelectInput
    (long xEventMask) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        int err;
        if (None != (xWindow = Attached()))
        if ((xDisplay = m_display.Attached()))
        {
            err = XSelectInput(xDisplay,xWindow, xEventMask);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetSelectedXEventMask
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual long SetSelectedXEventMask
    (long xEventMask) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        m_selectedXEventMask = xEventMask;
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        xEventMask = 0;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return xEventMask;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SelectedXEventMask
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual long SelectedXEventMask() const 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        long xEventMask = m_selectedXEventMask;
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        long xEventMask = 0;
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return xEventMask;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: SetXEventDelegateBefore
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXEventTargetInterface* SetXEventDelegateBefore
    (cXEventTargetInterface* delegateTo) 
    {
        m_delegateBeforeTo = delegateTo;
        return m_delegateBeforeTo;
    }
    /**
     **********************************************************************
     * Function: XEventDelegateBefore
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXEventTargetInterface* XEventDelegateBefore() const 
    {
        return m_delegateBeforeTo;
    }
    /**
     **********************************************************************
     * Function: SetXEventDelegateAfter
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXEventTargetInterface* SetXEventDelegateAfter
    (cXEventTargetInterface* delegateTo) 
    {
        m_delegateAfterTo = delegateTo;
        return m_delegateAfterTo;
    }
    /**
     **********************************************************************
     * Function: XEventDelegateAfter
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXEventTargetInterface* XEventDelegateAfter() const 
    {
        return m_delegateAfterTo;
    }
#include "cxwindow_events.hxx"
#include "cxobjectimplement_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOW_HXX) || defined(CXWINDOW_MEMBERS_ONLY) */

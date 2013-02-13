/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$     
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
 *   Date: 6/23/2009
 **********************************************************************
 */
#if !defined(_CXWINDOW_HXX) || defined(CXWINDOW_MEMBERS_ONLY)
#if !defined(_CXWINDOW_HXX) && !defined(CXWINDOW_MEMBERS_ONLY)
#define _CXWINDOW_HXX
#endif /* !defined(_CXWINDOW_HXX) && !defined(CXWINDOW_MEMBERS_ONLY) */

#if !defined(CXWINDOW_MEMBERS_ONLY)
#include "cxwindowinterface.hxx"
#include "cxdisplayinterface.hxx"
#include "cxregion.hxx"
#include "cxrectangle.hxx"
#include "cxgc.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXWindow
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class cXWindow
: virtual public cXWindowImplement,
  virtual public cXEventTargetImplement,
  public cXWindowCreated
{
public:
    typedef cXWindowCreated cExtends;

    static XContext m_defaultXContext;
    static long m_defaultXEventMask;
    static long m_defaultGrabXEventMask;

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
     *         Date: 6/23/2009
     **********************************************************************
     */
    cXWindow
    (cXDisplayInterface& display,
     Window attached=None,
     bool isCreated=false,
     cXEventTargetInterface* delegateAfterTo=0,
     cXEventTargetInterface* delegateBeforeTo=0)
    : cExtends(attached, isCreated),
      m_display(display),
      m_xContext(m_defaultXContext),
      m_savedXContext(0),
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
     *        Date: 6/23/2009
     **********************************************************************
     */
    virtual ~cXWindow()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("()\n throwing error=%d\n", (int)(error)));
            throw (error);
        }
    }
#else /* !defined(CXWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CreateSimple
     *
     *   Author: $author$           
     *     Date: 6/24/2009
     **********************************************************************
     */
    virtual eError CreateSimple
    (Window parentXWindow, int x, int y, 
     unsigned int width, unsigned int height, 
     unsigned int borderWidth, unsigned long border, 
     unsigned long background, bool onlyDestroyed=false) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        eError error2;
        int isCreated;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow = XCreateSimpleWindow
            (xDisplay, parentXWindow, x,y, width,height, 
             borderWidth,border, background)))
        {
            if (0 <= (isCreated = SetIsCreated()))
            if (None != (Attach(xWindow)))
            if (!(error = SaveXContext(m_xContext)))
            if (!(error = SelectInput(m_xEventMask)))
                return error;
            else
            DeleteXContext();

            XDestroyWindow(xDisplay, xWindow);
        }
        else
        {
            DBE(("() failed on XCreateSimpleWindow()\n"));
            error = e_ERROR_FAILED;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$           
     *     Date: 6/24/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        eError error2;
        int err;

        if ((error2 = Created(onlyCreated, true)))
            return error2;

        m_gc.Destroy();
        SetIsCreated(false);

        if ((error2 = DeleteXContext(onlyCreated)))
            return error2;

        if (None != (xWindow = Detach()))
        if ((xDisplay = m_display.Attached()))
        {
            err = XDestroyWindow(xDisplay,xWindow);
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

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow = Attached()))
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
        if ((xDisplay = m_display.Attached()))
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
        if ((xDisplay = m_display.Attached()))
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
    (const XSetWindowAttributes& xSetWindowAttributes) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
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
        DBE(("() failed on %d = XGetWindowAttributes(%p,0x%x,...)\n", 
             (int)status, xDisplay, (int)xWindow));

#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
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
     * Function: SaveXContext
     *
     *   Author: $author$           
     *     Date: 6/24/2009
     **********************************************************************
     */
    virtual eError SaveXContext
    (XContext xContext=1, bool onlyDeleted=false) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        XPointer xPointer;
        XContext savedXContext;
        eError error2;
        int err;

        if ((savedXContext = SavedXContext()))
        if (onlyDeleted)
            return e_ERROR_ALREADY_ATTACHED;
        else
        if ((error2 = DeleteXContext(true)))
            return error2;

        if (None != (xWindow = Attached()))
        if ((xDisplay = m_display.Attached()))
        if ((err = XSaveContext
            (xDisplay, xWindow, xContext, 
             xPointer = (XPointer)((cXEventTargetInterface*)(this)))))
        {
            DBE(("() failed on XSaveContext(%p,%u, %u,%p)\n", xDisplay,xWindow, xContext,xPointer));
            error = e_ERROR_FAILED;
        }
        else
        if ((err = XFindContext
            (xDisplay, xWindow, xContext, &xPointer)))
        {
            DBE(("() failed on XFindContext(%p,%u, %u,%p)\n", xDisplay,xWindow, xContext,&xPointer));
            error = e_ERROR_FAILED;
        }
        else
        {
            SetSavedXContext(xContext);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DeleteXContext
     *
     *   Author: $author$           
     *     Date: 6/24/2009
     **********************************************************************
     */
    virtual eError DeleteXContext
    (bool onlySaved=false) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Window xWindow;
        XContext xContext;
        int err;

        if ((xContext = SavedXContext()))
            SetSavedXContext(0);
        else
        if (!(onlySaved))
            return e_ERROR_NONE;

        if (None != (xWindow = Attached()))
        if ((xDisplay = m_display.Attached()))
        if ((err = XDeleteContext
            (xDisplay, xWindow, xContext)))
        {
            DBE(("() failed on XDeleteContext(%p,%u, %u)\n", xDisplay,xWindow, xContext));
            error = e_ERROR_FAILED;
        }
        else
        error = e_ERROR_NONE;
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
        xContext = m_savedXContext;
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
        //DBT(("() m_delegateAfterTo=%p\n", m_delegateAfterTo));
        return m_delegateAfterTo;
    }

#include "cxwindow_events.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOW_HXX) || defined(CXWINDOW_MEMBERS_ONLY) */

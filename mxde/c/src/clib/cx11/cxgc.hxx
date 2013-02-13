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
 *   File: cxgc.hxx
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
#if !defined(_CXGC_HXX) || defined(CXGC_MEMBERS_ONLY)
#if !defined(_CXGC_HXX) && !defined(CXGC_MEMBERS_ONLY)
#define _CXGC_HXX
#endif /* !defined(_CXGC_HXX) && !defined(CXGC_MEMBERS_ONLY) */

#if !defined(CXGC_MEMBERS_ONLY)
#include "cxgcinterface.hxx"
#include "cdebug.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXGC
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class cXGC
: virtual public cXGCImplement,
  public cXGCCreated
{
public:
    typedef cXGCCreated cExtends;

    cXDisplayInterface& m_display;
    cXDrawableAttached m_drawable;
    cXRegionAttached m_region;

    unsigned long m_foreground;
    unsigned long m_background;
    unsigned m_gotten;

    /**
     **********************************************************************
     *  Constructor: cXGC
     *
     *       Author: $author$           
     *         Date: 6/29/2009
     **********************************************************************
     */
    cXGC
    (cXDisplayInterface& display,
     GC attached=NULL,
     bool isCreated=false)
    : cExtends(attached,isCreated), 
      m_display(display),
      m_foreground(0),
      m_background(0),
      m_gotten(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXGC
     *
     *      Author: $author$           
     *        Date: 6/29/2009
     **********************************************************************
     */
    virtual ~cXGC()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("()\n throwing error=%d\n", (int)(error)));
            throw (error);
        }
    }
#else /* !defined(CXGC_MEMBERS_ONLY) */
#endif /* !defined(CXGC_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CreateAttached
     *
     *   Author: $author$           
     *     Date: 5/30/2010
     **********************************************************************
     */
    virtual GC CreateAttached
    (eError& error,
     Drawable xDrawable, 
     unsigned long xGCValueMask=0, 
     XGCValues* xGCValues=0,
     bool onlyDestroyed=false) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        GC detached = 0;
        error = e_ERROR_FAILED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        if (!(error = Destroyed(onlyDestroyed)))

        if ((detached = CreateDetached
            (error, xDrawable, xGCValueMask, xGCValues)))
        {
            if (detached == (Attach(detached)))
            {
                if (xDrawable == (m_drawable.Attach(xDrawable)))
                {
                    if (0 < (SetIsCreated()))
                        return detached;

                    m_drawable.Detach();
                }
               Detach();
            }
            DestroyDetached(detached);
            detached = 0;
        }
        error = e_ERROR_FAILED;
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError Create
    (Drawable xDrawable, 
     unsigned long xGCValueMask=0, 
     XGCValues* xGCValues=0,
     bool onlyDestroyed=false) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        GC detached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((detached = CreateDetached
            (error, xDrawable, xGCValueMask, xGCValues)))
        {
            if (detached == (Attach(detached)))
            {
                if (xDrawable == (m_drawable.Attach(xDrawable)))
                {
                    if (0 < (SetIsCreated()))
                        return e_ERROR_NONE;

                    m_drawable.Detach();
                }
               Detach();
            }
            DestroyDetached(detached);
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        GC detached;

        if ((error = Created(onlyCreated, true)))
            return error;

        m_gotten = 0;
        SetIsCreated(false);

        if ((error = m_drawable.Detached(false, onlyCreated)))
            return error;

        if ((detached = Detached(error, false, onlyCreated)))
            error = DestroyDetached(detached);

#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$           
     *     Date: 4/12/2010
     **********************************************************************
     */
    virtual cXGCInterface* Get
    (eError& error, bool onlyFreed = false) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
        cXGCInterface* gc = 0;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_NOT_ATTACHED;
        if (None != (Attached()))
        {
            if (m_gotten && onlyFreed)
            {
                error = e_ERROR_ALREADY_ACQUIRED;
                return gc;
            }

            m_gotten++;
            gc = (cXGCInterface*)(this);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return gc;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$           
     *     Date: 4/12/2010
     **********************************************************************
     */
    virtual eError Free
    (bool onlyGotten = false) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;

        if (m_gotten)
            --m_gotten;
        else
        if (onlyGotten)
            error = e_ERROR_NOT_ACQUIRED;
        else
        error = Destroy(true);
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: DrawString
     *
     *    Author: $author$           
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual TLENGTH DrawString
    (int x,int y, const char* string, 
     TLENGTH length = UNDEFINED_LENGTH) const
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_FAILED;
        Drawable xDrawable;
        if (None != (xDrawable = DrawableAttached()))
            count = DrawString(xDrawable, x,y, string, length);
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DrawString
     *
     *    Author: $author$           
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual TLENGTH DrawString
    (Drawable xDrawable, int x,int y, 
     const char* string, TLENGTH length = UNDEFINED_LENGTH) const
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        GC xGC;
        int status;

        if (string)
        if (None != (xDrawable))
        if ((xGC = Attached()))
        if ((xDisplay = DisplayAttached()))
        {
            if (0 > (length))
            if (0 >= (length = cCHARS::Count(string)))
                return length;

            if (!(status = XDrawString
                (xDisplay, xDrawable, xGC, x,y, string, length)))
                count = length;
            else
            DBE
            (("()\n failed status = %d on XDrawString"
              "(xDisplay=%p, xDrawable=0x%x, xGC=%p, x=%d,y=%d, string=\"%s\", length=%d)\n", 
              status, xDisplay, xDrawable, xGC, x,y, string, length));
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetFont
     *
     *    Author: $author$           
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual Font SetFont
    (Font xFont) const
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        Font xFontPrev = SetFont(error, xFont);
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return xFontPrev;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetFont
     *
     *    Author: $author$           
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual Font SetFont
    (eError& error, Font xFont) const
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
        Font xFontPrev = None;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        GC xGC;
        int status;

        error = e_ERROR_FAILED;

        if (None != (xFont))
        if ((xGC = Attached()))
        if ((xDisplay = DisplayAttached()))
        if ((status = XSetFont
            (xDisplay, xGC, xFont)))
            error = e_ERROR_NONE;
        else
        DBE
        (("()\n failed status = %d on XSetFont"
          "(xDisplay=%p, xGC=%p, xFont=0x%x)\n", 
          status, xDisplay, xGC, xFont));
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return xFontPrev;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetXRegion
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError SetXRegion
    (Region xRegion) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        GC xGC;
        int err;
        if ((xDisplay = m_display.Attached()))
        if ((xGC = Attached()))
        {
            err = XSetRegion
            (xDisplay, xGC, xRegion);
            m_region.Attach(xRegion);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: XRegion
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual Region XRegion() const 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        Region xRegion = 0;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        xRegion = m_region.Attached();
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return xRegion;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: FillRectangle
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError FillRectangle
    (int x,
     int y,
     unsigned int width,
     unsigned int height,
     unsigned long colorPixel) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
        unsigned long oldForegroundColorPixel;
        if (!(error = SetForeground(oldForegroundColorPixel, colorPixel)))
        {
            error = FillRectangle(x,y, width,height);
            SetForeground(colorPixel, oldForegroundColorPixel);
        }
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FillRectangle
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError FillRectangle
    (int x,
     int y,
     unsigned int width,
     unsigned int height) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Drawable xDrawable;
        GC xGC;
        int err;
        if ((xDisplay = m_display.Attached()))
        if ((xDrawable = m_drawable.Attached()))
        if ((xGC = Attached()))
        {
            err = XFillRectangle
            (xDisplay, xDrawable, xGC, x,y, width,height);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetForeground
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError SetForeground
    (unsigned long& oldColor,
     unsigned long toColor) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error;
        oldColor = Foreground();
        error = SetForeground(toColor);
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetForeground
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError SetForeground
    (unsigned long toColor) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        GC xGC;
        int err;
        if ((xDisplay = m_display.Attached()))
        if ((xGC = Attached()))
        {
            DBF
            (("()\n XSetForeground"
              "(xDisplay=%p, xGC=%p, toColor=0x%x)...\n",
              xDisplay, xGC, toColor));

            err = XSetForeground(xDisplay, xGC, toColor);
            m_foreground = toColor;
            error = e_ERROR_NONE;
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Foreground
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual unsigned long Foreground() const 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        unsigned long color = 0;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        color = m_foreground;
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return color;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBackground
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError SetBackground
    (unsigned long& oldColor,
     unsigned long toColor) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error;
        oldColor = Background();
        error = SetBackground(toColor);
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetBackground
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError SetBackground
    (unsigned long toColor) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        GC xGC;
        int err;
        if ((xDisplay = m_display.Attached()))
        if ((xGC = Attached()))
        {
            DBF
            (("()\n XSetBackground"
              "(xDisplay=%p, xGC=%p, toColor=0x%x)...\n",
              xDisplay, xGC, toColor));

            err = XSetBackground(xDisplay, xGC, toColor);
            m_background = toColor;
            error = e_ERROR_NONE;
        }
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Background
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual unsigned long Background() const 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        unsigned long color = 0;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        color = m_background;
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return color;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual GC CreateDetached
    (eError& error, 
     Drawable xDrawable, 
     unsigned long xGCValueMask=0, 
     XGCValues* xGCValues=0) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        GC detached = NULL;
        error = e_ERROR_FAILED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;

        if ((xDisplay = m_display.Attached()))
        if ((detached = XCreateGC
            (xDisplay, xDrawable, xGCValueMask, xGCValues)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XCreateGC(%p,0x%x)\n", &xDisplay, (int)xDrawable));
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$           
     *     Date: 6/29/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (GC detached) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        int err;

        if ((xDisplay = m_display.Attached()))
        if ((err = XFreeGC(xDisplay, detached)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XFreeGC(%p,%p)\n", &xDisplay, detached));
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SelectDrawable
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual Drawable SelectDrawable
    (Drawable xDrawable) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        Drawable oldXDrawable = SelectDrawable(error, xDrawable);
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return oldXDrawable;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SelectDrawable
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual Drawable SelectDrawable
    (eError& error,
     Drawable xDrawable) 
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXGC_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
        Drawable oldXDrawable = m_drawable.Attached();
        m_drawable.Attach(xDrawable);
        error = e_ERROR_NONE;
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        Drawable oldXDrawable = None;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return oldXDrawable;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: DrawableAttached
     *
     *    Author: $author$           
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual Drawable DrawableAttached() const
#if defined(CXGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */
    {
        Drawable xDrawable = None;
#if !defined(CXGC_MEMBER_FUNCS_IMPLEMENT)
        xDrawable = m_drawable.Attached();
#else /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGC_MEMBER_FUNCS_IMPLEMENT) */
        return xDrawable;
    }
#endif /* defined(CXGC_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXGC_MEMBERS_ONLY)
#include "cxobjectimplement_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXGC_MEMBERS_ONLY) */
#endif /* !defined(CXGC_MEMBERS_ONLY) */

#endif /* !defined(_CXGC_HXX) || defined(CXGC_MEMBERS_ONLY) */

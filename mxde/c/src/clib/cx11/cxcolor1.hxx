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
 *   File: cxcolor.hxx
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
#if !defined(_CXCOLOR_HXX) || defined(CXCOLOR_MEMBERS_ONLY)
#if !defined(_CXCOLOR_HXX) && !defined(CXCOLOR_MEMBERS_ONLY)
#define _CXCOLOR_HXX
#endif /* !defined(_CXCOLOR_HXX) && !defined(CXCOLOR_MEMBERS_ONLY) */

#if !defined(CXCOLOR_MEMBERS_ONLY)
#include "cplatform_string.h"
#include "cxcolorinterface.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXColor
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
class c_X11_CLASS cXColor
: virtual public cXColorImplement,
  public cXPixelAllocated
{
public:
    typedef cXColorImplement cImplements;
    typedef cXPixelAllocated cExtends;

    cXDisplayInterface& m_display;
    cXColormapInterface& m_colormap;
    XColor m_xColor;
    XColor m_xColorDefinition;

    /**
     **********************************************************************
     *  Constructor: cXColor
     *
     *       Author: $author$           
     *         Date: 7/4/2009
     **********************************************************************
     */
    cXColor
    (cXDisplayInterface& display,
     cXColormapInterface& colormap,
     Pixel attached=0,
     bool isAllocated=false)
    : cExtends(attached, isAllocated),
      m_display(display),
      m_colormap(colormap)
    {
        memset(&m_xColor, 0, sizeof(XColor));
        memset(&m_xColorDefinition, 0, sizeof(XColor));
    }
    /**
     **********************************************************************
     *  Destructor: ~cXColor
     *
     *      Author: $author$           
     *        Date: 7/4/2009
     **********************************************************************
     */
    virtual ~cXColor()
    {
        eError error;
        if ((error = Freed()))
        {
            DBE(("() throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXCOLOR_MEMBERS_ONLY) */
#endif /* !defined(CXCOLOR_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AllocateNamedAttached
     *
     *    Author: $author$           
     *      Date: 6/7/2010
     **********************************************************************
     */
    virtual Pixel AllocateNamedAttached
    (eError& error, 
     const char* colorName, 
     bool onlyFreed = false)
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        Pixel detached = 0;

        if (!(error = Freed(onlyFreed)))
        {
            detached = AllocateNamedDetached
            (error, colorName, m_xColor, m_xColorDefinition);

            if (!(error))
            {
                if (detached == (Attach(detached)))
                if (0 < (SetIsAllocated()))
                    return detached;
                else
                Detach();

                FreeDetached(detached);
            }
        }
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return 0;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AllocateBYTE
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError AllocateBYTE
    (BYTE r,
     BYTE g,
     BYTE b,
     bool onlyFreed=false) 
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLOR_MEMBER_FUNCS_INTERFACE */
    {
        unsigned long iL = (1 << (16))-1;
        unsigned short iS = (1 << (8))-1;
        unsigned short rS = (unsigned short)((iL*r)/iS);
        unsigned short gS = (unsigned short)((iL*g)/iS);
        unsigned short bS = (unsigned short)((iL*b)/iS);
        eError error = Allocate(rS, gS, bS, onlyFreed);
        return error;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Allocate
     *
     *   Author: $author$           
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual eError Allocate
    (unsigned short r,
     unsigned short g,
     unsigned short b,
     bool onlyFreed=false) 
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLOR_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Colormap xColormap;
        Pixel detached;
        Status status;
        eError error2;
        int isTrue;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        DBI(("() r=%u g=%u b=%u\n", r,g,b));

        m_xColor.red = r;
        m_xColor.green = g;
        m_xColor.blue = b;

        if ((xDisplay = m_display.Attached()))
        if (None != (xColormap = m_colormap.Attached()))
        if ((status = XAllocColor
            (xDisplay, xColormap, &m_xColor)))
        {
            detached = m_xColor.pixel;

            DBI(("() pixel=0x%x\n", detached));

            if (detached == (Attach(detached)))
            if (0 < (isTrue = SetIsAllocated()))
                return e_ERROR_NONE;
            else 
            Detach();

            XFreeColors
            (xDisplay, xColormap, &detached, 1, 0);
        }
        else
        DBE(("() failed on %d = XAllocColor(%p,0x%x)\n", status, xDisplay, xColormap));

#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$           
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual eError Free
    (bool onlyAllocated=false) 
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLOR_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Colormap xColormap;
        Pixel detached;
        Status status;
        eError error2;
        bool isAllocated;
        int isTrue;

        if ((error2 = Allocated(onlyAllocated, true)))
            return error2;

        if ((isAllocated = IsAllocated()))
        if ((isTrue = SetIsAllocated(false)))
            return e_ERROR_FAILED;

        detached = Detach();

        memset(&m_xColor, 0, sizeof(XColor));
        memset(&m_xColorDefinition, 0, sizeof(XColor));

        if (isAllocated)
        if ((xDisplay = m_display.Attached()))
        if (None != (xColormap = m_colormap.Attached()))
        if (Success == (status = XFreeColors
            (xDisplay, xColormap, &detached, 1, 0)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XFreeColors()\n"));

#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AttachBlackPixel
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual Pixel AttachBlackPixel() 
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLOR_MEMBER_FUNCS_INTERFACE */
    {
        Pixel xPixel = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Screen* xScreen;

        if ((xDisplay = m_display.Attached()))
        if ((xScreen = XDefaultScreenOfDisplay(xDisplay)))
            xPixel = XBlackPixelOfScreen(xScreen);
        else
        DBE(("() failed on XBlackPixelOfScreen()\n"));
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return xPixel;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AttachWhitePixel
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual Pixel AttachWhitePixel() 
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLOR_MEMBER_FUNCS_INTERFACE */
    {
        Pixel xPixel = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Screen* xScreen;

        if ((xDisplay = m_display.Attached()))
        if ((xScreen = XDefaultScreenOfDisplay(xDisplay)))
            xPixel = XWhitePixelOfScreen(xScreen);
        else
        DBE(("() failed on XWhitePixelOfScreen()\n"));
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return xPixel;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AllocateNamedDetached
     *
     *    Author: $author$           
     *      Date: 6/7/2010
     **********************************************************************
     */
    virtual Pixel AllocateNamedDetached
    (eError& error, const char* colorName, 
     XColor& color, XColor& colorDefinition) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Colormap xColormap;
        Status status;

        error = e_ERROR_FAILED;

        if ((xDisplay = m_display.Attached()))
        if (None != (xColormap = m_colormap.Attached()))
        if (Success == (status = XAllocNamedColor
            (xDisplay, xColormap, colorName, 
             &color, &colorDefinition)))
        {
            detached = color.pixel;
            error = e_ERROR_NONE;
        }
        else
        DBE(("()\n failed status = %d on XAllocNamedColor()\n", status));
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AllocateBYTEDetached
     *
     *    Author: $author$           
     *      Date: 6/8/2010
     **********************************************************************
     */
    virtual Pixel AllocateBYTEDetached
    (eError& error, XColor& color,
     BYTE r, BYTE g, BYTE b) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        RGBBYTEToXColor(color, r,g,b);
        detached = AllocateDetached(error, color);
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AllocateDetached
     *
     *    Author: $author$           
     *      Date: 6/8/2010
     **********************************************************************
     */
    virtual Pixel AllocateDetached
    (eError& error, 
     XColor& color,
     unsigned short r, 
     unsigned short g, 
     unsigned short b) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        RGBToXColor(color, r,g,b);
        detached = AllocateDetached(error, color);
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AllocateDetached
     *
     *    Author: $author$           
     *      Date: 6/8/2010
     **********************************************************************
     */
    virtual Pixel AllocateDetached
    (eError& error, XColor& color) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Colormap xColormap;
        Status status;

        error = e_ERROR_FAILED;

        if ((xDisplay = m_display.Attached()))
        if (None != (xColormap = m_colormap.Attached()))
        if (Success == (status = XAllocColor
            (xDisplay, xColormap, &color)))
        {
            detached = color.pixel;
            error = e_ERROR_NONE;
        }
        else
        DBE(("()\n failed status = %d on XAllocColor()\n", status));
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FreeDetached
     *
     *    Author: $author$           
     *      Date: 6/7/2010
     **********************************************************************
     */
    virtual eError FreeDetached
    (Pixel xPixel) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        Display* xDisplay;
        Colormap xColormap;
        Status status;

        if ((xDisplay = m_display.Attached()))
        if (None != (xColormap = m_colormap.Attached()))
        if (Success == (status = XFreeColors
            (xDisplay, xColormap, &xPixel, 1, 0)))
            error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XFreeColors()\n", status));
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: QueryBYTEDetached
     *
     *    Author: $author$           
     *      Date: 6/7/2010
     **********************************************************************
     */
    virtual Pixel QueryBYTEDetached
    (eError& error, XColor& color,
     BYTE r, BYTE g, BYTE b) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;        
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        RGBBYTEToXColor(color, r,g,b);
        detached = QueryDetached(error, color);
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryDetached
     *
     *    Author: $author$           
     *      Date: 6/7/2010
     **********************************************************************
     */
    virtual Pixel QueryDetached
    (eError& error, 
     XColor& color,
     unsigned short r, 
     unsigned short g, 
     unsigned short b) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        RGBToXColor(color, r,g,b);
        detached = QueryDetached(error, color);
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryDetached
     *
     *    Author: $author$           
     *      Date: 6/7/2010
     **********************************************************************
     */
    virtual Pixel QueryDetached
    (eError& error, XColor& color) const
#if defined(CXCOLOR_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel detached = 0;
#if !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Colormap xColormap;
        Status status;

        error = e_ERROR_FAILED;

        if ((xDisplay = m_display.Attached()))
        if (None != (xColormap = m_colormap.Attached()))
        if (Success == (status = XQueryColor
            (xDisplay, xColormap, &color)))
        {
            detached = color.pixel;
            error = e_ERROR_NONE;
        }
        else
        DBE(("()\n failed status = %d on XQueryColor()\n", status));
#else /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXCOLOR_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXCOLOR_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXCOLOR_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: RGBBYTEToXColor
     *
     *    Author: $author$           
     *      Date: 6/8/2010
     **********************************************************************
     */
    inline void RGBBYTEToXColor
    (XColor& color,
     BYTE r, BYTE g, BYTE b) const
    {
        unsigned long iL = (1 << (16))-1;
        unsigned short iS = (1 << (8))-1;
        unsigned short rS = (unsigned short)((iL*r)/iS);
        unsigned short gS = (unsigned short)((iL*g)/iS);
        unsigned short bS = (unsigned short)((iL*b)/iS);

        memset(&color, 0, sizeof(XColor));
        color.red = rS;
        color.green = gS;
        color.blue = bS;
    }
    /**
     **********************************************************************
     *  Function: RGBToXColor
     *
     *    Author: $author$           
     *      Date: 6/8/2010
     **********************************************************************
     */
    inline void RGBToXColor
    (XColor& color,
     unsigned short r, 
     unsigned short g, 
     unsigned short b) const
    {
        memset(&color, 0, sizeof(XColor));
        color.red = r;
        color.green = g;
        color.blue = b;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXCOLOR_MEMBERS_ONLY) */
#endif /* !defined(CXCOLOR_MEMBERS_ONLY) */

#endif /* !defined(_CXCOLOR_HXX) || defined(CXCOLOR_MEMBERS_ONLY) */

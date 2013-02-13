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
 *   File: cxcolormap.hxx
 *
 * Author: $author$           
 *   Date: 7/3/2009
 **********************************************************************
 */
#if !defined(_CXCOLORMAP_HXX) || defined(CXCOLORMAP_MEMBERS_ONLY)
#if !defined(_CXCOLORMAP_HXX) && !defined(CXCOLORMAP_MEMBERS_ONLY)
#define _CXCOLORMAP_HXX
#endif /* !defined(_CXCOLORMAP_HXX) && !defined(CXCOLORMAP_MEMBERS_ONLY) */

#if !defined(CXCOLORMAP_MEMBERS_ONLY)
#include "cxcolormapinterface.hxx"
#include "cxcolormapattached.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXColormap
 *
 * Author: $author$           
 *   Date: 7/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cXColormap
: virtual public cXColormapImplement,
  public cXColormapCreated
{
public:
    typedef cXColormapCreated cExtends;

    cXDisplayInterface& m_display;

    /**
     **********************************************************************
     *  Constructor: cXColormap
     *
     *       Author: $author$           
     *         Date: 7/3/2009
     **********************************************************************
     */
    cXColormap
    (cXDisplayInterface& display,
     Colormap attached=None,
     bool isCreated=false)
    : cExtends(attached,isCreated), 
      m_display(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXColormap
     *
     *      Author: $author$           
     *        Date: 7/3/2009
     **********************************************************************
     */
    virtual ~cXColormap()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("()\n throwing error=%d\n", (int)(error)));
            throw (error);
        }
    }
#else /* !defined(CXCOLORMAP_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORMAP_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$           
     *     Date: 7/4/2009
     **********************************************************************
     */
    virtual eError Create
    (Window xWindow, 
     Visual* xVisual, 
     int allocEntries=AllocAll,
     bool onlyDestroyed=false) 
#if defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLORMAP_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Colormap detached;
        int isTrue;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow))
        if ((xVisual))
        if (None != (detached = XCreateColormap
            (xDisplay, xWindow, xVisual, allocEntries)))
        {
            if (detached == (Attach(detached)))
            {
                if (0 < (isTrue = SetIsCreated()))
                    return e_ERROR_NONE;
                Detach();
            }
            XFreeColormap(xDisplay, detached);
            error = e_ERROR_FAILED;
        }
        else
        DBE(("() failed on XCreateColormap()\n"));
#else /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$           
     *     Date: 7/4/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLORMAP_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Colormap detached;
        int isTrue,err;

        if ((error = Created(onlyCreated, true)))
            return error;

        if ((xDisplay = m_display.Attached()))
        if (!(isTrue = SetIsCreated(false)))
        if ((detached = Detach()))
        {
            err = XFreeColormap(xDisplay, detached);
            error = e_ERROR_NONE;
        }
#else /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AttachDefault
     *
     *   Author: $author$           
     *     Date: 7/4/2009
     **********************************************************************
     */
    virtual Colormap AttachDefault
    (bool onlyDetached=false) 
#if defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLORMAP_MEMBER_FUNCS_INTERFACE */
    {
        Colormap attached = None;
#if !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;

        if ((xDisplay = m_display.Attached()))
            attached = AttachDefaultOfScreen
            (DefaultScreen(xDisplay), onlyDetached);

#else /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AttachDefaultOfScreen
     *
     *   Author: $author$           
     *     Date: 7/4/2009
     **********************************************************************
     */
    virtual Colormap AttachDefaultOfScreen
    (unsigned int screen,
     bool onlyDetached=false) 
#if defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXCOLORMAP_MEMBER_FUNCS_INTERFACE */
    {
        Colormap attached = None;
#if !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        Screen* xScreen;
        Colormap detached;
        eError error;

        if (!(error = Destroyed(onlyDetached)))
        if ((xDisplay = m_display.Attached()))
        if ((xScreen = XScreenOfDisplay(xDisplay, screen)))
        if (None != (detached = XDefaultColormapOfScreen(xScreen)))
            attached = Attach(detached);

#else /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CXCOLORMAP_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXCOLORMAP_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXCOLORMAP_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORMAP_MEMBERS_ONLY) */

#endif /* !defined(_CXCOLORMAP_HXX) || defined(CXCOLORMAP_MEMBERS_ONLY) */

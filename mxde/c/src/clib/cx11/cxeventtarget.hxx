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
 *   File: cxeventtarget.hxx
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
#if !defined(_CXEVENTTARGET_HXX) || defined(CXEVENTTARGET_MEMBERS_ONLY)
#if !defined(_CXEVENTTARGET_HXX) && !defined(CXEVENTTARGET_MEMBERS_ONLY)
#define _CXEVENTTARGET_HXX
#endif /* !defined(_CXEVENTTARGET_HXX) && !defined(CXEVENTTARGET_MEMBERS_ONLY) */

#if !defined(CXEVENTTARGET_MEMBERS_ONLY)
#include "cxeventtargetinterface.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXEventTarget
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
class cXEventTarget
: virtual public cXEventTargetImplement,
  public cXBase
{
public:
    cXEventTargetInterface* m_delegateAfterTo;
    cXEventTargetInterface* m_delegateBeforeTo;

    /**
     **********************************************************************
     *  Constructor: cXEventTarget
     *
     *       Author: $author$           
     *         Date: 6/20/2009
     **********************************************************************
     */
    cXEventTarget
    (cXEventTargetInterface* delegateAfterTo=0,
     cXEventTargetInterface* delegateBeforeTo=0)
     : m_delegateBeforeTo(delegateAfterTo),
       m_delegateAfterTo(delegateBeforeTo)
    {
    }
#else /* !defined(CXEVENTTARGET_MEMBERS_ONLY) */
#endif /* !defined(CXEVENTTARGET_MEMBERS_ONLY) */

#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     * Function: FindTarget
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    static cXEventTargetInterface* FindTarget
    (eError& error, Display& display, XID xId, XContext xContext);
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        cXEventTargetInterface* delegatedTo = 0;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
        delegatedTo = (m_delegateBeforeTo = delegateTo);
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: XEventDelegateBefore
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXEventTargetInterface* XEventDelegateBefore() const 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        cXEventTargetInterface* delegatedTo = 0;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
        delegatedTo = m_delegateBeforeTo;
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        cXEventTargetInterface* delegatedTo = 0;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
        delegatedTo = (m_delegateAfterTo = delegateTo);
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: XEventDelegateAfter
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXEventTargetInterface* XEventDelegateAfter() const 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        cXEventTargetInterface* delegatedTo = 0;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
        delegatedTo = m_delegateAfterTo;
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        cXEventTargetInterface* delegateTo;
        eError error2;

        if ((delegateTo = XEventDelegateBefore()))
        {
            DBT(("() delegate before\n"));
            if ((error2 = delegateTo->OnXEvent(xEvent)))
                return error2;
        }

        switch(xEvent.type)
        {
            case KeyPress:
                DBT(("() KeyPress\n"));
                error = OnKeyPressXEvent(xEvent);
                break;

            case KeyRelease:
                DBT(("() KeyRelease\n"));
                error = OnKeyReleaseXEvent(xEvent);
                break;

            case ButtonPress:
                DBT(("() ButtonPress\n"));
                error = OnButtonPressXEvent(xEvent);
                break;

            case ButtonRelease:
                DBT(("() ButtonRelease\n"));
                error = OnButtonReleaseXEvent(xEvent);
                break;

            case MotionNotify:
                error = OnMotionNotifyXEvent(xEvent);
                break;

            case EnterNotify:
                DBT(("() EnterNotify\n"));
                error = OnEnterNotifyXEvent(xEvent);
                break;

            case LeaveNotify:
                DBT(("() LeaveNotify\n"));
                error = OnLeaveNotifyXEvent(xEvent);
                break;

            case FocusIn:
                DBT(("() FocusIn\n"));
                error = OnFocusInXEvent(xEvent);
                break;

            case FocusOut:
                DBT(("() FocusOut\n"));
                error = OnFocusOutXEvent(xEvent);
                break;

            case KeymapNotify:
                DBT(("() KeymapNotify\n"));
                error = OnKeymapNotifyXEvent(xEvent);
                break;

            case Expose:
                DBT(("() Expose\n"));
                error = OnExposeXEvent(xEvent);
                break;

            case GraphicsExpose:
                DBT(("() GraphicsExpose\n"));
                error = OnGraphicsExposeXEvent(xEvent);
                break;

            case NoExpose:
                DBT(("() NoExpose\n"));
                error = OnNoExposeXEvent(xEvent);
                break;

            case VisibilityNotify:
                DBT(("() VisibilityNotify\n"));
                error = OnVisibilityNotifyXEvent(xEvent);
                break;

            case CreateNotify:
                DBT(("() CreateNotify\n"));
                error = OnCreateNotifyXEvent(xEvent);
                break;

            case DestroyNotify:
                DBT(("() DestroyNotify\n"));
                error = OnDestroyNotifyXEvent(xEvent);
                break;

            case UnmapNotify:
                DBT(("() UnmapNotify\n"));
                error = OnUnmapNotifyXEvent(xEvent);
                break;

            case MapNotify:
                DBT(("() MapNotify\n"));
                error = OnMapNotifyXEvent(xEvent);
                break;

            case MapRequest:
                DBT(("() MapRequest\n"));
                error = OnMapRequestXEvent(xEvent);
                break;

            case ReparentNotify:
                DBT(("() ReparentNotify\n"));
                error = OnReparentNotifyXEvent(xEvent);
                break;

            case ConfigureNotify:
                DBT(("() ConfigureNotify\n"));
                error = OnConfigureNotifyXEvent(xEvent);
                break;

            case ConfigureRequest:
                DBT(("() ConfigureRequest\n"));
                error = OnConfigureRequestXEvent(xEvent);
                break;

            case GravityNotify:
                DBT(("() GravityNotify\n"));
                error = OnGravityNotifyXEvent(xEvent);
                break;

            case ResizeRequest:
                DBT(("() ResizeRequest\n"));
                error = OnResizeRequestXEvent(xEvent);
                break;

            case CirculateNotify:
                DBT(("() CirculateNotify\n"));
                error = OnCirculateNotifyXEvent(xEvent);
                break;

            case CirculateRequest:
                DBT(("() CirculateRequest\n"));
                error = OnCirculateRequestXEvent(xEvent);
                break;

            case PropertyNotify:
                DBT(("() PropertyNotify\n"));
                error = OnPropertyNotifyXEvent(xEvent);
                break;

            case SelectionClear:
                DBT(("() SelectionClear\n"));
                error = OnSelectionClearXEvent(xEvent);
                break;

            case SelectionRequest:
                DBT(("() SelectionRequest\n"));
                error = OnSelectionRequestXEvent(xEvent);
                break;

            case SelectionNotify:
                DBT(("() SelectionNotify\n"));
                error = OnSelectionNotifyXEvent(xEvent);
                break;

            case ColormapNotify:
                DBT(("() ColormapNotify\n"));
                error = OnColormapNotifyXEvent(xEvent);
                break;

            case ClientMessage:
                DBT(("() ClientMessage\n"));
                error = OnClientMessageXEvent(xEvent);
                break;

            case MappingNotify:
                DBT(("() MappingNotify\n"));
                error = OnMappingNotifyXEvent(xEvent);
                break;

        default:
            error = OnXEventDefault(xEvent);
        }

        if (!error)
        if ((delegateTo = XEventDelegateAfter()))
        {
            DBT(("() delegate after\n"));
            if ((error2 = delegateTo->OnXEvent(xEvent)))
                return error2;
        }

#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnXEventDefault
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnXEventDefault
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnKeyPressXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnKeyPressXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnKeyReleaseXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnKeyReleaseXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnButtonPressXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnButtonPressXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnButtonReleaseXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnButtonReleaseXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnMotionNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnMotionNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEnterNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnEnterNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnLeaveNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnLeaveNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnFocusInXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnFocusInXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnFocusOutXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnFocusOutXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnKeymapNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnKeymapNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnExposeXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnExposeXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnGraphicsExposeXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnGraphicsExposeXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnNoExposeXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnNoExposeXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnVisibilityNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnVisibilityNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnCreateNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnCreateNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnDestroyNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnDestroyNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnUnmapNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnUnmapNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnMapNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnMapNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnMapRequestXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnMapRequestXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnReparentNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnReparentNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnConfigureNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnConfigureNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnConfigureRequestXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnConfigureRequestXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnGravityNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnGravityNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnResizeRequestXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnResizeRequestXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnCirculateNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnCirculateNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnCirculateRequestXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnCirculateRequestXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPropertyNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnPropertyNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnSelectionClearXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnSelectionClearXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnSelectionRequestXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnSelectionRequestXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnSelectionNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnSelectionNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnColormapNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnColormapNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnClientMessageXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnClientMessageXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnMappingNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnMappingNotifyXEvent
    (const XEvent& xEvent) 
#if defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXEVENTTARGET_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXEVENTTARGET_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXEVENTTARGET_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXEVENTTARGET_MEMBERS_ONLY) */
#endif /* !defined(CXEVENTTARGET_MEMBERS_ONLY) */

#endif /* !defined(_CXEVENTTARGET_HXX) || defined(CXEVENTTARGET_MEMBERS_ONLY) */

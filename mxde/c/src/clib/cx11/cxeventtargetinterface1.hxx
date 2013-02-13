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
 *   File: cxeventtargetinterface.hxx
 *
 * Author: $author$           
 *   Date: 4/29/2009
 **********************************************************************
 */
#if !defined(_CXEVENTTARGETINTERFACEINTERFACE_HXX) || defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXEVENTTARGETINTERFACEINTERFACE_HXX) && !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY)
#define _CXEVENTTARGETINTERFACEINTERFACE_HXX
#endif /* !defined(_CXEVENTTARGETINTERFACEINTERFACE_HXX) && !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY)
/* cXEventTargetInterface interface definition
 */
#include "cinterfacebase.hxx"
#include "cplatform_Xlib.h"

/**
 **********************************************************************
 *  Class: cXEventTargetInterface
 *
 * Author: $author$           
 *   Date: 4/29/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXEventTargetInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cXEventTargetInterface cDerives;
#else /* !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnKeyPressEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnKeyPressEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnKeyReleaseEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnKeyReleaseEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnButtonPressEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnButtonPressEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnButtonReleaseEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnButtonReleaseEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnMotionNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnMotionNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnEnterNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnEnterNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnLeaveNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnLeaveNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnFocusInEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnFocusInEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnFocusOutEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnFocusOutEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnKeymapNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnKeymapNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnExposeEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnExposeEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnGraphicsExposeEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnGraphicsExposeEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnNoExposeEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnNoExposeEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnVisibilityNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnVisibilityNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnCreateNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnCreateNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnDestroyNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnDestroyNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnUnmapNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnUnmapNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnMapNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnMapNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnMapRequestEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnMapRequestEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnReparentNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnReparentNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnConfigureNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnConfigureNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnConfigureRequestEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnConfigureRequestEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnGravityNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnGravityNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnResizeRequestEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnResizeRequestEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnCirculateNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnCirculateNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnCirculateRequestEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnCirculateRequestEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnPropertyNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnPropertyNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnSelectionClearEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnSelectionClearEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnSelectionRequestEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnSelectionRequestEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnSelectionNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnSelectionNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnColormapNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnColormapNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnClientMessageEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnClientMessageEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    /**
     **********************************************************************
     * Function: OnMappingNotifyEvent
     *
     *   Author: $author$           
     *     Date: 4/30/2009
     **********************************************************************
     */
    virtual eError OnMappingNotifyEvent
    (const XEvent& xEvent) 
#if !defined(CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */

#if !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cXEventTargetImplement
 *
 * Author: $author$           
 *   Date: 4/30/2009
 **********************************************************************
 */
class cXEventTargetImplement
: virtual public cXEventTargetInterface
{
public:
    typedef cXEventTargetInterface cImplements;
    typedef cXEventTargetImplement cDerives;
    
/* include cXEventTargetInterface member functions implement
 */
#define CXEVENTTARGETINTERFACE_MEMBERS_ONLY
#define CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT
#include "cxeventtargetinterface.hxx"
#undef CXEVENTTARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT
#undef CXEVENTTARGETINTERFACE_MEMBERS_ONLY
};
#else /* !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXEVENTTARGETINTERFACEINTERFACE_HXX) || defined(CXEVENTTARGETINTERFACEINTERFACE_MEMBERS_ONLY) */
